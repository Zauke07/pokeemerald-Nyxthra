#ifndef GUARD_CHALLENGE_MODE_H
#define GUARD_CHALLENGE_MODE_H

#include "global.h"

#define CHALLENGE_MODE_FLAG_DOOR_WARP_RANDOM (1 << 0)

u16 IsDoorWarpRandomizerActiveSpecial(void);
void ChallengeMode_DisableDoorWarpRandom(void);
void ChallengeMode_EnableDoorWarpRandom(void);
bool8 ChallengeMode_GetWarpDestinationOverride(u8 sourceMapGroup, u8 sourceMapNum, u8 sourceWarpId,
                                               u8 *destMapGroup, u8 *destMapNum, u8 *destWarpId);

#endif // GUARD_CHALLENGE_MODE_H
