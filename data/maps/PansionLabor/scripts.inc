PansionLabor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PansionLabor_OnTransition
	.byte 0

PansionLabor_OnTransition:
	goto_if_unset FLAG_DAYCARE_RESCUE_QUEST_COMPLETED, PansionLabor_CheckShowNPCs
	setflag FLAG_HIDE_PANSION_DISGUISED_NPC
	setflag FLAG_HIDE_PANSION_JAMES
	setflag FLAG_HIDE_PANSION_OLD_MAN
	end

PansionLabor_CheckShowNPCs:
	goto_if_set FLAG_PENDING_DAYCARE_EGG, PansionLabor_ShowNPCs
	setflag FLAG_HIDE_PANSION_DISGUISED_NPC
	setflag FLAG_HIDE_PANSION_JAMES
	setflag FLAG_HIDE_PANSION_OLD_MAN
	end

PansionLabor_ShowNPCs:
	goto_if_unset FLAG_DEFEATED_DAYCARE_KIDNAPPER, PansionLabor_ShowDisguised
	goto_if_set FLAG_PENDING_DAYCARE_EGG, PansionLabor_ShowOldManAtJamesPosition
	setflag FLAG_HIDE_PANSION_DISGUISED_NPC
	setflag FLAG_HIDE_PANSION_JAMES
	setflag FLAG_HIDE_PANSION_OLD_MAN
	end

PansionLabor_ShowDisguised:
	clearflag FLAG_HIDE_PANSION_DISGUISED_NPC
	clearflag FLAG_HIDE_PANSION_OLD_MAN
	setflag FLAG_HIDE_PANSION_JAMES
	end

PansionLabor_ShowOldManAtJamesPosition:
	setflag FLAG_HIDE_PANSION_DISGUISED_NPC
	setflag FLAG_HIDE_PANSION_JAMES
	end

@ Verkleideter NPC (wird zu James)
PansionLabor_EventScript_DisguisedNPC::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DAYCARE_KIDNAPPER, PansionLabor_EventScript_AlreadyDefeated
	msgbox PansionLabor_Text_DisguisedIntro, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_WHITE
	delay 10
	fadescreen FADE_FROM_WHITE
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 6
	setvar VAR_0x8007, 4
	special ShakeCamera
	waitstate
	waitmoncry
	fadescreen FADE_TO_BLACK
	delay 20
	removeobject LOCALID_DISGUISED_NPC
	addobject LOCALID_JAMES
	applymovement LOCALID_JAMES, Common_Movement_FacePlayer
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	playse SE_PIN
	delay 30
	msgbox PansionLabor_Text_JamesReveal, MSGBOX_DEFAULT
	msgbox PansionLabor_Text_TeamRocketPlan, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_JAMES_TEAM_ROCKET, PansionLabor_Text_JamesDefeat
	@ Nach Kampf - James letzte Worte
	msgbox PansionLabor_Text_JamesAfterDefeat, MSGBOX_DEFAULT
	closemessage

	@ WEIßER BLITZ - James verschwindet!
	fadescreen FADE_TO_WHITE
	delay 10
	playse SE_M_FLY
	removeobject LOCALID_JAMES
	setflag FLAG_HIDE_PANSION_JAMES
	fadescreen FADE_FROM_WHITE

	delay 30

	@ Old Man Position aktualisieren (wichtig!)
	removeobject LOCALID_OLD_MAN
	setobjectxyperm LOCALID_OLD_MAN, 16, 9

	@ WEIßER BLITZ - Old Man erscheint!
	fadescreen FADE_TO_WHITE
	delay 10
	playse SE_WARP_IN
	addobject LOCALID_OLD_MAN
	clearflag FLAG_HIDE_PANSION_OLD_MAN
	fadescreen FADE_FROM_WHITE

	@ Old Man dreht sich zum Spieler
	applymovement LOCALID_OLD_MAN, Common_Movement_FacePlayer
	waitmovement 0

	delay 20

	@ Old Man bedankt sich und gibt EI!
	msgbox PansionLabor_Text_OldManThanks, MSGBOX_DEFAULT

	@ Prüfe ob Platz für Ei
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, PARTY_SIZE, PansionLabor_EventScript_NoRoomForEgg

	@ EI ÜBERGABE!
	message PansionLabor_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress

	@ Gib Ei!
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG

	msgbox PansionLabor_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT

	@ Quest abgeschlossen!
	setflag FLAG_DEFEATED_DAYCARE_KIDNAPPER

	@ Old Man verlässt das Labor
	msgbox PansionLabor_Text_OldManLeaving, MSGBOX_DEFAULT
	closemessage

	@ SPIELER BEWEGT SICH AUS DEM WEG
	applymovement OBJ_EVENT_ID_PLAYER, PansionLabor_Movement_PlayerMakeSpace
	waitmovement OBJ_EVENT_ID_PLAYER

	delay 5

	@ OLD MAN LÄUFT LOS
	applymovement LOCALID_OLD_MAN, PansionLabor_Movement_OldManLeave

	@ Warte bis Old Man 2 Schritte gemacht hat, dann Spieler nach unten schauen
	delay 16
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown

	@ Warte bis Old Man KOMPLETT fertig ist!
	waitmovement LOCALID_OLD_MAN

	@ Erst JETZT verschwindet er!
	playse SE_EXIT
	removeobject LOCALID_OLD_MAN

	@ Quest KOMPLETT abgeschlossen!
	setflag FLAG_DAYCARE_RESCUE_QUEST_COMPLETED
	setflag FLAG_HIDE_PANSION_OLD_MAN
	clearflag FLAG_HIDE_ROUTE117_DAYCARE_MAN

	msgbox PansionLabor_Text_OldManGone, MSGBOX_DEFAULT
	release
	end

