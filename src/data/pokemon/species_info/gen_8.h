#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen8[] =
{
#endif

#if P_FAMILY_GROOKEY
    [SPECIES_GROOKEY] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 50,
        .baseSpeed     = 65,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 62,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_GRASS },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_GRASSY_SURGE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Chimpep"),
        .cryId = CRY_GROOKEY,
        .natDexNum = NATIONAL_DEX_GROOKEY,
        .categoryName = _("Schimpansen"),
        .height = 3,
        .weight = 50,
        .description = POKEDEX_DESC_STRING(
            "Es greift an, indem es wiederholt seinen\n"
            "Schlägel schwingt. Diese rasanten\n"
            "Trommelbewegungen bringen es immer mehr in\n"
            "Fahrt."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Grookey, 40, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Grookey,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Grookey, 48, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Grookey),
        ICON(Grookey, 1),
        .footprint = gMonFootprint_Grookey,
        LEARNSETS(Grookey),
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_THWACKEY}),
    },

    [SPECIES_THWACKEY] =
    {
        .baseHP        = 70,
        .baseAttack    = 85,
        .baseDefense   = 70,
        .baseSpeed     = 80,
        .baseSpAttack  = 55,
        .baseSpDefense = 60,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 147,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_GRASS },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_GRASSY_SURGE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Chimstix"),
        .cryId = CRY_THWACKEY,
        .natDexNum = NATIONAL_DEX_THWACKEY,
        .categoryName = _("Beat"),
        .height = 7,
        .weight = 140,
        .description = POKEDEX_DESC_STRING(
            "Verliert es sich im Kampf in seinem wilden\n"
            "Beat, bemerkt es ab und zu nicht mal, dass\n"
            "sein Gegner bereits zu Boden gegangen ist."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Thwackey, 48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Thwackey,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Thwackey, 56, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Thwackey),
        ICON(Thwackey, 1),
        .footprint = gMonFootprint_Thwackey,
        LEARNSETS(Thwackey),
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_RILLABOOM}),
    },

#define RILLABOOM_MISC_INFO                                                     \
        .baseHP        = 100,                                                   \
        .baseAttack    = 125,                                                   \
        .baseDefense   = 90,                                                    \
        .baseSpeed     = 85,                                                    \
        .baseSpAttack  = 60,                                                    \
        .baseSpDefense = 70,                                                    \
        .types = { TYPE_GRASS, TYPE_GRASS },                                    \
        .catchRate = 45,                                                        \
        .expYield = 265,                                                        \
        .evYield_Attack = 3,                                                    \
        .genderRatio = PERCENT_FEMALE(12.5),                                    \
        .eggCycles = 20,                                                        \
        .friendship = STANDARD_FRIENDSHIP,                                      \
        .growthRate = GROWTH_MEDIUM_SLOW,                                       \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_GRASS },                      \
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_GRASSY_SURGE },  \
        .bodyColor = BODY_COLOR_GREEN,                                          \
        .speciesName = _("Chimstix"),                                          \
        .cryId = CRY_RILLABOOM,                                                 \
        .natDexNum = NATIONAL_DEX_RILLABOOM,                                    \
        .categoryName = _("Beat"),                                           \
        .footprint = gMonFootprint_Rillaboom,                                   \
        LEARNSETS(Rillaboom),                                                   \
        .formSpeciesIdTable = sRillaboomFormSpeciesIdTable,                     \
        .formChangeTable = sRillaboomFormChangeTable

    [SPECIES_RILLABOOM] =
    {
        RILLABOOM_MISC_INFO,
        .height = 21,
        .weight = 900,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        .description = POKEDEX_DESC_STRING(
            "Es kontrolliert die Macht seines\n"
            "speziellen Baumstumpfes durch\n"
            "Trommeln. Im Kampf manipuliert es\n"
            "damit Wurzeln."),
        FRONT_PIC(Rillaboom, 64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Rillaboom,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Rillaboom, 64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Rillaboom),
        ICON(Rillaboom, 1),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_RILLABOOM_GIGANTAMAX] =
    {
        RILLABOOM_MISC_INFO,
        .height = 280,
        .weight = 0,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        .description = POKEDEX_DESC_STRING(
            "Es kontrolliert die Macht seines\n"
            "speziellen Baumstumpfes durch\n"
            "Trommeln. Im Kampf manipuliert es\n"
            "damit Wurzeln."),
        FRONT_PIC(RillaboomGigantamax, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_RillaboomGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(RillaboomGigantamax, 64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(RillaboomGigantamax),
        ICON(RillaboomGigantamax, 1),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_GROOKEY

#if P_FAMILY_SCORBUNNY
    [SPECIES_SCORBUNNY] =
    {
        .baseHP        = 50,
        .baseAttack    = 71,
        .baseDefense   = 40,
        .baseSpeed     = 69,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 62,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_LIBERO },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Hopplo"),
        .cryId = CRY_SCORBUNNY,
        .natDexNum = NATIONAL_DEX_SCORBUNNY,
        .categoryName = _("Hasen"),
        .height = 3,
        .weight = 45,
        .description = POKEDEX_DESC_STRING(
            "Ist es kampfbereit, verströmt es von\n"
            "seiner Nasenspitze und von den Ballen an\n"
            "seinen Läufen Hitze."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Scorbunny, 40, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Scorbunny,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Scorbunny, 48, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Scorbunny),
        ICON(Scorbunny, 0),
        .footprint = gMonFootprint_Scorbunny,
        LEARNSETS(Scorbunny),
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_RABOOT}),
    },

    [SPECIES_RABOOT] =
    {
        .baseHP        = 65,
        .baseAttack    = 86,
        .baseDefense   = 60,
        .baseSpeed     = 94,
        .baseSpAttack  = 55,
        .baseSpDefense = 60,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 147,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_LIBERO },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Kickerlo"),
        .cryId = CRY_RABOOT,
        .natDexNum = NATIONAL_DEX_RABOOT,
        .categoryName = _("Hasen"),
        .height = 6,
        .weight = 90,
        .description = POKEDEX_DESC_STRING(
            "Sein flauschiges Fell schützt es\n"
            "vor Kälte und ermöglicht es ihm,\n"
            "noch heißere Feuer-Attacken\n"
            "auszuteilen."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Raboot, 40, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Raboot,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Raboot, 56, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Raboot),
        ICON(Raboot, 0),
        .footprint = gMonFootprint_Raboot,
        LEARNSETS(Raboot),
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_CINDERACE}),
    },

#define CINDERACE_MISC_INFO                                             \
        .baseHP        = 80,                                            \
        .baseAttack    = 116,                                           \
        .baseDefense   = 75,                                            \
        .baseSpeed     = 119,                                           \
        .baseSpAttack  = 65,                                            \
        .baseSpDefense = 75,                                            \
        .types = { TYPE_FIRE, TYPE_FIRE },                              \
        .catchRate = 45,                                                \
        .expYield = 265,                                                \
        .evYield_Speed = 3,                                             \
        .genderRatio = PERCENT_FEMALE(12.5),                            \
        .eggCycles = 20,                                                \
        .friendship = STANDARD_FRIENDSHIP,                              \
        .growthRate = GROWTH_MEDIUM_SLOW,                               \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE },         \
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_LIBERO },   \
        .bodyColor = BODY_COLOR_WHITE,                                  \
        .speciesName = _("Kickerlo"),                                  \
        .cryId = CRY_CINDERACE,                                         \
        .natDexNum = NATIONAL_DEX_CINDERACE,                            \
        .categoryName = _("Hasen"),                                   \
        .footprint = gMonFootprint_Cinderace,                           \
        LEARNSETS(Cinderace),                                           \
        .formSpeciesIdTable = sCinderaceFormSpeciesIdTable,             \
        .formChangeTable = sCinderaceFormChangeTable

    [SPECIES_CINDERACE] =
    {
        CINDERACE_MISC_INFO,
        .height = 14,
        .weight = 330,
        .description = POKEDEX_DESC_STRING(
            "Es jongliert kleine Steine mit den\n"
            "Füßen und erschafft daraus einen\n"
            "Flammenfußball. Seine Gegner\n"
            "verbrennt es mit scharfen Schüssen."),
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Cinderace, 40, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Cinderace,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Cinderace, 48, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Cinderace),
        ICON(Cinderace, 0),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_CINDERACE_GIGANTAMAX] =
    {
        CINDERACE_MISC_INFO,
        .height = 270,
        .weight = 0,
        .description = POKEDEX_DESC_STRING(
            "Es jongliert kleine Steine mit den\n"
            "Füßen und erschafft daraus einen\n"
            "Flammenfußball. Seine Gegner\n"
            "verbrennt es mit scharfen Schüssen."),
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(CinderaceGigantamax, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_CinderaceGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(CinderaceGigantamax, 64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(CinderaceGigantamax),
        ICON(CinderaceGigantamax, 0),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_SCORBUNNY

#if P_FAMILY_SOBBLE
    [SPECIES_SOBBLE] =
    {
        .baseHP        = 50,
        .baseAttack    = 40,
        .baseDefense   = 40,
        .baseSpeed     = 70,
        .baseSpAttack  = 70,
        .baseSpDefense = 40,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 62,
        .evYield_Speed = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SNIPER },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Memmeon"),
        .cryId = CRY_SOBBLE,
        .natDexNum = NATIONAL_DEX_SOBBLE,
        .categoryName = _("Wasserechsen"),
        .height = 3,
        .weight = 40,
        .description = POKEDEX_DESC_STRING(
            "Wird seine Haut feucht, ändert sich ihre\n"
            "Farbe. Dies dient ihm zur Tarnung, da man\n"
            "es dann nicht mehr sehen kann."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Sobble, 40, 56),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Sobble,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Sobble, 40, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Sobble),
        ICON(Sobble, 2),
        .footprint = gMonFootprint_Sobble,
        LEARNSETS(Sobble),
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_DRIZZILE}),
    },

    [SPECIES_DRIZZILE] =
    {
        .baseHP        = 65,
        .baseAttack    = 60,
        .baseDefense   = 55,
        .baseSpeed     = 90,
        .baseSpAttack  = 95,
        .baseSpDefense = 55,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 147,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SNIPER },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Phlegleon"),
        .cryId = CRY_DRIZZILE,
        .natDexNum = NATIONAL_DEX_DRIZZILE,
        .categoryName = _("Wasserechsen"),
        .height = 7,
        .weight = 115,
        .description = POKEDEX_DESC_STRING(
            "Das Sekret, das aus seinen\n"
            "Handflächen austritt, formt es zu\n"
            "Wasserkugeln. Diese nutzt es im\n"
            "Kampf für taktisch ausgeklügelte\n"
            "Angriffe."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Drizzile, 40, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Drizzile,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Drizzile, 56, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Drizzile),
        ICON(Drizzile, 2),
        .footprint = gMonFootprint_Drizzile,
        LEARNSETS(Drizzile),
        .evolutions = EVOLUTION({EVO_LEVEL, 35, SPECIES_INTELEON}),
    },

#define INTELEON_MISC_INFO                                              \
        .baseHP        = 70,                                            \
        .baseAttack    = 85,                                            \
        .baseDefense   = 65,                                            \
        .baseSpeed     = 120,                                           \
        .baseSpAttack  = 125,                                           \
        .baseSpDefense = 65,                                            \
        .types = { TYPE_WATER, TYPE_WATER },                            \
        .catchRate = 45,                                                \
        .expYield = 265,                                                \
        .evYield_Speed = 3,                                             \
        .genderRatio = PERCENT_FEMALE(12.5),                            \
        .eggCycles = 20,                                                \
        .friendship = STANDARD_FRIENDSHIP,                              \
        .growthRate = GROWTH_MEDIUM_SLOW,                               \
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },            \
        .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_SNIPER }, \
        .bodyColor = BODY_COLOR_BLUE,                                   \
        .speciesName = _("Phlegleon"),                                   \
        .cryId = CRY_INTELEON,                                          \
        .natDexNum = NATIONAL_DEX_INTELEON,                             \
        .categoryName = _("Wasserechsen"),                              \
        .footprint = gMonFootprint_Inteleon,                            \
        LEARNSETS(Inteleon),                                            \
        .formSpeciesIdTable = sInteleonFormSpeciesIdTable,              \
        .formChangeTable = sInteleonFormChangeTable

    [SPECIES_INTELEON] =
    {
        INTELEON_MISC_INFO,
        .height = 19,
        .weight = 452,
        .description = POKEDEX_DESC_STRING(
            "Zu seinen vielen geheimen Talenten\n"
            "gehört es, Wasser aus den Fingern\n"
            "zu schießen und mit der Membran am\n"
            "Rücken durch die Lüfte zu segeln."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        FRONT_PIC(Inteleon, 48, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Inteleon,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Inteleon, 56, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Inteleon),
        ICON(Inteleon, 0),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_INTELEON_GIGANTAMAX] =
    {
        INTELEON_MISC_INFO,
        .height = 400,
        .weight = 0,
        .description = POKEDEX_DESC_STRING(
            "Zu seinen vielen geheimen Talenten\n"
            "gehört es, Wasser aus den Fingern\n"
            "zu schießen und mit der Membran am\n"
            "Rücken durch die Lüfte zu segeln."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        FRONT_PIC(InteleonGigantamax, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_InteleonGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(InteleonGigantamax, 64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(InteleonGigantamax),
        ICON(InteleonGigantamax, 0),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_SOBBLE

#if P_FAMILY_SKWOVET
    [SPECIES_SKWOVET] =
    {
        .baseHP        = 70,
        .baseAttack    = 55,
        .baseDefense   = 55,
        .baseSpeed     = 25,
        .baseSpAttack  = 35,
        .baseSpDefense = 35,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 55,
        .evYield_HP = 1,
        .itemRare = ITEM_ORAN_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_CHEEK_POUCH, ABILITY_NONE, ABILITY_GLUTTONY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Raffel"),
        .cryId = CRY_SKWOVET,
        .natDexNum = NATIONAL_DEX_SKWOVET,
        .categoryName = _("Raffbacken"),
        .height = 3,
        .weight = 25,
        .description = POKEDEX_DESC_STRING(
            "Da es unentwegt Beeren futtert, ist es\n"
            "zäher als es aussieht. Man sieht es oft\n"
            "auf Feldern, wo es nach Beeren sucht."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Skwovet, 40, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Skwovet,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Skwovet, 64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Skwovet),
        ICON(Skwovet, 2),
        .footprint = gMonFootprint_Skwovet,
        LEARNSETS(Skwovet),
        .evolutions = EVOLUTION({EVO_LEVEL, 24, SPECIES_GREEDENT}),
    },

    [SPECIES_GREEDENT] =
    {
        .baseHP        = 120,
        .baseAttack    = 95,
        .baseDefense   = 95,
        .baseSpeed     = 20,
        .baseSpAttack  = 55,
        .baseSpDefense = 75,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 90,
        .expYield = 161,
        .evYield_HP = 2,
        .itemRare = ITEM_SITRUS_BERRY,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_CHEEK_POUCH, ABILITY_NONE, ABILITY_GLUTTONY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Schlaraffel"),
        .cryId = CRY_GREEDENT,
        .natDexNum = NATIONAL_DEX_GREEDENT,
        .categoryName = _("Gierschlund"),
        .height = 6,
        .weight = 60,
        .description = POKEDEX_DESC_STRING(
            "Es hortet in seinem Schweif Beeren.\n"
            "Versucht es, zu viele\n"
            "unterzubringen, fallen sie heraus.\n"
            "Da es jedoch nicht allzu clever\n"
            "ist, bemerkt es das nicht."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Greedent, 56, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Greedent,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Greedent, 64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Greedent),
        ICON(Greedent, 0),
        .footprint = gMonFootprint_Greedent,
        LEARNSETS(Greedent),
    },
#endif //P_FAMILY_SKWOVET

#if P_FAMILY_ROOKIDEE
    [SPECIES_ROOKIDEE] =
    {
        .baseHP        = 38,
        .baseAttack    = 47,
        .baseDefense   = 35,
        .baseSpeed     = 57,
        .baseSpAttack  = 33,
        .baseSpDefense = 35,
        .types = { TYPE_FLYING, TYPE_FLYING },
        .catchRate = 255,
        .expYield = 49,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_UNNERVE, ABILITY_BIG_PECKS },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Meikro"),
        .cryId = CRY_ROOKIDEE,
        .natDexNum = NATIONAL_DEX_ROOKIDEE,
        .categoryName = _("Kleinvogel"),
        .height = 2,
        .weight = 18,
        .description = POKEDEX_DESC_STRING(
            "Mit seinem kleinen Körper kann es flink\n"
            "fliegen und so mithilfe von trickreichen\n"
            "Taktiken größere Gegner überlisten."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Rookidee, 40, 40),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Rookidee,
        .frontAnimId = ANIM_H_VIBRATE,
        BACK_PIC(Rookidee, 64, 32),
        .backPicYOffset = 17,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Rookidee),
        ICON(Rookidee, 0),
        .footprint = gMonFootprint_Rookidee,
        LEARNSETS(Rookidee),
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_CORVISQUIRE}),
    },

    [SPECIES_CORVISQUIRE] =
    {
        .baseHP        = 68,
        .baseAttack    = 67,
        .baseDefense   = 55,
        .baseSpeed     = 77,
        .baseSpAttack  = 43,
        .baseSpDefense = 55,
        .types = { TYPE_FLYING, TYPE_FLYING },
        .catchRate = 120,
        .expYield = 128,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_UNNERVE, ABILITY_BIG_PECKS },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Kranoviz"),
        .cryId = CRY_CORVISQUIRE,
        .natDexNum = NATIONAL_DEX_CORVISQUIRE,
        .categoryName = _("Krähen"),
        .height = 8,
        .weight = 160,
        .description = POKEDEX_DESC_STRING(
            "Es hat viele heftige Kämpfe überstanden\n"
            "und dabei gelernt, die Stärke seiner\n"
            "Gegner stets korrekt einzuschätzen."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Corvisquire, 64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Corvisquire,
        .frontAnimId = ANIM_CIRCLE_INTO_BG,
        .enemyMonElevation = 10,
        BACK_PIC(Corvisquire, 56, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Corvisquire),
        ICON(Corvisquire, 0),
        .footprint = gMonFootprint_Corvisquire,
        LEARNSETS(Corvisquire),
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_CORVIKNIGHT}),
    },

