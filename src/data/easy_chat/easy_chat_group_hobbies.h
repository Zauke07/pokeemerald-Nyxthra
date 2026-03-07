const u8 gEasyChatWord_Idol[] = _("Idol");
const u8 gEasyChatWord_Anime[] = _("Anime");
const u8 gEasyChatWord_Song[] = _("Lied");
const u8 gEasyChatWord_Movie[] = _("Film");
const u8 gEasyChatWord_Sweets[] = _("Süßigkeiten");
const u8 gEasyChatWord_Chat[] = _("Plaudern");
const u8 gEasyChatWord_ChildsPlay[] = _("Kinderspiel");
const u8 gEasyChatWord_Toys[] = _("Spielzeug");
const u8 gEasyChatWord_Music[] = _("Musik");
const u8 gEasyChatWord_Cards[] = _("Karten");
const u8 gEasyChatWord_Shopping[] = _("Einkaufen");
const u8 gEasyChatWord_Camera[] = _("Kamera");
const u8 gEasyChatWord_Viewing[] = _("Ansehen");
const u8 gEasyChatWord_Spectator[] = _("Zuschauer");
const u8 gEasyChatWord_Gourmet[] = _("Feinschmecker");
const u8 gEasyChatWord_Game[] = _("Spiel");
const u8 gEasyChatWord_Rpg[] = _("RPG");
const u8 gEasyChatWord_Collection[] = _("Sammlung");
const u8 gEasyChatWord_Complete[] = _("Komplett");
const u8 gEasyChatWord_Magazine[] = _("Magazin");
const u8 gEasyChatWord_Walk[] = _("Spazieren");
const u8 gEasyChatWord_Bike[] = _("Fahrrad");
const u8 gEasyChatWord_Hobby[] = _("Hobby");
const u8 gEasyChatWord_Sports[] = _("Sport");
const u8 gEasyChatWord_Software[] = _("Software");
const u8 gEasyChatWord_Songs[] = _("Lieder");
const u8 gEasyChatWord_Diet[] = _("Diät");
const u8 gEasyChatWord_Treasure[] = _("Schatz");
const u8 gEasyChatWord_Travel[] = _("Reisen");
const u8 gEasyChatWord_Dance[] = _("Tanzen");
const u8 gEasyChatWord_Channel[] = _("Kanal");
const u8 gEasyChatWord_Making[] = _("Machen");
const u8 gEasyChatWord_Fishing[] = _("Angeln");
const u8 gEasyChatWord_Date[] = _("Datum");
const u8 gEasyChatWord_Design[] = _("Design");
const u8 gEasyChatWord_Locomotive[] = _("Lokomotive");
const u8 gEasyChatWord_PlushDoll[] = _("Plüschpuppe");
const u8 gEasyChatWord_Pc[] = _("PC");
const u8 gEasyChatWord_Flowers[] = _("Blumen");
const u8 gEasyChatWord_Hero[] = _("Held");
const u8 gEasyChatWord_Nap[] = _("Nickerchen");
const u8 gEasyChatWord_Heroine[] = _("Heldin");
const u8 gEasyChatWord_Fashion[] = _("Mode");
const u8 gEasyChatWord_Adventure[] = _("Abenteuer");
const u8 gEasyChatWord_Board[] = _("Brett");
const u8 gEasyChatWord_Ball[] = _("Ball");
const u8 gEasyChatWord_Book[] = _("Buch");
const u8 gEasyChatWord_Festival[] = _("Festival");
const u8 gEasyChatWord_Comics[] = _("Comics");
const u8 gEasyChatWord_Holiday[] = _("Urlaub");
const u8 gEasyChatWord_Plans[] = _("Pläne");
const u8 gEasyChatWord_Trendy[] = _("Trend");
const u8 gEasyChatWord_Vacation[] = _("Ferien");
const u8 gEasyChatWord_Look[] = _("Aussehen");

