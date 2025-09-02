DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "Hier auf der kleinen Insel…\n"
	.string "Pokémon, Familie, Meeresrauschen…\l"
	.string "Einfach ein gutes Leben.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "Früher habe ich in GRAPHITPORT CITY\n"
	.string "gelebt - laut, hektisch, voll.\p"
	.string "Hier ist alles langsamer. Ruhiger.\n"
	.string "Das Meer direkt vor der Tür…\l"
	.string "Mehr brauche ich nicht zum Glück.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZACHS: Ziguuh!$"


