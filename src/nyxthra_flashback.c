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
#include "sprite.h"
#include "battle_scripts.h"
#include "battle_util.h"
#include "battle_interface.h"
#include "battle_setup.h"
#include "constants/moves.h"
#include "constants/species.h"
#include "constants/pokemon.h"
#include "constants/items.h"

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
static EWRAM_DATA u8 sFlashbackNosepassMenus = 0;
static EWRAM_DATA u8 sFlashbackBattlePhase = 0;
static EWRAM_DATA bool8 sFlashbackKeepBlack = 0;
static EWRAM_DATA u8 sFlashbackSkipState = 0;

#define FLASHBACK_BATTLE_START  1
#define FLASHBACK_BATTLE_FINISH 2

#define FLASHBACK_SKIP_NONE    0
#define FLASHBACK_SKIP_FADEOUT 1
#define FLASHBACK_SKIP_FADEIN  2
#define FLASHBACK_SKIP_SWITCH  3

static const u8 sText_NickKleinstein[] = _("KLEINSTEIN");
static const u8 sText_NickNasgnet[] = _("NASGNET");

static void Flashback_GiveMoves(struct Pokemon *mon, u16 m0, u16 m1, u16 m2, u16 m3)
{
    SetMonMoveSlot(mon, m0, 0);
    SetMonMoveSlot(mon, m1, 1);
    SetMonMoveSlot(mon, m2, 2);
    SetMonMoveSlot(mon, m3, 3);
}

// Brix tritt in der Arena mit Moorabbel auf Stufe 16 an. Level und KP
// kommen aus CreateMon/CalculateMonStats, keine künstlichen Werte.

static void Flashback_SetCurrentHpFraction(struct Pokemon *mon, u32 num, u32 den)
{
    u16 max = GetMonData(mon, MON_DATA_MAX_HP);
    u16 cur;
    if (max < 2)
        return;
    cur = (u16)((max * num) / den);
    if (cur < 1)
        cur = 1;
    if (cur >= max)
        cur = max - 1;
    SetMonData(mon, MON_DATA_HP, &cur);
}

static void Flashback_GivePlayerMarshtomp(void)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][0];
    u32 i;

    ZeroPlayerPartyMons();
    for (i = 1; i < PARTY_SIZE; i++)
        ZeroMonData(&gParties[B_TRAINER_PLAYER][i]);
    CreateMon(mon, SPECIES_MARSHTOMP, 16, 0, OTID_STRUCT_PLAYER_ID);
    CalculateMonStats(mon);
    Flashback_GiveMoves(mon, MOVE_WATER_GUN, MOVE_MUD_SHOT, MOVE_MUD_SLAP, MOVE_TACKLE);
    gPartiesCount[B_TRAINER_PLAYER] = 1;
}

// Originales Smaragd-Team von Felizia laut pret/pokeemerald:
// Kleinstein Lv12, Kleinstein Lv12, Nasgnet Lv15 (Oranbeere).
// Nicht das Nyxthra-Team (Nacli/Geosali usw.).
static void Flashback_CreateVanillaRoxanneParty(void)
{
    struct Pokemon *party = gParties[B_TRAINER_OPPONENT_A];
    u16 item = ITEM_ORAN_BERRY;
    u32 i;

    for (i = 0; i < PARTY_SIZE; i++)
        ZeroMonData(&party[i]);

    CreateMonWithIVs(&party[0], SPECIES_GEODUDE, 12, 0, OTID_STRUCT_RANDOM_NO_SHINY, 12);
    Flashback_GiveMoves(&party[0], MOVE_TACKLE, MOVE_DEFENSE_CURL, MOVE_ROCK_THROW, MOVE_ROCK_TOMB);
    SetMonData(&party[0], MON_DATA_NICKNAME, sText_NickKleinstein);

    CreateMonWithIVs(&party[1], SPECIES_GEODUDE, 12, 0, OTID_STRUCT_RANDOM_NO_SHINY, 12);
    Flashback_GiveMoves(&party[1], MOVE_TACKLE, MOVE_DEFENSE_CURL, MOVE_ROCK_THROW, MOVE_ROCK_TOMB);
    SetMonData(&party[1], MON_DATA_NICKNAME, sText_NickKleinstein);

    CreateMonWithIVs(&party[2], SPECIES_NOSEPASS, 15, 0, OTID_STRUCT_RANDOM_NO_SHINY, 24);
    Flashback_GiveMoves(&party[2], MOVE_BLOCK, MOVE_HARDEN, MOVE_TACKLE, MOVE_ROCK_TOMB);
    SetMonData(&party[2], MON_DATA_HELD_ITEM, &item);
    SetMonData(&party[2], MON_DATA_NICKNAME, sText_NickNasgnet);

    gPartiesCount[B_TRAINER_OPPONENT_A] = 3;
}

