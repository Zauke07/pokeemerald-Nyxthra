#include "global.h"
#include "main.h"
#include "task.h"
#include "bg.h"
#include "malloc.h"
#include "window.h"
#include "text.h"
#include "menu.h"
#include "international_string_util.h"
#include "palette.h"
#include "sprite.h"
#include "sound.h"
#include "gpu_regs.h"
#include "m4a.h"
#include "rayquaza_scene.h"
#include "main_menu.h"
#include "nyxthra_prologue.h"
#include "intro.h"
#include "decompress.h"
#include "graphics.h"
#include "battle_transition.h"
#include "event_object_movement.h"
#include "constants/event_objects.h"
#include "constants/rgb.h"
#include "constants/songs.h"
#include "constants/species.h"
#include "constants/sound.h"

/*
    Nyxthra story prologue - shown once, before Birch's speech, on every
    "start a new game" path (see MainMenu_BeginBirchSpeechScene in
    main_menu.c). Deliberately built the same way the existing intro/credits
    screens are (its own BG + borderless text window, own task chain, no map
    or script engine involved) since no save file exists yet at this point.

    Minimal first version:
      black screen -> "Vor vielen Jahren..." -> Groudon/Kyogre/Rayquaza
      (reusing the original Emerald cutscene as-is) -> mysterious energy
      burst -> "Jahre vergingen." / "Hoenn begann sich zu veraendern." ->
      title card -> hand off to Birch's speech.

    Deliberately silent on what the energy actually was, and the hero from
    that day is never shown (matches the later per-player-gender Champion
    reveal - see IsChampionMay() in overworld.c).
*/

#define tState   data[0]
#define tTimer   data[1]
#define tCardIdx data[2]

struct PrologueCard
{
    const u8 *line1;
    const u8 *line2; // NULL if the card is only one line
};

static const u8 sText_Prologue_Intro1[] = _("Vor vielen Jahren…");
static const u8 sText_Prologue_Intro2[] = _("…stand Hoenn kurz vor der");
static const u8 sText_Prologue_Intro2b[] = _("vollkommenen Vernichtung.");
static const u8 sText_Prologue_Mystery[] = _("Doch niemand wusste, was an diesem Tag");
static const u8 sText_Prologue_Mysteryb[] = _("wirklich freigesetzt wurde.");
static const u8 sText_Prologue_YearsPassed[] = _("Jahre vergingen.");
static const u8 sText_Prologue_HoennChanges[] = _("Und Hoenn begann sich zu verändern.");

static const struct PrologueCard sIntroCards[] =
{
    { sText_Prologue_Intro1, NULL },
    { sText_Prologue_Intro2, sText_Prologue_Intro2b },
};

static const struct PrologueCard sOutroCards[] =
{
    { sText_Prologue_Mystery, sText_Prologue_Mysteryb },
    { sText_Prologue_YearsPassed, NULL },
    { sText_Prologue_HoennChanges, NULL },
};

// Nyxthra story: closing title card. Reuses the real title screen's own
// "POKEMON" logo (affine BG2) and version banner graphics/positions (see
// title_screen.c) instead of plain text - just without its build-up
// animation, Rayquaza backdrop or clouds; it simply fades in already settled.
#define TAG_PROLOGUE_VERSION_BANNER 30600

static const struct OamData sPrologueVersionBannerOamData =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_8BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sPrologueVersionBannerLeftAnimSeq[] = { ANIMCMD_FRAME(0, 30), ANIMCMD_END };
static const union AnimCmd sPrologueVersionBannerRightAnimSeq[] = { ANIMCMD_FRAME(64, 30), ANIMCMD_END };
static const union AnimCmd *const sPrologueVersionBannerLeftAnimTable[] = { sPrologueVersionBannerLeftAnimSeq };
static const union AnimCmd *const sPrologueVersionBannerRightAnimTable[] = { sPrologueVersionBannerRightAnimSeq };

