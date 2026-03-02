Testlabor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Testlabor_OnTransition
	.byte 0

Testlabor_OnTransition:
	call Common_EventScript_SetupRivalGfxId_FromPlayerStyle
	clearflag FLAG_ENCOUNTERED_ENTEI
	clearflag FLAG_ENCOUNTERED_RAIKOU
	clearflag FLAG_ENCOUNTERED_SUICUNE
	return

EventScript_Testlabor_MusicNPC1::
	msgbox gText_PlayMusicChoice, MSGBOX_DEFAULT
	waitbuttonpress
	closemessage
	playmusictest1
	end

EventScript_Testlabor_MusicNPC2::
	msgbox gText_PlayMusicChoice, MSGBOX_DEFAULT
	waitbuttonpress
	closemessage
	playmusictest2
	end

EventScript_Testlabor_MusicNPC3::
	msgbox gText_PlayMusicChoice, MSGBOX_DEFAULT
	waitbuttonpress
	closemessage
	playmusictest3
	end

EventScript_Testlabor_Bed::
	lockall
	msgbox Testlabor_Bed_Text_TakeRest, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	releaseall
	end

EventScript_Testlabor_DebugPlayerStyle::
	lockall
	faceplayer
	getplayerstyle
	copyvar VAR_TEMP_0, VAR_RESULT
	bufferintvar1 VAR_TEMP_0
	msgbox Text_DebugPlayerStyleInfo, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

Testlabor_Bed_Text_TakeRest:
	.string "Digga, deine Mons sehen aus wie'n\n"
	.string "verkehrter Döner bei 30 Grad…\p"
	.string "Wenn Prof. Birk das sieht, zieht er dir\n"
	.string "den Pokédex ab und blockiert dich.\p"
	.string "Leg dich hin, aber mach keinen Mucks.\n"
	.string "Ich hab schon schwächere Trainer gefickt.\p"
	.string "Und wehe du sabberst… das Kissen hat\n"
	.string "mehr Niveau als dein ganzes Team.\p"
	.string "Du bist der Grund, warum Gift-\n"
	.string "Pokémon überhaupt erfunden wurden.\p"
	.string "Selbst Team Rocket würde dich\n"
	.string "aus Mitleid durchwinken.\p"
	.string "Wurdest du vom Bus überfahren oder\n"
	.string "hat dich ’ne Trainerin zerstört?\p"
	.string "Leg dich hin, du Pokémon-Pleite,\n"
	.string "bevor du noch XP verlierst.\p"
	.string "Aber wehe, du pinkelst ins Bett…\n"
	.string "Dann klatsch ich dich höchstpersönlich.$"

Text_DebugPlayerStyleInfo:
	.string "Der aktuelle Spieler-Style-Wert\n"
	.string "ist: {STR_VAR_1}.\p"
	.string "Das sollte dem erwarteten Wert\n"
	.string "STYLE_ entsprechen.$"

Text_DebugNoMatchingStyleBattle:
	.string "Kein passender Style gefunden\n"
	.string "für einen Debug-Kampf. Startet\n"
	.string "Brendan-Kampf.$"


Text_BrendanDebugIntro:
	.string "Ich bin Hans! Lass uns kämpfen!$"

Text_BrendanDebugWin:
	.string "Du bist gut.$"

Text_BrendanDebugAfterWin:
	.string "Das war ein guter Test mit Hans.$"

Text_MayDebugIntro:
	.string "Ich bin Brigitte! Kämpfen wir!$"

Text_MayDebugWin:
	.string "Du bist stark.$"

Text_MayDebugAfterWin:
	.string "Das war ein guter Test mit Brigitte.$"

Text_RedDebugIntro:
	.string "Red: …$"

Text_RedDebugWin:
	.string "Red: …$"

Text_RedDebugAfterWin:
	.string "Das war ein guter Test mit Red.$"

Text_LeafDebugIntro:
	.string "Leaf: Hi!$"

Text_LeafDebugWin:
	.string "Leaf: Oh.$"

Text_LeafDebugAfterWin:
	.string "Das war ein guter Test mit Leaf.$"

