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
#include "gba/m4a_internal.h"
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
#include "scanline_effect.h"
#include "trig.h"

/*
    Nyxthra story prologue - shown once, before Birch's speech, on every
    "start a new game" path (see MainMenu_BeginBirchSpeechScene in
    main_menu.c). Deliberately built the same way the existing intro/credits
    screens are (its own BG + borderless text window, own task chain, no map
    or script engine involved) since no save file exists yet at this point.

    Intro 2.0 plays new globe scenes first, then the existing v1 cards
    and cutscenes:
      space + Erde steigt auf ("Hoenn." / "Ein Land im Gleichgewicht.")
      -> Zoom auf Hoenn ("Doch zwei Gewalten ruhten darin: Land und Meer.")
      -> Regen/Dürre wechseln sich auf dem Planeten immer schneller ab
      -> Rayquaza kreist um den Planeten und beendet den Streit
      -> Stille: Sonnenaufgang, "Jahrhunderte vergingen. Man vergaß, was damals erwachte."
      -> Nebel + Herzschlag: "Die Welt begann sich zu verändern … / … und die Pokémon mit ihr."
      -> Augen: "Etwas beobachtet uns." / "Nyxthra.", Darkrai-Blitz, Schwarzes Loch
      -> Titelkarte -> Birchs Rede.

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
    bool8 shake;     // Nyxthra: Bildschirm bebt, sobald die Karte fertig getippt ist
};

static const u8 sText_Prologue_Mystery[] = _("Doch niemand wusste, was an diesem Tag");
static const u8 sText_Prologue_Mysteryb[] = _("wirklich freigesetzt wurde.");

// Nur noch die Mystery-Tafel: "Jahre vergingen." / "Und Hoenn begann
// sich zu verändern." wiederholt Szene 5 und wird in Szene 6 neu erzählt.
static const struct PrologueCard sOutroCards[] =
{
    { sText_Prologue_Mystery, sText_Prologue_Mysteryb, FALSE },
    // Danach folgt der Darkrai-Teaser, danach die Titelkarte.
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

// Palette: 0 backdrop/transparent, 1 white text, 2 dark gray shadow,
// 3/4 Darkrais rote Augen im Teaser.
static const u16 sPrologueTextPal[] = {
    RGB_BLACK, RGB(28, 28, 28), RGB(12, 12, 12), RGB(31, 4, 4), RGB(16, 0, 2),
    RGB(16, 26, 31), RGB(2, 6, 12), // 5/6 Regen
    RGB(31, 22, 6), RGB(12, 5, 0),  // 7/8 Dürre
};

// Nyxthra: violetter Nebel auf BG1 hinter den Texttafeln.
#define PROLOGUE_FOG_PAL 1
#define TEXT_SPEED_PROLOGUE 2
static EWRAM_DATA u8 sPrologueShakeTimer = 0;

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
    {
        .bg = 1,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
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

static void Task_Prologue_OutroCards(u8 taskId);
static void Task_Prologue_TitleLogo(u8 taskId);
static void Task_Prologue_DarkraiTeaser(u8 taskId);
static void Task_Prologue_GlobeScenes(u8 taskId);
static void CB2_NyxthraPrologueGlobe(void);
static void VBlankCB_NyxthraPrologueGlobe(void);
static void InitPrologueGlobeScene(void);
static void StartPrologueIntroCards(u8 taskId);
static void ApplyGlobeAffine(void);
static void PulseGlobeAtmosphere(u16 timer);

static void VBlankCB_NyxthraPrologue(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void UpdatePrologueFogAndShake(void)
{
    // Nebel driftet langsam schräg
    ChangeBgX(1, 40, BG_COORD_ADD);
    ChangeBgY(1, 12, BG_COORD_ADD);

    if (sPrologueShakeTimer != 0)
    {
        sPrologueShakeTimer--;
        if (sPrologueShakeTimer == 0)
        {
            ChangeBgX(0, 0, BG_COORD_SET);
            ChangeBgY(0, 0, BG_COORD_SET);
        }
        else
        {
            ChangeBgX(0, ((sPrologueShakeTimer & 2) ? 3 : -3) << 8, BG_COORD_SET);
            ChangeBgY(0, ((sPrologueShakeTimer & 4) ? 2 : -2) << 8, BG_COORD_SET);
        }
    }
}

static void CB2_NyxthraPrologue(void)
{
    RunTextPrinters();
    UpdatePrologueFogAndShake();
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
    // Reste von Kampfübergängen / Rayquaza-Szene (Fenster, Blending, HBlank) zurücksetzen
    ScanlineEffect_Stop();
    SetHBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WIN1H, 0);
    SetGpuReg(REG_OFFSET_WIN1V, 0);
    sPrologueShakeTimer = 0;
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sPrologueBgTemplates, ARRAY_COUNT(sPrologueBgTemplates));
    SetBgTilemapBuffer(0, AllocZeroed(BG_SCREEN_SIZE));
    {
        // Nyxthra: Nebel-Kacheln (16x16 Kacheln, kachelbar) über die ganze BG1-Map wiederholen
        u16 *fogMap = AllocZeroed(BG_SCREEN_SIZE);
        u32 x, y;
        for (y = 0; y < 32; y++)
            for (x = 0; x < 32; x++)
                fogMap[y * 32 + x] = ((y % 16) * 16 + (x % 16)) | (PROLOGUE_FOG_PAL << 12);
        SetBgTilemapBuffer(1, fogMap);
        LoadBgTiles(1, gNyxthraPrologueFog_Gfx, 16 * 16 * TILE_SIZE_4BPP, 0);
        LoadPalette(gNyxthraPrologueFog_Pal, BG_PLTT_ID(PROLOGUE_FOG_PAL), PLTT_SIZE_4BPP);
        CopyBgTilemapBufferToVram(1);
        ShowBg(1);
    }
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
    ptr = GetBgTilemapBuffer(1);
    if (ptr)
        Free(ptr);
    SetBgTilemapBuffer(1, NULL);
    ptr = GetBgTilemapBuffer(2);
    if (ptr)
        Free(ptr);
    SetBgTilemapBuffer(2, NULL);
}

// Nyxthra: Zeilen erscheinen Buchstabe für Buchstabe (Text-Printer mit Tempo,
// RunTextPrinters() läuft im CB2).
static void PrintPrologueLineTyped(const u8 *string, u8 y)
{
    u8 x;
    u8 color[3];

    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_COLOR_WHITE;
    color[2] = TEXT_COLOR_DARK_GRAY;

    x = GetStringCenterAlignXOffsetWithLetterSpacing(FONT_NORMAL, string, DISPLAY_WIDTH, 1);
    AddTextPrinterParameterized4(0, FONT_NORMAL, x, y, 1, 0, color, TEXT_SPEED_PROLOGUE, string);
}

static void PrintPrologueLineTypedFit(const u8 *string, u8 y)
{
    u8 font = FONT_NORMAL;
    u8 spacing = 1;
    u8 x;
    u8 color[3];

    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = TEXT_COLOR_WHITE;
    color[2] = TEXT_COLOR_DARK_GRAY;

    if (GetStringWidth(FONT_NORMAL, string, 1) > DISPLAY_WIDTH - 4)
    {
        font = FONT_NARROW;
        spacing = 0;
    }
    x = GetStringCenterAlignXOffsetWithLetterSpacing(font, string, DISPLAY_WIDTH, spacing);
    AddTextPrinterParameterized4(0, font, x, y, spacing, 0, color, TEXT_SPEED_PROLOGUE, string);
}

// Generic card driver for the remaining prologue cards: the fog fades in
// while the first line types itself out, then the second line, an optional
// quake, a short hold (A/B/Start skips), and a fade to black.
enum
{
    CARD_STATE_FADE_IN,
    CARD_STATE_TYPE_LINE1,
    CARD_STATE_TYPE_LINE2,
    CARD_STATE_WAIT,
    CARD_STATE_FADE_OUT,
    CARD_STATE_DONE,
};

#define CARD_HOLD_FRAMES 100

static bool8 RunPrologueCard(u8 taskId, const struct PrologueCard *card)
{
    bool8 pressed = JOY_NEW(A_BUTTON | B_BUTTON | START_BUTTON);

    switch (gTasks[taskId].tState)
    {
    case CARD_STATE_FADE_IN:
        DeactivateAllTextPrinters();
        FillWindowPixelBuffer(0, PIXEL_FILL(0));
        CopyWindowToVram(0, COPYWIN_FULL);
        PrintPrologueLineTyped(card->line1, card->line2 == NULL ? 76 : 68);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gTasks[taskId].tTimer = 0;
        gTasks[taskId].tState = CARD_STATE_TYPE_LINE1;
        break;
    case CARD_STATE_TYPE_LINE1:
        if (pressed)
            gTasks[taskId].tState = CARD_STATE_FADE_OUT;
        else if (!IsTextPrinterActiveOnWindow(0))
        {
            if (card->line2 != NULL)
            {
                PrintPrologueLineTyped(card->line2, 84);
                gTasks[taskId].tState = CARD_STATE_TYPE_LINE2;
            }
            else
            {
                gTasks[taskId].tState = CARD_STATE_WAIT;
            }
        }
        break;
    case CARD_STATE_TYPE_LINE2:
        if (pressed)
            gTasks[taskId].tState = CARD_STATE_FADE_OUT;
        else if (!IsTextPrinterActiveOnWindow(0))
        {
            if (card->shake)
            {
                PlaySE(SE_M_EARTHQUAKE);
                sPrologueShakeTimer = 40;
            }
            gTasks[taskId].tState = CARD_STATE_WAIT;
        }
        break;
    case CARD_STATE_WAIT:
        if (!gPaletteFade.active)
        {
            gTasks[taskId].tTimer++;
            if (pressed || gTasks[taskId].tTimer > CARD_HOLD_FRAMES)
                gTasks[taskId].tState = CARD_STATE_FADE_OUT;
        }
        break;
    case CARD_STATE_FADE_OUT:
        if (gPaletteFade.active)
            break;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].tState = CARD_STATE_DONE;
        break;
    case CARD_STATE_DONE:
        if (!gPaletteFade.active)
        {
            DeactivateAllTextPrinters();
            sPrologueShakeTimer = 0;
            ChangeBgX(0, 0, BG_COORD_SET);
            ChangeBgY(0, 0, BG_COORD_SET);
            gTasks[taskId].tState = CARD_STATE_FADE_IN;
            return TRUE; // this card is finished, caller should advance
        }
        break;
    }
    return FALSE;
}

// Die Trio-Energieszene gehört chronologisch zum "Tag des Streits" und
// käme nach "Jahrhunderte vergingen" zu spät. Der Code bleibt für Szene 6
// erhalten, wird im Intro 2.0 aber nicht mehr aufgerufen.
#if 0
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

static const u16 sTrioCrySpecies[] = { SPECIES_GROUDON, SPECIES_KYOGRE, SPECIES_RAYQUAZA };
static const u16 sTrioPulseColors[] = { RGB(31, 6, 0), RGB(0, 10, 31), RGB(4, 28, 8) };

static void Task_Prologue_LegendaryEnergyScene(u8 taskId)
{
    // Nyxthra: A/Start überspringt direkt zum Schwarzblenden
    if (JOY_NEW(A_BUTTON | START_BUTTON)
     && gTasks[taskId].tState > LEGENDARY_STATE_CALM
     && gTasks[taskId].tState < LEGENDARY_STATE_HOLD_WHITE)
    {
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        m4aMPlayStop(&gMPlayInfo_BGM);
        ResetPaletteFade();
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        gTasks[taskId].tBurstStep = 0;
        gTasks[taskId].tState = LEGENDARY_STATE_FADE_BLACK;
        return;
    }
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
        if (!gPaletteFade.active && gTasks[taskId].tBurstStep > 30)
        {
            gTasks[taskId].tBurstStep = 0;
            gTasks[taskId].tFlashCount = 0;
            gTasks[taskId].tState = LEGENDARY_STATE_GROUDON_CRY;
        }
        break;

    // Nyxthra (gestrafft): statt drei kompletter Kampfübergänge ruft jedes
    // Legendäre nur kurz, während der Bildschirm in seiner Farbe aufleuchtet.
    // tFlashCount zählt 0 = Groudon, 1 = Kyogre, 2 = Rayquaza.
    case LEGENDARY_STATE_GROUDON_CRY: // Ruf + Farbpuls starten
        PlayCry_Script(sTrioCrySpecies[gTasks[taskId].tFlashCount], CRY_MODE_ENCOUNTER);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 8, sTrioPulseColors[gTasks[taskId].tFlashCount]);
        gTasks[taskId].tBurstStep = 0;
        gTasks[taskId].tState = LEGENDARY_STATE_GROUDON_TRANSITION;
        break;
    case LEGENDARY_STATE_GROUDON_TRANSITION: // Puls wieder abklingen lassen
        if (!gPaletteFade.active)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 1, 8, 0, sTrioPulseColors[gTasks[taskId].tFlashCount]);
            gTasks[taskId].tState = LEGENDARY_STATE_GROUDON_TRANSITION_WAIT;
        }
        break;
    case LEGENDARY_STATE_GROUDON_TRANSITION_WAIT:
        if (!gPaletteFade.active && gTasks[taskId].tBurstStep > 40)
        {
            gTasks[taskId].tFlashCount++;
            gTasks[taskId].tBurstStep = 0;
            if (gTasks[taskId].tFlashCount < (s16)ARRAY_COUNT(sTrioCrySpecies))
            {
                gTasks[taskId].tState = LEGENDARY_STATE_GROUDON_CRY;
            }
            else
            {
                gTasks[taskId].tFlashCount = 0;
                gTasks[taskId].tState = LEGENDARY_STATE_ESCALATE_FLASHES;
            }
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

#endif

static void Task_Prologue_OutroCards(u8 taskId)
{
    if (RunPrologueCard(taskId, &sOutroCards[gTasks[taskId].tCardIdx]))
    {
        gTasks[taskId].tCardIdx++;
        if (gTasks[taskId].tCardIdx == 1)
        {
            // Nyxthra: nach "Doch niemand wusste…" erscheint Darkrai
            gTasks[taskId].tState = 0;
            gTasks[taskId].tTimer = 0;
            gTasks[taskId].func = Task_Prologue_DarkraiTeaser;
        }
        else if (gTasks[taskId].tCardIdx >= ARRAY_COUNT(sOutroCards))
        {
            gTasks[taskId].tState = 0;
            gTasks[taskId].func = Task_Prologue_TitleLogo;
        }
    }
}

// Nyxthra: Darkrai-Teaser. Rote Augen blinzeln in der Dunkelheit, Darkrai
// ruft, der Nebel glüht violett und der Bildschirm bebt, dann verschluckt
// der Schwarzes-Loch-Übergang (derselbe wie beim Darkrai-Kampf) alles.
enum
{
    TEASER_STATE_INIT,
    TEASER_STATE_BLINK_IN,
    TEASER_STATE_BLINK_HOLD,
    TEASER_STATE_BLINK_OUT,
    TEASER_STATE_EYES_OPEN,
    TEASER_STATE_GLOW,
    TEASER_STATE_GLOW_WAIT,
    TEASER_STATE_BLACK_HOLE,
    TEASER_STATE_BLACK_HOLE_WAIT,
    TEASER_STATE_HOLD_BLACK,
};

#define tBlinks data[3]

static void DrawDarkraiEyes(void)
{
    // Zwei schräge, nach innen abfallende Augen (Farbe 3 hell, 4 dunkel)
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    FillWindowPixelRect(0, PIXEL_FILL(4), 90, 66, 6, 2);
    FillWindowPixelRect(0, PIXEL_FILL(3), 92, 68, 10, 2);
    FillWindowPixelRect(0, PIXEL_FILL(3), 94, 70, 13, 2);
    FillWindowPixelRect(0, PIXEL_FILL(3), 98, 72, 13, 2);
    FillWindowPixelRect(0, PIXEL_FILL(3), 102, 74, 9, 2);
    FillWindowPixelRect(0, PIXEL_FILL(4), 106, 76, 5, 2);
    FillWindowPixelRect(0, PIXEL_FILL(4), 144, 66, 6, 2);
    FillWindowPixelRect(0, PIXEL_FILL(3), 138, 68, 10, 2);
    FillWindowPixelRect(0, PIXEL_FILL(3), 133, 70, 13, 2);
    FillWindowPixelRect(0, PIXEL_FILL(3), 129, 72, 13, 2);
    FillWindowPixelRect(0, PIXEL_FILL(3), 129, 74, 9, 2);
    FillWindowPixelRect(0, PIXEL_FILL(4), 129, 76, 5, 2);
    CopyWindowToVram(0, COPYWIN_FULL);
}

static void Task_Prologue_DarkraiTeaser(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    tTimer++;
    if (JOY_NEW(A_BUTTON | START_BUTTON) && tState > TEASER_STATE_INIT && tState < TEASER_STATE_BLACK_HOLE)
    {
        ResetPaletteFade();
        sPrologueShakeTimer = 0;
        tState = TEASER_STATE_BLACK_HOLE;
    }

    switch (tState)
    {
    case TEASER_STATE_INIT:
        // Bildschirm ist schwarz (vorherige Karte ausgeblendet); Nebel erst mal aus
        DeactivateAllTextPrinters();
        HideBg(1);
        DrawDarkraiEyes();
        tBlinks = 0;
        tTimer = 0;
        tState = TEASER_STATE_BLINK_IN;
        break;
    case TEASER_STATE_BLINK_IN:
        if (tTimer > 20 && !gPaletteFade.active)
        {
            PlaySE(SE_M_NIGHTMARE);
            BeginNormalPaletteFade(PALETTES_ALL, -1, 16, 0, RGB_BLACK);
            tTimer = 0;
            tState = TEASER_STATE_BLINK_HOLD;
        }
        break;
    case TEASER_STATE_BLINK_HOLD:
        if (!gPaletteFade.active && tTimer > 14)
        {
            BeginNormalPaletteFade(PALETTES_ALL, -1, 0, 16, RGB_BLACK);
            tTimer = 0;
            tState = TEASER_STATE_BLINK_OUT;
        }
        break;
    case TEASER_STATE_BLINK_OUT:
        if (!gPaletteFade.active)
        {
            tBlinks++;
            tTimer = 0;
            tState = (tBlinks < 2) ? TEASER_STATE_BLINK_IN : TEASER_STATE_EYES_OPEN;
        }
        break;
    case TEASER_STATE_EYES_OPEN:
        if (tTimer > 24)
        {
            ShowBg(1);
            PlayCry_Script(SPECIES_DARKRAI, CRY_MODE_ENCOUNTER);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            tTimer = 0;
            tState = TEASER_STATE_GLOW;
        }
        break;
    case TEASER_STATE_GLOW:
        if (!gPaletteFade.active)
        {
            // Nebel glüht violett auf, der Boden bebt
            PlaySE(SE_ORB);
            BeginNormalPaletteFade(1 << PROLOGUE_FOG_PAL, 1, 0, 7, RGB(20, 2, 28));
            sPrologueShakeTimer = 70;
            tTimer = 0;
            tState = TEASER_STATE_GLOW_WAIT;
        }
        break;
    case TEASER_STATE_GLOW_WAIT:
        if (!gPaletteFade.active && tTimer > 60)
            tState = TEASER_STATE_BLACK_HOLE;
        break;
    case TEASER_STATE_BLACK_HOLE:
        sPrologueShakeTimer = 0;
        ChangeBgX(0, 0, BG_COORD_SET);
        ChangeBgY(0, 0, BG_COORD_SET);
        PlaySE(SE_M_NIGHTMARE);
        // Die Übergänge erwarten (wie in der Oberwelt) ein aktives Fenster 0,
        // sonst bleibt die Schwarzes-Loch-Maske unsichtbar.
        SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(0, DISPLAY_HEIGHT));
        SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL);
        SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_ALL);
        SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
        BattleTransition_Start(B_TRANSITION_BLACKHOLE);
        tState = TEASER_STATE_BLACK_HOLE_WAIT;
        break;
    case TEASER_STATE_BLACK_HOLE_WAIT:
        if (IsBattleTransitionDone())
        {
            // Übergänge setzen eigene VBlank/HBlank-Callbacks und Fenster -
            // alles zurück auf den Prolog (siehe LegendaryEnergyScene).
            SetVBlankCallback(VBlankCB_NyxthraPrologue);
            FreePrologueBgAndWindow();
            InitPrologueBgAndWindow();
            ResetPaletteFade();
            BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
            tTimer = 0;
            tState = TEASER_STATE_HOLD_BLACK;
        }
        break;
    case TEASER_STATE_HOLD_BLACK:
        if (tTimer > 30)
        {
            tState = CARD_STATE_FADE_IN;
            tTimer = 0;
            if (gTasks[taskId].tCardIdx >= (s16)ARRAY_COUNT(sOutroCards))
            {
                gTasks[taskId].tState = 0;
                gTasks[taskId].func = Task_Prologue_TitleLogo;
            }
            else
            {
                gTasks[taskId].func = Task_Prologue_OutroCards;
            }
        }
        break;
    }
}

#undef tBlinks

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
            if (JOY_NEW(A_BUTTON | B_BUTTON | START_BUTTON) || gTasks[taskId].tTimer > 150)
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

#if 0
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

#endif

// ---------------------------------------------------------------------------
// Intro 2.0, Szenen 1–7: Erde, Zoom, Regen/Dürre, Rayquaza, Stille, Nebel, Augen.
// Mode 1: BG0 Text (4bpp, Palette 8), BG1 Sterne oder Regen (4bpp),
// BG2 Planet (affin, 8bpp, Paletten 0–1 / 32 Farben). Atmosphären-
// Farben liegen fest auf den Indizes 28–31, damit sie pulsieren können.
// A/Start blendet die neuen Szenen aus und setzt den v1-Prolog fort.
// ---------------------------------------------------------------------------
#define PROLOGUE_STARS_PAL 2
#define GLOBE_ATMOS_INDEX  28
#define GLOBE_ATMOS_COUNT  4

#define GLOBE_TEX_CENTER   0x4000 // 64px in 8.8
#define GLOBE_SCR_X        120
#define GLOBE_SCR_Y_END    68
#define GLOBE_SCR_Y_START  220
#define GLOBE_SCALE_1_0    256
#define GLOBE_SCALE_1_8    142    // 256 / 1.8 ≈ 142
#define GLOBE_ANGLE_END    0x0600 // leichte Drehung, ≈ 8,4°

#define GLOBE_STARS_FADE_FRAMES  50
#define GLOBE_RISE_FRAMES        140
#define GLOBE_SCENE1_FRAMES      360 // 6 s
#define GLOBE_ZOOM_FRAMES        280
#define GLOBE_SCENE2_FRAMES      300 // 5 s
#define GLOBE_SCALE_SCENE3       170 // ~1.5×, etwas Luft für Silhouetten
#define GLOBE_RAIN_TILE          256
#define PROLOGUE_RAIN_PAL        3
#define GLOBE_SIL_SIZE           (64 * 64 / 2)
#define TAG_KYOGRE_SIL           0x4E01
#define TAG_GROUDON_SIL          0x4E02
#define TAG_RAYQUAZA_SIL         0x4E03
#define TAG_SPARK                0x4E04
#define SPARK_COUNT              8
#define SPARK_SIZE               (16 * 16 / 2)
#define GLOBE_SCENE4_FRAMES      330 // 5,5 s
#define GLOBE_RAY_FLY_START      28
#define GLOBE_RAY_FLY_FRAMES     200
#define GLOBE_SCENE5_LEAD_FRAMES 30
#define GLOBE_SCENE5_SILENCE_FRAMES 60
#define GLOBE_FOG_PAL            4
#define GLOBE_SCENE6_WIPE_FRAMES 240
#define GLOBE_FOG_TILE            256
#define GLOBE_SCENE6_PAL_FRAMES  200
#define GLOBE_SCENE6_TEXT_FRAMES 48
#define GLOBE_SCENE6_SIL_FRAMES  330
#define GLOBE_SCENE6_END_FRAMES  660
#define GLOBE_HEART_PULSE_FRAMES 12
#define GLOBE_FOG_ALPHA_MAX      12
#define GLOBE_HEART_INTERVAL_START 60
#define GLOBE_HEART_INTERVAL_END   30
#define GLOBE_BGM_VOL_NORMAL       256
#define GLOBE_BGM_VOL_DUCK         16
#define GLOBE_EYES_SIZE            (64 * 32 / 2)
#define TAG_DARKRAI_EYES           0x4E05
#define TAG_DARKRAI_SIL            0x4E06
#define GLOBE_SCENE7_EYES_FRAMES   24
#define GLOBE_SCENE7_FLASH_FRAMES  210
#define GLOBE_SCENE7_HOLD_FRAMES   90
#define GLOBE_SCENE7_SIL_HOLD_FRAMES 60

#define WEATHER_RAIN             0
#define WEATHER_DROUGHT          1

static const u8 sText_Globe_Hoenn[] = _("Hoenn.");
static const u8 sText_Globe_Balance[] = _("Ein Land im Gleichgewicht.");
static const u8 sText_Globe_Forces1[] = _("Doch zwei Gewalten ruhten darin:");
static const u8 sText_Globe_Forces2[] = _("Land und Meer.");
static const u8 sText_Globe_Rain[] = _("Regen.");
static const u8 sText_Globe_Drought[] = _("Dürre.");
static const u8 sText_Globe_Rayquaza[] = _("Rayquaza beendete den Streit.");
static const u8 sText_Globe_Centuries1[] = _("Jahrhunderte vergingen.");
static const u8 sText_Globe_Centuries2[] = _("Man vergaß, was damals erwachte.");
static const u8 sText_Globe_Change1[] = _("Die Welt begann sich zu verändern…");
static const u8 sText_Globe_Change2[] = _("…und die Pokémon mit ihr.");
static const u8 sText_Globe_Watched[] = _("Etwas beobachtet uns.");
static const u8 sText_Globe_Nyxthra[] = _("Nyxthra.");

// Intervalle in Frames: 2,0 → 1,5 → 1,0 → 0,6 s, danach 0,4 s bis ~10 s.
static const u16 sWeatherDurations[] = {
    120, 90, 60, 36,
    24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24, 24,
};

static const u16 sGlobeRainAtmos[GLOBE_ATMOS_COUNT] = {
    RGB(19, 26, 31),
    RGB(8, 15, 27),
    RGB(3, 6, 17),
    RGB(1, 2, 8),
};

static const u16 sGlobeDroughtAtmos[GLOBE_ATMOS_COUNT] = {
    RGB(31, 26, 10),
    RGB(29, 17, 4),
    RGB(22, 8, 2),
    RGB(12, 3, 1),
};

static const u16 sGlobeRayAtmos[GLOBE_ATMOS_COUNT] = {
    RGB(31, 31, 14),
    RGB(22, 28, 6),
    RGB(8, 20, 4),
    RGB(4, 10, 2),
};

static const u16 sGlobeSunriseAtmos[GLOBE_ATMOS_COUNT] = {
    RGB(31, 27, 17),
    RGB(31, 19, 10),
    RGB(24, 10, 6),
    RGB(12, 4, 4),
};

static const u16 sGlobeMistAtmos[GLOBE_ATMOS_COUNT] = {
    RGB(20, 13, 27),
    RGB(14, 6, 22),
    RGB(8, 3, 14),
    RGB(4, 1, 7),
};

// Fest aus prologue_globe.pal, Indizes 28–31 (bereits auf 5 Bit gerundet).
static const u16 sGlobeAtmosPal[GLOBE_ATMOS_COUNT] = {
    RGB(13, 21, 31),
    RGB(7, 12, 24),
    RGB(4, 6, 15),
    RGB(2, 3, 9),
};

static const struct BgTemplate sGlobeBgTemplates[] =
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
    {
        .bg = 1,
        .charBaseIndex = 1,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 2,
        .baseTile = 0,
    },
    {
        .bg = 2,
        .charBaseIndex = 0,
        .mapBaseIndex = 26,
        .screenSize = 0, // 128×128 affiner BG, 256 Kacheln
        .paletteMode = 1, // 8bpp
        .priority = 1,
        .baseTile = 0,
    },
};

// Nur die unteren Textzeilen: ein volles 30×20-Fenster würde aus Charblock 2
// hinaus in die Planeten-Tilemap laufen.
static const struct WindowTemplate sGlobeWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 0,
        .tilemapTop = 14,
        .width = DISPLAY_TILE_WIDTH,
        .height = 6,
        .paletteNum = 8,
        .baseBlock = 1,
    },
    DUMMY_WIN_TEMPLATE,
};

// Fenster ab Pixelzeile 14*8=112, Höhe 48 px. Texte auf dem dunklen
// Sternenhimmel unter dem Planeten (Bildschirm-Y 128/144).
#define GLOBE_TEXT_Y1 16
#define GLOBE_TEXT_Y2 32

struct GlobeAffine
{
    s32 texX;
    s32 texY;
    s16 scrX;
    s16 scrY;
    s16 scale;
    u16 angle;
};

static EWRAM_DATA struct GlobeAffine sGlobeAffine = {0};
static EWRAM_DATA bool8 sGlobeRainScroll = FALSE;
static EWRAM_DATA bool8 sGlobeFogScroll = FALSE;
static EWRAM_DATA u8 sGlobeHeartPulse = 0;
static EWRAM_DATA u8 sGlobeMosaic = 0;
static EWRAM_DATA u8 sGlobeShakeTimer = 0;
static EWRAM_DATA u8 sGlobeFlashTimer = 0;
static EWRAM_DATA u8 sGlobeKyogreSprite = 0;
static EWRAM_DATA u8 sGlobeGroudonSprite = 0;
static EWRAM_DATA u8 sGlobeRaySprite = 0;
static EWRAM_DATA u8 sGlobeEyesSprite = 0;
static EWRAM_DATA u8 sGlobeDarkraiSprite = 0;
static EWRAM_DATA u8 sGlobeSparks[SPARK_COUNT] = {0};
static EWRAM_DATA u8 sGlobeWeather = 0;
static EWRAM_DATA u8 sGlobeLabelTimer = 0;
static EWRAM_DATA u16 sGlobeRayFlyTimer = 0;

static const struct SpriteSheet sKyogreSilhouetteSheet =
{
    .data = gNyxthraPrologueKyogreSil_Gfx,
    .size = GLOBE_SIL_SIZE,
    .tag = TAG_KYOGRE_SIL,
};

static const struct SpriteSheet sGroudonSilhouetteSheet =
{
    .data = gNyxthraPrologueGroudonSil_Gfx,
    .size = GLOBE_SIL_SIZE,
    .tag = TAG_GROUDON_SIL,
};

static const struct SpritePalette sKyogreSilhouettePal =
{
    .data = gNyxthraPrologueKyogreSil_Pal,
    .tag = TAG_KYOGRE_SIL,
};

static const struct SpritePalette sGroudonSilhouettePal =
{
    .data = gNyxthraPrologueGroudonSil_Pal,
    .tag = TAG_GROUDON_SIL,
};

static const struct OamData sOam_Silhouette64 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .size = SPRITE_SIZE(64x64),
    .priority = 0,
};

static void SpriteCB_Silhouette(struct Sprite *sprite)
{
    sprite->data[0]++;
    sprite->y2 = Sin((sprite->data[0] * 2) & 0xFF, 2);
}

static const struct SpriteTemplate sKyogreSilhouetteTemplate =
{
    .tileTag = TAG_KYOGRE_SIL,
    .paletteTag = TAG_KYOGRE_SIL,
    .oam = &sOam_Silhouette64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Silhouette,
};

static const struct SpriteTemplate sGroudonSilhouetteTemplate =
{
    .tileTag = TAG_GROUDON_SIL,
    .paletteTag = TAG_GROUDON_SIL,
    .oam = &sOam_Silhouette64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Silhouette,
};

static const struct SpriteSheet sRayquazaSilhouetteSheet =
{
    .data = gNyxthraPrologueRayquazaSil_Gfx,
    .size = GLOBE_SIL_SIZE * 2, // zwei Flug-Frames
    .tag = TAG_RAYQUAZA_SIL,
};

static const struct SpritePalette sRayquazaSilhouettePal =
{
    .data = gNyxthraPrologueRayquazaSil_Pal,
    .tag = TAG_RAYQUAZA_SIL,
};

static const union AnimCmd sAnim_RayquazaFly[] =
{
    ANIMCMD_FRAME(0, 6),
    ANIMCMD_FRAME(64, 6),
    ANIMCMD_JUMP(0),
};

static const union AnimCmd *const sAnims_RayquazaFly[] =
{
    sAnim_RayquazaFly,
};

static const struct SpriteTemplate sRayquazaSilhouetteTemplate =
{
    .tileTag = TAG_RAYQUAZA_SIL,
    .paletteTag = TAG_RAYQUAZA_SIL,
    .oam = &sOam_Silhouette64,
    .anims = sAnims_RayquazaFly,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteSheet sSparkSheet =
{
    .data = gNyxthraPrologueSpark_Gfx,
    .size = SPARK_SIZE,
    .tag = TAG_SPARK,
};

static const struct SpritePalette sSparkPal =
{
    .data = gNyxthraPrologueSpark_Pal,
    .tag = TAG_SPARK,
};

static const struct OamData sOam_Spark16 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x16),
    .x = 0,
    .size = SPRITE_SIZE(16x16),
    .priority = 0,
};

static void SpriteCB_Spark(struct Sprite *sprite)
{
    sprite->data[0]++;
    if ((sprite->data[0] & 1) == 0)
        sprite->y--;
    if (sprite->data[0] > 18)
        sprite->invisible = TRUE;
}

static const struct SpriteTemplate sSparkTemplate =
{
    .tileTag = TAG_SPARK,
    .paletteTag = TAG_SPARK,
    .oam = &sOam_Spark16,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_Spark,
};

static const struct SpriteSheet sDarkraiEyesSheet =
{
    .data = gNyxthraPrologueDarkraiEyes_Gfx,
    .size = GLOBE_EYES_SIZE,
    .tag = TAG_DARKRAI_EYES,
};

static const struct SpritePalette sDarkraiEyesPal =
{
    .data = gNyxthraPrologueDarkraiEyes_Pal,
    .tag = TAG_DARKRAI_EYES,
};

static const struct SpriteSheet sDarkraiSilSheet =
{
    .data = gNyxthraPrologueDarkraiSil_Gfx,
    .size = GLOBE_SIL_SIZE,
    .tag = TAG_DARKRAI_SIL,
};

static const struct SpritePalette sDarkraiSilPal =
{
    .data = gNyxthraPrologueDarkraiSil_Pal,
    .tag = TAG_DARKRAI_SIL,
};

static const struct OamData sOam_Eyes64x32 =
{
    .y = 0,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .size = SPRITE_SIZE(64x32),
    .priority = 0,
};

static void SpriteCB_EyesPulse(struct Sprite *sprite)
{
    u8 amt = 0;

    if (sGlobeHeartPulse != 0)
        amt = (sGlobeHeartPulse > 6) ? (GLOBE_HEART_PULSE_FRAMES - sGlobeHeartPulse) : sGlobeHeartPulse;
    sprite->y2 = -(amt / 2);
}

static const struct SpriteTemplate sDarkraiEyesTemplate =
{
    .tileTag = TAG_DARKRAI_EYES,
    .paletteTag = TAG_DARKRAI_EYES,
    .oam = &sOam_Eyes64x32,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_EyesPulse,
};

static const struct SpriteTemplate sDarkraiSilTemplate =
{
    .tileTag = TAG_DARKRAI_SIL,
    .paletteTag = TAG_DARKRAI_SIL,
    .oam = &sOam_Silhouette64,
    .anims = gDummySpriteAnimTable,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};


static void ApplyGlobeAffine(void)
{
    SetBgAffine(2,
                sGlobeAffine.texX,
                sGlobeAffine.texY,
                sGlobeAffine.scrX,
                sGlobeAffine.scrY,
                sGlobeAffine.scale,
                sGlobeAffine.scale,
                sGlobeAffine.angle);
}

static void SetGlobeAffine(s16 scrY, s16 scale, u16 angle)
{
    sGlobeAffine.texX = GLOBE_TEX_CENTER;
    sGlobeAffine.texY = GLOBE_TEX_CENTER;
    sGlobeAffine.scrX = GLOBE_SCR_X;
    sGlobeAffine.scrY = scrY;
    sGlobeAffine.scale = scale;
    sGlobeAffine.angle = angle;
    ApplyGlobeAffine();
}

static void PulseAtmosphereColors(u16 timer, const u16 *base, u8 tr, u8 tg, u8 tb)
{
    u32 i;
    s16 k = (Sin(timer & 0xFF, 10) + 10); // 0..20

    for (i = 0; i < GLOBE_ATMOS_COUNT; i++)
    {
        u16 c = base[i];
        u8 r = GET_R(c);
        u8 g = GET_G(c);
        u8 b = GET_B(c);
        r = r + ((tr - r) * k / 40);
        g = g + ((tg - g) * k / 40);
        b = b + ((tb - b) * k / 40);
        if (r > 31)
            r = 31;
        if (g > 31)
            g = 31;
        if (b > 31)
            b = 31;
        gPlttBufferUnfaded[GLOBE_ATMOS_INDEX + i] = RGB(r, g, b);
        gPlttBufferFaded[GLOBE_ATMOS_INDEX + i] = RGB(r, g, b);
    }
}

static void PulseGlobeAtmosphere(u16 timer)
{
    PulseAtmosphereColors(timer, sGlobeAtmosPal, 20, 26, 31);
}

static void VBlankCB_NyxthraPrologueGlobe(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ApplyGlobeAffine();
    SetGpuReg(REG_OFFSET_MOSAIC, (sGlobeMosaic << 4) | sGlobeMosaic);
    ScanlineEffect_InitHBlankDmaTransfer();
}

static void CB2_NyxthraPrologueGlobe(void)
{
    RunTextPrinters();
    if (sGlobeRainScroll)
    {
        // Diagonaler Regen, etwa 2 px/Frame horizontal und vertikal.
        ChangeBgX(1, 512, BG_COORD_ADD);
        ChangeBgY(1, 448, BG_COORD_ADD);
    }
    else if (sGlobeFogScroll)
    {
        // Langsamer violetter Nebel, schräg wie in den v1-Tafeln.
        ChangeBgX(1, 40, BG_COORD_ADD);
        ChangeBgY(1, 12, BG_COORD_ADD);
    }
    else
    {
        ChangeBgX(1, 16, BG_COORD_ADD);
    }
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void InitPrologueGlobeScene(void)
{
    u32 x, y;
    u8 *globeMap;
    u16 *starsMap;

    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);
    LoadPalette(&(u16){RGB_BLACK}, BG_PLTT_ID(0), sizeof(u16));
    ScanlineEffect_Stop();
    SetHBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WIN1H, 0);
    SetGpuReg(REG_OFFSET_WIN1V, 0);
    sPrologueShakeTimer = 0;
    sGlobeRainScroll = FALSE;
    sGlobeFogScroll = FALSE;
    sGlobeHeartPulse = 0;
    sGlobeMosaic = 0;
    sGlobeShakeTimer = 0;
    sGlobeFlashTimer = 0;
    sGlobeKyogreSprite = SPRITE_NONE;
    sGlobeGroudonSprite = SPRITE_NONE;
    sGlobeRaySprite = SPRITE_NONE;
    sGlobeEyesSprite = SPRITE_NONE;
    sGlobeDarkraiSprite = SPRITE_NONE;
    sGlobeWeather = 0;
    sGlobeLabelTimer = 0;
    sGlobeRayFlyTimer = 0;
    {
        u32 i;
        for (i = 0; i < SPARK_COUNT; i++)
            sGlobeSparks[i] = SPRITE_NONE;
    }

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(1, sGlobeBgTemplates, ARRAY_COUNT(sGlobeBgTemplates));
    SetBgAttribute(2, BG_ATTR_WRAPAROUND, 0);
    SetBgAttribute(2, BG_ATTR_MOSAIC, 1);

    SetBgTilemapBuffer(0, AllocZeroed(BG_SCREEN_SIZE));

    starsMap = AllocZeroed(BG_SCREEN_SIZE);
    for (y = 0; y < 32; y++)
        for (x = 0; x < 32; x++)
            starsMap[y * 32 + x] = ((y % 16) * 16 + (x % 16)) | (PROLOGUE_STARS_PAL << 12);
    SetBgTilemapBuffer(1, starsMap);
    LoadBgTiles(1, gNyxthraPrologueStars_Gfx, 16 * 16 * TILE_SIZE_4BPP, 0);
    LoadPalette(gNyxthraPrologueStars_Pal, BG_PLTT_ID(PROLOGUE_STARS_PAL), PLTT_SIZE_4BPP);
    LoadBgTiles(1, gNyxthraPrologueRain_Gfx, 64 * TILE_SIZE_4BPP, GLOBE_RAIN_TILE);
    LoadPalette(gNyxthraPrologueRain_Pal, BG_PLTT_ID(PROLOGUE_RAIN_PAL), PLTT_SIZE_4BPP);
    CopyBgTilemapBufferToVram(1);

    globeMap = AllocZeroed(0x100);
    for (x = 0; x < 256; x++)
        globeMap[x] = x;
    SetBgTilemapBuffer(2, globeMap);
    LoadBgTiles(2, gNyxthraPrologueGlobe_Gfx, 256 * TILE_SIZE_8BPP, 0);
    LoadPalette(gNyxthraPrologueGlobe_Pal, BG_PLTT_ID(0), 32 * sizeof(u16));
    // Index 0 ist in der Grafik transparent; als Backdrop muss er schwarz bleiben.
    LoadPalette(&(u16){RGB_BLACK}, BG_PLTT_ID(0), sizeof(u16));
    CopyBgTilemapBufferToVram(2);

    LoadPalette(sPrologueTextPal, BG_PLTT_ID(8), sizeof(sPrologueTextPal));
    InitWindows(sGlobeWindowTemplates);
    DeactivateAllTextPrinters();
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);

    SetGlobeAffine(GLOBE_SCR_Y_START, GLOBE_SCALE_1_0, 0);
    // Paletten sind geladen, Bildschirm bleibt schwarz, bis die Sterne einblenden.
    BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);

    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
}

static void ClearGlobeText(void)
{
    DeactivateAllTextPrinters();
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    CopyWindowToVram(0, COPYWIN_FULL);
    sGlobeLabelTimer = 0;
}

static void PrintGlobeLabel(const u8 *string, u8 fg, u8 shadow)
{
    u8 x;
    u8 color[3];

    color[0] = TEXT_COLOR_TRANSPARENT;
    color[1] = fg;
    color[2] = shadow;
    DeactivateAllTextPrinters();
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    x = GetStringCenterAlignXOffsetWithLetterSpacing(FONT_SMALL_NARROW, string, DISPLAY_WIDTH, 0);
    AddTextPrinterParameterized4(0, FONT_SMALL_NARROW, x, GLOBE_TEXT_Y1, 0, 0, color, 0, string);
}

static void FillBg1Stars(void)
{
    u16 *map = GetBgTilemapBuffer(1);
    u32 x, y;

    for (y = 0; y < 32; y++)
        for (x = 0; x < 32; x++)
            map[y * 32 + x] = ((y % 16) * 16 + (x % 16)) | (PROLOGUE_STARS_PAL << 12);
    CopyBgTilemapBufferToVram(1);
}

static void FillBg1Rain(void)
{
    u16 *map = GetBgTilemapBuffer(1);
    u32 x, y;

    for (y = 0; y < 32; y++)
        for (x = 0; x < 32; x++)
            map[y * 32 + x] = (GLOBE_RAIN_TILE + ((y % 8) * 8 + (x % 8))) | (PROLOGUE_RAIN_PAL << 12);
    CopyBgTilemapBufferToVram(1);
}

static void SetRainOverlay(bool8 enabled)
{
    if (enabled)
    {
        FillBg1Rain();
        SetBgAttribute(1, BG_ATTR_PRIORITY, 0);
        SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BD);
        SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(8, 10));
        sGlobeRainScroll = TRUE;
    }
    else
    {
        sGlobeRainScroll = FALSE;
        SetBgAttribute(1, BG_ATTR_PRIORITY, 2);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        FillBg1Stars();
        ChangeBgY(1, 0, BG_COORD_SET);
    }
}

static void FillBg1FogWipe(u16 fogCols)
{
    u16 *map = GetBgTilemapBuffer(1);
    u32 x, y;

    if (fogCols > 32)
        fogCols = 32;
    for (y = 0; y < 32; y++)
    {
        for (x = 0; x < 32; x++)
        {
            if (x < fogCols)
                map[y * 32 + x] = (GLOBE_FOG_TILE + ((y % 16) * 16 + (x % 16))) | (GLOBE_FOG_PAL << 12);
            else
                map[y * 32 + x] = ((y % 16) * 16 + (x % 16)) | (PROLOGUE_STARS_PAL << 12);
        }
    }
    CopyBgTilemapBufferToVram(1);
}

static void FillBg1Fog(void)
{
    FillBg1FogWipe(32);
}

static void LerpGlobePalette(const u16 *from, const u16 *to, u16 t, u16 duration)
{
    u16 pal[32];
    u32 i;
    u16 f = (t >= duration) ? 16 : (u16)((u32)t * 16 / duration);

    pal[0] = RGB_BLACK;
    for (i = 1; i < 32; i++)
    {
        u16 a = from[i];
        u16 b = to[i];
        s16 r = GET_R(a) + (s16)(GET_R(b) - GET_R(a)) * (s16)f / 16;
        s16 g = GET_G(a) + (s16)(GET_G(b) - GET_G(a)) * (s16)f / 16;
        s16 bcol = GET_B(a) + (s16)(GET_B(b) - GET_B(a)) * (s16)f / 16;
        pal[i] = RGB(r, g, bcol);
    }
    LoadPalette(pal, BG_PLTT_ID(0), 32 * sizeof(u16));
}

static u16 GetScene6HeartInterval(u16 t)
{
    if (t >= GLOBE_SCENE6_END_FRAMES)
        return GLOBE_HEART_INTERVAL_END;
    return GLOBE_HEART_INTERVAL_START
         - (GLOBE_HEART_INTERVAL_START - GLOBE_HEART_INTERVAL_END) * t / GLOBE_SCENE6_END_FRAMES;
}

static void TriggerHeartbeat(void)
{
    PlaySE(SE_M_MEGA_KICK);
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, GLOBE_BGM_VOL_DUCK);
    sGlobeHeartPulse = GLOBE_HEART_PULSE_FRAMES;
    sGlobeShakeTimer = 6;
}

static u8 UpdateHeartbeatPulse(void)
{
    u8 pulseAmt = 0;
    u16 vol;

    if (sGlobeHeartPulse != 0)
    {
        pulseAmt = (sGlobeHeartPulse > 6) ? (GLOBE_HEART_PULSE_FRAMES - sGlobeHeartPulse) : sGlobeHeartPulse;
        vol = GLOBE_BGM_VOL_DUCK
            + (GLOBE_BGM_VOL_NORMAL - GLOBE_BGM_VOL_DUCK)
            * (GLOBE_HEART_PULSE_FRAMES - sGlobeHeartPulse)
            / GLOBE_HEART_PULSE_FRAMES;
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, vol);
        sGlobeHeartPulse--;
        if (sGlobeHeartPulse == 0)
            m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, GLOBE_BGM_VOL_NORMAL);
    }
    return pulseAmt;
}

static void RecolorSilhouette(u8 spriteId, const u16 *pal)
{
    u32 palNum;

    if (spriteId == SPRITE_NONE)
        return;
    palNum = IndexOfSpritePaletteTag(gSprites[spriteId].template->paletteTag);
    if (palNum != 0xFF)
        LoadPalette(pal, OBJ_PLTT_ID(palNum), PLTT_SIZE_4BPP);
}

static void DestroyGlobeSilhouettes(void);
static void DestroyGlobeRayquaza(void);
static void DestroyScene7Sprites(void);

static void CreateScene6Silhouettes(void)
{
    DestroyGlobeSilhouettes();
    DestroyGlobeRayquaza();
    LoadSpriteSheet(&sKyogreSilhouetteSheet);
    LoadSpriteSheet(&sGroudonSilhouetteSheet);
    LoadSpriteSheet(&sRayquazaSilhouetteSheet);
    LoadSpritePalette(&sKyogreSilhouettePal);
    LoadSpritePalette(&sGroudonSilhouettePal);
    LoadSpritePalette(&sRayquazaSilhouettePal);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);

    sGlobeKyogreSprite = CreateSprite(&sKyogreSilhouetteTemplate, 52, 96, 0);
    sGlobeGroudonSprite = CreateSprite(&sGroudonSilhouetteTemplate, 188, 98, 0);
    sGlobeRaySprite = CreateSprite(&sRayquazaSilhouetteTemplate, 120, 58, 0);

    if (sGlobeKyogreSprite != MAX_SPRITES)
        gSprites[sGlobeKyogreSprite].invisible = TRUE;
    else
        sGlobeKyogreSprite = SPRITE_NONE;

    if (sGlobeGroudonSprite != MAX_SPRITES)
        gSprites[sGlobeGroudonSprite].invisible = TRUE;
    else
        sGlobeGroudonSprite = SPRITE_NONE;

    if (sGlobeRaySprite != MAX_SPRITES)
    {
        gSprites[sGlobeRaySprite].invisible = TRUE;
        gSprites[sGlobeRaySprite].callback = SpriteCB_Silhouette;
        StartSpriteAnim(&gSprites[sGlobeRaySprite], 0);
    }
    else
    {
        sGlobeRaySprite = SPRITE_NONE;
    }
}

static void ShowScene6Silhouettes(void)
{
    if (sGlobeKyogreSprite != SPRITE_NONE)
        gSprites[sGlobeKyogreSprite].invisible = FALSE;
    if (sGlobeGroudonSprite != SPRITE_NONE)
        gSprites[sGlobeGroudonSprite].invisible = FALSE;
    if (sGlobeRaySprite != SPRITE_NONE)
        gSprites[sGlobeRaySprite].invisible = FALSE;
}

static void DestroyScene7Sprites(void)
{
    if (sGlobeEyesSprite != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sGlobeEyesSprite]);
        sGlobeEyesSprite = SPRITE_NONE;
    }
    if (sGlobeDarkraiSprite != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sGlobeDarkraiSprite]);
        sGlobeDarkraiSprite = SPRITE_NONE;
    }
}

static void CreateScene7Sprites(void)
{
    DestroyScene7Sprites();
    LoadSpriteSheet(&sDarkraiEyesSheet);
    LoadSpriteSheet(&sDarkraiSilSheet);
    LoadSpritePalette(&sDarkraiEyesPal);
    LoadSpritePalette(&sDarkraiSilPal);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);

    sGlobeEyesSprite = CreateSprite(&sDarkraiEyesTemplate, 120, 64, 0);
    sGlobeDarkraiSprite = CreateSprite(&sDarkraiSilTemplate, 120, 84, 0);

    if (sGlobeEyesSprite != MAX_SPRITES)
        gSprites[sGlobeEyesSprite].invisible = TRUE;
    else
        sGlobeEyesSprite = SPRITE_NONE;

    if (sGlobeDarkraiSprite != MAX_SPRITES)
        gSprites[sGlobeDarkraiSprite].invisible = TRUE;
    else
        sGlobeDarkraiSprite = SPRITE_NONE;
}

static void ShiftNextNyxthraSilhouette(s16 *shiftCount)
{
    if (*shiftCount == 0)
        RecolorSilhouette(sGlobeKyogreSprite, gNyxthraPrologueKyogreSilAbgrund_Pal);
    else if (*shiftCount == 1)
        RecolorSilhouette(sGlobeGroudonSprite, gNyxthraPrologueGroudonSilGlow_Pal);
    else if (*shiftCount == 2)
        RecolorSilhouette(sGlobeRaySprite, gNyxthraPrologueRayquazaSilGlow_Pal);
    else
        return;
    (*shiftCount)++;
}

static void UpdateScene6Fog(u16 t, u8 pulse)
{
    u8 alpha;
    u8 amt;

    // Schon früh sichtbar, damit die von links kriechende Kante zu sehen ist.
    if (t >= 80)
        alpha = GLOBE_FOG_ALPHA_MAX;
    else
        alpha = 5 + (u8)((u32)(GLOBE_FOG_ALPHA_MAX - 5) * t / 80);

    if (pulse != 0)
    {
        amt = (pulse > 6) ? (GLOBE_HEART_PULSE_FRAMES - pulse) : pulse;
        alpha += amt / 2;
        if (alpha > 16)
            alpha = 16;
    }

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_OBJ | BLDCNT_TGT2_BD);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(alpha, (16 > alpha) ? (16 - alpha) : 1));

    {
        u16 cols = 32;
        static u16 sLastFogCols;

        if (t < GLOBE_SCENE6_WIPE_FRAMES)
            cols = 1 + t * 31 / GLOBE_SCENE6_WIPE_FRAMES;
        if (t == 1 || cols != sLastFogCols)
        {
            FillBg1FogWipe(cols);
            sLastFogCols = cols;
        }
    }
}

static void LoadGlobeWeatherPalette(u8 weather)
{
    if (weather == WEATHER_RAIN)
        LoadPalette(gNyxthraPrologueGlobeRain_Pal, BG_PLTT_ID(0), 32 * sizeof(u16));
    else
        LoadPalette(gNyxthraPrologueGlobeDrought_Pal, BG_PLTT_ID(0), 32 * sizeof(u16));
    LoadPalette(&(u16){RGB_BLACK}, BG_PLTT_ID(0), sizeof(u16));
}

static void DestroyGlobeSilhouettes(void)
{
    if (sGlobeKyogreSprite != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sGlobeKyogreSprite]);
        sGlobeKyogreSprite = SPRITE_NONE;
    }
    if (sGlobeGroudonSprite != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sGlobeGroudonSprite]);
        sGlobeGroudonSprite = SPRITE_NONE;
    }
}

static void CreateGlobeSilhouettes(void)
{
    DestroyGlobeSilhouettes();
    LoadSpriteSheet(&sKyogreSilhouetteSheet);
    LoadSpriteSheet(&sGroudonSilhouetteSheet);
    LoadSpritePalette(&sKyogreSilhouettePal);
    LoadSpritePalette(&sGroudonSilhouettePal);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    sGlobeKyogreSprite = CreateSprite(&sKyogreSilhouetteTemplate, 64, 78, 0);
    sGlobeGroudonSprite = CreateSprite(&sGroudonSilhouetteTemplate, 196, 82, 0);
    if (sGlobeKyogreSprite != MAX_SPRITES)
        gSprites[sGlobeKyogreSprite].invisible = TRUE;
    else
        sGlobeKyogreSprite = SPRITE_NONE;
    if (sGlobeGroudonSprite != MAX_SPRITES)
        gSprites[sGlobeGroudonSprite].invisible = TRUE;
    else
        sGlobeGroudonSprite = SPRITE_NONE;
}

static void ShowWeatherSilhouette(u8 weather)
{
    if (sGlobeKyogreSprite != SPRITE_NONE)
        gSprites[sGlobeKyogreSprite].invisible = (weather != WEATHER_RAIN);
    if (sGlobeGroudonSprite != SPRITE_NONE)
        gSprites[sGlobeGroudonSprite].invisible = (weather != WEATHER_DROUGHT);
}

static void DestroyGlobeRayquaza(void)
{
    u32 i;

    if (sGlobeRaySprite != SPRITE_NONE)
    {
        DestroySprite(&gSprites[sGlobeRaySprite]);
        sGlobeRaySprite = SPRITE_NONE;
    }
    for (i = 0; i < SPARK_COUNT; i++)
    {
        if (sGlobeSparks[i] != SPRITE_NONE)
        {
            DestroySprite(&gSprites[sGlobeSparks[i]]);
            sGlobeSparks[i] = SPRITE_NONE;
        }
    }
}

static void CreateGlobeRayquaza(void)
{
    LoadSpriteSheet(&sRayquazaSilhouetteSheet);
    LoadSpritePalette(&sRayquazaSilhouettePal);
    LoadSpriteSheet(&sSparkSheet);
    LoadSpritePalette(&sSparkPal);
    SetGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    sGlobeRaySprite = CreateSprite(&sRayquazaSilhouetteTemplate, -40, 80, 0);
    if (sGlobeRaySprite != MAX_SPRITES)
    {
        gSprites[sGlobeRaySprite].hFlip = TRUE;
        gSprites[sGlobeRaySprite].invisible = TRUE;
        StartSpriteAnim(&gSprites[sGlobeRaySprite], 0);
    }
    else
    {
        sGlobeRaySprite = SPRITE_NONE;
    }
}

static void SpawnSpark(s16 x, s16 y)
{
    u32 i;

    for (i = 0; i < SPARK_COUNT; i++)
    {
        if (sGlobeSparks[i] == SPRITE_NONE)
        {
            sGlobeSparks[i] = CreateSprite(&sSparkTemplate, x, y, 1);
            if (sGlobeSparks[i] == MAX_SPRITES)
                sGlobeSparks[i] = SPRITE_NONE;
            return;
        }
        if (gSprites[sGlobeSparks[i]].invisible)
        {
            gSprites[sGlobeSparks[i]].x = x;
            gSprites[sGlobeSparks[i]].y = y;
            gSprites[sGlobeSparks[i]].y2 = 0;
            gSprites[sGlobeSparks[i]].invisible = FALSE;
            gSprites[sGlobeSparks[i]].data[0] = 0;
            return;
        }
    }
}

static void SetRayquazaFlightPos(u16 t)
{
    u8 ang;
    s16 x, y;

    if (t > GLOBE_RAY_FLY_FRAMES)
        t = GLOBE_RAY_FLY_FRAMES;
    // 112 (unten links) über 192 (oben) nach 0 (rechts).
    ang = 112 + (t * 144) / GLOBE_RAY_FLY_FRAMES;
    x = GLOBE_SCR_X + Cos(ang, 84);
    y = GLOBE_SCR_Y_END + Sin(ang, 62);
    if (sGlobeRaySprite != SPRITE_NONE)
    {
        gSprites[sGlobeRaySprite].x = x;
        gSprites[sGlobeRaySprite].y = y;
        gSprites[sGlobeRaySprite].invisible = FALSE;
    }
    if ((t & 3) == 0)
        SpawnSpark(x + 10, y + 6);
}

static void StopScene3Effects(void)
{
    sGlobeRainScroll = FALSE;
    sGlobeFogScroll = FALSE;
    sGlobeHeartPulse = 0;
    sGlobeMosaic = 0;
    sGlobeShakeTimer = 0;
    sGlobeFlashTimer = 0;
    sGlobeLabelTimer = 0;
    SetGpuReg(REG_OFFSET_MOSAIC, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    ClearGpuRegBits(REG_OFFSET_DISPCNT, DISPCNT_WIN0_ON);
    SetBgAttribute(1, BG_ATTR_PRIORITY, 2);
    SetBgAttribute(2, BG_ATTR_MOSAIC, 0);
    DestroyGlobeSilhouettes();
    DestroyGlobeRayquaza();
    DestroyScene7Sprites();
    FreeSpriteTilesByTag(TAG_KYOGRE_SIL);
    FreeSpriteTilesByTag(TAG_GROUDON_SIL);
    FreeSpriteTilesByTag(TAG_RAYQUAZA_SIL);
    FreeSpriteTilesByTag(TAG_SPARK);
    FreeSpriteTilesByTag(TAG_DARKRAI_EYES);
    FreeSpriteTilesByTag(TAG_DARKRAI_SIL);
    FreeSpritePaletteByTag(TAG_KYOGRE_SIL);
    FreeSpritePaletteByTag(TAG_GROUDON_SIL);
    FreeSpritePaletteByTag(TAG_RAYQUAZA_SIL);
    FreeSpritePaletteByTag(TAG_SPARK);
    FreeSpritePaletteByTag(TAG_DARKRAI_EYES);
    FreeSpritePaletteByTag(TAG_DARKRAI_SIL);
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, GLOBE_BGM_VOL_NORMAL);
    PlaySE(SE_THUNDERSTORM_STOP);
}

static void StartWeatherPhase(u8 weather, u16 duration)
{
    sGlobeWeather = weather;
    LoadGlobeWeatherPalette(weather);
    SetRainOverlay(weather == WEATHER_RAIN);
    ShowWeatherSilhouette(weather);
    sGlobeMosaic = 7;
    sGlobeShakeTimer = 10;
    sGlobeFlashTimer = 3;
    sGlobeLabelTimer = (duration < 40) ? duration : 40;

    if (weather == WEATHER_RAIN)
    {
        PrintGlobeLabel(sText_Globe_Rain, 5, 6);
        PlaySE(SE_M_RAIN_DANCE);
        if (duration >= 60)
            PlaySE(SE_THUNDERSTORM);
        if (duration >= 36)
        {
            PlaySE(SE_THUNDER);
            PlayCry_Script(SPECIES_KYOGRE, CRY_MODE_ENCOUNTER);
        }
    }
    else
    {
        PlaySE(SE_THUNDERSTORM_STOP);
        PrintGlobeLabel(sText_Globe_Drought, 7, 8);
        PlaySE(SE_M_HEAT_WAVE);
        if (duration >= 36)
            PlayCry_Script(SPECIES_GROUDON, CRY_MODE_ENCOUNTER);
    }
}

static void UpdateScene3Effects(u16 pulse, s16 scale, u16 angle)
{
    s16 shakeX = 0;
    s16 shakeY = 0;
    s32 texX = GLOBE_TEX_CENTER;

    if (sGlobeShakeTimer != 0)
    {
        shakeX = (sGlobeShakeTimer & 1) ? 1 : -1;
        shakeY = (sGlobeShakeTimer & 2) ? 1 : 0;
        sGlobeShakeTimer--;
    }

    if (sGlobeMosaic != 0)
        sGlobeMosaic--;

    if (sGlobeWeather == WEATHER_DROUGHT)
    {
        // Hitzeflimmern: Textur und Maßstab zittern leicht.
        texX += Sin((pulse * 8) & 0xFF, 3) * 256;
        scale += Sin((pulse * 11) & 0xFF, 2);
        PulseAtmosphereColors(pulse, sGlobeDroughtAtmos, 31, 30, 16);
    }
    else
    {
        PulseAtmosphereColors(pulse, sGlobeRainAtmos, 24, 29, 31);
    }

    sGlobeAffine.texX = texX;
    sGlobeAffine.texY = GLOBE_TEX_CENTER;
    sGlobeAffine.scrX = GLOBE_SCR_X + shakeX;
    sGlobeAffine.scrY = GLOBE_SCR_Y_END + shakeY;
    sGlobeAffine.scale = scale;
    sGlobeAffine.angle = angle;
    ApplyGlobeAffine();

    if (sGlobeFlashTimer != 0)
    {
        u8 coeff = (sGlobeFlashTimer == 3) ? 16 : (sGlobeFlashTimer == 2) ? 10 : 4;
        BlendPalettes(PALETTES_ALL, coeff, RGB_WHITE);
        sGlobeFlashTimer--;
        if (sGlobeFlashTimer == 0)
            BlendPalettes(PALETTES_ALL, 0, RGB_WHITE);
    }

    if (sGlobeLabelTimer != 0)
    {
        sGlobeLabelTimer--;
        if (sGlobeLabelTimer == 0)
            ClearGlobeText();
    }
}

// Nach den Globus-Szenen 1–7 folgt die Titelkarte. Mystery-Tafel und
// der alte Darkrai-Teaser entfallen, weil Szene 7 dasselbe erzählt.
static void StartPrologueIntroCards(u8 taskId)
{
    StopScene3Effects();
    ResetSpriteData();
    FreeAllSpritePalettes();
    FreePrologueBgAndWindow();
    InitPrologueBgAndWindow();
    SetVBlankCallback(VBlankCB_NyxthraPrologue);
    SetMainCallback2(CB2_NyxthraPrologue);
    m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, GLOBE_BGM_VOL_NORMAL);
    gTasks[taskId].func = Task_Prologue_TitleLogo;
    gTasks[taskId].tState = CARD_STATE_FADE_IN;
    gTasks[taskId].tCardIdx = 0;
    gTasks[taskId].tTimer = 0;
}

enum
{
    GLOBE_STATE_INIT,
    GLOBE_STATE_STARS_FADE,
    GLOBE_STATE_EARTH_RISE,
    GLOBE_STATE_TYPE_LINE1,
    GLOBE_STATE_TYPE_LINE2,
    GLOBE_STATE_HOLD1,
    GLOBE_STATE_SCENE2_START,
    GLOBE_STATE_ZOOM,
    GLOBE_STATE_SCENE3_START,
    GLOBE_STATE_SCENE3,
    GLOBE_STATE_SCENE4_START,
    GLOBE_STATE_SCENE4,
    GLOBE_STATE_SCENE5_START,
    GLOBE_STATE_SCENE5,
    GLOBE_STATE_SCENE6_START,
    GLOBE_STATE_SCENE6,
    GLOBE_STATE_SCENE7_START,
    GLOBE_STATE_SCENE7,
    GLOBE_STATE_FADE_OUT,
    GLOBE_STATE_DONE,
};

#define tGlobePulse data[6]
#define tTypedScene2 data[7]
#define tBgmFaded data[8]
#define tWeatherStep data[9]
#define tScene3Timer data[10]

static void Task_Prologue_GlobeScenes(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    bool8 skip = JOY_NEW(A_BUTTON | START_BUTTON);
    s16 riseT;
    s16 zoomT;
    s16 eased;
    s16 y;
    s16 scale;
    u16 angle;

    // Skip: Szenen 1–7 abbrechen und zur Titelkarte springen.
    if (skip && tState > GLOBE_STATE_INIT && tState < GLOBE_STATE_FADE_OUT)
    {
        if (!gPaletteFade.active)
        {
            StopScene3Effects();
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            FadeOutBGM(4);
            tState = GLOBE_STATE_FADE_OUT;
        }
    }

    switch (tState)
    {
    case GLOBE_STATE_INIT:
        if (IsDma3ManagerBusyWithBgCopy())
            return;
        // Sicherstellen, dass die 256 affinen Kachelindizes wirklich in VRAM
        // liegen (eine vorherige DMA-Kopie kann in der Init-Warteschlange
        // untergegangen sein).
        {
            u8 *map = GetBgTilemapBuffer(2);
            if (map != NULL)
                CpuCopy16(map, (void *)(BG_SCREEN_ADDR(26)), 0x100);
        }
        tTimer = 0;
        tState = GLOBE_STATE_STARS_FADE;
        BeginNormalPaletteFade((1 << PROLOGUE_STARS_PAL), 1, 16, 0, RGB_BLACK);
        break;

    case GLOBE_STATE_STARS_FADE:
        tTimer++;
        if (!gPaletteFade.active && tTimer >= GLOBE_STARS_FADE_FRAMES)
        {
            tTimer = 0;
            tState = GLOBE_STATE_EARTH_RISE;
            BeginNormalPaletteFade((1 << 0) | (1 << 1) | (1 << 8), 1, 16, 0, RGB_BLACK);
        }
        break;

    case GLOBE_STATE_EARTH_RISE:
        tTimer++;
        riseT = tTimer;
        if (riseT > GLOBE_RISE_FRAMES)
            riseT = GLOBE_RISE_FRAMES;
        // Ease-out: 1 - (1-t)^2
        eased = riseT * 128 / GLOBE_RISE_FRAMES;          // 0..128
        eased = 128 - ((128 - eased) * (128 - eased) / 128);
        y = GLOBE_SCR_Y_START + (GLOBE_SCR_Y_END - GLOBE_SCR_Y_START) * eased / 128;
        SetGlobeAffine(y, GLOBE_SCALE_1_0, 0);
        if (!gPaletteFade.active)
            PulseGlobeAtmosphere(tTimer);
        if (tTimer >= GLOBE_RISE_FRAMES)
        {
            SetGlobeAffine(GLOBE_SCR_Y_END, GLOBE_SCALE_1_0, 0);
            PrintPrologueLineTyped(sText_Globe_Hoenn, GLOBE_TEXT_Y1);
            tTimer = 0;
            tGlobePulse = 0;
            tState = GLOBE_STATE_TYPE_LINE1;
        }
        break;

    case GLOBE_STATE_TYPE_LINE1:
        tGlobePulse++;
        SetGlobeAffine(GLOBE_SCR_Y_END, GLOBE_SCALE_1_0 + Sin(tGlobePulse, 3), 0);
        PulseGlobeAtmosphere(tGlobePulse);
        if (!IsTextPrinterActiveOnWindow(0))
        {
            PrintPrologueLineTyped(sText_Globe_Balance, GLOBE_TEXT_Y2);
            tState = GLOBE_STATE_TYPE_LINE2;
        }
        break;

    case GLOBE_STATE_TYPE_LINE2:
        tGlobePulse++;
        SetGlobeAffine(GLOBE_SCR_Y_END, GLOBE_SCALE_1_0 + Sin(tGlobePulse, 3), 0);
        PulseGlobeAtmosphere(tGlobePulse);
        if (!IsTextPrinterActiveOnWindow(0))
        {
            tTimer = 0;
            tState = GLOBE_STATE_HOLD1;
        }
        break;

    case GLOBE_STATE_HOLD1:
        tGlobePulse++;
        tTimer++;
        SetGlobeAffine(GLOBE_SCR_Y_END, GLOBE_SCALE_1_0 + Sin(tGlobePulse, 3), 0);
        PulseGlobeAtmosphere(tGlobePulse);
        // Rest von Szene 1 (6 s ab Start der Sterne). Rise+Fade ~190 Frames,
        // der Rest ist Tippen + Halten. Wir halten nach dem Tippen noch kurz.
        if (tTimer >= 90)
            tState = GLOBE_STATE_SCENE2_START;
        break;

    case GLOBE_STATE_SCENE2_START:
        ClearGlobeText();
        tTimer = 0;
        tTypedScene2 = 0;
        tBgmFaded = 0;
        tState = GLOBE_STATE_ZOOM;
        PrintPrologueLineTyped(sText_Globe_Forces1, GLOBE_TEXT_Y1);
        break;

    case GLOBE_STATE_ZOOM:
        tTimer++;
        tGlobePulse++;
        zoomT = tTimer;
        if (zoomT > GLOBE_ZOOM_FRAMES)
            zoomT = GLOBE_ZOOM_FRAMES;
        // Ease-in-out über eine halbe Cosinus-Periode (0..128).
        eased = (128 - Cos((zoomT * 128) / GLOBE_ZOOM_FRAMES, 128)) / 2;
        scale = GLOBE_SCALE_1_0 + (GLOBE_SCALE_1_8 - GLOBE_SCALE_1_0) * eased / 128;
        angle = (u16)(GLOBE_ANGLE_END * (u32)eased / 128);
        SetGlobeAffine(GLOBE_SCR_Y_END, scale, angle);
        PulseGlobeAtmosphere(tGlobePulse);

        if (tTypedScene2 == 0 && !IsTextPrinterActiveOnWindow(0))
        {
            PrintPrologueLineTyped(sText_Globe_Forces2, GLOBE_TEXT_Y2);
            tTypedScene2 = 1;
        }

        if (tBgmFaded == 0 && tTimer >= GLOBE_ZOOM_FRAMES - 80)
        {
            FadeOutBGM(4);
            tBgmFaded = 1;
        }

        if (tTimer >= GLOBE_SCENE2_FRAMES)
        {
            tState = GLOBE_STATE_SCENE3_START;
            tTimer = 0;
        }
        break;

    case GLOBE_STATE_SCENE3_START:
        ClearGlobeText();
        CreateGlobeSilhouettes();
        m4aSongNumStart(MUS_ABNORMAL_WEATHER);
        tWeatherStep = 0;
        tScene3Timer = 0;
        tGlobePulse = 0;
        tTimer = sWeatherDurations[0];
        StartWeatherPhase(WEATHER_RAIN, sWeatherDurations[0]);
        tState = GLOBE_STATE_SCENE3;
        break;

    case GLOBE_STATE_SCENE3:
    {
        u16 duration = sWeatherDurations[tWeatherStep];
        s16 scale = GLOBE_SCALE_1_8;
        u16 angle;

        tScene3Timer++;
        tGlobePulse++;

        // Vom Zoom 1,8x etwas zurück, damit Silhouetten Platz haben.
        if (tScene3Timer < 48)
            scale = GLOBE_SCALE_1_8 + (GLOBE_SCALE_SCENE3 - GLOBE_SCALE_1_8) * tScene3Timer / 48;
        else
            scale = GLOBE_SCALE_SCENE3;

        angle = GLOBE_ANGLE_END + tScene3Timer * 4;
        UpdateScene3Effects(tGlobePulse, scale, angle);

        // In längeren Regenphasen ein zweiter Blitz in der Mitte.
        if (sGlobeWeather == WEATHER_RAIN
            && duration >= 60
            && tTimer == duration / 2
            && sGlobeFlashTimer == 0)
        {
            sGlobeFlashTimer = 3;
            PlaySE(SE_THUNDER);
        }

        tTimer--;
        if (tTimer <= 0)
        {
            tWeatherStep++;
            if (tWeatherStep >= (s16)ARRAY_COUNT(sWeatherDurations))
            {
                tState = GLOBE_STATE_SCENE4_START;
                tTimer = 0;
            }
            else
            {
                u8 nextWeather = (tWeatherStep & 1) ? WEATHER_DROUGHT : WEATHER_RAIN;
                tTimer = sWeatherDurations[tWeatherStep];
                StartWeatherPhase(nextWeather, sWeatherDurations[tWeatherStep]);
            }
        }
        break;
    }

    case GLOBE_STATE_SCENE4_START:
        StopScene3Effects();
        ClearGlobeText();
        LoadPalette(gNyxthraPrologueGlobe_Pal, BG_PLTT_ID(0), 32 * sizeof(u16));
        LoadPalette(&(u16){RGB_BLACK}, BG_PLTT_ID(0), sizeof(u16));
        FillBg1Stars();
        CreateGlobeRayquaza();
        m4aSongNumStart(MUS_RAYQUAZA_APPEARS);
        sGlobeFlashTimer = 8;
        sGlobeShakeTimer = 16;
        sGlobeMosaic = 6;
        sGlobeRayFlyTimer = 0;
        tTimer = 0;
        tGlobePulse = 0;
        tState = GLOBE_STATE_SCENE4;
        break;

    case GLOBE_STATE_SCENE4:
    {
        s16 scale;
        u16 angle;

        tTimer++;
        tGlobePulse++;

        // Nach der Nahaufnahme von Szene 3 zoomen wir zurück, damit
        // Rayquaza um die ganze Erde kreisen kann.
        if (tTimer < 48)
            scale = GLOBE_SCALE_SCENE3 + (GLOBE_SCALE_1_0 - GLOBE_SCALE_SCENE3) * tTimer / 48;
        else
            scale = GLOBE_SCALE_1_0;

        angle = GLOBE_ANGLE_END + tTimer * 2;

        if (tTimer == GLOBE_RAY_FLY_START)
        {
            PlayCry_Script(SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER);
            PlaySE(SE_M_DRAGON_RAGE);
            PlaySE(SE_M_FLY);
            sGlobeFlashTimer = 4;
            sGlobeShakeTimer = 12;
            PrintGlobeLabel(sText_Globe_Rayquaza, 5, 6);
            sGlobeLabelTimer = 0; // Text bleibt stehen
        }

        if (tTimer >= GLOBE_RAY_FLY_START)
        {
            if (sGlobeRayFlyTimer < GLOBE_RAY_FLY_FRAMES)
            {
                sGlobeRayFlyTimer++;
                SetRayquazaFlightPos(sGlobeRayFlyTimer);
            }
            else if (sGlobeRaySprite != SPRITE_NONE)
            {
                gSprites[sGlobeRaySprite].invisible = TRUE;
            }
        }

        // Gold-grünes Licht, gegen Ende zurück zur normalen Atmosphäre.
        if (tTimer < 240)
            PulseAtmosphereColors(tGlobePulse, sGlobeRayAtmos, 31, 31, 20);
        else
            PulseGlobeAtmosphere(tGlobePulse);

        {
            s16 shakeX = 0;
            s16 shakeY = 0;
            if (sGlobeShakeTimer != 0)
            {
                shakeX = (sGlobeShakeTimer & 1) ? 1 : -1;
                shakeY = (sGlobeShakeTimer & 2) ? 1 : 0;
                sGlobeShakeTimer--;
            }
            if (sGlobeMosaic != 0)
                sGlobeMosaic--;
            sGlobeAffine.texX = GLOBE_TEX_CENTER;
            sGlobeAffine.texY = GLOBE_TEX_CENTER;
            sGlobeAffine.scrX = GLOBE_SCR_X + shakeX;
            sGlobeAffine.scrY = GLOBE_SCR_Y_END + shakeY;
            sGlobeAffine.scale = scale;
            sGlobeAffine.angle = angle;
            ApplyGlobeAffine();
        }

        if (sGlobeFlashTimer != 0)
        {
            u8 coeff = (sGlobeFlashTimer > 5) ? 16 : (sGlobeFlashTimer * 3);
            if (coeff > 16)
                coeff = 16;
            BlendPalettes(PALETTES_ALL, coeff, RGB_WHITE);
            sGlobeFlashTimer--;
            if (sGlobeFlashTimer == 0)
                BlendPalettes(PALETTES_ALL, 0, RGB_WHITE);
        }

        if (tTimer == 280)
            FadeOutBGM(4);

        if (tTimer >= GLOBE_SCENE4_FRAMES)
            tState = GLOBE_STATE_SCENE5_START;
        break;
    }

    case GLOBE_STATE_SCENE5_START:
        // Kein Fade ins Schwarze: die Erde bleibt stehen, der Streit ist
        // vorbei, und der Sonnenaufgang setzt ein.
        StopScene3Effects();
        ClearGlobeText();
        LoadPalette(gNyxthraPrologueGlobeSunrise_Pal, BG_PLTT_ID(0), 32 * sizeof(u16));
        LoadPalette(&(u16){RGB_BLACK}, BG_PLTT_ID(0), sizeof(u16));
        FillBg1Stars();
        m4aMPlayStop(&gMPlayInfo_BGM);
        sGlobeFlashTimer = 0;
        sGlobeMosaic = 0;
        sGlobeShakeTimer = 0;
        tTimer = 0;
        tTypedScene2 = 0;
        tGlobePulse = 0;
        tState = GLOBE_STATE_SCENE5;
        break;

    case GLOBE_STATE_SCENE5:
        tTimer++;
        tGlobePulse++;
        SetGlobeAffine(GLOBE_SCR_Y_END, GLOBE_SCALE_1_0, GLOBE_ANGLE_END + tTimer);

        PulseAtmosphereColors(tGlobePulse, sGlobeSunriseAtmos, 31, 28, 18);

        if (tTypedScene2 == 0 && tTimer >= GLOBE_SCENE5_LEAD_FRAMES)
        {
            PrintPrologueLineTyped(sText_Globe_Centuries1, GLOBE_TEXT_Y1);
            tTypedScene2 = 1;
        }
        else if (tTypedScene2 == 1 && !IsTextPrinterActiveOnWindow(0))
        {
            PrintPrologueLineTyped(sText_Globe_Centuries2, GLOBE_TEXT_Y2);
            tTypedScene2 = 2;
        }
        else if (tTypedScene2 == 2 && !IsTextPrinterActiveOnWindow(0))
        {
            tTimer = 0;
            tTypedScene2 = 3;
        }
        else if (tTypedScene2 == 3 && tTimer >= GLOBE_SCENE5_SILENCE_FRAMES)
            tState = GLOBE_STATE_SCENE6_START;
        break;

    case GLOBE_STATE_SCENE6_START:
        // Die Erde bleibt im Sonnenaufgang stehen. Violetter Nebel kriecht
        // herüber, der Herzschlag setzt ein, die Stille ist vorbei.
        ClearGlobeText();
        LoadBgTiles(1, gNyxthraPrologueFog_Gfx, 16 * 16 * TILE_SIZE_4BPP, GLOBE_FOG_TILE);
        LoadPalette(gNyxthraPrologueFog_Pal, BG_PLTT_ID(GLOBE_FOG_PAL), PLTT_SIZE_4BPP);
        FillBg1Fog();
        SetBgAttribute(1, BG_ATTR_PRIORITY, 0);
        ChangeBgX(1, 0, BG_COORD_SET);
        ChangeBgY(1, 0, BG_COORD_SET);
        sGlobeFogScroll = TRUE;
        sGlobeRainScroll = FALSE;
        sGlobeHeartPulse = 0;
        sGlobeShakeTimer = 0;
        CreateScene6Silhouettes();
        m4aSongNumStart(MUS_PL_DISTORTION_WORLD);
        tTimer = 0;
        tTypedScene2 = 0;
        tBgmFaded = 0; // wie viele Silhouetten schon umgefärbt sind
        tWeatherStep = 20; // erster Herzschlag kurz nach dem Einsatz
        tGlobePulse = 0;
        tState = GLOBE_STATE_SCENE6;
        break;

    case GLOBE_STATE_SCENE6:
    {
        s16 scale = GLOBE_SCALE_1_0;
        u16 angle;
        s16 shakeX = 0;
        s16 shakeY = 0;
        u8 pulseAmt;

        tTimer++;

        pulseAmt = UpdateHeartbeatPulse();
        if (pulseAmt != 0)
            scale = GLOBE_SCALE_1_0 - (10 * pulseAmt / 6); // etwa +4 % Zoom

        if (sGlobeShakeTimer != 0)
        {
            shakeX = (sGlobeShakeTimer & 1) ? 1 : -1;
            shakeY = (sGlobeShakeTimer & 2) ? 1 : 0;
            sGlobeShakeTimer--;
        }

        angle = GLOBE_ANGLE_END + tTimer;
        sGlobeAffine.texX = GLOBE_TEX_CENTER;
        sGlobeAffine.texY = GLOBE_TEX_CENTER;
        sGlobeAffine.scrX = GLOBE_SCR_X + shakeX;
        sGlobeAffine.scrY = GLOBE_SCR_Y_END + shakeY;
        sGlobeAffine.scale = scale;
        sGlobeAffine.angle = angle;
        ApplyGlobeAffine();

        LerpGlobePalette(gNyxthraPrologueGlobeSunrise_Pal, gNyxthraPrologueGlobeMist_Pal, tTimer, GLOBE_SCENE6_PAL_FRAMES);
        if (tTimer >= GLOBE_SCENE6_PAL_FRAMES)
            PulseAtmosphereColors(tTimer, sGlobeMistAtmos, 24, 10, 28);

        UpdateScene6Fog(tTimer, sGlobeHeartPulse);

        tWeatherStep--;
        if (tWeatherStep <= 0)
        {
            TriggerHeartbeat();
            if (tTimer >= GLOBE_SCENE6_SIL_FRAMES && tBgmFaded < 3)
                ShiftNextNyxthraSilhouette(&tBgmFaded);
            tWeatherStep = GetScene6HeartInterval(tTimer);
        }

        if (tTimer == GLOBE_SCENE6_SIL_FRAMES)
            ShowScene6Silhouettes();

        if (tTypedScene2 == 0 && tTimer >= GLOBE_SCENE6_TEXT_FRAMES)
        {
            PrintPrologueLineTypedFit(sText_Globe_Change1, GLOBE_TEXT_Y1);
            tTypedScene2 = 1;
        }
        else if (tTypedScene2 == 1 && !IsTextPrinterActiveOnWindow(0) && tTimer >= GLOBE_SCENE6_SIL_FRAMES)
        {
            PrintPrologueLineTypedFit(sText_Globe_Change2, GLOBE_TEXT_Y2);
            tTypedScene2 = 2;
        }

        if (tTimer >= GLOBE_SCENE6_END_FRAMES && tTypedScene2 >= 2 && !IsTextPrinterActiveOnWindow(0))
            tState = GLOBE_STATE_SCENE7_START;
        break;
    }

    case GLOBE_STATE_SCENE7_START:
        // Der Planet bleibt im Nebel, die Legendären verschwinden, und
        // aus der Stille blicken rote Augen.
        DestroyGlobeSilhouettes();
        DestroyGlobeRayquaza();
        ClearGlobeText();
        FillBg1Fog();
        sGlobeFogScroll = TRUE;
        sGlobeHeartPulse = 0;
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, TRACKS_ALL, GLOBE_BGM_VOL_NORMAL);
        m4aSongNumStart(MUS_DP_LEGEND_APPEARS);
        CreateScene7Sprites();
        tTimer = 0;
        tTypedScene2 = 0;
        tBgmFaded = 0; // 0 = vor dem Blitz, 1 = Silhouette sichtbar, 2 = danach, 3 = Loch
        tWeatherStep = 20;
        tState = GLOBE_STATE_SCENE7;
        break;

    case GLOBE_STATE_SCENE7:
    {
        s16 scale = GLOBE_SCALE_1_0;
        u16 angle;
        s16 shakeX = 0;
        s16 shakeY = 0;
        u8 pulseAmt;

        tTimer++;
        pulseAmt = UpdateHeartbeatPulse();
        if (pulseAmt != 0)
            scale = GLOBE_SCALE_1_0 - (10 * pulseAmt / 6);
        if (tTypedScene2 == 5)
            scale = GLOBE_SCALE_1_0 + tTimer * 28;

        if (sGlobeShakeTimer != 0)
        {
            shakeX = (sGlobeShakeTimer & 1) ? 1 : -1;
            shakeY = (sGlobeShakeTimer & 2) ? 1 : 0;
            sGlobeShakeTimer--;
        }

        // Planet verdunkelt sich, der Nebel bleibt.
        if (sGlobeFlashTimer == 0 && tTypedScene2 < 5)
        {
            LerpGlobePalette(gNyxthraPrologueGlobeMist_Pal, gNyxthraPrologueGlobeMist_Pal, 16, 16);
            {
                u16 dark = (tTimer < 60) ? (tTimer * 12 / 60) : 12;
                BlendPalettes(0x0003, dark, RGB_BLACK); // pals 0–1 = globe
            }
        }

        angle = GLOBE_ANGLE_END + tTimer;
        sGlobeAffine.texX = GLOBE_TEX_CENTER;
        sGlobeAffine.texY = GLOBE_TEX_CENTER;
        sGlobeAffine.scrX = GLOBE_SCR_X + shakeX;
        sGlobeAffine.scrY = GLOBE_SCR_Y_END + shakeY;
        sGlobeAffine.scale = scale;
        sGlobeAffine.angle = angle;
        ApplyGlobeAffine();
        UpdateScene6Fog(GLOBE_SCENE6_WIPE_FRAMES + tTimer, sGlobeHeartPulse);

        tWeatherStep--;
        if (tWeatherStep <= 0 && tBgmFaded < 3)
        {
            TriggerHeartbeat();
            tWeatherStep = GLOBE_HEART_INTERVAL_END;
        }

        if (tTypedScene2 == 0 && tTimer >= GLOBE_SCENE7_EYES_FRAMES)
        {
            if (sGlobeEyesSprite != SPRITE_NONE)
                gSprites[sGlobeEyesSprite].invisible = FALSE;
            PlaySE(SE_M_NIGHTMARE);
            PrintPrologueLineTypedFit(sText_Globe_Watched, GLOBE_TEXT_Y1);
            tTypedScene2 = 1;
        }
        else if (tTypedScene2 == 1 && !IsTextPrinterActiveOnWindow(0) && tTimer >= GLOBE_SCENE7_FLASH_FRAMES)
        {
            // Blitz: Darkrai-Silhouette, Ruf, Augen kurz verdeckt.
            if (sGlobeEyesSprite != SPRITE_NONE)
                gSprites[sGlobeEyesSprite].invisible = TRUE;
            if (sGlobeDarkraiSprite != SPRITE_NONE)
                gSprites[sGlobeDarkraiSprite].invisible = FALSE;
            sGlobeFlashTimer = 10;
            sGlobeShakeTimer = 14;
            tScene3Timer = 0;
            PlayCry_Script(SPECIES_DARKRAI, CRY_MODE_ENCOUNTER);
            PlaySE(SE_ORB);
            tBgmFaded = 1;
            tTypedScene2 = 2;
        }
        else if (tTypedScene2 == 2)
        {
            // Nach dem Blitz bleibt Darkrai eine Sekunde sichtbar.
            if (sGlobeFlashTimer == 0)
                tScene3Timer++;
            if (tScene3Timer >= GLOBE_SCENE7_SIL_HOLD_FRAMES)
            {
                if (sGlobeDarkraiSprite != SPRITE_NONE)
                    gSprites[sGlobeDarkraiSprite].invisible = TRUE;
                if (sGlobeEyesSprite != SPRITE_NONE)
                    gSprites[sGlobeEyesSprite].invisible = FALSE;
                PrintPrologueLineTypedFit(sText_Globe_Nyxthra, GLOBE_TEXT_Y2);
                tBgmFaded = 2;
                tTypedScene2 = 3;
            }
        }
        else if (tTypedScene2 == 3 && !IsTextPrinterActiveOnWindow(0))
        {
            tScene3Timer = 0;
            tTypedScene2 = 4;
        }
        else if (tTypedScene2 == 4)
        {
            tScene3Timer++;
            if (tScene3Timer >= GLOBE_SCENE7_HOLD_FRAMES)
            {
                // Augen schließen, der Planet fällt in die Schwärze.
                if (sGlobeEyesSprite != SPRITE_NONE)
                    gSprites[sGlobeEyesSprite].invisible = TRUE;
                DestroyScene7Sprites();
                ClearGlobeText();
                FadeOutBGM(4);
                tTimer = 0;
                tBgmFaded = 3;
                tTypedScene2 = 5;
            }
        }
        else if (tTypedScene2 == 5)
        {
            u16 coeff = (tTimer * 16) / 70;
            if (coeff > 16)
                coeff = 16;
            BlendPalettes(PALETTES_ALL, coeff, RGB_BLACK);
            if (tTimer >= 90)
            {
                BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
                tState = GLOBE_STATE_FADE_OUT;
            }
        }

        if (sGlobeFlashTimer != 0)
        {
            u8 coeff = (sGlobeFlashTimer > 5) ? 16 : (sGlobeFlashTimer * 3);
            if (coeff > 16)
                coeff = 16;
            BlendPalettes(PALETTES_ALL, coeff, RGB_WHITE);
            sGlobeFlashTimer--;
            if (sGlobeFlashTimer == 0)
                BlendPalettes(PALETTES_ALL, 0, RGB_WHITE);
        }
        break;
    }

    case GLOBE_STATE_FADE_OUT:
        if (!gPaletteFade.active)
            tState = GLOBE_STATE_DONE;
        break;

    case GLOBE_STATE_DONE:
        StartPrologueIntroCards(taskId);
        break;
    }
}

#undef tGlobePulse
#undef tTypedScene2
#undef tBgmFaded
#undef tWeatherStep
#undef tScene3Timer

void CB2_InitNyxthraPrologue(void)
{
    u8 taskId;

    SetVBlankCallback(NULL);
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetPaletteFade();
    ResetTasks();

    // Intro 2.0: ruhige Sootopolis-Musik über den neuen Erd-Szenen.
    // Szene 5 ist stumm, Szene 6 setzt MUS_PL_DISTORTION_WORLD an,
    // Szene 7 MUS_DP_LEGEND_APPEARS.
    InitPrologueGlobeScene();

    EnableInterrupts(INTR_FLAG_VBLANK);
    SetVBlankCallback(VBlankCB_NyxthraPrologueGlobe);
    SetMainCallback2(CB2_NyxthraPrologueGlobe);

    m4aSongNumStart(MUS_SOOTOPOLIS);
    taskId = CreateTask(Task_Prologue_GlobeScenes, 0);
    gTasks[taskId].tState = 0;
    gTasks[taskId].tTimer = 0;
}

#undef tState
#undef tTimer
#undef tCardIdx