#define CORVIKNIGHT_MISC_INFO                                                       \
        .baseHP        = 98,                                                        \
        .baseAttack    = 87,                                                        \
        .baseDefense   = 105,                                                       \
        .baseSpeed     = 67,                                                        \
        .baseSpAttack  = 53,                                                        \
        .baseSpDefense = 85,                                                        \
        .types = { TYPE_FLYING, TYPE_STEEL },                                       \
        .catchRate = 45,                                                            \
        .expYield = 248,                                                            \
        .evYield_Defense = 3,                                                       \
        .genderRatio = PERCENT_FEMALE(50),                                          \
        .eggCycles = 15,                                                            \
        .friendship = STANDARD_FRIENDSHIP,                                          \
        .growthRate = GROWTH_MEDIUM_SLOW,                                           \
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },                        \
        .abilities = { ABILITY_PRESSURE, ABILITY_UNNERVE, ABILITY_MIRROR_ARMOR },   \
        .bodyColor = BODY_COLOR_PURPLE,                                             \
        .speciesName = _("Kranoviz"),                                             \
        .cryId = CRY_CORVIKNIGHT,                                                   \
        .natDexNum = NATIONAL_DEX_CORVIKNIGHT,                                      \
        .categoryName = _("Krähen"),                                                 \
        .footprint = gMonFootprint_Corviknight,                                     \
        LEARNSETS(Corviknight),                                                     \
        .formSpeciesIdTable = sCorviknightFormSpeciesIdTable,                       \
        .formChangeTable = sCorviknightFormChangeTable

    [SPECIES_CORVIKNIGHT] =
    {
        CORVIKNIGHT_MISC_INFO,
        .height = 22,
        .weight = 750,
        .description = POKEDEX_DESC_STRING(
            "Niemand wagt es, ihm den Himmel\n"
            "über Galar streitig zu machen. Sein\n"
            "schwarz glänzendes, stählernes\n"
            "Äußeres schüchtert jeden Gegner\n"
            "ein."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 348,
        .trainerOffset = 6,
        FRONT_PIC(Corviknight, 56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Corviknight,
        .frontAnimId = ANIM_H_VIBRATE,
        BACK_PIC(Corviknight, 64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Corviknight),
        ICON(Corviknight, 0),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_CORVIKNIGHT_GIGANTAMAX] =
    {
        CORVIKNIGHT_MISC_INFO,
        .height = 140,
        .weight = 0,
        .description = POKEDEX_DESC_STRING(
            "Niemand wagt es, ihm den Himmel\n"
            "über Galar streitig zu machen. Sein\n"
            "schwarz glänzendes, stählernes\n"
            "Äußeres schüchtert jeden Gegner\n"
            "ein."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 348,
        .trainerOffset = 6,
        FRONT_PIC(CorviknightGigantamax, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_CorviknightGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(CorviknightGigantamax, 64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(CorviknightGigantamax),
        ICON(CorviknightGigantamax, 0),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_ROOKIDEE

#if P_FAMILY_BLIPBUG
    [SPECIES_BLIPBUG] =
    {
        .baseHP        = 25,
        .baseAttack    = 20,
        .baseDefense   = 20,
        .baseSpeed     = 45,
        .baseSpAttack  = 25,
        .baseSpDefense = 45,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 255,
        .expYield = 36,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_COMPOUND_EYES, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Sensect"),
        .cryId = CRY_BLIPBUG,
        .natDexNum = NATIONAL_DEX_BLIPBUG,
        .categoryName = _("Larven"),
        .height = 4,
        .weight = 80,
        .description = POKEDEX_DESC_STRING(
            "Sensect ist ein schlaues Pokémon,\n"
            "da es immer fleißig Informationen\n"
            "sammelt. Seine Stärke lässt jedoch\n"
            "zu wünschen übrig."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Blipbug, 32, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Blipbug,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Blipbug, 40, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Blipbug),
        ICON(Blipbug, 0),
        .footprint = gMonFootprint_Blipbug,
        LEARNSETS(Blipbug),
        .evolutions = EVOLUTION({EVO_LEVEL, 10, SPECIES_DOTTLER}),
    },

    [SPECIES_DOTTLER] =
    {
        .baseHP        = 50,
        .baseAttack    = 35,
        .baseDefense   = 80,
        .baseSpeed     = 30,
        .baseSpAttack  = 50,
        .baseSpDefense = 90,
        .types = { TYPE_BUG, TYPE_PSYCHIC },
        .catchRate = 120,
        .expYield = 117,
        .evYield_SpDefense = 2,
        .itemRare = ITEM_PSYCHIC_SEED,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_COMPOUND_EYES, ABILITY_TELEPATHY },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Keradar"),
        .cryId = CRY_DOTTLER,
        .natDexNum = NATIONAL_DEX_DOTTLER,
        .categoryName = _("Radarkuppel"),
        .height = 4,
        .weight = 195,
        .description = POKEDEX_DESC_STRING(
            "Im Inneren seines Panzers wächst es.\n"
            "Während es sich auf die Entwicklung\n"
            "vorbereitet, prüft es mit seinen\n"
            "Psycho-Kräften, was im Freien geschieht."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Dottler, 48, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Dottler,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Dottler, 56, 32),
        .backPicYOffset = 17,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Dottler),
        ICON(Dottler, 2),
        .footprint = gMonFootprint_Dottler,
        LEARNSETS(Dottler),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_ORBEETLE}),
    },

#define ORBEETLE_MISC_INFO                                                  \
        .baseHP        = 60,                                                \
        .baseAttack    = 45,                                                \
        .baseDefense   = 110,                                               \
        .baseSpeed     = 90,                                                \
        .baseSpAttack  = 80,                                                \
        .baseSpDefense = 120,                                               \
        .types = { TYPE_BUG, TYPE_PSYCHIC },                                \
        .catchRate = 45,                                                    \
        .expYield = 253,                                                    \
        .evYield_SpDefense = 3,                                             \
        .itemRare = ITEM_PSYCHIC_SEED,                                      \
        .genderRatio = PERCENT_FEMALE(50),                                  \
        .eggCycles = 15,                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                  \
        .growthRate = GROWTH_MEDIUM_FAST,                                   \
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },                      \
        .abilities = { ABILITY_SWARM, ABILITY_FRISK, ABILITY_TELEPATHY },   \
        .bodyColor = BODY_COLOR_RED,                                        \
        .speciesName = _("Keradar"),                                       \
        .cryId = CRY_ORBEETLE,                                              \
        .natDexNum = NATIONAL_DEX_ORBEETLE,                                 \
        .categoryName = _("Radarkuppel"),                                    \
        .footprint = gMonFootprint_Orbeetle,                                \
        LEARNSETS(Orbeetle),                                                \
        .formSpeciesIdTable = sOrbeetleFormSpeciesIdTable,                  \
        .formChangeTable = sOrbeetleFormChangeTable

    [SPECIES_ORBEETLE] =
    {
        ORBEETLE_MISC_INFO,
        .height = 4,
        .weight = 408,
        .description = POKEDEX_DESC_STRING(
            "Es ist allseits als sehr schlaues\n"
            "Pokémon bekannt. Sein großes Gehirn\n"
            "ist ein Indiz dafür, dass es über\n"
            "mächtige Psycho-Kräfte verfügt."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Orbeetle, 48, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Orbeetle,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        BACK_PIC(Orbeetle, 64, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Orbeetle),
        ICON(Orbeetle, 0),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_ORBEETLE_GIGANTAMAX] =
    {
        ORBEETLE_MISC_INFO,
        .height = 140,
        .weight = 0,
        .description = POKEDEX_DESC_STRING(
            "Es ist allseits als sehr schlaues\n"
            "Pokémon bekannt. Sein großes Gehirn\n"
            "ist ein Indiz dafür, dass es über\n"
            "mächtige Psycho-Kräfte verfügt."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(OrbeetleGigantamax, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_OrbeetleGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(OrbeetleGigantamax, 64, 64),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(OrbeetleGigantamax),
        ICON(OrbeetleGigantamax, 0),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_BLIPBUG

#if P_FAMILY_NICKIT
    [SPECIES_NICKIT] =
    {
        .baseHP        = 40,
        .baseAttack    = 28,
        .baseDefense   = 28,
        .baseSpeed     = 50,
        .baseSpAttack  = 47,
        .baseSpDefense = 52,
        .types = { TYPE_DARK, TYPE_DARK },
        .catchRate = 255,
        .expYield = 49,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RUN_AWAY, ABILITY_UNBURDEN, ABILITY_STAKEOUT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Kleptifux"),
        .cryId = CRY_NICKIT,
        .natDexNum = NATIONAL_DEX_NICKIT,
        .categoryName = _("Fuchs"),
        .height = 6,
        .weight = 89,
        .description = POKEDEX_DESC_STRING(
            "Es stibitzt Futter, das andere\n"
            "Pokémon gefunden haben. Dank der\n"
            "samtweichen Ballen an seinen Pfoten\n"
            "ist sein Gang lautlos."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Nickit, 56, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Nickit,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Nickit, 64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Nickit),
        ICON(Nickit, 2),
        .footprint = gMonFootprint_Nickit,
        LEARNSETS(Nickit),
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_THIEVUL}),
    },

    [SPECIES_THIEVUL] =
    {
        .baseHP        = 70,
        .baseAttack    = 58,
        .baseDefense   = 58,
        .baseSpeed     = 90,
        .baseSpAttack  = 87,
        .baseSpDefense = 92,
        .types = { TYPE_DARK, TYPE_DARK },
        .catchRate = 127,
        .expYield = 159,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RUN_AWAY, ABILITY_UNBURDEN, ABILITY_STAKEOUT },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Gaunux"),
        .cryId = CRY_THIEVUL,
        .natDexNum = NATIONAL_DEX_THIEVUL,
        .categoryName = _("Fuchs"),
        .height = 12,
        .weight = 199,
        .description = POKEDEX_DESC_STRING(
            "Dank seines agilen Körpers und seiner\n"
            "scharfen Klauen ist es ihm ein Leichtes,\n"
            "überall Futter und Eier zu stehlen.\n"
            "Bellektro ist sein Erzfeind."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Thievul, 64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Thievul,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Thievul, 56, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Thievul),
        ICON(Thievul, 2),
        .footprint = gMonFootprint_Thievul,
        LEARNSETS(Thievul),
    },
#endif //P_FAMILY_NICKIT

#if P_FAMILY_GOSSIFLEUR
    [SPECIES_GOSSIFLEUR] =
    {
        .baseHP        = 40,
        .baseAttack    = 40,
        .baseDefense   = 60,
        .baseSpeed     = 10,
        .baseSpAttack  = 40,
        .baseSpDefense = 60,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 190,
        .expYield = 50,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_COTTON_DOWN, ABILITY_REGENERATOR, ABILITY_EFFECT_SPORE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Cottini"),
        .cryId = CRY_GOSSIFLEUR,
        .natDexNum = NATIONAL_DEX_GOSSIFLEUR,
        .categoryName = _("Blumenzier"),
        .height = 4,
        .weight = 22,
        .description = POKEDEX_DESC_STRING(
            "Steckt es sein Beinchen fest in den\n"
            "Boden und badet dann ausgiebig im\n"
            "Sonnenlicht, nimmt seine Blüte eine\n"
            "kräftigere Farbe an."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Gossifleur, 48, 56),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Gossifleur,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Gossifleur, 56, 48),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Gossifleur),
        ICON(Gossifleur, 1),
        .footprint = gMonFootprint_Gossifleur,
        LEARNSETS(Gossifleur),
        .evolutions = EVOLUTION({EVO_LEVEL, 20, SPECIES_ELDEGOSS}),
    },

    [SPECIES_ELDEGOSS] =
    {
        .baseHP        = 60,
        .baseAttack    = 50,
        .baseDefense   = 90,
        .baseSpeed     = 60,
        .baseSpAttack  = 80,
        .baseSpDefense = 120,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 75,
        .expYield = 161,
        .evYield_SpDefense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_COTTON_DOWN, ABILITY_REGENERATOR, ABILITY_EFFECT_SPORE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Cottomi"),
        .cryId = CRY_ELDEGOSS,
        .natDexNum = NATIONAL_DEX_ELDEGOSS,
        .categoryName = _("Baumwollzier"),
        .height = 5,
        .weight = 25,
        .description = POKEDEX_DESC_STRING(
            "Die Saat seines Wollflaums steckt\n"
            "voller Nährstoffe. Es verstreut sie\n"
            "im Wind und heilt damit Pflanzen\n"
            "und Pokémon."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Eldegoss, 48, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Eldegoss,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Eldegoss, 64, 40),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Eldegoss),
        ICON(Eldegoss, 1),
        .footprint = gMonFootprint_Eldegoss,
        LEARNSETS(Eldegoss),
    },
#endif //P_FAMILY_GOSSIFLEUR

#if P_FAMILY_WOOLOO
    [SPECIES_WOOLOO] =
    {
        .baseHP        = 42,
        .baseAttack    = 40,
        .baseDefense   = 55,
        .baseSpeed     = 48,
        .baseSpAttack  = 40,
        .baseSpDefense = 45,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 122,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_FLUFFY, ABILITY_RUN_AWAY, ABILITY_BULLETPROOF },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Wolly"),
        .cryId = CRY_WOOLOO,
        .natDexNum = NATIONAL_DEX_WOOLOO,
        .categoryName = _("Schaf"),
        .height = 6,
        .weight = 60,
        .description = POKEDEX_DESC_STRING(
            "Sein stark gelocktes Fell hat eine\n"
            "sehr polsternde Wirkung. Selbst\n"
            "eine Klippe hinunterzufallen macht\n"
            "ihm nichts aus."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Wooloo, 40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Wooloo,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Wooloo, 56, 32),
        .backPicYOffset = 18,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Wooloo),
        ICON(Wooloo, 0),
        .footprint = gMonFootprint_Wooloo,
        LEARNSETS(Wooloo),
        .evolutions = EVOLUTION({EVO_LEVEL, 24, SPECIES_DUBWOOL}),
    },

    [SPECIES_DUBWOOL] =
    {
        .baseHP        = 72,
        .baseAttack    = 80,
        .baseDefense   = 100,
        .baseSpeed     = 88,
        .baseSpAttack  = 60,
        .baseSpDefense = 90,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 127,
        .expYield = 172,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_FLUFFY, ABILITY_STEADFAST, ABILITY_BULLETPROOF },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Zwollock"),
        .cryId = CRY_DUBWOOL,
        .natDexNum = NATIONAL_DEX_DUBWOOL,
        .categoryName = _("Schaf"),
        .height = 13,
        .weight = 430,
        .description = POKEDEX_DESC_STRING(
            "Seine prächtig gewachsenen Hörner dienen\n"
            "dazu, dem anderen Geschlecht zu\n"
            "imponieren. Es nutzt sie nicht als Waffe."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Dubwool, 48, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Dubwool,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Dubwool, 64, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Dubwool),
        ICON(Dubwool, 2),
        .footprint = gMonFootprint_Dubwool,
        LEARNSETS(Dubwool),
    },
#endif //P_FAMILY_WOOLOO

#if P_FAMILY_CHEWTLE
    [SPECIES_CHEWTLE] =
    {
        .baseHP        = 50,
        .baseAttack    = 64,
        .baseDefense   = 50,
        .baseSpeed     = 44,
        .baseSpAttack  = 38,
        .baseSpDefense = 38,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 255,
        .expYield = 57,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1 },
        .abilities = { ABILITY_STRONG_JAW, ABILITY_SHELL_ARMOR, ABILITY_SWIFT_SWIM },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Kamehaps"),
        .cryId = CRY_CHEWTLE,
        .natDexNum = NATIONAL_DEX_CHEWTLE,
        .categoryName = _("Schnapp"),
        .height = 3,
        .weight = 85,
        .description = POKEDEX_DESC_STRING(
            "Es schnappt sofort nach allem, was\n"
            "ihm unterkommt. Der Grund dafür ist\n"
            "anscheinend, dass seine wachsenden\n"
            "Vorderzähne jucken."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Chewtle, 32, 48),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Chewtle,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Chewtle, 56, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Chewtle),
        ICON(Chewtle, 0),
        .footprint = gMonFootprint_Chewtle,
        LEARNSETS(Chewtle),
        .evolutions = EVOLUTION({EVO_LEVEL, 22, SPECIES_DREDNAW}),
    },

#define DREDNAW_MISC_INFO                                                               \
        .baseHP        = 90,                                                            \
        .baseAttack    = 115,                                                           \
        .baseDefense   = 90,                                                            \
        .baseSpeed     = 74,                                                            \
        .baseSpAttack  = 48,                                                            \
        .baseSpDefense = 68,                                                            \
        .types = { TYPE_WATER, TYPE_ROCK },                                             \
        .catchRate = 75,                                                                \
        .expYield = 170,                                                                \
        .evYield_Attack = 2,                                                            \
        .genderRatio = PERCENT_FEMALE(50),                                              \
        .eggCycles = 20,                                                                \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_MEDIUM_FAST,                                               \
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_WATER_1 },                          \
        .abilities = { ABILITY_STRONG_JAW, ABILITY_SHELL_ARMOR, ABILITY_SWIFT_SWIM },   \
        .bodyColor = BODY_COLOR_GREEN,                                                  \
        .speciesName = _("Kamehaps"),                                                    \
        .cryId = CRY_DREDNAW,                                                           \
        .natDexNum = NATIONAL_DEX_DREDNAW,                                              \
        .categoryName = _("Schnapp"),                                                      \
        .footprint = gMonFootprint_Drednaw,                                             \
        LEARNSETS(Drednaw),                                                             \
        .formSpeciesIdTable = sDrednawFormSpeciesIdTable,                               \
        .formChangeTable = sDrednawFormChangeTable

    [SPECIES_DREDNAW] =
    {
        DREDNAW_MISC_INFO,
        .height = 10,
        .weight = 1155,
        .description = POKEDEX_DESC_STRING(
            "Dieses von Natur aus aggressive\n"
            "Pokémon beißt seine Beute mit\n"
            "seinem kräftigen Kiefer, der selbst\n"
            "Eisenstangen zermalmen kann."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Drednaw, 64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Drednaw,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Drednaw, 64, 40),
        .backPicYOffset = 18,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Drednaw),
        ICON(Drednaw, 0),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_DREDNAW_GIGANTAMAX] =
    {
        DREDNAW_MISC_INFO,
        .height = 240,
        .weight = 0,
        .description = POKEDEX_DESC_STRING(
            "Dieses von Natur aus aggressive\n"
            "Pokémon beißt seine Beute mit\n"
            "seinem kräftigen Kiefer, der selbst\n"
            "Eisenstangen zermalmen kann."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(DrednawGigantamax, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_DrednawGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(DrednawGigantamax, 64, 64),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(DrednawGigantamax),
        ICON(DrednawGigantamax, 0),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_CHEWTLE

#if P_FAMILY_YAMPER
    [SPECIES_YAMPER] =
    {
        .baseHP        = 59,
        .baseAttack    = 45,
        .baseDefense   = 50,
        .baseSpeed     = 26,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 255,
        .expYield = 54,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_BALL_FETCH, ABILITY_NONE, ABILITY_RATTLED },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Voldi"),
        .cryId = CRY_YAMPER,
        .natDexNum = NATIONAL_DEX_YAMPER,
        .categoryName = _("Welpen"),
        .height = 3,
        .weight = 135,
        .description = POKEDEX_DESC_STRING(
            "Beim Rennen erzeugt es Elektrizität\n"
            "in seinem Schwanzansatz. In der\n"
            "Galar-Region erfreut es sich bei\n"
            "Hirten großer Beliebtheit."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Yamper, 40, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Yamper,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Yamper, 48, 48),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Yamper),
        ICON(Yamper, 1),
        .footprint = gMonFootprint_Yamper,
        LEARNSETS(Yamper),
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_BOLTUND}),
    },

    [SPECIES_BOLTUND] =
    {
        .baseHP        = 69,
        .baseAttack    = 90,
        .baseDefense   = 60,
        .baseSpeed     = 121,
        .baseSpAttack  = 90,
        .baseSpDefense = 60,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 45,
        .expYield = 172,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_STRONG_JAW, ABILITY_NONE, ABILITY_COMPETITIVE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Bellektro"),
        .cryId = CRY_BOLTUND,
        .natDexNum = NATIONAL_DEX_BOLTUND,
        .categoryName = _("Hunde"),
        .height = 10,
        .weight = 340,
        .description = POKEDEX_DESC_STRING(
            "Es generiert Strom und lässt ihn\n"
            "zur Unterstützung beim Rennen in\n"
            "seine Beine fließen. Dadurch kann\n"
            "es drei Tage und Nächte ohne Pause\n"
            "rennen."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Boltund, 48, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Boltund,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Boltund, 64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Boltund),
        ICON(Boltund, 1),
        .footprint = gMonFootprint_Boltund,
        LEARNSETS(Boltund),
    },
#endif //P_FAMILY_YAMPER

#if P_FAMILY_ROLYCOLY
    [SPECIES_ROLYCOLY] =
    {
        .baseHP        = 30,
        .baseAttack    = 40,
        .baseDefense   = 50,
        .baseSpeed     = 30,
        .baseSpAttack  = 40,
        .baseSpDefense = 50,
        .types = { TYPE_ROCK, TYPE_ROCK },
        .catchRate = 255,
        .expYield = 48,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_STEAM_ENGINE, ABILITY_HEATPROOF, ABILITY_FLASH_FIRE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Klonkett"),
        .cryId = CRY_ROLYCOLY,
        .natDexNum = NATIONAL_DEX_ROLYCOLY,
        .categoryName = _("Kohle"),
        .height = 3,
        .weight = 120,
        .description = POKEDEX_DESC_STRING(
            "Es wurde vor circa 400 Jahren in\n"
            "einer Kohlemine entdeckt. Sein\n"
            "Körper besteht fast aus denselben\n"
            "Komponenten wie Steinkohle."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Rolycoly, 40, 40),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Rolycoly,
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        BACK_PIC(Rolycoly, 64, 32),
        .backPicYOffset = 17,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Rolycoly),
        ICON(Rolycoly, 0),
        .footprint = gMonFootprint_Rolycoly,
        LEARNSETS(Rolycoly),
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_CARKOL}),
    },

    [SPECIES_CARKOL] =
    {
        .baseHP        = 80,
        .baseAttack    = 60,
        .baseDefense   = 90,
        .baseSpeed     = 50,
        .baseSpAttack  = 60,
        .baseSpDefense = 70,
        .types = { TYPE_ROCK, TYPE_FIRE },
        .catchRate = 120,
        .expYield = 144,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_STEAM_ENGINE, ABILITY_FLAME_BODY, ABILITY_FLASH_FIRE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Wagong"),
        .cryId = CRY_CARKOL,
        .natDexNum = NATIONAL_DEX_CARKOL,
        .categoryName = _("Kohle"),
        .height = 11,
        .weight = 780,
        .description = POKEDEX_DESC_STRING(
            "Es dreht seine Füße mit hoher\n"
            "Geschwindigkeit und kann sich dadurch bis\n"
            "zu 30 km/h schnell bewegen. Es speit 1 000\n"
            "ÂºC heiße Flammen."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Carkol, 48, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Carkol,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Carkol, 64, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Carkol),
        ICON(Carkol, 0),
        .footprint = gMonFootprint_Carkol,
        LEARNSETS(Carkol),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_COALOSSAL}),
    },

