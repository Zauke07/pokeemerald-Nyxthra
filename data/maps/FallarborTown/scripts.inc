FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome::
	.string "Hier geht irgendwas faul ab,\n"
	.string "und ich krieg schlechte Laune!\p"
	.string "Irgendwelche zwielichtigen Gestalten\n"
	.string "rennen bei PROF. KOSMO ständig rein\l"
	.string "und raus. Bestimmt die Mafia…$"

FallarborTown_Text_RegionKnownForMeteors::
	.string "Dieses Kaff ist seit Ewigkeiten für\n"
	.string "Meteore bekannt. Toll, oder?\p"
	.string "Die METEORFÄLLE wurden angeblich von\n"
	.string "einem fetten Stein aus dem All aus-\l"
	.string "gehöhlt. Wer's glaubt…$"

FallarborTown_Text_MyPreciousAzurill::
	.string "Glotz nicht so! Guck dir lieber mal\n"
	.string "mein wertvolles AZURILL an!\p"
	.string "Es ist glitschig, weich und sieht viel\n"
	.string "besser aus als deine Visage!$"

FallarborTown_Text_Azurill::
	.string "AZURILL: Roo-re-würg…$"

FallarborTown_Text_HaveYouChallengedFlannery::
	.string "Hast du dich schon mit FLAVIA aus\n"
	.string "BAD LAVASTADT angelegt?\p"
	.string "Ihr Oppa war mal ’ne große Nummer bei\n"
	.string "den TOP VIER der LIGA.\p"
	.string "Kein Wunder, dass das Mädel so ’ne\n"
	.string "große Klappe hat. Vitamin B eben!$"

FallarborTown_Text_BattleTentSign::
	.string "KAMPFCAMP LAUBWECHSELFELD\n"
	.string "“Wo sich die größten Angeber treffen!”$"

FallarborTown_Text_TownSign::
	.string "LAUBWECHSELFELD\n"
	.string "“Ein staubiges Kaff mit mickrigen Gärten.”$"

FallarborTown_Text_MoveTutorSign::
	.string "HAUS DES ATTACKEN-HELFERS\n"
	.string "“Bringe deinen POKéMON Tricks bei,\n"
	.string "die sie eh wieder vergessen.”$"
