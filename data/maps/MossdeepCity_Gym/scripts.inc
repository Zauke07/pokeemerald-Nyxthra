MossdeepCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_Gym_OnLoad
	.byte 0

@ NOTE: Mossdeep Gym was redesigned between R/S and E. Leftover (and now functionally unused) scripts are commented below

MossdeepCity_Gym_OnTransition:
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower since it can collide with moving statues
	end

@ All the below checks are leftover from RS. FLAG_MOSSDEEP_GYM_SWITCH_X is never set
MossdeepCity_Gym_OnLoad:
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_SetSwitch1Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_CheckSwitch2::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_SetSwitch2Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_CheckSwitch3::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_SetSwitch3Metatiles
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_CheckSwitch4::
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_SetSwitch4Metatiles
	end

@ All the below set metatile scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_SetSwitch1Metatiles::
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch2
	end

MossdeepCity_Gym_EventScript_SetSwitch2Metatiles::
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch3
	end

MossdeepCity_Gym_EventScript_SetSwitch3Metatiles::
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_CheckSwitch4
	end

MossdeepCity_Gym_EventScript_SetSwitch4Metatiles::
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	end

MossdeepCity_Gym_EventScript_TateAndLiza::
	trainerbattle_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaIntro, MossdeepCity_Gym_Text_TateAndLizaDefeat, MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons, MossdeepCity_Gym_EventScript_TateAndLizaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MossdeepCity_Gym_EventScript_TateAndLizaRematch
	goto_if_unset FLAG_RECEIVED_TM_CALM_MIND, MossdeepCity_Gym_EventScript_GiveCalmMind2
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_TateAndLizaDefeated::
	message MossdeepCity_Gym_Text_ReceivedMindBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_MOSSDEEP_GYM
	setflag FLAG_BADGE07_GET
	setflag FLAG_HIDE_AQUA_HIDEOUT_GRUNTS
	clearflag FLAG_HIDE_SLATEPORT_CITY_STERNS_SHIPYARD_MR_BRINEY
	clearflag FLAG_UNKNOWN_0x393
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	setvar VAR_MOSSDEEP_CITY_STATE, 1
	setflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_STEVEN
	setvar VAR_MOSSDEEP_SPACE_CENTER_STATE, 1
	call MossdeepCity_Gym_EventScript_GiveCalmMind
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MossdeepCity_Gym_Text_RegisteredTateAndLiza, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_TATE_AND_LIZA_MATCH_CALL
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind2::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	release
	end

MossdeepCity_Gym_EventScript_GiveCalmMind::
	giveitem ITEM_TM_CALM_MIND
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MossdeepCity_Gym_Text_ExplainCalmMind, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_CALM_MIND
	return

MossdeepCity_Gym_EventScript_TateAndLizaRematch::
	trainerbattle_rematch_double TRAINER_TATE_AND_LIZA_1, MossdeepCity_Gym_Text_TateAndLizaPreRematch, MossdeepCity_Gym_Text_TateAndLizaRematchDefeat, MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons
	msgbox MossdeepCity_Gym_Text_TateAndLizaPostRematch, MSGBOX_AUTOCLOSE
	end

@ All the below switch scripts are leftover from RS and are functionally unused
MossdeepCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_1, MossdeepCity_Gym_EventScript_ClearSwitch1
	setflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed::
	special DrawWholeMapView
	playse SE_CLICK
	releaseall
	end

