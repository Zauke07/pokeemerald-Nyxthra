#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoGen4[] =
{
#endif

#if P_FAMILY_TURTWIG
    [SPECIES_TURTWIG] =
    {
        .baseHP        = 55,
        .baseAttack    = 68,
        .baseDefense   = 64,
        .baseSpeed     = 31,
        .baseSpAttack  = 45,
        .baseSpDefense = 55,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 64,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_GRASS },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_SHELL_ARMOR },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Chelast"),
        .cryId = CRY_TURTWIG,
        .natDexNum = NATIONAL_DEX_TURTWIG,
        .categoryName = _("Winziglaub"),
        .height = 4,
        .weight = 102,
        .description = POKEDEX_DESC_STRING(
            "Sein Körper lebt von der Photosynthese,\n"
            "die Sauerstoff freisetzt. Ist es durstig,\n"
            "welkt sein Blatt."),
        .pokemonScale = 491,
        .pokemonOffset = 20,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Turtwig, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Turtwig,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Turtwig, 48, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Turtwig),
        ICON(Turtwig, 1),
        .footprint = gMonFootprint_Turtwig,
        LEARNSETS(Turtwig),
        .evolutions = EVOLUTION({EVO_LEVEL, 18, SPECIES_GROTLE}),
    },

    [SPECIES_GROTLE] =
    {
        .baseHP        = 75,
        .baseAttack    = 89,
        .baseDefense   = 85,
        .baseSpeed     = 36,
        .baseSpAttack  = 55,
        .baseSpDefense = 65,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 45,
        .expYield = 142,
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_GRASS },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_SHELL_ARMOR },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Chelcarain"),
        .cryId = CRY_GROTLE,
        .natDexNum = NATIONAL_DEX_GROTLE,
        .categoryName = _("Hain"),
        .height = 11,
        .weight = 970,
        .description = POKEDEX_DESC_STRING(
            "Es weiß, wo es reinstes Quellwasser finden\n"
            "kann. trägt andere Pokémon auf seinem\n"
            "Rücken dorthin."),
        .pokemonScale = 320,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Grotle, 56, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Grotle,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Grotle, 64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Grotle),
        ICON(Grotle, 1),
        .footprint = gMonFootprint_Grotle,
        LEARNSETS(Grotle),
        .evolutions = EVOLUTION({EVO_LEVEL, 32, SPECIES_TORTERRA}),
    },

    [SPECIES_TORTERRA] =
    {
        .baseHP        = 95,
        .baseAttack    = 109,
        .baseDefense   = 105,
        .baseSpeed     = 56,
        .baseSpAttack  = 75,
        .baseSpDefense = 85,
        .types = { TYPE_GRASS, TYPE_GROUND },
        .catchRate = 45,
        .expYield = 236,
        .evYield_Attack = 2,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_GRASS },
        .abilities = { ABILITY_OVERGROW, ABILITY_NONE, ABILITY_SHELL_ARMOR },
        .bodyColor = BODY_COLOR_GREEN,
        .noFlip = TRUE,
        .speciesName = _("Chelterrar"),
        .cryId = CRY_TORTERRA,
        .natDexNum = NATIONAL_DEX_TORTERRA,
        .categoryName = _("Kontinent"),
        .height = 22,
        .weight = 3100,
        .description = POKEDEX_DESC_STRING(
            "Kleine Pokémon fangen manchmal an, auf dem\n"
            "bewegungslosen Rücken Nester zu bauen."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 348,
        .trainerOffset = 6,
        FRONT_PIC(Torterra, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Torterra,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Torterra, 64, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_GREEN,
        PALETTES(Torterra),
        ICON(Torterra, 1),
        .footprint = gMonFootprint_Torterra,
        LEARNSETS(Torterra),
    },
#endif //P_FAMILY_TURTWIG

#if P_FAMILY_CHIMCHAR
    [SPECIES_CHIMCHAR] =
    {
        .baseHP        = 44,
        .baseAttack    = 58,
        .baseDefense   = 44,
        .baseSpeed     = 61,
        .baseSpAttack  = 58,
        .baseSpDefense = 44,
        .types = { TYPE_FIRE, TYPE_FIRE },
        .catchRate = 45,
        .expYield = 62,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_IRON_FIST },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Panflam"),
        .cryId = CRY_CHIMCHAR,
        .natDexNum = NATIONAL_DEX_CHIMCHAR,
        .categoryName = _("Schimpanse"),
        .height = 5,
        .weight = 62,
        .description = POKEDEX_DESC_STRING(
            "Das Feuer an seinem Hinterteil wird\n"
            "durch Gase im Bauch genährt. Selbst\n"
            "Regen löscht es nicht."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Chimchar, 32, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Chimchar,
        .frontAnimId = ANIM_V_JUMPS_BIG,
        BACK_PIC(Chimchar, 56, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Chimchar),
        ICON(Chimchar, 1),
        .footprint = gMonFootprint_Chimchar,
        LEARNSETS(Chimchar),
        .evolutions = EVOLUTION({EVO_LEVEL, 14, SPECIES_MONFERNO}),
    },

    [SPECIES_MONFERNO] =
    {
        .baseHP        = 64,
        .baseAttack    = 78,
        .baseDefense   = 52,
        .baseSpeed     = 81,
        .baseSpAttack  = 78,
        .baseSpDefense = 52,
        .types = { TYPE_FIRE, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 142,
        .evYield_Speed = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_IRON_FIST },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Panpyro"),
        .cryId = CRY_MONFERNO,
        .natDexNum = NATIONAL_DEX_MONFERNO,
        .categoryName = _("Verspielt"),
        .height = 9,
        .weight = 220,
        .description = POKEDEX_DESC_STRING(
            "Es stürzt sich von Decken und Wänden auf\n"
            "Beute. Sein feuriger Schweif ist nur eine\n"
            "seiner Waffen."),
        .pokemonScale = 338,
        .pokemonOffset = 9,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Monferno, 56, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Monferno,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(Monferno, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Monferno),
        ICON(Monferno, 0),
        .footprint = gMonFootprint_Monferno,
        LEARNSETS(Monferno),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_INFERNAPE}),
    },

    [SPECIES_INFERNAPE] =
    {
        .baseHP        = 76,
        .baseAttack    = 104,
        .baseDefense   = 71,
        .baseSpeed     = 108,
        .baseSpAttack  = 104,
        .baseSpDefense = 71,
        .types = { TYPE_FIRE, TYPE_FIGHTING },
        .catchRate = 45,
        .expYield = 240,
        .evYield_Attack = 1,
        .evYield_Speed = 1,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_BLAZE, ABILITY_NONE, ABILITY_IRON_FIST },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Panferno"),
        .cryId = CRY_INFERNAPE,
        .natDexNum = NATIONAL_DEX_INFERNAPE,
        .categoryName = _("Flamme"),
        .height = 12,
        .weight = 550,
        .description = POKEDEX_DESC_STRING(
            "Es hält den Gegner mit flinken Bewegungen\n"
            "zum Narren. Im Kampf setzt es alle\n"
            "Gliedmaßen ein."),
        .pokemonScale = 282,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Infernape, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_Infernape,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Infernape, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(Infernape),
        ICON(Infernape, 0),
        .footprint = gMonFootprint_Infernape,
        LEARNSETS(Infernape),
    },
#endif //P_FAMILY_CHIMCHAR

#if P_FAMILY_PIPLUP
    [SPECIES_PIPLUP] =
    {
        .baseHP        = 53,
        .baseAttack    = 51,
        .baseDefense   = 53,
        .baseSpeed     = 40,
        .baseSpAttack  = 61,
        .baseSpDefense = 56,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 63,
        .evYield_SpAttack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        #if P_UPDATED_ABILITIES >= GEN_9
            .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_COMPETITIVE },
        #else
            .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_DEFIANT },
        #endif
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Plinfa"),
        .cryId = CRY_PIPLUP,
        .natDexNum = NATIONAL_DEX_PIPLUP,
        .categoryName = _("Pinguin"),
        .height = 4,
        .weight = 52,
        .description = POKEDEX_DESC_STRING(
            "Einmischung kann es gar nicht\n"
            "leiden. Es ist bockig und fasst nur\n"
            "schwer Zutrauen zu seinem Trainer."),
        .pokemonScale = 491,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Piplup, 24, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Piplup,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Piplup, 40, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Piplup),
        ICON(Piplup, 0),
        .footprint = gMonFootprint_Piplup,
        LEARNSETS(Piplup),
        .evolutions = EVOLUTION({EVO_LEVEL, 16, SPECIES_PRINPLUP}),
    },

    [SPECIES_PRINPLUP] =
    {
        .baseHP        = 64,
        .baseAttack    = 66,
        .baseDefense   = 68,
        .baseSpeed     = 50,
        .baseSpAttack  = 81,
        .baseSpDefense = 76,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 45,
        .expYield = 142,
        .evYield_SpAttack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        #if P_UPDATED_ABILITIES >= GEN_9
            .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_COMPETITIVE },
        #else
            .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_DEFIANT },
        #endif
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Pliprin"),
        .cryId = CRY_PRINPLUP,
        .natDexNum = NATIONAL_DEX_PRINPLUP,
        .categoryName = _("Pinguin"),
        .height = 8,
        .weight = 230,
        .description = POKEDEX_DESC_STRING(
            "Es lebt allein, entfernt von\n"
            "anderen. Jedes von ihnen denkt, es\n"
            "sei das Bedeutendste unter ihnen."),
        .pokemonScale = 366,
        .pokemonOffset = 10,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Prinplup, 48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Prinplup,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Prinplup, 48, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Prinplup),
        ICON(Prinplup, 0),
        .footprint = gMonFootprint_Prinplup,
        LEARNSETS(Prinplup),
        .evolutions = EVOLUTION({EVO_LEVEL, 36, SPECIES_EMPOLEON}),
    },

    [SPECIES_EMPOLEON] =
    {
        .baseHP        = 84,
        .baseAttack    = 86,
        .baseDefense   = 88,
        .baseSpeed     = 60,
        .baseSpAttack  = 111,
        .baseSpDefense = 101,
        .types = { TYPE_WATER, TYPE_STEEL },
        .catchRate = 45,
        .expYield = 239,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        #if P_UPDATED_ABILITIES >= GEN_9
            .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_COMPETITIVE },
        #else
            .abilities = { ABILITY_TORRENT, ABILITY_NONE, ABILITY_DEFIANT },
        #endif
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Impoleon"),
        .cryId = CRY_EMPOLEON,
        .natDexNum = NATIONAL_DEX_EMPOLEON,
        .categoryName = _("Kaiser"),
        .height = 17,
        .weight = 845,
        .description = POKEDEX_DESC_STRING(
            "Die drei Hörner, die aus dem Schnabel\n"
            "wachsen, stehen für Kraft. Ein Anführer\n"
            "hat die größten Hörner."),
        .pokemonScale = 259,
        .pokemonOffset = 0,
        .trainerScale = 290,
        .trainerOffset = 1,
        FRONT_PIC(Empoleon, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Empoleon,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Empoleon, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        PALETTES(Empoleon),
        ICON(Empoleon, 0),
        .footprint = gMonFootprint_Empoleon,
        LEARNSETS(Empoleon),
    },
#endif //P_FAMILY_PIPLUP

#if P_FAMILY_STARLY
    [SPECIES_STARLY] =
    {
        .baseHP        = 40,
        .baseAttack    = 55,
        .baseDefense   = 30,
        .baseSpeed     = 60,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 255,
        .expYield = 49,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_NONE, ABILITY_RECKLESS },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Staralili"),
        .cryId = CRY_STARLY,
        .natDexNum = NATIONAL_DEX_STARLY,
        .categoryName = _("Star"),
        .height = 3,
        .weight = 20,
        .description = POKEDEX_DESC_STRING(
            "Ihr Schwarm ist stets groß. Obwohl\n"
            "es kleine Pokémon sind, schwingen\n"
            "sie ihre Flügel mit enormer Kraft."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Starly, 40, 40),
        FRONT_PIC_FEMALE(Starly, 40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Starly,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Starly, 56, 48),
        BACK_PIC_FEMALE(Starly, 56, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Starly),
        ICON(Starly, 0),
        .footprint = gMonFootprint_Starly,
        LEARNSETS(Starly),
        .evolutions = EVOLUTION({EVO_LEVEL, 14, SPECIES_STARAVIA}),
    },

    [SPECIES_STARAVIA] =
    {
        .baseHP        = 55,
        .baseAttack    = 75,
        .baseDefense   = 50,
        .baseSpeed     = 80,
        .baseSpAttack  = 40,
        .baseSpDefense = 40,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 120,
        .expYield = 119,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_INTIMIDATE, ABILITY_NONE, ABILITY_RECKLESS },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Staravia"),
        .cryId = CRY_STARAVIA,
        .natDexNum = NATIONAL_DEX_STARAVIA,
        .categoryName = _("Star"),
        .height = 6,
        .weight = 155,
        .description = POKEDEX_DESC_STRING(
            "Es neigt dazu, sich in großen\n"
            "Gruppen zu bewegen. Zwischen ihnen\n"
            "kommt es zu heftigen Kämpfen."),
        .pokemonScale = 422,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Staravia, 40, 48),
        FRONT_PIC_FEMALE(Staravia, 40, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Staravia,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Staravia, 64, 64),
        BACK_PIC_FEMALE(Staravia, 64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Staravia),
        ICON(Staravia, 0),
        .footprint = gMonFootprint_Staravia,
        LEARNSETS(Staravia),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_STARAPTOR}),
    },

    [SPECIES_STARAPTOR] =
    {
        .baseHP        = 85,
        .baseAttack    = 120,
        .baseDefense   = 70,
        .baseSpeed     = 100,
        .baseSpAttack  = 50,
        .baseSpDefense = P_UPDATED_STATS >= GEN_6 ? 60 : 50,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 218,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_INTIMIDATE, ABILITY_NONE, ABILITY_RECKLESS },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Staraptor"),
        .cryId = CRY_STARAPTOR,
        .natDexNum = NATIONAL_DEX_STARAPTOR,
        .categoryName = _("Raubtier"),
        .height = 12,
        .weight = 249,
        .description = POKEDEX_DESC_STRING(
            "Wird Staravia zu Staraptor, verlässt es\n"
            "die Gruppe und lebt allein. Seine\n"
            "Spannweite ist gigantisch."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Staraptor, 56, 64),
        FRONT_PIC_FEMALE(Staraptor, 56, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Staraptor,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Staraptor, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Staraptor),
        ICON(Staraptor, 0),
        .footprint = gMonFootprint_Staraptor,
        LEARNSETS(Staraptor),
    },
#endif //P_FAMILY_STARLY

#if P_FAMILY_BIDOOF
    [SPECIES_BIDOOF] =
    {
        .baseHP        = 59,
        .baseAttack    = 45,
        .baseDefense   = 40,
        .baseSpeed     = 31,
        .baseSpAttack  = 35,
        .baseSpDefense = 40,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 255,
        .expYield = 50,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SIMPLE, ABILITY_UNAWARE, ABILITY_MOODY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Bidiza"),
        .cryId = CRY_BIDOOF,
        .natDexNum = NATIONAL_DEX_BIDOOF,
        .categoryName = _("Dickmaus"),
        .height = 5,
        .weight = 200,
        .description = POKEDEX_DESC_STRING(
            "Es knabbert ständig an Holz und Steinen,\n"
            "um seine Vorderzähne zu kürzen. Es nistet\n"
            "am Wasser."),
        .pokemonScale = 432,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Bidoof, 40, 40),
        FRONT_PIC_FEMALE(Bidoof, 40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Bidoof,
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        BACK_PIC(Bidoof, 64, 40),
        BACK_PIC_FEMALE(Bidoof, 64, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Bidoof),
        ICON(Bidoof, 2),
        .footprint = gMonFootprint_Bidoof,
        LEARNSETS(Bidoof),
        .evolutions = EVOLUTION({EVO_LEVEL, 15, SPECIES_BIBAREL}),
    },

    [SPECIES_BIBAREL] =
    {
        .baseHP        = 79,
        .baseAttack    = 85,
        .baseDefense   = 60,
        .baseSpeed     = 71,
        .baseSpAttack  = 55,
        .baseSpDefense = 60,
        .types = { TYPE_NORMAL, TYPE_WATER },
        .catchRate = 127,
        .expYield = 144,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SIMPLE, ABILITY_UNAWARE, ABILITY_MOODY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Bidifas"),
        .cryId = CRY_BIBAREL,
        .natDexNum = NATIONAL_DEX_BIBAREL,
        .categoryName = _("Biber"),
        .height = 10,
        .weight = 315,
        .description = POKEDEX_DESC_STRING(
            "Es baut sein Nest, indem es in Flüssen\n"
            "Dämme aus Schlamm und Ästen baut. Ein\n"
            "fleißiger Arbeiter."),
        .pokemonScale = 305,
        .pokemonOffset = 8,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Bibarel, 56, 48),
        FRONT_PIC_FEMALE(Bibarel, 56, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Bibarel,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Bibarel, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_DIP_RIGHT_SIDE,
        PALETTES(Bibarel),
        ICON(Bibarel, 2),
        .footprint = gMonFootprint_Bibarel,
        LEARNSETS(Bibarel),
    },
