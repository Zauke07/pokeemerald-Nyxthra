FallarborTown_MoveRelearnersHouse_MapScripts::
	.byte 0

FallarborTown_MoveRelearnersHouse_EventScript_MoveRelearner::
	lockall
	applymovement LOCALID_MOVE_RELEARNER, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_TEMP_1, FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	msgbox FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	msgbox FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon, MSGBOX_DEFAULT
	setmoverelearnerstate MOVE_RELEARNER_LEVEL_UP_MOVES @ Specifically supposed to teach level up moves
	special ChooseMonForMoveRelearner
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg
	goto_if_eq VAR_0x8005, 0, FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove
	end

FallarborTown_MoveRelearnersHouse_EventScript_ChooseMove::
	msgbox FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	msgbox FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale
	end

FallarborTown_MoveRelearnersHouse_EventScript_NoMoveToTeachMon::
	msgbox FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_CantTeachEgg::
	msgbox FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto FallarborTown_MoveRelearnersHouse_EventScript_ChooseMon
	end

FallarborTown_MoveRelearnersHouse_EventScript_ComeBackWithHeartScale::
	msgbox FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	releaseall
	end

FallarborTown_MoveRelearnersHouse_Text_ImTheMoveTutor::
	.string "Ich bin der ATTACKEN-HELFER.\p"
	.string "Ich kenne jede einzelne Attacke, die\n"
	.string "jemals existiert hat. Ich bin quasi\l"
	.string "ein Gott, was das angeht.\p"
	.string "Wenn du willst, dass dein POKéMON\n"
	.string "nicht mehr ganz so nutzlos ist, kann\l"
	.string "ich ihm was beibringen.\p"
	.string "Aber ich arbeite nicht umsonst.\n"
	.string "Rück eine HERZSCHUPPE raus, sonst\l"
	.string "bleibt dein Vieh so dumm wie es ist.$"

FallarborTown_MoveRelearnersHouse_Text_ThatsAHeartScaleWantMeToTeachMove::
	.string "Oh! Sieh mal an! Eine echte,\n"
	.string "ehrliche HERZSCHUPPE!\p"
	.string "Lass mich raten: Du willst jetzt,\n"
	.string "dass ich meinen Grips für dich\l"
	.string "anstrenge?$"

FallarborTown_MoveRelearnersHouse_Text_TutorWhichMon::
	.string "Welches POKéMON soll ich vor der\n"
	.string "Verblödung retten?$"

FallarborTown_MoveRelearnersHouse_Text_TeachWhichMove::
	.string "Welche Attacke soll ich in den\n"
	.string "Schädel reinprügeln?$"

FallarborTown_MoveRelearnersHouse_Text_DontHaveMoveToTeachPokemon::
	.string "Tja, Pech gehabt…\p"
	.string "Sogar ich kann diesem hoffnungslosen\n"
	.string "Fall nichts mehr beibringen.$"

FallarborTown_MoveRelearnersHouse_Text_HandedOverHeartScale::
	.string "{PLAYER} hat die wertvolle HERZSCHUPPE\n"
	.string "an den gierigen Typen abgegeben.$"

FallarborTown_MoveRelearnersHouse_Text_ComeBackWithHeartScale::
	.string "Wenn du willst, dass deine POKéMON\n"
	.string "was lernen, besorg gefälligst mehr\l"
	.string "HERZSCHUPPEN!$"

FallarborTown_MoveRelearnersHouse_Text_CantTeachEgg::
	.string "Häh? Willst du mich verarschen?\n"
	.string "Einem EI kann man nichts beibringen!$"
