#ifndef GUARD_MAIN_MENU_H
#define GUARD_MAIN_MENU_H

void CB2_InitMainMenu(void);
void CreateYesNoMenuParameterized(u8 x, u8 y, u16 baseTileNum, u16 baseBlock, u8 yesNoPalNum, u8 winPalNum);
void NewGameBirchSpeech_SetDefaultPlayerName(u8);
void Task_NewGameBirchSpeech_WhatsYourName(u8 taskId);
void AddBirchSpeechObjects(u8 taskId);
u16 PlayerStyleToFacilityClass(u8 style);
extern const u8 *const sMalePresetNames[];
extern const u8 *const sFemalePresetNames[];
void CreateTrainerSprites(u8, bool8);
void FreeTrainerSprites(u8);


#endif // GUARD_MAIN_MENU_H