bool8 NyxthraFlashback_IsActive(void)
{
    return sFlashbackActive;
}

bool8 NyxthraFlashback_ShouldKeepScreenBlack(void)
{
    return (sFlashbackActive && sFlashbackKeepBlack);
}

void NyxthraFlashback_ClearKeepScreenBlack(void)
{
    sFlashbackKeepBlack = FALSE;
}

void NyxthraFlashback_ApplyDreamTint(void)
{
    u32 i;
    u16 *pal;

    if (!sFlashbackActive)
        return;

    if (sFlashbackKeepBlack)
    {
        CpuFastFill16(RGB_BLACK, gPlttBufferFaded, PLTT_SIZE);
        return;
    }

    // Während einer Überblendung die Palette nicht überschreiben.
    if (gPaletteFade.active
     || sFlashbackSkipState == FLASHBACK_SKIP_FADEOUT
     || sFlashbackSkipState == FLASHBACK_SKIP_FADEIN)
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
    sFlashbackKeepBlack = FALSE;
    sFlashbackSkipState = 0;

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
    sFlashbackNosepassMenus = 0;
    sFlashbackBattlePhase = FLASHBACK_BATTLE_START;
    sFlashbackCountThisMenu = TRUE;

    Flashback_GivePlayerMarshtomp();
}

void NyxthraFlashback_PrepareScriptedBattleFinish(void)
{
    if (!sFlashbackActive)
        return;

    // Ende: Moorabbel ist angeschlagen, nur noch Nasgnet, eine letzte Aquaknarre.
    sFlashbackPlayerMove = MOVE_WATER_GUN;
    sFlashbackOpponentMove = MOVE_ROCK_TOMB;
    sFlashbackMaxTurns = 1;
    sFlashbackBattleActive = TRUE;
    sFlashbackActionMenus = 0;
    sFlashbackAutoTimer = 0;
    sFlashbackBattleTextTimer = 0;
    sFlashbackNosepassMenus = 0;
    sFlashbackBattlePhase = FLASHBACK_BATTLE_FINISH;
    sFlashbackCountThisMenu = TRUE;

    Flashback_GivePlayerMarshtomp();
    Flashback_SetCurrentHpFraction(&gParties[B_TRAINER_PLAYER][0], 1, 3);
}

void NyxthraFlashback_OnTrainerPartyCreated(void)
{
    if (!sFlashbackBattleActive)
        return;

    if (sFlashbackBattlePhase == FLASHBACK_BATTLE_FINISH)
    {
        struct Pokemon *party = gParties[B_TRAINER_OPPONENT_A];
        u32 i;

        for (i = 0; i < PARTY_SIZE; i++)
            ZeroMonData(&party[i]);
        CreateMonWithIVs(&party[0], SPECIES_NOSEPASS, 15, 0, OTID_STRUCT_RANDOM_NO_SHINY, 24);
        Flashback_GiveMoves(&party[0], MOVE_BLOCK, MOVE_HARDEN, MOVE_TACKLE, MOVE_ROCK_TOMB);
        SetMonData(&party[0], MON_DATA_NICKNAME, sText_NickNasgnet);
        // Wenig KP, keine Beere: eine Aquaknarre soll den Kampf beenden.
        {
            u16 hp = 8;
            SetMonData(&party[0], MON_DATA_HP, &hp);
        }
        gPartiesCount[B_TRAINER_OPPONENT_A] = 1;
        return;
    }

    Flashback_CreateVanillaRoxanneParty();
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

static u16 Flashback_OpponentSpecies(void)
{
    return gBattleMons[GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)].species;
}

