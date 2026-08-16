MossdeepCity_House2_MapScripts::
	.byte 0

MossdeepCity_House2_EventScript_Man::
	msgbox MossdeepCity_House2_Text_SisterMailsBoyfriendInFortree, MSGBOX_NPC
	end

MossdeepCity_House2_EventScript_Twin::
	msgbox MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth, MSGBOX_NPC
	end

MossdeepCity_House2_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox MossdeepCity_House2_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	setflag FLAG_WINGULL_DELIVERED_MAIL
	clearflag FLAG_HIDE_FORTREE_CITY_HOUSE_4_WINGULL
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_House2_EventScript_WingullExitNorth
	call_if_eq VAR_FACING, DIR_WEST, MossdeepCity_House2_EventScript_WingullExitWest
	removeobject LOCALID_MOSSDEEP_HOUSE_WINGULL
	release
	end

MossdeepCity_House2_EventScript_WingullExitNorth::
	applymovement LOCALID_MOSSDEEP_HOUSE_WINGULL, MossdeepCity_House2_Movement_WingullExitNorth
	waitmovement 0
	return

MossdeepCity_House2_EventScript_WingullExitWest::
	applymovement LOCALID_MOSSDEEP_HOUSE_WINGULL, MossdeepCity_House2_Movement_WingullExitEast
	waitmovement 0
	return

MossdeepCity_House2_Movement_WingullExitNorth:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_down
	delay_8
	step_end

MossdeepCity_House2_Movement_WingullExitEast:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	delay_8
	step_end

MossdeepCity_House2_Text_SisterMailsBoyfriendInFortree:
	.string "Meine kleine Schwester schickt ständig\n"
	.string "versaute Briefe an ihren Stecher in\l"
	.string "Baumhausen.\p"
	.string "Absoluter Cringe. Ich bin echt froh,\n"
	.string "dass ich nicht so ein liebestolles\l"
	.string "Opfer bin.$"

MossdeepCity_House2_Text_PokemonCarriesMailBackAndForth:
	.string "Auch wenn ich meinen Typen in\n"
	.string "Baumhausen gerade nicht reiten kann,\l"
	.string "schleppt mein armes Pokémon unsere\l"
	.string "schmutzigen Briefe hin und her.\p"
	.string "Wer braucht schon echte Nähe, wenn\n"
	.string "man Sexting über 'nen Vogel betreiben\l"
	.string "kann? Gar kein Problem für mich.$"

MossdeepCity_House2_Text_Wingull:
	.string "Wingull: Pi… Pihyoh…$"