MossdeepCity_Gym_EventScript_ClearSwitch1::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 5, 5, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 2, 7, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_2, MossdeepCity_Gym_EventScript_ClearSwitch2
	setflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch2::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 8, 14, METATILE_RSMossdeepGym_RedArrow_Down, FALSE
	setmetatile 8, 10, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_3, MossdeepCity_Gym_EventScript_ClearSwitch3
	setflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Left, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch3::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 15, 17, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 17, 15, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_MOSSDEEP_GYM_SWITCH_4, MossdeepCity_Gym_EventScript_ClearSwitch4
	setflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Up, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Down, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_ClearSwitch4::
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	applymovement LOCALID_PLAYER, MossdeepCity_Gym_Movement_WaitAfterSwitchUse
	waitmovement 0
	setmetatile 1, 23, METATILE_RSMossdeepGym_RedArrow_Right, FALSE
	setmetatile 5, 24, METATILE_RSMossdeepGym_Switch_Up, TRUE
	goto MossdeepCity_Gym_EventScript_DrawMapAfterSwitchUsed
	end

MossdeepCity_Gym_EventScript_WarpToEntrance::
	lockall
	warpmossdeepgym MAP_MOSSDEEP_CITY_GYM, 7, 30
	waitstate
	releaseall
	end

MossdeepCity_Gym_EventScript_Preston::
	trainerbattle_single TRAINER_PRESTON, MossdeepCity_Gym_Text_PrestonIntro, MossdeepCity_Gym_Text_PrestonDefeat
	msgbox MossdeepCity_Gym_Text_PrestonPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Virgil::
	trainerbattle_single TRAINER_VIRGIL, MossdeepCity_Gym_Text_VirgilIntro, MossdeepCity_Gym_Text_VirgilDefeat
	msgbox MossdeepCity_Gym_Text_VirgilPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE, MossdeepCity_Gym_Text_BlakeIntro, MossdeepCity_Gym_Text_BlakeDefeat
	msgbox MossdeepCity_Gym_Text_BlakePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Hannah::
	trainerbattle_single TRAINER_HANNAH, MossdeepCity_Gym_Text_HannahIntro, MossdeepCity_Gym_Text_HannahDefeat
	msgbox MossdeepCity_Gym_Text_HannahPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA, MossdeepCity_Gym_Text_SamanthaIntro, MossdeepCity_Gym_Text_SamanthaDefeat
	msgbox MossdeepCity_Gym_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Maura::
	trainerbattle_single TRAINER_MAURA, MossdeepCity_Gym_Text_MauraIntro, MossdeepCity_Gym_Text_MauraDefeat
	msgbox MossdeepCity_Gym_Text_MauraPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Sylvia::
	trainerbattle_single TRAINER_SYLVIA, MossdeepCity_Gym_Text_SylviaIntro, MossdeepCity_Gym_Text_SylviaDefeat
	msgbox MossdeepCity_Gym_Text_SylviaPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nate::
	trainerbattle_single TRAINER_NATE, MossdeepCity_Gym_Text_NateIntro, MossdeepCity_Gym_Text_NateDefeat
	msgbox MossdeepCity_Gym_Text_NatePostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Macey::
	trainerbattle_single TRAINER_MACEY, MossdeepCity_Gym_Text_MaceyIntro, MossdeepCity_Gym_Text_MaceyDefeat
	msgbox MossdeepCity_Gym_Text_MaceyPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Clifford::
	trainerbattle_single TRAINER_CLIFFORD, MossdeepCity_Gym_Text_CliffordIntro, MossdeepCity_Gym_Text_CliffordDefeat
	msgbox MossdeepCity_Gym_Text_CliffordPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Nicholas::
	trainerbattle_single TRAINER_NICHOLAS, MossdeepCity_Gym_Text_NicholasIntro, MossdeepCity_Gym_Text_NicholasDefeat
	msgbox MossdeepCity_Gym_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_Kathleen::
	trainerbattle_single TRAINER_KATHLEEN, MossdeepCity_Gym_Text_KathleenIntro, MossdeepCity_Gym_Text_KathleenDefeat
	msgbox MossdeepCity_Gym_Text_KathleenPostBattle, MSGBOX_AUTOCLOSE
	end

MossdeepCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MOSSDEEP_GYM, MossdeepCity_Gym_EventScript_GymGuidePostVictory
	msgbox MossdeepCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MossdeepCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

