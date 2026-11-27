@ All the LOCALID constants used in this file are essentially redundant.
@ They're all used to have the NPC the player talked to turn back so they're facing
@ their original direction (because they're watching/participating in the contests).
@ They could all be substituted for VAR_LAST_TALKED.
LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "Dieses Pokémon hat hier schon den\n"
	.string "SCHÖNHEITS-WETTBEWERB gewonnen.\p"
	.string "Aber stell dir vor: Heute habe ich damit\n"
	.string "einen KLUGHEITS-WETTBEWERB gewonnen!\p"
	.string "Meine Fähigkeiten machen sogar mir\n"
	.string "Angst…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "Ich habe an einigen WETTBEWERBEN\n"
	.string "teilgenommen und sehe, wie es läuft.\p"
	.string "In einem COOLNESS-WETTBEWERB kommen\n"
	.string "coole Attacken als Auftritt gut an.\p"
	.string "Kluge und niedliche Attacken kommen\n"
	.string "zum Beispiel nicht gut an.$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "Der junge Mann, der vorhin gewonnen hat,\n"
	.string "hatte eine ganze Menge verschiedener\l"
	.string "{POKEBLOCK}.\p"
	.string "Kann man gewinnen, wenn man so\n"
	.string "viele davon hat?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "Wow, ist das hier riesig!\p"
	.string "Die Spannung in der Luft… Das ist\n"
	.string "kein WETTBEWERBS-Saal auf dem Dorf.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "MC: Okay, KLUGHEITS-Pokémon und ihre\n"
	.string "TRAINER, seid ihr bereit?!\p"
	.string "Gebt euer Bestes!\n"
	.string "Auf zum Auftritt!$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "RICHTER: Gefällt dir dieser\n"
	.string "WETTBEWERB?\p"
	.string "Komm mit drei Freunden wieder, dann\n"
	.string "könnt ihr alle an einem WETTBEWERB\l"
	.string "teilnehmen!$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Ojojoj… Ich habe am falschen\n"
	.string "WETTBEWERB teilgenommen.\p"
	.string "Ich habe dieses robuste Pokémon im\n"
	.string "KLUGHEITS-WETTBEWERB angemeldet…\p"
	.string "Komm schon, beeindrucke sie mit einem\n"
	.string "klug aussehenden ZERTRÜMMERER.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "Viele Jahre und meine ganze Weisheit\n"
	.string "habe ich darauf verwendet, dieses\l"
	.string "Pokémon klug zu erziehen.\p"
	.string "Das Pokémon irgendeines jungen\n"
	.string "Hüpfers schlägt es nicht so leicht.\p"
	.string "Meine liebe Frau, siehst du das?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "Da ist es!\p"
	.string "Wenn mein Pokémon als Nächstes eine\n"
	.string "kluge Attacke zeigt, erreicht die\l"
	.string "Begeisterung des Publikums ihren\l"
	.string "Höhepunkt!$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "Ach, du meine Güte!\p"
	.string "Der BLUTSAUGER meines Lieblings ZUBAT\n"
	.string "ist so niedlich, dass ich ihn immer\l"
	.string "wieder benutzt habe!\p"
	.string "Aber diese gemeinen Leute wissen das\n"
	.string "überhaupt nicht zu schätzen!$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "Kiyaaah! Du bist wunderschön, Opa!$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "Selbst wenn TRAINER dieselbe Art\n"
	.string "Pokémon anmelden, scheinen sie alle\l"
	.string "unterschiedliche Attacken für den\l"
	.string "Auftritt zu nutzen.\p"
	.string "Genau wie Leute verschiedene\n"
	.string "Kampfstile haben.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "Ich finde, die Pokémon sehen klüger\n"
	.string "aus als ihre TRAINER. Und zwar deutlich.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "Alles in allem liebe ich\n"
	.string "KLUGHEITS-WETTBEWERBE immer noch.\p"
	.string "Diese intellektuelle grüne Farbe…\n"
	.string "Sie ist so… So… Cool.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "MC: Nimmst du auch am SCHÖNHEITS-\n"
	.string "WETTBEWERB teil? Viel Glück!$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "RICHTER: Ah, jedes Pokémon hier ist\n"
	.string "ein Vorbild makelloser Schönheit!\p"
	.string "Meine Güte, fast hätte ich\n"
	.string "vergessen, sie zu bewerten!$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "Ein so schönes Pokémon…\n"
	.string "Es gibt kein zweites wie dieses.\p"
	.string "Alle Augen werden an meiner\n"
	.string "Schönheit kleben.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "Waaaah!\p"
	.string "Ich habe mein Pokémon für diesen\n"
	.string "WETTBEWERB sorgfältig gebürstet und\l"
	.string "gepflegt…\p"
	.string "Aber ich habe es übertrieben… Sein Fell\n"
	.string "ist ganz struppig geworden…\p"
	.string "Was soll ich nur tun?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "Dieser AURORASTRAHL ist so blendend,\n"
	.string "dass der RICHTER nichts sehen kann.\p"
	.string "Äh, warte mal…\n"
	.string "Dann bringt er ja gar nichts!$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "Dieses hübsche Pokémon sieht genau\n"
	.string "so aus wie ich in jungen Jahren.\p"
	.string "Genau als ich das sagte, hat mein\n"
	.string "Mann seinen Kaffee ausgespuckt.\p"
	.string "Habe ich etwas Lustiges gesagt?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "Weißt du, wenn ich einen SCHÖNHEITS-\n"
	.string "WETTBEWERB gewinne, macht mich das\l"
	.string "glücklich. Mehr als sonst jedenfalls.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "Wahahahah!\p"
	.string "Schau dir nur all die hübschen\n"
	.string "Pokémon an!\l"
	.string "Ich liebe diesen Glanz einfach!$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "Man kann nicht immer nur mit\n"
	.string "Schönheit gewinnen.\p"
	.string "Du musst dein Pokémon pflegen,\n"
	.string "damit es schön glänzt wie meins.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "MC: Oh, hallo!\n"
	.string "Wir sind mitten in einem WETTBEWERB!\p"
	.string "Bitte melde dich an unserem Anmelde-\n"
	.string "schalter an und komm dann raus, okay?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "RICHTER: Oh, was für charmante und\n"
	.string "niedliche Auftritte!\p"
	.string "Meine Güte! Was für ein vollkommen\n"
	.string "reizender NASSMACHER-Auftritt!$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Oh nein… Mein süßes AZURILL wurde\n"
	.string "von einem anderen Pokémon abgelenkt.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "Mein Pokémon hat noch nie einen Kampf\n"
	.string "gewonnen, aber im WETTBEWERB: Vorsicht!$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "Der BLÄTTERTANZ meines Pokémon ist ein\n"
	.string "Wunder an Eleganz.\p"
	.string "Ich lasse nicht zu, dass jemand\n"
	.string "seinen Auftritt stört.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "Alle Pokémon hier sind sehr niedlich.\p"
	.string "Aber wenn mein Pokémon einen niedlichen\n"
	.string "Auftritt hinlegt…\p"
	.string "Dann ist es bestimmt viel niedlicher\n"
	.string "als die anderen.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "Mein Kind nimmt an diesem WETTBEWERB\n"
	.string "teil.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "Komm schon, Schatz. Gib alles!\n"
	.string "Dein Pokémon ist das Beste!$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "Ich glaube, das Mädchen da drüben\n"
	.string "ist die Niedlichste von allen.\p"
	.string "Was? Es werden Pokémon nach ihrem\n"
	.string "Aussehen beurteilt?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Ohh, wenn ich all diese niedlichen\n"
	.string "Pokémon sehe, will ich auch eins haben!\p"
	.string "Ich gehe gleich ein paar fangen!$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "BÜHNE DES SCHÖNHEITS-WETTBEWERBS\n"
	.string "LASS DICH VON SCHÖNEN POKéMON\l"
	.string "BEZAUBERN!$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "BÜHNE DES ANMUT-WETTBEWERBS LASS\n"
	.string "DICH VON NIEDLICHEN POKéMON\l"
	.string "BEZAUBERN!$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "BÜHNE DES KLUGHEITS-WETTBEWERBS\n"
	.string "LASS DICH VON KLUGEN POKéMON\l"
	.string "BEEINDRUCKEN!$"

