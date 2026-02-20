LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

LilycoveCity_OnTransition:
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId_FromPlayerStyle
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_LILYCOVE_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	getplayerstyle
	call_if_eq VAR_RESULT, STYLE_BRENDAN, LilycoveCity_EventScript_May
	call_if_eq VAR_RESULT, STYLE_MAY, LilycoveCity_EventScript_Brendan
	call_if_eq VAR_RESULT, STYLE_RED, LilycoveCity_EventScript_May
	call_if_eq VAR_RESULT, STYLE_LEAF, LilycoveCity_EventScript_Brendan
    call_if_eq VAR_RESULT, STYLE_ETHAN, LilycoveCity_EventScript_May
    call_if_eq VAR_RESULT, STYLE_LYRA, LilycoveCity_EventScript_Brendan
    call_if_eq VAR_RESULT, STYLE_LUCAS, LilycoveCity_EventScript_May
    call_if_eq VAR_RESULT, STYLE_DAWN, LilycoveCity_EventScript_Brendan
    call_if_eq VAR_RESULT, STYLE_HILBERT, LilycoveCity_EventScript_May
    call_if_eq VAR_RESULT, STYLE_HILDA, LilycoveCity_EventScript_Brendan
@     call_if_eq VAR_RESULT, STYLE_NATE, LilycoveCity_EventScript_May
@     call_if_eq VAR_RESULT, STYLE_ROSA, LilycoveCity_EventScript_Brendan
@    call_if_eq VAR_RESULT, STYLE_CALEM, LilycoveCity_EventScript_May
@    call_if_eq VAR_RESULT, STYLE_SERENA, LilycoveCity_EventScript_Brendan
@    call_if_eq VAR_RESULT, STYLE_ELIO, LilycoveCity_EventScript_May
@    call_if_eq VAR_RESULT, STYLE_SELENE, LilycoveCity_EventScript_Brendan
@    call_if_eq VAR_RESULT, STYLE_VICTOR, LilycoveCity_EventScript_May
@    call_if_eq VAR_RESULT, STYLE_GLORIA, LilycoveCity_EventScript_Brendan
@    call_if_eq VAR_RESULT, STYLE_FLORIAN, LilycoveCity_EventScript_May
@    call_if_eq VAR_RESULT, STYLE_JULIANA, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle::
	.string "{COLOR RIVAL_CLR}{RIVAL}: Oh, hey……\n"
	.string "{PLAYER}{KUN}, bist du auch auf Shopping-Tour?\p"
	.string "Ich hab mir haufenweise PUPPEN und\n"
	.string "POSTER gegönnt.\p"
	.string "Natürlich hab ich auch massig POKéMON\n"
	.string "gefangen und ziehe sie richtig stramm.\p"
	.string "Ehrlich gesagt frag ich mich, ob du deine\n"
	.string "Viecher überhaupt im Griff hast.\p"
	.string "Lass mal kämpfen, damit ich sehen kann,\n"
	.string "ob du deine POKéMON nur ausführst oder\l"
	.string "wirklich trainierst!{COLOR DARK_GRAY}$"

LilycoveCity_Text_MayNotRaisingPokemon::
	.string "{COLOR RIVAL_CLR}{RIVAL}: Äh, warum nicht? {PLAYER}{KUN}, hast du\n"
	.string "etwa Schiss oder deine POKéMON vernach-\l"
	.string "lässigt?\p"
	.string "Das ist ja mal 'ne echt schwache Leistung\n"
	.string "als TRAINER……{COLOR DARK_GRAY}$"

LilycoveCity_Text_MayBattleMe::
	.string "{COLOR RIVAL_CLR}{RIVAL}: Jetzt komm schon, kämpf gegen\n"
	.string "mich! Ich will deine Gurkentruppe sehen!{COLOR DARK_GRAY}$"

LilycoveCity_Text_MayWontBeBeaten::
	.string "{COLOR RIVAL_CLR}{RIVAL}: Meine POKéMON lassen sich von\n"
	.string "deinem Haufen sicher nicht abziehen!{COLOR DARK_GRAY}$"

LilycoveCity_Text_MayDefeat::
	.string "…… …… …… ……\p"
	.string "Ich erinner mich noch an unseren Kampf\n"
	.string "auf ROUTE 103, {PLAYER}{KUN}.\p"
	.string "Anscheinend hat dir die Abreibung damals\n"
	.string "geholfen, so krass zu werden, was?$"

