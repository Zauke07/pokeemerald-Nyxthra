#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen6[] =
{
#endif

#if P_FAMILY_CHESPIN
    [SPECIES_CHESPIN] =
    {
        .baseHP        = 56,
        .baseAttack    = 61,
        .baseDefense   = 65,
        .baseSpeed     = 38,
        .baseSpAttack  = 48,
        .baseSpDefense = 45,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 63,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_BULLETPROOF },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Igamaro"),
        .cryId = CRY_CHESPIN,
        .natDexNum = NATIONAL_DEX_CHESPIN,
        .categoryName = _("Stachelkopf"),
        .height = 4,
        .weight = 90,
        .description = POKEDEX_DESC_STRING(
            "Wenn es seine Kraft auf die sonst\n"
            "eher weichen Stacheln auf seinem\n"
            "Kopf konzentriert, werden diese\n"
            "robust genug, um damit Steine zu\n"
            "zertrümmern."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Chespin, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Chespin,
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        BACK_PIC(Chespin, 56, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Chespin),
        ICON(Chespin, 1),
        .footprint = gMonFootprint_Chespin,
        LEARNSETS(Chespin),
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_QUILLADIN}),
    },

    [SPECIES_QUILLADIN] =
    {
        .baseHP        = 61,
        .baseAttack    = 78,
        .baseDefense   = 95,
        .baseSpeed     = 57,
        .baseSpAttack  = 56,
        .baseSpDefense = 58,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 142,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_BULLETPROOF },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Igastarnish"),
        .cryId = CRY_QUILLADIN,
        .natDexNum = NATIONAL_DEX_QUILLADIN,
        .categoryName = _("Spitzpanzer"),
        .height = 7,
        .weight = 290,
        .description = POKEDEX_DESC_STRING(
            "Der Panzer, der seinen Körper\n"
            "umgibt, bietet ihm Schutz vor\n"
            "Angreifern und straft direkte\n"
            "Angriffe postwendend mit spitzen\n"
            "Stacheln ab."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Quilladin, 48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Quilladin,
        .frontAnimId = ANIM_LUNGE_GROW,
        BACK_PIC(Quilladin, 64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_GROW,
        PALETTES(Quilladin),
        ICON(Quilladin, 1),
        .footprint = gMonFootprint_Quilladin,
        LEARNSETS(Quilladin),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_CHESNAUGHT}),
    },

    [SPECIES_CHESNAUGHT] =
    {
        .baseHP        = 88,
        .baseAttack    = 107,
        .baseDefense   = 122,
        .baseSpeed     = 64,
        .baseSpAttack  = 74,
        .baseSpDefense = 75,
        .types = { TYPE_GRASS, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 239,
        .evYield_Defense = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_BULLETPROOF },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Brigaron"),
        .cryId = CRY_CHESNAUGHT,
        .natDexNum = NATIONAL_DEX_CHESNAUGHT,
        .categoryName = _("Spitzpanzer"),
        .height = 16,
        .weight = 900,
        .description = POKEDEX_DESC_STRING(
            "Wenn es seine Fäuste vors Gesicht hält und\n"
            "so eine Verteidigungshaltung einnimmt,\n"
            "kann es selbst eine Explosion überstehen."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Chesnaught, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Chesnaught,
        .frontAnimId = ANIM_GROW_IN_STAGES,
        BACK_PIC(Chesnaught, 64, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Chesnaught),
        ICON(Chesnaught, 1),
        .footprint = gMonFootprint_Chesnaught,
        LEARNSETS(Chesnaught),
    },
#endif //P_FAMILY_CHESPIN

#if P_FAMILY_FENNEKIN
    [SPECIES_FENNEKIN] =
    {
        .baseHP        = 40,
        .baseAttack    = 45,
        .baseDefense   = 40,
        .baseSpeed     = 60,
        .baseSpAttack  = 62,
        .baseSpDefense = 60,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 61,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_MAGICIAN },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Fynx"),
        .cryId = CRY_FENNEKIN,
        .natDexNum = NATIONAL_DEX_FENNEKIN,
        .categoryName = _("Fuchs"),
        .height = 4,
        .weight = 94,
        .description = POKEDEX_DESC_STRING(
            "Wenn es Zweige frisst, fasst es\n"
            "neue Kraft und stößt über seine\n"
            "Ohren über 200 Grad C heiße Luft aus."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Fennekin, 40, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Fennekin,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Fennekin, 56, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Fennekin),
        ICON(Fennekin, 0),
        .footprint = gMonFootprint_Fennekin,
        LEARNSETS(Fennekin),
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_BRAIXEN}),
    },

    [SPECIES_BRAIXEN] =
    {
        .baseHP        = 59,
        .baseAttack    = 59,
        .baseDefense   = 58,
        .baseSpeed     = 73,
        .baseSpAttack  = 90,
        .baseSpDefense = 70,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 143,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_MAGICIAN },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Rutena"),
        .cryId = CRY_BRAIXEN,
        .natDexNum = NATIONAL_DEX_BRAIXEN,
        .categoryName = _("Fuchs"),
        .height = 10,
        .weight = 145,
        .description = POKEDEX_DESC_STRING(
            "In seinem Schweif steckt ein Zweig,\n"
            "den es bei Bedarf mit der\n"
            "Reibungswärme seiner Schweifhaare\n"
            "anzündet und im Kampf einsetzt."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Braixen, 48, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Braixen,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Braixen, 64, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Braixen),
        ICON(Braixen, 0),
        .footprint = gMonFootprint_Braixen,
        LEARNSETS(Braixen),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_DELPHOX}),
    },

    [SPECIES_DELPHOX] =
    {
        .baseHP        = 75,
        .baseAttack    = 69,
        .baseDefense   = 72,
        .baseSpeed     = 104,
        .baseSpAttack  = 114,
        .baseSpDefense = 100,
        .types = { TYPE_FIRE, TYPE_PSYCHIC },
        .catchRate = 45,
        .expYield = 240,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_MAGICIAN },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Fennexis"),
        .cryId = CRY_DELPHOX,
        .natDexNum = NATIONAL_DEX_DELPHOX,
        .categoryName = _("Fuchs"),
        .height = 15,
        .weight = 390,
        .description = POKEDEX_DESC_STRING(
            "Es kann die Zukunft vorhersehen,\n"
            "indem es konzentriert in die Flamme\n"
            "an der Spitze seines Zweiges\n"
            "blickt."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Delphox, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Delphox,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Delphox, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Delphox),
        ICON(Delphox, 0),
        .footprint = gMonFootprint_Delphox,
        LEARNSETS(Delphox),
    },
#endif //P_FAMILY_FENNEKIN

#if P_FAMILY_FROAKIE
    [SPECIES_FROAKIE] =
    {
        .baseHP        = 41,
        .baseAttack    = 56,
        .baseDefense   = 40,
        .baseSpeed     = 71,
        .baseSpAttack  = 62,
        .baseSpDefense = 44,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 63,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_PROTEAN },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Froxy"),
        .cryId = CRY_FROAKIE,
        .natDexNum = NATIONAL_DEX_FROAKIE,
        .categoryName = _("Blubbfrosch"),
        .height = 3,
        .weight = 70,
        .description = POKEDEX_DESC_STRING(
            "Es stößt aus Brust und Rücken\n"
            "elastische Blasen aus, mit denen es\n"
            "gegnerische Angriffe abfängt und so\n"
            "den erlittenen Schaden verringert."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Froakie, 40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Froakie,
        .frontAnimId = ANIM_H_JUMPS,
        BACK_PIC(Froakie, 56, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Froakie),
        ICON(Froakie, 0),
        .footprint = gMonFootprint_Froakie,
        LEARNSETS(Froakie),
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_FROGADIER}),
    },

    [SPECIES_FROGADIER] =
    {
        .baseHP        = 54,
        .baseAttack    = 63,
        .baseDefense   = 52,
        .baseSpeed     = 97,
        .baseSpAttack  = 83,
        .baseSpDefense = 56,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 142,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_PROTEAN },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Amphizel"),
        .cryId = CRY_FROGADIER,
        .natDexNum = NATIONAL_DEX_FROGADIER,
        .categoryName = _("Blubbfrosch"),
        .height = 6,
        .weight = 109,
        .description = POKEDEX_DESC_STRING(
            "Seine Flinkheit sucht ihresgleichen. Es\n"
            "kann einen 600 m hohen Turm in weniger als\n"
            "einer Minute erklimmen."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Frogadier, 56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Frogadier,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Frogadier, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Frogadier),
        ICON(Frogadier, 0),
        .footprint = gMonFootprint_Frogadier,
        LEARNSETS(Frogadier),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_GRENINJA}),
    },

#define GRENINJA_NORMAL_MISC_INFO           \
        .baseHP        = 72,                \
        .baseAttack    = 95,                \
        .baseDefense   = 67,                \
        .baseSpeed     = 122,               \
        .baseSpAttack  = 103,               \
        .baseSpDefense = 71,                \
        .expYield = 239,                    \
        .description = gGreninjaPokedexText,\
        FRONT_PIC(Greninja, 64, 56),        \
        .frontPicYOffset = 7,               \
        .frontAnimFrames = sAnims_Greninja, \
        BACK_PIC(Greninja, 64, 48),         \
        .backPicYOffset = 11,               \
        PALETTES(Greninja),                 \
        ICON(Greninja, 0)

#define GRENINJA_MISC_INFO                              \
        .types = { TYPE_WATER, TYPE_DARK },             \
        .catchRate = 45,                                \
        .evYield_Speed = 3,                             \
        .eggCycles = 20,                                \
        .friendship = STANDARD_FRIENDSHIP,              \
        .growthRate = GROWTH_MEDIUM_SLOW,               \
        .bodyColor = BODY_COLOR_BLUE,                   \
        .noFlip = TRUE,                                 \
        .speciesName = _("Amphizel"),                   \
        .cryId = CRY_GRENINJA,                          \
        .natDexNum = NATIONAL_DEX_GRENINJA,             \
        .categoryName = _("Blubbfrosch"),                     \
        .height = 15,                                   \
        .weight = 400,                                  \
        .pokemonScale = 268,                            \
        .pokemonOffset = 2,                             \
        .trainerScale = 271,                            \
        .trainerOffset = 0,                             \
        .footprint = gMonFootprint_Greninja,            \
        LEARNSETS(Greninja),                            \
        .formSpeciesIdTable = sGreninjaFormSpeciesIdTable

    [SPECIES_GRENINJA] =
    {
        GRENINJA_MISC_INFO,
        GRENINJA_NORMAL_MISC_INFO,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_PROTEAN },
        .frontAnimId = ANIM_V_STRETCH,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
    },

    [SPECIES_GRENINJA_BATTLE_BOND] =
    {
        GRENINJA_MISC_INFO,
        GRENINJA_NORMAL_MISC_INFO,
        .genderRatio = MON_MALE,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BATTLE_BOND, ABILITY_NONE, ABILITY_NONE },
        .frontAnimId = ANIM_V_STRETCH,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        .formChangeTable = sGreninjaBattleBondFormChangeTable,
    },

    [SPECIES_GRENINJA_ASH] =
    {
        GRENINJA_MISC_INFO,
        .baseHP        = 72,
        .baseAttack    = 145,
        .baseDefense   = 67,
        .baseSpeed     = 132,
        .baseSpAttack  = 153,
        .baseSpDefense = 71,
        .expYield = 288,
        .genderRatio = MON_MALE,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BATTLE_BOND, ABILITY_NONE, ABILITY_NONE },
        .description = POKEDEX_DESC_STRING(
            "Es stellt Wurfsterne aus\n"
            "komprimiertem Wasser her, die durch\n"
            "ihre hohe Drehgeschwindigkeit beim\n"
            "Werfen sogar Metall durchtrennen."),
        FRONT_PIC(GreninjaAsh, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_GreninjaAsh,
        BACK_PIC(GreninjaAsh, 64, 48),
        .backPicYOffset = 11,
        PALETTES(GreninjaAsh),
        ICON(GreninjaAsh, 0),
        .frontAnimId = ANIM_V_STRETCH,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .formChangeTable = sGreninjaBattleBondFormChangeTable,
    },
#endif //P_FAMILY_FROAKIE

#if P_FAMILY_BUNNELBY
    [SPECIES_BUNNELBY] =
    {
        .baseHP        = 38,
        .baseAttack    = 36,
        .baseDefense   = 38,
        .baseSpeed     = 57,
        .baseSpAttack  = 32,
        .baseSpDefense = 36,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 47,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_PICKUP, ABILITY_CHEEK_POUCH, ABILITY_HUGE_POWER },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Scoppel"),
        .cryId = CRY_BUNNELBY,
        .natDexNum = NATIONAL_DEX_BUNNELBY,
        .categoryName = _("Baugräber"),
        .height = 4,
        .weight = 50,
        .description = POKEDEX_DESC_STRING(
            "Mit den Ohren schaufelt es Löcher. Es\n"
            "braucht nur eine Nacht, um einen 10 m\n"
            "tiefen Bau zu graben."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Bunnelby, 48, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Bunnelby,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Bunnelby, 48, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Bunnelby),
        ICON(Bunnelby, 2),
        .footprint = gMonFootprint_Bunnelby,
        LEARNSETS(Bunnelby),
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_DIGGERSBY}),
    },

    [SPECIES_DIGGERSBY] =
    {
        .baseHP        = 85,
        .baseAttack    = 56,
        .baseDefense   = 77,
        .baseSpeed     = 78,
        .baseSpAttack  = 50,
        .baseSpDefense = 77,
        .types = { TYPE_NORMAL, TYPE_GROUND },
        .catchRate = 127,
        .expYield = 148,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_PICKUP, ABILITY_CHEEK_POUCH, ABILITY_HUGE_POWER },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Grebbit"),
        .cryId = CRY_DIGGERSBY,
        .natDexNum = NATIONAL_DEX_DIGGERSBY,
        .categoryName = _("Baugräber"),
        .height = 10,
        .weight = 424,
        .description = POKEDEX_DESC_STRING(
            "Das Fell an seinem Bauch hält es schön\n"
            "warm. Früher haben die Menschen daraus\n"
            "Kleidung gefertigt, die sie vor Kälte\n"
            "schützte."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Diggersby, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Diggersby,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(Diggersby, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Diggersby),
        ICON(Diggersby, 2),
        .footprint = gMonFootprint_Diggersby,
        LEARNSETS(Diggersby),
    },
#endif //P_FAMILY_BUNNELBY

