const u8 gEasyChatWord_Hot[] = _("Heiß");
const u8 gEasyChatWord_Exists[] = _("Existiert");
const u8 gEasyChatWord_Excess[] = _("Übermässig");
const u8 gEasyChatWord_Approved[] = _("Genehmigt");
const u8 gEasyChatWord_Has[] = _("Hat");
const u8 gEasyChatWord_Good[] = _("Fein");
const u8 gEasyChatWord_Less[] = _("Weniger");
const u8 gEasyChatWord_Momentum[] = _("Schwung");
const u8 gEasyChatWord_Going[] = _("Gehen");
const u8 gEasyChatWord_Weird[] = _("Verrückt");
const u8 gEasyChatWord_Busy[] = _("Beschäftigt");
const u8 gEasyChatWord_Together[] = _("Zusammen");
const u8 gEasyChatWord_Full[] = _("Voll");
const u8 gEasyChatWord_Absent[] = _("Abwesend");
const u8 gEasyChatWord_Being[] = _("Seine");
const u8 gEasyChatWord_Need[] = _("Brauche");
const u8 gEasyChatWord_Tasty[] = _("Lecker");
const u8 gEasyChatWord_Skilled[] = _("Geschickt");
const u8 gEasyChatWord_Noisy[] = _("Laut");
const u8 gEasyChatWord_Big[] = _("Groß");
const u8 gEasyChatWord_Late[] = _("Spät");
const u8 gEasyChatWord_Close[] = _("Nahe Bei");
const u8 gEasyChatWord_Docile[] = _("Sanftmütig");
const u8 gEasyChatWord_Amusing[] = _("Amüsant");
const u8 gEasyChatWord_Entertaining[] = _("Unterhaltsam");
const u8 gEasyChatWord_Perfection[] = _("Perfektion");
const u8 gEasyChatWord_Pretty[] = _("Hübsch");
const u8 gEasyChatWord_Healthy[] = _("Gesund");
const u8 gEasyChatWord_Excellent[] = _("EXZELLENT");
const u8 gEasyChatWord_UpsideDown[] = _("Umgedreht");
const u8 gEasyChatWord_Cold[] = _("Kalt");
const u8 gEasyChatWord_Refreshing[] = _("Erfrischend");
const u8 gEasyChatWord_Unavoidable[] = _("Unvermeidbar");
const u8 gEasyChatWord_Much[] = _("Viele");
const u8 gEasyChatWord_Overwhelming[] = _("Mitreisend");
const u8 gEasyChatWord_Fabulous[] = _("Fabelhaft");
const u8 gEasyChatWord_Else[] = _("Anders");
const u8 gEasyChatWord_Expensive[] = _("Teure");
const u8 gEasyChatWord_Correct[] = _("Richtig");
const u8 gEasyChatWord_Impossible[] = _("Unmöglich");
const u8 gEasyChatWord_Small[] = _("Klein");
const u8 gEasyChatWord_Different[] = _("Verschiedene");
const u8 gEasyChatWord_Tired[] = _("Müde");
const u8 gEasyChatWord_Skill[] = _("Geschick");
const u8 gEasyChatWord_Top[] = _("TOP");
const u8 gEasyChatWord_NonStop[] = _("NON-STOP");
const u8 gEasyChatWord_Preposterous[] = _("Absurd");
const u8 gEasyChatWord_None[] = _("Kein");
const u8 gEasyChatWord_Nothing[] = _("Nichts");
const u8 gEasyChatWord_Natural[] = _("Natürlich");
const u8 gEasyChatWord_Becomes[] = _("wird");
const u8 gEasyChatWord_Lukewarm[] = _("Lauwarm");
const u8 gEasyChatWord_Fast[] = _("Schnell");
const u8 gEasyChatWord_Low[] = _("Niedrig");
const u8 gEasyChatWord_Awful[] = _("Schlimm");
const u8 gEasyChatWord_Alone[] = _("Alleine");
const u8 gEasyChatWord_Bored[] = _("Gelangweilt");
const u8 gEasyChatWord_Secret[] = _("Geheimnis");
const u8 gEasyChatWord_Mystery[] = _("Geheim");
const u8 gEasyChatWord_Lacks[] = _("Fehlt");
const u8 gEasyChatWord_Best[] = _("Bestes");
const u8 gEasyChatWord_Lousy[] = _("Lustig");
const u8 gEasyChatWord_Mistake[] = _("Fehler");
const u8 gEasyChatWord_Kind[] = _("Höflich");
const u8 gEasyChatWord_Well[] = _("Schlecht");
const u8 gEasyChatWord_Weakened[] = _("Geschwächt");
const u8 gEasyChatWord_Simple[] = _("Einfach");
const u8 gEasyChatWord_Seems[] = _("Scheinbar");
const u8 gEasyChatWord_Badly[] = _("Mies");