LilycoveCity_Text_MayGoingBackToLittleroot::
	.string "{COLOR RIVAL_CLR}{RIVAL}: Ich werd wohl bald wieder nach\n"
	.string "WURZELHEIM abhauen.\p"
	.string "Ich hab genug POKéMON im Sack und mein\n"
	.string "POKéDEX sieht top aus. Das muss ich\l"
	.string "meinem Dad unter die Nase reiben.{COLOR DARK_GRAY}$"

LilycoveCity_Text_MayYouGoingToCollectBadges::
	.string "{PLAYER}{KUN}, was hast du jetzt vor?\p"
	.string "Willst du echt alle ORDEN sammeln und die\n"
	.string "POKéMON LIGA stressen?\p"
	.string "Während du dich abmühst, mach ich meinen\n"
	.string "POKéDEX fertig. Ich bin eh schneller!\p"
	.string "Man sieht sich!$"

LilycoveCity_Text_BrendanShoppingLetsBattle::
	.string "{COLOR RIVAL_CLR}{RIVAL}: Oh, hey, {PLAYER}.\p"
	.string "Ich erledige gerade Kram für meinen Dad.\n"
	.string "Und nein, ich kauf hier keine PUPPEN!\p"
	.string "Egal, ist ja schon 'ne Weile her.\p"
	.string "Bock auf 'ne Abreibung? Mal sehen, wer\n"
	.string "seine Viecher besser im Griff hat.{COLOR DARK_GRAY}$"

LilycoveCity_Text_BrendanNoConfidence::
	.string "{COLOR RIVAL_CLR}{RIVAL}: Was ist los? Hast du keine Eier\n"
	.string "in der Hose für 'nen echten Kampf?{COLOR DARK_GRAY}$"

LilycoveCity_Text_BrendanDefeat::
	.string "Hmpf……\n"
	.string "Du hast deine Viecher echt gut getrimmt.\p"
	.string "Das wurmt mich jetzt schon ein bisschen,\n"
	.string "wo ich doch viel länger dabei bin……$"

LilycoveCity_Text_MovedLootIntoHideoutToday::
	.string "Fufufu……\p"
	.string "Heute haben wir noch mehr Diebesgut in\n"
	.string "unser Versteck geschleppt……\p"
	.string "W-wer bist du?! Verpiss dich!\n"
	.string "Ich hab nur Selbstgespräche geführt!$"

LilycoveCity_Text_DontGoNearCaveInCove::
	.string "He, du Blage!\p"
	.string "Bleib bloß weg von der Höhle in der Bucht!\p"
	.string "Warum? Weil ich es sage! Ich bin hier\n"
	.string "der Erwachsene, also zisch ab!$"

LilycoveCity_Text_GetLostMessingUpTraining::
	.string "Häh? Was willst du hier glotzen?\p"
	.string "Du störst unser Training, also zieh\n"
	.string "Leine, bevor es knallt!$"

LilycoveCity_Text_ContestHallSign::
	.string "WETTBEWERBS-HALLE\n"
	.string "“Wo Leute ihre POKéMON unnötig stylen!”$"

LilycoveCity_Text_HarborSignUnderConstruction::
	.string "HAFEN VON SEEGRASULB CITY\p"
	.string "“Die Fähre S.S. TIDAL wird in GRAPHITPORT\n"
	.string "zusammengezimmert. Nerv nicht!”$"

LilycoveCity_Text_MoveDeletersHouseSign::
	.string "HAUS DES ATTACKEN-VERLERNERS\p"
	.string "“Ich lösche den Müll in deinem Kopf.”$"

LilycoveCity_Text_CitySign::
	.string "SEEGRASULB CITY\p"
	.string "“Hier endet das Land und der ganze\n"
	.string "Mist wird ins Meer gespült.”$"

LilycoveCity_Text_ChanceToDoBigThings::
	.string "Ich bin nur ein RÜPEL, also hab ich keinen\n"
	.string "Plan, was der BOSS eigentlich will…\p"
	.string "Aber bei TEAM AQUA krieg ich wenigstens\n"
	.string "die Chance, mal so richtig Randale zu\l"
	.string "machen!\p"
	.string "W-wer bist du?! Hast du mich belauscht?!\n"
	.string "Zisch ab!$"

LilycoveCity_Text_IfWorldBecomesOurs::
	.string "Wenn diese ganze verdammte Welt uns\n"
	.string "gehört, wird's den POKéMON auch besser\l"
	.string "gehen. Sagen die Bosse jedenfalls.$"

