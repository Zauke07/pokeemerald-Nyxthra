@ Nyxthra: Rocket-Labor unter der Rosalhöhle - Jessie und der NYX-RESONATOR.
@ Story: Team Rocket versucht, mit Kristallen aus der Ader unter Rosaltstadt
@ künstlich Nyxthra-Formen zu erzeugen. Nebenwirkung: die "Herzsperre"
@ verschließt die Herzen der Pokémon (Vorbote der Crypto-Pokémon aus ORRE).
Rosalhoehle_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Rosalhoehle_B2F_OnTransition
	.byte 0

Rosalhoehle_B2F_OnTransition:
	call_if_set FLAG_DEFEATED_ROSAL_JESSIE, Rosalhoehle_B2F_EventScript_DisableJessieTrigger
	end

Rosalhoehle_B2F_EventScript_DisableJessieTrigger::
	setvar VAR_TEMP_1, 1
	return

Rosalhoehle_B2F_EventScript_Rocket4::
	trainerbattle_single TRAINER_ROSAL_ROCKET_4, Rosalhoehle_B2F_Text_Rocket4Intro, Rosalhoehle_B2F_Text_Rocket4Defeat
	msgbox Rosalhoehle_B2F_Text_Rocket4After, MSGBOX_AUTOCLOSE
	end

Rosalhoehle_B2F_EventScript_Rocket5::
	trainerbattle_single TRAINER_ROSAL_ROCKET_5, Rosalhoehle_B2F_Text_Rocket5Intro, Rosalhoehle_B2F_Text_Rocket5Defeat
	msgbox Rosalhoehle_B2F_Text_Rocket5After, MSGBOX_AUTOCLOSE
	end

Rosalhoehle_B2F_EventScript_Jessie::
	lockall
	faceplayer
	goto Rosalhoehle_B2F_EventScript_JessieScene

Rosalhoehle_B2F_EventScript_JessieTrigger::
	lockall
	playse SE_PIN
	applymovement LOCALID_ROSAL_JESSIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_ROSAL_JESSIE, Rosalhoehle_B2F_Movement_JessieApproach
	waitmovement 0
	getplayerxy VAR_0x8004, VAR_0x8005
	setvar VAR_0x8006, 13
	call Rosalhoehle_B2F_EventScript_JessieLineUp
	applymovement LOCALID_ROSAL_JESSIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
Rosalhoehle_B2F_EventScript_JessieScene::
	playbgm MUS_HG_ENCOUNTER_ROCKET, FALSE
	msgbox Rosalhoehle_B2F_Text_JessieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ROSAL_JESSIE, Rosalhoehle_B2F_Text_JessieDefeat
	msgbox Rosalhoehle_B2F_Text_JessieAfter, MSGBOX_DEFAULT
	closemessage
	playse SE_M_REFLECT
	fadescreenspeed FADE_TO_WHITE, 4
	removeobject LOCALID_ROSAL_JESSIE
	setflag FLAG_HIDE_ROSAL_JESSIE
	setflag FLAG_DEFEATED_ROSAL_JESSIE
	setvar VAR_TEMP_1, 1
	setvar VAR_ROCKET_STATE, 2
	fadescreenspeed FADE_FROM_WHITE, 4
	delay 30
	msgbox Rosalhoehle_B2F_Text_ResonatorSilent, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	applymovement LOCALID_ROSAL_CAGED_PIKACHU, Common_Movement_ExclamationMark
	applymovement LOCALID_ROSAL_CAGED_ABSOL, Common_Movement_ExclamationMark
	waitmoncry
	waitmovement 0
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ROSAL_CAGED_PIKACHU
	removeobject LOCALID_ROSAL_CAGED_ABSOL
	setflag FLAG_HIDE_ROSAL_CAGED_MONS
	fadescreen FADE_FROM_BLACK
	msgbox Rosalhoehle_B2F_Text_MonsFled, MSGBOX_DEFAULT
	releaseall
	end

@ JESSIE geht in Reihe 9 genau über den Spieler (der in Reihe 10 steht).
Rosalhoehle_B2F_EventScript_JessieLineUp::
	goto_if_eq VAR_0x8006, VAR_0x8004, Common_EventScript_NopReturn
	call_if_gt VAR_0x8006, VAR_0x8004, Rosalhoehle_B2F_EventScript_JessieStepLeft
	call_if_lt VAR_0x8006, VAR_0x8004, Rosalhoehle_B2F_EventScript_JessieStepRight
	goto Rosalhoehle_B2F_EventScript_JessieLineUp

Rosalhoehle_B2F_EventScript_JessieStepLeft::
	applymovement LOCALID_ROSAL_JESSIE, Common_Movement_WalkLeft
	waitmovement 0
	subvar VAR_0x8006, 1
	return

