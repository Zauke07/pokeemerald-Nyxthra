MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "Früher bin ich als POKéMON-TRAINER\n"
	.string "durch die ganze Welt gezogen.\p"
	.string "Heute bin ich nur noch ein alter Kauz,\n"
	.string "und mein größter Spaß ist es, jungen\l"
	.string "TRAINERN beim Kämpfen zuzusehen.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "Die Tür ist abgeschlossen.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "Ein TRAINER namens {STR_VAR_1}\n"
	.string "ist gerade zu Besuch.\p"
	.string "Willst du {STR_VAR_1}\n"
	.string "herausfordern?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "Kein Kampf? Schade, ich hätte euch\n"
	.string "gerne in Aktion gesehen…$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "Sehr gut, sehr gut!\p"
	.string "Aber mein Haus ist nicht gerade stabil.\p"
	.string "Könnt ihr es bei einem\n"
	.string "3-gegen-3 belassen?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Bevor ihr loslegt, solltet ihr\n"
	.string "erst speichern.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "Ich bin gespannt auf einen starken Kampf!$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "Also ein Unentschieden.\p"
	.string "Das war ein richtig guter Kampf,\n"
	.string "keiner hat auch nur einen Meter nachgegeben!$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "Das war großartig!\p"
	.string "Fast so, als würde ich mich selbst\n"
	.string "in jungen Jahren sehen!$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "Ah, schade für dich!\p"
	.string "Aber es war ein guter Kampf.\n"
	.string "Nächstes Mal holst du dir den Sieg.$"
