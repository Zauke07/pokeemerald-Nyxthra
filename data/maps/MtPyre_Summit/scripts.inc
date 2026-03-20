MtPyre_Summit_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

MtPyre_Summit_OnTransition:
	call_if_eq VAR_MT_PYRE_STATE, 2, MtPyre_Summit_EventScript_SetArchieMaxiePositions
	end

MtPyre_Summit_EventScript_SetArchieMaxiePositions::
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_MAXIE, 23, 6
	setobjectxyperm LOCALID_MT_PYRE_SUMMIT_ARCHIE, 22, 6
	end

MtPyre_Summit_EventScript_TeamAquaTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_TeamAquaExits
	end

MtPyre_Summit_EventScript_TeamAquaExits::
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieFacePlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieFacePlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieFacePlayer2
	msgbox MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_1
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_2
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_3
	removeobject LOCALID_MT_PYRE_SUMMIT_GRUNT_4
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	fadescreenswapbuffers FADE_FROM_BLACK
	delay 20
	setvar VAR_MT_PYRE_STATE, 1
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_OldLadyApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_OldLadyApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_OldLadyApproachPlayer2
	msgbox MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis, MSGBOX_DEFAULT
	giveitem ITEM_MAGMA_EMBLEM
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	releaseall
	end

MtPyre_Summit_EventScript_ArchieFacePlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer0
	waitmovement 0
	return

@ Archie is already facing player
MtPyre_Summit_EventScript_ArchieFacePlayer1::
	return

MtPyre_Summit_EventScript_ArchieFacePlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieFacePlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer0::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer0
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer1::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_OldLadyApproachPlayer2::
	applymovement LOCALID_MT_PYRE_SUMMIT_OLD_LADY, MtPyre_Summit_Movement_OldLadyApproachPlayer2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

MtPyre_Summit_Movement_OldLadyApproachPlayer0:
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer1:
	walk_down
	step_end

MtPyre_Summit_Movement_OldLadyApproachPlayer2:
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer0:
	walk_left
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_ArchieFacePlayer2:
	walk_right
	walk_in_place_faster_down
	step_end

MtPyre_Summit_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_OldManAfterRayquaza
	msgbox MtPyre_Summit_Text_WillYouHearOutMyTale, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManAfterRayquaza::
	msgbox MtPyre_Summit_Text_HearTheNewLegendOfHoenn, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, MtPyre_Summit_EventScript_OldManNewTale
	call_if_eq VAR_RESULT, NO, MtPyre_Summit_EventScript_DeclineOldManTale
	release
	end

MtPyre_Summit_EventScript_OldManTale::
	msgbox MtPyre_Summit_Text_GroudonKyogreTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_DeclineOldManTale::
	msgbox MtPyre_Summit_Text_WellThatTooIsFine, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldManNewTale::
	msgbox MtPyre_Summit_Text_HoennTrioTale, MSGBOX_DEFAULT
	return

MtPyre_Summit_EventScript_OldLady::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned
	call_if_ge VAR_MT_PYRE_STATE, 3, MtPyre_Summit_EventScript_OldLadyOrbsReturned
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_OldLadyLegendariesAwake
	msgbox MtPyre_Summit_Text_OrbsHaveBeenTaken, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyOrbsReturned::
	msgbox MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end

MtPyre_Summit_EventScript_OldLadyLegendariesAwake::
	msgbox MtPyre_Summit_Text_GroudonKyogreAwakened, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_OldLadyAfterOrbsReturned::
	msgbox MtPyre_Summit_Text_SuperAncientPokemonTaughtUs, MSGBOX_DEFAULT
	release
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger0::
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger1::
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieTrigger2::
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs
	end

MtPyre_Summit_EventScript_ArchieMaxieReturnOrbs::
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_ArchieMaxieBeginExit0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_ArchieMaxieBeginExit1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_ArchieMaxieBeginExit2
	playse SE_PIN
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachPlayer0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachPlayer1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachPlayer2
	msgbox MtPyre_Summit_Text_MaxieSilence, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, MtPyre_Summit_EventScript_MaxieApproachArchie0
	call_if_eq VAR_0x8008, 1, MtPyre_Summit_EventScript_MaxieApproachArchie1
	call_if_eq VAR_0x8008, 2, MtPyre_Summit_EventScript_MaxieApproachArchie2
	delay 30
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	removeobject LOCALID_MT_PYRE_SUMMIT_ARCHIE
	removeobject LOCALID_MT_PYRE_SUMMIT_MAXIE
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_ArchieMaxieBeginExit0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_ArchieMaxieBeginExit2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieExit
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieExit
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer0
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer1
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachPlayer2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerFaceMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, MtPyre_Summit_Movement_ArchieWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachPlayer2
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie0::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie0
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie1::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie1
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_MaxieApproachArchie2::
	applymovement LOCALID_PLAYER, MtPyre_Summit_Movement_PlayerWatchMaxie
	applymovement LOCALID_MT_PYRE_SUMMIT_MAXIE, MtPyre_Summit_Movement_MaxieApproachArchie2
	waitmovement 0
	applymovement LOCALID_MT_PYRE_SUMMIT_ARCHIE, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