void NyxthraFlashback_NotePlayerActionMenu(void)
{
    // Nur einmal pro Aktionsmenü zählen, nicht jeden Frame.
    if (!sFlashbackCountThisMenu)
        return;

    if (sFlashbackActionMenus < 0xFF)
        sFlashbackActionMenus++;
    if (Flashback_OpponentSpecies() == SPECIES_NOSEPASS && sFlashbackNosepassMenus < 0xFF)
        sFlashbackNosepassMenus++;
    sFlashbackCountThisMenu = FALSE;
}

bool8 NyxthraFlashback_ShouldAbortBattle(void)
{
    if (sFlashbackBattlePhase == FLASHBACK_BATTLE_FINISH)
        return FALSE; // Natürlicher Sieg nach der letzten Attacke

    // Startphase: nach einer Runde (eine Attacke je Seite) ausblenden.
    if (sFlashbackActionMenus > 1)
        return TRUE;
    return FALSE;
}

bool8 NyxthraFlashback_PreventFaint(void)
{
    return (sFlashbackActive && sFlashbackBattleActive
         && sFlashbackBattlePhase == FLASHBACK_BATTLE_START);
}

void NyxthraFlashback_ClampMoveDamage(u32 battler)
{
    u16 hp;
    u16 minRemain;

    if (!NyxthraFlashback_PreventFaint())
        return;
    if (gBattleStruct->moveDamage[battler] <= 0)
        return;

    hp = gBattleMons[battler].hp;
    if (hp <= 1)
        return;

    // Sichtbar überleben, nicht bei 1 KP wie nach einem K.O. aussehen.
    minRemain = hp / 2;
    if (minRemain < 1)
        minRemain = 1;
    if (gBattleStruct->moveDamage[battler] > (s32)(hp - minRemain))
        gBattleStruct->moveDamage[battler] = hp - minRemain;
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
    sFlashbackNosepassMenus = 0;
    sFlashbackBattlePhase = 0;
    sFlashbackCountThisMenu = TRUE;
    sFlashbackSkipState = 0;
}


static void Flashback_ApplyTimeSkipState(void)
{
    enum BattlerId player = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
    enum BattlerId opp = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);
    struct Pokemon *oppParty = gParties[B_TRAINER_OPPONENT_A];
    struct Pokemon *playerMon = &gParties[B_TRAINER_PLAYER][gBattlerPartyIndexes[player]];
    u32 i;
    u16 hp;
    u16 noItem = ITEM_NONE;

    // Beide Kleinstein sind im Zeitsprung besiegt, Nasgnet bleibt mit wenig KP.
    for (i = 0; i < PARTY_SIZE; i++)
    {
        u16 species = GetMonData(&oppParty[i], MON_DATA_SPECIES);
        if (species == SPECIES_GEODUDE)
        {
            hp = 0;
            SetMonData(&oppParty[i], MON_DATA_HP, &hp);
        }
        else if (species == SPECIES_NOSEPASS)
        {
            hp = 8;
            SetMonData(&oppParty[i], MON_DATA_HP, &hp);
            SetMonData(&oppParty[i], MON_DATA_HELD_ITEM, &noItem);
        }
    }

    gBattleMons[opp].hp = 0;
    gHitMarker |= HITMARKER_FAINTED(opp);

    Flashback_SetCurrentHpFraction(playerMon, 1, 3);
    gBattleMons[player].hp = GetMonData(playerMon, MON_DATA_HP);
    UpdateHealthboxAttribute(gHealthboxSpriteIds[player], playerMon, HEALTHBOX_ALL);

    // Kleinstein nicht mehr sichtbar, wenn wir wieder einblenden.
    if (gBattlerSpriteIds[opp] != 0xFF)
        gSprites[gBattlerSpriteIds[opp]].invisible = TRUE;
    if (gHealthboxSpriteIds[opp] != 0xFF)
        gSprites[gHealthboxSpriteIds[opp]].invisible = TRUE;
}

