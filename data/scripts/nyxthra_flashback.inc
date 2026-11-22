@ Nyxthra: Rückblick-Clip 1 — Brix wählt 2005 auf der originalen Route 101 Hydropi.
@ Karte und Tilesets sind Kopien aus pret/pokeemerald (Smaragd 2005).
@ Texte im offiziellen deutschen Stil (PokéWiki, 3. Generation).

NyxthraFlashback_Text_HelpMe:
	.string "HI… HIIIILFE!!!\n"
	.string "HILFE!!!$"

NyxthraFlashback_Text_PleaseHelp:
	.string "Du dort drüben!\n"
	.string "Bitte! HILFE!!!\p"
	.string "In meinem BEUTEL…\n"
	.string "Da findest du einen POKéBALL!$"

NyxthraFlashback_EventScript_Clip1::
	lockall
	setflag FLAG_HIDE_MAP_NAME_POPUP
	playbgm MUS_HELP, TRUE
	msgbox NyxthraFlashback_Text_HelpMe, MSGBOX_DEFAULT
	closemessage
	setobjectxy LOCALID_FLASHBACK_BIRCH, 0, 15
	setobjectxy LOCALID_FLASHBACK_ZIGZAGOON, 0, 16
	applymovement LOCALID_PLAYER, Route101_Movement_EnterScene
	applymovement LOCALID_FLASHBACK_BIRCH, Route101_Movement_BirchRunAway1
	applymovement LOCALID_FLASHBACK_ZIGZAGOON, Route101_Movement_ZigzagoonChase1
	waitmovement 0
	applymovement LOCALID_FLASHBACK_ZIGZAGOON, Route101_Movement_ZigzagoonChaseInCircles
	applymovement LOCALID_FLASHBACK_BIRCH, Route101_Movement_BirchRunInCircles
	waitmovement 0
	applymovement LOCALID_FLASHBACK_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	applymovement LOCALID_FLASHBACK_ZIGZAGOON, Route101_Movement_ZigzagoonFaceBirch
	applymovement LOCALID_FLASHBACK_BIRCH, Route101_Movement_BirchFaceZigzagoon
	waitmovement 0
	msgbox NyxthraFlashback_Text_PleaseHelp, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_FLASHBACK_ZIGZAGOON
	setobjectxy OBJ_EVENT_ID_PLAYER, 6, 13
	applymovement OBJ_EVENT_ID_PLAYER, Route101_Movement_PlayerFaceLeft
	waitmovement 0
	special ChooseStarter
	delay 40
	fadescreen FADE_TO_BLACK
	warpsilent MAP_FLASHBACK_RUSTBORO_GYM, 5, 5
	waitstate
	end

NyxthraFlashback_Text_RoxanneIntro:
	.string "Hi, ich bin FELIZIA,\n"
	.string "LEITERIN der METAROST ARENA.\p"
	.string "Lass uns sehen, wie du kämpfst!$"

NyxthraFlashback_Text_RoxanneDefeat:
	.string "Oh… verloren…$"

NyxthraFlashback_Text_ReceivedStoneBadge:
	.string "{PLAYER} erhält den STEINORDEN von\n"
	.string "FELIZIA!$"

@ Nur 2 Schritte vor Felizia: der komplette Arenaweg würde
@ andere Trainer zeigen, die im Rückblick nicht vorkommen.
NyxthraFlashback_Movement_ApproachRoxanne:
	walk_up
	walk_up
	step_end

NyxthraFlashback_EventScript_Clip2::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, NyxthraFlashback_Movement_ApproachRoxanne
	waitmovement 0
	applymovement LOCALID_FLASHBACK_ROXANNE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox NyxthraFlashback_Text_RoxanneIntro, MSGBOX_DEFAULT
	closemessage
	special NyxthraFlashback_PrepareScriptedBattle
	trainerbattle_no_intro TRAINER_ROXANNE_1, NyxthraFlashback_Text_RoxanneDefeat
	delay 20
	message NyxthraFlashback_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	waitmessage
	closemessage
	delay 50
	fadescreen FADE_TO_BLACK
	special NyxthraFlashback_Finish
	releaseall
	end

NyxthraFlashback_Movement_ApproachLeader:
	walk_up
	walk_up
	step_end

NyxthraFlashback_Movement_GroudonApproach:
	init_affine_anim
	walk_down_start_affine
	delay_16
	delay_16
	walk_down_affine
	delay_16
	delay_16
	walk_down_affine
	step_end

