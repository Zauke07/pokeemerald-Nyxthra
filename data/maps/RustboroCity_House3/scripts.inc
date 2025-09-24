RustboroCity_House3_MapScripts::
	.byte 0

RustboroCity_House3_EventScript_OldMan::
	msgbox RustboroCity_House3_Text_IGivePerfectlySuitedNicknames, MSGBOX_NPC
	end

RustboroCity_House3_EventScript_OldWoman::
	msgbox RustboroCity_House3_Text_NamingPikachuPekachu, MSGBOX_NPC
	end

@ Misspelling on purpose, see nickname
RustboroCity_House3_EventScript_Pekachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox RustboroCity_House3_Text_Pekachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RustboroCity_House3_Text_IGivePerfectlySuitedNicknames:
	.string "Ich finde, ein KOSENAME sollte perfekt\n"
	.string "zum POKéMON passen!\p"
	.string "Das ist meine Art, meine Kreativität\n"
	.string "auszudrücken. Oder so ähnlich.$"

RustboroCity_House3_Text_NamingPikachuPekachu:
	.string "Aber ein PIKACHU einfach “Hurensohn”\n"
	.string "zu nennen…? Hm.\p"
	.string "Ich mein, jeder merkt sich den Namen,\n"
	.string "aber stilvoll ist das nicht gerade…$"

RustboroCity_House3_Text_Pekachu:
	.string "Hurensohn: Peka!$"