#define COALOSSAL_MISC_INFO                                                             \
        .baseHP        = 110,                                                           \
        .baseAttack    = 80,                                                            \
        .baseDefense   = 120,                                                           \
        .baseSpeed     = 30,                                                            \
        .baseSpAttack  = 80,                                                            \
        .baseSpDefense = 90,                                                            \
        .types = { TYPE_ROCK, TYPE_FIRE },                                              \
        .catchRate = 45,                                                                \
        .expYield = 255,                                                                \
        .evYield_Defense = 3,                                                           \
        .genderRatio = PERCENT_FEMALE(50),                                              \
        .eggCycles = 15,                                                                \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_MEDIUM_SLOW,                                               \
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },                          \
        .abilities = { ABILITY_STEAM_ENGINE, ABILITY_FLAME_BODY, ABILITY_FLASH_FIRE },  \
        .bodyColor = BODY_COLOR_BLACK,                                                  \
        .speciesName = _("Wagong"),                                                  \
        .cryId = CRY_COALOSSAL,                                                         \
        .natDexNum = NATIONAL_DEX_COALOSSAL,                                            \
        .categoryName = _("Kohle"),                                                      \
        .footprint = gMonFootprint_Coalossal,                                           \
        LEARNSETS(Coalossal),                                                           \
        .formSpeciesIdTable = sCoalossalFormSpeciesIdTable,                             \
        .formChangeTable = sCoalossalFormChangeTable

    [SPECIES_COALOSSAL] =
    {
        COALOSSAL_MISC_INFO,
        .height = 28,
        .weight = 3105,
        .description = POKEDEX_DESC_STRING(
            "Meist ist es friedfertig, aber wenn\n"
            "Menschen eine Mine zugrunde\n"
            "richten, sieht es rot und verbrennt\n"
            "sie mit 1 500 ÂºC heißen Flammen."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Coalossal, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Coalossal,
        .frontAnimId = ANIM_GLOW_RED,
        BACK_PIC(Coalossal, 64, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Coalossal),
        ICON(Coalossal, 0),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_COALOSSAL_GIGANTAMAX] =
    {
        COALOSSAL_MISC_INFO,
        .height = 420,
        .weight = 0,
        .description = POKEDEX_DESC_STRING(
            "Meist ist es friedfertig, aber wenn\n"
            "Menschen eine Mine zugrunde\n"
            "richten, sieht es rot und verbrennt\n"
            "sie mit 1 500 ÂºC heißen Flammen."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(CoalossalGigantamax, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_CoalossalGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(CoalossalGigantamax, 64, 64),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(CoalossalGigantamax),
        ICON(CoalossalGigantamax, 0),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_ROLYCOLY

#if P_FAMILY_APPLIN
    [SPECIES_APPLIN] =
    {
        .baseHP        = 40,
        .baseAttack    = 40,
        .baseDefense   = 80,
        .baseSpeed     = 20,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = { TYPE_GRASS, TYPE_DRAGON },
        .catchRate = 255,
        .expYield = 52,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_RIPEN, ABILITY_GLUTTONY, ABILITY_BULLETPROOF },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Knapfel"),
        .cryId = CRY_APPLIN,
        .natDexNum = NATIONAL_DEX_APPLIN,
        .categoryName = _("Apfelhaus"),
        .height = 2,
        .weight = 5,
        .description = POKEDEX_DESC_STRING(
            "Nach der Geburt kriecht es sofort in einen\n"
            "Apfel und verspeist dessen Inneres, um zu\n"
            "wachsen. Seine Entwicklung hängt von\n"
            "dessen Aroma ab."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Applin, 32, 40),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Applin,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Applin, 40, 48),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Applin),
        ICON(Applin, 1),
        .footprint = gMonFootprint_Applin,
        LEARNSETS(Applin),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_TART_APPLE, SPECIES_FLAPPLE},
                                {EVO_ITEM, ITEM_SWEET_APPLE, SPECIES_APPLETUN},
                                {EVO_ITEM, ITEM_SYRUPY_APPLE, SPECIES_DIPPLIN}),
    },