static const struct SpriteTemplate sPrologueVersionBannerLeftTemplate =
{
    .tileTag = TAG_PROLOGUE_VERSION_BANNER,
    .paletteTag = TAG_PROLOGUE_VERSION_BANNER,
    .oam = &sPrologueVersionBannerOamData,
    .anims = sPrologueVersionBannerLeftAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sPrologueVersionBannerRightTemplate =
{
    .tileTag = TAG_PROLOGUE_VERSION_BANNER,
    .paletteTag = TAG_PROLOGUE_VERSION_BANNER,
    .oam = &sPrologueVersionBannerOamData,
    .anims = sPrologueVersionBannerRightAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct CompressedSpriteSheet sPrologueVersionBannerSpriteSheet[] =
{
    { .data = gTitleScreenNyxthraVersionGfx, .size = 0x1000, .tag = TAG_PROLOGUE_VERSION_BANNER },
    {},
};

#define VERSION_BANNER_LEFT_X  98
#define VERSION_BANNER_RIGHT_X 162
#define VERSION_BANNER_Y_GOAL  66

// Palette: 0 backdrop/transparent, 1 white text, 2 dark gray shadow.
static const u16 sPrologueTextPal[] = { RGB_BLACK, RGB(28, 28, 28), RGB(12, 12, 12) };

static const struct BgTemplate sPrologueBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 28,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
};

static const struct WindowTemplate sPrologueWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 0,
        .width = DISPLAY_TILE_WIDTH,
        .height = DISPLAY_TILE_HEIGHT,
        .paletteNum = 8,
        .baseBlock = 1,
    },
    DUMMY_WIN_TEMPLATE,
};

static void Task_Prologue_IntroCards(u8 taskId);
static void Task_Prologue_OutroCards(u8 taskId);
static void Task_Prologue_LegendaryEnergyScene(u8 taskId);
static void Task_Prologue_TitleLogo(u8 taskId);
static void CB2_NyxthraPrologue_AfterRayquaza(void);

static void VBlankCB_NyxthraPrologue(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void CB2_NyxthraPrologue(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void InitPrologueBgAndWindow(void)
{
    // Blank the display first and hold it there until everything below is
    // fully set up - otherwise whatever was on screen right before this call
    // (the main menu, or Rayquaza's own cutscene BGs) can flash through for
    // a frame or two while we're still resetting things. LoadPalette() alone
    // only updates the buffered palette (applied at the next VBlank transfer,
    // which is why it wasn't enough on its own); the raw DMA fill forces the
    // actual palette RAM to black immediately, the same way credits.c and
    // the title screen itself do it on entry.
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);
    LoadPalette(&(u16){RGB_BLACK}, BG_PLTT_ID(0), sizeof(u16)); // pin the backdrop color to black too
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sPrologueBgTemplates, ARRAY_COUNT(sPrologueBgTemplates));
    SetBgTilemapBuffer(0, AllocZeroed(BG_SCREEN_SIZE));
    LoadPalette(sPrologueTextPal, BG_PLTT_ID(8), sizeof(sPrologueTextPal));
    InitWindows(sPrologueWindowTemplates);
    DeactivateAllTextPrinters();
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
    ShowBg(0);
}

static void FreePrologueBgAndWindow(void)
{
    void *ptr;
    FreeAllWindowBuffers();
    ptr = GetBgTilemapBuffer(0);
    if (ptr)
        Free(ptr);
}

static void PrintPrologueLine(const u8 *string, u8 y)
{
    u8 x;
    u8 color[3];

    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_COLOR_WHITE;
    color[2] = TEXT_COLOR_DARK_GRAY;

    x = GetStringCenterAlignXOffsetWithLetterSpacing(FONT_NORMAL, string, DISPLAY_WIDTH, 1);
    AddTextPrinterParameterized4(0, FONT_NORMAL, x, y, 1, 0, color, TEXT_SKIP_DRAW, string);
}

static void ShowPrologueCard(const struct PrologueCard *card)
{
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    if (card->line2 == NULL)
    {
        PrintPrologueLine(card->line1, 76);
    }
    else
    {
        PrintPrologueLine(card->line1, 68);
        PrintPrologueLine(card->line2, 84);
    }
    CopyWindowToVram(0, COPYWIN_FULL);
}

// Generic "fade up on the card's text, wait for input or a timeout, fade back
// to black" driver shared by the intro and outro card sequences. tState/
// tTimer/tCardIdx are reused; the card table + what to do when the list ends
// differ, so this only handles a single card and the caller's task func
// decides what happens next.
//
// The text is printed *before* the fade-in starts (not after it finishes) -
// that way the fade-in is the actual reveal, and there's never a moment
// where the previous card's now-stale text is still sitting in the window
// while the screen brightens back up.
enum
{
    CARD_STATE_FADE_IN,
    CARD_STATE_WAIT,
    CARD_STATE_FADE_OUT,
    CARD_STATE_DONE,
};

