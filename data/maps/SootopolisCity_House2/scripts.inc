SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "Der Pyroberg…\p"
	.string "Ganz oben liegen zwei fette\n"
	.string "Kugeln nebeneinander.\l"
	.string "Wusstest du das, du Lappen?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Genau, zwei fette Kugeln…\p"
	.string "Wenn man die zusammen anguckt…\n"
	.string "Das ist so ein geiler Vibe…\l"
	.string "Richtig chillig.$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "Ach, echt nicht?\n"
	.string "Dann beweg deinen Arsch mal\l"
	.string "hoch und guck dir das an.$"

