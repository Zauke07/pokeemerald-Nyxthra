Route111_01_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_01_OnTransition
	.byte 0

Route111_01_OnTransition:
	end

Route111_01_EventScript_Reporter::
	lock
	faceplayer
	msgbox Route111_01_Text_Reporter, MSGBOX_DEFAULT
	release
	end

Route111_01_EventScript_Cameraman::
	lock
	faceplayer
	msgbox Route111_01_Text_Cameraman, MSGBOX_DEFAULT
	release
	end

Route111_01_EventScript_OfficerRocky::
	trainerbattle_single TRAINER_OFFICER_ROCKY, Route111_01_Text_RockyIntro, Route111_01_Text_RockyDefeat
	msgbox Route111_01_Text_RockyPost, MSGBOX_AUTOCLOSE
	end

Route111_01_EventScript_NurseJoy::
	trainerbattle_single TRAINER_NURSE_JOY, Route111_01_Text_JoyIntro, Route111_01_Text_JoyDefeat
	msgbox Route111_01_Text_JoyPost, MSGBOX_AUTOCLOSE
	end

Route111_01_EventScript_CamperSven::
	trainerbattle_single TRAINER_CAMPER_SVEN, Route111_01_Text_SvenIntro, Route111_01_Text_SvenDefeat
	msgbox Route111_01_Text_SvenPost, MSGBOX_AUTOCLOSE
	end

Route111_01_EventScript_PicnickerLara::
	trainerbattle_single TRAINER_PICNICKER_LARA, Route111_01_Text_LaraIntro, Route111_01_Text_LaraDefeat
	msgbox Route111_01_Text_LaraPost, MSGBOX_AUTOCLOSE
	end

Route111_01_EventScript_RuinManiacKarl::
	trainerbattle_single TRAINER_RUIN_MANIAC_CARLA, Route111_01_Text_KarlIntro, Route111_01_Text_KarlDefeat
	msgbox Route111_01_Text_KarlPost, MSGBOX_AUTOCLOSE
	end

Route111_01_EventScript_HikerBjoern::
	trainerbattle_single TRAINER_HIKER_BJOERN, Route111_01_Text_BjoernIntro, Route111_01_Text_BjoernDefeat
	msgbox Route111_01_Text_BjoernPost, MSGBOX_AUTOCLOSE
	end

Route111_01_Text_Reporter:
	.string "REPORTER: Live vor Ort an den\n"
	.string "mysteriösen Ruinen. Wir bleiben dran!$"

Route111_01_Text_Cameraman:
	.string "KAMERAMANN: Nicht bewegen…\n"
	.string "Und… Aufnahme!$"

Route111_01_Text_RockyIntro:
	.string "OFFICER ROCKY: Sicherheitskontrolle!\n"
	.string "Zeig mir deine Stärke, Trainer!$"

Route111_01_Text_RockyDefeat:
	.string "Du hast bestanden. Stark und korrekt.$"

Route111_01_Text_RockyPost:
	.string "Bleib wachsam. In der Wüste gibt es\n"
	.string "mehr als nur Sand.$"

Route111_01_Text_JoyIntro:
	.string "SCHWESTER JOY: Ein kurzer Check!\n"
	.string "Ein Kampf sagt oft mehr als Worte.$"

Route111_01_Text_JoyDefeat:
	.string "Gut gekämpft. Vergiss die Erholung\n"
	.string "deiner Pokémon nicht.$"

Route111_01_Text_JoyPost:
	.string "Heilung ist wichtig, doch Training\n"
	.string "genauso. Pass gut auf sie auf.$"

Route111_01_Text_SvenIntro:
	.string "CAMPER SVEN: Sand im Schuh, Mut im\n"
	.string "Herz! Los geht's!$"

Route111_01_Text_SvenDefeat:
	.string "Der Sand war wohl nicht die Ausrede…$"

Route111_01_Text_SvenPost:
	.string "Ich trainiere weiter. Irgendwann\n"
	.string "gewinne ich hier oben!$"

Route111_01_Text_LaraIntro:
	.string "PICKNICKER LARA: Kleiner Snack,\n"
	.string "großer Kampf!$"

Route111_01_Text_LaraDefeat:
	.string "Okay… Snackpause verlängert.$"

Route111_01_Text_LaraPost:
	.string "Die Aussicht ist schön. Und du bist\n"
	.string "schneller als ich dachte.$"

Route111_01_Text_KarlIntro:
	.string "Rucksackturi Carla: Alte Steine,\n"
	.string "neue Geheimnisse. Test gefällig?$"

Route111_01_Text_KarlDefeat:
	.string "Wissen allein schlägt nicht Stärke.$"

Route111_01_Text_KarlPost:
	.string "Diese Ruinen bergen Rätsel. Ich\n"
	.string "werde sie lösen.$"

Route111_01_Text_BjoernIntro:
	.string "WANDERER BJÖRN: Hoch hinaus!\n"
	.string "Auch im Kampf!$"

Route111_01_Text_BjoernDefeat:
	.string "Uff… außer Puste.$"

Route111_01_Text_BjoernPost:
	.string "Ein Schluck Wasser, dann geht’s\n"
	.string "weiter.$"

