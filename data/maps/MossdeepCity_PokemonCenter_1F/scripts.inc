MossdeepCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MossdeepCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MOSSDEEP_CITY
	end

MossdeepCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_MOSSDEEP_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MossdeepCity_PokemonCenter_1F_EventScript_Woman::
	msgbox MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_EventScript_Girl::
	msgbox MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves, MSGBOX_NPC
	end

MossdeepCity_PokemonCenter_1F_Text_GymLeaderDuoFormidable:
	.string "Die Arenaleiter hier sind ein komplett\n"
	.string "gestörtes Psycho-Pärchen.\p"
	.string "Die geilen sich richtig daran auf,\n"
	.string "dich zu zweit in die Zange zu nehmen\l"
	.string "und deinen Kopf weichzukneten.\p"
	.string "Für die ist ein Arenakampf kein Kampf,\n"
	.string "sondern ein perverses kleines\l"
	.string "Psycho-Spielchen.\p"
	.string "Die beiden sind so versaut, dass sie\n"
	.string "sogar den Loser danach fragen,\l"
	.string "ob er noch mitmachen will.\p"
	.string "Angeblich stehen die total auf Dreier,\n"
	.string "wenn ihnen dabei jemand völlig\l"
	.string "verstört beim Ficken zusieht.\p"
	.string "Ich sag dir: Diese Arena testet nicht\n"
	.string "nur deine Pokémon, sondern auch\l"
	.string "deine letzten Hirnzellen.$"

MossdeepCity_PokemonCenter_1F_Text_AbilitiesMightChangeMoves:
	.string "Pass auf, manche Pokémon haben so\n"
	.string "abgefuckte Fähigkeiten, dass deine\l"
	.string "Attacken einfach im Keim ersticken.\p"
	.string "Es ist, als ob sie deine Moves wie so\n"
	.string "kleine Sklaven für ihre eigenen\l"
	.string "perversen Gelüste missbrauchen.\p"
	.string "Entweder macht dein Move plötzlich\n"
	.string "null Schaden oder er wird komplett\l"
	.string "umgedreht, um dich zu demütigen.\p"
	.string "Wer nicht checkt, wie die Viecher\n"
	.string "ticken, wird hier schneller flachgelegt\l"
	.string "als er Pokéball sagen kann!$"
