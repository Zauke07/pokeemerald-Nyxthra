SootopolisCity_MysteryEventsHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_MysteryEventsHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MysteryEventsHouse_1F_OnFrame
	.byte 0

SootopolisCity_MysteryEventsHouse_1F_OnTransition:
	frontier_checkvisittrainer
	call_if_eq VAR_RESULT, 0, SootopolisCity_MysteryEventsHouse_1F_EventScript_SetTrainerVisitingLayout
	call_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_MysteryEventsHouse_1F_EventScript_OpenStairsForChamp
	call_if_ne VAR_SOOTOPOLIS_MYSTERY_EVENTS_STATE, 0, SootopolisCity_MysteryEventsHouse_1F_EventScript_MoveOldManToDoor
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_SetTrainerVisitingLayout::
	setvar VAR_TEMP_1, 1
	setobjectxyperm LOCALID_MYSTERY_EVENTS_OLD_MAN, 3, 2
	setobjectmovementtype LOCALID_MYSTERY_EVENTS_OLD_MAN, MOVEMENT_TYPE_FACE_DOWN
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_STAIRS_UNBLOCKED
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_OpenStairsForChamp::
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_1F_STAIRS_UNBLOCKED
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_MoveOldManToDoor::
	setobjectxyperm LOCALID_MYSTERY_EVENTS_OLD_MAN, 2, 2
	setobjectmovementtype LOCALID_MYSTERY_EVENTS_OLD_MAN, MOVEMENT_TYPE_FACE_RIGHT
	return

SootopolisCity_MysteryEventsHouse_1F_OnFrame:
	.2byte 0



SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerExitStairs:
	walk_down
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_OldManWalkBehindPlayer:
	walk_right
	walk_in_place_faster_down
	step_end

SootopolisCity_MysteryEventsHouse_1F_EventScript_OldMan::
	lock
	faceplayer
	goto_if_eq VAR_PROTAGONIST_CHALLENGE_PROGRESS, 18, SootopolisCity_MysteryEventsHouse_1F_EventScript_ChallengeReward
	frontier_checkvisittrainer
	goto_if_eq VAR_RESULT, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_InvalidVisitingTrainer
	goto_if_eq VAR_TEMP_1, 1, SootopolisCity_MysteryEventsHouse_1F_EventScript_TrainerVisiting
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_InvalidVisitingTrainer::
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_TrainerVisiting::
	special SavePlayerParty
	special BufferEReaderTrainerName
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_ChallengeVisitingTrainer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
	call SootopolisCity_MysteryEventsHouse_1F_EventScript_ChooseParty
	goto_if_eq VAR_RESULT, 0, SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_SaveProgressBeforeBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
	special LoadPlayerParty
	call Common_EventScript_SaveGame
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle
	special SavePlayerParty
	special ReducePlayerPartyToSelectedMons
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_HopeToSeeGoodMatch, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementNorth
	call_if_eq VAR_FACING, DIR_EAST, SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementEast
	call_if_eq VAR_FACING, DIR_WEST, SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementWest
	warp MAP_SOOTOPOLIS_CITY_MYSTERY_EVENTS_HOUSE_B1F, 3, 1
	waitstate
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_DeclineBattle::
	special LoadPlayerParty
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_YouWontBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_ChooseParty::
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_KeepItTo3On3, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseHalfPartyForBattle
	waitstate
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementNorth::
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft
	applymovement LOCALID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementNorth
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementEast::
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideRight
	applymovement LOCALID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementEast
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_EventScript_EnterBasementWest::
	applymovement VAR_LAST_TALKED, SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft
	applymovement LOCALID_PLAYER, SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementWest
	waitmovement 0
	return

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementNorth:
	delay_16
	walk_up
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementEast:
	delay_16
	walk_right
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_PlayerEnterBasementWest:
	delay_16
	walk_left
	walk_up
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideLeft:
	walk_left
	walk_in_place_faster_right
	step_end

SootopolisCity_MysteryEventsHouse_1F_Movement_OldManMoveAsideRight:
	walk_right
	walk_in_place_faster_left
	step_end

