#include "global.h"
#include "bg.h"
#include "gpu_regs.h"
#include "main.h"
#include "main_menu.h"
#include "menu.h"
#include "palette.h"
#include "random.h"
#include "randomizer.h"
#include "scanline_effect.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "window.h"
#include "constants/rgb.h"
#include "constants/songs.h"

#define RANDOMIZER_WINDOW_ID 0
#define RANDOMIZER_TEXTBOX_WINDOW_ID 1
#define RANDOMIZER_VISIBLE_OPTION_COUNT 6
#define RANDOMIZER_BORDER_TILE 0x214

enum
{
    SCREEN_ASK,
    SCREEN_CONFIG,
    SCREEN_START_CONFIRM,
};

enum
{
    ASK_CURSOR_YES,
    ASK_CURSOR_NO,
};

struct RandomizerSetupState
{
    bool8 enabled;
    u8 flags;
    u32 seed;
};

static EWRAM_DATA struct RandomizerSetupState sSetup = {0};

static const struct BgTemplate sBgTemplates[] =
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

static const struct WindowTemplate sWindowTemplates[] =
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
static const u8 sTextColorTitle[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_GREEN, TEXT_COLOR_LIGHT_GRAY};
static const u8 sTextColorHeader[] = {TEXT_DYNAMIC_COLOR_1, TEXT_DYNAMIC_COLOR_2, TEXT_DYNAMIC_COLOR_3};
static const u8 sTextColorMain[] = {TEXT_DYNAMIC_COLOR_1, TEXT_DYNAMIC_COLOR_2, TEXT_DYNAMIC_COLOR_3};
static const u8 sTextColorCursor[] = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED, TEXT_COLOR_LIGHT_GRAY};

static const u8 sTextTitle[] = _("Randomizer Setup");
static const u8 sTextAskEnable[] = _("Randomizer aktivieren?");
static const u8 sTextYes[] = _("Ja");
static const u8 sTextNo[] = _("Nein");
static const u8 sTextWild[] = _("Wild Pokémon");
static const u8 sTextTrainer[] = _("Trainer-Pokémon");
static const u8 sTextStarter[] = _("Starter-Pokémon");
static const u8 sTextEvolution[] = _("Evolutionsziel");
static const u8 sTextFieldItems[] = _("Field Items + TM/VM");
static const u8 sTextGift[] = _("Geschenk-Pokémon");
static const u8 sTextStatic[] = _("Statische Pokémon");
static const u8 sTextKeepLegends[] = _("Static Legenden fix");
static const u8 sTextSeed[] = _("Seed");
static const u8 sTextSave[] = _("Speichern");
static const u8 sTextOn[] = _("{COLOR GREEN}ON");
static const u8 sTextOff[] = _("{COLOR RED}OFF");
static const u8 sTextCursor[] = _("▶");
static const u8 sTextStartConfirm[] = _("Randomizer so starten?");
static const u8 sTextMsgAskYes[] = _("Ja: Einstellungen öffnen.");
static const u8 sTextMsgAskNo[] = _("Nein: Normal starten.");
static const u8 sTextMsgWild[] = _("Wilde Pokémon werden\nneu zugeordnet.");
static const u8 sTextMsgTrainer[] = _("Trainer-Pokémon werden\nneu zugeordnet.");
static const u8 sTextMsgStarter[] = _("Starter-Pokémon werden\nneu zugeordnet.");
static const u8 sTextMsgEvolution[] = _("Evolutionsziele werden\nneu zugeordnet.");
static const u8 sTextMsgField[] = _("Feld-Items, versteckte Items,\nShops und TM/VM werden gemappt.");
static const u8 sTextMsgGift[] = _("Geschenk-Pokémon werden\nneu zugeordnet.");
static const u8 sTextMsgStatic[] = _("Statische Begegnungen\nwerden neu zugeordnet.");
static const u8 sTextMsgKeepLegends[] = _("Legenden/Mythicals bleiben\nbei statischen Encountern fix.");
static const u8 sTextMsgSeed[] = _("A: Seed bearbeiten\nHoch/Runter: Menüpunkt.");
static const u8 sTextMsgSeedEdit[] = _("Links/Rechts: Stelle wählen\nHoch/Runter: Ziffer ändern.");
static const u8 sTextMsgSave[] = _("A: Start-Bestätigung  B: Zurück");
static const u8 sTextMsgConfirmYes[] = _("Ja: Speichern und Intro starten.");
static const u8 sTextMsgConfirmNo[] = _("Nein: Zurück zu Einstellungen.");

