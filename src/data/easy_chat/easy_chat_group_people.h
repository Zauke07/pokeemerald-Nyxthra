const u8 gEasyChatWord_Opponent[] = _("Gegner");
const u8 gEasyChatWord_I[] = _("Ich");
const u8 gEasyChatWord_You[] = _("Du");
const u8 gEasyChatWord_Yours[] = _("Deins");
const u8 gEasyChatWord_Son[] = _("Sohn");
const u8 gEasyChatWord_Your[] = _("Dein");
const u8 gEasyChatWord_Youre[] = _("Du bist");
const u8 gEasyChatWord_Youve[] = _("Du hast");
const u8 gEasyChatWord_Mother[] = _("Mutter");
const u8 gEasyChatWord_Grandfather[] = _("Großvater");
const u8 gEasyChatWord_Uncle[] = _("Onkel");
const u8 gEasyChatWord_Father[] = _("Vater");
const u8 gEasyChatWord_Boy[] = _("Junge");
const u8 gEasyChatWord_Adult[] = _("Erwachsener");
const u8 gEasyChatWord_Brother[] = _("Bruder");
const u8 gEasyChatWord_Sister[] = _("Schwester");
const u8 gEasyChatWord_Grandmother[] = _("Großmutter");
const u8 gEasyChatWord_Aunt[] = _("Tante");
const u8 gEasyChatWord_Parent[] = _("Elternteil");
const u8 gEasyChatWord_Man[] = _("Mann");
const u8 gEasyChatWord_Me[] = _("Mich");
const u8 gEasyChatWord_Girl[] = _("Mädchen");
const u8 gEasyChatWord_Babe[] = _("Baby");
const u8 gEasyChatWord_Family[] = _("Familie");
const u8 gEasyChatWord_Her[] = _("Ihr");
const u8 gEasyChatWord_Him[] = _("Ihm");
const u8 gEasyChatWord_He[] = _("Er");
const u8 gEasyChatWord_Place[] = _("Ort");
const u8 gEasyChatWord_Daughter[] = _("Tochter");
const u8 gEasyChatWord_His[] = _("Sein");
const u8 gEasyChatWord_Hes[] = _("Er ist");
const u8 gEasyChatWord_Arent[] = _("Sind nicht");
const u8 gEasyChatWord_Siblings[] = _("Geschwister");
const u8 gEasyChatWord_Kid[] = _("Kind");
const u8 gEasyChatWord_Children[] = _("Kinder");
const u8 gEasyChatWord_Mr[] = _("Herr");
const u8 gEasyChatWord_Mrs[] = _("Frau");
const u8 gEasyChatWord_Myself[] = _("Mich selbst");
const u8 gEasyChatWord_IWas[] = _("Ich war");
const u8 gEasyChatWord_ToMe[] = _("Zu mir");
const u8 gEasyChatWord_My[] = _("Mein");
const u8 gEasyChatWord_IAm[] = _("Ich bin");
const u8 gEasyChatWord_Ive[] = _("Ich habe");
const u8 gEasyChatWord_Who[] = _("Wer");
const u8 gEasyChatWord_Someone[] = _("Jemand");
const u8 gEasyChatWord_WhoWas[] = _("Wer war");
const u8 gEasyChatWord_ToWhom[] = _("Zu wem");
const u8 gEasyChatWord_Whose[] = _("Wessen");
const u8 gEasyChatWord_WhoIs[] = _("Wer ist");
const u8 gEasyChatWord_Its[] = _("Es ist");
const u8 gEasyChatWord_Lady[] = _("Dame");
const u8 gEasyChatWord_Friend[] = _("Freund");
const u8 gEasyChatWord_Ally[] = _("Verbündeter");
const u8 gEasyChatWord_Person[] = _("Person");
const u8 gEasyChatWord_Dude[] = _("Kerl");
const u8 gEasyChatWord_They[] = _("Sie");
const u8 gEasyChatWord_TheyWere[] = _("Sie waren");
const u8 gEasyChatWord_ToThem[] = _("Zu ihnen");
const u8 gEasyChatWord_Their[] = _("Ihr");
const u8 gEasyChatWord_Theyre[] = _("Sie sind");
const u8 gEasyChatWord_Theyve[] = _("Sie haben");
const u8 gEasyChatWord_We[] = _("Wir");
const u8 gEasyChatWord_Been[] = _("Gewesen");
const u8 gEasyChatWord_ToUs[] = _("Zu uns");
const u8 gEasyChatWord_Our[] = _("Unser");
const u8 gEasyChatWord_WeRe[] = _("Wir sind");
const u8 gEasyChatWord_Rival[] = _("Rivale");
const u8 gEasyChatWord_Weve[] = _("Wir haben");
const u8 gEasyChatWord_Woman[] = _("Frau");
const u8 gEasyChatWord_She[] = _("Sie");
const u8 gEasyChatWord_SheWas[] = _("Sie war");
const u8 gEasyChatWord_ToHer[] = _("Zu ihr");
const u8 gEasyChatWord_Hers[] = _("Ihrs");
const u8 gEasyChatWord_SheIs[] = _("Sie ist");
const u8 gEasyChatWord_Some[] = _("Einige");

