#include "global.h"
#include "main.h"
#include "main_menu.h"
#include "new_game.h"
#include "overworld.h"
#include "rtc.h"
#include "constants/rtc.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_control_avatar.h"
#include "field_screen_effect.h"
#include "fieldmap.h"
#include "field_weather.h"
#include "palette.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "text.h"
#include "pokemon.h"
#include "fpmath.h"
#include "constants/battle.h"
#include "task.h"
#include "constants/flags.h"
#include "constants/global.h"
#include "constants/map_groups.h"
#include "constants/maps.h"
#include "constants/songs.h"
#include "constants/vars.h"
#include "constants/rgb.h"
#include "nyxthra_flashback.h"
#include "pokemon.h"
#include "battle.h"
#include "battle_setup.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/pokemon.h"

// Architektur (für spätere Clips):
//
// 1. Nach dem Randomizer startet CB2_StartNyxthraFlashback statt der
//    Birk-Rede. Ein Laufzeitflag (nicht im Save) markiert den Traum.
// 2. NewGameInitData legt nur einen Wegwerf-Spielstand an. Name und
//    Style werden auf Brix gesetzt, danach Warp auf die echte Karte.
//    Vorher merken wir uns Name/Style aus SaveBlock2, damit die
//    anschließende Birk-Rede und CB2_NewGame unberührt bleiben.
//    Es wird niemals in den Flash gespeichert.
// 3. Jeder Clip ist ein Skript auf der echten Karte (Bewegung, Dialog,
//    Specials). Kämpfe später: ein Controller / KI-Override mit festem
//    Zugablauf, nach N Attacken Fade und weiter. Entwicklungen und
//    Rufe nutzen die normalen Animationen.
// 4. Ein Director-Task legt die Traumtönung auf die sichtbare Palette,
//    blättert Texte von allein weiter und beendet alles bei Start.
// 5. NyxthraFlashback_Finish stellt Name/Style wieder her, leert das
//    Team und springt zu MainMenu_BeginBirchSpeechScene. CB2_NewGame
//    ruft NewGameInitData danach noch einmal auf, Flags und Variablen
//    aus den Clips überleben das nicht.
//
// Clip-Reihenfolge (geplant):
//   0 Route 101 / Hydropi  (dieser Stand)
//   1 Arenen, Liga, Marc, Adrian (kurze Autokämpfe)
//   2 Entwicklungen Hydropi → Moorabbel → Sumpex
//   3 Groudon, Kyogre, Rayquaza (Animation + Ruf)
//   4 Ruhmeshalle, Text „2005… das ist sehr lange her.“, Birk

extern const u8 NyxthraFlashback_EventScript_Clip1[];

enum {
    FLASHBACK_CLIP_ROUTE101 = 0,
    FLASHBACK_CLIP_COUNT,
};

#define FLASHBACK_AUTO_A_FRAMES 50
// Sanfte Traumtönung: nur leicht entsättigt und kühl, nicht volles Grau.
#define FLASHBACK_DESAT 90          // /256 ≈ 35 % Richtung Grau
#define FLASHBACK_TONE_R 268        // /256 ≈ 1.05
#define FLASHBACK_TONE_G 250        // /256 ≈ 0.98
#define FLASHBACK_TONE_B 276        // /256 ≈ 1.08

static EWRAM_DATA bool8 sFlashbackActive = FALSE;
static EWRAM_DATA bool8 sFlashbackFinishing = FALSE;
static EWRAM_DATA u8 sFlashbackClip = 0;
static EWRAM_DATA u8 sAutoATimer = 0;
static EWRAM_DATA bool8 sAutoAArmed = FALSE;
static EWRAM_DATA u8 sSavedName[PLAYER_NAME_LENGTH + 1] = {0};
static EWRAM_DATA s8 sSavedStyles[8] = {0};
static EWRAM_DATA bool8 sSavedStateValid = FALSE;

static const u8 sText_Brix[] = _("Brix");

static void FieldCB_FlashbackEnter(void);
static void Task_FlashbackDirector(u8 taskId);
static void Task_FlashbackStartClip(u8 taskId);
static void Task_FlashbackCleanup(u8 taskId);
static void Flashback_EnsureDirector(void);
static void Flashback_ApplyBrixIdentity(void);
static void Flashback_RestoreIdentity(void);
static void Flashback_WarpToRoute101(void);

#define FLASHBACK_BATTLE_AUTO_DELAY 40
#define FLASHBACK_DEFAULT_MAX_MOVES 2

