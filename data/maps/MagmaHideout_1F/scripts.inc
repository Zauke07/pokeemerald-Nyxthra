MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_2, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "Wenn TEAM MAGMA zum Appell antreten muss,\n"
	.string "werden die wichtigen Wachposten nach\l"
	.string "Reihenfolge verteilt.\p"
	.string "Deshalb hänge ich hier in dieser Ecke fest.\n"
	.string "Ich bin immer zu spät beim Appell!$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "Beim Training bin ich auch immer zu spät…\n"
	.string "immer!\p"
	.string "Ich sag's ungern, aber ich bin echt ein Lauch…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "Okay, ich geb mir ab jetzt\n"
	.string "ein bisschen mehr Mühe…$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Unser Boss hat uns befohlen, am\n"
	.string "SCHLOTBERG zu graben, also haben wir gegraben ohne Ende.\p"
	.string "Und dabei sind wir auf etwas gestoßen,\n"
	.string "das komplett krank ist!\p"
	.string "Was wir gefunden haben?\p"
	.string "Fuhahaha!\n"
	.string "Sag ich dir, wenn du mich schlägst!$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Arrgh!\n"
	.string "Voll weggehauen!$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "Nö, ich sag's dir doch nicht.\n"
	.string "Find's selbst raus, wenn du da bist!\p"
	.string "Ist doch viel besser, wenn die große\n"
	.string "Überraschung bis zum Ende bleibt, oder?$"

