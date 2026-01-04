MtPyre_4F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_5F_EventScript_Atsushi::
	trainerbattle_single TRAINER_ATSUSHI, MtPyre_5F_Text_AtsushiIntro, MtPyre_5F_Text_AtsushiDefeat
	msgbox MtPyre_5F_Text_AtsushiPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_5F_Text_AtsushiIntro::
	.string "Meister……\n"
	.string "Schau zu, wie ich diesen Eindringling\l"
	.string "aus dem Leben trete!$"

MtPyre_5F_Text_AtsushiDefeat::
	.string "Meister……\n"
	.string "Vergib mir meine Unfähigkeit!$"

MtPyre_5F_Text_AtsushiPostBattle::
	.string "Solange ich so eine Nullnummer bin,\n"
	.string "wird mein Meister hier niemals seinen\l"
	.string "verdammten Frieden finden……$"