const struct EasyChatWordInfo gEasyChatGroup_Hobbies[] = {
    [EC_INDEX(EC_WORD_IDOL)] =
    {
        .text = COMPOUND_STRING("IDOL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ADVENTURE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ANIME)] =
    {
        .text = COMPOUND_STRING("ANIME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ANIME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SONG)] =
    {
        .text = COMPOUND_STRING("SONG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BALL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MOVIE)] =
    {
        .text = COMPOUND_STRING("MOVIE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BIKE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SWEETS)] =
    {
        .text = COMPOUND_STRING("SWEETS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BOARD),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHAT)] =
    {
        .text = COMPOUND_STRING("CHAT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BOOK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHILD_S_PLAY)] =
    {
        .text = COMPOUND_STRING("CHILD'S PLAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CAMERA),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TOYS)] =
    {
        .text = COMPOUND_STRING("TOYS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CARDS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MUSIC)] =
    {
        .text = COMPOUND_STRING("MUSIC"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHANNEL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CARDS)] =
    {
        .text = COMPOUND_STRING("CARDS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHAT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHOPPING)] =
    {
        .text = COMPOUND_STRING("SHOPPING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHILD_S_PLAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CAMERA)] =
    {
        .text = COMPOUND_STRING("CAMERA"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COLLECTION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VIEWING)] =
    {
        .text = COMPOUND_STRING("VIEWING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COMICS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SPECTATOR)] =
    {
        .text = COMPOUND_STRING("SPECTATOR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_COMPLETE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GOURMET)] =
    {
        .text = COMPOUND_STRING("GOURMET"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DANCE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GAME)] =
    {
        .text = COMPOUND_STRING("GAME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DATE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RPG)] =
    {
        .text = COMPOUND_STRING("RPG"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DESIGN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COLLECTION)] =
    {
        .text = COMPOUND_STRING("COLLECTION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DIET),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COMPLETE)] =
    {
        .text = COMPOUND_STRING("COMPLETE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FASHION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAGAZINE)] =
    {
        .text = COMPOUND_STRING("MAGAZINE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FESTIVAL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WALK)] =
    {
        .text = COMPOUND_STRING("WALK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FISHING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BIKE)] =
    {
        .text = COMPOUND_STRING("BIKE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FLOWERS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOBBY)] =
    {
        .text = COMPOUND_STRING("HOBBY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GAME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SPORTS)] =
    {
        .text = COMPOUND_STRING("SPORTS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GOURMET),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOFTWARE)] =
    {
        .text = COMPOUND_STRING("SOFTWARE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SONGS)] =
    {
        .text = COMPOUND_STRING("SONGS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HEROINE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DIET)] =
    {
        .text = COMPOUND_STRING("DIET"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOBBY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TREASURE)] =
    {
        .text = COMPOUND_STRING("TREASURE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HOLIDAY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRAVEL)] =
    {
        .text = COMPOUND_STRING("TRAVEL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IDOL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DANCE)] =
    {
        .text = COMPOUND_STRING("DANCE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOCOMOTIVE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHANNEL)] =
    {
        .text = COMPOUND_STRING("CHANNEL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LOOK),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAKING)] =
    {
        .text = COMPOUND_STRING("MAKING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAGAZINE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FISHING)] =
    {
        .text = COMPOUND_STRING("FISHING"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAKING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DATE)] =
    {
        .text = COMPOUND_STRING("DATE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOVIE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DESIGN)] =
    {
        .text = COMPOUND_STRING("DESIGN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MUSIC),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOCOMOTIVE)] =
    {
        .text = COMPOUND_STRING("LOCOMOTIVE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_NAP),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLUSH_DOLL)] =
    {
        .text = COMPOUND_STRING("PLUSH DOLL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PC),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PC)] =
    {
        .text = COMPOUND_STRING("PC"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLANS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FLOWERS)] =
    {
        .text = COMPOUND_STRING("FLOWERS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLUSH_DOLL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERO)] =
    {
        .text = COMPOUND_STRING("HERO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RPG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_NAP)] =
    {
        .text = COMPOUND_STRING("NAP"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHOPPING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HEROINE)] =
    {
        .text = COMPOUND_STRING("HEROINE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOFTWARE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FASHION)] =
    {
        .text = COMPOUND_STRING("FASHION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SONG),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ADVENTURE)] =
    {
        .text = COMPOUND_STRING("ADVENTURE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SONGS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BOARD)] =
    {
        .text = COMPOUND_STRING("BOARD"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPECTATOR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BALL)] =
    {
        .text = COMPOUND_STRING("BALL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SPORTS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BOOK)] =
    {
        .text = COMPOUND_STRING("BOOK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SWEETS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FESTIVAL)] =
    {
        .text = COMPOUND_STRING("FESTIVAL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TOYS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_COMICS)] =
    {
        .text = COMPOUND_STRING("COMICS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRAVEL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HOLIDAY)] =
    {
        .text = COMPOUND_STRING("HOLIDAY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TREASURE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLANS)] =
    {
        .text = COMPOUND_STRING("PLANS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TRENDY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TRENDY)] =
    {
        .text = COMPOUND_STRING("TRENDY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VACATION),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_VACATION)] =
    {
        .text = COMPOUND_STRING("VACATION"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_VIEWING),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LOOK)] =
    {
        .text = COMPOUND_STRING("LOOK"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WALK),
        .enabled = TRUE,
    },
};