#endif //P_FAMILY_BIDOOF

#if P_FAMILY_KRICKETOT
    [SPECIES_KRICKETOT] =
    {
        .baseHP        = 37,
        .baseAttack    = 25,
        .baseDefense   = 41,
        .baseSpeed     = 25,
        .baseSpAttack  = 25,
        .baseSpDefense = 41,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 255,
        .expYield = 39,
        .evYield_Defense = 1,
        .itemRare = ITEM_METRONOME,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SHED_SKIN, ABILITY_NONE, ABILITY_RUN_AWAY },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Zirpurze"),
        .cryId = CRY_KRICKETOT,
        .natDexNum = NATIONAL_DEX_KRICKETOT,
        .categoryName = _("Zirper"),
        .height = 3,
        .weight = 22,
        .description = POKEDEX_DESC_STRING(
            "Wenn seine zwei Antennen sich berühren,\n"
            "erklingt ein Ruf wie das Spiel eines\n"
            "Xylophons."),
        .pokemonScale = 530,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Kricketot, 48, 48),
        FRONT_PIC_FEMALE(Kricketot, 48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Kricketot,
        .frontAnimId = ANIM_H_JUMPS,
        BACK_PIC(Kricketot, 48, 56),
        BACK_PIC_FEMALE(Kricketot, 48, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Kricketot),
        ICON(Kricketot, 2),
        .footprint = gMonFootprint_Kricketot,
        LEARNSETS(Kricketot),
        .evolutions = EVOLUTION({EVO_LEVEL, 10, SPECIES_KRICKETUNE}),
    },

    [SPECIES_KRICKETUNE] =
    {
        .baseHP        = 77,
        .baseAttack    = 85,
        .baseDefense   = 51,
        .baseSpeed     = 65,
        .baseSpAttack  = 55,
        .baseSpDefense = 51,
        .types = { TYPE_BUG, TYPE_BUG },
        .catchRate = 45,
        .expYield = 134,
        .evYield_Attack = 2,
        .itemRare = ITEM_METRONOME,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_NONE, ABILITY_TECHNICIAN },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Zirpeise"),
        .cryId = CRY_KRICKETUNE,
        .natDexNum = NATIONAL_DEX_KRICKETUNE,
        .categoryName = _("Zirper"),
        .height = 10,
        .weight = 255,
        .description = POKEDEX_DESC_STRING(
            "Wenn es ruft, verschränkt es seine\n"
            "messerartigen Arme vor der Brust.\n"
            "Es komponiert aus dem Stegreif."),
        .pokemonScale = 305,
        .pokemonOffset = 8,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Kricketune, 56, 56),
        FRONT_PIC_FEMALE(Kricketune, 56, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Kricketune,
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        BACK_PIC(Kricketune, 56, 64),
        BACK_PIC_FEMALE(Kricketune, 56, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        PALETTES(Kricketune),
        ICON(Kricketune, 2),
        .footprint = gMonFootprint_Kricketune,
        LEARNSETS(Kricketune),
    },
#endif //P_FAMILY_KRICKETOT

#if P_FAMILY_SHINX
    [SPECIES_SHINX] =
    {
        .baseHP        = 45,
        .baseAttack    = 65,
        .baseDefense   = 34,
        .baseSpeed     = 45,
        .baseSpAttack  = 40,
        .baseSpDefense = 34,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 235,
        .expYield = 53,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RIVALRY, ABILITY_INTIMIDATE, ABILITY_GUTS },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Sheinux"),
        .cryId = CRY_SHINX,
        .natDexNum = NATIONAL_DEX_SHINX,
        .categoryName = _("Flacker"),
        .height = 5,
        .weight = 95,
        .description = POKEDEX_DESC_STRING(
            "Es erzeugt Elektrizität durch das\n"
            "Strecken und Zusammenziehen seiner\n"
            "Muskeln. Bei Bedrohung glüht es."),
        .pokemonScale = 432,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Shinx, 48, 40),
        FRONT_PIC_FEMALE(Shinx, 48, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Shinx,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Shinx, 64, 48),
        BACK_PIC_FEMALE(Shinx, 64, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Shinx),
        ICON(Shinx, 0),
        .footprint = gMonFootprint_Shinx,
        LEARNSETS(Shinx),
        .evolutions = EVOLUTION({EVO_LEVEL, 15, SPECIES_LUXIO}),
    },

    [SPECIES_LUXIO] =
    {
        .baseHP        = 60,
        .baseAttack    = 85,
        .baseDefense   = 49,
        .baseSpeed     = 60,
        .baseSpAttack  = 60,
        .baseSpDefense = 49,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 120,
        .expYield = 127,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 100,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RIVALRY, ABILITY_INTIMIDATE, ABILITY_GUTS },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Luxio"),
        .cryId = CRY_LUXIO,
        .natDexNum = NATIONAL_DEX_LUXIO,
        .categoryName = _("Funken"),
        .height = 9,
        .weight = 305,
        .description = POKEDEX_DESC_STRING(
            "Seine Krallen geben Elektrizität\n"
            "ab, die stark genug ist, jemanden\n"
            "bewusstlos zu machen."),
        .pokemonScale = 338,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Luxio, 48, 48),
        FRONT_PIC_FEMALE(Luxio, 48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Luxio,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Luxio, 64, 64),
        BACK_PIC_FEMALE(Luxio, 64, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Luxio),
        ICON(Luxio, 0),
        .footprint = gMonFootprint_Luxio,
        LEARNSETS(Luxio),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_LUXRAY}),
    },

    [SPECIES_LUXRAY] =
    {
        .baseHP        = 80,
        .baseAttack    = 120,
        .baseDefense   = 79,
        .baseSpeed     = 70,
        .baseSpAttack  = 95,
        .baseSpDefense = 79,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 45,
        .expYield = 235,
        .evYield_Attack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_RIVALRY, ABILITY_INTIMIDATE, ABILITY_GUTS },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Luxtra"),
        .cryId = CRY_LUXRAY,
        .natDexNum = NATIONAL_DEX_LUXRAY,
        .categoryName = _("Glühaugen"),
        .height = 14,
        .weight = 420,
        .description = POKEDEX_DESC_STRING(
            "Beim Aufspüren von Gefahren sind Luxtras\n"
            "hellseherische Fähigkeiten äußerst\n"
            "hilfreich."),
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Luxray, 64, 64),
        FRONT_PIC_FEMALE(Luxray, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Luxray,
        .frontAnimId = ANIM_GLOW_YELLOW,
        BACK_PIC(Luxray, 64, 64),
        BACK_PIC_FEMALE(Luxray, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(Luxray),
        ICON(Luxray, 0),
        .footprint = gMonFootprint_Luxray,
        LEARNSETS(Luxray),
    },
#endif //P_FAMILY_SHINX

#if P_FAMILY_CRANIDOS
    [SPECIES_CRANIDOS] =
    {
        .baseHP        = 67,
        .baseAttack    = 125,
        .baseDefense   = 40,
        .baseSpeed     = 58,
        .baseSpAttack  = 30,
        .baseSpDefense = 30,
        .types = { TYPE_ROCK, TYPE_ROCK },
        .catchRate = 45,
        .expYield = 70,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MONSTER },
        .abilities = { ABILITY_MOLD_BREAKER, ABILITY_NONE, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Koknodon"),
        .cryId = CRY_CRANIDOS,
        .natDexNum = NATIONAL_DEX_CRANIDOS,
        .categoryName = _("Kopfstoß"),
        .height = 9,
        .weight = 315,
        .description = POKEDEX_DESC_STRING(
            "Dieses urzeitliche Pokémon war trotz\n"
            "seines harten, robusten Schädels nicht\n"
            "sehr schlau."),
        .pokemonScale = 338,
        .pokemonOffset = 10,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cranidos, 48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Cranidos,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Cranidos, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(Cranidos),
        ICON(Cranidos, 0),
        .footprint = gMonFootprint_Cranidos,
        LEARNSETS(Cranidos),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_RAMPARDOS}),
    },

    [SPECIES_RAMPARDOS] =
    {
        .baseHP        = 97,
        .baseAttack    = 165,
        .baseDefense   = 60,
        .baseSpeed     = 58,
        .baseSpAttack  = 65,
        .baseSpDefense = 50,
        .types = { TYPE_ROCK, TYPE_ROCK },
        .catchRate = 45,
        .expYield = 173,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MONSTER },
        .abilities = { ABILITY_MOLD_BREAKER, ABILITY_NONE, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Rameidon"),
        .cryId = CRY_RAMPARDOS,
        .natDexNum = NATIONAL_DEX_RAMPARDOS,
        .categoryName = _("Kopfstoß"),
        .height = 16,
        .weight = 1025,
        .description = POKEDEX_DESC_STRING(
            "Sein dicker Schädelknochen trotzt\n"
            "jedem Angriff. Gleichzeitig stoppt\n"
            "er jedoch sein Hirnwachstum."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 296,
        .trainerOffset = 1,
        FRONT_PIC(Rampardos, 64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Rampardos,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        BACK_PIC(Rampardos, 64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Rampardos),
        ICON(Rampardos, 0),
        .footprint = gMonFootprint_Rampardos,
        LEARNSETS(Rampardos),
    },
#endif //P_FAMILY_CRANIDOS

#if P_FAMILY_SHIELDON
    [SPECIES_SHIELDON] =
    {
        .baseHP        = 30,
        .baseAttack    = 42,
        .baseDefense   = 118,
        .baseSpeed     = 30,
        .baseSpAttack  = 42,
        .baseSpDefense = 88,
        .types = { TYPE_ROCK, TYPE_STEEL },
        .catchRate = 45,
        .expYield = 70,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MONSTER },
        .abilities = { ABILITY_STURDY, ABILITY_NONE, ABILITY_SOUNDPROOF },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Schilterus"),
        .cryId = CRY_SHIELDON,
        .natDexNum = NATIONAL_DEX_SHIELDON,
        .categoryName = _("Schutzschild"),
        .height = 5,
        .weight = 570,
        .description = POKEDEX_DESC_STRING(
            "Es reibt sein Gesicht an\n"
            "Baumstämmen, um es zu polieren. Es\n"
            "ist leicht, es von hinten\n"
            "anzugreifen."),
        .pokemonScale = 432,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Shieldon, 40, 40),
        .frontPicYOffset = 15,
        .frontAnimFrames = sAnims_Shieldon,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Shieldon, 56, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Shieldon),
        ICON(Shieldon, 1),
        .footprint = gMonFootprint_Shieldon,
        LEARNSETS(Shieldon),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_BASTIODON}),
    },

    [SPECIES_BASTIODON] =
    {
        .baseHP        = 60,
        .baseAttack    = 52,
        .baseDefense   = 168,
        .baseSpeed     = 30,
        .baseSpAttack  = 47,
        .baseSpDefense = 138,
        .types = { TYPE_ROCK, TYPE_STEEL },
        .catchRate = 45,
        .expYield = 173,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_MONSTER },
        .abilities = { ABILITY_STURDY, ABILITY_NONE, ABILITY_SOUNDPROOF },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Bollterus"),
        .cryId = CRY_BASTIODON,
        .natDexNum = NATIONAL_DEX_BASTIODON,
        .categoryName = _("Schutzschild"),
        .height = 13,
        .weight = 1495,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon lebte vor etwa 100\n"
            "Millionen Jahren. Sein unglaublich\n"
            "robustes Gesicht ist härter als Stahl."),
        .pokemonScale = 272,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Bastiodon, 64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Bastiodon,
        .frontAnimId = ANIM_BACK_AND_LUNGE,
        BACK_PIC(Bastiodon, 64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Bastiodon),
        ICON(Bastiodon, 1),
        .footprint = gMonFootprint_Bastiodon,
        LEARNSETS(Bastiodon),
    },
#endif //P_FAMILY_SHIELDON

#if P_FAMILY_BURMY
#define BURMY_MISC_INFO                                                     \
        .baseHP        = 40,                                                \
        .baseAttack    = 29,                                                \
        .baseDefense   = 45,                                                \
        .baseSpeed     = 36,                                                \
        .baseSpAttack  = 29,                                                \
        .baseSpDefense = 45,                                                \
        .types = { TYPE_BUG, TYPE_BUG },                                    \
        .catchRate = 120,                                                   \
        .expYield = 45,                                                     \
        .evYield_SpDefense = 1,                                             \
        .genderRatio = PERCENT_FEMALE(50),                                  \
        .eggCycles = 15,                                                    \
        .friendship = STANDARD_FRIENDSHIP,                                  \
        .growthRate = GROWTH_MEDIUM_FAST,                                   \
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },                      \
        .abilities = { ABILITY_SHED_SKIN, ABILITY_NONE, ABILITY_OVERCOAT }, \
        .speciesName = _("Bollterus"),                                          \
        .cryId = CRY_BURMY,                                                 \
        .natDexNum = NATIONAL_DEX_BURMY,                                    \
        .categoryName = _("Schutzschild"),                                       \
        .height = 2,                                                        \
        .weight = 34,                                                       \
        .pokemonScale = 682,                                                \
        .pokemonOffset = 24,                                                \
        .trainerScale = 256,                                                \
        .trainerOffset = 0,                                                 \
        .frontAnimFrames = sAnims_Burmy,                                    \
        .frontAnimId = ANIM_V_STRETCH,                                      \
        .enemyMonElevation = 10,                                            \
        .backAnimId = BACK_ANIM_H_SHAKE,                                    \
        .footprint = gMonFootprint_Burmy,                                   \
        LEARNSETS(Burmy),                                                   \
        .formSpeciesIdTable = sBurmyFormSpeciesIdTable,                     \
        .formChangeTable = sBurmyFormChangeTable

    [SPECIES_BURMY_PLANT_CLOAK] =
    {
        BURMY_MISC_INFO,
        .bodyColor = BODY_COLOR_GREEN,
        .description = POKEDEX_DESC_STRING(
            "Um sich vor dem eisigen Winterwind\n"
            "zu schützen, legt es sich unter\n"
            "einen Umhang aus Ästen und Laub."),
        FRONT_PIC(BurmyPlantCloak, 32, 56),
        .frontPicYOffset = 13,
        BACK_PIC(BurmyPlantCloak, 40, 56),
        .backPicYOffset = 6,
        PALETTES(BurmyPlantCloak),
        ICON(BurmyPlantCloak, 1),
        .evolutions = EVOLUTION({EVO_LEVEL_FEMALE, 20, SPECIES_WORMADAM_PLANT_CLOAK},
                                {EVO_LEVEL_MALE, 20, SPECIES_MOTHIM}),
    },

    [SPECIES_BURMY_SANDY_CLOAK] =
    {
        BURMY_MISC_INFO,
        .bodyColor = BODY_COLOR_BROWN,
        .description = POKEDEX_DESC_STRING(
            "Um sich vor dem eisigen Winterwind\n"
            "zu schützen, legt es sich unter\n"
            "einen Umhang aus Ästen und Laub."),
        FRONT_PIC(BurmySandyCloak, 32, 56),
        .frontPicYOffset = 12,
        BACK_PIC(BurmySandyCloak, 32, 56),
        .backPicYOffset = 7,
        PALETTES(BurmySandyCloak),
        ICON(BurmySandyCloak, 1),
        .evolutions = EVOLUTION({EVO_LEVEL_FEMALE, 20, SPECIES_WORMADAM_SANDY_CLOAK},
                                {EVO_LEVEL_MALE, 20, SPECIES_MOTHIM}),
    },

    [SPECIES_BURMY_TRASH_CLOAK] =
    {
        BURMY_MISC_INFO,
        .bodyColor = BODY_COLOR_RED,
        .description = POKEDEX_DESC_STRING(
            "Um sich vor dem eisigen Winterwind\n"
            "zu schützen, legt es sich unter\n"
            "einen Umhang aus Ästen und Laub."),
        FRONT_PIC(BurmyTrashCloak, 32, 56),
        .frontPicYOffset = 8,
        BACK_PIC(BurmyTrashCloak, 40, 64),
        .backPicYOffset = 0,
        PALETTES(BurmyTrashCloak),
        ICON(BurmyTrashCloak, 0),
        .evolutions = EVOLUTION({EVO_LEVEL_FEMALE, 20, SPECIES_WORMADAM_TRASH_CLOAK},
                                {EVO_LEVEL_MALE, 20, SPECIES_MOTHIM}),
    },

