LavaridgeTown_House_MapScripts::
	.byte 0

LavaridgeTown_House_EventScript_OldMan::
	msgbox LavaridgeTown_House_Text_WifeWarmingEggInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_House_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox LavaridgeTown_House_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LavaridgeTown_House_Text_WifeWarmingEggInHotSprings::
	.string "Meine Olle hockt draußen und wärmt\n"
	.string "so ein dämliches EI in den Quellen.\p"
	.string "Sie labert ständig davon, dass sie zwei\n"
	.string "POKéMON in der PENSION abgegeben hat.\p"
	.string "Und plötzlich war da dieses EI. Ich will\n"
	.string "gar nicht wissen, was die Viecher da\l"
	.string "getrieben haben. Echt eklig!$"

LavaridgeTown_House_Text_Zigzagoon:
	.string "Zichszachs: Pshoo!$"

