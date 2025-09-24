extern const u8 EventScript_FollowerIsShivering[];
extern const u8 EventScript_FollowerNostalgia[];
extern const u8 EventScript_FollowerHopping[];
extern const u8 EventScript_FollowerJumpOnPlayer[];
extern const u8 EventScript_FollowerCuddling[];
extern const u8 EventScript_FollowerShiverCuddling[];
extern const u8 EventScript_FollowerGetCloser[];
extern const u8 EventScript_FollowerPokingPlayer[];
extern const u8 EventScript_FollowerLookAround[];
extern const u8 EventScript_FollowerLookAway[];
extern const u8 EventScript_FollowerLookAwayBark[];
extern const u8 EventScript_FollowerLookAwayPoke[];
extern const u8 EventScript_FollowerPokeGround[];
extern const u8 EventScript_FollowerStartled[];
extern const u8 EventScript_FollowerFastHopping[];
extern const u8 EventScript_FollowerDizzy[];
extern const u8 EventScript_FollowerLookAroundScared[];
extern const u8 EventScript_FollowerDance[];
extern const u8 EventScript_FollowerLookUp[];

// 'Generic', unconditional happy messages
static const u8 sHappyMsg00[] = _("Dein {STR_VAR_1} begann, dich im\nBauch zu stupsen.");
static const u8 sHappyMsg01[] = _("Dein {STR_VAR_1} ist glücklich, aber schüchtern.");
static const u8 sHappyMsg02[] = _("Dein {STR_VAR_1} kommt fröhlich mit.");
static const u8 sHappyMsg03[] = _("Dein {STR_VAR_1} ist gelassen.");
static const u8 sHappyMsg04[] = _("Dein {STR_VAR_1} scheint sich großartig zu fühlen,\nmit dir zu laufen!");
static const u8 sHappyMsg05[] = _("Dein {STR_VAR_1} strahlt vor Gesundheit.");
static const u8 sHappyMsg06[] = _("Dein {STR_VAR_1} sieht sehr glücklich aus.");
static const u8 sHappyMsg07[] = _("Dein {STR_VAR_1} hat sich besonders angestrengt.");
static const u8 sHappyMsg08[] = _("Dein {STR_VAR_1} riecht die Düfte\nder Umgebung.");
static const u8 sHappyMsg09[] = _("Dein {STR_VAR_1} springt vor Freude!");
static const u8 sHappyMsg10[] = _("Dein {STR_VAR_1} fühlt sich immer noch großartig!");
static const u8 sHappyMsg11[] = _("Dein POKéMON hat den Geruch von\nRauch wahrgenommen.");
static const u8 sHappyMsg12[] = _("Dein {STR_VAR_1} stupst an deinen Bauch.");
static const u8 sHappyMsg13[] = _("Dein POKéMON hat sich ausgestreckt\nund entspannt sich.");
static const u8 sHappyMsg14[] = _("Dein {STR_VAR_1} sieht aus, als wolle es\nführen!");
static const u8 sHappyMsg15[] = _("Dein {STR_VAR_1} gibt sein Bestes, um\nmit dir Schritt zu halten.");
static const u8 sHappyMsg16[] = _("Dein {STR_VAR_1} kuschelt sich glücklich\nan dich!");
static const u8 sHappyMsg17[] = _("Dein {STR_VAR_1} ist voller Leben!");
static const u8 sHappyMsg18[] = _("Dein {STR_VAR_1} scheint sehr glücklich zu sein!");
static const u8 sHappyMsg19[] = _("Dein {STR_VAR_1} ist so glücklich, dass es\nnicht stillstehen kann!");
static const u8 sHappyMsg20[] = _("Dein {STR_VAR_1} nickte langsam.");
static const u8 sHappyMsg21[] = _("Dein {STR_VAR_1} ist sehr eifrig!");
static const u8 sHappyMsg22[] = _("Dein {STR_VAR_1} wandert umher und\nlauscht den verschiedenen Geräuschen.");
static const u8 sHappyMsg23[] = _("Dein {STR_VAR_1} sieht sehr interessiert aus.");
static const u8 sHappyMsg24[] = _("Dein {STR_VAR_1} zwingt sich irgendwie,\nweiterzumachen.");
static const u8 sHappyMsg25[] = _("Dein {STR_VAR_1} hat dir einen sonnigen Blick zugeworfen!");
static const u8 sHappyMsg26[] = _("Dein {STR_VAR_1} gibt dir einen glücklichen Blick\nund ein Lächeln.");
static const u8 sHappyMsg27[] = _("Dein POKéMON riecht den Duft\nvon Blumen.");
static const u8 sHappyMsg28[] = _("Dein {STR_VAR_1} scheint sehr glücklich zu sein,\ndich zu sehen!");
static const u8 sHappyMsg29[] = _("Dein {STR_VAR_1} drehte sich um und\ngrinst.");
static const u8 sHappyMsg30[] = _("Dein {STR_VAR_1} kuschelte sich glücklich\nan dich!");
// Conditional messages begin here, index 31
static const u8 sHappyMsg31[] = _("Dein POKéMON scheint glücklich über das\ngute Wetter zu sein.");
static const u8 sHappyMsg32[] = _("Dein {STR_VAR_1} ist sehr gelassen und\nselbstsicher!");