static const u8 *const sLabels[] =
{
    sTextWild,
    sTextTrainer,
    sTextStarter,
    sTextEvolution,
    sTextFieldItems,
    sTextGift,
    sTextStatic,
    sTextKeepLegends,
};

static const u8 sBits[] =
{
    RANDOMIZER_FLAG_WILD,
    RANDOMIZER_FLAG_TRAINER,
    RANDOMIZER_FLAG_STARTER,
    RANDOMIZER_FLAG_EVOLUTION,
    RANDOMIZER_FLAG_FIELD_ITEM,
    RANDOMIZER_FLAG_GIFT,
    RANDOMIZER_FLAG_STATIC,
    RANDOMIZER_FLAG_STATIC_KEEP_LEGENDS,
};

#define TOGGLE_COUNT ARRAY_COUNT(sLabels)
#define CURSOR_SEED TOGGLE_COUNT
#define CURSOR_CONFIRM (TOGGLE_COUNT + 1)

static const u32 sSeedPlaceValues[] =
{
    1000000000,
    100000000,
    10000000,
    1000000,
    100000,
    10000,
    1000,
    100,
    10,
    1,
};

static void ChangeSeedDigit(u8 digitIndex, bool8 increase)
{
    u32 place = sSeedPlaceValues[digitIndex];
    u32 digit = (sSetup.seed / place) % 10;
    u32 newDigit = increase ? ((digit + 1) % 10) : ((digit == 0) ? 9 : digit - 1);
    s64 candidate = (s64)sSetup.seed + ((s64)newDigit - (s64)digit) * (s64)place;

    if (candidate >= 0 && (u64)candidate <= 0xFFFFFFFFULL)
        sSetup.seed = (u32)candidate;
}