Rosalhoehle_B2F_EventScript_JessieStepRight::
	applymovement LOCALID_ROSAL_JESSIE, Common_Movement_WalkRight
	waitmovement 0
	addvar VAR_0x8006, 1
	return

Rosalhoehle_B2F_Movement_JessieApproach:
	walk_down
	walk_down
	step_end

Rosalhoehle_B2F_EventScript_Scientist::
	lock
	faceplayer
	goto_if_set FLAG_ROSAL_GOT_TM06, Rosalhoehle_B2F_EventScript_ScientistDone
	goto_if_set FLAG_DEFEATED_ROSAL_JESSIE, Rosalhoehle_B2F_EventScript_ScientistReward
	msgbox Rosalhoehle_B2F_Text_ScientistScared, MSGBOX_DEFAULT
	release
	end

Rosalhoehle_B2F_EventScript_ScientistReward::
	msgbox Rosalhoehle_B2F_Text_ScientistThanks, MSGBOX_DEFAULT
	giveitem ITEM_TM06
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_ROSAL_GOT_TM06
	msgbox Rosalhoehle_B2F_Text_ScientistAfterReward, MSGBOX_DEFAULT
	release
	end

Rosalhoehle_B2F_EventScript_ScientistDone::
	msgbox Rosalhoehle_B2F_Text_ScientistAfterReward, MSGBOX_DEFAULT
	release
	end

Rosalhoehle_B2F_EventScript_CagedPikachu::
	lock
	faceplayer
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox Rosalhoehle_B2F_Text_CagedPikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Rosalhoehle_B2F_EventScript_CagedAbsol::
	lock
	playmoncry SPECIES_ABSOL, CRY_MODE_WEAK
	msgbox Rosalhoehle_B2F_Text_CagedAbsol, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Rosalhoehle_B2F_EventScript_Resonator::
	goto_if_set FLAG_DEFEATED_ROSAL_JESSIE, Rosalhoehle_B2F_EventScript_ResonatorOff
	msgbox Rosalhoehle_B2F_Text_Resonator, MSGBOX_SIGN
	end

Rosalhoehle_B2F_EventScript_ResonatorOff::
	msgbox Rosalhoehle_B2F_Text_ResonatorOff, MSGBOX_SIGN
	end

Rosalhoehle_B2F_EventScript_Report::
	msgbox Rosalhoehle_B2F_Text_Report, MSGBOX_SIGN
	end

Rosalhoehle_B2F_EventScript_Monitors::
	msgbox Rosalhoehle_B2F_Text_Monitors, MSGBOX_SIGN
	end

Rosalhoehle_B2F_EventScript_CrystalTanks::
	msgbox Rosalhoehle_B2F_Text_CrystalTanks, MSGBOX_SIGN
	end

Rosalhoehle_B2F_EventScript_Console::
	msgbox Rosalhoehle_B2F_Text_Console, MSGBOX_SIGN
	end

Rosalhoehle_B2F_Text_Rocket4Intro:
	.string "Das Labor ist streng geheim!\n"
	.string "Hier kommt niemand durch!$"

Rosalhoehle_B2F_Text_Rocket4Defeat:
	.string "Nicht zu fassen!$"

Rosalhoehle_B2F_Text_Rocket4After:
	.string "Die Messdaten schicken wir an einen\n"
	.string "Partner weit weg… in ORRE.\p"
	.string "Die wissen angeblich, wie man das\n"
	.string "Herz eines Pokémon versiegelt.$"

Rosalhoehle_B2F_Text_Rocket5Intro:
	.string "Du willst zu JESSIE?\n"
	.string "Erst musst du an mir vorbei!$"

Rosalhoehle_B2F_Text_Rocket5Defeat:
	.string "Mein KRAMURX… nein, warte, das war\n"
	.string "mein SMOGON… egal, verloren!$"

Rosalhoehle_B2F_Text_Rocket5After:
	.string "JAMES hat das große Modell geplant.\n"
	.string "Dieses hier ist nur der Prototyp.$"

Rosalhoehle_B2F_Text_JessieIntro:
	.string "JESSIE: Na sieh mal einer an!\n"
	.string "Eine kleine Ratte im Labor!\p"
	.string "Du bist also das Gör, das JAMES\n"
	.string "auf ROUTE 117 so blamiert hat.\p"
	.string "Bist du gekommen, um meinen\n"
	.string "NYX-RESONATOR zu bewundern?\p"
	.string "Mit den Kristallen aus dieser Höhle\n"
	.string "erschaffen wir NYXTHRA-Formen -\l"
	.string "ganz nach unseren Wünschen!\p"
	.string "Und der Boss wird mich dafür\n"
	.string "endlich befördern!\p"
	.string "“Um die Welt vor dem Frieden…”\n"
	.string "Ach, ohne JAMES klingt das nur\l"
	.string "halb so gut!\p"
	.string "Dann eben kurz und schmerzhaft:\n"
	.string "ARBOK, VIPITIS - zeigt es dem Gör!$"