const struct FollowerMsgInfo gFollowerHappyMessages[] = {
    {sHappyMsg00, EventScript_FollowerPokingPlayer},
    {sHappyMsg01}, {sHappyMsg02}, {sHappyMsg03}, {sHappyMsg04}, {sHappyMsg05}, {sHappyMsg06}, {sHappyMsg07},
    {sHappyMsg08, EventScript_FollowerLookAround},
    {sHappyMsg09, EventScript_FollowerHopping},
    {sHappyMsg10}, {sHappyMsg11},
    {sHappyMsg12, EventScript_FollowerPokingPlayer},
    {sHappyMsg13, EventScript_FollowerLookAround},
    {sHappyMsg14}, {sHappyMsg15},
    {sHappyMsg16, EventScript_FollowerCuddling},
    {sHappyMsg17}, {sHappyMsg18},
    {sHappyMsg19, EventScript_FollowerFastHopping},
    {sHappyMsg20}, {sHappyMsg21}, {sHappyMsg22}, {sHappyMsg23}, {sHappyMsg24}, {sHappyMsg25}, {sHappyMsg26}, {sHappyMsg27}, {sHappyMsg28}, {sHappyMsg29},
    {sHappyMsg30, EventScript_FollowerCuddling},
    {sHappyMsg31}, {sHappyMsg32},
};

// Unconditional neutral messages
static const u8 sNeutralMsg00[] = _("Dein {STR_VAR_1} stupst stetig auf\nden Boden.");
static const u8 sNeutralMsg01[] = _("Dein {STR_VAR_1} steht Wache.");
static const u8 sNeutralMsg02[] = _("Dein {STR_VAR_1} starrt geduldig\nins Nichts.");
static const u8 sNeutralMsg03[] = _("Dein {STR_VAR_1} wandert umher.");
static const u8 sNeutralMsg04[] = _("Dein POKéMON gähnte laut!");
static const u8 sNeutralMsg05[] = _("Dein POKéMON schaut sich\nunruhig um.");
static const u8 sNeutralMsg06[] = _("Dein {STR_VAR_1} schaut in diese\nRichtung und lächelt.");
static const u8 sNeutralMsg07[] = _("Dein {STR_VAR_1} blickt unruhig\numher.");
static const u8 sNeutralMsg08[] = _("Dein {STR_VAR_1} ließ einen\nKampfschrei los.");
static const u8 sNeutralMsg09[] = _("Dein {STR_VAR_1} tanzte einen\nwunderbaren Tanz!");
static const u8 sNeutralMsg10[] = _("Dein {STR_VAR_1} ist sehr eifrig.");
static const u8 sNeutralMsg11[] = _("Dein {STR_VAR_1} starrt intensiv\nin die Ferne.");
static const u8 sNeutralMsg12[] = _("Dein {STR_VAR_1} hält Ausschau!");
static const u8 sNeutralMsg13[] = _("Dein {STR_VAR_1} schaute in die\nFerne und bellte!");