static bool8 RunPrologueCard(u8 taskId, const struct PrologueCard *card)
{
    switch (gTasks[taskId].tState)
    {
    case CARD_STATE_FADE_IN:
        ShowPrologueCard(card);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].tState = CARD_STATE_WAIT;
        break;
    case CARD_STATE_WAIT:
        if (!gPaletteFade.active)
        {
            gTasks[taskId].tTimer++;
            if (JOY_NEW(A_BUTTON | B_BUTTON | START_BUTTON) || gTasks[taskId].tTimer > 240)
                gTasks[taskId].tState = CARD_STATE_FADE_OUT;
        }
        break;
    case CARD_STATE_FADE_OUT:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].tState = CARD_STATE_DONE;
        break;
    case CARD_STATE_DONE:
        if (!gPaletteFade.active)
        {
            gTasks[taskId].tState = CARD_STATE_FADE_IN;
            return TRUE; // this card is finished, caller should advance
        }
        break;
    }
    return FALSE;
}

static void Task_Prologue_IntroCards(u8 taskId)
{
    if (RunPrologueCard(taskId, &sIntroCards[gTasks[taskId].tCardIdx]))
    {
        gTasks[taskId].tCardIdx++;
        if (gTasks[taskId].tCardIdx >= ARRAY_COUNT(sIntroCards))
        {
            DestroyTask(taskId);
            FreePrologueBgAndWindow();
            // Groudon vs. Kyogre, then Rayquaza steps in to separate them -
            // reusing Emerald's own cutscene engine verbatim (see
            // rayquaza_scene.c). animId 1 (RAY_ANIM_DUO_FIGHT) with
            // endEarly=FALSE runs the whole chain through Rayquaza chasing
            // them off on its own; we pick back up in the exit callback.
            DoRayquazaScene(1, FALSE, CB2_NyxthraPrologue_AfterRayquaza);
        }
    }
}

#define tBurstStep    tTimer
#define tGroudonSprite data[3]
#define tKyogreSprite  data[4]
#define tRayquazaSprite data[5]
#define tFlashCount    data[6]

// Nyxthra story: the original Rayquaza cutscene ends and looks like the
// disaster is over - then this scene shows all three legendaries reacting
// together to something new, escalating into the mysterious energy burst.
// Kept deliberately silent on what that energy actually is (see file header).
//
// Built entirely from existing assets: the three legendaries are shown as
// the same small overworld object sprites the Sootopolis City encounter
// scene uses (CreateObjectGraphicsSprite, OBJ_EVENT_GFX_GROUDON_SIDE /
// _KYOGRE_SIDE / _RAYQUAZA) rather than trying to re-stage rayquaza_scene.c's
// own purpose-built animation pieces, which are cut for very specific
// dramatic angles and don't necessarily belong together in a calm group
// shot. Their own official battle-intro transitions (BattleTransition_Start,
// normally played right before you fight one of them) are reused for each
// one's "something's wrong" reaction - that call is already fully decoupled
// from actually starting a battle, it's purely the visual task, so no battle
// ever gets set up here.
enum
{
    LEGENDARY_STATE_SHOW_TRIO,
    LEGENDARY_STATE_CALM,
    LEGENDARY_STATE_GROUDON_CRY,
    LEGENDARY_STATE_GROUDON_TRANSITION,
    LEGENDARY_STATE_GROUDON_TRANSITION_WAIT,
    LEGENDARY_STATE_KYOGRE_CRY,
    LEGENDARY_STATE_KYOGRE_TRANSITION,
    LEGENDARY_STATE_KYOGRE_TRANSITION_WAIT,
    LEGENDARY_STATE_RAYQUAZA_CRY,
    LEGENDARY_STATE_RAYQUAZA_TRANSITION,
    LEGENDARY_STATE_RAYQUAZA_TRANSITION_WAIT,
    LEGENDARY_STATE_REGROUP,
    LEGENDARY_STATE_ESCALATE_FLASHES,
    LEGENDARY_STATE_SHAKE,
    LEGENDARY_STATE_FINAL_FLASH,
    LEGENDARY_STATE_HOLD_WHITE,
    LEGENDARY_STATE_FADE_BLACK,
    LEGENDARY_STATE_DONE,
};