Testlabor_EventScript_DebugRivalBattle::
	lockall
	faceplayer
	getplayerstyle
	copyvar VAR_TEMP_0, VAR_RESULT
	bufferintvar1 VAR_TEMP_0
	msgbox Text_DebugPlayerStyleInfo, MSGBOX_DEFAULT
	waitmessage

	compare VAR_TEMP_0, STYLE_BRENDAN
	goto_if_eq Debug_SetRivalGfx_May
	compare VAR_TEMP_0, STYLE_MAY
	goto_if_eq Debug_SetRivalGfx_Brendan
	compare VAR_TEMP_0, STYLE_RED
	goto_if_eq Debug_SetRivalGfx_Leaf
	compare VAR_TEMP_0, STYLE_LEAF
	goto_if_eq Debug_SetRivalGfx_Red

	msgbox Text_DebugNoMatchingStyleBattle, MSGBOX_DEFAULT
	waitmessage
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	goto Debug_StartBattle_Brendan

Debug_SetRivalGfx_May:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	goto Debug_StartBattle_Brendan
Debug_SetRivalGfx_Brendan:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	goto Debug_StartBattle_May
Debug_SetRivalGfx_Leaf:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_LEAF
	goto Debug_StartBattle_Red
Debug_SetRivalGfx_Red:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_RED
	goto Debug_StartBattle_Leaf

Debug_StartBattle_Brendan:
	msgbox Text_BrendanDebugIntro, MSGBOX_DEFAULT
	waitbuttonpress
	closemessage
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	trainerbattle_no_intro TRAINER_BRENDAN_DEBUG, Text_BrendanDebugWin
	msgbox Text_BrendanDebugAfterWin, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

Debug_StartBattle_May:
	msgbox Text_MayDebugIntro, MSGBOX_DEFAULT
	waitbuttonpress
	closemessage
	playbgm MUS_ENCOUNTER_MAY, TRUE
	trainerbattle_no_intro TRAINER_MAY_DEBUG, Text_MayDebugWin
	msgbox Text_MayDebugAfterWin, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

Debug_StartBattle_Red:
	msgbox Text_RedDebugIntro, MSGBOX_DEFAULT
	waitbuttonpress
	closemessage
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	trainerbattle_no_intro TRAINER_RED_DEBUG, Text_RedDebugWin
	msgbox Text_RedDebugAfterWin, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

Debug_StartBattle_Leaf:
	msgbox Text_LeafDebugIntro, MSGBOX_DEFAULT
	waitbuttonpress
	closemessage
	playbgm MUS_ENCOUNTER_MAY, TRUE
	trainerbattle_no_intro TRAINER_LEAF_DEBUG, Text_LeafDebugWin
	msgbox Text_LeafDebugAfterWin, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

Testlabor_EventScript_DebugFollower::
	special ShowFieldMessageFollowerDebug
	waitmessage
	waitbuttonpress
	end

Testlabor_EventScript_ShowTime::
	lockall
	faceplayer
	special BufferClockToStrVars123
	msgbox Testlabor_Text_CurrentTime, MSGBOX_DEFAULT
	waitbuttonpress
	closemessage
	releaseall
	end

Testlabor_Text_CurrentTime::
	.string "{STR_VAR_1}:{STR_VAR_2} Uhr ({STR_VAR_3})$"

Testlabor_Eventscript_Joytest::
	trainerbattle_single TRAINER_OFFICER_ROCKY, Testlabor_Text_RockyIntro, Testlabor_Text_RockyDefeat
	msgbox Testlabor_Text_RockyPost, MSGBOX_AUTOCLOSE
	end

Testlabor_EventScript_NurseJoyTest::
	trainerbattle_single TRAINER_NURSE_JOY, Testlabor_Text_JoyIntro, Testlabor_Text_JoyDefeat
	msgbox Testlabor_Text_JoyPost, MSGBOX_AUTOCLOSE
	end

Testlabor_Text_RockyIntro:
	.string "OFFICER ROCKY: Sicherheitskontrolle!\n"
	.string "Zeig mir deine Stärke, Trainer!$"

Testlabor_Text_RockyDefeat:
	.string "Du hast bestanden. Stark und korrekt.$"

Testlabor_Text_RockyPost:
	.string "Bleib wachsam. In der Wüste gibt es\n"
	.string "mehr als nur Sand.$"

Testlabor_Text_JoyIntro:
	.string "SCHWESTER JOY: Ein kurzer Check!\n"
	.string "Ein Kampf sagt oft mehr als Worte.$"

Testlabor_Text_JoyDefeat:
	.string "Gut gekämpft. Vergiss die Erholung\n"
	.string "deiner Pokémon nicht.$"

