#include "global.h"
#include "bg.h"
#include "challenge_mode.h"
#include "challenge_mode_menu.h"
#include "gpu_regs.h"
#include "main.h"
#include "main_menu.h"
#include "menu.h"
#include "palette.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define CHALLENGE_WINDOW_ID 0
#define CHALLENGE_TEXTBOX_WINDOW_ID 1
#define CHALLENGE_BORDER_TILE 0x214

enum
{
    CHALLENGE_SCREEN_LIST,
    CHALLENGE_SCREEN_CONFIRM,
};

enum
{
    CHALLENGE_ITEM_DOOR_RANDOM,
    CHALLENGE_ITEM_COMING_SOON_1,
    CHALLENGE_ITEM_COMING_SOON_2,
    CHALLENGE_ITEM_COUNT,
};

enum
{
    CHALLENGE_CONFIRM_YES,
    CHALLENGE_CONFIRM_NO,
};

static const struct BgTemplate sChallengeBgTemplates[] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
};

static const struct WindowTemplate sChallengeWindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 1,
        .width = 26,
        .height = 11,
        .paletteNum = 15,
        .baseBlock = 8,
    },
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x180,
    },
    DUMMY_WIN_TEMPLATE
};

static const u16 sMainMenuTextPal[] = INCBIN_U16("graphics/interface/main_menu_text.gbapal");
static const u8 sTextColorTitle[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_GREEN, TEXT_COLOR_DARK_GRAY};
static const u8 sTextColorMain[] = {TEXT_COLOR_TRANSPARENT, TEXT_DYNAMIC_COLOR_3, TEXT_DYNAMIC_COLOR_2};

static const u8 sTextTitle[] = _("Challenge Modus");
static const u8 sTextDoorRandom[] = _("Random Warp Modus");
static const u8 sTextComingSoon[] = _("Coming soon…");
static const u8 sTextComingSoon2[] = _("Coming soon 2…");
static const u8 sTextCursor[] = _("▶");
static const u8 sTextYes[] = _("Ja");
static const u8 sTextNo[] = _("Nein");
static const u8 sTextConfirmStart[] = _("Jede Tür Random starten?");
static const u8 sTextInfoDoorRandom[] = _("Jeder Warp wird zufällig\nneu verbunden.");
static const u8 sTextInfoComingSoon[] = _("Dieser Challenge-Modus\nkommt später.");

