#include "global.h"
#include "battle.h"
#include "battle_anim.h"
#include "battle_controllers.h"
#include "battle_message.h"
#include "battle_setup.h"
#include "battle_tower.h"
#include "battle_z_move.h"
#include "data.h"
#include "event_data.h"
#include "frontier_util.h"
#include "graphics.h"
#include "international_string_util.h"
#include "item.h"
#include "link.h"
#include "menu.h"
#include "palette.h"
#include "recorded_battle.h"
#include "string_util.h"
#include "strings.h"
#include "test_runner.h"
#include "text.h"
#include "trainer_hill.h"
#include "trainer_slide.h"
#include "window.h"
#include "line_break.h"
#include "constants/abilities.h"
#include "constants/battle_dome.h"
#include "constants/battle_string_ids.h"
#include "constants/frontier_util.h"
#include "constants/items.h"
#include "constants/moves.h"
#include "constants/opponents.h"
#include "constants/species.h"
#include "constants/trainers.h"
#include "constants/trainer_hill.h"
#include "constants/weather.h"

struct BattleWindowText
{
    u8 fillValue;
    u8 fontId;
    u8 x;
    u8 y;
    u8 letterSpacing;
    u8 lineSpacing;
    u8 speed;
    u8 fgColor;
    u8 bgColor;
    u8 shadowColor;
};

#if TESTING
EWRAM_DATA u16 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
#else
static EWRAM_DATA u16 sBattlerAbilities[MAX_BATTLERS_COUNT] = {0};
#endif
EWRAM_DATA struct BattleMsgData *gBattleMsgDataPtr = NULL;

// todo: make some of those names less vague: attacker/target vs pkmn, etc.

static const u8 sText_EmptyString4[] = _("");

const u8 gText_PkmnShroudedInMist[] = _("{B_ATK_TEAM1} Team wurde in Nebel gehüllt!");
const u8 gText_PkmnGettingPumped[] = _("{B_DEF_NAME_WITH_PREFIX} ist aufgeregt!");
const u8 gText_PkmnsXPreventsSwitching[] = _("{B_BUFF1} verhindert das Auswechseln mit seiner Fähigkeit {B_LAST_ABILITY}!\p");
const u8 gText_StatSharply[] = _("stark ");
const u8 gText_StatRose[] = _("stieg!");
const u8 gText_StatFell[] = _("Sinkt!");
const u8 gText_DefendersStatRose[] = _("{B_BUFF1} von {B_DEF_NAME_WITH_PREFIX} {B_BUFF2}");
static const u8 sText_GotAwaySafely[] = _("{PLAY_SE SE_FLEE}Du bist sicher entkommen!\p");
static const u8 sText_PlayerDefeatedLinkTrainer[] = _("Du hast {B_LINK_OPPONENT1_NAME} besiegt!");
static const u8 sText_TwoLinkTrainersDefeated[] = _("Du hast {B_LINK_OPPONENT1_NAME} und {B_LINK_OPPONENT2_NAME} besiegt!");
static const u8 sText_PlayerLostAgainstLinkTrainer[] = _("Du hast gegen {B_LINK_OPPONENT1_NAME} verloren!");
static const u8 sText_PlayerLostToTwo[] = _("Du hast gegen {B_LINK_OPPONENT1_NAME} und {B_LINK_OPPONENT2_NAME} verloren!");
static const u8 sText_PlayerBattledToDrawLinkTrainer[] = _("Du hast unentschieden gegen {B_LINK_OPPONENT1_NAME} gekämpft!");
static const u8 sText_PlayerBattledToDrawVsTwo[] = _("Du hast unentschieden gegen {B_LINK_OPPONENT1_NAME} und {B_LINK_OPPONENT2_NAME} gekämpft!");
static const u8 sText_WildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} ist geflohen!"); //not in gen 5+, replaced with match was forfeited text
static const u8 sText_TwoWildFled[] = _("{PLAY_SE SE_FLEE}{B_LINK_OPPONENT1_NAME} und {B_LINK_OPPONENT2_NAME} sind geflohen!"); //not in gen 5+, replaced with match was forfeited text
static const u8 sText_PlayerDefeatedLinkTrainerTrainer1[] = _("Du hast {B_TRAINER1_NAME_WITH_CLASS} besiegt!\p");
static const u8 sText_OpponentMon1Appeared[] = _("{B_OPPONENT_MON1_NAME} erscheint!\p");
static const u8 sText_WildPkmnAppeared[] = _("Ein Wildes {B_OPPONENT_MON1_NAME} taucht auf!\p");
static const u8 sText_LegendaryPkmnAppeared[] = _("Das Legendäre {B_OPPONENT_MON1_NAME} taucht auf!\p");
static const u8 sText_WildPkmnAppearedPause[] = _("Ein Wildes {B_OPPONENT_MON1_NAME} taucht auf!\p{PAUSE 127}");
static const u8 sText_TwoWildPkmnAppeared[] = _("Oh! Ein wildes {B_OPPONENT_MON1_NAME} und {B_OPPONENT_MON2_NAME} erscheinen!\p");
static const u8 sText_WildShinyPkmnAppeared[] = _("Ein Wildes {COLOR RED}Shiny {B_OPPONENT_MON1_NAME}{COLOR WHITE} taucht auf!\p");
static const u8 sText_TwoWildShinyPkmnAppeared[] = _("Ein Wildes {COLOR RED}{SHADOW GREEN}Shiny{COLOR WHITE} {B_OPPONENT_MON1_NAME} und ein Wildes\n{COLOR RED}{SHADOW GREEN}Shiny{COLOR WHITE} {B_OPPONENT_MON2_NAME} tauchen auf!\p");
static const u8 sText_Trainer1WantsToBattle[] = _("Eine Herausvorderung von\n{B_TRAINER1_NAME_WITH_CLASS}!\p");
static const u8 sText_LinkTrainerWantsToBattle[] = _("Du wirst von {B_LINK_OPPONENT1_NAME} herausgefordert!");
static const u8 sText_TwoLinkTrainersWantToBattle[] = _("Du wirst von {B_LINK_OPPONENT1_NAME} und {B_LINK_OPPONENT2_NAME} herausgefordert!");
static const u8 sText_Trainer1SentOutPkmn[] = _("{B_TRAINER1_NAME_WITH_CLASS} schickt {B_OPPONENT_MON1_NAME} in den Kampf!");
static const u8 sText_Trainer1SentOutTwoPkmn[] = _("{B_TRAINER1_NAME_WITH_CLASS} schickt {B_OPPONENT_MON1_NAME} und {B_OPPONENT_MON2_NAME} in den Kampf!");
const u8 sText_Trainer1SentOutPkmn2[] = _("{B_TRAINER1_NAME_WITH_CLASS} schickt {B_BUFF1} in den Kampf!");
static const u8 sText_LinkTrainerSentOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} schickt {B_OPPONENT_MON1_NAME} in den Kampf!");
static const u8 sText_LinkTrainerSentOutTwoPkmn[] = _("{B_LINK_OPPONENT1_NAME} schickt {B_OPPONENT_MON1_NAME} und {B_OPPONENT_MON2_NAME} in den Kampf!");
static const u8 sText_TwoLinkTrainersSentOutPkmn[] = _("{B_LINK_OPPONENT1_NAME} schickt {B_LINK_OPPONENT_MON1_NAME} in den Kampf! {B_LINK_OPPONENT2_NAME} schickte {B_LINK_OPPONENT_MON2_NAME} in den Kampf!");
static const u8 sText_LinkTrainerSentOutPkmn2[] = _("{B_LINK_OPPONENT1_NAME} schickt {B_BUFF1} in den Kampf!");
static const u8 sText_LinkTrainerMultiSentOutPkmn[] = _("{B_LINK_SCR_TRAINER_NAME} schickt {B_BUFF1} in den Kampf!");
static const u8 sText_GoPkmn[] = _("Los! {B_PLAYER_MON1_NAME}!");
static const u8 sText_GoTwoPkmn[] = _("Los! {B_PLAYER_MON1_NAME} und {B_PLAYER_MON2_NAME}!");
static const u8 sText_GoPkmn2[] = _("Los! {B_BUFF1}!");
static const u8 sText_DoItPkmn[] = _("Du bist dran, {B_BUFF1}!");
static const u8 sText_GoForItPkmn[] = _("Gib dein Bestes, {B_BUFF1}!");
static const u8 sText_JustALittleMorePkmn[] = _("Nur noch ein bisschen! Halte durch, {B_BUFF1}!"); //currently unused, will require code changes
static const u8 sText_YourFoesWeakGetEmPkmn[] = _("Dein Gegner ist schwach! Schnapp ihn dir, {B_BUFF1}!");
static const u8 sText_LinkPartnerSentOutPkmnGoPkmn[] = _("{B_LINK_PARTNER_NAME} schickt {B_LINK_PLAYER_MON2_NAME} in den Kampf! Los! {B_LINK_PLAYER_MON1_NAME}!");
static const u8 sText_PkmnSwitchOut[] = _("{B_BUFF1}, wechsel aus! Komm zurück!"); //currently unused, I believe its used for when you switch on a pokemon in shift mode
static const u8 sText_PkmnThatsEnough[] = _("{B_BUFF1}, das reicht! Komm zurück!");
static const u8 sText_PkmnComeBack[] = _("{B_BUFF1}, komm zurück!");
static const u8 sText_PkmnOkComeBack[] = _("OK, {B_BUFF1}! Komm zurück!");
static const u8 sText_PkmnGoodComeBack[] = _("Gute Arbeit, {B_BUFF1}! Komm zurück!");
static const u8 sText_Trainer1WithdrewPkmn[] = _("{B_TRAINER1_NAME_WITH_CLASS} zieht {B_BUFF1} zurück!");
static const u8 sText_Trainer2WithdrewPkmn[] = _("{B_TRAINER2_NAME_WITH_CLASS} zieht {B_BUFF1} zurück!");
static const u8 sText_LinkTrainer1WithdrewPkmn[] = _("{B_LINK_OPPONENT1_NAME} zieht {B_BUFF1} zurück!");
static const u8 sText_LinkTrainer2WithdrewPkmn[] = _("{B_LINK_SCR_TRAINER_NAME} zieht {B_BUFF1} zurück!");
static const u8 sText_WildPkmnPrefix[] = _("(Wild)");
static const u8 sText_FoePkmnPrefix[] = _("(Gegner)");
static const u8 sText_WildPkmnPrefixLower[] = _("das wilde ");
static const u8 sText_FoePkmnPrefixLower[] = _("das gegnerische ");
static const u8 sText_EmptyString8[] = _("");
static const u8 sText_FoePkmnPrefix2[] = _("Gegnerisches");
static const u8 sText_AllyPkmnPrefix[] = _("Verbündetes");
static const u8 sText_FoePkmnPrefix3[] = _("Gegnerisches");
static const u8 sText_AllyPkmnPrefix2[] = _("Verbündetes");
static const u8 sText_FoePkmnPrefix4[] = _("Gegnerisches");
static const u8 sText_AllyPkmnPrefix3[] = _("Verbündetes");
static const u8 sText_AttackerUsedX[] = _("{B_ATK_NAME_WITH_PREFIX} setzt {B_BUFF3} ein!");
static const u8 sText_ExclamationMark[] = _("!");
static const u8 sText_ExclamationMark2[] = _("!");
static const u8 sText_ExclamationMark3[] = _("!");
static const u8 sText_ExclamationMark4[] = _("!");
static const u8 sText_ExclamationMark5[] = _("!");
static const u8 sText_HP[] = _("KP");
static const u8 sText_Attack[] = _("Angriff");
static const u8 sText_Defense[] = _("Vert.");
static const u8 sText_Speed[] = _("Initiative");
static const u8 sText_SpAttack[] = _("Spez. Angr.");
static const u8 sText_SpDefense[] = _("Spez. Vert.");
static const u8 sText_Accuracy[] = _("Init.");
static const u8 sText_Evasiveness[] = _("Fluchtwert");

const u8 *const gStatNamesTable[NUM_BATTLE_STATS] =
{
    [STAT_HP]      = sText_HP,
    [STAT_ATK]     = sText_Attack,
    [STAT_DEF]     = sText_Defense,
    [STAT_SPEED]   = sText_Speed,
    [STAT_SPATK]   = sText_SpAttack,
    [STAT_SPDEF]   = sText_SpDefense,
    [STAT_ACC]     = sText_Accuracy,
    [STAT_EVASION] = sText_Evasiveness,
};
const u8 *const gPokeblockWasTooXStringTable[FLAVOR_COUNT] =
{
    [FLAVOR_SPICY]  = COMPOUND_STRING("war zu scharf!"),
    [FLAVOR_DRY]    = COMPOUND_STRING("war zu trocken!"),
    [FLAVOR_SWEET]  = COMPOUND_STRING("war zu süß!"),
    [FLAVOR_BITTER] = COMPOUND_STRING("war zu bitter!"),
    [FLAVOR_SOUR]   = COMPOUND_STRING("war zu sauer!"),
};

static const u8 sText_Someones[] = _("jemandens");
static const u8 sText_Lanettes[] = _("LANETTEs"); //no decapitalize until it is everywhere
static const u8 sText_EnigmaBerry[] = _("ENIGMA BEERE"); //no decapitalize until it is everywhere
static const u8 sText_BerrySuffix[] = _(" BEERE"); //no decapitalize until it is everywhere
const u8 gText_EmptyString3[] = _("");

static const u8 sText_TwoInGameTrainersDefeated[] = _("Du hast {B_TRAINER1_NAME_WITH_CLASS} und {B_TRAINER2_NAME_WITH_CLASS} besiegt!\p");

// Neue Kampftexte.
const u8 gText_drastically[] = _("drastisch ");
const u8 gText_severely[] = _("schwer ");
static const u8 sText_TerrainReturnedToNormal[] = _("Das Terrain ist wieder normal!\p"); // Unbenutzt