#define FLAPPLE_MISC_INFO                                                   \
        .baseHP        = 70,                                                \
        .baseAttack    = 110,                                               \
        .baseDefense   = 80,                                                \
        .baseSpeed     = 70,                                                \
        .baseSpAttack  = 95,                                                \
        .baseSpDefense = 60,                                                \
        .types = { TYPE_GRASS, TYPE_DRAGON },                               \
        .catchRate = 45,                                                    \
        .expYield = 170,                                                    \
        .evYield_Attack = 2,                                                \
        .genderRatio = PERCENT_FEMALE(50),                                  \
        .eggCycles = 20,                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                  \
        .growthRate = GROWTH_ERRATIC,                                       \
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_DRAGON },                 \
        .abilities = { ABILITY_RIPEN, ABILITY_GLUTTONY, ABILITY_HUSTLE },   \
        .bodyColor = BODY_COLOR_GREEN,                                      \
        .speciesName = _("Knapfel"),                                        \
        .cryId = CRY_FLAPPLE,                                               \
        .natDexNum = NATIONAL_DEX_FLAPPLE,                                  \
        .categoryName = _("Apfelhaus"),                                    \
        .footprint = gMonFootprint_Flapple,                                 \
        LEARNSETS(Flapple),                                                 \
        .formSpeciesIdTable = sFlappleFormSpeciesIdTable,                   \
        .formChangeTable = sFlappleFormChangeTable

    [SPECIES_FLAPPLE] =
    {
        FLAPPLE_MISC_INFO,
        .height = 3,
        .weight = 10,
        .description = POKEDEX_DESC_STRING(
            "Nach dem Verzehr eines sauren\n"
            "Apfels hat es sich entwickelt. In\n"
            "den Backentaschen speichert es eine\n"
            "saure Substanz, die zu\n"
            "Verbrennungen führt."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Flapple, 56, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Flapple,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 9,
        BACK_PIC(Flapple, 48, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Flapple),
        ICON(Flapple, 1),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_FLAPPLE_GIGANTAMAX] =
    {
        FLAPPLE_MISC_INFO,
        .height = 240,
        .weight = 0,
        .description = POKEDEX_DESC_STRING(
            "Nach dem Verzehr eines sauren\n"
            "Apfels hat es sich entwickelt. In\n"
            "den Backentaschen speichert es eine\n"
            "saure Substanz, die zu\n"
            "Verbrennungen führt."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(FlappleGigantamax, 64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_FlappleGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(FlappleGigantamax, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(FlappleGigantamax),
        ICON(FlappleGigantamax, 1),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS

#define APPLETUN_MISC_INFO                                                      \
        .baseHP        = 110,                                                   \
        .baseAttack    = 85,                                                    \
        .baseDefense   = 80,                                                    \
        .baseSpeed     = 30,                                                    \
        .baseSpAttack  = 100,                                                   \
        .baseSpDefense = 80,                                                    \
        .types = { TYPE_GRASS, TYPE_DRAGON },                                   \
        .catchRate = 45,                                                        \
        .expYield = 170,                                                        \
        .evYield_HP = 2,                                                        \
        .genderRatio = PERCENT_FEMALE(50),                                      \
        .eggCycles = 20,                                                        \
        .friendship = STANDARD_FRIENDSHIP,                                      \
        .growthRate = GROWTH_ERRATIC,                                           \
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_DRAGON },                     \
        .abilities = { ABILITY_RIPEN, ABILITY_GLUTTONY, ABILITY_THICK_FAT },    \
        .bodyColor = BODY_COLOR_GREEN,                                          \
        .speciesName = _("Drapfel"),                                           \
        .cryId = CRY_APPLETUN,                                                  \
        .natDexNum = NATIONAL_DEX_APPLETUN,                                     \
        .categoryName = _("Apfelflügel"),                                      \
        .footprint = gMonFootprint_Appletun,                                    \
        LEARNSETS(Appletun),                                                    \
        .formSpeciesIdTable = sAppletunFormSpeciesIdTable,                      \
        .formChangeTable = sAppletunFormChangeTable

    [SPECIES_APPLETUN] =
    {
        APPLETUN_MISC_INFO,
        .height = 4,
        .weight = 130,
        .description = POKEDEX_DESC_STRING(
            "Nach dem Verzehr eines süßen Apfels\n"
            "hat es sich entwickelt. Es\n"
            "verströmt einen süßen Duft und\n"
            "lockt damit sein Futter an: Käfer-\n"
            "Pokémon."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Appletun, 64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Appletun,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Appletun, 64, 56),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Appletun),
        ICON(Appletun, 1),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_APPLETUN_GIGANTAMAX] =
    {
        APPLETUN_MISC_INFO,
        .height = 240,
        .weight = 0,
        .description = POKEDEX_DESC_STRING(
            "Nach dem Verzehr eines süßen Apfels\n"
            "hat es sich entwickelt. Es\n"
            "verströmt einen süßen Duft und\n"
            "lockt damit sein Futter an: Käfer-\n"
            "Pokémon."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(AppletunGigantamax, 64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_AppletunGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(AppletunGigantamax, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(AppletunGigantamax),
        ICON(AppletunGigantamax, 1),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS

#if P_GEN_9_CROSS_EVOS
    [SPECIES_DIPPLIN] =
    {
        .baseHP        = 80,
        .baseAttack    = 80,
        .baseDefense   = 110,
        .baseSpeed     = 40,
        .baseSpAttack  = 95,
        .baseSpDefense = 80,
        .types = { TYPE_GRASS, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 170,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_SUPERSWEET_SYRUP, ABILITY_GLUTTONY, ABILITY_STICKY_HOLD },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Sirapfel"),
        .cryId = CRY_DIPPLIN,
        .natDexNum = NATIONAL_DEX_DIPPLIN,
        .categoryName = _("Süßer Apfel"),
        .height = 4,
        .weight = 44,
        .description = POKEDEX_DESC_STRING(
            "Dipplin ist zwei Kreaturen in einem\n"
            "Pokémon. Seine Entwicklung wurde durch\n"
            "einen besonderen Apfel ausgelöst, der nur\n"
            "an einem Ort angebaut wurde."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Dipplin, 64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Dipplin,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Dipplin, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Dipplin),
        ICON(Dipplin, 1),
        //.footprint = gMonFootprint_Dipplin,
        LEARNSETS(Dipplin),
        .evolutions = EVOLUTION({EVO_MOVE, MOVE_DRAGON_CHEER, SPECIES_HYDRAPPLE}),
    },

    [SPECIES_HYDRAPPLE] =
    {
        .baseHP        = 106,
        .baseAttack    = 80,
        .baseDefense   = 110,
        .baseSpeed     = 44,
        .baseSpAttack  = 120,
        .baseSpDefense = 80,
        .types = { TYPE_GRASS, TYPE_DRAGON },
        .catchRate = 10,
        .expYield = 270,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_SUPERSWEET_SYRUP, ABILITY_REGENERATOR, ABILITY_STICKY_HOLD },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Hydrapfel"),
        .cryId = CRY_HYDRAPPLE,
        .natDexNum = NATIONAL_DEX_HYDRAPPLE,
        .categoryName = _("Apfelhydra"),
        .height = 18,
        .weight = 930,
        .description = COMPOUND_STRING(
            "Diese launischen Schlangen haben sich\n"
            "zusammengeschlossen. Wenn ihre Stimmungen\n"
            "übereinstimmen, entfaltet sich ihre wahre\n"
            "Kraft."),
        .pokemonScale = 356,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Hydrapple,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Hydrapple,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Hydrapple,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Hydrapple,
        .shinyPalette = gMonShinyPalette_Hydrapple,
        .iconSprite = gMonIcon_Hydrapple,
        .iconPalIndex = 5,
        //FOOTPRINT(Hydrapple)
        //.levelUpLearnset = sHydrappleLevelUpLearnset,
        //.teachableLearnset = sHydrappleTeachableLearnset,
    },
#endif //P_GEN_9_CROSS_EVOS
#endif //P_FAMILY_APPLIN

#if P_FAMILY_SILICOBRA
    [SPECIES_SILICOBRA] =
    {
        .baseHP        = 52,
        .baseAttack    = 57,
        .baseDefense   = 75,
        .baseSpeed     = 46,
        .baseSpAttack  = 35,
        .baseSpDefense = 50,
        .types = { TYPE_GROUND, TYPE_GROUND },
        .catchRate = 255,
        .expYield = 63,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_SAND_SPIT, ABILITY_SHED_SKIN, ABILITY_SAND_VEIL },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Salanga"),
        .cryId = CRY_SILICOBRA,
        .natDexNum = NATIONAL_DEX_SILICOBRA,
        .categoryName = _("Sandschlangen"),
        .height = 22,
        .weight = 76,
        .description = POKEDEX_DESC_STRING(
            "Den Sand, den es beim Graben von\n"
            "Löchern verzehrt, speichert es in\n"
            "einem Beutel in seinem Hals. Dieser\n"
            "kann bis zu 8 kg Sand aufnehmen."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 348,
        .trainerOffset = 6,
        FRONT_PIC(Silicobra, 40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Silicobra,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Silicobra, 56, 48),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Silicobra),
        ICON(Silicobra, 1),
        .footprint = gMonFootprint_Silicobra,
        LEARNSETS(Silicobra),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_SANDACONDA}),
    },

#define SANDACONDA_MISC_INFO                                                        \
        .baseHP        = 72,                                                        \
        .baseAttack    = 107,                                                       \
        .baseDefense   = 125,                                                       \
        .baseSpeed     = 71,                                                        \
        .baseSpAttack  = 65,                                                        \
        .baseSpDefense = 70,                                                        \
        .types = { TYPE_GROUND, TYPE_GROUND },                                      \
        .catchRate = 120,                                                           \
        .expYield = 179,                                                            \
        .evYield_Defense = 2,                                                       \
        .genderRatio = PERCENT_FEMALE(50),                                          \
        .eggCycles = 20,                                                            \
        .friendship = STANDARD_FRIENDSHIP,                                          \
        .growthRate = GROWTH_MEDIUM_FAST,                                           \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_DRAGON },                         \
        .abilities = { ABILITY_SAND_SPIT, ABILITY_SHED_SKIN, ABILITY_SAND_VEIL },   \
        .bodyColor = BODY_COLOR_GREEN,                                              \
        .speciesName = _("Salanga"),                                             \
        .cryId = CRY_SANDACONDA,                                                    \
        .natDexNum = NATIONAL_DEX_SANDACONDA,                                       \
        .categoryName = _("Sandschlangen"),                                            \
        .footprint = gMonFootprint_Sandaconda,                                      \
        LEARNSETS(Sandaconda),                                                      \
        .formSpeciesIdTable = sSandacondaFormSpeciesIdTable,                        \
        .formChangeTable = sSandacondaFormChangeTable

    [SPECIES_SANDACONDA] =
    {
        SANDACONDA_MISC_INFO,
        .height = 38,
        .weight = 655,
        .description = POKEDEX_DESC_STRING(
            "Zieht es seinen ganzen Körper\n"
            "zusammen, kann es 100 kg Sand aus\n"
            "seinen Nasenlöchern feuern. Geht\n"
            "ihm der Sand aus, verliert es den\n"
            "Mut."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 610,
        .trainerOffset = 17,
        FRONT_PIC(Sandaconda, 64, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Sandaconda,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Sandaconda, 64, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Sandaconda),
        ICON(Sandaconda, 1),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_SANDACONDA_GIGANTAMAX] =
    {
        SANDACONDA_MISC_INFO,
        .height = 220,
        .weight = 0,
        .description = POKEDEX_DESC_STRING(
            "Zieht es seinen ganzen Körper\n"
            "zusammen, kann es 100 kg Sand aus\n"
            "seinen Nasenlöchern feuern. Geht\n"
            "ihm der Sand aus, verliert es den\n"
            "Mut."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 610,
        .trainerOffset = 17,
        FRONT_PIC(SandacondaGigantamax, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_SandacondaGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(SandacondaGigantamax, 64, 64),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(SandacondaGigantamax),
        ICON(SandacondaGigantamax, 1),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_SILICOBRA

#if P_FAMILY_CRAMORANT
#define CRAMORANT_MISC_INFO                                     \
        .baseHP        = 70,                                    \
        .baseAttack    = 85,                                    \
        .baseDefense   = 55,                                    \
        .baseSpeed     = 85,                                    \
        .baseSpAttack  = 85,                                    \
        .baseSpDefense = 95,                                    \
        .types = { TYPE_FLYING, TYPE_WATER },                   \
        .catchRate = 45,                                        \
        .expYield = 166,                                        \
        .evYield_SpDefense = 2,                                 \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 20,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_MEDIUM_FAST,                       \
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FLYING },   \
        .abilities = { ABILITY_GULP_MISSILE, ABILITY_NONE },    \
        .bodyColor = BODY_COLOR_BLUE,                           \
        .speciesName = _("Sanaconda"),                          \
        .cryId = CRY_CRAMORANT,                                 \
        .natDexNum = NATIONAL_DEX_CRAMORANT,                    \
        .categoryName = _("Sandschlangen"),                              \
        .height = 8,                                            \
        .weight = 180,                                          \
        .pokemonScale = 366,                                    \
        .pokemonOffset = 7,                                     \
        .trainerScale = 257,                                    \
        .trainerOffset = 0,                                     \
        .footprint = gMonFootprint_Cramorant,                   \
        LEARNSETS(Cramorant),                                   \
        .formSpeciesIdTable = sCramorantFormSpeciesIdTable,     \
        .formChangeTable = sCramorantFormChangeTable

    [SPECIES_CRAMORANT] =
    {
        CRAMORANT_MISC_INFO,
        .description = POKEDEX_DESC_STRING(
            "Es ist so stark, dass es seine\n"
            "Gegner mit einem Angriff vernichten\n"
            "könnte, aber zerstreut wie es ist,\n"
            "vergisst es öfters, wen es gerade\n"
            "bekämpft."),
        FRONT_PIC(Cramorant, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Cramorant,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Cramorant, 56, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Cramorant),
        ICON(Cramorant, 0),
    },

    [SPECIES_CRAMORANT_GULPING] =
    {
        CRAMORANT_MISC_INFO,
        .description = POKEDEX_DESC_STRING(
            "Es ist so stark, dass es seine\n"
            "Gegner mit einem Angriff vernichten\n"
            "könnte, aber zerstreut wie es ist,\n"
            "vergisst es öfters, wen es gerade\n"
            "bekämpft."),
        FRONT_PIC(CramorantGulping, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Cramorant,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(CramorantGulping, 64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(CramorantGulping),
        ICON(CramorantGulping, 0),
    },

    [SPECIES_CRAMORANT_GORGING] =
    {
        CRAMORANT_MISC_INFO,
        .description = POKEDEX_DESC_STRING(
            "Es ist so stark, dass es seine\n"
            "Gegner mit einem Angriff vernichten\n"
            "könnte, aber zerstreut wie es ist,\n"
            "vergisst es öfters, wen es gerade\n"
            "bekämpft."),
        FRONT_PIC(CramorantGorging, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Cramorant,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(CramorantGorging, 64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(CramorantGorging),
        ICON(CramorantGorging, 0),
    },
#endif //P_FAMILY_CRAMORANT

#if P_FAMILY_ARROKUDA
    [SPECIES_ARROKUDA] =
    {
        .baseHP        = 41,
        .baseAttack    = 63,
        .baseDefense   = 40,
        .baseSpeed     = 66,
        .baseSpAttack  = 40,
        .baseSpDefense = 30,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 255,
        .expYield = 56,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2 },
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_NONE, ABILITY_PROPELLER_TAIL },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Pikuda"),
        .cryId = CRY_ARROKUDA,
        .natDexNum = NATIONAL_DEX_ARROKUDA,
        .categoryName = _("Rempler"),
        .height = 5,
        .weight = 10,
        .description = POKEDEX_DESC_STRING(
            "Sein spitz zulaufender Kiefer ist\n"
            "sein ganzer Stolz. Erblickt es\n"
            "etwas, das sich auch nur ein\n"
            "bisschen bewegt, setzt es\n"
            "geradewegs zum Stoßangriff an."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Arrokuda, 56, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_Arrokuda,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Arrokuda, 48, 40),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Arrokuda),
        ICON(Arrokuda, 2),
        .footprint = gMonFootprint_Arrokuda,
        LEARNSETS(Arrokuda),
        .evolutions = EVOLUTION({EVO_LEVEL, 26, SPECIES_BARRASKEWDA}),
    },

    [SPECIES_BARRASKEWDA] =
    {
        .baseHP        = 61,
        .baseAttack    = 123,
        .baseDefense   = 60,
        .baseSpeed     = 136,
        .baseSpAttack  = 60,
        .baseSpDefense = 50,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 60,
        .expYield = 172,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2 },
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_NONE, ABILITY_PROPELLER_TAIL },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Barrakiefa"),
        .cryId = CRY_BARRASKEWDA,
        .natDexNum = NATIONAL_DEX_BARRASKEWDA,
        .categoryName = _("Spieß"),
        .height = 13,
        .weight = 300,
        .description = POKEDEX_DESC_STRING(
            "Sein Kiefer ist spitz wie ein Speer\n"
            "und hart wie Stahl. Außerdem soll\n"
            "Barrakiefa überraschend deliziös\n"
            "sein."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Barraskewda, 56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Barraskewda,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Barraskewda, 64, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Barraskewda),
        ICON(Barraskewda, 2),
        .footprint = gMonFootprint_Barraskewda,
        LEARNSETS(Barraskewda),
    },
#endif //P_FAMILY_ARROKUDA

#if P_FAMILY_TOXEL
    [SPECIES_TOXEL] =
    {
        .baseHP        = 40,
        .baseAttack    = 38,
        .baseDefense   = 35,
        .baseSpeed     = 40,
        .baseSpAttack  = 54,
        .baseSpDefense = 35,
        .types = { TYPE_ELECTRIC, TYPE_POISON },
        .catchRate = 75,
        .expYield = 48,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_RATTLED, ABILITY_STATIC, ABILITY_KLUTZ },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Toxel"),
        .cryId = CRY_TOXEL,
        .natDexNum = NATIONAL_DEX_TOXEL,
        .categoryName = _("Baby"),
        .height = 4,
        .weight = 110,
        .description = POKEDEX_DESC_STRING(
            "Das Gift aus dem Giftsack in seinem\n"
            "Körper sondert es über die Haut ab.\n"
            "Berührt man es, bekommt man einen\n"
            "lähmenden Schock verpasst."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Toxel, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Toxel,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Toxel, 48, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Toxel),
        ICON(Toxel, 2),
        .footprint = gMonFootprint_Toxel,
        LEARNSETS(Toxel),
        .evolutions = EVOLUTION({EVO_LEVEL_NATURE_AMPED, 30, SPECIES_TOXTRICITY_AMPED},
                                {EVO_LEVEL_NATURE_LOW_KEY, 30, SPECIES_TOXTRICITY_LOW_KEY}),
    },

#define TOXTRICITY_MISC_INFO                                            \
        .baseHP        = 75,                                            \
        .baseAttack    = 98,                                            \
        .baseDefense   = 70,                                            \
        .baseSpeed     = 75,                                            \
        .baseSpAttack  = 114,                                           \
        .baseSpDefense = 70,                                            \
        .types = { TYPE_ELECTRIC, TYPE_POISON },                        \
        .catchRate = 45,                                                \
        .expYield = 176,                                                \
        .evYield_SpAttack = 2,                                          \
        .genderRatio = PERCENT_FEMALE(50),                              \
        .eggCycles = 25,                                                \
        .friendship = STANDARD_FRIENDSHIP,                              \
        .growthRate = GROWTH_MEDIUM_SLOW,                               \
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },    \
        .bodyColor = BODY_COLOR_PURPLE,                                 \
        .speciesName = _("Toxel"),                                 \
        .natDexNum = NATIONAL_DEX_TOXTRICITY,                           \
        .categoryName = _("Baby"),                                      \
        .formSpeciesIdTable = sToxtricityFormSpeciesIdTable,            \
        .formChangeTable = sToxtricityAmpedFormChangeTable

    [SPECIES_TOXTRICITY_AMPED] =
    {
        TOXTRICITY_MISC_INFO,
        .abilities = { ABILITY_PUNK_ROCK, ABILITY_PLUS, ABILITY_TECHNICIAN },
        .cryId = CRY_TOXTRICITY_AMPED,
        .height = 16,
        .weight = 400,
        .description = POKEDEX_DESC_STRING(
            "Wenn es am Fortsatz an seiner Brust\n"
            "kratzt und dadurch Strom erzeugt,\n"
            "dann erklingt in der Umgebung ein\n"
            "Ton wie von einer Gitarre."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(ToxtricityAmped, 48, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Toxtricity,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(ToxtricityAmped, 56, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(ToxtricityAmped),
        ICON(ToxtricityAmped, 2),
        .footprint = gMonFootprint_Toxtricity,
        LEARNSETS(ToxtricityAmped),

    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_TOXTRICITY_AMPED_GIGANTAMAX] =
    {
        TOXTRICITY_MISC_INFO,
        .abilities = { ABILITY_PUNK_ROCK, ABILITY_PLUS, ABILITY_TECHNICIAN },
        .cryId = CRY_TOXTRICITY_AMPED,
        .height = 240,
        .weight = 0,
        .description = gToxtricityGigantamaxPokedexText,
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(ToxtricityGigantamax, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_ToxtricityGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(ToxtricityGigantamax, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(ToxtricityGigantamax),
        ICON(ToxtricityGigantamax, 0),
        .footprint = gMonFootprint_Toxtricity,
        LEARNSETS(ToxtricityAmped),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS

    [SPECIES_TOXTRICITY_LOW_KEY] =
    {
        TOXTRICITY_MISC_INFO,
        .abilities = { ABILITY_PUNK_ROCK, ABILITY_MINUS, ABILITY_TECHNICIAN },
        .cryId = CRY_TOXTRICITY_LOW_KEY,
        .height = 16,
        .weight = 400,
        .description = POKEDEX_DESC_STRING(
            "Wenn es am Fortsatz an seiner Brust\n"
            "kratzt und dadurch Strom erzeugt,\n"
            "dann erklingt in der Umgebung ein\n"
            "Ton wie von einer Gitarre."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(ToxtricityLowKey, 48, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Toxtricity,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(ToxtricityLowKey, 48, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(ToxtricityLowKey),
        ICON(ToxtricityLowKey, 2),
        .footprint = gMonFootprint_Toxtricity,
        LEARNSETS(ToxtricityLowKey),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_TOXTRICITY_LOW_KEY_GIGANTAMAX] =
    {
        TOXTRICITY_MISC_INFO,
        .abilities = { ABILITY_PUNK_ROCK, ABILITY_MINUS, ABILITY_TECHNICIAN },
        .cryId = CRY_TOXTRICITY_LOW_KEY,
        .height = 240,
        .weight = 0,
        .description = gToxtricityGigantamaxPokedexText,
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(ToxtricityGigantamax, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_ToxtricityGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(ToxtricityGigantamax, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(ToxtricityGigantamax),
        ICON(ToxtricityGigantamax, 0),
        .footprint = gMonFootprint_Toxtricity,
        LEARNSETS(ToxtricityLowKey),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_TOXEL

#if P_FAMILY_SIZZLIPEDE
    [SPECIES_SIZZLIPEDE] =
    {
        .baseHP        = 50,
        .baseAttack    = 65,
        .baseDefense   = 45,
        .baseSpeed     = 45,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = { TYPE_FIRE, TYPE_BUG },
        .catchRate = 190,
        .expYield = 61,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_WHITE_SMOKE, ABILITY_FLAME_BODY },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Thermopod"),
        .cryId = CRY_SIZZLIPEDE,
        .natDexNum = NATIONAL_DEX_SIZZLIPEDE,
        .categoryName = _("Exotherm"),
        .height = 7,
        .weight = 10,
        .description = POKEDEX_DESC_STRING(
            "Mit dem entzündlichen Gas in seinem\n"
            "Körper erzeugt es Hitze. Die gelben\n"
            "Stellen an seinem Bauch werden\n"
            "besonders heiß."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Sizzlipede, 48, 32),
        .frontPicYOffset = 17,
        .frontAnimFrames = sAnims_Sizzlipede,
        .frontAnimId = ANIM_H_VIBRATE,
        BACK_PIC(Sizzlipede, 40, 32),
        .backPicYOffset = 16,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Sizzlipede),
        ICON(Sizzlipede, 0),
        .footprint = gMonFootprint_Sizzlipede,
        LEARNSETS(Sizzlipede),
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_CENTISKORCH}),
    },

#define CENTISKORCH_MISC_INFO                                                           \
        .baseHP        = 100,                                                           \
        .baseAttack    = 115,                                                           \
        .baseDefense   = 65,                                                            \
        .baseSpeed     = 65,                                                            \
        .baseSpAttack  = 90,                                                            \
        .baseSpDefense = 90,                                                            \
        .types = { TYPE_FIRE, TYPE_BUG },                                               \
        .catchRate = 75,                                                                \
        .expYield = 184,                                                                \
        .evYield_Attack = 2,                                                            \
        .genderRatio = PERCENT_FEMALE(50),                                              \
        .eggCycles = 20,                                                                \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_MEDIUM_FAST,                                               \
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },                                  \
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_WHITE_SMOKE, ABILITY_FLAME_BODY },   \
        .bodyColor = BODY_COLOR_RED,                                                    \
        .speciesName = _("Thermopod"),                                                 \
        .cryId = CRY_CENTISKORCH,                                                       \
        .natDexNum = NATIONAL_DEX_CENTISKORCH,                                          \
        .categoryName = _("Exotherm"),                                                  \
        .footprint = gMonFootprint_Centiskorch,                                         \
        LEARNSETS(Centiskorch),                                                         \
        .formSpeciesIdTable = sCentiskorchFormSpeciesIdTable,                           \
        .formChangeTable = sCentiskorchFormChangeTable

    [SPECIES_CENTISKORCH] =
    {
        CENTISKORCH_MISC_INFO,
        .height = 30,
        .weight = 1200,
        .description = POKEDEX_DESC_STRING(
            "Wenn es Hitze erzeugt, beträgt\n"
            "seine Temperatur etwa 800 ÂºC. Es\n"
            "bewegt seinen Körper wie eine\n"
            "Peitsche, um dann den Gegner\n"
            "anzuspringen."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Centiskorch, 64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Centiskorch,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Centiskorch, 56, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Centiskorch),
        ICON(Centiskorch, 0),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_CENTISKORCH_GIGANTAMAX] =
    {
        CENTISKORCH_MISC_INFO,
        .height = 750,
        .weight = 0,
        .description = POKEDEX_DESC_STRING(
            "Wenn es Hitze erzeugt, beträgt\n"
            "seine Temperatur etwa 800 ÂºC. Es\n"
            "bewegt seinen Körper wie eine\n"
            "Peitsche, um dann den Gegner\n"
            "anzuspringen."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(CentiskorchGigantamax, 64, 64),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_CentiskorchGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(CentiskorchGigantamax, 64, 64),
        .backPicYOffset = 1,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(CentiskorchGigantamax),
        ICON(CentiskorchGigantamax, 0),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_SIZZLIPEDE

#if P_FAMILY_CLOBBOPUS
    [SPECIES_CLOBBOPUS] =
    {
        .baseHP        = 50,
        .baseAttack    = 68,
        .baseDefense   = 60,
        .baseSpeed     = 32,
        .baseSpAttack  = 50,
        .baseSpDefense = 50,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 180,
        .expYield = 62,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_LIMBER, ABILITY_NONE, ABILITY_TECHNICIAN },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Klopptopus"),
        .cryId = CRY_CLOBBOPUS,
        .natDexNum = NATIONAL_DEX_CLOBBOPUS,
        .categoryName = _("Balg"),
        .height = 6,
        .weight = 40,
        .description = POKEDEX_DESC_STRING(
            "Zur Futtersuche kommt es an Land.\n"
            "Es ist sehr neugierig, weshalb es\n"
            "alles, was es sieht, zunächst\n"
            "einmal mit seinen Tentakeln haut."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Clobbopus, 48, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_Clobbopus,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Clobbopus, 64, 40),
        .backPicYOffset = 14,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Clobbopus),
        ICON(Clobbopus, 0),
        .footprint = gMonFootprint_Clobbopus,
        LEARNSETS(Clobbopus),
        .evolutions = EVOLUTION({EVO_MOVE, MOVE_TAUNT, SPECIES_GRAPPLOCT}),
    },

    [SPECIES_GRAPPLOCT] =
    {
        .baseHP        = 80,
        .baseAttack    = 118,
        .baseDefense   = 90,
        .baseSpeed     = 42,
        .baseSpAttack  = 70,
        .baseSpDefense = 80,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 168,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_LIMBER, ABILITY_NONE, ABILITY_TECHNICIAN },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Kaocto"),
        .cryId = CRY_GRAPPLOCT,
        .natDexNum = NATIONAL_DEX_GRAPPLOCT,
        .categoryName = _("Jiu-Jitsu"),
        .height = 16,
        .weight = 390,
        .description = POKEDEX_DESC_STRING(
            "Sein Körper besteht gänzlich aus\n"
            "Muskeln. Die schiere Stärke seines\n"
            "Würgegriffs, bei dem es seine\n"
            "Tentakel einsetzt, ist sagenhaft."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Grapploct, 48, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Grapploct,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Grapploct, 56, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Grapploct),
        ICON(Grapploct, 2),
        .footprint = gMonFootprint_Grapploct,
        LEARNSETS(Grapploct),
    },
#endif //P_FAMILY_CLOBBOPUS

#if P_FAMILY_SINISTEA
#define SINISTEA_MISC_INFO                                                      \
        .baseHP        = 40,                                                    \
        .baseAttack    = 45,                                                    \
        .baseDefense   = 45,                                                    \
        .baseSpeed     = 50,                                                    \
        .baseSpAttack  = 74,                                                    \
        .baseSpDefense = 54,                                                    \
        .types = { TYPE_GHOST, TYPE_GHOST },                                    \
        .catchRate = 120,                                                       \
        .expYield = 62,                                                         \
        .evYield_SpAttack = 1,                                                  \
        .genderRatio = MON_GENDERLESS,                                          \
        .eggCycles = 20,                                                        \
        .friendship = STANDARD_FRIENDSHIP,                                      \
        .growthRate = GROWTH_MEDIUM_FAST,                                       \
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS },                \
        .abilities = { ABILITY_WEAK_ARMOR, ABILITY_NONE, ABILITY_CURSED_BODY }, \
        .bodyColor = BODY_COLOR_PURPLE,                                         \
        .speciesName = _("Kaocto"),                                           \
        .cryId = CRY_SINISTEA,                                                  \
        .natDexNum = NATIONAL_DEX_SINISTEA,                                     \
        .categoryName = _("Jiu-Jitsu"),                                         \
        .height = 1,                                                            \
        .weight = 2,                                                            \
        .pokemonScale = 682,                                                    \
        .pokemonOffset = 24,                                                    \
        .trainerScale = 256,                                                    \
        .trainerOffset = 0,                                                     \
        FRONT_PIC(Sinistea, 40, 32),                                            \
        .frontPicYOffset = 17,                                                  \
        .frontAnimFrames = sAnims_Sinistea,                                     \
        BACK_PIC(Sinistea, 48, 32),                                             \
        .backPicYOffset = 16,                                                   \
        PALETTES(Sinistea),                                                     \
        ICON(Sinistea, 2),                                                      \
        .footprint = gMonFootprint_Sinistea,                                    \
        LEARNSETS(Sinistea),                                                    \
        .formSpeciesIdTable = sSinisteaFormSpeciesIdTable
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        //.backAnimId = BACK_ANIM_NONE,

    [SPECIES_SINISTEA_PHONY] =
    {
        SINISTEA_MISC_INFO,
        .description = POKEDEX_DESC_STRING(
            "Es heißt, eine einsame Seele habe\n"
            "Besitz von einer abgestellten,\n"
            "kalten Tasse Schwarztee ergriffen\n"
            "und sei zu diesem Pokémon geworden."),
        .enemyMonElevation = 9,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_CRACKED_POT, SPECIES_POLTEAGEIST_PHONY}),
    },

    [SPECIES_SINISTEA_ANTIQUE] =
    {
        SINISTEA_MISC_INFO,
        .description = POKEDEX_DESC_STRING(
            "Es heißt, eine einsame Seele habe\n"
            "Besitz von einer abgestellten,\n"
            "kalten Tasse Schwarztee ergriffen\n"
            "und sei zu diesem Pokémon geworden."),
        .enemyMonElevation = 10,
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_CHIPPED_POT, SPECIES_POLTEAGEIST_ANTIQUE}),
    },

#define POLTEAGEIST_MISC_INFO                                                   \
        .baseHP        = 60,                                                    \
        .baseAttack    = 65,                                                    \
        .baseDefense   = 65,                                                    \
        .baseSpeed     = 70,                                                    \
        .baseSpAttack  = 134,                                                   \
        .baseSpDefense = 114,                                                   \
        .types = { TYPE_GHOST, TYPE_GHOST },                                    \
        .catchRate = 60,                                                        \
        .expYield = 178,                                                        \
        .evYield_SpAttack = 2,                                                  \
        .genderRatio = MON_GENDERLESS,                                          \
        .eggCycles = 20,                                                        \
        .friendship = STANDARD_FRIENDSHIP,                                      \
        .growthRate = GROWTH_MEDIUM_FAST,                                       \
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_AMORPHOUS },                \
        .abilities = { ABILITY_WEAK_ARMOR, ABILITY_NONE, ABILITY_CURSED_BODY }, \
        .bodyColor = BODY_COLOR_PURPLE,                                         \
        .speciesName = _("Fatalitee"),                                         \
        .cryId = CRY_POLTEAGEIST,                                               \
        .natDexNum = NATIONAL_DEX_POLTEAGEIST,                                  \
        .categoryName = _("Schwarztee"),                                         \
        .height = 2,                                                            \
        .weight = 4,                                                            \
        .pokemonScale = 682,                                                    \
        .pokemonOffset = 24,                                                    \
        .trainerScale = 256,                                                    \
        .trainerOffset = 0,                                                     \
        FRONT_PIC(Polteageist, 48, 48),                                         \
        .frontPicYOffset = 11,                                                  \
        .frontAnimFrames = sAnims_Polteageist,                                  \
        BACK_PIC(Polteageist, 64, 40),                                          \
        .backPicYOffset = 13,                                                   \
        PALETTES(Polteageist),                                                  \
        ICON(Polteageist, 2),                                                   \
        .footprint = gMonFootprint_Polteageist,                                 \
        LEARNSETS(Polteageist),                                                 \
        .formSpeciesIdTable = sPolteageistFormSpeciesIdTable
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        //.backAnimId = BACK_ANIM_NONE,

    [SPECIES_POLTEAGEIST_PHONY] =
    {
        POLTEAGEIST_MISC_INFO,
        .description = POKEDEX_DESC_STRING(
            "Sie lassen sich in alten Teekannen\n"
            "nieder. Die meisten dieser Kannen\n"
            "sind billige Fälschungen, aber es\n"
            "gibt auch ein paar sehr seltene\n"
            "Originale."),
        .enemyMonElevation = 12,
    },

    [SPECIES_POLTEAGEIST_ANTIQUE] =
    {
        POLTEAGEIST_MISC_INFO,
        .description = POKEDEX_DESC_STRING(
            "Sie lassen sich in alten Teekannen\n"
            "nieder. Die meisten dieser Kannen\n"
            "sind billige Fälschungen, aber es\n"
            "gibt auch ein paar sehr seltene\n"
            "Originale."),
        .enemyMonElevation = 11,
    },
#endif //P_FAMILY_SINISTEA

#if P_FAMILY_HATENNA
    [SPECIES_HATENNA] =
    {
        .baseHP        = 42,
        .baseAttack    = 30,
        .baseDefense   = 45,
        .baseSpeed     = 39,
        .baseSpAttack  = 56,
        .baseSpDefense = 53,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 235,
        .expYield = 53,
        .evYield_SpAttack = 1,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_HEALER, ABILITY_ANTICIPATION, ABILITY_MAGIC_BOUNCE },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Brimova"),
        .cryId = CRY_HATENNA,
        .natDexNum = NATIONAL_DEX_HATENNA,
        .categoryName = _("Geruhsam"),
        .height = 4,
        .weight = 34,
        .description = POKEDEX_DESC_STRING(
            "Es liebt Orte, wo sonst niemand ist. Nimmt\n"
            "es starke Emotionen wahr, macht es sich so\n"
            "schnell es kann aus dem Staub."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Hatenna, 48, 48),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Hatenna,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Hatenna, 40, 40),
        .backPicYOffset = 12,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Hatenna),
        ICON(Hatenna, 0),
        .footprint = gMonFootprint_Hatenna,
        LEARNSETS(Hatenna),
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_HATTREM}),
    },

    [SPECIES_HATTREM] =
    {
        .baseHP        = 57,
        .baseAttack    = 40,
        .baseDefense   = 65,
        .baseSpeed     = 49,
        .baseSpAttack  = 86,
        .baseSpDefense = 73,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 120,
        .expYield = 130,
        .evYield_SpAttack = 2,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_HEALER, ABILITY_ANTICIPATION, ABILITY_MAGIC_BOUNCE },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Brimano"),
        .cryId = CRY_HATTREM,
        .natDexNum = NATIONAL_DEX_HATTREM,
        .categoryName = _("Ruhe"),
        .height = 6,
        .weight = 48,
        .description = POKEDEX_DESC_STRING(
            "Empfindet jemand starke Emotionen,\n"
            "bringt es ihn auf gewaltsame Art\n"
            "zum Schweigen, egal, um wen es sich\n"
            "dabei handelt."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Hattrem, 56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Hattrem,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Hattrem, 56, 48),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Hattrem),
        ICON(Hattrem, 0),
        .footprint = gMonFootprint_Hattrem,
        LEARNSETS(Hattrem),
        .evolutions = EVOLUTION({EVO_LEVEL, 42, SPECIES_HATTERENE}),
    },

