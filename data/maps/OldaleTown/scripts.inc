OldaleTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
	.byte 0

OldaleTown_OnTransition:
    setflag FLAG_VISITED_OLDALE_TOWN
    call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_BlockWestEntrance
    call_if_unset FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_MoveMartEmployee
    call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_SetOldaleState
    end

@ This script seems pointless because nothing uses VAR_OLDALE_TOWN_STATE
OldaleTown_EventScript_SetOldaleState::
	setvar VAR_OLDALE_TOWN_STATE, 1
	return

OldaleTown_EventScript_BlockWestEntrance::
	setobjectxyperm LOCALID_FOOTPRINTS_MAN, 1, 11
	setobjectmovementtype LOCALID_FOOTPRINTS_MAN, MOVEMENT_TYPE_FACE_LEFT
	return

OldaleTown_EventScript_MoveMartEmployee::
	setobjectxyperm LOCALID_OLDALE_MART_EMPLOYEE, 13, 14
	setobjectmovementtype LOCALID_OLDALE_MART_EMPLOYEE, MOVEMENT_TYPE_FACE_DOWN
	return

OldaleTown_EventScript_TownSign::
	msgbox OldaleTown_Text_TownSign, MSGBOX_SIGN
	end

OldaleTown_EventScript_Girl::
	msgbox OldaleTown_Text_SavingMyProgress, MSGBOX_NPC
	end

OldaleTown_EventScript_MartEmployee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_ExplainPotion
	goto_if_set FLAG_TEMP_1, OldaleTown_EventScript_ExplainPotion
	setflag FLAG_TEMP_1
	playbgm MUS_FOLLOW_ME, FALSE
	msgbox OldaleTown_Text_IWorkAtPokemonMart, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, OldaleTown_EventScript_GoToMartSouth
	case DIR_NORTH, OldaleTown_EventScript_GoToMartNorth
	case DIR_EAST, OldaleTown_EventScript_GoToMartEast
	end

OldaleTown_EventScript_GoToMartSouth::
	applymovement LOCALID_OLDALE_MART_EMPLOYEE, OldaleTown_Movement_EmployeeSouth
	applymovement LOCALID_PLAYER, OldaleTown_Movement_PlayerSouth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartNorth::
	applymovement LOCALID_OLDALE_MART_EMPLOYEE, OldaleTown_Movement_EmployeeNorth
	applymovement LOCALID_PLAYER, OldaleTown_Movement_PlayerNorth
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_GoToMartEast::
	applymovement LOCALID_PLAYER, OldaleTown_Movement_PlayerEast
	applymovement LOCALID_OLDALE_MART_EMPLOYEE, OldaleTown_Movement_EmployeeEast
	waitmovement 0
	goto OldaleTown_EventScript_ExplainPokemonMart
	end

OldaleTown_EventScript_ExplainPokemonMart::
	msgbox OldaleTown_Text_ThisIsAPokemonMart, MSGBOX_DEFAULT
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, OldaleTown_EventScript_BagIsFull
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_POTION_OLDALE
	fadedefaultbgm
	release
	end

OldaleTown_EventScript_ExplainPotion::
	msgbox OldaleTown_Text_PotionExplanation, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	fadedefaultbgm
	release
	end

OldaleTown_Movement_EmployeeEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_EmployeeSouth:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_EmployeeNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_Unknown1:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	delay_8
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_PlayerEast:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerSouth:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_PlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_Unknown2:
	walk_left
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_EventScript_FootprintsMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_NotBlockingPath
	msgbox OldaleTown_Text_DiscoveredFootprints, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOOTPRINTS_MAN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

OldaleTown_EventScript_BlockedPath::
	lockall
	applymovement LOCALID_PLAYER, OldaleTown_Movement_PlayerStepBack
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_BackUp
	waitmovement 0
	msgbox OldaleTown_Text_WaitDontComeInHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_FOOTPRINTS_MAN, OldaleTown_Movement_ReturnToOriginalPosition
	waitmovement 0
	releaseall
	end

OldaleTown_EventScript_NotBlockingPath::
	msgbox OldaleTown_Text_FinishedSketchingFootprints, MSGBOX_DEFAULT
	release
	end

