GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "He, warte kurz!\n"
	.string "Dort vorne wird's richtig finster.\l"
	.string "Ohne Licht sieht man kein Stück.\p"
	.string "So ein anderer Typ war vorhin hier...\n"
	.string "TROY hieß der wohl. Der kennt sich aus.\p"
	.string "Der kann BLITZ einsetzen - kein Problem\n"
	.string "für ihn also.\p"
	.string "Aber hey, wir WANDERER halten zusammen!\n"
	.string "Also nimm das hier, könnte helfen.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Bring einem deiner Pokémon die VM BLITZ\n"
	.string "bei und setz sie hier ein.\p"
	.string "Dann wird’s deutlich heller - wie'n\n"
	.string "Scheinwerfer in der Nacht.\p"
	.string "Aber Vorsicht: Du brauchst den ORDEN\n"
	.string "von FAUSTAUHAVEN, sonst klappt’s nicht.$"

