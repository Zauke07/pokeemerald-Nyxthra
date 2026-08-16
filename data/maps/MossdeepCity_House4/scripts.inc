MossdeepCity_House4_MapScripts::
	.byte 0

MossdeepCity_House4_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_House4_EventScript_CanBattleAtSecretBases
	msgbox MossdeepCity_House4_Text_BrotherLikesToFindBases, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_CanBattleAtSecretBases::
	msgbox MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NinjaBoy::
	lock
	faceplayer
	special CheckPlayerHasSecretBase
	goto_if_eq VAR_RESULT, FALSE, MossdeepCity_House4_EventScript_NoSecretBase
	special GetSecretBaseNearbyMapName
	msgbox MossdeepCity_House4_Text_YouMadeSecretBaseNearX, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_NoSecretBase::
	msgbox MossdeepCity_House4_Text_MakeSecretBase, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House4_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox MossdeepCity_House4_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

MossdeepCity_House4_Text_BrotherLikesToFindBases:
	.string "Mein kleiner Bruder ist ein kompletter\n"
	.string "Creep. Der sucht den ganzen Tag die\l"
	.string "Geheimbasen von anderen Leuten, um da\l"
	.string "heimlich rumzuschnüffeln.$"

MossdeepCity_House4_Text_BrotherLikesToVisitBasesAndBattle:
	.string "Mein kleiner Bruder bricht ungelogen\n"
	.string "bei fremden Leuten in die Geheimbasis\l"
	.string "ein, nur um die dann wegzuboxen.\p"
	.string "Absoluter Psychopath, der Kleine.$"

MossdeepCity_House4_Text_YouMadeSecretBaseNearX:
	.string "Yo, bist du der Typ, der seine billige\n"
	.string "Geheimbasis einfach bei {STR_VAR_1}\l"
	.string "hingeklatscht hat? Richtig lost...$"

MossdeepCity_House4_Text_MakeSecretBase:
	.string "Bau dir mal irgendwo 'ne Geheimbasis.\n"
	.string "Ich schwör dir, ich find die und\l"
	.string "randalier dann da ein bisschen rum!$"

MossdeepCity_House4_Text_Skitty:
	.string "Eneco: Miyaan?\n"
	.string "(Bitte hol mich hier raus, diese Familie\l"
	.string "ist komplett lost...)$"

