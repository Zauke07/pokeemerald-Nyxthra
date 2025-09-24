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

#include "rtc.h"
#include "test_labor.h"
#include "text.h"
#include "field_message_box.h"



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
#define tStyleSelectId     data[18]


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
#undef tStyleSelectId

static const u8 sMorning[] = _("morgens");
static const u8 sDay[]     = _("tagsüber");
static const u8 sEvening[] = _("abends");
static const u8 sNight[]   = _("nachts");

// Füllt STR_VAR_1 = HH, STR_VAR_2 = MM, STR_VAR_3 = Tageszeit (DE)
void BufferClockToStrVars123(void)
{
    RtcCalcLocalTime(); // aktualisiert gLocalTime

    ConvertIntToDecimalStringN(gStringVar1, gLocalTime.hours,   STR_CONV_MODE_LEADING_ZEROS, 2);
    ConvertIntToDecimalStringN(gStringVar2, gLocalTime.minutes, STR_CONV_MODE_LEADING_ZEROS, 2);

    // Nimm, wenn vorhanden, deine interne Tageszeit-Funktion:
    #ifdef GUARD_TIMEOFDAY_H
    switch (GetTimeOfDay())
    {
        case TIME_MORNING: StringCopy(gStringVar3, sMorning); break;
        case TIME_DAY:     StringCopy(gStringVar3, sDay);     break;
        case TIME_EVENING: StringCopy(gStringVar3, sEvening); break;
        case TIME_NIGHT:   StringCopy(gStringVar3, sNight);   break;
        default:           StringCopy(gStringVar3, sDay);     break;
    }
    #else
    // Fallback nach Stunden
    if      (gLocalTime.hours < 6)  StringCopy(gStringVar3, sNight);
    else if (gLocalTime.hours < 12) StringCopy(gStringVar3, sMorning);
    else if (gLocalTime.hours < 18) StringCopy(gStringVar3, sDay);
    else if (gLocalTime.hours < 22) StringCopy(gStringVar3, sEvening);
    else                            StringCopy(gStringVar3, sNight);
    #endif
}

static const u8 gText_NpcDebugLevelExp[] = _("Level: {STR_VAR_1}\nEXP: {STR_VAR_2}\nMappedLvl: {STR_VAR_3}$");

void BufferNpcExpLevelDebug(struct Pokemon *mon)
{
    u8 actualLevel = GetMonData(mon, MON_DATA_LEVEL, NULL);
    u32 exp = GetMonData(mon, MON_DATA_EXP, NULL);
    u8 mappedLevel = GetLevelFromMonExp(mon);

    ConvertIntToDecimalStringN(gStringVar1, actualLevel, STR_CONV_MODE_LEADING_ZEROS, 3);
    ConvertIntToDecimalStringN(gStringVar2, exp, STR_CONV_MODE_LEADING_ZEROS, 7);
    ConvertIntToDecimalStringN(gStringVar3, mappedLevel, STR_CONV_MODE_LEADING_ZEROS, 3);
}

bool8 ShowNpcExpLevelDebugMessage(void)
{
    StringExpandPlaceholders(gStringVar4, gText_NpcDebugLevelExp);
    ShowFieldMessage(gStringVar4);
    return FALSE;
}

void BufferDebugExpLevelVars(struct Pokemon *mon)
{
    u8 actualLevel = GetMonData(mon, MON_DATA_LEVEL, NULL);
    u32 exp = GetMonData(mon, MON_DATA_EXP, NULL);
    u8 mappedLevel = GetLevelFromMonExp(mon);

    ConvertIntToDecimalStringN(gStringVar1, actualLevel, STR_CONV_MODE_LEADING_ZEROS, 3);
    ConvertIntToDecimalStringN(gStringVar2, exp, STR_CONV_MODE_LEADING_ZEROS, 7);
    ConvertIntToDecimalStringN(gStringVar3, mappedLevel, STR_CONV_MODE_LEADING_ZEROS, 3);
}

