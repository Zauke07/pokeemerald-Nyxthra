#ifndef GUARD_CONSTANTS_REGIONS_H
#define GUARD_CONSTANTS_REGIONS_H

// Core-series regions
enum Region
{
    REGION_NONE,
    REGION_KANTO,
    REGION_JOHTO,
    REGION_HOENN,
    REGION_SINNOH,
    REGION_UNOVA,
    REGION_KALOS,
    REGION_ALOLA,
    REGION_GALAR,
    REGION_HISUI,
    REGION_PALDEA,
    REGIONS_COUNT,
};

// Starter region IDs (used for starter selection)
// NOTE: These IDs are intentionally 0-based for script switch compatibility.
#define STARTER_REGION_KANTO   0
#define STARTER_REGION_JOHTO   1
#define STARTER_REGION_HOENN   2
#define STARTER_REGION_SINNOH  3
#define STARTER_REGION_UNOVA   4
#define STARTER_REGION_KALOS   5
#define STARTER_REGION_ALOLA   6
#define STARTER_REGION_GALAR   7
#define STARTER_REGION_PALDEA  8
#define STARTER_REGIONS_COUNT  9

#endif  // GUARD_CONSTANTS_REGIONS_H
