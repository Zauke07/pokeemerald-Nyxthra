#ifndef GUARD_OPTION_MENU_H
#define GUARD_OPTION_MENU_H

#include "gba/m4a_internal.h"

#define ROGUE_SOUND_TYPE_UNKNOWN 0
#define ROGUE_SOUND_TYPE_CRY 1

void CB2_InitOptionMenu(void);
bool8 Rogue_GetBattleAnimsEnabled(void);
//bool8 RogueToD_ApplyTimeVisuals();
u8 Rogue_ModifySoundVolume(struct MusicPlayerInfo *mplayInfo, u8 volume, u16 soundType);
//void Rogue_OverworldCB(u16 newKeys, u16 heldKeys, bool8 inputActive);
bool8 Rogue_ShouldForceNicknameScreen();
bool8 Rogue_ShouldSkipAssignNickname(struct Pokemon* mon);
bool8 Rogue_ShouldSkipAssignNicknameYesNoMessage();
u8 Rogue_GetBattleSpeedScale(bool8 forHealthbar);
void Rogue_SetDefaultOptions(void);
u32 RogueGift_GetCustomMonId(struct Pokemon* mon);
u32 RogueGift_GetCustomBoxMonId(struct BoxPokemon* mon);
u32 RogueGift_GetCustomMonIdBySpecies(u16 species, u32 otId);
bool8 Rogue_IsRunningToggledOn();
u16 GetCurrentNicknameMode(void);
bool8 Rogue_UseKeyBattleAnims(void);
bool8 RogueGift_CanRenameCustomMon(u32 id);
bool8 Rogue_CanRenameMon(struct Pokemon* mon);
void Rogue_AssistantOverworldCB();


#endif // GUARD_OPTION_MENU_H