@ Leftover from RS, functionally unused
MossdeepCity_Gym_Movement_WaitAfterSwitchUse:
	delay_16
	delay_16
	step_end

MossdeepCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE07_GET, MossdeepCity_Gym_EventScript_GymStatueCertified
	goto MossdeepCity_Gym_EventScript_GymStatue
	end

MossdeepCity_Gym_EventScript_GymStatueCertified::
	msgbox MossdeepCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_GymStatue::
	msgbox MossdeepCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MossdeepCity_Gym_EventScript_YellowFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 0
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_BlueFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 1
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_GreenFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 2
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_PurpleFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 3
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_EventScript_RedFloorSwitch::
	playse SE_SWITCH
	waitse
	playse SE_REPEL
	initrotatingtilepuzzle FALSE
	moverotatingtileobjects 4
	waitmovement 0
	turnrotatingtileobjects
	waitmovement 0
	freerotatingtilepuzzle
	end

MossdeepCity_Gym_Text_GymGuideAdvice:
	.string "Yo, was geht, du kleiner Pisser von\n"
	.string "einem {PLAYER}?\p"
	.string "Die Leiter hier ficken deinen Kopf mit\n"
	.string "richtig abartigem Psycho-Scheiß.\p"
	.string "Wenn du hier mit Kampf- oder Gift-Opfern\n"
	.string "antanzt, kriegst du so hart auf die\l"
	.string "Fresse, dass deine Mutter es spürt!\p"
	.string "Die ballern Kombos raus, da wackelt\n"
	.string "wirklich die Wand.\p"
	.string "Wenn du nicht komplett kassieren willst,\n"
	.string "zeig denen, wer hier die fettesten Eier\l"
	.string "hat. Mach sie platt!$"

MossdeepCity_Gym_Text_GymGuidePostVictory:
	.string "Bruder, du hast die ja komplett\n"
	.string "hops genommen! Geisteskranker Ficker!$"

MossdeepCity_Gym_Text_PrestonIntro:
	.string "Wer fette Eier hat, gewinnt! Pussys\n"
	.string "wie du gehen hier direkt heulen!$"

MossdeepCity_Gym_Text_PrestonDefeat:
	.string "FICK DICH! Meine Eier sind wohl\n"
	.string "doch zu klein!$"

MossdeepCity_Gym_Text_PrestonPostBattle:
	.string "Wer rumfotzt, kassiert.\n"
	.string "Merk dir das, du kleiner Lappen.$"

MossdeepCity_Gym_Text_VirgilIntro:
	.string "Lass mal sehen, ob du mehr kannst,\n"
	.string "als nur dumm aus der Wäsche zu gucken!$"

MossdeepCity_Gym_Text_VirgilDefeat:
	.string "Okay, fick mein Leben, du bist krass!$"

MossdeepCity_Gym_Text_VirgilPostBattle:
	.string "Eigentlich sind unsere Leiter die\n"
	.string "absoluten Babos auf der Straße!\p"
	.string "Aber du bist ja ein verdammter\n"
	.string "Cheatcode, Junge...$"

MossdeepCity_Gym_Text_BlakeIntro:
	.string "Hehe… guck mal, ich lass meine Bälle\n"
	.string "mit den Gedanken schweben!\p"
	.string "WROOOOOAAAAR!\n"
	.string "… … … … … … …\p"
	.string "Scheiße, mein WLAN im Kopf spackt.$"

MossdeepCity_Gym_Text_BlakeDefeat:
	.string "Mein Kopf ist leer gefickt!$"

MossdeepCity_Gym_Text_BlakePostBattle:
	.string "Für 'nen Pokéball reicht mein Hirn\n"
	.string "nicht, aber guck dir diesen Staub an…\p"
	.string "WHOOOOOOOOOOOOOOOH!\n"
	.string "… … … … … …\p"
	.string "Halts Maul, ich hab nicht gepustet!\n"
	.string "Willst du Schläge, du Bastard?!$"