@ --- Entwicklung Moorabbel → Sumpex ---
NyxthraFlashback_EventScript_Evolution::
	lockall
	delay 30
	special NyxthraFlashback_BeginEvolution
	@ waitstate already in special
	delay 80
	fadescreen FADE_TO_BLACK
	special NyxthraFlashback_Finish
	releaseall
	end

@ --- 4. Arena: Flavia, Bad Lavastadt ---
NyxthraFlashback_Text_FlaviaIntro:
	.string "Willkommen! Ich bin FLAVIA,\n"
	.string "LEITERIN der ARENA von BAD LAVASTADT.\p"
	.string "Meine POKéMON sind im Feuer des\n"
	.string "Vulkans abgehärtet! Los geht's!$"

NyxthraFlashback_Text_FlaviaDefeat:
	.string "Die Flamme… ist erloschen…$"

NyxthraFlashback_Text_ReceivedHeatBadge:
	.string "{PLAYER} erhält den HITZEORDEN von\n"
	.string "FLAVIA!$"

NyxthraFlashback_EventScript_Gym4::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, NyxthraFlashback_Movement_ApproachLeader
	waitmovement 0
	applymovement LOCALID_FLASHBACK_FLAVIA, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox NyxthraFlashback_Text_FlaviaIntro, MSGBOX_DEFAULT
	closemessage
	special NyxthraFlashback_PrepareScriptedBattle
	trainerbattle_no_intro TRAINER_FLANNERY_1, NyxthraFlashback_Text_FlaviaDefeat
	delay 20
	message NyxthraFlashback_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	waitmessage
	closemessage
	delay 50
	fadescreen FADE_TO_BLACK
	special NyxthraFlashback_Finish
	releaseall
	end

@ --- 8. Arena: Juan, Xeneroville (Champ ist Wassili) ---
NyxthraFlashback_Text_JuanIntro:
	.string "Ah… willkommen. Ich bin JUAN,\n"
	.string "LEITER der XENEROVILLE-ARENA.\p"
	.string "Lass uns einen Kampf führen,\n"
	.string "so elegant wie das Wasser selbst!$"

NyxthraFlashback_Text_JuanDefeat:
	.string "Eine ausgezeichnete Vorstellung.$"

NyxthraFlashback_Text_ReceivedRainBadge:
	.string "{PLAYER} erhält den SCHWALLORDEN von\n"
	.string "JUAN!$"

NyxthraFlashback_EventScript_Gym8::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, NyxthraFlashback_Movement_ApproachLeader
	waitmovement 0
	applymovement LOCALID_FLASHBACK_JUAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox NyxthraFlashback_Text_JuanIntro, MSGBOX_DEFAULT
	closemessage
	special NyxthraFlashback_PrepareScriptedBattle
	trainerbattle_no_intro TRAINER_JUAN_1, NyxthraFlashback_Text_JuanDefeat
	delay 20
	message NyxthraFlashback_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	waitmessage
	closemessage
	delay 50
	fadescreen FADE_TO_BLACK
	special NyxthraFlashback_Finish
	releaseall
	end

@ --- Team Magma: Marc im Versteck ---
NyxthraFlashback_Text_MarcIntro:
	.string "Du schon wieder…\n"
	.string "Ich bin MARC, der Boss von TEAM MAGMA.\p"
	.string "Mit GROUDON formen wir die Welt neu!$"

NyxthraFlashback_Text_MarcDefeat:
	.string "Unmöglich… TEAM MAGMA… besiegt…$"

NyxthraFlashback_EventScript_Marc::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, NyxthraFlashback_Movement_ApproachLeader
	waitmovement 0
	applymovement LOCALID_FLASHBACK_MAXIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox NyxthraFlashback_Text_MarcIntro, MSGBOX_DEFAULT
	closemessage
	special NyxthraFlashback_PrepareScriptedBattle
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, NyxthraFlashback_Text_MarcDefeat
	delay 40
	fadescreen FADE_TO_BLACK
	special NyxthraFlashback_Finish
	releaseall
	end

@ --- Team Aqua: Adrian in der Meereshöhle ---
NyxthraFlashback_Text_AdrianIntro:
	.string "Du gehst zu weit.\n"
	.string "Ich bin ADRIAN, Boss von TEAM AQUA.\p"
	.string "KYOGRE wird die Welt mit Wasser\n"
	.string "bedecken!$"