static void Flashback_StartNasgnetSwitchIn(void)
{
    enum BattlerId opp = GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT);

    gBattlerFainted = gBattlerTarget = opp;
    gHitMarker |= HITMARKER_FAINTED(opp);
    gBattleOutcome = 0;
    gBattleScripting.battleStyle = OPTIONS_BATTLE_STYLE_SET;
    gBattleControllerExecFlags = 0;
    sFlashbackBattlePhase = FLASHBACK_BATTLE_FINISH;
    {
        enum BattlerId i;
        for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        {
            if (!IsOnPlayerSide(i))
                gChosenActionByBattler[i] = B_ACTION_FINISHED;
        }
    }
    BattleScriptExecute(BattleScript_HandleFaintedMon);
}

void NyxthraFlashback_BeginTimeSkip(void)
{
    if (!sFlashbackBattleActive || sFlashbackSkipState != FLASHBACK_SKIP_NONE)
        return;

    sFlashbackSkipState = FLASHBACK_SKIP_FADEOUT;
    gBattle_BG0_Y = 0;
    TryHideLastUsedBall();
    // Gegner hat für diese (abgebrochene) Runde schon eine Attacke gewählt.
    {
        enum BattlerId i;
        for (i = 0; i < MAX_BATTLERS_COUNT; i++)
        {
            if (!IsOnPlayerSide(i))
                gChosenActionByBattler[i] = B_ACTION_FINISHED;
        }
    }
    if (!gPaletteFade.active)
        BeginNormalPaletteFade(PALETTES_ALL, 2, 0, 16, RGB_BLACK);
}

bool8 NyxthraFlashback_IsTimeSkipping(void)
{
    return (sFlashbackSkipState == FLASHBACK_SKIP_FADEOUT
         || sFlashbackSkipState == FLASHBACK_SKIP_FADEIN);
}

void NyxthraFlashback_BeginAbortBattle(void)
{
    if (!sFlashbackBattleActive)
        return;

    gBattleOutcome = B_OUTCOME_WON;
    sFlashbackKeepBlack = TRUE;
    if (!gPaletteFade.active)
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    SetMainCallback2(CB2_QuitRecordedBattle);
}


void NyxthraFlashback_ProcessBattleInput(void)
{
    if (!sFlashbackActive)
        return;

    if (JOY_NEW(START_BUTTON))
    {
        NyxthraFlashback_Finish();
        return;
    }

    if (sFlashbackSkipState == FLASHBACK_SKIP_FADEOUT)
    {
        if (!gPaletteFade.active)
        {
            Flashback_ApplyTimeSkipState();
            sFlashbackSkipState = FLASHBACK_SKIP_FADEIN;
            BeginNormalPaletteFade(PALETTES_ALL, 2, 16, 0, RGB_BLACK);
        }
        return;
    }
    if (sFlashbackSkipState == FLASHBACK_SKIP_FADEIN)
    {
        if (!gPaletteFade.active)
        {
            sFlashbackSkipState = FLASHBACK_SKIP_NONE;
            Flashback_StartNasgnetSwitchIn();
        }
        return;
    }

    if (!NyxthraFlashback_IsScriptedBattle())
        return;

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