MtPyre_Summit_Movement_PlayerFaceMaxie0:
	delay_16
	delay_16
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_PlayerFaceMaxie:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_ArchieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_MaxieExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit0:
	delay_16
	delay_8
	walk_left
	walk_in_place_faster_right
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit1:
	delay_16
	delay_8
	walk_right
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_PlayerWatchArchieMaxieExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer0:
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer1:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_MaxieApproachPlayer2:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

MtPyre_Summit_Movement_ArchieWatchMaxie:
	delay_16
	walk_in_place_faster_up
	step_end

MtPyre_Summit_Movement_PlayerWatchMaxie:
	delay_16
	walk_in_place_faster_down
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie0:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie1:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_Movement_MaxieApproachArchie2:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_left
	step_end

MtPyre_Summit_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_1, MtPyre_Summit_Text_Grunt1Intro, MtPyre_Summit_Text_Grunt1Defeat
	msgbox MtPyre_Summit_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt2::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_2, MtPyre_Summit_Text_Grunt2Intro, MtPyre_Summit_Text_Grunt2Defeat
	msgbox MtPyre_Summit_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_3, MtPyre_Summit_Text_Grunt3Intro, MtPyre_Summit_Text_Grunt3Defeat
	msgbox MtPyre_Summit_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MT_PYRE_4, MtPyre_Summit_Text_Grunt4Intro, MtPyre_Summit_Text_Grunt4Defeat
	msgbox MtPyre_Summit_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_Summit_Text_Grunt1Intro::
	.string "{COLOR BLUE}Verdammt! Diese MAGMA-Idioten waren\n"
	.string "tatsächlich vor uns hier!\p"
	.string "Wir dürfen uns von diesen Lappen nicht\n"
	.string "abhängen lassen!{COLOR WHITE}$"

MtPyre_Summit_Text_Grunt1Defeat::
	.string "{COLOR BLUE}Ich dachte, du wärst einer von den\n"
	.string "MAGMAS, der zu dumm zum Weglaufen war…{COLOR WHITE}$"

MtPyre_Summit_Text_Grunt1PostBattle::
	.string "{COLOR BLUE}Ja, ja, du kannst kämpfen… Aber wir\n"
	.string "haben noch 'ne ganze Armee am Start!{COLOR WHITE}$"

MtPyre_Summit_Text_Grunt2Intro::
	.string "{COLOR BLUE}Hah! Pech für dich, Kleiner!\p"
	.string "Wärst du früher gekommen, hättest du\n"
	.string "nur gegen Team Magma kämpfen müssen.\p"
	.string "Aber jetzt hast du die Ehre, von den\n"
	.string "echten Kerlen vermöbelt zu werden!{COLOR WHITE}$"

MtPyre_Summit_Text_Grunt2Defeat::
	.string "{COLOR BLUE}Urgh… Ich hätte dich erst Team Magma\n"
	.string "abfertigen lassen sollen…{COLOR WHITE}$"

MtPyre_Summit_Text_Grunt2PostBattle::
	.string "{COLOR BLUE}Du hast doch keine Ahnung!\n"
	.string "Warum mischt du dich überhaupt ein?{COLOR WHITE}$"

MtPyre_Summit_Text_Grunt3Intro::
	.string "{COLOR BLUE}Dich Kenn ich doch…\n"
	.string "Du hast am SCHORNSTEINBERG genervt.\p"
	.string "Du gehörst zu keinem Verein, also was\n"
	.string "willst du hier auf dem Friedhof?{COLOR WHITE}$"

MtPyre_Summit_Text_Grunt3Defeat::
	.string "{COLOR BLUE}Wenn du unbedingt jemanden stressen\n"
	.string "willst, dann geh zu TEAM MAGMA…{COLOR WHITE}$"

