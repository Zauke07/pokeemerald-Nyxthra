LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId_FromPlayerStyle
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL, 11, 9
	setobjectxyperm LOCALID_LAVARIDGE_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_LAVARIDGE_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_LAVARIDGE_TOWN_STATE, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	lockall
	call Common_EventScript_SetupRivalMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	
	goto_if_eq VAR_RESULT, STYLE_BRENDAN, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_MAY, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_RED, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_LEAF, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_ETHAN, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_LYRA, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_LUCAS, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_DAWN, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_HILBERT, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, STYLE_HILDA, LavaridgeTown_EventScript_BrendanGiveGoGoggles
@	 goto_if_eq VAR_RESULT, STYLE_NATE, LavaridgeTown_EventScript_MayGiveGoGoggles
@	 goto_if_eq VAR_RESULT, STYLE_ROSA, LavaridgeTown_EventScript_BrendanGiveGoGoggles
@	goto_if_eq VAR_RESULT, STYLE_CALEM, LavaridgeTown_EventScript_MayGiveGoGoggles
@	goto_if_eq VAR_RESULT, STYLE_SERENA, LavaridgeTown_EventScript_BrendanGiveGoGoggles
@	goto_if_eq VAR_RESULT, STYLE_ELIO, LavaridgeTown_EventScript_MayGiveGoGoggles
@	goto_if_eq VAR_RESULT, STYLE_SELENE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
@	goto_if_eq VAR_RESULT, STYLE_VICTOR, LavaridgeTown_EventScript_MayGiveGoGoggles
@	goto_if_eq VAR_RESULT, STYLE_GLORIA, LavaridgeTown_EventScript_BrendanGiveGoGoggles
@	goto_if_eq VAR_RESULT, STYLE_FLORIAN, LavaridgeTown_EventScript_MayGiveGoGoggles
@	goto_if_eq VAR_RESULT, STYLE_JULIANA, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_LAVARIDGE_RIVAL
	addobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_LAVARIDGE_RIVAL_ON_BIKE
	setvar VAR_LAVARIDGE_TOWN_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_LAVARIDGE_RIVAL
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_LAVARIDGE_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_LAVARIDGE_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement LOCALID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_LAVARIDGE_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis::
	.string "{COLOR RIVAL_CLR}{RIVAL}: {PLAYER}{KUN}! Dass ich dich hier\n"
	.string "treffen muss, versaut mir echt den Tag.\p"
	.string "Oh? Während ich mich in den Quellen\n"
	.string "amüsiert habe, hast du dir den Orden\n"
	.string "erschlichen? Glück muss man haben.\p"
	.string "Hast wohl im Lotto gewonnen und dir\n"
	.string "ein paar starke POKéMON gekauft…\l"
	.string "Oder hast du sie tatsächlich trainiert?\p"
	.string "Egal, nimm das hier, bevor du in der\n"
	.string "Wüste noch jämmerlich krepierst.{COLOR DARK_GRAY}$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad::
	.string "{COLOR RIVAL_CLR}{RIVAL}: Mit diesen GO-GOGGLES heulst\n"
	.string "du wenigstens nicht rum, wenn dir der\n"
	.string "Sand in die Augen fliegt.\p"
	.string "Aber mal im Ernst, {PLAYER}{KUN}…\n"
	.string "Du und Orden sammeln…\p"
	.string "Du versuchst es echt krampfhaft, nur\n"
	.string "damit ich dich nicht wieder auslache!\p"
	.string "{PLAYER}{KUN}, ich geh jetzt mal zu deinem\n"
	.string "Vadda in die ARENA von Blütenburg City.\p"
	.string "Der kann mir wenigstens einen echten\n"
	.string "Kampf bieten. Ciao!{COLOR DARK_GRAY}$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis::
	.string "{COLOR RIVAL_CLR}{RIVAL}: {PLAYER}, hey. Musste das sein?\n"
	.string "Sogar hier muss ich deine Fratze sehen.\p"
	.string "Hmm…\n"
	.string "Ein paar Orden hast du ja gesammelt.\n"
	.string "Muss wohl an der miesen KI liegen.\p"
	.string "Na gut.\n"
	.string "Nimm den Schrott hier, ich hab eh zwei.{COLOR DARK_GRAY}$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad::
	.string "{COLOR RIVAL_CLR}{RIVAL}: Steck die Brille ein, wenn du\n"
	.string "in der Wüste nicht blind werden willst.\p"
	.string "Da gibt's POKéMON, die nur dort im Dreck\n"
	.string "hocken. Kannst ja mal danach buddeln.\p"
	.string "Ich hab Wichtigeres vor…\n"
	.string "Ich werd deinen Vadda herausfordern,\l"
	.string "den Boss von Blütenburg City.\p"
	.string "Ganz ehrlich, {PLAYER}, ich frag mich echt,\n"
	.string "ob du adoptiert bist. Dein Alter sieht\l"
	.string "nämlich nach was aus, im Gegensatz zu dir.\p"
	.string "Man sieht sich!{COLOR DARK_GRAY}$"