Testlabor_Text_JoyPost:
	.string "Heilung ist wichtig, doch Training\n"
	.string "genauso. Pass gut auf sie auf.$"

Testlabor_EventScript_AllHounds_Test::
	lockall
	faceplayer
	msgbox Testlabor_Text_Hundeevent, MSGBOX_DEFAULT
	waitmessage
	closemessage
	@ Entei
	playmoncry SPECIES_ENTEI, CRY_MODE_ENCOUNTER
	waitmoncry
	applymovement LOCALID_ENTEI_TEST, Testlabor_Movement_HopOutOfRock
	waitmovement 0
	applymovement LOCALID_ENTEI_TEST, Testlabor_Movement_HopRightToMiddle
	waitmovement 0
	playmoncry SPECIES_ENTEI, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_ENTEI_TEST, Testlabor_Movement_HopLeftDownAndExit
	waitmovement 0
	removeobject LOCALID_ENTEI_TEST
	setflag FLAG_ENCOUNTERED_ENTEI

	@ Raikou
	playmoncry SPECIES_RAIKOU, CRY_MODE_ENCOUNTER
	waitmoncry
	applymovement LOCALID_RAIKOU_TEST, Testlabor_Movement_HopOutOfRock
	waitmovement 0
	applymovement LOCALID_RAIKOU_TEST, Testlabor_Movement_HopDownMiddle
	waitmovement 0
	playmoncry SPECIES_RAIKOU, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_RAIKOU_TEST, Testlabor_Movement_HopRightDownAndExit
	waitmovement 0
	removeobject LOCALID_RAIKOU_TEST
	setflag FLAG_ENCOUNTERED_RAIKOU

	@ Suicune
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	waitmoncry
	applymovement LOCALID_SUICUNE_TEST, Testlabor_Movement_HopOutOfRock
	waitmovement 0
	applymovement LOCALID_SUICUNE_TEST, Testlabor_Movement_HopLeftToMiddle
	waitmovement 0
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	waitmoncry
	applymovement LOCALID_SUICUNE_TEST, Testlabor_Movement_HopRightDownAndExit
	waitmovement 0
	removeobject LOCALID_SUICUNE_TEST
	setflag FLAG_ENCOUNTERED_SUICUNE

	releaseall
	end

@ ==================================================================
@ NPC Text
@ ==================================================================
Testlabor_Text_Hundeevent:
	.string "Der Test der 3 Hunde beginnt Jetzt.$"

@ ==================================================================
@ Bewegungen der Hunde
@ ==================================================================

Testlabor_Movement_HopOutOfRock::
	jump_2_down
	jump_down
	step_end

Testlabor_Movement_HopRightToMiddle::
	jump_right
	jump_right
	jump_right
	step_end

Testlabor_Movement_HopLeftDownAndExit::
	jump_left
	jump_down
	jump_down
	jump_down
	step_end

Testlabor_Movement_HopDownMiddle::
	jump_down
	jump_down
	jump_down
	step_end

Testlabor_Movement_HopRightDownAndExit::
	jump_right
	jump_down
	jump_down
	jump_down
	step_end

Testlabor_Movement_HopLeftToMiddle::
	jump_left
	jump_left
	jump_left
	step_end

Testlabor_EventScript_Test::
	lockall
	checkflag FLAG_BADGE01_GET
	goto_if_set FLAG_BADGE01_GET, Testlabor_EventScript_Test_CheckNextBadge
	msgbox Testlabor_Text_Test_GiveStoneBadge, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE01_GET
	releaseall
	end

Testlabor_EventScript_Test_CheckNextBadge::
	checkflag FLAG_BADGE02_GET
	goto_if_set FLAG_BADGE02_GET, Testlabor_EventScript_Test_CheckNextBadge2
	msgbox Testlabor_Text_Test_GiveKnuckleBadge, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE02_GET
	releaseall
	end

Testlabor_EventScript_Test_CheckNextBadge2::
	checkflag FLAG_BADGE03_GET
	goto_if_set FLAG_BADGE03_GET, Testlabor_EventScript_Test_CheckNextBadge3
	msgbox Testlabor_Text_Test_GiveDynamoBadge, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE03_GET
	releaseall
	end

