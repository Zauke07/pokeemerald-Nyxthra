MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_CEDRIC, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro::
	.string "Wenn ich hier oben stehe……\n"
	.string "fließt so eine kranke Macht in mich rein……$"

MtPyre_6F_Text_ValerieDefeat::
	.string "Die Macht verpisst sich gerade wieder……$"

MtPyre_6F_Text_ValeriePostBattle::
	.string "Wahrscheinlich kommt die Kraft von den\n"
	.string "Geistern der Viecher, die hier oben\l"
	.string "ihren ewigen Schlaf abhalten……$"

MtPyre_6F_Text_ValerieRegister::
	.string "Fufufu…… Ich hab zwar verloren, aber…\n"
	.string "Ich hab da so 'ne kleine Begabung……\p"
	.string "Ich muss deinen POKéNAV nicht mal\n"
	.string "berühren, um mich reinzuhacken! Hiyah!$"

MtPyre_6F_Text_ValerieRematchIntro::
	.string "Direkt hinter dir……\n"
	.string "Was ist das bloß……$"

MtPyre_6F_Text_ValerieRematchDefeat::
	.string "Irgendetwas ist gerade verpufft……$"

MtPyre_6F_Text_ValeriePostRematch::
	.string "Die POKéMON, die hier verrotten……\n"
	.string "Manchmal kommen sie raus, um zu\l"
	.string "spielen. Gruselig, oder?$"

MtPyre_6F_Text_CedricIntro::
	.string "Hast du dich verlaufen, Kleiner?\n"
	.string "Keine Sorge, ich bin ja da!$"

MtPyre_6F_Text_CedricDefeat::
	.string "Wartest du nicht total verängstigt?$"

MtPyre_6F_Text_CedricPostBattle::
	.string "Ich dachte echt, ein verirrter Trainer\n"
	.string "wäre total in Panik und leichtes Spiel.\p"
	.string "War 'ne miese Nummer, ich geb's zu.\n"
	.string "Mach ich nie wieder…… vielleicht.$"