static void CB2_ChallengeModeMenu(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_ChallengeModeMenu(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void InitChallengeTextPalette(void)
{
    u16 palette;

    LoadPalette(sMainMenuTextPal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);

    palette = gSaveBlock2Ptr->optionsUITheme ? RGB(6, 7, 9) : RGB_WHITE;
    LoadPalette(&palette, BG_PLTT_ID(15) + 10, PLTT_SIZEOF(1));
    if (!gSaveBlock2Ptr->optionsUITheme)
    {
        palette = RGB(8, 8, 8);
        LoadPalette(&palette, BG_PLTT_ID(15) + 11, PLTT_SIZEOF(1));
        palette = RGB(30, 30, 30);
        LoadPalette(&palette, BG_PLTT_ID(15) + 12, PLTT_SIZEOF(1));
    }

    if (IsFemaleStyle(gSaveBlock2Ptr->playerStyles[0]))
        palette = RGB(31, 3, 21);
    else
        palette = RGB(4, 16, 31);

    LoadPalette(&palette, BG_PLTT_ID(15) + 1, PLTT_SIZEOF(1));

    Nyxthra_ApplyDarkModeToWindowPalette(BG_PLTT_ID(15));

    if (gSaveBlock2Ptr->optionsUITheme)
    {
        // Dark mode: body text white with black shadow. Must run AFTER
        // Nyxthra_ApplyDarkModeToWindowPalette() above, which otherwise
        // immediately darkens this bright white right back down again (it
        // treats any bright neutral color as a leftover light-mode fill).
        palette = RGB_BLACK;
        LoadPalette(&palette, BG_PLTT_ID(15) + 11, PLTT_SIZEOF(1));
        palette = RGB_WHITE;
        LoadPalette(&palette, BG_PLTT_ID(15) + 12, PLTT_SIZEOF(1));

        // sTextColorTitle uses the raw TEXT_COLOR_GREEN, which was tuned for
        // a light background and is nearly unreadable on the dark window fill.
        palette = RGB(14, 30, 14);
        LoadPalette(&palette, BG_PLTT_ID(15) + TEXT_COLOR_GREEN, PLTT_SIZEOF(1));
    }

    // Keep title shadow black in both light and dark mode.
    palette = RGB_BLACK;
    LoadPalette(&palette, BG_PLTT_ID(15) + TEXT_COLOR_DARK_GRAY, PLTT_SIZEOF(1));
}

static void LoadChallengeWindowFrameTiles(u8 bgId, u16 tileOffset)
{
    LoadBgTiles(bgId, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, tileOffset);
    LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, BG_PLTT_ID(2), PLTT_SIZE_4BPP);

    if (gSaveBlock2Ptr->optionsUITheme)
        Nyxthra_ApplyDarkModeToBorderPalette(BG_PLTT_ID(2));
}

static void DrawChallengeWindowBorder(u8 windowId, u16 baseTileNum)
{
    u8 bg = GetWindowAttribute(windowId, WINDOW_BG);
    u8 left = GetWindowAttribute(windowId, WINDOW_TILEMAP_LEFT);
    u8 top = GetWindowAttribute(windowId, WINDOW_TILEMAP_TOP);
    u8 width = GetWindowAttribute(windowId, WINDOW_WIDTH);
    u8 height = GetWindowAttribute(windowId, WINDOW_HEIGHT);

    FillBgTilemapBufferRect(bg, baseTileNum + 0, left - 1, top - 1, 1, 1, 2);
    FillBgTilemapBufferRect(bg, baseTileNum + 1, left, top - 1, width, 1, 2);
    FillBgTilemapBufferRect(bg, baseTileNum + 2, left + width, top - 1, 1, 1, 2);
    FillBgTilemapBufferRect(bg, baseTileNum + 3, left - 1, top, 1, height, 2);
    FillBgTilemapBufferRect(bg, baseTileNum + 5, left + width, top, 1, height, 2);
    FillBgTilemapBufferRect(bg, baseTileNum + 6, left - 1, top + height, 1, 1, 2);
    FillBgTilemapBufferRect(bg, baseTileNum + 7, left, top + height, width, 1, 2);
    FillBgTilemapBufferRect(bg, baseTileNum + 8, left + width, top + height, 1, 1, 2);
}

static void DrawUserFrame(u8 windowId)
{
    ClearWindowTilemap(windowId);
    DrawChallengeWindowBorder(windowId, CHALLENGE_BORDER_TILE);
}

static void DrawInfoText(const u8 *text)
{
    FillWindowPixelBuffer(CHALLENGE_TEXTBOX_WINDOW_ID, PIXEL_FILL(1));
    DrawUserFrame(CHALLENGE_TEXTBOX_WINDOW_ID);
    AddTextPrinterParameterized3(CHALLENGE_TEXTBOX_WINDOW_ID, FONT_NORMAL, 8, 2, sTextColorMain, TEXT_SKIP_DRAW, text);
    PutWindowTilemap(CHALLENGE_TEXTBOX_WINDOW_ID);
    CopyWindowToVram(CHALLENGE_TEXTBOX_WINDOW_ID, COPYWIN_FULL);
}

static void DrawListWindow(u8 cursor)
{
    FillWindowPixelBuffer(CHALLENGE_WINDOW_ID, PIXEL_FILL(1));
    DrawUserFrame(CHALLENGE_WINDOW_ID);

    AddTextPrinterParameterized3(CHALLENGE_WINDOW_ID, FONT_NORMAL, 8, 1, sTextColorTitle, TEXT_SKIP_DRAW, sTextTitle);
    AddTextPrinterParameterized3(CHALLENGE_WINDOW_ID, FONT_NORMAL, 16, 30, sTextColorMain, TEXT_SKIP_DRAW, sTextDoorRandom);
    AddTextPrinterParameterized3(CHALLENGE_WINDOW_ID, FONT_NORMAL, 16, 46, sTextColorMain, TEXT_SKIP_DRAW, sTextComingSoon);
    AddTextPrinterParameterized3(CHALLENGE_WINDOW_ID, FONT_NORMAL, 16, 62, sTextColorMain, TEXT_SKIP_DRAW, sTextComingSoon2);
    AddTextPrinterParameterized3(CHALLENGE_WINDOW_ID, FONT_NORMAL, 2, 30 + (cursor * 16), sTextColorMain, TEXT_SKIP_DRAW, sTextCursor);

    PutWindowTilemap(CHALLENGE_WINDOW_ID);
    CopyWindowToVram(CHALLENGE_WINDOW_ID, COPYWIN_FULL);

    if (cursor == CHALLENGE_ITEM_DOOR_RANDOM)
        DrawInfoText(sTextInfoDoorRandom);
    else
        DrawInfoText(sTextInfoComingSoon);
}

static void DrawConfirmWindow(u8 cursor)
{
    FillWindowPixelBuffer(CHALLENGE_WINDOW_ID, PIXEL_FILL(1));
    DrawUserFrame(CHALLENGE_WINDOW_ID);

    AddTextPrinterParameterized3(CHALLENGE_WINDOW_ID, FONT_NORMAL, 8, 1, sTextColorTitle, TEXT_SKIP_DRAW, sTextTitle);
    AddTextPrinterParameterized3(CHALLENGE_WINDOW_ID, FONT_NORMAL, 16, 31, sTextColorMain, TEXT_SKIP_DRAW, sTextConfirmStart);
    AddTextPrinterParameterized3(CHALLENGE_WINDOW_ID, FONT_NORMAL, 40, 57, sTextColorMain, TEXT_SKIP_DRAW, sTextYes);
    AddTextPrinterParameterized3(CHALLENGE_WINDOW_ID, FONT_NORMAL, 40, 73, sTextColorMain, TEXT_SKIP_DRAW, sTextNo);
    AddTextPrinterParameterized3(CHALLENGE_WINDOW_ID, FONT_NORMAL, 20, 57 + (cursor * 16), sTextColorMain, TEXT_SKIP_DRAW, sTextCursor);

    PutWindowTilemap(CHALLENGE_WINDOW_ID);
    CopyWindowToVram(CHALLENGE_WINDOW_ID, COPYWIN_FULL);

    DrawInfoText(sTextInfoDoorRandom);
}

static void ReturnToMainMenu(void)
{
    PlaySE(SE_SELECT);
    ChallengeMode_DisableDoorWarpRandom();
    SetMainCallback2(CB2_InitMainMenu);
}

static void Task_ChallengeModeMenu(u8 taskId)
{
    bool8 redraw = FALSE;
    s16 cursor = gTasks[taskId].data[0];

    if (gTasks[taskId].data[1] == CHALLENGE_SCREEN_LIST)
    {
        if (JOY_NEW(DPAD_UP))
        {
            if (cursor > 0)
                cursor--;
            redraw = TRUE;
        }
        else if (JOY_NEW(DPAD_DOWN))
        {
            if (cursor < CHALLENGE_ITEM_COUNT - 1)
                cursor++;
            redraw = TRUE;
        }

        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (cursor == CHALLENGE_ITEM_DOOR_RANDOM)
            {
                gTasks[taskId].data[1] = CHALLENGE_SCREEN_CONFIRM;
                gTasks[taskId].data[0] = CHALLENGE_CONFIRM_NO;
                DrawConfirmWindow(CHALLENGE_CONFIRM_NO);
            }
            else
            {
                DrawInfoText(sTextInfoComingSoon);
            }
            return;
        }

        if (JOY_NEW(B_BUTTON))
        {
            ReturnToMainMenu();
            return;
        }
    }
    else
    {
        if (JOY_NEW(DPAD_UP) || JOY_NEW(DPAD_DOWN) || JOY_NEW(DPAD_LEFT) || JOY_NEW(DPAD_RIGHT))
        {
            cursor ^= 1;
            redraw = TRUE;
        }

        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (cursor == CHALLENGE_CONFIRM_YES)
            {
                ChallengeMode_EnableDoorWarpRandom();
                MainMenu_BeginBirchSpeechScene();
            }
            else
            {
                ReturnToMainMenu();
            }
            return;
        }

        if (JOY_NEW(B_BUTTON))
        {
            ReturnToMainMenu();
            return;
        }
    }

    if (cursor != gTasks[taskId].data[0])
    {
        gTasks[taskId].data[0] = cursor;
        redraw = TRUE;
    }

    if (redraw)
    {
        if (gTasks[taskId].data[1] == CHALLENGE_SCREEN_LIST)
            DrawListWindow(gTasks[taskId].data[0]);
        else
            DrawConfirmWindow(gTasks[taskId].data[0]);
    }
}

void CB2_InitChallengeModeMenu(void)
{
    u8 taskId;

    SetVBlankCallback(NULL);
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);

    ResetPaletteFade();
    ScanlineEffect_Stop();
    ResetTasks();
    ResetSpriteData();
    FreeAllSpritePalettes();
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);

    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sChallengeBgTemplates, ARRAY_COUNT(sChallengeBgTemplates));
    InitWindows(sChallengeWindowTemplates);
    DeactivateAllTextPrinters();
    InitChallengeTextPalette();
    LoadChallengeWindowFrameTiles(0, CHALLENGE_BORDER_TILE);

    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);

    taskId = CreateTask(Task_ChallengeModeMenu, 0);
    gTasks[taskId].data[0] = CHALLENGE_ITEM_DOOR_RANDOM;
    gTasks[taskId].data[1] = CHALLENGE_SCREEN_LIST;
    DrawListWindow(CHALLENGE_ITEM_DOOR_RANDOM);

    EnableInterrupts(1);
    SetVBlankCallback(VBlankCB_ChallengeModeMenu);
    SetMainCallback2(CB2_ChallengeModeMenu);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
}
