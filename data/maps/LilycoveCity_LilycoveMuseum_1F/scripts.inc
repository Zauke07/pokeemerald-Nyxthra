LilycoveCity_LilycoveMuseum_1F_MapScripts::
	.byte 0

LilycoveCity_LilycoveMuseum_1F_EventScript_Greeter::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Curator::
	lockall
	applymovement LOCALID_MUSEUM_1F_CURATOR, Common_Movement_FacePlayer
	message LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings
	waitmessage
	multichoice 20, 8, MULTI_VIEWED_PAINTINGS, TRUE
	goto_if_eq VAR_RESULT, 0, LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings
	goto_if_eq VAR_RESULT, 1, LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotYet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SawPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested
	goto_if_eq VAR_RESULT, YES, LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NotInterested::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat, MSGBOX_SIGN
	releaseall
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_InterestedInPaintings::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe, MSGBOX_SIGN
	applymovement LOCALID_MUSEUM_1F_CURATOR, LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs
	waitmovement 0
	removeobject LOCALID_MUSEUM_1F_CURATOR
	switch VAR_FACING
	case DIR_NORTH, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth
	case DIR_WEST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest
	case DIR_EAST, LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorNorth::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorWest::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FollowCuratorEast::
	lockall
	applymovement LOCALID_PLAYER, LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast
	waitmovement 0
	warp MAP_LILYCOVE_CITY_LILYCOVE_MUSEUM_2F, 11, 8
	waitstate
	end

LilycoveCity_LilycoveMuseum_1F_Movement_CuratorEnterStairs:
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorWest:
	walk_left
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorEast:
	walk_right
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_Movement_FollowCuratorNorth:
	walk_up
	walk_up
	step_end

LilycoveCity_LilycoveMuseum_1F_EventScript_OldPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FantasyPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_WomanPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_LegendaryPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_GrassPokemonPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_BerryPainting::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_EventScript_BirdSculpture::
	msgbox LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PokeBallSculpture::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_StoneTablet::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_SchoolKidM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_NinjaBoy::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman1::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable, MSGBOX_SIGN
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Woman2::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_PsychicM::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_Artist2::
	lock
	faceplayer
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MUSEUM_1F_ARTIST_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_LilycoveMuseum_1F_EventScript_FatMan::
	msgbox LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination, MSGBOX_NPC
	end

LilycoveCity_LilycoveMuseum_1F_Text_WelcomeToLilycoveMuseum::
	.string "Willkommen im MUSEUM von SEEGRASULB.\p"
	.string "Nimm dir gefälligst Zeit, unsere Sammlung\n"
	.string "anzuglotzen. Sowas kriegst du in deiner\l"
	.string "Bruchbude sicher nicht zu sehen.$"

LilycoveCity_LilycoveMuseum_1F_Text_ImCuratorHaveYouViewedOurPaintings::
	.string "Ich bin der KURATOR dieser heiligen\n"
	.string "Hallen der feinen Kunst.\p"
	.string "Schon fast rührend, dass so'n kleiner\n"
	.string "Rotzlöffel wie du sich hierher verirrt.\p"
	.string "Hast du dir die Schinken an den Wänden\n"
	.string "schon reingezogen?$"

LilycoveCity_LilycoveMuseum_1F_Text_NotDisturbYouTakeYourTime::
	.string "Ah, dann will ich dich mal nicht weiter\n"
	.string "beim Gaffen stören. Lass dir Zeit.$"

LilycoveCity_LilycoveMuseum_1F_Text_HaveYouAnInterestInPaintings::
	.string "Oh? Du siehst mir verdammt nach einem\n"
	.string "POKéMON-TRAINER aus.\p"
	.string "Interessierst du dich echt für Kunst\n"
	.string "oder suchst du nur die Toilette?$"

LilycoveCity_LilycoveMuseum_1F_Text_HonoredYoudVisitInSpiteOfThat::
	.string "Verstehe……\p"
	.string "Dass du trotzdem hier aufkreuzt,\n"
	.string "ehrt mich ja fast schon.$"

LilycoveCity_LilycoveMuseum_1F_Text_ExcellentCanYouComeWithMe::
	.string "Ah, hervorragend!\n"
	.string "Du hast also doch Geschmack!\p"
	.string "Dann schwing deinen Hintern und komm\n"
	.string "mal kurz mit mir mit.$"

LilycoveCity_LilycoveMuseum_1F_Text_VeryOldPainting::
	.string "Ein uraltes Gemälde.\n"
	.string "Die Farbe blättert schon ab. Richtig räudig.$"

