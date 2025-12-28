Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother::
	.string "Mein großer Bruder ist der FOSSIL-\n"
	.string "MANIAC… Er ist ein Freak, der Steine\l"
	.string "mehr liebt als Menschen…\p"
	.string "Der Typ gräbt den ganzen Tag Löcher,\n"
	.string "als hätte er sie nicht mehr alle.\l"
	.string "Das riesige Loch da? Alles er selbst!\p"
	.string "Nimm das hier. Damit kannst du auch im\n"
	.string "Dreck wühlen, wenn du sonst keine\l"
	.string "Hobbys hast…$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance::
	.string "Wenn ein POKéMON in einer Höhle\n"
	.string "SCHAUFLER einsetzt, teleportiert es dich\l"
	.string "zum Eingang zurück. Praktisch für faule\l"
	.string "Säcke wie dich.$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase::
	.string "Ein Haufen hässlicher Steine liegt im\n"
	.string "Schaukasten. Wer stellt sich so einen\l"
	.string "Schrott bitteschön ins Wohnzimmer?$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks::
	.string "DIE DRECKIGSTEN ERDSCHICHTEN…\n"
	.string "WARUM REGEN NERVT…\l"
	.string "STEINE, BODEN UND ANDERER MÜLL…\p"
	.string "Das Regal ist gerammelt voll mit\n"
	.string "stinklangweiligen Büchern.$"