OldaleTown_EventScript_Rival::
	lockall
	setvar VAR_0x8004, LOCALID_OLDALE_RIVAL
	spawnrival_style
	applymovement LOCALID_OLDALE_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_0x8009, 0
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger1::
	lockall
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalApproachPlayer1
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger2::
	lockall
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalApproachPlayer2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_RivalTrigger3::
	lockall
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalApproachPlayer3
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_ShowRivalMessage
	end

OldaleTown_EventScript_ShowRivalMessage::
	getplayerstyle
	goto_if_eq VAR_RESULT, STYLE_BRENDAN, OldaleTown_EventScript_ShowMayMessage
	goto_if_eq VAR_RESULT, STYLE_MAY, OldaleTown_EventScript_ShowBrendanMessage
	goto_if_eq VAR_RESULT, STYLE_RED, OldaleTown_EventScript_ShowMayMessage
	goto_if_eq VAR_RESULT, STYLE_LEAF, OldaleTown_EventScript_ShowBrendanMessage
	goto_if_eq VAR_RESULT, STYLE_ETHAN, OldaleTown_EventScript_ShowMayMessage
	goto_if_eq VAR_RESULT, STYLE_LYRA, OldaleTown_EventScript_ShowBrendanMessage
	goto_if_eq VAR_RESULT, STYLE_LUCAS, OldaleTown_EventScript_ShowMayMessage
	goto_if_eq VAR_RESULT, STYLE_DAWN, OldaleTown_EventScript_ShowBrendanMessage
	goto_if_eq VAR_RESULT, STYLE_HILBERT, OldaleTown_EventScript_ShowMayMessage
	goto_if_eq VAR_RESULT, STYLE_HILDA, OldaleTown_EventScript_ShowBrendanMessage
@ 	goto_if_eq VAR_RESULT, STYLE_NATE, OldaleTown_EventScript_ShowMayMessage
@ 	goto_if_eq VAR_RESULT, STYLE_ROSA, OldaleTown_EventScript_ShowBrendanMessage
@	goto_if_eq VAR_RESULT, STYLE_CALEM, OldaleTown_EventScript_ShowMayMessage
@	goto_if_eq VAR_RESULT, STYLE_SERENA, OldaleTown_EventScript_ShowBrendanMessage
@	goto_if_eq VAR_RESULT, STYLE_ELIO, OldaleTown_EventScript_ShowMayMessage
@	goto_if_eq VAR_RESULT, STYLE_SELENE, OldaleTown_EventScript_ShowBrendanMessage
@	goto_if_eq VAR_RESULT, STYLE_VICTOR, OldaleTown_EventScript_ShowMayMessage
@	goto_if_eq VAR_RESULT, STYLE_GLORIA, OldaleTown_EventScript_ShowBrendanMessage
@	goto_if_eq VAR_RESULT, STYLE_FLORIAN, OldaleTown_EventScript_ShowMayMessage
@	goto_if_eq VAR_RESULT, STYLE_JULIANA, OldaleTown_EventScript_ShowBrendanMessage
	end

OldaleTown_EventScript_ShowMayMessage::
	msgbox OldaleTown_Text_MayLetsGoBack, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_RivalFinish
	end

OldaleTown_EventScript_ShowBrendanMessage::
	msgbox OldaleTown_Text_BrendanLetsGoBack, MSGBOX_DEFAULT
	goto OldaleTown_EventScript_RivalFinish
	end

OldaleTown_EventScript_RivalFinish::
	closemessage
	call_if_eq VAR_0x8009, 0, OldaleTown_EventScript_DoExitMovement1
	call_if_eq VAR_0x8009, 1, OldaleTown_EventScript_DoExitMovement2
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	removeobject LOCALID_OLDALE_RIVAL
	setvar VAR_OLDALE_RIVAL_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	releaseall
	end

OldaleTown_EventScript_DoExitMovement1::
	goto_if_ne VAR_FACING, DIR_SOUTH, OldaleTown_EventScript_DoExitMovement2
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	return

OldaleTown_EventScript_DoExitMovement2::
	applymovement LOCALID_PLAYER, OldaleTown_Movement_WatchRivalExit
	applymovement LOCALID_OLDALE_RIVAL, OldaleTown_Movement_RivalExit
	waitmovement 0
	return

OldaleTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	step_end

