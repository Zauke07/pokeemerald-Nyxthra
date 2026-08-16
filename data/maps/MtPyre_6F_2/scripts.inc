MtPyre_6F_2_MapScripts::
	.byte 0

MtPyre_6F_2_EventScript_NotFinishedTrigger::
	lockall
	setvar VAR_TEMP_0, 1
	msgbox MtPyre_6F_2_Text_NotFinishedYet, MSGBOX_DEFAULT
	switch VAR_FACING
	case DIR_NORTH, MtPyre_6F_2_EventScript_StepBackSouth
	case DIR_SOUTH, MtPyre_6F_2_EventScript_StepBackNorth
	case DIR_WEST, MtPyre_6F_2_EventScript_StepBackEast
	case DIR_EAST, MtPyre_6F_2_EventScript_StepBackWest
	goto MtPyre_6F_2_EventScript_Release

MtPyre_6F_2_EventScript_StepBackSouth::
	applymovement LOCALID_PLAYER, MtPyre_6F_2_Movement_StepBackSouth
	waitmovement 0
	goto MtPyre_6F_2_EventScript_Release

MtPyre_6F_2_EventScript_StepBackNorth::
	applymovement LOCALID_PLAYER, MtPyre_6F_2_Movement_StepBackNorth
	waitmovement 0
	goto MtPyre_6F_2_EventScript_Release

MtPyre_6F_2_EventScript_StepBackEast::
	applymovement LOCALID_PLAYER, MtPyre_6F_2_Movement_StepBackEast
	waitmovement 0
	goto MtPyre_6F_2_EventScript_Release

MtPyre_6F_2_EventScript_StepBackWest::
	applymovement LOCALID_PLAYER, MtPyre_6F_2_Movement_StepBackWest
	waitmovement 0
	goto MtPyre_6F_2_EventScript_Release

MtPyre_6F_2_EventScript_Release::
	setvar VAR_TEMP_0, 0
	releaseall
	end

MtPyre_6F_2_Movement_StepBackSouth:
	walk_down
	step_end

MtPyre_6F_2_Movement_StepBackNorth:
	walk_up
	step_end

MtPyre_6F_2_Movement_StepBackEast:
	walk_right
	step_end

MtPyre_6F_2_Movement_StepBackWest:
	walk_left
	step_end

MtPyre_6F_2_Text_NotFinishedYet:
	.string "{COLOR PLAYER_CLR}{PLAYER}: Hm...\p"
	.string "Hier kann ich noch nicht weiter.\n"
	.string "Sieht noch nicht fertig aus...{COLOR WHITE}$"
