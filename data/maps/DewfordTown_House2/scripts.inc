DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Sieh dir das mal an!\p"
	.string "Ein SEIDENSCHAL - voll im Trend!\n"
	.string "Stylisch UND nützlich, yeah!\p"
	.string "Dein Blick sagt alles…\n"
	.string "Du hast Geschmack, das gefällt mir!\p"
	.string "Komm, den schenke ich dir!$"

DewfordTown_House2_Text_NoRoom:
	.string "Oh nein, dein BEUTEL ist voll!\p"
	.string "Dieser SCHAL ist ein echtes Must-have!\n"
	.string "Ich würde alles verkaufen, nur um ihn\l"
	.string "zu behalten - aber du sollst ihn haben!$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "Der SEIDENSCHAL boostet normale\n"
	.string "Attacken - richtig stark!\p"
	.string "Und das Beste: Er steht fast jedem\n"
	.string "Pokémon ausgezeichnet!$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Wow, du bist wirklich über das Meer\n"
	.string "gereist, um hierherzukommen?\p"
	.string "Weil du von KAMILLO gehört hast,\n"
	.string "stimmt’s?\p"
	.string "Er ist soooo cool…\n"
	.string "Ein echtes Idol!$"


