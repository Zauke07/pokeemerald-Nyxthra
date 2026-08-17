MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON_SLEEPING
	addobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_MAGMA_HIDEOUT_4F_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_HIDEOUT_4F_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAGMA_HIDEOUT_4F_MAXIE
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_1
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_2
	removeobject LOCALID_MAGMA_HIDEOUT_4F_GRUNT_3
	removeobject LOCALID_MAGMA_HIDEOUT_4F_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "Ich will GROUDON auch sehen, aber sie\n"
	.string "lassen mich nicht mal einen Blick drauf werfen…\p"
	.string "Das frustriert mich total.\p"
	.string "Oh nein!\n"
	.string "Ich hab was über GROUDON ausgeplaudert!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "Ohne einen ruhigen Kopf kann man\n"
	.string "wohl einfach nicht gewinnen…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "Ich frag mich, ob GROUDON überhaupt einen Schwanz hat?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Fuhahaha!\n"
	.string "Bald! Sehr bald!\l"
	.string "Dann erreichen wir unser großes Ziel!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr…\n"
	.string "So weit gekommen, und dann das?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "MAXIE, Sir!\n"
	.string "Ein Eindringling ist auf dem Weg zu dir!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "Du bist noch nicht fertig!\n"
	.string "An mir kommst du nicht so leicht vorbei!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "War ich echt so leicht umzuhauen?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "K-komm schon, noch ein Kampf…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Hehehe!\n"
	.string "Du bist bis hier gekommen, also sag ich's dir!\p"
	.string "Genau!\n"
	.string "Da vorne schläft GROUDON!\p"
	.string "MAXIE ist erst vor ein paar Sekunden\n"
	.string "zu GROUDON gegangen!\p"
	.string "Es wird gleich aufwachen!\n"
	.string "Hehe! Hehehe!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Schon wieder erledigt…\n"
	.string "Hehe…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "…Während du dich hier mit mir aufgehalten hast,\n"
	.string "hat MAXIE GROUDON längst geweckt…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAXIE: GROUDON…\p"
	.string "Nichts konnte dich aus deinem\n"
	.string "Schlaf im Magma wecken…\p"
	.string "Doch diesen BLAUEN ORB hast du gesucht.\n"
	.string "Oder nicht?\p"
	.string "Ich habe dir den BLAUEN ORB gebracht.\n"
	.string "Sein Glanz soll dich erwecken!\p"
	.string "Und zeig mir…\n"
	.string "Zeig mir die ganze Macht, die in dir steckt!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAXIE: GROUDON!\n"
	.string "Was ist los?\p"
	.string "War der BLAUE ORB nicht der Schlüssel?\p"
	.string "GROUDON!\n"
	.string "Wohin bist du verschwunden…$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MAXIE: Oh, also warst du das?\p"
	.string "Ich habe dich schon öfter gesehen,\n"
	.string "wie du ungefragt herumgeschnüffelt hast…\p"
	.string "Jetzt ist klar!\n"
	.string "Du hast also einen billigen Trick abgezogen!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "Was macht dich so gut im Umgang mit\n"
	.string "POKéMON?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "MAXIE: Es muss einen Grund geben,\n"
	.string "warum GROUDON geflohen ist…\p"
	.string "Das willst du mir doch sagen,\n"
	.string "oder?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Hmph…\n"
	.string "Du glaubst, ich hätte das nicht selbst erkannt?\p"
	.string "Ohne GROUDON gibt es keinen Grund mehr\n"
	.string "für diesen verfluchten Vulkan.\p"
	.string "Ich gehe GROUDON nach. Also\n"
	.string "trennen sich unsere Wege hier!$"
