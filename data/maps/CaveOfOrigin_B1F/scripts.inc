CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_CAVE_OF_ORIGIN_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_SOOTOPOLIS_CITY_STATE, 3
	removeobject LOCALID_CAVE_OF_ORIGIN_WALLACE
	clearflag FLAG_HIDE_SKY_PILLAR_WALLACE
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Ah, du bist also {PLAYER}{KUN}? Ich\n"
	.string "habe Geschichten über deine Taten\l"
	.string "gehört.\p"
	.string "Mein Name ist WASSILI.\p"
	.string "Ich war einmal Arenaleiter von\n"
	.string "XENEROVILLE, aber es kam etwas\l"
	.string "dazwischen.\p"
	.string "Darum habe ich meinen Mentor JUAN mit\n"
	.string "der Leitung der Arena betraut.\p"
	.string "… … … … … … … … … … … …\p"
	.string "GROUDON und KYOGRE, die beiden\n"
	.string "Pokémon, die hier Chaos stiften, gelten\l"
	.string "als uralte Pokémon.\p"
	.string "Aber es gibt nicht nur zwei uralte\n"
	.string "Pokémon.\p"
	.string "Es gibt noch eines, irgendwo.\p"
	.string "Irgendwo gibt es ein uraltes Pokémon\n"
	.string "namens RAYQUAZA.\p"
	.string "Es heißt, RAYQUAZA habe die beiden\n"
	.string "Kontrahenten in ferner Vergangenheit\l"
	.string "besänftigt.\p"
	.string "Aber selbst ich habe keine Ahnung, wo\n"
	.string "sich RAYQUAZA aufhält…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "WASSILI: {PLAYER}{KUN}, weißt du\n"
	.string "vielleicht, wo RAYQUAZA gerade ist?\p"
	.string "Falls ja, sag es mir bitte.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "WASSILI: Die URZEITHÖHLE?\p"
	.string "Aber die ist doch genau hier!\n"
	.string "Da musst du dir mehr Mühe geben!\p"
	.string "Bitte denk darüber nach, wo\n"
	.string "RAYQUAZA gerade sein könnte.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "WASSILI: Der PYROBERG?\p"
	.string "Aber als ich dort vorhin die alte Dame\n"
	.string "getroffen habe, hat sie nichts\l"
	.string "erwähnt.\p"
	.string "Ich bezweifle sehr, dass die alte Dame\n"
	.string "etwas vor mir verbergen würde…\p"
	.string "{PLAYER}{KUN}, könntest du noch\n"
	.string "einmal genauer darüber nachdenken?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "WASSILI: Hä? Du erinnerst dich nicht?\n"
	.string "Hmm… Das ist ein Problem…\p"
	.string "Kannst du dich nicht irgendwie\n"
	.string "erinnern?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "WASSILI: Der HIMMELTURM?\p"
	.string "Genau! Das muss der HIMMELTURM sein!\p"
	.string "{PLAYER}{KUN}, wir haben keine Zeit\n"
	.string "zu verlieren! Wir brechen sofort zum\l"
	.string "HIMMELTURM auf!$"

