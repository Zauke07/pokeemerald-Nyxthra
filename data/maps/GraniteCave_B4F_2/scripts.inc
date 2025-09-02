GraniteCave_B4F_2_MapScripts::
	.byte 0

GraniteCave_B4F_2_EventScript_RocketM1::
	msgbox GraniteCave_B4F_2_Text_RocketM1_BattleStart, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_ROCKET_M_1, GraniteCave_B4F_2_Text_RocketM1_BattleStart, GraniteCave_B4F_2_Text_RocketM1_Defeated
	msgbox GraniteCave_B4F_2_Text_AfterBattle_Generic, MSGBOX_DEFAULT
	end

GraniteCave_B4F_2_EventScript_RocketF1::
	msgbox GraniteCave_B4F_2_Text_RocketF1_BattleStart, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_ROCKET_F_1, GraniteCave_B4F_2_Text_RocketF1_BattleStart, GraniteCave_B4F_2_Text_RocketF1_Defeated
	msgbox GraniteCave_B4F_2_Text_AfterBattle_Generic, MSGBOX_DEFAULT
	end

GraniteCave_B4F_2_EventScript_RocketF2::
	msgbox GraniteCave_B4F_2_Text_RocketF2_BattleStart, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_ROCKET_F_2, GraniteCave_B4F_2_Text_RocketF2_BattleStart, GraniteCave_B4F_2_Text_RocketF2_Defeated
	msgbox GraniteCave_B4F_2_Text_AfterBattle_Generic, MSGBOX_DEFAULT
	end

GraniteCave_B4F_2_EventScript_RocketM2::
	msgbox GraniteCave_B4F_2_Text_RocketM2_BattleStart, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_ROCKET_M_2, GraniteCave_B4F_2_Text_RocketM2_BattleStart, GraniteCave_B4F_2_Text_RocketM2_Defeated
	msgbox GraniteCave_B4F_2_Text_AfterBattle_Generic, MSGBOX_DEFAULT
	end

GraniteCave_B4F_2_EventScript_RocketM3::
	msgbox GraniteCave_B4F_2_Text_RocketM3_BattleStart, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_ROCKET_M_3, GraniteCave_B4F_2_Text_RocketM3_BattleStart, GraniteCave_B4F_2_Text_RocketM3_Defeated
	msgbox GraniteCave_B4F_2_Text_AfterBattle_Generic, MSGBOX_DEFAULT
	end

GraniteCave_B4F_2_EventScript_RocketF3::
	msgbox GraniteCave_B4F_2_Text_RocketF3_BattleStart, MSGBOX_DEFAULT
	trainerbattle_single TRAINER_ROCKET_F_3, GraniteCave_B4F_2_Text_RocketF3_BattleStart, GraniteCave_B4F_2_Text_RocketF3_Defeated
	msgbox GraniteCave_B4F_2_Text_AfterBattle_Generic, MSGBOX_DEFAULT
	end

GraniteCave_B4F_2_Text_RocketM1_BattleStart:
	.string "Hey, was machst du hier?\p"
	.string "Das ist unser Revier!$"

GraniteCave_B4F_2_Text_RocketM1_Defeated:
	.string "Unglaublich… du hast mich besiegt!$"

GraniteCave_B4F_2_Text_RocketF1_BattleStart:
	.string "Ich würde dir raten, dich nicht\n"
	.string "mit uns anzulegen!$"

GraniteCave_B4F_2_Text_RocketF1_Defeated:
	.string "Verdammt… ich habe dich unterschätzt…$"

GraniteCave_B4F_2_Text_RocketF2_BattleStart:
	.string "Ist dir was aufgefallen?\p"
	.string "Hier in der Höhle?$"

GraniteCave_B4F_2_Text_RocketF2_Defeated:
	.string "Ugh… du bist wirklich aufmerksam…$"

GraniteCave_B4F_2_Text_RocketM2_BattleStart:
	.string "Es gibt hier keine wilden Pokémon!\p"
	.string "Dank uns! Haha!$"

GraniteCave_B4F_2_Text_RocketM2_Defeated:
	.string "Mist… ich hätte leiser lachen sollen…$"

GraniteCave_B4F_2_Text_RocketM3_BattleStart:
	.string "Du musst ja stark sein, wenn du\n"
	.string "schon bei mir bist!$"

GraniteCave_B4F_2_Text_RocketM3_Defeated:
	.string "Wie kann das sein… ich war sicher!$"

GraniteCave_B4F_2_Text_RocketF3_BattleStart:
	.string "Unser Auftrag ist es, in Hoenn\n"
	.string "die seltenen Pokémon von Trainern\l"
	.string "zu stehlen!$"

GraniteCave_B4F_2_Text_RocketF3_Defeated:
	.string "Du Penner! Das melde ich\n"
	.string "sofort meinem Boss!$"

GraniteCave_B4F_2_Text_AfterBattle_Generic:
	.string "Tsk… du wirst schon sehen, was\n"
	.string "noch kommt…$"
