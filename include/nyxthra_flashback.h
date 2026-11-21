#ifndef GUARD_NYXTHRA_FLASHBACK_H
#define GUARD_NYXTHRA_FLASHBACK_H

// Traum-Rückblick 2005: echte In-Game-Clips nach dem Randomizer
// und vor Prof. Birks Ansprache. Start überspringt alles.
// Der Spielstand des neuen Spiels bleibt danach unberührt.

void CB2_StartNyxthraFlashback(void);
bool8 NyxthraFlashback_IsActive(void);
void NyxthraFlashback_Finish(void);
void NyxthraFlashback_ProcessInput(void);
void NyxthraFlashback_OnOverworldTick(void);
void NyxthraFlashback_ApplyDreamTint(void);
bool8 NyxthraFlashback_ShouldKeepScreenBlack(void);
void NyxthraFlashback_ClearKeepScreenBlack(void);

// Wiederverwendbarer Autokampf für die Rückblick-Clips (Arena, Liga, Bosse).
void NyxthraFlashback_PrepareScriptedBattle(void);
void NyxthraFlashback_PrepareScriptedBattleFinish(void);
bool8 NyxthraFlashback_PreventFaint(void);
void NyxthraFlashback_ClampMoveDamage(u32 battler);
void NyxthraFlashback_OnTrainerPartyCreated(void);
void NyxthraFlashback_OnBattleEnded(void);
bool8 NyxthraFlashback_IsScriptedBattle(void);
u16 NyxthraFlashback_GetPlayerMove(void);
u16 NyxthraFlashback_GetOpponentMove(void);
bool8 NyxthraFlashback_OpponentShouldMove(void);
bool8 NyxthraFlashback_ShouldAbortBattle(void);
bool8 NyxthraFlashback_TickAutoInput(u8 delay);
void NyxthraFlashback_BeginAbortBattle(void);
void NyxthraFlashback_BeginTimeSkip(void);
bool8 NyxthraFlashback_IsTimeSkipping(void);
void NyxthraFlashback_NotePlayerActionMenu(void);
void NyxthraFlashback_ProcessBattleInput(void);

#endif // GUARD_NYXTHRA_FLASHBACK_H
