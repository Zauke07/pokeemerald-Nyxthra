#include "global.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "pokemon.h"
#include "randomizer.h"

#define RANDOMIZER_ALL_FLAGS (RANDOMIZER_FLAG_WILD \
                           | RANDOMIZER_FLAG_TRAINER \
                           | RANDOMIZER_FLAG_STARTER \
                           | RANDOMIZER_FLAG_EVOLUTION \
                           | RANDOMIZER_FLAG_FIELD_ITEM \
                           | RANDOMIZER_FLAG_GIFT \
                           | RANDOMIZER_FLAG_STATIC \
                           | RANDOMIZER_FLAG_STATIC_KEEP_LEGENDS)

static u32 MixHash32(u32 value)
{
    value ^= value >> 16;
    value *= 0x7FEB352D;
    value ^= value >> 15;
    value *= 0x846CA68B;
    value ^= value >> 16;
    return value;
}

static bool32 IsModeEnabled(enum RandomizerMode mode)
{
    u8 modeFlag = 0;
    u8 enabled;
    u8 flags;

    if (gSaveBlock2Ptr == NULL)
        return FALSE;

    enabled = gSaveBlock2Ptr->optionsRandomizerEnabled;
    flags = gSaveBlock2Ptr->optionsRandomizerFlags;

    // Only accept explicit valid state to avoid accidental randomization from stale/corrupt save bytes.
    if (enabled != TRUE)
        return FALSE;

    if ((flags & ~RANDOMIZER_ALL_FLAGS) != 0)
        return FALSE;

    if (flags == 0 || gSaveBlock2Ptr->optionsRandomizerSeed == 0)
        return FALSE;

    switch (mode)
    {
    case RANDOMIZER_MODE_WILD:
        modeFlag = RANDOMIZER_FLAG_WILD;
        break;
    case RANDOMIZER_MODE_TRAINER:
        modeFlag = RANDOMIZER_FLAG_TRAINER;
        break;
    case RANDOMIZER_MODE_STARTER:
        modeFlag = RANDOMIZER_FLAG_STARTER;
        break;
    case RANDOMIZER_MODE_EVOLUTION:
        modeFlag = RANDOMIZER_FLAG_EVOLUTION;
        break;
    case RANDOMIZER_MODE_FIELD_ITEM:
        modeFlag = RANDOMIZER_FLAG_FIELD_ITEM;
        break;
    case RANDOMIZER_MODE_GIFT:
        modeFlag = RANDOMIZER_FLAG_GIFT;
        break;
    case RANDOMIZER_MODE_STATIC:
        modeFlag = RANDOMIZER_FLAG_STATIC;
        break;
    case RANDOMIZER_MODE_TMHM:
        modeFlag = RANDOMIZER_FLAG_FIELD_ITEM;
        break;
    default:
        return FALSE;
    }

    return (flags & modeFlag) != 0;
}

u16 Randomizer_GetSpecies(u16 originalSpecies, enum RandomizerMode mode)
{
    u16 species;
    u32 hash;

    if (!IsModeEnabled(mode))
        return originalSpecies;

    species = SanitizeSpeciesId(originalSpecies);
    if (species == SPECIES_NONE || species == SPECIES_EGG)
        return originalSpecies;

    hash = gSaveBlock2Ptr->optionsRandomizerSeed;
    hash ^= (u32)(mode + 1) * 0x9E3779B9;
    hash ^= (u32)species * 0x85EBCA6B;
    hash = MixHash32(hash);

    species = (hash % (NUM_SPECIES - 1)) + 1;
    while (!IsSpeciesEnabled(species) || species == SPECIES_EGG)
    {
        species++;
        if (species >= NUM_SPECIES)
            species = SPECIES_NONE + 1;
    }

    return species;
}

u16 Randomizer_GetItem(u16 originalItem, enum RandomizerMode mode)
{
    u16 item;
    u32 hash;

    if (!IsModeEnabled(mode))
        return originalItem;

    item = originalItem;
    if (item == ITEM_NONE || item >= ITEMS_COUNT)
        return originalItem;

    hash = gSaveBlock2Ptr->optionsRandomizerSeed;
    hash ^= (u32)(mode + 1) * 0x9E3779B9;
    hash ^= (u32)item * 0x85EBCA6B;
    hash = MixHash32(hash);

    item = (hash % (ITEMS_COUNT - 1)) + 1;
    return item;
}

u16 Randomizer_GetMove(u16 originalMove, enum RandomizerMode mode)
{
    u16 move;
    u32 hash;

    if (!IsModeEnabled(mode))
        return originalMove;

    move = originalMove;
    if (move == MOVE_NONE || move >= MOVES_COUNT)
        return originalMove;

    hash = gSaveBlock2Ptr->optionsRandomizerSeed;
    hash ^= (u32)(mode + 1) * 0x9E3779B9;
    hash ^= (u32)move * 0x85EBCA6B;
    hash = MixHash32(hash);

    move = (hash % (MOVES_COUNT - 1)) + 1;
    if (move == MOVE_STRUGGLE)
        move = MOVE_POUND;

    return move;
}

static bool32 IsLegendaryOrMythicalSpecies(u16 species)
{
    const struct SpeciesInfo *speciesInfo;

    species = SanitizeSpeciesId(species);
    if (species == SPECIES_NONE || species == SPECIES_EGG)
        return FALSE;

    speciesInfo = &gSpeciesInfo[species];
    return speciesInfo->isRestrictedLegendary || speciesInfo->isSubLegendary || speciesInfo->isMythical;
}

u16 Randomizer_GetStaticSpecies(u16 originalSpecies)
{
    if ((gSaveBlock2Ptr->optionsRandomizerFlags & RANDOMIZER_FLAG_STATIC_KEEP_LEGENDS)
        && IsLegendaryOrMythicalSpecies(originalSpecies))
    {
        return originalSpecies;
    }

    return Randomizer_GetSpecies(originalSpecies, RANDOMIZER_MODE_STATIC);
}
