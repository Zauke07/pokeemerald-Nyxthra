JaggedPass_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, JaggedPass_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, JaggedPass_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, JaggedPass_OnLoad
	.byte 0

JaggedPass_OnResume:
	setstepcallback STEP_CB_ASH
	call_if_eq VAR_JAGGED_PASS_STATE, 0, JaggedPass_EventScript_CheckHasMagmaEmblem
	end

JaggedPass_EventScript_CheckHasMagmaEmblem::
	checkitem ITEM_MAGMA_EMBLEM
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_SetReadyToOpenHideout
	return

JaggedPass_EventScript_SetReadyToOpenHideout::
	setvar VAR_JAGGED_PASS_STATE, 1
	return

JaggedPass_OnTransition:
	call_if_eq VAR_JAGGED_PASS_ASH_WEATHER, 1, JaggedPass_EventScript_SetWeatherAsh
	end

JaggedPass_EventScript_SetWeatherAsh::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	return

JaggedPass_OnLoad:
	goto_if_le VAR_JAGGED_PASS_STATE, 1, JaggedPass_EventScript_ConcealHideoutEntrance
	end

JaggedPass_EventScript_ConcealHideoutEntrance::
	setmetatile 16, 17, METATILE_Lavaridge_RockWall, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_RockWall, TRUE
	end

JaggedPass_EventScript_OpenMagmaHideout::
	lockall
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	msgbox JaggedPass_Text_BoulderShakingInResponseToEmblem, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1   @ vertical pan
	setvar VAR_0x8005, 1   @ horizontal pan
	setvar VAR_0x8006, 16  @ num shakes
	setvar VAR_0x8007, 3   @ shake delay
	special ShakeCamera
	waitstate
	playse SE_EFFECTIVE
	setmetatile 16, 17, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 16, 18, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	special DrawWholeMapView
	delay 30
	setvar VAR_JAGGED_PASS_STATE, 2
	waitse
	releaseall
	end

JaggedPass_EventScript_MagmaHideoutGuard::
	lockall
	goto_if_set FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS, JaggedPass_EventScript_GuardDefeated
	waitse
	playse SE_PIN
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_JAGGED_PASS, JaggedPass_Text_GruntDefeat
	setflag FLAG_BEAT_MAGMA_GRUNT_JAGGED_PASS
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_GuardDefeated::
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox JaggedPass_Text_GoWhereverYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_HIDEOUT_GUARD, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

JaggedPass_EventScript_Eric::
	trainerbattle_single TRAINER_ERIC, JaggedPass_Text_EricIntro, JaggedPass_Text_EricDefeat
	msgbox JaggedPass_Text_EricPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA_1, JaggedPass_Text_DianaIntro, JaggedPass_Text_DianaDefeat, JaggedPass_EventScript_RegisterDiana
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_DianaRematch
	msgbox JaggedPass_Text_DianaPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterDiana::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_DianaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DIANA_1
	release
	end

JaggedPass_EventScript_DianaRematch::
	trainerbattle_rematch TRAINER_DIANA_1, JaggedPass_Text_DianaRematchIntro, JaggedPass_Text_DianaRematchDefeat
	msgbox JaggedPass_Text_DianaPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN_1, JaggedPass_Text_EthanIntro, JaggedPass_Text_EthanDefeat, JaggedPass_EventScript_RegisterEthan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, JaggedPass_EventScript_EthanRematch
	msgbox JaggedPass_Text_EthanPostBattle, MSGBOX_DEFAULT
	release
	end

JaggedPass_EventScript_RegisterEthan::
	special PlayerFaceTrainerAfterBattle
	msgbox JaggedPass_Text_EthanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ETHAN_1
	release
	end

JaggedPass_EventScript_EthanRematch::
	trainerbattle_rematch TRAINER_ETHAN_1, JaggedPass_Text_EthanRematchIntro, JaggedPass_Text_EthanRematchDefeat
	msgbox JaggedPass_Text_EthanPostRematch, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Julio::
	trainerbattle_single TRAINER_JULIO, JaggedPass_Text_JulioIntro, JaggedPass_Text_JulioDefeat
	msgbox JaggedPass_Text_JulioPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_EventScript_Autumn::
	trainerbattle_single TRAINER_AUTUMN, JaggedPass_Text_AutumnIntro, JaggedPass_Text_AutumnDefeat
	msgbox JaggedPass_Text_AutumnPostBattle, MSGBOX_AUTOCLOSE
	end

JaggedPass_Text_EricIntro::
	.string "Der STEILPASS am SCHLOTBERG…\p"
	.string "Endlich ein Berg, der einen so richtig\n"
	.string "fertigmacht!\p"
	.string "Dieses ganze kantige Zeug hier…\n"
	.string "Das kickt mich so richtig hart!$"

JaggedPass_Text_EricDefeat::
	.string "Verlieren macht mich echt sauer!$"