SootopolisCity_MysteryEventsHouse_1F_Text_OnlyAmusementWatchingBattles:
	.string "Als ich jung war, hab ich\n"
	.string "die Map komplett leergeräumt.\p"
	.string "Jetzt bin ich alt und ergötze\n"
	.string "mich nur noch an Noob-Fights.$"

SootopolisCity_MysteryEventsHouse_1F_Text_DoorAppearsToBeLocked:
	.string "Die Tür ist verrammelt.$"

SootopolisCity_MysteryEventsHouse_1F_Text_ChallengeVisitingTrainer:
	.string "Ein Tryharder namens\n"
	.string "{STR_VAR_1} ist zu Besuch.\p"
	.string "Willst du {STR_VAR_1}\n"
	.string "wegklatschen?$"

SootopolisCity_MysteryEventsHouse_1F_Text_YouWontBattle:
	.string "Du kneifst? Ich bin echt\n"
	.string "enttäuscht von dir…$"

SootopolisCity_MysteryEventsHouse_1F_Text_KeepItTo3On3:
	.string "Oh, sehr geil!\p"
	.string "Aber meine Bude ist alt.\p"
	.string "Mach bitte nur ein 3-gegen-3,\n"
	.string "sonst stürzt hier alles ein.$"

SootopolisCity_MysteryEventsHouse_1F_Text_SaveProgressBeforeBattle:
	.string "Speicher dein Game ab, bevor\n"
	.string "ihr euch auf die Fresse gebt.$"

SootopolisCity_MysteryEventsHouse_1F_Text_HopeToSeeGoodMatch:
	.string "Ich will krasse Plays sehen!$"

SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Tie:
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_B1F_Text_MatchEndedUpDraw:
	.string "Das war wohl ein Unentschieden.$"

SootopolisCity_MysteryEventsHouse_1F_Text_BrilliantStandoff:
	.string "Ein fettes Patt.\p"
	.string "Ihr habt beide so krass\n"
	.string "reingeschwitzt, GG!$"

SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Won:
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_1F_Text_ThatWasSuperlative:
	.string "Absolut OP!\p"
	.string "Ich dachte kurz, ich seh mir\n"
	.string "selbst beim Zocken zu!$"

SootopolisCity_MysteryEventsHouse_1F_Text_StrVar1Lost:
	.string "{STR_VAR_1}$"

SootopolisCity_MysteryEventsHouse_1F_Text_TooBadForYou:
	.string "Tja, du wurdest rasiert!\p"
	.string "Trotzdem GG.\n"
	.string "Vielleicht nächstes Mal.$"

SootopolisCity_MysteryEventsHouse_1F_EventScript_ChallengeReward::
	goto_if_set FLAG_CHALLENGE_HOUSE_REWARD_GIVEN, SootopolisCity_MysteryEventsHouse_1F_EventScript_AlreadyRewarded
	setflag FLAG_CHALLENGE_HOUSE_REWARD_GIVEN
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_ChallengeReward, MSGBOX_DEFAULT
	additem ITEM_SACRED_ASH, 1
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_ReceivedSacredAsh, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_EventScript_AlreadyRewarded::
	msgbox SootopolisCity_MysteryEventsHouse_1F_Text_ChampionGreeting, MSGBOX_DEFAULT
	release
	end

SootopolisCity_MysteryEventsHouse_1F_Text_ChallengeReward:
	.string "Was?! Du hast alle 18\n"
	.string "Protagonisten besiegt?!\p"
	.string "Das ist die krasseste Leistung,\n"
	.string "die ich in meinem Leben gesehen habe!\p"
	.string "Nimm das hier -\n"
	.string "du hast es dir verdient!$"

SootopolisCity_MysteryEventsHouse_1F_Text_ReceivedSacredAsh:
	.string "{PLAYER} erhielt\n"
	.string "die Belohnung!$"

SootopolisCity_MysteryEventsHouse_1F_Text_ChampionGreeting:
	.string "Der stärkste Trainer aller\n"
	.string "Regionen. Absolute Legende!$"

