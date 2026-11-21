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

#endif // GUARD_NYXTHRA_FLASHBACK_H