MossdeepCity_Gym_Text_HannahIntro:
	.string "Heul gleich nicht rum, wenn ich dich\n"
	.string "vor allen Leuten komplett zerstöre.\p"
	.string "Du bist nicht einfach nur scheiße,\n"
	.string "ich bin einfach zu geil für dich!$"

MossdeepCity_Gym_Text_HannahDefeat:
	.string "Was für ein abartiger Bullshit!$"

MossdeepCity_Gym_Text_HannahPostBattle:
	.string "Scheiß drauf, ich war eh besoffen.\n"
	.string "Muss halt noch krasser reinballern.\p"
	.string "Positiver Vibe und so. Verpiss dich!$"

MossdeepCity_Gym_Text_SamanthaIntro:
	.string "Ich seh's…\n"
	.string "Ich seh deine miese Zukunft…\p"
	.string "Wenn du mich wegklatscht, sag ich dir,\n"
	.string "wann und wo du krepierst!$"

MossdeepCity_Gym_Text_SamanthaDefeat:
	.string "Okay, okay, fick mich doch nicht\n"
	.string "so hart!$"

MossdeepCity_Gym_Text_SamanthaPostBattle:
	.string "Die Leiter werden dich gleich komplett\n"
	.string "auseinandernehmen… Blut überall…\p"
	.string "Und das Ende?\n"
	.string "Finde es selbst raus, du Missgeburt!$"

MossdeepCity_Gym_Text_MauraIntro:
	.string "Egal durch welche dreckige Gosse\n"
	.string "du bisher gekrochen bist…\p"
	.string "Zeig mir, ob du auf der Straße was\n"
	.string "gelernt hast!$"

MossdeepCity_Gym_Text_MauraDefeat:
	.string "Scheiße, du hast Straßenabitur!$"

MossdeepCity_Gym_Text_MauraPostBattle:
	.string "Wer hart ballert, kriegt den Fame.\p"
	.string "Wer nur kifft und chillt, endet als\n"
	.string "Penner unter der Brücke.\p"
	.string "Karma fickt jeden, Digga.$"

MossdeepCity_Gym_Text_SylviaIntro:
	.string "Ich reiß dir den Kopf ab, selbst wenn\n"
	.string "ich dabei draufgehe, du Fotze!$"

MossdeepCity_Gym_Text_SylviaDefeat:
	.string "Bist du komplett geistesgestört?!$"

MossdeepCity_Gym_Text_SylviaPostBattle:
	.string "Dass du Lappen mich echt wegbummst…\p"
	.string "Wenn dir nachher ein Klavier auf den\n"
	.string "Kopf fällt, war ich das nicht… vielleicht.$"

MossdeepCity_Gym_Text_NateIntro:
	.string "Hahaha.\p"
	.string "Komm her, ich zeig dir mal, wie Psycho-\n"
	.string "Typen dir den Arsch aufreißen.$"

MossdeepCity_Gym_Text_NateDefeat:
	.string "Alter Schwede!\n"
	.string "Was für ein kranker Scheiß!$"

MossdeepCity_Gym_Text_NatePostBattle:
	.string "B-bitte schlag mich nicht nochmal,\n"
	.string "ich p-piss mich gleich ein.$"

MossdeepCity_Gym_Text_KathleenIntro:
	.string "Ich werde dich jetzt so hart ficken,\n"
	.string "dass du morgen noch nicht sitzen kannst!$"

MossdeepCity_Gym_Text_KathleenDefeat:
	.string "N-NEEEEEEIN! MEIN ARSCH!$"

MossdeepCity_Gym_Text_KathleenPostBattle:
	.string "Du bist ja komplett auf Koks!\n"
	.string "Verpiss dich aus meinen Augen, Psycho!$"