OldaleTown_Movement_RivalApproachPlayer2:
	walk_left
	step_end

OldaleTown_Movement_RivalApproachPlayer3:
	face_left
	step_end

OldaleTown_Movement_RivalExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OldaleTown_Movement_WatchRivalExit:
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

OldaleTown_Movement_PlayerStepBack:
	delay_8
	walk_right
	step_end

OldaleTown_Movement_BackUp:
	walk_fast_up
	walk_in_place_faster_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

OldaleTown_Movement_ReturnToOriginalPosition:
	walk_down
	walk_left
	step_end

OldaleTown_Text_SavingMyProgress:
	.string "Diese Höhle dort am Rand der Stadt…\n"
	.string "die war früher nicht da.\p"
	.string "Manche sagen, sie sei über Nacht\n"
	.string "aufgetaucht. Einfach so.\p"
	.string "Ein paar Einheimische behaupten, nachts\n"
	.string "seltsame Geräusche daraus gehört\l"
    .string "zu haben.\p"
	.string "Ich würde da nicht reingehen…\n"
	.string "Jedenfalls nicht allein.$"

OldaleTown_Text_IWorkAtPokemonMart:
	.string "Hey, du bist neu hier, oder?\n"
	.string "Ich arbeite im Pokémon-SUPERMARKT.\p"
	.string "Komm kurz mit - dauert nicht lang.$"

OldaleTown_Text_ThisIsAPokemonMart:
	.string "Hier ist der PKMN-SUPERMARKT -\n"
	.string "erkennbar am blauen Dach.\p"
	.string "Wir verkaufen nützliche Items -\n"
	.string "wie POKéBÄLLE zum Fangen von Pokémon.\p"
	.string "Hier, nimm das. Eine kleine\n"
	.string "Aufmerksamkeit für neue Trainer.$"

OldaleTown_Text_PotionExplanation:
	.string "Ein TRANK heilt dein Pokémon unterwegs -\n"
	.string "ganz ohne CENTER.\p"
	.string "Manchmal macht genau das den Unter-\n"
	.string "schied zwischen Sieg und Niederlage.$"

OldaleTown_Text_WaitDontComeInHere:
	.string "Warte! Geh da nicht hin!\n"
	.string "Du könntest wichtige Spuren zerstören!\p"
	.string "Ich habe hier Fußabdrücke entdeckt…\n"
	.string "aber sie stammen von keinem bekannten\l"
    .string "Pokémon.\p"
	.string "Die Form ist… seltsam. Irgendwie\n"
    .string "fremdartig.\p"
	.string "Ich muss sie genau dokumentieren.\n"
	.string "Bitte warte noch etwas!$"

OldaleTown_Text_DiscoveredFootprints:
	.string "Ich habe sie abgezeichnet…\n"
	.string "Und sie ähneln wirklich nichts Bekanntem.\p"
	.string "Es sieht aus, als wäre hier ein Wesen\n"
	.string "unterwegs gewesen, das sich tarnen kann…\p"
	.string "Aber das ergibt keinen Sinn.\n"
	.string "Oder etwa doch?$"

OldaleTown_Text_FinishedSketchingFootprints:
	.string "Ich hab die Fußspuren endlich skizziert…\n"
	.string "Aber sie geben mir Rätsel auf.\p"
	.string "Zuerst dachte ich, sie wären von einem\n"
	.string "seltenen Pokémon.\p"
	.string "Aber jetzt bin ich mir nicht mehr sicher.\n"
	.string "Vielleicht waren es… gar keine Spuren.$"

OldaleTown_Text_MayLetsGoBack:
	.string "{COLOR RIVAL_CLR}{RIVAL}: {PLAYER}{KUN}!\n"
	.string "Komm schon! Lass uns zurück ins LABOR!{COLOR DARK_GRAY}$"

OldaleTown_Text_BrendanLetsGoBack:
	.string "{COLOR RIVAL_CLR}{RIVAL}: Ich geh schon mal vor ins LABOR\n"
	.string "von meinem Dad. Komm ruhig nach.{COLOR DARK_GRAY}$"
OldaleTown_Text_TownSign:
	.string "ROSALTSTADT\n"
	.string "“Die Höhle flüstert - hörst du es auch?”$"