PansionLabor_EventScript_NoRoomForEgg::
	msgbox PansionLabor_Text_NoRoomForEgg, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DAYCARE_KIDNAPPER
	release
	end

PansionLabor_EventScript_AlreadyDefeated:
	msgbox PansionLabor_Text_JamesGone, MSGBOX_DEFAULT
	release
	end

@ James nach Reveal (sollte nie erreicht werden)
PansionLabor_EventScript_JamesAfterReveal::
	lock
	faceplayer
	msgbox PansionLabor_Text_JamesStillHere, MSGBOX_DEFAULT
	release
	end

@ Alter Mann (gefangen im Käfig oben)
PansionLabor_EventScript_OldMan::
	lock
	faceplayer
	goto_if_unset FLAG_DEFEATED_DAYCARE_KIDNAPPER, PansionLabor_EventScript_OldManCaptive
	msgbox PansionLabor_Text_OldManAfterRescue, MSGBOX_DEFAULT
	release
	end

PansionLabor_EventScript_OldManCaptive:
	msgbox PansionLabor_Text_OldManCaptive, MSGBOX_DEFAULT
	release
	end

@ Spieler macht Platz
PansionLabor_Movement_PlayerMakeSpace:
	walk_down
	walk_right
	face_left
	step_end

@ Old Man verlässt Labor
PansionLabor_Movement_OldManLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PansionLabor_EventScript_StolenEgg::
	lock
	msgbox PansionLabor_Text_StolenEgg, MSGBOX_DEFAULT
	release
	end

@ ============ SIGN ============

PansionLabor_Eventscript_Sign_Plan::
	lockall
	msgbox PansionLabor_Text_Sign_Plan, MSGBOX_DEFAULT
	releaseall
	end

PansionLabor_Eventscript_Sign_Mischung::
	lockall
	msgbox PansionLabor_Text_Sign_Mischung, MSGBOX_DEFAULT
	releaseall
	end

PansionLabor_Eventscript_Sign_Waschmaschine::
	lockall
	msgbox PansionLabor_Text_Sign_Waschmaschine, MSGBOX_DEFAULT
	releaseall
	end

@ ============ TEXTE ============

PansionLabor_Text_DisguisedIntro:
	.string "Oh… du hast dieses geheime Labor\n"
	.string "gefunden.\p"
	.string "Ich dachte, niemand würde hierher\n"
	.string "kommen…\p"
	.string "Dann muss ich wohl meine wahre\n"
	.string "Identität enthüllen!$"

PansionLabor_Text_JamesReveal:
	.string "JAMES: Überraschung!\p"
	.string "Ich bin JAMES von TEAM ROCKET!$"