const u8 *const gBattleStringsTable[STRINGID_COUNT] =
{
    [STRINGID_TRAINER1LOSETEXT]                     = COMPOUND_STRING("{B_TRAINER1_LOSE_TEXT}"),
    [STRINGID_PKMNGAINEDEXP]                        = COMPOUND_STRING("{B_BUFF1} erhält {B_BUFF2} {B_BUFF3} EP!\p"),
    [STRINGID_PKMNGREWTOLV]                         = COMPOUND_STRING("{B_BUFF1} erreicht Level {B_BUFF2}!{WAIT_SE}\p"),
    [STRINGID_PKMNLEARNEDMOVE]                      = COMPOUND_STRING("{B_BUFF1} lernt {B_BUFF2}!{WAIT_SE}\p"),
    [STRINGID_TRYTOLEARNMOVE1]                      = COMPOUND_STRING("{B_BUFF1} möchte die Attacke {B_BUFF2} lernen.\p"),
    [STRINGID_TRYTOLEARNMOVE2]                      = COMPOUND_STRING("Aber {B_BUFF1} kennt bereits vier Attacken.\p"),
    [STRINGID_TRYTOLEARNMOVE3]                      = COMPOUND_STRING("Soll eine Attacke vergessen und durch {B_BUFF2} ersetzt werden?"),
    [STRINGID_PKMNFORGOTMOVE]                       = COMPOUND_STRING("{B_BUFF1} vergisst {B_BUFF2}…\p"),
    [STRINGID_STOPLEARNINGMOVE]                     = COMPOUND_STRING("{PAUSE 32}Möchtest du darauf verzichten, dass {B_BUFF1} {B_BUFF2} lernt?"),
    [STRINGID_DIDNOTLEARNMOVE]                      = COMPOUND_STRING("{B_BUFF1} hat {B_BUFF2} nicht gelernt.\p"),
    [STRINGID_PKMNLEARNEDMOVE2]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} lernt {B_BUFF1}!"),
    [STRINGID_ATTACKMISSED]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s Angriff verfehlte!"),
    [STRINGID_PKMNPROTECTEDITSELF]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} schützte sich selbst!"),
    [STRINGID_STATSWONTINCREASE2]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s Werte können nicht weiter steigen!"),
    [STRINGID_AVOIDEDDAMAGE]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wich dem Schaden mit {B_DEF_ABILITY} aus!"), //not in gen 5+, ability popup
    [STRINGID_ITDOESNTAFFECT]                       = COMPOUND_STRING("Es hat keine Wirkung auf {B_DEF_NAME_WITH_PREFIX2}…"),
    [STRINGID_BATTLERFAINTED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde besiegt!\p"),
    //[STRINGID_TARGETFAINTED]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde besiegt!\p"),
    [STRINGID_PLAYERGOTMONEY]                       = COMPOUND_STRING("Du hast ¥{B_BUFF1} für den Sieg erhalten!\p"),
    [STRINGID_PLAYERWHITEOUT]                       = COMPOUND_STRING("Du hast keine kampffähigen Pokémon mehr!\p"),
    [STRINGID_PLAYERWHITEOUT2_WILD]                 = COMPOUND_STRING("Du bist in Panik geraten und hast ¥{B_BUFF1} fallen lassen…"),
    [STRINGID_PLAYERWHITEOUT2_TRAINER]              = COMPOUND_STRING("Du hast ¥{B_BUFF1} an den Gewinner gegeben…"),
    [STRINGID_PLAYERWHITEOUT3]                      = COMPOUND_STRING("Du warst von deiner Niederlage überwältigt!"),
    [STRINGID_PREVENTSESCAPE]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} verhindert die Flucht mit {B_SCR_ABILITY}!\p"),
    [STRINGID_HITXTIMES]                            = COMPOUND_STRING("Das Pokémon wurde {B_BUFF1} Mal getroffen!"), //SV has dynamic plural here
    [STRINGID_PKMNFELLASLEEP]                       = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} ist eingeschlafen!"),
    [STRINGID_PKMNMADESLEEP]                        = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} ließ {B_EFF_NAME_WITH_PREFIX2} einschlafen!"), //not in gen 5+, ability popup
    [STRINGID_PKMNALREADYASLEEP]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} schläft bereits!"),
    [STRINGID_PKMNALREADYASLEEP2]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} schläft bereits!"),
    //[STRINGID_PKMNWASNTAFFECTED]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} war nicht betroffen!"), //not in gen 5+, ability popup
    [STRINGID_PKMNWASPOISONED]                      = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} wurde vergiftet!"),
    [STRINGID_PKMNPOISONEDBY]                       = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} wurde von {B_SCR_NAME_WITH_PREFIX2}'s {B_BUFF1} vergiftet!"), //not in gen 5+, ability popup
    [STRINGID_PKMNHURTBYPOISON]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde durch das Gift verletzt!"),
    [STRINGID_PKMNALREADYPOISONED]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} ist bereits vergiftet!"),
    [STRINGID_PKMNBADLYPOISONED]                    = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} wurde schwer vergiftet!"),
    [STRINGID_PKMNENERGYDRAINED]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde Energie entzogen!"),
    [STRINGID_PKMNWASBURNED]                        = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} wurde verbrannt!"),
    [STRINGID_PKMNBURNEDBY]                         = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} verbrannte {B_EFF_NAME_WITH_PREFIX2}!"), //not in gen 5+, ability popup
    [STRINGID_PKMNHURTBYBURN]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde durch den Brand verletzt!"),
    [STRINGID_PKMNWASFROZEN]                        = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} wurde eingefroren!"),
    [STRINGID_PKMNFROZENBY]                         = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} fror {B_EFF_NAME_WITH_PREFIX2} ein!"), //not in gen 5+, ability popup
    [STRINGID_PKMNISFROZEN]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ist eingefroren!"),
    [STRINGID_PKMNWASDEFROSTED]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde aufgetaut!"),
    [STRINGID_PKMNWASDEFROSTED2]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde aufgetaut!"),
    [STRINGID_PKMNWASDEFROSTEDBY]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} schmolz das Eis!"),
    [STRINGID_PKMNWASPARALYZED]                     = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} ist paralysiert, es könnte sich nicht bewegen!"),
    [STRINGID_PKMNWASPARALYZEDBY]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} paralysierte {B_EFF_NAME_WITH_PREFIX2}, es könnte sich nicht bewegen!"), //not in gen 5+, ability popup
    [STRINGID_PKMNISPARALYZED]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} konnte sich nicht bewegen, weil es paralysiert ist!"),
    [STRINGID_PKMNISALREADYPARALYZED]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} ist bereits paralysiert!"),
    [STRINGID_PKMNHEALEDPARALYSIS]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde von der Paralyse geheilt!"),
    //[STRINGID_PKMNDREAMEATEN]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Traum wurde gefressen!"), //not in gen 5+, expansion doesn't use anymore
    [STRINGID_STATSWONTINCREASE]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1} kann nicht weiter steigen!"),
    [STRINGID_STATSWONTDECREASE]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} kann nicht weiter sinken!"),
    //[STRINGID_TEAMSTOPPEDWORKING]                   = COMPOUND_STRING("Das {B_BUFF1} deines Teams hat aufgehört zu wirken!"), //unused
    //[STRINGID_FOESTOPPEDWORKING]                    = COMPOUND_STRING("Das {B_BUFF1} des Gegners hat aufgehört zu wirken!"), //unused
    [STRINGID_PKMNISCONFUSED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ist verwirrt!"),
    [STRINGID_PKMNHEALEDCONFUSION]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat seine Verwirrung überwunden!"),
    [STRINGID_PKMNWASCONFUSED]                      = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} wurde verwirrt!"),
    [STRINGID_PKMNALREADYCONFUSED]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} ist bereits verwirrt!"),
    [STRINGID_PKMNFELLINLOVE]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} hat sich verliebt!"),
    [STRINGID_PKMNINLOVE]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ist in {B_SCR_NAME_WITH_PREFIX2} verliebt!"),
    [STRINGID_PKMNIMMOBILIZEDBYLOVE]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ist vor Liebe gelähmt!"),
    //[STRINGID_PKMNBLOWNAWAY]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde weggeblasen!"), //unused
    [STRINGID_PKMNCHANGEDTYPE]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} verwandelte sich in den {B_BUFF1}-Typ!"),
    [STRINGID_PKMNFLINCHED]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} zuckte zusammen und konnte sich nicht bewegen!"),
    [STRINGID_PKMNREGAINEDHEALTH]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s KP wurden wiederhergestellt."),
    [STRINGID_PKMNHPFULL]                           = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s KP sind voll!"),
    [STRINGID_PKMNRAISEDSPDEF]                      = COMPOUND_STRING("Lichtschild machte {B_ATK_TEAM2} Team stärker gegen Spezial-Attacken!"),
    [STRINGID_PKMNRAISEDDEF]                        = COMPOUND_STRING("Reflektor machte {B_ATK_TEAM2} Team stärker gegen physische Attacken!"),
    [STRINGID_PKMNCOVEREDBYVEIL]                    = COMPOUND_STRING("{B_ATK_TEAM1} Team hüllte sich in einen mystischen Schleier!"),
    [STRINGID_PKMNUSEDSAFEGUARD]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} wird von Schutzschild geschützt!"),
    [STRINGID_PKMNSAFEGUARDEXPIRED]                 = COMPOUND_STRING("{B_ATK_TEAM1} Team wird nicht mehr von Schutzschild geschützt!"),
    [STRINGID_PKMNWENTTOSLEEP]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ist eingeschlafen!"), //not in gen 5+
    [STRINGID_PKMNSLEPTHEALTHY]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} schlief und stellte seine KP wieder her!"),
    [STRINGID_PKMNWHIPPEDWHIRLWIND]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wirbelte einen Wirbelwind auf!"),
    [STRINGID_PKMNTOOKSUNLIGHT]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} absorbierte Licht!"),
    [STRINGID_PKMNLOWEREDHEAD]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} zieht seinen Kopf ein!"),
    [STRINGID_PKMNISGLOWING]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde in ein grelles Licht gehüllt!"),
    [STRINGID_PKMNFLEWHIGH]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} flog hoch hinauf!"),
    [STRINGID_PKMNDUGHOLE]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} grub sich unter die Erde!"),
    [STRINGID_PKMNSQUEEZEDBYBIND]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde von {B_ATK_NAME_WITH_PREFIX2} gequetscht!"),
    [STRINGID_PKMNTRAPPEDINVORTEX]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde im Wirbel gefangen!"),
    [STRINGID_PKMNWRAPPEDBY]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde von {B_ATK_NAME_WITH_PREFIX2} umwickelt!"),
    [STRINGID_PKMNCLAMPED]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} klemmte sich an {B_DEF_NAME_WITH_PREFIX2} fest!"),
    [STRINGID_PKMNHURTBY]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde durch {B_BUFF1} verletzt!"),
    [STRINGID_PKMNFREEDFROM]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde von {B_BUFF1} befreit!"),
    [STRINGID_PKMNCRASHED]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} stürzte weiter und krachte!"),
    [STRINGID_PKMNSHROUDEDINMIST]                   = gText_PkmnShroudedInMist,
    [STRINGID_PKMNPROTECTEDBYMIST]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} wird vom Nebel geschützt!"),
    [STRINGID_PKMNGETTINGPUMPED]                    = gText_PkmnGettingPumped,
    [STRINGID_PKMNHITWITHRECOIL]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde durch den Rückstoß verletzt!"),
    [STRINGID_PKMNPROTECTEDITSELF2]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat sich geschützt!"),
    [STRINGID_PKMNBUFFETEDBYSANDSTORM]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wird vom Sandsturm getroffen!"),
    [STRINGID_PKMNPELTEDBYHAIL]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wird vom Hagel getroffen!"),
    [STRINGID_PKMNSEEDED]                           = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde gesät!"),
    [STRINGID_PKMNEVADEDATTACK]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} hat dem Angriff ausgewichen!"),
    [STRINGID_PKMNSAPPEDBYLEECHSEED]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s Gesundheit wird durch Egelsamen entzogen!"),
    [STRINGID_PKMNFASTASLEEP]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} schläft tief und fest."),
    [STRINGID_PKMNWOKEUP]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ist aufgewacht!"),
    [STRINGID_PKMNUPROARKEPTAWAKE]                  = COMPOUND_STRING("Aber der Aufruhr hielt {B_SCR_NAME_WITH_PREFIX2} wach!"),
    [STRINGID_PKMNWOKEUPINUPROAR]                   = COMPOUND_STRING("Der Aufruhr weckte {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNCAUSEDUPROAR]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} verursachte einen Aufruhr!"),
    [STRINGID_PKMNMAKINGUPROAR]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} macht einen Aufruhr!"),
    [STRINGID_PKMNCALMEDDOWN]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat sich beruhigt."),
    [STRINGID_PKMNCANTSLEEPINUPROAR]                = COMPOUND_STRING("Aber {B_DEF_NAME_WITH_PREFIX2} kann in einem Aufruhr nicht schlafen!"),
    [STRINGID_PKMNSTOCKPILED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat {B_BUFF1} gehortet!"),
    //[STRINGID_PKMNCANTSTOCKPILE]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} kann nicht mehr horten!"), //Ich glaube, das wurde durch "Aber es schlug fehl!" ersetzt
    [STRINGID_PKMNCANTSLEEPINUPROAR2]               = COMPOUND_STRING("Aber {B_DEF_NAME_WITH_PREFIX2} kann in einem Aufruhr nicht schlafen!"),
    [STRINGID_UPROARKEPTPKMNAWAKE]                  = COMPOUND_STRING("Aber der Aufruhr hielt {B_DEF_NAME_WITH_PREFIX2} wach!"),
    [STRINGID_PKMNSTAYEDAWAKEUSING]                 = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} blieb wach, indem es seine {B_DEF_ABILITY} nutzte!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNSTORINGENERGY]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} speichert Energie!"),
    [STRINGID_PKMNUNLEASHEDENERGY]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} entließ seine Energie!"),
    [STRINGID_PKMNFATIGUECONFUSION]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde durch Müdigkeit verwirrt!"),
    [STRINGID_PLAYERPICKEDUPMONEY]                  = COMPOUND_STRING("Du hast ¥{B_BUFF1} aufgehoben!\p"),
    [STRINGID_PKMNUNAFFECTED]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} ist nicht betroffen!"),
    [STRINGID_PKMNTRANSFORMEDINTO]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} verwandelte sich in {B_BUFF1}!"),
    [STRINGID_PKMNMADESUBSTITUTE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} setzte ein Ersatz ein!"),
    [STRINGID_PKMNHASSUBSTITUTE]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat bereits einen Ersatz!"),
    [STRINGID_SUBSTITUTEDAMAGED]                    = COMPOUND_STRING("Der Ersatz nahm den Schaden für {B_DEF_NAME_WITH_PREFIX2}!\p"),
    [STRINGID_PKMNSUBSTITUTEFADED]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Ersatz verschwand!\p"),
    [STRINGID_PKMNMUSTRECHARGE]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} muss sich aufladen!"),
    [STRINGID_PKMNRAGEBUILDING]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Wut baut sich auf!"),
    [STRINGID_PKMNMOVEWASDISABLED]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} wurde deaktiviert!"),
    [STRINGID_PKMNMOVEISDISABLED]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} ist deaktiviert!\p"),
    [STRINGID_PKMNMOVEDISABLEDNOMORE]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s Zug ist nicht mehr deaktiviert!"),
    [STRINGID_PKMNGOTENCORE]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} muss eine Zugabe machen!"),
    [STRINGID_PKMNGOTENCOREDMOVE]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} kann nur noch {B_CURRENT_MOVE} einsetzen!\p"),
    [STRINGID_PKMNENCOREENDED]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} beendete seine Zugabe!"),
    [STRINGID_PKMNTOOKAIM]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} nahm {B_DEF_NAME_WITH_PREFIX2} ins Visier!"),
    [STRINGID_PKMNSKETCHEDMOVE]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} skizzierte {B_BUFF1}!"),
    [STRINGID_PKMNTRYINGTOTAKEFOE]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hofft, seinen Angreifer mit sich zu nehmen!"),
    [STRINGID_PKMNTOOKFOE]                          = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} nahm seinen Angreifer mit sich!"),
    [STRINGID_PKMNREDUCEDPP]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s AP wurden reduziert!"),
    [STRINGID_PKMNSTOLEITEM]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} stahl {B_EFF_NAME_WITH_PREFIX2}'s {B_LAST_ITEM}!"),
    [STRINGID_TARGETCANTESCAPENOW]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} kann nicht mehr entkommen!"),
    [STRINGID_PKMNFELLINTONIGHTMARE]                = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} begann einen Albtraum zu haben!"),
    [STRINGID_PKMNLOCKEDINNIGHTMARE]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ist in einem Albtraum gefangen!"),
    [STRINGID_PKMNLAIDCURSE]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} opferte seine eigenen KP und belegte {B_DEF_NAME_WITH_PREFIX2} mit einem Fluch!"),
    [STRINGID_PKMNAFFLICTEDBYCURSE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ist von dem Fluch betroffen!"),
    [STRINGID_SPIKESSCATTERED]                      = COMPOUND_STRING("Stacheln wurden auf dem Boden um das Team {B_DEF_TEAM2} verstreut!"),
    [STRINGID_PKMNHURTBYSPIKES]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} wurde von den Stacheln verletzt!"),
    [STRINGID_PKMNIDENTIFIED]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde identifiziert!"),
    [STRINGID_PKMNPERISHCOUNTFELL]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s Todeszähler fiel auf {B_BUFF1}!"),
    [STRINGID_PKMNBRACEDITSELF]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat sich vorbereitet!"),
    [STRINGID_PKMNENDUREDHIT]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} hat den Treffer ausgehalten!"),
    [STRINGID_MAGNITUDESTRENGTH]                    = COMPOUND_STRING("Magnitude {B_BUFF1}!"),
    [STRINGID_PKMNCUTHPMAXEDATTACK]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat seine eigenen KP gesenkt und seinen Angriff maximiert!"),
    [STRINGID_PKMNCOPIEDSTATCHANGES]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} hat die Statusänderungen von {B_EFF_NAME_WITH_PREFIX2} kopiert!"),
    [STRINGID_PKMNGOTFREE]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat sich von {B_DEF_NAME_WITH_PREFIX2}'s {B_BUFF1} befreit!"), //nicht in Gen 5+, generisches Turbodreher?
    [STRINGID_PKMNSHEDLEECHSEED]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat Egelsamen abgeschüttelt!"), //nicht in Gen 5+, generisches Turbodreher?
    [STRINGID_PKMNBLEWAWAYSPIKES]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat Stacheln weggeblasen!"), //nicht in Gen 5+, generisches Turbodreher?
    [STRINGID_PKMNFLEDFROMBATTLE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ist aus dem Kampf geflohen!"),
    [STRINGID_PKMNFORESAWATTACK]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat einen Angriff vorhergesehen!"),
    [STRINGID_PKMNTOOKATTACK]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} hat den {B_BUFF1} Angriff abgefangen!"),
    [STRINGID_PKMNATTACK]                           = COMPOUND_STRING("{B_BUFF1}'s Angriff!"), //nicht in Gen 5+, Erweiterung verwendet es nicht mehr
    [STRINGID_PKMNCENTERATTENTION]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde zum Mittelpunkt der Aufmerksamkeit!"),
    [STRINGID_PKMNCHARGINGPOWER]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} begann, Energie zu sammeln!"),
    [STRINGID_NATUREPOWERTURNEDINTO]                = COMPOUND_STRING("Natur-Kraft wurde zu {B_CURRENT_MOVE}!"),
    [STRINGID_PKMNSTATUSNORMAL]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s Status kehrte zur Normalität zurück!"),
    [STRINGID_PKMNHASNOMOVESLEFT]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat keine Züge mehr, die es verwenden kann!\p"),
    [STRINGID_PKMNSUBJECTEDTOTORMENT]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde gequält!"),
    [STRINGID_PKMNCANTUSEMOVETORMENT]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} kann denselben Zug aufgrund der Qual nicht zweimal hintereinander verwenden!\p"),
    [STRINGID_PKMNTIGHTENINGFOCUS]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} fokussiert sich!"),
    [STRINGID_PKMNFELLFORTAUNT]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} fiel auf den Spott herein!"),
    [STRINGID_PKMNCANTUSEMOVETAUNT]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} kann {B_CURRENT_MOVE} nach dem Spott nicht verwenden!\p"),
    [STRINGID_PKMNREADYTOHELP]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ist bereit, {B_DEF_NAME_WITH_PREFIX2} zu helfen!"),
    [STRINGID_PKMNSWITCHEDITEMS]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat Gegenstände mit seinem Ziel getauscht!"),
    [STRINGID_PKMNCOPIEDFOE]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat die Fähigkeit von {B_DEF_NAME_WITH_PREFIX2} kopiert!"),
    //[STRINGID_PKMNMADEWISH]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat sich etwas gewünscht!"), //unbenutzt
    [STRINGID_PKMNWISHCAMETRUE]                     = COMPOUND_STRING("{B_BUFF1}'s Wunsch wurde wahr!"),
    [STRINGID_PKMNPLANTEDROOTS]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat seine Wurzeln geschlagen!"),
    [STRINGID_PKMNABSORBEDNUTRIENTS]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat Nährstoffe mit seinen Wurzeln aufgenommen!"),
    [STRINGID_PKMNANCHOREDITSELF]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} hat sich mit seinen Wurzeln verankert!"),
    [STRINGID_PKMNWASMADEDROWSY]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde schläfrig!"),
    [STRINGID_PKMNKNOCKEDOFF]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat {B_DEF_NAME_WITH_PREFIX2}'s {B_LAST_ITEM} abgeschlagen!"),
    [STRINGID_PKMNSWAPPEDABILITIES]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat Fähigkeiten mit seinem Ziel getauscht!"),
    [STRINGID_PKMNSEALEDOPPONENTMOVE]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat alle Züge seines Ziels, die es teilt, versiegelt!"),
    [STRINGID_PKMNCANTUSEMOVESEALED]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} kann seinen versiegelten {B_CURRENT_MOVE} nicht verwenden!\p"),
    [STRINGID_PKMNWANTSGRUDGE]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} möchte, dass sein Ziel einen Groll hegt!"),
    [STRINGID_PKMNLOSTPPGRUDGE]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1} hat aufgrund des Grolls alle AP verloren!"),
    [STRINGID_PKMNSHROUDEDITSELF]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat sich mit Magiemantel umhüllt!"),
    [STRINGID_PKMNMOVEBOUNCED]                      = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} hat den {B_CURRENT_MOVE} zurückgeworfen!"),
    [STRINGID_PKMNWAITSFORTARGET]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wartet darauf, dass ein Ziel einen Zug macht!"),
    [STRINGID_PKMNSNATCHEDMOVE]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} hat {B_SCR_NAME_WITH_PREFIX2}'s Zug gestohlen!"),
    [STRINGID_PKMNMADEITRAIN]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} hat es regnen lassen!"), //nicht in Gen 5+, Fähigkeit Popup
    //[STRINGID_PKMNRAISEDSPEED]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} hat seine Geschwindigkeit erhöht!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNPROTECTEDBY]                      = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde von {B_DEF_ABILITY} geschützt!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNPREVENTSUSAGE]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} verhindert, dass {B_ATK_NAME_WITH_PREFIX2} {B_CURRENT_MOVE} verwendet!"), //Ich sehe das nicht im SV-Text
    [STRINGID_PKMNRESTOREDHPUSING]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} hat KP mit seiner {B_DEF_ABILITY} wiederhergestellt!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNCHANGEDTYPEWITH]                  = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} hat es zum {B_BUFF1} Typ gemacht!"), //nicht in Gen 5+, Fähigkeit Popup
    //[STRINGID_PKMNPREVENTSPARALYSISWITH]            = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} verhindert Paralyse!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNPREVENTSROMANCEWITH]              = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} verhindert Romantik!"), //nicht in Gen 5+, Fähigkeit Popup
    //[STRINGID_PKMNPREVENTSPOISONINGWITH]            = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} verhindert Vergiftung!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNPREVENTSCONFUSIONWITH]            = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} verhindert Verwirrung!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNRAISEDFIREPOWERWITH]              = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} hat die Kraft von Feuer-Attacken erhöht!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNANCHORSITSELFWITH]                = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} verankert sich mit {B_DEF_ABILITY}!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNCUTSATTACKWITH]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} senkt den Angriff von {B_DEF_NAME_WITH_PREFIX2}!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNPREVENTSSTATLOSSWITH]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} verhindert Statusverlust!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNHURTSWITH]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde von {B_DEF_NAME_WITH_PREFIX2}'s {B_BUFF1} verletzt!"),
    [STRINGID_PKMNTRACED]                           = COMPOUND_STRING("Es hat {B_BUFF1}'s {B_BUFF2} kopiert!"),
    [STRINGID_STATSHARPLY]                          = gText_StatSharply,
    [STRINGID_STATROSE]                             = gText_StatRose,
    [STRINGID_STATHARSHLY]                          = COMPOUND_STRING("stark "),
    [STRINGID_STATFELL]                             = gText_StatFell,
    [STRINGID_ATTACKERSSTATROSE]                    = COMPOUND_STRING("{B_BUFF1} von {B_ATK_NAME_WITH_PREFIX} {B_BUFF2}"),
    [STRINGID_DEFENDERSSTATROSE]                    = gText_DefendersStatRose,
    [STRINGID_ATTACKERSSTATFELL]                    = COMPOUND_STRING("{B_BUFF1} von {B_ATK_NAME_WITH_PREFIX} {B_BUFF2}"),
    [STRINGID_DEFENDERSSTATFELL]                    = COMPOUND_STRING("{B_BUFF1} von {B_DEF_NAME_WITH_PREFIX} {B_BUFF2}"),
    [STRINGID_CRITICALHIT]                          = COMPOUND_STRING("Ein Volltreffer!"),
    [STRINGID_ONEHITKO]                             = COMPOUND_STRING("Es ist ein K.O. mit einem Treffer!"),
    [STRINGID_123POOF]                              = COMPOUND_STRING("Eins…{PAUSE 10}zwei…{PAUSE 10}und…{PAUSE 10}{PAUSE 20}{PLAY_SE SE_BALL_BOUNCE_1}tada!\p"),
    [STRINGID_ANDELLIPSIS]                          = COMPOUND_STRING("Und…\p"),
    [STRINGID_NOTVERYEFFECTIVE]                     = COMPOUND_STRING("Es ist nicht sehr effektiv…"),
    [STRINGID_SUPEREFFECTIVE]                       = COMPOUND_STRING("Es ist sehr effektiv!"),
    [STRINGID_GOTAWAYSAFELY]                        = sText_GotAwaySafely,
    [STRINGID_WILDPKMNFLED]                         = COMPOUND_STRING("{PLAY_SE SE_FLEE}Das wilde {B_BUFF1} ist geflohen!"),
    [STRINGID_NORUNNINGFROMTRAINERS]                = COMPOUND_STRING("Nein! Du kannst nicht vor einem Trainerkampf fliehen!\p"),
    [STRINGID_CANTESCAPE]                           = COMPOUND_STRING("Du kannst nicht entkommen!\p"),
    [STRINGID_DONTLEAVEBIRCH]                       = COMPOUND_STRING("PROF. BIRCH: Lass mich nicht so zurück!\p"), //nicht dekapitalisieren, bis es überall ist
    [STRINGID_BUTNOTHINGHAPPENED]                   = COMPOUND_STRING("Aber nichts ist passiert!"),
    [STRINGID_BUTITFAILED]                          = COMPOUND_STRING("Aber es schlug fehl!"),
    [STRINGID_ITHURTCONFUSION]                      = COMPOUND_STRING("Es hat sich selbst in seiner Verwirrung verletzt!"),
    //[STRINGID_MIRRORMOVEFAILED]                     = COMPOUND_STRING("Der Spiegeltrick schlug fehl!"), //nicht in Gen 5+, verwendet "aber es schlug fehl"
    [STRINGID_STARTEDTORAIN]                        = COMPOUND_STRING("Es begann zu regnen!"),
    [STRINGID_DOWNPOURSTARTED]                      = COMPOUND_STRING("Ein Wolkenbruch begann!"), //entspricht DownpourText in pokegold und pokecrystal und wird von Regentanz in GSC verwendet
    [STRINGID_RAINCONTINUES]                        = COMPOUND_STRING("Der Regen fällt weiter."), //nicht in Gen 5+
    [STRINGID_DOWNPOURCONTINUES]                    = COMPOUND_STRING("Der Wolkenbruch geht weiter."), // unbenutzt
    [STRINGID_RAINSTOPPED]                          = COMPOUND_STRING("Der Regen hat aufgehört."),
    [STRINGID_SANDSTORMBREWED]                      = COMPOUND_STRING("Ein Sandsturm kam auf!"),
    [STRINGID_SANDSTORMRAGES]                       = COMPOUND_STRING("Der Sandsturm tobt."),
    [STRINGID_SANDSTORMSUBSIDED]                    = COMPOUND_STRING("Der Sandsturm hat nachgelassen."),
    [STRINGID_SUNLIGHTGOTBRIGHT]                    = COMPOUND_STRING("Das Sonnenlicht wurde stark!"),
    [STRINGID_SUNLIGHTSTRONG]                       = COMPOUND_STRING("Das Sonnenlicht ist stark."), //nicht in Gen 5+
    [STRINGID_SUNLIGHTFADED]                        = COMPOUND_STRING("Das Sonnenlicht ist verblasst."),
    [STRINGID_STARTEDHAIL]                          = COMPOUND_STRING("Es begann zu hageln!"),
    [STRINGID_HAILCONTINUES]                        = COMPOUND_STRING("Der Hagel prasselt nieder."),
    [STRINGID_HAILSTOPPED]                          = COMPOUND_STRING("Der Hagel hat aufgehört."),
    //[STRINGID_FAILEDTOSPITUP]                       = COMPOUND_STRING("Aber es konnte nichts ausspucken!"), //nicht in Gen 5+, verwendet "aber es schlug fehl"
    //[STRINGID_FAILEDTOSWALLOW]                      = COMPOUND_STRING("Aber es konnte nichts schlucken!"), //nicht in Gen 5+, verwendet "aber es schlug fehl"
    //[STRINGID_WINDBECAMEHEATWAVE]                   = COMPOUND_STRING("Der Wind verwandelte sich in eine Hitzewelle!"), //unbenutzt
    [STRINGID_STATCHANGESGONE]                      = COMPOUND_STRING("Alle Statusänderungen wurden aufgehoben!"),
    [STRINGID_COINSSCATTERED]                       = COMPOUND_STRING("Münzen wurden überall verstreut!"),
    [STRINGID_TOOWEAKFORSUBSTITUTE]                 = COMPOUND_STRING("Aber es hat nicht genug KP übrig, um ein Ersatz zu machen!"),
    [STRINGID_SHAREDPAIN]                           = COMPOUND_STRING("Die Kämpfer teilten ihren Schmerz!"),
    [STRINGID_BELLCHIMED]                           = COMPOUND_STRING("Eine Glocke läutet!"),
    [STRINGID_FAINTINTHREE]                         = COMPOUND_STRING("Alle Pokémon, die das Lied gehört haben, werden in drei Runden besiegt!"),
    [STRINGID_NOPPLEFT]                             = COMPOUND_STRING("Es gibt keine AP mehr für diesen Zug!\p"), //nicht in Gen 5+
    [STRINGID_BUTNOPPLEFT]                          = COMPOUND_STRING("Aber es gab keine AP mehr für den Zug!"),
    [STRINGID_PLAYERUSEDITEM]                       = COMPOUND_STRING("{PLAYER} setzt {B_LAST_ITEM} ein!"),
    [STRINGID_WALLYUSEDITEM]                        = COMPOUND_STRING("WALLY setzt {B_LAST_ITEM} ein!"), //nicht dekapitalisieren, bis es überall ist
    [STRINGID_TRAINERBLOCKEDBALL]                   = COMPOUND_STRING("Der Trainer hat deinen Pokéball abgewehrt!"),
    [STRINGID_DONTBEATHIEF]                         = COMPOUND_STRING("Sei kein Dieb!"),
    [STRINGID_ITDODGEDBALL]                         = COMPOUND_STRING("Es hat deinem geworfenen Pokéball ausgewichen! Dieses Pokémon kann nicht gefangen werden!"),
    [STRINGID_YOUMISSEDPKMN]                        = COMPOUND_STRING("Du hast das Pokémon verfehlt!"),
    [STRINGID_PKMNBROKEFREE]                        = COMPOUND_STRING("Oh nein! Das Pokémon ist ausgebrochen!"),
    [STRINGID_ITAPPEAREDCAUGHT]                     = COMPOUND_STRING("Aww! Es schien gefangen zu sein!"),
    [STRINGID_AARGHALMOSTHADIT]                     = COMPOUND_STRING("Aargh! Fast gehabt!"),
    [STRINGID_SHOOTSOCLOSE]                         = COMPOUND_STRING("Gah! Es war so nah dran!"),
    [STRINGID_GOTCHAPKMNCAUGHTPLAYER]               = COMPOUND_STRING("Toll! {B_DEF_NAME} wurde gefangen!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}\p"),
    [STRINGID_GOTCHAPKMNCAUGHTWALLY]                = COMPOUND_STRING("Toll! {B_DEF_NAME} wurde gefangen!{WAIT_SE}{PLAY_BGM MUS_CAUGHT}{PAUSE 127}"),
    [STRINGID_GIVENICKNAMECAPTURED]                 = COMPOUND_STRING("Möchtest du {B_DEF_NAME} einen Spitznamen geben?"),
    [STRINGID_PKMNSENTTOPC]                         = COMPOUND_STRING("{B_DEF_NAME} wurde an {B_PC_CREATOR_NAME} PC geschickt!"), //Verwendet immer noch Lanettes PC, da die Terminologie unterschiedlich ist
    [STRINGID_PKMNDATAADDEDTODEX]                   = COMPOUND_STRING("{B_DEF_NAME}'s Daten wurden dem Pokédex hinzugefügt!\p"),
    [STRINGID_ITISRAINING]                          = COMPOUND_STRING("Es regnet!"),
    [STRINGID_SANDSTORMISRAGING]                    = COMPOUND_STRING("Der Sandsturm tobt!"),
    [STRINGID_CANTESCAPE2]                          = COMPOUND_STRING("Du kannst nicht entkommen!\p"),
    [STRINGID_PKMNIGNORESASLEEP]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ignorierte Befehle und schlief weiter!"),
    [STRINGID_PKMNIGNOREDORDERS]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ignorierte Befehle!"),
    [STRINGID_PKMNBEGANTONAP]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} begann zu dösen!"),
    [STRINGID_PKMNLOAFING]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} faulenzt!"),
    [STRINGID_PKMNWONTOBEY]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} gehorcht nicht!"),
    [STRINGID_PKMNTURNEDAWAY]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wendet sich ab!"),
    [STRINGID_PKMNPRETENDNOTNOTICE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} tat so, als ob es nichts bemerkt hätte!"),
    [STRINGID_ENEMYABOUTTOSWITCHPKMN]               = COMPOUND_STRING("{B_TRAINER1_NAME_WITH_CLASS} wird {B_BUFF2} einsetzen.\pWillst du dein Pokémon wechseln?"),
    [STRINGID_CREPTCLOSER]                          = COMPOUND_STRING("{B_PLAYER_NAME} schlich sich näher an {B_OPPONENT_MON1_NAME} heran!"), //Safari
    [STRINGID_CANTGETCLOSER]                        = COMPOUND_STRING("{B_PLAYER_NAME} kann nicht näher herankommen!"), //Safari
    [STRINGID_PKMNWATCHINGCAREFULLY]                = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} beobachtet aufmerksam!"), //Safari
    [STRINGID_PKMNCURIOUSABOUTX]                    = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} ist neugierig auf {B_BUFF1}!"), //Safari
    [STRINGID_PKMNENTHRALLEDBYX]                    = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} ist fasziniert von {B_BUFF1}!"), //Safari
    [STRINGID_PKMNIGNOREDX]                         = COMPOUND_STRING("{B_OPPONENT_MON1_NAME} ignorierte {B_BUFF1} völlig!"), //Safari
    [STRINGID_THREWPOKEBLOCKATPKMN]                 = COMPOUND_STRING("{B_PLAYER_NAME} warf einen {POKEBLOCK} auf {B_OPPONENT_MON1_NAME}!"), //Safari
    [STRINGID_OUTOFSAFARIBALLS]                     = COMPOUND_STRING("{PLAY_SE SE_DING_DONG}SPRECHER: Du hast keine Safari-Bälle mehr! Spiel vorbei!\p"), //Safari
    [STRINGID_PKMNSITEMCUREDPARALYSIS]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} heilt seine Paralyse!"),
    [STRINGID_PKMNSITEMCUREDPOISON]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} heilt sein Gift!"),
    [STRINGID_PKMNSITEMHEALEDBURN]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} heilt seine Verbrennung!"),
    [STRINGID_PKMNSITEMDEFROSTEDIT]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} taute es auf!"),
    [STRINGID_PKMNSITEMWOKEIT]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} weckte es auf!"),
    [STRINGID_PKMNSITEMSNAPPEDOUT]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} befreite es aus seiner Verwirrung!"),
    [STRINGID_PKMNSITEMCUREDPROBLEM]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} heilt sein {B_BUFF1} Problem!"),
    [STRINGID_PKMNSITEMRESTOREDHEALTH]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} stellte seine Gesundheit mit {B_LAST_ITEM} wieder her!"),
    [STRINGID_PKMNSITEMRESTOREDPP]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} stellte die AP seiner Attacke {B_BUFF1} mit {B_LAST_ITEM} wieder her!"),
    [STRINGID_PKMNSITEMRESTOREDSTATUS]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} stellte seine Statuswerte mit {B_LAST_ITEM} wieder her!"),
    [STRINGID_PKMNSITEMRESTOREDHPALITTLE]           = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} stellte ein wenig KP mit {B_LAST_ITEM} wieder her!"),
    [STRINGID_ITEMALLOWSONLYYMOVE]                  = COMPOUND_STRING("{B_LAST_ITEM} erlaubt nur die Verwendung von {B_CURRENT_MOVE}!\p"),
    [STRINGID_PKMNHUNGONWITHX]                      = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} hielt durch mit {B_LAST_ITEM}!"),
    [STRINGID_EMPTYSTRING3]                         = gText_EmptyString3,
    [STRINGID_PKMNSXPREVENTSBURNS]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_LAST_ABILITY} verhindert Verbrennungen!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNSXBLOCKSY]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} blockiert {B_CURRENT_MOVE}!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNSXRESTOREDHPALITTLE2]             = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} stellte ein wenig KP wieder her!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNSXWHIPPEDUPSANDSTORM]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} entfachte einen Sandsturm!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNSXPREVENTSYLOSS]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} verhindert den Verlust von {B_BUFF1}!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNSXINFATUATEDY]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} verliebte {B_ATK_NAME_WITH_PREFIX2}!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNSXMADEYINEFFECTIVE]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} machte {B_CURRENT_MOVE} wirkungslos!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNSXCUREDYPROBLEM]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} heilt sein {B_BUFF1} Problem!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_ITSUCKEDLIQUIDOOZE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} saugte den flüssigen Schleim auf!"),
    [STRINGID_PKMNTRANSFORMED]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} verwandelte sich!"),
    [STRINGID_ELECTRICITYWEAKENED]                  = COMPOUND_STRING("Die Kraft der Elektrizität wurde geschwächt!"),
    [STRINGID_FIREWEAKENED]                         = COMPOUND_STRING("Die Kraft des Feuers wurde geschwächt!"),
    [STRINGID_PKMNHIDUNDERWATER]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} versteckte sich unter Wasser!"),
    [STRINGID_PKMNSPRANGUP]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} sprang hoch!"),
    [STRINGID_HMMOVESCANTBEFORGOTTEN]               = COMPOUND_STRING("VM-Attacken können jetzt nicht vergessen werden.\p"),
    [STRINGID_XFOUNDONEY]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} fand ein {B_LAST_ITEM}!"),
    [STRINGID_PLAYERDEFEATEDTRAINER1]               = sText_PlayerDefeatedLinkTrainerTrainer1,
    [STRINGID_SOOTHINGAROMA]                        = COMPOUND_STRING("Ein beruhigendes Aroma durchzieht die Gegend!"),
    [STRINGID_ITEMSCANTBEUSEDNOW]                   = COMPOUND_STRING("Items können jetzt nicht verwendet werden.{PAUSE 64}"), //nicht in Gen 5+, glaube ich
    [STRINGID_USINGITEMSTATOFPKMNROSE]              = COMPOUND_STRING("Durch {B_LAST_ITEM} steigt {B_BUFF1} von {B_SCR_NAME_WITH_PREFIX2} {B_BUFF2}!"),
    [STRINGID_USINGITEMSTATOFPKMNFELL]              = COMPOUND_STRING("Durch {B_LAST_ITEM} sinkt {B_BUFF1} von {B_SCR_NAME_WITH_PREFIX2} {B_BUFF2}!"),
    [STRINGID_PKMNUSEDXTOGETPUMPED]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} benutzt {B_LAST_ITEM}, um sich zu motivieren!"),
    [STRINGID_PKMNSXMADEYUSELESS]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} machte {B_CURRENT_MOVE} nutzlos!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNTRAPPEDBYSANDTOMB]                = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde von Treibsand gefangen!"),
    [STRINGID_EMPTYSTRING4]                         = COMPOUND_STRING(""),
    [STRINGID_ABOOSTED]                             = COMPOUND_STRING(" ein verstärktes"),
    [STRINGID_PKMNSXINTENSIFIEDSUN]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} verstärkte die Sonnenstrahlen!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNMAKESGROUNDMISS]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} lässt Boden-Attacken mit {B_DEF_ABILITY} verfehlen!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_YOUTHROWABALLNOWRIGHT]                = COMPOUND_STRING("Du wirfst jetzt einen Ball, richtig? Ich… Ich werde mein Bestes geben!"),
    [STRINGID_PKMNSXTOOKATTACK]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} hat den Angriff abgefangen!"), //In Gen 5+ aber ohne Nennung der Fähigkeit
    [STRINGID_PKMNCHOSEXASDESTINY]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wählte Schicksalszahn als sein Schicksal!"),
    [STRINGID_PKMNLOSTFOCUS]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} verlor den Fokus und konnte sich nicht bewegen!"),
    [STRINGID_USENEXTPKMN]                          = COMPOUND_STRING("Nächstes Pokémon verwenden?"),
    [STRINGID_PKMNFLEDUSINGITS]                     = COMPOUND_STRING("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} floh mit seinem {B_LAST_ITEM}!\p"),
    [STRINGID_PKMNFLEDUSING]                        = COMPOUND_STRING("{PLAY_SE SE_FLEE}{B_ATK_NAME_WITH_PREFIX} floh mit {B_ATK_ABILITY}!\p"), //nicht in Gen 5+
    [STRINGID_PKMNWASDRAGGEDOUT]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde herausgezogen!\p"),
    //[STRINGID_PREVENTEDFROMWORKING]                 = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} verhindert, dass {B_SCR_NAME_WITH_PREFIX2}'s {B_BUFF1} funktionierte!"), //unbenutzt
    [STRINGID_PKMNSITEMNORMALIZEDSTATUS]            = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} normalisiert seinen Status!"),
    [STRINGID_TRAINER1USEDITEM]                     = COMPOUND_STRING("{B_ATK_TRAINER_NAME_WITH_CLASS} benutzt {B_LAST_ITEM}!"),
    [STRINGID_BOXISFULL]                            = COMPOUND_STRING("Die Box ist voll! Du kannst keine weiteren Pokémon fangen!\p"),
    [STRINGID_PKMNAVOIDEDATTACK]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wich dem Angriff aus!"),
    [STRINGID_PKMNSXMADEITINEFFECTIVE]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} machte es unwirksam!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNSXPREVENTSFLINCHING]              = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX}'s {B_EFF_ABILITY} verhindert Zusammenzucken!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNALREADYHASBURN]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} ist bereits verbrannt!"),
    [STRINGID_STATSWONTDECREASE2]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Werte können nicht weiter sinken!"),
    [STRINGID_PKMNSXBLOCKSY2]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} blockiert {B_CURRENT_MOVE}!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PKMNSXWOREOFF]                        = COMPOUND_STRING("{B_ATK_TEAM1} Team's {B_BUFF1} ist abgelaufen!"),
    //[STRINGID_PKMNRAISEDDEFALITTLE]                 = COMPOUND_STRING("{B_ATK_PREFIX1}'s {B_CURRENT_MOVE} erhöhte die VERTEIDIGUNG ein wenig!"), //Erweiterung verwendet es nicht mehr
    //[STRINGID_PKMNRAISEDSPDEFALITTLE]               = COMPOUND_STRING("{B_ATK_PREFIX1}'s {B_CURRENT_MOVE} erhöhte die SPEZ. VERTEIDIGUNG ein wenig!"), //Erweiterung verwendet es nicht mehr
    [STRINGID_THEWALLSHATTERED]                     = COMPOUND_STRING("Die Wand zerbrach!"), //nicht in Gen 5+, verwendet "dein Team's Lichtschild ist abgelaufen!" etc stattdessen
    //[STRINGID_PKMNSXPREVENTSYSZ]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} verhindert, dass {B_DEF_NAME_WITH_PREFIX2}'s {B_DEF_ABILITY} funktioniert!"),
    [STRINGID_PKMNSXCUREDITSYPROBLEM]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} heilt sein {B_BUFF1} Problem!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_ATTACKERCANTESCAPE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} kann nicht entkommen!"),
    [STRINGID_PKMNOBTAINEDX]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} erhält {B_BUFF1}."),
    [STRINGID_PKMNOBTAINEDX2]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} erhält {B_BUFF2}."),
    [STRINGID_PKMNOBTAINEDXYOBTAINEDZ]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} erhält {B_BUFF1}.\p{B_DEF_NAME_WITH_PREFIX} erhält {B_BUFF2}."),
    [STRINGID_BUTNOEFFECT]                          = COMPOUND_STRING("Aber es hatte keine Wirkung!"),
    //[STRINGID_PKMNSXHADNOEFFECTONY]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} hatte keine Wirkung auf {B_EFF_NAME_WITH_PREFIX2}!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_TWOENEMIESDEFEATED]                   = sText_TwoInGameTrainersDefeated,
    [STRINGID_TRAINER2LOSETEXT]                     = COMPOUND_STRING("{B_TRAINER2_LOSE_TEXT}"),
    [STRINGID_PKMNINCAPABLEOFPOWER]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} scheint nicht in der Lage zu sein, seine Kraft zu nutzen!"),
    [STRINGID_GLINTAPPEARSINEYE]                    = COMPOUND_STRING("Ein Glitzern erscheint in {B_SCR_NAME_WITH_PREFIX2}'s Augen!"),
    [STRINGID_PKMNGETTINGINTOPOSITION]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} nimmt Position ein!"),
    [STRINGID_PKMNBEGANGROWLINGDEEPLY]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} begann tief zu knurren!"),
    [STRINGID_PKMNEAGERFORMORE]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} ist begierig auf mehr!"),
    [STRINGID_DEFEATEDOPPONENTBYREFEREE]            = COMPOUND_STRING("{B_PLAYER_MON1_NAME} besiegte den Gegner {B_OPPONENT_MON1_NAME} durch eine Entscheidung des SCHIEDSRICHTERS!"),
    [STRINGID_LOSTTOOPPONENTBYREFEREE]              = COMPOUND_STRING("{B_PLAYER_MON1_NAME} verlor gegen den Gegner {B_OPPONENT_MON1_NAME} durch eine Entscheidung des SCHIEDSRICHTERS!"),
    [STRINGID_TIEDOPPONENTBYREFEREE]                = COMPOUND_STRING("{B_PLAYER_MON1_NAME} unentschieden gegen den Gegner {B_OPPONENT_MON1_NAME} durch eine Entscheidung des SCHIEDSRICHTERS!"),
    [STRINGID_QUESTIONFORFEITMATCH]                 = COMPOUND_STRING("Möchtest du das Match aufgeben und jetzt beenden?"),
    [STRINGID_FORFEITEDMATCH]                       = COMPOUND_STRING("Das Match wurde aufgegeben."),
    [STRINGID_PKMNTRANSFERREDSOMEONESPC]            = gText_PkmnTransferredSomeonesPC,
    [STRINGID_PKMNTRANSFERREDLANETTESPC]            = gText_PkmnTransferredLanettesPC,
    [STRINGID_PKMNBOXSOMEONESPCFULL]                = gText_PkmnTransferredSomeonesPCBoxFull,
    [STRINGID_PKMNBOXLANETTESPCFULL]                = gText_PkmnTransferredLanettesPCBoxFull,
    [STRINGID_TRAINER1WINTEXT]                      = COMPOUND_STRING("{B_TRAINER1_WIN_TEXT}"),
    [STRINGID_TRAINER2WINTEXT]                      = COMPOUND_STRING("{B_TRAINER2_WIN_TEXT}"),
    [STRINGID_ENDUREDSTURDY]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} hielt den Treffer mit {B_DEF_ABILITY} aus!"),
    [STRINGID_POWERHERB]                            = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde vollständig aufgeladen durch sein {B_LAST_ITEM}!"),
    [STRINGID_HURTBYITEM]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde durch das {B_LAST_ITEM} verletzt!"),
    [STRINGID_PSNBYITEM]                            = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} wurde durch das {B_LAST_ITEM} schwer vergiftet!"),
    [STRINGID_BRNBYITEM]                            = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} wurde durch das {B_LAST_ITEM} verbrannt!"),
    [STRINGID_DEFABILITYIN]                         = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} aktiviert sich!"),
    [STRINGID_GRAVITYINTENSIFIED]                   = COMPOUND_STRING("Die Schwerkraft hat sich verstärkt!"),
    [STRINGID_TARGETIDENTIFIED]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde identifiziert!"),
    [STRINGID_TARGETWOKEUP]                         = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} ist aufgewacht!"),
    [STRINGID_PKMNSTOLEANDATEITEM]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} stahl und aß das {B_LAST_ITEM} seines Ziels!"),
    [STRINGID_TAILWINDBLEW]                         = COMPOUND_STRING("Der Rückenwind blies hinter {B_ATK_TEAM2} Team!"),
    [STRINGID_PKMNWENTBACK]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} kehrte zu {B_ATK_TRAINER_NAME} zurück!"),
    [STRINGID_PKMNCANTUSEITEMSANYMORE]              = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} kann keine Items mehr verwenden!"),
    [STRINGID_PKMNFLUNG]                            = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} schleuderte sein {B_LAST_ITEM}!"),
    [STRINGID_PKMNPREVENTEDFROMHEALING]             = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde daran gehindert, sich zu heilen!"),
    [STRINGID_PKMNSWITCHEDATKANDDEF]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} tauschte seinen Angriff und seine Verteidigung!"),
    [STRINGID_PKMNSABILITYSUPPRESSED]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Fähigkeit wurde unterdrückt!"),
    [STRINGID_SHIELDEDFROMCRITICALHITS]             = COMPOUND_STRING("Glücksbringer schützte {B_ATK_TEAM2} Team vor Volltreffern!"),
    [STRINGID_SWITCHEDATKANDSPATK]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} tauschte alle Änderungen seines Angriffs und seiner Spez. Angriff\pmit seinem Ziel!"),
    [STRINGID_SWITCHEDDEFANDSPDEF]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} tauschte alle Änderungen seiner Verteidigung und seiner Spez. Verteidigung\pmit seinem Ziel!"),
    [STRINGID_PKMNACQUIREDABILITY]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} erwarb {B_DEF_ABILITY}!"),
    [STRINGID_POISONSPIKESSCATTERED]                = COMPOUND_STRING("Giftstacheln wurden auf dem Boden um {B_DEF_TEAM2} Team verstreut!"),
    [STRINGID_PKMNSWITCHEDSTATCHANGES]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} tauschte Statusänderungen mit seinem Ziel!"),
    [STRINGID_PKMNSURROUNDEDWITHVEILOFWATER]        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} umgab sich mit einem Schleier aus Wasser!"),
    [STRINGID_PKMNLEVITATEDONELECTROMAGNETISM]      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} schwebte mit Elektromagnetismus!"),
    [STRINGID_PKMNTWISTEDDIMENSIONS]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} verdrehte die Dimensionen!"),
    [STRINGID_POINTEDSTONESFLOAT]                   = COMPOUND_STRING("Spitze Steine schweben in der Luft um {B_DEF_TEAM2} Team!"),
    [STRINGID_CLOAKEDINMYSTICALMOONLIGHT]           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde in mystisches Mondlicht gehüllt!"),
    [STRINGID_TRAPPEDBYSWIRLINGMAGMA]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde von wirbelndem Magma gefangen!"),
    [STRINGID_VANISHEDINSTANTLY]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} verschwand sofort!"),
    [STRINGID_PROTECTEDTEAM]                        = COMPOUND_STRING("{B_CURRENT_MOVE} schützte {B_ATK_TEAM2} Team!"),
    [STRINGID_SHAREDITSGUARD]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} teilte seinen Schutz mit dem Ziel!"),
    [STRINGID_SHAREDITSPOWER]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} teilte seine Kraft mit dem Ziel!"),
    [STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON]         = COMPOUND_STRING("Es schuf ein bizarres Gebiet, in dem Verteidigung und Spez. Verteidigung vertauscht sind!"),
    [STRINGID_BECAMENIMBLE]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde flink!"),
    [STRINGID_HURLEDINTOTHEAIR]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde in die Luft geschleudert!"),
    [STRINGID_HELDITEMSLOSEEFFECTS]                 = COMPOUND_STRING("Es schuf ein bizarres Gebiet, in dem die Effekte der gehaltenen Items der Pokémon verloren gehen!"),
    [STRINGID_FELLSTRAIGHTDOWN]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} fiel gerade nach unten!"),
    [STRINGID_TARGETCHANGEDTYPE]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} verwandelte sich in den {B_BUFF1} Typ!"),
    [STRINGID_PKMNACQUIREDSIMPLE]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} erwarb Einfach!"), //sollte den Namen nicht direkt verwenden
    //[STRINGID_EMPTYSTRING5]                         = sText_EmptyString4,
    [STRINGID_KINDOFFER]                            = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} nahm das freundliche Angebot an!"),
    [STRINGID_RESETSTARGETSSTATLEVELS]              = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Statusänderungen wurden entfernt!"),
    [STRINGID_EMPTYSTRING6]                         = sText_EmptyString4,
    [STRINGID_ALLYSWITCHPOSITION]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} und {B_SCR_NAME_WITH_PREFIX2} tauschten die Plätze!"),
    [STRINGID_RESTORETARGETSHEALTH]                 = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s KP wurden wiederhergestellt!"),
    [STRINGID_TOOKPJMNINTOTHESKY]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} nahm {B_DEF_NAME_WITH_PREFIX2} in den Himmel!"),
    [STRINGID_FREEDFROMSKYDROP]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde aus dem Himmelssturz befreit!"),
    [STRINGID_POSTPONETARGETMOVE]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Zug wurde verschoben!"),
    [STRINGID_REFLECTTARGETSTYPE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde zum gleichen Typ wie {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_TRANSFERHELDITEM]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} erhält {B_LAST_ITEM} von {B_ATK_NAME_WITH_PREFIX2}"),
    [STRINGID_EMBARGOENDS]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} kann wieder Items verwenden!"),
    [STRINGID_ELECTROMAGNETISM]                     = COMPOUND_STRING("Elektromagnetismus"),
    [STRINGID_BUFFERENDS]                           = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} ist abgelaufen!"),
    [STRINGID_TELEKINESISENDS]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde aus der Telekinese befreit!"),
    [STRINGID_TAILWINDENDS]                         = COMPOUND_STRING("{B_ATK_TEAM1} Team's Rückenwind flaute ab!"),
    [STRINGID_LUCKYCHANTENDS]                       = COMPOUND_STRING("{B_ATK_TEAM1} Team's Glücksgesang ist abgelaufen!"),
    [STRINGID_TRICKROOMENDS]                        = COMPOUND_STRING("Die verdrehten Dimensionen kehrten zur Normalität zurück!"),
    [STRINGID_WONDERROOMENDS]                       = COMPOUND_STRING("Wunderraum ist abgelaufen, und Verteidigungs- und Spezial-Verteidigungswerte kehrten zur Normalität zurück!"),
    [STRINGID_MAGICROOMENDS]                        = COMPOUND_STRING("Zauberraum ist abgelaufen, und die Effekte der gehaltenen Items kehrten zur Normalität zurück!"),
    [STRINGID_MUDSPORTENDS]                         = COMPOUND_STRING("Die Effekte von Lehmsuhler sind verblasst."),
    [STRINGID_WATERSPORTENDS]                       = COMPOUND_STRING("Die Effekte von Wassersport sind verblasst."),
    [STRINGID_GRAVITYENDS]                          = COMPOUND_STRING("Die Schwerkraft kehrte zur Normalität zurück!"),
    [STRINGID_AQUARINGHEAL]                         = COMPOUND_STRING("Ein Schleier aus Wasser stellte {B_ATK_NAME_WITH_PREFIX2}'s KP wieder her!"),
    [STRINGID_ELECTRICTERRAINENDS]                  = COMPOUND_STRING("Die Elektrizität verschwand vom Schlachtfeld."),
    [STRINGID_MISTYTERRAINENDS]                     = COMPOUND_STRING("Der Nebel verschwand vom Schlachtfeld."),
    [STRINGID_PSYCHICTERRAINENDS]                   = COMPOUND_STRING("Die Seltsamkeit verschwand vom Schlachtfeld!"),
    [STRINGID_GRASSYTERRAINENDS]                    = COMPOUND_STRING("Das Gras verschwand vom Schlachtfeld."),
    [STRINGID_TARGETABILITYSTATRAISE]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} {B_BUFF2} erhöht seinen {B_BUFF1}!"),
    [STRINGID_TARGETSSTATWASMAXEDOUT]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} maximiert seinen {B_BUFF1}!"),
    [STRINGID_ATTACKERABILITYSTATRAISE]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} {B_BUFF2} erhöht seinen {B_BUFF1}!"),
    [STRINGID_POISONHEALHPUP]                       = COMPOUND_STRING("Die Vergiftung heilt {B_ATK_NAME_WITH_PREFIX2} ein wenig!"), //Ich glaube, diese Nachricht wird nicht mehr angezeigt
    [STRINGID_BADDREAMSDMG]                         = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wird gequält!"),
    [STRINGID_MOLDBREAKERENTERS]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} durchbricht die Form!"),
    [STRINGID_TERAVOLTENTERS]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} strahlt eine platzende Aura aus!"),
    [STRINGID_TURBOBLAZEENTERS]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} strahlt eine lodernde Aura aus!"),
    [STRINGID_SLOWSTARTENTERS]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} kommt nur langsam in Gang!"),
    [STRINGID_SLOWSTARTEND]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat sich endlich zusammengerissen!"),
    [STRINGID_SOLARPOWERHPDROP]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} fordert ihren Tribut!"), //Ich glaube, diese Nachricht wird nicht mehr angezeigt
    [STRINGID_AFTERMATHDMG]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde verletzt!"),
    [STRINGID_ANTICIPATIONACTIVATES]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} zitterte!"),
    [STRINGID_FOREWARNACTIVATES]                    = COMPOUND_STRING("{B_SCR_ABILITY} warnte {B_SCR_NAME_WITH_PREFIX2} vor {B_EFF_NAME_WITH_PREFIX2}'s {B_BUFF1}!"),
    [STRINGID_ICEBODYHPGAIN]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} heilt es ein wenig!"), //Ich glaube, diese Nachricht wird nicht mehr angezeigt
    [STRINGID_SNOWWARNINGHAIL]                      = COMPOUND_STRING("Es begann zu hageln!"),
    [STRINGID_FRISKACTIVATES]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} durchsuchte {B_DEF_NAME_WITH_PREFIX2} und fand sein {B_LAST_ITEM}!"),
    [STRINGID_UNNERVEENTERS]                        = COMPOUND_STRING("{B_EFF_TEAM1} Team ist zu nervös, um Beeren zu essen!"),
    [STRINGID_HARVESTBERRY]                         = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} erntete seine {B_LAST_ITEM}!"),