#if P_FAMILY_FLETCHLING
    [SPECIES_FLETCHLING] =
    {
        .baseHP        = 45,
        .baseAttack    = 50,
        .baseDefense   = 43,
        .baseSpeed     = 62,
        .baseSpAttack  = 40,
        .baseSpDefense = 38,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 255,
        .expYield = 56,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_BIG_PECKS, ABILITY_NONE, ABILITY_GALE_WINGS },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Dartiri"),
        .cryId = CRY_FLETCHLING,
        .natDexNum = NATIONAL_DEX_FLETCHLING,
        .categoryName = _("Rotkehlchen"),
        .height = 3,
        .weight = 17,
        .description = POKEDEX_DESC_STRING(
            "Sein Körper ist immer warm. In kalten\n"
            "Gebieten schlafen Trainer deshalb oft in\n"
            "einem Bett mit ihm."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Fletchling, 40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Fletchling,
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        BACK_PIC(Fletchling, 64, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Fletchling),
        ICON(Fletchling, 2),
        .footprint = gMonFootprint_Fletchling,
        LEARNSETS(Fletchling),
        .evolutions = EVOLUTION({EVO_LEVEL, 17, SPECIES_FLETCHINDER}),
    },

    [SPECIES_FLETCHINDER] =
    {
        .baseHP        = 62,
        .baseAttack    = 73,
        .baseDefense   = 55,
        .baseSpeed     = 84,
        .baseSpAttack  = 56,
        .baseSpDefense = 52,
        .types = { TYPE_FIRE, TYPE_FLYING },
        .catchRate = 120,
        .expYield = 134,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_FLAME_BODY, ABILITY_NONE, ABILITY_GALE_WINGS },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Dartignis"),
        .cryId = CRY_FLETCHINDER,
        .natDexNum = NATIONAL_DEX_FLETCHINDER,
        .categoryName = _("Funkenregen"),
        .height = 7,
        .weight = 160,
        .description = POKEDEX_DESC_STRING(
            "Es speit Funken aus seinem Schnabel\n"
            "und fängt die Beute, die überrascht\n"
            "aus dem angesengten Gras\n"
            "hervorspringt."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Fletchinder, 56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Fletchinder,
        .frontAnimId = ANIM_V_SLIDE_SLOW,
        .enemyMonElevation = 9,
        BACK_PIC(Fletchinder, 64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Fletchinder),
        ICON(Fletchinder, 2),
        .footprint = gMonFootprint_Fletchinder,
        LEARNSETS(Fletchinder),
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_TALONFLAME}),
    },

    [SPECIES_TALONFLAME] =
    {
        .baseHP        = 78,
        .baseAttack    = 81,
        .baseDefense   = 71,
        .baseSpeed     = 126,
        .baseSpAttack  = 74,
        .baseSpDefense = 69,
        .types = { TYPE_FIRE, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 175,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_FLAME_BODY, ABILITY_NONE, ABILITY_GALE_WINGS },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Fiaro"),
        .cryId = CRY_TALONFLAME,
        .natDexNum = NATIONAL_DEX_TALONFLAME,
        .categoryName = _("Stichflammen"),
        .height = 12,
        .weight = 245,
        .description = POKEDEX_DESC_STRING(
            "Sein Gefieder ist robust und feuerfest.\n"
            "Früher fertigte man Feuerwehranzüge\n"
            "deshalb aus Fiaro-Federn."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Talonflame, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Talonflame,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 7,
        BACK_PIC(Talonflame, 64, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(Talonflame),
        ICON(Talonflame, 2),
        .footprint = gMonFootprint_Talonflame,
        LEARNSETS(Talonflame),
    },
#endif //P_FAMILY_FLETCHLING

#if P_FAMILY_SCATTERBUG
    [SPECIES_SCATTERBUG] =
    {
        .baseHP        = 38,
        .baseAttack    = 35,
        .baseDefense   = 40,
        .baseSpeed     = 35,
        .baseSpAttack  = 27,
        .baseSpDefense = 25,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 255,
        .expYield = 40,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SHIELD_DUST, ABILITY_COMPOUND_EYES, ABILITY_FRIEND_GUARD },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Purmel"),
        .cryId = CRY_SCATTERBUG,
        .natDexNum = NATIONAL_DEX_SCATTERBUG,
        .categoryName = _("Puderinsekt"),
        .height = 3,
        .weight = 25,
        .description = POKEDEX_DESC_STRING(
            "Es reguliert seine Körpertemperatur mit\n"
            "dem Puder, das seinen Körper bedeckt, und\n"
            "kommt deswegen in jedem Klima und jeder\n"
            "Region zurecht."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Scatterbug, 32, 48),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Scatterbug,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Scatterbug, 40, 56),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Scatterbug),
        ICON(Scatterbug, 1),
        .footprint = gMonFootprint_Scatterbug,
        LEARNSETS(Scatterbug),
        .evolutions = EVOLUTION({EVO_LEVEL, 9, SPECIES_SPEWPA}),
    },

    [SPECIES_SPEWPA] =
    {
        .baseHP        = 45,
        .baseAttack    = 22,
        .baseDefense   = 60,
        .baseSpeed     = 29,
        .baseSpAttack  = 27,
        .baseSpDefense = 30,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 120,
        .expYield = 75,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SHED_SKIN, ABILITY_NONE, ABILITY_FRIEND_GUARD },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Puponcho"),
        .cryId = CRY_SPEWPA,
        .natDexNum = NATIONAL_DEX_SPEWPA,
        .categoryName = _("Puderinsekt"),
        .height = 3,
        .weight = 84,
        .description = POKEDEX_DESC_STRING(
            "Der Schnabel eines Vogel-Pokémon kann\n"
            "seinem harten Körper keinen Kratzer\n"
            "zufügen. Es verteidigt sich, indem es\n"
            "Puder spuckt."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Spewpa, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Spewpa,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Spewpa, 48, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Spewpa),
        ICON(Spewpa, 1),
        .footprint = gMonFootprint_Spewpa,
        LEARNSETS(Spewpa),
        .evolutions = EVOLUTION({EVO_LEVEL, 12, SPECIES_VIVILLON_ICY_SNOW}),
    },

