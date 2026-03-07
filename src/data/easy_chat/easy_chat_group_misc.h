const u8 gEasyChatWord_Highs[] = _("Höhen");
const u8 gEasyChatWord_Lows[] = _("Tiefen");
const u8 gEasyChatWord_Um[] = _("Ähm");
const u8 gEasyChatWord_Rear[] = _("Hinten");
const u8 gEasyChatWord_Things[] = _("Dinge");
const u8 gEasyChatWord_Thing[] = _("Ding");
const u8 gEasyChatWord_Below[] = _("Unten");
const u8 gEasyChatWord_Above[] = _("Oben");
const u8 gEasyChatWord_Back[] = _("Zurück");
const u8 gEasyChatWord_High[] = _("Hoch");
const u8 gEasyChatWord_Here[] = _("Hier");
const u8 gEasyChatWord_Inside[] = _("Drinnen");
const u8 gEasyChatWord_Outside[] = _("Draußen");
const u8 gEasyChatWord_Beside[] = _("Daneben");
const u8 gEasyChatWord_ThisIsItExcl[] = _("Das ist es!");
const u8 gEasyChatWord_This[] = _("Dies");
const u8 gEasyChatWord_Every[] = _("Jeder");
const u8 gEasyChatWord_These[] = _("Diese");
const u8 gEasyChatWord_TheseWere[] = _("Diese waren");
const u8 gEasyChatWord_Down[] = _("Runter");
const u8 gEasyChatWord_That[] = _("Das");
const u8 gEasyChatWord_ThoseAre[] = _("Das sind");
const u8 gEasyChatWord_ThoseWere[] = _("Das waren");
const u8 gEasyChatWord_ThatsItExcl[] = _("Das ist es!");
const u8 gEasyChatWord_Am[] = _("Bin");
const u8 gEasyChatWord_ThatWas[] = _("Das war");
const u8 gEasyChatWord_Front[] = _("Vorne");
const u8 gEasyChatWord_Up[] = _("Hoch");
const u8 gEasyChatWord_Choice[] = _("Wahl");
const u8 gEasyChatWord_Far[] = _("Weit");
const u8 gEasyChatWord_Away[] = _("Weg");
const u8 gEasyChatWord_Near[] = _("Nah");
const u8 gEasyChatWord_Where[] = _("Wo");
const u8 gEasyChatWord_When[] = _("Wann");
const u8 gEasyChatWord_What[] = _("Was");
const u8 gEasyChatWord_Deep[] = _("Tief");
const u8 gEasyChatWord_Shallow[] = _("Flach");
const u8 gEasyChatWord_Why[] = _("Warum");
const u8 gEasyChatWord_Confused[] = _("Verwirrt");
const u8 gEasyChatWord_Opposite[] = _("Gegenteil");
const u8 gEasyChatWord_Left[] = _("Links");
const u8 gEasyChatWord_Right[] = _("Rechts");

const struct EasyChatWordInfo gEasyChatGroup_Misc[] = {
    [EC_INDEX(EC_WORD_HIGHS)] =
    {
        .text = COMPOUND_STRING("HIGHS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABOVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOWS)] =
    {
        .text = COMPOUND_STRING("LOWS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UM)] =
    {
        .text = COMPOUND_STRING("UM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REAR)] =
    {
        .text = COMPOUND_STRING("REAR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BACK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THINGS)] =
    {
        .text = COMPOUND_STRING("THINGS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BELOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THING)] =
    {
        .text = COMPOUND_STRING("THING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BESIDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BELOW)] =
    {
        .text = COMPOUND_STRING("BELOW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHOICE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABOVE)] =
    {
        .text = COMPOUND_STRING("ABOVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONFUSED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BACK)] =
    {
        .text = COMPOUND_STRING("BACK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DEEP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIGH)] =
    {
        .text = COMPOUND_STRING("HIGH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOWN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERE)] =
    {
        .text = COMPOUND_STRING("HERE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVERY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INSIDE)] =
    {
        .text = COMPOUND_STRING("INSIDE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OUTSIDE)] =
    {
        .text = COMPOUND_STRING("OUTSIDE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FRONT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BESIDE)] =
    {
        .text = COMPOUND_STRING("BESIDE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIS_IS_IT_EXCL)] =
    {
        .text = COMPOUND_STRING("THIS IS IT!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIGH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THIS)] =
    {
        .text = COMPOUND_STRING("THIS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIGHS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVERY)] =
    {
        .text = COMPOUND_STRING("EVERY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INSIDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THESE)] =
    {
        .text = COMPOUND_STRING("THESE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LEFT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THESE_WERE)] =
    {
        .text = COMPOUND_STRING("THESE WERE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOWS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOWN)] =
    {
        .text = COMPOUND_STRING("DOWN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT)] =
    {
        .text = COMPOUND_STRING("THAT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OPPOSITE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THOSE_ARE)] =
    {
        .text = COMPOUND_STRING("THOSE ARE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OUTSIDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THOSE_WERE)] =
    {
        .text = COMPOUND_STRING("THOSE WERE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_REAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT_S_IT_EXCL)] =
    {
        .text = COMPOUND_STRING("THAT'S IT!"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIGHT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AM)] =
    {
        .text = COMPOUND_STRING("AM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHALLOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THAT_WAS)] =
    {
        .text = COMPOUND_STRING("THAT WAS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FRONT)] =
    {
        .text = COMPOUND_STRING("FRONT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT_WAS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UP)] =
    {
        .text = COMPOUND_STRING("UP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THAT_S_IT_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHOICE)] =
    {
        .text = COMPOUND_STRING("CHOICE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THESE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAR)] =
    {
        .text = COMPOUND_STRING("FAR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THESE_WERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWAY)] =
    {
        .text = COMPOUND_STRING("AWAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEAR)] =
    {
        .text = COMPOUND_STRING("NEAR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THINGS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHERE)] =
    {
        .text = COMPOUND_STRING("WHERE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHEN)] =
    {
        .text = COMPOUND_STRING("WHEN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THIS_IS_IT_EXCL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHAT)] =
    {
        .text = COMPOUND_STRING("WHAT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THOSE_ARE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DEEP)] =
    {
        .text = COMPOUND_STRING("DEEP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THOSE_WERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHALLOW)] =
    {
        .text = COMPOUND_STRING("SHALLOW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHY)] =
    {
        .text = COMPOUND_STRING("WHY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONFUSED)] =
    {
        .text = COMPOUND_STRING("CONFUSED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHAT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OPPOSITE)] =
    {
        .text = COMPOUND_STRING("OPPOSITE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LEFT)] =
    {
        .text = COMPOUND_STRING("LEFT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIGHT)] =
    {
        .text = COMPOUND_STRING("RIGHT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHY),
        .enabled = TRUE,
    },
};
