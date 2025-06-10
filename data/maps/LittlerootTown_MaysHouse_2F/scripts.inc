LittlerootTown_MaysHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MaysHouse_2F_OnWarp
	.byte 0

LittlerootTown_MaysHouse_2F_OnTransition:
    call_if_lt VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay
    call_if_ge VAR_LITTLEROOT_RIVAL_STATE, 3, LittlerootTown_MaysHouse_2F_EventScript_SetRivalPos
    call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, PlayersHouse_2F_EventScript_BlockStairsUntilClockIsSet
    call SecretBase_EventScript_SetDecorationFlags
    setvar VAR_SECRET_BASE_INITIALIZED, 0
    end

LittlerootTown_MaysHouse_2F_EventScript_SetRivalPos::
	checkflag FLAG_FIX_RIVAL_DOOR_RAN_MAY
	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_MaysHouse_2F_EventScript_Ret
	setobjectxyperm LOCALID_RIVAL, 8, 2
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
    setflag FLAG_FIX_RIVAL_DOOR_RAN_MAY
	return

LittlerootTown_MaysHouse_2F_EventScript_Ret::
	return

LittlerootTown_MaysHouse_2F_EventScript_SetFixedRivalPos::
	setobjectxyperm LOCALID_RIVAL, 9, 2
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_MaysHouse_2F_EventScript_CheckSetReadyToMeetMay::
	getplayerstyle
	goto_if_eq VAR_RESULT, STYLE_BRENDAN, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	goto_if_eq VAR_RESULT, STYLE_RED, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	@goto_if_eq VAR_RESULT, STYLE_ETHAN, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	@goto_if_eq VAR_RESULT, STYLE_LUCAS, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	@goto_if_eq VAR_RESULT, STYLE_HILBERT, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	@goto_if_eq VAR_RESULT, STYLE_NATE, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	@goto_if_eq VAR_RESULT, STYLE_CALEM, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	@goto_if_eq VAR_RESULT, STYLE_ELIO, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	@goto_if_eq VAR_RESULT, STYLE_VICTOR, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	@goto_if_eq VAR_RESULT, STYLE_FLORIAN, LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay
	return

LittlerootTown_MaysHouse_2F_EventScript_SetReadyToMeetMay::
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
	return

LittlerootTown_MaysHouse_2F_OnWarp:
	map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor
	.2byte 0

LittlerootTown_MaysHouse_2F_EventScript_CheckInitDecor::
	getplayerstyle
	goto_if_eq VAR_RESULT, STYLE_MAY, SecretBase_EventScript_InitDecorations
	goto_if_eq VAR_RESULT, STYLE_LEAF, SecretBase_EventScript_InitDecorations
	@goto_if_eq VAR_RESULT, STYLE_LYRA, SecretBase_EventScript_InitDecorations
	@goto_if_eq VAR_RESULT, STYLE_DAWN, SecretBase_EventScript_InitDecorations
	@goto_if_eq VAR_RESULT, STYLE_HILDA, SecretBase_EventScript_InitDecorations
	@goto_if_eq VAR_RESULT, STYLE_ROSA, SecretBase_EventScript_InitDecorations
	@goto_if_eq VAR_RESULT, STYLE_SERENA, SecretBase_EventScript_InitDecorations
	@goto_if_eq VAR_RESULT, STYLE_SELENE, SecretBase_EventScript_InitDecorations
	@goto_if_eq VAR_RESULT, STYLE_GLORIA, SecretBase_EventScript_InitDecorations
	@goto_if_eq VAR_RESULT, STYLE_JULIANA, SecretBase_EventScript_InitDecorations
	end

LittlerootTown_MaysHouse_2F_EventScript_RivalsPokeBall::
	lockall
	goto_if_eq VAR_LITTLEROOT_RIVAL_STATE, 2, LittlerootTown_MaysHouse_2F_EventScript_MeetMay
	msgbox RivalsHouse_2F_Text_ItsRivalsPokeBall, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_MeetMay:
    setvar VAR_0x8004, LOCALID_RIVAL
    spawnrival_style
    delay 10

    applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayEnters
    waitmovement 0

    playse SE_PIN
    applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
    waitmovement 0

    applymovement LOCALID_RIVAL, Common_Movement_Delay48
    waitmovement 0
    delay 10

    playbgm MUS_ENCOUNTER_MAY, TRUE

    call_if_eq VAR_0x8008, 0, LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth
    call_if_eq VAR_0x8008, 1, LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth
    call_if_eq VAR_0x8008, 2, LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest
    call_if_eq VAR_0x8008, 3, LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast

    setvar VAR_LITTLEROOT_RIVAL_STATE, 3
    setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
    clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
    setvar VAR_LITTLEROOT_TOWN_STATE, 1

    savebgm MUS_DUMMY
    fadedefaultbgm
    releaseall
    end