#define VIVILLON_MISC_INFO(form, color, iconPal)                                            \
        .baseHP        = 80,                                                                \
        .baseAttack    = 52,                                                                \
        .baseDefense   = 50,                                                                \
        .baseSpeed     = 89,                                                                \
        .baseSpAttack  = 90,                                                                \
        .baseSpDefense = 50,                                                                \
        .types = { TYPE_BUG, TYPE_FLYING },                                                 \
        .catchRate = 45,                                                                    \
        .expYield = 185,                                                                    \
        .evYield_HP = 1,                                                                    \
        .evYield_Speed = 1,                                                                 \
        .evYield_SpAttack = 1,                                                              \
        .genderRatio = PERCENT_FEMALE(50),                                                  \
        .eggCycles = 15,                                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                                  \
        .growthRate = GROWTH_MEDIUM_FAST,                                                   \
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },                                      \
        .abilities = { ABILITY_SHIELD_DUST, ABILITY_COMPOUND_EYES, ABILITY_FRIEND_GUARD },  \
        .bodyColor = color,                                                                 \
        .speciesName = _("Puponcho"),                                                       \
        .cryId = CRY_VIVILLON,                                                              \
        .natDexNum = NATIONAL_DEX_VIVILLON,                                                 \
        .categoryName = _("Puderinsekt"),                                                         \
        .height = 12,                                                                       \
        .weight = 170,                                                                      \
        .pokemonScale = 282,                                                                \
        .pokemonOffset = 4,                                                                 \
        .trainerScale = 256,                                                                \
        .trainerOffset = 0,                                                                 \
        FRONT_PIC(Vivillon ##form, 64, 64),                                                 \
        .frontPicYOffset = 0,                                                               \
        .frontAnimFrames = sAnims_Vivillon,                                                 \
        .frontAnimId = ANIM_ZIGZAG_SLOW,                                                    \
        .enemyMonElevation = 9,                                                             \
        BACK_PIC(Vivillon ##form, 64, 64),                                                  \
        .backPicYOffset = 0,                                                                \
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,                                    \
        PALETTES(Vivillon ##form),                                                           \
        ICON(Vivillon ##form, iconPal),                                                     \
        .footprint = gMonFootprint_Vivillon,                                                \
        LEARNSETS(Vivillon),                                                                \
        .formSpeciesIdTable = sVivillonFormSpeciesIdTable

    [SPECIES_VIVILLON_ICY_SNOW] =
    {
        VIVILLON_MISC_INFO(IcySnow, BODY_COLOR_WHITE, 0),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_POLAR] =
    {
        VIVILLON_MISC_INFO(Polar, BODY_COLOR_BLUE, 0),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_TUNDRA] =
    {
        VIVILLON_MISC_INFO(Tundra, BODY_COLOR_BLUE, 0),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_CONTINENTAL] =
    {
        VIVILLON_MISC_INFO(Continental, BODY_COLOR_YELLOW, 2),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_GARDEN] =
    {
        VIVILLON_MISC_INFO(Garden, BODY_COLOR_GREEN, 1),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_ELEGANT] =
    {
        VIVILLON_MISC_INFO(Elegant, BODY_COLOR_PURPLE, 0),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_MEADOW] =
    {
        VIVILLON_MISC_INFO(Meadow, BODY_COLOR_PINK, 0),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_MODERN] =
    {
        VIVILLON_MISC_INFO(Modern, BODY_COLOR_RED, 2),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_MARINE] =
    {
        VIVILLON_MISC_INFO(Marine, BODY_COLOR_BLUE, 0),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_ARCHIPELAGO] =
    {
        VIVILLON_MISC_INFO(Archipelago, BODY_COLOR_BROWN, 0),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_HIGH_PLAINS] =
    {
        VIVILLON_MISC_INFO(HighPlains, BODY_COLOR_BROWN, 0),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_SANDSTORM] =
    {
        VIVILLON_MISC_INFO(Sandstorm, BODY_COLOR_BROWN, 1),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_RIVER] =
    {
        VIVILLON_MISC_INFO(River, BODY_COLOR_BROWN, 2),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_MONSOON] =
    {
        VIVILLON_MISC_INFO(Monsoon, BODY_COLOR_GRAY, 0),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_SAVANNA] =
    {
        VIVILLON_MISC_INFO(Savanna, BODY_COLOR_GREEN, 0),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_SUN] =
    {
        VIVILLON_MISC_INFO(Sun, BODY_COLOR_RED, 0),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_OCEAN] =
    {
        VIVILLON_MISC_INFO(Ocean, BODY_COLOR_RED, 0),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_JUNGLE] =
    {
        VIVILLON_MISC_INFO(Jungle, BODY_COLOR_GREEN, 0),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_FANCY] =
    {
        VIVILLON_MISC_INFO(Fancy, BODY_COLOR_PINK, 1),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
    [SPECIES_VIVILLON_POKE_BALL] =
    {
        VIVILLON_MISC_INFO(PokeBall, BODY_COLOR_RED, 2),
        .description = POKEDEX_DESC_STRING(
            "Vivillon kommen weltweit mit den\n"
            "unterschiedlichsten Musterungen\n"
            "vor. Das Klima ihres Habitats hat\n"
            "Einfluss auf ihre Flügelmusterung."),
    },
#endif //P_FAMILY_SCATTERBUG

#if P_FAMILY_LITLEO
    [SPECIES_LITLEO] =
    {
        .baseHP        = 62,
        .baseAttack    = 50,
        .baseDefense   = 58,
        .baseSpeed     = 72,
        .baseSpAttack  = 73,
        .baseSpDefense = 54,
        .types = { TYPE_FIRE, TYPE_NORMAL },
        .catchRate = 220,
        .expYield = 74,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(87.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RIVALRY, ABILITY_UNNERVE, ABILITY_MOXIE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Leufeo"),
        .cryId = CRY_LITLEO,
        .natDexNum = NATIONAL_DEX_LITLEO,
        .categoryName = _("Junglöwe"),
        .height = 6,
        .weight = 135,
        .description = POKEDEX_DESC_STRING(
            "Ein sehr aktives und neugieriges Pokémon.\n"
            "Bei Kampfbeginn und wenn es wütend ist,\n"
            "wird seine Mähne heiß."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Litleo, 40, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Litleo,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        BACK_PIC(Litleo, 56, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Litleo),
        ICON(Litleo, 2),
        .footprint = gMonFootprint_Litleo,
        LEARNSETS(Litleo),
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_PYROAR}),
    },

    [SPECIES_PYROAR] =
    {
        .baseHP        = 86,
        .baseAttack    = 68,
        .baseDefense   = 72,
        .baseSpeed     = 106,
        .baseSpAttack  = 109,
        .baseSpDefense = 66,
        .types = { TYPE_FIRE, TYPE_NORMAL },
        .catchRate = 65,
        .expYield = 177,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(87.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RIVALRY, ABILITY_UNNERVE, ABILITY_MOXIE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Pyroleo"),
        .cryId = CRY_PYROAR,
        .natDexNum = NATIONAL_DEX_PYROAR,
        .categoryName = _("Monarch"),
        .height = 15,
        .weight = 815,
        .description = POKEDEX_DESC_STRING(
            "Das Männchen mit der prächtigsten\n"
            "Feuermähne führt das Rudel an."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Pyroar, 64, 64),
        FRONT_PIC_FEMALE(Pyroar, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Pyroar,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Pyroar, 64, 64),
        BACK_PIC_FEMALE(Pyroar, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Pyroar),
        ICON(Pyroar, 2),
        ICON_FEMALE(Pyroar, 2),
        .footprint = gMonFootprint_Pyroar,
        LEARNSETS(Pyroar),
    },
#endif //P_FAMILY_LITLEO

#if P_FAMILY_FLABEBE
#define FLABEBE_MISC_INFO(Form, FORM, iconPal)                                  \
        .baseHP        = 44,                                                    \
        .baseAttack    = 38,                                                    \
        .baseDefense   = 39,                                                    \
        .baseSpeed     = 42,                                                    \
        .baseSpAttack  = 61,                                                    \
        .baseSpDefense = 79,                                                    \
        .types = { TYPE_FAIRY, TYPE_FAIRY },                                    \
        .catchRate = 225,                                                       \
        .expYield = 61,                                                         \
        .evYield_SpDefense = 1,                                                 \
        .genderRatio = MON_FEMALE,                                              \
        .eggCycles = 20,                                                        \
        .friendship = STANDARD_FRIENDSHIP,                                      \
        .growthRate = GROWTH_MEDIUM_FAST,                                       \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },                      \
        .abilities = { ABILITY_FLOWER_VEIL, ABILITY_NONE, ABILITY_SYMBIOSIS },  \
        .bodyColor = BODY_COLOR_WHITE,                                          \
        .speciesName = _("Pyroleo"),                                            \
        .cryId = CRY_FLABEBE,                                                   \
        .natDexNum = NATIONAL_DEX_FLABEBE,                                      \
        .categoryName = _("Monarch"),                                      \
        .height = 1,                                                            \
        .weight = 1,                                                            \
        .pokemonScale = 682,                                                    \
        .pokemonOffset = 24,                                                    \
        .trainerScale = 256,                                                    \
        .trainerOffset = 0,                                                     \
        FRONT_PIC(Flabebe, 48, 56),                                             \
        .frontPicYOffset = 6,                                                   \
        .frontAnimFrames = sAnims_Flabebe,                                      \
        .frontAnimId = ANIM_H_SLIDE_SLOW,                                       \
        .enemyMonElevation = 6,                                                 \
        BACK_PIC(Flabebe, 64, 40),                                              \
        .backPicYOffset = 12,                                                   \
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,                              \
        PALETTES(Flabebe##Form##Flower),                                         \
        ICON(Flabebe##Form##Flower, iconPal),                                   \
        .footprint = gMonFootprint_Flabebe,                                     \
        LEARNSETS(Flabebe),                                                     \
        .formSpeciesIdTable = sFlabebeFormSpeciesIdTable,                       \
        .evolutions = EVOLUTION({EVO_LEVEL, 19, SPECIES_FLOETTE_ ##FORM##_FLOWER})

    [SPECIES_FLABEBE_RED_FLOWER] =
    {
        FLABEBE_MISC_INFO(Red, RED, 1),
        .description = POKEDEX_DESC_STRING(
            "Die Krone auf seinem Kopf hat es\n"
            "sich aus Pollen von Blumen\n"
            "gebastelt. Sie besitzt eine\n"
            "heilende Wirkung."),
    },
    [SPECIES_FLABEBE_YELLOW_FLOWER] =
    {
        FLABEBE_MISC_INFO(Yellow, YELLOW, 1),
        .description = POKEDEX_DESC_STRING(
            "Die Krone auf seinem Kopf hat es\n"
            "sich aus Pollen von Blumen\n"
            "gebastelt. Sie besitzt eine\n"
            "heilende Wirkung."),
    },
    [SPECIES_FLABEBE_ORANGE_FLOWER] =
    {
        FLABEBE_MISC_INFO(Orange, ORANGE, 0),
        .description = POKEDEX_DESC_STRING(
            "Die Krone auf seinem Kopf hat es\n"
            "sich aus Pollen von Blumen\n"
            "gebastelt. Sie besitzt eine\n"
            "heilende Wirkung."),
    },
    [SPECIES_FLABEBE_BLUE_FLOWER]   =
    {
        FLABEBE_MISC_INFO(Blue, BLUE, 0),
        .description = POKEDEX_DESC_STRING(
            "Die Krone auf seinem Kopf hat es\n"
            "sich aus Pollen von Blumen\n"
            "gebastelt. Sie besitzt eine\n"
            "heilende Wirkung."),
    },
    [SPECIES_FLABEBE_WHITE_FLOWER]  =
    {
        FLABEBE_MISC_INFO(White, WHITE, 1),
        .description = POKEDEX_DESC_STRING(
            "Die Krone auf seinem Kopf hat es\n"
            "sich aus Pollen von Blumen\n"
            "gebastelt. Sie besitzt eine\n"
            "heilende Wirkung."),
    },

#define FLOETTE_MISC_INFO(form, FORM, iconPal)                                  \
        .types = { TYPE_FAIRY, TYPE_FAIRY },                                    \
        .catchRate = 120,                                                       \
        .evYield_SpDefense = 2,                                                 \
        .genderRatio = MON_FEMALE,                                              \
        .eggCycles = 20,                                                        \
        .friendship = STANDARD_FRIENDSHIP,                                      \
        .growthRate = GROWTH_MEDIUM_FAST,                                       \
        .abilities = { ABILITY_FLOWER_VEIL, ABILITY_NONE, ABILITY_SYMBIOSIS },  \
        .bodyColor = BODY_COLOR_WHITE,                                          \
        .speciesName = _("Flabébé"),                                            \
        .natDexNum = NATIONAL_DEX_FLOETTE,                                      \
        .categoryName = _("Einblütler"),                                      \
        .height = 2,                                                            \
        .weight = 9,                                                            \
        .pokemonScale = 682,                                                    \
        .pokemonOffset = 24,                                                    \
        .trainerScale = 256,                                                    \
        .trainerOffset = 0,                                                     \
        .frontAnimFrames = sAnims_Floette,                                      \
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,                                     \
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,                              \
        PALETTES(Floette ##form##Flower),                                        \
        ICON(Floette##form##Flower, iconPal),                                   \
        .footprint = gMonFootprint_Floette,                                     \
        .formSpeciesIdTable = sFloetteFormSpeciesIdTable

#define FLOETTE_NORMAL_INFO(form, FORM, iconPal)                                                \
        .baseHP        = 54,                                                                    \
        .baseAttack    = 45,                                                                    \
        .baseDefense   = 47,                                                                    \
        .baseSpeed     = 52,                                                                    \
        .baseSpAttack  = 75,                                                                    \
        .baseSpDefense = 98,                                                                    \
        .expYield = 130,                                                                        \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },                                      \
        .cryId = CRY_FLOETTE,                                                                   \
        FRONT_PIC(Floette, 48, 64),                                                             \
        .frontPicYOffset = 3,                                                                   \
        .enemyMonElevation = 4,                                                                 \
        BACK_PIC(Floette, 64, 64),                                                              \
        .backPicYOffset = 2,                                                                    \
        LEARNSETS(Floette),                                                                     \
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SHINY_STONE, SPECIES_FLORGES_ ##FORM##_FLOWER}),\
        FLOETTE_MISC_INFO(form, FORM, iconPal)

    [SPECIES_FLOETTE_RED_FLOWER] =
    {
        FLOETTE_NORMAL_INFO(Red, RED, 1),
        .description = POKEDEX_DESC_STRING(
            "Es fliegt auf Wiesen umher und\n"
            "kümmert sich um welkende Blumen. Es\n"
            "setzt deren geheime Kräfte frei und\n"
            "nutzt diese zum Kämpfen."),
    },
    [SPECIES_FLOETTE_YELLOW_FLOWER] =
    {
        FLOETTE_NORMAL_INFO(Yellow, YELLOW, 1),
        .description = POKEDEX_DESC_STRING(
            "Es fliegt auf Wiesen umher und\n"
            "kümmert sich um welkende Blumen. Es\n"
            "setzt deren geheime Kräfte frei und\n"
            "nutzt diese zum Kämpfen."),
    },
    [SPECIES_FLOETTE_ORANGE_FLOWER] =
    {
        FLOETTE_NORMAL_INFO(Orange, ORANGE, 0),
        .description = POKEDEX_DESC_STRING(
            "Es fliegt auf Wiesen umher und\n"
            "kümmert sich um welkende Blumen. Es\n"
            "setzt deren geheime Kräfte frei und\n"
            "nutzt diese zum Kämpfen."),
    },
    [SPECIES_FLOETTE_BLUE_FLOWER] =
    {
        FLOETTE_NORMAL_INFO(Blue, BLUE, 0),
        .description = POKEDEX_DESC_STRING(
            "Es fliegt auf Wiesen umher und\n"
            "kümmert sich um welkende Blumen. Es\n"
            "setzt deren geheime Kräfte frei und\n"
            "nutzt diese zum Kämpfen."),
    },
    [SPECIES_FLOETTE_WHITE_FLOWER] =
    {
        FLOETTE_NORMAL_INFO(White, WHITE, 1),
        .description = POKEDEX_DESC_STRING(
            "Es fliegt auf Wiesen umher und\n"
            "kümmert sich um welkende Blumen. Es\n"
            "setzt deren geheime Kräfte frei und\n"
            "nutzt diese zum Kämpfen."),
    },
    [SPECIES_FLOETTE_ETERNAL_FLOWER] =
    {
        FLOETTE_MISC_INFO(Eternal, ETERNAL, 0),
        .baseHP        = 74,
        .baseAttack    = 65,
        .baseDefense   = 67,
        .baseSpeed     = 92,
        .baseSpAttack  = 125,
        .baseSpDefense = 128,
        .expYield = 243,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .description = POKEDEX_DESC_STRING(
            "Es fliegt auf Wiesen umher und\n"
            "kümmert sich um welkende Blumen. Es\n"
            "setzt deren geheime Kräfte frei und\n"
            "nutzt diese zum Kämpfen."),
        .cryId = CRY_FLOETTE_ETERNAL_FLOWER,
        FRONT_PIC(FloetteEternalFlower, 64, 64),
        .frontPicYOffset = 3,
        .enemyMonElevation = 4,
        BACK_PIC(FloetteEternalFlower, 64, 64),
        .backPicYOffset = 2,
        LEARNSETS(FloetteEternalFlower),
    },

#define FLORGES_MISC_INFO(Form, iconPal)                                        \
        .baseHP        = 78,                                                    \
        .baseAttack    = 65,                                                    \
        .baseDefense   = 68,                                                    \
        .baseSpeed     = 75,                                                    \
        .baseSpAttack  = 112,                                                   \
        .baseSpDefense = 154,                                                   \
        .types = { TYPE_FAIRY, TYPE_FAIRY },                                    \
        .catchRate = 45,                                                        \
        .expYield = 248,                                                        \
        .evYield_SpDefense = 3,                                                 \
        .genderRatio = MON_FEMALE,                                              \
        .eggCycles = 20,                                                        \
        .friendship = STANDARD_FRIENDSHIP,                                      \
        .growthRate = GROWTH_MEDIUM_FAST,                                       \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },                      \
        .abilities = { ABILITY_FLOWER_VEIL, ABILITY_NONE, ABILITY_SYMBIOSIS },  \
        .bodyColor = BODY_COLOR_WHITE,                                          \
        .speciesName = _("Floette"),                                            \
        .cryId = CRY_FLORGES,                                                   \
        .natDexNum = NATIONAL_DEX_FLORGES,                                      \
        .categoryName = _("Einblütler"),                                            \
        .height = 11,                                                           \
        .weight = 100,                                                          \
        .pokemonScale = 320,                                                    \
        .pokemonOffset = 7,                                                     \
        .trainerScale = 256,                                                    \
        .trainerOffset = 0,                                                     \
        FRONT_PIC(Florges, 64, 64),                                             \
        .frontPicYOffset = 0,                                                   \
        .frontAnimFrames = sAnims_Florges,                                      \
        .frontAnimId = ANIM_V_SLIDE_SLOW,                                       \
        BACK_PIC(Florges, 64, 48),                                              \
        .backPicYOffset = 9,                                                    \
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,                            \
        PALETTES(Florges##Form##Flower),                                         \
        ICON(Florges##Form##Flower, iconPal),                                   \
        .footprint = gMonFootprint_Florges,                                     \
        LEARNSETS(Florges),                                                     \
        .formSpeciesIdTable = sFlorgesFormSpeciesIdTable

    [SPECIES_FLORGES_RED_FLOWER] =
    {
        FLORGES_MISC_INFO(Red, 0),
        .description = POKEDEX_DESC_STRING(
            "Wunderschöne Blumengärten sind sein\n"
            "Revier. Es badet in der von\n"
            "blühenden Blumen freigesetzten\n"
            "Energie und zieht daraus seine\n"
            "Kraft."),
    },
    [SPECIES_FLORGES_YELLOW_FLOWER] =
    {
        FLORGES_MISC_INFO(Yellow, 1),
        .description = POKEDEX_DESC_STRING(
            "Wunderschöne Blumengärten sind sein\n"
            "Revier. Es badet in der von\n"
            "blühenden Blumen freigesetzten\n"
            "Energie und zieht daraus seine\n"
            "Kraft."),
    },
    [SPECIES_FLORGES_ORANGE_FLOWER] =
    {
        FLORGES_MISC_INFO(Orange, 0),
        .description = POKEDEX_DESC_STRING(
            "Wunderschöne Blumengärten sind sein\n"
            "Revier. Es badet in der von\n"
            "blühenden Blumen freigesetzten\n"
            "Energie und zieht daraus seine\n"
            "Kraft."),
    },
    [SPECIES_FLORGES_BLUE_FLOWER] =
    {
        FLORGES_MISC_INFO(Blue, 0),
        .description = POKEDEX_DESC_STRING(
            "Wunderschöne Blumengärten sind sein\n"
            "Revier. Es badet in der von\n"
            "blühenden Blumen freigesetzten\n"
            "Energie und zieht daraus seine\n"
            "Kraft."),
    },
    [SPECIES_FLORGES_WHITE_FLOWER] =
    {
        FLORGES_MISC_INFO(White, 0),
        .description = POKEDEX_DESC_STRING(
            "Wunderschöne Blumengärten sind sein\n"
            "Revier. Es badet in der von\n"
            "blühenden Blumen freigesetzten\n"
            "Energie und zieht daraus seine\n"
            "Kraft."),
    },
#endif //P_FAMILY_FLABEBE

#if P_FAMILY_SKIDDO
    [SPECIES_SKIDDO] =
    {
        .baseHP        = 66,
        .baseAttack    = 65,
        .baseDefense   = 48,
        .baseSpeed     = 52,
        .baseSpAttack  = 62,
        .baseSpDefense = 57,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 200,
        .expYield = 70,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SAP_SIPPER, ABILITY_NONE, ABILITY_GRASS_PELT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Mähikel"),
        .cryId = CRY_SKIDDO,
        .natDexNum = NATIONAL_DEX_SKIDDO,
        .categoryName = _("Ritt"),
        .height = 9,
        .weight = 310,
        .description = POKEDEX_DESC_STRING(
            "Man sagt, es sei eines der ersten\n"
            "Pokémon, die mit Menschen\n"
            "zusammengelebt haben. Es ist sehr\n"
            "ruhig und friedfertig."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Skiddo, 48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Skiddo,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Skiddo, 56, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Skiddo),
        ICON(Skiddo, 1),
        .footprint = gMonFootprint_Skiddo,
        LEARNSETS(Skiddo),
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_GOGOAT}),
    },

    [SPECIES_GOGOAT] =
    {
        .baseHP        = 123,
        .baseAttack    = 100,
        .baseDefense   = 62,
        .baseSpeed     = 68,
        .baseSpAttack  = 97,
        .baseSpDefense = 81,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 186,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SAP_SIPPER, ABILITY_NONE, ABILITY_GRASS_PELT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Chevrumm"),
        .cryId = CRY_GOGOAT,
        .natDexNum = NATIONAL_DEX_GOGOAT,
        .categoryName = _("Ritt"),
        .height = 17,
        .weight = 910,
        .description = POKEDEX_DESC_STRING(
            "Es kann die Stimmung seines\n"
            "Trainers an der kleinsten\n"
            "Veränderung dessen Griffes um seine\n"
            "Hörner ablesen und galoppiert\n"
            "sofort los, wenn dieser es wünscht."),
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 1,
        FRONT_PIC(Gogoat, 56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Gogoat,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Gogoat, 64, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Gogoat),
        ICON(Gogoat, 1),
        .footprint = gMonFootprint_Gogoat,
        LEARNSETS(Gogoat),
    },
#endif //P_FAMILY_SKIDDO

#if P_FAMILY_PANCHAM
    [SPECIES_PANCHAM] =
    {
        .baseHP        = 67,
        .baseAttack    = 82,
        .baseDefense   = 62,
        .baseSpeed     = 43,
        .baseSpAttack  = 46,
        .baseSpDefense = 48,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 220,
        .expYield = 70,
        .evYield_Attack = 1,
        .itemRare = ITEM_MENTAL_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_IRON_FIST, ABILITY_MOLD_BREAKER, ABILITY_SCRAPPY },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Pam-Pam"),
        .cryId = CRY_PANCHAM,
        .natDexNum = NATIONAL_DEX_PANCHAM,
        .categoryName = _("Verspielt"),
        .height = 6,
        .weight = 80,
        .description = POKEDEX_DESC_STRING(
            "Pandagro ist sein großes Vorbild, das es\n"
            "stets nachahmt. Dabei ist es so eifrig,\n"
            "dass es daran wächst."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pancham, 32, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Pancham,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Pancham, 48, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,
        PALETTES(Pancham),
        ICON(Pancham, 1),
        .footprint = gMonFootprint_Pancham,
        LEARNSETS(Pancham),
        .evolutions = EVOLUTION({EVO_LEVEL_DARK_TYPE_MON_IN_PARTY, 32, SPECIES_PANGORO}),
    },

    [SPECIES_PANGORO] =
    {
        .baseHP        = 95,
        .baseAttack    = 124,
        .baseDefense   = 78,
        .baseSpeed     = 58,
        .baseSpAttack  = 69,
        .baseSpDefense = 71,
        .types = { TYPE_FIGHTING, TYPE_DARK },
        .catchRate = 65,
        .expYield = 173,
        .evYield_Attack = 2,
        .itemRare = ITEM_MENTAL_HERB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_IRON_FIST, ABILITY_MOLD_BREAKER, ABILITY_SCRAPPY },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Pandagro"),
        .cryId = CRY_PANGORO,
        .natDexNum = NATIONAL_DEX_PANGORO,
        .categoryName = _("Gaunerblick"),
        .height = 21,
        .weight = 1360,
        .description = POKEDEX_DESC_STRING(
            "Dieses aggressive Pokémon bringt Gegner\n"
            "mit seiner Muskelkraft zum Verstummen. Es\n"
            "liebt Kämpfe gegen Barrikadax."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        FRONT_PIC(Pangoro, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Pangoro,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        BACK_PIC(Pangoro, 64, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Pangoro),
        ICON(Pangoro, 1),
        .footprint = gMonFootprint_Pangoro,
        LEARNSETS(Pangoro),
    },
#endif //P_FAMILY_PANCHAM

#if P_FAMILY_FURFROU
#define FURFROU_MISC_INFO                                   \
        .baseHP        = 75,                                \
        .baseAttack    = 80,                                \
        .baseDefense   = 60,                                \
        .baseSpeed     = 102,                               \
        .baseSpAttack  = 65,                                \
        .baseSpDefense = 90,                                \
        .types = { TYPE_NORMAL, TYPE_NORMAL },              \
        .catchRate = 160,                                   \
        .expYield = 165,                                    \
        .evYield_Speed = 1,                                 \
        .genderRatio = PERCENT_FEMALE(50),                  \
        .eggCycles = 20,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_MEDIUM_FAST,                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },  \
        .abilities = { ABILITY_FUR_COAT, ABILITY_NONE },    \
        .bodyColor = BODY_COLOR_WHITE,                      \
        .speciesName = _("Pandagro"),                        \
        .cryId = CRY_FURFROU,                               \
        .natDexNum = NATIONAL_DEX_FURFROU,                  \
        .categoryName = _("Gaunerblick"),                        \
        .height = 12,                                       \
        .weight = 280,                                      \
        .description = gFurfrouPokedexText,                 \
        .pokemonScale = 282,                                \
        .pokemonOffset = 4,                                 \
        .trainerScale = 256,                                \
        .trainerOffset = 0,                                 \
        .frontAnimFrames = sAnims_Furfrou,                  \
        .frontAnimId = ANIM_H_SLIDE,                        \
        .backAnimId = BACK_ANIM_V_STRETCH,                  \
        .footprint = gMonFootprint_Furfrou,                 \
        LEARNSETS(Furfrou),                                 \
        .formSpeciesIdTable = sFurfrouFormSpeciesIdTable

    [SPECIES_FURFROU_NATURAL] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouNatural, 48, 64),
        .frontPicYOffset = 3,
        BACK_PIC(FurfrouNatural, 56, 64),
        .backPicYOffset = 0,
        PALETTES(FurfrouNatural),
        ICON(FurfrouNatural, 0),
    },
    [SPECIES_FURFROU_HEART_TRIM] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouHeartTrim, 56, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouHeartTrim, 56, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouHeartTrim),
        ICON(FurfrouHeartTrim, 0),
    },
    [SPECIES_FURFROU_STAR_TRIM] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouStarTrim, 56, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouStarTrim, 64, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouStarTrim),
        ICON(FurfrouStarTrim, 0),
    },
    [SPECIES_FURFROU_DIAMOND_TRIM] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouDiamondTrim, 48, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouDiamondTrim, 56, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouDiamondTrim),
        ICON(FurfrouDiamondTrim, 0),
    },
    [SPECIES_FURFROU_DEBUTANTE_TRIM] =
    {
        FURFROU_MISC_INFO,
        .noFlip = TRUE,
        FRONT_PIC(FurfrouDebutanteTrim, 48, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouDebutanteTrim, 56, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouDebutanteTrim),
        ICON(FurfrouDebutanteTrim, 2),
    },
    [SPECIES_FURFROU_MATRON_TRIM] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouMatronTrim, 48, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouMatronTrim, 56, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouMatronTrim),
        ICON(FurfrouMatronTrim, 2),
    },
    [SPECIES_FURFROU_DANDY_TRIM] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouDandyTrim, 48, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouDandyTrim, 56, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouDandyTrim),
        ICON(FurfrouDandyTrim, 1),
    },
    [SPECIES_FURFROU_LA_REINE_TRIM] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouLaReineTrim, 48, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouLaReineTrim, 56, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouLaReineTrim),
        ICON(FurfrouLaReineTrim, 0),
    },
    [SPECIES_FURFROU_KABUKI_TRIM] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouKabukiTrim, 56, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouKabukiTrim, 56, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouKabukiTrim),
        ICON(FurfrouKabukiTrim, 0),
    },
    [SPECIES_FURFROU_PHARAOH_TRIM] =
    {
        FURFROU_MISC_INFO,
        FRONT_PIC(FurfrouPharaohTrim, 48, 64),
        .frontPicYOffset = 2,
        BACK_PIC(FurfrouPharaohTrim, 56, 64),
        .backPicYOffset = 1,
        PALETTES(FurfrouPharaohTrim),
        ICON(FurfrouPharaohTrim, 0),
    },