Testlabor_EventScript_Test_CheckNextBadge3::
	checkflag FLAG_BADGE04_GET
	goto_if_set FLAG_BADGE04_GET, Testlabor_EventScript_Test_CheckNextBadge4
	msgbox Testlabor_Text_Test_GiveHeatBadge, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE04_GET
	releaseall
	end

Testlabor_EventScript_Test_CheckNextBadge4::
	checkflag FLAG_BADGE05_GET
	goto_if_set FLAG_BADGE05_GET, Testlabor_EventScript_Test_CheckNextBadge5
	msgbox Testlabor_Text_Test_GiveBalanceBadge, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE05_GET
	releaseall
	end

Testlabor_EventScript_Test_CheckNextBadge5::
	checkflag FLAG_BADGE06_GET
	goto_if_set FLAG_BADGE06_GET, Testlabor_EventScript_Test_CheckNextBadge6
	msgbox Testlabor_Text_Test_GiveFeatherBadge, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE06_GET
	releaseall
	end

Testlabor_EventScript_Test_CheckNextBadge6::
	checkflag FLAG_BADGE07_GET
	goto_if_set FLAG_BADGE07_GET, Testlabor_EventScript_Test_CheckNextBadge7
	msgbox Testlabor_Text_Test_GiveMindBadge, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE07_GET
	releaseall
	end

Testlabor_EventScript_Test_CheckNextBadge7::
	checkflag FLAG_BADGE08_GET
	goto_if_set FLAG_BADGE08_GET, Testlabor_EventScript_Test_CheckNextBadge8
	msgbox Testlabor_Text_Test_GiveRainBadge, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE08_GET
	releaseall
	end
	
Testlabor_EventScript_Test_CheckNextBadge8::
	checkflag FLAG_BADGE09_GET
	goto_if_set FLAG_BADGE09_GET, Testlabor_EventScript_Test_CheckNextBadge9
	msgbox Testlabor_Text_Test_GiveCustomBadge9, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE09_GET
	releaseall
	end

Testlabor_EventScript_Test_CheckNextBadge9::
	checkflag FLAG_BADGE10_GET
	goto_if_set FLAG_BADGE10_GET, Testlabor_EventScript_Test_CheckNextBadge10
	msgbox Testlabor_Text_Test_GiveCustomBadge10, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE10_GET
	releaseall
	end
	
Testlabor_EventScript_Test_CheckNextBadge10::
	checkflag FLAG_BADGE11_GET
	goto_if_set FLAG_BADGE11_GET, Testlabor_EventScript_Test_CheckNextBadge11
	msgbox Testlabor_Text_Test_GiveCustomBadge11, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE11_GET
	releaseall
	end
	
Testlabor_EventScript_Test_CheckNextBadge11::
	checkflag FLAG_BADGE12_GET
	goto_if_set FLAG_BADGE12_GET, Testlabor_EventScript_Test_CheckNextBadge12
	msgbox Testlabor_Text_Test_GiveCustomBadge12, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE12_GET
	releaseall
	end
	
Testlabor_EventScript_Test_CheckNextBadge12::
	checkflag FLAG_BADGE13_GET
	goto_if_set FLAG_BADGE13_GET, Testlabor_EventScript_Test_CheckNextBadge13
	msgbox Testlabor_Text_Test_GiveCustomBadge13, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE13_GET
	releaseall
	end
	
Testlabor_EventScript_Test_CheckNextBadge13::
	checkflag FLAG_BADGE14_GET
	goto_if_set FLAG_BADGE14_GET, Testlabor_EventScript_Test_CheckNextBadge14
	msgbox Testlabor_Text_Test_GiveCustomBadge14, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE14_GET
	releaseall
	end
	
Testlabor_EventScript_Test_CheckNextBadge14::
	checkflag FLAG_BADGE15_GET
	goto_if_set FLAG_BADGE15_GET, Testlabor_EventScript_Test_CheckNextBadge15
	msgbox Testlabor_Text_Test_GiveCustomBadge15, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE15_GET
	releaseall
	end

Testlabor_EventScript_Test_CheckNextBadge15::
	checkflag FLAG_BADGE16_GET
	goto_if_set FLAG_BADGE16_GET, Testlabor_EventScript_Test_GiveGameClear
	msgbox Testlabor_Text_Test_GiveCustomBadge16, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE16_GET
	releaseall
	end