MossdeepCity_Gym_Text_CliffordIntro:
	.string "Ich bin vielleicht ein alter Sack, aber ich\n"
	.string "stopf dir trotzdem das Maul, Hurensohn!$"

MossdeepCity_Gym_Text_CliffordDefeat:
	.string "Fuck, ich bin echt zu alt für\n"
	.string "diesen Scheiß!$"

MossdeepCity_Gym_Text_CliffordPostBattle:
	.string "Du hast wohl zu viel Energy gesoffen.\n"
	.string "Mein Rücken fickt mich, lass mich in Ruhe.$"

MossdeepCity_Gym_Text_MaceyIntro:
	.string "Du kommst hier nicht vorbei!\n"
	.string "Ich polier dir die Fresse!$"

MossdeepCity_Gym_Text_MaceyDefeat:
	.string "Wie kann man nur so abartig stark\n"
	.string "sein, du Wichser?$"

MossdeepCity_Gym_Text_MaceyPostBattle:
	.string "Pah! Du bist vielleicht stark, aber du\n"
	.string "hast null verdammte Klasse!\p"
	.string "Du kämpfst wie so ein räudiger\n"
	.string "Straßenköter auf Crack!$"

MossdeepCity_Gym_Text_NicholasIntro:
	.string "WROOOAR! Friss meine verdammte\n"
	.string "Mega-Schwanz-Power!$"

MossdeepCity_Gym_Text_NicholasDefeat:
	.string "Uff!\n"
	.string "Direkt in die Eier!$"

MossdeepCity_Gym_Text_NicholasPostBattle:
	.string "Gut, gut. Dann bau ich mir halt 'nen\n"
	.string "Cyborg-Hund, der dich später zerfetzt.$"

MossdeepCity_Gym_Text_TateAndLizaIntro:
	.string "Svenja: Hehehe… Guckst du dumm?\p"
	.string "Ben: Fufufu… Hast dich eingeschissen?\p"
	.string "Svenja: Dass es hier zwei Leiter gibt?\n"
	.string "Ben: Dass wir zu zweit antreten?\p"
	.string "Svenja: Wir sind Zwillinge, Bitch!\n"
	.string "Ben: Genau, wir sind Zwillinge!\p"
	.string "Svenja: Wir müssen nicht mal labern…\n"
	.string "Ben: Weil wir genau wissen…\p"
	.string "Svenja: Wie wir dich ficken werden…\n"
	.string "Ben: Komplett per Telepathie!\p"
	.string "Svenja: Unsere Kombi…\n"
	.string "Ben: Zerstört dein Leben! Komm ran!$"

MossdeepCity_Gym_Text_TateAndLizaDefeat:
	.string "Svenja: Was zum Fick?! Unsere Kombi…\n"
	.string "Ben: Der hat uns einfach hops genommen!\p"
	.string "Svenja: Du bist ein kranker Bastard…\n"
	.string "Ben: Hier, nimm den Dreck und geh.$"

MossdeepCity_Gym_Text_ReceivedMindBadge:
	.string "{PLAYER} reißt Ben und Svenja den\n"
	.string "Seelenorden aus den blutigen Fingern.$"

MossdeepCity_Gym_Text_ExplainMindBadgeTakeThis:
	.string "Svenja: Der scheiß Seelenorden pumpt\n"
	.string "den Sp.-Ang und die Sp.-Ver auf.\p"
	.string "Ben: Und du kannst VM Taucher nutzen,\n"
	.string "falls du dich ertränken willst.\p"
	.string "Svenja: Den Müll hier kriegst du auch.$"

MossdeepCity_Gym_Text_ExplainCalmMind:
	.string "Svenja: In dieser schäbigen TM04 steckt…\n"
	.string "Ben: Gedankengut!\p"
	.string "Svenja: Macht den Sp.-Angriff dicker und…\n"
	.string "Ben: Die Sp.-Verfickung... äh, Verteidigung!\p"
	.string "Svenja: Ist halt perfekt für kranke…\n"
	.string "Ben: Psycho-Viecher!\p"
	.string "… … … … … …$"