#endif //P_FAMILY_FURFROU

#if P_FAMILY_ESPURR
    [SPECIES_ESPURR] =
    {
        .baseHP        = 62,
        .baseAttack    = 48,
        .baseDefense   = 54,
        .baseSpeed     = 68,
        .baseSpAttack  = 63,
        .baseSpDefense = 60,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 190,
        .expYield = 71,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_INFILTRATOR, ABILITY_OWN_TEMPO },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Psiau"),
        .cryId = CRY_ESPURR,
        .natDexNum = NATIONAL_DEX_ESPURR,
        .categoryName = _("Zügelungs"),
        .height = 3,
        .weight = 35,
        .description = POKEDEX_DESC_STRING(
            "Damit die starken Psycho-Kräfte\n"
            "dieses Pokémon nicht unkontrolliert\n"
            "nach außen dringen, ist das Organ,\n"
            "das diese freisetzt, von seinen\n"
            "Ohren bedeckt."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Espurr, 32, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Espurr,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Espurr, 56, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Espurr),
        ICON(Espurr, 2),
        .footprint = gMonFootprint_Espurr,
        LEARNSETS(Espurr),
        .evolutions = EVOLUTION({EVO_LEVEL_MALE, 25, SPECIES_MEOWSTIC_MALE},
                                {EVO_LEVEL_FEMALE, 25, SPECIES_MEOWSTIC_FEMALE}),
    },

#define MEOWSTIC_MISC_INFO                                  \
        .baseHP        = 74,                                \
        .baseAttack    = 48,                                \
        .baseDefense   = 76,                                \
        .baseSpeed     = 104,                               \
        .baseSpAttack  = 83,                                \
        .baseSpDefense = 81,                                \
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },            \
        .catchRate = 75,                                    \
        .expYield = 163,                                    \
        .evYield_Speed = 2,                                 \
        .eggCycles = 20,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_MEDIUM_FAST,                   \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },  \
        .speciesName = _("Psiau"),                       \
        .cryId = CRY_MEOWSTIC,                              \
        .natDexNum = NATIONAL_DEX_MEOWSTIC,                 \
        .categoryName = _("Zügelungs"),                    \
        .height = 6,                                        \
        .weight = 85,                                       \
        .pokemonScale = 422,                                \
        .pokemonOffset = 12,                                \
        .trainerScale = 256,                                \
        .trainerOffset = 0,                                 \
        .frontAnimFrames = sAnims_Meowstic,                 \
        .frontAnimId = ANIM_GROW_VIBRATE,                   \
        .backPicYOffset = 9,                                \
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,          \
        .footprint = gMonFootprint_Meowstic,                \
        .formSpeciesIdTable = sMeowsticFormSpeciesIdTable

    [SPECIES_MEOWSTIC_MALE] =
    {
        MEOWSTIC_MISC_INFO,
        .genderRatio = MON_MALE,
        .abilities = { ABILITY_KEEN_EYE, ABILITY_INFILTRATOR, ABILITY_PRANKSTER },
        .bodyColor = BODY_COLOR_BLUE,
        .description = POKEDEX_DESC_STRING(
            "In Gefahrensituationen hebt es\n"
            "seine Ohren an und setzt Psycho-\n"
            "Kräfte frei, die einen 10 t\n"
            "schweren LKW zu Schrott verarbeiten\n"
            "können."),
        FRONT_PIC(MeowsticMale, 48, 64),
        .frontPicYOffset = 3,
        BACK_PIC(MeowsticMale, 64, 64),
        PALETTES(MeowsticMale),
        ICON(MeowsticMale, 0),
        LEARNSETS(MeowsticMale),
    },

    [SPECIES_MEOWSTIC_FEMALE] =
    {
        MEOWSTIC_MISC_INFO,
        .genderRatio = MON_FEMALE,
        .abilities = { ABILITY_KEEN_EYE, ABILITY_INFILTRATOR, ABILITY_COMPETITIVE },
        .bodyColor = BODY_COLOR_WHITE,
        .description = POKEDEX_DESC_STRING(
            "In Gefahrensituationen hebt es\n"
            "seine Ohren an und setzt Psycho-\n"
            "Kräfte frei, die einen 10 t\n"
            "schweren LKW zu Schrott verarbeiten\n"
            "können."),
        FRONT_PIC(MeowsticFemale, 56, 64),
        .frontPicYOffset = 2,
        BACK_PIC(MeowsticFemale, 48, 64),
        PALETTES(MeowsticFemale),
        ICON(MeowsticFemale, 0),
        LEARNSETS(MeowsticFemale),
    },
#endif //P_FAMILY_ESPURR

#if P_FAMILY_HONEDGE
    [SPECIES_HONEDGE] =
    {
        .baseHP        = 45,
        .baseAttack    = 80,
        .baseDefense   = 100,
        .baseSpeed     = 28,
        .baseSpAttack  = 35,
        .baseSpDefense = 37,
        .types = { TYPE_STEEL, TYPE_GHOST },
        .catchRate = 180,
        .expYield = 65,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_NO_GUARD, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Gramokles"),
        .cryId = CRY_HONEDGE,
        .natDexNum = NATIONAL_DEX_HONEDGE,
        .categoryName = _("Klingenkraft"),
        .height = 8,
        .weight = 20,
        .description = POKEDEX_DESC_STRING(
            "Seine Seele ist die eines Menschen, der\n"
            "vor langer Zeit durch dieses Schwert\n"
            "getötet wurde."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Honedge, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Honedge,
        .frontAnimId = ANIM_SWING_CONVEX,
        .enemyMonElevation = 4,
        BACK_PIC(Honedge, 48, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Honedge),
        ICON(Honedge, 2),
        .footprint = gMonFootprint_Honedge,
        LEARNSETS(Honedge),
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_DOUBLADE}),
    },

    [SPECIES_DOUBLADE] =
    {
        .baseHP        = 59,
        .baseAttack    = 110,
        .baseDefense   = 150,
        .baseSpeed     = 35,
        .baseSpAttack  = 45,
        .baseSpDefense = 49,
        .types = { TYPE_STEEL, TYPE_GHOST },
        .catchRate = 90,
        .expYield = 157,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_NO_GUARD, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Duokles"),
        .cryId = CRY_DOUBLADE,
        .natDexNum = NATIONAL_DEX_DOUBLADE,
        .categoryName = _("Klingenkraft"),
        .height = 8,
        .weight = 45,
        .description = POKEDEX_DESC_STRING(
            "Seine zwei Schwerter wechseln sich in\n"
            "einer hektischen Aufeinanderfolge von\n"
            "Angriff und Verteidigung ab, um seine\n"
            "Beute zu erlegen."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Doublade, 64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Doublade,
        .frontAnimId = ANIM_GROW_VIBRATE,
        .enemyMonElevation = 5,
        BACK_PIC(Doublade, 64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Doublade),
        ICON(Doublade, 2),
        .footprint = gMonFootprint_Doublade,
        LEARNSETS(Doublade),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_DUSK_STONE, SPECIES_AEGISLASH_SHIELD}),
    },

#define AEGISLASH_MISC_INFO                                     \
        .types = { TYPE_STEEL, TYPE_GHOST },                    \
        .catchRate = 45,                                        \
        .expYield = 234,                                        \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 20,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_MEDIUM_FAST,                       \
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },  \
        .abilities = { ABILITY_STANCE_CHANGE, ABILITY_NONE },   \
        .bodyColor = BODY_COLOR_BROWN,                          \
        .speciesName = _("Duokles"),                          \
        .cryId = CRY_AEGISLASH,                                 \
        .natDexNum = NATIONAL_DEX_AEGISLASH,                    \
        .categoryName = _("Klingenkraft"),                       \
        .height = 17,                                           \
        .weight = 530,                                          \
        .pokemonScale = 259,                                    \
        .pokemonOffset = 0,                                     \
        .trainerScale = 290,                                    \
        .trainerOffset = 1,                                     \
        .footprint = gMonFootprint_Aegislash,                   \
        LEARNSETS(Aegislash),                                   \
        .formSpeciesIdTable = sAegislashFormSpeciesIdTable,     \
        .formChangeTable = sAegislashFormChangeTable

#define AEGISLASH_MAIN_STAT (P_UPDATED_STATS >= GEN_8 ? 140 : 150)

    [SPECIES_AEGISLASH_SHIELD] =
    {
        AEGISLASH_MISC_INFO,
        .baseHP        = 60,
        .baseAttack    = 50,
        .baseDefense   = AEGISLASH_MAIN_STAT,
        .baseSpeed     = 60,
        .baseSpAttack  = 50,
        .baseSpDefense = AEGISLASH_MAIN_STAT,
        .evYield_Defense = 2,
        .evYield_SpDefense = 1,
        .description = POKEDEX_DESC_STRING(
            "Generationen von Königen hatten\n"
            "dieses Pokémon an ihrer Seite. Mit\n"
            "seiner mysteriösen Kraft kann es\n"
            "Menschen und Pokémon gleichermaßen\n"
            "kontrollieren."),
        FRONT_PIC(AegislashShield, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_AegislashShield,
        .frontAnimId = ANIM_H_VIBRATE,
        .enemyMonElevation = 3,
        BACK_PIC(AegislashShield, 64, 64),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(AegislashShield),
        ICON(AegislashShield, 2),
    },

    [SPECIES_AEGISLASH_BLADE] =
    {
        AEGISLASH_MISC_INFO,
        .baseHP        = 60,
        .baseAttack    = AEGISLASH_MAIN_STAT,
        .baseDefense   = 50,
        .baseSpeed     = 60,
        .baseSpAttack  = AEGISLASH_MAIN_STAT,
        .baseSpDefense = 50,
        .evYield_Attack = 2,
        .evYield_SpAttack = 1,
        .description = POKEDEX_DESC_STRING(
            "Generationen von Königen hatten\n"
            "dieses Pokémon an ihrer Seite. Mit\n"
            "seiner mysteriösen Kraft kann es\n"
            "Menschen und Pokémon gleichermaßen\n"
            "kontrollieren."),
        FRONT_PIC(AegislashBlade, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_AegislashBlade,
        .frontAnimId = ANIM_CIRCLE_C_CLOCKWISE_SLOW,
        .enemyMonElevation = 3,
        BACK_PIC(AegislashBlade, 64, 64),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(AegislashBlade),
        ICON(AegislashBlade, 2),
    },
#endif //P_FAMILY_HONEDGE

#if P_FAMILY_SPRITZEE
    [SPECIES_SPRITZEE] =
    {
        .baseHP        = 78,
        .baseAttack    = 52,
        .baseDefense   = 60,
        .baseSpeed     = 23,
        .baseSpAttack  = 63,
        .baseSpDefense = 65,
        .types = { TYPE_FAIRY, TYPE_FAIRY },
        .catchRate = 200,
        .expYield = 68,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_HEALER, ABILITY_NONE, ABILITY_AROMA_VEIL },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Parfi"),
        .cryId = CRY_SPRITZEE,
        .natDexNum = NATIONAL_DEX_SPRITZEE,
        .categoryName = _("Parfüm"),
        .height = 2,
        .weight = 5,
        .description = POKEDEX_DESC_STRING(
            "Der von ihm verströmte Duft\n"
            "verzückt jeden, der ihn riecht. Je\n"
            "nachdem, was es frisst, ändert sich\n"
            "sein Duft."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Spritzee, 48, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Spritzee,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 14,
        BACK_PIC(Spritzee, 56, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Spritzee),
        ICON(Spritzee, 0),
        .footprint = gMonFootprint_Spritzee,
        LEARNSETS(Spritzee),
        .evolutions = EVOLUTION({EVO_TRADE_ITEM, ITEM_SACHET, SPECIES_AROMATISSE},
                                {EVO_ITEM, ITEM_SACHET, SPECIES_AROMATISSE}),
    },

    [SPECIES_AROMATISSE] =
    {
        .baseHP        = 101,
        .baseAttack    = 72,
        .baseDefense   = 72,
        .baseSpeed     = 29,
        .baseSpAttack  = 99,
        .baseSpDefense = 89,
        .types = { TYPE_FAIRY, TYPE_FAIRY },
        .catchRate = 140,
        .expYield = 162,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_HEALER, ABILITY_NONE, ABILITY_AROMA_VEIL },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Parfinesse"),
        .cryId = CRY_AROMATISSE,
        .natDexNum = NATIONAL_DEX_AROMATISSE,
        .categoryName = _("Duft"),
        .height = 8,
        .weight = 155,
        .description = POKEDEX_DESC_STRING(
            "Sein Duft ist so stark, dass es für einen\n"
            "Trainer, der seinen Duft nicht mag, schwer\n"
            "ist, es an seiner Seite zu haben."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Aromatisse, 48, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Aromatisse,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Aromatisse, 64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Aromatisse),
        ICON(Aromatisse, 0),
        .footprint = gMonFootprint_Aromatisse,
        LEARNSETS(Aromatisse),
    },
#endif //P_FAMILY_SPRITZEE

#if P_FAMILY_SWIRLIX
    [SPECIES_SWIRLIX] =
    {
        .baseHP        = 62,
        .baseAttack    = 48,
        .baseDefense   = 66,
        .baseSpeed     = 49,
        .baseSpAttack  = 59,
        .baseSpDefense = 57,
        .types = { TYPE_FAIRY, TYPE_FAIRY },
        .catchRate = 200,
        .expYield = 68,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_SWEET_VEIL, ABILITY_NONE, ABILITY_UNBURDEN },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Flauschling"),
        .cryId = CRY_SWIRLIX,
        .natDexNum = NATIONAL_DEX_SWIRLIX,
        .categoryName = _("Zuckerwatte"),
        .height = 4,
        .weight = 35,
        .description = POKEDEX_DESC_STRING(
            "Es frisst nur Süßigkeiten, weshalb sein\n"
            "Fell so süß und klebrig wie Zuckerwatte\n"
            "ist."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Swirlix, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Swirlix,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(Swirlix, 56, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_H_SPRING,
        PALETTES(Swirlix),
        ICON(Swirlix, 1),
        .footprint = gMonFootprint_Swirlix,
        LEARNSETS(Swirlix),
        .evolutions = EVOLUTION({EVO_TRADE_ITEM, ITEM_WHIPPED_DREAM, SPECIES_SLURPUFF},
                                {EVO_ITEM, ITEM_WHIPPED_DREAM, SPECIES_SLURPUFF}),
    },

    [SPECIES_SLURPUFF] =
    {
        .baseHP        = 82,
        .baseAttack    = 80,
        .baseDefense   = 86,
        .baseSpeed     = 72,
        .baseSpAttack  = 85,
        .baseSpDefense = 75,
        .types = { TYPE_FAIRY, TYPE_FAIRY },
        .catchRate = 140,
        .expYield = 168,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_SWEET_VEIL, ABILITY_NONE, ABILITY_UNBURDEN },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Sabbaione"),
        .cryId = CRY_SLURPUFF,
        .natDexNum = NATIONAL_DEX_SLURPUFF,
        .categoryName = _("Schlagsahne"),
        .height = 8,
        .weight = 50,
        .description = POKEDEX_DESC_STRING(
            "Es kann die körperliche und seelische\n"
            "Verfassung anderer anhand ihres\n"
            "Körpergeruchs erkennen. Dies versucht man\n"
            "für die Medizin zu nutzen."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Slurpuff, 48, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Slurpuff,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Slurpuff, 64, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Slurpuff),
        ICON(Slurpuff, 1),
        .footprint = gMonFootprint_Slurpuff,
        LEARNSETS(Slurpuff),
    },
#endif //P_FAMILY_SWIRLIX

#if P_FAMILY_INKAY
    [SPECIES_INKAY] =
    {
        .baseHP        = 53,
        .baseAttack    = 54,
        .baseDefense   = 53,
        .baseSpeed     = 45,
        .baseSpAttack  = 37,
        .baseSpDefense = 46,
        .types = { TYPE_DARK, TYPE_PSYCHIC },
        .catchRate = 190,
        .expYield = 58,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_2 },
        .abilities = { ABILITY_CONTRARY, ABILITY_SUCTION_CUPS, ABILITY_INFILTRATOR },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Iscalar"),
        .cryId = CRY_INKAY,
        .natDexNum = NATIONAL_DEX_INKAY,
        .categoryName = _("Rotations"),
        .height = 4,
        .weight = 35,
        .description = POKEDEX_DESC_STRING(
            "Gegner, die auf die blinkenden\n"
            "Punkte an seinem Körper blicken,\n"
            "werden geblendet und verlieren den\n"
            "Willen zu kämpfen."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Inkay, 48, 48),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Inkay,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 14,
        BACK_PIC(Inkay, 56, 64),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Inkay),
        ICON(Inkay, 0),
        .footprint = gMonFootprint_Inkay,
        LEARNSETS(Inkay),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_MALAMAR}),
    },

    [SPECIES_MALAMAR] =
    {
        .baseHP        = 86,
        .baseAttack    = 92,
        .baseDefense   = 88,
        .baseSpeed     = 73,
        .baseSpAttack  = 68,
        .baseSpDefense = 75,
        .types = { TYPE_DARK, TYPE_PSYCHIC },
        .catchRate = 80,
        .expYield = 169,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_2 },
        .abilities = { ABILITY_CONTRARY, ABILITY_SUCTION_CUPS, ABILITY_INFILTRATOR },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Calamanero"),
        .cryId = CRY_MALAMAR,
        .natDexNum = NATIONAL_DEX_MALAMAR,
        .categoryName = _("Inversions"),
        .height = 15,
        .weight = 470,
        .description = POKEDEX_DESC_STRING(
            "Man erzählt sich, dass die hypnotischen\n"
            "Kräfte dieses Pokémon mit einigen\n"
            "geschichtsträchtigen Ereignissen in\n"
            "Verbindung stehen."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Malamar, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Malamar,
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        BACK_PIC(Malamar, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Malamar),
        ICON(Malamar, 2),
        .footprint = gMonFootprint_Malamar,
        LEARNSETS(Malamar),
    },