LittlerootTown_MaysHouse_2F_EventScript_PlayerFaceMay::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PlayerFaceDown
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMayNorth::
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMaySouth::
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMayWest::
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest
	waitmovement 0
	return

LittlerootTown_MaysHouse_2F_EventScript_MeetMayEast::
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox RivalsHouse_2F_Text_MayWhoAreYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast
	applymovement LOCALID_RIVALS_HOUSE_2F_RIVAL, LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast
	waitmovement 0
	return

Movement_StepDown_LookUp:
	walk_down
	walk_in_place_faster_up
	step_end

Movement_StepDown:
	walk_down
	step_end

Movement_FixWalkToPC:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

Movement_LookUp:
	walk_in_place_faster_up
	step_end

Movement_PlayerFaceDown:
	walk_in_place_faster_down
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayEnters:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerNorth:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCNorth:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayNorth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerSouth:
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCSouth:
	walk_up
	walk_in_place_faster_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMaySouth:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerWest:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_down
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCWest:
	walk_up
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

@ Unused, the player is already facing this direction so its unneeded
LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayWest:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayApproachPlayerEast:
	walk_right
	walk_right
	walk_down
	walk_in_place_faster_right
	step_end

LittlerootTown_MaysHouse_2F_Movement_MayWalkToPCEast:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_PlayerWatchMayEast:
	delay_16
	walk_in_place_faster_up
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

RivalsHouse_2F_EventScript_Rival::
	lockall
	getplayerstyle
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, RivalsHouse_2F_EventScript_RivalPostLilycove
	goto_if_eq VAR_RESULT, STYLE_MAY, RivalsHouse_2F_EventScript_RivalFemale
	goto_if_eq VAR_RESULT, STYLE_LEAF, RivalsHouse_2F_EventScript_RivalFemale
	@goto_if_eq VAR_RESULT, STYLE_LYRA, RivalsHouse_2F_EventScript_RivalFemale
	@goto_if_eq VAR_RESULT, STYLE_DAWN, RivalsHouse_2F_EventScript_RivalFemale
	@goto_if_eq VAR_RESULT, STYLE_HILDA, RivalsHouse_2F_EventScript_RivalFemale
	@goto_if_eq VAR_RESULT, STYLE_ROSA, RivalsHouse_2F_EventScript_RivalFemale
	@goto_if_eq VAR_RESULT, STYLE_SERENA, RivalsHouse_2F_EventScript_RivalFemale
	@goto_if_eq VAR_RESULT, STYLE_SELENE, RivalsHouse_2F_EventScript_RivalFemale
	@goto_if_eq VAR_RESULT, STYLE_GLORIA, RivalsHouse_2F_EventScript_RivalFemale
	@goto_if_eq VAR_RESULT, STYLE_JULIANA, RivalsHouse_2F_EventScript_RivalFemale
	goto_if_eq VAR_RESULT, STYLE_BRENDAN, RivalsHouse_2F_EventScript_RivalMale
	goto_if_eq VAR_RESULT, STYLE_RED, RivalsHouse_2F_EventScript_RivalMale
	@goto_if_eq VAR_RESULT, STYLE_ETHAN, RivalsHouse_2F_EventScript_RivalMale
	@goto_if_eq VAR_RESULT, STYLE_LUCAS, RivalsHouse_2F_EventScript_RivalMale
	@goto_if_eq VAR_RESULT, STYLE_HILBERT, RivalsHouse_2F_EventScript_RivalMale
	@goto_if_eq VAR_RESULT, STYLE_NATE, RivalsHouse_2F_EventScript_RivalMale
	@goto_if_eq VAR_RESULT, STYLE_CALEM, RivalsHouse_2F_EventScript_RivalMale
	@goto_if_eq VAR_RESULT, STYLE_ELIO, RivalsHouse_2F_EventScript_RivalMale
	@goto_if_eq VAR_RESULT, STYLE_VICTOR, RivalsHouse_2F_EventScript_RivalMale
	@goto_if_eq VAR_RESULT, STYLE_FLORIAN, RivalsHouse_2F_EventScript_RivalMale
	end