#define LEGENDARY_GROUDON_X   72
#define LEGENDARY_GROUDON_Y   110
#define LEGENDARY_KYOGRE_X   168
#define LEGENDARY_KYOGRE_Y   110
#define LEGENDARY_RAYQUAZA_X 120
#define LEGENDARY_RAYQUAZA_Y  50

// (Re)draws the calm black backdrop + all three legendaries in their group
// shot positions. Needs to be called again after every BattleTransition_Start
// call below - those own the whole screen while they run and don't restore
// whatever was on screen before them (same as when they lead into a real
// battle, which is always a full fresh scene right after).
static void ShowLegendaryTrio(u8 taskId)
{
    // This is called repeatedly (once per legendary redraw), and
    // InitPrologueBgAndWindow() unconditionally allocates a fresh BG
    // tilemap buffer and window buffers every time - without freeing the
    // previous set first, each redraw permanently leaked one of each.
    FreePrologueBgAndWindow();
    InitPrologueBgAndWindow();
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON);
    ResetSpriteData();
    FreeAllSpritePalettes();
    // Nyxthra story: shown as the same small overworld object sprites used in
    // Sootopolis City's own Groudon/Kyogre/Rayquaza encounter (not the big
    // front-facing battle portraits) - matches how that scene actually looks
    // in-game instead of a mismatched "battle screen" composition.
    gTasks[taskId].tGroudonSprite = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_GROUDON_SIDE,
        SpriteCallbackDummy, LEGENDARY_GROUDON_X, LEGENDARY_GROUDON_Y, 0);
    // sAnimTable_GroudonSide (object_event_anims.h) maps FACE_SOUTH/NORTH/
    // WEST all to the exact same unflipped source frame - only FACE_EAST
    // actually differs (same frame, hFlip applied). So the default (=WEST,
    // visually) never looked any different no matter which of those three
    // was picked; EAST is the only one that actually mirrors it to face
    // the other way, toward Kyogre.
    StartSpriteAnim(&gSprites[gTasks[taskId].tGroudonSprite], ANIM_STD_FACE_EAST);
    gTasks[taskId].tKyogreSprite = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_KYOGRE_SIDE,
        SpriteCallbackDummy, LEGENDARY_KYOGRE_X, LEGENDARY_KYOGRE_Y, 1);
    gTasks[taskId].tRayquazaSprite = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_RAYQUAZA,
        SpriteCallbackDummy, LEGENDARY_RAYQUAZA_X, LEGENDARY_RAYQUAZA_Y, 2);
}

