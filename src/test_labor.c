#include "global.h"
#include "script.h"
#include "fieldmap.h"
#include "event_data.h"
#include "task.h"
#include "main.h"
#include "new_game.h"
#include "field_player_avatar.h"
#include "overworld.h"
#include "string_util.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "palette.h"
#include "field_specials.h"
#include "menu.h"
#include "trainer_pokemon_sprites.h"
#include "constants/maps.h"
#include "constants/characters.h"
#include "constants/songs.h"
#include "strings.h"
#include "random.h"
#include "naming_screen.h"
#include "field_screen_effect.h"
#include "list_menu.h"
#include "sound.h"
#include "constants/flags.h"
#include "main_menu.h"



static void CB2_TestlabSpeech_Init(void);
static void Task_TestlabSpeech_Begin(u8 taskId);
extern void NewGameBirchSpeech_SetDefaultPlayerName(u8 option);
extern void CreateTrainerSprites(u8 taskId, bool8 alreadyExists);
extern void FreeTrainerSprites(u8 taskId);
extern void LoadTrainerSprAndPalFromStyle(u8 style, u16 *gfxTag, u16 *palTag);
static void Task_TestlabSpeech_ChooseGender(u8 taskId);
static void Task_TestlabSpeech_WhatsYourName(u8 taskId);
static void CB2_TestlabSpeech_ReturnFromNamingScreen(void);

static u8 sTestSpeechTaskId;
static u8 sStyleMenuTaskId;

#define STYLE_MENU_WINDOW_ID 1

#define NUM_PRESET_NAMES 20


#define tPlayerSpriteId    data[2]
#define tBG1HOFS           data[4]
#define tIsDoneFadingSprites data[5]
#define tPlayerGender      data[6]
#define tTimer             data[7]
#define tBirchSpriteId     data[8]
#define tLotadSpriteId     data[9]
#define tBrendanSpriteId   data[10]
#define tMaySpriteId       data[11]
#define tRedSpriteId       data[12]
#define tLeafSpriteId      data[13]
#define tEthanSpriteId data[14]
#define tLyraSpriteId data[15]
#define tLucasSpriteId data[16]
#define tDawnSpriteId data[17]
#define tHilbertSpriteId data[18]
#define tHildaSpriteId data[19]
#define tNateSpriteId data[20]
#define tRosaSpriteId data[21]
#define tCalemSpriteId data[22]
#define tSerenaSpriteId data[23]
#define tElioSpriteId data[24]
#define tSeleneSpriteId data[25]
#define tVictorSpriteId data[26]
#define tGloriaSpriteId data[27]
#define tFlorianSpriteId data[28]
#define tJulianaSpriteId data[29]
#define tStyleSelectId     data[30]


bool8 WarpToTestlaborAfterStyleSelect(struct ScriptContext *ctx)
{
    SetWarpDestination(MAP_GROUP(MAP_TESTLABOR), MAP_NUM(MAP_TESTLABOR), -1, 7, 4);
    ScriptContext_Stop();
    WarpIntoMap();
    return TRUE;
}

bool8 StartTestlaborStyleSelection(struct ScriptContext *ctx)
{
    SetWarpDestination(MAP_GROUP(MAPSEC_LITTLEROOT_TOWN), MAP_NUM(MAPSEC_LITTLEROOT_TOWN), -1, 7, 4);
    VarSet(VAR_LITTLEROOT_INTRO_STATE, 99); // >> Eigener Zustand für Testlabor
    ScriptContext_Stop();
    WarpIntoMap();
    return TRUE;
}

// === Fenster & Menüstruktur ===

extern const struct ListMenuTemplate sBirchStyleListTemplate;
extern const struct {
    const u8 *text;
    u8 id;
} sBirchStyleList[];

// === Entry Point ===

bool8 StartCharacterStyleSelection(struct ScriptContext *ctx)
{
    ScriptContext_Stop();
    CleanupOverworldWindowsAndTilemaps();
    ResetTasks();
    ResetSpriteData();
    ResetPaletteFade();
    SetVBlankCallback(NULL);
    SetMainCallback2(CB2_TestlabSpeech_Init);
    return TRUE;
}

static void CB2_TestlabSpeech_Init(void)
{
    InitOverworldGraphicsRegisters();
    ResetTasks();
    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetAllPicSprites();
    LoadMessageBoxAndFrameGfx(0, TRUE);
    sTestSpeechTaskId = CreateTask(Task_TestlabSpeech_Begin, 0);
}

static void Task_TestlabSpeech_Begin(u8 taskId)
{
    // Init Auswahl
    DrawStdFrameWithCustomTileAndPalette(0, TRUE, 0xF3, 14);
    PutWindowTilemap(0);
    CopyWindowToVram(0, COPYWIN_FULL);
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_Birch_BoyOrGirl, 0, 1, 0, NULL);

    gTasks[taskId].tStyleSelectId = STYLE_BRENDAN;
    CreateTrainerSprites(taskId, FALSE);
    gTasks[taskId].func = Task_TestlabSpeech_ChooseGender;
}

