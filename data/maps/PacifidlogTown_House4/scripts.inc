PacifidlogTown_House4_MapScripts::
	.byte 0

PacifidlogTown_House4_EventScript_LittleGirl::
	msgbox PacifidlogTown_House4_Text_SkyPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Woman::
	msgbox PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon, MSGBOX_NPC
	end

PacifidlogTown_House4_EventScript_Boy::
	lock
	faceplayer
	msgbox PacifidlogTown_House4_Text_WhereDidYouComeFrom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PacifidlogTown_House4_EventScript_Yes
	goto_if_eq VAR_RESULT, NO, PacifidlogTown_House4_EventScript_No
	end

PacifidlogTown_House4_EventScript_Yes::
	msgbox PacifidlogTown_House4_Text_YesTown, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_EventScript_No::
	msgbox PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House4_Text_PeopleSawHighFlyingPokemon:
	.string "Die Leute labern, sie hätten so'n fettes\n"
	.string "POKéMON ganz oben am Himmel über\l"
	.string "HOENN gesehen.\p"
	.string "Fliegt das Vieh eigentlich 24/7 da rum?\n"
	.string "Irgendwann muss das doch auch mal\l"
	.string "pennen gehen, oder nicht?$"

PacifidlogTown_House4_Text_SkyPokemon:
	.string "Fettes Himmels-POKéMON! Wusch!\n"
	.string "Fettes Himmels-POKéMON!$"

PacifidlogTown_House4_Text_WhereDidYouComeFrom:
	.string "Ey, aus welchem Loch kommst du\n"
	.string "denn eigentlich gekrochen?$"

PacifidlogTown_House4_Text_YesTown:
	.string "“Ja”? Du kommst aus JA-HAUSEN?\p"
	.string "Was für ein absolutes Drecksloch soll\n"
	.string "das denn sein? Nie von dem Kaff gehört.$"

PacifidlogTown_House4_Text_YouHaveToComeFromSomewhere:
	.string "“Nein”? Willst du mich verarschen?\n"
	.string "Du musst ja wohl irgendwo gespawnt sein.\p"
	.string "Warte mal... Sag bloß, du bist da unten\n"
	.string "auf dem Meeresgrund geschlüpft?$"