static void Task_Prologue_LegendaryEnergyScene(u8 taskId)
{
    gTasks[taskId].tBurstStep++;
    switch (gTasks[taskId].tState)
    {
    case LEGENDARY_STATE_SHOW_TRIO:
        ShowLegendaryTrio(taskId);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gTasks[taskId].tBurstStep = 0;
        gTasks[taskId].tState = LEGENDARY_STATE_CALM;
        break;
    case LEGENDARY_STATE_CALM: // brief silence - looks like the fight is really over
        if (!gPaletteFade.active && gTasks[taskId].tBurstStep > 60)
        {
            gTasks[taskId].tBurstStep = 0;
            gTasks[taskId].tState = LEGENDARY_STATE_GROUDON_CRY;
        }
        break;

    case LEGENDARY_STATE_GROUDON_CRY:
        PlayCry_Script(SPECIES_GROUDON, CRY_MODE_ENCOUNTER);
        gTasks[taskId].tBurstStep = 0;
        gTasks[taskId].tState = LEGENDARY_STATE_GROUDON_TRANSITION;
        break;
    case LEGENDARY_STATE_GROUDON_TRANSITION:
        if (gTasks[taskId].tBurstStep > 30) // let the cry breathe before the flashy part
        {
            BattleTransition_Start(B_TRANSITION_GROUDON);
            gTasks[taskId].tState = LEGENDARY_STATE_GROUDON_TRANSITION_WAIT;
        }
        break;
    case LEGENDARY_STATE_GROUDON_TRANSITION_WAIT:
        if (IsBattleTransitionDone())
        {
            // The transition tasks swap in their own VBlank callback and never
            // restore it themselves (normally CB2_InitBattle does that right
            // after) - without this, the screen stops updating entirely once
            // the transition ends.
            SetVBlankCallback(VBlankCB_NyxthraPrologue);
            gTasks[taskId].tBurstStep = 0;
            gTasks[taskId].tState = LEGENDARY_STATE_KYOGRE_CRY;
        }
        break;

    case LEGENDARY_STATE_KYOGRE_CRY:
        ShowLegendaryTrio(taskId);
        // A battle transition always ends with the screen faded to black
        // (that's normally left to the real battle scene's own fade-in
        // right after) - without fading back in here, the redraw above is
        // there but invisible, and the scene just looks stuck black.
        // ResetPaletteFade() first because BeginNormalPaletteFade() silently
        // refuses to start a new fade while gPaletteFade.active is already
        // true - and some transitions (Rayquaza's especially, see below)
        // drive gPaletteFade/BlendPalettes directly as part of their own
        // choreography, so it can still read as "active" here otherwise.
        ResetPaletteFade();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        PlayCry_Script(SPECIES_KYOGRE, CRY_MODE_ENCOUNTER);
        gTasks[taskId].tBurstStep = 0;
        gTasks[taskId].tState = LEGENDARY_STATE_KYOGRE_TRANSITION;
        break;
    case LEGENDARY_STATE_KYOGRE_TRANSITION:
        if (!gPaletteFade.active && gTasks[taskId].tBurstStep > 30)
        {
            BattleTransition_Start(B_TRANSITION_KYOGRE);
            gTasks[taskId].tState = LEGENDARY_STATE_KYOGRE_TRANSITION_WAIT;
        }
        break;
    case LEGENDARY_STATE_KYOGRE_TRANSITION_WAIT:
        if (IsBattleTransitionDone())
        {
            SetVBlankCallback(VBlankCB_NyxthraPrologue);
            gTasks[taskId].tBurstStep = 0;
            gTasks[taskId].tState = LEGENDARY_STATE_RAYQUAZA_CRY;
        }
        break;

    case LEGENDARY_STATE_RAYQUAZA_CRY:
        ShowLegendaryTrio(taskId);
        ResetPaletteFade();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        PlayCry_Script(SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER);
        gTasks[taskId].tBurstStep = 0;
        gTasks[taskId].tState = LEGENDARY_STATE_RAYQUAZA_TRANSITION;
        break;
    case LEGENDARY_STATE_RAYQUAZA_TRANSITION:
        if (!gPaletteFade.active && gTasks[taskId].tBurstStep > 30)
        {
            BattleTransition_Start(B_TRANSITION_RAYQUAZA);
            gTasks[taskId].tState = LEGENDARY_STATE_RAYQUAZA_TRANSITION_WAIT;
        }
        break;
    case LEGENDARY_STATE_RAYQUAZA_TRANSITION_WAIT:
        if (IsBattleTransitionDone())
        {
            // Rayquaza's own transition (VBlankCB_Rayquaza) is the one that
            // actually needs this - without it the screen stayed black and
            // frozen forever right here.
            SetVBlankCallback(VBlankCB_NyxthraPrologue);
            gTasks[taskId].tBurstStep = 0;
            gTasks[taskId].tState = LEGENDARY_STATE_REGROUP;
        }
        break;

    case LEGENDARY_STATE_REGROUP: // all three back on screen - now their energies start reacting to each other
        if (gTasks[taskId].tBurstStep == 1) // first frame of this state - redraw and fade back in once
        {
            ShowLegendaryTrio(taskId);
            // This is the fade-in right after Rayquaza's own transition,
            // which is the one that actually needs the ResetPaletteFade()
            // safety call (see KYOGRE_CRY above) - Rayquaza_WaitFade/
            // Rayquaza_SetBlack in battle_transition.c drive gPaletteFade
            // and BlendPalettes directly through several phases of their
            // own, and without this the fade below was silently rejected
            // and the scene never got past this point at all.
            ResetPaletteFade();
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        }
        else if (!gPaletteFade.active && gTasks[taskId].tBurstStep > 20)
        {
            // Reset tBurstStep right as we hand off to ESCALATE_FLASHES, since
            // that state's first pulse relies on catching tBurstStep == 1 on
            // its very next frame - waiting on the fade here first (instead of
            // guessing how many frames it takes) is what keeps that reliable.
            gTasks[taskId].tBurstStep = 0;
            gTasks[taskId].tFlashCount = 0;
            gTasks[taskId].tState = LEGENDARY_STATE_ESCALATE_FLASHES;
        }
        break;
    case LEGENDARY_STATE_ESCALATE_FLASHES: // a handful of quick, tightening white pulses
        if (!gPaletteFade.active)
        {
            if (gTasks[taskId].tFlashCount >= 5)
            {
                gTasks[taskId].tBurstStep = 0;
                gTasks[taskId].tState = LEGENDARY_STATE_SHAKE;
            }
            else if (gTasks[taskId].tBurstStep == 1) // tBurstStep was just reset to 0 by the caller and already incremented once above
            {
                PlaySE(SE_ICE_CRACK);
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 10, RGB_WHITEALPHA);
            }
            else if (gTasks[taskId].tBurstStep >= (12 - gTasks[taskId].tFlashCount * 2))
            {
                BeginNormalPaletteFade(PALETTES_ALL, 0, 10, 0, RGB_WHITEALPHA);
                gTasks[taskId].tBurstStep = 0;
                gTasks[taskId].tFlashCount++;
            }
        }
        break;
    case LEGENDARY_STATE_SHAKE: // screen shake while the energy visibly gathers
        if (gTasks[taskId].tBurstStep <= 24)
        {
            SetGpuReg(REG_OFFSET_BG0HOFS, ((gTasks[taskId].tBurstStep & 1) ? 3 : -3));
        }
        else
        {
            SetGpuReg(REG_OFFSET_BG0HOFS, 0);
            m4aMPlayStop(&gMPlayInfo_BGM);
            PlaySE(SE_M_MEGA_KICK); // dull, heavy impact sound
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_WHITEALPHA);
            gTasks[taskId].tBurstStep = 0;
            gTasks[taskId].tState = LEGENDARY_STATE_HOLD_WHITE;
        }
        break;
    case LEGENDARY_STATE_HOLD_WHITE: // hold on the white flash, then cut to black (fading TO black, not from it)
        if (!gPaletteFade.active && gTasks[taskId].tBurstStep > 30)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].tBurstStep = 0;
            gTasks[taskId].tState = LEGENDARY_STATE_FADE_BLACK;
        }
        break;
    case LEGENDARY_STATE_FADE_BLACK:
        if (!gPaletteFade.active)
        {
            // Nyxthra story: this is where the "something was released that
            // day" beat lands - a thunderclap (echoing the storm from the
            // fight) and a somber score picking up, both carrying through
            // the rest of the prologue.
            PlaySE(SE_THUNDER);
            m4aSongNumStart(MUS_DP_OLD_CHATEAU);
            // The trio's 3 object sprites are never otherwise destroyed -
            // only ever recreated on top of a ResetSpriteData() call inside
            // ShowLegendaryTrio() - so without this they silently stayed on
            // screen (invisible here since we're faded to black, but back
            // once the outro cards/title logo fade back in).
            ResetSpriteData();
            FreeAllSpritePalettes();
            gTasks[taskId].tState = 0;
            gTasks[taskId].tCardIdx = 0;
            gTasks[taskId].func = Task_Prologue_OutroCards;
        }
        break;
    }
}

