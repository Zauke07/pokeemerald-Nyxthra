#ifndef GUARD_NYXTHRA_FLASHBACK_INTERNAL_H
#define GUARD_NYXTHRA_FLASHBACK_INTERNAL_H

#include "global.h"
#include "constants/nyxthra_flashback.h"

struct FlashbackClipDesc
{
    u32 map;
    u8 x;
    u8 y;
    const u8 *script;
    bool8 hasBattle;
    u16 startPlayerMove;
    u16 startOppMove;
    u16 finishPlayerMove;
    u16 finishOppMove;
};

const struct FlashbackClipDesc *Flashback_GetClipDesc(u8 clip);
void Flashback_GiveClipPlayerParty(u8 clip);
void Flashback_GiveClipOpponentParty(u8 clip);
void Flashback_GiveMoves(struct Pokemon *mon, u16 m0, u16 m1, u16 m2, u16 m3);

#endif