const struct FollowerMsgInfo gFollowerNeutralMessages[] = {
    {sNeutralMsg00, EventScript_FollowerPokeGround},
    {sNeutralMsg01},
    {sNeutralMsg02, EventScript_FollowerLookAway},
    {sNeutralMsg03, EventScript_FollowerLookAround},
    {sNeutralMsg04},
    {sNeutralMsg05, EventScript_FollowerLookAround},
    {sNeutralMsg06}, {sNeutralMsg07}, {sNeutralMsg08},
    {sNeutralMsg09, EventScript_FollowerDance},
    {sNeutralMsg10},
    {sNeutralMsg11, EventScript_FollowerLookAway},
    {sNeutralMsg12},
    {sNeutralMsg13, EventScript_FollowerLookAwayBark},
};

// Unconditional sad messages
static const u8 sSadMsg00[] = _("{STR_VAR_1} ist schwindelig.");
static const u8 sSadMsg01[] = _("{STR_VAR_1} tritt auf deine\nFüße!");
static const u8 sSadMsg02[] = _("{STR_VAR_1} scheint ein wenig müde zu sein.");
// Conditional messages begin, index 3
static const u8 sSadMsg03[] = _("{STR_VAR_1} ist nicht glücklich.");
static const u8 sSadMsg04[] = _("{STR_VAR_1} wird gleich umfallen!\n");
static const u8 sSadMsg05[] = _("{STR_VAR_1} scheint gleich umzufallen!");
static const u8 sSadMsg06[] = _("{STR_VAR_1} versucht sehr, mit dir\nSchritt zu halten…");
static const u8 sSadMsg07[] = _("{STR_VAR_1} ist nervös.");

const struct FollowerMsgInfo gFollowerSadMessages[] = {
    {sSadMsg00, EventScript_FollowerDizzy},
    {sSadMsg01}, {sSadMsg02},
    {sSadMsg03}, {sSadMsg04}, {sSadMsg05}, {sSadMsg06}, {sSadMsg07},
};

// Unconditional upset messages
static const u8 sUpsetMsg00[] = _("{STR_VAR_1} scheint irgendwie unglücklich\nzu sein…");
static const u8 sUpsetMsg01[] = _("{STR_VAR_1} macht ein unglückliches\nGesicht.");
static const u8 sUpsetMsg02[] = _("…Dein POKéMON scheint ein wenig\nkalt zu sein.");
// Conditional messages, index 3
static const u8 sUpsetMsg03[] = _("{STR_VAR_1} sucht im Gras Schutz vor dem\nRegen.");

const struct FollowerMsgInfo gFollowerUpsetMessages[] = {
    {sUpsetMsg00}, {sUpsetMsg01},
    {sUpsetMsg02, EventScript_FollowerIsShivering},
    {sUpsetMsg03},
};

// Unconditional angry messages
static const u8 sAngryMsg00[] = _("{STR_VAR_1} hat ein Brüllen ausgestoßen!");
static const u8 sAngryMsg01[] = _("{STR_VAR_1} macht ein Gesicht, als ob\nes wütend wäre!");
static const u8 sAngryMsg02[] = _("{STR_VAR_1} scheint aus irgendeinem Grund\nwütend zu sein.");
static const u8 sAngryMsg03[] = _("Dein POKéMON drehte sich um und zeigte\nein trotziges Gesicht.");
static const u8 sAngryMsg04[] = _("{STR_VAR_1} hat geschrien.");

const struct FollowerMsgInfo gFollowerAngryMessages[] = {
    {sAngryMsg00}, {sAngryMsg01}, {sAngryMsg02},
    {sAngryMsg03, EventScript_FollowerLookAway},
    {sAngryMsg04},
};