RivalsHouse_2F_EventScript_RivalFemale::
	msgbox RivalsHouse_2F_Text_MayGettingReady, MSGBOX_DEFAULT
	releaseall
	end

RivalsHouse_2F_EventScript_Brendan::
	msgbox RivalsHouse_2F_Text_BrendanGettingReady, MSGBOX_DEFAULT
	releaseall
	end

RivalsHouse_2F_EventScript_RivalPostLilycove::
	getplayerstyle
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	call_if_eq VAR_RESULT, STYLE_MAY, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	call_if_eq VAR_RESULT, STYLE_LEAF, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	@call_if_eq VAR_RESULT, STYLE_LYRA, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	@call_if_eq VAR_RESULT, STYLE_DAWN, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	@call_if_eq VAR_RESULT, STYLE_HILDA, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	@call_if_eq VAR_RESULT, STYLE_ROSA, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	@call_if_eq VAR_RESULT, STYLE_SERENA, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	@call_if_eq VAR_RESULT, STYLE_SELENE, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	@call_if_eq VAR_RESULT, STYLE_GLORIA, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	@call_if_eq VAR_RESULT, STYLE_JULIANA, RivalsHouse_2F_EventScript_RivalFemalePostLilycove
	call_if_eq VAR_RESULT, STYLE_BRENDAN, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	call_if_eq VAR_RESULT, STYLE_RED, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	@call_if_eq VAR_RESULT, STYLE_ETHAN, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	@call_if_eq VAR_RESULT, STYLE_LUCAS, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	@call_if_eq VAR_RESULT, STYLE_HILBERT, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	@call_if_eq VAR_RESULT, STYLE_NATE, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	@call_if_eq VAR_RESULT, STYLE_CALEM, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	@call_if_eq VAR_RESULT, STYLE_ELIO, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	@call_if_eq VAR_RESULT, STYLE_VICTOR, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	@call_if_eq VAR_RESULT, STYLE_FLORIAN, RivalsHouse_2F_EventScript_RivalMalePostLilycove
	setflag FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE
	releaseall
	end

RivalsHouse_2F_EventScript_MayPostLilycove::
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_MayWhereShouldIGoNext
	msgbox RivalsHouse_2F_Text_MayJustCheckingMyPokedex, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_BrendanPostLilycove::
	goto_if_set FLAG_MET_RIVAL_IN_HOUSE_AFTER_LILYCOVE, RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext
	msgbox RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_MayWhereShouldIGoNext::
	msgbox RivalsHouse_2F_Text_MayWhereShouldIGoNext, MSGBOX_DEFAULT
	return

RivalsHouse_2F_EventScript_BrendanWhereShouldIGoNext::
	msgbox RivalsHouse_2F_Text_BrendanWhereShouldIGoNext, MSGBOX_DEFAULT
	return

LittlerootTown_MaysHouse_2F_EventScript_PC::
	lockall
	getplayerstyle
	goto_if_eq VAR_RESULT, STYLE_MAY, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	goto_if_eq VAR_RESULT, STYLE_LEAF, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	@goto_if_eq VAR_RESULT, STYLE_LYRA, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	@goto_if_eq VAR_RESULT, STYLE_DAWN, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	@goto_if_eq VAR_RESULT, STYLE_HILDA, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	@goto_if_eq VAR_RESULT, STYLE_ROSA, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	@goto_if_eq VAR_RESULT, STYLE_SERENA, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	@goto_if_eq VAR_RESULT, STYLE_SELENE, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	@goto_if_eq VAR_RESULT, STYLE_GLORIA, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	@goto_if_eq VAR_RESULT, STYLE_JULIANA, LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC
	goto_if_eq VAR_RESULT, STYLE_BRENDAN, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	goto_if_eq VAR_RESULT, STYLE_RED, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	goto LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	@goto_if_eq VAR_RESULT, STYLE_ETHAN, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	@goto_if_eq VAR_RESULT, STYLE_LUCAS, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	@goto_if_eq VAR_RESULT, STYLE_HILBERT, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	@goto_if_eq VAR_RESULT, STYLE_NATE, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	@goto_if_eq VAR_RESULT, STYLE_CALEM, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	@goto_if_eq VAR_RESULT, STYLE_ELIO, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	@goto_if_eq VAR_RESULT, STYLE_VICTOR, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	@goto_if_eq VAR_RESULT, STYLE_FLORIAN, LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC
	end

LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC::
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_CheckPlayersPC::
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

RivalsHouse_2F_Text_MayWhoAreYou:
	.string "Huh?\n"
	.string "Who… Who are you?\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Oh, you're {PLAYER}{KUN}.\n"
	.string "So your move was today.\p"
	.string "Um… I'm MAY.\n"
	.string "Glad to meet you!\p"
	.string "I…\n"
	.string "I have this dream of becoming friends\l"
	.string "with POKéMON all over the world.\p"
	.string "I… I heard about you, {PLAYER}{KUN}, from\n"
	.string "my dad, PROF. BIRCH.\p"
	.string "I was hoping that you would be nice,\n"
	.string "{PLAYER}{KUN}, and that we could be friends.\p"
	.string "Oh, this is silly, isn't it?\n"
	.string "I… I've just met you, {PLAYER}{KUN}.\p"
	.string "Eheheh…\p"
	.string "Oh, no! I forgot!\p"
	.string "I was supposed to go help Dad catch\n"
	.string "some wild POKéMON!\p"
	.string "{PLAYER}{KUN}, I'll catch you later!$"

RivalsHouse_2F_Text_MayGettingReady:
	.string "POKéMON fully restored!\n"
	.string "Items ready, and…$"

RivalsHouse_2F_Text_BrendanWhoAreYou:
	.string "Hey!\n"
	.string "You…\p"
	.string "Who are you?\p"
	.string "Oh, you're {PLAYER}, aren't you?\n"
	.string "Moved in next door, right?\p"
	.string "I didn't know that you're a girl.\p"
	.string "Dad, PROF. BIRCH, said that our new\n"
	.string "next-door neighbor is a GYM LEADER's\l"
	.string "kid, so I assumed you'd be a guy.\p"
	.string "My name's BRENDAN.\n"
	.string "So, hi, neighbor!\p"
	.string "Huh? Hey, {PLAYER}, don't you have\n"
	.string "a POKéMON?\p"
	.string "Do you want me to go catch you one?\p"
	.string "Aw, darn, I forgot…\p"
	.string "I'm supposed to go help my dad catch\n"
	.string "some wild POKéMON.\p"
	.string "Some other time, okay?$"

RivalsHouse_2F_Text_BrendanGettingReady:
	.string "POKéMON fully restored…\n"
	.string "Items all packed, and…$"

RivalsHouse_2F_Text_ItsRivalsPokeBall:
	.string "It's {RIVAL}'s POKé BALL!\p"
	.string "Better leave it right where it is.$"

RivalsHouse_2F_Text_MayJustCheckingMyPokedex:
	.string "MAY: {PLAYER}{KUN}!\p"
	.string "I was just checking my POKéDEX.\p"
	.string "There's still a lot of POKéMON that\n"
	.string "I've seen but haven't caught.\p"
	.string "And there are many others that\n"
	.string "I think will evolve.\p"
	.string "I wonder where I should go catch\n"
	.string "some POKéMON next?$"

RivalsHouse_2F_Text_MayWhereShouldIGoNext:
	.string "MAY: I wonder where I should go catch\n"
	.string "some POKéMON next?\p"
	.string "Wouldn't it be funny if we ran into each\n"
	.string "other, {PLAYER}{KUN}?$"

RivalsHouse_2F_Text_BrendanJustCheckingMyPokedex:
	.string "BRENDAN: Hey, it's {PLAYER}.\p"
	.string "I was just checking out my POKéDEX.\p"
	.string "There are still many POKéMON that\n"
	.string "I need to catch, I know, but this\l"
	.string "is looking pretty good.\p"
	.string "Checking this POKéDEX out gives me\n"
	.string "the urge to hit the road again.$"

RivalsHouse_2F_Text_BrendanWhereShouldIGoNext:
	.string "{RIVAL}: Ich habe lange überlegt, wo ich\n"
	.string "hingehen soll, um weitere POKéMON\l"
	.string "zu fangen.\p"
	.string "Hey, {PLAYER}, wenn ich dich auf meiner\n"
	.string "Suche treffe, können wir ja einen\l"
	.string "POKéMON-Kampf austragen.$"

LittlerootTown_MaysHouse_2F_Text_BugfixDialog:
	.string "{RIVAL}: Äh… Sorry!\n"
	.string "Ein Bug verhindert gerade,\l"
	.string "dass ich normal durch die Tür gehe.\p"
	.string "Du musst das für mich übernehmen…\n"
	.string "Danke für's Debuggen!$"

