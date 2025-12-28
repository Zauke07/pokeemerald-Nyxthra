MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_CHIMNEY_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_CHIMNEY_MAXIE
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_1
	removeobject LOCALID_MT_CHIMNEY_TABITHA
	removeobject LOCALID_MT_CHIMNEY_MAGMA_GRUNT_2
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_MAGMA
	fadescreenswapbuffers FADE_FROM_BLACK
	setobjectxyperm LOCALID_MT_CHIMNEY_ARCHIE, 10, 12
	addobject LOCALID_MT_CHIMNEY_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_MT_CHIMNEY_ARCHIE
	setflag FLAG_HIDE_MT_CHIMNEY_TEAM_AQUA
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_HIDE_FALLARBOR_HOUSE_PROF_COZMO
	setflag FLAG_HIDE_METEOR_FALLS_1F_1R_COZMO
	clearflag FLAG_HIDE_MT_CHIMNEY_LAVA_COOKIE_LADY
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_MT_CHIMNEY_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
.if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_OFF
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end
.else
	hidemoneybox
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end
.endif @ OW_SHOW_ITEM_DESCRIPTIONS


MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_2, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_CHIMNEY_1, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano::
	.string "Die Power in diesem METEORITEN…\p"
	.string "Wenn diese Maschine den Saft erst mal\n"
	.string "hochpumpt, wird der Schlotberg sofort\l"
	.string "explodieren…\p"
	.string "Die Hitze wird alles Leben im Krater\n"
	.string "einfach wegschmelzen und…\l"
	.string "Fufufu… Alles wird zu Land!$"

MtChimney_Text_MaxieIntro::
	.string "MARC: Hm?\n"
	.string "Welcher Wurm wagt es, mich zu stören?\p"
	.string "… … … … … …\p"
	.string "Ach, jetzt erkenne ich dich.\n"
	.string "ADRIAN hat sich schon über ein Balg\l"
	.string "ausgeheult, das TEAM AQUA ständig\l"
	.string "auf den Sack geht.\p"
	.string "Du musst dieser nervige Winzling sein.\p"
	.string "Glaubst du echt, du kannst dich mit\n"
	.string "TEAM MAGMA anlegen?\p"
	.string "Hör mal zu: Land ist alles!\n"
	.string "Wasser ist nur Platzverschwendung!\p"
	.string "Wir werden Hoenn endlich zu einem\n"
	.string "ordentlichen Kontinent machen.\p"
	.string "Mehr Platz für Menschen, mehr Platz\n"
	.string "für POKéMON! Wer braucht schon Fische?\p"
	.string "Und die Kraft dazu schläft hier drin…\p"
	.string "Eigentlich bist du viel zu unwichtig,\n"
	.string "um das alles zu wissen.\p"
	.string "Egal! Ich zeig dir jetzt mal,\n"
	.string "was passiert, wenn man sich mit\l"
	.string "meinem Masterplan anlegt! Stirb!$"

MtChimney_Text_MaxieDefeat::
	.string "Was zur Hölle?!\p"
	.string "Ich, MARC, wurde von so einem\n"
	.string "Zwerg vorgeführt?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma::
	.string "MARC: Genug jetzt.\n"
	.string "Ich zieh mich erst mal zurück.\p"
	.string "Aber bild dir bloß nichts ein.\n"
	.string "Das war erst der Anfang von TEAM MAGMA.\p"
	.string "Fufufu…\p"
	.string "Selbst ohne METEORIT… wenn wir erst\n"
	.string "diese ROTE KUGEL haben… Fufufu…$"

MtChimney_Text_TabithaIntro::
	.string "Hehehe!\p"
	.string "Bist du den ganzen Weg hochgerannt?\p"
	.string "Pech gehabt! Du bist zu spät!\n"
	.string "Der Boss hat den METEORITEN schon.\l"
	.string "Hoenn wird bald brennen!$"

MtChimney_Text_TabithaDefeat::
	.string "Hehehe…\p"
	.string "Ich hab zwar verloren, aber wenn\n"
	.string "unser Boss erst mal Groudon weckt…$"

MtChimney_Text_TabithaPostBattle::
	.string "BOSS, mach schnell!\n"
	.string "Gib der Maschine den Rest!\p"
	.string "Hehehe… Mach alles platt!$"

MtChimney_Text_Grunt2Intro::
	.string "Wir von TEAM MAGMA tun das alles\n"
	.string "nur für euer Wohl.\p"
	.string "Mehr Land heißt mehr fette Häuser!\n"
	.string "Dann müssen die Leute nicht mehr\l"
	.string "auf dem Wasser rumgammeln!$"

MtChimney_Text_Grunt2Defeat::
	.string "Häh?\n"
	.string "Wieso liege ich im Dreck?$"