static EWRAM_DATA bool8 sFlashbackBattleActive = FALSE;
static EWRAM_DATA u8 sFlashbackActionMenus = 0;
static EWRAM_DATA u8 sFlashbackAutoTimer = 0;
static EWRAM_DATA u8 sFlashbackMaxTurns = 0;
static EWRAM_DATA u16 sFlashbackPlayerMove = 0;
static EWRAM_DATA u16 sFlashbackOpponentMove = 0;
static EWRAM_DATA bool8 sFlashbackCountThisMenu = 0;
static EWRAM_DATA u8 sFlashbackBattleTextTimer = 0;

static void Flashback_SetPartyForBattle(struct Pokemon *mon, u16 move)
{
    u8 level = 22;
    u16 none = MOVE_NONE;
    u8 pp = 40;
    u16 hp;

    if (GetMonData(mon, MON_DATA_SPECIES) == SPECIES_NONE)
        return;

    SetMonData(mon, MON_DATA_LEVEL, &level);
    SetMonData(mon, MON_DATA_MOVE1, &move);
    SetMonData(mon, MON_DATA_MOVE2, &none);
    SetMonData(mon, MON_DATA_MOVE3, &none);
    SetMonData(mon, MON_DATA_MOVE4, &none);
    SetMonData(mon, MON_DATA_PP1, &pp);
    CalculateMonStats(mon);
    hp = 220;
    SetMonData(mon, MON_DATA_MAX_HP, &hp);
    SetMonData(mon, MON_DATA_HP, &hp);
}

bool8 NyxthraFlashback_IsActive(void)
{
    return sFlashbackActive;
}

void NyxthraFlashback_ApplyDreamTint(void)
{
    u32 i;
    u16 *pal;

    if (!sFlashbackActive)
        return;

    // Immer aus Unfaded tönen, sonst würde die Tönung ohne PaletteFade
    // jeden Frame erneut auf Faded liegen und alles schwarz färben.
    pal = gPaletteFade.active ? gPlttBufferFaded : gPlttBufferUnfaded;
    for (i = 0; i < PLTT_BUFFER_SIZE; i++, pal++)
    {
        s32 r = GET_R(*pal);
        s32 g = GET_G(*pal);
        s32 b = GET_B(*pal);
        s32 gray = (r * 77 + g * 151 + b * 28) >> 8;
        s32 keep = 256 - FLASHBACK_DESAT;

        r = (r * keep + gray * FLASHBACK_DESAT) >> 8;
        g = (g * keep + gray * FLASHBACK_DESAT) >> 8;
        b = (b * keep + gray * FLASHBACK_DESAT) >> 8;

        r = (r * FLASHBACK_TONE_R) >> 8;
        g = (g * FLASHBACK_TONE_G) >> 8;
        b = (b * FLASHBACK_TONE_B) >> 8;

        if (r > 31) r = 31;
        if (g > 31) g = 31;
        if (b > 31) b = 31;
        gPlttBufferFaded[i] = RGB(r, g, b);
    }
}

static void Flashback_EnsureDirector(void)
{
    u8 i;

    if (!sFlashbackActive)
        return;

    for (i = 0; i < NUM_TASKS; i++)
    {
        if (gTasks[i].isActive && gTasks[i].func == Task_FlashbackDirector)
            return;
    }
    CreateTask(Task_FlashbackDirector, 0);
}

void NyxthraFlashback_OnOverworldTick(void)
{
    if (!sFlashbackActive)
        return;

    Flashback_EnsureDirector();
    NyxthraFlashback_ApplyDreamTint();
    // Vignette via WIN0+DARKEN made the map black after the first message;
    // left disabled. Soft tint is the dream frame for now.
}

static void Flashback_SnapshotIdentity(void)
{
    memcpy(sSavedName, gSaveBlock2Ptr->playerName, sizeof(sSavedName));
    memcpy(sSavedStyles, gSaveBlock2Ptr->playerStyles, sizeof(sSavedStyles));
    sSavedStateValid = TRUE;
}

static void Flashback_ApplyBrixIdentity(void)
{
    memset(gSaveBlock2Ptr->playerName, EOS, sizeof(gSaveBlock2Ptr->playerName));
    StringCopy(gSaveBlock2Ptr->playerName, sText_Brix);
    gSaveBlock2Ptr->playerStyles[0] = STYLE_BRENDAN;
}

static void Flashback_RestoreIdentity(void)
{
    if (sSavedStateValid)
    {
        memcpy(gSaveBlock2Ptr->playerName, sSavedName, sizeof(sSavedName));
        memcpy(gSaveBlock2Ptr->playerStyles, sSavedStyles, sizeof(sSavedStyles));
        sSavedStateValid = FALSE;
    }
    ZeroPlayerPartyMons();
    gPartiesCount[B_TRAINER_PLAYER] = 0;
}

