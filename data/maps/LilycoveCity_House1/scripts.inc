LilycoveCity_House1_MapScripts::
	.byte 0

LilycoveCity_House1_EventScript_ExpertM::
	msgbox LilycoveCity_House1_Text_PokemonPartnersNotTools, MSGBOX_NPC
	end

LilycoveCity_House1_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox LilycoveCity_House1_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_House1_Text_PokemonPartnersNotTools::
	.string "POKéMON sind Partner, verdammt noch mal.\n"
	.string "Kein Werkzeug für deine Zwecke!\p"
	.string "Leider gibt's genug Vollpfosten da\n"
	.string "draußen, die zu hohl sind, um das zu\l"
	.string "kapieren…… Gehörst du auch dazu?$"

LilycoveCity_House1_Text_Kecleon::
	.string "KECLEON: Ruroro? (Was glotzt du so?)$"