MossdeepCity_Gym_Text_RegisteredTateAndLiza:
	.string "Die zwei Pisser Ben & Svenja wurden\n"
	.string "im Pokénav registriert.$"

MossdeepCity_Gym_Text_TateAndLizaPostBattle:
	.string "Svenja: Deine Pokémon haben wohl echt\n"
	.string "Bock auf dich. Das ist ja noch krasser\l"
	.string "als unsere Inzest-Connection.\p"
	.string "Ben: Du bist echt 'n mieser Motherfucker.\n"
	.string "Geh jetzt, bevor wir noch mehr heulen.$"

MossdeepCity_Gym_Text_TateAndLizaNeedTwoMons:
	.string "Svenja: Hehehe… Guckst du dumm?\p"
	.string "Ben: Weil wir zu zweit sind?\p"
	.string "Svenja: Alter, bist du behindert?\n"
	.string "Ben: Du hast ja nur ein verdammtes\l"
	.string "Pokémon dabei!\p"
	.string "Svenja: Verpiss dich und hol noch eins!\p"
	.string "Ben: Wenn du Stress willst, komm mit\n"
	.string "mindestens zwei Pokémon wieder, du Opfer.$"

MossdeepCity_Gym_Text_GymStatue:
	.string "Pokémon Arena von Moosbach City$"

MossdeepCity_Gym_Text_GymStatueCertified:
	.string "Pokémon Arena von Moosbach City\p"
	.string "Leute, die Ben & Svenja hart gefickt haben:\n"
	.string "{PLAYER}$"

MossdeepCity_Gym_Text_TateAndLizaPreRematch:
	.string "Ben: Pokémon…\n"
	.string "Svenja: Pokémon…\p"
	.string "Ben: Wenn man sein Hurensohn-Team ändert…\n"
	.string "Svenja: Ändert sich der ganze verdammte Kampf.\p"
	.string "Ben: Aber ich…\n"
	.string "Svenja: Aber ich…\p"
	.string "Ben: Ich werd Svenja für immer am Arsch kleben!\n"
	.string "Svenja: Und ich werd Ben weiter wie mein\l"
	.string "persönliches Bückstück behandeln!\p"
	.string "Ben: Unsere geisteskranke Psycho-Kombi…\n"
	.string "Svenja: Fickt dich in Grund und Boden,\l"
	.string "wieder und immer wieder!$"

MossdeepCity_Gym_Text_TateAndLizaRematchDefeat:
	.string "Ben: Du und deine verfickten Pokémon…\n"
	.string "Svenja: Ihr treibt es doch safe heimlich\l"
	.string "miteinander! Abartig!$"

MossdeepCity_Gym_Text_TateAndLizaPostRematch:
	.string "Ben: Du kannst uns auf die Fresse schlagen,\n"
	.string "aber wir bleiben nicht am Boden liegen!\p"
	.string "Svenja: Weil wir uns gegenseitig den\n"
	.string "Arsch retten, du kleiner Wichser!$"

MossdeepCity_Gym_Text_TateAndLizaRematchNeedTwoMons:
	.string "Ben: Du kommst echt wieder angekrochen…\n"
	.string "Svenja: Echt wieder angekrochen…\p"
	.string "Ben: Willst nochmal auf die Fresse kriegen.\n"
	.string "Svenja: Noch mehr Schläge kassieren.\p"
	.string "Ben: Aber…\n"
	.string "Svenja: Für unsere kleine Orgie hier…\p"
	.string "Ben: Hast du Spast nur ein Pokémon dabei!\n"
	.string "Svenja: Nur ein verdammtes Pokémon dabei!\p"
	.string "Ben: Zieh Leine und bring verdammt nochmal…\n"
	.string "Svenja: Mindestens zwei Viecher mit,\l"
	.string "du absoluter Vollversager.$"
