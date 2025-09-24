PetalburgWoods_MapScripts::
	.byte 0

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_GRUNT_PETALBURG_WOODS, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement LOCALID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PETALBURG_WOODS_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_PETALBURG_WOODS_GRUNT
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_PETALBURG_WOODS_DEVON_EMPLOYEE
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_JAMES_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hmm…\n"
	.string "Nicht ein einziges Knilz weit und breit.$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Hey… hast du hier irgendwo\n"
	.string "KNILZ gesehen? Ich LIEBE Knilz!\p"
	.string "Ich würd sogar mein Team dafür\l"
	.string "rausschmeißen.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "Ich wollte dich eigentlich überfallen…\n"
	.string "Aber du bummelst hier ewig rum.\p"
	.string "Hab schon fast Moos angesetzt.\n"
	.string "Na los - Kampfzeit!$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "He, du da! Du bist doch von DEVON, oder?!\p"
	.string "Rück die Unterlagen raus. Sofort!$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Aaaaaah!\p"
	.string "Du bist doch Trainer, oder?!\n"
	.string "Hilf mir, bevor er mich wegbeißt!$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Was soll das?!\n"
	.string "Du stellst dich zwischen mich und\l"
	.string "mein Ziel?\p"
	.string "Niemand legt sich mit TEAM AQUA an\n"
	.string "und kommt ungeschoren davon!\p"
	.string "Na warte!$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "Was zum…?!\n"
	.string "Du bist echt stark! Das war fies!$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Tch! Ganz schön frech, dich gegen\n"
	.string "TEAM AQUA zu stellen!\p"
	.string "Ich würde ja gern noch mal kämpfen,\n"
	.string "aber mir sind die Pokémon ausgegangen…\p"
	.string "Wir haben in METAROST noch was zu tun.\n"
	.string "Du hast Glück gehabt - diesmal.$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Puh… Das war mehr als knapp!\p"
	.string "Danke dir, sonst wär ich jetzt\l"
	.string "papierlos.\p"
	.string "Hier - nimm diesen SUPERBALL\n"
	.string "als kleines Dankeschön!$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Der Typ von TEAM AQUA meinte doch,\n"
	.string "sie haben noch was in METAROST vor.$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Oh Mist, keine Zeit!\n"
	.string "Kaffepause gestrichen, das ist\l"
	.string "ein Notfall.\p"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Dein Beutel platzt gleich! Ich kann\n"
	.string "dir den SUPERBALL nicht geben.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "Ich hab mir voll viele Pokémon gefangen!\p"
	.string "Jetzt: Käfer-Power! GO, mein Team!$"

PetalburgWoods_Text_ICouldntWin:
	.string "So viele Käfer… und trotzdem verloren.\n"
	.string "Das war nicht der Plan.$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "Ich hab so viel gefangen, jetzt hab\n"
	.string "ich keine Bälle mehr übrig. Hmpf.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Bring ein Käfer-Pokémon mit zur Schule,\n"
	.string "und du bist sofort der King.$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Wenn ich verliere…\n"
	.string "Bin ich dann uncool?$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Große Käfer-Pokémon = Respekt.\n"
	.string "So läuft das hier.$"

PetalburgWoods_Text_IWantRematch1:
	.string "Wenn meine Käfer stärker werden,\n"
	.string "will ich Revanche!\p"
	.string "Ich speicher dich im PokéNav.$"

PetalburgWoods_Text_IWantRematch2:
	.string "Wenn meine Käfer stärker werden,\n"
	.string "will ich Revanche!\p"
	.string "Ich speicher dich im PokéNav.$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "Meine Käfer sind gewachsen.\n"
	.string "Jetzt darf ich wieder mitreden.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "Niemand mag Verlierer.\n"
	.string "Und ich verliere dauernd…$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "Starke Pokémon = Beliebtheit.\n"
	.string "Also trainier ich bis zur Ohnmacht.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Hey du!\n"
	.string "Sind deine Pokémon fit?\p"
	.string "Wenn nicht, bleib aus dem hohen Gras,\n"
	.string "sonst gibts Stress mit wilden Monstern.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Manchmal liegen Items am Boden,\n"
	.string "ohne dass man sie sieht.\p"
	.string "Ich taste hier jeden Schritt ab,\n"
	.string "wie ein Psychopath auf Schatzsuche.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Oh nice - der Orden aus METAROST!\p"
	.string "Dann probier doch dieses Item aus -\n"
	.string "ist ganz nützlich, glaub mir.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "Das ist WUNDERSAAT.\n"
	.string "Damit macht dein Pflanzen-Pokémon\n"
	.string "richtig Alarm!\p"
	.string "Es gibt viele Items, die Pokémon\n"
	.string "tragen können. Versuch mal was aus!$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "TIPPS für TRAINER\p"
	.string "Jedes Pokémon im Kampf bekommt\n"
	.string "EP - auch wenn es nur kurz dabei war.\p"
	.string "Setz ein schwaches Pokémon an die Spitze,\n"
	.string "wechsel es sofort aus - easy EP.$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "TIPPS für TRAINER\p"
	.string "Attacken verbrauchen AP - wenn die weg\n"
	.string "sind, ist’s Zeit fürs Pokémon-CENTER.\p"
	.string "Vergiss das nie. Ohne AP keine Action!$"

PetalburgWoods_EventScript_Endivie::
	msgbox PetalburgWoods_Text_Endivie, MSGBOX_NPC
	end

PetalburgWoods_Text_Endivie:
	.string "Hey {PLAYER}, ich bin ein\n"
	.string "Bote von diesem Rom Entwickler.\l"
	.string "Sein Name ist Zauke07!\p"
	.string "Immer wenn du mich am Ende einer\n"
	.string "Route siehst, sprich mich an, denn\l"
	.string "ich habe einen heißen Tipp für dich!\p"
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 2 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

