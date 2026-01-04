MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Kayla::
	trainerbattle_single TRAINER_KAYLA, MtPyre_3F_Text_KaylaIntro, MtPyre_3F_Text_KaylaDefeat
	msgbox MtPyre_3F_Text_KaylaPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro::
	.string "Die dicke Luft hier am Berg hat meine\n"
	.string "Psycho-Kräfte extrem gepusht!\p"
	.string "Ein kleiner Pimpf wie du……\n"
	.string "Du träumst echt vom Sieg? Lächerlich!$"

MtPyre_3F_Text_WilliamDefeat::
	.string "Ich ertrinke in Selbstmitleid……$"

MtPyre_3F_Text_WilliamPostBattle::
	.string "Meine Psycho-Kräfte sind definitiv\n"
	.string "gewachsen, aber du hast wohl einfach\l"
	.string "nur krankes Glück gehabt!$"

MtPyre_3F_Text_KaylaIntro::
	.string "Ahahahaha!\p"
	.string "Das hier ist kein Spielplatz für Blagen,\n"
	.string "schon gar nicht für so eine wie dich!$"

MtPyre_3F_Text_KaylaDefeat::
	.string "Das war…… verdammt deutlich.$"

MtPyre_3F_Text_KaylaPostBattle::
	.string "Das heißt wohl, mein Training ist immer\n"
	.string "noch für die Tonne……\p"
	.string "Ich muss weiter hoch zum Gipfel,\n"
	.string "egal wie weh es tut!\p"
	.string "Reiß dich zusammen, Mädel!$"

MtPyre_3F_Text_GabrielleIntro::
	.string "Was zum Teufel suchst du hier?$"

MtPyre_3F_Text_GabrielleDefeat::
	.string "Das war…… heftig!\n"
	.string "Du bist echt kein gewöhnlicher Trainer.$"

MtPyre_3F_Text_GabriellePostBattle::
	.string "POKéMON, die schon lange verrottet sind.\n"
	.string "POKéMON, die jetzt bei dir hocken.\p"
	.string "Und die POKéMON, die du erst noch\n"
	.string "versklaven wirst……\p"
	.string "Du musst sie alle gleich behandeln.\n"
	.string "Vergiss das bloß nicht, Kleiner.$"

MtPyre_3F_Text_GabrielleRegister::
	.string "Ich will sehen, wie deine Viecher aus-\n"
	.string "sehen, wenn sie noch mehr gelitten haben……\p"
	.string "Rück deinen POKéNAV raus. Sofort!$"

MtPyre_3F_Text_GabrielleRematchIntro::
	.string "Oh, du schon wieder……\p"
	.string "Bist du hier, um mir deine abgehärteten\n"
	.string "POKéMON unter die Nase zu reiben?$"

MtPyre_3F_Text_GabrielleRematchDefeat::
	.string "Einfach nur krank!\n"
	.string "Du bist echt ein spezieller Typ.$"

MtPyre_3F_Text_GabriellePostRematch::
	.string "Die Toten, die Lebenden und die,\n"
	.string "die noch kommen werden……\p"
	.string "Alle verdienen denselben Respekt.\n"
	.string "Schön zu sehen, dass du das nicht\l"
	.string "vergessen hast.$"