MtChimney_Text_Grunt2PostBattle::
	.string "Der Boss sagt immer: “Alle werden\n"
	.string "glücklich sein.”\p"
	.string "Warum wollen uns dann alle ständig\n"
	.string "aufs Maul geben?$"

MtChimney_Text_Grunt1Intro::
	.string "Wenn hier erst mal alles voller Land\n"
	.string "ist, bau ich mir ’ne riesige Villa!\p"
	.string "Mitten auf die erkaltete Lava! Geil!$"

MtChimney_Text_Grunt1Defeat::
	.string "Mein Traumhaus… weg…$"

MtChimney_Text_Grunt1PostBattle::
	.string "Ein Blag wie du sollte lieber am\n"
	.string "Strand Sandburgen bauen gehen!$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans::
	.string "Dieses nervige TEAM AQUA…\n"
	.string "Diese Fischköpfe versauen uns alles!$"

MtChimney_Text_MeteoritesPackAmazingPower::
	.string "Diese Steine aus dem All haben echt\n"
	.string "kranke Power!$"

MtChimney_Text_YouBetterNotMessWithUs::
	.string "Verpiss dich, Kleiner!\p"
	.string "Wir wecken hier gerade ein Gott-\n"
	.string "Monster auf, für’s Gemeinwohl!$"

MtChimney_Text_AquasNameSimilar::
	.string "Wir sind TEAM MAGMA!\p"
	.string "Die sind TEAM AQUA!\p"
	.string "Echt asozial, dass die sich fast\n"
	.string "so nennen wie wir!$"

MtChimney_Text_DouseThemInFire::
	.string "Yeah!\n"
	.string "Fackelt die Fischköpfe ab!$"

MtChimney_Text_KeepMakingMoreLand::
	.string "Wir walzen alles nieder! Land für alle!$"

MtChimney_Text_ArchieGoStopTeamMagma::
	.string "ADRIAN: Grr, {PLAYER}!\n"
	.string "Dass du hier auftauchst, war klar!\p"
	.string "Guck dir diese Irren von TEAM MAGMA\n"
	.string "an! Völlig geisteskrank!\p"
	.string "Die wollen den METEORITEN in den\n"
	.string "Vulkan jagen! Der Berg wird uns\l"
	.string "alle lebendig begraben!$"

MtChimney_Text_ArchieIHaveMyHandsFull::
	.string "ADRIAN: Grrr…\p"
	.string "Ich würde MARC ja gerne selbst\n"
	.string "eine verpassen, aber ich kann nicht!\p"
	.string "Diese feigen Penner greifen mich zu\n"
	.string "dritt an! Hilf mir gefälligst!$"

MtChimney_Text_ArchieThankYou::
	.string "ADRIAN: {PLAYER}!\n"
	.string "Gute Arbeit!\p"
	.string "Zusammen haben wir diesen kranken\n"
	.string "Plan von TEAM MAGMA gestoppt!\p"
	.string "Aber… sag mal…\n"
	.string "Auf welcher Seite stehst du eigentlich?\p"
	.string "Ach, egal.\p"
	.string "Wir werden diese MAGMA-Lappen weiter\n"
	.string "jagen, bis sie im Erdboden versinken.\p"
	.string "{PLAYER}, wir sehen uns! Und dann\n"
	.string "hoffentlich nicht als Feinde.$"

MtChimney_Text_MagmaOutnumbersUs::
	.string "Mist… TEAM MAGMA sind viel zu viele!\n"
	.string "Wir saufen hier fast ab!$"

MtChimney_Text_LessHabitatForWaterPokemon::
	.string "Wenn die noch mehr Land machen, haben\n"
	.string "die Wasser-POKéMON bald keinen Platz\l"
	.string "mehr zum Kacken!$"

MtChimney_Text_MagmasNameSimilar::
	.string "Wir sind TEAM AQUA!\p"
	.string "Die sind TEAM MAGMA!\p"
	.string "Echt zum Kotzen, dass die so einen\n"
	.string "ähnlichen Namen haben!$"

MtChimney_Text_LavaCookiesJust200::
	.string "LAVA-KEKSE sind das einzige Gute hier.\p"
	.string "Nimm einen, kostet nur ¥200.\n"
	.string "Günstiger wird's nicht.$"

MtChimney_Text_ThankYouDear::
	.string "Danke, Schätzchen!$"

MtChimney_Text_YouveNotGotTheMoney::
	.string "Ey, ohne Moos nix los.\n"
	.string "Verpiss dich, wenn du pleite bist.$"

MtChimney_Text_OhFineThen::
	.string "Dann eben nicht. Pech.$"