PansionLabor_Text_TeamRocketPlan:
	.string "JAMES: Hehehe… Du bist zu spät!\p"
	.string "Ich habe das Pokémon-EI aus der\n"
	.string "PENSION gestohlen!\p"
	.string "Mit seiner Lebensenergie werde ich\n"
	.string "diese ROTOM-GERÄTE zum Leben erwecken!\p"
	.string "Ein Super-ROTOM wird mir gehören!\p"
	.string "Aber zuerst… musst du mich besiegen!$"

PansionLabor_Text_JamesDefeat:
	.string "Was?! Unmöglich!$"

PansionLabor_Text_JamesAfterDefeat:
	.string "JAMES: Argh! Schon wieder verloren!\p"
	.string "Mein Plan mit den ROTOM ist ruiniert!\p"
	.string "Aber das ist noch nicht vorbei!\n"
	.string "TEAM ROCKET kommt wieder!\p"
	.string "Bis dann, Twerp!$"

PansionLabor_Text_JamesStillHere:
	.string "JAMES: Verschwinde schon!$"

PansionLabor_Text_JamesGone:
	.string "JAMES ist verschwunden…$"

PansionLabor_Text_OldManCaptive:
	.string "PENSIONSLEITER: Hilfe!\n"
	.string "Dieser TEAM ROCKET Kerl hält mich\l"
	.string "gefangen!\p"
	.string "Er hat dein EI gestohlen und will die\n"
	.string "Lebensenergie daraus nutzen!\p"
	.string "Bitte, rette mich und das EI!$"

PansionLabor_Text_OldManThanks:
	.string "PENSIONSLEITER: Oh, vielen Dank!\n"
	.string "Du hast mich gerettet!\p"
	.string "Dieser JAMES von TEAM ROCKET wollte\n"
	.string "die Energie aus deinem Pokémon-EI\l"
	.string "stehlen!\p"
	.string "Er wollte damit diese seltsamen\n"
	.string "ROTOM-GERÄTE erwecken…\p"
	.string "Zum Glück hast du ihn aufgehalten!\p"
	.string "Hier, nimm dein EI zurück!$"

PansionLabor_Text_ReceivedEgg:
	.string "{PLAYER} erhält das EI vom\n"
	.string "PENSIONSLEITER zurück!$"

PansionLabor_Text_TakeGoodCareOfIt:
	.string "PENSIONSLEITER: Kümmere dich gut\n"
	.string "darum!\p"
	.string "Es ist zum Glück noch völlig in\n"
	.string "Ordnung!$"

PansionLabor_Text_NoRoomForEgg:
	.string "PENSIONSLEITER: Oh nein!\n"
	.string "Du hast keinen Platz für das EI!\p"
	.string "Schaffe erst Platz in deinem Team,\n"
	.string "dann komme zurück!$"

PansionLabor_Text_OldManLeaving:
	.string "PENSIONSLEITER: Ich muss jetzt zurück\n"
	.string "zur PENSION!\p"
	.string "Meine Frau macht sich bestimmt Sorgen!\p"
	.string "Danke nochmal für deine Hilfe!$"

PansionLabor_Text_OldManGone:
	.string "Der PENSIONSLEITER ist zur PENSION\n"
	.string "auf ROUTE 117 zurückgekehrt.$"

PansionLabor_Text_OldManAfterRescue:
	.string "PENSIONSLEITER: Danke für die Rettung!\n"
	.string "Komm zur PENSION!$"

PansionLabor_Text_StolenEgg:
	.string "Ein gestohlenes Pokémon-EI!\p"
	.string "TEAM ROCKET wollte seine Energie\n"
	.string "für ihre Experimente nutzen…$"

PansionLabor_Text_Sign_Plan:
	.string "Hier liegt eine Zeichnung von\n"
	.string "einem seltsamen Reaktor.\p"
	.string "Es sieht aber viel größer aus als\n"
	.string "die, die hier stehen…$"

PansionLabor_Text_Sign_Mischung:
	.string "Es sieht sehr Dickflüssig aus…\p"
	.string "Da sind auch Stücke von Pokémon-\n"
	.string "Eiern drin…$"

PansionLabor_Text_Sign_Waschmaschine:
	.string "Eine Maschine?\p"
	.string "Es strahlt aber sehr starke Pokémon-\n"
	.string "Energie aus…$"

