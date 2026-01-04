MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty::
	.string "Erinnerungen an mein süßes Eneco……\n"
	.string "Mir kommen die Tränen, wenn ich daran\l"
	.string "denke, wie es im Dreck gelandet ist.$"

MtPyre_2F_Text_TumbledFromFloorAbove::
	.string "Au, verdammt…… Überall sind diese\n"
	.string "verdammten Löcher im Boden.\p"
	.string "Ich hab nicht aufgepasst und bin wie\n"
	.string "ein nasser Sack von oben runtergeknallt.$"

MtPyre_2F_Text_MarkIntro::
	.string "Hey! Suchst du hier auch nach POKéMON?\n"
	.string "Ich war zuerst hier, du kleiner Dieb!$"

MtPyre_2F_Text_MarkDefeat::
	.string "Aaaaah! Okay, okay!\n"
	.string "Lass mich in Ruhe, tut mir leid!$"

MtPyre_2F_Text_MarkPostBattle::
	.string "Hier kommt kaum ein Schwein her, also\n"
	.string "dachte ich, ich find hier was Geiles.$"

MtPyre_2F_Text_LukeIntro::
	.string "LUKE: Wir machen hier 'ne Mutprobe.\p"
	.string "Wenn ich mich hier wie der krasse Macker\n"
	.string "aufführe, springt sie mir direkt in die\l"
	.string "Arme. Ich weiß es genau!\p"
	.string "Pass auf! Ich mach dich jetzt platt, um\n"
	.string "vor meiner Kleinen anzugeben!$"

MtPyre_2F_Text_LukeDefeat::
	.string "LUKE: Ups! War wohl nix……$"

MtPyre_2F_Text_LukePostBattle::
	.string "LUKE: Na ja, wir haben verloren, aber\n"
	.string "egal! Ich bin ja für dich da, Schatzi.\l"
	.string "Wir überleben diese Mutprobe locker!$"

MtPyre_2F_Text_LukeNotEnoughMons::
	.string "LUKE: Wenn du dich mit mir anlegen willst,\n"
	.string "bring mehr Viecher mit.\p"
	.string "Sonst kann ich vor meiner Freundin nicht\n"
	.string "zeigen, wie hart ich zuschlage!$"

MtPyre_2F_Text_DezIntro::
	.string "DEZ: Mein Freund hat mich zu dieser\n"
	.string "gruseligen Mutprobe geschleppt.\p"
	.string "Ich hab zwar echt Schiss, aber mein\n"
	.string "Hengst beschützt mich ja.\p"
	.string "Guck mal! Mein Freund zeigt dir jetzt,\n"
	.string "was für ein harter Kerl er ist!$"

MtPyre_2F_Text_DezDefeat::
	.string "DEZ: Waaaah! Ich hab Angst!$"

MtPyre_2F_Text_DezPostBattle::
	.string "DEZ: Wir sind so krass verliebt, uns ist\n"
	.string "es völlig egal, wenn wir loooooosen!$"

MtPyre_2F_Text_DezNotEnoughMons::
	.string "DEZ: Wenn du uns herausfordern willst,\n"
	.string "brauchst du mindestens zwei POKéMON.\p"
	.string "Mein Freund ist ein Tier!\n"
	.string "Mit nur einem POKéMON lacht er dich aus.$"

MtPyre_2F_Text_LeahIntro::
	.string "Deine Visage hab ich hier noch nie gesehen……\n"
	.string "Zisch ab, bevor dir hier was Schlimmes\l"
	.string "zustößt!$"

MtPyre_2F_Text_LeahDefeat::
	.string "Hmm……\n"
	.string "Du hältst ja einiges aus.$"

MtPyre_2F_Text_LeahPostBattle::
	.string "Meine Familie trainiert hier schon seit\n"
	.string "meiner Urgroßmutter…\p"
	.string "Es ist mein Job, diesen Berg vor\n"
	.string "Touristen-Lappen wie dir zu schützen!$"

MtPyre_2F_Text_ZanderIntro::
	.string "Kiyaaaaah!\n"
	.string "Ich mach mir gleich in die Hose!$"

MtPyre_2F_Text_ZanderDefeat::
	.string "Neiiiiin!\n"
	.string "Ich hab völlig den Verstand verloren!$"

MtPyre_2F_Text_ZanderPostBattle::
	.string "Ich krieg jedes Mal 'nen Anfall, wenn\n"
	.string "sich hier irgendwas bewegt…\p"
	.string "Wer kam auf die dämliche Idee, hier\n"
	.string "zu trainieren? Ach ja, ich selbst.$"