//    [STRINGID_LASTABILITYRAISEDSTAT]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_LAST_ABILITY} erhöhte seinen {B_BUFF1}!"),
    [STRINGID_MAGICBOUNCEACTIVATES]                 = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} warf den {B_ATK_NAME_WITH_PREFIX2} zurück!"),
    [STRINGID_PROTEANTYPECHANGE]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_ATK_ABILITY} verwandelte es in den {B_BUFF1} Typ!"),
    [STRINGID_SYMBIOSISITEMPASS]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} übergab sein {B_LAST_ITEM} an {B_ATK_NAME_WITH_PREFIX2} durch {B_LAST_ABILITY}!"),
    [STRINGID_STEALTHROCKDMG]                       = COMPOUND_STRING("Spitze Steine bohrten sich in {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_TOXICSPIKESABSORBED]                  = COMPOUND_STRING("Die Giftstacheln verschwanden vom Boden um {B_EFF_TEAM2} Team!"),
    [STRINGID_TOXICSPIKESPOISONED]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} wurde vergiftet!"),
    [STRINGID_STICKYWEBSWITCHIN]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} wurde in einem klebrigen Netz gefangen!"),
    [STRINGID_HEALINGWISHCAMETRUE]                  = COMPOUND_STRING("Der Heilwunsch wurde für {B_ATK_NAME_WITH_PREFIX2} wahr!"),
    [STRINGID_HEALINGWISHHEALED]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} stellte Gesundheit wieder her!"),
    [STRINGID_LUNARDANCECAMETRUE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde in mystisches Mondlicht gehüllt!"),
//    [STRINGID_CUSEDBODYDISABLED]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_BUFF1} wurde durch {B_DEF_NAME_WITH_PREFIX2}'s {B_DEF_ABILITY} deaktiviert!"),
    [STRINGID_ATTACKERACQUIREDABILITY]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} erwarb {B_ATK_ABILITY}!"),
    [STRINGID_TARGETABILITYSTATLOWER]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_DEF_ABILITY} senkte seinen {B_BUFF1}!"),
    [STRINGID_TARGETSTATWONTGOHIGHER]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s {B_BUFF1} kann nicht weiter steigen!"),
    [STRINGID_PKMNMOVEBOUNCEDABILITY]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} wurde von {B_DEF_NAME_WITH_PREFIX2}'s {B_DEF_ABILITY} zurückgeworfen!"),
    [STRINGID_IMPOSTERTRANSFORM]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} verwandelte sich in {B_DEF_NAME_WITH_PREFIX2} mit {B_LAST_ABILITY}!"),
    [STRINGID_ASSAULTVESTDOESNTALLOW]               = COMPOUND_STRING("Die Effekte des {B_LAST_ITEM} verhindern die Verwendung von Statuszügen!\p"),
    [STRINGID_GRAVITYPREVENTSUSAGE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} kann {B_CURRENT_MOVE} wegen der Schwerkraft nicht verwenden!\p"),
    [STRINGID_HEALBLOCKPREVENTSUSAGE]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde daran gehindert, sich zu heilen!\p"),
    [STRINGID_NOTDONEYET]                           = COMPOUND_STRING("Dieser Zug-Effekt ist noch nicht abgeschlossen!\p"),
    [STRINGID_STICKYWEBUSED]                        = COMPOUND_STRING("Ein klebriges Netz wurde auf dem Boden um das Team {B_DEF_TEAM2} gelegt!"),
    [STRINGID_QUASHSUCCESS]                         = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Zug wurde verschoben!"),
    [STRINGID_PKMNBLEWAWAYTOXICSPIKES]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat Giftstacheln weggeblasen!"),
    [STRINGID_PKMNBLEWAWAYSTICKYWEB]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat das klebrige Netz weggeblasen!"),
    [STRINGID_PKMNBLEWAWAYSTEALTHROCK]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat Tarnsteine weggeblasen!"),
    [STRINGID_IONDELUGEON]                          = COMPOUND_STRING("Ein Ionenregen duscht das Schlachtfeld!"),
    [STRINGID_TOPSYTURVYSWITCHEDSTATS]              = COMPOUND_STRING("Alle Statusänderungen bei {B_DEF_NAME_WITH_PREFIX2} wurden umgekehrt!"),
    [STRINGID_TERRAINBECOMESMISTY]                  = COMPOUND_STRING("Nebel wirbelte um das Schlachtfeld!"),
    [STRINGID_TERRAINBECOMESGRASSY]                 = COMPOUND_STRING("Gras wuchs, um das Schlachtfeld zu bedecken!"),
    [STRINGID_TERRAINBECOMESELECTRIC]               = COMPOUND_STRING("Ein elektrischer Strom floss über das Schlachtfeld!"),
    [STRINGID_TERRAINBECOMESPSYCHIC]                = COMPOUND_STRING("Das Schlachtfeld wurde seltsam!"),
    [STRINGID_TARGETELECTRIFIED]                    = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Züge wurden elektrifiziert!"),
    [STRINGID_MEGAEVOREACTING]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_LAST_ITEM} reagiert auf {B_ATK_TRAINER_NAME}'s Mega-Ring!"), //zeigt tatsächlich die Art des Mega-Rings im Inventar an, aber wir haben sie nicht implementiert :(
    [STRINGID_MEGAEVOEVOLVED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat sich zu Mega-{B_BUFF1} entwickelt!"),
    [STRINGID_DRASTICALLY]                          = gText_drastically,
    [STRINGID_SEVERELY]                             = gText_severely,
    [STRINGID_INFESTATION]                          = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde von {B_ATK_NAME_WITH_PREFIX2} mit einem Befall belegt!"),
    [STRINGID_NOEFFECTONTARGET]                     = COMPOUND_STRING("Es wird keine Wirkung auf {B_DEF_NAME_WITH_PREFIX2} haben!"),
    [STRINGID_BURSTINGFLAMESHIT]                    = COMPOUND_STRING("Die platzenden Flammen trafen {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_BESTOWITEMGIVING]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} erhält {B_LAST_ITEM} von {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_THIRDTYPEADDED]                       = COMPOUND_STRING("{B_BUFF1}-Typ wurde zu {B_DEF_NAME_WITH_PREFIX2} hinzugefügt!"),
    [STRINGID_FELLFORFEINT]                         = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} fiel auf den Finte herein!"),
    [STRINGID_POKEMONCANNOTUSEMOVE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} kann {B_CURRENT_MOVE} nicht verwenden!"),
    [STRINGID_COVEREDINPOWDER]                      = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} ist mit Pulver bedeckt!"),
    [STRINGID_POWDEREXPLODES]                       = COMPOUND_STRING("Als die Flamme das Pulver auf dem Pokémon berührte, explodierte es!"),
    [STRINGID_BELCHCANTSELECT]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat keine Beeren gegessen, also kann es nicht rülpsen!\p"),
    [STRINGID_SPECTRALTHIEFSTEAL]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} stahl die erhöhten Statuswerte des Ziels!"),
    [STRINGID_GRAVITYGROUNDING]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} fiel aufgrund der Schwerkraft vom Himmel!"),
    [STRINGID_MISTYTERRAINPREVENTS]                 = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} umgibt sich mit einem schützenden Nebel!"),
    [STRINGID_GRASSYTERRAINHEALS]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wird durch das Grasfeld geheilt!"),
    [STRINGID_ELECTRICTERRAINPREVENTS]              = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} umgibt sich mit elektrifiziertem Terrain!"),
    [STRINGID_PSYCHICTERRAINPREVENTS]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} umgibt sich mit psychischem Terrain!"),
    [STRINGID_SAFETYGOGGLESPROTECTED]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} ist dank seines {B_LAST_ITEM} nicht betroffen!"),
    [STRINGID_FLOWERVEILPROTECTED]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} umgab sich mit einem Schleier aus Blütenblättern!"),
    [STRINGID_SWEETVEILPROTECTED]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} kann aufgrund eines süßen Schleiers nicht einschlafen!"),
    [STRINGID_AROMAVEILPROTECTED]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wird von einem aromatischen Schleier geschützt!"),
    [STRINGID_CELEBRATEMESSAGE]                     = COMPOUND_STRING("Herzlichen Glückwunsch, {B_PLAYER_NAME}!"),
    [STRINGID_USEDINSTRUCTEDMOVE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} folgte den Anweisungen von {B_BUFF1}!"),
    [STRINGID_THROATCHOPENDS]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} kann wieder klangbasierte Züge verwenden!"),
    [STRINGID_PKMNCANTUSEMOVETHROATCHOP]            = COMPOUND_STRING("Die Effekte von Kehrschelle verhindern, dass {B_ATK_NAME_WITH_PREFIX2} bestimmte Züge verwendet!\p"),
    [STRINGID_LASERFOCUS]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} konzentrierte sich intensiv!"),
    [STRINGID_GEMACTIVATES]                         = COMPOUND_STRING("Der {B_LAST_ITEM} stärkte die Kraft von {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_BERRYDMGREDUCES]                      = COMPOUND_STRING("Der {B_LAST_ITEM} schwächte den Schaden für {B_DEF_NAME_WITH_PREFIX2}!"),
//    [STRINGID_TARGETATEITEM]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} aß seinen {B_LAST_ITEM}!"),
    [STRINGID_AIRBALLOONFLOAT]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} schwebt in der Luft mit seinem Luftballon!"),
    [STRINGID_AIRBALLOONPOP]                        = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Luftballon platzte!"),
    [STRINGID_INCINERATEBURN]                       = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX}'s {B_LAST_ITEM} wurde verbrannt!"),
    [STRINGID_BUGBITE]                              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} stahl und aß den {B_LAST_ITEM} seines Ziels!"),
    [STRINGID_ILLUSIONWOREOFF]                      = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Illusion verschwand!"),
    [STRINGID_ATTACKERCUREDTARGETSTATUS]            = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} heilt das Problem von {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_ATTACKERLOSTFIRETYPE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat sich selbst ausgebrannt!"),
    [STRINGID_HEALERCURE]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_LAST_ABILITY} heilt das Problem von {B_SCR_NAME_WITH_PREFIX2}!"),
    [STRINGID_SCRIPTINGABILITYSTATRAISE]            = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} {B_BUFF2} erhöhte seinen {B_BUFF1}!"),
    [STRINGID_RECEIVERABILITYTAKEOVER]              = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} wurde übernommen!"),
    [STRINGID_PKNMABSORBINGPOWER]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} absorbiert Kraft!"),
    [STRINGID_NOONEWILLBEABLETORUNAWAY]             = COMPOUND_STRING("Niemand wird in der nächsten Runde weglaufen können!"),
    [STRINGID_DESTINYKNOTACTIVATES]                 = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} verliebte sich wegen des {B_LAST_ITEM}!"),
    [STRINGID_CLOAKEDINAFREEZINGLIGHT]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde in ein eisiges Licht gehüllt!"),
    [STRINGID_CLEARAMULETWONTLOWERSTATS]            = COMPOUND_STRING("Die Effekte des {B_LAST_ITEM}, das von {B_SCR_NAME_WITH_PREFIX2} gehalten wird, verhindern, dass seine Statuswerte gesenkt werden!"),
    [STRINGID_FERVENTWISHREACHED]                   = COMPOUND_STRING("{B_ATK_TRAINER_NAME}'s inniger Wunsch hat {B_ATK_NAME_WITH_PREFIX2} erreicht!"),
    [STRINGID_AIRLOCKACTIVATES]                     = COMPOUND_STRING("Die Effekte des Wetters verschwanden."),
    [STRINGID_PRESSUREENTERS]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} übt Druck aus!"),
    [STRINGID_DARKAURAENTERS]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} strahlt eine dunkle Aura aus!"),
    [STRINGID_FAIRYAURAENTERS]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} strahlt eine Feen-Aura aus!"),
    [STRINGID_AURABREAKENTERS]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} kehrte alle Auren der anderen Pokémon um!"),
    [STRINGID_COMATOSEENTERS]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} ist schläfrig!"),
    [STRINGID_SCREENCLEANERENTERS]                  = COMPOUND_STRING("Alle Bildschirme auf dem Feld wurden gereinigt!"),
    [STRINGID_FETCHEDPOKEBALL]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} fand einen {B_LAST_ITEM}!"),
    //[STRINGID_BATTLERABILITYRAISEDSTAT]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} erhöhte seinen {B_BUFF1}!"),
    [STRINGID_ASANDSTORMKICKEDUP]                   = COMPOUND_STRING("Ein Sandsturm kam auf!"),
    [STRINGID_PKMNSWILLPERISHIN3TURNS]              = COMPOUND_STRING("Beide Pokémon werden in drei Runden vergehen!"),  //Ich glaube, diese Nachricht wird nicht mehr angezeigt
    //[STRINGID_ABILITYRAISEDSTATDRASTICALLY]         = COMPOUND_STRING("{B_DEF_ABILITY} erhöhte {B_DEF_NAME_WITH_PREFIX2}'s {B_BUFF1} drastisch!"),
    [STRINGID_AURAFLAREDTOLIFE]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Aura flammte auf!"),
    [STRINGID_ASONEENTERS]                          = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} hat zwei Fähigkeiten!"),
    [STRINGID_CURIOUSMEDICINEENTERS]                = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX}'s Statusänderungen wurden entfernt!"),
    [STRINGID_CANACTFASTERTHANKSTO]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} kann dank seines {B_BUFF1} schneller handeln!"),
    [STRINGID_MICLEBERRYACTIVATES]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} erhöhte die Genauigkeit seines nächsten Zuges mit {B_LAST_ITEM}!"),
    [STRINGID_PKMNSHOOKOFFTHETAUNT]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} schüttelte den Spott ab!"),
    [STRINGID_PKMNGOTOVERITSINFATUATION]            = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} überwand seine Verliebtheit!"),
    [STRINGID_ITEMCANNOTBEREMOVED]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s Item kann nicht entfernt werden!"),
    [STRINGID_STICKYBARBTRANSFER]                   = COMPOUND_STRING("Der {B_LAST_ITEM} haftete sich an {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNBURNHEALED]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Verbrennung wurde geheilt!"),
    [STRINGID_REDCARDACTIVATE]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} hielt seine Rote Karte gegen {B_ATK_NAME_WITH_PREFIX2}!"),
    [STRINGID_EJECTBUTTONACTIVATE]                  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} wurde mit dem {B_LAST_ITEM} ausgetauscht!"),
    [STRINGID_ATKGOTOVERINFATUATION]                = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} überwand seine Verliebtheit!"),
    [STRINGID_TORMENTEDNOMORE]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} wird nicht mehr gequält!"),
    [STRINGID_HEALBLOCKEDNOMORE]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} ist von der Heilblockade geheilt!"),
    [STRINGID_ATTACKERBECAMEFULLYCHARGED]           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde vollständig aufgeladen aufgrund seiner Bindung zu seinem Trainer!\p"),
    [STRINGID_ATTACKERBECAMEASHSPECIES]             = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde zu Ash-Greninja!\p"),
    [STRINGID_EXTREMELYHARSHSUNLIGHT]               = COMPOUND_STRING("Das Sonnenlicht wurde extrem stark!"),
    [STRINGID_EXTREMESUNLIGHTFADED]                 = COMPOUND_STRING("Das extrem starke Sonnenlicht verblasste!"),
    [STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT]     = COMPOUND_STRING("Der Wasser-Angriff verdampfte im extrem starken Sonnenlicht!"),
    [STRINGID_EXTREMELYHARSHSUNLIGHTWASNOTLESSENED] = COMPOUND_STRING("Das extrem starke Sonnenlicht wurde überhaupt nicht gemildert!"),
    [STRINGID_HEAVYRAIN]                            = COMPOUND_STRING("Ein starker Regen begann zu fallen!"),
    [STRINGID_HEAVYRAINLIFTED]                      = COMPOUND_STRING("Der starke Regen hat aufgehört!"),
    [STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN]         = COMPOUND_STRING("Der Feuer-Angriff verpuffte im starken Regen!"),
    [STRINGID_NORELIEFROMHEAVYRAIN]                 = COMPOUND_STRING("Es gibt keine Erleichterung von diesem starken Regen!"),
    [STRINGID_MYSTERIOUSAIRCURRENT]                 = COMPOUND_STRING("Mysteriöse starke Winde schützen Flug-Pokémon!"),
    [STRINGID_STRONGWINDSDISSIPATED]                = COMPOUND_STRING("Die mysteriösen starken Winde haben sich aufgelöst!"),
    [STRINGID_MYSTERIOUSAIRCURRENTBLOWSON]          = COMPOUND_STRING("Die mysteriösen starken Winde wehen weiter!"),
    [STRINGID_ATTACKWEAKENEDBSTRONGWINDS]           = COMPOUND_STRING("Die mysteriösen starken Winde schwächten den Angriff!"),
    [STRINGID_STUFFCHEEKSCANTSELECT]                = COMPOUND_STRING("Es kann den Zug nicht verwenden, weil es keine Beere hat!\p"),
    [STRINGID_PKMNREVERTEDTOPRIMAL]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s Urform! Es kehrte zu seinem Urzustand zurück!"),
    [STRINGID_BUTPOKEMONCANTUSETHEMOVE]             = COMPOUND_STRING("Aber {B_ATK_NAME_WITH_PREFIX2} kann den Zug nicht verwenden!"),
    [STRINGID_BUTHOOPACANTUSEIT]                    = COMPOUND_STRING("Aber {B_ATK_NAME_WITH_PREFIX2} kann es in seinem jetzigen Zustand nicht verwenden!"),
    [STRINGID_BROKETHROUGHPROTECTION]               = COMPOUND_STRING("Es durchbrach {B_DEF_NAME_WITH_PREFIX2}'s Schutz!"),
    [STRINGID_ABILITYALLOWSONLYMOVE]                = COMPOUND_STRING("{B_ATK_ABILITY} erlaubt nur die Verwendung von {B_CURRENT_MOVE}!\p"),
    [STRINGID_SWAPPEDABILITIES]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} tauschte Fähigkeiten mit seinem Ziel!"),
    //[STRINGID_PASTELVEILPROTECTED]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wird von einem pastellfarbenen Schleier geschützt!"),
    [STRINGID_PASTELVEILENTERS]                     = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde von seiner Vergiftung geheilt!"),
    [STRINGID_BATTLERTYPECHANGEDTO]                 = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s Typ änderte sich zu {B_BUFF1}!"),
    [STRINGID_BOTHCANNOLONGERESCAPE]                = COMPOUND_STRING("Keines der Pokémon kann mehr fliehen!"),
    [STRINGID_CANTESCAPEDUETOUSEDMOVE]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} kann nicht mehr fliehen, weil es No Retreat verwendet hat!"),
    [STRINGID_PKMNBECAMEWEAKERTOFIRE]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde anfälliger für Feuer!"),
    [STRINGID_ABOUTTOUSEPOLTERGEIST]                = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wird gleich von seinem {B_BUFF1} angegriffen!"),
    [STRINGID_CANTESCAPEBECAUSEOFCURRENTMOVE]       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} kann nicht mehr fliehen wegen Octolock!"),
    [STRINGID_NEUTRALIZINGGASENTERS]                = COMPOUND_STRING("Neutralisierendes Gas füllte den Bereich!"),
    [STRINGID_NEUTRALIZINGGASOVER]                  = COMPOUND_STRING("Die Effekte des neutralisierenden Gases ließen nach!"),
    [STRINGID_TARGETTOOHEAVY]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} ist zu schwer, um gehoben zu werden!"),
    [STRINGID_PKMNTOOKTARGETHIGH]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} nahm {B_DEF_NAME_WITH_PREFIX2} in den Himmel!"),
    [STRINGID_PKMNINSNAPTRAP]                       = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde in einer Schnappfalle gefangen!"),
    [STRINGID_METEORBEAMCHARGING]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} ist überflutet mit Weltraumkraft!"),
    [STRINGID_HEATUPBEAK]                           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} begann, seinen Schnabel zu erhitzen!"),
    [STRINGID_COURTCHANGE]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} tauschte die Kampfeffekte, die jede Seite des Feldes betreffen!"),