const struct EasyChatWordInfo gEasyChatGroup_People[] = {
    [EC_INDEX(EC_WORD_OPPONENT)] =
    {
        .text = COMPOUND_STRING("OPPONENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ADULT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_I)] =
    {
        .text = COMPOUND_STRING("I"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ALLY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOU)] =
    {
        .text = COMPOUND_STRING("YOU"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AREN_T),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOURS)] =
    {
        .text = COMPOUND_STRING("YOURS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_AUNT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SON)] =
    {
        .text = COMPOUND_STRING("SON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BABE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOUR)] =
    {
        .text = COMPOUND_STRING("YOUR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BEEN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOU_RE)] =
    {
        .text = COMPOUND_STRING("YOU'RE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BOY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_YOU_VE)] =
    {
        .text = COMPOUND_STRING("YOU'VE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_BROTHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MOTHER)] =
    {
        .text = COMPOUND_STRING("MOTHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_CHILDREN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GRANDFATHER)] =
    {
        .text = COMPOUND_STRING("GRANDFATHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DAUGHTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_UNCLE)] =
    {
        .text = COMPOUND_STRING("UNCLE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_DUDE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FATHER)] =
    {
        .text = COMPOUND_STRING("FATHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FAMILY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BOY)] =
    {
        .text = COMPOUND_STRING("BOY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FATHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ADULT)] =
    {
        .text = COMPOUND_STRING("ADULT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_FRIEND),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BROTHER)] =
    {
        .text = COMPOUND_STRING("BROTHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GIRL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SISTER)] =
    {
        .text = COMPOUND_STRING("SISTER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GRANDFATHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GRANDMOTHER)] =
    {
        .text = COMPOUND_STRING("GRANDMOTHER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_GRANDMOTHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AUNT)] =
    {
        .text = COMPOUND_STRING("AUNT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PARENT)] =
    {
        .text = COMPOUND_STRING("PARENT"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HE_S),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MAN)] =
    {
        .text = COMPOUND_STRING("MAN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ME)] =
    {
        .text = COMPOUND_STRING("ME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HERS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_GIRL)] =
    {
        .text = COMPOUND_STRING("GIRL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BABE)] =
    {
        .text = COMPOUND_STRING("BABE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_HIS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FAMILY)] =
    {
        .text = COMPOUND_STRING("FAMILY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HER)] =
    {
        .text = COMPOUND_STRING("HER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_AM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIM)] =
    {
        .text = COMPOUND_STRING("HIM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_WAS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HE)] =
    {
        .text = COMPOUND_STRING("HE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_I_VE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PLACE)] =
    {
        .text = COMPOUND_STRING("PLACE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_IT_S),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DAUGHTER)] =
    {
        .text = COMPOUND_STRING("DAUGHTER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_KID),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HIS)] =
    {
        .text = COMPOUND_STRING("HIS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_LADY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HE_S)] =
    {
        .text = COMPOUND_STRING("HE'S"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MAN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_AREN_T)] =
    {
        .text = COMPOUND_STRING("AREN'T"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_ME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SIBLINGS)] =
    {
        .text = COMPOUND_STRING("SIBLINGS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MOTHER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_KID)] =
    {
        .text = COMPOUND_STRING("KID"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_CHILDREN)] =
    {
        .text = COMPOUND_STRING("CHILDREN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MRS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MR)] =
    {
        .text = COMPOUND_STRING("MR."),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MRS)] =
    {
        .text = COMPOUND_STRING("MRS."),
        .alphabeticalOrder = EC_INDEX(EC_WORD_MYSELF),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MYSELF)] =
    {
        .text = COMPOUND_STRING("MYSELF"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OPPONENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_I_WAS)] =
    {
        .text = COMPOUND_STRING("I WAS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_OUR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO_ME)] =
    {
        .text = COMPOUND_STRING("TO ME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PARENT),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_MY)] =
    {
        .text = COMPOUND_STRING("MY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PERSON),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_I_AM)] =
    {
        .text = COMPOUND_STRING("I AM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_PLACE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_I_VE)] =
    {
        .text = COMPOUND_STRING("I'VE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_RIVAL),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHO)] =
    {
        .text = COMPOUND_STRING("WHO"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOMEONE)] =
    {
        .text = COMPOUND_STRING("SOMEONE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHE_IS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHO_WAS)] =
    {
        .text = COMPOUND_STRING("WHO WAS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SHE_WAS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO_WHOM)] =
    {
        .text = COMPOUND_STRING("TO WHOM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SIBLINGS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHOSE)] =
    {
        .text = COMPOUND_STRING("WHOSE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SISTER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WHO_IS)] =
    {
        .text = COMPOUND_STRING("WHO IS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_IT_S)] =
    {
        .text = COMPOUND_STRING("IT'S"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SOMEONE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_LADY)] =
    {
        .text = COMPOUND_STRING("LADY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_SON),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_FRIEND)] =
    {
        .text = COMPOUND_STRING("FRIEND"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEIR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_ALLY)] =
    {
        .text = COMPOUND_STRING("ALLY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEY),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_PERSON)] =
    {
        .text = COMPOUND_STRING("PERSON"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEY_WERE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_DUDE)] =
    {
        .text = COMPOUND_STRING("DUDE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEY_RE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THEY)] =
    {
        .text = COMPOUND_STRING("THEY"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_THEY_VE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THEY_WERE)] =
    {
        .text = COMPOUND_STRING("THEY WERE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_HER),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO_THEM)] =
    {
        .text = COMPOUND_STRING("TO THEM"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_ME),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THEIR)] =
    {
        .text = COMPOUND_STRING("THEIR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_THEM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THEY_RE)] =
    {
        .text = COMPOUND_STRING("THEY'RE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_US),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_THEY_VE)] =
    {
        .text = COMPOUND_STRING("THEY'VE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_TO_WHOM),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WE)] =
    {
        .text = COMPOUND_STRING("WE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_UNCLE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_BEEN)] =
    {
        .text = COMPOUND_STRING("BEEN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO_US)] =
    {
        .text = COMPOUND_STRING("TO US"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WE_RE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_OUR)] =
    {
        .text = COMPOUND_STRING("OUR"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WE_VE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WE_RE)] =
    {
        .text = COMPOUND_STRING("WE'RE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHO),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_RIVAL)] =
    {
        .text = COMPOUND_STRING("RIVAL"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHO_IS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WE_VE)] =
    {
        .text = COMPOUND_STRING("WE'VE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHO_WAS),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_WOMAN)] =
    {
        .text = COMPOUND_STRING("WOMAN"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WHOSE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHE)] =
    {
        .text = COMPOUND_STRING("SHE"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_WOMAN),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHE_WAS)] =
    {
        .text = COMPOUND_STRING("SHE WAS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOU),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_TO_HER)] =
    {
        .text = COMPOUND_STRING("TO HER"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOU_RE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_HERS)] =
    {
        .text = COMPOUND_STRING("HERS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOU_VE),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SHE_IS)] =
    {
        .text = COMPOUND_STRING("SHE IS"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOUR),
        .enabled = TRUE,
    },
    [EC_INDEX(EC_WORD_SOME)] =
    {
        .text = COMPOUND_STRING("SOME"),
        .alphabeticalOrder = EC_INDEX(EC_WORD_YOURS),
        .enabled = TRUE,
    },
};