MtPyre_Summit_Text_Grunt3PostBattle::
	.string "{COLOR BLUE}Heh, egal! Wir haben genug Zeit\n"
	.string "geschunden!\p"
	.string "Der BOSS sollte sich das Teil jetzt\n"
	.string "unter den Nagel gerissen haben!{COLOR WHITE}$"

MtPyre_Summit_Text_Grunt4Intro::
	.string "{COLOR BLUE}Oh, ich weiß es!\n"
	.string "Du wolltest bei Team Magma mitmachen,\l"
	.string "aber die wollten dich nicht mal geschenkt!\p"
	.string "Glaub bloß nicht, dass wir bei\n"
	.string "TEAM AQUA jeden Versager nehmen!{COLOR WHITE}$"

MtPyre_Summit_Text_Grunt4Defeat::
	.string "{COLOR BLUE}Na gut, wenn du unbedingt zu uns willst,\n"
	.string "könnten wir drüber reden… vielleicht.{COLOR WHITE}$"

MtPyre_Summit_Text_Grunt4PostBattle::
	.string "{COLOR BLUE}Wir sind ein unschlagbares Team,\n"
	.string "solange der Boss uns sagt, was wir tun!{COLOR WHITE}$"

MtPyre_Summit_Text_ArchieWeGotTheOrbLetsGo::
	.string "{COLOR BLUE}ADRIAN: Team Magma war zwar schneller,\n"
	.string "aber wir haben auch, was wir wollten.\p"
	.string "Die ROTE KUGEL vom PYROBERG…\n"
	.string "Ich, ADRIAN, hab sie jetzt im Sack!\p"
	.string "Fufufu… Jetzt können wir unseren Plan\n"
	.string "endlich durchziehen!\p"
	.string "Abflug, Leute!\n"
	.string "Wir verschwinden!{COLOR WHITE}$"

MtPyre_Summit_Text_BothOrbsTakenMagmaLeftThis::
	.string "Oh, nein…\n"
	.string "Das darf doch nicht wahr sein…\p"
	.string "Nicht nur die BLAUE KUGEL, sondern\n"
	.string "auch noch die ROTE KUGEL weg…\p"
	.string "Die Kugeln gehören zusammen. Wenn man\n"
	.string "sie trennt, gibt's richtig Ärger.\p"
	.string "Was wollen diese Spinner bloß mit\n"
	.string "den zwei Dingern anstellen?\p"
	.string "…… …… …… ……\n"
	.string "…… …… …… ……\p"
	.string "Ach ja. Team Magma war zuerst hier und\n"
	.string "hat die BLAUE KUGEL geklaut.\p"
	.string "Dabei haben diese Hektiker das hier\n"
	.string "einfach liegen lassen.\p"
	.string "Keine Ahnung, was das für'n Schrott ist.\p"
	.string "Hier, nimm's mit. Vielleicht kannst du\n"
	.string "damit ja irgendwas anfangen.$"

MtPyre_Summit_Text_OrbsHaveBeenTaken::
	.string "Diese kriminellen Typen haben beide\n"
	.string "Kugeln mitgehen lassen…\p"
	.string "Das wird böse enden… Ich hab echt\n"
	.string "Schiss, dass die Welt jetzt untergeht…$"

MtPyre_Summit_Text_GroudonKyogreAwakened::
	.string "Ach du heilige Sch…\p"
	.string "Du sagst, dass sowohl GROUDON als auch\n"
	.string "KYOGRE aufgewacht sind?\p"
	.string "Die Legende sagt, dass die Kugeln den\n"
	.string "Zorn der beiden Viecher bändigen…\p"
	.string "Es heißt auch, dass es einen wahren\n"
	.string "Besitzer der Kugeln gibt.\p"
	.string "Aber keiner weiß, wer das sein soll.\p"
	.string "Vielleicht ein Mensch, vielleicht ein\n"
	.string "POKéMON… keine Ahnung.$"

MtPyre_Summit_Text_ThoseTwoMenReturnedOrbs::
	.string "Die zwei Typen haben die Kugeln\n"
	.string "tatsächlich freiwillig zurückgebracht.\p"
	.string "Vielleicht sind sie doch nicht so\n"
	.string "kaputt im Kopf, wie ich dachte…$"