LilycoveCity_Text_WailmerLeapOutOfWater::
	.string "Da! WAILMER!\n"
	.string "Spring gefälligst aus dem Wasser!$"

LilycoveCity_Text_ContestHallInTown::
	.string "Hier in der Stadt gibt's 'ne WETTBEWERBS-\n"
	.string "HALLE. \p"
	.string "Das heißt, haufenweise Leute kommen her,\n"
	.string "um ihre aufgebrezelten Viecher zu zeigen.\p"
	.string "Ich krieg jetzt schon das Kotzen vor\n"
	.string "lauter Aufregung!$"

LilycoveCity_Text_StrangeCaveInCove::
	.string "Hast du diese schräge Höhle in der Bucht\n"
	.string "am Stadtrand gesehen? Da geht was vor!$"

LilycoveCity_Text_GoingToMoveDeleterForHMs::
	.string "Ich will meinen POKéMON neue Moves für\n"
	.string "den WETTBEWERB beibringen.\p"
	.string "Deswegen geh ich zum ATTACKEN-VERLERNER,\n"
	.string "damit er diesen VM-Müll endlich löscht.$"

LilycoveCity_Text_ImFromKanto::
	.string "Ich komm extra aus KANTO.\p"
	.string "HOENN ist ja ganz nett mit dem ganzen\n"
	.string "Wasser und dem Gestrüpp überall.\p"
	.string "Häh? Warte mal 'ne Sekunde…\p"
	.string "Gibt's hier etwa Viecher, die man in\n"
	.string "KANTO nicht mal geschenkt kriegt?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer::
	.string "TEAM AQUA blockiert mit ihren WAILMER\n"
	.string "die ganze Bucht.\p"
	.string "Wir SEEMÄNNER kommen mit unseren Pötten\n"
	.string "gar nicht mehr raus auf's Meer! Dreckspack!$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut::
	.string "Ahoi, hast du's gehört?\p"
	.string "Irgendwer hat TEAM AQUA ordentlich in\n"
	.string "den Arsch getreten!\p"
	.string "Die WAILMER sind weg und wir können\n"
	.string "endlich wieder Segel setzen.$"

LilycoveCity_Text_SomeoneStoleMyPokemon::
	.string "Ich hab gerade friedlich im Hotel am Meer\n"
	.string "gepennt und dem Wellenrauschen zugehört…\p"
	.string "Da hat mir so'n Arsch mein POKéMON geklaut!\p"
	.string "Wer war das?! Team AQUA?\n"
	.string "Garantiert war das Team AQUA!$"

LilycoveCity_Text_MissingPokemonCameBack::
	.string "Mein geklautes POKéMON……\n"
	.string "Es kam einfach wieder zurück! Sachen gibt's.$"

LilycoveCity_Text_ImArtDealer::
	.string "Ich bin KUNSTHÄNDLER.\p"
	.string "Ich verkloppe überteuerte Schinken an\n"
	.string "Leute mit zu viel Kohle.\p"
	.string "Man sagt, das MUSEUM hier hätte ein paar\n"
	.string "brauchbare Werke rumstehen……$"

LilycoveCity_Text_SeaRemainsForeverYoung::
	.string "Während wir alt und schrumpelig werden,\n"
	.string "bleibt das Meer immer gleich blau……\p"
	.string "Fwohoho fwohohohoho……$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed::
	.string "Vor sechzig Jahren hat mein Alter mir\n"
	.string "hier 'nen Antrag gemacht.\l"
	.string "Das Meer ist immer noch schön. Er nicht.\p"
	.string "Mufufufu mufufufufufu……$"

LilycoveCity_Text_TeamAquaRenovatedCavern::
	.string "Hm, du weißt von der seltsamen Höhle?\p"
	.string "Früher war das Natur pur, aber dann kam\n"
	.string "das Pack von TEAM AQUA und hat alles\l"
	.string "umgebaut.\p"
	.string "Die nennen sich ernsthaft\n"
	.string "“naturverbundenes TEAM AQUA”!\p"
	.string "Aber was die labern und was sie tun,\n"
	.string "passt zusammen wie Feuer und Wasser!$"

LilycoveCity_Text_TeamAquaLotGoneForGood::
	.string "Diese Höhle in der Bucht……\p"
	.string "Ich hab's erst gar nicht geschnallt,\n"
	.string "aber jetzt ist sie komplett leer.\p"
	.string "Dieses AQUA-Gesindel ist anscheinend\n"
	.string "endlich für immer abgehauen.$"