// Unconditional pensive messages
static const u8 sPensiveMsg00[] = _("Dein {STR_VAR_1} schaut stetig\nnach unten.");
static const u8 sPensiveMsg01[] = _("Dein {STR_VAR_1} beobachtet die\nUmgebung.");
static const u8 sPensiveMsg02[] = _("Dein {STR_VAR_1} schaut nach unten.");
static const u8 sPensiveMsg03[] = _("Dein {STR_VAR_1} kämpft irgendwie\ngegen den Schlaf…");
static const u8 sPensiveMsg04[] = _("Dein {STR_VAR_1} scheint umherzuwandern.");
static const u8 sPensiveMsg05[] = _("Dein {STR_VAR_1} schaut gedankenverloren\numher.");
static const u8 sPensiveMsg06[] = _("Dein {STR_VAR_1} hat sehr laut gegähnt!");
static const u8 sPensiveMsg07[] = _("Dein {STR_VAR_1} entspannt sich bequem.");
static const u8 sPensiveMsg08[] = _("Dein {STR_VAR_1} starrt dir fest ins\nGesicht.");
static const u8 sPensiveMsg09[] = _("Dein {STR_VAR_1} starrt dir intensiv ins\nGesicht.");
static const u8 sPensiveMsg10[] = _("Dein {STR_VAR_1} konzentriert seine\nAufmerksamkeit auf dich.");
static const u8 sPensiveMsg11[] = _("Dein {STR_VAR_1} starrt in die\nTiefe.");
static const u8 sPensiveMsg12[] = _("Dein {STR_VAR_1} schnüffelt am\nBoden.");
static const u8 sPensiveMsg13[] = _("Dein POKéMON starrt intensiv ins\nNichts.");
static const u8 sPensiveMsg14[] = _("Dein {STR_VAR_1} fokussiert mit einem\nscharfen Blick!");
static const u8 sPensiveMsg15[] = _("Dein {STR_VAR_1} konzentriert sich.");
static const u8 sPensiveMsg16[] = _("Dein {STR_VAR_1} schaute in diese\nRichtung und nickte.");
static const u8 sPensiveMsg17[] = _("Dein {STR_VAR_1} scheint ein wenig nervös\nzu sein…");
static const u8 sPensiveMsg18[] = _("Dein {STR_VAR_1} schaut auf deine\nFußabdrücke.");
static const u8 sPensiveMsg19[] = _("Dein {STR_VAR_1} starrt dir direkt in die\nAugen.");

const struct FollowerMsgInfo gFollowerPensiveMessages[] = {
    {sPensiveMsg00},
    {sPensiveMsg01, EventScript_FollowerLookAround},
    {sPensiveMsg02}, {sPensiveMsg03}, {sPensiveMsg04},
    {sPensiveMsg05, EventScript_FollowerLookAround},
    {sPensiveMsg06}, {sPensiveMsg07}, {sPensiveMsg08}, {sPensiveMsg09}, {sPensiveMsg10},
    {sPensiveMsg11, EventScript_FollowerLookAway},
    {sPensiveMsg12, EventScript_FollowerPokeGround},
    {sPensiveMsg13, EventScript_FollowerLookAway},
    {sPensiveMsg14}, {sPensiveMsg15}, {sPensiveMsg16}, {sPensiveMsg17}, {sPensiveMsg18}, {sPensiveMsg19},
};

// All 'love' messages are unconditional
static const u8 sLoveMsg00[] = _("Dein {STR_VAR_1} begann plötzlich,\nenger zu laufen!");
static const u8 sLoveMsg01[] = _("Dein {STR_VAR_1} Wangen werden\nrosig!");
static const u8 sLoveMsg02[] = _("Wow! {STR_VAR_1} hat dich plötzlich\numarmt!");
static const u8 sLoveMsg03[] = _("Wow! {STR_VAR_1} ist plötzlich\nverspielt!");
static const u8 sLoveMsg04[] = _("Dein {STR_VAR_1} reibt sich an deinen\nBeinen!");
static const u8 sLoveMsg05[] = _("Dein {STR_VAR_1} errötet.");
static const u8 sLoveMsg06[] = _("Ah! {STR_VAR_1} kuschelt sich an dich!");
static const u8 sLoveMsg07[] = _("Dein {STR_VAR_1} betrachtet dich mit\nBewunderung!");
static const u8 sLoveMsg08[] = _("Dein {STR_VAR_1} kam näher zu dir.");
static const u8 sLoveMsg09[] = _("Dein {STR_VAR_1} bleibt nah an deinen\nFüßen.");