const struct EasyChatWordInfo gEasyChatGroup_Conditions[] = {
    [EC_INDEX(EC_WORD_HOT)] =
    {
        .text = COMPOUND_STRING("HOT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ABSENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXISTS)] =
    {
        .text = COMPOUND_STRING("EXISTS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALONE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCESS)] =
    {
        .text = COMPOUND_STRING("EXCESS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AMUSING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_APPROVED)] =
    {
        .text = COMPOUND_STRING("APPROVED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_APPROVED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HAS)] =
    {
        .text = COMPOUND_STRING("HAS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AWFUL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOOD)] =
    {
        .text = COMPOUND_STRING("GOOD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BADLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LESS)] =
    {
        .text = COMPOUND_STRING("LESS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BECOMES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MOMENTUM)] =
    {
        .text = COMPOUND_STRING("MOMENTUM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOING)] =
    {
        .text = COMPOUND_STRING("GOING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEIRD)] =
    {
        .text = COMPOUND_STRING("WEIRD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BIG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BUSY)] =
    {
        .text = COMPOUND_STRING("BUSY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BORED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOGETHER)] =
    {
        .text = COMPOUND_STRING("TOGETHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BUSY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FULL)] =
    {
        .text = COMPOUND_STRING("FULL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CLOSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ABSENT)] =
    {
        .text = COMPOUND_STRING("ABSENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COLD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEING)] =
    {
        .text = COMPOUND_STRING("BEING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CORRECT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEED)] =
    {
        .text = COMPOUND_STRING("NEED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIFFERENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TASTY)] =
    {
        .text = COMPOUND_STRING("TASTY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DOCILE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SKILLED)] =
    {
        .text = COMPOUND_STRING("SKILLED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ELSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOISY)] =
    {
        .text = COMPOUND_STRING("NOISY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ENTERTAINING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BIG)] =
    {
        .text = COMPOUND_STRING("BIG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCELLENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LATE)] =
    {
        .text = COMPOUND_STRING("LATE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXCESS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CLOSE)] =
    {
        .text = COMPOUND_STRING("CLOSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXISTS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DOCILE)] =
    {
        .text = COMPOUND_STRING("DOCILE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EXPENSIVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AMUSING)] =
    {
        .text = COMPOUND_STRING("AMUSING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FABULOUS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ENTERTAINING)] =
    {
        .text = COMPOUND_STRING("ENTERTAINING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PERFECTION)] =
    {
        .text = COMPOUND_STRING("PERFECTION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FULL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PRETTY)] =
    {
        .text = COMPOUND_STRING("PRETTY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEALTHY)] =
    {
        .text = COMPOUND_STRING("HEALTHY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOOD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXCELLENT)] =
    {
        .text = COMPOUND_STRING("EXCELLENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HAS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UPSIDE_DOWN)] =
    {
        .text = COMPOUND_STRING("UPSIDE DOWN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEALTHY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COLD)] =
    {
        .text = COMPOUND_STRING("COLD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_REFRESHING)] =
    {
        .text = COMPOUND_STRING("REFRESHING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IMPOSSIBLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNAVOIDABLE)] =
    {
        .text = COMPOUND_STRING("UNAVOIDABLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KIND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUCH)] =
    {
        .text = COMPOUND_STRING("MUCH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LACKS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OVERWHELMING)] =
    {
        .text = COMPOUND_STRING("OVERWHELMING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LATE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FABULOUS)] =
    {
        .text = COMPOUND_STRING("FABULOUS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LESS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ELSE)] =
    {
        .text = COMPOUND_STRING("ELSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOUSY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EXPENSIVE)] =
    {
        .text = COMPOUND_STRING("EXPENSIVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOW),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CORRECT)] =
    {
        .text = COMPOUND_STRING("CORRECT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LUKEWARM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IMPOSSIBLE)] =
    {
        .text = COMPOUND_STRING("IMPOSSIBLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MISTAKE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SMALL)] =
    {
        .text = COMPOUND_STRING("SMALL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOMENTUM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIFFERENT)] =
    {
        .text = COMPOUND_STRING("DIFFERENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUCH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TIRED)] =
    {
        .text = COMPOUND_STRING("TIRED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MYSTERY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SKILL)] =
    {
        .text = COMPOUND_STRING("SKILL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NATURAL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOP)] =
    {
        .text = COMPOUND_STRING("TOP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NON_STOP)] =
    {
        .text = COMPOUND_STRING("NON-STOP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOISY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PREPOSTEROUS)] =
    {
        .text = COMPOUND_STRING("PREPOSTEROUS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NON_STOP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NONE)] =
    {
        .text = COMPOUND_STRING("NONE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NONE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NOTHING)] =
    {
        .text = COMPOUND_STRING("NOTHING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NOTHING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NATURAL)] =
    {
        .text = COMPOUND_STRING("NATURAL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OVERWHELMING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BECOMES)] =
    {
        .text = COMPOUND_STRING("BECOMES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PERFECTION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LUKEWARM)] =
    {
        .text = COMPOUND_STRING("LUKEWARM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PREPOSTEROUS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAST)] =
    {
        .text = COMPOUND_STRING("FAST"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PRETTY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOW)] =
    {
        .text = COMPOUND_STRING("LOW"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_REFRESHING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AWFUL)] =
    {
        .text = COMPOUND_STRING("AWFUL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SECRET),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALONE)] =
    {
        .text = COMPOUND_STRING("ALONE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SEEMS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BORED)] =
    {
        .text = COMPOUND_STRING("BORED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SIMPLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SECRET)] =
    {
        .text = COMPOUND_STRING("SECRET"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SKILL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MYSTERY)] =
    {
        .text = COMPOUND_STRING("MYSTERY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SKILLED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LACKS)] =
    {
        .text = COMPOUND_STRING("LACKS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SMALL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEST)] =
    {
        .text = COMPOUND_STRING("BEST"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TASTY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOUSY)] =
    {
        .text = COMPOUND_STRING("LOUSY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TIRED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MISTAKE)] =
    {
        .text = COMPOUND_STRING("MISTAKE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOGETHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KIND)] =
    {
        .text = COMPOUND_STRING("KIND"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WELL)] =
    {
        .text = COMPOUND_STRING("WELL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNAVOIDABLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WEAKENED)] =
    {
        .text = COMPOUND_STRING("WEAKENED"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UPSIDE_DOWN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SIMPLE)] =
    {
        .text = COMPOUND_STRING("SIMPLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEAKENED),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SEEMS)] =
    {
        .text = COMPOUND_STRING("SEEMS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WEIRD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BADLY)] =
    {
        .text = COMPOUND_STRING("BADLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WELL),
        .enabled = TRUE,
    },
};