MtPyre_Summit_Text_SuperAncientPokemonTaughtUs::
	.string "Land, Meer und Himmel…\p"
	.string "Das sind die Identitäten dieser\n"
	.string "uralten Monster-POKéMON…\p"
	.string "Genau wie wir und die POKéMON lebt,\n"
	.string "lebt auch unsere Welt…\p"
	.string "Diese Urzeit-Viecher haben uns das\n"
	.string "auf die harte Tour beigebracht…$"

MtPyre_Summit_Text_WillYouHearOutMyTale::
	.string "Der PYROBERG ist der Ort, an dem wir\n"
	.string "tote POKéMON-Geister beruhigen…\p"
	.string "Hier oben hat man 'nen fetten Ausblick\n"
	.string "über ganz HOENN…\p"
	.string "Ein guter Ort für die Geister, um\n"
	.string "endlich die Klappe zu halten…\p"
	.string "Ist es Zufall, dass du hier bist?\p"
	.string "Willst du dir meine Story anhören?\n"
	.string "Ist ein Klassiker hier in HOENN.$"

MtPyre_Summit_Text_GroudonKyogreTale::
	.string "Das ist schon ewig her…\p"
	.string "Die Welt wurde fast zerlegt, weil das\n"
	.string "Land-Vieh und das Meer-Vieh sich\l"
	.string "gegenseitig auf die Fresse gaben…\p"
	.string "Das Land-Vieh hat Berge hochgezogen\n"
	.string "und Kontinente erschaffen…\p"
	.string "Das Meer-Vieh hat fette Wellen gemacht\n"
	.string "und Ozeane ausgegraben…\p"
	.string "Der Kampf ging ohne Ende weiter.\p"
	.string "Überall gab's Feuer und heftige Stürme.\p"
	.string "Erst die BLAUE und die ROTE KUGEL haben\n"
	.string "das Massaker beendet.\p"
	.string "Ein krasses Licht kam aus den Kugeln\n"
	.string "und hat die beiden beruhigt.\p"
	.string "Danach sind sie im Meer abgetaucht und\n"
	.string "endlich verschwunden…$"

MtPyre_Summit_Text_WellThatTooIsFine::
	.string "Ach so…\n"
	.string "Na ja, dann eben nicht…$"

MtPyre_Summit_Text_MaxieSilence::
	.string "{COLOR RED}MARC: {PLAYER}…\p"
	.string "…… …… …… ……\n"
	.string "…… …… …… ……{COLOR WHITE}$"

MtPyre_Summit_Text_HearTheNewLegendOfHoenn::
	.string "Es ist mein Job, die Legenden von\n"
	.string "HOENN an die nächste Brut weiterzugeben.\p"
	.string "Und die Krise in XENEROVILLE hat die\n"
	.string "Legende gerade neu geschrieben…\p"
	.string "Hast du Zeit für die neue Version?$"

MtPyre_Summit_Text_HoennTrioTale::
	.string "Das ist ewig her…\p"
	.string "Land-Monster und Meer-Monster haben\n"
	.string "sich bis aufs Blut bekämpft…\p"
	.string "Berge wurden hochgezogen, Ozeane\n"
	.string "ausgehoben, das volle Programm…\p"
	.string "Der Krieg hörte einfach nicht auf.\p"
	.string "Die Welt brannte und soff gleichzeitig\n"
	.string "in Stürmen ab.\p"
	.string "Da kam das POKéMON des Himmels aus\n"
	.string "einem fetten Gewitter runtergekracht.\p"
	.string "Das Teil war giftgrün und hat die\n"
	.string "beiden Streithähne zur Räson gebracht.\p"
	.string "Danach ist das grüne Ding wieder\n"
	.string "nach oben abgezischt…$"

MtPyre_Summit_EventScript_Kwaks::
	specialvar VAR_RESULT, IsWildRandomizerEnabled
	goto_if_eq VAR_RESULT, TRUE, MtPyre_Summit_EventScript_Kwaks_RandomizerText
	msgbox MtPyre_Summit_Text_Kwaks, MSGBOX_NPC
	end

MtPyre_Summit_EventScript_Kwaks_RandomizerText::
	msgbox MtPyre_Summit_Text_KwaksRandomizer, MSGBOX_NPC
	end

MtPyre_Summit_Text_Kwaks:
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 7 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

MtPyre_Summit_Text_KwaksRandomizer:
	.string "Tipp:\p"
	.string "Wild-Randomizer ist aktiv.\n"
	.string "Der feste 1%-Starter-Hinweis\l"
	.string "gilt deshalb hier nicht.\p"
	.string "Die Wild-Spawns werden über deinen\n"
	.string "Seed neu gemappt!$"
