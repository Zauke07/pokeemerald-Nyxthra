PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "Heute ist von WUNDEREILAND mal\n"
	.string "wieder absolut gar nix zu sehen…$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "Ey! Heilige Scheiße!\n"
	.string "Ich kann heute WUNDEREILAND sehen!$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "WUNDEREILAND…\p"
	.string "Kein Plan, ob der Bums nur bei 'nem\n"
	.string "bestimmten Dreckswetter auftaucht,\l"
	.string "wie so 'ne kaputte Fata Morgana.\p"
	.string "Oder ploppt die Insel echt einfach so\n"
	.string "in die Welt rein und wieder raus?\l"
	.string "Richtiger Mindfuck.$"