//    [STRINGID_PLAYERLOSTTOENEMYTRAINER]             = COMPOUND_STRING("Du hast keine Pokémon mehr, die kämpfen können!\pDu hast gegen {B_TRAINER1_NAME_WITH_CLASS} verloren!{PAUSE_UNTIL_PRESS}"),
//    [STRINGID_PLAYERPAIDPRIZEMONEY]                 = COMPOUND_STRING("Du gibst ¥{B_BUFF1} an den Gewinner…\pDu bist überwältigt von deiner Niederlage!{PAUSE_UNTIL_PRESS}"),
    [STRINGID_ZPOWERSURROUNDS]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} umgab sich mit seiner Z-Kraft!"),
    [STRINGID_ZMOVEUNLEASHED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} entfesselt seinen vollen Z-Move!"),
    [STRINGID_ZMOVERESETSSTATS]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} stellte seine gesenkten Werte mit seiner Z-Kraft wieder her!"),
    [STRINGID_ZMOVEALLSTATSUP]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} erhöhte seine Werte mit seiner Z-Kraft!"),
    [STRINGID_ZMOVEZBOOSTCRIT]                      = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} erhöhte seine Volltrefferquote mit seiner Z-Kraft!"),
    [STRINGID_ZMOVERESTOREHP]                       = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} stellte seine KP mit seiner Z-Kraft wieder her!"),
    [STRINGID_ZMOVESTATUP]                          = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} erhöhte seine Werte mit seiner Z-Kraft!"),
    [STRINGID_ZMOVEHPTRAP]                          = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s KP wurden durch die Z-Kraft wiederhergestellt!"),
    [STRINGID_ATTACKEREXPELLEDTHEPOISON]            = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} schaffte es, das Gift auszustoßen, damit du dir keine Sorgen machst!"),
    [STRINGID_ATTACKERSHOOKITSELFAWAKE]             = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} rüttelte sich wach, damit du dir keine Sorgen machst!"),
    [STRINGID_ATTACKERBROKETHROUGHPARALYSIS]        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} sammelte all seine Energie, um seine Lähmung zu durchbrechen, damit du dir keine Sorgen machst!"),
    [STRINGID_ATTACKERHEALEDITSBURN]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} heilt seine Verbrennung durch pure Entschlossenheit, damit du dir keine Sorgen machst!"),
    [STRINGID_ATTACKERMELTEDTHEICE]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} schmolz das Eis mit seiner feurigen Entschlossenheit, damit du dir keine Sorgen machst!"),
    [STRINGID_TARGETTOUGHEDITOUT]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} hielt durch, damit du nicht traurig bist!"),
    [STRINGID_ATTACKERLOSTELECTRICTYPE]             = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} verbrauchte all seine Elektrizität!"),
    [STRINGID_ATTACKERSWITCHEDSTATWITHTARGET]       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} tauschte {B_BUFF1} mit seinem Ziel!"),
    [STRINGID_BEINGHITCHARGEDPKMNWITHPOWER]         = COMPOUND_STRING("Durch den Treffer mit {B_CURRENT_MOVE} wurde {B_DEF_NAME_WITH_PREFIX2} mit Kraft aufgeladen!"),
    [STRINGID_SUNLIGHTACTIVATEDABILITY]             = COMPOUND_STRING("Das starke Sonnenlicht aktivierte {B_SCR_NAME_WITH_PREFIX2}'s Protosynthese!"),
    [STRINGID_STATWASHEIGHTENED]                    = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_BUFF1} wurde erhöht!"),
    [STRINGID_ELECTRICTERRAINACTIVATEDABILITY]      = COMPOUND_STRING("Das elektrische Terrain aktivierte {B_SCR_NAME_WITH_PREFIX2}'s Quark-Antrieb!"),
    [STRINGID_ABILITYWEAKENEDSURROUNDINGMONSSTAT]   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} schwächte den {B_BUFF1} aller umliegenden Pokémon!\p"),
    [STRINGID_ATTACKERGAINEDSTRENGTHFROMTHEFALLEN]  = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} gewann Kraft von den Gefallenen!"),
    [STRINGID_PKMNSABILITYPREVENTSABILITY]          = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_SCR_ABILITY} verhindert, dass {B_DEF_NAME_WITH_PREFIX2}'s {B_DEF_ABILITY} funktioniert!"), //nicht in Gen 5+, Fähigkeit Popup
    [STRINGID_PREPARESHELLTRAP]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} stellte eine Schalenfalle auf!"),
    [STRINGID_SHELLTRAPDIDNTWORK]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s Schalenfalle hat nicht funktioniert!"),
    [STRINGID_SPIKESDISAPPEAREDFROMTEAM]            = COMPOUND_STRING("Die Stacheln verschwanden vom Boden um das Team {B_ATK_TEAM2}!"),
    [STRINGID_TOXICSPIKESDISAPPEAREDFROMTEAM]       = COMPOUND_STRING("Die Giftstacheln verschwanden vom Boden um das Team {B_ATK_TEAM2}!"),
    [STRINGID_STICKYWEBDISAPPEAREDFROMTEAM]         = COMPOUND_STRING("Das klebrige Netz verschwand vom Boden um das Team {B_ATK_TEAM2}!"),
    [STRINGID_STEALTHROCKDISAPPEAREDFROMTEAM]       = COMPOUND_STRING("Die spitzen Steine verschwanden um das Team {B_ATK_TEAM2}!"),
    [STRINGID_COULDNTFULLYPROTECT]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} konnte sich nicht vollständig schützen und wurde verletzt!"),
    [STRINGID_STOCKPILEDEFFECTWOREOFF]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s gehorteter Effekt ließ nach!"),
    [STRINGID_PKMNREVIVEDREADYTOFIGHT]              = COMPOUND_STRING("{B_BUFF1} wurde wiederbelebt und ist bereit zu kämpfen!"),
    [STRINGID_ITEMRESTOREDSPECIESHEALTH]            = COMPOUND_STRING("{B_BUFF1} hat seine KP wiederhergestellt."),
    [STRINGID_ITEMCUREDSPECIESSTATUS]               = COMPOUND_STRING("{B_BUFF1} hat seinen Status geheilt!"),
    [STRINGID_ITEMRESTOREDSPECIESPP]                = COMPOUND_STRING("{B_BUFF1} hat seine AP wiederhergestellt!"),
    [STRINGID_THUNDERCAGETRAPPED]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} hat {B_DEF_NAME_WITH_PREFIX2} gefangen!"),
    [STRINGID_PKMNHURTBYFROSTBITE]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde von seiner Erfrierung verletzt!"),
    [STRINGID_PKMNGOTFROSTBITE]                     = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} hat eine Erfrierung bekommen!"),
    [STRINGID_PKMNSITEMHEALEDFROSTBITE]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX}'s {B_LAST_ITEM} heilt seine Erfrierung!"),
    [STRINGID_ATTACKERHEALEDITSFROSTBITE]           = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} heilt seine Erfrierung durch pure Entschlossenheit, damit du dir keine Sorgen machst!"),
    [STRINGID_PKMNFROSTBITEHEALED]                  = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX}'s Erfrierung wurde geheilt!"),
    [STRINGID_PKMNFROSTBITEHEALED2]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s Erfrierung wurde geheilt!"),
    [STRINGID_PKMNFROSTBITEHEALEDBY]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s {B_CURRENT_MOVE} heilt seine Erfrierung!"),
    [STRINGID_MIRRORHERBCOPIED]                     = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} benutzt sein Spiegelkraut, um die Statusänderungen seines Gegners zu spiegeln!"),
    [STRINGID_STARTEDSNOW]                          = COMPOUND_STRING("Es begann zu schneien!"),
    [STRINGID_SNOWCONTINUES]                        = COMPOUND_STRING("Der Schnee fällt weiter."), //nicht in Gen 5+ (lol)
    [STRINGID_SNOWSTOPPED]                          = COMPOUND_STRING("Der Schnee hat aufgehört."),
    [STRINGID_SNOWWARNINGSNOW]                      = COMPOUND_STRING("Es begann zu schneien!"),
    [STRINGID_PKMNITEMMELTED]                       = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} korrodiert {B_DEF_NAME_WITH_PREFIX2}'s {B_LAST_ITEM}!"),
    [STRINGID_ULTRABURSTREACTING]                   = COMPOUND_STRING("Helles Licht wird gleich aus {B_ATK_NAME_WITH_PREFIX2} ausbrechen!"),
    [STRINGID_ULTRABURSTCOMPLETED]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} erlangte seine wahre Kraft durch Ultra Burst zurück!"),
    [STRINGID_TEAMGAINEDEXP]                        = COMPOUND_STRING("Der Rest deines Teams erhält Erfahrungspunkte dank des EP-Teilers!\p"),
    [STRINGID_CURRENTMOVECANTSELECT]                = COMPOUND_STRING("{B_BUFF1} kann nicht verwendet werden!\p"),
    [STRINGID_TARGETISBEINGSALTCURED]               = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wird gesalzen!"),
    [STRINGID_TARGETISHURTBYSALTCURE]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wird von {B_BUFF1} verletzt!"),
    [STRINGID_TARGETCOVEREDINSTICKYCANDYSYRUP]      = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} wurde mit klebrigem Zuckersirup überzogen!"),
    [STRINGID_SHARPSTEELFLOATS]                     = COMPOUND_STRING("Scharfkantige Stahlstücke begannen um die Pokémon des Teams {B_DEF_TEAM2} zu schweben!"),
    [STRINGID_SHARPSTEELDMG]                        = COMPOUND_STRING("Der scharfe Stahl biss sich in {B_DEF_NAME_WITH_PREFIX2}!"),
    [STRINGID_PKMNBLEWAWAYSHARPSTEEL]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} blies den scharfen Stahl weg!"),
    [STRINGID_SHARPSTEELDISAPPEAREDFROMTEAM]        = COMPOUND_STRING("Die Stahlstücke um die Pokémon des Teams {B_ATK_TEAM2} verschwanden!"),
    [STRINGID_TEAMTRAPPEDWITHVINES]                 = COMPOUND_STRING("Die Pokémon des Teams {B_DEF_TEAM1} wurden mit Ranken gefangen!"),
    [STRINGID_PKMNHURTBYVINES]                      = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wird von G-Max Rebenhieb's wütendem Schlag verletzt!"),
    [STRINGID_TEAMCAUGHTINVORTEX]                   = COMPOUND_STRING("Die Pokémon des Teams {B_DEF_TEAM1} wurden in einem Wasserwirbel gefangen!"),
    [STRINGID_PKMNHURTBYVORTEX]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wird von G-Max Kanonade's Wirbel verletzt!"),
    [STRINGID_TEAMSURROUNDEDBYFIRE]                 = COMPOUND_STRING("Die Pokémon des Teams {B_DEF_TEAM1} wurden von Feuer umgeben!"),
    [STRINGID_PKMNBURNINGUP]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} brennt innerhalb von G-Max Flammeninferno's Flammen!"),
    [STRINGID_TEAMSURROUNDEDBYROCKS]                = COMPOUND_STRING("Die Pokémon des Teams {B_DEF_TEAM1} wurden von Felsen umgeben!"),
    [STRINGID_PKMNHURTBYROCKSTHROWN]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wird von Felsen verletzt, die von G-Max Felswurf geworfen wurden!"),
    [STRINGID_MOVEBLOCKEDBYDYNAMAX]                 = COMPOUND_STRING("Der Zug wurde durch die Kraft von Dynamax blockiert!"),
    [STRINGID_ZEROTOHEROTRANSFORMATION]             = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} unterzieht sich einer heldenhaften Verwandlung!"),
    [STRINGID_THETWOMOVESBECOMEONE]                 = COMPOUND_STRING("Die beiden Züge wurden zu einem! Es ist ein kombinierter Zug!{PAUSE 16}"),
    [STRINGID_ARAINBOWAPPEAREDONSIDE]               = COMPOUND_STRING("Ein Regenbogen erschien am Himmel auf der Seite des Teams {B_ATK_TEAM2}!"),
    [STRINGID_THERAINBOWDISAPPEARED]                = COMPOUND_STRING("Der Regenbogen auf der Seite des Teams {B_ATK_TEAM2} verschwand!"),
    [STRINGID_WAITINGFORPARTNERSMOVE]               = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wartet auf den Zug von {B_ATK_PARTNER_NAME}…{PAUSE 16}"),
    [STRINGID_SEAOFFIREENVELOPEDSIDE]               = COMPOUND_STRING("Ein Meer aus Feuer umhüllte das Team {B_DEF_TEAM2}!"),
    [STRINGID_HURTBYTHESEAOFFIRE]                   = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde vom Meer aus Feuer verletzt!"),
    [STRINGID_THESEAOFFIREDISAPPEARED]              = COMPOUND_STRING("Das Meer aus Feuer um das Team {B_ATK_TEAM2} verschwand!"),
    [STRINGID_SWAMPENVELOPEDSIDE]                   = COMPOUND_STRING("Ein Sumpf umhüllte das Team {B_DEF_TEAM2}!"),
    [STRINGID_THESWAMPDISAPPEARED]                  = COMPOUND_STRING("Der Sumpf um das Team {B_ATK_TEAM2} verschwand!"),
    [STRINGID_PKMNTELLCHILLINGRECEPTIONJOKE]        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} bereitet sich darauf vor, einen eiskalten Witz zu erzählen!"),
    [STRINGID_HOSPITALITYRESTORATION]               = COMPOUND_STRING("{B_EFF_NAME_WITH_PREFIX} trank den gesamten Matcha, den {B_SCR_NAME_WITH_PREFIX2} gemacht hat!"),
    [STRINGID_ELECTROSHOTCHARGING]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} absorbierte Elektrizität!"),
    [STRINGID_ITEMWASUSEDUP]                        = COMPOUND_STRING("Das {B_LAST_ITEM} wurde aufgebraucht…"),
    [STRINGID_ATTACKERLOSTITSTYPE]                  = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} verlor seinen {B_BUFF1} Typ!"),
    [STRINGID_SHEDITSTAIL]                          = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} warf seinen Schwanz ab, um einen Köder zu erstellen!"),
    [STRINGID_CLOAKEDINAHARSHLIGHT]                 = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} wurde in ein grelles Licht gehüllt!"),
    [STRINGID_SUPERSWEETAROMAWAFTS]                 = COMPOUND_STRING("Ein supersüßes Aroma weht von dem Sirup, der {B_ATK_NAME_WITH_PREFIX2} bedeckt!"),
    [STRINGID_DIMENSIONSWERETWISTED]                = COMPOUND_STRING("Die Dimensionen wurden verdreht!"),
    [STRINGID_BIZARREARENACREATED]                  = COMPOUND_STRING("Ein bizarrer Bereich wurde geschaffen, in dem die Effekte der gehaltenen Items der Pokémon verloren gehen!"),
    [STRINGID_BIZARREAREACREATED]                   = COMPOUND_STRING("Ein bizarrer Bereich wurde geschaffen, in dem Verteidigungs- und Spezial-Verteidigungswerte vertauscht sind!"),
    [STRINGID_TIDYINGUPCOMPLETE]                    = COMPOUND_STRING("Aufräumen abgeschlossen!"),
    [STRINGID_PKMNTERASTALLIZEDINTO]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} terakristallisierte sich in den {B_BUFF1} Typ!"),
    [STRINGID_BOOSTERENERGYACTIVATES]               = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} benutzt sein {B_LAST_ITEM}, um {B_SCR_ABILITY} zu aktivieren!"),
    [STRINGID_FOGCREPTUP]                           = COMPOUND_STRING("Nebel kroch auf, so dick wie Suppe!"),
    [STRINGID_FOGISDEEP]                            = COMPOUND_STRING("Der Nebel ist dicht…"),
    [STRINGID_FOGLIFTED]                            = COMPOUND_STRING("Der Nebel verzieht sich."),
    [STRINGID_PKMNMADESHELLGLEAM]                   = COMPOUND_STRING("{B_DEF_NAME_WITH_PREFIX} ließ seine Schale glänzen! Es verzerrt Typ-Matchups!"),
    [STRINGID_FICKLEBEAMDOUBLED]                    = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} gibt alles für diesen Angriff!"),
    [STRINGID_COMMANDERACTIVATES]                   = COMPOUND_STRING("{B_SCR_NAME_WITH_PREFIX} wurde von Dondozo verschluckt und wurde Dondozo's Kommandant!"),
    [STRINGID_POKEFLUTECATCHY]                      = COMPOUND_STRING("{B_PLAYER_NAME} spielte die {B_LAST_ITEM}.\pDas ist eine eingängige Melodie!"),
    [STRINGID_POKEFLUTE]                            = COMPOUND_STRING("{B_PLAYER_NAME} spielte die {B_LAST_ITEM}."),
    [STRINGID_MONHEARINGFLUTEAWOKE]                 = COMPOUND_STRING("Das Pokémon, das die Flöte hörte, wachte auf!"),
    [STRINGID_SUNLIGHTISHARSH]                      = COMPOUND_STRING("Das Sonnenlicht ist stark!"),
    [STRINGID_ITISHAILING]                          = COMPOUND_STRING("Es hagelt!"),
    [STRINGID_ITISSNOWING]                          = COMPOUND_STRING("Es schneit!"),
    [STRINGID_ISCOVEREDWITHGRASS]                   = COMPOUND_STRING("Das Schlachtfeld ist mit Gras bedeckt!"),
    [STRINGID_MISTSWIRLSAROUND]                     = COMPOUND_STRING("Nebel wirbelt um das Schlachtfeld!"),
    [STRINGID_ELECTRICCURRENTISRUNNING]             = COMPOUND_STRING("Ein elektrischer Strom fließt über das Schlachtfeld!"),
    [STRINGID_SEEMSWEIRD]                           = COMPOUND_STRING("Das Schlachtfeld wirkt seltsam!"),
    [STRINGID_WAGGLINGAFINGER]                      = COMPOUND_STRING("Durch das Wackeln eines Fingers konnte es {B_CURRENT_MOVE} verwenden!"),
    [STRINGID_BLOCKEDBYSLEEPCLAUSE]                 = COMPOUND_STRING("Sleep Clause kept {B_DEF_NAME_WITH_PREFIX2} awake!"),
    [STRINGID_SUPEREFFECTIVETWOFOES]                = COMPOUND_STRING("It's super effective on {B_DEF_NAME_WITH_PREFIX2} and {B_DEF_PARTNER_NAME}!"),
    [STRINGID_NOTVERYEFFECTIVETWOFOES]              = COMPOUND_STRING("It's not very effective on {B_DEF_NAME_WITH_PREFIX2} and {B_DEF_PARTNER_NAME}!"),
    [STRINGID_ITDOESNTAFFECTTWOFOES]                = COMPOUND_STRING("It doesn't affect {B_DEF_NAME_WITH_PREFIX2} and {B_DEF_PARTNER_NAME}…"),
    [STRINGID_SENDCAUGHTMONPARTYORBOX]              = COMPOUND_STRING("Willst du {B_DEF_NAME} in \ndeine Party aufnehmen?"),
    [STRINGID_PKMNSENTTOPCAFTERCATCH]               = gText_PkmnSentToPCAfterCatch,
    [STRINGID_PKMNDYNAMAXED]                        = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} grew huge into its Dynamax form!"),
    [STRINGID_PKMNGIGANTAMAXED]                     = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} grew huge into its Gigantamax form!"),
    [STRINGID_TIMETODYNAMAX]                        = COMPOUND_STRING("Time to Dynamax!"),
    [STRINGID_TIMETOGIGANTAMAX]                     = COMPOUND_STRING("Time to Gigantamax!"),
    [STRINGID_QUESTIONFORFEITBATTLE]                = COMPOUND_STRING("Would you like to give up on this battle and quit now? Quitting the battle is the same as losing the battle."),
    [STRINGID_POWERCONSTRUCTPRESENCEOFMANY]         = COMPOUND_STRING("You sense the presence of many!"),
    [STRINGID_POWERCONSTRUCTTRANSFORM]              = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX} transformed into its Complete Forme!"),
    [STRINGID_ABILITYSHIELDPROTECTS]                = COMPOUND_STRING("{B_ATK_NAME_WITH_PREFIX}'s Ability is protected by the effects of its {B_LAST_ITEM}!"),
};

