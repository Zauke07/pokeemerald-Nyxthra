SootopolisCity_Gym_B1F_MapScripts::
	.byte 0

SootopolisCity_Gym_B1F_EventScript_Andrea::
	trainerbattle_single TRAINER_ANDREA, SootopolisCity_Gym_B1F_Text_AndreaIntro, SootopolisCity_Gym_B1F_Text_AndreaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Crissy::
	trainerbattle_single TRAINER_CRISSY, SootopolisCity_Gym_B1F_Text_CrissyIntro, SootopolisCity_Gym_B1F_Text_CrissyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Brianna::
	trainerbattle_single TRAINER_BRIANNA, SootopolisCity_Gym_B1F_Text_BriannaIntro, SootopolisCity_Gym_B1F_Text_BriannaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BriannaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Connie::
	trainerbattle_single TRAINER_CONNIE, SootopolisCity_Gym_B1F_Text_ConnieIntro, SootopolisCity_Gym_B1F_Text_ConnieDefeat
	msgbox SootopolisCity_Gym_B1F_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET, SootopolisCity_Gym_B1F_Text_BridgetIntro, SootopolisCity_Gym_B1F_Text_BridgetDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA, SootopolisCity_Gym_B1F_Text_OliviaIntro, SootopolisCity_Gym_B1F_Text_OliviaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY, SootopolisCity_Gym_B1F_Text_TiffanyIntro, SootopolisCity_Gym_B1F_Text_TiffanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bethany::
	trainerbattle_single TRAINER_BETHANY, SootopolisCity_Gym_B1F_Text_BethanyIntro, SootopolisCity_Gym_B1F_Text_BethanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Annika::
	trainerbattle_single TRAINER_ANNIKA, SootopolisCity_Gym_B1F_Text_AnnikaIntro, SootopolisCity_Gym_B1F_Text_AnnikaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AnnikaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Daphne::
	trainerbattle_single TRAINER_DAPHNE, SootopolisCity_Gym_B1F_Text_DaphneIntro, SootopolisCity_Gym_B1F_Text_DaphneDefeat
	msgbox SootopolisCity_Gym_B1F_Text_DaphnePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_Text_AndreaIntro:
	.string "Ich zeig dir die OP-Taktiken,\n"
	.string "die Juan mir beigebracht hat!\l"
	.string "Mach dich bereit zu heulen!$"

SootopolisCity_Gym_B1F_Text_AndreaDefeat:
	.string "Sorry, Juan… Ich bin ein Lappen…$"

SootopolisCity_Gym_B1F_Text_AndreaPostBattle:
	.string "Pass auf, was passiert, wenn du\n"
	.string "nochmal durchs Eis brichst, Noob.$"

SootopolisCity_Gym_B1F_Text_CrissyIntro:
	.string "Du bist bis hierher gegrindet,\n"
	.string "aber Juan kriegst du nicht zu\l"
	.string "sehen. Ich schick dich heim!$"

SootopolisCity_Gym_B1F_Text_CrissyDefeat:
	.string "WTF! Du siehst aus wie ein\n"
	.string "Noob, aber haust mies rein!$"

SootopolisCity_Gym_B1F_Text_CrissyPostBattle:
	.string "Vielleicht überlebst du bei\n"
	.string "Juan ja wenigstens einen Hit, bevor\l"
	.string "er dich wegklatscht.$"

SootopolisCity_Gym_B1F_Text_DaphneIntro:
	.string "Wenn Juan kämpft… das ist\n"
	.string "so ein geiler Flex, dass ich\l"
	.string "direkt Trainerin wurde.$"

SootopolisCity_Gym_B1F_Text_DaphneDefeat:
	.string "Dein Tryhard-Style war einfach\n"
	.string "zu viel für mich…$"

SootopolisCity_Gym_B1F_Text_DaphnePostBattle:
	.string "Dein Grind ist echt krass.\n"
	.string "Gut, dass ich überhaupt ins\l"
	.string "Game gefunden hab.$"

SootopolisCity_Gym_B1F_Text_ConnieIntro:
	.string "Ich zeig dir jetzt mal, wie\n"
	.string "richtig geschwitzt wird, Opfer.$"