#define HATTERENE_MISC_INFO                                                             \
        .baseHP        = 57,                                                            \
        .baseAttack    = 90,                                                            \
        .baseDefense   = 95,                                                            \
        .baseSpeed     = 29,                                                            \
        .baseSpAttack  = 136,                                                           \
        .baseSpDefense = 103,                                                           \
        .types = { TYPE_PSYCHIC, TYPE_FAIRY },                                          \
        .catchRate = 45,                                                                \
        .expYield = 255,                                                                \
        .evYield_SpAttack = 3,                                                          \
        .genderRatio = MON_FEMALE,                                                      \
        .eggCycles = 20,                                                                \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },                              \
        .abilities = { ABILITY_HEALER, ABILITY_ANTICIPATION, ABILITY_MAGIC_BOUNCE },    \
        .bodyColor = BODY_COLOR_PINK,                                                   \
        .speciesName = _("Brimano"),                                                  \
        .cryId = CRY_HATTERENE,                                                         \
        .natDexNum = NATIONAL_DEX_HATTERENE,                                            \
        .categoryName = _("Ruhe"),                                                    \
        .footprint = gMonFootprint_Hatterene,                                           \
        LEARNSETS(Hatterene),                                                           \
        .formSpeciesIdTable = sHattereneFormSpeciesIdTable,                             \
        .formChangeTable = sHattereneFormChangeTable

    [SPECIES_HATTERENE] =
    {
        HATTERENE_MISC_INFO,
        .height = 21,
        .weight = 51,
        .description = POKEDEX_DESC_STRING(
            "Die starken Psycho-Kräfte, die es\n"
            "ausstrahlt, rufen Kopfschmerzen\n"
            "hervor. So hält es andere Lebewesen\n"
            "von sich fern."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        FRONT_PIC(Hatterene, 48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Hatterene,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Hatterene, 56, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Hatterene),
        ICON(Hatterene, 0),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_HATTERENE_GIGANTAMAX] =
    {
        HATTERENE_MISC_INFO,
        .height = 260,
        .weight = 0,
        .description = POKEDEX_DESC_STRING(
            "Die starken Psycho-Kräfte, die es\n"
            "ausstrahlt, rufen Kopfschmerzen\n"
            "hervor. So hält es andere Lebewesen\n"
            "von sich fern."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        FRONT_PIC(HattereneGigantamax, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_HattereneGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(HattereneGigantamax, 64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(HattereneGigantamax),
        ICON(HattereneGigantamax, 0),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_HATENNA

#if P_FAMILY_IMPIDIMP
    [SPECIES_IMPIDIMP] =
    {
        .baseHP        = 45,
        .baseAttack    = 45,
        .baseDefense   = 30,
        .baseSpeed     = 50,
        .baseSpAttack  = 55,
        .baseSpDefense = 40,
        .types = { TYPE_DARK, TYPE_FAIRY },
        .catchRate = 255,
        .expYield = 53,
        .evYield_SpAttack = 1,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_PRANKSTER, ABILITY_FRISK, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Bähmon"),
        .cryId = CRY_IMPIDIMP,
        .natDexNum = NATIONAL_DEX_IMPIDIMP,
        .categoryName = _("Hinterlist"),
        .height = 4,
        .weight = 55,
        .description = POKEDEX_DESC_STRING(
            "Es wird kräftiger, indem es die von\n"
            "unzufriedenen Menschen und Pokémon\n"
            "ausgestoßene negative Energie\n"
            "einatmet."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Impidimp, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Impidimp,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Impidimp, 48, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Impidimp),
        ICON(Impidimp, 0),
        .footprint = gMonFootprint_Impidimp,
        LEARNSETS(Impidimp),
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_MORGREM}),
    },

    [SPECIES_MORGREM] =
    {
        .baseHP        = 65,
        .baseAttack    = 60,
        .baseDefense   = 45,
        .baseSpeed     = 70,
        .baseSpAttack  = 75,
        .baseSpDefense = 55,
        .types = { TYPE_DARK, TYPE_FAIRY },
        .catchRate = 120,
        .expYield = 130,
        .evYield_SpAttack = 2,
        .genderRatio = MON_MALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_PRANKSTER, ABILITY_FRISK, ABILITY_PICKPOCKET },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Pelzebub"),
        .cryId = CRY_MORGREM,
        .natDexNum = NATIONAL_DEX_MORGREM,
        .categoryName = _("Schelm"),
        .height = 8,
        .weight = 125,
        .description = POKEDEX_DESC_STRING(
            "Es nutzt eine Taktik, bei der es\n"
            "sich niederwirft und vorgibt, sich\n"
            "zu entschuldigen, nur um dann mit\n"
            "seinem speerartigen Haar\n"
            "zuzustoßen."),
        .pokemonScale = 366,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Morgrem, 48, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Morgrem,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Morgrem, 56, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Morgrem),
        ICON(Morgrem, 0),
        .footprint = gMonFootprint_Morgrem,
        LEARNSETS(Morgrem),
        .evolutions = EVOLUTION({EVO_LEVEL, 42, SPECIES_GRIMMSNARL}),
    },

#define GRIMMSNARL_MISC_INFO                                                    \
        .baseHP        = 95,                                                    \
        .baseAttack    = 120,                                                   \
        .baseDefense   = 65,                                                    \
        .baseSpeed     = 60,                                                    \
        .baseSpAttack  = 95,                                                    \
        .baseSpDefense = 75,                                                    \
        .types = { TYPE_DARK, TYPE_FAIRY },                                     \
        .catchRate = 45,                                                        \
        .expYield = 255,                                                        \
        .evYield_Attack = 3,                                                    \
        .genderRatio = MON_MALE,                                                \
        .eggCycles = 20,                                                        \
        .friendship = STANDARD_FRIENDSHIP,                                      \
        .growthRate = GROWTH_MEDIUM_FAST,                                       \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_HUMAN_LIKE },                 \
        .abilities = { ABILITY_PRANKSTER, ABILITY_FRISK, ABILITY_PICKPOCKET },  \
        .bodyColor = BODY_COLOR_PURPLE,                                         \
        .speciesName = _("Pelzebub"),                                         \
        .cryId = CRY_GRIMMSNARL,                                                \
        .natDexNum = NATIONAL_DEX_GRIMMSNARL,                                   \
        .categoryName = _("Schelm"),                                           \
        .footprint = gMonFootprint_Grimmsnarl,                                  \
        LEARNSETS(Grimmsnarl),                                                  \
        .formSpeciesIdTable = sGrimmsnarlFormSpeciesIdTable,                    \
        .formChangeTable = sGrimmsnarlFormChangeTable

    [SPECIES_GRIMMSNARL] =
    {
        GRIMMSNARL_MISC_INFO,
        .height = 15,
        .weight = 610,
        .description = POKEDEX_DESC_STRING(
            "Wickelt es seine Haare um den\n"
            "ganzen Körper, verstärkt dies seine\n"
            "Muskelkraft. Das macht es so stark,\n"
            "dass es sogar Machomei bezwingen\n"
            "könnte."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Grimmsnarl, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Grimmsnarl,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Grimmsnarl, 64, 48),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Grimmsnarl),
        ICON(Grimmsnarl, 0),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_GRIMMSNARL_GIGANTAMAX] =
    {
        GRIMMSNARL_MISC_INFO,
        .height = 320,
        .weight = 0,
        .description = POKEDEX_DESC_STRING(
            "Wickelt es seine Haare um den\n"
            "ganzen Körper, verstärkt dies seine\n"
            "Muskelkraft. Das macht es so stark,\n"
            "dass es sogar Machomei bezwingen\n"
            "könnte."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(GrimmsnarlGigantamax, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_GrimmsnarlGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(GrimmsnarlGigantamax, 64, 64),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(GrimmsnarlGigantamax),
        ICON(GrimmsnarlGigantamax, 0),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_IMPIDIMP

#if P_FAMILY_MILCERY
    [SPECIES_MILCERY] =
    {
        .baseHP        = 45,
        .baseAttack    = 40,
        .baseDefense   = 40,
        .baseSpeed     = 34,
        .baseSpAttack  = 50,
        .baseSpDefense = 61,
        .types = { TYPE_FAIRY, TYPE_FAIRY },
        .catchRate = 200,
        .expYield = 54,
        .evYield_SpDefense = 1,
        .genderRatio = MON_FEMALE,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_SWEET_VEIL, ABILITY_NONE, ABILITY_AROMA_VEIL },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Hokumil"),
        .cryId = CRY_MILCERY,
        .natDexNum = NATIONAL_DEX_MILCERY,
        .categoryName = _("Sahne"),
        .height = 2,
        .weight = 3,
        .description = POKEDEX_DESC_STRING(
            "Es heißt, dass den Konditoreien, in denen\n"
            "sich Hokumil zeigt, großer Wohlstand\n"
            "verheißen sei."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Milcery, 40, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_Milcery,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 10,
        BACK_PIC(Milcery, 56, 48),
        .backPicYOffset = 16,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Milcery),
        ICON(Milcery, 1),
        .footprint = gMonFootprint_Milcery,
        LEARNSETS(Milcery),
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_ALCREMIE_STRAWBERRY_VANILLA_CREAM},
                                {EVO_LEVEL, 0, SPECIES_ALCREMIE_STRAWBERRY_RUBY_CREAM},
                                {EVO_LEVEL, 0, SPECIES_ALCREMIE_STRAWBERRY_MATCHA_CREAM},
                                {EVO_LEVEL, 0, SPECIES_ALCREMIE_STRAWBERRY_MINT_CREAM},
                                {EVO_LEVEL, 0, SPECIES_ALCREMIE_STRAWBERRY_LEMON_CREAM},
                                {EVO_LEVEL, 0, SPECIES_ALCREMIE_STRAWBERRY_SALTED_CREAM},
                                {EVO_LEVEL, 0, SPECIES_ALCREMIE_STRAWBERRY_RUBY_SWIRL},
                                {EVO_LEVEL, 0, SPECIES_ALCREMIE_STRAWBERRY_CARAMEL_SWIRL},
                                {EVO_LEVEL, 0, SPECIES_ALCREMIE_STRAWBERRY_RAINBOW_SWIRL}),
    },

#define ALCREMIE_MISC_INFO(color)                                               \
        .baseHP        = 65,                                                    \
        .baseAttack    = 60,                                                    \
        .baseDefense   = 75,                                                    \
        .baseSpeed     = 64,                                                    \
        .baseSpAttack  = 110,                                                   \
        .baseSpDefense = 121,                                                   \
        .types = { TYPE_FAIRY, TYPE_FAIRY },                                    \
        .catchRate = 100,                                                       \
        .expYield = 173,                                                        \
        .evYield_SpDefense = 2,                                                 \
        .genderRatio = MON_FEMALE,                                              \
        .eggCycles = 20,                                                        \
        .friendship = STANDARD_FRIENDSHIP,                                      \
        .growthRate = GROWTH_MEDIUM_FAST,                                       \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_AMORPHOUS },                  \
        .abilities = { ABILITY_SWEET_VEIL, ABILITY_NONE, ABILITY_AROMA_VEIL },  \
        .bodyColor = color

#define ALCREMIE_REGULAR_SPECIES_INFO(sweet, cream, color)  \
    {                                                       \
        ALCREMIE_MISC_INFO(color),                          \
        .speciesName = _("Hokumil"),                       \
        .cryId = CRY_ALCREMIE,                              \
        .natDexNum = NATIONAL_DEX_ALCREMIE,                 \
        .categoryName = _("Sahne"),                         \
        .height = 3,                                        \
        .weight = 5,                                        \
        .description = gAlcremie ##cream##PokedexText,      \
        .pokemonScale = 530,                                \
        .pokemonOffset = 13,                                \
        .trainerScale = 256,                                \
        .trainerOffset = 0,                                 \
        FRONT_PIC(Alcremie ##sweet, 40, 56),                \
        .frontPicYOffset = 7,                               \
        .frontAnimFrames = sAnims_Alcremie,                 \
        BACK_PIC(Alcremie ##sweet, 48, 56),                 \
        .backPicYOffset = 9,                                \
        .palette = gMonPalette_Alcremie ##sweet##cream,     \
        .shinyPalette = gMonShinyPalette_Alcremie ##sweet,  \
        ICON(AlcremieStrawberryVanillaCream, 1),            \
        .footprint = gMonFootprint_Alcremie,                \
        LEARNSETS(Alcremie),                                \
        .formSpeciesIdTable = sAlcremieFormSpeciesIdTable,  \
        .formChangeTable = sAlcremieFormChangeTable,        \
    }
        //ICON(AlcremieStrawberry##cream##, 1),
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        //.backAnimId = BACK_ANIM_NONE,

    [SPECIES_ALCREMIE_STRAWBERRY_VANILLA_CREAM] = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, VanillaCream, BODY_COLOR_WHITE),
    [SPECIES_ALCREMIE_STRAWBERRY_RUBY_CREAM]    = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, RubyCream,    BODY_COLOR_PINK),
    [SPECIES_ALCREMIE_STRAWBERRY_MATCHA_CREAM]  = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, MatchaCream,  BODY_COLOR_GREEN),
    [SPECIES_ALCREMIE_STRAWBERRY_MINT_CREAM]    = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, MintCream,    BODY_COLOR_BLUE),
    [SPECIES_ALCREMIE_STRAWBERRY_LEMON_CREAM]   = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, LemonCream,   BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_STRAWBERRY_SALTED_CREAM]  = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, SaltedCream,  BODY_COLOR_WHITE),
    [SPECIES_ALCREMIE_STRAWBERRY_RUBY_SWIRL]    = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, RubySwirl,    BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_STRAWBERRY_CARAMEL_SWIRL] = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, CaramelSwirl, BODY_COLOR_BROWN),
    [SPECIES_ALCREMIE_STRAWBERRY_RAINBOW_SWIRL] = ALCREMIE_REGULAR_SPECIES_INFO(Strawberry, RainbowSwirl, BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_BERRY_VANILLA_CREAM]      = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      VanillaCream, BODY_COLOR_WHITE),
    [SPECIES_ALCREMIE_BERRY_RUBY_CREAM]         = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      RubyCream,    BODY_COLOR_PINK),
    [SPECIES_ALCREMIE_BERRY_MATCHA_CREAM]       = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      MatchaCream,  BODY_COLOR_GREEN),
    [SPECIES_ALCREMIE_BERRY_MINT_CREAM]         = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      MintCream,    BODY_COLOR_BLUE),
    [SPECIES_ALCREMIE_BERRY_LEMON_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      LemonCream,   BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_BERRY_SALTED_CREAM]       = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      SaltedCream,  BODY_COLOR_WHITE),
    [SPECIES_ALCREMIE_BERRY_RUBY_SWIRL]         = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      RubySwirl,    BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_BERRY_CARAMEL_SWIRL]      = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      CaramelSwirl, BODY_COLOR_BROWN),
    [SPECIES_ALCREMIE_BERRY_RAINBOW_SWIRL]      = ALCREMIE_REGULAR_SPECIES_INFO(Berry,      RainbowSwirl, BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_LOVE_VANILLA_CREAM]       = ALCREMIE_REGULAR_SPECIES_INFO(Love,       VanillaCream, BODY_COLOR_WHITE),
    [SPECIES_ALCREMIE_LOVE_RUBY_CREAM]          = ALCREMIE_REGULAR_SPECIES_INFO(Love,       RubyCream,    BODY_COLOR_PINK),
    [SPECIES_ALCREMIE_LOVE_MATCHA_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Love,       MatchaCream,  BODY_COLOR_GREEN),
    [SPECIES_ALCREMIE_LOVE_MINT_CREAM]          = ALCREMIE_REGULAR_SPECIES_INFO(Love,       MintCream,    BODY_COLOR_BLUE),
    [SPECIES_ALCREMIE_LOVE_LEMON_CREAM]         = ALCREMIE_REGULAR_SPECIES_INFO(Love,       LemonCream,   BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_LOVE_SALTED_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Love,       SaltedCream,  BODY_COLOR_WHITE),
    [SPECIES_ALCREMIE_LOVE_RUBY_SWIRL]          = ALCREMIE_REGULAR_SPECIES_INFO(Love,       RubySwirl,    BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_LOVE_CARAMEL_SWIRL]       = ALCREMIE_REGULAR_SPECIES_INFO(Love,       CaramelSwirl, BODY_COLOR_BROWN),
    [SPECIES_ALCREMIE_LOVE_RAINBOW_SWIRL]       = ALCREMIE_REGULAR_SPECIES_INFO(Love,       RainbowSwirl, BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_STAR_VANILLA_CREAM]       = ALCREMIE_REGULAR_SPECIES_INFO(Star,       VanillaCream, BODY_COLOR_WHITE),
    [SPECIES_ALCREMIE_STAR_RUBY_CREAM]          = ALCREMIE_REGULAR_SPECIES_INFO(Star,       RubyCream,    BODY_COLOR_PINK),
    [SPECIES_ALCREMIE_STAR_MATCHA_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Star,       MatchaCream,  BODY_COLOR_GREEN),
    [SPECIES_ALCREMIE_STAR_MINT_CREAM]          = ALCREMIE_REGULAR_SPECIES_INFO(Star,       MintCream,    BODY_COLOR_BLUE),
    [SPECIES_ALCREMIE_STAR_LEMON_CREAM]         = ALCREMIE_REGULAR_SPECIES_INFO(Star,       LemonCream,   BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_STAR_SALTED_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Star,       SaltedCream,  BODY_COLOR_WHITE),
    [SPECIES_ALCREMIE_STAR_RUBY_SWIRL]          = ALCREMIE_REGULAR_SPECIES_INFO(Star,       RubySwirl,    BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_STAR_CARAMEL_SWIRL]       = ALCREMIE_REGULAR_SPECIES_INFO(Star,       CaramelSwirl, BODY_COLOR_BROWN),
    [SPECIES_ALCREMIE_STAR_RAINBOW_SWIRL]       = ALCREMIE_REGULAR_SPECIES_INFO(Star,       RainbowSwirl, BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_CLOVER_VANILLA_CREAM]     = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     VanillaCream, BODY_COLOR_WHITE),
    [SPECIES_ALCREMIE_CLOVER_RUBY_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     RubyCream,    BODY_COLOR_PINK),
    [SPECIES_ALCREMIE_CLOVER_MATCHA_CREAM]      = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     MatchaCream,  BODY_COLOR_GREEN),
    [SPECIES_ALCREMIE_CLOVER_MINT_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     MintCream,    BODY_COLOR_BLUE),
    [SPECIES_ALCREMIE_CLOVER_LEMON_CREAM]       = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     LemonCream,   BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_CLOVER_SALTED_CREAM]      = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     SaltedCream,  BODY_COLOR_WHITE),
    [SPECIES_ALCREMIE_CLOVER_RUBY_SWIRL]        = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     RubySwirl,    BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_CLOVER_CARAMEL_SWIRL]     = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     CaramelSwirl, BODY_COLOR_BROWN),
    [SPECIES_ALCREMIE_CLOVER_RAINBOW_SWIRL]     = ALCREMIE_REGULAR_SPECIES_INFO(Clover,     RainbowSwirl, BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_FLOWER_VANILLA_CREAM]     = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     VanillaCream, BODY_COLOR_WHITE),
    [SPECIES_ALCREMIE_FLOWER_RUBY_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     RubyCream,    BODY_COLOR_PINK),
    [SPECIES_ALCREMIE_FLOWER_MATCHA_CREAM]      = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     MatchaCream,  BODY_COLOR_GREEN),
    [SPECIES_ALCREMIE_FLOWER_MINT_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     MintCream,    BODY_COLOR_BLUE),
    [SPECIES_ALCREMIE_FLOWER_LEMON_CREAM]       = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     LemonCream,   BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_FLOWER_SALTED_CREAM]      = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     SaltedCream,  BODY_COLOR_WHITE),
    [SPECIES_ALCREMIE_FLOWER_RUBY_SWIRL]        = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     RubySwirl,    BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_FLOWER_CARAMEL_SWIRL]     = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     CaramelSwirl, BODY_COLOR_BROWN),
    [SPECIES_ALCREMIE_FLOWER_RAINBOW_SWIRL]     = ALCREMIE_REGULAR_SPECIES_INFO(Flower,     RainbowSwirl, BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_RIBBON_VANILLA_CREAM]     = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     VanillaCream, BODY_COLOR_WHITE),
    [SPECIES_ALCREMIE_RIBBON_RUBY_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     RubyCream,    BODY_COLOR_PINK),
    [SPECIES_ALCREMIE_RIBBON_MATCHA_CREAM]      = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     MatchaCream,  BODY_COLOR_GREEN),
    [SPECIES_ALCREMIE_RIBBON_MINT_CREAM]        = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     MintCream,    BODY_COLOR_BLUE),
    [SPECIES_ALCREMIE_RIBBON_LEMON_CREAM]       = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     LemonCream,   BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_RIBBON_SALTED_CREAM]      = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     SaltedCream,  BODY_COLOR_WHITE),
    [SPECIES_ALCREMIE_RIBBON_RUBY_SWIRL]        = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     RubySwirl,    BODY_COLOR_YELLOW),
    [SPECIES_ALCREMIE_RIBBON_CARAMEL_SWIRL]     = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     CaramelSwirl, BODY_COLOR_BROWN),
    [SPECIES_ALCREMIE_RIBBON_RAINBOW_SWIRL]     = ALCREMIE_REGULAR_SPECIES_INFO(Ribbon,     RainbowSwirl, BODY_COLOR_YELLOW),
