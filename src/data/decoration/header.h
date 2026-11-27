const struct Decoration gDecorations[] =
{
    [DECOR_NONE] =
    {
        .id = DECOR_NONE,
        .name = _("KLEINER TISCH"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DESK,
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein kleiner Tisch\n"
            "für eine Person."),
        .tiles = DecorGfx_SMALL_DESK,
        .icon = {gItemIcon_QuestionMark, gItemIconPalette_QuestionMark},
    },

    [DECOR_SMALL_DESK] =
    {
        .id = DECOR_SMALL_DESK,
        .name = _("KLEINER TISCH"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DESK,
        .price = 3000,
        .description = COMPOUND_STRING(
            "Ein kleiner Tisch\n"
            "für eine Person."),
        .tiles = DecorGfx_SMALL_DESK,
        .icon = {NULL, NULL},
    },

    [DECOR_POKEMON_DESK] =
    {
        .id = DECOR_POKEMON_DESK,
        .name = _("POKéMON-TISCH"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DESK,
        .price = 3000,
        .description = COMPOUND_STRING(
            "Ein kleiner Tisch\n"
            "in Form eines\n"
            "POKéBALLS."),
        .tiles = DecorGfx_POKEMON_DESK,
        .icon = {NULL, NULL},
    },

    [DECOR_HEAVY_DESK] =
    {
        .id = DECOR_HEAVY_DESK,
        .name = _("STAHLTISCH"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x2,
        .category = DECORCAT_DESK,
        .price = 6000,
        .description = COMPOUND_STRING(
            "Ein großer Tisch\n"
            "aus Stahl. Stelle\n"
            "Deko darauf."),
        .tiles = DecorGfx_HEAVY_DESK,
        .icon = {gDecorIcon_HeavyDesk, gDecorIconPalette_HeavyDesk},
    },

    [DECOR_RAGGED_DESK] =
    {
        .id = DECOR_RAGGED_DESK,
        .name = _("HOLZTISCH"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x2,
        .category = DECORCAT_DESK,
        .price = 6000,
        .description = COMPOUND_STRING(
            "Ein großer Tisch\n"
            "aus Holz. Stelle\n"
            "Deko darauf."),
        .tiles = DecorGfx_RAGGED_DESK,
        .icon = {gDecorIcon_RaggedDesk, gDecorIconPalette_RaggedDesk},
    },

    [DECOR_COMFORT_DESK] =
    {
        .id = DECOR_COMFORT_DESK,
        .name = _("BLATTTISCH"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x2,
        .category = DECORCAT_DESK,
        .price = 6000,
        .description = COMPOUND_STRING(
            "Ein großer Tisch\n"
            "aus Blättern. Stelle\n"
            "Deko darauf."),
        .tiles = DecorGfx_COMFORT_DESK,
        .icon = {gDecorIcon_ComfortDesk, gDecorIconPalette_ComfortDesk},
    },

    [DECOR_PRETTY_DESK] =
    {
        .id = DECOR_PRETTY_DESK,
        .name = _("GLASTISCH"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_DESK,
        .price = 9000,
        .description = COMPOUND_STRING(
            "Ein riesiger Tisch\n"
            "aus Glas. Bietet\n"
            "viel Platz für Deko."),
        .tiles = DecorGfx_PRETTY_DESK,
        .icon = {gDecorIcon_PrettyDesk, gDecorIconPalette_PrettyDesk},
    },

    [DECOR_BRICK_DESK] =
    {
        .id = DECOR_BRICK_DESK,
        .name = _("ZIEGELTISCH"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_DESK,
        .price = 9000,
        .description = COMPOUND_STRING(
            "Ein riesiger Tisch\n"
            "aus Ziegeln. Bietet\n"
            "viel Platz für Deko."),
        .tiles = DecorGfx_BRICK_DESK,
        .icon = {gDecorIcon_BrickDesk, gDecorIconPalette_BrickDesk},
    },

    [DECOR_CAMP_DESK] =
    {
        .id = DECOR_CAMP_DESK,
        .name = _("BLOCKTISCH"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_DESK,
        .price = 9000,
        .description = COMPOUND_STRING(
            "Ein riesiger Tisch\n"
            "aus Baumstämmen.\n"
            "Viel Platz für Deko."),
        .tiles = DecorGfx_CAMP_DESK,
        .icon = {gDecorIcon_CampDesk, gDecorIconPalette_CampDesk},
    },

    [DECOR_HARD_DESK] =
    {
        .id = DECOR_HARD_DESK,
        .name = _("FELSTISCH"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_DESK,
        .price = 9000,
        .description = COMPOUND_STRING(
            "Ein riesiger Tisch\n"
            "aus Felsen. Bietet\n"
            "viel Platz für Deko."),
        .tiles = DecorGfx_HARD_DESK,
        .icon = {gDecorIcon_HardDesk, gDecorIconPalette_HardDesk},
    },

    [DECOR_SMALL_CHAIR] =
    {
        .id = DECOR_SMALL_CHAIR,
        .name = _("KLEINER STUHL"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Ein kleiner Stuhl\n"
            "für eine Person."),
        .tiles = DecorGfx_SMALL_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_POKEMON_CHAIR] =
    {
        .id = DECOR_POKEMON_CHAIR,
        .name = _("POKéMON-STUHL"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Ein kleiner Stuhl\n"
            "in Form eines\n"
            "POKéBALLS."),
        .tiles = DecorGfx_POKEMON_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_HEAVY_CHAIR] =
    {
        .id = DECOR_HEAVY_CHAIR,
        .name = _("STAHLSTUHL"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Ein kleiner Stuhl\n"
            "aus Stahl."),
        .tiles = DecorGfx_HEAVY_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_PRETTY_CHAIR] =
    {
        .id = DECOR_PRETTY_CHAIR,
        .name = _("GLASSTUHL"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Ein kleiner Stuhl\n"
            "aus Glas."),
        .tiles = DecorGfx_PRETTY_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_COMFORT_CHAIR] =
    {
        .id = DECOR_COMFORT_CHAIR,
        .name = _("BLATTSTUHL"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Ein kleiner Stuhl\n"
            "aus Blättern."),
        .tiles = DecorGfx_COMFORT_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_RAGGED_CHAIR] =
    {
        .id = DECOR_RAGGED_CHAIR,
        .name = _("HOLZSTUHL"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Ein kleiner Stuhl\n"
            "aus Holz."),
        .tiles = DecorGfx_RAGGED_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_BRICK_CHAIR] =
    {
        .id = DECOR_BRICK_CHAIR,
        .name = _("ZIEGELSTUHL"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Ein kleiner Stuhl\n"
            "aus Ziegeln."),
        .tiles = DecorGfx_BRICK_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_CAMP_CHAIR] =
    {
        .id = DECOR_CAMP_CHAIR,
        .name = _("BLOCKSTUHL"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Ein kleiner Stuhl\n"
            "aus Baumstämmen."),
        .tiles = DecorGfx_CAMP_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_HARD_CHAIR] =
    {
        .id = DECOR_HARD_CHAIR,
        .name = _("FELSSTUHL"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Ein kleiner Stuhl\n"
            "aus Stein."),
        .tiles = DecorGfx_HARD_CHAIR,
        .icon = {NULL, NULL},
    },

    [DECOR_RED_PLANT] =
    {
        .id = DECOR_RED_PLANT,
        .name = _("ROTE PFLANZE"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_PLANT,
        .price = 3000,
        .description = COMPOUND_STRING(
            "Eine leuchtend rote\n"
            "Topfpflanze."),
        .tiles = DecorGfx_RED_PLANT,
        .icon = {gDecorIcon_RedPlant, gDecorIconPalette_RedPlant},
    },

    [DECOR_TROPICAL_PLANT] =
    {
        .id = DECOR_TROPICAL_PLANT,
        .name = _("TROPENPFLANZE"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_PLANT,
        .price = 3000,
        .description = COMPOUND_STRING(
            "Eine blühende\n"
            "tropische Pflanze\n"
            "im Topf."),
        .tiles = DecorGfx_TROPICAL_PLANT,
        .icon = {gDecorIcon_TropicalPlant, gDecorIconPalette_TropicalPlant},
    },

    [DECOR_PRETTY_FLOWERS] =
    {
        .id = DECOR_PRETTY_FLOWERS,
        .name = _("SCHÖNE BLUMEN"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_PLANT,
        .price = 3000,
        .description = COMPOUND_STRING(
            "Ein Topf mit\n"
            "niedlichen Blumen."),
        .tiles = DecorGfx_PRETTY_FLOWERS,
        .icon = {gDecorIcon_PrettyFlowers, gDecorIconPalette_PrettyFlowers},
    },

    [DECOR_COLORFUL_PLANT] =
    {
        .id = DECOR_COLORFUL_PLANT,
        .name = _("BUNTE PFLANZE"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_2x2,
        .category = DECORCAT_PLANT,
        .price = 5000,
        .description = COMPOUND_STRING(
            "Ein großer Topf mit\n"
            "vielen bunten\n"
            "Blumen."),
        .tiles = DecorGfx_COLORFUL_PLANT,
        .icon = {gDecorIcon_ColorfulPlant, gDecorIconPalette_ColorfulPlant},
    },

    [DECOR_BIG_PLANT] =
    {
        .id = DECOR_BIG_PLANT,
        .name = _("GROSSE PFLANZE"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_2x2,
        .category = DECORCAT_PLANT,
        .price = 5000,
        .description = COMPOUND_STRING(
            "Eine große, schirm-\n"
            "förmige Pflanze\n"
            "im großen Topf."),
        .tiles = DecorGfx_BIG_PLANT,
        .icon = {gDecorIcon_BigPlant, gDecorIconPalette_BigPlant},
    },

    [DECOR_GORGEOUS_PLANT] =
    {
        .id = DECOR_GORGEOUS_PLANT,
        .name = _("PRACHTPFLANZE"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_2x2,
        .category = DECORCAT_PLANT,
        .price = 5000,
        .description = COMPOUND_STRING(
            "Eine große, präch-\n"
            "tige Pflanze im\n"
            "großen Topf."),
        .tiles = DecorGfx_GORGEOUS_PLANT,
        .icon = {gDecorIcon_GorgeousPlant, gDecorIconPalette_GorgeousPlant},
    },

    [DECOR_RED_BRICK] =
    {
        .id = DECOR_RED_BRICK,
        .name = _("ROTER ZIEGEL"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = COMPOUND_STRING(
            "Ein roter Ziegel.\n"
            "Darauf kann man\n"
            "Deko stellen."),
        .tiles = DecorGfx_RED_BRICK,
        .icon = {gDecorIcon_RedBrick, gDecorIconPalette_RedBrick},
    },

    [DECOR_YELLOW_BRICK] =
    {
        .id = DECOR_YELLOW_BRICK,
        .name = _("GELBER ZIEGEL"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = COMPOUND_STRING(
            "Ein gelber Ziegel.\n"
            "Stelle Deko\n"
            "darauf."),
        .tiles = DecorGfx_YELLOW_BRICK,
        .icon = {gDecorIcon_YellowBrick, gDecorIconPalette_YellowBrick},
    },

    [DECOR_BLUE_BRICK] =
    {
        .id = DECOR_BLUE_BRICK,
        .name = _("BLAUER ZIEGEL"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = COMPOUND_STRING(
            "Ein blauer Ziegel.\n"
            "Stelle Deko\n"
            "darauf."),
        .tiles = DecorGfx_BLUE_BRICK,
        .icon = {gDecorIcon_BlueBrick, gDecorIconPalette_BlueBrick},
    },

    [DECOR_RED_BALLOON] =
    {
        .id = DECOR_RED_BALLOON,
        .name = _("ROTER BALLON"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = COMPOUND_STRING(
            "Ein wassergefüllter\n"
            "roter Ballon. Platzt\n"
            "beim Drauftreten."),
        .tiles = DecorGfx_RED_BALLOON,
        .icon = {NULL, NULL},
    },

    [DECOR_BLUE_BALLOON] =
    {
        .id = DECOR_BLUE_BALLOON,
        .name = _("BLAUER BALLON"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = COMPOUND_STRING(
            "Ein wassergefüllter\n"
            "blauer Ballon. Platzt\n"
            "beim Drauftreten."),
        .tiles = DecorGfx_BLUE_BALLOON,
        .icon = {NULL, NULL},
    },

    [DECOR_YELLOW_BALLOON] =
    {
        .id = DECOR_YELLOW_BALLOON,
        .name = _("GELBER BALLON"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = COMPOUND_STRING(
            "Ein wassergefüllter\n"
            "gelber Ballon. Platzt\n"
            "beim Drauftreten."),
        .tiles = DecorGfx_YELLOW_BALLOON,
        .icon = {NULL, NULL},
    },

    [DECOR_RED_TENT] =
    {
        .id = DECOR_RED_TENT,
        .name = _("ROTES ZELT"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_ORNAMENT,
        .price = 10000,
        .description = COMPOUND_STRING(
            "Ein großes rotes\n"
            "Zelt. Man kann sich\n"
            "darin verstecken."),
        .tiles = DecorGfx_RED_TENT,
        .icon = {gDecorIcon_RedTent, gDecorIconPalette_RedTent},
    },

    [DECOR_BLUE_TENT] =
    {
        .id = DECOR_BLUE_TENT,
        .name = _("BLAUES ZELT"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_ORNAMENT,
        .price = 10000,
        .description = COMPOUND_STRING(
            "Ein großes blaues\n"
            "Zelt. Man kann sich\n"
            "darin verstecken."),
        .tiles = DecorGfx_BLUE_TENT,
        .icon = {gDecorIcon_BlueTent, gDecorIconPalette_BlueTent},
    },

    [DECOR_SOLID_BOARD] =
    {
        .id = DECOR_SOLID_BOARD,
        .name = _("STABILES BRETT"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 3000,
        .description = COMPOUND_STRING(
            "Über ein Loch legen,\n"
            "um auf die andere\n"
            "Seite zu gelangen."),
        .tiles = DecorGfx_SOLID_BOARD,
        .icon = {gDecorIcon_SolidBoard, gDecorIconPalette_SolidBoard},
    },

    [DECOR_SLIDE] =
    {
        .id = DECOR_SLIDE,
        .name = _("RUTSCHE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_2x4,
        .category = DECORCAT_ORNAMENT,
        .price = 8000,
        .description = COMPOUND_STRING(
            "Zum Hinunterrut-\n"
            "schen von der\n"
            "Plattform."),
        .tiles = DecorGfx_SLIDE,
        .icon = {gDecorIcon_Slide, gDecorIconPalette_Slide},
    },

    [DECOR_FENCE_LENGTH] =
    {
        .id = DECOR_FENCE_LENGTH,
        .name = _("ZAUN (LANG)"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = COMPOUND_STRING(
            "Ein kleiner Zaun,\n"
            "der den Weg\n"
            "versperrt."),
        .tiles = DecorGfx_FENCE_LENGTH,
        .icon = {NULL, NULL},
    },

    [DECOR_FENCE_WIDTH] =
    {
        .id = DECOR_FENCE_WIDTH,
        .name = _("ZAUN (BREIT)"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = COMPOUND_STRING(
            "Ein kleiner Zaun,\n"
            "der den Weg\n"
            "versperrt."),
        .tiles = DecorGfx_FENCE_WIDTH,
        .icon = {NULL, NULL},
    },

    [DECOR_TIRE] =
    {
        .id = DECOR_TIRE,
        .name = _("REIFEN"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_2x2,
        .category = DECORCAT_ORNAMENT,
        .price = 800,
        .description = COMPOUND_STRING(
            "Ein großer alter\n"
            "Reifen. Darauf kann\n"
            "man Deko stellen."),
        .tiles = DecorGfx_TIRE,
        .icon = {gDecorIcon_Tire, gDecorIconPalette_Tire},
    },

    [DECOR_STAND] =
    {
        .id = DECOR_STAND,
        .name = _("PODEST"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_4x2,
        .category = DECORCAT_ORNAMENT,
        .price = 7000,
        .description = COMPOUND_STRING(
            "Ein großes Podest\n"
            "mit Stufen."),
        .tiles = DecorGfx_STAND,
        .icon = {gDecorIcon_Stand, gDecorIconPalette_Stand},
    },

    [DECOR_MUD_BALL] =
    {
        .id = DECOR_MUD_BALL,
        .name = _("SCHLAMMBALL"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 200,
        .description = COMPOUND_STRING(
            "Ein großer Ball aus\n"
            "Schlamm. Zerfällt,\n"
            "wenn man drauftritt."),
        .tiles = DecorGfx_MUD_BALL,
        .icon = {NULL, NULL},
    },

    [DECOR_BREAKABLE_DOOR] =
    {
        .id = DECOR_BREAKABLE_DOOR,
        .name = _("BRECHTÜR"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 3000,
        .description = COMPOUND_STRING(
            "Eine seltsame Tür,\n"
            "durch die man\n"
            "einfach gehen kann."),
        .tiles = DecorGfx_BREAKABLE_DOOR,
        .icon = {gDecorIcon_BreakableDoor, gDecorIconPalette_BreakableDoor},
    },

    [DECOR_SAND_ORNAMENT] =
    {
        .id = DECOR_SAND_ORNAMENT,
        .name = _("SANDFIGUR"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 3000,
        .description = COMPOUND_STRING(
            "Eine Figur aus\n"
            "Sand. Zerfällt bei\n"
            "Berührung."),
        .tiles = DecorGfx_SAND_ORNAMENT,
        .icon = {gDecorIcon_SandOrnament, gDecorIconPalette_SandOrnament},
    },

    [DECOR_SILVER_SHIELD] =
    {
        .id = DECOR_SILVER_SHIELD,
        .name = _("SILBERSCHILD"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 0,
        .description = COMPOUND_STRING(
            "Für 50 Siege in\n"
            "Folge im KAMPF-\n"
            "TURM verliehen."),
        .tiles = DecorGfx_SILVER_SHIELD,
        .icon = {NULL, NULL},
    },

    [DECOR_GOLD_SHIELD] =
    {
        .id = DECOR_GOLD_SHIELD,
        .name = _("GOLDSCHILD"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 0,
        .description = COMPOUND_STRING(
            "Für 100 Siege in\n"
            "Folge im KAMPF-\n"
            "TURM verliehen."),
        .tiles = DecorGfx_GOLD_SHIELD,
        .icon = {NULL, NULL},
    },

    [DECOR_GLASS_ORNAMENT] =
    {
        .id = DECOR_GLASS_ORNAMENT,
        .name = _("GLASFIGUR"),
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 0,
        .description = COMPOUND_STRING(
            "Ein Glasnachbau\n"
            "einer berühmten\n"
            "Skulptur im MUSEUM."),
        .tiles = DecorGfx_GLASS_ORNAMENT,
        .icon = {gDecorIcon_GlassOrnament, gDecorIconPalette_GlassOrnament},
    },

    [DECOR_TV] =
    {
        .id = DECOR_TV,
        .name = _("FERNSEHER"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 3000,
        .description = COMPOUND_STRING(
            "Ein kleiner grauer\n"
            "Spielzeug-\n"
            "Fernseher."),
        .tiles = DecorGfx_TV,
        .icon = {NULL, NULL},
    },

    [DECOR_ROUND_TV] =
    {
        .id = DECOR_ROUND_TV,
        .name = _("RUNDER TV"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "Ein Spielzeug-\n"
            "Fernseher in Form\n"
            "eines SAMURZEL."),
        .tiles = DecorGfx_ROUND_TV,
        .icon = {NULL, NULL},
    },

    [DECOR_CUTE_TV] =
    {
        .id = DECOR_CUTE_TV,
        .name = _("NIEDLICHER TV"),
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "Ein Spielzeug-\n"
            "Fernseher in Form\n"
            "eines ENECO."),
        .tiles = DecorGfx_CUTE_TV,
        .icon = {NULL, NULL},
    },

    [DECOR_GLITTER_MAT] =
    {
        .id = DECOR_GLITTER_MAT,
        .name = _("GLITZERMATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Eine seltsame Matte,\n"
            "die glitzert, wenn\n"
            "man drauftritt."),
        .tiles = DecorGfx_GLITTER_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_JUMP_MAT] =
    {
        .id = DECOR_JUMP_MAT,
        .name = _("SPRUNGMATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Eine Trickmatte, die\n"
            "hüpft, wenn man\n"
            "drauftritt."),
        .tiles = DecorGfx_JUMP_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_SPIN_MAT] =
    {
        .id = DECOR_SPIN_MAT,
        .name = _("DREHMATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Eine Trickmatte, die\n"
            "sich dreht, wenn\n"
            "man drauftritt."),
        .tiles = DecorGfx_SPIN_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_C_LOW_NOTE_MAT] =
    {
        .id = DECOR_C_LOW_NOTE_MAT,
        .name = _("TIEFES-C-MATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = COMPOUND_STRING(
            "Eine Matte, die ein\n"
            "tiefes C spielt,\n"
            "wenn man drauftritt."),
        .tiles = DecorGfx_C_LOW_NOTE_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_D_NOTE_MAT] =
    {
        .id = DECOR_D_NOTE_MAT,
        .name = _("D-TON-MATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = COMPOUND_STRING(
            "Eine Matte, die ein\n"
            "D spielt, wenn\n"
            "man drauftritt."),
        .tiles = DecorGfx_D_NOTE_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_E_NOTE_MAT] =
    {
        .id = DECOR_E_NOTE_MAT,
        .name = _("E-TON-MATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = COMPOUND_STRING(
            "Eine Matte, die ein\n"
            "E spielt, wenn\n"
            "man drauftritt."),
        .tiles = DecorGfx_E_NOTE_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_F_NOTE_MAT] =
    {
        .id = DECOR_F_NOTE_MAT,
        .name = _("F-TON-MATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = COMPOUND_STRING(
            "Eine Matte, die ein\n"
            "F spielt, wenn\n"
            "man drauftritt."),
        .tiles = DecorGfx_F_NOTE_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_G_NOTE_MAT] =
    {
        .id = DECOR_G_NOTE_MAT,
        .name = _("G-TON-MATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = COMPOUND_STRING(
            "Eine Matte, die ein\n"
            "G spielt, wenn\n"
            "man drauftritt."),
        .tiles = DecorGfx_G_NOTE_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_A_NOTE_MAT] =
    {
        .id = DECOR_A_NOTE_MAT,
        .name = _("A-TON-MATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = COMPOUND_STRING(
            "Eine Matte, die ein\n"
            "A spielt, wenn\n"
            "man drauftritt."),
        .tiles = DecorGfx_A_NOTE_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_B_NOTE_MAT] =
    {
        .id = DECOR_B_NOTE_MAT,
        .name = _("H-TON-MATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = COMPOUND_STRING(
            "Eine Matte, die ein\n"
            "H spielt, wenn\n"
            "man drauftritt."),
        .tiles = DecorGfx_B_NOTE_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_C_HIGH_NOTE_MAT] =
    {
        .id = DECOR_C_HIGH_NOTE_MAT,
        .name = _("HOHES-C-MATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = COMPOUND_STRING(
            "Eine Matte, die ein\n"
            "hohes C spielt,\n"
            "wenn man drauftritt."),
        .tiles = DecorGfx_C_HIGH_NOTE_MAT,
        .icon = {NULL, NULL},
    },

    [DECOR_SURF_MAT] =
    {
        .id = DECOR_SURF_MAT,
        .name = _("SURFER-MATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "Eine Matte mit\n"
            "SURFER-Motiv.\n"
            "Stelle Items darauf."),
        .tiles = DecorGfx_SURF_MAT,
        .icon = {gDecorIcon_SurfMat, gDecorIconPalette_SurfMat},
    },

    [DECOR_THUNDER_MAT] =
    {
        .id = DECOR_THUNDER_MAT,
        .name = _("DONNER-MATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "Eine Matte mit\n"
            "DONNER-Motiv.\n"
            "Stelle Items darauf."),
        .tiles = DecorGfx_THUNDER_MAT,
        .icon = {gDecorIcon_ThunderMat, gDecorIconPalette_ThunderMat},
    },

    [DECOR_FIRE_BLAST_MAT] =
    {
        .id = DECOR_FIRE_BLAST_MAT,
        .name = _("FEUERSTURMMATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "Eine Matte mit\n"
            "FEUERSTURM-Motiv.\n"
            "Stelle Items darauf."),
        .tiles = DecorGfx_FIRE_BLAST_MAT,
        .icon = {gDecorIcon_FireBlastMat, gDecorIconPalette_FireBlastMat},
    },

    [DECOR_POWDER_SNOW_MAT] =
    {
        .id = DECOR_POWDER_SNOW_MAT,
        .name = _("SCHNEE-MATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "Eine Matte mit\n"
            "PUDERSCHNEE-Motiv.\n"
            "Stelle Items darauf."),
        .tiles = DecorGfx_POWDER_SNOW_MAT,
        .icon = {gDecorIcon_PowderSnowMat, gDecorIconPalette_PowderSnowMat},
    },

    [DECOR_ATTRACT_MAT] =
    {
        .id = DECOR_ATTRACT_MAT,
        .name = _("ATTRAKT.-MATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "Eine Matte mit\n"
            "ATTRAKTION-Motiv.\n"
            "Stelle Items darauf."),
        .tiles = DecorGfx_ATTRACT_MAT,
        .icon = {gDecorIcon_AttractMat, gDecorIconPalette_AttractMat},
    },

    [DECOR_FISSURE_MAT] =
    {
        .id = DECOR_FISSURE_MAT,
        .name = _("ERDSPALT-MATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "Eine Matte mit\n"
            "ERDSPALT-Motiv.\n"
            "Stelle Items darauf."),
        .tiles = DecorGfx_FISSURE_MAT,
        .icon = {gDecorIcon_FissureMat, gDecorIconPalette_FissureMat},
    },

    [DECOR_SPIKES_MAT] =
    {
        .id = DECOR_SPIKES_MAT,
        .name = _("STACHELN-MATTE"),
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = COMPOUND_STRING(
            "Eine Matte mit\n"
            "STACHELN-Motiv.\n"
            "Stelle Items darauf."),
        .tiles = DecorGfx_SPIKES_MAT,
        .icon = {gDecorIcon_SpikesMat, gDecorIconPalette_SpikesMat},
    },

    [DECOR_BALL_POSTER] =
    {
        .id = DECOR_BALL_POSTER,
        .name = _("BALL-POSTER"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = COMPOUND_STRING(
            "Ein kleines Poster\n"
            "mit POKéBÄLLEN."),
        .tiles = DecorGfx_BALL_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_GREEN_POSTER] =
    {
        .id = DECOR_GREEN_POSTER,
        .name = _("GRÜNES POSTER"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = COMPOUND_STRING(
            "Ein kleines Poster\n"
            "mit GECKARBOR."),
        .tiles = DecorGfx_GREEN_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_RED_POSTER] =
    {
        .id = DECOR_RED_POSTER,
        .name = _("ROTES POSTER"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = COMPOUND_STRING(
            "Ein kleines Poster\n"
            "mit FLEMMLI."),
        .tiles = DecorGfx_RED_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_BLUE_POSTER] =
    {
        .id = DECOR_BLUE_POSTER,
        .name = _("BLAUES POSTER"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = COMPOUND_STRING(
            "Ein kleines Poster\n"
            "mit HYDROPI."),
        .tiles = DecorGfx_BLUE_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_CUTE_POSTER] =
    {
        .id = DECOR_CUTE_POSTER,
        .name = _("NIEDL. POSTER"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = COMPOUND_STRING(
            "Ein kleines Poster\n"
            "mit AZURILL."),
        .tiles = DecorGfx_CUTE_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_PIKA_POSTER] =
    {
        .id = DECOR_PIKA_POSTER,
        .name = _("PIKA-POSTER"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = COMPOUND_STRING(
            "Ein großes Poster\n"
            "mit PIKACHU und\n"
            "PICHU."),
        .tiles = DecorGfx_PIKA_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_LONG_POSTER] =
    {
        .id = DECOR_LONG_POSTER,
        .name = _("LANGES POSTER"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = COMPOUND_STRING(
            "Ein großes Poster\n"
            "mit VIPITIS."),
        .tiles = DecorGfx_LONG_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_SEA_POSTER] =
    {
        .id = DECOR_SEA_POSTER,
        .name = _("MEER-POSTER"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = COMPOUND_STRING(
            "Ein großes Poster\n"
            "mit RELICANTH."),
        .tiles = DecorGfx_SEA_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_SKY_POSTER] =
    {
        .id = DECOR_SKY_POSTER,
        .name = _("HIMMELS-POSTER"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = COMPOUND_STRING(
            "Ein großes Poster\n"
            "mit WINGULL."),
        .tiles = DecorGfx_SKY_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_KISS_POSTER] =
    {
        .id = DECOR_KISS_POSTER,
        .name = _("KUSS-POSTER"),
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = COMPOUND_STRING(
            "Ein großes Poster\n"
            "mit KUSSILLA."),
        .tiles = DecorGfx_KISS_POSTER,
        .icon = {NULL, NULL},
    },

    [DECOR_PICHU_DOLL] =
    {
        .id = DECOR_PICHU_DOLL,
        .name = _("PICHU-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "PICHU-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_PICHU_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_PIKACHU_DOLL] =
    {
        .id = DECOR_PIKACHU_DOLL,
        .name = _("PIKACHU-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "PIKACHU-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_PIKACHU_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_MARILL_DOLL] =
    {
        .id = DECOR_MARILL_DOLL,
        .name = _("MARILL-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "MARILL-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_MARILL_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_TOGEPI_DOLL] =
    {
        .id = DECOR_TOGEPI_DOLL,
        .name = _("TOGEPI-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "TOGEPI-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_TOGEPI_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_CYNDAQUIL_DOLL] =
    {
        .id = DECOR_CYNDAQUIL_DOLL,
        .name = _("FEURIGEL-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "FEURIGEL-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_CYNDAQUIL_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_CHIKORITA_DOLL] =
    {
        .id = DECOR_CHIKORITA_DOLL,
        .name = _("ENDIVIE-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "ENDIVIE-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_CHIKORITA_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_TOTODILE_DOLL] =
    {
        .id = DECOR_TOTODILE_DOLL,
        .name = _("KARNIMANI-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "KARNIMANI-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_TOTODILE_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_JIGGLYPUFF_DOLL] =
    {
        .id = DECOR_JIGGLYPUFF_DOLL,
        .name = _("PUMMELUFF-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "PUMMELUFF-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_JIGGLYPUFF_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_MEOWTH_DOLL] =
    {
        .id = DECOR_MEOWTH_DOLL,
        .name = _("MAUZI-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "MAUZI-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_MEOWTH_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_CLEFAIRY_DOLL] =
    {
        .id = DECOR_CLEFAIRY_DOLL,
        .name = _("PIEPI-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "PIEPI-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_CLEFAIRY_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_DITTO_DOLL] =
    {
        .id = DECOR_DITTO_DOLL,
        .name = _("DITTO-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "DITTO-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_DITTO_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_SMOOCHUM_DOLL] =
    {
        .id = DECOR_SMOOCHUM_DOLL,
        .name = _("KUSSILLA-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "KUSSILLA-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_SMOOCHUM_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_TREECKO_DOLL] =
    {
        .id = DECOR_TREECKO_DOLL,
        .name = _("GECKARBOR-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "GECKARBOR-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_TREECKO_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_TORCHIC_DOLL] =
    {
        .id = DECOR_TORCHIC_DOLL,
        .name = _("FLEMMLI-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "FLEMMLI-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_TORCHIC_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_MUDKIP_DOLL] =
    {
        .id = DECOR_MUDKIP_DOLL,
        .name = _("HYDROPI-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "HYDROPI-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_MUDKIP_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_DUSKULL_DOLL] =
    {
        .id = DECOR_DUSKULL_DOLL,
        .name = _("ZWIRRL.-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "ZWIRRLICHT-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_DUSKULL_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_WYNAUT_DOLL] =
    {
        .id = DECOR_WYNAUT_DOLL,
        .name = _("ISSO-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "ISSO-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_WYNAUT_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_BALTOY_DOLL] =
    {
        .id = DECOR_BALTOY_DOLL,
        .name = _("PUPPANCE-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "PUPPANCE-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_BALTOY_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_KECLEON_DOLL] =
    {
        .id = DECOR_KECLEON_DOLL,
        .name = _("KECLEON-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "KECLEON-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_KECLEON_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_AZURILL_DOLL] =
    {
        .id = DECOR_AZURILL_DOLL,
        .name = _("AZURILL-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "AZURILL-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_AZURILL_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_SKITTY_DOLL] =
    {
        .id = DECOR_SKITTY_DOLL,
        .name = _("ENECO-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "ENECO-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_SKITTY_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_SWABLU_DOLL] =
    {
        .id = DECOR_SWABLU_DOLL,
        .name = _("WABLU-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "WABLU-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_SWABLU_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_GULPIN_DOLL] =
    {
        .id = DECOR_GULPIN_DOLL,
        .name = _("SCHLUPP.-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "SCHLUPPUCK-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_GULPIN_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_LOTAD_DOLL] =
    {
        .id = DECOR_LOTAD_DOLL,
        .name = _("LOTURZEL-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "LOTURZEL-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_LOTAD_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_SEEDOT_DOLL] =
    {
        .id = DECOR_SEEDOT_DOLL,
        .name = _("SAMURZEL-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = COMPOUND_STRING(
            "SAMURZEL-Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_SEEDOT_DOLL,
        .icon = {NULL, NULL},
    },

    [DECOR_PIKA_CUSHION] =
    {
        .id = DECOR_PIKA_CUSHION,
        .name = _("PIKA-KISSEN"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Ein PIKACHU-Kissen.\n"
            "Stelle es auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_PIKA_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_ROUND_CUSHION] =
    {
        .id = DECOR_ROUND_CUSHION,
        .name = _("RUNDES KISSEN"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Ein MARILL-Kissen.\n"
            "Stelle es auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_ROUND_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_KISS_CUSHION] =
    {
        .id = DECOR_KISS_CUSHION,
        .name = _("KUSS-KISSEN"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Ein Kussilla-Kissen.\n"
            "Stelle es auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_KISS_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_ZIGZAG_CUSHION] =
    {
        .id = DECOR_ZIGZAG_CUSHION,
        .name = _("ZIGZACHS-KISSEN"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Ein Zigzachs-Kissen.\n"
            "Stelle es auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_ZIGZAG_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_SPIN_CUSHION] =
    {
        .id = DECOR_SPIN_CUSHION,
        .name = _("PANDIR-KISSEN"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Ein PANDIR-Kissen.\n"
            "Stelle es auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_SPIN_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_DIAMOND_CUSHION] =
    {
        .id = DECOR_DIAMOND_CUSHION,
        .name = _("ZOBIRIS-KISSEN"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Ein ZOBIRIS-Kissen.\n"
            "Stelle es auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_DIAMOND_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_BALL_CUSHION] =
    {
        .id = DECOR_BALL_CUSHION,
        .name = _("BALL-KISSEN"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Ein BALL-Kissen.\n"
            "Stelle es auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_BALL_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_GRASS_CUSHION] =
    {
        .id = DECOR_GRASS_CUSHION,
        .name = _("PFLANZEN-KISSEN"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Kissen mit Pflanzen-\n"
            "Symbol. Auf Matte\n"
            "oder Tisch."),
        .tiles = DecorGfx_GRASS_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_FIRE_CUSHION] =
    {
        .id = DECOR_FIRE_CUSHION,
        .name = _("FEUER-KISSEN"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Kissen mit Feuer-\n"
            "Symbol. Auf Matte\n"
            "oder Tisch."),
        .tiles = DecorGfx_FIRE_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_WATER_CUSHION] =
    {
        .id = DECOR_WATER_CUSHION,
        .name = _("WASSER-KISSEN"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = COMPOUND_STRING(
            "Kissen mit Wasser-\n"
            "Symbol. Auf Matte\n"
            "oder Tisch."),
        .tiles = DecorGfx_WATER_CUSHION,
        .icon = {NULL, NULL},
    },

    [DECOR_SNORLAX_DOLL] =
    {
        .id = DECOR_SNORLAX_DOLL,
        .name = _("RELAXO-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "Eine große Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_SNORLAX_DOLL,
        .icon = {gDecorIcon_SnorlaxDoll, gDecorIconPalette_SnorlaxDoll},
    },

    [DECOR_RHYDON_DOLL] =
    {
        .id = DECOR_RHYDON_DOLL,
        .name = _("RIZEROS-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "Eine große Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_RHYDON_DOLL,
        .icon = {gDecorIcon_RhydonDoll, gDecorIconPalette_RhydonDoll},
    },

    [DECOR_LAPRAS_DOLL] =
    {
        .id = DECOR_LAPRAS_DOLL,
        .name = _("LAPRAS-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "Eine große Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_LAPRAS_DOLL,
        .icon = {gDecorIcon_LaprasDoll, gDecorIconPalette_LaprasDoll},
    },

    [DECOR_VENUSAUR_DOLL] =
    {
        .id = DECOR_VENUSAUR_DOLL,
        .name = _("BISAFLOR-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "Eine große Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_VENUSAUR_DOLL,
        .icon = {gDecorIcon_VenusaurDoll, gDecorIconPalette_VenusaurDoll},
    },

    [DECOR_CHARIZARD_DOLL] =
    {
        .id = DECOR_CHARIZARD_DOLL,
        .name = _("GLURAK-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "Eine große Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_CHARIZARD_DOLL,
        .icon = {gDecorIcon_CharizardDoll, gDecorIconPalette_CharizardDoll},
    },

    [DECOR_BLASTOISE_DOLL] =
    {
        .id = DECOR_BLASTOISE_DOLL,
        .name = _("TURTOK-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "Eine große Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_BLASTOISE_DOLL,
        .icon = {gDecorIcon_BlastoiseDoll, gDecorIconPalette_BlastoiseDoll},
    },

    [DECOR_WAILMER_DOLL] =
    {
        .id = DECOR_WAILMER_DOLL,
        .name = _("WAILMER-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "Eine große Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_WAILMER_DOLL,
        .icon = {gDecorIcon_WailmerDoll, gDecorIconPalette_WailmerDoll},
    },

    [DECOR_REGIROCK_DOLL] =
    {
        .id = DECOR_REGIROCK_DOLL,
        .name = _("REGIROCK-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "Eine große Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_REGIROCK_DOLL,
        .icon = {gDecorIcon_RegirockDoll, gDecorIconPalette_RegirockDoll},
    },

    [DECOR_REGICE_DOLL] =
    {
        .id = DECOR_REGICE_DOLL,
        .name = _("REGICE-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "Eine große Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_REGICE_DOLL,
        .icon = {gDecorIcon_RegiceDoll, gDecorIconPalette_RegiceDoll},
    },

    [DECOR_REGISTEEL_DOLL] =
    {
        .id = DECOR_REGISTEEL_DOLL,
        .name = _("REGISTEEL-PUPPE"),
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = COMPOUND_STRING(
            "Eine große Puppe.\n"
            "Stelle sie auf\n"
            "Matte oder Tisch."),
        .tiles = DecorGfx_REGISTEEL_DOLL,
        .icon = {gDecorIcon_RegisteelDoll, gDecorIconPalette_RegisteelDoll},
    }
};
