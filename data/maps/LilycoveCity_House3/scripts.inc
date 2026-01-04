LilycoveCity_House3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_House3_OnTransition
	.byte 0

LilycoveCity_House3_OnTransition:
	random 4
	copyvar VAR_TEMP_1, VAR_RESULT
	end

LilycoveCity_House3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_House3_EventScript_DeclinePokeblockLearn
	msgbox LilycoveCity_House3_Text_ExplainPokeblocks, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_DeclinePokeblockLearn::
	msgbox LilycoveCity_House3_Text_OhAreYouSure, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_Man::
	lock
	faceplayer
	msgbox LilycoveCity_House3_Text_HappyToHaveQuadruplets, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_House3_EventScript_GameBoyKid1::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid2::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid3::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_GameBoyKid4::
	lock
	faceplayer
	switch VAR_TEMP_1
	case 0, LilycoveCity_House3_EventScript_WereDoingMultiBattle
	case 1, LilycoveCity_House3_EventScript_WereMixingRecords
	case 2, LilycoveCity_House3_EventScript_WereBlendingBerries
	case 3, LilycoveCity_House3_EventScript_WereDoingContest
	end

LilycoveCity_House3_EventScript_WereDoingMultiBattle::
	msgbox LilycoveCity_House3_Text_GoingToWinMultiBattles, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereMixingRecords::
	msgbox LilycoveCity_House3_Text_LikeMixingAtRecordCorner, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereBlendingBerries::
	msgbox LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_EventScript_WereDoingContest::
	msgbox LilycoveCity_House3_Text_GoingToEnterContest, MSGBOX_DEFAULT
	release
	end

LilycoveCity_House3_Text_LearnFromMasterOfPokeblocks::
	.string "Oha! Ganz allein unterwegs, Kleiner?\n"
	.string "Bist ja noch halb feucht hinter den Ohren!\p"
	.string "Meine Bälger könnten dir sicher noch\n"
	.string "einiges beibringen!\p"
	.string "Ich? Ich bin der Gott der {POKEBLOCK}.\p"
	.string "Wenn ich mich nur minimal anstrenge,\n"
	.string "braue ich Zeug, das dich umhaut.\p"
	.string "Willst du was vom Meister lernen oder\n"
	.string "lieber weiter im Dunkeln tappen?$"

LilycoveCity_House3_Text_OhAreYouSure::
	.string "Oh? Sicher? Musst ja wissen, wie du\n"
	.string "deine Zeit verschwendest!\p"
	.string "Versuch nicht immer, den harten Max zu\n"
	.string "markieren, Schätzchen!$"

LilycoveCity_House3_Text_ExplainPokeblocks::
	.string "Na also! Bist ja doch nicht ganz hohl!\n"
	.string "Hör gut zu, ich sag's nur einmal!\p"
	.string "Bereit?\p"
	.string "Bei {POKEBLOCK} zählt vor allem die Würze.\n"
	.string "Je niedriger dieser Wert, desto besser\l"
	.string "flutscht das Zeug. Merk dir das!\p"
	.string "Ein guter {POKEBLOCK} hat 'ne niedrige Würze\n"
	.string "und ein verdammt hohes Level.\p"
	.string "Davon fressen dir deine Viecher auch\n"
	.string "viel mehr aus der Hand.\p"
	.string "Und jetzt pass auf.\p"
	.string "Wenn du geschmeidige {POKEBLOCK} willst,\n"
	.string "musst du verschiedene BEEREN mischen.\p"
	.string "Sei kein Geizkragen! Die Sorte bestimmt,\n"
	.string "ob das Ergebnis Müll ist oder nicht.\p"
	.string "Und noch was……\p"
	.string "Je mehr Leute am Mixer kurbeln, desto\n"
	.string "geiler wird der {POKEBLOCK}.\p"
	.string "Also laber andere Leute voll und macht\n"
	.string "das Zeug gefälligst zusammen.\p"
	.string "Das ist eigentlich alles, was du wissen\n"
	.string "musst, um kein Versager zu sein.\p"
	.string "Wenn jeder POKéMON, fette {POKEBLOCK} und\n"
	.string "keine nervigen Nachbarn hätte, wäre\l"
	.string "die Welt ein besserer Ort.\p"
	.string "Lass dich nicht unterkriegen!$"

LilycoveCity_House3_Text_HappyToHaveQuadruplets::
	.string "Als meine Alte Vierlinge geworfen hat,\n"
	.string "war ich erst mal bedient, ohne Witz.\p"
	.string "Aber wenn ich sehe, wie sie jetzt andere\n"
	.string "Leute nerven, bin ich fast stolz.$"

LilycoveCity_House3_Text_GoingToWinMultiBattles::
	.string "Wir machen hier MULTIKÄMPFE und ich\n"
	.string "werd' dich so was von nass machen!$"

LilycoveCity_House3_Text_LikeMixingAtRecordCorner::
	.string "Wir hängen ständig in der STATISTIK-\n"
	.string "ECKE rum und mischen Zeug.\p"
	.string "Was dabei rauskommt? Keine Ahnung!$"

LilycoveCity_House3_Text_MakePokeblocksWithBerryBlender::
	.string "Wir werden die krassesten {POKEBLOCK} mit\n"
	.string "dem BEEREN-MIXER zusammenmatschen!$"

LilycoveCity_House3_Text_GoingToEnterContest::
	.string "Ich will damit angeben, wie brutal mein\n"
	.string "POKéMON ist. Deshalb meld ich uns beim\l"
	.string "WETTBEWERB an. Die werden staunen!$"