#define WORMADAM_MISC_INFO                                                      \
        .catchRate = 45,                                                        \
        .expYield = 148,                                                        \
        .itemRare = ITEM_SILVER_POWDER,                                         \
        .genderRatio = MON_FEMALE,                                              \
        .eggCycles = 15,                                                        \
        .friendship = STANDARD_FRIENDSHIP,                                      \
        .growthRate = GROWTH_MEDIUM_FAST,                                       \
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },                          \
        .abilities = { ABILITY_ANTICIPATION, ABILITY_NONE, ABILITY_OVERCOAT },  \
        .speciesName = _("Burmy"),                                           \
        .cryId = CRY_WORMADAM,                                                  \
        .natDexNum = NATIONAL_DEX_WORMADAM,                                     \
        .categoryName = _("Beutelwurm"),                                           \
        .height = 5,                                                            \
        .weight = 65,                                                           \
        .pokemonScale = 432,                                                    \
        .pokemonOffset = 13,                                                    \
        .trainerScale = 256,                                                    \
        .trainerOffset = 0,                                                     \
        .frontPicYOffset = 10,                                                  \
        .frontAnimFrames = sAnims_Wormadam,                                     \
        .frontAnimId = ANIM_SWING_CONVEX_FAST_SHORT,                            \
        .enemyMonElevation = 8,                                                 \
        .backPicYOffset = 2,                                                    \
        .backAnimId = BACK_ANIM_V_SHAKE,                                        \
        .footprint = gMonFootprint_Wormadam,                                    \
        .formSpeciesIdTable = sWormadamFormSpeciesIdTable

    [SPECIES_WORMADAM_PLANT_CLOAK] =
    {
        WORMADAM_MISC_INFO,
        .baseHP        = 60,
        .baseAttack    = 59,
        .baseDefense   = 85,
        .baseSpeed     = 36,
        .baseSpAttack  = 79,
        .baseSpDefense = 105,
        .types = { TYPE_BUG, TYPE_GRASS },
        .evYield_SpDefense = 2,
        .bodyColor = BODY_COLOR_GREEN,
        .description = POKEDEX_DESC_STRING(
            "Die Umgebung, in der es sich\n"
            "entwickelt, bestimmt sein Aussehen.\n"
            "Es formt seinen Körper mithilfe der\n"
            "umliegenden Materialien."),
        FRONT_PIC(WormadamPlantCloak, 48, 56),
        BACK_PIC(WormadamPlantCloak, 56, 64),
        PALETTES(WormadamPlantCloak),
        ICON(WormadamPlantCloak, 1),
        LEARNSETS(WormadamPlantCloak),
    },

    [SPECIES_WORMADAM_SANDY_CLOAK] =
    {
        WORMADAM_MISC_INFO,
        .baseHP        = 60,
        .baseAttack    = 79,
        .baseDefense   = 105,
        .baseSpeed     = 36,
        .baseSpAttack  = 59,
        .baseSpDefense = 85,
        .types = { TYPE_BUG, TYPE_GROUND },
        .evYield_Defense = 2,
        .bodyColor = BODY_COLOR_BROWN,
        .description = POKEDEX_DESC_STRING(
            "Die Umgebung, in der es sich\n"
            "entwickelt, bestimmt sein Aussehen.\n"
            "Es formt seinen Körper mithilfe der\n"
            "umliegenden Materialien."),
        FRONT_PIC(WormadamSandyCloak, 40, 56),
        BACK_PIC(WormadamSandyCloak, 56, 64),
        PALETTES(WormadamSandyCloak),
        ICON(WormadamSandyCloak, 1),
        LEARNSETS(WormadamSandyCloak),
    },

    [SPECIES_WORMADAM_TRASH_CLOAK] =
    {
        WORMADAM_MISC_INFO,
        .baseHP        = 60,
        .baseAttack    = 69,
        .baseDefense   = 95,
        .baseSpeed     = 36,
        .baseSpAttack  = 69,
        .baseSpDefense = 95,
        .types = { TYPE_BUG, TYPE_STEEL },
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .bodyColor = BODY_COLOR_RED,
        .description = POKEDEX_DESC_STRING(
            "Die Umgebung, in der es sich\n"
            "entwickelt, bestimmt sein Aussehen.\n"
            "Es formt seinen Körper mithilfe der\n"
            "umliegenden Materialien."),
        FRONT_PIC(WormadamTrashCloak, 48, 56),
        BACK_PIC(WormadamTrashCloak, 64, 64),
        PALETTES(WormadamTrashCloak),
        ICON(WormadamTrashCloak, 0),
        LEARNSETS(WormadamTrashCloak),
    },

    [SPECIES_MOTHIM] =
    {
        .baseHP        = 70,
        .baseAttack    = 94,
        .baseDefense   = 50,
        .baseSpeed     = 66,
        .baseSpAttack  = 94,
        .baseSpDefense = 50,
        .types = { TYPE_BUG, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 148,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_SILVER_POWDER,
        .genderRatio = MON_MALE,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_SWARM, ABILITY_NONE, ABILITY_TINTED_LENS },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Moterpel"),
        .cryId = CRY_MOTHIM,
        .natDexNum = NATIONAL_DEX_MOTHIM,
        .categoryName = _("Motte"),
        .height = 9,
        .weight = 233,
        .description = POKEDEX_DESC_STRING(
            "Es liebt Honig und stiehlt den\n"
            "Honig, der von Wadribie gesammelt\n"
            "wurde."),
        .pokemonScale = 338,
        .pokemonOffset = 8,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Mothim, 64, 64),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Mothim,
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 10,
        BACK_PIC(Mothim, 64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Mothim),
        ICON(Mothim, 0),
        .footprint = gMonFootprint_Mothim,
        LEARNSETS(Mothim),
    },
#endif //P_FAMILY_BURMY

#if P_FAMILY_COMBEE
    [SPECIES_COMBEE] =
    {
        .baseHP        = 30,
        .baseAttack    = 30,
        .baseDefense   = 42,
        .baseSpeed     = 70,
        .baseSpAttack  = 30,
        .baseSpDefense = 42,
        .types = { TYPE_BUG, TYPE_FLYING },
        .catchRate = 120,
        .expYield = 49,
        .evYield_Speed = 1,
        .itemRare = ITEM_HONEY,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_HONEY_GATHER, ABILITY_NONE, ABILITY_HUSTLE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Wadribie"),
        .cryId = CRY_COMBEE,
        .natDexNum = NATIONAL_DEX_COMBEE,
        .categoryName = _("Kleinbienen"),
        .height = 3,
        .weight = 55,
        .description = POKEDEX_DESC_STRING(
            "Dieses Trio ist von Geburt an\n"
            "zusammen. Fleißig bringt es\n"
            "Blütenhonig zu Honweisel."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Combee, 64, 40),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Combee,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 15,
        BACK_PIC(Combee, 64, 48),
        .backPicYOffset = 22,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Combee),
        PALETTE_FEMALE(Combee),
        ICON(Combee, 0),
        .footprint = gMonFootprint_Combee,
        LEARNSETS(Combee),
        .evolutions = EVOLUTION({EVO_LEVEL_FEMALE, 21, SPECIES_VESPIQUEN}),
    },

    [SPECIES_VESPIQUEN] =
    {
        .baseHP        = 70,
        .baseAttack    = 80,
        .baseDefense   = 102,
        .baseSpeed     = 40,
        .baseSpAttack  = 80,
        .baseSpDefense = 102,
        .types = { TYPE_BUG, TYPE_FLYING },
        .catchRate = 45,
        .expYield = 166,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = MON_FEMALE,
        .eggCycles = 15,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_BUG },
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_UNNERVE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Honweisel"),
        .cryId = CRY_VESPIQUEN,
        .natDexNum = NATIONAL_DEX_VESPIQUEN,
        .categoryName = _("Bienenstock"),
        .height = 12,
        .weight = 385,
        .description = POKEDEX_DESC_STRING(
            "Je mehr Pheromone ein Honweisel freisetzt,\n"
            "desto mehr Wadribie kann es kontrollieren."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Vespiquen, 48, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Vespiquen,
        .frontAnimId = ANIM_LUNGE_GROW,
        .enemyMonElevation = 4,
        BACK_PIC(Vespiquen, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CIRCLE_COUNTERCLOCKWISE,
        PALETTES(Vespiquen),
        ICON(Vespiquen, 0),
        .footprint = gMonFootprint_Vespiquen,
        LEARNSETS(Vespiquen),
    },
#endif //P_FAMILY_COMBEE

#if P_FAMILY_PACHIRISU
    [SPECIES_PACHIRISU] =
    {
        .baseHP        = 60,
        .baseAttack    = 45,
        .baseDefense   = 70,
        .baseSpeed     = 95,
        .baseSpAttack  = 45,
        .baseSpDefense = 90,
        .types = { TYPE_ELECTRIC, TYPE_ELECTRIC },
        .catchRate = 200,
        .expYield = 142,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = 100,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_RUN_AWAY, ABILITY_PICKUP, ABILITY_VOLT_ABSORB },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Pachirisu"),
        .cryId = CRY_PACHIRISU,
        .natDexNum = NATIONAL_DEX_PACHIRISU,
        .categoryName = _("Elektrohörnchen"),
        .height = 4,
        .weight = 39,
        .description = POKEDEX_DESC_STRING(
            "Um gespeicherte Elektrizität zu teilen,\n"
            "reiben zwei von ihnen ihre Backentaschen\n"
            "aneinander."),
        .pokemonScale = 491,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Pachirisu, 48, 56),
        FRONT_PIC_FEMALE(Pachirisu, 48, 56),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Pachirisu,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Pachirisu, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(Pachirisu),
        ICON(Pachirisu, 0),
        .footprint = gMonFootprint_Pachirisu,
        LEARNSETS(Pachirisu),
    },
#endif //P_FAMILY_PACHIRISU

#if P_FAMILY_BUIZEL
    [SPECIES_BUIZEL] =
    {
        .baseHP        = 55,
        .baseAttack    = 65,
        .baseDefense   = 35,
        .baseSpeed     = 85,
        .baseSpAttack  = 60,
        .baseSpDefense = 30,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 190,
        .expYield = 66,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_NONE, ABILITY_WATER_VEIL },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Bamelin"),
        .cryId = CRY_BUIZEL,
        .natDexNum = NATIONAL_DEX_BUIZEL,
        .categoryName = _("Meereswiesel"),
        .height = 7,
        .weight = 295,
        .description = POKEDEX_DESC_STRING(
            "Es füllt den Schwimmreifen um seinen Hals\n"
            "mit Luft, um den Kopf über dem Wasser zu\n"
            "halten und die Umgebung zu überblicken."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Buizel, 56, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Buizel,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Buizel, 64, 48),
        BACK_PIC_FEMALE(Buizel, 64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Buizel),
        ICON(Buizel, 0),
        .footprint = gMonFootprint_Buizel,
        LEARNSETS(Buizel),
        .evolutions = EVOLUTION({EVO_LEVEL, 26, SPECIES_FLOATZEL}),
    },

    [SPECIES_FLOATZEL] =
    {
        .baseHP        = 85,
        .baseAttack    = 105,
        .baseDefense   = 55,
        .baseSpeed     = 115,
        .baseSpAttack  = 85,
        .baseSpDefense = 50,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 75,
        .expYield = 173,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_NONE, ABILITY_WATER_VEIL },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Bojelin"),
        .cryId = CRY_FLOATZEL,
        .natDexNum = NATIONAL_DEX_FLOATZEL,
        .categoryName = _("Meereswiesel"),
        .height = 11,
        .weight = 335,
        .description = POKEDEX_DESC_STRING(
            "Da es seit jeher Beute im Wasser jagt,\n"
            "entwickelte es einen Rettungsring."),
        .pokemonScale = 320,
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Floatzel, 64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Floatzel,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(Floatzel, 64, 64),
        BACK_PIC_FEMALE(Floatzel, 64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Floatzel),
        ICON(Floatzel, 0),
        .footprint = gMonFootprint_Floatzel,
        LEARNSETS(Floatzel),
    },
#endif //P_FAMILY_BUIZEL

#if P_FAMILY_CHERUBI
    [SPECIES_CHERUBI] =
    {
        .baseHP        = 45,
        .baseAttack    = 35,
        .baseDefense   = 45,
        .baseSpeed     = 35,
        .baseSpAttack  = 62,
        .baseSpDefense = 53,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 190,
        .expYield = 55,
        .evYield_SpAttack = 1,
        .itemRare = ITEM_MIRACLE_SEED,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_GRASS },
        .abilities = { ABILITY_CHLOROPHYLL, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Kikugi"),
        .cryId = CRY_CHERUBI,
        .natDexNum = NATIONAL_DEX_CHERUBI,
        .categoryName = _("Kirschen"),
        .height = 4,
        .weight = 33,
        .description = POKEDEX_DESC_STRING(
            "Es saugt Nährstoffe, die in seinem\n"
            "Bällchen enthalten sind, und nutzt die\n"
            "Energie für seine Entwicklung."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Cherubi, 40, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_Cherubi,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Cherubi, 48, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Cherubi),
        ICON(Cherubi, 1),
        .footprint = gMonFootprint_Cherubi,
        LEARNSETS(Cherubi),
        .evolutions = EVOLUTION({EVO_LEVEL, 25, SPECIES_CHERRIM_OVERCAST}),
    },

#define CHERRIM_MISC_INFO                                   \
        .baseHP        = 70,                                \
        .baseAttack    = 60,                                \
        .baseDefense   = 70,                                \
        .baseSpeed     = 85,                                \
        .baseSpAttack  = 87,                                \
        .baseSpDefense = 78,                                \
        .types = { TYPE_GRASS, TYPE_GRASS },                \
        .catchRate = 75,                                    \
        .expYield = 158,                                    \
        .evYield_SpAttack = 2,                              \
        .itemRare = ITEM_MIRACLE_SEED,                      \
        .genderRatio = PERCENT_FEMALE(50),                  \
        .eggCycles = 20,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_MEDIUM_FAST,                   \
        .eggGroups = { EGG_GROUP_FAIRY, EGG_GROUP_GRASS },  \
        .abilities = { ABILITY_FLOWER_GIFT, ABILITY_NONE }, \
        .speciesName = _("Kikugi"),                        \
        .cryId = CRY_CHERRIM,                               \
        .natDexNum = NATIONAL_DEX_CHERRIM,                  \
        .categoryName = _("Kirschen"),                       \
        .height = 5,                                        \
        .weight = 93,                                       \
        .pokemonScale = 432,                                \
        .pokemonOffset = 13,                                \
        .trainerScale = 256,                                \
        .trainerOffset = 0,                                 \
        .footprint = gMonFootprint_Cherrim,                 \
        LEARNSETS(Cherrim),                                 \
        .formSpeciesIdTable = sCherrimFormSpeciesIdTable,   \
        .formChangeTable = sCherrimFormChangeTable

    [SPECIES_CHERRIM_OVERCAST] =
    {
        CHERRIM_MISC_INFO,
        .bodyColor = BODY_COLOR_PURPLE,
        .description = POKEDEX_DESC_STRING(
            "Bei Sonnenschein entfaltet seine\n"
            "Knospe ihre BlütenBlätter und es\n"
            "springt lebhaft umher."),
        FRONT_PIC(CherrimOvercast, 32, 48),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_CherrimOvercast,
        .frontAnimId = ANIM_DEEP_V_SQUISH_AND_BOUNCE,
        BACK_PIC(CherrimOvercast, 40, 56),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(CherrimOvercast),
        ICON(CherrimOvercast, 0),
    },

    [SPECIES_CHERRIM_SUNSHINE] =
    {
        CHERRIM_MISC_INFO,
        .bodyColor = BODY_COLOR_PINK,
        .description = POKEDEX_DESC_STRING(
            "Bei Sonnenschein entfaltet seine\n"
            "Knospe ihre BlütenBlätter und es\n"
            "springt lebhaft umher."),
        FRONT_PIC(CherrimSunshine, 48, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_CherrimSunshine,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(CherrimSunshine, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(CherrimSunshine),
        ICON(CherrimSunshine, 1),
    },
#endif //P_FAMILY_CHERUBI

#if P_FAMILY_SHELLOS
#define SHELLOS_MISC_INFO                                                               \
        .baseHP        = 76,                                                            \
        .baseAttack    = 48,                                                            \
        .baseDefense   = 48,                                                            \
        .baseSpeed     = 34,                                                            \
        .baseSpAttack  = 57,                                                            \
        .baseSpDefense = 62,                                                            \
        .types = { TYPE_WATER, TYPE_WATER },                                            \
        .catchRate = 190,                                                               \
        .expYield = 65,                                                                 \
        .evYield_HP = 1,                                                                \
        .genderRatio = PERCENT_FEMALE(50),                                              \
        .eggCycles = 20,                                                                \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_MEDIUM_FAST,                                               \
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_AMORPHOUS },                        \
        .abilities = { ABILITY_STICKY_HOLD, ABILITY_STORM_DRAIN, ABILITY_SAND_FORCE },  \
        .speciesName = _("Kinoso"),                                                    \
        .cryId = CRY_SHELLOS,                                                           \
        .natDexNum = NATIONAL_DEX_SHELLOS,                                              \
        .categoryName = _("Blüten"),                                                  \
        .height = 3,                                                                    \
        .weight = 63,                                                                   \
        .pokemonScale = 530,                                                            \
        .pokemonOffset = 13,                                                            \
        .trainerScale = 256,                                                            \
        .trainerOffset = 0,                                                             \
        .frontAnimFrames = sAnims_Shellos,                                              \
        .frontAnimId = ANIM_V_STRETCH,                                                  \
        .backPicYOffset = 8,                                                            \
        .backAnimId = BACK_ANIM_H_SPRING,                                               \
        .footprint = gMonFootprint_Shellos,                                             \
        LEARNSETS(Shellos),                                                             \
        .formSpeciesIdTable = sShellosFormSpeciesIdTable

    [SPECIES_SHELLOS_WEST_SEA] =
    {
        SHELLOS_MISC_INFO,
        .bodyColor = BODY_COLOR_PURPLE,
        .description = POKEDEX_DESC_STRING(
            "Nicht seinen Körper\n"
            "zusammendrücken, sonst sickert eine\n"
            "seltsame lilafarbene Flüssigkeit\n"
            "aus!"),
        FRONT_PIC(ShellosWestSea, 40, 40),
        .frontPicYOffset = 13,
        BACK_PIC(ShellosWestSea, 40, 56),
        PALETTES(ShellosWestSea),
        ICON(ShellosWestSea, 0),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_GASTRODON_WEST_SEA}),
    },

    [SPECIES_SHELLOS_EAST_SEA] =
    {
        SHELLOS_MISC_INFO,
        .bodyColor = BODY_COLOR_BLUE,
        .description = POKEDEX_DESC_STRING(
            "Nicht seinen Körper\n"
            "zusammendrücken, sonst sickert eine\n"
            "seltsame lilafarbene Flüssigkeit\n"
            "aus!"),
        FRONT_PIC(ShellosEastSea, 40, 40),
        .frontPicYOffset = 14,
        BACK_PIC(ShellosEastSea, 56, 48),
        PALETTES(ShellosEastSea),
        ICON(ShellosEastSea, 0),
        .evolutions = EVOLUTION({EVO_LEVEL, 30, SPECIES_GASTRODON_EAST_SEA}),
    },