static void Task_Prologue_OutroCards(u8 taskId)
{
    if (RunPrologueCard(taskId, &sOutroCards[gTasks[taskId].tCardIdx]))
    {
        gTasks[taskId].tCardIdx++;
        if (gTasks[taskId].tCardIdx >= ARRAY_COUNT(sOutroCards))
        {
            gTasks[taskId].tState = 0;
            gTasks[taskId].func = Task_Prologue_TitleLogo;
        }
    }
}

static void ShowPrologueTitleLogo(void)
{
    HideBg(0);

    // BG2 (affine, 256-color): the real "POKEMON" logo, at the exact resting
    // zoom/position the actual title screen settles into (see
    // CB2_InitTitleScreen in title_screen.c) - just shown directly instead
    // of animating there, and without its Rayquaza/cloud backdrop.
    DecompressDataWithHeaderVram(gTitleScreenPokemonLogoGfx, (void *)(BG_CHAR_ADDR(0)));
    DecompressDataWithHeaderVram(gTitleScreenPokemonLogoTilemap, (void *)(BG_SCREEN_ADDR(9)));
    LoadPalette(gTitleScreenBgPalettes, BG_PLTT_ID(0), 15 * PLTT_SIZE_4BPP);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(1) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(9) | BGCNT_256COLOR | BGCNT_AFF256x256);
    PanFadeAndZoomScreen(DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, 0x100, 0);
    SetGpuReg(REG_OFFSET_BG2X_L, -29 * 256);
    SetGpuReg(REG_OFFSET_BG2X_H, -1);
    // The real title screen starts the logo here (BG2Y = -32*256) and then
    // slides it up to BG2Y = 0 right after the shine animation, to make room
    // for the version banner below it - we want that settled/shifted-up
    // position directly, not the pre-shift one.
    SetGpuReg(REG_OFFSET_BG2Y_L, 0);
    SetGpuReg(REG_OFFSET_BG2Y_H, 0);

    // The "...VERSION" banner - same graphic as the real title screen, shown
    // directly at its settled resting spot instead of sliding in.
    LoadCompressedSpriteSheet(&sPrologueVersionBannerSpriteSheet[0]);
    LoadPalette(gTitleScreenNyxthraVersionPal, OBJ_PLTT_ID(0), PLTT_SIZE_4BPP);
    CreateSprite(&sPrologueVersionBannerLeftTemplate, VERSION_BANNER_LEFT_X, VERSION_BANNER_Y_GOAL, 0);
    CreateSprite(&sPrologueVersionBannerRightTemplate, VERSION_BANNER_RIGHT_X, VERSION_BANNER_Y_GOAL, 0);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG2_ON | DISPCNT_OBJ_ON);
}