Testlabor_EventScript_Test_GiveGameClear::
	checkflag FLAG_SYS_GAME_CLEAR
	goto_if_set FLAG_SYS_GAME_CLEAR, Testlabor_EventScript_Test_NoMoreBadges
	msgbox Testlabor_Text_Test_GameClear, MSGBOX_DEFAULT
	setflag FLAG_SYS_GAME_CLEAR
	releaseall
	end

Testlabor_EventScript_Test_NoMoreBadges::
	msgbox Testlabor_Text_Test_NoMoreBadges, MSGBOX_DEFAULT
	releaseall
	end

Testlabor_Text_Test_GiveStoneBadge::
	.string "Hier hast du den Steinorden.$"

Testlabor_Text_Test_GiveKnuckleBadge::
	.string "Hier hast du den Faustenorden.$"

Testlabor_Text_Test_GiveDynamoBadge::
	.string "Hier hast du den Dynamoorden.$"

Testlabor_Text_Test_GiveHeatBadge::
	.string "Hier hast du den Hitzeorden.$"

Testlabor_Text_Test_GiveBalanceBadge::
	.string "Hier hast du den Gleichgewichtsorden.$"

Testlabor_Text_Test_GiveFeatherBadge::
	.string "Hier hast du den Federorden.$"

Testlabor_Text_Test_GiveMindBadge::
	.string "Hier hast du den Seelenorden.$"

Testlabor_Text_Test_GiveRainBadge::
	.string "Hier hast du den Regenorden.$"

Testlabor_Text_Test_GameClear::
	.string "Du bist jetzt Champ!$"

Testlabor_Text_Test_NoMoreBadges::
	.string "Ich habe nix mehr für dich.$"

Testlabor_Text_Test_GiveCustomBadge9::
	.string "Hier hast du den Neuntenorden.$"

Testlabor_Text_Test_GiveCustomBadge10::
	.string "Hier hast du den Zehntenorden.$"

Testlabor_Text_Test_GiveCustomBadge11::
	.string "Hier hast du den Elftenorden.$"

Testlabor_Text_Test_GiveCustomBadge12::
	.string "Hier hast du den Zwölftenorden.$"

Testlabor_Text_Test_GiveCustomBadge13::
	.string "Hier hast du den Dreizehntenorden.$"

Testlabor_Text_Test_GiveCustomBadge14::
	.string "Hier hast du den Vierzehntenorden.$"

Testlabor_Text_Test_GiveCustomBadge15::
	.string "Hier hast du den Fünfzehntenorden.$"

Testlabor_Text_Test_GiveCustomBadge16::
	.string "Hier hast du den Sechzehntenorden.$"

Testlabor_Eventscript_Hikertest::
	trainerbattle_single TRAINER_HIKER_TEST2, Testlabor_Text_HikerIntro, Testlabor_Text_HikerDefeat
	msgbox Testlabor_Text_HikerPost, MSGBOX_AUTOCLOSE
	end

Testlabor_Text_HikerIntro:
	.string "Test für Level 101+ Pokémon!$"

Testlabor_Text_HikerDefeat:
	.string "Gut gekämpft!$"

Testlabor_Text_HikerPost:
	.string "Du hast den Test bestanden!$"

Testlabor_EventScript_CelebiRepeat::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_CELEBI, 110
	special BattleSetup_StartLegendaryBattle
	waitstate
	release
	end

Testlabor_Eventscript_BackpackerMtest::
	trainerbattle_single TRAINER_BACKPACKER_M_TEST, Testlabor_Text_BackpackerMtest_Intro, Testlabor_Text_BackpackerMtest_Defeat
	msgbox Testlabor_Text_BackpackerMtest_Post, MSGBOX_AUTOCLOSE
	end

Testlabor_Text_BackpackerMtest_Intro:
	.string "Test für Level 101+ Pokémon!$"

Testlabor_Text_BackpackerMtest_Defeat:
	.string "Gut gekämpft!$"

Testlabor_Text_BackpackerMtest_Post:
	.string "Du hast den Test bestanden!$"

Testlabor_Eventscript_DebugShowExpLevelNpc::
	lockall
	faceplayer
	special BufferDebugExpLevelVars
	msgbox Testlabor_Text_DebugExpLevel, MSGBOX_DEFAULT
	waitbuttonpress
	closemessage
	releaseall
	end