static void Task_TestlabSpeech_ChooseGender(u8 taskId)
{
    s32 input = ListMenu_ProcessInput(sStyleMenuTaskId);

    if (input == LIST_CANCEL)
    {
        PlaySE(SE_BOO);
        return;
    }

    if (input >= 0)
    {
        PlaySE(SE_SELECT);
        u8 selectedStyle = sBirchStyleList[input].id;
        gTasks[taskId].tStyleSelectId = selectedStyle;
        gSaveBlock2Ptr->playerStyles[0] = selectedStyle;
        gSaveBlock2Ptr->playerGender = IsPlayerStyleMale(selectedStyle) ? MALE : FEMALE;

        ClearWindowTilemap(STYLE_MENU_WINDOW_ID);
        RemoveWindow(STYLE_MENU_WINDOW_ID);
        DestroyTask(sStyleMenuTaskId);
        FreeTrainerSprites(taskId);

        gTasks[taskId].func = Task_TestlabSpeech_WhatsYourName;
    }
}

static void Task_TestlabSpeech_WhatsYourName(u8 taskId)
{
    NewGameBirchSpeech_SetDefaultPlayerName(Random() % NUM_PRESET_NAMES);
    DoNamingScreen(NAMING_SCREEN_PLAYER, gSaveBlock2Ptr->playerName, gSaveBlock2Ptr->playerStyles[0], 0, 0, CB2_TestlabSpeech_ReturnFromNamingScreen);
}

static void CB2_TestlabSpeech_ReturnFromNamingScreen(void)
{
    SetWarpDestination(MAP_GROUP(MAP_TESTLABOR), MAP_NUM(MAP_TESTLABOR), -1, 7, 4);
    SetWarpDestinationToMapWarp(MAP_GROUP(MAP_TESTLABOR), MAP_NUM(MAP_TESTLABOR), 0);
    WarpIntoMap();
    SetMainCallback2(CB2_ReturnToField);
}

bool8 ScrCmd_BufferStyleNameToStringVar1(struct ScriptContext *ctx)
{
    u8 style = VarGet(VAR_RESULT);

    switch (style)
    {
    case STYLE_BRENDAN:  StringCopy(gStringVar1, gText_TrainerName_Brendan); break;
    case STYLE_MAY:      StringCopy(gStringVar1, gText_TrainerName_May); break;
    case STYLE_RED:      StringCopy(gStringVar1, gText_TrainerName_Red); break;
    case STYLE_LEAF:     StringCopy(gStringVar1, gText_TrainerName_Leaf); break;
    case STYLE_ETHAN:    StringCopy(gStringVar1, gText_TrainerName_Ethan); break;
    case STYLE_LYRA:     StringCopy(gStringVar1, gText_TrainerName_Lyra); break;
    case STYLE_LUCAS:    StringCopy(gStringVar1, gText_TrainerName_Lucas); break;
    case STYLE_DAWN:     StringCopy(gStringVar1, gText_TrainerName_Dawn); break;
    case STYLE_HILBERT:  StringCopy(gStringVar1, gText_TrainerName_Hilbert); break;
    case STYLE_HILDA:    StringCopy(gStringVar1, gText_TrainerName_Hilda); break;
    case STYLE_NATE:     StringCopy(gStringVar1, gText_TrainerName_Nate); break;
    case STYLE_ROSA:     StringCopy(gStringVar1, gText_TrainerName_Rosa); break;
    case STYLE_CALEM:    StringCopy(gStringVar1, gText_TrainerName_Calem); break;
    case STYLE_SERENA:   StringCopy(gStringVar1, gText_TrainerName_Serena); break;
    case STYLE_ELIO:     StringCopy(gStringVar1, gText_TrainerName_Elio); break;
    case STYLE_SELENE:   StringCopy(gStringVar1, gText_TrainerName_Selene); break;
    case STYLE_VICTOR:   StringCopy(gStringVar1, gText_TrainerName_Victor); break;
    case STYLE_GLORIA:   StringCopy(gStringVar1, gText_TrainerName_Gloria); break;
    case STYLE_FLORIAN:  StringCopy(gStringVar1, gText_TrainerName_Florian); break;
    case STYLE_JULIANA:  StringCopy(gStringVar1, gText_TrainerName_Juliana); break;
    default:             StringCopy(gStringVar1, gText_QuestionMark); break;
    }

    return FALSE;
}

#undef tPlayerSpriteId
#undef tBG1HOFS
#undef tIsDoneFadingSprites
#undef tBirchSpriteId
#undef tLotadSpriteId
#undef tBrendanSpriteId
#undef tMaySpriteId
#undef tRedSpriteId
#undef tLeafSpriteId
#undef tEthanSpriteId
#undef tLyraSpriteId
#undef tLucasSpriteId
#undef tDawnSpriteId
#undef tHilbertSpriteId
#undef tHildaSpriteId
#undef tNateSpriteId
#undef tRosaSpriteId
#undef tCalemSpriteId
#undef tSerenaSpriteId
#undef tElioSpriteId
#undef tSeleneSpriteId
#undef tVictorSpriteId
#undef tGloriaSpriteId
#undef tFlorianSpriteId
#undef tJulianaSpriteId
#undef tStyleSelectId