const struct FollowerMsgInfo gFollowerLoveMessages[] = {
    {sLoveMsg00, EventScript_FollowerGetCloser},
    {sLoveMsg01},
    {sLoveMsg02, EventScript_FollowerCuddling},
    {sLoveMsg03},
    {sLoveMsg04, EventScript_FollowerCuddling},
    {sLoveMsg05},
    {sLoveMsg06, EventScript_FollowerCuddling},
    {sLoveMsg07},
    {sLoveMsg08, EventScript_FollowerGetCloser},
    {sLoveMsg09},
};

// Unconditional surprised messages
static const u8 sSurpriseMsg00[] = _("Dein {STR_VAR_1} ist in Gefahr,\numzufallen!");
static const u8 sSurpriseMsg01[] = _("Dein {STR_VAR_1} ist gegen dich\ngelaufen!");
static const u8 sSurpriseMsg02[] = _("Dein {STR_VAR_1} scheint seinen\nNamen noch nicht zu kennen.");
static const u8 sSurpriseMsg03[] = _("Dein {STR_VAR_1} schaut nach unten.");
static const u8 sSurpriseMsg04[] = _("Dein POKéMON stolperte und fiel\nfast!");
static const u8 sSurpriseMsg05[] = _("Dein {STR_VAR_1} fühlt etwas und\nheult!");
static const u8 sSurpriseMsg06[] = _("Dein {STR_VAR_1} scheint erfrischt!");
static const u8 sSurpriseMsg07[] = _("Dein {STR_VAR_1} drehte sich plötzlich\num und bellte!");
static const u8 sSurpriseMsg08[] = _("Dein {STR_VAR_1} drehte sich plötzlich\num!");
static const u8 sSurpriseMsg09[] = _("Dein POKéMON war überrascht, dass du\nplötzlich mit ihm gesprochen hast!");
static const u8 sSurpriseMsg10[] = _("Schnüff schnüff, etwas riecht sehr\ngut!");
static const u8 sSurpriseMsg11[] = _("Dein {STR_VAR_1} fühlt sich erfrischt.");
static const u8 sSurpriseMsg12[] = _("Dein {STR_VAR_1} wackelt und scheint\numzufallen.");
static const u8 sSurpriseMsg13[] = _("Dein {STR_VAR_1} ist in Gefahr,\numzufallen.");
static const u8 sSurpriseMsg14[] = _("Dein {STR_VAR_1} geht vorsichtig\nvoran.");
static const u8 sSurpriseMsg15[] = _("Dein {STR_VAR_1} wird angespannt vor\nnervöser Energie.");
static const u8 sSurpriseMsg16[] = _("Dein {STR_VAR_1} spürte etwas\nSeltsames und war überrascht!");
static const u8 sSurpriseMsg17[] = _("Dein {STR_VAR_1} hat Angst und kuschelte\nsich an dich!");
static const u8 sSurpriseMsg18[] = _("Dein {STR_VAR_1} fühlt eine ungewöhnliche\nPräsenz…");
static const u8 sSurpriseMsg19[] = _("Dein {STR_VAR_1} wird angespannt vor\nnervöser Energie.");
// Conditional messages, index 20
static const u8 sSurpriseMsg20[] = _("Dein {STR_VAR_1} scheint sehr\nüberrascht zu sein, dass es regnet!");

const struct FollowerMsgInfo gFollowerSurpriseMessages[] = {
    {sSurpriseMsg00},
    {sSurpriseMsg01, EventScript_FollowerPokingPlayer},
    {sSurpriseMsg02}, {sSurpriseMsg03}, {sSurpriseMsg04}, {sSurpriseMsg05}, {sSurpriseMsg06},
    {sSurpriseMsg07, EventScript_FollowerLookAwayBark},
    {sSurpriseMsg08, EventScript_FollowerLookAway},
    {sSurpriseMsg09},
    {sSurpriseMsg10, EventScript_FollowerLookAround},
    {sSurpriseMsg11}, {sSurpriseMsg12}, {sSurpriseMsg13}, {sSurpriseMsg14}, {sSurpriseMsg15}, {sSurpriseMsg16},
    {sSurpriseMsg17, EventScript_FollowerCuddling},
    {sSurpriseMsg18},
    {sSurpriseMsg19, EventScript_FollowerLookAround},
    {sSurpriseMsg20},
};