const u16 gTrainerUsedItemStringIds[] =
{
    STRINGID_PLAYERUSEDITEM, STRINGID_TRAINER1USEDITEM
};

const u16 gZEffectStringIds[] =
{
    [B_MSG_Z_RESET_STATS] = STRINGID_ZMOVERESETSSTATS,
    [B_MSG_Z_ALL_STATS_UP]= STRINGID_ZMOVEALLSTATSUP,
    [B_MSG_Z_BOOST_CRITS] = STRINGID_ZMOVEZBOOSTCRIT,
    [B_MSG_Z_FOLLOW_ME]   = STRINGID_PKMNCENTERATTENTION,
    [B_MSG_Z_RECOVER_HP]  = STRINGID_ZMOVERESTOREHP,
    [B_MSG_Z_STAT_UP]     = STRINGID_ZMOVESTATUP,
    [B_MSG_Z_HP_TRAP]     = STRINGID_ZMOVEHPTRAP,
};

const u16 gMentalHerbCureStringIds[] =
{
    [B_MSG_MENTALHERBCURE_INFATUATION] = STRINGID_ATKGOTOVERINFATUATION,
    [B_MSG_MENTALHERBCURE_TAUNT]       = STRINGID_BUFFERENDS,
    [B_MSG_MENTALHERBCURE_ENCORE]      = STRINGID_PKMNENCOREENDED,
    [B_MSG_MENTALHERBCURE_TORMENT]     = STRINGID_TORMENTEDNOMORE,
    [B_MSG_MENTALHERBCURE_HEALBLOCK]   = STRINGID_HEALBLOCKEDNOMORE,
    [B_MSG_MENTALHERBCURE_DISABLE]     = STRINGID_PKMNMOVEDISABLEDNOMORE,
};

const u16 gStartingStatusStringIds[B_MSG_STARTING_STATUS_COUNT] =
{
    [B_MSG_TERRAIN_SET_MISTY]    = STRINGID_TERRAINBECOMESMISTY,
    [B_MSG_TERRAIN_SET_ELECTRIC] = STRINGID_TERRAINBECOMESELECTRIC,
    [B_MSG_TERRAIN_SET_PSYCHIC]  = STRINGID_TERRAINBECOMESPSYCHIC,
    [B_MSG_TERRAIN_SET_GRASSY]   = STRINGID_TERRAINBECOMESGRASSY,
    [B_MSG_SET_TRICK_ROOM]       = STRINGID_DIMENSIONSWERETWISTED,
    [B_MSG_SET_MAGIC_ROOM]       = STRINGID_BIZARREARENACREATED,
    [B_MSG_SET_WONDER_ROOM]      = STRINGID_BIZARREAREACREATED,
    [B_MSG_SET_TAILWIND]         = STRINGID_TAILWINDBLEW,
    [B_MSG_SET_RAINBOW]          = STRINGID_ARAINBOWAPPEAREDONSIDE,
    [B_MSG_SET_SEA_OF_FIRE]      = STRINGID_SEAOFFIREENVELOPEDSIDE,
    [B_MSG_SET_SWAMP]            = STRINGID_SWAMPENVELOPEDSIDE,
};

const u16 gTerrainStringIds[B_MSG_TERRAIN_COUNT] =
{
    [B_MSG_TERRAIN_SET_MISTY] = STRINGID_TERRAINBECOMESMISTY,
    [B_MSG_TERRAIN_SET_ELECTRIC] = STRINGID_TERRAINBECOMESELECTRIC,
    [B_MSG_TERRAIN_SET_PSYCHIC] = STRINGID_TERRAINBECOMESPSYCHIC,
    [B_MSG_TERRAIN_SET_GRASSY] = STRINGID_TERRAINBECOMESGRASSY,
    [B_MSG_TERRAIN_END_MISTY] = STRINGID_MISTYTERRAINENDS,
    [B_MSG_TERRAIN_END_ELECTRIC] = STRINGID_ELECTRICTERRAINENDS,
    [B_MSG_TERRAIN_END_PSYCHIC] = STRINGID_PSYCHICTERRAINENDS,
    [B_MSG_TERRAIN_END_GRASSY] = STRINGID_GRASSYTERRAINENDS,
};

const u16 gTerrainPreventsStringIds[] =
{
    [B_MSG_TERRAINPREVENTS_MISTY]    = STRINGID_MISTYTERRAINPREVENTS,
    [B_MSG_TERRAINPREVENTS_ELECTRIC] = STRINGID_ELECTRICTERRAINPREVENTS,
    [B_MSG_TERRAINPREVENTS_PSYCHIC]  = STRINGID_PSYCHICTERRAINPREVENTS
};

const u16 gHealingWishStringIds[] =
{
    STRINGID_HEALINGWISHCAMETRUE,
    STRINGID_LUNARDANCECAMETRUE
};

const u16 gDmgHazardsStringIds[] =
{
    [B_MSG_PKMNHURTBYSPIKES]   = STRINGID_PKMNHURTBYSPIKES,
    [B_MSG_STEALTHROCKDMG]     = STRINGID_STEALTHROCKDMG,
    [B_MSG_SHARPSTEELDMG]      = STRINGID_SHARPSTEELDMG,
    [B_MSG_POINTEDSTONESFLOAT] = STRINGID_POINTEDSTONESFLOAT,
    [B_MSG_SPIKESSCATTERED]    = STRINGID_SPIKESSCATTERED,
    [B_MSG_SHARPSTEELFLOATS]   = STRINGID_SHARPSTEELFLOATS,
};

const u16 gSwitchInAbilityStringIds[] =
{
    [B_MSG_SWITCHIN_MOLDBREAKER] = STRINGID_MOLDBREAKERENTERS,
    [B_MSG_SWITCHIN_TERAVOLT] = STRINGID_TERAVOLTENTERS,
    [B_MSG_SWITCHIN_TURBOBLAZE] = STRINGID_TURBOBLAZEENTERS,
    [B_MSG_SWITCHIN_SLOWSTART] = STRINGID_SLOWSTARTENTERS,
    [B_MSG_SWITCHIN_UNNERVE] = STRINGID_UNNERVEENTERS,
    [B_MSG_SWITCHIN_ANTICIPATION] = STRINGID_ANTICIPATIONACTIVATES,
    [B_MSG_SWITCHIN_FOREWARN] = STRINGID_FOREWARNACTIVATES,
    [B_MSG_SWITCHIN_PRESSURE] = STRINGID_PRESSUREENTERS,
    [B_MSG_SWITCHIN_DARKAURA] = STRINGID_DARKAURAENTERS,
    [B_MSG_SWITCHIN_FAIRYAURA] = STRINGID_FAIRYAURAENTERS,
    [B_MSG_SWITCHIN_AURABREAK] = STRINGID_AURABREAKENTERS,
    [B_MSG_SWITCHIN_COMATOSE] = STRINGID_COMATOSEENTERS,
    [B_MSG_SWITCHIN_SCREENCLEANER] = STRINGID_SCREENCLEANERENTERS,
    [B_MSG_SWITCHIN_ASONE] = STRINGID_ASONEENTERS,
    [B_MSG_SWITCHIN_CURIOUS_MEDICINE] = STRINGID_CURIOUSMEDICINEENTERS,
    [B_MSG_SWITCHIN_PASTEL_VEIL] = STRINGID_PASTELVEILENTERS,
    [B_MSG_SWITCHIN_NEUTRALIZING_GAS] = STRINGID_NEUTRALIZINGGASENTERS,
};

const u16 gMissStringIds[] =
{
    [B_MSG_MISSED]      = STRINGID_ATTACKMISSED,
    [B_MSG_PROTECTED]   = STRINGID_PKMNPROTECTEDITSELF,
    [B_MSG_AVOIDED_ATK] = STRINGID_PKMNAVOIDEDATTACK,
    [B_MSG_AVOIDED_DMG] = STRINGID_AVOIDEDDAMAGE,
    [B_MSG_GROUND_MISS] = STRINGID_PKMNMAKESGROUNDMISS
};

const u16 gNoEscapeStringIds[] =
{
    [B_MSG_CANT_ESCAPE]          = STRINGID_CANTESCAPE,
    [B_MSG_DONT_LEAVE_BIRCH]     = STRINGID_DONTLEAVEBIRCH,
    [B_MSG_PREVENTS_ESCAPE]      = STRINGID_PREVENTSESCAPE,
    [B_MSG_CANT_ESCAPE_2]        = STRINGID_CANTESCAPE2,
    [B_MSG_ATTACKER_CANT_ESCAPE] = STRINGID_ATTACKERCANTESCAPE
};

const u16 gMoveWeatherChangeStringIds[] =
{
    [B_MSG_STARTED_RAIN]      = STRINGID_STARTEDTORAIN,
    [B_MSG_STARTED_DOWNPOUR]  = STRINGID_DOWNPOURSTARTED, // Unused
    [B_MSG_WEATHER_FAILED]    = STRINGID_BUTITFAILED,
    [B_MSG_STARTED_SANDSTORM] = STRINGID_SANDSTORMBREWED,
    [B_MSG_STARTED_SUNLIGHT]  = STRINGID_SUNLIGHTGOTBRIGHT,
    [B_MSG_STARTED_HAIL]      = STRINGID_STARTEDHAIL,
    [B_MSG_STARTED_SNOW]      = STRINGID_STARTEDSNOW,
    [B_MSG_STARTED_FOG]       = STRINGID_FOGCREPTUP, // Unused, can use for custom moves that set fog
};

const u16 gWeatherEndsStringIds[B_MSG_WEATHER_END_COUNT] =
{
    [B_MSG_WEATHER_END_RAIN]         = STRINGID_RAINSTOPPED,
    [B_MSG_WEATHER_END_SUN]          = STRINGID_SUNLIGHTFADED,
    [B_MSG_WEATHER_END_SANDSTORM]    = STRINGID_SANDSTORMSUBSIDED,
    [B_MSG_WEATHER_END_HAIL]         = STRINGID_HAILSTOPPED,
    [B_MSG_WEATHER_END_SNOW]         = STRINGID_SNOWSTOPPED,
    [B_MSG_WEATHER_END_FOG]          = STRINGID_FOGLIFTED,
    [B_MSG_WEATHER_END_STRONG_WINDS] = STRINGID_STRONGWINDSDISSIPATED,
};

const u16 gWeatherTurnStringIds[] =
{
    [B_MSG_WEATHER_TURN_RAIN]         = STRINGID_RAINCONTINUES,
    [B_MSG_WEATHER_TURN_DOWNPOUR]     = STRINGID_DOWNPOURCONTINUES,
    [B_MSG_WEATHER_TURN_SUN]          = STRINGID_SUNLIGHTSTRONG,
    [B_MSG_WEATHER_TURN_SANDSTORM]    = STRINGID_SANDSTORMRAGES,
    [B_MSG_WEATHER_TURN_HAIL]         = STRINGID_HAILCONTINUES,
    [B_MSG_WEATHER_TURN_SNOW]         = STRINGID_SNOWCONTINUES,
    [B_MSG_WEATHER_TURN_FOG]          = STRINGID_FOGISDEEP,
    [B_MSG_WEATHER_TURN_STRONG_WINDS] = STRINGID_MYSTERIOUSAIRCURRENTBLOWSON,
};

const u16 gSandStormHailDmgStringIds[] =
{
    [B_MSG_SANDSTORM] = STRINGID_PKMNBUFFETEDBYSANDSTORM,
    [B_MSG_HAIL]      = STRINGID_PKMNPELTEDBYHAIL
};

const u16 gProtectLikeUsedStringIds[] =
{
    [B_MSG_PROTECTED_ITSELF] = STRINGID_PKMNPROTECTEDITSELF2,
    [B_MSG_BRACED_ITSELF]    = STRINGID_PKMNBRACEDITSELF,
    [B_MSG_PROTECT_FAILED]   = STRINGID_BUTITFAILED,
    [B_MSG_PROTECTED_TEAM]   = STRINGID_PROTECTEDTEAM,
};

const u16 gReflectLightScreenSafeguardStringIds[] =
{
    [B_MSG_SIDE_STATUS_FAILED]     = STRINGID_BUTITFAILED,
    [B_MSG_SET_REFLECT_SINGLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_REFLECT_DOUBLE]     = STRINGID_PKMNRAISEDDEF,
    [B_MSG_SET_LIGHTSCREEN_SINGLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_LIGHTSCREEN_DOUBLE] = STRINGID_PKMNRAISEDSPDEF,
    [B_MSG_SET_SAFEGUARD]          = STRINGID_PKMNCOVEREDBYVEIL,
};

const u16 gLeechSeedStringIds[] =
{
    [B_MSG_LEECH_SEED_SET]   = STRINGID_PKMNSEEDED,
    [B_MSG_LEECH_SEED_MISS]  = STRINGID_PKMNEVADEDATTACK,
    [B_MSG_LEECH_SEED_FAIL]  = STRINGID_ITDOESNTAFFECT,
    [B_MSG_LEECH_SEED_DRAIN] = STRINGID_PKMNSAPPEDBYLEECHSEED,
    [B_MSG_LEECH_SEED_OOZE]  = STRINGID_ITSUCKEDLIQUIDOOZE,
};

const u16 gRestUsedStringIds[] =
{
    [B_MSG_REST]          = STRINGID_PKMNWENTTOSLEEP,
    [B_MSG_REST_STATUSED] = STRINGID_PKMNSLEPTHEALTHY
};

const u16 gUproarOverTurnStringIds[] =
{
    [B_MSG_UPROAR_CONTINUES] = STRINGID_PKMNMAKINGUPROAR,
    [B_MSG_UPROAR_ENDS]      = STRINGID_PKMNCALMEDDOWN
};

const u16 gWokeUpStringIds[] =
{
    [B_MSG_WOKE_UP]        = STRINGID_PKMNWOKEUP,
    [B_MSG_WOKE_UP_UPROAR] = STRINGID_PKMNWOKEUPINUPROAR
};

const u16 gUproarAwakeStringIds[] =
{
    [B_MSG_CANT_SLEEP_UPROAR]  = STRINGID_PKMNCANTSLEEPINUPROAR2,
    [B_MSG_UPROAR_KEPT_AWAKE]  = STRINGID_UPROARKEPTPKMNAWAKE,
};

const u16 gStatUpStringIds[] =
{
    [B_MSG_ATTACKER_STAT_CHANGED] = STRINGID_ATTACKERSSTATROSE,
    [B_MSG_DEFENDER_STAT_CHANGED] = STRINGID_DEFENDERSSTATROSE,
    [B_MSG_STAT_WONT_CHANGE]      = STRINGID_STATSWONTINCREASE,
    [B_MSG_STAT_CHANGE_EMPTY]     = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_CHANGED_ITEM]     = STRINGID_USINGITEMSTATOFPKMNROSE,
    [B_MSG_USED_DIRE_HIT]         = STRINGID_PKMNUSEDXTOGETPUMPED,
};

const u16 gStatDownStringIds[] =
{
    [B_MSG_ATTACKER_STAT_CHANGED] = STRINGID_ATTACKERSSTATFELL,
    [B_MSG_DEFENDER_STAT_CHANGED] = STRINGID_DEFENDERSSTATFELL,
    [B_MSG_STAT_WONT_CHANGE]      = STRINGID_STATSWONTDECREASE,
    [B_MSG_STAT_CHANGE_EMPTY]     = STRINGID_EMPTYSTRING3,
    [B_MSG_STAT_CHANGED_ITEM]     = STRINGID_USINGITEMSTATOFPKMNFELL,
};

// Index copied from move's index in sTrappingMoves
const u16 gWrappedStringIds[NUM_TRAPPING_MOVES] =
{
    [B_MSG_WRAPPED_BIND]        = STRINGID_PKMNSQUEEZEDBYBIND,     // MOVE_BIND
    [B_MSG_WRAPPED_WRAP]        = STRINGID_PKMNWRAPPEDBY,          // MOVE_WRAP
    [B_MSG_WRAPPED_FIRE_SPIN]   = STRINGID_PKMNTRAPPEDINVORTEX,    // MOVE_FIRE_SPIN
    [B_MSG_WRAPPED_CLAMP]       = STRINGID_PKMNCLAMPED,            // MOVE_CLAMP
    [B_MSG_WRAPPED_WHIRLPOOL]   = STRINGID_PKMNTRAPPEDINVORTEX,    // MOVE_WHIRLPOOL
    [B_MSG_WRAPPED_SAND_TOMB]   = STRINGID_PKMNTRAPPEDBYSANDTOMB,  // MOVE_SAND_TOMB
    [B_MSG_WRAPPED_MAGMA_STORM] = STRINGID_TRAPPEDBYSWIRLINGMAGMA, // MOVE_MAGMA_STORM
    [B_MSG_WRAPPED_INFESTATION] = STRINGID_INFESTATION,            // MOVE_INFESTATION
    [B_MSG_WRAPPED_SNAP_TRAP]   = STRINGID_PKMNINSNAPTRAP,         // MOVE_SNAP_TRAP
    [B_MSG_WRAPPED_THUNDER_CAGE]= STRINGID_THUNDERCAGETRAPPED,     // MOVE_THUNDER_CAGE
};

const u16 gMistUsedStringIds[] =
{
    [B_MSG_SET_MIST]    = STRINGID_PKMNSHROUDEDINMIST,
    [B_MSG_MIST_FAILED] = STRINGID_BUTITFAILED
};

const u16 gFocusEnergyUsedStringIds[] =
{
    [B_MSG_GETTING_PUMPED]      = STRINGID_PKMNGETTINGPUMPED,
    [B_MSG_FOCUS_ENERGY_FAILED] = STRINGID_BUTITFAILED
};

const u16 gTransformUsedStringIds[] =
{
    [B_MSG_TRANSFORMED]      = STRINGID_PKMNTRANSFORMEDINTO,
    [B_MSG_TRANSFORM_FAILED] = STRINGID_BUTITFAILED
};

const u16 gSubstituteUsedStringIds[] =
{
    [B_MSG_SET_SUBSTITUTE]    = STRINGID_PKMNMADESUBSTITUTE,
    [B_MSG_SUBSTITUTE_FAILED] = STRINGID_TOOWEAKFORSUBSTITUTE
};

const u16 gGotPoisonedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPOISONED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNPOISONEDBY
};

const u16 gGotParalyzedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASPARALYZED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNWASPARALYZEDBY
};

const u16 gFellAsleepStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLASLEEP,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNMADESLEEP,
};

const u16 gGotBurnedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASBURNED,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNBURNEDBY
};