LavaridgeTown_Text_HaveEggWillYouTakeIt::
	.string "Ich hab hier so ’n EI rumliegen.\p"
	.string "Ich dachte, wenn ich es im heißen Sand\n"
	.string "vergrabe, schlüpft es schneller. War wohl\l"
	.string "nichts. Jetzt hab ich keine Lust mehr drauf.\p"
	.string "Man sagt, es braucht Bewegung und\n"
	.string "andere POKéMON um sich rum.\p"
	.string "Du siehst aus, als hättest du eh nichts\n"
	.string "Besseres zu tun.\n"
	.string "Willst du den Ballast hier mitschleppen?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg::
	.string "Gut! Dann beweg mal deinen Hintern\n"
	.string "und bring das Ding zum Schlüpfen!$"

LavaridgeTown_Text_NoRoomForThisEgg::
	.string "Häh? Dein Team ist voll. Ich behalt\n"
	.string "den Müll doch nicht für dich auf!$"

LavaridgeTown_Text_AsYouWishThen::
	.string "Wie du meinst…\p"
	.string "Dann gammelt das EI halt weiter hier\n"
	.string "rum. Wenn du deine Meinung änderst,\n"
	.string "weißt du ja, wo ich hocke.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare::
	.string "In der Pension finden sie ständig EIER.\p"
	.string "Keine Ahnung, was die POKéMON da\n"
	.string "treiben, wenn keiner hinguckt.$"

LavaridgeTown_Text_HotSpringsNeverRunDry::
	.string "Wir pumpen hier ohne Ende Wasser ab,\n"
	.string "und trotzdem versiegt das Zeug nie.\p"
	.string "Ziemlich unheimlich, wenn du mich fragst.\p"
	.string "Unter uns blubbert Magma und erhitzt\n"
	.string "die ganze Brühe. Hoffentlich fliegen wir\n"
	.string "nicht irgendwann in die Luft.$"

LavaridgeTown_Text_PokemonNippedBackside::
	.string "Sich hier im Sand einbuddeln zu lassen…\p"
	.string "Einfach nur geil… seufz…\p"
	.string "Häh? GYAah! VERDAMMT!\p"
	.string "Irgendein Mistvieh hat mir gerade voll\n"
	.string "in den Arsch gebissen!$"

LavaridgeTown_Text_OhYouLikeHotSprings::
	.string "Was? Du hängst auch in heißen Quellen\n"
	.string "rum?\p"
	.string "Bist du nicht ein bisschen zu jung,\n"
	.string "um hier wie ’n alter Sack zu entspannen?$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay::
	.string "Ich hock hier jeden Tag im Wasser.\p"
	.string "Vielleicht werd ich dann auch mal so\n"
	.string "ne heiße Braut wie Flavia.$"

LavaridgeTown_Text_IfPokemonInHotSprings::
	.string "Stell dir mal vor, Leute würden ihre\n"
	.string "POKéMON hier einfach reinschmeißen.\p"
	.string "Ein Elektro-Bad wär der absolute Killer.\n"
	.string "Oder direkt ein Lava-Bad… autsch.$"

LavaridgeTown_Text_HotSpringsClaims::
	.string "Die behaupten ja, das Wasser hier heilt\n"
	.string "alles: Stress, Muskelkater, Liebeskummer\n"
	.string "und Geldnot… Wer’s glaubt, wird selig.$"

LavaridgeTown_Text_TownSign::
	.string "Bad Lavastadt\p"
	.string "“POKéMON CENTER & HEIßE QUELLEN\n"
	.string "Hier kannst du deine Wunden lecken!”$"

LavaridgeTown_Text_GymSign::
	.string "ARENA von Bad Lavastadt\n"
	.string "LEITERIN: Flavia\l"
	.string "“Vorsicht: Verbrennungsgefahr für Lappen!”$"

LavaridgeTown_Text_HerbShopSign::
	.string "POKéMON-KRÄUTERLADEN\n"
	.string "“Schmeckt scheiße, hilft aber - vielleicht!”$"

LavaridgeTown_Text_ReceivedTheEgg::
	.string "{PLAYER} hat das EI von der alten\n"
	.string "Schachtel übernommen!$"