static void Flashback_WarpToRoute101(void)
{
    // Eigene Karte mit den originalen Smaragd-Kacheln von 2005,
    // unabhängig von den später geänderten Nyxthra-Tilesets.
    SetWarpDestination(MAP_GROUP(MAP_FLASHBACK_ROUTE101), MAP_NUM(MAP_FLASHBACK_ROUTE101), WARP_ID_NONE, 10, 19);
    WarpIntoMap();
}

void CB2_StartNyxthraFlashback(void)
{
    sFlashbackActive = TRUE;
    sFlashbackFinishing = FALSE;
    sFlashbackClip = FLASHBACK_CLIP_ROUTE101;
    sAutoATimer = 0;
    sAutoAArmed = FALSE;

    Flashback_SnapshotIdentity();
    NewGameInitData();
    Flashback_ApplyBrixIdentity();
    Flashback_WarpToRoute101();
    FlagSet(FLAG_HIDE_MAP_NAME_POPUP);
    FlagSet(FLAG_HIDE_ROUTE_101_BIRCH);
    FlagSet(FLAG_HIDE_ROUTE_101_BOY);
    FlagClear(FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE);
    FlagClear(FLAG_HIDE_ROUTE_101_ZIGZAGOON);
    FlagClear(FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG);
    VarSet(VAR_ROUTE101_STATE, 0);
    Overworld_StartFromNewGameWarp(FieldCB_FlashbackEnter);
}

static void FieldCB_FlashbackEnter(void)
{
    // Originales Smaragd hatte keine Tageszeiten-Tönung. Nach dem Warp
    // (der die Stunden-Override löscht) Mittag setzen und Paletten neu
    // laden, damit der Fade-in nicht mit der Nachtmischung startet.
    SetTimeOfDay(12);
    gTimeOfDay = TIME_DAY;
    UpdateTimeOfDay(TRUE);
    LoadMapTilesetPalettes(gMapHeader.mapLayout);
    CpuCopy16(gPlttBufferUnfaded, gPlttBufferFaded, PLTT_SIZE);
    FadeInFromBlack();
    LockPlayerFieldControls();
    Flashback_EnsureDirector();
    CreateTask(Task_FlashbackStartClip, 1);
}

static void Task_FlashbackStartClip(u8 taskId)
{
    if (gPaletteFade.active)
        return;

    LockPlayerFieldControls();
    ScriptContext_SetupScript(NyxthraFlashback_EventScript_Clip1);
    DestroyTask(taskId);
}

void NyxthraFlashback_ProcessInput(void)
{
    bool8 printerActive;

    if (!sFlashbackActive || sFlashbackFinishing)
        return;

    if (JOY_NEW(START_BUTTON))
    {
        NyxthraFlashback_Finish();
        return;
    }

    // Vor OverworldBasic, damit JOY_NEW in derselben Frame ankommt.
    // Manche Texte (Prompt-Zeichen) lassen den Drucker aktiv, bis A kommt.
    // Andere beenden den Drucker und warten danach mit waitbuttonpress.
    if (gPaletteFade.active)
        return;

    printerActive = IsTextPrinterActiveOnWindow(0);
    if (printerActive)
        sAutoAArmed = TRUE;

    if (!sAutoAArmed)
        return;

    if (sAutoATimer < 0xFF)
        sAutoATimer++;
    if (sAutoATimer >= FLASHBACK_AUTO_A_FRAMES)
    {
        sAutoATimer = 0;
        gMain.newKeys |= A_BUTTON;
        gMain.newAndRepeatedKeys |= A_BUTTON;
        if (!printerActive)
            sAutoAArmed = FALSE;
    }
}

static void Task_FlashbackDirector(u8 taskId)
{
    if (!sFlashbackActive)
        DestroyTask(taskId);
}

static void CB2_FlashbackFinishAfterBattle(void)
{
    ScriptContext_Stop();
    StopMapMusic();
    Flashback_RestoreIdentity();
    sFlashbackBattleActive = FALSE;
    sFlashbackActive = FALSE;
    sFlashbackFinishing = FALSE;
    MainMenu_BeginBirchSpeechScene();
}

void NyxthraFlashback_Finish(void)
{
    u8 i;

    if (sFlashbackFinishing)
        return;

    sFlashbackFinishing = TRUE;
    sAutoATimer = 0;
    sAutoAArmed = FALSE;
    sFlashbackBattleActive = FALSE;

    if (gMain.inBattle)
    {
        if (!gPaletteFade.active)
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gMain.savedCallback = CB2_FlashbackFinishAfterBattle;
        SetMainCallback2(CB2_QuitRecordedBattle);
        return;
    }

    for (i = 0; i < NUM_TASKS; i++)
    {
        if (gTasks[i].isActive && gTasks[i].func == Task_FlashbackCleanup)
            return;
    }

    if (!gPaletteFade.active)
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);

    CreateTask(Task_FlashbackCleanup, 0);
}

