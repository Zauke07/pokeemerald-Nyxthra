MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis::
	.string "YEEAAHHH!\p"
	.string "Die Leute nennen mich den\n"
	.string "ZERTRÜMMERER, aber das ist mir zu\l"
	.string "weich! Ich bin der ZERTRÜMMERER-\l"
	.string "GOTT, verdammt noch mal!\p"
	.string "Ein bisschen mehr Respekt vor meiner\n"
	.string "Zerstörungswut, wenn ich bitten darf!\p"
	.string "YEEAAHHH, deine POKéMON sehen aus,\n"
	.string "als könnten sie auch ordentlich\l"
	.string "Schädel spalten!\p"
	.string "Das gefällt mir! Hier, nimm den Scheiß\n"
	.string "und mach was kaputt!$"

MauvilleCity_House1_Text_ExplainRockSmash::
	.string "In der VM steckt ZERTRÜMMERER.\p"
	.string "Wenn dir irgendein hässlicher Fels\n"
	.string "im Weg steht…\p"
	.string "Dann lass dein POKéMON draufkloppen,\n"
	.string "bis nur noch Staub übrig ist!\p"
	.string "Jawohl! Alles kurz und klein schlagen,\n"
	.string "das ist mein Lifestyle! YEEAAHHH!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock::
	.string "Ach ja, wenn du so einen Kiesel\n"
	.string "zerlegst, springt dir manchmal ein\l"
	.string "POKéMON ins Gesicht.\p"
	.string "Dann kriegt das halt auch direkt aufs\n"
	.string "Maul! YEEAAHHH!$"

