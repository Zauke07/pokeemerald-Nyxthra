Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "Was ist? Was ich mache?\p"
	.string "Ich überlege, hier mit einer Pokémon-\n"
	.string "Attacke mein eigenes Zimmer zu bauen.\p"
	.string "Ich weiß! Ich gebe dir diese TM.\n"
	.string "Benutzt du sie, um dir ein eigenes\l"
	.string "Zimmer zu bauen?$"

Route111_Text_ExplainSecretPower:
	.string "Such einen großen Baum, von dem\n"
	.string "Ranken herabhängen könnten.\p"
	.string "Benutze GEHEIMKRAFT vor dem Baum.\n"
	.string "Die Ranken lösen sich und fallen herab,\l"
	.string "sodass du den Baum erklimmen kannst.\p"
	.string "Dort findest du viel Platz für\n"
	.string "deine Lieblingssachen.\p"
	.string "Es wird dein eigenes geheimes Zimmer…\n"
	.string "Eine GEHEIMBASIS!\p"
	.string "Du solltest auch eine bauen.\p"
	.string "Außerdem musst du deine GEHEIMBASIS\n"
	.string "nicht immer in einem Baum bauen.\p"
	.string "Probier GEHEIMKRAFT an Felswänden\n"
	.string "mit kleinen Einbuchtungen aus.\p"
	.string "Ich suche auch nach anderen Orten.\n"
	.string "Okay, tschüss!$"

Route111_Text_DontWantThis:
	.string "Oh, du willst das nicht? Wenn du es dir\n"
	.string "anders überlegst, sag Bescheid, okay?$"

Route111_Text_DontHaveAnyRoom:
	.string "Oh, du hast keinen Platz dafür.\p"
	.string "Ich behalte es, also komm ein andermal\n"
	.string "wieder vorbei, okay?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_HIDE_SLATEPORT_CITY_TM_SALESMAN
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