const u16 gGotFrostbiteStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNGOTFROSTBITE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNGOTFROSTBITE,
};

const u16 gFrostbiteHealedStringIds[] =
{
    [B_MSG_FROSTBITE_HEALED]         = STRINGID_PKMNFROSTBITEHEALED2,
    [B_MSG_FROSTBITE_HEALED_BY_MOVE] = STRINGID_PKMNFROSTBITEHEALEDBY
};

const u16 gGotFrozenStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNWASFROZEN,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNFROZENBY
};

const u16 gGotDefrostedStringIds[] =
{
    [B_MSG_DEFROSTED]         = STRINGID_PKMNWASDEFROSTED2,
    [B_MSG_DEFROSTED_BY_MOVE] = STRINGID_PKMNWASDEFROSTEDBY
};

const u16 gKOFailedStringIds[] =
{
    [B_MSG_KO_MISS]       = STRINGID_ATTACKMISSED,
    [B_MSG_KO_UNAFFECTED] = STRINGID_PKMNUNAFFECTED
};

const u16 gAttractUsedStringIds[] =
{
    [B_MSG_STATUSED]            = STRINGID_PKMNFELLINLOVE,
    [B_MSG_STATUSED_BY_ABILITY] = STRINGID_PKMNSXINFATUATEDY
};

const u16 gAbsorbDrainStringIds[] =
{
    [B_MSG_ABSORB]      = STRINGID_PKMNENERGYDRAINED,
    [B_MSG_ABSORB_OOZE] = STRINGID_ITSUCKEDLIQUIDOOZE
};

const u16 gSportsUsedStringIds[] =
{
    [B_MSG_WEAKEN_ELECTRIC] = STRINGID_ELECTRICITYWEAKENED,
    [B_MSG_WEAKEN_FIRE]     = STRINGID_FIREWEAKENED
};

const u16 gPartyStatusHealStringIds[] =
{
    [B_MSG_BELL]                     = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_ATTACKER] = STRINGID_BELLCHIMED,
    [B_MSG_BELL_SOUNDPROOF_PARTNER]  = STRINGID_BELLCHIMED,
    [B_MSG_BELL_BOTH_SOUNDPROOF]     = STRINGID_BELLCHIMED,
    [B_MSG_SOOTHING_AROMA]           = STRINGID_SOOTHINGAROMA
};

const u16 gFutureMoveUsedStringIds[] =
{
    [B_MSG_FUTURE_SIGHT] = STRINGID_PKMNFORESAWATTACK,
    [B_MSG_DOOM_DESIRE]  = STRINGID_PKMNCHOSEXASDESTINY
};

const u16 gBallEscapeStringIds[] =
{
    [BALL_NO_SHAKES]     = STRINGID_PKMNBROKEFREE,
    [BALL_1_SHAKE]       = STRINGID_ITAPPEAREDCAUGHT,
    [BALL_2_SHAKES]      = STRINGID_AARGHALMOSTHADIT,
    [BALL_3_SHAKES_FAIL] = STRINGID_SHOOTSOCLOSE
};

// Overworld weathers that don't have an associated battle weather default to "It is raining."
const u16 gWeatherStartsStringIds[] =
{
    [WEATHER_NONE]               = STRINGID_ITISRAINING,
    [WEATHER_SUNNY_CLOUDS]       = STRINGID_ITISRAINING,
    [WEATHER_SUNNY]              = STRINGID_ITISRAINING,
    [WEATHER_RAIN]               = STRINGID_ITISRAINING,
    [WEATHER_SNOW]               = (B_OVERWORLD_SNOW >= GEN_9 ? STRINGID_ITISSNOWING : STRINGID_ITISHAILING),
    [WEATHER_RAIN_THUNDERSTORM]  = STRINGID_ITISRAINING,
    [WEATHER_FOG_HORIZONTAL]     = STRINGID_FOGISDEEP,
    [WEATHER_VOLCANIC_ASH]       = STRINGID_ITISRAINING,
    [WEATHER_SANDSTORM]          = STRINGID_SANDSTORMISRAGING,
    [WEATHER_FOG_DIAGONAL]       = STRINGID_FOGISDEEP,
    [WEATHER_UNDERWATER]         = STRINGID_ITISRAINING,
    [WEATHER_SHADE]              = STRINGID_ITISRAINING,
    [WEATHER_DROUGHT]            = STRINGID_SUNLIGHTISHARSH,
    [WEATHER_DOWNPOUR]           = STRINGID_ITISRAINING,
    [WEATHER_UNDERWATER_BUBBLES] = STRINGID_ITISRAINING,
    [WEATHER_ABNORMAL]           = STRINGID_ITISRAINING
};

const u16 gTerrainStartsStringIds[] =
{
    [B_MSG_TERRAIN_SET_MISTY]    = STRINGID_MISTSWIRLSAROUND,
    [B_MSG_TERRAIN_SET_ELECTRIC] = STRINGID_ELECTRICCURRENTISRUNNING,
    [B_MSG_TERRAIN_SET_PSYCHIC]  = STRINGID_SEEMSWEIRD,
    [B_MSG_TERRAIN_SET_GRASSY]   = STRINGID_ISCOVEREDWITHGRASS,
};

const u16 gPrimalWeatherBlocksStringIds[] =
{
    [B_MSG_PRIMAL_WEATHER_FIZZLED_BY_RAIN]      = STRINGID_MOVEFIZZLEDOUTINTHEHEAVYRAIN,
    [B_MSG_PRIMAL_WEATHER_EVAPORATED_IN_SUN]    = STRINGID_MOVEEVAPORATEDINTHEHARSHSUNLIGHT,
};

const u16 gInobedientStringIds[] =
{
    [B_MSG_LOAFING]            = STRINGID_PKMNLOAFING,
    [B_MSG_WONT_OBEY]          = STRINGID_PKMNWONTOBEY,
    [B_MSG_TURNED_AWAY]        = STRINGID_PKMNTURNEDAWAY,
    [B_MSG_PRETEND_NOT_NOTICE] = STRINGID_PKMNPRETENDNOTNOTICE,
    [B_MSG_INCAPABLE_OF_POWER] = STRINGID_PKMNINCAPABLEOFPOWER
};

const u16 gSafariGetNearStringIds[] =
{
    [B_MSG_CREPT_CLOSER]    = STRINGID_CREPTCLOSER,
    [B_MSG_CANT_GET_CLOSER] = STRINGID_CANTGETCLOSER
};

const u16 gSafariPokeblockResultStringIds[] =
{
    [B_MSG_MON_CURIOUS]    = STRINGID_PKMNCURIOUSABOUTX,
    [B_MSG_MON_ENTHRALLED] = STRINGID_PKMNENTHRALLEDBYX,
    [B_MSG_MON_IGNORED]    = STRINGID_PKMNIGNOREDX
};

const u16 CureStatusBerryEffectStringID[] =
{
    [B_MSG_CURED_PARALYSIS] = STRINGID_PKMNSITEMCUREDPARALYSIS,
    [B_MSG_CURED_POISON] = STRINGID_PKMNSITEMCUREDPOISON,
    [B_MSG_CURED_BURN] = STRINGID_PKMNSITEMHEALEDBURN,
    [B_MSG_CURED_FREEEZE] = STRINGID_PKMNSITEMDEFROSTEDIT,
    [B_MSG_CURED_FROSTBITE] = STRINGID_PKMNSITEMHEALEDFROSTBITE,
    [B_MSG_CURED_SLEEP] = STRINGID_PKMNSITEMWOKEIT,
    [B_MSG_CURED_PROBLEM]     = STRINGID_PKMNSITEMCUREDPROBLEM,
    [B_MSG_NORMALIZED_STATUS] = STRINGID_PKMNSITEMNORMALIZEDSTATUS
};

const u16 gItemSwapStringIds[] =
{
    [B_MSG_ITEM_SWAP_TAKEN] = STRINGID_PKMNOBTAINEDX,
    [B_MSG_ITEM_SWAP_GIVEN] = STRINGID_PKMNOBTAINEDX2,
    [B_MSG_ITEM_SWAP_BOTH]  = STRINGID_PKMNOBTAINEDXYOBTAINEDZ
};

const u16 gFlashFireStringIds[] =
{
    [B_MSG_FLASH_FIRE_BOOST]    = STRINGID_PKMNRAISEDFIREPOWERWITH,
    [B_MSG_FLASH_FIRE_NO_BOOST] = STRINGID_PKMNSXMADEYINEFFECTIVE
};

const u16 gCaughtMonStringIds[] =
{
    [B_MSG_SENT_SOMEONES_PC]   = STRINGID_PKMNTRANSFERREDSOMEONESPC,
    [B_MSG_SENT_LANETTES_PC]   = STRINGID_PKMNTRANSFERREDLANETTESPC,
    [B_MSG_SOMEONES_BOX_FULL]  = STRINGID_PKMNBOXSOMEONESPCFULL,
    [B_MSG_LANETTES_BOX_FULL]  = STRINGID_PKMNBOXLANETTESPCFULL,
    [B_MSG_SWAPPED_INTO_PARTY] = STRINGID_PKMNSENTTOPCAFTERCATCH,
};

const u16 gRoomsStringIds[] =
{
    STRINGID_PKMNTWISTEDDIMENSIONS, STRINGID_TRICKROOMENDS,
    STRINGID_SWAPSDEFANDSPDEFOFALLPOKEMON, STRINGID_WONDERROOMENDS,
    STRINGID_HELDITEMSLOSEEFFECTS, STRINGID_MAGICROOMENDS,
    STRINGID_EMPTYSTRING3
};

const u16 gStatusConditionsStringIds[] =
{
    STRINGID_PKMNWASPOISONED, STRINGID_PKMNBADLYPOISONED, STRINGID_PKMNWASBURNED, STRINGID_PKMNWASPARALYZED, STRINGID_PKMNFELLASLEEP, STRINGID_PKMNGOTFROSTBITE
};

const u16 gDamageNonTypesStartStringIds[] =
{
    [B_MSG_TRAPPED_WITH_VINES]  = STRINGID_TEAMTRAPPEDWITHVINES,
    [B_MSG_CAUGHT_IN_VORTEX]    = STRINGID_TEAMCAUGHTINVORTEX,
    [B_MSG_SURROUNDED_BY_FIRE]  = STRINGID_TEAMSURROUNDEDBYFIRE,
    [B_MSG_SURROUNDED_BY_ROCKS] = STRINGID_TEAMSURROUNDEDBYROCKS,
};

const u16 gDamageNonTypesDmgStringIds[] =
{
    [B_MSG_HURT_BY_VINES]        = STRINGID_PKMNHURTBYVINES,
    [B_MSG_HURT_BY_VORTEX]       = STRINGID_PKMNHURTBYVORTEX,
    [B_MSG_BURNING_UP]           = STRINGID_PKMNBURNINGUP,
    [B_MSG_HURT_BY_ROCKS_THROWN] = STRINGID_PKMNHURTBYROCKSTHROWN,
};

const u16 gDefogHazardsStringIds[] =
{
    [HAZARDS_SPIKES] = STRINGID_SPIKESDISAPPEAREDFROMTEAM,
    [HAZARDS_STICKY_WEB] = STRINGID_STICKYWEBDISAPPEAREDFROMTEAM,
    [HAZARDS_TOXIC_SPIKES] = STRINGID_TOXICSPIKESDISAPPEAREDFROMTEAM,
    [HAZARDS_STEALTH_ROCK] = STRINGID_STEALTHROCKDISAPPEAREDFROMTEAM,
    [HAZARDS_STEELSURGE] = STRINGID_SHARPSTEELDISAPPEAREDFROMTEAM,
};

const u16 gSpinHazardsStringIds[] =
{
    [HAZARDS_SPIKES] = STRINGID_PKMNBLEWAWAYSPIKES,
    [HAZARDS_STICKY_WEB] = STRINGID_PKMNBLEWAWAYSTICKYWEB,
    [HAZARDS_TOXIC_SPIKES] = STRINGID_PKMNBLEWAWAYTOXICSPIKES,
    [HAZARDS_STEALTH_ROCK] = STRINGID_PKMNBLEWAWAYSTEALTHROCK,
    [HAZARDS_STEELSURGE] = STRINGID_PKMNBLEWAWAYSHARPSTEEL,
};

const u8 gText_PkmnIsEvolving[] = _("Was?\n{STR_VAR_1} entwickelt sich!");
const u8 gText_CongratsPkmnEvolved[] = _("Herzlichen Glückwunsch! Dein {STR_VAR_1}\nhat sich zu {STR_VAR_2} entwickelt!{WAIT_SE}\p");
const u8 gText_PkmnStoppedEvolving[] = _("Hm? Die Entwicklung\nwurde abgebrochen!\p");
const u8 gText_EllipsisQuestionMark[] = _("……?\p");
const u8 gText_WhatWillPkmnDo[] = _("Was soll {B_BUFF1}\ntun?");
const u8 gText_WhatWillPkmnDo2[] = _("Was soll {B_PLAYER_NAME}\ntun?");
const u8 gText_WhatWillWallyDo[] = _("Was wird\nWALLY tun?");
const u8 gText_LinkStandby[] = _("{PAUSE 16}Link standby…");
const u8 gText_BattleMenu[] = _("Kampf{CLEAR_TO 56}Beutel\nPokémon{CLEAR_TO 56}Flucht");
const u8 gText_SafariZoneMenu[] = _("Ball{CLEAR_TO 56}{POKEBLOCK}\nNähern{CLEAR_TO 56}Flucht");
const u8 gText_MoveInterfacePP[] = _("AP ");
const u8 gText_MoveInterfaceType[] = _("Typ/");
const u8 gText_MoveInterfacePpType[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}AP\nTYP/");
const u8 gText_MoveInterfaceDynamicColors[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_WhichMoveToForget4[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Welche Attacke\nsoll vergessen werden?");
const u8 gText_BattleYesNoChoice[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Ja\nNein");
const u8 gText_BattleSwitchWhich[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}Wechseln\nwelches?");
const u8 gText_BattleSwitchWhich2[] = _("{PALETTE 5}{COLOR_HIGHLIGHT_SHADOW DYNAMIC_COLOR4 DYNAMIC_COLOR5 DYNAMIC_COLOR6}");
const u8 gText_BattleSwitchWhich3[] = _("{UP_ARROW}");
const u8 gText_BattleSwitchWhich4[] = _("{ESCAPE 4}");
const u8 gText_BattleSwitchWhich5[] = _("-");
const u8 gText_SafariBalls[] = _("{HIGHLIGHT DARK_GRAY}Safari Bälle");
const u8 gText_SafariBallLeft[] = _("{HIGHLIGHT DARK_GRAY}Übrig: $" "{HIGHLIGHT DARK_GRAY}");
const u8 gText_Sleep[] = _("Schlaf");
const u8 gText_Poison[] = _("Gift");
const u8 gText_Burn[] = _("Verbrennung");
const u8 gText_Paralysis[] = _("Paralyse");
const u8 gText_Ice[] = _("Eis");
const u8 gText_Confusion[] = _("Verwirrung");
const u8 gText_Love[] = _("Liebe");
const u8 gText_SpaceAndSpace[] = _(" und ");
const u8 gText_CommaSpace[] = _(", ");
const u8 gText_Space2[] = _(" ");
const u8 gText_LineBreak[] = _("\l");
const u8 gText_NewLine[] = _("\n");
const u8 gText_Are[] = _("sind");
const u8 gText_Are2[] = _("sind");
const u8 gText_BadEgg[] = _("Schlechtes Ei");
const u8 gText_BattleWallyName[] = _("WALLY");
const u8 gText_Win[] = _("{HIGHLIGHT TRANSPARENT}Sieg");
const u8 gText_Loss[] = _("{HIGHLIGHT TRANSPARENT}Niederlage");
const u8 gText_Draw[] = _("{HIGHLIGHT TRANSPARENT}Unentschieden");
static const u8 sText_SpaceIs[] = _(" ist");
static const u8 sText_ApostropheS[] = _("'s");
const u8 gText_BattleTourney[] = _("KAMPF TURNIER");

const u8 *const gRoundsStringTable[DOME_ROUNDS_COUNT] =
{
    [DOME_ROUND1]    = COMPOUND_STRING("Runde 1"),
    [DOME_ROUND2]    = COMPOUND_STRING("Runde 2"),
    [DOME_SEMIFINAL] = COMPOUND_STRING("Halbfinale"),
    [DOME_FINAL]     = COMPOUND_STRING("Finale"),
};

const u8 gText_TheGreatNewHope[] = _("Die große neue Hoffnung!\p");
const u8 gText_WillChampionshipDreamComeTrue[] = _("Wird der Meisterschaftstraum wahr werden?!\p");
const u8 gText_AFormerChampion[] = _("Ein ehemaliger Champion!\p");
const u8 gText_ThePreviousChampion[] = _("Der vorherige Champion!\p");
const u8 gText_TheUnbeatenChampion[] = _("Der ungeschlagene Champion!\p");
const u8 gText_PlayerMon1Name[] = _("{B_PLAYER_MON1_NAME}");
const u8 gText_Vs[] = _("VS");
const u8 gText_OpponentMon1Name[] = _("{B_OPPONENT_MON1_NAME}");
const u8 gText_Mind[] = _("Geist");
const u8 gText_Skill[] = _("Fähigkeit");
const u8 gText_Body[] = _("Körper");
const u8 gText_Judgment[] = _("{B_BUFF1}{CLEAR 13}Urteil{CLEAR 13}{B_BUFF2}");
static const u8 sText_TwoTrainersSentPkmn[] = _("{B_TRAINER1_NAME_WITH_CLASS} schickte {B_OPPONENT_MON1_NAME} in den Kampf!\p{B_TRAINER2_NAME_WITH_CLASS} schickte {B_OPPONENT_MON2_NAME} in den Kampf!");
static const u8 sText_Trainer2SentOutPkmn[] = _("{B_TRAINER2_NAME_WITH_CLASS} schickte {B_BUFF1} in den Kampf!");
static const u8 sText_TwoTrainersWantToBattle[] = _("Du wirst herausgefordert von {B_TRAINER1_NAME_WITH_CLASS} und {B_TRAINER2_NAME_WITH_CLASS}!\p");
static const u8 sText_InGamePartnerSentOutZGoN[] = _("{B_PARTNER_NAME_WITH_CLASS} schickte {B_PLAYER_MON2_NAME} in den Kampf! Los, {B_PLAYER_MON1_NAME}!");

const u16 gBattlePalaceFlavorTextTable[] =
{
    [B_MSG_GLINT_IN_EYE]   = STRINGID_GLINTAPPEARSINEYE,
    [B_MSG_GETTING_IN_POS] = STRINGID_PKMNGETTINGINTOPOSITION,
    [B_MSG_GROWL_DEEPLY]   = STRINGID_PKMNBEGANGROWLINGDEEPLY,
    [B_MSG_EAGER_FOR_MORE] = STRINGID_PKMNEAGERFORMORE,
};

const u8 *const gRefereeStringsTable[] =
{
    [B_MSG_REF_NOTHING_IS_DECIDED] = COMPOUND_STRING("SCHIEDSRICHTER: Wenn in 3 Runden nichts entschieden ist, gehen wir zum Urteil!"),
    [B_MSG_REF_THATS_IT]           = COMPOUND_STRING("SCHIEDSRICHTER: Das war's! Wir gehen jetzt zum Urteil, um den Gewinner zu bestimmen!"),
    [B_MSG_REF_JUDGE_MIND]         = COMPOUND_STRING("SCHIEDSRICHTER: Urteil Kategorie 1, Geist! Das Pokémon, das den meisten Mut zeigt!\p"),
    [B_MSG_REF_JUDGE_SKILL]        = COMPOUND_STRING("SCHIEDSRICHTER: Urteil Kategorie 2, Fähigkeit! Das Pokémon, das die besten Züge verwendet!\p"),
    [B_MSG_REF_JUDGE_BODY]         = COMPOUND_STRING("SCHIEDSRICHTER: Urteil Kategorie 3, Körper! Das Pokémon mit der meisten Vitalität!\p"),
    [B_MSG_REF_PLAYER_WON]         = COMPOUND_STRING("SCHIEDSRICHTER: Urteil: {B_BUFF1} zu {B_BUFF2}! Der Gewinner ist {B_PLAYER_NAME}'s {B_PLAYER_MON1_NAME}!\p"),
    [B_MSG_REF_OPPONENT_WON]       = COMPOUND_STRING("SCHIEDSRICHTER: Urteil: {B_BUFF1} zu {B_BUFF2}! Der Gewinner ist {B_TRAINER1_NAME}'s {B_OPPONENT_MON1_NAME}!\p"),
    [B_MSG_REF_DRAW]               = COMPOUND_STRING("SCHIEDSRICHTER: Urteil: 3 zu 3! Es ist ein Unentschieden!\p"),
    [B_MSG_REF_COMMENCE_BATTLE]    = COMPOUND_STRING("SCHIEDSRICHTER: {B_PLAYER_MON1_NAME} VS {B_OPPONENT_MON1_NAME}! Beginnt den Kampf!"),
};

static const u8 sText_Trainer1Fled[] = _( "{PLAY_SE SE_FLEE}{B_TRAINER1_NAME_WITH_CLASS} ist geflohen!");
static const u8 sText_PlayerLostAgainstTrainer1[] = _("Du hast gegen {B_TRAINER1_NAME_WITH_CLASS} verloren!");
static const u8 sText_PlayerBattledToDrawTrainer1[] = _("Du hast ein Unentschieden gegen {B_TRAINER1_NAME_WITH_CLASS} erreicht!");
const u8 gText_RecordBattleToPass[] = _("Möchtest du deinen Kampf auf deinem\nFrontier Pass aufzeichnen?");
const u8 gText_BattleRecordedOnPass[] = _("{B_PLAYER_NAME}'s Kampfergebnis wurde\nauf dem Frontier Pass aufgezeichnet.");
static const u8 sText_LinkTrainerWantsToBattlePause[] = _("Du wirst herausgefordert von {B_LINK_OPPONENT1_NAME}!\p");
static const u8 sText_TwoLinkTrainersWantToBattlePause[] = _("Du wirst herausgefordert von {B_LINK_OPPONENT1_NAME} und {B_LINK_OPPONENT2_NAME}!\p");
static const u8 sText_Your1[] = _("Dein");
static const u8 sText_Opposing1[] = _("Das gegnerische");
static const u8 sText_Your2[] = _("dein");
static const u8 sText_Opposing2[] = _("das gegnerische");

// This is four lists of moves which use a different attack string in Japanese
// to the default. See the documentation for ChooseTypeOfMoveUsedString for more detail.
static const u16 sGrammarMoveUsedTable[] =
{
    MOVE_SWORDS_DANCE, MOVE_STRENGTH, MOVE_GROWTH,
    MOVE_HARDEN, MOVE_MINIMIZE, MOVE_SMOKESCREEN,
    MOVE_WITHDRAW, MOVE_DEFENSE_CURL, MOVE_EGG_BOMB,
    MOVE_SMOG, MOVE_BONE_CLUB, MOVE_FLASH, MOVE_SPLASH,
    MOVE_ACID_ARMOR, MOVE_BONEMERANG, MOVE_REST, MOVE_SHARPEN,
    MOVE_SUBSTITUTE, MOVE_MIND_READER, MOVE_SNORE,
    MOVE_PROTECT, MOVE_SPIKES, MOVE_ENDURE, MOVE_ROLLOUT,
    MOVE_SWAGGER, MOVE_SLEEP_TALK, MOVE_HIDDEN_POWER,
    MOVE_PSYCH_UP, MOVE_EXTREME_SPEED, MOVE_FOLLOW_ME,
    MOVE_TRICK, MOVE_ASSIST, MOVE_INGRAIN, MOVE_KNOCK_OFF,
    MOVE_CAMOUFLAGE, MOVE_ASTONISH, MOVE_ODOR_SLEUTH,
    MOVE_GRASS_WHISTLE, MOVE_SHEER_COLD, MOVE_MUDDY_WATER,
    MOVE_IRON_DEFENSE, MOVE_BOUNCE, 0,

    MOVE_TELEPORT, MOVE_RECOVER, MOVE_BIDE, MOVE_AMNESIA,
    MOVE_FLAIL, MOVE_TAUNT, MOVE_BULK_UP, 0,

    MOVE_MEDITATE, MOVE_AGILITY, MOVE_MIMIC, MOVE_DOUBLE_TEAM,
    MOVE_BARRAGE, MOVE_TRANSFORM, MOVE_STRUGGLE, MOVE_SCARY_FACE,
    MOVE_CHARGE, MOVE_WISH, MOVE_BRICK_BREAK, MOVE_YAWN,
    MOVE_FEATHER_DANCE, MOVE_TEETER_DANCE, MOVE_MUD_SPORT,
    MOVE_FAKE_TEARS, MOVE_WATER_SPORT, MOVE_CALM_MIND, 0,

    MOVE_POUND, MOVE_SCRATCH, MOVE_VISE_GRIP,
    MOVE_WING_ATTACK, MOVE_FLY, MOVE_BIND, MOVE_SLAM,
    MOVE_HORN_ATTACK, MOVE_WRAP, MOVE_THRASH, MOVE_TAIL_WHIP,
    MOVE_LEER, MOVE_BITE, MOVE_GROWL, MOVE_ROAR,
    MOVE_SING, MOVE_PECK, MOVE_ABSORB, MOVE_STRING_SHOT,
    MOVE_EARTHQUAKE, MOVE_FISSURE, MOVE_DIG, MOVE_TOXIC,
    MOVE_SCREECH, MOVE_METRONOME, MOVE_LICK, MOVE_CLAMP,
    MOVE_CONSTRICT, MOVE_POISON_GAS, MOVE_BUBBLE,
    MOVE_SLASH, MOVE_SPIDER_WEB, MOVE_NIGHTMARE, MOVE_CURSE,
    MOVE_FORESIGHT, MOVE_CHARM, MOVE_ATTRACT, MOVE_ROCK_SMASH,
    MOVE_UPROAR, MOVE_SPIT_UP, MOVE_SWALLOW, MOVE_TORMENT,
    MOVE_FLATTER, MOVE_ROLE_PLAY, MOVE_ENDEAVOR, MOVE_TICKLE,
    MOVE_COVET, 0
};

static const u8 sText_EmptyStatus[] = _("$$$$$$$");

static const struct BattleWindowText sTextOnWindowsInfo_Normal[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 13 : 12,
        .bgColor = 14,
        .shadowColor = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 15 : 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 2,
    },
    [B_WIN_VS_PLAYER] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OPPONENT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_MULTI_PLAYER_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_VS_OUTCOME_DRAW] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_LEFT] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_VS_OUTCOME_RIGHT] = {
        .fillValue = PIXEL_FILL(0x0),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 6,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
};

