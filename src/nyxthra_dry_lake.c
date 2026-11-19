#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "fieldmap.h"
#include "nyxthra_dry_lake.h"
#include "constants/flags.h"

struct Route104DryLakeTile
{
    u8 x;
    u8 y;
    u16 mapEntry; // full packed grid entry: metatile ID + collision + elevation
};

// Nyxthra story: once Groudon has awakened (the same flag vanilla Emerald
// sets when the region-wide drought begins), the lake on Route 104 next to
// the Pretty Petal Flower Shop dries up permanently, replaced by the rocky/
// boulder quarry bed built for this hack. The map's saved layout (map.bin)
// keeps the real lake as its persistent default - so it looks right even
// before this feature ever runs (e.g. viewed in Porymap, or a save from
// before Groudon awakens) - and this table is applied on top of that
// default at runtime, once the flag is set. Entries are full grid values
// (metatile ID + collision + elevation), since MapGridSetMetatileIdAt()
// would keep the lake's old elevation and break walking.
//
// The dried-up bed has wooden walkways crossing over it, which work like
// Route 110's cycling bridge: you can walk ON them from the surrounding land,
// or walk UNDER them on the pit floor, but never step between the two.
//  - Pit floor: elevation 1 (draw priority 2 -> below the top BG layer),
//    and != the land's elevation 3, so the floor's edge toward land blocks.
//  - Walkway tiles (892-895): copies of 854/855/814/822 with layer type
//    SPLIT instead of COVERED, so the planks sit on the top BG layer and
//    cover a player walking underneath. The originals stay COVERED because
//    the lake-state bridge further south (x22-23 y49-54) still uses them as
//    a normal walk-on bridge. Elevation 15 (multi-level), so whoever is on
//    them keeps the elevation they arrived with.
//  - Walkway ends touching land: elevation 4 (draw priority 1 -> above the
//    planks), with the land tile in front of each end set to elevation 0
//    (transition), so a player coming from land is promoted to 4 and stays
//    on top for the whole crossing. The two southern walkways end on the
//    first grass row (y22) instead of inside the pit, so the pit's last
//    row (y21) stays passable underneath them.
//  - The Gina/Mia twins stand on the walkway; they're hidden via their
//    object flag (FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT) in map.json.
// Coordinates are local to Route104's layout (add MAP_OFFSET). The small
// round puddles further north (near the sign/bridge area) are unrelated
// decoration, not part of the main lake, and are intentionally left out of
// this table so they never change.
static const struct Route104DryLakeTile sRoute104DryLakeTiles[] =
{
    {20, 9, 1140}, {21, 9, 1148}, {22, 9, 1148}, {23, 9, 1148},
    {24, 9, 17276}, {25, 9, 17277}, {26, 9, 1148}, {27, 9, 1148},
    {28, 9, 1148}, {29, 9, 1148}, {30, 9, 1148}, {31, 9, 207},
    {32, 9, 1148}, {33, 9, 1148}, {34, 9, 17276}, {35, 9, 17277},
    {36, 9, 1148}, {37, 9, 1161}, {20, 10, 1141}, {21, 10, 4209},
    {22, 10, 4209}, {23, 10, 4209}, {24, 10, 62332}, {25, 10, 62333},
    {26, 10, 4209}, {27, 10, 4209}, {28, 10, 4209}, {29, 10, 4209},
    {30, 10, 4209}, {31, 10, 4209}, {32, 10, 4209}, {33, 10, 4209},
    {34, 10, 62332}, {35, 10, 62333}, {36, 10, 4209}, {37, 10, 1139},
    {20, 11, 1141}, {21, 11, 4209}, {22, 11, 4209}, {23, 11, 4209},
    {24, 11, 62332}, {25, 11, 62333}, {26, 11, 4209}, {27, 11, 1171},
    {28, 11, 1172}, {29, 11, 4209}, {30, 11, 4209}, {31, 11, 4209},
    {32, 11, 4209}, {33, 11, 4209}, {34, 11, 62332}, {35, 11, 62333},
    {36, 11, 4209}, {37, 11, 1139}, {13, 12, 1140}, {14, 12, 207},
    {15, 12, 1148}, {16, 12, 17276}, {17, 12, 17277}, {18, 12, 1148},
    {19, 12, 1148}, {20, 12, 1149}, {21, 12, 4209}, {22, 12, 4209},
    {23, 12, 4209}, {24, 12, 62332}, {25, 12, 62333}, {26, 12, 4209},
    {27, 12, 1179}, {28, 12, 1180}, {29, 12, 4209}, {30, 12, 4209},
    {31, 12, 4209}, {32, 12, 4209}, {33, 12, 4209}, {34, 12, 62332},
    {35, 12, 62333}, {36, 12, 4209}, {37, 12, 1139}, {13, 13, 1141},
    {14, 13, 4209}, {15, 13, 4209}, {16, 13, 62332}, {17, 13, 62333},
    {18, 13, 4209}, {19, 13, 4209}, {20, 13, 4209}, {21, 13, 4209},
    {22, 13, 1249}, {23, 13, 4209}, {24, 13, 62332}, {25, 13, 62333},
    {26, 13, 4209}, {27, 13, 4209}, {28, 13, 4209}, {29, 13, 4209},
    {30, 13, 4209}, {31, 13, 4209}, {32, 13, 4209}, {33, 13, 4209},
    {34, 13, 62332}, {35, 13, 62333}, {36, 13, 1249}, {37, 13, 1139},
    {13, 14, 1141}, {14, 14, 4209}, {15, 14, 4209}, {16, 14, 62332},
    {17, 14, 62333}, {18, 14, 4209}, {19, 14, 4209}, {20, 14, 4209},
    {21, 14, 4209}, {22, 14, 4209}, {23, 14, 4209}, {24, 14, 62332},
    {25, 14, 62333}, {26, 14, 4209}, {27, 14, 4209}, {28, 14, 4209},
    {29, 14, 4209}, {30, 14, 4209}, {31, 14, 4209}, {32, 14, 4209},
    {33, 14, 4209}, {34, 14, 62332}, {35, 14, 62333}, {36, 14, 4209},
    {37, 14, 1139}, {13, 15, 1141}, {14, 15, 4209}, {15, 15, 4209},
    {16, 15, 62332}, {17, 15, 62333}, {18, 15, 4209}, {19, 15, 4209},
    {20, 15, 4209}, {21, 15, 4209}, {22, 15, 4209}, {23, 15, 4209},
    {24, 15, 62332}, {25, 15, 62333}, {26, 15, 62334}, {27, 15, 62334},
    {28, 15, 62334}, {29, 15, 62334}, {30, 15, 62334}, {31, 15, 62334},
    {32, 15, 62334}, {33, 15, 62334}, {34, 15, 62332}, {35, 15, 62333},
    {36, 15, 4209}, {37, 15, 1139}, {13, 16, 1141}, {14, 16, 4209},
    {15, 16, 4209}, {16, 16, 62332}, {17, 16, 62333}, {18, 16, 4209},
    {19, 16, 4209}, {20, 16, 4209}, {21, 16, 4209}, {22, 16, 4209},
    {23, 16, 4209}, {24, 16, 62332}, {25, 16, 62333}, {26, 16, 62335},
    {27, 16, 62335}, {28, 16, 62335}, {29, 16, 62335}, {30, 16, 62335},
    {31, 16, 62335}, {32, 16, 62335}, {33, 16, 62335}, {34, 16, 62332},
    {35, 16, 62333}, {36, 16, 4209}, {37, 16, 1139}, {13, 17, 1141},
    {14, 17, 4209}, {15, 17, 4209}, {16, 17, 62332}, {17, 17, 62333},
    {18, 17, 4209}, {19, 17, 4209}, {20, 17, 4209}, {21, 17, 4209},
    {22, 17, 4209}, {23, 17, 4209}, {24, 17, 4315}, {25, 17, 4316},
    {26, 17, 4209}, {27, 17, 4209}, {28, 17, 4209}, {29, 17, 4209},
    {30, 17, 62332}, {31, 17, 62333}, {32, 17, 4209}, {33, 17, 4209},
    {34, 17, 4315}, {35, 17, 4316}, {36, 17, 4209}, {37, 17, 1139},
    {13, 18, 1141}, {14, 18, 4209}, {15, 18, 4209}, {16, 18, 62332},
    {17, 18, 62333}, {18, 18, 4209}, {19, 18, 1249}, {20, 18, 4209},
    {21, 18, 1171}, {22, 18, 1172}, {23, 18, 4209}, {24, 18, 4209},
    {25, 18, 4209}, {26, 18, 4209}, {27, 18, 4209}, {28, 18, 4209},
    {29, 18, 4209}, {30, 18, 62332}, {31, 18, 62333}, {32, 18, 4209},
    {33, 18, 1249}, {34, 18, 4209}, {35, 18, 4209}, {36, 18, 4209},
    {37, 18, 1139}, {13, 19, 1141}, {14, 19, 4209}, {15, 19, 4209},
    {16, 19, 62332}, {17, 19, 62333}, {18, 19, 4209}, {19, 19, 4209},
    {20, 19, 4209}, {21, 19, 1179}, {22, 19, 1180}, {23, 19, 4209},
    {24, 19, 4209}, {25, 19, 4209}, {26, 19, 4209}, {27, 19, 4209},
    {28, 19, 4209}, {29, 19, 4209}, {30, 19, 62332}, {31, 19, 62333},
    {32, 19, 4209}, {33, 19, 4209}, {34, 19, 1171}, {35, 19, 1172},
    {36, 19, 4209}, {37, 19, 1139}, {13, 20, 1141}, {14, 20, 1249},
    {15, 20, 4209}, {16, 20, 62332}, {17, 20, 62333}, {18, 20, 4209},
    {19, 20, 4209}, {20, 20, 4209}, {21, 20, 4209}, {22, 20, 4209},
    {23, 20, 4209}, {24, 20, 4209}, {25, 20, 4209}, {26, 20, 4209},
    {27, 20, 1249}, {28, 20, 4209}, {29, 20, 4209}, {30, 20, 62332},
    {31, 20, 62333}, {32, 20, 4209}, {33, 20, 4209}, {34, 20, 1179},
    {35, 20, 1180}, {36, 20, 4209}, {37, 20, 1139}, {13, 21, 1141},
    {14, 21, 4209}, {15, 21, 4209}, {16, 21, 62332}, {17, 21, 62333},
    {18, 21, 4209}, {19, 21, 4209}, {20, 21, 4209}, {21, 21, 4209},
    {22, 21, 4209}, {23, 21, 4209}, {24, 21, 4209}, {25, 21, 4209},
    {26, 21, 4209}, {27, 21, 4209}, {28, 21, 4209}, {29, 21, 4209},
    {30, 21, 62332}, {31, 21, 62333}, {32, 21, 4209}, {33, 21, 4209},
    {34, 21, 4209}, {35, 21, 4209}, {36, 21, 4209}, {37, 21, 1139},
    {24, 8, 1}, {25, 8, 1}, {34, 8, 1}, {35, 8, 1},
    {16, 11, 1}, {17, 11, 1}, {16, 22, 16385}, {17, 22, 16385},
    {30, 22, 16385}, {31, 22, 16385}, {16, 23, 1}, {30, 23, 280},
    {31, 23, 282},
};

void Nyxthra_DryUpRoute104Lake(void)
{
    u32 i;

    if (!FlagGet(FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT))
        return;

    for (i = 0; i < ARRAY_COUNT(sRoute104DryLakeTiles); i++)
    {
        MapGridSetMetatileEntryAt(sRoute104DryLakeTiles[i].x + MAP_OFFSET,
                                   sRoute104DryLakeTiles[i].y + MAP_OFFSET,
                                   sRoute104DryLakeTiles[i].mapEntry);
    }
    DrawWholeMapView();
}