Testlabor_Text_DebugExpLevel::
	.string "Level: {STR_VAR_1}, EXP: {STR_VAR_2}, MappedLvl: {STR_VAR_3}$"

Testlabor_EventScript_GalacticTest::
	trainerbattle_single TRAINER_GALACTIC_GRUNT_F_TEST, Testlabor_Text_GalacticIntro, Testlabor_Text_GalacticOutro
	msgbox Testlabor_Text_GalacticPostBattle, MSGBOX_AUTOCLOSE
	end

@ ========== TEXTE ==========

Testlabor_Text_GalacticIntro:
	.string "Galactic Transition Test.$"

Testlabor_Text_GalacticOutro:
	.string "Test.$"

Testlabor_Text_GalacticPostBattle:
	.string "Fertig.$"

Testlabor_EventScript_ChatgptTest::
	trainerbattle_single TRAINER_CHATGPT_TEST, Testlabor_Text_ChatgptIntro, Testlabor_Text_ChatgptOutro
	msgbox Testlabor_Text_ChatgptPostBattle, MSGBOX_AUTOCLOSE
	end

@ ========== TEXTE ==========

Testlabor_Text_ChatgptIntro:
	.string "ChatGPT Transition Test.$"

Testlabor_Text_ChatgptOutro:
	.string "Test.$"

Testlabor_Text_ChatgptPostBattle:
	.string "Fertig.$"

Testlabor_EventScript_ShinyToggleNPC::
	lock
	faceplayer
	goto_if_set FLAG_SHINY_MODE_ON, Testlabor_EventScript_ShinyToggleNPC_AlreadyOn
	msgbox Testlabor_Text_ShinyToggleNPC_Intro, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Testlabor_EventScript_ShinyToggleNPC_TurnOn
	msgbox Testlabor_Text_ShinyToggleNPC_No
	release
	end

Testlabor_EventScript_ShinyToggleNPC_AlreadyOn::
	msgbox Testlabor_Text_ShinyToggleNPC_AlreadyOn, MSGBOX_YESNO
	
	compare VAR_RESULT, YES
	goto_if_eq Testlabor_EventScript_ShinyToggleNPC_TurnOff
	
	release
	end

Testlabor_EventScript_ShinyToggleNPC_TurnOn::
	setflag FLAG_SHINY_MODE_ON
	msgbox Testlabor_Text_ShinyToggleNPC_Yes
	release
	end

Testlabor_EventScript_ShinyToggleNPC_TurnOff::
	clearflag FLAG_SHINY_MODE_ON
	msgbox Testlabor_Text_ShinyToggleNPC_No
	release
	end

Testlabor_Text_ShinyToggleNPC_Intro:
	.string "Hallo! Ich bin der Shiny-Forscher!\n"
	.string "Möchtest du dass alle wilden Pokémon\l"
	.string "Shiny sind zum Testen?$"

Testlabor_Text_ShinyToggleNPC_Yes:
	.string "Super! Von jetzt an sind alle\n"
	.string "wilden Pokémon Shiny!$"

Testlabor_Text_ShinyToggleNPC_No:
	.string "Okay! Shiny-Mode ist AUS.\n"
	.string "Normale Pokémon sind zurück!$"

Testlabor_Text_ShinyToggleNPC_AlreadyOn:
	.string "Der Shiny-Mode ist schon AN!\n"
	.string "Möchtest du ihn ausschalten?$"

Testlabor_Text_ShinyToggleNPC_AlreadyOff:
	.string "Der Shiny-Mode ist schon AUS!\n"
	.string "Möchtest du ihn einschalten?$"

Testlabor_EventScript_Route104_MiaBattle::
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_MiaIntro, Route104_Text_MiaDefeat, Route104_Text_MiaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route104_Text_MiaPostBattle, MSGBOX_DEFAULT
	release
	end

Testlabor_EventScript_TransitionTester::
	lock
	faceplayer
	msgbox Testlabor_Text_TransIntro, MSGBOX_DEFAULT
	goto Testlabor_TransMenu_Page1
	end