#endif //P_FAMILY_INKAY

#if P_FAMILY_BINACLE
    [SPECIES_BINACLE] =
    {
        .baseHP        = 42,
        .baseAttack    = 52,
        .baseDefense   = 67,
        .baseSpeed     = 50,
        .baseSpAttack  = 39,
        .baseSpDefense = 56,
        .types = { TYPE_ROCK, TYPE_WATER },
        .catchRate = 120,
        .expYield = 61,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_3, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_TOUGH_CLAWS, ABILITY_SNIPER, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Bithora"),
        .cryId = CRY_BINACLE,
        .natDexNum = NATIONAL_DEX_BINACLE,
        .categoryName = _("Krallenduo"),
        .height = 5,
        .weight = 310,
        .description = POKEDEX_DESC_STRING(
            "Bithora bewohnen jeweils zu zweit\n"
            "einen Felsen. Entzweien sie sich im\n"
            "Streit, sucht sich eines der beiden\n"
            "einen neuen Felsen als Unterkunft."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Binacle, 48, 56),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Binacle,
        .frontAnimId = ANIM_H_SLIDE,
        BACK_PIC(Binacle, 64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Binacle),
        ICON(Binacle, 2),
        .footprint = gMonFootprint_Binacle,
        LEARNSETS(Binacle),
        .evolutions = EVOLUTION({EVO_LEVEL, 39, SPECIES_BARBARACLE}),
    },

    [SPECIES_BARBARACLE] =
    {
        .baseHP        = 72,
        .baseAttack    = 105,
        .baseDefense   = 115,
        .baseSpeed     = 68,
        .baseSpAttack  = 54,
        .baseSpDefense = 86,
        .types = { TYPE_ROCK, TYPE_WATER },
        .catchRate = 45,
        .expYield = 175,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_3, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_TOUGH_CLAWS, ABILITY_SNIPER, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Thanathora"),
        .cryId = CRY_BARBARACLE,
        .natDexNum = NATIONAL_DEX_BARBARACLE,
        .categoryName = _("Ballungs"),
        .height = 13,
        .weight = 960,
        .description = POKEDEX_DESC_STRING(
            "Sein Körper besteht aus sieben\n"
            "verschiedenen Bithora, wobei der Kopf das\n"
            "Sagen über die anderen Gliedmaßen hat."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Barbaracle, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Barbaracle,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Barbaracle, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Barbaracle),
        ICON(Barbaracle, 2),
        .footprint = gMonFootprint_Barbaracle,
        LEARNSETS(Barbaracle),
    },
#endif //P_FAMILY_BINACLE

#if P_FAMILY_SKRELP
    [SPECIES_SKRELP] =
    {
        .baseHP        = 50,
        .baseAttack    = 60,
        .baseDefense   = 60,
        .baseSpeed     = 30,
        .baseSpAttack  = 60,
        .baseSpDefense = 60,
        .types = { TYPE_POISON, TYPE_WATER },
        .catchRate = 225,
        .expYield = 64,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_POISON_POINT, ABILITY_POISON_TOUCH, ABILITY_ADAPTABILITY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Algitt"),
        .cryId = CRY_SKRELP,
        .natDexNum = NATIONAL_DEX_SKRELP,
        .categoryName = _("Tangmimikry"),
        .height = 5,
        .weight = 73,
        .description = POKEDEX_DESC_STRING(
            "Da es wie verfaulter Seetang aussieht,\n"
            "versteckt es sich zwischen den im Meer\n"
            "treibenden Algen, um sich den Blicken\n"
            "seiner Feinde zu entziehen."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Skrelp, 40, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Skrelp,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        BACK_PIC(Skrelp, 64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Skrelp),
        ICON(Skrelp, 2),
        .footprint = gMonFootprint_Skrelp,
        LEARNSETS(Skrelp),
        .evolutions = EVOLUTION({EVO_LEVEL, 48, SPECIES_DRAGALGE}),
    },

    [SPECIES_DRAGALGE] =
    {
        .baseHP        = 65,
        .baseAttack    = 75,
        .baseDefense   = 90,
        .baseSpeed     = 44,
        .baseSpAttack  = 97,
        .baseSpDefense = 123,
        .types = { TYPE_POISON, TYPE_DRAGON },
        .catchRate = 55,
        .expYield = 173,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_POISON_POINT, ABILITY_POISON_TOUCH, ABILITY_ADAPTABILITY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Tandrak"),
        .cryId = CRY_DRAGALGE,
        .natDexNum = NATIONAL_DEX_DRAGALGE,
        .categoryName = _("Tangmimikry"),
        .height = 18,
        .weight = 815,
        .description = POKEDEX_DESC_STRING(
            "Dringen Tankschiffe in sein Revier ein,\n"
            "versenkt es diese mithilfe eines Giftes,\n"
            "das selbst Metall zum Korrodieren bringt."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Dragalge, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Dragalge,
        .frontAnimId = ANIM_FRONT_FLIP,
        BACK_PIC(Dragalge, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Dragalge),
        ICON(Dragalge, 5),
        .footprint = gMonFootprint_Dragalge,
        LEARNSETS(Dragalge),
    },
#endif //P_FAMILY_SKRELP

#if P_FAMILY_CLAUNCHER
    [SPECIES_CLAUNCHER] =
    {
        .baseHP        = 50,
        .baseAttack    = 53,
        .baseDefense   = 62,
        .baseSpeed     = 44,
        .baseSpAttack  = 58,
        .baseSpDefense = 63,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 225,
        .expYield = 66,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_MEGA_LAUNCHER, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
        .speciesName = _("Scampisto"),
        .cryId = CRY_CLAUNCHER,
        .natDexNum = NATIONAL_DEX_CLAUNCHER,
        .categoryName = _("Aquapistolen"),
        .height = 5,
        .weight = 83,
        .description = POKEDEX_DESC_STRING(
            "Mit Salven komprimierten Wassers,\n"
            "die es wie Pistolenkugeln aus\n"
            "seinen Scheren abfeuert, schießt es\n"
            "fliegende Beute ab."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Clauncher, 56, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Clauncher,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        BACK_PIC(Clauncher, 64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Clauncher),
        ICON(Clauncher, 0),
        .footprint = gMonFootprint_Clauncher,
        LEARNSETS(Clauncher),
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_CLAWITZER}),
    },

    [SPECIES_CLAWITZER] =
    {
        .baseHP        = 71,
        .baseAttack    = 73,
        .baseDefense   = 88,
        .baseSpeed     = 59,
        .baseSpAttack  = 120,
        .baseSpDefense = 89,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 55,
        .expYield = 100,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_MEGA_LAUNCHER, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .noFlip = TRUE,
        .speciesName = _("Wummer"),
        .cryId = CRY_CLAWITZER,
        .natDexNum = NATIONAL_DEX_CLAWITZER,
        .categoryName = _("Aquawummen"),
        .height = 13,
        .weight = 353,
        .description = POKEDEX_DESC_STRING(
            "Aus seinen gewaltigen Scheren\n"
            "feuert es mächtige Wassergeschosse\n"
            "ab, die selbst den Rumpf eines\n"
            "Tankschiffes durchdringen."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Clawitzer, 64, 64),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Clawitzer,
        .frontAnimId = ANIM_CIRCLE_C_CLOCKWISE_SLOW,
        BACK_PIC(Clawitzer, 64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Clawitzer),
        ICON(Clawitzer, 0),
        .footprint = gMonFootprint_Clawitzer,
        LEARNSETS(Clawitzer),
    },
#endif //P_FAMILY_CLAUNCHER

#if P_FAMILY_HELIOPTILE
    [SPECIES_HELIOPTILE] =
    {
        .baseHP        = 44,
        .baseAttack    = 38,
        .baseDefense   = 33,
        .baseSpeed     = 70,
        .baseSpAttack  = 61,
        .baseSpDefense = 43,
        .types = { TYPE_ELECTRIC, TYPE_NORMAL },
        .catchRate = 190,
        .expYield = 58,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_DRY_SKIN, ABILITY_SAND_VEIL, ABILITY_SOLAR_POWER },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Eguana"),
        .cryId = CRY_HELIOPTILE,
        .natDexNum = NATIONAL_DEX_HELIOPTILE,
        .categoryName = _("Generatoren"),
        .height = 5,
        .weight = 60,
        .description = POKEDEX_DESC_STRING(
            "Es ist in der Wüste zu Hause und\n"
            "wandelt die Energie der Sonne in\n"
            "Körperkraft um, wodurch es auch\n"
            "ohne Nahrung auskommt."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Helioptile, 40, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Helioptile,
        .frontAnimId = ANIM_GLOW_YELLOW,
        BACK_PIC(Helioptile, 64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Helioptile),
        ICON(Helioptile, 2),
        .footprint = gMonFootprint_Helioptile,
        LEARNSETS(Helioptile),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_SUN_STONE, SPECIES_HELIOLISK}),
    },

    [SPECIES_HELIOLISK] =
    {
        .baseHP        = 62,
        .baseAttack    = 55,
        .baseDefense   = 52,
        .baseSpeed     = 109,
        .baseSpAttack  = 109,
        .baseSpDefense = 94,
        .types = { TYPE_ELECTRIC, TYPE_NORMAL },
        .catchRate = 75,
        .expYield = 168,
        .evYield_Speed = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_DRY_SKIN, ABILITY_SAND_VEIL, ABILITY_SOLAR_POWER },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Elezard"),
        .cryId = CRY_HELIOLISK,
        .natDexNum = NATIONAL_DEX_HELIOLISK,
        .categoryName = _("Generatoren"),
        .height = 10,
        .weight = 210,
        .description = POKEDEX_DESC_STRING(
            "Es stimuliert seine Beinmuskulatur mit\n"
            "Strom, wodurch es ihm gelingt, 100 m in\n"
            "fünf Sekunden zurückzulegen."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Heliolisk, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Heliolisk,
        .frontAnimId = ANIM_RAPID_H_HOPS,
        BACK_PIC(Heliolisk, 56, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(Heliolisk),
        ICON(Heliolisk, 2),
        .footprint = gMonFootprint_Heliolisk,
        LEARNSETS(Heliolisk),
    },
#endif //P_FAMILY_HELIOPTILE

#if P_FAMILY_TYRUNT
    [SPECIES_TYRUNT] =
    {
        .baseHP        = 58,
        .baseAttack    = 89,
        .baseDefense   = 77,
        .baseSpeed     = 48,
        .baseSpAttack  = 45,
        .baseSpDefense = 45,
        .types = { TYPE_ROCK, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 72,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_STRONG_JAW, ABILITY_NONE, ABILITY_STURDY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Balgoras"),
        .cryId = CRY_TYRUNT,
        .natDexNum = NATIONAL_DEX_TYRUNT,
        .categoryName = _("Kronprinz"),
        .height = 8,
        .weight = 260,
        .description = POKEDEX_DESC_STRING(
            "Es ist eigennützig und verzogen. Selbst\n"
            "wenn Balgoras nur spielen will, verletzt\n"
            "es dabei seinen Trainer manchmal schwer."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Tyrunt, 48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Tyrunt,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Tyrunt, 64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Tyrunt),
        ICON(Tyrunt, 2),
        .footprint = gMonFootprint_Tyrunt,
        LEARNSETS(Tyrunt),
        .evolutions = EVOLUTION({EVO_LEVEL_DAY, 39, SPECIES_TYRANTRUM}),
    },

    [SPECIES_TYRANTRUM] =
    {
        .baseHP        = 82,
        .baseAttack    = 121,
        .baseDefense   = 119,
        .baseSpeed     = 71,
        .baseSpAttack  = 69,
        .baseSpDefense = 59,
        .types = { TYPE_ROCK, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 182,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_STRONG_JAW, ABILITY_NONE, ABILITY_ROCK_HEAD },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Monargoras"),
        .cryId = CRY_TYRANTRUM,
        .natDexNum = NATIONAL_DEX_TYRANTRUM,
        .categoryName = _("Tyrannen"),
        .height = 25,
        .weight = 2700,
        .description = POKEDEX_DESC_STRING(
            "Ein Biss seines starken Kiefers reicht, um\n"
            "ein Auto zu zermalmen. Dieses Pokémon war\n"
            "der Regent der Urzeit."),
        .pokemonScale = 257,
        .pokemonOffset = 10,
        .trainerScale = 423,
        .trainerOffset = 8,
        FRONT_PIC(Tyrantrum, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Tyrantrum,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Tyrantrum, 64, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Tyrantrum),
        ICON(Tyrantrum, 0),
        .footprint = gMonFootprint_Tyrantrum,
        LEARNSETS(Tyrantrum),
    },
#endif //P_FAMILY_TYRUNT

#if P_FAMILY_AMAURA
    [SPECIES_AMAURA] =
    {
        .baseHP        = 77,
        .baseAttack    = 59,
        .baseDefense   = 50,
        .baseSpeed     = 46,
        .baseSpAttack  = 67,
        .baseSpDefense = 63,
        .types = { TYPE_ROCK, TYPE_ICE },
        .catchRate = 45,
        .expYield = 72,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MONSTER },
        .abilities = { ABILITY_REFRIGERATE, ABILITY_NONE, ABILITY_SNOW_WARNING },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Amarino"),
        .cryId = CRY_AMAURA,
        .natDexNum = NATIONAL_DEX_AMAURA,
        .categoryName = _("Tundra"),
        .height = 13,
        .weight = 252,
        .description = POKEDEX_DESC_STRING(
            "Vor Urzeiten lebte es in kalten Gebieten.\n"
            "Es heißt, wenn Amarino seine Stimme\n"
            "erklingen lässt, erscheinen Polarlichter."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Amaura, 32, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Amaura,
        .frontAnimId = ANIM_CONCAVE_ARC_SMALL_TWICE,
        BACK_PIC(Amaura, 40, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Amaura),
        ICON(Amaura, 0),
        .footprint = gMonFootprint_Amaura,
        LEARNSETS(Amaura),
        .evolutions = EVOLUTION({EVO_LEVEL_NIGHT, 39, SPECIES_AURORUS}),
    },

    [SPECIES_AURORUS] =
    {
        .baseHP        = 123,
        .baseAttack    = 77,
        .baseDefense   = 72,
        .baseSpeed     = 58,
        .baseSpAttack  = 99,
        .baseSpDefense = 92,
        .types = { TYPE_ROCK, TYPE_ICE },
        .catchRate = 45,
        .expYield = 104,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MONSTER },
        .abilities = { ABILITY_REFRIGERATE, ABILITY_NONE, ABILITY_SNOW_WARNING },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Amagarga"),
        .cryId = CRY_AURORUS,
        .natDexNum = NATIONAL_DEX_AURORUS,
        .categoryName = _("Tundra"),
        .height = 27,
        .weight = 2250,
        .description = POKEDEX_DESC_STRING(
            "Mit der -150 Grad C kalten Luft, die\n"
            "den diamantförmigen Kristallen auf\n"
            "seinem Körper entströmt, friert es\n"
            "Gegner ein."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Aurorus, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Aurorus,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Aurorus, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(Aurorus),
        ICON(Aurorus, 0),
        .footprint = gMonFootprint_Aurorus,
        LEARNSETS(Aurorus),
    },
#endif //P_FAMILY_AMAURA

#if P_FAMILY_HAWLUCHA
    [SPECIES_HAWLUCHA] =
    {
        .baseHP        = 78,
        .baseAttack    = 92,
        .baseDefense   = 75,
        .baseSpeed     = 118,
        .baseSpAttack  = 74,
        .baseSpDefense = 63,
        .types = { TYPE_FIGHTING, TYPE_FLYING },
        .catchRate = 100,
        .expYield = 175,
        .evYield_Attack = 2,
        .itemRare = ITEM_KINGS_ROCK,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        #if P_UPDATED_EGG_GROUPS >= GEN_8
            .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_HUMAN_LIKE },
        #else
            .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        #endif
        .abilities = { ABILITY_LIMBER, ABILITY_UNBURDEN, ABILITY_MOLD_BREAKER },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Resladero"),
        .cryId = CRY_HAWLUCHA,
        .natDexNum = NATIONAL_DEX_HAWLUCHA,
        .categoryName = _("Wrestling"),
        .height = 8,
        .weight = 215,
        .description = POKEDEX_DESC_STRING(
            "Es nutzt seine Flügel, um sich am Himmel\n"
            "in Position zu halten. Gegen seine\n"
            "Angriffe aus der Luft kann man sich nur\n"
            "schwer zur Wehr setzen."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Hawlucha, 64, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Hawlucha,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Hawlucha, 64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Hawlucha),
        ICON(Hawlucha, 0),
        .footprint = gMonFootprint_Hawlucha,
        LEARNSETS(Hawlucha),
    },
#endif //P_FAMILY_HAWLUCHA

#if P_FAMILY_DEDENNE
    [SPECIES_DEDENNE] =
    {
        .baseHP        = 67,
        .baseAttack    = 58,
        .baseDefense   = 57,
        .baseSpeed     = 101,
        .baseSpAttack  = 81,
        .baseSpDefense = 67,
        .types = { TYPE_ELECTRIC, TYPE_FAIRY },
        .catchRate = 180,
        .expYield = 151,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_CHEEK_POUCH, ABILITY_PICKUP, ABILITY_PLUS },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Dedenne"),
        .cryId = CRY_DEDENNE,
        .natDexNum = NATIONAL_DEX_DEDENNE,
        .categoryName = _("Antennen"),
        .height = 2,
        .weight = 22,
        .description = POKEDEX_DESC_STRING(
            "Mit den Schnurrhaaren empfangen sie\n"
            "elektrische Wellen von Artgenossen. So\n"
            "teilen sie einander mit, wo Futter und\n"
            "Elektrizität zu finden sind."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Dedenne, 64, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Dedenne,
        .frontAnimId = ANIM_GLOW_YELLOW,
        BACK_PIC(Dedenne, 64, 48),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(Dedenne),
        ICON(Dedenne, 0),
        .footprint = gMonFootprint_Dedenne,
        LEARNSETS(Dedenne),
    },
#endif //P_FAMILY_DEDENNE

#if P_FAMILY_CARBINK
    [SPECIES_CARBINK] =
    {
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 150,
        .baseSpeed     = 50,
        .baseSpAttack  = 50,
        .baseSpDefense = 150,
        .types = { TYPE_ROCK, TYPE_FAIRY },
        .catchRate = 60,
        .expYield = 100,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_NONE, ABILITY_STURDY },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Rocara"),
        .cryId = CRY_CARBINK,
        .natDexNum = NATIONAL_DEX_CARBINK,
        .categoryName = _("Edelstein"),
        .height = 3,
        .weight = 57,
        .description = POKEDEX_DESC_STRING(
            "Tief unter der Erde gibt es angeblich ein\n"
            "Königreich aus Diamanten, in dem Rocara\n"
            "zusammen mit ihrer Königin leben."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Carbink, 48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Carbink,
        .frontAnimId = ANIM_ZIGZAG_SLOW,
        .enemyMonElevation = 4,
        BACK_PIC(Carbink, 56, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Carbink),
        ICON(Carbink, 2),
        .footprint = gMonFootprint_Carbink,
        LEARNSETS(Carbink),
    },
#endif //P_FAMILY_CARBINK

#if P_FAMILY_GOOMY
    [SPECIES_GOOMY] =
    {
        .baseHP        = 45,
        .baseAttack    = 50,
        .baseDefense   = 35,
        .baseSpeed     = 40,
        .baseSpAttack  = 55,
        .baseSpDefense = 75,
        .types = { TYPE_DRAGON, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 60,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_SHED_SHELL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_SAP_SIPPER, ABILITY_HYDRATION, ABILITY_GOOEY },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Viscora"),
        .cryId = CRY_GOOMY,
        .natDexNum = NATIONAL_DEX_GOOMY,
        .categoryName = _("Schneckedei"),
        .height = 3,
        .weight = 28,
        .description = POKEDEX_DESC_STRING(
            "Das schwächste aller Drachen-Pokémon. Wenn\n"
            "seine Haut austrocknet, erstickt es. Daher\n"
            "hält es sich bevorzugt im Schatten auf."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Goomy, 32, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Goomy,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Goomy, 48, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SPRING,
        PALETTES(Goomy),
        ICON(Goomy, 5),
        .footprint = gMonFootprint_Goomy,
        LEARNSETS(Goomy),
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_SLIGGOO},
                                {EVO_NONE, 0, SPECIES_SLIGGOO_HISUI}),
    },

