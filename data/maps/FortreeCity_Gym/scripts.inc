FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower bc of rotating gates
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_DARIUS, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice::
	.string "Na, wie sieht's aus? Immer noch auf dem\n"
	.string "Trip, CHAMP werden zu wollen, {PLAYER}?\p"
	.string "WIBKE, die Bossin hier, hält sich für die\n"
	.string "Göttin der FLUG-POKéMON.\p"
	.string "Die hockt ganz hinten hinter diesen\n"
	.string "nervigen Drehtüren rum.\p"
	.string "Sie wartet nur darauf, dass wieder ein\n"
	.string "Anfänger eintrudelt, dem sie die Flügel\l"
	.string "stutzen kann!\p"
	.string "Na ja, viel Glück. Wirst es brauchen!$"

FortreeCity_Gym_Text_GymGuidePostVictory::
	.string "Hui, du hast es echt geschafft!\n"
	.string "Startfreigabe für den nächsten Blödsinn!$"

FortreeCity_Gym_Text_JaredIntro::
	.string "Glotz nicht so dumm und bewundere den\n"
	.string "Style meiner VOGEL-POKéMON!$"

FortreeCity_Gym_Text_JaredDefeat::
	.string "Du……\n"
	.string "Du bist ja doch nicht so weich……$"

FortreeCity_Gym_Text_JaredPostBattle::
	.string "Ein TRAINER muss hellwach sein, wenn der\n"
	.string "Wind sich dreht.\p"
	.string "Mal sehen, ob du überhaupt peilst, wie\n"
	.string "du zu unserer Bossin durchkommst.$"

FortreeCity_Gym_Text_EdwardoIntro::
	.string "Jeder Vogel-Fan träumt davon, in diesen\n"
	.string "erlauchten Kreis aufgenommen zu werden.\p"
	.string "Ich als Mitglied dieser Elite-ARENA\n"
	.string "darf gegen so 'ne Laufkundschaft nicht\l"
	.string "verlieren!$"

FortreeCity_Gym_Text_EdwardoDefeat::
	.string "Das war wohl 'ne Nummer zu groß für\n"
	.string "meine kleinen Flügel……$"

FortreeCity_Gym_Text_EdwardoPostBattle::
	.string "Die Welt ist voll mit Typen, die was\n"
	.string "auf dem Kasten haben.\p"
	.string "Ich geh weiter trainieren, bis ich dich\n"
	.string "beim nächsten Mal aus der Luft hole!$"

FortreeCity_Gym_Text_FlintIntro::
	.string "Glaubst du echt, WIBKE hat Zeit für\n"
	.string "so jemanden wie dich?\p"
	.string "Ich reiche völlig aus, um dich wieder\n"
	.string "auf den Boden der Tatsachen zu holen!$"

FortreeCity_Gym_Text_FlintDefeat::
	.string "WIBKE…… Ich……\n"
	.string "Ich hab mich voll blamiert!$"

FortreeCity_Gym_Text_FlintPostBattle::
	.string "WIBKE ist nicht nur heiß, sondern auch\n"
	.string "verdammt gefährlich. Sie ist die Beste!\p"
	.string "Hups…… Laber ich schon wieder? Ich werd\n"
	.string "gar nicht rot! Schnauze!$"

FortreeCity_Gym_Text_AshleyIntro::
	.string "WIBKE hat mich höchstpersönlich\n"
	.string "abgerichtet! Du hast hier null Chance!$"

FortreeCity_Gym_Text_AshleyDefeat::
	.string "Voll abgeschmiert……$"

FortreeCity_Gym_Text_AshleyPostBattle::
	.string "Nur dank WIBKE können die Leute hier\n"
	.string "überhaupt ruhig schlafen.$"

FortreeCity_Gym_Text_HumbertoIntro::
	.string "WIBKE sieht so verdammt gut aus, wenn\n"
	.string "sie jemanden im Kampf fertig macht!\p"
	.string "Ich werd' dafür sorgen, dass du diesen\n"
	.string "Blick aus nächster Nähe siehst!$"

FortreeCity_Gym_Text_HumbertoDefeat::
	.string "Argh!\n"
	.string "Ich konnte dich nicht bremsen!$"

FortreeCity_Gym_Text_HumbertoPostBattle::
	.string "Pass bloß auf! Glotz WIBKE nicht mit\n"
	.string "offenem Mund an, sonst rammt sie dich\l"
	.string "ungespitzt in den Boden!$"

FortreeCity_Gym_Text_DariusIntro::
	.string "Es gibt zig verschiedene FLUG-POKéMON.\p"
	.string "Aber du checkst das eh nicht, oder?$"