MtChimney_Text_MetoriteFittedOnMachine::
	.string "Ein METEORIT steckt in dieser\n"
	.string "seltsamen Maschine…\p"
	.string "Das Teil saugt den Stein förmlich leer.$"

MtChimney_Text_RemoveTheMeteorite::
	.string "Da steckt ein METEORIT drin…\n"
	.string "Willst du das Teil einfach klauen?$"

MtChimney_Text_PlayerRemovedMeteorite::
	.string "{PLAYER} hat den METEORITEN einfach\n"
	.string "aus der Maschine gerissen. Zack!$"

MtChimney_Text_PlayerLeftMeteorite::
	.string "{PLAYER} lässt den Stein stecken.\n"
	.string "Soll Hoenn halt brennen.$"

MtChimney_Text_MachineMakesNoResponse::
	.string "Das Ding ist tot.\n"
	.string "Kein Saft mehr drauf.$"

MtChimney_Text_ShelbyIntro::
	.string "Ich war gerade in den heißen Quellen\n"
	.string "meine alten Knochen einweichen.\l"
	.string "Jetzt bin ich bereit, dich zu zerlegen!$"

MtChimney_Text_ShelbyDefeat::
	.string "Ach du grüne Neune!\n"
	.string "Du bist ja ein richtiges Biest!$"

MtChimney_Text_ShelbyPostBattle::
	.string "Na toll, verloren. Ich sollte mich wohl\n"
	.string "lieber wieder in die Wanne setzen.$"

MtChimney_Text_SawyerIntro::
	.string "Geiler Berg! Hier sind nur heiße\n"
	.string "Leute unterwegs!$"

MtChimney_Text_SawyerDefeat::
	.string "Uff, du bist ja brandgefährlich!$"

MtChimney_Text_SawyerPostBattle::
	.string "Ich geh jetzt erst mal mit den Mädels\n"
	.string "in BAD LAVASTADT baden!$"

MtChimney_Text_Bufoh::
	.string "FIFFYEN: Wuff! (Zisch ab!)$"

MtChimney_Text_Bushaa::
	.string "FIFFYEN: Grrrr! (Gleich beiß ich zu!)$"

MtChimney_Text_RouteSign::
	.string "SCHORNSTEINBERG\n"
	.string "Vorsicht: Heiß und staubig!$"

MtChimney_Text_ShelbyRegister::
	.string "SHELBY: Gar nicht mal so schlecht.\n"
	.string "Ich merk mir deine Visage im POKéNAV.$"

MtChimney_Text_ShelbyRematchIntro::
	.string "SHELBY: Ach, du schon wieder.\n"
	.string "Lust auf 'ne weitere Abreibung?$"

MtChimney_Text_ShelbyRematchDefeat::
	.string "SHELBY: Argh! Immer noch so giftig…$"

MtChimney_Text_ShelbyPostRematch::
	.string "SHELBY: Eines Tages schubs ich dich\n"
	.string "noch in den Krater!$"

MtChimney_Text_MelissaIntro::
	.string "MELISSA: Hier oben ist es heiß, aber\n"
	.string "meine Attacken sind noch heißer!$"

MtChimney_Text_MelissaDefeat::
	.string "MELISSA: Verdammt, abgekühlt…$"

MtChimney_Text_MelissaPostBattle::
	.string "MELISSA: Puh, ich brauch erst mal ein\n"
	.string "Eis. Geh mir aus der Sonne.$"

MtChimney_Text_SheilaIntro::
	.string "SHEILA: Du störst mich beim Schwitzen!$"

MtChimney_Text_SheilaDefeat::
	.string "SHEILA: Jetzt schwitz ich vor Wut!$"

MtChimney_Text_SheilaPostBattle::
	.string "SHEILA: Geh woanders nerven!$"

MtChimney_Text_ShirleyIntro::
	.string "SHIRLEY: Mein Feuer-Team fackelt nicht\n"
	.string "lange!$"

MtChimney_Text_ShirleyDefeat::
	.string "SHIRLEY: Nur noch Asche…$"

MtChimney_Text_ShirleyPostBattle::
	.string "SHIRLEY: Vielleicht sollte ich Wasser-\n"
	.string "POKéMON trainieren… ach ne, bäh!$"

MtChimney_Text_SawyerRegister::
	.string "SAWYER: Deine Taktik ist asozial.\n"
	.string "Das gefällt mir. POKéNAV!$"

MtChimney_Text_SawyerRematchIntro::
	.string "SAWYER: Na, bereit für die Revanche?$"

MtChimney_Text_SawyerRematchDefeat::
	.string "SAWYER: Wieder im Staub gelandet…$"

MtChimney_Text_SawyerPostRematch::
	.string "SAWYER: Du bist echt hartnäckig.\n"
	.string "Respekt, du Nervensäge.$"
