FortreeCity_House4_MapScripts::
	.byte 0

FortreeCity_House4_EventScript_Woman::
	msgbox FortreeCity_House4_Text_BringsWorldCloserTogether, MSGBOX_NPC
	end

FortreeCity_House4_EventScript_Boy::
	lockall
	goto_if_set FLAG_RECEIVED_MENTAL_HERB, FortreeCity_House4_EventScript_ReceivedMentalHerb
	goto_if_set FLAG_WINGULL_DELIVERED_MAIL, FortreeCity_House4_EventScript_WingullReturned
	goto_if_set FLAG_WINGULL_SENT_ON_ERRAND, FortreeCity_House4_EventScript_WingullOnErrand
	msgbox FortreeCity_House4_Text_GoBirdPokemon, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_WINGULL_SENT_ON_ERRAND
	clearflag FLAG_HIDE_MOSSDEEP_CITY_HOUSE_2_WINGULL
	applymovement LOCALID_FORTREE_HOUSE_WINGULL, FortreeCity_House4_Movement_WingullExit
	waitmovement 0
	removeobject LOCALID_FORTREE_HOUSE_WINGULL
	releaseall
	end

FortreeCity_House4_EventScript_WingullOnErrand::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_AskedWingullToRunErrand, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_EventScript_WingullReturned::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb, MSGBOX_DEFAULT
	giveitem ITEM_MENTAL_HERB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MENTAL_HERB
	releaseall
	end

FortreeCity_House4_EventScript_ReceivedMentalHerb::
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox FortreeCity_House4_Text_FriendsFarAwayThanksToWingull, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_House4_Movement_WingullExit:
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_down
	delay_8
	step_end

FortreeCity_House4_EventScript_Wingull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, CRY_MODE_NORMAL
	msgbox FortreeCity_House4_Text_Wingull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House4_Text_BringsWorldCloserTogether::
	.string "Wenn man POKéMON dabei hat, finden\n"
	.string "selbst die größten Creeps Freunde.\p"
	.string "So rückt die Welt zusammen, ob man will\n"
	.string "oder nicht. Ziemlich nervig, oder?$"

FortreeCity_House4_Text_GoBirdPokemon::
	.string "Abflug!\n"
	.string "Los, du nutzloses VOGEL-POKéMON!$"

FortreeCity_House4_Text_AskedWingullToRunErrand::
	.string "Hähähä, mein WINGULL muss für mich\n"
	.string "die Drecksarbeit erledigen.$"

FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb::
	.string "Na endlich!\n"
	.string "Komm zurück, du lahme Ente!\p"
	.string "Huch! Was hast du da im Schnabel?\n"
	.string "Wo hast du das denn mitgehen lassen?\p"
	.string "Ein MENTALKRAUT?\n"
	.string "Wahrscheinlich hat es das irgendwo geklaut.\p"
	.string "Da ich kein Trainer bin, kannst du das\n"
	.string "Zeug haben. Ich fang damit nix an.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToWingull::
	.string "Dank meines WINGULLS hab ich Brieffreunde,\n"
	.string "die so weit weg wohnen, dass ich sie\l"
	.string "zum Glück nie persönlich sehen muss.$"

FortreeCity_House4_Text_Wingull::
	.string "WINGULL: Pihyoh! (Lass mich in Ruhe!)$"