static void Task_FlashbackCleanup(u8 taskId)
{
    if (gPaletteFade.active)
        return;

    ScriptContext_Stop();
    StopMapMusic();
    Flashback_RestoreIdentity();
    sFlashbackBattleActive = FALSE;
    sFlashbackActive = FALSE;
    sFlashbackFinishing = FALSE;
    DestroyTask(taskId);
    MainMenu_BeginBirchSpeechScene();
}

void NyxthraFlashback_PrepareScriptedBattle(void)
{
    u16 playerMove = gSpecialVar_0x8004;
    u16 opponentMove = gSpecialVar_0x8005;
    u16 maxTurns = gSpecialVar_0x8006;

    if (!sFlashbackActive)
        return;

    sFlashbackPlayerMove = playerMove ? playerMove : MOVE_WATER_GUN;
    sFlashbackOpponentMove = opponentMove ? opponentMove : MOVE_ROCK_TOMB;
    sFlashbackMaxTurns = maxTurns ? maxTurns : 1;
    sFlashbackBattleActive = TRUE;
    sFlashbackActionMenus = 0;
    sFlashbackAutoTimer = 0;
    sFlashbackBattleTextTimer = 0;
    sFlashbackCountThisMenu = TRUE;

    Flashback_SetPartyForBattle(&gParties[B_TRAINER_PLAYER][0], sFlashbackPlayerMove);
}

void NyxthraFlashback_OnTrainerPartyCreated(void)
{
    if (!sFlashbackBattleActive)
        return;
    Flashback_SetPartyForBattle(&gParties[B_TRAINER_OPPONENT_A][0], sFlashbackOpponentMove);
}

bool8 NyxthraFlashback_IsScriptedBattle(void)
{
    return (sFlashbackActive && sFlashbackBattleActive && !sFlashbackFinishing);
}

u16 NyxthraFlashback_GetPlayerMove(void)
{
    return sFlashbackPlayerMove;
}

u16 NyxthraFlashback_GetOpponentMove(void)
{
    return sFlashbackOpponentMove;
}

void NyxthraFlashback_NotePlayerActionMenu(void)
{
    // Nur einmal pro Aktionsmenü zählen, nicht jeden Frame.
    if (sFlashbackCountThisMenu)
    {
        if (sFlashbackActionMenus < 0xFF)
            sFlashbackActionMenus++;
        sFlashbackCountThisMenu = FALSE;
    }
}

bool8 NyxthraFlashback_ShouldAbortBattle(void)
{
    // Erstes Aktionsmenü = vor den Zügen, jedes weitere = nächste Runde.
    return (sFlashbackActionMenus > sFlashbackMaxTurns);
}

bool8 NyxthraFlashback_TickAutoInput(u8 delay)
{
    if (sFlashbackAutoTimer < 0xFF)
        sFlashbackAutoTimer++;
    if (sFlashbackAutoTimer >= delay)
    {
        sFlashbackAutoTimer = 0;
        sFlashbackCountThisMenu = TRUE; // nächstes Menü wieder zählen
        return TRUE;
    }
    return FALSE;
}

void NyxthraFlashback_OnBattleEnded(void)
{
    sFlashbackBattleActive = FALSE;
    sFlashbackActionMenus = 0;
    sFlashbackAutoTimer = 0;
    sFlashbackBattleTextTimer = 0;
    sFlashbackCountThisMenu = TRUE;
}

void NyxthraFlashback_BeginAbortBattle(void)
{
    if (!sFlashbackBattleActive)
        return;

    gBattleOutcome = B_OUTCOME_WON;
    if (!gPaletteFade.active)
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    SetMainCallback2(CB2_QuitRecordedBattle);
}


void NyxthraFlashback_ProcessBattleInput(void)
{
    if (!NyxthraFlashback_IsScriptedBattle())
        return;

    if (JOY_NEW(START_BUTTON))
    {
        NyxthraFlashback_Finish();
        return;
    }

    if (gPaletteFade.active)
        return;

    if (sFlashbackBattleTextTimer < 0xFF)
        sFlashbackBattleTextTimer++;
    if (sFlashbackBattleTextTimer >= 45)
    {
        sFlashbackBattleTextTimer = 0;
        gMain.newKeys |= A_BUTTON;
    }
}