#define GASTRODON_MISC_INFO                                                             \
        .baseHP        = 111,                                                           \
        .baseAttack    = 83,                                                            \
        .baseDefense   = 68,                                                            \
        .baseSpeed     = 39,                                                            \
        .baseSpAttack  = 92,                                                            \
        .baseSpDefense = 82,                                                            \
        .types = { TYPE_WATER, TYPE_GROUND },                                           \
        .catchRate = 75,                                                                \
        .expYield = 166,                                                                \
        .evYield_HP = 2,                                                                \
        .genderRatio = PERCENT_FEMALE(50),                                              \
        .eggCycles = 20,                                                                \
        .friendship = STANDARD_FRIENDSHIP,                                              \
        .growthRate = GROWTH_MEDIUM_FAST,                                               \
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_AMORPHOUS },                        \
        .abilities = { ABILITY_STICKY_HOLD, ABILITY_STORM_DRAIN, ABILITY_SAND_FORCE },  \
        .speciesName = _("Schalellos"),                                                  \
        .cryId = CRY_GASTRODON,                                                         \
        .natDexNum = NATIONAL_DEX_GASTRODON,                                            \
        .categoryName = _("Seeschnecken"),                                                  \
        .height = 9,                                                                    \
        .weight = 299,                                                                  \
        .pokemonScale = 338,                                                            \
        .pokemonOffset = 8,                                                             \
        .trainerScale = 256,                                                            \
        .trainerOffset = 0,                                                             \
        .frontPicYOffset = 8,                                                           \
        .frontAnimFrames = sAnims_Gastrodon,                                            \
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,                                     \
        .backPicYOffset = 3,                                                            \
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,                                    \
        .footprint = gMonFootprint_Gastrodon,                                           \
        LEARNSETS(Gastrodon),                                                           \
        .formSpeciesIdTable = sGastrodonFormSpeciesIdTable

    [SPECIES_GASTRODON_WEST_SEA] =
    {
        GASTRODON_MISC_INFO,
        .bodyColor = BODY_COLOR_PURPLE,
        .description = POKEDEX_DESC_STRING(
            "Wird es von einem natürlichen Feind\n"
            "angegriffen, flieht es, indem es\n"
            "ein lila Sekret über die Haut\n"
            "ausstößt."),
        FRONT_PIC(GastrodonWestSea, 48, 48),
        BACK_PIC(GastrodonWestSea, 56, 64),
        PALETTES(GastrodonWestSea),
        ICON(GastrodonWestSea, 0),
    },

    [SPECIES_GASTRODON_EAST_SEA] =
    {
        GASTRODON_MISC_INFO,
        .bodyColor = BODY_COLOR_BLUE,
        .description = POKEDEX_DESC_STRING(
            "Wird es von einem natürlichen Feind\n"
            "angegriffen, flieht es, indem es\n"
            "ein lila Sekret über die Haut\n"
            "ausstößt."),
        FRONT_PIC(GastrodonEastSea, 56, 48),
        BACK_PIC(GastrodonEastSea, 56, 64),
        PALETTES(GastrodonEastSea),
        ICON(GastrodonEastSea, 0),
    },
#endif //P_FAMILY_SHELLOS

#if P_FAMILY_DRIFLOON
    [SPECIES_DRIFLOON] =
    {
        .baseHP        = 90,
        .baseAttack    = 50,
        .baseDefense   = 34,
        .baseSpeed     = 70,
        .baseSpAttack  = 60,
        .baseSpDefense = 44,
        .types = { TYPE_GHOST, TYPE_FLYING },
        .catchRate = 125,
        .expYield = 70,
        .evYield_HP = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FLUCTUATING,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_AFTERMATH, ABILITY_UNBURDEN, ABILITY_FLARE_BOOST },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Driftlon"),
        .cryId = CRY_DRIFLOON,
        .natDexNum = NATIONAL_DEX_DRIFLOON,
        .categoryName = _("Ballon"),
        .height = 4,
        .weight = 12,
        .description = POKEDEX_DESC_STRING(
            "Sie sind aus einer Ansammlung an Seelen\n"
            "entstanden. In feuchten Jahreszeiten\n"
            "erscheinen sie in rauen Mengen."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Drifloon, 32, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Drifloon,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 5,
        BACK_PIC(Drifloon, 40, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Drifloon),
        ICON(Drifloon, 2),
        .footprint = gMonFootprint_Drifloon,
        LEARNSETS(Drifloon),
        .evolutions = EVOLUTION({EVO_LEVEL, 28, SPECIES_DRIFBLIM}),
    },

    [SPECIES_DRIFBLIM] =
    {
        .baseHP        = 150,
        .baseAttack    = 80,
        .baseDefense   = 44,
        .baseSpeed     = 80,
        .baseSpAttack  = 90,
        .baseSpDefense = 54,
        .types = { TYPE_GHOST, TYPE_FLYING },
        .catchRate = 60,
        .expYield = 174,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FLUCTUATING,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_AFTERMATH, ABILITY_UNBURDEN, ABILITY_FLARE_BOOST },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Drifzepeli"),
        .cryId = CRY_DRIFBLIM,
        .natDexNum = NATIONAL_DEX_DRIFBLIM,
        .categoryName = _("Luftschiff"),
        .height = 12,
        .weight = 150,
        .description = POKEDEX_DESC_STRING(
            "Es greift sich Menschen und Pokémon und\n"
            "trägt sie fort. Niemand weiß, wohin."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Drifblim, 56, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Drifblim,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 7,
        BACK_PIC(Drifblim, 64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Drifblim),
        ICON(Drifblim, 2),
        .footprint = gMonFootprint_Drifblim,
        LEARNSETS(Drifblim),
    },
#endif //P_FAMILY_DRIFLOON

#if P_FAMILY_BUNEARY
    [SPECIES_BUNEARY] =
    {
        .baseHP        = 55,
        .baseAttack    = 66,
        .baseDefense   = 44,
        .baseSpeed     = 85,
        .baseSpAttack  = 44,
        .baseSpDefense = 56,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 190,
        .expYield = 70,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 0,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_RUN_AWAY, ABILITY_KLUTZ, ABILITY_LIMBER },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Haspiror"),
        .cryId = CRY_BUNEARY,
        .natDexNum = NATIONAL_DEX_BUNEARY,
        .categoryName = _("Hasen"),
        .height = 4,
        .weight = 55,
        .description = POKEDEX_DESC_STRING(
            "Seine Ohren sind immer aufgerollt.\n"
            "Mit ihnen kann es selbst große\n"
            "Felsbrocken zertrümmern."),
        .pokemonScale = 491,
        .pokemonOffset = 16,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Buneary, 32, 64),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Buneary,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        BACK_PIC(Buneary, 64, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Buneary),
        ICON(Buneary, 2),
        .footprint = gMonFootprint_Buneary,
        LEARNSETS(Buneary),
        .evolutions = EVOLUTION({EVO_FRIENDSHIP, 0, SPECIES_LOPUNNY}),
    },