LilycoveCity_LilycoveMuseum_1F_Text_OddLandscapeFantasticScenery::
	.string "Irgendeine schräge Landschaft.\n"
	.string "Sieht aus wie nach 'ner Überdosis Beeren.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBeautifulWoman::
	.string "Das Bild einer grinsenden Frau mit einem\n"
	.string "Schoßhündchen-POKéMON. Kitsch pur.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfLegendaryPokemon::
	.string "Ein Bild von einem legendären POKéMON\n"
	.string "aus grauer Vorzeit.\p"
	.string "Der Maler hat sich das wohl komplett\n"
	.string "aus den Fingern gesaugt.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfGrassPokemon::
	.string "Ein paar PFLANZEN-POKéMON, die im Wind\n"
	.string "rumwedeln. Spannend wie beim Wachsen\l"
	.string "zuzusehen.$"

LilycoveCity_LilycoveMuseum_1F_Text_PaintingOfBerries::
	.string "Ein Bild von BEEREN, das so echt aussieht,\n"
	.string "dass man am liebsten reinbeißen würde.\l"
	.string "Kriegst du jetzt Hunger, was?$"

LilycoveCity_LilycoveMuseum_Text_BirdPokemonSculptureReplica::
	.string "Eine billige Kopie einer Skulptur.\n"
	.string "Soll wohl ein antikes VOGEL-POKéMON sein.$"

LilycoveCity_LilycoveMuseum_1F_Text_BigPokeBallCarvedFromStone::
	.string "Ein fetter POKéBALL aus schwarzem Stein.\n"
	.string "Damit haben die früher wohl Leute auf\l"
	.string "Festivals beworfen.$"

LilycoveCity_LilycoveMuseum_1F_Text_StoneTabletWithAncientText::
	.string "Eine riesige Steintafel vollgekritzelt mit\n"
	.string "POKéMON und Hieroglyphen, die kein\l"
	.string "Schwein lesen kann.$"

LilycoveCity_LilycoveMuseum_1F_Text_WorksOfMagnificence::
	.string "Hmmm……\n"
	.string "Was für prachtvolle Meisterwerke……$"

LilycoveCity_LilycoveMuseum_1F_Text_MustntForgetLoveForFineArts::
	.string "POKéMON-Kämpfe sind ja ganz nett,\n"
	.string "das geb ich ja zu.\p"
	.string "Aber man sollte seinen Schädel nicht nur\n"
	.string "zum Kämpfen, sondern auch für Kunst nutzen!$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisMuseumIsInspiration::
	.string "Dieses MUSEUM…… Na ja, man kann sich hier\n"
	.string "ein paar krasse Bilder reinziehen.\p"
	.string "Und der KURATOR ist ein feiner Kerl.\p"
	.string "Für Künstler wie mich ist dieser Laden\n"
	.string "eine echte Inspiration.$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisLadyIsPretty::
	.string "Die Frau ist hübsch!\n"
	.string "Sieht fast aus wie Mutti!$"

LilycoveCity_LilycoveMuseum_1F_Text_ThisPokemonIsAdorable::
	.string "Das POKéMON ist ja süß!\n"
	.string "Genau wie unser kleiner Satansbraten!$"

LilycoveCity_LilycoveMuseum_1F_Text_HeardMuseumGotNewPaintings::
	.string "Ich hab gehört, das MUSEUM hat neue\n"
	.string "Schinken reinbekommen.\p"
	.string "Bin natürlich sofort hergeflitzt.\p"
	.string "Hängen die neuen Bilder oben im\n"
	.string "zweiten Stock oder was?$"

LilycoveCity_LilycoveMuseum_1F_Text_CuratorHasBeenCheerful::
	.string "In letzter Zeit ist der KURATOR verdammt\n"
	.string "gut drauf. Schon fast unheimlich.\p"
	.string "Bestimmt hat er im Lotto gewonnen.\n"
	.string "Ganz sicher.$"

LilycoveCity_LilycoveMuseum_1F_Text_AimToSeeGreatPaintings::
	.string "Ich will hier was lernen, damit meine\n"
	.string "eigenen Kritzeleien besser werden.\p"
	.string "Mein Traum ist es, dass mein Müll hier\n"
	.string "irgendwann mal an der Wand hängt.$"

LilycoveCity_LilycoveMuseum_1F_Text_MuseumTouristDestination::
	.string "Das MUSEUM ist mittlerweile die Top-\n"
	.string "Adresse für Touristen-Lappen.\p"
	.string "Gut für SEEGRASULB……\n"
	.string "Nein, gut für ganz HOENN!\p"
	.string "Man erzählt sich, dass ein einzelner\n"
	.string "TRAINER die ganzen Bilder oben besorgt hat.$"