JaggedPass_Text_EricPostBattle::
	.string "Ja, okay, im Kämpfen hast du mich\n"
	.string "abgezogen…\p"
	.string "Aber wenn’s darum geht, wie man sich\n"
	.string "an Steinen die Knie aufschlägt, macht\l"
	.string "mir keiner was vor!$"

JaggedPass_Text_DianaIntro::
	.string "Das hier ist kein Sonntagsspaziergang.\n"
	.string "Pack dein Picknick wieder ein und\l"
	.string "verpiss dich nach Hause!$"

JaggedPass_Text_DianaDefeat::
	.string "Ohhh, nein!\n"
	.string "Dieser Boden ist verfluchter Abfall!$"

JaggedPass_Text_DianaPostBattle::
	.string "Wusstest du das?\p"
	.string "Es gibt so ein paar Verrückte, die mit\n"
	.string "ihren Drahteseln diesen unmöglichen\l"
	.string "Pass hochbrettern. Geisteskrank!$"

JaggedPass_Text_DianaRegister::
	.string "Willst du hier wirklich nochmal her?\n"
	.string "Falls du dich wieder herwagst, klatsch\l"
	.string "ich dich weg!$"

JaggedPass_Text_DianaRematchIntro::
	.string "Picknicks sind was für Pussys.\n"
	.string "POKéMON-Kämpfe sind das Wahre!$"

JaggedPass_Text_DianaRematchDefeat::
	.string "Ich hab nur verloren, weil ich über\n"
	.string "einen Stein gestolpert bin!$"

JaggedPass_Text_DianaPostRematch::
	.string "Scheiß aufs Verlieren. Ich genieß jetzt\n"
	.string "einfach diesen harten Aufstieg.$"

JaggedPass_Text_EthanIntro::
	.string "Der STEILPASS ist die Hölle zum Laufen.\n"
	.string "Perfekt, um Weicheier auszusortieren.$"

JaggedPass_Text_EthanDefeat::
	.string "Es war vorbei, bevor ich überhaupt\n"
	.string "festen Boden unter den Füßen hatte…$"

JaggedPass_Text_EthanPostBattle::
	.string "Wenn ich ein KUNSTRAD hätte, würde ich\n"
	.string "über diese Abgründe einfach drüber-\l"
	.string "hüpfen und über dich lachen.$"

JaggedPass_Text_EthanRegister::
	.string "Wenn ich gelernt hab, auf diesem Dreck\n"
	.string "zu stehen, mach ich dich fertig!\p"
	.string "Lass mal POKéNAV-Daten rüberwachsen.$"

JaggedPass_Text_EthanRematchIntro::
	.string "Ich hab mich an den Schmerz gewöhnt.\n"
	.string "Ich lach jetzt beim Klettern!$"

JaggedPass_Text_EthanRematchDefeat::
	.string "Es ist immer noch ein Drecksboden zum\n"
	.string "Kämpfen…$"

JaggedPass_Text_EthanPostRematch::
	.string "Ich sollte mir bei RADLA in MALVENFROH\n"
	.string "endlich ein KUNSTRAD holen…$"

JaggedPass_Text_GruntIntro::
	.string "Wah!\n"
	.string "Was lungerst du hier rum?\p"
	.string "Was ich hier mache?\p"
	.string "Geht dich einen feuchten Dreck an,\n"
	.string "du Schnüffler!$"

JaggedPass_Text_GruntDefeat::
	.string "Urrrgh…\p"
	.string "Ich hätte sofort in unser VERSTECK\n"
	.string "verschwinden sollen…$"

JaggedPass_Text_GoWhereverYouWant::
	.string "Okay, okay!\n"
	.string "Du bist ja schon gut, Mann!\p"
	.string "Vergiss einfach, dass du mich gesehen hast.\n"
	.string "Zisch ab, wo immer du willst!$"

JaggedPass_Text_BoulderShakingInResponseToEmblem::
	.string "Oh! Dieser Klunker vibriert, weil das\n"
	.string "MAGMA-EMBLEM in der Nähe ist!$"

JaggedPass_Text_JulioIntro::
	.string "Aiyeeh! Es ist so verdammt gruselig,\n"
	.string "hier den Berg runterzuballern!$"

JaggedPass_Text_JulioDefeat::
	.string "Ich fühl mich, als wär ich zerbrochen…$"

JaggedPass_Text_JulioPostBattle::
	.string "Mein RAD ist so rumgehüpft, dass mir\n"
	.string "jetzt der Arsch wehtut…$"

JaggedPass_Text_AutumnIntro::
	.string "Ich kletter hier jeden Tag hoch.\n"
	.string "Meine Waden sind härter als Stein!$"

JaggedPass_Text_AutumnDefeat::
	.string "Hmm…\n"
	.string "Was ist da schiefgelaufen?$"

JaggedPass_Text_AutumnPostBattle::
	.string "Was ist das eigentlich für ein hässlicher\n"
	.string "Felsbrocken da oben am Hügel?$"

