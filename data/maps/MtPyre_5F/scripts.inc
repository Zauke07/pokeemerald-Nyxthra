MtPyre_5F_MapScripts::
	.byte 0

@ Seems like the scripts for the 4F and 5F were swapped

MtPyre_4F_EventScript_Tasha::
	trainerbattle_single TRAINER_TASHA, MtPyre_4F_Text_TashaIntro, MtPyre_4F_Text_TashaDefeat
	msgbox MtPyre_4F_Text_TashaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_4F_Text_TashaIntro::
	.string "Ich steh total auf kranken Horror…\n"
	.string "Das ist wie 'ne Sucht…\p"
	.string "Wenn ich hier bin…\n"
	.string "Zitter ich am ganzen Leib vor Angst…\l"
	.string "Geil, oder?$"

MtPyre_4F_Text_TashaDefeat::
	.string "Verlieren find ich…… zum Kotzen.$"

MtPyre_4F_Text_TashaPostBattle::
	.string "Ich will noch mehr gruseligen Scheiß\n"
	.string "sehen… ich komm hier nicht weg…\p"
	.string "Bleib doch noch…\n"
	.string "Willst du nicht für immer bei mir bleiben?$"