NyxthraFlashback_Text_AdrianDefeat:
	.string "Wie… kann TEAM AQUA nur verlieren…$"

NyxthraFlashback_EventScript_Adrian::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, NyxthraFlashback_Movement_ApproachLeader
	waitmovement 0
	applymovement LOCALID_FLASHBACK_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox NyxthraFlashback_Text_AdrianIntro, MSGBOX_DEFAULT
	closemessage
	special NyxthraFlashback_PrepareScriptedBattle
	trainerbattle_no_intro TRAINER_ARCHIE, NyxthraFlashback_Text_AdrianDefeat
	delay 40
	fadescreen FADE_TO_BLACK
	special NyxthraFlashback_Finish
	releaseall
	end

@ --- Top Vier, 2. Mitglied: Antonia ---
NyxthraFlashback_Text_AntoniaIntro:
	.string "Ahahaha! Ich bin ANTONIA\n"
	.string "von den TOP VIER.\p"
	.string "Meine Geister-POKéMON werden dich\n"
	.string "erschaudern lassen!$"

NyxthraFlashback_Text_AntoniaDefeat:
	.string "Ich bin beeindruckt…$"

NyxthraFlashback_Text_DefeatedAntonia:
	.string "{PLAYER} hat ANTONIA von den TOP VIER\n"
	.string "besiegt!$"

NyxthraFlashback_EventScript_Antonia::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, NyxthraFlashback_Movement_ApproachLeader
	waitmovement 0
	applymovement LOCALID_FLASHBACK_PHOEBE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox NyxthraFlashback_Text_AntoniaIntro, MSGBOX_DEFAULT
	closemessage
	special NyxthraFlashback_PrepareScriptedBattle
	trainerbattle_no_intro TRAINER_PHOEBE, NyxthraFlashback_Text_AntoniaDefeat
	delay 20
	message NyxthraFlashback_Text_DefeatedAntonia
	waitmessage
	waitbuttonpress
	closemessage
	delay 40
	fadescreen FADE_TO_BLACK
	special NyxthraFlashback_Finish
	releaseall
	end

@ --- Champ: Wassili (in Smaragd der Champ, Juan ist die 8. Arena) ---
NyxthraFlashback_Text_WassiliIntro:
	.string "Ich bin WASSILI, der CHAMP der\n"
	.string "POKéMON LIGA von HOENN.\p"
	.string "Zeig mir die Schönheit deines\n"
	.string "Kampfes!$"

NyxthraFlashback_Text_WassiliDefeat:
	.string "Du… bist der neue CHAMP.$"

NyxthraFlashback_Text_BecameChamp:
	.string "{PLAYER} ist der neue CHAMP von HOENN!$"

NyxthraFlashback_EventScript_Wassili::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_PLAYER, NyxthraFlashback_Movement_ApproachLeader
	waitmovement 0
	applymovement LOCALID_FLASHBACK_WALLACE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox NyxthraFlashback_Text_WassiliIntro, MSGBOX_DEFAULT
	closemessage
	special NyxthraFlashback_PrepareScriptedBattle
	trainerbattle_no_intro TRAINER_WALLACE, NyxthraFlashback_Text_WassiliDefeat
	delay 20
	message NyxthraFlashback_Text_BecameChamp
	waitmessage
	waitbuttonpress
	closemessage
	delay 40
	fadescreen FADE_TO_BLACK
	special NyxthraFlashback_Finish
	releaseall
	end

@ --- Legendäre Begegnungen (Originalablauf: Auftritt, Ruf, Kampfbeginn mit
@ Kampfmusik und Übergangsanimation, dann ein Angriffspaar, dann Fade). ---
NyxthraFlashback_Movement_StepUp:
	walk_up
	step_end

NyxthraFlashback_EventScript_Groudon::
	lockall
	applymovement LOCALID_PLAYER, NyxthraFlashback_Movement_StepUp
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_FLASHBACK_GROUDON, NyxthraFlashback_Movement_GroudonApproach
	waitmovement 0
	waitse
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special NyxthraFlashback_PrepareScriptedBattle
	setwildbattle SPECIES_GROUDON, 70
	special NyxthraFlashback_PrepareWildOpponent
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	special BattleSetup_StartLegendaryBattle
	@ Nach einer Kampfrunde blendet der Autokampf aus und kehrt zurück.
	delay 30
	fadescreen FADE_TO_BLACK
	special NyxthraFlashback_Finish
	releaseall
	end

