FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FORTREE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Na, Schätzelein, tryhardest du gerade\n"
	.string "für deinen Pokédex?\p"
	.string "Hmm… Wenn ich du wäre, würde ich mal\n"
	.string "meinen Arsch zur Safari-Zone auf der\l"
	.string "Route 121 bewegen. Da gibt's Loot.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Hast du schon mal deine Statistik\n"
	.string "mit anderen getauscht?\p"
	.string "Ist quasi wie ein Schwanzvergleich für\n"
	.string "Trainer. Da wird alles gespeichert und\l"
	.string "man sieht genau, wer der größte Lappen\l"
	.string "ist.\p"
	.string "Keine Ahnung, wie die das machen, aber\n"
	.string "es bockt richtig! Geisteskrank!$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Ey, du hast ja 'nen Pokénav!\n"
	.string "Ich hab auch so ein Teil.\p"
	.string "Checkst du schon das Trainer-Ruf-System\n"
	.string "von dem Ding?\p"
	.string "Damit kannst du die ganzen registrierten\n"
	.string "Dullis jederzeit vollquatschen.\p"
	.string "Und du siehst sofort, welcher Low-Bob\n"
	.string "nochmal Bock auf 'ne Abreibung hat.\p"
	.string "Ist doch mega geil, oder?\n"
	.string "Muss man Devon lassen, stabiles Teil!$"