#define SLIGGOO_MISC_INFO                                       \
        .catchRate = 45,                                        \
        .expYield = 158,                                        \
        .evYield_SpDefense = 2,                                 \
        .itemRare = ITEM_SHED_SHELL,                            \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 40,                                        \
        .friendship = 35,                                       \
        .growthRate = GROWTH_SLOW,                              \
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },    \
        .bodyColor = BODY_COLOR_PURPLE,                         \
        .speciesName = _("Viscora"),                            \
        .cryId = CRY_SLIGGOO,                                   \
        .natDexNum = NATIONAL_DEX_SLIGGOO,                      \
        .footprint = gMonFootprint_Sliggoo,                     \
        .formSpeciesIdTable = sSliggooFormSpeciesIdTable

    [SPECIES_SLIGGOO] =
    {
        SLIGGOO_MISC_INFO,
        .baseHP        = 68,
        .baseAttack    = 75,
        .baseDefense   = 53,
        .baseSpeed     = 60,
        .baseSpAttack  = 83,
        .baseSpDefense = 113,
        .types = { TYPE_DRAGON, TYPE_DRAGON },
        .abilities = { ABILITY_SAP_SIPPER, ABILITY_HYDRATION, ABILITY_GOOEY },
        .categoryName = _("Schneckedei"),
        .height = 8,
        .weight = 175,
        .description = POKEDEX_DESC_STRING(
            "Die Grenze zwischen Freund und Fressen ist\n"
            "bei diesem Pokémon fließend. Als Freund\n"
            "geschätzt, zu Suppe zersetzt!"),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Sliggoo, 32, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Sliggoo,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Sliggoo, 48, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Sliggoo),
        ICON(Sliggoo, 5),
        LEARNSETS(Sliggoo),
        .evolutions = EVOLUTION({EVO_LEVEL_RAIN, 50, SPECIES_GOODRA},
                                {EVO_LEVEL_FOG, 50, SPECIES_GOODRA}),
    },

