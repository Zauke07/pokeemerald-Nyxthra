GraniteCave_B4F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GraniteCave_B4F_OnLoad
	.byte 0

GraniteCave_B4F_OnLoad:
	end

GraniteCave_B4F_EventScript_IntroTrigger::
	lockall
	checkflag FLAG_TRIGGER_GRANITECAVE_B4F_INTRO
	goto_if_eq GraniteCave_B4F_EventScript_IntroAlreadyDone
	msgbox GraniteCave_B4F_Text_Intro, MSGBOX_DEFAULT
	setflag FLAG_TRIGGER_GRANITECAVE_B4F_INTRO
	releaseall
	end

GraniteCave_B4F_EventScript_IntroAlreadyDone::
	releaseall
	end

GraniteCave_B4F_Text_Intro:
	.string "{PLAYER}: Wow, die Höhle hier sieht\n"
	.string "aber lang aus…\p"
	.string "Was mich am Ende wohl erwartet?$"