#define LOPUNNY_MISC_INFO                                       \
        .catchRate = 60,                                        \
        .evYield_Speed = 2,                                     \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 20,                                        \
        .friendship = 140,                                      \
        .growthRate = GROWTH_MEDIUM_FAST,                       \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE }, \
        .bodyColor = BODY_COLOR_BROWN,                          \
        .speciesName = _("Haspiror"),                            \
        .natDexNum = NATIONAL_DEX_LOPUNNY,                      \
        .categoryName = _("Hasen"),                            \
        .footprint = gMonFootprint_Lopunny,                     \
        LEARNSETS(Lopunny),                                     \
        .formSpeciesIdTable = sLopunnyFormSpeciesIdTable,       \
        .formChangeTable = sLopunnyFormChangeTable

    [SPECIES_LOPUNNY] =
    {
        LOPUNNY_MISC_INFO,
        .baseHP        = 65,
        .baseAttack    = 76,
        .baseDefense   = 84,
        .baseSpeed     = 105,
        .baseSpAttack  = 54,
        .baseSpDefense = 96,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .expYield = 168,
        .abilities = { ABILITY_CUTE_CHARM, ABILITY_KLUTZ, ABILITY_LIMBER },
        .cryId = CRY_LOPUNNY,
        .height = 12,
        .weight = 333,
        .description = POKEDEX_DESC_STRING(
            "Es ist extrem vorsichtig. Wenn es\n"
            "Gefahr wittert, macht es sich mit\n"
            "flinken Sprüngen aus dem Staub."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Lopunny, 56, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Lopunny,
        .frontAnimId = ANIM_SHRINK_GROW,
        BACK_PIC(Lopunny, 64, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(Lopunny),
        ICON(Lopunny, 2),
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_LOPUNNY_MEGA] =
    {
        LOPUNNY_MISC_INFO,
        .baseHP        = 65,
        .baseAttack    = 136,
        .baseDefense   = 94,
        .baseSpeed     = 135,
        .baseSpAttack  = 54,
        .baseSpDefense = 96,
        .types = { TYPE_NORMAL, TYPE_FIGHTING },
        .expYield = 203,
        .abilities = { ABILITY_SCRAPPY, ABILITY_SCRAPPY, ABILITY_SCRAPPY },
        .cryId = CRY_LOPUNNY_MEGA,
        .height = 13,
        .weight = 283,
        .description = POKEDEX_DESC_STRING(
            "Es ist extrem vorsichtig. Wenn es\n"
            "Gefahr wittert, macht es sich mit\n"
            "flinken Sprüngen aus dem Staub."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(LopunnyMega, 56, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_LopunnyMega,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(LopunnyMega, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(LopunnyMega),
        ICON(LopunnyMega, 2),
        .isMegaEvolution = TRUE,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_BUNEARY

#if P_FAMILY_GLAMEOW
    [SPECIES_GLAMEOW] =
    {
        .baseHP        = 49,
        .baseAttack    = 55,
        .baseDefense   = 42,
        .baseSpeed     = 85,
        .baseSpAttack  = 42,
        .baseSpDefense = 37,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 190,
        .expYield = 62,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_LIMBER, ABILITY_OWN_TEMPO, ABILITY_KEEN_EYE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Charmian"),
        .cryId = CRY_GLAMEOW,
        .natDexNum = NATIONAL_DEX_GLAMEOW,
        .categoryName = _("Fies"),
        .height = 5,
        .weight = 39,
        .description = POKEDEX_DESC_STRING(
            "Es schlägt mit Krallen zu oder\n"
            "schnurrt, je nachdem, ob es gerade\n"
            "wütend oder zutraulich ist."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Glameow, 56, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Glameow,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(Glameow, 64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_SHRINK_GROW,
        PALETTES(Glameow),
        ICON(Glameow, 0),
        .footprint = gMonFootprint_Glameow,
        LEARNSETS(Glameow),
        .evolutions = EVOLUTION({EVO_LEVEL, 38, SPECIES_PURUGLY}),
    },

    [SPECIES_PURUGLY] =
    {
        .baseHP        = 71,
        .baseAttack    = 82,
        .baseDefense   = 64,
        .baseSpeed     = 112,
        .baseSpAttack  = 64,
        .baseSpDefense = 59,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 75,
        .expYield = 158,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(75),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_THICK_FAT, ABILITY_OWN_TEMPO, ABILITY_DEFIANT },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Shnurgarst"),
        .cryId = CRY_PURUGLY,
        .natDexNum = NATIONAL_DEX_PURUGLY,
        .categoryName = _("Tigerkatze"),
        .height = 10,
        .weight = 438,
        .description = POKEDEX_DESC_STRING(
            "Behagt ihm die Behausung eines\n"
            "anderen Pokémon, bleibt Shnurgarst\n"
            "einfach da und nistet sich dort\n"
            "ein."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Purugly, 64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Purugly,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Purugly, 64, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(Purugly),
        ICON(Purugly, 0),
        .footprint = gMonFootprint_Purugly,
        LEARNSETS(Purugly),
    },
#endif //P_FAMILY_GLAMEOW

#if P_FAMILY_STUNKY
    [SPECIES_STUNKY] =
    {
        .baseHP        = 63,
        .baseAttack    = 63,
        .baseDefense   = 47,
        .baseSpeed     = 74,
        .baseSpAttack  = 41,
        .baseSpDefense = 41,
        .types = { TYPE_POISON, TYPE_DARK },
        .catchRate = 225,
        .expYield = 66,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_STENCH, ABILITY_AFTERMATH, ABILITY_KEEN_EYE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Skunkapuh"),
        .cryId = CRY_STUNKY,
        .natDexNum = NATIONAL_DEX_STUNKY,
        .categoryName = _("Stinktier"),
        .height = 4,
        .weight = 192,
        .description = POKEDEX_DESC_STRING(
            "Um sich zu schützen, versprüht es eine\n"
            "Substanz aus seinem Hinterleib, die 24\n"
            "Stunden stinkt."),
        .pokemonScale = 491,
        .pokemonOffset = 17,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Stunky, 56, 48),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Stunky,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        BACK_PIC(Stunky, 64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Stunky),
        ICON(Stunky, 2),
        .footprint = gMonFootprint_Stunky,
        LEARNSETS(Stunky),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_SKUNTANK}),
    },

    [SPECIES_SKUNTANK] =
    {
        .baseHP        = 103,
        .baseAttack    = 93,
        .baseDefense   = 67,
        .baseSpeed     = 84,
        .baseSpAttack  = 71,
        .baseSpDefense = 61,
        .types = { TYPE_POISON, TYPE_DARK },
        .catchRate = 60,
        .expYield = 168,
        .evYield_HP = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_STENCH, ABILITY_AFTERMATH, ABILITY_KEEN_EYE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Skuntank"),
        .cryId = CRY_SKUNTANK,
        .natDexNum = NATIONAL_DEX_SKUNTANK,
        .categoryName = _("Stinktier"),
        .height = 10,
        .weight = 380,
        .description = POKEDEX_DESC_STRING(
            "Es spritzt eine stinkende Substanz aus\n"
            "seinem Schweif. Hat sie lange gegärt,\n"
            "stinkt sie stärker."),
        .pokemonScale = 305,
        .pokemonOffset = 9,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Skuntank, 64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Skuntank,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        BACK_PIC(Skuntank, 64, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_H_STRETCH,
        PALETTES(Skuntank),
        ICON(Skuntank, 2),
        .footprint = gMonFootprint_Skuntank,
        LEARNSETS(Skuntank),
    },
#endif //P_FAMILY_STUNKY

#if P_FAMILY_BRONZOR
    [SPECIES_BRONZOR] =
    {
        .baseHP        = 57,
        .baseAttack    = 24,
        .baseDefense   = 86,
        .baseSpeed     = 23,
        .baseSpAttack  = 24,
        .baseSpDefense = 86,
        .types = { TYPE_STEEL, TYPE_PSYCHIC },
        .catchRate = 255,
        .expYield = 60,
        .evYield_Defense = 1,
        .itemRare = ITEM_METAL_COAT,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_LEVITATE, ABILITY_HEATPROOF, ABILITY_HEAVY_METAL },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Bronzel"),
        .cryId = CRY_BRONZOR,
        .natDexNum = NATIONAL_DEX_BRONZOR,
        .categoryName = _("Bronze"),
        .height = 5,
        .weight = 605,
        .description = POKEDEX_DESC_STRING(
            "Sein Körper sieht aus, als seien Teile\n"
            "davon in alten Gräbern gefunden worden."),
        .pokemonScale = 432,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Bronzor, 32, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Bronzor,
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 9,
        BACK_PIC(Bronzor, 40, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(Bronzor),
        ICON(Bronzor, 0),
        .footprint = gMonFootprint_Bronzor,
        LEARNSETS(Bronzor),
        .evolutions = EVOLUTION({EVO_LEVEL, 33, SPECIES_BRONZONG}),
    },

    [SPECIES_BRONZONG] =
    {
        .baseHP        = 67,
        .baseAttack    = 89,
        .baseDefense   = 116,
        .baseSpeed     = 33,
        .baseSpAttack  = 79,
        .baseSpDefense = 116,
        .types = { TYPE_STEEL, TYPE_PSYCHIC },
        .catchRate = 90,
        .expYield = 175,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .itemRare = ITEM_METAL_COAT,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_MINERAL, EGG_GROUP_MINERAL },
        .abilities = { ABILITY_LEVITATE, ABILITY_HEATPROOF, ABILITY_HEAVY_METAL },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Bronzong"),
        .cryId = CRY_BRONZONG,
        .natDexNum = NATIONAL_DEX_BRONZONG,
        .categoryName = _("Bronzeglocken"),
        .height = 13,
        .weight = 1870,
        .description = POKEDEX_DESC_STRING(
            "Früher verehrten die Menschen die\n"
            "Bronzong, weil sie sich davon Regen oder\n"
            "gute Ernten erhofften."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Bronzong, 56, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Bronzong,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        .enemyMonElevation = 7,
        BACK_PIC(Bronzong, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Bronzong),
        ICON(Bronzong, 0),
        .footprint = gMonFootprint_Bronzong,
        LEARNSETS(Bronzong),
    },
#endif //P_FAMILY_BRONZOR

#if P_FAMILY_CHATOT
    [SPECIES_CHATOT] =
    {
        .baseHP        = 76,
        .baseAttack    = 65,
        .baseDefense   = 45,
        .baseSpeed     = 91,
        .baseSpAttack  = 92,
        .baseSpDefense = 42,
        .types = { TYPE_NORMAL, TYPE_FLYING },
        .catchRate = 30,
        .expYield = 144,
        .evYield_Attack = 1,
        .itemRare = ITEM_METRONOME,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = 35,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_FLYING, EGG_GROUP_FLYING },
        .abilities = { ABILITY_KEEN_EYE, ABILITY_TANGLED_FEET, ABILITY_BIG_PECKS },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Plaudagei"),
        .cryId = CRY_CHATOT,
        .natDexNum = NATIONAL_DEX_CHATOT,
        .categoryName = _("Musiknote"),
        .height = 5,
        .weight = 19,
        .description = POKEDEX_DESC_STRING(
            "Es kann die menschliche Sprache nachahmen.\n"
            "Versammeln sie sich, bringen sich alle\n"
            "dasselbe bei."),
        .pokemonScale = 432,
        .pokemonOffset = 15,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Chatot, 40, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Chatot,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        BACK_PIC(Chatot, 48, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Chatot),
        ICON(Chatot, 0),
        .footprint = gMonFootprint_Chatot,
        LEARNSETS(Chatot),
    },
#endif //P_FAMILY_CHATOT

#if P_FAMILY_SPIRITOMB
    [SPECIES_SPIRITOMB] =
    {
        .baseHP        = 50,
        .baseAttack    = 92,
        .baseDefense   = 108,
        .baseSpeed     = 35,
        .baseSpAttack  = 92,
        .baseSpDefense = 108,
        .types = { TYPE_GHOST, TYPE_DARK },
        .catchRate = 100,
        .expYield = 170,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_INFILTRATOR },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Kryppuk"),
        .cryId = CRY_SPIRITOMB,
        .natDexNum = NATIONAL_DEX_SPIRITOMB,
        .categoryName = _("Verboten"),
        .height = 10,
        .weight = 1080,
        .description = POKEDEX_DESC_STRING(
            "Es besteht aus 108 Geistern. Allerdings\n"
            "scheinen sich auch einige bösartige\n"
            "daruntergemischt zu haben."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Spiritomb, 56, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Spiritomb,
        .frontAnimId = ANIM_GROW_IN_STAGES,
        BACK_PIC(Spiritomb, 64, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(Spiritomb),
        ICON(Spiritomb, 5),
        .footprint = gMonFootprint_Spiritomb,
        LEARNSETS(Spiritomb),
    },
#endif //P_FAMILY_SPIRITOMB

#if P_FAMILY_GIBLE
    [SPECIES_GIBLE] =
    {
        .baseHP        = 58,
        .baseAttack    = 70,
        .baseDefense   = 45,
        .baseSpeed     = 42,
        .baseSpAttack  = 40,
        .baseSpDefense = 45,
        .types = { TYPE_DRAGON, TYPE_GROUND },
        .catchRate = 45,
        .expYield = 60,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_SAND_VEIL, ABILITY_NONE, ABILITY_ROUGH_SKIN },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Kaumalat"),
        .cryId = CRY_GIBLE,
        .natDexNum = NATIONAL_DEX_GIBLE,
        .categoryName = _("Landhai"),
        .height = 7,
        .weight = 205,
        .description = POKEDEX_DESC_STRING(
            "Es nistet in kleinen Löchern in\n"
            "Höhlenwänden. Es springt Beute, die sich\n"
            "zu nah heranwagt, an."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Gible, 48, 48),
        FRONT_PIC_FEMALE(Gible, 48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Gible,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Gible, 56, 48),
        BACK_PIC_FEMALE(Gible, 56, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Gible),
        ICON(Gible, 0),
        .footprint = gMonFootprint_Gible,
        LEARNSETS(Gible),
        .evolutions = EVOLUTION({EVO_LEVEL, 24, SPECIES_GABITE}),
    },

    [SPECIES_GABITE] =
    {
        .baseHP        = 68,
        .baseAttack    = 90,
        .baseDefense   = 65,
        .baseSpeed     = 82,
        .baseSpAttack  = 50,
        .baseSpDefense = 55,
        .types = { TYPE_DRAGON, TYPE_GROUND },
        .catchRate = 45,
        .expYield = 144,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },
        .abilities = { ABILITY_SAND_VEIL, ABILITY_NONE, ABILITY_ROUGH_SKIN },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Knarksel"),
        .cryId = CRY_GABITE,
        .natDexNum = NATIONAL_DEX_GABITE,
        .categoryName = _("Höhlen"),
        .height = 14,
        .weight = 560,
        .description = POKEDEX_DESC_STRING(
            "Ab und zu häutet es sich und verliert\n"
            "Schuppen. Medizin, die solche Schuppen\n"
            "enthält, macht müde Körper munter."),
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Gabite, 64, 64),
        FRONT_PIC_FEMALE(Gabite, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Gabite,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Gabite, 64, 64),
        BACK_PIC_FEMALE(Gabite, 64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Gabite),
        ICON(Gabite, 0),
        .footprint = gMonFootprint_Gabite,
        LEARNSETS(Gabite),
        .evolutions = EVOLUTION({EVO_LEVEL, 48, SPECIES_GARCHOMP}),
    },

#define GARCHOMP_MISC_INFO                                      \
        .types = { TYPE_DRAGON, TYPE_GROUND },                  \
        .catchRate = 45,                                        \
        .evYield_Attack = 3,                                    \
        .genderRatio = PERCENT_FEMALE(50),                      \
        .eggCycles = 40,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_SLOW,                              \
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_DRAGON },   \
        .bodyColor = BODY_COLOR_BLUE,                           \
        .speciesName = _("Knarksel"),                           \
        .natDexNum = NATIONAL_DEX_GARCHOMP,                     \
        .categoryName = _("Höhlen"),                              \
        .height = 19,                                           \
        .weight = 950,                                          \
        .pokemonScale = 256,                                    \
        .pokemonOffset = 1,                                     \
        .trainerScale = 326,                                    \
        .trainerOffset = 4,                                     \
        .footprint = gMonFootprint_Garchomp,                    \
        LEARNSETS(Garchomp),                                    \
        .formSpeciesIdTable = sGarchompFormSpeciesIdTable,      \
        .formChangeTable = sGarchompFormChangeTable

    [SPECIES_GARCHOMP] =
    {
        GARCHOMP_MISC_INFO,
        .baseHP        = 108,
        .baseAttack    = 130,
        .baseDefense   = 95,
        .baseSpeed     = 102,
        .baseSpAttack  = 80,
        .baseSpDefense = 85,
        .expYield = 270,
        .abilities = { ABILITY_SAND_VEIL, ABILITY_NONE, ABILITY_ROUGH_SKIN },
        .cryId = CRY_GARCHOMP,
        .description = POKEDEX_DESC_STRING(
            "Spannt es seinen Körper und seine\n"
            "Flügel, sieht es aus wie ein Jet.\n"
            "Es fliegt mit\n"
            "Schallgeschwindigkeit."),
        FRONT_PIC(Garchomp, 64, 64),
        FRONT_PIC_FEMALE(Garchomp, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Garchomp,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        BACK_PIC(Garchomp, 64, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Garchomp),
        ICON(Garchomp, 0),
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_GARCHOMP_MEGA] =
    {
        GARCHOMP_MISC_INFO,
        .baseHP        = 108,
        .baseAttack    = 170,
        .baseDefense   = 115,
        .baseSpeed     = 92,
        .baseSpAttack  = 120,
        .baseSpDefense = 95,
        .expYield = 315,
        .abilities = { ABILITY_SAND_FORCE, ABILITY_SAND_FORCE, ABILITY_SAND_FORCE },
        .cryId = CRY_GARCHOMP_MEGA,
        .description = POKEDEX_DESC_STRING(
            "Spannt es seinen Körper und seine\n"
            "Flügel, sieht es aus wie ein Jet.\n"
            "Es fliegt mit\n"
            "Schallgeschwindigkeit."),
        FRONT_PIC(GarchompMega, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_GarchompMega,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(GarchompMega, 64, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_JOLT_RIGHT,
        PALETTES(GarchompMega),
        ICON(GarchompMega, 0),
        .isMegaEvolution = TRUE,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_GIBLE

#if P_FAMILY_RIOLU
    [SPECIES_RIOLU] =
    {
        .baseHP        = 40,
        .baseAttack    = 70,
        .baseDefense   = 40,
        .baseSpeed     = 60,
        .baseSpAttack  = 35,
        .baseSpDefense = 40,
        .types = { TYPE_FIGHTING, TYPE_FIGHTING },
        .catchRate = 75,
        .expYield = 57,
        .evYield_Attack = 1,
        .genderRatio = PERCENT_FEMALE(12.5),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_STEADFAST, ABILITY_INNER_FOCUS, ABILITY_PRANKSTER },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Riolu"),
        .cryId = CRY_RIOLU,
        .natDexNum = NATIONAL_DEX_RIOLU,
        .categoryName = _("Wellenspiel"),
        .height = 7,
        .weight = 202,
        .description = POKEDEX_DESC_STRING(
            "Es kommuniziert mit seinen\n"
            "Artgenossen über Wellen, die je\n"
            "nach Gefühlslage eine andere Form\n"
            "annehmen."),
        .pokemonScale = 365,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Riolu, 48, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Riolu,
        .frontAnimId = ANIM_RAPID_H_HOPS,
        BACK_PIC(Riolu, 64, 64),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(Riolu),
        ICON(Riolu, 2),
        .footprint = gMonFootprint_Riolu,
        LEARNSETS(Riolu),
        .evolutions = EVOLUTION({EVO_FRIENDSHIP_DAY, 0, SPECIES_LUCARIO}),
    },

#define LUCARIO_MISC_INFO                                       \
        .types = { TYPE_FIGHTING, TYPE_STEEL },                 \
        .catchRate = 45,                                        \
        .evYield_Attack = 1,                                    \
        .evYield_SpAttack = 1,                                  \
        .genderRatio = PERCENT_FEMALE(12.5),                    \
        .eggCycles = 25,                                        \
        .friendship = STANDARD_FRIENDSHIP,                      \
        .growthRate = GROWTH_MEDIUM_SLOW,                       \
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_HUMAN_LIKE }, \
        .bodyColor = BODY_COLOR_BLUE,                           \
        .speciesName = _("Riolu"),                            \
        .natDexNum = NATIONAL_DEX_LUCARIO,                      \
        .categoryName = _("Wellenspiel"),                              \
        .footprint = gMonFootprint_Lucario,                     \
        LEARNSETS(Lucario),                                     \
        .formSpeciesIdTable = sLucarioFormSpeciesIdTable,       \
        .formChangeTable = sLucarioFormChangeTable

    [SPECIES_LUCARIO] =
    {
        LUCARIO_MISC_INFO,
        .baseHP        = 70,
        .baseAttack    = 110,
        .baseDefense   = 70,
        .baseSpeed     = 90,
        .baseSpAttack  = 115,
        .baseSpDefense = 70,
        .expYield = 184,
        .abilities = { ABILITY_STEADFAST, ABILITY_INNER_FOCUS, ABILITY_JUSTIFIED },
        .cryId = CRY_LUCARIO,
        .height = 12,
        .weight = 540,
        .description = POKEDEX_DESC_STRING(
            "Es nimmt die Aura seines Gegners\n"
            "wahr. So kann es dessen Gedanken\n"
            "und Bewegungen erkennen."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Lucario, 48, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_Lucario,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Lucario, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Lucario),
        ICON(Lucario, 2),
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_LUCARIO_MEGA] =
    {
        LUCARIO_MISC_INFO,
        .baseHP        = 70,
        .baseAttack    = 145,
        .baseDefense   = 88,
        .baseSpeed     = 112,
        .baseSpAttack  = 140,
        .baseSpDefense = 70,
        .expYield = 219,
        .abilities = { ABILITY_ADAPTABILITY, ABILITY_ADAPTABILITY, ABILITY_ADAPTABILITY },
        .cryId = CRY_LUCARIO_MEGA,
        .height = 13,
        .weight = 575,
        .description = POKEDEX_DESC_STRING(
            "Es nimmt die Aura seines Gegners\n"
            "wahr. So kann es dessen Gedanken\n"
            "und Bewegungen erkennen."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(LucarioMega, 48, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_LucarioMega,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(LucarioMega, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_LARGE,
        PALETTES(LucarioMega),
        ICON(LucarioMega, 2),
        .isMegaEvolution = TRUE,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_RIOLU

#if P_FAMILY_HIPPOPOTAS
    [SPECIES_HIPPOPOTAS] =
    {
        .baseHP        = 68,
        .baseAttack    = 72,
        .baseDefense   = 78,
        .baseSpeed     = 32,
        .baseSpAttack  = 38,
        .baseSpDefense = 42,
        .types = { TYPE_GROUND, TYPE_GROUND },
        .catchRate = 140,
        .expYield = 66,
        .evYield_Defense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SAND_STREAM, ABILITY_NONE, ABILITY_SAND_FORCE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Hippopotas"),
        .cryId = CRY_HIPPOPOTAS,
        .natDexNum = NATIONAL_DEX_HIPPOPOTAS,
        .categoryName = _("Flusspferd"),
        .height = 8,
        .weight = 495,
        .description = POKEDEX_DESC_STRING(
            "Es lebt in ausgetrockneten\n"
            "Gebieten. Statt zu schwitzen,\n"
            "sondert sein Körper Sand ab."),
        .pokemonScale = 366,
        .pokemonOffset = 11,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Hippopotas, 64, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Hippopotas,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(Hippopotas, 64, 40),
        .backPicYOffset = 14,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Hippopotas),
        PALETTE_FEMALE(Hippopotas),
        ICON(Hippopotas, 1),
    #if P_CUSTOM_GENDER_DIFF_ICONS == TRUE
        ICON_FEMALE(Hippopotas, 1),
    #endif
        .footprint = gMonFootprint_Hippopotas,
        LEARNSETS(Hippopotas),
        .evolutions = EVOLUTION({EVO_LEVEL, 34, SPECIES_HIPPOWDON}),
    },

    [SPECIES_HIPPOWDON] =
    {
        .baseHP        = 108,
        .baseAttack    = 112,
        .baseDefense   = 118,
        .baseSpeed     = 47,
        .baseSpAttack  = 68,
        .baseSpDefense = 72,
        .types = { TYPE_GROUND, TYPE_GROUND },
        .catchRate = 60,
        .expYield = 184,
        .evYield_Defense = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 30,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_FIELD, EGG_GROUP_FIELD },
        .abilities = { ABILITY_SAND_STREAM, ABILITY_NONE, ABILITY_SAND_FORCE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Hippoterus"),
        .cryId = CRY_HIPPOWDON,
        .natDexNum = NATIONAL_DEX_HIPPOWDON,
        .categoryName = _("Schwergewichts"),
        .height = 20,
        .weight = 3000,
        .description = POKEDEX_DESC_STRING(
            "Das weit aufgerissene Maul\n"
            "demonstriert seine Stärke. Es\n"
            "attackiert mit gebündeltem Sand."),
        .pokemonScale = 261,
        .pokemonOffset = 2,
        .trainerScale = 334,
        .trainerOffset = 4,
        FRONT_PIC(Hippowdon, 64, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Hippowdon,
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        BACK_PIC(Hippowdon, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Hippowdon),
        PALETTE_FEMALE(Hippowdon),
        ICON(Hippowdon, 1),
    #if P_CUSTOM_GENDER_DIFF_ICONS == TRUE
        ICON_FEMALE(Hippowdon, 1),
    #endif
        .footprint = gMonFootprint_Hippowdon,
        LEARNSETS(Hippowdon),
    },
#endif //P_FAMILY_HIPPOPOTAS

#if P_FAMILY_SKORUPI
    [SPECIES_SKORUPI] =
    {
        .baseHP        = 40,
        .baseAttack    = 50,
        .baseDefense   = 90,
        .baseSpeed     = 65,
        .baseSpAttack  = 30,
        .baseSpDefense = 55,
        .types = { TYPE_POISON, TYPE_BUG },
        .catchRate = 120,
        .expYield = 66,
        .evYield_Defense = 1,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_BATTLE_ARMOR, ABILITY_SNIPER, ABILITY_KEEN_EYE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Pionskora"),
        .cryId = CRY_SKORUPI,
        .natDexNum = NATIONAL_DEX_SKORUPI,
        .categoryName = _("Skorpion"),
        .height = 8,
        .weight = 120,
        .description = POKEDEX_DESC_STRING(
            "Es greift seine Beute mit den\n"
            "Krallen an seinem Schweif und\n"
            "vergiftet sie. Dann wartet es ab..."),
        .pokemonScale = 366,
        .pokemonOffset = 12,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Skorupi, 48, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Skorupi,
        .frontAnimId = ANIM_H_SLIDE_SLOW,
        BACK_PIC(Skorupi, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(Skorupi),
        ICON(Skorupi, 0),
        .footprint = gMonFootprint_Skorupi,
        LEARNSETS(Skorupi),
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_DRAPION}),
    },

    [SPECIES_DRAPION] =
    {
        .baseHP        = 70,
        .baseAttack    = 90,
        .baseDefense   = 110,
        .baseSpeed     = 95,
        .baseSpAttack  = 60,
        .baseSpDefense = 75,
        .types = { TYPE_POISON, TYPE_DARK },
        .catchRate = 45,
        .expYield = 175,
        .evYield_Defense = 2,
        .itemRare = ITEM_POISON_BARB,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_BUG, EGG_GROUP_WATER_3 },
        .abilities = { ABILITY_BATTLE_ARMOR, ABILITY_SNIPER, ABILITY_KEEN_EYE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Piondragi"),
        .cryId = CRY_DRAPION,
        .natDexNum = NATIONAL_DEX_DRAPION,
        .categoryName = _("Ogerskorpion"),
        .height = 13,
        .weight = 615,
        .description = POKEDEX_DESC_STRING(
            "In seinen Armen steckt so viel Kraft, dass\n"
            "es mit seinen giftigen Krallen Autos\n"
            "zerquetschen kann."),
        .pokemonScale = 272,
        .pokemonOffset = 5,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Drapion, 64, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_Drapion,
        .frontAnimId = ANIM_V_JUMPS_BIG,
        BACK_PIC(Drapion, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Drapion),
        ICON(Drapion, 2),
        .footprint = gMonFootprint_Drapion,
        LEARNSETS(Drapion),
    },
#endif //P_FAMILY_SKORUPI

#if P_FAMILY_CROAGUNK
    [SPECIES_CROAGUNK] =
    {
        .baseHP        = 48,
        .baseAttack    = 61,
        .baseDefense   = 40,
        .baseSpeed     = 50,
        .baseSpAttack  = 61,
        .baseSpDefense = 40,
        .types = { TYPE_POISON, TYPE_FIGHTING },
        .catchRate = 140,
        .expYield = 60,
        .evYield_Attack = 1,
        .itemRare = ITEM_BLACK_SLUDGE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = 100,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_ANTICIPATION, ABILITY_DRY_SKIN, ABILITY_POISON_TOUCH },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Glibunkel"),
        .cryId = CRY_CROAGUNK,
        .natDexNum = NATIONAL_DEX_CROAGUNK,
        .categoryName = _("Giftmund"),
        .height = 7,
        .weight = 230,
        .description = POKEDEX_DESC_STRING(
            "In seinen Backen sammelt sich Gift.\n"
            "Es versucht, Beute zu überraschen\n"
            "und mit Giftfingern zu schnappen."),
        .pokemonScale = 365,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Croagunk, 40, 48),
        FRONT_PIC_FEMALE(Croagunk, 40, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_Croagunk,
        .frontAnimId = ANIM_RAPID_H_HOPS,
        BACK_PIC(Croagunk, 56, 56),
        BACK_PIC_FEMALE(Croagunk, 56, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_GROW,
        PALETTES(Croagunk),
        ICON(Croagunk, 0),
        .footprint = gMonFootprint_Croagunk,
        LEARNSETS(Croagunk),
        .evolutions = EVOLUTION({EVO_LEVEL, 37, SPECIES_TOXICROAK}),
    },

    [SPECIES_TOXICROAK] =
    {
        .baseHP        = 83,
        .baseAttack    = 106,
        .baseDefense   = 65,
        .baseSpeed     = 85,
        .baseSpAttack  = 86,
        .baseSpDefense = 65,
        .types = { TYPE_POISON, TYPE_FIGHTING },
        .catchRate = 75,
        .expYield = 172,
        .evYield_Attack = 2,
        .itemRare = ITEM_BLACK_SLUDGE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = { EGG_GROUP_HUMAN_LIKE, EGG_GROUP_HUMAN_LIKE },
        .abilities = { ABILITY_ANTICIPATION, ABILITY_DRY_SKIN, ABILITY_POISON_TOUCH },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Toxiquak"),
        .cryId = CRY_TOXICROAK,
        .natDexNum = NATIONAL_DEX_TOXICROAK,
        .categoryName = _("Giftmund"),
        .height = 13,
        .weight = 444,
        .description = POKEDEX_DESC_STRING(
            "Die Gelenke an seinen Klauen geben ein so\n"
            "starkes Gift ab, dass selbst ein kleiner\n"
            "Kratzer fatal ist."),
        .pokemonScale = 272,
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Toxicroak, 56, 56),
        FRONT_PIC_FEMALE(Toxicroak, 56, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Toxicroak,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Toxicroak, 56, 56),
        BACK_PIC_FEMALE(Toxicroak, 56, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(Toxicroak),
        ICON(Toxicroak, 0),
        .footprint = gMonFootprint_Toxicroak,
        LEARNSETS(Toxicroak),
    },
#endif //P_FAMILY_CROAGUNK

#if P_FAMILY_CARNIVINE
    [SPECIES_CARNIVINE] =
    {
        .baseHP        = 74,
        .baseAttack    = 100,
        .baseDefense   = 72,
        .baseSpeed     = 46,
        .baseSpAttack  = 90,
        .baseSpDefense = 72,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .catchRate = 200,
        .expYield = 159,
        .evYield_Attack = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 25,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_GRASS, EGG_GROUP_GRASS },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Venuflibis"),
        .cryId = CRY_CARNIVINE,
        .natDexNum = NATIONAL_DEX_CARNIVINE,
        .categoryName = _("Käfertod"),
        .height = 14,
        .weight = 270,
        .description = POKEDEX_DESC_STRING(
            "Sein süßlich riechender Speichel\n"
            "zieht Beute an, die es frisst. Es\n"
            "braucht einen Tag, sie zu fressen."),
        .pokemonScale = 265,
        .pokemonOffset = 2,
        .trainerScale = 262,
        .trainerOffset = 0,
        FRONT_PIC(Carnivine, 64, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Carnivine,
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = 8,
        BACK_PIC(Carnivine, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(Carnivine),
        ICON(Carnivine, 1),
        .footprint = gMonFootprint_Carnivine,
        LEARNSETS(Carnivine),
    },
#endif //P_FAMILY_CARNIVINE

#if P_FAMILY_FINNEON
    [SPECIES_FINNEON] =
    {
        .baseHP        = 49,
        .baseAttack    = 49,
        .baseDefense   = 56,
        .baseSpeed     = 66,
        .baseSpAttack  = 49,
        .baseSpDefense = 61,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 190,
        .expYield = 66,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2 },
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_STORM_DRAIN, ABILITY_WATER_VEIL },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Finneon"),
        .cryId = CRY_FINNEON,
        .natDexNum = NATIONAL_DEX_FINNEON,
        .categoryName = _("Flügelfisch"),
        .height = 4,
        .weight = 70,
        .description = POKEDEX_DESC_STRING(
            "Wurden die Flossen lange dem Sonnenlicht\n"
            "ausgesetzt, leuchten sie in der\n"
            "Dunkelheit."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Finneon, 32, 40),
        FRONT_PIC_FEMALE(Finneon, 32, 40),
        .frontPicYOffset = 14,
        .frontAnimFrames = sAnims_Finneon,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        BACK_PIC(Finneon, 56, 40),
        BACK_PIC_FEMALE(Finneon, 56, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Finneon),
        ICON(Finneon, 0),
        .footprint = gMonFootprint_Finneon,
        LEARNSETS(Finneon),
        .evolutions = EVOLUTION({EVO_LEVEL, 31, SPECIES_LUMINEON}),
    },

    [SPECIES_LUMINEON] =
    {
        .baseHP        = 69,
        .baseAttack    = 69,
        .baseDefense   = 76,
        .baseSpeed     = 91,
        .baseSpAttack  = 69,
        .baseSpDefense = 86,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 75,
        .expYield = 161,
        .evYield_Speed = 2,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_ERRATIC,
        .eggGroups = { EGG_GROUP_WATER_2, EGG_GROUP_WATER_2 },
        .abilities = { ABILITY_SWIFT_SWIM, ABILITY_STORM_DRAIN, ABILITY_WATER_VEIL },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Lumineon"),
        .cryId = CRY_LUMINEON,
        .natDexNum = NATIONAL_DEX_LUMINEON,
        .categoryName = _("Neon"),
        .height = 12,
        .weight = 240,
        .description = POKEDEX_DESC_STRING(
            "Es lebt tief auf dem Meeresboden.\n"
            "Das blinkende Muster auf seinen\n"
            "vier Rückenflossen zieht Beute an."),
        .pokemonScale = 282,
        .pokemonOffset = 4,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Lumineon, 56, 56),
        FRONT_PIC_FEMALE(Lumineon, 56, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Lumineon,
        .frontAnimId = ANIM_H_STRETCH,
        BACK_PIC(Lumineon, 56, 64),
        BACK_PIC_FEMALE(Lumineon, 56, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Lumineon),
        ICON(Lumineon, 0),
        .footprint = gMonFootprint_Lumineon,
        LEARNSETS(Lumineon),
    },
#endif //P_FAMILY_FINNEON

#if P_FAMILY_SNOVER
    [SPECIES_SNOVER] =
    {
        .baseHP        = 60,
        .baseAttack    = 62,
        .baseDefense   = 50,
        .baseSpeed     = 40,
        .baseSpAttack  = 62,
        .baseSpDefense = 60,
        .types = { TYPE_GRASS, TYPE_ICE },
        .catchRate = 120,
        .expYield = 67,
        .evYield_Attack = 1,
        .itemRare = ITEM_NEVER_MELT_ICE,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_GRASS },
        .abilities = { ABILITY_SNOW_WARNING, ABILITY_NONE, ABILITY_SOUNDPROOF },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Shnebedeck"),
        .cryId = CRY_SNOVER,
        .natDexNum = NATIONAL_DEX_SNOVER,
        .categoryName = _("Frostbaum"),
        .height = 10,
        .weight = 505,
        .description = POKEDEX_DESC_STRING(
            "Im Frühjahr wachsen Beeren, die wie\n"
            "gefrorene Süßigkeiten aussehen, um seinen\n"
            "Bauch herum."),
        .pokemonScale = 305,
        .pokemonOffset = 7,
        .trainerScale = 257,
        .trainerOffset = 0,
        FRONT_PIC(Snover, 64, 48),
        FRONT_PIC_FEMALE(Snover, 64, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_Snover,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(Snover, 64, 56),
        BACK_PIC_FEMALE(Snover, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_STRETCH,
        PALETTES(Snover),
        ICON(Snover, 1),
        .footprint = gMonFootprint_Snover,
        LEARNSETS(Snover),
        .evolutions = EVOLUTION({EVO_LEVEL, 40, SPECIES_ABOMASNOW}),
    },

#define ABOMASNOW_MISC_INFO                                 \
        .types = { TYPE_GRASS, TYPE_ICE },                  \
        .catchRate = 60,                                    \
        .evYield_Attack = 1,                                \
        .evYield_SpAttack = 1,                              \
        .itemRare = ITEM_NEVER_MELT_ICE,                    \
        .genderRatio = PERCENT_FEMALE(50),                  \
        .eggCycles = 20,                                    \
        .friendship = STANDARD_FRIENDSHIP,                  \
        .growthRate = GROWTH_SLOW,                          \
        .eggGroups = { EGG_GROUP_MONSTER, EGG_GROUP_GRASS },\
        .bodyColor = BODY_COLOR_WHITE,                      \
        .speciesName = _("Shnebedeck"),                      \
        .natDexNum = NATIONAL_DEX_ABOMASNOW,                \
        .categoryName = _("Frostbaum"),                    \
        .footprint = gMonFootprint_Abomasnow,               \
        LEARNSETS(Abomasnow),                               \
        .formSpeciesIdTable = sAbomasnowFormSpeciesIdTable, \
        .formChangeTable = sAbomasnowFormChangeTable

    [SPECIES_ABOMASNOW] =
    {
        ABOMASNOW_MISC_INFO,
        .baseHP        = 90,
        .baseAttack    = 92,
        .baseDefense   = 75,
        .baseSpeed     = 60,
        .baseSpAttack  = 92,
        .baseSpDefense = 85,
        .expYield = 173,
        .abilities = { ABILITY_SNOW_WARNING, ABILITY_NONE, ABILITY_SOUNDPROOF },
        .cryId = CRY_ABOMASNOW,
        .height = 22,
        .weight = 1355,
        .description = POKEDEX_DESC_STRING(
            "Es bedeckt weite Gebiete mit\n"
            "Schnee, indem es Blizzards auslöst.\n"
            "Man nennt es â€žDas Eismonsterâ€œ."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 348,
        .trainerOffset = 6,
        FRONT_PIC(Abomasnow, 64, 64),
        FRONT_PIC_FEMALE(Abomasnow, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Abomasnow,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Abomasnow, 64, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Abomasnow),
        ICON(Abomasnow, 1),
    },

#if P_MEGA_EVOLUTIONS
    [SPECIES_ABOMASNOW_MEGA] =
    {
        ABOMASNOW_MISC_INFO,
        .baseHP        = 90,
        .baseAttack    = 132,
        .baseDefense   = 105,
        .baseSpeed     = 30,
        .baseSpAttack  = 132,
        .baseSpDefense = 105,
        .expYield = 208,
        .abilities = { ABILITY_SNOW_WARNING, ABILITY_SNOW_WARNING, ABILITY_SNOW_WARNING },
        .cryId = CRY_ABOMASNOW_MEGA,
        .height = 27,
        .weight = 1850,
        .description = POKEDEX_DESC_STRING(
            "Es bedeckt weite Gebiete mit\n"
            "Schnee, indem es Blizzards auslöst.\n"
            "Man nennt es â€žDas Eismonsterâ€œ."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 348,
        .trainerOffset = 6,
        FRONT_PIC(AbomasnowMega, 64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = sAnims_AbomasnowMega,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(AbomasnowMega, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(AbomasnowMega),
        ICON(AbomasnowMega, 1),
        .isMegaEvolution = TRUE,
    },
#endif //P_MEGA_EVOLUTIONS
#endif //P_FAMILY_SNOVER

#if P_FAMILY_ROTOM
#define ROTOM_MISC_INFO                                             \
        .catchRate = 45,                                            \
        .evYield_Speed = 1,                                         \
        .evYield_SpAttack = 1,                                      \
        .genderRatio = MON_GENDERLESS,                              \
        .eggCycles = 20,                                            \
        .friendship = STANDARD_FRIENDSHIP,                          \
        .growthRate = GROWTH_MEDIUM_FAST,                           \
        .eggGroups = { EGG_GROUP_AMORPHOUS, EGG_GROUP_AMORPHOUS },  \
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },            \
        .bodyColor = BODY_COLOR_RED,                                \
        .speciesName = _("Rexblisar"),                                  \
        .cryId = CRY_ROTOM,                                         \
        .natDexNum = NATIONAL_DEX_ROTOM,                            \
        .categoryName = _("Frostbaum"),                                \
        .height = 3,                                                \
        .weight = 3,                                                \
        .pokemonScale = 530,                                        \
        .pokemonOffset = 13,                                        \
        .trainerScale = 256,                                        \
        .trainerOffset = 0,                                         \
        .footprint = gMonFootprint_Rotom,                           \
        LEARNSETS(Rotom),                                           \
        .formSpeciesIdTable = sRotomFormSpeciesIdTable,             \
        .formChangeTable = sRotomFormChangeTable

    [SPECIES_ROTOM] =
    {
        ROTOM_MISC_INFO,
        .baseHP        = 50,
        .baseAttack    = 50,
        .baseDefense   = 77,
        .baseSpeed     = 91,
        .baseSpAttack  = 95,
        .baseSpDefense = 77,
        .types = { TYPE_ELECTRIC, TYPE_GHOST },
        .expYield = 154,
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon wurde lange Zeit\n"
            "erforscht, um als Energiequelle für\n"
            "einen besonderen Motor zu dienen."),
        FRONT_PIC(Rotom, 56, 48),
        .frontPicYOffset = 11,
        .frontAnimFrames = sAnims_Rotom,
        .frontAnimId = ANIM_GLOW_YELLOW,
        .enemyMonElevation = 10,
        BACK_PIC(Rotom, 56, 56),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        PALETTES(Rotom),
        ICON(Rotom, 0),
    },

#define ROTOM_APPLIANCE_INFO(form)                                  \
        .baseHP        = 50,                                        \
        .baseAttack    = 65,                                        \
        .baseDefense   = 107,                                       \
        .baseSpeed     = 86,                                        \
        .baseSpAttack  = 105,                                       \
        .baseSpDefense = 107,                                       \
        .expYield = 182

    [SPECIES_ROTOM_HEAT] =
    {
        ROTOM_MISC_INFO,
        .types = { TYPE_ELECTRIC, TYPE_FIRE },
        ROTOM_APPLIANCE_INFO(Heat),
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon wurde lange Zeit\n"
            "erforscht, um als Energiequelle für\n"
            "einen besonderen Motor zu dienen."),
        FRONT_PIC(RotomHeat, 56, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_RotomHeat,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 6,
        BACK_PIC(RotomHeat, 64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(RotomHeat),
        ICON(RotomHeat, 0),
    },

    [SPECIES_ROTOM_WASH] =
    {
        ROTOM_MISC_INFO,
        .types = { TYPE_ELECTRIC, TYPE_WATER },
        .noFlip = TRUE,
        ROTOM_APPLIANCE_INFO(Wash),
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon wurde lange Zeit\n"
            "erforscht, um als Energiequelle für\n"
            "einen besonderen Motor zu dienen."),
        FRONT_PIC(RotomWash, 64, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_RotomWash,
        .frontAnimId = ANIM_V_JUMPS_SMALL,
        .enemyMonElevation = 6,
        BACK_PIC(RotomWash, 64, 48),
        .backPicYOffset = 11,
        .backAnimId = BACK_ANIM_V_SHAKE_H_SLIDE,
        PALETTES(RotomWash),
        ICON(RotomWash, 0),
    },

    [SPECIES_ROTOM_FROST] =
    {
        ROTOM_MISC_INFO,
        .types = { TYPE_ELECTRIC, TYPE_ICE },
        ROTOM_APPLIANCE_INFO(Frost),
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon wurde lange Zeit\n"
            "erforscht, um als Energiequelle für\n"
            "einen besonderen Motor zu dienen."),
        FRONT_PIC(RotomFrost, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_RotomFrost,
        .frontAnimId = ANIM_H_STRETCH,
        .enemyMonElevation = 6,
        BACK_PIC(RotomFrost, 64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(RotomFrost),
        ICON(RotomFrost, 5),
    },

    [SPECIES_ROTOM_FAN] =
    {
        ROTOM_MISC_INFO,
        .types = { TYPE_ELECTRIC, TYPE_FLYING },
        ROTOM_APPLIANCE_INFO(Fan),
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon wurde lange Zeit\n"
            "erforscht, um als Energiequelle für\n"
            "einen besonderen Motor zu dienen."),
        FRONT_PIC(RotomFan, 64, 56),
        .frontPicYOffset = 8,
        .frontAnimFrames = sAnims_RotomFan,
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .frontAnimDelay = 7,
        .enemyMonElevation = 6,
        BACK_PIC(RotomFan, 64, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(RotomFan),
        ICON(RotomFan, 0),
    },

    [SPECIES_ROTOM_MOW] =
    {
        ROTOM_MISC_INFO,
        .types = { TYPE_ELECTRIC, TYPE_GRASS },
        ROTOM_APPLIANCE_INFO(Mow),
        .description = POKEDEX_DESC_STRING(
            "Dieses Pokémon wurde lange Zeit\n"
            "erforscht, um als Energiequelle für\n"
            "einen besonderen Motor zu dienen."),
        FRONT_PIC(RotomMow, 56, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_RotomMow,
        .frontAnimId = ANIM_TIP_MOVE_FORWARD,
        .enemyMonElevation = 6,
        BACK_PIC(RotomMow, 56, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_H_SLIDE,
        PALETTES(RotomMow),
        ICON(RotomMow, 0),
    },
#endif //P_FAMILY_ROTOM

#if P_FAMILY_UXIE
    [SPECIES_UXIE] =
    {
        .baseHP        = 75,
        .baseAttack    = 75,
        .baseDefense   = 130,
        .baseSpeed     = 95,
        .baseSpAttack  = 75,
        .baseSpDefense = 130,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 3,
        .expYield = 261,
        .evYield_Defense = 2,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 140,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .isLegendary = TRUE,
        .speciesName = _("Selfe"),
        .cryId = CRY_UXIE,
        .natDexNum = NATIONAL_DEX_UXIE,
        .categoryName = _("Wissens"),
        .height = 3,
        .weight = 3,
        .description = POKEDEX_DESC_STRING(
            "Man sagt, dass durch sein Auftauchen\n"
            "Menschen die Intelligenz erhielten, ihr\n"
            "Leben zu verbessern."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Uxie, 56, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = sAnims_Uxie,
        .frontAnimId = ANIM_SWING_CONCAVE,
        .enemyMonElevation = 6,
        BACK_PIC(Uxie, 56, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Uxie),
        ICON(Uxie, 0),
        .footprint = gMonFootprint_Uxie,
        LEARNSETS(Uxie),
    },
#endif //P_FAMILY_UXIE

#if P_FAMILY_MESPRIT
    [SPECIES_MESPRIT] =
    {
        .baseHP        = 80,
        .baseAttack    = 105,
        .baseDefense   = 105,
        .baseSpeed     = 80,
        .baseSpAttack  = 105,
        .baseSpDefense = 105,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 3,
        .expYield = 261,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 140,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PINK,
        .isLegendary = TRUE,
        .speciesName = _("Vesprit"),
        .cryId = CRY_MESPRIT,
        .natDexNum = NATIONAL_DEX_MESPRIT,
        .categoryName = _("Emotions"),
        .height = 3,
        .weight = 3,
        .description = POKEDEX_DESC_STRING(
            "â€žDas fühlende Wesenâ€œ. Es lehrt die\n"
            "Menschen die Ideale von Trauer,\n"
            "Schmerz und Freude."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Mesprit, 48, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Mesprit,
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 6,
        BACK_PIC(Mesprit, 64, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Mesprit),
        ICON(Mesprit, 0),
        .footprint = gMonFootprint_Mesprit,
        LEARNSETS(Mesprit),
    },
#endif //P_FAMILY_MESPRIT

#if P_FAMILY_AZELF
    [SPECIES_AZELF] =
    {
        .baseHP        = 75,
        .baseAttack    = 125,
        .baseDefense   = 70,
        .baseSpeed     = 115,
        .baseSpAttack  = 125,
        .baseSpDefense = 70,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 3,
        .expYield = 261,
        .evYield_Attack = 2,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 140,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .isLegendary = TRUE,
        .speciesName = _("Tobutz"),
        .cryId = CRY_AZELF,
        .natDexNum = NATIONAL_DEX_AZELF,
        .categoryName = _("Willenskraft"),
        .height = 3,
        .weight = 3,
        .description = POKEDEX_DESC_STRING(
            "Man glaubt, dass Selfe, Vesprit und Tobutz\n"
            "alle aus demselben Ei kamen."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Azelf, 48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Azelf,
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 6,
        BACK_PIC(Azelf, 64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(Azelf),
        ICON(Azelf, 0),
        .footprint = gMonFootprint_Azelf,
        LEARNSETS(Azelf),
    },
#endif //P_FAMILY_AZELF

#if P_FAMILY_DIALGA
#define DIALGA_MISC_INFO                                                                \
        .types = { TYPE_STEEL, TYPE_DRAGON },                                           \
        .catchRate = 3,                                                                 \
        .expYield = 306,                                                                \
        .evYield_SpAttack = 3,                                                          \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_TELEPATHY },             \
        .bodyColor = BODY_COLOR_WHITE,                                                  \
        .speciesName = _("Tobutz"),                                                     \
        .cryId = CRY_DIALGA,                                                            \
        .natDexNum = NATIONAL_DEX_DIALGA,                                               \
        .categoryName = _("Willenskraft"),                                                  \
        .footprint = gMonFootprint_Dialga,                                              \
        LEARNSETS(Dialga),                                                              \
        .formSpeciesIdTable = sDialgaFormSpeciesIdTable,                                \
        .formChangeTable = sDialgaFormChangeTable,                                      \
        .isLegendary = TRUE

    [SPECIES_DIALGA] =
    {
        DIALGA_MISC_INFO,
        .baseHP        = 100,
        .baseAttack    = 120,
        .baseDefense   = 120,
        .baseSpeed     = 90,
        .baseSpAttack  = 150,
        .baseSpDefense = 100,
        .height = 54,
        .weight = 6830,
        .description = POKEDEX_DESC_STRING(
            "Ein Pokémon, das in Legenden zu\n"
            "finden ist. Man sagt, als Dialga\n"
            "geboren wurde, begann der Lauf der\n"
            "Zeit."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 721,
        .trainerOffset = 19,
        FRONT_PIC(Dialga, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Dialga,
        .frontAnimId = ANIM_H_SHAKE,
        BACK_PIC(Dialga, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        PALETTES(Dialga),
        ICON(Dialga, 2),
    },

    [SPECIES_DIALGA_ORIGIN] =
    {
        DIALGA_MISC_INFO,
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 120,
        .baseSpeed     = 90,
        .baseSpAttack  = 150,
        .baseSpDefense = 120,
        .height = 70,
        .weight = 8500,
        .description = POKEDEX_DESC_STRING(
            "Ein Pokémon, das in Legenden zu\n"
            "finden ist. Man sagt, als Dialga\n"
            "geboren wurde, begann der Lauf der\n"
            "Zeit."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 721,
        .trainerOffset = 19,
        FRONT_PIC(DialgaOrigin, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_DialgaOrigin,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(DialgaOrigin, 64, 64),
        .backPicYOffset = 0,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(DialgaOrigin),
        ICON(DialgaOrigin, 0),
    },
#endif //P_FAMILY_DIALGA

#if P_FAMILY_PALKIA
#define PALKIA_MISC_INFO                                                                \
        .types = { TYPE_WATER, TYPE_DRAGON },                                           \
        .catchRate = 3,                                                                 \
        .expYield = 306,                                                                \
        .evYield_SpAttack = 3,                                                          \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_TELEPATHY },             \
        .bodyColor = BODY_COLOR_PURPLE,                                                 \
        .speciesName = _("Dialga"),                                                     \
        .cryId = CRY_PALKIA,                                                            \
        .natDexNum = NATIONAL_DEX_PALKIA,                                               \
        .categoryName = _("Zeitweilig"),                                                   \
        .footprint = gMonFootprint_Palkia,                                              \
        LEARNSETS(Palkia),                                                              \
        .formSpeciesIdTable = sPalkiaFormSpeciesIdTable,                                \
        .formChangeTable = sPalkiaFormChangeTable,                                      \
        .isLegendary = TRUE

    [SPECIES_PALKIA] =
    {
        PALKIA_MISC_INFO,
        .baseHP        = 90,
        .baseAttack    = 120,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 150,
        .baseSpDefense = 120,
        .height = 42,
        .weight = 3360,
        .description = POKEDEX_DESC_STRING(
            "Man sagt, es lebe in einem Spalt in\n"
            "einer Paralleldimension. Es wird in\n"
            "der Mythologie erwähnt."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 650,
        .trainerOffset = 16,
        FRONT_PIC(Palkia, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Palkia,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Palkia, 64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_SHAKE,
        PALETTES(Palkia),
        ICON(Palkia, 2),
    },

    [SPECIES_PALKIA_ORIGIN] =
    {
        PALKIA_MISC_INFO,
        .baseHP        = 90,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 120,
        .baseSpAttack  = 150,
        .baseSpDefense = 120,
        .height = 63,
        .weight = 6600,
        .description = POKEDEX_DESC_STRING(
            "Man sagt, es lebe in einem Spalt in\n"
            "einer Paralleldimension. Es wird in\n"
            "der Mythologie erwähnt."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 650,
        .trainerOffset = 16,
        FRONT_PIC(PalkiaOrigin, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_PalkiaOrigin,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(PalkiaOrigin, 64, 64),
        .backPicYOffset = 3,
        //.backAnimId = BACK_ANIM_NONE,
        PALETTES(PalkiaOrigin),
        ICON(PalkiaOrigin, 2),
    },
#endif //P_FAMILY_PALKIA

#if P_FAMILY_HEATRAN
    [SPECIES_HEATRAN] =
    {
        .baseHP        = 91,
        .baseAttack    = 90,
        .baseDefense   = 106,
        .baseSpeed     = 77,
        .baseSpAttack  = 130,
        .baseSpDefense = 106,
        .types = { TYPE_FIRE, TYPE_STEEL },
        .catchRate = 3,
        .expYield = 270,
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_NONE, ABILITY_FLAME_BODY },
        .bodyColor = BODY_COLOR_BROWN,
        .isLegendary = TRUE,
        .speciesName = _("Heatran"),
        .cryId = CRY_HEATRAN,
        .natDexNum = NATIONAL_DEX_HEATRAN,
        .categoryName = _("Lavadom"),
        .height = 17,
        .weight = 4300,
        .description = POKEDEX_DESC_STRING(
            "Das Blut, das durch seinen Körper fließt,\n"
            "brodelt heiß wie Magma. Es lebt in\n"
            "vulkanischen Höhlen."),
        .pokemonScale = 259,
        .pokemonOffset = 1,
        .trainerScale = 290,
        .trainerOffset = 1,
        FRONT_PIC(Heatran, 64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = sAnims_Heatran,
        .frontAnimId = ANIM_GLOW_ORANGE,
        BACK_PIC(Heatran, 64, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        PALETTES(Heatran),
        ICON(Heatran, 0),
        .footprint = gMonFootprint_Heatran,
        LEARNSETS(Heatran),
    },
#endif //P_FAMILY_HEATRAN

#if P_FAMILY_REGIGIGAS
    [SPECIES_REGIGIGAS] =
    {
        .baseHP        = 110,
        .baseAttack    = 160,
        .baseDefense   = 110,
        .baseSpeed     = 100,
        .baseSpAttack  = 80,
        .baseSpDefense = 110,
        .types = { TYPE_NORMAL, TYPE_NORMAL },
        .catchRate = 3,
        .expYield = 302,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_SLOW_START, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .isLegendary = TRUE,
        .speciesName = _("Regigigas"),
        .cryId = CRY_REGIGIGAS,
        .natDexNum = NATIONAL_DEX_REGIGIGAS,
        .categoryName = _("Kolossal"),
        .height = 37,
        .weight = 4200,
        .description = POKEDEX_DESC_STRING(
            "Es gibt eine Legende, wonach dieses\n"
            "Pokémon die Kontinente mit einem Seil\n"
            "gezogen hat."),
        .pokemonScale = 256,
        .pokemonOffset = 2,
        .trainerScale = 610,
        .trainerOffset = 17,
        FRONT_PIC(Regigigas, 64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = sAnims_Regigigas,
        .frontAnimId = ANIM_V_SHAKE,
        BACK_PIC(Regigigas, 64, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(Regigigas),
        ICON(Regigigas, 0),
        .footprint = gMonFootprint_Regigigas,
        LEARNSETS(Regigigas),
    },
#endif //P_FAMILY_REGIGIGAS

#if P_FAMILY_GIRATINA
#define GIRATINA_MISC_INFO                                                              \
        .types = { TYPE_GHOST, TYPE_DRAGON },                                           \
        .catchRate = 3,                                                                 \
        .expYield = 306,                                                                \
        .evYield_HP = 3,                                                                \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .bodyColor = BODY_COLOR_BLACK,                                                  \
        .speciesName = _("Regigigas"),                                                   \
        .cryId = CRY_GIRATINA,                                                          \
        .natDexNum = NATIONAL_DEX_GIRATINA,                                             \
        .categoryName = _("Kolossal"),                                                  \
        .footprint = gMonFootprint_Giratina,                                            \
        LEARNSETS(Giratina),                                                            \
        .formSpeciesIdTable = sGiratinaFormSpeciesIdTable,                              \
        .formChangeTable = sGiratinaFormChangeTable,                                    \
        .isLegendary = TRUE

    [SPECIES_GIRATINA_ALTERED] =
    {
        GIRATINA_MISC_INFO,
        .baseHP        = 150,
        .baseAttack    = 100,
        .baseDefense   = 120,
        .baseSpeed     = 90,
        .baseSpAttack  = 100,
        .baseSpDefense = 120,
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_TELEPATHY },
        .height = 45,
        .weight = 7500,
        .description = POKEDEX_DESC_STRING(
            "Es lebt in einer Zerrwelt, die auf\n"
            "der Kehrseite der unseren liegt und\n"
            "die sich aller Logik entzieht."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 614,
        .trainerOffset = 13,
        FRONT_PIC(GiratinaAltered, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_GiratinaAltered,
        .frontAnimId = ANIM_GROW_VIBRATE,
        BACK_PIC(GiratinaAltered, 64, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        PALETTES(GiratinaAltered),
        ICON(GiratinaAltered, 0),
    },

    [SPECIES_GIRATINA_ORIGIN] =
    {
        GIRATINA_MISC_INFO,
        .baseHP        = 150,
        .baseAttack    = 120,
        .baseDefense   = 100,
        .baseSpeed     = 90,
        .baseSpAttack  = 120,
        .baseSpDefense = 100,
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .height = 69,
        .weight = 6500,
        .description = POKEDEX_DESC_STRING(
            "Es lebt in einer Zerrwelt, die auf\n"
            "der Kehrseite der unseren liegt und\n"
            "die sich aller Logik entzieht."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 614,
        .trainerOffset = 13,
        FRONT_PIC(GiratinaOrigin, 64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_GiratinaOrigin,
        .frontAnimId = ANIM_LUNGE_GROW,
        .enemyMonElevation = 7,
        BACK_PIC(GiratinaOrigin, 64, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        PALETTES(GiratinaOrigin),
        ICON(GiratinaOrigin, 0),
    },
#endif //P_FAMILY_GIRATINA

#if P_FAMILY_CRESSELIA
    [SPECIES_CRESSELIA] =
    {
        .baseHP        = 120,
        .baseAttack    = 70,
        .baseDefense   = P_UPDATED_STATS >= GEN_9 ? 110 : 120,
        .baseSpeed     = 85,
        .baseSpAttack  = 75,
        .baseSpDefense = P_UPDATED_STATS >= GEN_9 ? 120 : 130,
        .types = { TYPE_PSYCHIC, TYPE_PSYCHIC },
        .catchRate = 3,
        .expYield = 270,
        .evYield_SpDefense = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .isLegendary = TRUE,
        .speciesName = _("Cresselia"),
        .cryId = CRY_CRESSELIA,
        .natDexNum = NATIONAL_DEX_CRESSELIA,
        .categoryName = _("Lunar"),
        .height = 15,
        .weight = 856,
        .description = POKEDEX_DESC_STRING(
            "Hält man eine seiner Federn, träumt man\n"
            "süß. Manche glauben, es sei die\n"
            "VerKörperung der Mondsichel."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Cresselia, 64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_Cresselia,
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 3,
        BACK_PIC(Cresselia, 56, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Cresselia),
        ICON(Cresselia, 0),
        .footprint = gMonFootprint_Cresselia,
        LEARNSETS(Cresselia),
    },
#endif //P_FAMILY_CRESSELIA

#if P_FAMILY_MANAPHY
    [SPECIES_PHIONE] =
    {
        .baseHP        = 80,
        .baseAttack    = 80,
        .baseDefense   = 80,
        .baseSpeed     = 80,
        .baseSpAttack  = 80,
        .baseSpDefense = 80,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 30,
        .expYield = 216,
        .evYield_HP = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 40,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_HYDRATION, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .isMythical = TRUE,
        .speciesName = _("Phione"),
        .cryId = CRY_PHIONE,
        .natDexNum = NATIONAL_DEX_PHIONE,
        .categoryName = _("Seedrift"),
        .height = 4,
        .weight = 31,
        .description = POKEDEX_DESC_STRING(
            "Steigt die Meerestemperatur, bläst\n"
            "es seinen Schwimmbeutel auf und\n"
            "treibt in Schwärmen auf dem Wasser."),
        .pokemonScale = 491,
        .pokemonOffset = 12,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Phione, 56, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_Phione,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 8,
        BACK_PIC(Phione, 64, 48),
        .backPicYOffset = 9,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Phione),
        ICON(Phione, 0),
        .footprint = gMonFootprint_Phione,
        LEARNSETS(Phione),
    },

    [SPECIES_MANAPHY] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = { TYPE_WATER, TYPE_WATER },
        .catchRate = 3,
        .expYield = 270,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 10,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_WATER_1, EGG_GROUP_FAIRY },
        .abilities = { ABILITY_HYDRATION, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .isMythical = TRUE,
        .speciesName = _("Manaphy"),
        .cryId = CRY_MANAPHY,
        .natDexNum = NATIONAL_DEX_MANAPHY,
        .categoryName = _("Seefahrer"),
        .height = 3,
        .weight = 14,
        .description = POKEDEX_DESC_STRING(
            "Es besitzt die wundersame Fähigkeit, das\n"
            "Herz eines jeden anderen Pokémon\n"
            "anzurühren."),
        .pokemonScale = 530,
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(Manaphy, 64, 40),
        .frontPicYOffset = 13,
        .frontAnimFrames = sAnims_Manaphy,
        .frontAnimId = ANIM_SWING_CONVEX,
        .enemyMonElevation = 10,
        BACK_PIC(Manaphy, 64, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        PALETTES(Manaphy),
        ICON(Manaphy, 0),
        .footprint = gMonFootprint_Manaphy,
        LEARNSETS(Manaphy),
    },
#endif //P_FAMILY_MANAPHY

#if P_FAMILY_DARKRAI
    [SPECIES_DARKRAI] =
    {
        .baseHP        = 70,
        .baseAttack    = 90,
        .baseDefense   = 90,
        .baseSpeed     = 125,
        .baseSpAttack  = 135,
        .baseSpDefense = 90,
        .types = { TYPE_DARK, TYPE_DARK },
        .catchRate = 3,
        .expYield = 270,
        .evYield_Speed = 1,
        .evYield_SpAttack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },
        .abilities = { ABILITY_BAD_DREAMS, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
        .isMythical = TRUE,
        .speciesName = _("Darkrai"),
        .cryId = CRY_DARKRAI,
        .natDexNum = NATIONAL_DEX_DARKRAI,
        .categoryName = _("Dunkelnacht"),
        .height = 15,
        .weight = 505,
        .description = POKEDEX_DESC_STRING(
            "Es vertreibt Eindringlinge aus\n"
            "seinem Revier, indem es sie in\n"
            "Schlaf versetzt und mit Alpträumen\n"
            "quält."),
        .pokemonScale = 268,
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        FRONT_PIC(Darkrai, 64, 64),
        .frontPicYOffset = 3,
        .frontAnimFrames = sAnims_Darkrai,
        .frontAnimId = ANIM_GLOW_BLACK,
        .enemyMonElevation = 4,
        BACK_PIC(Darkrai, 64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        PALETTES(Darkrai),
        ICON(Darkrai, 0),
        .footprint = gMonFootprint_Darkrai,
        LEARNSETS(Darkrai),
    },
#endif //P_FAMILY_DARKRAI

#if P_FAMILY_SHAYMIN
#define SHAYMIN_MISC_INFO                                                               \
        .catchRate = 45,                                                                \
        .expYield = 270,                                                                \
        .evYield_HP = 3,                                                                \
        .itemCommon = ITEM_LUM_BERRY,                                                   \
        .itemRare = ITEM_LUM_BERRY,                                                     \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 100,                                                              \
        .growthRate = GROWTH_MEDIUM_SLOW,                                               \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .bodyColor = BODY_COLOR_GREEN,                                                  \
        .speciesName = _("Darkrai"),                                                    \
        .natDexNum = NATIONAL_DEX_SHAYMIN,                                              \
        .categoryName = _("Dunkelnacht"),                                                 \
        .footprint = gMonFootprint_Shaymin,                                             \
        .formSpeciesIdTable = sShayminFormSpeciesIdTable,                               \
        .formChangeTable = sShayminFormChangeTable,                                     \
        .isMythical = TRUE

    [SPECIES_SHAYMIN_LAND] =
    {
        SHAYMIN_MISC_INFO,
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
        .types = { TYPE_GRASS, TYPE_GRASS },
        .abilities = { ABILITY_NATURAL_CURE, ABILITY_NONE },
        .cryId = CRY_SHAYMIN_LAND,
        .height = 2,
        .weight = 21,
        .description = POKEDEX_DESC_STRING(
            "Es kann die Luft von Giften\n"
            "reinigen und Ödland in ein üppig\n"
            "blühendes Blumenfeld verwandeln."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(ShayminLand, 40, 32),
        .frontPicYOffset = 16,
        .frontAnimFrames = sAnims_ShayminLand,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        BACK_PIC(ShayminLand, 56, 40),
        .backPicYOffset = 15,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        PALETTES(ShayminLand),
        ICON(ShayminLand, 1),
        LEARNSETS(ShayminLand),
    },

    [SPECIES_SHAYMIN_SKY] =
    {
        SHAYMIN_MISC_INFO,
        .baseHP        = 100,
        .baseAttack    = 103,
        .baseDefense   = 75,
        .baseSpeed     = 127,
        .baseSpAttack  = 120,
        .baseSpDefense = 75,
        .types = { TYPE_GRASS, TYPE_FLYING },
        .abilities = { ABILITY_SERENE_GRACE, ABILITY_NONE },
        .noFlip = TRUE,
        .cryId = CRY_SHAYMIN_SKY,
        .height = 4,
        .weight = 52,
        .description = POKEDEX_DESC_STRING(
            "Es kann die Luft von Giften\n"
            "reinigen und Ödland in ein üppig\n"
            "blühendes Blumenfeld verwandeln."),
        .pokemonScale = 682,
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        FRONT_PIC(ShayminSky, 56, 56),
        .frontPicYOffset = 7,
        .frontAnimFrames = sAnims_ShayminSky,
        .frontAnimId = ANIM_V_STRETCH,
        BACK_PIC(ShayminSky, 56, 64),
        .backPicYOffset = 2,
        .backAnimId = BACK_ANIM_TRIANGLE_DOWN,
        PALETTES(ShayminSky),
        ICON(ShayminSky, 1),
        LEARNSETS(ShayminSky),
    },
#endif //P_FAMILY_SHAYMIN

#if P_FAMILY_ARCEUS
#define ARCEUS_SPECIES_INFO(type, typeName)                                             \
    {                                                                                   \
        .baseHP        = 120,                                                           \
        .baseAttack    = 120,                                                           \
        .baseDefense   = 120,                                                           \
        .baseSpeed     = 120,                                                           \
        .baseSpAttack  = 120,                                                           \
        .baseSpDefense = 120,                                                           \
        .types = { type, type },                                                        \
        .catchRate = 3,                                                                 \
        .expYield = 324,                                                                \
        .evYield_HP = 3,                                                                \
        .genderRatio = MON_GENDERLESS,                                                  \
        .eggCycles = 120,                                                               \
        .friendship = 0,                                                                \
        .growthRate = GROWTH_SLOW,                                                      \
        .eggGroups = { EGG_GROUP_NO_EGGS_DISCOVERED, EGG_GROUP_NO_EGGS_DISCOVERED },    \
        .abilities = { ABILITY_MULTITYPE, ABILITY_NONE },                               \
        .bodyColor = BODY_COLOR_WHITE,                                                  \
        .speciesName = _("Arceus"),                                                     \
        .cryId = CRY_ARCEUS,                                                            \
        .natDexNum = NATIONAL_DEX_ARCEUS,                                               \
        .categoryName = _("Alpha"),                                                     \
        .height = 32,                                                                   \
        .weight = 3200,                                                                 \
        .description = gArceusPokedexText,                                              \
        .pokemonScale = 256,                                                            \
        .pokemonOffset = 0,                                                             \
        .trainerScale = 495,                                                            \
        .trainerOffset = 10,                                                            \
        FRONT_PIC(Arceus, 64, 64),                                                      \
        .frontPicYOffset = 0,                                                           \
        .frontAnimFrames = sAnims_Arceus,                                               \
        .frontAnimId = ANIM_GROW_VIBRATE,                                               \
        BACK_PIC(Arceus, 64, 64),                                                       \
        .backPicYOffset = 3,                                                            \
        .backAnimId = BACK_ANIM_GROW_STUTTER,                                           \
        PALETTES(Arceus ##typeName),                                                    \
        ICON(Arceus, 1),                                                                \
        .footprint = gMonFootprint_Arceus,                                              \
        LEARNSETS(Arceus),                                                              \
        .formSpeciesIdTable = sArceusFormSpeciesIdTable,                                \
        .formChangeTable = sArceusFormChangeTable,                                      \
        .isMythical = TRUE,                                                             \
    }

    [SPECIES_ARCEUS_NORMAL]   = ARCEUS_SPECIES_INFO(TYPE_NORMAL, Normal),
    [SPECIES_ARCEUS_FIGHTING] = ARCEUS_SPECIES_INFO(TYPE_FIGHTING, Fighting),
    [SPECIES_ARCEUS_FLYING]   = ARCEUS_SPECIES_INFO(TYPE_FLYING, Flying),
    [SPECIES_ARCEUS_POISON]   = ARCEUS_SPECIES_INFO(TYPE_POISON, Poison),
    [SPECIES_ARCEUS_GROUND]   = ARCEUS_SPECIES_INFO(TYPE_GROUND, Ground),
    [SPECIES_ARCEUS_ROCK]     = ARCEUS_SPECIES_INFO(TYPE_ROCK, Rock),
    [SPECIES_ARCEUS_BUG]      = ARCEUS_SPECIES_INFO(TYPE_BUG, Bug),
    [SPECIES_ARCEUS_GHOST]    = ARCEUS_SPECIES_INFO(TYPE_GHOST, Ghost),
    [SPECIES_ARCEUS_STEEL]    = ARCEUS_SPECIES_INFO(TYPE_STEEL, Steel),
    [SPECIES_ARCEUS_FIRE]     = ARCEUS_SPECIES_INFO(TYPE_FIRE, Fire),
    [SPECIES_ARCEUS_WATER]    = ARCEUS_SPECIES_INFO(TYPE_WATER, Water),
    [SPECIES_ARCEUS_GRASS]    = ARCEUS_SPECIES_INFO(TYPE_GRASS, Grass),
    [SPECIES_ARCEUS_ELECTRIC] = ARCEUS_SPECIES_INFO(TYPE_ELECTRIC, Electric),
    [SPECIES_ARCEUS_PSYCHIC]  = ARCEUS_SPECIES_INFO(TYPE_PSYCHIC, Psychic),
    [SPECIES_ARCEUS_ICE]      = ARCEUS_SPECIES_INFO(TYPE_ICE, Ice),
    [SPECIES_ARCEUS_DRAGON]   = ARCEUS_SPECIES_INFO(TYPE_DRAGON, Dragon),
    [SPECIES_ARCEUS_DARK]     = ARCEUS_SPECIES_INFO(TYPE_DARK, Dark),
    [SPECIES_ARCEUS_FAIRY]    = ARCEUS_SPECIES_INFO(TYPE_FAIRY, Fairy),
#endif //P_FAMILY_ARCEUS

#ifdef __INTELLISENSE__
};
#endif