#define GOODRA_MISC_INFO                                        \
        .catchRate = 45,                                        \
        .expYield = 270,                                        \
        .evYield_SpDefense = 3,                                 \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 40,                                        \
        .friendship = 35,                                       \
        .growthRate = GROWTH_SLOW,                              \
        .eggGroups = { EGG_GROUP_DRAGON, EGG_GROUP_DRAGON },    \
        .bodyColor = BODY_COLOR_PURPLE,                         \
        .speciesName = _("Viscargot"),                             \
        .cryId = CRY_GOODRA,                                    \
        .natDexNum = NATIONAL_DEX_GOODRA,                       \
        .footprint = gMonFootprint_Goodra,                      \
        .formSpeciesIdTable = sGoodraFormSpeciesIdTable

    [SPECIES_GOODRA] =
    {
        GOODRA_MISC_INFO,
        .baseHP        = 90,
        .baseAttack    = 100,
        .baseDefense   = 70,
        .baseSpeed     = 80,
        .baseSpAttack  = 110,
        .baseSpDefense = 150,
        .types = { TYPE_DRAGON, TYPE_DRAGON },
        .abilities = { ABILITY_SAP_SIPPER, ABILITY_HYDRATION, ABILITY_GOOEY },
        .categoryName = _("Drachen"),
        .height = 20,
        .weight = 1505,
        .description = POKEDEX_DESC_STRING(
            "Unter seiner schleimigen Haut befindet\n"
            "sich eine dicke Speckschicht, die\n"
            "gegnerische Angriffe abfängt."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(Goodra, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Goodra,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Goodra, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Goodra),
        ICON(Goodra, 5),
        LEARNSETS(Goodra),
    },

#if P_HISUIAN_FORMS
    [SPECIES_SLIGGOO_HISUI] =
    {
        SLIGGOO_MISC_INFO,
        .baseHP        = 58,
        .baseAttack    = 75,
        .baseDefense   = 83,
        .baseSpeed     = 40,
        .baseSpAttack  = 83,
        .baseSpDefense = 113,
        .types = { TYPE_DRAGON, TYPE_STEEL },
        .abilities = { ABILITY_SAP_SIPPER, ABILITY_SHELL_ARMOR, ABILITY_GOOEY },
        .categoryName = _("Schneckedei"),
        .height = 7,
        .weight = 685,
        .description = POKEDEX_DESC_STRING(
            "Es verjagt Gegner durch Absonderung\n"
            "eines alles zersetzenden Schleims.\n"
            "Die zurückgebildeten Augäpfel des\n"
            "Pokémon gewähren ihm keine Sicht."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(SliggooHisuian, 48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_SliggooHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(SliggooHisuian, 64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(SliggooHisuian),
        ICON(SliggooHisuian, 2),
        LEARNSETS(SliggooHisuian),
        .isHisuianForm = TRUE,
        .evolutions = EVOLUTION({EVO_LEVEL_RAIN, 50, SPECIES_GOODRA_HISUI},
                                {EVO_LEVEL_FOG, 50, SPECIES_GOODRA_HISUI}),
    },

    [SPECIES_GOODRA_HISUI] =
    {
        GOODRA_MISC_INFO,
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 60,
        .baseSpAttack  = 110,
        .baseSpDefense = 150,
        .types = { TYPE_DRAGON, TYPE_STEEL },
        .abilities = { ABILITY_SAP_SIPPER, ABILITY_SHELL_ARMOR, ABILITY_GOOEY },
        .categoryName = _("Drachen"),
        .height = 17,
        .weight = 3341,
        .description = POKEDEX_DESC_STRING(
            "Dieses äußerst freundliche Drachen-\n"
            "Pokémon neigt dazu, seinen\n"
            "geliebten Trainer zu umarmen und so\n"
            "mit einer dicken Schleimschicht zu\n"
            "umhüllen."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(GoodraHisuian, 56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_GoodraHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(GoodraHisuian, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(GoodraHisuian),
        ICON(GoodraHisuian, 2),
        LEARNSETS(GoodraHisuian),
        .isHisuianForm = TRUE,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_GOOMY

#if P_FAMILY_KLEFKI
    [SPECIES_KLEFKI] =
    {
        .baseHP        = 57,
        .baseAttack    = 80,
        .baseDefense   = 91,
        .baseSpeed     = 75,
        .baseSpAttack  = 80,
        .baseSpDefense = 87,
        .types = { TYPE_STEEL, TYPE_FAIRY },
        .catchRate = 75,
        .expYield = 165,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_PRANKSTER, ABILITY_NONE, ABILITY_MAGICIAN },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Clavion"),
        .cryId = CRY_KLEFKI,
        .natDexNum = NATIONAL_DEX_KLEFKI,
        .categoryName = _("Schlüssel"),
        .height = 2,
        .weight = 30,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon sammelt eifrig Schlüssel,\n"
            "die es oft aus fremden Häusern entwendet.\n"
            "Ansonsten ist es aber sehr friedlich."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Klefki, 40, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Klefki,
        .frontAnimId = ANIM_FOUR_PETAL,
        .enemyMonElevation = 5,
        BACK_PIC(Klefki, 56, 64),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Klefki),
        ICON(Klefki, 0),
        .footprint = gMonFootprint_Klefki,
        LEARNSETS(Klefki),
    },
#endif //P_FAMILY_KLEFKI

#if P_FAMILY_PHANTUMP
    [SPECIES_PHANTUMP] =
    {
        .baseHP        = 43,
        .baseAttack    = 70,
        .baseDefense   = 48,
        .baseSpeed     = 38,
        .baseSpAttack  = 50,
        .baseSpDefense = 60,
        .types = { TYPE_GHOST, TYPE_GRASS },
        .catchRate = 120,
        .expYield = 62,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_NATURAL_CURE, ABILITY_FRISK, ABILITY_HARVEST },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Paragoni"),
        .cryId = CRY_PHANTUMP,
        .natDexNum = NATIONAL_DEX_PHANTUMP,
        .categoryName = _("Baumstumpf"),
        .height = 4,
        .weight = 70,
        .description = POKEDEX_DESC_STRING(
            "Röstet man seine grünen Blätter, lässt\n"
            "sich daraus ein Tee kochen, der gegen\n"
            "sämtliche Krankheiten helfen soll."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Phantump, 48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Phantump,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        BACK_PIC(Phantump, 64, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,
        PALETTES(Phantump),
        ICON(Phantump, 1),
        .footprint = gMonFootprint_Phantump,
        LEARNSETS(Phantump),
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_TREVENANT},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_TREVENANT}),
    },

    [SPECIES_TREVENANT] =
    {
        .baseHP        = 85,
        .baseAttack    = 110,
        .baseDefense   = 76,
        .baseSpeed     = 56,
        .baseSpAttack  = 65,
        .baseSpDefense = 82,
        .types = { TYPE_GHOST, TYPE_GRASS },
        .catchRate = 60,
        .expYield = 166,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_NATURAL_CURE, ABILITY_FRISK, ABILITY_HARVEST },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Trombork"),
        .cryId = CRY_TREVENANT,
        .natDexNum = NATIONAL_DEX_TREVENANT,
        .categoryName = _("Urgehölz"),
        .height = 15,
        .weight = 710,
        .description = POKEDEX_DESC_STRING(
            "Es nutzt seine Wurzeln als Nervensystem\n"
            "und kontrolliert so andere Bäume. Es ist\n"
            "nett zu den Pokémon, die in ihm leben."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Trevenant, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Trevenant,
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        BACK_PIC(Trevenant, 64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Trevenant),
        ICON(Trevenant, 1),
        .footprint = gMonFootprint_Trevenant,
        LEARNSETS(Trevenant),
    },
#endif //P_FAMILY_PHANTUMP

#if P_FAMILY_PUMPKABOO
#define PUMPKABOO_MISC_INFO                                                 \
        .types = { TYPE_GHOST, TYPE_GRASS },                                \
        .catchRate = 120,                                                   \
        .expYield = 67,                                                     \
        .evYield_Defense = 1,                                               \
        .genderRatio = PERCENT_FEMALE(50),                                  \
        .eggCycles = 20,                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                  \
        .growthRate = GROWTH_MEDIUM_FAST,                                   \
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },          \
        .abilities = { ABILITY_PICKUP, ABILITY_FRISK, ABILITY_INSOMNIA },   \
        .bodyColor = BODY_COLOR_BROWN,                                      \
        .speciesName = _("Trombork"),                                      \
        .natDexNum = NATIONAL_DEX_PUMPKABOO,                                \
        .categoryName = _("Urgehölz"),                                       \
        .frontAnimFrames = sAnims_Pumpkaboo,                                \
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,                                 \
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,                              \
        PALETTES(Pumpkaboo),                                                \
        ICON(Pumpkaboo, 2),                                                 \
        .footprint = gMonFootprint_Pumpkaboo,                               \
        LEARNSETS(Pumpkaboo),                                               \
        .formSpeciesIdTable = sPumpkabooFormSpeciesIdTable

    [SPECIES_PUMPKABOO_AVERAGE] =
    {
        PUMPKABOO_MISC_INFO,
        .baseHP        = 49,
        .baseAttack    = 66,
        .baseDefense   = 70,
        .baseSpeed     = 51,
        .baseSpAttack  = 44,
        .baseSpDefense = 55,
        .cryId = CRY_PUMPKABOO,
        .height = 4,
        .weight = 50,
        .description = POKEDEX_DESC_STRING(
            "Es entsteht aus der Vereinigung\n"
            "einer in der Welt der Lebenden\n"
            "gefangenen Seele mit einem Kürbis.\n"
            "Es wird erst nach Sonnenuntergang\n"
            "aktiv."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(PumpkabooAverage, 40, 40),
        .frontPicYOffset = 13,
        BACK_PIC(PumpkabooAverage, 56, 48),
        .backPicYOffset = 13,
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_GOURGEIST_AVERAGE},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_GOURGEIST_AVERAGE}),
    },

    [SPECIES_PUMPKABOO_SMALL] =
    {
        PUMPKABOO_MISC_INFO,
        .baseHP        = 44,
        .baseAttack    = 66,
        .baseDefense   = 70,
        .baseSpeed     = 56,
        .baseSpAttack  = 44,
        .baseSpDefense = 55,
        .cryId = CRY_PUMPKABOO,
        .height = 3,
        .weight = 35,
        .description = POKEDEX_DESC_STRING(
            "Es entsteht aus der Vereinigung\n"
            "einer in der Welt der Lebenden\n"
            "gefangenen Seele mit einem Kürbis.\n"
            "Es wird erst nach Sonnenuntergang\n"
            "aktiv."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(PumpkabooSmall, 40, 40),
        .frontPicYOffset = 15,
        BACK_PIC(PumpkabooSmall, 56, 48),
        .backPicYOffset = 14,
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_GOURGEIST_SMALL},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_GOURGEIST_SMALL}),
    },

    [SPECIES_PUMPKABOO_LARGE] =
    {
        PUMPKABOO_MISC_INFO,
        .baseHP        = 54,
        .baseAttack    = 66,
        .baseDefense   = 70,
        .baseSpeed     = 46,
        .baseSpAttack  = 44,
        .baseSpDefense = 55,
        .cryId = CRY_PUMPKABOO,
        .height = 5,
        .weight = 75,
        .description = POKEDEX_DESC_STRING(
            "Es entsteht aus der Vereinigung\n"
            "einer in der Welt der Lebenden\n"
            "gefangenen Seele mit einem Kürbis.\n"
            "Es wird erst nach Sonnenuntergang\n"
            "aktiv."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(PumpkabooLarge, 48, 48),
        .frontPicYOffset = 12,
        BACK_PIC(PumpkabooLarge, 56, 48),
        .backPicYOffset = 13,
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_GOURGEIST_LARGE},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_GOURGEIST_LARGE}),
    },

    [SPECIES_PUMPKABOO_SUPER] =
    {
        PUMPKABOO_MISC_INFO,
        .baseHP        = 59,
        .baseAttack    = 66,
        .baseDefense   = 70,
        .baseSpeed     = 41,
        .baseSpAttack  = 44,
        .baseSpDefense = 55,
        .itemCommon = ITEM_MIRACLE_SEED,
        .itemRare = ITEM_MIRACLE_SEED,
        .cryId = CRY_PUMPKABOO_SUPER,
        .height = 8,
        .weight = 150,
        .description = POKEDEX_DESC_STRING(
            "Es entsteht aus der Vereinigung\n"
            "einer in der Welt der Lebenden\n"
            "gefangenen Seele mit einem Kürbis.\n"
            "Es wird erst nach Sonnenuntergang\n"
            "aktiv."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(PumpkabooSuper, 48, 48),
        .frontPicYOffset = 10,
        BACK_PIC(PumpkabooSuper, 56, 48),
        .backPicYOffset = 12,
        .evolutions = EVOLUTION({EVO_TRADE, 0, SPECIES_GOURGEIST_SUPER},
                                {EVO_ITEM, ITEM_LINKING_CORD, SPECIES_GOURGEIST_SUPER}),
    },

#define GOURGEIST_MISC_INFO                                                 \
        .types = { TYPE_GHOST, TYPE_GRASS },                                \
        .catchRate = 60,                                                    \
        .expYield = 173,                                                    \
        .evYield_Defense = 2,                                               \
        .genderRatio = PERCENT_FEMALE(50),                                  \
        .eggCycles = 20,                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                  \
        .growthRate = GROWTH_MEDIUM_FAST,                                   \
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },          \
        .abilities = { ABILITY_PICKUP, ABILITY_FRISK, ABILITY_INSOMNIA },   \
        .bodyColor = BODY_COLOR_BROWN,                                      \
        .speciesName = _("Irrbis"),                                      \
        .natDexNum = NATIONAL_DEX_GOURGEIST,                                \
        .categoryName = _("Kürbis"),                                       \
        .frontAnimFrames = sAnims_Gourgeist,                                \
        .frontAnimId = ANIM_SHRINK_GROW,                                    \
        .backAnimId = BACK_ANIM_V_STRETCH,                                  \
        PALETTES(Gourgeist),                                                \
        ICON(Gourgeist, 2),                                                 \
        .footprint = gMonFootprint_Gourgeist,                               \
        LEARNSETS(Gourgeist),                                               \
        .formSpeciesIdTable = sGourgeistFormSpeciesIdTable

    [SPECIES_GOURGEIST_AVERAGE] =
    {
        GOURGEIST_MISC_INFO,
        .baseHP        = 65,
        .baseAttack    = 90,
        .baseDefense   = 122,
        .baseSpeed     = 84,
        .baseSpAttack  = 58,
        .baseSpDefense = 75,
        .cryId = CRY_GOURGEIST,
        .height = 9,
        .weight = 125,
        .description = POKEDEX_DESC_STRING(
            "Unter unheimlichen Gesängen\n"
            "durchstreift es in Neumondnächten\n"
            "Städte und Dörfer. Wer dem\n"
            "unheilvollen Gesang lauscht, wird\n"
            "verflucht."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(GourgeistAverage, 64, 64),
        .frontPicYOffset = 4,
        BACK_PIC(GourgeistAverage, 48, 64),
        .backPicYOffset = 3,
    },

    [SPECIES_GOURGEIST_SMALL] =
    {
        GOURGEIST_MISC_INFO,
        .baseHP        = 55,
        .baseAttack    = 85,
        .baseDefense   = 122,
        .baseSpeed     = 99,
        .baseSpAttack  = 58,
        .baseSpDefense = 75,
        .cryId = CRY_GOURGEIST,
        .height = 7,
        .weight = 95,
        .description = POKEDEX_DESC_STRING(
            "Unter unheimlichen Gesängen\n"
            "durchstreift es in Neumondnächten\n"
            "Städte und Dörfer. Wer dem\n"
            "unheilvollen Gesang lauscht, wird\n"
            "verflucht."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(GourgeistSmall, 56, 64),
        .frontPicYOffset = 5,
        BACK_PIC(GourgeistSmall, 48, 56),
        .backPicYOffset = 4,
    },

    [SPECIES_GOURGEIST_LARGE] =
    {
        GOURGEIST_MISC_INFO,
        .baseHP        = 75,
        .baseAttack    = 95,
        .baseDefense   = 122,
        .baseSpeed     = 69,
        .baseSpAttack  = 58,
        .baseSpDefense = 75,
        .cryId = CRY_GOURGEIST,
        .height = 11,
        .weight = 140,
        .description = POKEDEX_DESC_STRING(
            "Unter unheimlichen Gesängen\n"
            "durchstreift es in Neumondnächten\n"
            "Städte und Dörfer. Wer dem\n"
            "unheilvollen Gesang lauscht, wird\n"
            "verflucht."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(GourgeistLarge, 64, 64),
        .frontPicYOffset = 2,
        BACK_PIC(GourgeistLarge, 48, 64),
        .backPicYOffset = 2,
    },

    [SPECIES_GOURGEIST_SUPER] =
    {
        GOURGEIST_MISC_INFO,
        .baseHP        = 85,
        .baseAttack    = 100,
        .baseDefense   = 122,
        .baseSpeed     = 54,
        .baseSpAttack  = 58,
        .baseSpDefense = 75,
        .itemCommon = ITEM_MIRACLE_SEED,
        .itemRare = ITEM_MIRACLE_SEED,
        .cryId = CRY_GOURGEIST_SUPER,
        .height = 17,
        .weight = 390,
        .description = POKEDEX_DESC_STRING(
            "Unter unheimlichen Gesängen\n"
            "durchstreift es in Neumondnächten\n"
            "Städte und Dörfer. Wer dem\n"
            "unheilvollen Gesang lauscht, wird\n"
            "verflucht."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(GourgeistSuper, 64, 64),
        .frontPicYOffset = 0,
        BACK_PIC(GourgeistSuper, 56, 64),
        .backPicYOffset = 1,
    },
#endif //P_FAMILY_PUMPKABOO

#if P_FAMILY_BERGMITE
#if P_UPDATED_EGG_GROUPS >= GEN_8
    #define BERGMITE_EGG_GROUPS {EGG_GROUP_MONSTER, EGG_GROUP_MINERAL }
#else
    #define BERGMITE_EGG_GROUPS {EGG_GROUP_MONSTER, EGG_GROUP_MONSTER }
#endif

    [SPECIES_BERGMITE] =
    {
        .baseHP        = 55,
        .baseAttack    = 69,
        .baseDefense   = 85,
        .baseSpeed     = 28,
        .baseSpAttack  = 32,
        .baseSpDefense = 35,
        .types = { TYPE_ICE, TYPE_ICE },
        .catchRate = 190,
        .expYield = 61,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = BERGMITE_EGG_GROUPS,
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_ICE_BODY, ABILITY_STURDY },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Arktip"),
        .cryId = CRY_BERGMITE,
        .natDexNum = NATIONAL_DEX_BERGMITE,
        .categoryName = _("Eisklumpen"),
        .height = 10,
        .weight = 995,
        .description = POKEDEX_DESC_STRING(
            "Es lebt in extrem kalten Gebieten. Um sich\n"
            "an Arktilas zu befestigen, lässt es seine\n"
            "Beine an dessen Rücken festfrieren."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Bergmite, 40, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Bergmite,
        .frontAnimId = ANIM_LUNGE_GROW,
        BACK_PIC(Bergmite, 56, 48),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Bergmite),
        ICON(Bergmite, 0),
        .footprint = gMonFootprint_Bergmite,
        LEARNSETS(Bergmite),
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_AVALUGG},
                                {EVO_NONE, 0, SPECIES_AVALUGG_HISUI}),
    },

#define AVALUGG_MISC_INFO                               \
        .catchRate = 55,                                \
        .expYield = 180,                                \
        .evYield_Defense = 2,                           \
        .genderRatio = PERCENT_FEMALE(50),              \
        .eggCycles = 20,                                \
        .friendship = STANDARD_FRIENDSHIP,              \
        .growthRate = GROWTH_MEDIUM_FAST,               \
        .eggGroups = BERGMITE_EGG_GROUPS,               \
        .bodyColor = BODY_COLOR_BLUE,                   \
        .speciesName = _("Arktip"),                    \
        .cryId = CRY_AVALUGG,                           \
        .natDexNum = NATIONAL_DEX_AVALUGG,              \
        .categoryName = _("Eisklumpen"),                   \
        .footprint = gMonFootprint_Avalugg,             \
        .formSpeciesIdTable = sAvaluggFormSpeciesIdTable

    [SPECIES_AVALUGG] =
    {
        AVALUGG_MISC_INFO,
        .baseHP        = 95,
        .baseAttack    = 117,
        .baseDefense   = 184,
        .baseSpeed     = 28,
        .baseSpAttack  = 44,
        .baseSpDefense = 46,
        .types = { TYPE_ICE, TYPE_ICE },
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_ICE_BODY, ABILITY_STURDY },
        .height = 20,
        .weight = 5050,
        .description = POKEDEX_DESC_STRING(
            "Sein eisbedeckter Körper ist so\n"
            "hart wie Stahl. Es nutzt diese\n"
            "stahlharte Hülle, um Hindernisse zu\n"
            "zerschmettern und sich so seinen\n"
            "Weg zu bahnen."),
,
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(Avalugg, 64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Avalugg,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Avalugg, 64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Avalugg),
        ICON(Avalugg, 0),
        LEARNSETS(Avalugg),
    },

