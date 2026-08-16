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
	.string "Mit Pokémon kriegen selbst die\n"
	.string "hässlichsten Wichser 'ne Alte ab.\p"
	.string "Dank diesen Viechern rückt die Welt\n"
	.string "enger zusammen. Richtig widerlich, wenn\l"
	.string "man mal genauer drüber nachdenkt, oder?$"

FortreeCity_House4_Text_GoBirdPokemon::
	.string "Beweg deinen Arsch!\n"
	.string "Bring meiner Perle die versaute Post,\l"
	.string "du nutzloser Drecksvogel!$"

FortreeCity_House4_Text_AskedWingullToRunErrand::
	.string "Hehehe… Mein dummes Wingull muss\n"
	.string "meine Nacktbilder nach Moosbach fliegen.\p"
	.string "Ist billiger als Internet und der Vogel\n"
	.string "kann mich bei den Bullen eh nicht\l"
	.string "verpetzen. Genial, oder?$"

FortreeCity_House4_Text_WelcomeWingullTakeMentalHerb::
	.string "Na endlich! Da bist du ja wieder,\n"
	.string "du fliegende Ratte!\p"
	.string "Was hast du mir von ihr mitgebracht?\n"
	.string "Ihre getragenen Höschen? Lass sehen!\p"
	.string "… Ein Mentalkraut?!\n"
	.string "Will die mich verarschen? Denkt die,\l"
	.string "ich brauche Potenzmittel oder was?!\p"
	.string "Hier, nimm den Müll mit. Ich hab eh\n"
	.string "'nen Ständer wie ein Laternenpfahl.\l"
	.string "Ich fang mit dem Dreck nix an.$"

FortreeCity_House4_Text_FriendsFarAwayThanksToWingull::
	.string "Dank meinem Wingull hab ich 'ne geile\n"
	.string "Fernbeziehung am Laufen.\p"
	.string "Ist eigentlich der absolute Jackpot.\n"
	.string "Ich krieg versaute Post und muss ihr\l"
	.string "Gelaber nicht im echten Leben ertragen.$"

FortreeCity_House4_Text_Wingull::
	.string "Wingull: Pi… Pihyoh…\n"
	.string "(Bitte… ich rieche immer noch nach\l"
	.string "seinen ungewaschenen Eiern…\l"
	.string "erlöse mich…)$"