// Unconditional curious messages
static const u8 sCuriousMsg00[] = _("Dein POKéMON schaut sich\nunruhig nach etwas um.");
static const u8 sCuriousMsg01[] = _("Dein POKéMON hat nicht aufgepasst\nund ist gegen dich gelaufen!");
static const u8 sCuriousMsg02[] = _("Schnüff, schnüff! Ist da etwas\nin der Nähe?");
static const u8 sCuriousMsg03[] = _("Dein {STR_VAR_1} rollt spielerisch\neinen Kieselstein herum.");
static const u8 sCuriousMsg04[] = _("Dein {STR_VAR_1} wandert umher und\nsucht nach etwas.");
static const u8 sCuriousMsg05[] = _("Dein {STR_VAR_1} schnüffelt an dir.");
static const u8 sCuriousMsg06[] = _("Dein {STR_VAR_1} scheint ein wenig\nzögerlich…");

const struct FollowerMsgInfo gFollowerCuriousMessages[] = {
    {sCuriousMsg00, EventScript_FollowerLookAround},
    {sCuriousMsg01, EventScript_FollowerPokingPlayer},
    {sCuriousMsg02}, {sCuriousMsg03},
    {sCuriousMsg04, EventScript_FollowerLookAround},
    {sCuriousMsg05}, {sCuriousMsg06},
};

// Unconditional music messages
static const u8 sMusicMsg00[] = _("Dein {STR_VAR_1} zeigt seine\nBeweglichkeit!");
static const u8 sMusicMsg01[] = _("Dein {STR_VAR_1} bewegt sich\nfröhlich!");
static const u8 sMusicMsg02[] = _("Wow! {STR_VAR_1} begann plötzlich,\nvor Freude zu tanzen!");
static const u8 sMusicMsg03[] = _("Dein {STR_VAR_1} hält stetig mit\ndir Schritt!");
static const u8 sMusicMsg04[] = _("Dein {STR_VAR_1} scheint mit dir\nspielen zu wollen.");
static const u8 sMusicMsg05[] = _("Dein {STR_VAR_1} hüpft fröhlich\nherum.");
static const u8 sMusicMsg06[] = _("Dein {STR_VAR_1} singt und summt.");
static const u8 sMusicMsg07[] = _("Dein {STR_VAR_1} knabbert an deinen\nFüßen!");
static const u8 sMusicMsg08[] = _("Dein {STR_VAR_1} dreht sich um und\nschaut dich an.");
static const u8 sMusicMsg09[] = _("Dein {STR_VAR_1} arbeitet hart, um seine\nmächtige Kraft zu zeigen!");
static const u8 sMusicMsg10[] = _("Wow! {STR_VAR_1} tanzte plötzlich vor\nFreude!");
static const u8 sMusicMsg11[] = _("Dein {STR_VAR_1} ist fröhlich!");
static const u8 sMusicMsg12[] = _("Dein {STR_VAR_1} hüpft sorglos\nherum!");
static const u8 sMusicMsg13[] = _("Dein POKéMON scheint einen\nnostalgisch vertrauten Duft zu riechen…");
// Conditional music messages, index 14
static const u8 sMusicMsg14[] = _("Dein {STR_VAR_1} ist sehr glücklich über\nden Regen.");

const struct FollowerMsgInfo gFollowerMusicMessages[] = {
    {sMusicMsg00, EventScript_FollowerLookAround},
    {sMusicMsg01},
    {sMusicMsg02, EventScript_FollowerDance},
    {sMusicMsg03},
    {sMusicMsg04, EventScript_FollowerHopping},
    {sMusicMsg05, EventScript_FollowerHopping},
    {sMusicMsg06}, {sMusicMsg07}, {sMusicMsg08}, {sMusicMsg09},
    {sMusicMsg10, EventScript_FollowerDance},
    {sMusicMsg11},
    {sMusicMsg12, EventScript_FollowerHopping},
    {sMusicMsg13, EventScript_FollowerNostalgia},
    {sMusicMsg14}
};


static const u8 sPoisonedMsg00[] = _("{STR_VAR_1} zittert aufgrund der\nWirkung des Gifts.");

const struct FollowerMsgInfo gFollowerPoisonedMessages[] = {
    {sPoisonedMsg00, EventScript_FollowerIsShivering},
};