#if P_HISUIAN_FORMS
    [SPECIES_AVALUGG_HISUI] =
    {
        AVALUGG_MISC_INFO,
        .baseHP        = 95,
        .baseAttack    = 127,
        .baseDefense   = 184,
        .baseSpeed     = 38,
        .baseSpAttack  = 34,
        .baseSpDefense = 36,
        .types = { TYPE_ICE, TYPE_ROCK },
        .abilities = { ABILITY_STRONG_JAW, ABILITY_ICE_BODY, ABILITY_STURDY },
        .height = 14,
        .weight = 2624,
        .description = POKEDEX_DESC_STRING(
            "Sein eisbedeckter Körper ist so\n"
            "hart wie Stahl. Es nutzt diese\n"
            "stahlharte Hülle, um Hindernisse zu\n"
            "zerschmettern und sich so seinen\n"
            "Weg zu bahnen."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(AvaluggHisuian, 64, 48),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_AvaluggHisuian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(AvaluggHisuian, 64, 32),
        .backPicYOffset = 16,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(AvaluggHisuian),
        ICON(AvaluggHisuian, 5),
        LEARNSETS(AvaluggHisuian),
        .isHisuianForm = TRUE,
    },
#endif //P_HISUIAN_FORMS
#endif //P_FAMILY_BERGMITE

#if P_FAMILY_NOIBAT
    [SPECIES_NOIBAT] =
    {
        .baseHP        = 40,
        .baseAttack    = 30,
        .baseDefense   = 35,
        .baseSpeed     = 55,
        .baseSpAttack  = 45,
        .baseSpDefense = 40,
        .types = { TYPE_FLYING, TYPE_DRAGON },
        .catchRate = 190,
        .expYield = 49,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        #if P_UPDATED_EGG_GROUPS >= GEN_8
            .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_DRAGON },
        #else
            .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        #endif
        .abilities = { ABILITY_FRISK, ABILITY_INFILTRATOR, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("eF-eM"),
        .cryId = CRY_NOIBAT,
        .natDexNum = NATIONAL_DEX_NOIBAT,
        .categoryName = _("Schallwellen"),
        .height = 5,
        .weight = 80,
        .description = POKEDEX_DESC_STRING(
            "Es lebt im Inneren pechschwarzer\n"
            "Höhlen. Seine riesigen Ohren setzen\n"
            "Ultraschallwellen von 200 000 Hz\n"
            "frei."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Noibat, 64, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Noibat,
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 8,
        BACK_PIC(Noibat, 56, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Noibat),
        ICON(Noibat, 2),
        .footprint = gMonFootprint_Noibat,
        LEARNSETS(Noibat),
        .evolutions = EVOLUTION({EVO_LEVEL, 48, SPECIES_NOIVERN}),
    },

    [SPECIES_NOIVERN] =
    {
        .baseHP        = 85,
        .baseAttack    = 70,
        .baseDefense   = 80,
        .baseSpeed     = 123,
        .baseSpAttack  = 97,
        .baseSpDefense = 80,
        .types = { TYPE_FLYING, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 187,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        #if P_UPDATED_EGG_GROUPS >= GEN_8
            .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_DRAGON },
        #else
            .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        #endif
        .abilities = { ABILITY_FRISK, ABILITY_INFILTRATOR, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("UHaFnir"),
        .cryId = CRY_NOIVERN,
        .natDexNum = NATIONAL_DEX_NOIVERN,
        .categoryName = _("Schallwellen"),
        .height = 15,
        .weight = 850,
        .description = POKEDEX_DESC_STRING(
            "Ein heißblütiges und brutales Pokémon. Es\n"
            "fügt seinen in der Dunkelheit wehrlosen\n"
            "Gegnern gnadenlos Verletzungen zu."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Noivern, 64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Noivern,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Noivern, 64, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Noivern),
        ICON(Noivern, 2),
        .footprint = gMonFootprint_Noivern,
        LEARNSETS(Noivern),
    },
#endif //P_FAMILY_NOIBAT

#if P_FAMILY_XERNEAS
#define XERNEAS_MISC_INFO(Form)                                                         \
    {                                                                                   \
        .baseHP        = 126,                                                           \
        .baseAttack    = 131,                                                           \
        .baseDefense   = 95,                                                            \
        .baseSpeed     = 99,                                                            \
        .baseSpAttack  = 131,                                                           \
        .baseSpDefense = 98,                                                            \
        .types = { TYPE_FAIRY, TYPE_FAIRY },                                            \
        .catchRate = 45,                                                                \
        .expYield = 306,                                                                \
        .evYield_HP = 3,                                                                \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_FAIRY_AURA, ABILITY_NONE },                              \
        .bodyColor = BODY_COLOR_BLUE,                                                   \
        .speciesName = _("UHaFnir"),                                                    \
        .cryId = CRY_XERNEAS,                                                           \
        .natDexNum = NATIONAL_DEX_XERNEAS,                                              \
        .categoryName = _("Schallwellen"),                                                      \
        .height = 30,                                                                   \
        .weight = 2150,                                                                 \
        .description = gXerneasPokedexText,                                             \
        .pokemonScale = 275,                                                            \
        .pokemonOffset = 7,                                                             \
        .trainerScale = 256,                                                            \
        .trainerOffset = 0,                                                             \
        FRONT_PIC(Xerneas##Form, 64, 64),                                               \
        .frontPicYOffset = 0,                                                           \
        .frontAnimFrames = sAnims_Xerneas,                                              \
        .frontAnimId = ANIM_GROW_VIBRATE,                                               \
        BACK_PIC(Xerneas##Form, 64, 64),                                                \
        .backPicYOffset = 0,                                                            \
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,                                        \
        PALETTES(Xerneas##Form),                                                        \
        ICON(Xerneas##Form, 0),                                                         \
        .footprint = gMonFootprint_Xerneas,                                             \
        LEARNSETS(Xerneas),                                                             \
        .formSpeciesIdTable = sXerneasFormSpeciesIdTable,                               \
        .formChangeTable = sXerneasFormChangeTable,                                     \
        .isLegendary = TRUE,                                                            \
    }

    [SPECIES_XERNEAS_NEUTRAL] = XERNEAS_MISC_INFO(Neutral),
    [SPECIES_XERNEAS_ACTIVE]  = XERNEAS_MISC_INFO(Active),
#endif //P_FAMILY_XERNEAS

#if P_FAMILY_YVELTAL
    [SPECIES_YVELTAL] =
    {
        .baseHP        = 126,
        .baseAttack    = 131,
        .baseDefense   = 95,
        .baseSpeed     = 99,
        .baseSpAttack  = 131,
        .baseSpDefense = 98,
        .types = { TYPE_DARK, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 306,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_DARK_AURA, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
        .isLegendary = TRUE,
        .speciesName = _("Yveltal"),
        .cryId = CRY_YVELTAL,
        .natDexNum = NATIONAL_DEX_YVELTAL,
        .categoryName = _("Zerstörungs"),
        .height = 58,
        .weight = 2030,
        .description = POKEDEX_DESC_STRING(
            "Wenn Schwingen und Schwanzgefieder\n"
            "dieses Legendären Pokémon rot\n"
            "leuchten, entzieht es Lebewesen\n"
            "deren Energie."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 360,
        .trainerOffset = 7,
        FRONT_PIC(Yveltal, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Yveltal,
        .frontAnimId = ANIM_FRONT_FLIP,
        .enemyMonElevation = 5,
        BACK_PIC(Yveltal, 64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(Yveltal),
        ICON(Yveltal, 0),
        .footprint = gMonFootprint_Yveltal,
        LEARNSETS(Yveltal),
    },
#endif //P_FAMILY_YVELTAL

#if P_FAMILY_ZYGARDE
#define ZYGARDE_MISC_INFO(ability)                                                      \
        .types = { TYPE_DRAGON, TYPE_GROUND },                                          \
        .catchRate = 3,                                                                 \
        .evYield_HP = 3,                                                                \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ability, ABILITY_NONE },                                         \
        .noFlip = TRUE,                                                                 \
        .speciesName = _("Yveltal"),                                                    \
        .natDexNum = NATIONAL_DEX_ZYGARDE,                                              \
        .categoryName = _("Zerstörungs"),                                                     \
        .footprint = gMonFootprint_Zygarde,                                             \
        LEARNSETS(Zygarde),                                                             \
        .formSpeciesIdTable = sZygardeFormSpeciesIdTable,                               \
        .isLegendary = TRUE

#define ZYGARDE_50_SPECIES_INFO(ability)                        \
    {                                                           \
        .baseHP        = 108,                                   \
        .baseAttack    = 100,                                   \
        .baseDefense   = 121,                                   \
        .baseSpeed     = 95,                                    \
        .baseSpAttack  = 81,                                    \
        .baseSpDefense = 95,                                    \
        .expYield = 270,                                        \
        .bodyColor = BODY_COLOR_GREEN,                          \
        .cryId = CRY_ZYGARDE_50,                                \
        .height = 50,                                           \
        .weight = 3050,                                         \
        .description = gZygarde50PokedexText,                   \
        .pokemonScale = 256,                                    \
        .pokemonOffset = 0,                                     \
        .trainerScale = 721,                                    \
        .trainerOffset = 19,                                    \
        FRONT_PIC(Zygarde50, 64, 64),                           \
        .frontPicYOffset = 0,                                   \
        .frontAnimFrames = sAnims_Zygarde50,                    \
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,                   \
        BACK_PIC(Zygarde50, 64, 64),                            \
        .backPicYOffset = 4,                                    \
        .backAnimId = (ability == ABILITY_POWER_CONSTRUCT       \
            ? BACK_ANIM_SHAKE_GLOW_GREEN                        \
            : BACK_ANIM_V_STRETCH),                             \
        PALETTES(Zygarde50),                                    \
        ICON(Zygarde50, 1),                                     \
        .formChangeTable = (ability == ABILITY_POWER_CONSTRUCT  \
            ? sZygarde50PowerConstructFormChangeTable           \
            : sZygarde50AuraBreakFormChangeTable),              \
        ZYGARDE_MISC_INFO(ability),                             \
    }

#define ZYGARDE_10_SPECIES_INFO(ability)                        \
    {                                                           \
        .baseHP        = 54,                                    \
        .baseAttack    = 100,                                   \
        .baseDefense   = 71,                                    \
        .baseSpeed     = 115,                                   \
        .baseSpAttack  = 61,                                    \
        .baseSpDefense = 85,                                    \
        .expYield = 219,                                        \
        .bodyColor = BODY_COLOR_BLACK,                          \
        .cryId = CRY_ZYGARDE_10,                                \
        .height = 12,                                           \
        .weight = 335,                                          \
        .description = gZygarde10PokedexText,                   \
        .pokemonScale = 256,                                    \
        .pokemonOffset = 0,                                     \
        .trainerScale = 721,                                    \
        .trainerOffset = 19,                                    \
        FRONT_PIC(Zygarde10, 56, 64),                           \
        .frontPicYOffset = 2,                                   \
        .frontAnimFrames = sAnims_Zygarde10,                    \
        BACK_PIC(Zygarde10, 64, 56),                            \
        .backPicYOffset = 8,                                    \
        .backAnimId = (ability == ABILITY_POWER_CONSTRUCT       \
            ? BACK_ANIM_SHAKE_GLOW_GREEN                        \
            : BACK_ANIM_JOLT_RIGHT),                            \
        PALETTES(Zygarde10),                                    \
        ICON(Zygarde10, 1),                                     \
        .formChangeTable = (ability == ABILITY_POWER_CONSTRUCT  \
            ? sZygarde10PowerConstructFormChangeTable           \
            : sZygarde10AuraBreakFormChangeTable),              \
        ZYGARDE_MISC_INFO(ability),                             \
    }
    //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,

    [SPECIES_ZYGARDE_50_AURA_BREAK]      = ZYGARDE_50_SPECIES_INFO(ABILITY_AURA_BREAK),
    [SPECIES_ZYGARDE_50_POWER_CONSTRUCT] = ZYGARDE_50_SPECIES_INFO(ABILITY_POWER_CONSTRUCT),
    [SPECIES_ZYGARDE_10_AURA_BREAK]      = ZYGARDE_10_SPECIES_INFO(ABILITY_AURA_BREAK),
    [SPECIES_ZYGARDE_10_POWER_CONSTRUCT] = ZYGARDE_10_SPECIES_INFO(ABILITY_POWER_CONSTRUCT),
    [SPECIES_ZYGARDE_COMPLETE] =
    {
        ZYGARDE_MISC_INFO(ABILITY_POWER_CONSTRUCT),
        .baseHP        = 216,
        .baseAttack    = 100,
        .baseDefense   = 121,
        .baseSpeed     = 85,
        .baseSpAttack  = 91,
        .baseSpDefense = 95,
        .expYield = 319,
        .bodyColor = BODY_COLOR_BLACK,
        .cryId = CRY_ZYGARDE_COMPLETE,
        .height = 45,
        .weight = 6100,
        .description = POKEDEX_DESC_STRING(
            "Wenn das Ökosystem der Kalos-Region\n"
            "kippt, erscheint dieses Pokémon und\n"
            "offenbart seine geheimen Kräfte."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 721,
        .trainerOffset = 19,
        FRONT_PIC(ZygardeComplete, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_ZygardeComplete,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(ZygardeComplete, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_GREEN,
        PALETTES(ZygardeComplete),
        ICON(ZygardeComplete, 1),
        .formChangeTable = sZygardeCompleteFormChangeTable,
    },
#endif //P_FAMILY_ZYGARDE

#if P_FAMILY_DIANCIE
#define DIANCE_MISC_INFO                                                                \
        .types = { TYPE_ROCK, TYPE_FAIRY },                                             \
        .catchRate = 3,                                                                 \
        .evYield_Defense = 1,                                                           \
        .evYield_SpDefense = 2,                                                         \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 25,                                                                \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .bodyColor = BODY_COLOR_PINK,                                                   \
        .speciesName = _("Zygarde"),                                                    \
        .natDexNum = NATIONAL_DEX_DIANCIE,                                              \
        .categoryName = _("Ordnungs"),                                                     \
        .footprint = gMonFootprint_Diancie,                                             \
        LEARNSETS(Diancie),                                                             \
        .formSpeciesIdTable = sDiancieFormSpeciesIdTable,                               \
        .formChangeTable = sDiancieFormChangeTable,                                     \
        .isMythical = TRUE

    [SPECIES_DIANCIE] =
    {
        DIANCE_MISC_INFO,
        .baseHP        = 50,
        .baseAttack    = 100,
        .baseDefense   = 150,
        .baseSpeed     = 50,
        .baseSpAttack  = 100,
        .baseSpDefense = 150,
        .expYield = 270,
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_NONE },
        .cryId = CRY_DIANCIE,
        .height = 7,
        .weight = 88,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon ist eine Mutation\n"
            "von Rocara. Sein rosafarben\n"
            "schimmernder Körper gilt als\n"
            "schönster Anblick überhaupt."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Diancie, 40, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Diancie,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Diancie, 64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,
        PALETTES(Diancie),
        ICON(Diancie, 1),
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_DIANCIE_MEGA] =
    {
        DIANCE_MISC_INFO,
        .baseHP        = 50,
        .baseAttack    = 160,
        .baseDefense   = 110,
        .baseSpeed     = 110,
        .baseSpAttack  = 160,
        .baseSpDefense = 110,
        .expYield = 315,
        .abilities = { ABILITY_MAGIC_BOUNCE, ABILITY_MAGIC_BOUNCE, ABILITY_MAGIC_BOUNCE },
        .cryId = CRY_DIANCIE_MEGA,
        .height = 11,
        .weight = 278,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon ist eine Mutation\n"
            "von Rocara. Sein rosafarben\n"
            "schimmernder Körper gilt als\n"
            "schönster Anblick überhaupt."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(DiancieMega, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_DiancieMega,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(DiancieMega, 64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(DiancieMega),
        ICON(DiancieMega, 0),
        .isMegaEvolution = TRUE,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_DIANCIE

#if P_FAMILY_HOOPA
#define HOOPA_MISC_INFO                                                                 \
        .catchRate = 3,                                                                 \
        .expYield = 270,                                                                \
        .evYield_SpAttack = 3,                                                          \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_MAGICIAN, ABILITY_NONE },                                \
        .bodyColor = BODY_COLOR_PURPLE,                                                 \
        .speciesName = _("Diancie"),                                                      \
        .natDexNum = NATIONAL_DEX_HOOPA,                                                \
        .footprint = gMonFootprint_Hoopa,                                               \
        .formSpeciesIdTable = sHoopaFormSpeciesIdTable,                                 \
        .formChangeTable = sHoopaFormChangeTable,                                       \
        .isMythical = TRUE

    [SPECIES_HOOPA_CONFINED] =
    {
        HOOPA_MISC_INFO,
        .baseHP        = 80,
        .baseAttack    = 110,
        .baseDefense   = 60,
        .baseSpeed     = 70,
        .baseSpAttack  = 150,
        .baseSpDefense = 130,
        .types = { TYPE_PSYCHIC, TYPE_GHOST },
        .friendship = 100,
        .cryId = CRY_HOOPA_CONFINED,
        .categoryName = _("Schabernack"),
        .height = 5,
        .weight = 90,
        .description = POKEDEX_DESC_STRING(
            "Mittels seiner Ringe, die\n"
            "Raumkrümmungen verursachen,\n"
            "verfrachtet dieser Unruhestifter\n"
            "alles und jeden an die entlegensten\n"
            "Orte."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(HoopaConfined, 48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_HoopaConfined,
        .frontAnimId = ANIM_ZIGZAG_SLOW,
        .enemyMonElevation = 13,
        BACK_PIC(HoopaConfined, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(HoopaConfined),
        ICON(HoopaConfined, 0),
        LEARNSETS(HoopaConfined),
    },

    [SPECIES_HOOPA_UNBOUND] =
    {
        HOOPA_MISC_INFO,
        .baseHP        = 80,
        .baseAttack    = 160,
        .baseDefense   = 60,
        .baseSpeed     = 80,
        .baseSpAttack  = 170,
        .baseSpDefense = 130,
        .types = { TYPE_PSYCHIC, TYPE_DARK },
        .friendship = P_UPDATED_FRIENDSHIP >= GEN_8 ? STANDARD_FRIENDSHIP : 100,
        .cryId = CRY_HOOPA_UNBOUND,
        .categoryName = _("Schabernack"),
        .height = 65,
        .weight = 490,
        .description = POKEDEX_DESC_STRING(
            "Mittels seiner Ringe, die\n"
            "Raumkrümmungen verursachen,\n"
            "verfrachtet dieser Unruhestifter\n"
            "alles und jeden an die entlegensten\n"
            "Orte."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(HoopaUnbound, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_HoopaUnbound,
        .frontAnimId = ANIM_GROW_IN_STAGES,
        .enemyMonElevation = 3,
        BACK_PIC(HoopaUnbound, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(HoopaUnbound),
        ICON(HoopaUnbound, 0),
        LEARNSETS(HoopaUnbound),
    },
#endif //P_FAMILY_HOOPA

#if P_FAMILY_VOLCANION
    [SPECIES_VOLCANION] =
    {
        .baseHP        = 80,
        .baseAttack    = 110,
        .baseDefense   = 120,
        .baseSpeed     = 70,
        .baseSpAttack  = 130,
        .baseSpDefense = 90,
        .types = { TYPE_FIRE, TYPE_WATER },
        .catchRate = 3,
        .expYield = 270,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
        .isMythical = TRUE,
        .speciesName = _("Volcanion"),
        .cryId = CRY_VOLCANION,
        .natDexNum = NATIONAL_DEX_VOLCANION,
        .categoryName = _("Dampf"),
        .height = 17,
        .weight = 1950,
        .description = POKEDEX_DESC_STRING(
            "Über die Arme auf seinem Rücken stößt es\n"
            "Wasserdampf aus. Seine Kraft reicht aus,\n"
            "um Berge zu versetzen."),
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 1,
        FRONT_PIC(Volcanion, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Volcanion,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        BACK_PIC(Volcanion, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(Volcanion),
        ICON(Volcanion, 0),
        .footprint = gMonFootprint_Volcanion,
        LEARNSETS(Volcanion),
    },
#endif //P_FAMILY_VOLCANION

#ifdef __INTELLISENSE__
};
#endif