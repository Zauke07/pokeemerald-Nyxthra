Rival_Test_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Rival_Test_OnTransition
	.byte 0

Rival_Test_OnTransition:
	end

EventScript_RivalTest_Red::
	trainerbattle_single TRAINER_RIVAL_TEST_RED, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Leaf::
	trainerbattle_single TRAINER_RIVAL_TEST_LEAF, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Ethan::
	trainerbattle_single TRAINER_RIVAL_TEST_ETHAN, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Lyra::
	trainerbattle_single TRAINER_RIVAL_TEST_LYRA, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Lucas::
	trainerbattle_single TRAINER_RIVAL_TEST_LUCAS, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Dawn::
	trainerbattle_single TRAINER_RIVAL_TEST_DAWN, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Hilbert::
	trainerbattle_single TRAINER_RIVAL_TEST_HILBERT, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Hilda::
	trainerbattle_single TRAINER_RIVAL_TEST_HILDA, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Nate::
	trainerbattle_single TRAINER_RIVAL_TEST_NATE, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Rosa::
	trainerbattle_single TRAINER_RIVAL_TEST_ROSA, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Calem::
	trainerbattle_single TRAINER_RIVAL_TEST_CALEM, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Serena::
	trainerbattle_single TRAINER_RIVAL_TEST_SERENA, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Elio::
	trainerbattle_single TRAINER_RIVAL_TEST_ELIO, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Selene::
	trainerbattle_single TRAINER_RIVAL_TEST_SELENE, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Victor::
	trainerbattle_single TRAINER_RIVAL_TEST_VICTOR, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Gloria::
	trainerbattle_single TRAINER_RIVAL_TEST_GLORIA, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Florian::
	trainerbattle_single TRAINER_RIVAL_TEST_FLORIAN, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Juliana::
	trainerbattle_single TRAINER_RIVAL_TEST_JULIANA, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_Brendan::
	trainerbattle_single TRAINER_RIVAL_TEST_BRENDAN, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

EventScript_RivalTest_May::
	trainerbattle_single TRAINER_RIVAL_TEST_MAY, Text_RivalTest_Intro, Text_RivalTest_Defeated
	msgbox Text_RivalTest_After, MSGBOX_AUTOCLOSE
	end

Text_RivalTest_Intro::
	.string "Test.$"

Text_RivalTest_Defeated::
	.string "Fertig.$"

Text_RivalTest_After::
	.string "Ok, ist ja eh nur ein Test.$"

