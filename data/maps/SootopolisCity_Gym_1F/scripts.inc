SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement LOCALID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_SOOTOPOLIS_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_WALLACE
	setvar VAR_SOOTOPOLIS_CITY_STATE, 6
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SOOTOPOLIS_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Yo! Was geht, du Tryharder?\n"
	.string "Auf dem Weg zum Champ, {PLAYER}?\p"
	.string "Juans Arena ist komplett auf Wasser\n"
	.string "aufgebaut, also pass auf deinen Arsch auf.\p"
	.string "Um zu dem Schönling zu kommen, musst du\n"
	.string "über so einen beschissenen Eisboden…\p"
	.string "Sorry, mehr Tipps hab ich nicht für dich.\n"
	.string "Rutsch einfach nicht aus, du Noob!\p"
	.string "Den Rest musst du schon selbst carrien!$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Krank! Du hast einfach Juan in den\n"
	.string "Boden gestampft. Der Typ hielt sich\l"
	.string "echt für den King von Hoenn!\p"
	.string "Check mal deine Trainer-Card ab!\p"
	.string "Wenn du alle Orden hast, kannst du\n"
	.string "direkt in die Pokémon-Liga reinpushen!$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Lass mich dich was fragen, du Lappen.\n"
	.string "Wusstest du das schon?\l"
	.string "Ach, ich brauche nicht bescheiden zu tun.\p"
	.string "Ich war es, der Wassili beigebracht hat,\n"
	.string "wie man nicht wie ein kompletter Noob\l"
	.string "spielt.\p"
	.string "Eigentlich hatte ich meinen Job als\n"
	.string "Leiter schon längst an den Nagel gehängt.\p"
	.string "Aber jemand musste Wassilis Platz ein-\n"
	.string "nehmen, weil der Typ lieber Champ spielt.\p"
	.string "Aber genug gelabert.\n"
	.string "Lass uns die Scheiße hinter uns bringen.\p"
	.string "Mach dich bereit, von meiner perfekten\n"
	.string "Wasser-Kunst weggespült zu werden!$"

@ Text gekürzt, um den Vanilla-Buffer-Overflow zu verhindern.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "Ahahaha! Ein Glitch!\n"
	.string "Na gut, du hast wohl gewonnen.\p"
	.string "Du hast zwar Skills, aber im Vergleich\n"
	.string "zu mir siehst du aus wie ein Bauer.\p"
	.string "Hier, nimm diesen dreckigen Schauerorden\n"
	.string "und verschwinde aus meinen Augen.$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} hat sich den Schauerorden\n"
	.string "von Juan gegrabbt.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Mit dem Schauerorden im Gepäck hören\n"
	.string "jetzt alle Pokémon auf deine Befehle.\p"
	.string "Und du kannst Kaskade benutzen, um\n"
	.string "Wasserfälle hochzupushen.\p"
	.string "Damit du diese Demütigung nie vergisst,\n"
	.string "nimm noch diesen Müll hier mit…$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "Die TM, die ich dir zugeworfen habe,\n"
	.string "enthält Aquawelle.\p"
	.string "Die ballert den Gegnern Ultraschall in\n"
	.string "den Kopf und verwirrt sie komplett.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "Gym-Leader Juan wurde in den PokéNav\n"
	.string "reingeklatscht.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "Jeder Tryharder, der alle Orden aus\n"
	.string "Hoenn zusammengesammelt hat, sollte\l"
	.string "sich jetzt zur Liga verpissen.\p"
	.string "Ganz im Osten von Hoenn, auf der Insel\n"
	.string "Prachtpolis City.\p"
	.string "Dort wartet die Pokémon-Liga auf dich.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Dir fehlt noch ein scheiß Orden aus\n"
	.string "Hoenn, du Anfänger.\p"
	.string "Wenn du in die Liga willst, musst du dir\n"
	.string "erst den Orden aus Baumhausen holen.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "Pokémon-Arena Xeneroville$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "Pokémon-Arena Xeneroville\p"
	.string "Juans zertifizierte Tryharder:\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "Juan: Ah, meine Arena war gerade so\n"
	.string "schön chillig…\p"
	.string "Aber unser kleiner Tryharder ist zurück,\n"
	.string "um sich noch eine Abreibung zu holen!\p"
	.string "Von mir aus, du nerviger Stalker!\p"
	.string "Ich werde dich gerne nochmal komplett\n"
	.string "nassmachen!$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahaha, schon wieder weggeluckt!\n"
	.string "Du hast mich echt nochmal besiegt!$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "Juan: Wenn ich dich fragen würde, ob\n"
	.string "du mein Sklave werden willst, würdest\l"
	.string "du sicher ablehnen.\p"
	.string "Ich würde dir ja meine geile Jacke\n"
	.string "schenken…\p"
	.string "Aber die ist dir eh viel zu teuer.\n"
	.string "Verpiss dich jetzt lieber.$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "Juan: Ah, meine Arena war gerade\n"
	.string "so schön chillig…\p"
	.string "Aber der kleine Tryharder ist\n"
	.string "zurück für die nächste Klatsche!\p"
	.string "Von mir aus…\n"
	.string "Ich mach dich gerne nochmal-\p"
	.string "Moment mal, du Bauer.\n"
	.string "Du hast ja nur ein Pokémon dabei.\p"
	.string "Komm mit mindestens zwei Viechern\n"
	.string "wieder, sonst ist das zu blöd.$"

