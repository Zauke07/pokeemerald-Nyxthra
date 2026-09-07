#ifndef GUARD_NYXTHRA_DRY_LAKE_H
#define GUARD_NYXTHRA_DRY_LAKE_H

// Nyxthra story: dries up the Route 104 lake once Groudon has awakened.
// See src/nyxthra_dry_lake.c for details. Safe to call on every map load;
// it no-ops until FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT is set.
void Nyxthra_DryUpRoute104Lake(void);

#endif // GUARD_NYXTHRA_DRY_LAKE_H