NyxthraFlashback_EventScript_Kyogre::
	lockall
	applymovement LOCALID_PLAYER, NyxthraFlashback_Movement_StepUp
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_FLASHBACK_KYOGRE, NyxthraFlashback_Movement_GroudonApproach
	waitmovement 0
	waitse
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special NyxthraFlashback_PrepareScriptedBattle
	setwildbattle SPECIES_KYOGRE, 70
	special NyxthraFlashback_PrepareWildOpponent
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	special BattleSetup_StartLegendaryBattle
	@ Nach einer Kampfrunde blendet der Autokampf aus und kehrt zurück.
	delay 30
	fadescreen FADE_TO_BLACK
	special NyxthraFlashback_Finish
	releaseall
	end

@ Rayquaza: Erwachen wie in der Himmelsäule (Kamerafahrt, Rühren, zwei Rufe
@ mit Kamerawackeln), dann der Kampf.
NyxthraFlashback_EventScript_Rayquaza::
	lockall
	applymovement LOCALID_PLAYER, NyxthraFlashback_Movement_StepUp
	waitmovement 0
	fadeoutbgm 1
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, SkyPillar_Top_Movement_CameraPanUp
	waitmovement 0
	special RemoveCameraObject
	applymovement LOCALID_FLASHBACK_RAYQUAZA, SkyPillar_Top_Movement_RayquazaStir
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special ShakeCamera
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	waitmoncry
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special NyxthraFlashback_PrepareScriptedBattle
	setwildbattle SPECIES_RAYQUAZA, 70
	special NyxthraFlashback_PrepareWildOpponent
	playmoncry SPECIES_RAYQUAZA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	special BattleSetup_StartLegendaryBattle
	@ Nach einer Kampfrunde blendet der Autokampf aus und kehrt zurück.
	delay 30
	fadescreen FADE_TO_BLACK
	special NyxthraFlashback_Finish
	releaseall
	end

NyxthraFlashback_EventScript_Regirock::
	lockall
	applymovement LOCALID_PLAYER, NyxthraFlashback_Movement_ApproachLeader
	waitmovement 0
	applymovement LOCALID_FLASHBACK_REGIROCK, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	waitse
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special NyxthraFlashback_PrepareScriptedBattle
	setwildbattle SPECIES_REGIROCK, 40
	special NyxthraFlashback_PrepareWildOpponent
	playmoncry SPECIES_REGIROCK, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	special StartRegiBattle
	@ Nach einer Kampfrunde blendet der Autokampf aus und kehrt zurück.
	delay 30
	fadescreen FADE_TO_BLACK
	special NyxthraFlashback_Finish
	releaseall
	end

NyxthraFlashback_EventScript_Regice::
	lockall
	applymovement LOCALID_PLAYER, NyxthraFlashback_Movement_ApproachLeader
	waitmovement 0
	applymovement LOCALID_FLASHBACK_REGICE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	waitse
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special NyxthraFlashback_PrepareScriptedBattle
	setwildbattle SPECIES_REGICE, 40
	special NyxthraFlashback_PrepareWildOpponent
	playmoncry SPECIES_REGICE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	special StartRegiBattle
	@ Nach einer Kampfrunde blendet der Autokampf aus und kehrt zurück.
	delay 30
	fadescreen FADE_TO_BLACK
	special NyxthraFlashback_Finish
	releaseall
	end

NyxthraFlashback_EventScript_Registeel::
	lockall
	applymovement LOCALID_PLAYER, NyxthraFlashback_Movement_ApproachLeader
	waitmovement 0
	applymovement LOCALID_FLASHBACK_REGISTEEL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	waitse
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special NyxthraFlashback_PrepareScriptedBattle
	setwildbattle SPECIES_REGISTEEL, 40
	special NyxthraFlashback_PrepareWildOpponent
	playmoncry SPECIES_REGISTEEL, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	special StartRegiBattle
	@ Nach einer Kampfrunde blendet der Autokampf aus und kehrt zurück.
	delay 30
	fadescreen FADE_TO_BLACK
	special NyxthraFlashback_Finish
	releaseall
	end

@ --- Entwicklung Hydropi → Moorabbel (Lv16) ---
NyxthraFlashback_EventScript_EvolutionMudkip::
	lockall
	delay 30
	special NyxthraFlashback_BeginEvolution
	@ waitstate already in special
	delay 80
	fadescreen FADE_TO_BLACK
	special NyxthraFlashback_Finish
	releaseall
	end