SootopolisCity_Gym_B1F_Text_ConnieDefeat:
	.string "Fuck.\n"
	.string "Du bist echt OP.$"

SootopolisCity_Gym_B1F_Text_ConniePostBattle:
	.string "Hör gut zu, du Lappen.\p"
	.string "Wenn du zu Juan willst, musst\n"
	.string "du über jedes verfickte\l"
	.string "Eisfeld einmal latschen.$"

SootopolisCity_Gym_B1F_Text_BridgetIntro:
	.string "Die Arena mit dem krassesten\n"
	.string "Elo in ganz Hoenn…\p"
	.string "Das ist Xeneroville, Digga.$"

SootopolisCity_Gym_B1F_Text_BridgetDefeat:
	.string "Was für ein abgefuckt hohes\n"
	.string "Level hast du bitte?!$"

SootopolisCity_Gym_B1F_Text_BridgetPostBattle:
	.string "Anstatt hier im Eis rumzu-\n"
	.string "campen, solltest du lieber\l"
	.string "draußen weitergrinden.\l"
	.string "Ist auch weniger abfuck.$"

SootopolisCity_Gym_B1F_Text_OliviaIntro:
	.string "Ich grinde immer im Duo-Q mit\n"
	.string "Juan. Denk bloß nicht, ich\l"
	.string "wäre ein Free Kill.$"

SootopolisCity_Gym_B1F_Text_OliviaDefeat:
	.string "Einfach weggeklatscht…$"

SootopolisCity_Gym_B1F_Text_OliviaPostBattle:
	.string "Du hast echt Skills.\n"
	.string "Willst du nicht hier bleiben\l"
	.string "und mit uns Tryhards smurfen?$"

SootopolisCity_Gym_B1F_Text_TiffanyIntro:
	.string "Elegant über das Eis sliden,\n"
	.string "ohne reinzuinten…\p"
	.string "Wer das schafft, ist ein\n"
	.string "absoluter Pro-Gamer!$"

SootopolisCity_Gym_B1F_Text_TiffanyDefeat:
	.string "Geht's noch, du Schwitzer?!$"

SootopolisCity_Gym_B1F_Text_TiffanyPostBattle:
	.string "Es juckt echt niemanden, wie\n"
	.string "alt du bist. Hauptsache, dein\l"
	.string "Elo ist hoch genug.$"

SootopolisCity_Gym_B1F_Text_BethanyIntro:
	.string "Beim Grinden vergeht die Zeit\n"
	.string "so schnell, da sag ich nur:\l"
	.string "“Ups!”$"

SootopolisCity_Gym_B1F_Text_BethanyDefeat:
	.string "Kompletter Int!$"

SootopolisCity_Gym_B1F_Text_BethanyPostBattle:
	.string "Ich wünschte, ich könnte\n"
	.string "meine Losses einfach löschen.\l"
	.string "Meine Win-Rate ist im Arsch!$"

SootopolisCity_Gym_B1F_Text_AnnikaIntro:
	.string "Ich flex mal kurz mit meinen\n"
	.string "absolut seltenen Pokémon.$"

SootopolisCity_Gym_B1F_Text_AnnikaDefeat:
	.string "Was für ein Bullshit!\n"
	.string "Hast du meine Sammlung\l"
	.string "wenigstens angeguckt?$"

SootopolisCity_Gym_B1F_Text_AnnikaPostBattle:
	.string "Juan hat meinen Loot gelobt,\n"
	.string "deshalb bin ich hier.\p"
	.string "Wäre ich bloß jünger gewesen,\n"
	.string "als ich ihn getroffen hab…$"

SootopolisCity_Gym_B1F_Text_BriannaIntro:
	.string "Kicher…\n"
	.string "Dein Tryhard-Face ist echt süß.$"

SootopolisCity_Gym_B1F_Text_BriannaDefeat:
	.string "Oh Mann.\n"
	.string "Ich hab komplett reingetrollt.$"

SootopolisCity_Gym_B1F_Text_BriannaPostBattle:
	.string "Du triffst bei Juan eh keinen\n"
	.string "einzigen Skillshot. Kicher…$"