LilycoveCity_Text_MotelSign::
	.string "COVE LILY MOTEL\p"
	.string "“Schlaf hier oder bleib weg. Uns egal.”$"

LilycoveCity_Text_MuseumSign::
	.string "SEEGRASULB MUSEUM\p"
	.string "“Krasse POKéMON-Bilder für Leute,\n"
	.string "die keine Hobbys haben!”$"

LilycoveCity_Text_MuseumSignPlayersExhibit::
	.string "SEEGRASULB MUSEUM\p"
	.string "“{PLAYER}s private Sammlung.\n"
	.string "Glotzen verboten!”$"

LilycoveCity_Text_HarborSign::
	.string "HAFEN VON SEEGRASULB CITY\p"
	.string "“Verschwende dein Geld auf der\n"
	.string "Fähre S.S. TIDAL.”$"

LilycoveCity_Text_TrainerFanClubSign::
	.string "POKéMON TRAINER FAN CLUB\p"
	.string "Das Schild ist vollgekritzelt mit Namen\n"
	.string "von Leuten, die sich wichtig fühlen……$"

LilycoveCity_Text_DepartmentStoreSign::
	.string "EINKAUFSZENTRUM VON SEEGRASULB\p"
	.string "“Wir haben alles, was du nicht brauchst,\n"
	.string "zu Preisen, die dich arm machen!”$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender::
	.string "Kennst du dieses Beeren-Mix-Teil?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks::
	.string "Man muss mit anderen zusammenarbeiten,\n"
	.string "damit das Ding schneller dreht.\p"
	.string "Je schneller es eiert, desto bessere\n"
	.string "{POKEBLOCK}S kriegst du raus. Angeblich.$"

LilycoveCity_Text_ExplainBerryBlender::
	.string "Damit macht man dieses Zeug namens\n"
	.string "{POKEBLOCK}.\p"
	.string "Wenn du den Mist an deine POKéMON ver-\n"
	.string "fütterst, sehen sie vielleicht besser aus.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar::
	.string "Ich hab gehört, irgendwo auf dem Meer\n"
	.string "soll ein Turm rumstehen.\p"
	.string "HIMMELSTURM oder so heißt der Kasten.$"

LilycoveCity_Text_SawTallTowerOnRoute131::
	.string "Ich hab so 'nen fetten Turm auf der\n"
	.string "ROUTE 131 gesehen.\p"
	.string "Könnte das etwa…… neee, oder?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon::
	.string "Wir sind gerade auf Hochzeitsreise hier.\p"
	.string "Haben direkt 'n DRACHEN-POKéMON am Himmel\n"
	.string "gesehen. Voll abgefahren!\p"
	.string "Gibt's hier in HOENN nur so krasses Vieh?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon::
	.string "In unseren Flitterwochen wollten wir so\n"
	.string "viele seltene Viecher sehen wie möglich.\p"
	.string "Und zack, kaum da, schon das erste im Sack.\n"
	.string "Wir sind so verdammt glücklich, ey!$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "{COLOR RIVAL_CLR}{RIVAL}{COLOR DARK_GRAY}: Ich lass mich von dir doch nicht\n"
	.string "ewig abziehen! Pass mal auf!$"

LilycoveCity_Text_BrendanBattleMe:
	.string "{COLOR RIVAL_CLR}{RIVAL}{COLOR DARK_GRAY}: Na, bereit für 'ne Abreibung?$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{COLOR RIVAL_CLR}{RIVAL}{COLOR DARK_GRAY}: Willst du echt zur LIGA?\n"
	.string "Viel Erfolg, du wirst es brauchen...$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{COLOR RIVAL_CLR}{RIVAL}{COLOR DARK_GRAY}: Gehst du zur KAMPFZONE?\n"
	.string "Da fressen sie dich lebendig!$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "{COLOR RIVAL_CLR}{RIVAL}{COLOR DARK_GRAY}: Ich verpiss mich zurück nach\n"
	.string "WURZELHEIM. Muss mehr trainieren...$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{COLOR RIVAL_CLR}{RIVAL}{COLOR DARK_GRAY}: Sammelst du immer noch Orden?\n"
	.string "Bisschen langsam, was?$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{COLOR RIVAL_CLR}{RIVAL}{COLOR DARK_GRAY}: Du willst zur POKéMON LIGA?\n"
	.string "Träum weiter, Kleiner!$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{COLOR RIVAL_CLR}{RIVAL}{COLOR DARK_GRAY}: KAMPFZONE? Da wirst du doch\n"
	.string "eh nur direkt rausgeworfen.$"