#if P_GIGANTAMAX_FORMS
    [SPECIES_ALCREMIE_GIGANTAMAX] =
    {
        ALCREMIE_MISC_INFO(BODY_COLOR_YELLOW),
        .isGigantamax = TRUE,
        .speciesName = _("Pokusan"),
        .cryId = CRY_ALCREMIE,
        .natDexNum = NATIONAL_DEX_ALCREMIE,
        .categoryName = _("Sahne"),
        .height = 3,
        .weight = 5,
        .description = POKEDEX_DESC_STRING(
            "Es macht einem Trainer, dem es\n"
            "vertraut, mit Beeren samt\n"
            "Sahnedekoration eine Freude."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(AlcremieGigantamax, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_AlcremieGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(AlcremieGigantamax, 64, 64),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(AlcremieGigantamax),
        ICON(AlcremieGigantamax, 1),
        .footprint = gMonFootprint_Alcremie,
        LEARNSETS(Alcremie),
        .formSpeciesIdTable = sAlcremieFormSpeciesIdTable,
        .formChangeTable = sAlcremieFormChangeTable,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_MILCERY

#if P_FAMILY_FALINKS
    [SPECIES_FALINKS] =
    {
        .baseHP        = 65,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 75,
        .baseSpAttack  = 70,
        .baseSpDefense = 60,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 165,
        .evYield_Attack = 2,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_BATTLE_ARMOR, ABILITY_NONE, ABILITY_DEFIANT },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Legios"),
        .cryId = CRY_FALINKS,
        .natDexNum = NATIONAL_DEX_FALINKS,
        .categoryName = _("Formations"),
        .height = 30,
        .weight = 620,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon besteht aus fünf\n"
            "Untergebenen und einem Anführer.\n"
            "Die Befehle des Anführers werden\n"
            "nie in Frage gestellt."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Falinks, 56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Falinks,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Falinks, 64, 40),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Falinks),
        ICON(Falinks, 0),
        .footprint = gMonFootprint_Falinks,
        LEARNSETS(Falinks),
    },
#endif //P_FAMILY_FALINKS

#if P_FAMILY_PINCURCHIN
    [SPECIES_PINCURCHIN] =
    {
        .baseHP        = 48,
        .baseAttack    = 101,
        .baseDefense   = 95,
        .baseSpeed     = 15,
        .baseSpAttack  = 91,
        .baseSpDefense = 85,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 75,
        .expYield = 152,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_LIGHTNING_ROD, ABILITY_NONE, ABILITY_ELECTRIC_SURGE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Britzigel"),
        .cryId = CRY_PINCURCHIN,
        .natDexNum = NATIONAL_DEX_PINCURCHIN,
        .categoryName = _("Seeigel"),
        .height = 3,
        .weight = 10,
        .description = POKEDEX_DESC_STRING(
            "In jedem einzelnen seiner Stacheln\n"
            "speichert es Elektrizität. Selbst\n"
            "abgebrochene Stacheln sind noch drei\n"
            "Stunden lang geladen."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pincurchin, 40, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_Pincurchin,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Pincurchin, 56, 40),
        .backPicYOffset = 13,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Pincurchin),
        ICON(Pincurchin, 0),
        .footprint = gMonFootprint_Pincurchin,
        LEARNSETS(Pincurchin),
    },
#endif //P_FAMILY_PINCURCHIN

#if P_FAMILY_SNOM
    [SPECIES_SNOM] =
    {
        .baseHP        = 30,
        .baseAttack    = 25,
        .baseDefense   = 35,
        .baseSpeed     = 20,
        .baseSpAttack  = 45,
        .baseSpDefense = 30,
        .types = { TYPE_ICE, TYPE_BUG },
        .catchRate = 190,
        .expYield = 37,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_SNOWBALL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SHIELD_DUST, ABILITY_NONE, ABILITY_ICE_SCALES },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Snomnom"),
        .cryId = CRY_SNOM,
        .natDexNum = NATIONAL_DEX_SNOM,
        .categoryName = _("Wurm"),
        .height = 3,
        .weight = 38,
        .description = POKEDEX_DESC_STRING(
            "Es frisst den Schnee, der sich am Boden\n"
            "angesammelt hat. Je mehr es frisst, desto\n"
            "größer werden die Stacheln auf seinem\n"
            "Rücken."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Snom, 40, 32),
        .frontPicYOffset = 20,
        .frontAnimFrames = sAnims_Snom,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Snom, 48, 32),
        .backPicYOffset = 17,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Snom),
        ICON(Snom, 0),
        .footprint = gMonFootprint_Snom,
        LEARNSETS(Snom),
        .evolutions = EVOLUTION({EVO_FRIENDSHIP_NIGHT, 0, SPECIES_FROSMOTH}),
    },

    [SPECIES_FROSMOTH] =
    {
        .baseHP        = 70,
        .baseAttack    = 65,
        .baseDefense   = 60,
        .baseSpeed     = 65,
        .baseSpAttack  = 125,
        .baseSpDefense = 90,
        .types = { TYPE_ICE, TYPE_BUG },
        .catchRate = 75,
        .expYield = 166,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SHIELD_DUST, ABILITY_NONE, ABILITY_ICE_SCALES },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Mottineva"),
        .cryId = CRY_FROSMOTH,
        .natDexNum = NATIONAL_DEX_FROSMOTH,
        .categoryName = _("Eismotten"),
        .height = 13,
        .weight = 420,
        .description = POKEDEX_DESC_STRING(
            "Verwüstet jemand Felder und Berge, vergibt\n"
            "es ihm niemals. Es bestraft den Täter,\n"
            "indem es mit seinen kalten Flügeln einen\n"
            "Schneesturm erzeugt."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Frosmoth, 64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Frosmoth,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 7,
        BACK_PIC(Frosmoth, 64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Frosmoth),
        ICON(Frosmoth, 0),
        .footprint = gMonFootprint_Frosmoth,
        LEARNSETS(Frosmoth),
    },
#endif //P_FAMILY_SNOM

#if P_FAMILY_STONJOURNER
    [SPECIES_STONJOURNER] =
    {
        .baseHP        = 100,
        .baseAttack    = 125,
        .baseDefense   = 135,
        .baseSpeed     = 70,
        .baseSpAttack  = 20,
        .baseSpDefense = 20,
        .types = { TYPE_ROCK, TYPE_ROCK },
        .catchRate = 60,
        .expYield = 165,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_POWER_SPOT, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Humanolith"),
        .cryId = CRY_STONJOURNER,
        .natDexNum = NATIONAL_DEX_STONJOURNER,
        .categoryName = _("Megalithen"),
        .height = 25,
        .weight = 5200,
        .description = POKEDEX_DESC_STRING(
            "Es verweilt auf weitläufigen Wiesen\n"
            "und beobachtet den Lauf der Sonne.\n"
            "Dynamische Trittangriffe sind sein\n"
            "Spezialgebiet."),
        .pokemonScale = 257,
        .pokemonOffset = 10,
        .trainerScale = 423,
        .trainerOffset = 8,
        FRONT_PIC(Stonjourner, 48, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Stonjourner,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Stonjourner, 64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Stonjourner),
        ICON(Stonjourner, 2),
        .footprint = gMonFootprint_Stonjourner,
        LEARNSETS(Stonjourner),
    },
#endif //P_FAMILY_STONJOURNER