static void Task_Prologue_TitleLogo(u8 taskId)
{
    switch (gTasks[taskId].tState)
    {
    case CARD_STATE_FADE_IN:
        ShowPrologueTitleLogo();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].tState = CARD_STATE_WAIT;
        break;
    case CARD_STATE_WAIT:
        if (!gPaletteFade.active)
        {
            gTasks[taskId].tTimer++;
            if (JOY_NEW(A_BUTTON | B_BUTTON | START_BUTTON) || gTasks[taskId].tTimer > 240)
                gTasks[taskId].tState = CARD_STATE_FADE_OUT;
        }
        break;
    case CARD_STATE_FADE_OUT:
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].tState = CARD_STATE_DONE;
        break;
    case CARD_STATE_DONE:
        if (!gPaletteFade.active)
        {
            DestroyTask(taskId);
            FreePrologueBgAndWindow();
            MainMenu_StartBirchSpeechDirect();
        }
        break;
    }
}

static void CB2_NyxthraPrologue_AfterRayquaza(void)
{
    u8 taskId;

    SetVBlankCallback(NULL);
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetPaletteFade();
    ResetTasks();
    InitPrologueBgAndWindow();

    EnableInterrupts(INTR_FLAG_VBLANK);
    SetVBlankCallback(VBlankCB_NyxthraPrologue);
    SetMainCallback2(CB2_NyxthraPrologue);

    taskId = CreateTask(Task_Prologue_LegendaryEnergyScene, 0);
    gTasks[taskId].tState = 0;
    gTasks[taskId].tBurstStep = 0;
}

void CB2_InitNyxthraPrologue(void)
{
    u8 taskId;

    SetVBlankCallback(NULL);
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetPaletteFade();
    ResetTasks();
    InitPrologueBgAndWindow();

    EnableInterrupts(INTR_FLAG_VBLANK);
    SetVBlankCallback(VBlankCB_NyxthraPrologue);
    SetMainCallback2(CB2_NyxthraPrologue);

    taskId = CreateTask(Task_Prologue_IntroCards, 0);
    gTasks[taskId].tState = CARD_STATE_FADE_IN;
    gTasks[taskId].tCardIdx = 0;
}

#undef tState
#undef tTimer
#undef tCardIdx
#undef tBurstStep
