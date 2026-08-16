FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_FORTREE_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	setvar VAR_0x8004, SPECIES_KECLEON
	special RandomizeStaticMonVar8004
	waitse
	playmoncry VAR_0x8004, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky::
	.string "Kein Schwein glaubt mir. Aber ich hab\n"
	.string "ein gigantisches POKéMON am Himmel\l"
	.string "gesehen, ohne Witz!\p"
	.string "Das Teil ist Richtung ROUTE 131\n"
	.string "geeiert und hat sich voll gewunden.\p"
	.string "Schnüffel……\n"
	.string "Sag mal…… Du riechst nach Grillfest.\p"
	.string "Warst du in 'nem Vulkan oder hast du\n"
	.string "beim Kochen versagt?$"

FortreeCity_Text_SomethingBlockingGym::
	.string "Ich wollte gerade zur ARENA, aber\n"
	.string "da ist irgendwas Unsichtbares im Weg.\p"
	.string "Echt jetzt? Da trainier ich wie ein\n"
	.string "Ochse auf ROUTE 120 und dann das……$"

FortreeCity_Text_ThisTimeIllBeatWinona::
	.string "Dieses POKéMON hier ist mein ganzer\n"
	.string "Stolz! Damit mach ich WIBKE platt!\l"
	.string "Die wird gar nicht wissen, wie ihr\l"
	.string "geschieht!$"

FortreeCity_Text_TreesGrowByDrinkingRainwater::
	.string "Der Boden säuft den Regen und die\n"
	.string "Bäume saufen den Boden leer……\p"
	.string "BAUMHAUSEN CITY existiert nur, weil\n"
	.string "wir hier genug Matsch und Wasser haben.$"

FortreeCity_Text_EveryoneHealthyAndLively::
	.string "Wir hocken hier oben auf den Bäumen\n"
	.string "wie die Affen.\p"
	.string "Anscheinend macht das gesund und\n"
	.string "munter, oder so'n Quatsch.\p"
	.string "Ich fühl mich jedenfalls, als wär ich\n"
	.string "30 Jahre jünger. Fast schon gruselig.$"

FortreeCity_Text_BugPokemonComeThroughWindow::
	.string "Klar, Baumhaus ist cool.\p"
	.string "Blöd nur, wenn einem ständig diese\n"
	.string "KÄFER-Viecher durchs Fenster fliegen.\l"
	.string "Da kriegst du echt 'nen Anfall!$"

FortreeCity_Text_PokemonThatEvolveWhenTraded::
	.string "Manche POKéMON entwickeln sich erst,\n"
	.string "wenn man sie wegtauscht. Wer lässt\l"
	.string "sich so einen Mist einfallen?$"

FortreeCity_Text_SomethingUnseeable::
	.string "Irgendwas Unsichtbares nervt hier rum\n"
	.string "und blockiert den Weg.$"

FortreeCity_Text_UnseeableUseDevonScope::
	.string "Da ist wieder dieser unsichtbare Mist im\n"
	.string "Weg. Willst du das DEVON-SCOPE nutzen?$"

FortreeCity_Text_UsedDevonScopePokemonFled::
	.string "{PLAYER} setzt das DEVON-SCOPE ein.\p"
	.string "Das POKéMON wird sichtbar gemacht!\p"
	.string "Das kleine feige Ding haut sofort ab!$"

FortreeCity_Text_CitySign::
	.string "BAUMHAUSEN CITY\n"
	.string "“Wir hocken auf Bäumen und halten\l"
	.string "uns für was Besseres.”$"

FortreeCity_Text_GymSign::
	.string "POKéMON ARENA von BAUMHAUSEN CITY\n"
	.string "LEITERIN: WIBKE\p"
	.string "“Die Vögel-Tante macht den Abflug!”$"