static const struct BattleWindowText sTextOnWindowsInfo_Arena[] =
{
    [B_WIN_MSG] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_PROMPT] = {
        .fillValue = PIXEL_FILL(0xF),
        .fontId = FONT_NORMAL,
        .x = 1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 15,
        .shadowColor = 6,
    },
    [B_WIN_ACTION_MENU] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_1] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_2] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_3] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_MOVE_NAME_4] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 13 : 12,
        .bgColor = 14,
        .shadowColor = B_SHOW_EFFECTIVENESS != SHOW_EFFECTIVENESS_NEVER ? 15 : 11,
    },
    [B_WIN_DUMMY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_PP_REMAINING] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 2,
        .y = 1,
        .speed = 0,
        .fgColor = 12,
        .bgColor = 14,
        .shadowColor = 11,
    },
    [B_WIN_MOVE_TYPE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_SWITCH_PROMPT] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_YESNO] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BOX] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [B_WIN_LEVEL_UP_BANNER] = {
        .fillValue = PIXEL_FILL(0),
        .fontId = FONT_NORMAL,
        .x = 32,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .shadowColor = 2,
    },
    [ARENA_WIN_PLAYER_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 1,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_VS] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_OPPONENT_NAME] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_MIND] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_SKILL] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_BODY] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_JUDGMENT_TITLE] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NORMAL,
        .x = -1,
        .y = 1,
        .speed = 0,
        .fgColor = 13,
        .bgColor = 14,
        .shadowColor = 15,
    },
    [ARENA_WIN_JUDGMENT_TEXT] = {
        .fillValue = PIXEL_FILL(0x1),
        .fontId = FONT_NORMAL,
        .x = 0,
        .y = 1,
        .speed = 1,
        .fgColor = 2,
        .bgColor = 1,
        .shadowColor = 3,
    },
    [B_WIN_MOVE_DESCRIPTION] = {
        .fillValue = PIXEL_FILL(0xE),
        .fontId = FONT_NARROW,
        .x = 0,
        .y = 1,
        .letterSpacing = 0,
        .lineSpacing = 0,
        .speed = 0,
        .fgColor = TEXT_DYNAMIC_COLOR_4,
        .bgColor = TEXT_DYNAMIC_COLOR_5,
        .shadowColor = TEXT_DYNAMIC_COLOR_6,
    },
};

static const struct BattleWindowText *const sBattleTextOnWindowsInfo[] =
{
    [B_WIN_TYPE_NORMAL] = sTextOnWindowsInfo_Normal,
    [B_WIN_TYPE_ARENA]  = sTextOnWindowsInfo_Arena
};

static const u8 sRecordedBattleTextSpeeds[] = {8, 4, 1, 0};

void BufferStringBattle(enum StringID stringID, u32 battler)
{
    s32 i;
    const u8 *stringPtr = NULL;

    gBattleMsgDataPtr = (struct BattleMsgData *)(&gBattleResources->bufferA[battler][4]);
    gLastUsedItem = gBattleMsgDataPtr->lastItem;
    gLastUsedAbility = gBattleMsgDataPtr->lastAbility;
    gBattleScripting.battler = gBattleMsgDataPtr->scrActive;
    gBattleStruct->scriptPartyIdx = gBattleMsgDataPtr->bakScriptPartyIdx;
    gBattleStruct->hpScale = gBattleMsgDataPtr->hpScale;
    gPotentialItemEffectBattler = gBattleMsgDataPtr->itemEffectBattler;
    gBattleStruct->stringMoveType = gBattleMsgDataPtr->moveType;

    for (i = 0; i < MAX_BATTLERS_COUNT; i++)
    {
        sBattlerAbilities[i] = gBattleMsgDataPtr->abilities[i];
    }
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        gBattleTextBuff1[i] = gBattleMsgDataPtr->textBuffs[0][i];
        gBattleTextBuff2[i] = gBattleMsgDataPtr->textBuffs[1][i];
        gBattleTextBuff3[i] = gBattleMsgDataPtr->textBuffs[2][i];
    }

    switch (stringID)
    {
    case STRINGID_INTROMSG: // first battle msg
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    stringPtr = sText_TwoTrainersWantToBattle;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                    {
                        if (TESTING && gBattleTypeFlags & BATTLE_TYPE_MULTI)
                        {
                            if (!(gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS))
                                stringPtr = sText_Trainer1WantsToBattle;
                            else
                                stringPtr = sText_TwoTrainersWantToBattle;
                        }
                        else if (TESTING && gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                        {
                            stringPtr = sText_TwoTrainersWantToBattle;
                        }
                        else if (!(gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS))
                        {
                            stringPtr = sText_LinkTrainerWantsToBattlePause;
                        }
                        else
                        {
                            stringPtr = sText_TwoLinkTrainersWantToBattlePause;
                        }
                    }
                    else
                    {
                        stringPtr = sText_TwoLinkTrainersWantToBattle;
                    }
                }
                else
                {
                    if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
                        stringPtr = sText_Trainer1WantsToBattle;
                    else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
                        stringPtr = sText_LinkTrainerWantsToBattlePause;
                    else
                        stringPtr = sText_LinkTrainerWantsToBattle;
                }
            }
            else
            {
                if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_Trainer1WantsToBattle;
                else if (gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER))
                    stringPtr = sText_TwoTrainersWantToBattle;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersWantToBattle;
                else
                    stringPtr = sText_Trainer1WantsToBattle;
            }
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_LEGENDARY)
                stringPtr = sText_LegendaryPkmnAppeared;
            else if (IsDoubleBattle() && IsValidForBattle(GetBattlerMon(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT))))
            {
                // ✅ Prüfe ob EINES der beiden Pokemon Shiny ist
                bool8 mon1Shiny = GetMonData(GetBattlerMon(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)), MON_DATA_IS_SHINY);
                bool8 mon2Shiny = GetMonData(GetBattlerMon(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT)), MON_DATA_IS_SHINY);
                
                if (mon1Shiny || mon2Shiny)
                    stringPtr = sText_TwoWildShinyPkmnAppeared;
                else
                    stringPtr = sText_TwoWildPkmnAppeared;
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
                stringPtr = sText_WildPkmnAppearedPause;
            else
            {
                // ✅ Prüfe ob das einzelne Wild-Pokemon Shiny ist
                bool8 monShiny = GetMonData(GetBattlerMon(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)), MON_DATA_IS_SHINY);
                stringPtr = monShiny ? sText_WildShinyPkmnAppeared : sText_WildPkmnAppeared;
            }
        }
        break;
    case STRINGID_INTROSENDOUT: // poke first send-out
        if (IsOnPlayerSide(battler))
        {
            if (IsDoubleBattle() && IsValidForBattle(GetBattlerMon(BATTLE_PARTNER(battler))))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                    stringPtr = sText_InGamePartnerSentOutZGoN;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_GoTwoPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkPartnerSentOutPkmnGoPkmn;
                else
                    stringPtr = sText_GoTwoPkmn;
            }
            else
            {
                stringPtr = sText_GoPkmn;
            }
        }
        else
        {
            if (IsDoubleBattle() && IsValidForBattle(GetBattlerMon(BATTLE_PARTNER(battler))))
            {
                if (BATTLE_TWO_VS_ONE_OPPONENT)
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                    stringPtr = sText_TwoTrainersSentPkmn;
                else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_TwoLinkTrainersSentOutPkmn;
                else if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                    stringPtr = sText_LinkTrainerSentOutTwoPkmn;
                else
                    stringPtr = sText_Trainer1SentOutTwoPkmn;
            }
            else
            {
                if (!(gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK)))
                    stringPtr = sText_Trainer1SentOutPkmn;
                else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
                    stringPtr = sText_Trainer1SentOutPkmn;
                else
                    stringPtr = sText_LinkTrainerSentOutPkmn;
            }
        }
        break;
    case STRINGID_RETURNMON: // sending poke to ball msg
        if (IsOnPlayerSide(battler))
        {
            if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER && GetBattlerPosition(battler) == B_POSITION_PLAYER_RIGHT)
                stringPtr = sText_InGamePartnerWithdrewPkmn2;
            else if (*(&gBattleStruct->hpScale) == 0)
                stringPtr = sText_PkmnThatsEnough;
            else if (*(&gBattleStruct->hpScale) == 1 || IsDoubleBattle())
                stringPtr = sText_PkmnComeBack;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_PkmnOkComeBack;
            else
                stringPtr = sText_PkmnGoodComeBack;
        }
        else
        {
            if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_LINK_OPPONENT || gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    stringPtr = sText_LinkTrainer2WithdrewPkmn;
                else
                    stringPtr = sText_LinkTrainer1WithdrewPkmn;
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                {
                    if (GetBattlerPosition(battler) == B_POSITION_OPPONENT_LEFT)
                        stringPtr = sText_Trainer1WithdrewPkmn;
                    else
                        stringPtr = sText_Trainer2WithdrewPkmn;

                }
                else
                {
                    stringPtr = sText_Trainer1WithdrewPkmn;
                }
            }
        }
        break;
    case STRINGID_SWITCHINMON: // switch-in msg
        if (IsOnPlayerSide(gBattleScripting.battler))
        {
            if ((gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER) && (GetBattlerAtPosition(gBattleScripting.battler) == 2))
                stringPtr = sText_InGamePartnerSentOutPkmn2;
            else if (*(&gBattleStruct->hpScale) == 0 || IsDoubleBattle())
                stringPtr = sText_GoPkmn2;
            else if (*(&gBattleStruct->hpScale) == 1)
                stringPtr = sText_DoItPkmn;
            else if (*(&gBattleStruct->hpScale) == 2)
                stringPtr = sText_GoForItPkmn;
            else
                stringPtr = sText_YourFoesWeakGetEmPkmn;
        }
        else
        {
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    if (TESTING && gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    {
                        if (gBattleScripting.battler == 1)
                        {
                            stringPtr = sText_Trainer1SentOutPkmn;
                        }
                        else
                        {
                            if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                                stringPtr = sText_Trainer2SentOutPkmn;
                            else
                                stringPtr = sText_Trainer1SentOutPkmn2;
                        }
                    }
                    else if (TESTING && gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                    {
                        if (gBattleScripting.battler == 1)
                            stringPtr = sText_Trainer1SentOutPkmn;
                        else
                            stringPtr = sText_Trainer2SentOutPkmn;
                    }
                    else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                    {
                        stringPtr = sText_LinkTrainerMultiSentOutPkmn;
                    }
                    else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
                    {
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    }
                    else
                    {
                        stringPtr = sText_LinkTrainerSentOutPkmn2;
                    }
                }
            }
            else
            {
                if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
                {
                    if (gBattleScripting.battler == 1)
                        stringPtr = sText_Trainer1SentOutPkmn2;
                    else
                        stringPtr = sText_Trainer2SentOutPkmn;
                }
                else
                {
                    stringPtr = sText_Trainer1SentOutPkmn2;
                }
            }
        }
        break;
    case STRINGID_USEDMOVE: // Pokémon used a move msg
        if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT
         && !IsZMove(gBattleMsgDataPtr->currentMove)
         && !IsMaxMove(gBattleMsgDataPtr->currentMove))
            StringCopy(gBattleTextBuff3, gTypesInfo[*(&gBattleStruct->stringMoveType)].generic);
        else
            StringCopy(gBattleTextBuff3, GetMoveName(gBattleMsgDataPtr->currentMove));
        stringPtr = sText_AttackerUsedX;
        break;
    case STRINGID_BATTLEEND: // battle end
        if (gBattleTextBuff1[0] & B_OUTCOME_LINK_BATTLE_RAN)
        {
            gBattleTextBuff1[0] &= ~(B_OUTCOME_LINK_BATTLE_RAN);
            if (!IsOnPlayerSide(battler) && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTextBuff1[0] == B_OUTCOME_LOST || gBattleTextBuff1[0] == B_OUTCOME_DREW)
                stringPtr = sText_GotAwaySafely;
            else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
                stringPtr = sText_TwoWildFled;
            else
                stringPtr = sText_WildFled;
        }
        else
        {
            if (!IsOnPlayerSide(battler) && gBattleTextBuff1[0] != B_OUTCOME_DREW)
                gBattleTextBuff1[0] ^= (B_OUTCOME_LOST | B_OUTCOME_WON);

            if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    if (gBattleTypeFlags & BATTLE_TYPE_TOWER_LINK_MULTI)
                        stringPtr = sText_TwoInGameTrainersDefeated;
                    else
                        stringPtr = sText_TwoLinkTrainersDefeated;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostToTwo;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawVsTwo;
                    break;
                }
            }
            else if (TRAINER_BATTLE_PARAM.opponentA == TRAINER_UNION_ROOM)
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainerTrainer1;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstTrainer1;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawTrainer1;
                    break;
                }
            }
            else
            {
                switch (gBattleTextBuff1[0])
                {
                case B_OUTCOME_WON:
                    stringPtr = sText_PlayerDefeatedLinkTrainer;
                    break;
                case B_OUTCOME_LOST:
                    stringPtr = sText_PlayerLostAgainstLinkTrainer;
                    break;
                case B_OUTCOME_DREW:
                    stringPtr = sText_PlayerBattledToDrawLinkTrainer;
                    break;
                }
            }
        }
        break;
    case STRINGID_TRAINERSLIDE:
        stringPtr = gBattleStruct->trainerSlideMsg;
        break;
    default: // load a string from the table
        if (stringID >= STRINGID_COUNT)
        {
            gDisplayedStringBattle[0] = EOS;
            return;
        }
        else
        {
            stringPtr = gBattleStringsTable[stringID];
        }
        break;
    }

    BattleStringExpandPlaceholdersToDisplayedString(stringPtr);
}

u32 BattleStringExpandPlaceholdersToDisplayedString(const u8 *src)
{
#ifndef NDEBUG
    u32 j, strWidth;
    u32 dstID = BattleStringExpandPlaceholders(src, gDisplayedStringBattle, sizeof(gDisplayedStringBattle));
    for (j = 1;; j++)
    {
        strWidth = GetStringLineWidth(0, gDisplayedStringBattle, 0, j, sizeof(gDisplayedStringBattle));
        if (strWidth == 0)
            break;
    }
    return dstID;
#else
    return BattleStringExpandPlaceholders(src, gDisplayedStringBattle, sizeof(gDisplayedStringBattle));
#endif
}

static const u8 *TryGetStatusString(u8 *src)
{
    u32 i;
    u8 status[8];
    u32 chars1, chars2;
    u8 *statusPtr;

    memcpy(status, sText_EmptyStatus, min(ARRAY_COUNT(status), ARRAY_COUNT(sText_EmptyStatus)));

    statusPtr = status;
    for (i = 0; i < ARRAY_COUNT(status); i++)
    {
        if (*src == EOS) break; // one line required to match -g
        *statusPtr = *src;
        src++;
        statusPtr++;
    }

    chars1 = *(u32 *)(&status[0]);
    chars2 = *(u32 *)(&status[4]);

    for (i = 0; i < ARRAY_COUNT(gStatusConditionStringsTable); i++)
    {
        if (chars1 == *(u32 *)(&gStatusConditionStringsTable[i][0][0])
            && chars2 == *(u32 *)(&gStatusConditionStringsTable[i][0][4]))
            return gStatusConditionStringsTable[i][1];
    }
    return NULL;
}

static void GetBattlerNick(u32 battler, u8 *dst)
{
    struct Pokemon *illusionMon = GetIllusionMonPtr(battler);
    struct Pokemon *mon = GetBattlerMon(battler);

    if (illusionMon != NULL)
        mon = illusionMon;
    GetMonData(mon, MON_DATA_NICKNAME, dst);
    StringGet_Nickname(dst);
}

#define HANDLE_NICKNAME_STRING_CASE(battler)                            \
{                                                                       \
    /* Erst den Nicknamen holen und schreiben */                        \
    GetMonData(                                                         \
        IsOnPlayerSide(battler)                                         \
            ? &gPlayerParty[gBattlerPartyIndexes[battler]]              \
            : &gEnemyParty[gBattlerPartyIndexes[battler]],              \
        MON_DATA_NICKNAME, text);                                       \
    StringGet_Nickname(text);                                           \
    toCpy = text;                                                       \
    while (*toCpy != EOS)                                               \
    {                                                                   \
        dst[dstID++] = *toCpy++;                                        \
    }                                                                   \
    /* Danach ggf. (Wild) oder (Gegner) anhängen */                     \
    if (!IsOnPlayerSide(battler))                                       \
    {                                                                   \
        dst[dstID++] = CHAR_SPACE; /* Leerzeichen vor Klammer */        \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            toCpy = sText_FoePkmnPrefix;                                \
        else                                                            \
            toCpy = sText_WildPkmnPrefix;                               \
        while (*toCpy != EOS)                                           \
        {                                                               \
            dst[dstID++] = *toCpy++;                                    \
        }                                                               \
    }                                                                   \
}

#define HANDLE_NICKNAME_STRING_LOWERCASE(battler)                       \
{                                                                       \
    /* Erst den Nicknamen holen und schreiben */                        \
    GetMonData(                                                         \
        IsOnPlayerSide(battler)                                         \
            ? &gPlayerParty[gBattlerPartyIndexes[battler]]              \
            : &gEnemyParty[gBattlerPartyIndexes[battler]],              \
        MON_DATA_NICKNAME, text);                                       \
    StringGet_Nickname(text);                                           \
    toCpy = text;                                                       \
    while (*toCpy != EOS)                                               \
    {                                                                   \
        dst[dstID++] = *toCpy++;                                        \
    }                                                                   \
    /* Danach ggf. (wild) oder (gegner) anhängen (klein) */             \
    if (!IsOnPlayerSide(battler))                                       \
    {                                                                   \
        dst[dstID++] = CHAR_SPACE; /* Leerzeichen vor Klammer */        \
        if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)                     \
            toCpy = sText_FoePkmnPrefixLower;                           \
        else                                                            \
            toCpy = sText_WildPkmnPrefixLower;                          \
        while (*toCpy != EOS)                                           \
        {                                                               \
            dst[dstID++] = *toCpy++;                                    \
        }                                                               \
    }                                                                   \
}