Rosalhoehle_B2F_Text_JessieDefeat:
	.string "Unmöglich! Meine wunderschönen\n"
	.string "Pokémon… gegen so ein Kind?!$"

Rosalhoehle_B2F_Text_JessieAfter:
	.string "JESSIE: Das wirst du bereuen!\p"
	.string "Die Daten sind längst in ORRE.\n"
	.string "Der Resonator war nur der Anfang!\p"
	.string "Bald gibt es Pokémon, die keine\n"
	.string "Gefühle mehr kennen - nur Befehle!\p"
	.string "Team ROCKET verschwindet mal\n"
	.string "wieder… aber nur fürs Erste!$"

Rosalhoehle_B2F_Text_ResonatorSilent:
	.string "Das Summen des NYX-RESONATORS\n"
	.string "verstummt…\p"
	.string "Die Käfigtür springt mit einem\n"
	.string "Klicken auf!$"

Rosalhoehle_B2F_Text_MonsFled:
	.string "Die gefangenen Pokémon sind in die\n"
	.string "Tiefen der Höhle geflohen.\p"
	.string "Sie wirken erleichtert…\n"
	.string "aber ihr Blick war seltsam kalt.$"

Rosalhoehle_B2F_Text_ScientistScared:
	.string "Ich… ich bin nur Forscher!\n"
	.string "JESSIE zwingt mich, hier zu arbeiten!\p"
	.string "Bitte, halte sie auf, bevor der\n"
	.string "Resonator noch mehr Pokémon\l"
	.string "kaputt macht!$"

Rosalhoehle_B2F_Text_ScientistThanks:
	.string "Du hast JESSIE vertrieben!\n"
	.string "Danke, wirklich!\p"
	.string "Nimm das hier. Team ROCKET hat es\n"
	.string "für ihre Versuche benutzt -\l"
	.string "bei dir ist es besser aufgehoben.$"

Rosalhoehle_B2F_Text_ScientistAfterReward:
	.string "Die Kristalle haben die Pokémon\n"
	.string "verändert, aber ihre Herzen wurden\l"
	.string "dabei immer dunkler.\p"
	.string "Team ROCKET nennt das\n"
	.string "“Herzsperre”…\p"
	.string "Ich werde MR. TRUMM von der DEVON\n"
	.string "CORPORATION alles berichten.$"

Rosalhoehle_B2F_Text_CagedPikachu:
	.string "PIKACHU: Pika…\p"
	.string "Sein Fell schimmert in einer\n"
	.string "seltsamen Farbe.$"

Rosalhoehle_B2F_Text_CagedAbsol:
	.string "ABSOL starrt ins Leere.\n"
	.string "Es reagiert kaum auf dich…$"

Rosalhoehle_B2F_Text_Resonator:
	.string "NYX-RESONATOR - PROTOTYP 03\p"
	.string "Das Gerät summt laut. In der Kammer\n"
	.string "pulsiert ein violetter Kristall.$"

Rosalhoehle_B2F_Text_ResonatorOff:
	.string "NYX-RESONATOR - PROTOTYP 03\p"
	.string "Das Gerät ist abgeschaltet.\n"
	.string "Der Kristall glimmt nur noch schwach.$"

Rosalhoehle_B2F_Text_Report:
	.string "Ein Bericht liegt auf dem Tisch:\p"
	.string "“Farbwechsel bei Testobjekten:\n"
	.string "3 % stabil.\p"
	.string "Nebenwirkung: Herzsperre aktiv.\n"
	.string "Objekte gehorchen, zeigen aber\l"
	.string "keine Emotionen mehr.\p"
	.string "Daten an Partner in ORRE senden.”$"

Rosalhoehle_B2F_Text_Monitors:
	.string "Auf den Bildschirmen laufen\n"
	.string "Messkurven: RESONANZ, PULS, HERZ…\p"
	.string "Die Kurve “HERZ” fällt\n"
	.string "immer weiter ab.$"

Rosalhoehle_B2F_Text_CrystalTanks:
	.string "In den Tanks schwimmen Splitter\n"
	.string "aus violettem NYX-KRISTALL.$"

Rosalhoehle_B2F_Text_Console:
	.string "Eine Steuerkonsole.\n"
	.string "“ENERGIE-ZUFUHR: RESONATOR”\p"
	.string "Ohne Passwort lässt sich hier\n"
	.string "nichts bedienen.$"