#if P_FAMILY_EISCUE
#define EISCUE_MISC_INFO                                        \
        .types = { TYPE_ICE, TYPE_ICE },                        \
        .catchRate = 60,                                        \
        .expYield = 165,                                        \
        .evYield_Defense = 2,                                   \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 25,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_SLOW,                              \
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },    \
        .abilities = { ABILITY_ICE_FACE, ABILITY_NONE },        \
        .bodyColor = BODY_COLOR_BLUE,                           \
        .speciesName = _("Humanolith"),                             \
        .natDexNum = NATIONAL_DEX_EISCUE,                       \
        .categoryName = _("Megalithen"),                           \
        .height = 14,                                           \
        .weight = 890,                                          \
        .pokemonScale = 265,                                    \
        .pokemonOffset = 2,                                     \
        .trainerScale = 262,                                    \
        .trainerOffset = 0,                                     \
        .footprint = gMonFootprint_Eiscue,                      \
        LEARNSETS(Eiscue),                                      \
        .formSpeciesIdTable = sEiscueFormSpeciesIdTable,        \
        .formChangeTable = sEiscueFormChangeTable

    [SPECIES_EISCUE_ICE_FACE] =
    {
        EISCUE_MISC_INFO,
        .baseHP        = 75,
        .baseAttack    = 80,
        .baseDefense   = 110,
        .baseSpeed     = 50,
        .baseSpAttack  = 65,
        .baseSpDefense = 90,
        .cryId = CRY_EISCUE_ICE_FACE,
        .description = POKEDEX_DESC_STRING(
            "Es kam von einem extrem kalten Ort,\n"
            "indem es sich treiben ließ und\n"
            "schließlich angespült wurde. Es\n"
            "kühlt unablässig sein Gesicht mit\n"
            "Eis."),
        FRONT_PIC(EiscueIceFace, 40, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Eiscue,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(EiscueIceFace, 48, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(EiscueIceFace),
        ICON(EiscueIceFace, 0),
    },

    [SPECIES_EISCUE_NOICE_FACE] =
    {
        EISCUE_MISC_INFO,
        .baseHP        = 75,
        .baseAttack    = 80,
        .baseDefense   = 70,
        .baseSpeed     = 130,
        .baseSpAttack  = 65,
        .baseSpDefense = 50,
        .cryId = CRY_EISCUE_NOICE_FACE,
        .description = POKEDEX_DESC_STRING(
            "Es kam von einem extrem kalten Ort,\n"
            "indem es sich treiben ließ und\n"
            "schließlich angespült wurde. Es\n"
            "kühlt unablässig sein Gesicht mit\n"
            "Eis."),
        FRONT_PIC(EiscueNoiceFace, 40, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Eiscue,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(EiscueNoiceFace, 40, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(EiscueNoiceFace),
        ICON(EiscueNoiceFace, 0),
    },
#endif //P_FAMILY_EISCUE

#if P_FAMILY_INDEEDEE
#define INDEEDEE_MISC_INFO                                  \
        .types = { TYPE_PSYCHIC, TYPE_NORMAL },             \
        .catchRate = 30,                                    \
        .expYield = 166,                                    \
        .eggCycles = 40,                                    \
        .friendship = 140,                                  \
        .growthRate = GROWTH_FAST,                          \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_FAIRY },  \
        .bodyColor = BODY_COLOR_PURPLE,                     \
        .speciesName = _("Kubuin"),                       \
        .natDexNum = NATIONAL_DEX_INDEEDEE,                 \
        .categoryName = _("Pinguin"),                       \
        .height = 9,                                        \
        .weight = 280,                                      \
        .pokemonScale = 338,                                \
        .pokemonOffset = 8,                                 \
        .trainerScale = 256,                                \
        .trainerOffset = 0,                                 \
        .footprint = gMonFootprint_Indeedee,                \
        .formSpeciesIdTable = sIndeedeeFormSpeciesIdTable

    [SPECIES_INDEEDEE_MALE] =
    {
        INDEEDEE_MISC_INFO,
        .baseHP        = 60,
        .baseAttack    = 65,
        .baseDefense   = 55,
        .baseSpeed     = 95,
        .baseSpAttack  = 105,
        .baseSpDefense = 95,
        .evYield_SpAttack = 2,
        .genderRatio = MON_MALE,
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_SYNCHRONIZE, ABILITY_PSYCHIC_SURGE },
        .cryId = CRY_INDEEDEE_MALE,
        .description = POKEDEX_DESC_STRING(
            "Mit den Hörnern auf seinem Kopf\n"
            "erfasst es die Gefühle seines\n"
            "Gegenübers. Männchen kümmern sich\n"
            "wie Bedienstete um ihren Trainer."),
        FRONT_PIC(IndeedeeMale, 40, 56),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Indeedee,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(IndeedeeMale, 56, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(IndeedeeMale),
        ICON(IndeedeeMale, 2),
        LEARNSETS(IndeedeeMale),
    },

    [SPECIES_INDEEDEE_FEMALE] =
    {
        INDEEDEE_MISC_INFO,
        .baseHP        = 70,
        .baseAttack    = 55,
        .baseDefense   = 65,
        .baseSpeed     = 85,
        .baseSpAttack  = 95,
        .baseSpDefense = 105,
        .evYield_SpDefense = 2,
        .genderRatio = MON_FEMALE,
        .abilities = { ABILITY_OWN_TEMPO, ABILITY_SYNCHRONIZE, ABILITY_PSYCHIC_SURGE },
        .cryId = CRY_INDEEDEE_FEMALE,
        .description = POKEDEX_DESC_STRING(
            "Mit den Hörnern auf seinem Kopf\n"
            "erfasst es die Gefühle seines\n"
            "Gegenübers. Männchen kümmern sich\n"
            "wie Bedienstete um ihren Trainer."),
        FRONT_PIC(IndeedeeFemale, 40, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Indeedee,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(IndeedeeFemale, 64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(IndeedeeFemale),
        ICON(IndeedeeFemale, 2),
        LEARNSETS(IndeedeeFemale),
    },
#endif //P_FAMILY_INDEEDEE

#if P_FAMILY_MORPEKO
#define MORPEKO_MISC_INFO                                       \
        .baseHP        = 58,                                    \
        .baseAttack    = 95,                                    \
        .baseDefense   = 58,                                    \
        .baseSpeed     = 97,                                    \
        .baseSpAttack  = 70,                                    \
        .baseSpDefense = 58,                                    \
        .types = { TYPE_ELECTRIC, TYPE_DARK },                  \
        .catchRate = 180,                                       \
        .expYield = 153,                                        \
        .evYield_Speed = 2,                                     \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 10,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_MEDIUM_FAST,                       \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FAIRY },      \
        .abilities = { ABILITY_HUNGER_SWITCH, ABILITY_NONE },   \
        .bodyColor = BODY_COLOR_YELLOW,                         \
        .speciesName = _("Servol"),                            \
        .natDexNum = NATIONAL_DEX_MORPEKO,                      \
        .categoryName = _("Emotions"),                         \
        .height = 3,                                            \
        .weight = 30,                                           \
        .pokemonScale = 530,                                    \
        .pokemonOffset = 13,                                    \
        .trainerScale = 256,                                    \
        .trainerOffset = 0,                                     \
        .footprint = gMonFootprint_Morpeko,                     \
        LEARNSETS(Morpeko),                                     \
        .formSpeciesIdTable = sMorpekoFormSpeciesIdTable,       \
        .formChangeTable = sMorpekoFormChangeTable

    [SPECIES_MORPEKO_FULL_BELLY] =
    {
        MORPEKO_MISC_INFO,
        .cryId = CRY_MORPEKO_FULL_BELLY,
        .description = POKEDEX_DESC_STRING(
            "Dieses immerzu hungrige Pokémon\n"
            "frisst Samen, die es in seinen\n"
            "beutelartigen Taschen verwahrt, und\n"
            "produziert so Elektrizität."),
        FRONT_PIC(MorpekoFullBelly, 32, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Morpeko,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(MorpekoFullBelly, 48, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(MorpekoFullBelly),
        ICON(MorpekoFullBelly, 2),
    },

    [SPECIES_MORPEKO_HANGRY] =
    {
        MORPEKO_MISC_INFO,
        .cryId = CRY_MORPEKO_HANGRY,
        .description = POKEDEX_DESC_STRING(
            "Dieses immerzu hungrige Pokémon\n"
            "frisst Samen, die es in seinen\n"
            "beutelartigen Taschen verwahrt, und\n"
            "produziert so Elektrizität."),
        FRONT_PIC(MorpekoHangry, 32, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Morpeko,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(MorpekoHangry, 48, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(MorpekoHangry),
        ICON(MorpekoHangry, 2),
    },
#endif //P_FAMILY_MORPEKO

#if P_FAMILY_CUFANT
    [SPECIES_CUFANT] =
    {
        .baseHP        = 72,
        .baseAttack    = 80,
        .baseDefense   = 49,
        .baseSpeed     = 40,
        .baseSpAttack  = 40,
        .baseSpDefense = 49,
        .types = { TYPE_STEEL, TYPE_STEEL },
        .catchRate = 190,
        .expYield = 66,
        .evYield_Attack = 1,
        .itemRare = ITEM_LAGGING_TAIL,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_SHEER_FORCE, ABILITY_NONE, ABILITY_HEAVY_METAL },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Kupfanti"),
        .cryId = CRY_CUFANT,
        .natDexNum = NATIONAL_DEX_CUFANT,
        .categoryName = _("Kupferfant"),
        .height = 12,
        .weight = 1000,
        .description = POKEDEX_DESC_STRING(
            "Harte Knochenarbeit kann man problemlos\n"
            "ihm überlassen. Sein Körper aus Kupfer\n"
            "rostet im Regen und nimmt eine leuchtend\n"
            "grüne Farbe an."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cufant, 56, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Cufant,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Cufant, 64, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Cufant),
        ICON(Cufant, 0),
        .footprint = gMonFootprint_Cufant,
        LEARNSETS(Cufant),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_COPPERAJAH}),
    },

#define COPPERAJAH_MISC_INFO                                                        \
        .baseHP        = 122,                                                       \
        .baseAttack    = 130,                                                       \
        .baseDefense   = 69,                                                        \
        .baseSpeed     = 30,                                                        \
        .baseSpAttack  = 80,                                                        \
        .baseSpDefense = 69,                                                        \
        .types = { TYPE_STEEL, TYPE_STEEL },                                        \
        .catchRate = 90,                                                            \
        .expYield = 175,                                                            \
        .evYield_Attack = 2,                                                        \
        .itemRare = ITEM_LAGGING_TAIL,                                              \
        .genderRatio = PERCENT_FEMALE(50),                                          \
        .eggCycles = 25,                                                            \
        .friendship = STANDARD_FRIENDSHIP,                                          \
        .growthRate = GROWTH_MEDIUM_FAST,                                           \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_MINERAL },                        \
        .abilities = { ABILITY_SHEER_FORCE, ABILITY_NONE, ABILITY_HEAVY_METAL },    \
        .bodyColor = BODY_COLOR_GREEN,                                              \
        .speciesName = _("Kupfanti"),                                             \
        .cryId = CRY_COPPERAJAH,                                                    \
        .natDexNum = NATIONAL_DEX_COPPERAJAH,                                       \
        .categoryName = _("Kupferfant"),                                            \
        .footprint = gMonFootprint_Copperajah,                                      \
        LEARNSETS(Copperajah),                                                      \
        .formSpeciesIdTable = sCopperajahFormSpeciesIdTable,                        \
        .formChangeTable = sCopperajahFormChangeTable

    [SPECIES_COPPERAJAH] =
    {
        COPPERAJAH_MISC_INFO,
        .height = 30,
        .weight = 6500,
        .description = POKEDEX_DESC_STRING(
            "Seine grüne Haut ist\n"
            "wasserresistent. Es kam vor langer\n"
            "Zeit aus einer anderen Region und\n"
            "verrichtete mit den Menschen\n"
            "Arbeiten."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Copperajah, 64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Copperajah,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Copperajah, 64, 32),
        .backPicYOffset = 16,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Copperajah),
        ICON(Copperajah, 0),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_COPPERAJAH_GIGANTAMAX] =
    {
        COPPERAJAH_MISC_INFO,
        .height = 230,
        .weight = 0,
        .description = POKEDEX_DESC_STRING(
            "Seine grüne Haut ist\n"
            "wasserresistent. Es kam vor langer\n"
            "Zeit aus einer anderen Region und\n"
            "verrichtete mit den Menschen\n"
            "Arbeiten."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(CopperajahGigantamax, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_CopperajahGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(CopperajahGigantamax, 64, 64),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(CopperajahGigantamax),
        ICON(CopperajahGigantamax, 0),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_CUFANT

#if P_FAMILY_DRACOZOLT
    [SPECIES_DRACOZOLT] =
    {
        .baseHP        = 90,
        .baseAttack    = 100,
        .baseDefense   = 90,
        .baseSpeed     = 75,
        .baseSpAttack  = 80,
        .baseSpDefense = 70,
        .types = { TYPE_ELECTRIC, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 177,
        .evYield_Attack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_VOLT_ABSORB, ABILITY_HUSTLE, ABILITY_SAND_RUSH },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Lectragon"),
        .cryId = CRY_DRACOZOLT,
        .natDexNum = NATIONAL_DEX_DRACOZOLT,
        .categoryName = _("Fossil"),
        .height = 18,
        .weight = 1900,
        .description = POKEDEX_DESC_STRING(
            "Mit den kräftigen Muskeln in seinem\n"
            "Schwanz erzeugt es Elektrizität. Sein\n"
            "OberKörper ist im Vergleich zu seinem\n"
            "UnterKörper zu klein."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Dracozolt, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Dracozolt,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Dracozolt, 64, 56),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Dracozolt),
        ICON(Dracozolt, 1),
        .footprint = gMonFootprint_Dracozolt,
        LEARNSETS(Dracozolt),
    },
#endif //P_FAMILY_DRACOZOLT

#if P_FAMILY_ARCTOZOLT
    [SPECIES_ARCTOZOLT] =
    {
        .baseHP        = 90,
        .baseAttack    = 100,
        .baseDefense   = 90,
        .baseSpeed     = 55,
        .baseSpAttack  = 90,
        .baseSpDefense = 80,
        .types = { TYPE_ELECTRIC, TYPE_ICE },
        .catchRate = 45,
        .expYield = 177,
        .evYield_Attack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_VOLT_ABSORB, ABILITY_STATIC, ABILITY_SLUSH_RUSH },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Lecryodon"),
        .cryId = CRY_ARCTOZOLT,
        .natDexNum = NATIONAL_DEX_ARCTOZOLT,
        .categoryName = _("Fossil"),
        .height = 23,
        .weight = 1500,
        .description = POKEDEX_DESC_STRING(
            "Durch das Zittern seines gefrorenen\n"
            "OberKörpers entsteht Elektrizität.\n"
            "Das Laufen fällt ihm äußerst\n"
            "schwer."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 342,
        .trainerOffset = 7,
        FRONT_PIC(Arctozolt, 56, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Arctozolt,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Arctozolt, 56, 48),
        .backPicYOffset = 8,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Arctozolt),
        ICON(Arctozolt, 2),
        .footprint = gMonFootprint_Arctozolt,
        LEARNSETS(Arctozolt),
    },
#endif //P_FAMILY_ARCTOZOLT

#if P_FAMILY_DRACOVISH
    [SPECIES_DRACOVISH] =
    {
        .baseHP        = 90,
        .baseAttack    = 90,
        .baseDefense   = 100,
        .baseSpeed     = 75,
        .baseSpAttack  = 70,
        .baseSpDefense = 80,
        .types = { TYPE_WATER, TYPE_DRAGON },
        .catchRate = 45,
        .expYield = 177,
        .evYield_Defense = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_STRONG_JAW, ABILITY_SAND_RUSH },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Pescragon"),
        .cryId = CRY_DRACOVISH,
        .natDexNum = NATIONAL_DEX_DRACOVISH,
        .categoryName = _("Fossil"),
        .height = 23,
        .weight = 2150,
        .description = POKEDEX_DESC_STRING(
            "Seine außergewöhnlich kräftigen Beine\n"
            "lassen es zwar über 60 km/h schnell\n"
            "laufen, doch atmen kann es nur unter\n"
            "Wasser."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 342,
        .trainerOffset = 7,
        FRONT_PIC(Dracovish, 48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Dracovish,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Dracovish, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Dracovish),
        ICON(Dracovish, 0),
        .footprint = gMonFootprint_Dracovish,
        LEARNSETS(Dracovish),
    },
#endif //P_FAMILY_DRACOVISH

#if P_FAMILY_ARCTOVISH
    [SPECIES_ARCTOVISH] =
    {
        .baseHP        = 90,
        .baseAttack    = 90,
        .baseDefense   = 100,
        .baseSpeed     = 55,
        .baseSpAttack  = 80,
        .baseSpDefense = 90,
        .types = { TYPE_WATER, TYPE_ICE },
        .catchRate = 45,
        .expYield = 177,
        .evYield_Defense = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 35,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_ICE_BODY, ABILITY_SLUSH_RUSH },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Pescryodon"),
        .cryId = CRY_ARCTOVISH,
        .natDexNum = NATIONAL_DEX_ARCTOVISH,
        .categoryName = _("Fossil"),
        .height = 20,
        .weight = 1750,
        .description = POKEDEX_DESC_STRING(
            "Kein Angriff konnte seine Gesichtshaut\n"
            "verletzen, doch es war in seiner Atmung\n"
            "eingeschränkt und starb daher aus."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(Arctovish, 64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Arctovish,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Arctovish, 64, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Arctovish),
        ICON(Arctovish, 0),
        .footprint = gMonFootprint_Arctovish,
        LEARNSETS(Arctovish),
    },
#endif //P_FAMILY_ARCTOVISH

#if P_FAMILY_DURALUDON
#define DURALUDON_MISC_INFO                                                             \
        .baseHP        = 70,                                                            \
        .baseAttack    = 95,                                                            \
        .baseDefense   = 115,                                                           \
        .baseSpeed     = 85,                                                            \
        .baseSpAttack  = 120,                                                           \
        .baseSpDefense = 50,                                                            \
        .types = { TYPE_STEEL, TYPE_DRAGON },                                           \
        .catchRate = 45,                                                                \
        .expYield = 187,                                                                \
        .evYield_SpAttack = 2,                                                          \
        .genderRatio = PERCENT_FEMALE(50),                                              \
        .eggCycles = 30,                                                                \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_MEDIUM_FAST,                                               \
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_DRAGON },                           \
        .abilities = { ABILITY_LIGHT_METAL, ABILITY_HEAVY_METAL, ABILITY_STALWART },    \
        .bodyColor = BODY_COLOR_WHITE,                                                  \
        .speciesName = _("Pescryodon"),                                                  \
        .cryId = CRY_DURALUDON,                                                         \
        .natDexNum = NATIONAL_DEX_DURALUDON,                                            \
        .categoryName = _("Fossil"),                                                     \
        .footprint = gMonFootprint_Duraludon,                                           \
        LEARNSETS(Duraludon),                                                           \
        .formSpeciesIdTable = sDuraludonFormSpeciesIdTable,                             \
        .formChangeTable = sDuraludonFormChangeTable

    [SPECIES_DURALUDON] =
    {
        DURALUDON_MISC_INFO,
        .height = 18,
        .weight = 400,
        .description = POKEDEX_DESC_STRING(
            "Sein an aufpoliertes Metall\n"
            "erinnernder Körper ist nicht nur\n"
            "leicht, sondern auch robust. Er hat\n"
            "jedoch den Nachteil, schnell zu\n"
            "rosten."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(Duraludon, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Duraludon,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Duraludon, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Duraludon),
        ICON(Duraludon, 0),
        .evolutions = EVOLUTION({EVO_ITEM, ITEM_METAL_ALLOY, SPECIES_ARCHALUDON}),
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_DURALUDON_GIGANTAMAX] =
    {
        DURALUDON_MISC_INFO,
        .height = 430,
        .weight = 0,
        .description = POKEDEX_DESC_STRING(
            "Sein an aufpoliertes Metall\n"
            "erinnernder Körper ist nicht nur\n"
            "leicht, sondern auch robust. Er hat\n"
            "jedoch den Nachteil, schnell zu\n"
            "rosten."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        FRONT_PIC(DuraludonGigantamax, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_DuraludonGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(DuraludonGigantamax, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(DuraludonGigantamax),
        ICON(DuraludonGigantamax, 0),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS

#if P_GEN_9_CROSS_EVOS
    [SPECIES_ARCHALUDON] =
    {
        .baseHP        = 90,
        .baseAttack    = 105,
        .baseDefense   = 130,
        .baseSpeed     = 85,
        .baseSpAttack  = 125,
        .baseSpDefense = 65,
        .types = { TYPE_STEEL, TYPE_DRAGON },
        .catchRate = 10,
        .expYield = 300,
        .evYield_Defense = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_STAMINA, ABILITY_STURDY, ABILITY_STALWART },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Briduradon"),
        .cryId = CRY_ARCHALUDON,
        .natDexNum = NATIONAL_DEX_ARCHALUDON,
        .categoryName = _("Legierung"),
        .height = 20,
        .weight = 600,
        .description = COMPOUND_STRING(
            "Es sammelt statische Elektrizität aus\n"
            "seiner Umgebung. Die Strahlen, die es auf\n"
            "allen Vieren abfeuert, sind enorm\n"
            "kraftvoll."),
        .pokemonScale = 267,
        .pokemonOffset = 2,
        .trainerScale = 286,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Archaludon,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Archaludon,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Archaludon,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Archaludon,
        .shinyPalette = gMonShinyPalette_Archaludon,
        .iconSprite = gMonIcon_Archaludon,
        .iconPalIndex = 0,
        //FOOTPRINT(Archaludon)
        //.levelUpLearnset = sArchaludonLevelUpLearnset,
        //.teachableLearnset = sArchaludonTeachableLearnset,
    },
#endif //P_GEN_9_CROSS_EVOS
#endif //P_FAMILY_DURALUDON

#if P_FAMILY_DREEPY
    [SPECIES_DREEPY] =
    {
        .baseHP        = 28,
        .baseAttack    = 60,
        .baseDefense   = 30,
        .baseSpeed     = 82,
        .baseSpAttack  = 40,
        .baseSpDefense = 30,
        .types = { TYPE_DRAGON, TYPE_GHOST },
        .catchRate = 45,
        .expYield = 54,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_INFILTRATOR, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Grolldra"),
        .cryId = CRY_DREEPY,
        .natDexNum = NATIONAL_DEX_DREEPY,
        .categoryName = _("Missgunst"),
        .height = 5,
        .weight = 20,
        .description = POKEDEX_DESC_STRING(
            "In der Urzeit lebte es im Meer. Nun\n"
            "ist es als Geister-Pokémon\n"
            "wiedererwacht und irrt rastlos\n"
            "durch seinen früheren Lebensraum."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Dreepy, 48, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Dreepy,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        BACK_PIC(Dreepy, 56, 40),
        .backPicYOffset = 15,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Dreepy),
        ICON(Dreepy, 0),
        .footprint = gMonFootprint_Dreepy,
        LEARNSETS(Dreepy),
        .evolutions = EVOLUTION({EVO_LEVEL, 50, SPECIES_DRAKLOAK}),
    },

    [SPECIES_DRAKLOAK] =
    {
        .baseHP        = 68,
        .baseAttack    = 80,
        .baseDefense   = 50,
        .baseSpeed     = 102,
        .baseSpAttack  = 60,
        .baseSpDefense = 50,
        .types = { TYPE_DRAGON, TYPE_GHOST },
        .catchRate = 45,
        .expYield = 144,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_INFILTRATOR, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Phandra"),
        .cryId = CRY_DRAKLOAK,
        .natDexNum = NATIONAL_DEX_DRAKLOAK,
        .categoryName = _("Betreuer"),
        .height = 14,
        .weight = 110,
        .description = POKEDEX_DESC_STRING(
            "Hat es kein Grolldra auf seinem Kopf, auf\n"
            "das es aufpassen kann, wird es nervös.\n"
            "Dann versucht es, ein anderes Pokémon auf\n"
            "seinen Kopf zu setzen."),
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Drakloak, 64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Drakloak,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        BACK_PIC(Drakloak, 64, 48),
        .backPicYOffset = 11,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Drakloak),
        ICON(Drakloak, 0),
        .footprint = gMonFootprint_Drakloak,
        LEARNSETS(Drakloak),
        .evolutions = EVOLUTION({EVO_LEVEL, 60, SPECIES_DRAGAPULT}),
    },

    [SPECIES_DRAGAPULT] =
    {
        .baseHP        = 88,
        .baseAttack    = 120,
        .baseDefense   = 75,
        .baseSpeed     = 142,
        .baseSpAttack  = 100,
        .baseSpDefense = 75,
        .types = { TYPE_DRAGON, TYPE_GHOST },
        .catchRate = 45,
        .expYield = 300,
        .evYield_Speed = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_CLEAR_BODY, ABILITY_INFILTRATOR, ABILITY_CURSED_BODY },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Katapuldra"),
        .cryId = CRY_DRAGAPULT,
        .natDexNum = NATIONAL_DEX_DRAGAPULT,
        .categoryName = _("Tarnkünstler"),
        .height = 30,
        .weight = 500,
        .description = POKEDEX_DESC_STRING(
            "Die Grolldra, die in seinen Hörnern\n"
            "sitzen, warten angeblich voller Spannung\n"
            "darauf, mit Mach-Geschwindigkeit\n"
            "abgefeuert zu werden."),
        .pokemonScale = 275,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Dragapult, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Dragapult,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 3,
        BACK_PIC(Dragapult, 64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Dragapult),
        ICON(Dragapult, 0),
        .footprint = gMonFootprint_Dragapult,
        LEARNSETS(Dragapult),
    },
#endif //P_FAMILY_DREEPY

#if P_FAMILY_ZACIAN
#define ZACIAN_MISC_INFO                                                                \
        .catchRate = 10,                                                                \
        .evYield_Speed = 3,                                                             \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_INTREPID_SWORD, ABILITY_NONE },                          \
        .bodyColor = BODY_COLOR_BLUE,                                                   \
        .isLegendary = TRUE,                                                            \
        .speciesName = _("Katapuldra"),                                                     \
        .natDexNum = NATIONAL_DEX_ZACIAN,                                               \
        .categoryName = _("Tarnkünstler"),                                                   \
        .height = 28,                                                                   \
        .pokemonScale = 275,                                                            \
        .pokemonOffset = 7,                                                             \
        .trainerScale = 256,                                                            \
        .trainerOffset = 0,                                                             \
        .footprint = gMonFootprint_Zacian,                                              \
        LEARNSETS(Zacian),                                                              \
        .formSpeciesIdTable = sZacianFormSpeciesIdTable,                                \
        .formChangeTable = sZacianFormChangeTable

    [SPECIES_ZACIAN_HERO_OF_MANY_BATTLES] =
    {
        ZACIAN_MISC_INFO,
        .baseHP        = 92,
        .baseAttack    = P_UPDATED_STATS >= GEN_9 ? 120 : 130,
        .baseDefense   = 115,
        .baseSpeed     = 138,
        .baseSpAttack  = 80,
        .baseSpDefense = 115,
        .types = { TYPE_FAIRY, TYPE_FAIRY },
        .expYield = 335,
        .cryId = CRY_ZACIAN_HERO_OF_MANY_BATTLES,
        .weight = 1100,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon gilt als Legendärer\n"
            "Held. Es nimmt Metall auf, wandelt\n"
            "dies in eine Waffe um und kämpft\n"
            "damit."),
        FRONT_PIC(ZacianHeroOfManyBattles, 64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Zacian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(ZacianHeroOfManyBattles, 64, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(ZacianHeroOfManyBattles),
        ICON(ZacianHeroOfManyBattles, 2),
    },

    [SPECIES_ZACIAN_CROWNED_SWORD] =
    {
        ZACIAN_MISC_INFO,
        .baseHP        = 92,
        .baseAttack    = P_UPDATED_STATS >= GEN_9 ? 150 : 170,
        .baseDefense   = 115,
        .baseSpeed     = 148,
        .baseSpAttack  = 80,
        .baseSpDefense = 115,
        .types = { TYPE_FAIRY, TYPE_STEEL },
        .expYield = 360,
        .cryId = CRY_ZACIAN_CROWNED_SWORD,
        .weight = 3550,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon gilt als Legendärer\n"
            "Held. Es nimmt Metall auf, wandelt\n"
            "dies in eine Waffe um und kämpft\n"
            "damit."),
        FRONT_PIC(ZacianCrownedSword, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Zacian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(ZacianCrownedSword, 64, 56),
        .backPicYOffset = 6,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(ZacianCrownedSword),
        ICON(ZacianCrownedSword, 2),
    },
#endif //P_FAMILY_ZACIAN

#if P_FAMILY_ZAMAZENTA
#define ZAMAZENTA_MISC_INFO                                                             \
        .catchRate = 10,                                                                \
        .evYield_Speed = 3,                                                             \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_DAUNTLESS_SHIELD, ABILITY_NONE },                        \
        .bodyColor = BODY_COLOR_RED,                                                    \
        .isLegendary = TRUE,                                                            \
        .speciesName = _("Zacian"),                                                  \
        .natDexNum = NATIONAL_DEX_ZAMAZENTA,                                            \
        .categoryName = _("Krieger"),                                                   \
        .height = 29,                                                                   \
        .pokemonScale = 275,                                                            \
        .pokemonOffset = 7,                                                             \
        .trainerScale = 256,                                                            \
        .trainerOffset = 0,                                                             \
        .footprint = gMonFootprint_Zamazenta,                                           \
        LEARNSETS(Zamazenta),                                                           \
        .formSpeciesIdTable = sZamazentaFormSpeciesIdTable,                             \
        .formChangeTable = sZamazentaFormChangeTable

    [SPECIES_ZAMAZENTA_HERO_OF_MANY_BATTLES] =
    {
        ZAMAZENTA_MISC_INFO,
        .baseHP        = 92,
        .baseAttack    = P_UPDATED_STATS >= GEN_9 ? 120 : 130,
        .baseDefense   = 115,
        .baseSpeed     = 138,
        .baseSpAttack  = 80,
        .baseSpDefense = 115,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .expYield = 335,
        .cryId = CRY_ZAMAZENTA_HERO_OF_MANY_BATTLES,
        .weight = 2100,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon vereinte seine\n"
            "Kräfte mit einem Menschenkönig und\n"
            "rettete die Galar-Region. Es nimmt\n"
            "Metall in sich auf und kämpft\n"
            "damit."),
        FRONT_PIC(ZamazentaHeroOfManyBattles, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Zamazenta,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(ZamazentaHeroOfManyBattles, 64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(ZamazentaHeroOfManyBattles),
        ICON(ZamazentaHeroOfManyBattles, 2),
    },

    [SPECIES_ZAMAZENTA_CROWNED_SHIELD] =
    {
        ZAMAZENTA_MISC_INFO,
        .baseHP        = 92,
        .baseAttack    = P_UPDATED_STATS >= GEN_9 ? 120 : 130,
        .baseDefense   = P_UPDATED_STATS >= GEN_9 ? 140 : 145,
        .baseSpeed     = 128,
        .baseSpAttack  = 80,
        .baseSpDefense = P_UPDATED_STATS >= GEN_9 ? 140 : 145,
        .types = { TYPE_FIGHTING, TYPE_STEEL },
        .expYield = 360,
        .cryId = CRY_ZAMAZENTA_CROWNED_SHIELD,
        .weight = 7850,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon vereinte seine\n"
            "Kräfte mit einem Menschenkönig und\n"
            "rettete die Galar-Region. Es nimmt\n"
            "Metall in sich auf und kämpft\n"
            "damit."),
        FRONT_PIC(ZamazentaCrownedShield, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Zamazenta,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(ZamazentaCrownedShield, 64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(ZamazentaCrownedShield),
        ICON(ZamazentaCrownedShield, 2),
    },
#endif //P_FAMILY_ZAMAZENTA

#if P_FAMILY_ETERNATUS
#define ETERNATUS_MISC_INFO                                                             \
        .types = { TYPE_POISON, TYPE_DRAGON },                                          \
        .catchRate = 255,                                                               \
        .evYield_HP = 3,                                                                \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE },                                \
        .bodyColor = BODY_COLOR_PURPLE,                                                 \
        .isLegendary = TRUE,                                                            \
        .speciesName = _("Zamazenta"),                                                  \
        .natDexNum = NATIONAL_DEX_ETERNATUS,                                            \
        .categoryName = _("Krieger"),                                                  \
        .footprint = gMonFootprint_Eternatus,                                           \
        LEARNSETS(Eternatus),                                                           \
        .formSpeciesIdTable = sEternatusFormSpeciesIdTable

    [SPECIES_ETERNATUS] =
    {
        ETERNATUS_MISC_INFO,
        .baseHP        = 140,
        .baseAttack    = 85,
        .baseDefense   = 95,
        .baseSpeed     = 130,
        .baseSpAttack  = 145,
        .baseSpDefense = 95,
        .expYield = 345,
        .cryId = CRY_ETERNATUS,
        .height = 200,
        .weight = 9500,
        .pokemonScale = 230,
        .pokemonOffset = 0,
        .trainerScale = 4852,
        .trainerOffset = 20,
        .description = POKEDEX_DESC_STRING(
            "Indem der Kern in seinem Brustkorb\n"
            "die Energie absorbiert, die aus dem\n"
            "Boden der Galar-Region strömt, wird\n"
            "es aktiv."),
        FRONT_PIC(Eternatus, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Eternatus,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 4,
        BACK_PIC(Eternatus, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Eternatus),
        ICON(Eternatus, 0),
    },

    [SPECIES_ETERNATUS_ETERNAMAX] =
    {
        ETERNATUS_MISC_INFO,
        .baseHP        = 255,
        .baseAttack    = 115,
        .baseDefense   = 250,
        .baseSpeed     = 130,
        .baseSpAttack  = 125,
        .baseSpDefense = 250,
        .expYield = 563,
        .cryId = CRY_ETERNATUS_ETERNAMAX,
        .height = 1000,
        .weight = 0,
        .pokemonScale = 230,
        .pokemonOffset = 0,
        .trainerScale = 4852,
        .trainerOffset = 20,
        .description = POKEDEX_DESC_STRING(
            "Indem der Kern in seinem Brustkorb\n"
            "die Energie absorbiert, die aus dem\n"
            "Boden der Galar-Region strömt, wird\n"
            "es aktiv."),
        FRONT_PIC(EternatusEternamax, 64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Eternatus,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 13,
        BACK_PIC(EternatusEternamax, 64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(EternatusEternamax),
        ICON(EternatusEternamax, 0),
    },
#endif //P_FAMILY_ETERNATUS

#if P_FAMILY_KUBFU
    [SPECIES_KUBFU] =
    {
        .baseHP        = 60,
        .baseAttack    = 90,
        .baseDefense   = 60,
        .baseSpeed     = 72,
        .baseSpAttack  = 53,
        .baseSpDefense = 50,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 3,
        .expYield = 77,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 120,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .isLegendary = TRUE,
        .speciesName = _("Dakuma"),
        .cryId = CRY_KUBFU,
        .natDexNum = NATIONAL_DEX_KUBFU,
        .categoryName = _("Kung-Fu"),
        .height = 6,
        .weight = 120,
        .description = POKEDEX_DESC_STRING(
            "Durch rigoroses Training\n"
            "perfektioniert es seine\n"
            "Kampftechnik. Diese bestimmt,\n"
            "welche Form Dakuma nach der\n"
            "Entwicklung annimmt."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Kubfu, 40, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Kubfu,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Kubfu, 56, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Kubfu),
        ICON(Kubfu, 1),
        .footprint = gMonFootprint_Kubfu,
        LEARNSETS(Kubfu),
        .evolutions = EVOLUTION({EVO_DARK_SCROLL, 0, SPECIES_URSHIFU_SINGLE_STRIKE_STYLE},
                                {EVO_ITEM, ITEM_SCROLL_OF_DARKNESS, SPECIES_URSHIFU_SINGLE_STRIKE_STYLE},
                                {EVO_WATER_SCROLL, 0, SPECIES_URSHIFU_RAPID_STRIKE_STYLE},
                                {EVO_ITEM, ITEM_SCROLL_OF_WATERS, SPECIES_URSHIFU_RAPID_STRIKE_STYLE}),
    },

#define URSHIFU_MISC_INFO(style)                                                        \
        .baseHP        = 100,                                                           \
        .baseAttack    = 130,                                                           \
        .baseDefense   = 100,                                                           \
        .baseSpeed     = 97,                                                            \
        .baseSpAttack  = 63,                                                            \
        .baseSpDefense = 60,                                                            \
        .catchRate = 3,                                                                 \
        .expYield = 275,                                                                \
        .evYield_Attack = 3,                                                            \
        .genderRatio = PERCENT_FEMALE(12.5),                                            \
        .eggCycles = 120,                                                               \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_UNSEEN_FIST, ABILITY_NONE },                             \
        .bodyColor = BODY_COLOR_GRAY,                                                   \
        .isLegendary = TRUE,                                                            \
        .speciesName = _("Dakuma"),                                                    \
        .natDexNum = NATIONAL_DEX_URSHIFU,                                              \
        .categoryName = _("Kung-Fu"),                                                     \
        .footprint = gMonFootprint_Urshifu,                                             \
        .formSpeciesIdTable = sUrshifuFormSpeciesIdTable

#define URSHIFU_SINGLE_STRIKE_STYLE_MISC_INFO       \
        .types = { TYPE_FIGHTING, TYPE_DARK },      \
        .cryId = CRY_URSHIFU_SINGLE_STRIKE_STYLE,   \
        LEARNSETS(UrshifuSingleStrikeStyle),        \
        URSHIFU_MISC_INFO(SingleStrike)

    [SPECIES_URSHIFU_SINGLE_STRIKE_STYLE] =
    {
        URSHIFU_SINGLE_STRIKE_STYLE_MISC_INFO,
        .height = 19,
        .weight = 1050,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .description = POKEDEX_DESC_STRING(
            "Es ist darauf spezialisiert, Gegner\n"
            "mit nur einem Treffer zu bezwingen,\n"
            "indem es sie schlagartig anfällt\n"
            "und einen fokussierten Hieb\n"
            "austeilt."),
        FRONT_PIC(UrshifuSingleStrikeStyle, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Urshifu,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(UrshifuSingleStrikeStyle, 64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(UrshifuSingleStrikeStyle),
        ICON(Urshifu, 2),
        .formChangeTable = sUrshifuSingleStrikeFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_URSHIFU_SINGLE_STRIKE_STYLE_GIGANTAMAX] =
    {
        URSHIFU_SINGLE_STRIKE_STYLE_MISC_INFO,
        .height = 290,
        .weight = 0,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .description = POKEDEX_DESC_STRING(
            "Es ist darauf spezialisiert, Gegner\n"
            "mit nur einem Treffer zu bezwingen,\n"
            "indem es sie schlagartig anfällt\n"
            "und einen fokussierten Hieb\n"
            "austeilt."),
        FRONT_PIC(UrshifuSingleStrikeStyleGigantamax, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_UrshifuSingleStrikeStyleGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(UrshifuSingleStrikeStyleGigantamax, 64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(UrshifuSingleStrikeStyleGigantamax),
        ICON(UrshifuSingleStrikeStyleGigantamax, 0),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS

#define URSHIFU_RAPID_STRIKE_STYLE_MISC_INFO        \
        .types = { TYPE_FIGHTING, TYPE_WATER },     \
        .cryId = CRY_URSHIFU_RAPID_STRIKE_STYLE,    \
        LEARNSETS(UrshifuRapidStrikeStyle),         \
        URSHIFU_MISC_INFO(RapidStrike)

    [SPECIES_URSHIFU_RAPID_STRIKE_STYLE] =
    {
        URSHIFU_RAPID_STRIKE_STYLE_MISC_INFO,
        .height = 19,
        .weight = 1050,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .description = POKEDEX_DESC_STRING(
            "Es ist darauf spezialisiert, Gegner\n"
            "mit nur einem Treffer zu bezwingen,\n"
            "indem es sie schlagartig anfällt\n"
            "und einen fokussierten Hieb\n"
            "austeilt."),
        FRONT_PIC(UrshifuRapidStrikeStyle, 56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Urshifu,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(UrshifuRapidStrikeStyle, 64, 56),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(UrshifuRapidStrikeStyle),
        ICON(Urshifu, 2),
        .formChangeTable = sUrshifuRapidStrikeFormChangeTable,
    },

#if P_GIGANTAMAX_FORMS
    [SPECIES_URSHIFU_RAPID_STRIKE_STYLE_GIGANTAMAX] =
    {
        URSHIFU_RAPID_STRIKE_STYLE_MISC_INFO,
        .height = 260,
        .weight = 0,
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .description = POKEDEX_DESC_STRING(
            "Es ist darauf spezialisiert, Gegner\n"
            "mit nur einem Treffer zu bezwingen,\n"
            "indem es sie schlagartig anfällt\n"
            "und einen fokussierten Hieb\n"
            "austeilt."),
        FRONT_PIC(UrshifuRapidStrikeStyleGigantamax, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_UrshifuRapidStrikeStyleGigantamax,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(UrshifuRapidStrikeStyleGigantamax, 64, 64),
        .backPicYOffset = 4,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(UrshifuRapidStrikeStyleGigantamax),
        ICON(UrshifuRapidStrikeStyleGigantamax, 0),
        .isGigantamax = TRUE,
    },
#endif //P_GIGANTAMAX_FORMS
#endif //P_FAMILY_KUBFU


#if P_FAMILY_ZARUDE
#define ZARUDE_MISC_INFO                                                                \
        .baseHP        = 105,                                                           \
        .baseAttack    = 120,                                                           \
        .baseDefense   = 105,                                                           \
        .baseSpeed     = 105,                                                           \
        .baseSpAttack  = 70,                                                            \
        .baseSpDefense = 95,                                                            \
        .types = { TYPE_DARK, TYPE_GRASS },                                             \
        .catchRate = 3,                                                                 \
        .expYield = 300,                                                                \
        .evYield_Attack = 3,                                                            \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_LEAF_GUARD, ABILITY_NONE },                              \
        .bodyColor = BODY_COLOR_GREEN,                                                  \
        .isMythical = TRUE,                                                             \
        .speciesName = _("Wulaosu"),                                                     \
        .cryId = CRY_ZARUDE,                                                            \
        .natDexNum = NATIONAL_DEX_ZARUDE,                                               \
        .categoryName = _("Kung-Fu"),                                              \
        .height = 18,                                                                   \
        .weight = 700,                                                                  \
        .pokemonScale = 267,                                                            \
        .pokemonOffset = 2,                                                             \
        .trainerScale = 286,                                                            \
        .trainerOffset = 1,                                                             \
        .footprint = gMonFootprint_Zarude,                                              \
        LEARNSETS(Zarude),                                                              \
        .formSpeciesIdTable = sZarudeFormSpeciesIdTable

    [SPECIES_ZARUDE] =
    {
        ZARUDE_MISC_INFO,
        .description = POKEDEX_DESC_STRING(
            "Zarude leben gruppenweise in\n"
            "dichten Wäldern und werden von den\n"
            "anderen Pokémon dort gefürchtet, da\n"
            "sie sehr aggressiv sind."),
        FRONT_PIC(Zarude, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Zarude,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Zarude, 64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Zarude),
        ICON(Zarude, 1),
    },
    [SPECIES_ZARUDE_DADA] =
    {
        ZARUDE_MISC_INFO,
        .description = POKEDEX_DESC_STRING(
            "Zarude leben gruppenweise in\n"
            "dichten Wäldern und werden von den\n"
            "anderen Pokémon dort gefürchtet, da\n"
            "sie sehr aggressiv sind."),
        FRONT_PIC(ZarudeDada, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Zarude,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(ZarudeDada, 64, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(ZarudeDada),
        ICON(ZarudeDada, 1),
    },
#endif //P_FAMILY_ZARUDE

#if P_FAMILY_REGIELEKI
    [SPECIES_REGIELEKI] =
    {
        .baseHP        = 80,
        .baseAttack    = 100,
        .baseDefense   = 50,
        .baseSpeed     = 200,
        .baseSpAttack  = 100,
        .baseSpDefense = 50,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 3,
        .expYield = 290,
        .evYield_Speed = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_TRANSISTOR, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Regieleki"),
        .cryId = CRY_REGIELEKI,
        .natDexNum = NATIONAL_DEX_REGIELEKI,
        .categoryName = _("Elektronen"),
        .height = 12,
        .weight = 1450,
        .description = POKEDEX_DESC_STRING(
            "Sein Körper besteht aus einem Organ, das\n"
            "elektrische Energie erzeugt. Regieleki\n"
            "kann genug Strom produzieren, um ganz\n"
            "Galar zu versorgen."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Regieleki, 64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Regieleki,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        BACK_PIC(Regieleki, 64, 48),
        .backPicYOffset = 9,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Regieleki),
        ICON(Regieleki, 0),
        .footprint = gMonFootprint_Regieleki,
        LEARNSETS(Regieleki),
        .isLegendary = TRUE,
    },
#endif //P_FAMILY_REGIELEKI

#if P_FAMILY_REGIDRAGO
    [SPECIES_REGIDRAGO] =
    {
        .baseHP        = 200,
        .baseAttack    = 100,
        .baseDefense   = 50,
        .baseSpeed     = 80,
        .baseSpAttack  = 100,
        .baseSpDefense = 50,
        .types = { TYPE_DRAGON, TYPE_DRAGON },
        .catchRate = 3,
        .expYield = 290,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_DRAGONS_MAW, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .isLegendary = TRUE,
        .speciesName = _("Regidrago"),
        .cryId = CRY_REGIDRAGO,
        .natDexNum = NATIONAL_DEX_REGIDRAGO,
        .categoryName = _("Drachenkugel"),
        .height = 21,
        .weight = 2000,
        .description = POKEDEX_DESC_STRING(
            "Einer unbestätigten Theorie zufolge\n"
            "sind seine Arme wie der Kopf eines\n"
            "urzeitlichen Drachen-Pokémon\n"
            "geformt."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 365,
        .trainerOffset = 7,
        FRONT_PIC(Regidrago, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Regidrago,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 5,
        BACK_PIC(Regidrago, 64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Regidrago),
        ICON(Regidrago, 0),
        .footprint = gMonFootprint_Regidrago,
        LEARNSETS(Regidrago),
    },
#endif //P_FAMILY_REGIDRAGO

#if P_FAMILY_GLASTRIER
    [SPECIES_GLASTRIER] =
    {
        .baseHP        = 100,
        .baseAttack    = 145,
        .baseDefense   = 130,
        .baseSpeed     = 30,
        .baseSpAttack  = 65,
        .baseSpDefense = 110,
        .types = { TYPE_ICE, TYPE_ICE },
        .catchRate = 3,
        .expYield = 290,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_CHILLING_NEIGH, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .isLegendary = TRUE,
        .speciesName = _("Polaross"),
        .cryId = CRY_GLASTRIER,
        .natDexNum = NATIONAL_DEX_GLASTRIER,
        .categoryName = _("Wildblut"),
        .height = 22,
        .weight = 8000,
        .description = POKEDEX_DESC_STRING(
            "Aus seinen Hufen verströmt es\n"
            "eisige Kälte. Dieses ungestüme\n"
            "Pokémon nimmt sich alles, was es\n"
            "will, mit roher Gewalt."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 348,
        .trainerOffset = 6,
        FRONT_PIC(Glastrier, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Glastrier,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Glastrier, 56, 64),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Glastrier),
        ICON(Glastrier, 0),
        .footprint = gMonFootprint_Glastrier,
        LEARNSETS(Glastrier),
    },
#endif //P_FAMILY_GLASTRIER

#if P_FAMILY_SPECTRIER
    [SPECIES_SPECTRIER] =
    {
        .baseHP        = 100,
        .baseAttack    = 65,
        .baseDefense   = 60,
        .baseSpeed     = 130,
        .baseSpAttack  = 145,
        .baseSpDefense = 80,
        .types = { TYPE_GHOST, TYPE_GHOST },
        .catchRate = 3,
        .expYield = 290,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_GRIM_NEIGH, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
        .isLegendary = TRUE,
        .speciesName = _("Phantoross"),
        .cryId = CRY_SPECTRIER,
        .natDexNum = NATIONAL_DEX_SPECTRIER,
        .categoryName = _("Flinkblut"),
        .height = 20,
        .weight = 445,
        .description = POKEDEX_DESC_STRING(
            "Es galoppiert durch die finstere Nacht und\n"
            "absorbiert die Lebensenergie der\n"
            "Schlafenden. Phantoross bevorzugt\n"
            "Einsamkeit und Stille."),
        .pokemonScale = 261,
        .pokemonOffset = 1,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(Spectrier, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Spectrier,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Spectrier, 56, 56),
        .backPicYOffset = 5,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Spectrier),
        ICON(Spectrier, 0),
        .footprint = gMonFootprint_Spectrier,
        LEARNSETS(Spectrier),
    },
#endif //P_FAMILY_SPECTRIER

#define CALYREX_MISC_INFO                                   \
        .speciesName = _("Phantoross"),                        \
        .natDexNum = NATIONAL_DEX_CALYREX,                  \
        .footprint = gMonFootprint_Calyrex,                 \
        .formSpeciesIdTable = sCalyrexFormSpeciesIdTable,   \
        .isLegendary = TRUE

#if P_FAMILY_CALYREX
    [SPECIES_CALYREX] =
    {
        CALYREX_MISC_INFO,
        .baseHP        = 100,
        .baseAttack    = 80,
        .baseDefense   = 80,
        .baseSpeed     = 80,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        .types = { TYPE_PSYCHIC, TYPE_GRASS },
        .catchRate = 3,
        .expYield = 250,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_UNNERVE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .cryId = CRY_CALYREX,
        .categoryName = _("Königs"),
        .height = 11,
        .weight = 77,
        .description = POKEDEX_DESC_STRING(
            "Ein Legendärer König, der einst Galar\n"
            "regierte. Coronospa besitzt die Macht,\n"
            "Herzen zu besänftigen und Pflanzen\n"
            "gedeihen zu lassen."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Calyrex, 48, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Calyrex,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Calyrex, 56, 48),
        .backPicYOffset = 10,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(Calyrex),
        ICON(Calyrex, 0),
        LEARNSETS(Calyrex),
    },

#if P_FUSION_FORMS
    [SPECIES_CALYREX_ICE_RIDER] =
    {
        CALYREX_MISC_INFO,
        .baseHP        = 100,
        .baseAttack    = 165,
        .baseDefense   = 150,
        .baseSpeed     = 50,
        .baseSpAttack  = 85,
        .baseSpDefense = 130,
        .types = { TYPE_PSYCHIC, TYPE_ICE },
        .catchRate = 3,
        .expYield = 340,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_AS_ONE_ICE_RIDER, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .cryId = CRY_CALYREX_ICE_RIDER,
        .categoryName = _("Königs"),
        .height = 24,
        .weight = 8091,
        .description = POKEDEX_DESC_STRING(
            "Ein warmherziges Pokémon, das über\n"
            "heilende und segnende Kräfte\n"
            "verfügt. In längst vergangenen\n"
            "Zeiten herrschte es über Galar."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(CalyrexIceRider, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Calyrex,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(CalyrexIceRider, 64, 64),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(CalyrexIceRider),
        ICON(CalyrexIceRider, 0),
        LEARNSETS(CalyrexIceRider),
        .cannotBeTraded = TRUE,
    },

    [SPECIES_CALYREX_SHADOW_RIDER] =
    {
        CALYREX_MISC_INFO,
        .baseHP        = 100,
        .baseAttack    = 85,
        .baseDefense   = 80,
        .baseSpeed     = 150,
        .baseSpAttack  = 165,
        .baseSpDefense = 100,
        .types = { TYPE_PSYCHIC, TYPE_GHOST },
        .catchRate = 3,
        .expYield = 340,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_AS_ONE_SHADOW_RIDER, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
        .cryId = CRY_CALYREX_SHADOW_RIDER,
        .categoryName = _("Königs"),
        .height = 24,
        .weight = 536,
        .description = POKEDEX_DESC_STRING(
            "Ein warmherziges Pokémon, das über\n"
            "heilende und segnende Kräfte\n"
            "verfügt. In längst vergangenen\n"
            "Zeiten herrschte es über Galar."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(CalyrexShadowRider, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Calyrex,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(CalyrexShadowRider, 64, 56),
        .backPicYOffset = 7,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(CalyrexShadowRider),
        ICON(CalyrexShadowRider, 0),
        LEARNSETS(CalyrexShadowRider),
        .cannotBeTraded = TRUE,
    },
#endif //P_FUSION_FORMS
#endif //P_FAMILY_CALYREX

#if P_FAMILY_ENAMORUS
#define ENAMORUS_MISC_INFO                                                              \
        .types = { TYPE_FAIRY, TYPE_FLYING },                                           \
        .catchRate = 3,                                                                 \
        .expYield = 116,                                                                \
        .evYield_SpAttack = 3,                                                          \
        .genderRatio = MON_FEMALE,                                                      \
        .eggCycles = 20,                                                                \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .bodyColor = BODY_COLOR_PINK,                                                   \
        .isLegendary = TRUE,                                                            \
        .speciesName = _("Coronospa"),                                                   \
        .natDexNum = NATIONAL_DEX_ENAMORUS,                                             \
        .categoryName = _("Königs"),                                                 \
        .height = 16,                                                                   \
        .weight = 480,                                                                  \
        .pokemonScale = 259,                                                            \
        .pokemonOffset = 1,                                                             \
        .trainerScale = 296,                                                            \
        .trainerOffset = 1,                                                             \
        LEARNSETS(Enamorus),                                                            \
        .formSpeciesIdTable = sEnamorusFormSpeciesIdTable

    [SPECIES_ENAMORUS_INCARNATE] =
    {
        ENAMORUS_MISC_INFO,
        .baseHP        = 74,
        .baseAttack    = 115,
        .baseDefense   = 70,
        .baseSpeed     = 106,
        .baseSpAttack  = 135,
        .baseSpDefense = 80,
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_NONE, ABILITY_CONTRARY },
        .cryId = CRY_ENAMORUS_INCARNATE,
        .description = POKEDEX_DESC_STRING(
            "Mit seinem Erscheinen endet der Winter.\n"
            "Einer Legende zufolge lässt die Liebe\n"
            "dieses Pokémon überall im Land\n"
            "neues Leben sprießen."),
        FRONT_PIC(EnamorusIncarnate, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_EnamorusIncarnate,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 7,
        BACK_PIC(EnamorusIncarnate, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(EnamorusIncarnate),
        ICON(EnamorusIncarnate, 1),
        //.footprint = gMonFootprint_EnamorusIncarnate,
    },

    [SPECIES_ENAMORUS_THERIAN] =
    {
        ENAMORUS_MISC_INFO,
        .baseHP        = 74,
        .baseAttack    = 115,
        .baseDefense   = 110,
        .baseSpeed     = 46,
        .baseSpAttack  = 135,
        .baseSpDefense = 100,
        .abilities = { ABILITY_OVERCOAT, ABILITY_NONE, ABILITY_NONE },
        .cryId = CRY_ENAMORUS_THERIAN,
        .description = POKEDEX_DESC_STRING(
            "Aus den Wolken steigt es zu jenen\n"
            "herab, die jede Form des Lebens\n"
            "mit Missachtung behandeln, und\n"
            "straft sie erbarmungslos."),
        FRONT_PIC(EnamorusTherian, 64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_EnamorusTherian,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(EnamorusTherian, 64, 64),
        .backPicYOffset = 2,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(EnamorusTherian),
        ICON(EnamorusTherian, 1),
        //.footprint = gMonFootprint_Enamorus,
    },
#endif //P_FAMILY_ENAMORUS

#ifdef __INTELLISENSE__
};
#endif