static const u8 *BattleStringGetOpponentNameByTrainerId(u16 trainerId, u8 *text, u8 multiplayerId, u8 battler)
{
    const u8 *toCpy = NULL;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
    {
        u32 i;
        for (i = 0; i < ARRAY_COUNT(gBattleResources->secretBase->trainerName); i++)
            text[i] = gBattleResources->secretBase->trainerName[i];
        text[i] = EOS;
        ConvertInternationalString(text, gBattleResources->secretBase->language);
        toCpy = text;
    }
    else if (trainerId == TRAINER_UNION_ROOM)
    {
        toCpy = gLinkPlayers[multiplayerId ^ BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_LINK_OPPONENT)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battler)].name;
        else
            toCpy = gLinkPlayers[GetBattlerMultiplayerId(battler) & BIT_SIDE].name;
    }
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
    {
        CopyFrontierBrainTrainerName(text);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
    {
        GetFrontierTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
    {
        GetTrainerHillTrainerName(text, trainerId);
        toCpy = text;
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
    {
        GetEreaderTrainerName(text);
        toCpy = text;
    }
    else
    {
        toCpy = GetTrainerNameFromId(trainerId);
    }

    return toCpy;
}

static const u8 *BattleStringGetOpponentName(u8 *text, u8 multiplayerId, u8 battler)
{
    const u8 *toCpy = NULL;

    switch (GetBattlerPosition(battler))
    {
    case B_POSITION_OPPONENT_LEFT:
        toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, text, multiplayerId, battler);
        break;
    case B_POSITION_OPPONENT_RIGHT:
        if (gBattleTypeFlags & (BATTLE_TYPE_TWO_OPPONENTS | BATTLE_TYPE_MULTI) && !BATTLE_TWO_VS_ONE_OPPONENT)
            toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentB, text, multiplayerId, battler);
        else
            toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, text, multiplayerId, battler);
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetPlayerName(u8 *text, u8 battler)
{
    const u8 *toCpy = NULL;

    switch (GetBattlerPosition(battler))
    {
    case B_POSITION_PLAYER_LEFT:
        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            toCpy = gLinkPlayers[0].name;
        else
            toCpy = gSaveBlock2Ptr->playerName;
        break;
    case B_POSITION_PLAYER_RIGHT:
        if (((gBattleTypeFlags & BATTLE_TYPE_RECORDED) && !(gBattleTypeFlags & (BATTLE_TYPE_MULTI | BATTLE_TYPE_INGAME_PARTNER)))
            || gTestRunnerEnabled)
        {
            toCpy = gLinkPlayers[0].name;
        }
        else if ((gBattleTypeFlags & BATTLE_TYPE_LINK) && gBattleTypeFlags & (BATTLE_TYPE_RECORDED | BATTLE_TYPE_MULTI))
        {
            toCpy = gLinkPlayers[2].name;
        }
        else if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
        {
            GetFrontierTrainerName(text, gPartnerTrainerId);
            toCpy = text;
        }
        else
        {
            toCpy = gSaveBlock2Ptr->playerName;
        }
        break;
    }

    return toCpy;
}

static const u8 *BattleStringGetTrainerName(u8 *text, u8 multiplayerId, u8 battler)
{
    if (IsOnPlayerSide(battler))
        return BattleStringGetPlayerName(text, battler);
    else
        return BattleStringGetOpponentName(text, multiplayerId, battler);
}

static const u8 *BattleStringGetOpponentClassByTrainerId(u16 trainerId)
{
    const u8 *toCpy;

    if (gBattleTypeFlags & BATTLE_TYPE_SECRET_BASE)
        toCpy = gTrainerClasses[GetSecretBaseTrainerClass()].name;
    else if (trainerId == TRAINER_UNION_ROOM)
        toCpy = gTrainerClasses[GetUnionRoomTrainerClass()].name;
    else if (trainerId == TRAINER_FRONTIER_BRAIN)
        toCpy = gTrainerClasses[GetFrontierBrainTrainerClass()].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
        toCpy = gTrainerClasses[GetFrontierOpponentClass(trainerId)].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
        toCpy = gTrainerClasses[GetTrainerHillOpponentClass(trainerId)].name;
    else if (gBattleTypeFlags & BATTLE_TYPE_EREADER_TRAINER)
        toCpy = gTrainerClasses[GetEreaderTrainerClassId()].name;
    else
        toCpy = gTrainerClasses[GetTrainerClassFromId(trainerId)].name;

    return toCpy;
}

// Ensure the defined length for an item name can contain the full defined length of a berry name.
// This ensures that custom Enigma Berry names will fit in the text buffer at the top of BattleStringExpandPlaceholders.
STATIC_ASSERT(BERRY_NAME_LENGTH + ARRAY_COUNT(sText_BerrySuffix) <= ITEM_NAME_LENGTH, BerryNameTooLong);

u32 BattleStringExpandPlaceholders(const u8 *src, u8 *dst, u32 dstSize)
{
    u32 dstID = 0; // if they used dstID, why not use srcID as well?
    const u8 *toCpy = NULL;
    u8 text[max(max(max(32, TRAINER_NAME_LENGTH + 1), POKEMON_NAME_LENGTH + 1), ITEM_NAME_LENGTH)];
    u8 *textStart = &text[0];
    u8 multiplayerId;
    u8 fontId = FONT_NORMAL;

    if (gBattleTypeFlags & BATTLE_TYPE_RECORDED_LINK)
        multiplayerId = gRecordedBattleMultiplayerId;
    else
        multiplayerId = GetMultiplayerId();

    // Clear destination first
    while (dstID < dstSize)
    {
        dst[dstID] = EOS;
        dstID++;
    }

    dstID = 0;
    while (*src != EOS)
    {
        toCpy = NULL;

        if (*src == PLACEHOLDER_BEGIN)
        {
            src++;
            u32 classLength = 0;
            u32 nameLength = 0;
            const u8 *classString;
            const u8 *nameString;
            switch (*src)
            {
            case B_TXT_BUFF1:
                if (gBattleTextBuff1[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff1, gStringVar1);
                    toCpy = gStringVar1;
                }
                else
                {
                    toCpy = TryGetStatusString(gBattleTextBuff1);
                    if (toCpy == NULL)
                        toCpy = gBattleTextBuff1;
                }
                break;
            case B_TXT_BUFF2:
                if (gBattleTextBuff2[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff2, gStringVar2);
                    toCpy = gStringVar2;
                }
                else
                {
                    toCpy = gBattleTextBuff2;
                }
                break;
            case B_TXT_BUFF3:
                if (gBattleTextBuff3[0] == B_BUFF_PLACEHOLDER_BEGIN)
                {
                    ExpandBattleTextBuffPlaceholders(gBattleTextBuff3, gStringVar3);
                    toCpy = gStringVar3;
                }
                else
                {
                    toCpy = gBattleTextBuff3;
                }
                break;
            case B_TXT_COPY_VAR_1:
                toCpy = gStringVar1;
                break;
            case B_TXT_COPY_VAR_2:
                toCpy = gStringVar2;
                break;
            case B_TXT_COPY_VAR_3:
                toCpy = gStringVar3;
                break;
            case B_TXT_PLAYER_MON1_NAME: // first player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON1_NAME: // first enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON1_SHINY: // Shiny indicator for first enemy poke
                if (GetMonData(GetBattlerMon(GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT)), MON_DATA_IS_SHINY))
                    toCpy = COMPOUND_STRING("Shiny ");
                else
                    toCpy = COMPOUND_STRING("");
                break;
            case B_TXT_OPPONENT_MON2_SHINY: // Shiny indicator for second enemy poke
                if (GetMonData(GetBattlerMon(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT)), MON_DATA_IS_SHINY))
                    toCpy = COMPOUND_STRING("Shiny ");
                else
                    toCpy = COMPOUND_STRING("");
                break;
            case B_TXT_PLAYER_MON2_NAME: // second player poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_OPPONENT_MON2_NAME: // second enemy poke name
                GetBattlerNick(GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT), text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON1_NAME: // link first player poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id, text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON1_NAME: // link first opponent poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 1, text);
                toCpy = text;
                break;
            case B_TXT_LINK_PLAYER_MON2_NAME: // link second player poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 2, text);
                toCpy = text;
                break;
            case B_TXT_LINK_OPPONENT_MON2_NAME: // link second opponent poke name
                GetBattlerNick(gLinkPlayers[multiplayerId].id ^ 3, text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX_MON1: // Unused, to change into sth else.
                break;
            case B_TXT_ATK_PARTNER_NAME: // attacker partner name
                GetBattlerNick(BATTLE_PARTNER(gBattlerAttacker), text);
                toCpy = text;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX: // attacker name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerAttacker)
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX: // target name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattlerTarget)
                break;
            case B_TXT_DEF_NAME: // target name
                GetBattlerNick(gBattlerTarget, text);
                toCpy = text;
                break;
            case B_TXT_DEF_PARTNER_NAME: // partner target name
                GetBattlerNick(BATTLE_PARTNER(gBattlerTarget), text);
                toCpy = text;
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX: // effect battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gEffectBattler)
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX: // scripting active battler name with prefix
                HANDLE_NICKNAME_STRING_CASE(gBattleScripting.battler)
                break;
            case B_TXT_CURRENT_MOVE: // current move name
                if (gBattleMsgDataPtr->currentMove >= MOVES_COUNT
                 && !IsZMove(gBattleMsgDataPtr->currentMove)
                 && !IsMaxMove(gBattleMsgDataPtr->currentMove))
                    toCpy = gTypesInfo[gBattleStruct->stringMoveType].generic;
                else
                    toCpy = GetMoveName(gBattleMsgDataPtr->currentMove);
                break;
            case B_TXT_LAST_MOVE: // originally used move name
                if (gBattleMsgDataPtr->originallyUsedMove >= MOVES_COUNT
                 && !IsZMove(gBattleMsgDataPtr->currentMove)
                 && !IsMaxMove(gBattleMsgDataPtr->currentMove))
                    toCpy = gTypesInfo[gBattleStruct->stringMoveType].generic;
                else
                    toCpy = GetMoveName(gBattleMsgDataPtr->originallyUsedMove);
                break;
            case B_TXT_LAST_ITEM: // last used item
                if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
                {
                    if (gLastUsedItem == ITEM_ENIGMA_BERRY_E_READER)
                    {
                        if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
                        {
                            if ((gBattleScripting.multiplayerId != 0 && (gPotentialItemEffectBattler & BIT_SIDE))
                                || (gBattleScripting.multiplayerId == 0 && !(gPotentialItemEffectBattler & BIT_SIDE)))
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                            {
                                toCpy = sText_EnigmaBerry;
                            }
                        }
                        else
                        {
                            if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                            {
                                StringCopy(text, gEnigmaBerries[gPotentialItemEffectBattler].name);
                                StringAppend(text, sText_BerrySuffix);
                                toCpy = text;
                            }
                            else
                            {
                                toCpy = sText_EnigmaBerry;
                            }
                        }
                    }
                    else
                    {
                        CopyItemName(gLastUsedItem, text);
                        toCpy = text;
                    }
                }
                else
                {
                    CopyItemName(gLastUsedItem, text);
                    toCpy = text;
                }
                break;
            case B_TXT_LAST_ABILITY: // last used ability
                toCpy = gAbilitiesInfo[gLastUsedAbility].name;
                break;
            case B_TXT_ATK_ABILITY: // attacker ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gBattlerAttacker]].name;
                break;
            case B_TXT_DEF_ABILITY: // target ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gBattlerTarget]].name;
                break;
            case B_TXT_SCR_ACTIVE_ABILITY: // scripting active ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gBattleScripting.battler]].name;
                break;
            case B_TXT_EFF_ABILITY: // effect battler ability
                toCpy = gAbilitiesInfo[sBattlerAbilities[gEffectBattler]].name;
                break;
            case B_TXT_TRAINER1_CLASS: // trainer class name
                toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                break;
            case B_TXT_TRAINER1_NAME: // trainer1 name
                toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
                break;
            case B_TXT_TRAINER1_NAME_WITH_CLASS: // trainer1 name with trainer class
                toCpy = textStart;
                classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                while (classString[classLength] != EOS)
                {
                    textStart[classLength] = classString[classLength];
                    classLength++;
                }
                textStart[classLength] = CHAR_SPACE;
                textStart += classLength + 1;
                nameString = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentA, textStart, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_LEFT));
                if (nameString != textStart)
                {
                    while (nameString[nameLength] != EOS)
                    {
                        textStart[nameLength] = nameString[nameLength];
                        nameLength++;
                    }
                    textStart[nameLength] = EOS;
                }
                break;
            case B_TXT_LINK_PLAYER_NAME: // link player name
                toCpy = gLinkPlayers[multiplayerId].name;
                break;
            case B_TXT_LINK_PARTNER_NAME: // link partner name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT1_NAME: // link opponent 1 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id))].name;
                break;
            case B_TXT_LINK_OPPONENT2_NAME: // link opponent 2 name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(BATTLE_PARTNER(BATTLE_OPPOSITE(gLinkPlayers[multiplayerId].id)))].name;
                break;
            case B_TXT_LINK_SCR_TRAINER_NAME: // link scripting active name
                toCpy = gLinkPlayers[GetBattlerMultiplayerId(gBattleScripting.battler)].name;
                break;
            case B_TXT_PLAYER_NAME: // player name
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_LEFT));
                break;
            case B_TXT_TRAINER1_LOSE_TEXT: // trainerA lose text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerALoseText();
                }
                break;
            case B_TXT_TRAINER1_WIN_TEXT: // trainerA win text
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, TRAINER_BATTLE_PARAM.opponentA);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_26: // ?
                if (!IsOnPlayerSide(gBattleScripting.battler))
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        toCpy = sText_FoePkmnPrefix;
                    else
                        toCpy = sText_WildPkmnPrefix;
                    while (*toCpy != EOS)
                    {
                        dst[dstID] = *toCpy;
                        dstID++;
                        toCpy++;
                    }
                    GetMonData(&gEnemyParty[gBattleStruct->scriptPartyIdx], MON_DATA_NICKNAME, text);
                }
                else
                {
                    GetMonData(&gPlayerParty[gBattleStruct->scriptPartyIdx], MON_DATA_NICKNAME, text);
                }
                StringGet_Nickname(text);
                toCpy = text;
                break;
            case B_TXT_PC_CREATOR_NAME: // lanette pc
                if (FlagGet(FLAG_SYS_PC_LANETTE))
                    toCpy = sText_Lanettes;
                else
                    toCpy = sText_Someones;
                break;
            case B_TXT_ATK_PREFIX2:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_DEF_PREFIX2:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_AllyPkmnPrefix2;
                else
                    toCpy = sText_FoePkmnPrefix3;
                break;
            case B_TXT_ATK_PREFIX1:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_DEF_PREFIX1:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_AllyPkmnPrefix;
                else
                    toCpy = sText_FoePkmnPrefix2;
                break;
            case B_TXT_ATK_PREFIX3:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_DEF_PREFIX3:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_AllyPkmnPrefix3;
                else
                    toCpy = sText_FoePkmnPrefix4;
                break;
            case B_TXT_TRAINER2_CLASS:
                toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                break;
            case B_TXT_TRAINER2_NAME:
                toCpy = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentB, text, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT));
                break;
            case B_TXT_TRAINER2_NAME_WITH_CLASS:
                toCpy = textStart;
                classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                while (classString[classLength] != EOS)
                {
                    textStart[classLength] = classString[classLength];
                    classLength++;
                }
                textStart[classLength] = CHAR_SPACE;
                textStart += classLength + 1;
                nameString = BattleStringGetOpponentNameByTrainerId(TRAINER_BATTLE_PARAM.opponentB, textStart, multiplayerId, GetBattlerAtPosition(B_POSITION_OPPONENT_RIGHT));
                if (nameString != textStart)
                {
                    while (nameString[nameLength] != EOS)
                    {
                        textStart[nameLength] = nameString[nameLength];
                        nameLength++;
                    }
                    textStart[nameLength] = EOS;
                }
                break;
            case B_TXT_TRAINER2_LOSE_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_WON_TEXT, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_WON, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                else
                {
                    toCpy = GetTrainerBLoseText();
                }
                break;
            case B_TXT_TRAINER2_WIN_TEXT:
                if (gBattleTypeFlags & BATTLE_TYPE_FRONTIER)
                {
                    CopyFrontierTrainerText(FRONTIER_PLAYER_LOST_TEXT, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                else if (gBattleTypeFlags & BATTLE_TYPE_TRAINER_HILL)
                {
                    CopyTrainerHillTrainerText(TRAINER_HILL_TEXT_PLAYER_LOST, TRAINER_BATTLE_PARAM.opponentB);
                    toCpy = gStringVar4;
                }
                break;
            case B_TXT_PARTNER_CLASS:
                toCpy = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                break;
            case B_TXT_PARTNER_NAME:
                toCpy = BattleStringGetPlayerName(text, GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT));
                break;
            case B_TXT_PARTNER_NAME_WITH_CLASS:
                toCpy = textStart;
                classString = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                while (classString[classLength] != EOS)
                {
                    textStart[classLength] = classString[classLength];
                    classLength++;
                }
                textStart[classLength] = CHAR_SPACE;
                textStart += classLength + 1;
                nameString = BattleStringGetPlayerName(textStart, GetBattlerAtPosition(B_POSITION_PLAYER_RIGHT));
                if (nameString != textStart)
                {
                    while (nameString[nameLength] != EOS)
                    {
                        textStart[nameLength] = nameString[nameLength];
                        nameLength++;
                    }
                    textStart[nameLength] = EOS;
                }
                break;
            case B_TXT_ATK_TRAINER_NAME:
                toCpy = BattleStringGetTrainerName(text, multiplayerId, gBattlerAttacker);
                break;
            case B_TXT_ATK_TRAINER_CLASS:
                switch (GetBattlerPosition(gBattlerAttacker))
                {
                case B_POSITION_PLAYER_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                        toCpy = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                    break;
                case B_POSITION_OPPONENT_LEFT:
                    toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                    break;
                case B_POSITION_OPPONENT_RIGHT:
                    if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && !BATTLE_TWO_VS_ONE_OPPONENT)
                        toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                    else
                        toCpy = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                    break;
                }
                break;
            case B_TXT_ATK_TRAINER_NAME_WITH_CLASS:
                toCpy = textStart;
                if (GetBattlerPosition(gBattlerAttacker) == B_POSITION_PLAYER_LEFT)
                {
                    textStart = StringCopy(textStart, BattleStringGetTrainerName(textStart, multiplayerId, gBattlerAttacker));
                }
                else
                {
                    classString = NULL;
                    switch (GetBattlerPosition(gBattlerAttacker))
                    {
                    case B_POSITION_PLAYER_RIGHT:
                        if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
                            classString = gTrainerClasses[GetFrontierOpponentClass(gPartnerTrainerId)].name;
                        break;
                    case B_POSITION_OPPONENT_LEFT:
                        classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                        break;
                    case B_POSITION_OPPONENT_RIGHT:
                        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS && !BATTLE_TWO_VS_ONE_OPPONENT)
                            classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentB);
                        else
                            classString = BattleStringGetOpponentClassByTrainerId(TRAINER_BATTLE_PARAM.opponentA);
                        break;
                    }
                    classLength = 0;
                    nameLength = 0;
                    while (classString[classLength] != EOS)
                    {
                        textStart[classLength] = classString[classLength];
                        classLength++;
                    }
                    textStart[classLength] = CHAR_SPACE;
                    textStart += 1 + classLength;
                    nameString = BattleStringGetTrainerName(textStart, multiplayerId, gBattlerAttacker);
                    if (nameString != textStart)
                    {
                        while (nameString[nameLength] != EOS)
                        {
                            textStart[nameLength] = nameString[nameLength];
                            nameLength++;
                        }
                        textStart[nameLength] = EOS;
                    }
                }
                break;
            case B_TXT_ATK_TEAM1:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_ATK_TEAM2:
                if (IsOnPlayerSide(gBattlerAttacker))
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_DEF_TEAM1:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_DEF_TEAM2:
                if (IsOnPlayerSide(gBattlerTarget))
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_EFF_TEAM1:
                if (IsOnPlayerSide(gEffectBattler))
                    toCpy = sText_Your1;
                else
                    toCpy = sText_Opposing1;
                break;
            case B_TXT_EFF_TEAM2:
                if (IsOnPlayerSide(gEffectBattler))
                    toCpy = sText_Your2;
                else
                    toCpy = sText_Opposing2;
                break;
            case B_TXT_ATK_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gBattlerAttacker)
                break;
            case B_TXT_DEF_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gBattlerTarget)
                break;
            case B_TXT_EFF_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gEffectBattler)
                break;
            case B_TXT_SCR_ACTIVE_NAME_WITH_PREFIX2:
                HANDLE_NICKNAME_STRING_LOWERCASE(gBattleScripting.battler)
                break;
            }

            if (toCpy != NULL)
            {
                while (*toCpy != EOS)
                {
                    if (*toCpy == CHAR_SPACE)
                        dst[dstID] = CHAR_NBSP;
                    else
                        dst[dstID] = *toCpy;
                    dstID++;
                    toCpy++;
                }
            }

            if (*src == B_TXT_TRAINER1_LOSE_TEXT || *src == B_TXT_TRAINER2_LOSE_TEXT
                || *src == B_TXT_TRAINER1_WIN_TEXT || *src == B_TXT_TRAINER2_WIN_TEXT)
            {
                dst[dstID] = EXT_CTRL_CODE_BEGIN;
                dstID++;
                dst[dstID] = EXT_CTRL_CODE_PAUSE_UNTIL_PRESS;
                dstID++;
            }
        }
        else
        {
            dst[dstID] = *src;
            dstID++;
        }
        src++;
    }

    dst[dstID] = *src;
    dstID++;

    BreakStringAutomatic(dst, BATTLE_MSG_MAX_WIDTH, BATTLE_MSG_MAX_LINES, fontId, SHOW_SCROLL_PROMPT);

    return dstID;
}

static void IllusionNickHack(u32 battler, u32 partyId, u8 *dst)
{
    u32 id = PARTY_SIZE;
    // we know it's gEnemyParty
    struct Pokemon *mon = &gEnemyParty[partyId], *partnerMon;

    if (GetMonAbility(mon) == ABILITY_ILLUSION)
    {
        if (IsBattlerAlive(BATTLE_PARTNER(battler)))
            partnerMon = GetBattlerMon(BATTLE_PARTNER(battler));
        else
            partnerMon = mon;

        id = GetIllusionMonPartyId(gEnemyParty, mon, partnerMon, battler);
    }

    if (id != PARTY_SIZE)
        GetMonData(&gEnemyParty[id], MON_DATA_NICKNAME, dst);
    else
        GetMonData(mon, MON_DATA_NICKNAME, dst);
}

void ExpandBattleTextBuffPlaceholders(const u8 *src, u8 *dst)
{
    u32 srcID = 1;
    u32 value = 0;
    u8 nickname[POKEMON_NAME_LENGTH + 1];
    u16 hword;

    *dst = EOS;
    while (src[srcID] != B_BUFF_EOS)
    {
        switch (src[srcID])
        {
        case B_BUFF_STRING: // battle string
            hword = T1_READ_16(&src[srcID + 1]);
            StringAppend(dst, gBattleStringsTable[hword]);
            srcID += 3;
            break;
        case B_BUFF_NUMBER: // int to string
            switch (src[srcID + 1])
            {
            case 1:
                value = src[srcID + 3];
                break;
            case 2:
                value = T1_READ_16(&src[srcID + 3]);
                break;
            case 4:
                value = T1_READ_32(&src[srcID + 3]);
                break;
            }
            ConvertIntToDecimalStringN(dst, value, STR_CONV_MODE_LEFT_ALIGN, src[srcID + 2]);
            srcID += src[srcID + 1] + 3;
            break;
        case B_BUFF_MOVE: // move name
            StringAppend(dst, GetMoveName(T1_READ_16(&src[srcID + 1])));
            srcID += 3;
            break;
        case B_BUFF_TYPE: // type name
            StringAppend(dst, gTypesInfo[src[srcID + 1]].name);
            srcID += 2;
            break;
        case B_BUFF_MON_NICK_WITH_PREFIX: // poke nick with prefix
        case B_BUFF_MON_NICK_WITH_PREFIX_LOWER: // poke nick with lowercase prefix
            if (IsOnPlayerSide(src[srcID + 1]))
            {
                GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            }
            else
            {
                if (src[srcID] == B_BUFF_MON_NICK_WITH_PREFIX_LOWER)
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        StringAppend(dst, sText_FoePkmnPrefixLower);
                    else
                        StringAppend(dst, sText_WildPkmnPrefixLower);
                }
                else
                {
                    if (gBattleTypeFlags & BATTLE_TYPE_TRAINER)
                        StringAppend(dst, sText_FoePkmnPrefix);
                    else
                        StringAppend(dst, sText_WildPkmnPrefix);
                }

                GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, nickname);
            }
            StringGet_Nickname(nickname);
            StringAppend(dst, nickname);
            srcID += 3;
            break;
        case B_BUFF_STAT: // stats
            StringAppend(dst, gStatNamesTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_SPECIES: // species name
            StringCopy(dst, GetSpeciesName(T1_READ_16(&src[srcID + 1])));
            srcID += 3;
            break;
        case B_BUFF_MON_NICK: // poke nick without prefix
            if (src[srcID + 2] == gBattlerPartyIndexes[src[srcID + 1]])
            {
                GetBattlerNick(src[srcID + 1], dst);
            }
            else if (gBattleScripting.illusionNickHack) // for STRINGID_ENEMYABOUTTOSWITCHPKMN
            {
                gBattleScripting.illusionNickHack = 0;
                IllusionNickHack(src[srcID + 1], src[srcID + 2], dst);
                StringGet_Nickname(dst);
            }
            else
            {
                if (IsOnPlayerSide(src[srcID + 1]))
                    GetMonData(&gPlayerParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                else
                    GetMonData(&gEnemyParty[src[srcID + 2]], MON_DATA_NICKNAME, dst);
                StringGet_Nickname(dst);
            }
            srcID += 3;
            break;
        case B_BUFF_NEGATIVE_FLAVOR: // flavor table
            StringAppend(dst, gPokeblockWasTooXStringTable[src[srcID + 1]]);
            srcID += 2;
            break;
        case B_BUFF_ABILITY: // ability names
            StringAppend(dst, gAbilitiesInfo[T1_READ_16(&src[srcID + 1])].name);
            srcID += 3;
            break;
        case B_BUFF_ITEM: // item name
            hword = T1_READ_16(&src[srcID + 1]);
            if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            {
                if (hword == ITEM_ENIGMA_BERRY_E_READER)
                {
                    if (gLinkPlayers[gBattleScripting.multiplayerId].id == gPotentialItemEffectBattler)
                    {
                        StringCopy(dst, gEnigmaBerries[gPotentialItemEffectBattler].name);
                        StringAppend(dst, sText_BerrySuffix);
                    }
                    else
                    {
                        StringAppend(dst, sText_EnigmaBerry);
                    }
                }
                else
                {
                    CopyItemName(hword, dst);
                }
            }
            else
            {
                CopyItemName(hword, dst);
            }
            srcID += 3;
            break;
        }
    }
}

// Loads one of two text strings into the provided buffer. This is functionally
// unused, since the value loaded into the buffer is not read; it loaded one of
// two particles (either "?" or "?") which works in tandem with ChooseTypeOfMoveUsedString
// below to effect changes in the meaning of the line.
static void UNUSED ChooseMoveUsedParticle(u8 *textBuff)
{
    s32 counter = 0;
    u32 i = 0;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == 0)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    if (counter >= 0)
    {
        if (counter <= 2)
            StringCopy(textBuff, sText_SpaceIs); // is
        else if (counter <= MAX_MON_MOVES)
            StringCopy(textBuff, sText_ApostropheS); // 's
    }
}

// Appends "!" to the text buffer `dst`. In the original Japanese this looked
// into the table of moves at sGrammarMoveUsedTable and varied the line accordingly.
//
// sText_ExclamationMark was a plain "!", used for any attack not on the list.
// It resulted in the translation "<NAME>'s <ATTACK>!".
//
// sText_ExclamationMark2 was "? ????!". This resulted in the translation
// "<NAME> used <ATTACK>!", which was used for all attacks in English.
//
// sText_ExclamationMark3 was "??!". This was used for those moves whose
// names were verbs, such as Recover, and resulted in translations like "<NAME>
// recovered itself!".
//
// sText_ExclamationMark4 was "? ??!" This resulted in a translation of
// "<NAME> did an <ATTACK>!".
//
// sText_ExclamationMark5 was " ????!" This resulted in a translation of
// "<NAME>'s <ATTACK> attack!".
static void UNUSED ChooseTypeOfMoveUsedString(u8 *dst)
{
    s32 counter = 0;
    s32 i = 0;

    while (*dst != EOS)
        dst++;

    while (counter != MAX_MON_MOVES)
    {
        if (sGrammarMoveUsedTable[i] == MOVE_NONE)
            counter++;
        if (sGrammarMoveUsedTable[i++] == gBattleMsgDataPtr->currentMove)
            break;
    }

    switch (counter)
    {
    case 0:
        StringCopy(dst, sText_ExclamationMark);
        break;
    case 1:
        StringCopy(dst, sText_ExclamationMark2);
        break;
    case 2:
        StringCopy(dst, sText_ExclamationMark3);
        break;
    case 3:
        StringCopy(dst, sText_ExclamationMark4);
        break;
    case 4:
        StringCopy(dst, sText_ExclamationMark5);
        break;
    }
}

void BattlePutTextOnWindow(const u8 *text, u8 windowId)
{
    const struct BattleWindowText *textInfo = sBattleTextOnWindowsInfo[gBattleScripting.windowsType];
    bool32 copyToVram;
    struct TextPrinterTemplate printerTemplate;
    u8 speed;

    if (windowId & B_WIN_COPYTOVRAM)
    {
        windowId &= ~B_WIN_COPYTOVRAM;
        copyToVram = FALSE;
    }
    else
    {
        FillWindowPixelBuffer(windowId, textInfo[windowId].fillValue);
        copyToVram = TRUE;
    }

    printerTemplate.currentChar = text;
    printerTemplate.windowId = windowId;
    printerTemplate.fontId = textInfo[windowId].fontId;
    printerTemplate.x = textInfo[windowId].x;
    printerTemplate.y = textInfo[windowId].y;
    printerTemplate.currentX = printerTemplate.x;
    printerTemplate.currentY = printerTemplate.y;
    printerTemplate.letterSpacing = textInfo[windowId].letterSpacing;
    printerTemplate.lineSpacing = textInfo[windowId].lineSpacing;
    printerTemplate.unk = 0;
    printerTemplate.fgColor = textInfo[windowId].fgColor;
    printerTemplate.bgColor = textInfo[windowId].bgColor;
    printerTemplate.shadowColor = textInfo[windowId].shadowColor;

    if (B_WIN_MOVE_NAME_1 <= windowId && windowId <= B_WIN_MOVE_NAME_4)
    {
        // We cannot check the actual width of the window because
        // B_WIN_MOVE_NAME_1 and B_WIN_MOVE_NAME_3 are 16 wide for
        // Z-move details.
        if (gBattleStruct->zmove.viewing && windowId == B_WIN_MOVE_NAME_1)
            printerTemplate.fontId = GetFontIdToFit(text, printerTemplate.fontId, printerTemplate.letterSpacing, 16 * TILE_WIDTH);
        else
            printerTemplate.fontId = GetFontIdToFit(text, printerTemplate.fontId, printerTemplate.letterSpacing, 8 * TILE_WIDTH);
    }

    if (printerTemplate.x == 0xFF)
    {
        u32 width = GetBattleWindowTemplatePixelWidth(gBattleScripting.windowsType, windowId);
        s32 alignX = GetStringCenterAlignXOffsetWithLetterSpacing(printerTemplate.fontId, printerTemplate.currentChar, width, printerTemplate.letterSpacing);
        printerTemplate.x = printerTemplate.currentX = alignX;
    }

    if (windowId == ARENA_WIN_JUDGMENT_TEXT)
        gTextFlags.useAlternateDownArrow = FALSE;
    else
        gTextFlags.useAlternateDownArrow = TRUE;

    if ((gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED)) || gTestRunnerEnabled)
        gTextFlags.autoScroll = TRUE;
    else
        gTextFlags.autoScroll = FALSE;

    if (windowId == B_WIN_MSG || windowId == ARENA_WIN_JUDGMENT_TEXT)
    {
        if (gBattleTypeFlags & (BATTLE_TYPE_LINK | BATTLE_TYPE_RECORDED_LINK))
            speed = 1;
        else if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
            speed = sRecordedBattleTextSpeeds[GetTextSpeedInRecordedBattle()];
        else
            speed = GetPlayerTextSpeedDelay();

        gTextFlags.canABSpeedUpPrint = 1;
    }
    else
    {
        speed = textInfo[windowId].speed;
        gTextFlags.canABSpeedUpPrint = 0;
    }

    AddTextPrinter(&printerTemplate, speed, NULL);

    if (copyToVram)
    {
        PutWindowTilemap(windowId);
        CopyWindowToVram(windowId, COPYWIN_FULL);
    }
}

void SetPpNumbersPaletteInMoveSelection(u32 battler)
{
    struct ChooseMoveStruct *chooseMoveStruct = (struct ChooseMoveStruct *)(&gBattleResources->bufferA[battler][4]);
    const u16 *palPtr = gPPTextPalette;
    u8 var;

    if (!gBattleStruct->zmove.viewing)
        var = GetCurrentPpToMaxPpState(chooseMoveStruct->currentPp[gMoveSelectionCursor[battler]],
                         chooseMoveStruct->maxPp[gMoveSelectionCursor[battler]]);
    else
        var = 3;

    gPlttBufferUnfaded[BG_PLTT_ID(5) + 12] = palPtr[(var * 2) + 0];
    gPlttBufferUnfaded[BG_PLTT_ID(5) + 11] = palPtr[(var * 2) + 1];

    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 12], &gPlttBufferFaded[BG_PLTT_ID(5) + 12], PLTT_SIZEOF(1));
    CpuCopy16(&gPlttBufferUnfaded[BG_PLTT_ID(5) + 11], &gPlttBufferFaded[BG_PLTT_ID(5) + 11], PLTT_SIZEOF(1));
}

u8 GetCurrentPpToMaxPpState(u8 currentPp, u8 maxPp)
{
    if (maxPp == currentPp)
    {
        return 3;
    }
    else if (maxPp <= 2)
    {
        if (currentPp > 1)
            return 3;
        else
            return 2 - currentPp;
    }
    else if (maxPp <= 7)
    {
        if (currentPp > 2)
            return 3;
        else
            return 2 - currentPp;
    }
    else
    {
        if (currentPp == 0)
            return 2;
        if (currentPp <= maxPp / 4)
            return 1;
        if (currentPp > maxPp / 2)
            return 3;
    }

    return 0;
}
