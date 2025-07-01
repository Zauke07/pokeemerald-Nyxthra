#if 0
const struct MonCoords gTrainerBackPicCoords[] =
{
    [TRAINER_BACK_PIC_NONE] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_BRENDAN] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_MAY] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_RED] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_LEAF] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_ETHAN] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_LYRA] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_RUBY_SAPPHIRE_BRENDAN] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_RUBY_SAPPHIRE_MAY] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_WALLY] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_STEVEN] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_LUCAS] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_DAWN] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_WES] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_HILBERT] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_HILDA] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_NATE] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_ROSA] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_CALEM] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_SERENA] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_ELIO] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_SELENE] = {.size = 8, .y_offset = 4},
    [TRAINER_BACK_PIC_VICTOR] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_GLORIA] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_FLORIAN] = {.size = 8, .y_offset = 5},
    [TRAINER_BACK_PIC_JULIANA] = {.size = 8, .y_offset = 5},
//    [TRAINER_BACK_PIC_ASH] = {.size = 8, .y_offset = 5},
//    [TRAINER_BACK_PIC_WES] = {.size = 8, .y_offset = 4},
};

// this table goes functionally unused, since none of these pics are compressed
// and the place they would get extracted to gets overwritten later anyway
// the casts are so they'll play nice with the strict struct definition
#define TRAINER_BACK_SPRITE(trainerPic, sprite, size) [TRAINER_BACK_PIC_##trainerPic] = {(const u32 *)sprite, size, TRAINER_BACK_PIC_##trainerPic}

const struct SpriteSheet gTrainerBackPicTable[] =
{
    TRAINER_BACK_SPRITE(NONE, gTrainerBackPic_None, 0x2000),
    TRAINER_BACK_SPRITE(BRENDAN, gTrainerBackPic_Brendan, 0x2000),
    TRAINER_BACK_SPRITE(MAY, gTrainerBackPic_May, 0x2000),
    TRAINER_BACK_SPRITE(RED, gTrainerBackPic_Red, 0x2800),
    TRAINER_BACK_SPRITE(LEAF, gTrainerBackPic_Leaf, 0x2800),
    TRAINER_BACK_SPRITE(ETHAN, gTrainerBackPic_Ethan, 0x2800),
    TRAINER_BACK_SPRITE(LYRA, gTrainerBackPic_Lyra, 0x2800),
    TRAINER_BACK_SPRITE(RUBY_SAPPHIRE_BRENDAN, gTrainerBackPic_RubySapphireBrendan, 0x2000),
    TRAINER_BACK_SPRITE(RUBY_SAPPHIRE_MAY, gTrainerBackPic_RubySapphireMay, 0x2000),
    TRAINER_BACK_SPRITE(WALLY, gTrainerBackPic_Wally, 0x2000),
    TRAINER_BACK_SPRITE(STEVEN, gTrainerBackPic_Steven, 0x2000),
    TRAINER_BACK_SPRITE(LUCAS, gTrainerBackPic_Lucas, 0x2800),
    TRAINER_BACK_SPRITE(DAWN, gTrainerBackPic_Dawn, 0x2800),
    TRAINER_BACK_SPRITE(WES, gTrainerBackPic_Wes, 0x2800),
    TRAINER_BACK_SPRITE(HILBERT, gTrainerBackPic_Hilbert, 0x2800),
    TRAINER_BACK_SPRITE(HILDA, gTrainerBackPic_Hilda, 0x2800),
    TRAINER_BACK_SPRITE(NATE, gTrainerBackPic_Nate, 0x2800),
    TRAINER_BACK_SPRITE(ROSA, gTrainerBackPic_Rosa, 0x2800),
    TRAINER_BACK_SPRITE(CALEM, gTrainerBackPic_Calem, 0x2800),
    TRAINER_BACK_SPRITE(SERENA, gTrainerBackPic_Serena, 0x2800),
    TRAINER_BACK_SPRITE(ELIO, gTrainerBackPic_Elio, 0x2800),
    TRAINER_BACK_SPRITE(SELENE, gTrainerBackPic_Selene, 0x2800),
    TRAINER_BACK_SPRITE(VICTOR, gTrainerBackPic_Victor, 0x2800),
    TRAINER_BACK_SPRITE(GLORIA, gTrainerBackPic_Gloria, 0x2800),
    TRAINER_BACK_SPRITE(FLORIAN, gTrainerBackPic_Florian, 0x2800),
    TRAINER_BACK_SPRITE(JULIANA, gTrainerBackPic_Juliana, 0x2800),
//    TRAINER_BACK_SPRITE(ASH, gTrainerBackPic_Ash, 0x2800),
//    TRAINER_BACK_SPRITE(WES, gTrainerBackPic_Wes, 0x2800),
};

#define TRAINER_BACK_PAL(trainerPic, pal) [TRAINER_BACK_PIC_##trainerPic] = {pal, TRAINER_BACK_PIC_##trainerPic}

const struct SpritePalette gTrainerBackPicPaletteTable[] =
{
    TRAINER_BACK_PAL(NONE, gTrainerPalette_PlayerBackPlaceholder), // OK als Fallback
    TRAINER_BACK_PAL(BRENDAN, gTrainerPalette_Brendan),
    TRAINER_BACK_PAL(MAY, gTrainerPalette_May),
    TRAINER_BACK_PAL(RED, gTrainerPalette_Red),
    TRAINER_BACK_PAL(LEAF, gTrainerPalette_Leaf),
    TRAINER_BACK_PAL(RUBY_SAPPHIRE_BRENDAN, gTrainerPalette_RubySapphireBrendan),
    TRAINER_BACK_PAL(RUBY_SAPPHIRE_MAY, gTrainerPalette_RubySapphireMay),
    TRAINER_BACK_PAL(WALLY, gTrainerPalette_Wally),
    TRAINER_BACK_PAL(STEVEN, gTrainerPalette_Steven),
    TRAINER_BACK_PAL(LUCAS, gTrainerPalette_Lucas),
    TRAINER_BACK_PAL(DAWN, gTrainerPalette_Dawn),
    TRAINER_BACK_PAL(WES, gTrainerPalette_Wes),
    TRAINER_BACK_PAL(HILBERT, gTrainerPalette_Hilbert),
    TRAINER_BACK_PAL(HILDA, gTrainerPalette_Hilda),
    TRAINER_BACK_PAL(NATE, gTrainerPalette_Nate),
    TRAINER_BACK_PAL(ROSA, gTrainerPalette_Rosa),
    TRAINER_BACK_PAL(CALEM, gTrainerPalette_Calem),
    TRAINER_BACK_PAL(SERENA, gTrainerPalette_Serena),
    TRAINER_BACK_PAL(ELIO, gTrainerPalette_Elio),
    TRAINER_BACK_PAL(SELENE, gTrainerPalette_Selene),
    TRAINER_BACK_PAL(VICTOR, gTrainerPalette_Victor),
    TRAINER_BACK_PAL(GLORIA, gTrainerPalette_Gloria),
    TRAINER_BACK_PAL(FLORIAN, gTrainerPalette_Florian),
    TRAINER_BACK_PAL(JULIANA, gTrainerPalette_Juliana),
//    TRAINER_BACK_PAL(ASH, gTrainerPalette_Ash),
//    TRAINER_BACK_PAL(WES, gTrainerPalette_Wes),
    
};
#endif