Testlabor_TransMenu_Page1:
	multichoice 0, 0, MULTI_TESTLAB_TRANSITIONS_PAGE1, 0
	compare VAR_RESULT, 0
	goto_if_eq Testlabor_SetTrans_Blur
	compare VAR_RESULT, 1
	goto_if_eq Testlabor_SetTrans_Swirl
	compare VAR_RESULT, 2
	goto_if_eq Testlabor_SetTrans_Shuffle
	compare VAR_RESULT, 3
	goto_if_eq Testlabor_SetTrans_BigPokeBall
	compare VAR_RESULT, 4
	goto_if_eq Testlabor_SetTrans_PokeBallsTrail
	compare VAR_RESULT, 5
	goto_if_eq Testlabor_SetTrans_ClockwiseWipe
	compare VAR_RESULT, 6
	goto_if_eq Testlabor_SetTrans_Ripple
	compare VAR_RESULT, 7
	goto_if_eq Testlabor_SetTrans_Wave
	compare VAR_RESULT, 8
	goto_if_eq Testlabor_TransMenu_Page2
	goto Testlabor_TransExit

Testlabor_TransMenu_Page2:
	multichoice 0, 0, MULTI_TESTLAB_TRANSITIONS_PAGE2, 0
	compare VAR_RESULT, 0
	goto_if_eq Testlabor_SetTrans_Slice
	compare VAR_RESULT, 1
	goto_if_eq Testlabor_SetTrans_WhiteBarsFade
	compare VAR_RESULT, 2
	goto_if_eq Testlabor_SetTrans_GridSquares
	compare VAR_RESULT, 3
	goto_if_eq Testlabor_SetTrans_AngledWipes
	compare VAR_RESULT, 4
	goto_if_eq Testlabor_SetTrans_Mugshot
	compare VAR_RESULT, 5
	goto_if_eq Testlabor_SetTrans_Aqua
	compare VAR_RESULT, 6
	goto_if_eq Testlabor_SetTrans_Magma
	compare VAR_RESULT, 7
	goto_if_eq Testlabor_SetTrans_ChatGPT
	compare VAR_RESULT, 8
	goto_if_eq Testlabor_TransMenu_Page3
	goto Testlabor_TransExit

Testlabor_TransMenu_Page3:
	multichoice 0, 0, MULTI_TESTLAB_TRANSITIONS_PAGE3, 0
	compare VAR_RESULT, 0
	goto_if_eq Testlabor_SetTrans_Regice
	compare VAR_RESULT, 1
	goto_if_eq Testlabor_SetTrans_Registeel
	compare VAR_RESULT, 2
	goto_if_eq Testlabor_SetTrans_Regirock
	compare VAR_RESULT, 3
	goto_if_eq Testlabor_SetTrans_Kyogre
	compare VAR_RESULT, 4
	goto_if_eq Testlabor_SetTrans_Groudon
	compare VAR_RESULT, 5
	goto_if_eq Testlabor_SetTrans_Rayquaza
	compare VAR_RESULT, 6
	goto_if_eq Testlabor_SetTrans_ShredSplit
	compare VAR_RESULT, 7
	goto_if_eq Testlabor_SetTrans_Blackhole
	compare VAR_RESULT, 8
	goto_if_eq Testlabor_TransMenu_Page4
	goto Testlabor_TransExit

Testlabor_TransMenu_Page4:
	multichoice 0, 0, MULTI_TESTLAB_TRANSITIONS_PAGE4, 0
	compare VAR_RESULT, 0
	goto_if_eq Testlabor_SetTrans_BlackholePulsate
	compare VAR_RESULT, 1
	goto_if_eq Testlabor_SetTrans_RectSpiral
	compare VAR_RESULT, 2
	goto_if_eq Testlabor_SetTrans_FrontierWiggle
	compare VAR_RESULT, 3
	goto_if_eq Testlabor_SetTrans_FrontierWave
	compare VAR_RESULT, 4
	goto_if_eq Testlabor_SetTrans_FrontierSquares
	compare VAR_RESULT, 5
	goto_if_eq Testlabor_SetTrans_FrontierSquaresScroll
	compare VAR_RESULT, 6
	goto_if_eq Testlabor_SetTrans_FrontierSquaresSpiral
	compare VAR_RESULT, 7
	goto_if_eq Testlabor_TransMenu_Page5
	goto Testlabor_TransExit

