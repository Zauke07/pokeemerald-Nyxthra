#include "global.h"
#include "main.h"
#include "main_menu.h"
#include "new_game.h"
#include "overworld.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_control_avatar.h"
#include "field_screen_effect.h"
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
#define FLASHBACK_TINT_R Q_8_8(1.15)
#define FLASHBACK_TINT_G Q_8_8(1.00)
#define FLASHBACK_TINT_B Q_8_8(1.22)

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

bool8 NyxthraFlashback_IsActive(void)
{
    return sFlashbackActive;
}

void NyxthraFlashback_ApplyDreamTint(void)
{
    if (!sFlashbackActive)
        return;

    TintPalette_CustomTone(gPlttBufferFaded, PLTT_BUFFER_SIZE, FLASHBACK_TINT_R, FLASHBACK_TINT_G, FLASHBACK_TINT_B);
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
    SetWarpDestination(MAP_GROUP(MAP_ROUTE101), MAP_NUM(MAP_ROUTE101), WARP_ID_NONE, 10, 19);
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
    VarSet(VAR_ROUTE101_STATE, 1);
    Overworld_StartFromNewGameWarp(FieldCB_FlashbackEnter);
}

static void FieldCB_FlashbackEnter(void)
{
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

void NyxthraFlashback_Finish(void)
{
    u8 i;

    if (sFlashbackFinishing)
        return;

    sFlashbackFinishing = TRUE;
    sAutoATimer = 0;
    sAutoAArmed = FALSE;

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
    sFlashbackActive = FALSE;
    sFlashbackFinishing = FALSE;
    DestroyTask(taskId);
    MainMenu_BeginBirchSpeechScene();
}
