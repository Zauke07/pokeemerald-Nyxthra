const u8 gEasyChatWord_Chores[] = _("Hausarbeit");
const u8 gEasyChatWord_Home[] = _("Zuhause");
const u8 gEasyChatWord_Money[] = _("Geld");
const u8 gEasyChatWord_Allowance[] = _("Taschengeld");
const u8 gEasyChatWord_Bath[] = _("Bad");
const u8 gEasyChatWord_Conversation[] = _("Gespräch");
const u8 gEasyChatWord_School[] = _("Schule");
const u8 gEasyChatWord_Commemorate[] = _("Gedenken");
const u8 gEasyChatWord_Habit[] = _("Gewohnheit");
const u8 gEasyChatWord_Group[] = _("Gruppe");
const u8 gEasyChatWord_Word[] = _("Wort");
const u8 gEasyChatWord_Store[] = _("Laden");
const u8 gEasyChatWord_Service[] = _("Dienst");
const u8 gEasyChatWord_Work[] = _("Arbeit");
const u8 gEasyChatWord_System[] = _("System");
const u8 gEasyChatWord_Train[] = _("Zug");
const u8 gEasyChatWord_Class[] = _("Klasse");
const u8 gEasyChatWord_Lessons[] = _("Unterricht");
const u8 gEasyChatWord_Information[] = _("Information");
const u8 gEasyChatWord_Living[] = _("Leben");
const u8 gEasyChatWord_Teacher[] = _("Lehrer");
const u8 gEasyChatWord_Tournament[] = _("Turnier");
const u8 gEasyChatWord_Letter[] = _("Brief");
const u8 gEasyChatWord_Event[] = _("Ereignis");
const u8 gEasyChatWord_Digital[] = _("Digital");
const u8 gEasyChatWord_Test[] = _("Test");
const u8 gEasyChatWord_DeptStore[] = _("Kaufhaus");
const u8 gEasyChatWord_Television[] = _("Fernsehen");
const u8 gEasyChatWord_Phone[] = _("Telefon");
const u8 gEasyChatWord_Item[] = _("Gegenstand");
const u8 gEasyChatWord_Name[] = _("Name");
const u8 gEasyChatWord_News[] = _("Nachrichten");
const u8 gEasyChatWord_Popular[] = _("Beliebt");
const u8 gEasyChatWord_Party[] = _("Party");
const u8 gEasyChatWord_Study[] = _("Studium");
const u8 gEasyChatWord_Machine[] = _("Maschine");
const u8 gEasyChatWord_Mail[] = _("Post");
const u8 gEasyChatWord_Message[] = _("Nachricht");
const u8 gEasyChatWord_Promise[] = _("Versprechen");
const u8 gEasyChatWord_Dream[] = _("Traum");
const u8 gEasyChatWord_Kindergarten[] = _("Kindergarten");
const u8 gEasyChatWord_Life[] = _("Leben");
const u8 gEasyChatWord_Radio[] = _("Radio");
const u8 gEasyChatWord_Rental[] = _("Miete");
const u8 gEasyChatWord_World[] = _("Welt");

const struct EasyChatWordInfo gEasyChatGroup_Lifestyle[] = {
    [EC_INDEX(EC_WORD_CHORES)] =
    {
        .text = COMPOUND_STRING("CHORES"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALLOWANCE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOME)] =
    {
        .text = COMPOUND_STRING("HOME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BATH),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MONEY)] =
    {
        .text = COMPOUND_STRING("MONEY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHORES),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALLOWANCE)] =
    {
        .text = COMPOUND_STRING("ALLOWANCE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CLASS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BATH)] =
    {
        .text = COMPOUND_STRING("BATH"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COMMEMORATE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CONVERSATION)] =
    {
        .text = COMPOUND_STRING("CONVERSATION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CONVERSATION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SCHOOL)] =
    {
        .text = COMPOUND_STRING("SCHOOL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DEPT_STORE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COMMEMORATE)] =
    {
        .text = COMPOUND_STRING("COMMEMORATE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIGITAL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HABIT)] =
    {
        .text = COMPOUND_STRING("HABIT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DREAM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GROUP)] =
    {
        .text = COMPOUND_STRING("GROUP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_EVENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORD)] =
    {
        .text = COMPOUND_STRING("WORD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GROUP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STORE)] =
    {
        .text = COMPOUND_STRING("STORE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HABIT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SERVICE)] =
    {
        .text = COMPOUND_STRING("SERVICE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORK)] =
    {
        .text = COMPOUND_STRING("WORK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_INFORMATION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SYSTEM)] =
    {
        .text = COMPOUND_STRING("SYSTEM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ITEM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRAIN)] =
    {
        .text = COMPOUND_STRING("TRAIN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KINDERGARTEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CLASS)] =
    {
        .text = COMPOUND_STRING("CLASS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LESSONS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LESSONS)] =
    {
        .text = COMPOUND_STRING("LESSONS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LETTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_INFORMATION)] =
    {
        .text = COMPOUND_STRING("INFORMATION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIFE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIVING)] =
    {
        .text = COMPOUND_STRING("LIVING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LIVING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TEACHER)] =
    {
        .text = COMPOUND_STRING("TEACHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MACHINE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOURNAMENT)] =
    {
        .text = COMPOUND_STRING("TOURNAMENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAIL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LETTER)] =
    {
        .text = COMPOUND_STRING("LETTER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MESSAGE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_EVENT)] =
    {
        .text = COMPOUND_STRING("EVENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MONEY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIGITAL)] =
    {
        .text = COMPOUND_STRING("DIGITAL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NAME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TEST)] =
    {
        .text = COMPOUND_STRING("TEST"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NEWS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DEPT_STORE)] =
    {
        .text = COMPOUND_STRING("DEPT. STORE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PARTY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TELEVISION)] =
    {
        .text = COMPOUND_STRING("TELEVISION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PHONE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PHONE)] =
    {
        .text = COMPOUND_STRING("PHONE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_POPULAR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ITEM)] =
    {
        .text = COMPOUND_STRING("ITEM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PROMISE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NAME)] =
    {
        .text = COMPOUND_STRING("NAME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RADIO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NEWS)] =
    {
        .text = COMPOUND_STRING("NEWS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RENTAL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_POPULAR)] =
    {
        .text = COMPOUND_STRING("POPULAR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SCHOOL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PARTY)] =
    {
        .text = COMPOUND_STRING("PARTY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SERVICE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_STUDY)] =
    {
        .text = COMPOUND_STRING("STUDY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STORE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MACHINE)] =
    {
        .text = COMPOUND_STRING("MACHINE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_STUDY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAIL)] =
    {
        .text = COMPOUND_STRING("MAIL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SYSTEM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MESSAGE)] =
    {
        .text = COMPOUND_STRING("MESSAGE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TEACHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PROMISE)] =
    {
        .text = COMPOUND_STRING("PROMISE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TELEVISION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DREAM)] =
    {
        .text = COMPOUND_STRING("DREAM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TEST),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KINDERGARTEN)] =
    {
        .text = COMPOUND_STRING("KINDERGARTEN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOURNAMENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LIFE)] =
    {
        .text = COMPOUND_STRING("LIFE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRAIN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RADIO)] =
    {
        .text = COMPOUND_STRING("RADIO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RENTAL)] =
    {
        .text = COMPOUND_STRING("RENTAL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WORLD)] =
    {
        .text = COMPOUND_STRING("WORLD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WORLD),
        .enabled = TRUE,
    },
};