FortreeCity_Gym_Text_DariusDefeat::
	.string "Du weißt anscheinend doch, was du tust.$"

FortreeCity_Gym_Text_DariusPostBattle::
	.string "Na gut, du hast mich besiegt. Wayne.\n"
	.string "Gegen WIBKE wirst du sowieso wie ein\l"
	.string "Stein vom Himmel fallen!$"

FortreeCity_Gym_Text_WinonaIntro::
	.string "Ich bin WIBKE. Ich leite diesen Laden hier\n"
	.string "in BAUMHAUSEN CITY.\p"
	.string "Zusammen mit meinen Vögeln habe ich\n"
	.string "Dinge gesehen, von denen du nur träumst.\p"
	.string "Egal wie dreckig der Kampf war, wir\n"
	.string "haben immer mit Stil gewonnen……\p"
	.string "Bewundere jetzt, wie meine POKéMON dich\n"
	.string "mit eleganter Grazie zerfetzen!$"

FortreeCity_Gym_Text_WinonaDefeat::
	.string "Ich hätte nie gedacht, dass jemand\n"
	.string "noch mehr eingebildete Grazie besitzt\l"
	.string "als ich selbst……\p"
	.string "Weil du mich so krass genervt hast,\n"
	.string "kriegst du halt diesen Orden.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge::
	.string "{PLAYER} erhält den FEDERORDEN von\n"
	.string "WIBKE.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis::
	.string "Mit dem FEDERORDEN kuschen alle POKéMON\n"
	.string "bis Lv. 70 vor dir, sogar die getauschten.\p"
	.string "Außerdem kannst du jetzt endlich mit\n"
	.string "FLIEGEN durch die Gegend eiern.\p"
	.string "Und nimm das hier auch noch……\n"
	.string "bevor ich es mir anders überlege.$"

FortreeCity_Gym_Text_ExplainAerialAce::
	.string "In TM40 steckt AERO-ASS.\p"
	.string "Das ist so verdammt schnell……\n"
	.string "Da kommt kein POKéMON mehr mit.\p"
	.string "…… …… …… ……$"

FortreeCity_Gym_Text_RegisteredWinona::
	.string "Die Vögel-Tante WIBKE wurde im POKéNAV\n"
	.string "unter 'Potenzielle Opfer' eingetragen.$"

FortreeCity_Gym_Text_WinonaPostBattle::
	.string "Auch wenn ich gegen dich geloost habe,\n"
	.string "meine Vögel sind trotzdem cooler.$"

FortreeCity_Gym_Text_GymStatue::
	.string "POKéMON ARENA von BAUMHAUSEN CITY$"

FortreeCity_Gym_Text_GymStatueCertified::
	.string "POKéMON ARENA von BAUMHAUSEN CITY\p"
	.string "WIBKES LISTE DER LEUTE, DIE NERVEN:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch::
	.string "WIBKE: Wir Menschen sind eigentlich\n"
	.string "nur Fleischklumpen am Boden.\p"
	.string "Aber weil ich so perfekt bin, kann ich\n"
	.string "trotzdem über alles und jeden lachen!\p"
	.string "Du hältst dich jetzt für den CHAMP.\n"
	.string "Ganz toll gemacht.\p"
	.string "Komm schon, zeig mir, wie du abhebst!\n"
	.string "Oder fällst du gleich wieder hin?$"

FortreeCity_Gym_Text_WinonaRematchDefeat::
	.string "Du fliegst mir definitiv zu hoch……$"

FortreeCity_Gym_Text_WinonaPostRematch::
	.string "WIBKE: Auch wenn ich wieder geloost hab,\n"
	.string "mein Ego bleibt im Himmel.\p"
	.string "Ich werde immer wieder aufsteigen und\n"
	.string "alle von oben herab anschauen!\p"
	.string "Glaub mir ruhig!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons::
	.string "WIBKE: Wir Menschen sind eigentlich\n"
	.string "nur Fleischklumpen am Boden.\p"
	.string "Aber weil ich so perfekt bin, kann ich\n"
	.string "trotzdem über alles lachen!\p"
	.string "Du bist also CHAMP? Super.\p"
	.string "Zeig mir, was du kannst!\p"
	.string "Huch…… Du hast ja nur ein einziges\n"
	.string "POKéMON dabei? Wie armselig.\p"
	.string "Zisch ab und komm mit mindestens zwei\n"
	.string "Viechern wieder, sonst lohnt das nicht.$"