static void CB2_Randomizer(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static void VBlankCB_Randomizer(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static void InitDefaultConfig(void)
{
    sSetup.enabled = TRUE;
    sSetup.flags = RANDOMIZER_FLAG_WILD
                 | RANDOMIZER_FLAG_TRAINER
                 | RANDOMIZER_FLAG_STARTER
                 | RANDOMIZER_FLAG_EVOLUTION
                 | RANDOMIZER_FLAG_FIELD_ITEM
                 | RANDOMIZER_FLAG_GIFT
                 | RANDOMIZER_FLAG_STATIC
                 | RANDOMIZER_FLAG_STATIC_KEEP_LEGENDS;
    sSetup.seed = ((u32)Random() << 16) | Random();
    if (sSetup.seed == 0)
        sSetup.seed = 1;
}

static void DisableAndContinue(void)
{
    gSaveBlock2Ptr->optionsRandomizerEnabled = FALSE;
    gSaveBlock2Ptr->optionsRandomizerFlags = 0;
    gSaveBlock2Ptr->optionsRandomizerSeed = 0;
    PlaySE(SE_SELECT);
    MainMenu_BeginBirchSpeechScene();
}

static void SaveAndContinue(void)
{
    gSaveBlock2Ptr->optionsRandomizerEnabled = sSetup.enabled;
    gSaveBlock2Ptr->optionsRandomizerFlags = sSetup.flags;
    gSaveBlock2Ptr->optionsRandomizerSeed = (sSetup.seed == 0) ? 1 : sSetup.seed;
    PlaySE(SE_SELECT);
    MainMenu_BeginBirchSpeechScene();
}

static void LoadRandomizerWindowFrameTiles(u8 bgId, u16 tileOffset)
{
    LoadBgTiles(bgId, GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->tiles, 0x120, tileOffset);
    LoadPalette(GetWindowFrameTilesPal(gSaveBlock2Ptr->optionsWindowFrameType)->pal, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
}

static void InitRandomizerTextPalette(void)
{
    u16 palette;

    LoadPalette(sMainMenuTextPal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);

    palette = RGB_WHITE;
    LoadPalette(&palette, BG_PLTT_ID(15) + 10, PLTT_SIZEOF(1));
    palette = RGB(12, 12, 12);
    LoadPalette(&palette, BG_PLTT_ID(15) + 11, PLTT_SIZEOF(1));
    palette = RGB(26, 26, 25);
    LoadPalette(&palette, BG_PLTT_ID(15) + 12, PLTT_SIZEOF(1));

    if (IsFemaleStyle(gSaveBlock2Ptr->playerStyles[0]))
        palette = RGB(31, 3, 21);
    else
        palette = RGB(4, 16, 31);

    LoadPalette(&palette, BG_PLTT_ID(15) + 1, PLTT_SIZEOF(1));
}

static void DrawRandomizerWindowBorder(u8 windowId, u16 baseTileNum)
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
    FillWindowPixelBuffer(windowId, PIXEL_FILL(0xA));
    ClearWindowTilemap(windowId);
    DrawRandomizerWindowBorder(windowId, RANDOMIZER_BORDER_TILE);
}

static void UpdateConfigScroll(u8 taskId)
{
    u8 cursor = gTasks[taskId].data[0];
    u8 scroll = gTasks[taskId].data[4];

    if (cursor < scroll)
        scroll = cursor;
    else if (cursor >= scroll + RANDOMIZER_VISIBLE_OPTION_COUNT)
        scroll = cursor - RANDOMIZER_VISIBLE_OPTION_COUNT + 1;

    gTasks[taskId].data[4] = scroll;
}

static const u8 *GetConfigDescription(u8 cursor)
{
    switch (cursor)
    {
    case 0:
        return sTextMsgWild;
    case 1:
        return sTextMsgTrainer;
    case 2:
        return sTextMsgStarter;
    case 3:
        return sTextMsgEvolution;
    case 4:
        return sTextMsgField;
    case 5:
        return sTextMsgGift;
    case 6:
        return sTextMsgStatic;
    case 7:
        return sTextMsgKeepLegends;
    case CURSOR_SEED:
        return sTextMsgSeed;
    case CURSOR_CONFIRM:
    default:
        return sTextMsgSave;
    }
}

static const u8 *GetSeedDescription(u8 taskId)
{
    return gTasks[taskId].data[3] ? sTextMsgSeedEdit : sTextMsgSeed;
}

static void DrawBottomMessage(const u8 *text)
{
    DrawUserFrame(RANDOMIZER_TEXTBOX_WINDOW_ID);
    AddTextPrinterParameterized3(RANDOMIZER_TEXTBOX_WINDOW_ID, FONT_NORMAL, 0, 1, sTextColorMain, TEXT_SKIP_DRAW, text);
    PutWindowTilemap(RANDOMIZER_TEXTBOX_WINDOW_ID);
    CopyWindowToVram(RANDOMIZER_TEXTBOX_WINDOW_ID, COPYWIN_FULL);
}

static void DrawAskWindow(u8 taskId)
{
    const u8 lineHeight = 16;

    DrawUserFrame(RANDOMIZER_WINDOW_ID);

    AddTextPrinterParameterized3(RANDOMIZER_WINDOW_ID, FONT_NORMAL, 8, 1, sTextColorTitle, TEXT_SKIP_DRAW, sTextTitle);
    AddTextPrinterParameterized3(RANDOMIZER_WINDOW_ID, FONT_NORMAL, 16, 28, sTextColorMain, TEXT_SKIP_DRAW, sTextAskEnable);
    AddTextPrinterParameterized3(RANDOMIZER_WINDOW_ID, FONT_NORMAL, 40, 54, sTextColorMain, TEXT_SKIP_DRAW, sTextYes);
    AddTextPrinterParameterized3(RANDOMIZER_WINDOW_ID, FONT_NORMAL, 40, 54 + lineHeight, sTextColorMain, TEXT_SKIP_DRAW, sTextNo);
    AddTextPrinterParameterized3(RANDOMIZER_WINDOW_ID, FONT_NORMAL, 20, 54 + (gTasks[taskId].data[0] * lineHeight), sTextColorMain, TEXT_SKIP_DRAW, sTextCursor);
    if (gTasks[taskId].data[0] == ASK_CURSOR_YES)
        DrawBottomMessage(sTextMsgAskYes);
    else
        DrawBottomMessage(sTextMsgAskNo);

    PutWindowTilemap(RANDOMIZER_WINDOW_ID);
    CopyWindowToVram(RANDOMIZER_WINDOW_ID, COPYWIN_FULL);
}

static void DrawConfigWindow(u8 taskId)
{
    const u8 lineHeight = 12;
    const u8 firstRowY = 14;
    u8 y = firstRowY;
    u8 i;
    u8 itemId;
    u8 digitText[2] = {EOS, EOS};
    u8 scroll = gTasks[taskId].data[4];

    DrawUserFrame(RANDOMIZER_WINDOW_ID);

    AddTextPrinterParameterized3(RANDOMIZER_WINDOW_ID, FONT_NORMAL, 8, 1, sTextColorTitle, TEXT_SKIP_DRAW, sTextTitle);

    for (i = 0; i < RANDOMIZER_VISIBLE_OPTION_COUNT; i++)
    {
        itemId = scroll + i;
        if (itemId > CURSOR_CONFIRM)
            break;

        if (itemId < TOGGLE_COUNT)
        {
            bool8 enabled = (sSetup.flags & sBits[itemId]) != 0;
            AddTextPrinterParameterized3(RANDOMIZER_WINDOW_ID, FONT_NORMAL, 16, y, sTextColorMain, TEXT_SKIP_DRAW, sLabels[itemId]);
            AddTextPrinterParameterized3(RANDOMIZER_WINDOW_ID, FONT_NORMAL, 152, y, sTextColorMain, TEXT_SKIP_DRAW, enabled ? sTextOn : sTextOff);
        }
        else if (itemId == CURSOR_SEED)
        {
            AddTextPrinterParameterized3(RANDOMIZER_WINDOW_ID, FONT_NORMAL, 16, y, sTextColorMain, TEXT_SKIP_DRAW, sTextSeed);
            for (u8 digit = 0; digit < ARRAY_COUNT(sSeedPlaceValues); digit++)
            {
                u8 digitValue = (sSetup.seed / sSeedPlaceValues[digit]) % 10;
                const u8 *digitColor = (gTasks[taskId].data[0] == CURSOR_SEED && gTasks[taskId].data[3] == TRUE && gTasks[taskId].data[2] == digit)
                                     ? sTextColorCursor
                                     : sTextColorMain;
                digitText[0] = CHAR_0 + digitValue;
                AddTextPrinterParameterized3(RANDOMIZER_WINDOW_ID, FONT_NORMAL, 92 + (digit * 6), y, digitColor, TEXT_SKIP_DRAW, digitText);
            }
        }
        else
        {
            AddTextPrinterParameterized3(RANDOMIZER_WINDOW_ID, FONT_NORMAL, 16, y, sTextColorMain, TEXT_SKIP_DRAW, sTextSave);
        }
        y += lineHeight;
    }
    AddTextPrinterParameterized3(RANDOMIZER_WINDOW_ID, FONT_NORMAL, 2, firstRowY + ((gTasks[taskId].data[0] - scroll) * lineHeight), sTextColorMain, TEXT_SKIP_DRAW, sTextCursor);
    DrawBottomMessage(gTasks[taskId].data[0] == CURSOR_SEED ? GetSeedDescription(taskId) : GetConfigDescription(gTasks[taskId].data[0]));

    PutWindowTilemap(RANDOMIZER_WINDOW_ID);
    CopyWindowToVram(RANDOMIZER_WINDOW_ID, COPYWIN_FULL);
}

static void DrawStartConfirmWindow(u8 taskId)
{
    const u8 lineHeight = 16;

    DrawUserFrame(RANDOMIZER_WINDOW_ID);

    AddTextPrinterParameterized3(RANDOMIZER_WINDOW_ID, FONT_NORMAL, 8, 1, sTextColorTitle, TEXT_SKIP_DRAW, sTextTitle);
    AddTextPrinterParameterized3(RANDOMIZER_WINDOW_ID, FONT_NORMAL, 16, 28, sTextColorMain, TEXT_SKIP_DRAW, sTextStartConfirm);
    AddTextPrinterParameterized3(RANDOMIZER_WINDOW_ID, FONT_NORMAL, 40, 54, sTextColorMain, TEXT_SKIP_DRAW, sTextYes);
    AddTextPrinterParameterized3(RANDOMIZER_WINDOW_ID, FONT_NORMAL, 40, 54 + lineHeight, sTextColorMain, TEXT_SKIP_DRAW, sTextNo);
    AddTextPrinterParameterized3(RANDOMIZER_WINDOW_ID, FONT_NORMAL, 20, 54 + (gTasks[taskId].data[0] * lineHeight), sTextColorMain, TEXT_SKIP_DRAW, sTextCursor);
    if (gTasks[taskId].data[0] == ASK_CURSOR_YES)
        DrawBottomMessage(sTextMsgConfirmYes);
    else
        DrawBottomMessage(sTextMsgConfirmNo);

    PutWindowTilemap(RANDOMIZER_WINDOW_ID);
    CopyWindowToVram(RANDOMIZER_WINDOW_ID, COPYWIN_FULL);
}

static void Task_Randomizer(u8 taskId)
{
    bool8 redraw = FALSE;
    s16 cursor = gTasks[taskId].data[0];

    if (gTasks[taskId].data[1] == SCREEN_ASK)
    {
        if (JOY_NEW(DPAD_UP) || JOY_NEW(DPAD_DOWN))
        {
            cursor ^= 1;
            redraw = TRUE;
        }
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (cursor == ASK_CURSOR_YES)
            {
                InitDefaultConfig();
                gTasks[taskId].data[1] = SCREEN_CONFIG;
                gTasks[taskId].data[0] = 0;
                gTasks[taskId].data[2] = ARRAY_COUNT(sSeedPlaceValues) - 1;
                gTasks[taskId].data[3] = FALSE;
                gTasks[taskId].data[4] = 0;
                DrawConfigWindow(taskId);
            }
            else
            {
                DisableAndContinue();
            }
            return;
        }
        if (JOY_NEW(B_BUTTON))
        {
            DisableAndContinue();
            return;
        }
    }
    else if (gTasks[taskId].data[1] == SCREEN_START_CONFIRM)
    {
        if (JOY_NEW(DPAD_UP) || JOY_NEW(DPAD_DOWN))
        {
            cursor ^= 1;
            redraw = TRUE;
        }
        if (JOY_NEW(A_BUTTON))
        {
            PlaySE(SE_SELECT);
            if (cursor == ASK_CURSOR_YES)
                SaveAndContinue();
            else
            {
                gTasks[taskId].data[1] = SCREEN_CONFIG;
                gTasks[taskId].data[0] = CURSOR_CONFIRM;
                UpdateConfigScroll(taskId);
                DrawConfigWindow(taskId);
            }
            return;
        }
        if (JOY_NEW(B_BUTTON))
        {
            PlaySE(SE_SELECT);
            gTasks[taskId].data[1] = SCREEN_CONFIG;
            gTasks[taskId].data[0] = CURSOR_CONFIRM;
            UpdateConfigScroll(taskId);
            DrawConfigWindow(taskId);
            return;
        }
    }
    else // SCREEN_CONFIG
    {
        if (gTasks[taskId].data[3] == TRUE)
        {
            u8 digitIndex = gTasks[taskId].data[2];

            if (JOY_NEW(DPAD_LEFT))
            {
                if (digitIndex > 0)
                    gTasks[taskId].data[2] = digitIndex - 1;
                redraw = TRUE;
            }
            else if (JOY_NEW(DPAD_RIGHT))
            {
                if (digitIndex < ARRAY_COUNT(sSeedPlaceValues) - 1)
                    gTasks[taskId].data[2] = digitIndex + 1;
                redraw = TRUE;
            }
            else if (JOY_NEW(DPAD_UP))
            {
                ChangeSeedDigit(digitIndex, TRUE);
                redraw = TRUE;
            }
            else if (JOY_NEW(DPAD_DOWN))
            {
                ChangeSeedDigit(digitIndex, FALSE);
                redraw = TRUE;
            }
            else if (JOY_NEW(A_BUTTON) || JOY_NEW(B_BUTTON))
            {
                PlaySE(SE_SELECT);
                gTasks[taskId].data[3] = FALSE;
                redraw = TRUE;
            }
        }
        else
        {
            if (JOY_NEW(DPAD_UP))
            {
                cursor = (cursor == 0) ? CURSOR_CONFIRM : cursor - 1;
                redraw = TRUE;
            }
            else if (JOY_NEW(DPAD_DOWN))
            {
                cursor++;
                if (cursor > CURSOR_CONFIRM)
                    cursor = 0;
                redraw = TRUE;
            }
            else if (JOY_NEW(DPAD_LEFT) || JOY_NEW(DPAD_RIGHT) || JOY_NEW(A_BUTTON))
            {
                if (cursor < TOGGLE_COUNT)
                {
                    if (JOY_NEW(A_BUTTON) || JOY_NEW(DPAD_LEFT) || JOY_NEW(DPAD_RIGHT))
                    {
                        sSetup.flags ^= sBits[cursor];
                        redraw = TRUE;
                    }
                }
                else if (cursor == CURSOR_SEED && JOY_NEW(A_BUTTON))
                {
                    PlaySE(SE_SELECT);
                    gTasks[taskId].data[3] = TRUE;
                    redraw = TRUE;
                }
                else if (cursor == CURSOR_CONFIRM && JOY_NEW(A_BUTTON))
                {
                    PlaySE(SE_SELECT);
                    gTasks[taskId].data[1] = SCREEN_START_CONFIRM;
                    gTasks[taskId].data[0] = ASK_CURSOR_YES;
                    DrawStartConfirmWindow(taskId);
                    return;
                }
            }
            
            if (JOY_NEW(B_BUTTON))
            {
                PlaySE(SE_SELECT);
                gTasks[taskId].data[1] = SCREEN_ASK;
                gTasks[taskId].data[0] = ASK_CURSOR_YES;
                DrawAskWindow(taskId);
                return;
            }
        }
    }

    if (cursor != gTasks[taskId].data[0])
    {
        gTasks[taskId].data[0] = cursor;
        if (gTasks[taskId].data[1] == SCREEN_CONFIG)
            UpdateConfigScroll(taskId);
        redraw = TRUE;
    }

    if (redraw)
    {
        if (gTasks[taskId].data[1] == SCREEN_ASK)
            DrawAskWindow(taskId);
        else if (gTasks[taskId].data[1] == SCREEN_START_CONFIRM)
            DrawStartConfirmWindow(taskId);
        else
            DrawConfigWindow(taskId);
    }
}

void CB2_InitNewGameRandomizer(void)
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
    InitBgsFromTemplates(0, sBgTemplates, ARRAY_COUNT(sBgTemplates));
    InitWindows(sWindowTemplates);
    DeactivateAllTextPrinters();
    InitRandomizerTextPalette();
    LoadRandomizerWindowFrameTiles(0, RANDOMIZER_BORDER_TILE);

    SetGpuReg(REG_OFFSET_WIN0H, 0);
    SetGpuReg(REG_OFFSET_WIN0V, 0);
    SetGpuReg(REG_OFFSET_WININ, 0);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);

    taskId = CreateTask(Task_Randomizer, 0);
    gTasks[taskId].data[0] = ASK_CURSOR_YES;
    gTasks[taskId].data[1] = SCREEN_ASK;
    gTasks[taskId].data[2] = ARRAY_COUNT(sSeedPlaceValues) - 1;
    gTasks[taskId].data[3] = FALSE;
    gTasks[taskId].data[4] = 0;
    
    DrawAskWindow(taskId);

    EnableInterrupts(1);
    SetVBlankCallback(VBlankCB_Randomizer);
    SetMainCallback2(CB2_Randomizer);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_BG0_ON | DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
}
