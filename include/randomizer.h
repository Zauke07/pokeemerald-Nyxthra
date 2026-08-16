#ifndef GUARD_RANDOMIZER_H
#define GUARD_RANDOMIZER_H

#include "global.h"

enum RandomizerMode
{
    RANDOMIZER_MODE_WILD,
    RANDOMIZER_MODE_TRAINER,
    RANDOMIZER_MODE_STARTER,
    RANDOMIZER_MODE_EVOLUTION,
    RANDOMIZER_MODE_FIELD_ITEM,
    RANDOMIZER_MODE_GIFT,
    RANDOMIZER_MODE_STATIC,
    RANDOMIZER_MODE_TMHM,
};

enum
{
    RANDOMIZER_FLAG_WILD      = (1 << 0),
    RANDOMIZER_FLAG_TRAINER   = (1 << 1),
    RANDOMIZER_FLAG_STARTER   = (1 << 2),
    RANDOMIZER_FLAG_EVOLUTION = (1 << 3),
    RANDOMIZER_FLAG_FIELD_ITEM = (1 << 4),
    RANDOMIZER_FLAG_GIFT      = (1 << 5),
    RANDOMIZER_FLAG_STATIC    = (1 << 6),
    RANDOMIZER_FLAG_STATIC_KEEP_LEGENDS = (1 << 7),
};

u16 Randomizer_GetSpecies(u16 originalSpecies, enum RandomizerMode mode);
u16 Randomizer_GetItem(u16 originalItem, enum RandomizerMode mode);
u16 Randomizer_GetMove(u16 originalMove, enum RandomizerMode mode);
u16 Randomizer_GetStaticSpecies(u16 originalSpecies);

#endif // GUARD_RANDOMIZER_H