Testlabor_TransMenu_Page5:
	multichoice 0, 0, MULTI_TESTLAB_TRANSITIONS_PAGE5, 0
	compare VAR_RESULT, 0
	goto_if_eq Testlabor_SetTrans_FrontierCirclesMeet
	compare VAR_RESULT, 1
	goto_if_eq Testlabor_SetTrans_FrontierCirclesCross
	compare VAR_RESULT, 2
	goto_if_eq Testlabor_SetTrans_FrontierCirclesAsym
	compare VAR_RESULT, 3
	goto_if_eq Testlabor_SetTrans_FrontierCirclesSym
	compare VAR_RESULT, 4
	goto_if_eq Testlabor_SetTrans_Galactic
	compare VAR_RESULT, 5
	goto_if_eq Testlabor_SetTrans_Shiny
	compare VAR_RESULT, 6
	goto_if_eq Testlabor_TransExit
	goto Testlabor_TransExit

Testlabor_TransExit:
	setvar VAR_DEBUG_BATTLE_TRANSITION, 0xFFFF
	msgbox Testlabor_Text_TransBye, MSGBOX_DEFAULT
	release
	end

Testlabor_SetTrans_Blur:
	setvar VAR_0x8004, 0
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_Swirl:
	setvar VAR_0x8004, 1
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_Shuffle:
	setvar VAR_0x8004, 2
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_BigPokeBall:
	setvar VAR_0x8004, 3
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_PokeBallsTrail:
	setvar VAR_0x8004, 4
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_ClockwiseWipe:
	setvar VAR_0x8004, 5
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_Ripple:
	setvar VAR_0x8004, 6
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_Wave:
	setvar VAR_0x8004, 7
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_Slice:
	setvar VAR_0x8004, 8
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_WhiteBarsFade:
	setvar VAR_0x8004, 9
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_GridSquares:
	setvar VAR_0x8004, 10
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_AngledWipes:
	setvar VAR_0x8004, 11
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_Mugshot:
	setvar VAR_0x8004, 12
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_Aqua:
	setvar VAR_0x8004, 13
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_Magma:
	setvar VAR_0x8004, 14
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_ChatGPT:
	setvar VAR_0x8004, 15
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_Regice:
	setvar VAR_0x8004, 16
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_Registeel:
	setvar VAR_0x8004, 17
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_Regirock:
	setvar VAR_0x8004, 18
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_Kyogre:
	setvar VAR_0x8004, 19
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_Groudon:
	setvar VAR_0x8004, 20
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_Rayquaza:
	setvar VAR_0x8004, 21
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_ShredSplit:
	setvar VAR_0x8004, 22
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_Blackhole:
	setvar VAR_0x8004, 23
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_BlackholePulsate:
	setvar VAR_0x8004, 24
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_RectSpiral:
	setvar VAR_0x8004, 25
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_FrontierWiggle:
	setvar VAR_0x8004, 26
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_FrontierWave:
	setvar VAR_0x8004, 27
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_FrontierSquares:
	setvar VAR_0x8004, 28
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_FrontierSquaresScroll:
	setvar VAR_0x8004, 29
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_FrontierSquaresSpiral:
	setvar VAR_0x8004, 30
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_FrontierCirclesMeet:
	setvar VAR_0x8004, 31
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_FrontierCirclesCross:
	setvar VAR_0x8004, 32
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_FrontierCirclesAsym:
	setvar VAR_0x8004, 33
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_FrontierCirclesSym:
	setvar VAR_0x8004, 34
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_Galactic:
	setvar VAR_0x8004, 39
	goto Testlabor_CallSpecialAndBattle

Testlabor_SetTrans_Shiny:
	setvar VAR_0x8004, 40
	goto Testlabor_CallSpecialAndBattle

Testlabor_CallSpecialAndBattle:
	special SetDebugBattleTransition
	goto Testlabor_DoTransitionBattle

Testlabor_DoTransitionBattle:
	closemessage
	playbgm MUS_ENCOUNTER_MAY, TRUE
	trainerbattle_no_intro TRAINER_TRANSITION_TEST, Testlabor_Text_DummyWin
	msgbox Testlabor_Text_AfterBattle, MSGBOX_DEFAULT
	goto Testlabor_TransMenu_Page1

Testlabor_Text_TransIntro:
	.string "Wähle eine Battle-Transition.$"

Testlabor_Text_TransBye:
	.string "Okay.$"

Testlabor_Text_DummyWin:
	.string "ok$"

Testlabor_Text_AfterBattle:
	.string "Noch eine?$"

Testlabor_EventScript_UxieRepeat::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_UXIE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_UXIE, 1
	special BattleSetup_StartLegendaryBattle
	waitstate
	release
	end
