PetalburgCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_Gym_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_Gym_OnFrame
	.byte 0

PetalburgCity_Gym_OnLoad:
	goto_if_eq VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_OpenUnlockedDoors
	call_if_ge VAR_PETALBURG_GYM_STATE, 7, PetalburgCity_Gym_EventScript_UnlockAllDoors
	end

@ NOTE: Strength and OHKO rooms are misleading. Both are more accurately Critical-Hit
PetalburgCity_Gym_EventScript_OpenUnlockedDoors::
	setvar VAR_0x8005, 1
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
	call_if_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	call_if_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	call_if_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	call_if_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	call_if_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	call_if_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	call_if_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	end

PetalburgCity_Gym_EventScript_UnlockAllDoors::
	setvar VAR_0x8005, 1
	call PetalburgCity_Gym_EventScript_OpenGymEntranceDoors
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	return

PetalburgCity_Gym_OnTransition:
	call_if_eq VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_MoveWallyToEntrance
	call_if_eq VAR_PETALBURG_GYM_STATE, 9, PetalburgCity_Gym_EventScript_MoveChampToEntrance
	call_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_MoveNormanToEntrance
	call_if_eq VAR_PETALBURG_GYM_STATE, 9, PetalburgCity_Gym_EventScript_MoveNormanToEntrance
	call_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_CheckNormanForRematch
	call PetalburgCity_Gym_EventScript_SetChampGfx
	end

@ Nyxthra story: mirrors MoveWallyToEntrance above - the Champ's farewell
@ walk (ReturnFromChampCatchDemo) needs him actually visible and standing
@ just past the door again after the warp back in, same spot Wally uses for
@ his own equivalent state. He was hidden again after leaving for the catch
@ demo (see ChampFirstAppearanceEnd), so the hide flag has to be cleared
@ here or he'd stay invisible for the whole farewell scene.
PetalburgCity_Gym_EventScript_MoveChampToEntrance::
	clearflag FLAG_HIDE_PETALBURG_GYM_CHAMP
	setobjectxyperm LOCALID_PETALBURG_GYM_CHAMP, 5, 108
	return

@ Nyxthra story: the Champion (May or Brendan, fixed by IsChampionMay - not
@ the per-style dynamic rival) makes their first appearance here to
@ demonstrate catching, in place of Wally's old borrow-a-Pokemon tutorial.
PetalburgCity_Gym_EventScript_SetChampGfx::
	specialvar VAR_RESULT, IsChampionMay
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_SetChampGfxMay
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL
	return
PetalburgCity_Gym_EventScript_SetChampGfxMay:
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_RIVAL_MAY_NORMAL
	return

PetalburgCity_Gym_EventScript_MoveWallyToEntrance::
	setobjectxyperm LOCALID_PETALBURG_GYM_WALLY, 5, 108
	return

PetalburgCity_Gym_EventScript_MoveNormanToEntrance::
	setobjectxyperm LOCALID_PETALBURG_GYM_NORMAN, 4, 107
	return

PetalburgCity_Gym_EventScript_CheckNormanForRematch::
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, TRAINER_NORMAN_1
	specialvar VAR_RESULT, IsTrainerReadyForRematch
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontMoveNormanToFront
	goto_if_eq VAR_PETALBURG_GYM_STATE, 8, PetalburgCity_Gym_EventScript_DontMoveNormanToFront
	setobjectxyperm LOCALID_PETALBURG_GYM_NORMAN, 4, 107
	return

PetalburgCity_Gym_EventScript_DontMoveNormanToFront::
	setvar VAR_PETALBURG_GYM_STATE, 8
	end

PetalburgCity_Gym_OnWarp:
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_TurnPlayerNorth
	map_script_2 VAR_PETALBURG_GYM_STATE, 9, PetalburgCity_Gym_EventScript_TurnPlayerNorth
	.2byte 0

PetalburgCity_Gym_EventScript_TurnPlayerNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	end

PetalburgCity_Gym_OnFrame:
	map_script_2 VAR_PETALBURG_GYM_STATE, 1, PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial
	map_script_2 VAR_PETALBURG_GYM_STATE, 9, PetalburgCity_Gym_EventScript_ReturnFromChampCatchDemo
	.2byte 0

PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial::
	lockall
	msgbox PetalburgCity_Gym_Text_DadSoDidItWorkOut, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyThankYouBye, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitGym
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_PETALBURG_CITY_WALLY
	delay 30
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_DadGoCollectBadges, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_GYM_STATE, 2
	releaseall
	end

PetalburgCity_Gym_Movement_WallyExitGym:
	walk_down
	walk_down
	walk_down
	delay_16
	step_end

PetalburgCity_Gym_EventScript_Norman::
	vsseeker_rematchid TRAINER_NORMAN_1
	lock
	faceplayer
	switch VAR_PETALBURG_GYM_STATE
	case 2, PetalburgCity_Gym_EventScript_NormanNoBadges
	case 3, PetalburgCity_Gym_EventScript_NormanOneBadge
	case 4, PetalburgCity_Gym_EventScript_NormanTwoBadges
	case 5, PetalburgCity_Gym_EventScript_NormanThreeBadges
	case 6, PetalburgCity_Gym_EventScript_NormanBattle
	case 7, PetalburgCity_Gym_EventScript_NormanPostBattle
	case 8, PetalburgCity_Gym_EventScript_NormanRematch
	msgbox PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_SOUTH, PetalburgCity_Gym_EventScript_ChampFirstAppearanceSouth
	case DIR_NORTH, PetalburgCity_Gym_EventScript_ChampFirstAppearanceNorth
	case DIR_WEST, PetalburgCity_Gym_EventScript_ChampFirstAppearanceWest
	case DIR_EAST, PetalburgCity_Gym_EventScript_ChampFirstAppearanceEast
	end

PetalburgCity_Gym_EventScript_ChampFirstAppearanceSouth::
	setvar VAR_0x8008, 0
	goto PetalburgCity_Gym_EventScript_ChampFirstAppearance
	end

PetalburgCity_Gym_EventScript_ChampFirstAppearanceNorth::
	setvar VAR_0x8008, 1
	goto PetalburgCity_Gym_EventScript_ChampFirstAppearance
	end

PetalburgCity_Gym_EventScript_ChampFirstAppearanceWest::
	setvar VAR_0x8008, 2
	goto PetalburgCity_Gym_EventScript_ChampFirstAppearance
	end

PetalburgCity_Gym_EventScript_ChampFirstAppearanceEast::
	setvar VAR_0x8008, 3
	goto PetalburgCity_Gym_EventScript_ChampFirstAppearance
	end

@ Nyxthra story: on your very first visit, the Champion (May or Brendan -
@ see IsChampionMay/LOCALID_PETALBURG_GYM_CHAMP) shows up instead of Wally's
@ old "borrow a Zigzagoon and go catch a Ralts" tutorial. Wally himself is
@ untouched everywhere else - this only replaces his role in this one scene.
@ Mirrors BeginWallyTutorial's own VAR_0x8008/VAR_FACING direction handling
@ below - the player can reach Norman from any of the 4 sides of this gym's
@ invisible-wall maze, and reuses Wally's exact arrival/exit movement
@ scripts (they're plain relative step lists, not tied to a specific
@ object) just applied to the Champ instead.
PetalburgCity_Gym_EventScript_ChampFirstAppearance::
	addobject LOCALID_PETALBURG_GYM_CHAMP
	playse SE_DOOR
	playse SE_PIN
	applymovement LOCALID_PETALBURG_GYM_CHAMP, Common_Movement_ExclamationMark
	waitmovement 0
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_ChampArriveSouth
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ChampArriveNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ChampArriveWestEast
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ChampArriveWestEast
	specialvar VAR_RESULT, IsChampionMay
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_ChampFirstAppearanceMay
	goto PetalburgCity_Gym_EventScript_ChampFirstAppearanceBrendan
	end

PetalburgCity_Gym_EventScript_ChampArriveSouth::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_CHAMP, PetalburgCity_Gym_Movement_WallyArrive
	waitmovement 0
	return

@ Nyxthra story: WallyArriveNorth (Wally's own version of this) has a deliberate
@ extra walk_right baked in partway through - staging to end up beside Norman
@ specifically. We want the Champ to end up beside the PLAYER instead (who's
@ standing directly south of Marek here), so this uses the plain WallyArrive
@ movement like the other directions, not the North-specific jog.
@ Nyxthra story: Marek doesn't turn here (Wally's own version turns Norman
@ to face right too, but Marek is already facing the player from earlier in
@ this conversation - turning him away mid-scene looked wrong). The Champ
@ just turns to face the player after arriving (no extra step - WallyArrive
@ leaves them facing up/away from the player they just walked past).
PetalburgCity_Gym_EventScript_ChampArriveNorth::
	applymovement LOCALID_PETALBURG_GYM_CHAMP, PetalburgCity_Gym_Movement_WallyArrive
	waitmovement 0
	applymovement LOCALID_PETALBURG_GYM_CHAMP, Common_Movement_FacePlayer
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ChampArriveWestEast::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_CHAMP, PetalburgCity_Gym_Movement_WallyArrive
	waitmovement 0
	return

@ Nyxthra story: the "who's looking at whom" turns below (FaceUp for Marek,
@ FacePlayer/FaceRight for Champ<->Player) are only geometrically verified
@ for the North approach (player standing south of Marek, facing up - the
@ one that's been tested). They're harmless either way for South/West/East
@ (just a turn in place), but may not point at exactly the right person
@ there until those get checked too.
PetalburgCity_Gym_EventScript_ChampFirstAppearanceMay::
	msgbox PetalburgCity_Gym_Text_ChampArrivesMay, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_GYM_CHAMP, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_KaiIntroducesPlayerMay, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_GYM_CHAMP, Common_Movement_FacePlayer
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_ChampExplainsWhyHereMay, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_GYM_CHAMP, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_MarekBestFriendsRivals, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_GYM_CHAMP, Common_Movement_FacePlayer
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	special BufferChampReunionRegionName
	msgbox PetalburgCity_Gym_Text_ChampReunionMemoryMay, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_PlayerDontRememberThat, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_ChampFatherRavedAboutYouMay, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_GYM_CHAMP, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_MarekFatherWasProud, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_MarekFatherCouldntWalk, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_GYM_CHAMP, Common_Movement_FacePlayer
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_ChampLaughsAtJokeMay, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_ChampUsedToStandHereMay, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_ChampOffersCatchDemoMay, MSGBOX_DEFAULT
	goto PetalburgCity_Gym_EventScript_ChampFirstAppearanceEnd
	end

PetalburgCity_Gym_EventScript_ChampFirstAppearanceBrendan::
	msgbox PetalburgCity_Gym_Text_ChampArrivesBrendan, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_GYM_CHAMP, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_KaiIntroducesPlayerBrendan, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_GYM_CHAMP, Common_Movement_FacePlayer
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_ChampExplainsWhyHereBrendan, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_GYM_CHAMP, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_MarekBestFriendsRivals, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_GYM_CHAMP, Common_Movement_FacePlayer
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	special BufferChampReunionRegionName
	msgbox PetalburgCity_Gym_Text_ChampReunionMemoryBrendan, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_PlayerDontRememberThat, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_ChampFatherRavedAboutYouBrendan, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_GYM_CHAMP, Common_Movement_FaceUp
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_MarekFatherWasProud, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_MarekFatherCouldntWalk, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_GYM_CHAMP, Common_Movement_FacePlayer
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_ChampLaughsAtJokeBrendan, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_ChampUsedToStandHereBrendan, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_ChampOffersCatchDemoBrendan, MSGBOX_DEFAULT
	goto PetalburgCity_Gym_EventScript_ChampFirstAppearanceEnd
	end

@ Walk out to Petalburg City for the actual catch demo battle - same exit
@ choreography/warp target Wally's tutorial used (direction-aware, just
@ like ExitGymWithWallyX below), see PetalburgCity_EventScript_ChampCatchDemo
@ for the battle itself.
PetalburgCity_Gym_EventScript_ChampFirstAppearanceEnd::
	closemessage
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_FOLLOW_ME, FALSE
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_ExitGymWithChampSouth
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ExitGymWithChampNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ExitGymWithChampWest
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ExitGymWithChampEast
	removeobject LOCALID_PETALBURG_GYM_CHAMP
	setflag FLAG_HIDE_PETALBURG_GYM_CHAMP
	@ Nyxthra story: clear the CITY object's own hide flag now, before the warp,
	@ the same way Wally's own flow clears FLAG_HIDE_PETALBURG_CITY_WALLY here -
	@ that way the Champ is already visible (standing at their spot) the instant
	@ the city map loads, instead of only appearing a beat later once the
	@ OnFrame-triggered catch-demo script gets around to an addobject.
	clearflag FLAG_HIDE_PETALBURG_CITY_CHAMP
	setvar VAR_PETALBURG_GYM_STATE, 9
	setvar VAR_PETALBURG_CITY_STATE, 5
	warp MAP_PETALBURG_CITY, 15, 8
	waitstate
	release
	end

PetalburgCity_Gym_EventScript_ExitGymWithChampSouth::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_CHAMP, PetalburgCity_Gym_Movement_WallyExitSouthWest
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallySouth
	waitmovement 0
	return

@ Nyxthra story: uses the South/West exit movement (3x walk_down), not
@ WallyExitNorth (4x walk_down) - that extra step was tuned for Wally's own
@ North arrival endpoint (one row further up, see WallyArriveNorth), which
@ ChampArriveNorth deliberately doesn't use (see its own comment above). The
@ Champ's actual starting row here now matches the South/West case exactly,
@ so the exit needs to match those too, or it overshoots by one tile.
PetalburgCity_Gym_EventScript_ExitGymWithChampNorth::
	applymovement LOCALID_PETALBURG_GYM_CHAMP, PetalburgCity_Gym_Movement_WallyExitSouthWest
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithChampWest::
	applymovement LOCALID_PETALBURG_GYM_CHAMP, PetalburgCity_Gym_Movement_WallyExitSouthWest
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyWest
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithChampEast::
	applymovement LOCALID_PETALBURG_GYM_CHAMP, PetalburgCity_Gym_Movement_WallyExitEast
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyEast
	waitmovement 0
	return

@ Triggered by PetalburgCity_Gym_OnFrame once the Champ's catch demo warps
@ you back in (VAR_PETALBURG_GYM_STATE == 9) - mirrors
@ PetalburgCity_Gym_EventScript_ReturnFromWallyTutorial below (including the
@ actual walk-to-the-door exit, which was missing before - the Champ needs
@ to visibly and audibly leave, not just vanish), just with the Champ saying
@ goodbye instead of Wally.
@ Nyxthra story: Marek's parting question here is a quiet hook, not a
@ reveal - the player has no reason yet to know this is literally the
@ reigning Champion of Hoenn (that's only ever officially shown once you
@ challenge the League). An astute player might clock it; the game never
@ spells it out.
PetalburgCity_Gym_EventScript_ReturnFromChampCatchDemo::
	lockall
	specialvar VAR_RESULT, IsChampionMay
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_ReturnFromChampCatchDemoMay
	msgbox PetalburgCity_Gym_Text_DadSoDidItWorkOut, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_ChampLikeAlwaysBrendan, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_MarekAskAboutCompetition, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_ChampStayVigilantBrendan, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_GYM_CHAMP, Common_Movement_FacePlayer
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_ChampSaysByeBrendan, MSGBOX_DEFAULT
	goto PetalburgCity_Gym_EventScript_ReturnFromChampCatchDemoEnd
PetalburgCity_Gym_EventScript_ReturnFromChampCatchDemoMay::
	msgbox PetalburgCity_Gym_Text_DadSoDidItWorkOut, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_ChampLikeAlwaysMay, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_MarekAskAboutCompetition, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_ChampStayVigilantMay, MSGBOX_DEFAULT
	applymovement LOCALID_PETALBURG_GYM_CHAMP, Common_Movement_FacePlayer
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_ChampSaysByeMay, MSGBOX_DEFAULT
PetalburgCity_Gym_EventScript_ReturnFromChampCatchDemoEnd::
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_CHAMP, PetalburgCity_Gym_Movement_WallyExitGym
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_PETALBURG_GYM_CHAMP
	setflag FLAG_HIDE_PETALBURG_GYM_CHAMP
	delay 30
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_DadGoCollectBadges, MSGBOX_DEFAULT
	setvar VAR_PETALBURG_GYM_STATE, 2
	releaseall
	end

@ Unused now that the Champion's first appearance (ChampFirstAppearance
@ above) replaced this whole Wally tutorial trigger - left in place rather
@ than deleted, harmless as dead code.
PetalburgCity_Gym_EventScript_BeginWallyTutorialSouth::
	setvar VAR_0x8008, 0
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialNorth::
	setvar VAR_0x8008, 1
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialWest::
	setvar VAR_0x8008, 2
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorialEast::
	setvar VAR_0x8008, 3
	goto PetalburgCity_Gym_EventScript_BeginWallyTutorial
	end

PetalburgCity_Gym_EventScript_BeginWallyTutorial::
	addobject LOCALID_PETALBURG_GYM_WALLY
	playse SE_DOOR
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyArriveSouth
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyArriveNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyArriveWestEast
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyArriveWestEast
	msgbox PetalburgCity_Gym_Text_WallyIdLikeAPokemon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_DadOhYoureWallyRight, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_DadHmISee, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressPlayerWest
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressPlayerEast
	msgbox PetalburgCity_Gym_Text_DadPlayerGoWithWally, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanAddressWallySouth
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanAddressWallyNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanAddressWallyWest
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanAddressWallyEast
	msgbox PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall, MSGBOX_DEFAULT
	msgbox PetalburgCity_Gym_Text_WallyOhWowThankYou, MSGBOX_DEFAULT
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_NormanFaceDoorSouth
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_NormanFaceDoorNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_NormanFaceDoorWest
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_NormanFaceDoorEast
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_WallyFacePlayer
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallyFaceDown
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallyFacePlayer
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallyFacePlayer
	msgbox PetalburgCity_Gym_Text_WouldYouReallyComeWithMe, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_FOLLOW_ME, FALSE
	call_if_eq VAR_0x8008, 0, PetalburgCity_Gym_EventScript_ExitGymWithWallySouth
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ExitGymWithWallyWest
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ExitGymWithWallyEast
	removeobject LOCALID_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_PETALBURG_CITY_WALLYS_MOM
	setvar VAR_PETALBURG_GYM_STATE, 1
	setvar VAR_PETALBURG_CITY_STATE, 2
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLY
	clearflag FLAG_HIDE_PETALBURG_GYM_WALLY
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	special InitBirchState
	warp MAP_PETALBURG_CITY, 15, 8
	waitstate
	release
	end

PetalburgCity_Gym_EventScript_WallyArriveSouth::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArrive
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyArriveNorth::
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArriveNorth
	waitmovement 0
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyArriveWestEast::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyArrive
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallySouth::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallySouth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyNorth::
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitNorth
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyWest::
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitSouthWest
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyWest
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallyEast::
	applymovement LOCALID_PETALBURG_GYM_WALLY, PetalburgCity_Gym_Movement_WallyExitEast
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallyEast
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerSouth::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerNorth::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerWest::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressPlayerEast::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallySouth::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyNorth::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyWest::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanAddressWallyEast::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyFacePlayer::
	applymovement LOCALID_PETALBURG_GYM_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallyFaceDown::
	applymovement LOCALID_PETALBURG_GYM_WALLY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanNoBadges::
	msgbox PetalburgCity_Gym_Text_NormanGoToRustboro, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanOneBadge::
	msgbox PetalburgCity_Gym_Text_NormanGoToDewford, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanTwoBadges::
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanThreeBadges::
	msgbox PetalburgCity_Gym_Text_YouHaveGottenStronger, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_NormanFaceDoorSouth::
	return

@ For all other NormanFaceDoorX, Norman is already facing the door from NormanAddressWallyX
PetalburgCity_Gym_EventScript_NormanFaceDoorNorth::
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_NormanFaceDoorWest::
	return

PetalburgCity_Gym_EventScript_NormanFaceDoorEast::
	return

PetalburgCity_Gym_EventScript_NormanPostBattle::
	call PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_GiveEnigmaBerry
	goto_if_unset FLAG_RECEIVED_TM_FACADE, PetalburgCity_Gym_EventScript_GiveFacade2
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough
	msgbox PetalburgCity_Gym_Text_DadGoingToKeepTraining, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_GiveFacade2::
	call PetalburgCity_Gym_EventScript_GiveFacade
	release
	end

PetalburgCity_Gym_EventScript_NormanRematch::
	trainerbattle_rematch_double TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanPreRematch, PetalburgCity_Gym_Text_NormanRematchDefeat, PetalburgCity_Gym_Text_NormanRematchNeedTwoMons
	msgbox PetalburgCity_Gym_Text_NormanPostRematch, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_ShouldGiveEnigmaBerry::
	specialvar VAR_RESULT, IsEnigmaBerryValid
	goto_if_eq VAR_RESULT, FALSE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	checkitem ITEM_ENIGMA_BERRY_E_READER
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	checkpcitem ITEM_ENIGMA_BERRY_E_READER
	goto_if_eq VAR_RESULT, TRUE, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	goto_if_eq VAR_ENIGMA_BERRY_AVAILABLE, 0, PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry
	msgbox PetalburgCity_Gym_Text_GiveEnigmaBerry, MSGBOX_DEFAULT
	setvar VAR_RESULT, TRUE
	return

PetalburgCity_Gym_EventScript_DontGiveEnigmaBerry::
	setvar VAR_RESULT, FALSE
	return

PetalburgCity_Gym_EventScript_GiveEnigmaBerry::
	giveitem ITEM_ENIGMA_BERRY_E_READER
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_ENIGMA_BERRY_AVAILABLE, 0
	release
	end

PetalburgCity_Gym_EventScript_NormanBattle::
	msgbox PetalburgCity_Gym_Text_NormanIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_NORMAN_1, PetalburgCity_Gym_Text_NormanDefeat
	message PetalburgCity_Gym_Text_ReceivedBalanceBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setvar VAR_PETALBURG_GYM_STATE, 7
	setflag FLAG_BADGE05_GET
	special ResetHealLocationFromDewford
	call EventScript_HideMrBriney
	setflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	setvar VAR_0x8008, 5
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
	call PetalburgCity_Gym_EventScript_UnlockAllDoors
	special DrawWholeMapView
	call PetalburgCity_Gym_EventScript_GiveFacade
	delay 30
	msgbox PetalburgCity_Gym_Text_DadHappyAndSad, MSGBOX_DEFAULT
	closemessage
	delay 40
	playse SE_DOOR
	delay 10
	addobject LOCALID_PETALBURG_GYM_WALLYS_DAD
	switch VAR_FACING
	case DIR_NORTH, PetalburgCity_Gym_EventScript_WallysDadArrivesNorth
	case DIR_WEST, PetalburgCity_Gym_EventScript_WallysDadArrivesWest
	case DIR_EAST, PetalburgCity_Gym_EventScript_WallysDadArrivesEast
	end

PetalburgCity_Gym_EventScript_GiveFacade::
	giveitem ITEM_TM_FACADE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_RECEIVED_TM_FACADE
	msgbox PetalburgCity_Gym_Text_ExplainFacade, MSGBOX_DEFAULT
	return

PetalburgCity_Gym_EventScript_WallysDadArrivesNorth::
	setvar VAR_0x8008, 1
	goto PetalburgCity_Gym_EventScript_WallysDadArrives

PetalburgCity_Gym_EventScript_WallysDadArrivesEast::
	setvar VAR_0x8008, 2
	goto PetalburgCity_Gym_EventScript_WallysDadArrives

PetalburgCity_Gym_EventScript_WallysDadArrivesWest::
	setvar VAR_0x8008, 3
	goto PetalburgCity_Gym_EventScript_WallysDadArrives

PetalburgCity_Gym_EventScript_WallysDadArrives::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadEnterGym
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_Delay48
	waitmovement 0
	delay 10
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest
	msgbox PetalburgCity_Gym_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	delay 20
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest
	msgbox PetalburgCity_Gym_Text_LetMeBorrowPlayer, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_DONT_TRANSITION_MUSIC
	playbgm MUS_FOLLOW_ME, FALSE
	call_if_eq VAR_0x8008, 1, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth
	call_if_eq VAR_0x8008, 2, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast
	call_if_eq VAR_0x8008, 3, PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest
	removeobject LOCALID_PETALBURG_GYM_WALLYS_DAD
	setvar VAR_PETALBURG_CITY_STATE, 4
	clearflag FLAG_HIDE_PETALBURG_CITY_WALLYS_DAD
	warp MAP_PETALBURG_CITY, 15, 8
	waitstate
	release
	end

PetalburgCity_Gym_EventScript_WallysDadFaceNormanNorth::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadFaceNormanEast::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadFaceNormanWest::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadApproachPlayerNorth::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadApproachPlayerEast::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_WallysDadApproachPlayerWest::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysDadNorth::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitNorth
	applymovement LOCALID_PETALBURG_GYM_NORMAN, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysDadEast::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitEast
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast
	waitmovement 0
	return

PetalburgCity_Gym_EventScript_ExitGymWithWallysDadWest::
	applymovement LOCALID_PETALBURG_GYM_WALLYS_DAD, PetalburgCity_Gym_Movement_WallysDadExitWest
	applymovement LOCALID_PLAYER, PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest
	waitmovement 0
	return

PetalburgCity_Gym_Movement_WallysDadExitNorth:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_WallysDadExitEast:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_WallysDadExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_8
	walk_in_place_down
	set_invisible
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysDadNorth:
	delay_16
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysDadEast:
	delay_16
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallysDadWest:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

PetalburgCity_Gym_Movement_WallysDadEnterGym:
	walk_up
	delay_8
	walk_in_place_faster_right
	delay_8
	walk_in_place_faster_left
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgCity_Gym_Movement_WallysDadApproachPlayerNorth:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_right
	step_end

PetalburgCity_Gym_Movement_WallysDadApproachPlayerEast:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Movement_WallysDadApproachPlayerWest:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	step_end

PetalburgCity_Gym_Movement_Unused:
	walk_in_place_faster_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_down
	step_end

PetalburgCity_Gym_Movement_WallyArriveNorth:
	delay_16
	walk_up
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

PetalburgCity_Gym_Movement_WallyArrive:
	delay_16
	walk_up
	delay_16
	delay_8
	walk_up
	walk_up
	step_end

PetalburgCity_Gym_Movement_WallyExitNorth:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_WallyExitEast:
	walk_down
	walk_down
	walk_right
	walk_down
	walk_in_place_faster_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_WallyExitSouthWest:
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_up
	delay_16
	walk_in_place_down
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyNorth:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallySouth:
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyWest:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_Movement_PlayerExitWithWallyEast:
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	delay_8
	step_end

PetalburgCity_Gym_EventScript_NoAmountOfTrainingIsEnough::
	msgbox PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_SpeedRoomDoor::
	lockall
	goto_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 85
	msgbox PetalburgCity_Gym_Text_EnterSpeedRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_EnterRoom::
	closemessage
	delay 30
	warpdoor MAP_PETALBURG_CITY_GYM, VAR_0x8008, VAR_0x8009
	waitstate
	releaseall
	end

PetalburgCity_Gym_EventScript_DontEnterRoom::
	releaseall
	end

PetalburgCity_Gym_EventScript_DoorLocked::
	msgbox PetalburgCity_Gym_Text_DoorAppearsLocked, MSGBOX_DEFAULT
	releaseall
	end

@ VAR_0x8008 and VAR_0x8009 below are the x and y coordinates of the warp
PetalburgCity_Gym_EventScript_AccuracyRoomDoor::
	lockall
	goto_if_lt VAR_PETALBURG_GYM_STATE, 6, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 98
	msgbox PetalburgCity_Gym_Text_EnterAccuracyRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_ConfusionRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 46
	msgbox PetalburgCity_Gym_Text_EnterConfusionRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftDefenseRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_RANDALL, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 59
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightDefenseRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 59
	msgbox PetalburgCity_Gym_Text_EnterDefenseRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RecoveryRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_MARY, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 72
	msgbox PetalburgCity_Gym_Text_EnterRecoveryRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftStrengthRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_PARKER, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 20
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightStrengthRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 20
	msgbox PetalburgCity_Gym_Text_EnterStrengthRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftOHKORoomDoor::
	lockall
	goto_if_not_defeated TRAINER_ALEXIA, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 33
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightOHKORoomDoor::
	lockall
	goto_if_not_defeated TRAINER_GEORGE, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 33
	msgbox PetalburgCity_Gym_Text_EnterOHKORoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_LeftGymLeadersRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_JODY, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 7
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_RightGymLeadersRoomDoor::
	lockall
	goto_if_not_defeated TRAINER_BERKE, PetalburgCity_Gym_EventScript_DoorLocked
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 7
	msgbox PetalburgCity_Gym_Text_EnterGymLeadersRoom, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, PetalburgCity_Gym_EventScript_EnterRoom
	goto_if_eq VAR_RESULT, NO, PetalburgCity_Gym_EventScript_DontEnterRoom
	end

PetalburgCity_Gym_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL, PetalburgCity_Gym_Text_RandallIntro, PetalburgCity_Gym_Text_RandallDefeat, PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_RandallPostBadge
	msgbox PetalburgCity_Gym_Text_RandallPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenSpeedRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_RandallPostBadge::
	msgbox PetalburgCity_Gym_Text_RandallPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Parker::
	trainerbattle_single TRAINER_PARKER, PetalburgCity_Gym_Text_ParkerIntro, PetalburgCity_Gym_Text_ParkerDefeat, PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_ParkerPostBadge
	msgbox PetalburgCity_Gym_Text_ParkerPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenConfusionRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_ParkerPostBadge::
	msgbox PetalburgCity_Gym_Text_ParkerPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_George::
	trainerbattle_single TRAINER_GEORGE, PetalburgCity_Gym_Text_GeorgeIntro, PetalburgCity_Gym_Text_GeorgeDefeat, PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GeorgePostBadge
	msgbox PetalburgCity_Gym_Text_GeorgePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenRecoveryRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_GeorgePostBadge::
	msgbox PetalburgCity_Gym_Text_GeorgePostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE, PetalburgCity_Gym_Text_BerkeIntro, PetalburgCity_Gym_Text_BerkeDefeat, PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_BerkePostBadge
	msgbox PetalburgCity_Gym_Text_BerkePostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenOHKORoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenOHKORoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_BerkePostBadge::
	msgbox PetalburgCity_Gym_Text_BerkePostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Mary::
	trainerbattle_single TRAINER_MARY, PetalburgCity_Gym_Text_MaryIntro, PetalburgCity_Gym_Text_MaryDefeat, PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_MaryPostBadge
	msgbox PetalburgCity_Gym_Text_MaryPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenAccuracyRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_MaryPostBadge::
	msgbox PetalburgCity_Gym_Text_MaryPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Alexia::
	trainerbattle_single TRAINER_ALEXIA, PetalburgCity_Gym_Text_AlexiaIntro, PetalburgCity_Gym_Text_AlexiaDefeat, PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_AlexiaPostBadge
	msgbox PetalburgCity_Gym_Text_AlexiaPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenDefenseRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_AlexiaPostBadge::
	msgbox PetalburgCity_Gym_Text_AlexiaPostBadge, MSGBOX_NPC
	end

PetalburgCity_Gym_EventScript_Jody::
	trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_JodyIntro, PetalburgCity_Gym_Text_JodyDefeat, PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_JodyPostBadge
	msgbox PetalburgCity_Gym_Text_JodyPostBattle, MSGBOX_AUTOCLOSE
	end

PetalburgCity_Gym_EventScript_SlideOpenStrengthRoomDoors::
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors
	special DrawWholeMapView
	release
	end

PetalburgCity_Gym_EventScript_JodyPostBadge::
	msgbox PetalburgCity_Gym_Text_JodyPostBadge, MSGBOX_NPC
	end

@ VAR_0x8004 below is the room number
@ VAR_0x8005 below is 0 when the door should be slid open and 1 when it should be unlocked immediately
PetalburgCity_Gym_EventScript_OpenGymEntranceDoors::
	setvar VAR_0x8004, 1
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenSpeedRoomDoors::
	setvar VAR_0x8004, 2
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenAccuracyRoomDoors::
	setvar VAR_0x8004, 3
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenConfusionRoomDoors::
	setvar VAR_0x8004, 4
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenDefenseRoomDoors::
	setvar VAR_0x8004, 5
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenRecoveryRoomDoors::
	setvar VAR_0x8004, 6
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenStrengthRoomDoors::
	setvar VAR_0x8004, 7
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_OpenOHKORoomDoors::
	setvar VAR_0x8004, 8
	call_if_eq VAR_0x8005, 0, PetalburgCity_Gym_EventScript_SlideOpenRoomDoors
	call_if_eq VAR_0x8005, 1, PetalburgCity_Gym_EventScript_UnlockRoomDoors
	call PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles
	return

PetalburgCity_Gym_EventScript_SetEntranceRoomDoorMetatiles::
	setmetatile 6, 85, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 85, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	setmetatile 1, 98, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 98, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetSpeedRoomDoorMetatiles::
	setmetatile 6, 46, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 46, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	setmetatile 1, 59, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 59, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetAccuracyRoomDoorMetatiles::
	setmetatile 6, 59, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 59, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	setmetatile 1, 72, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 72, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetConfusionRoomDoorMetatiles::
	setmetatile 1, 20, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 20, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetDefenseRoomDoorMetatiles::
	setmetatile 6, 20, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 20, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	setmetatile 1, 33, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 33, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetRecoveryRoomDoorMetatiles::
	setmetatile 6, 33, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 33, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetStrengthRoomDoorMetatiles::
	setmetatile 1, 7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 2, 7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SetOHKORoomDoorMetatiles::
	setmetatile 6, 7, METATILE_PetalburgGym_RoomEntrance_Left, FALSE
	setmetatile 7, 7, METATILE_PetalburgGym_RoomEntrance_Right, FALSE
	return

PetalburgCity_Gym_EventScript_SlideOpenRoomDoors::
	special PetalburgGymSlideOpenRoomDoors
	return

PetalburgCity_Gym_EventScript_UnlockRoomDoors::
	special PetalburgGymUnlockRoomDoors
	return

PetalburgCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_GymGuidePostVictory
	msgbox PetalburgCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_GymGuidePostVictory::
	msgbox PetalburgCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

PetalburgCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
	goto PetalburgCity_Gym_EventScript_GymStatue
	end

PetalburgCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_EventScript_GymStatueCertified
	goto PetalburgCity_Gym_EventScript_GymStatue
	end

PetalburgCity_Gym_EventScript_GymStatueCertified::
	msgbox PetalburgCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_EventScript_GymStatue::
	msgbox PetalburgCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

PetalburgCity_Gym_Text_DadYoureHereWithYourPokemon:
	.string "Marek: Hm?\p"
	.string "Na, wenn das nicht {PLAYER} ist!\n"
	.string "Ihr habt also den Umzug gepackt?\p"
	.string "Krass, dass du ganz alleine hergefunden\n"
	.string "hast.\p"
	.string "Mensch, ich hab dich zuletzt gesehen,\n"
	.string "da warst du noch ein Baby.\p"
	.string "Ah, verstehe.\n"
	.string "Du bist sogar schon mit Pokémon\l"
	.string "unterwegs.\p"
	.string "Ich hab das Gefühl, du trittst echt mal\n"
	.string "in die Fußstapfen deines Vaters, {PLAYER}.\p"
	.string "Das gefällt mir. Ich freu mich drauf.$"

PetalburgCity_Gym_Text_WallyIdLikeAPokemon:
	.string "Ähm… Ich… Ich hätte so gerne\n"
	.string "ein Pokémon. Bitte…$"

PetalburgCity_Gym_Text_DadOhYoureWallyRight:
	.string "Marek: Hm? Du… Ach ja, stimmt.\n"
	.string "Du bist Heiko, oder?$"

PetalburgCity_Gym_Text_WallyIveNeverCaughtAPokemon:
	.string "Heiko: Ich fahr bald zu meinen Verwandten\n"
	.string "nach Wiesenflur.\p"
	.string "Ich glaub, ich werd mich dort bisschen\n"
	.string "allein fühlen, also…\p"
	.string "Ich hätte gerne ein Pokémon bei mir.\n"
	.string "Aber ich hab noch nie eins gefangen…$"

PetalburgCity_Gym_Text_DadHmISee:
	.string "Marek: Hm, ich verstehe…$"

PetalburgCity_Gym_Text_ChampArrivesMay:
	.string "Mai: Moment mal…\n"
	.string "Bist du das wirklich, {PLAYER}?\p"
	.string "Krass…\n"
	.string "Dich hätte ich fast nicht erkannt.$"

PetalburgCity_Gym_Text_ChampArrivesBrendan:
	.string "Brix: Warte mal…\n"
	.string "Bist du das wirklich, {PLAYER}?\p"
	.string "Alter…\n"
	.string "Dich hätte ich fast nicht erkannt.$"

@ Nyxthra story: expanded first-meeting scene (Champ actually came to check
@ in on Marek, not looking for the player at all - finding them here is the
@ surprise) - split across several shorter texts instead of one long block
@ so the facing changes above land between the right lines.
PetalburgCity_Gym_Text_KaiIntroducesPlayerMay:
	.string "Marek: Na, das nenn ich mal Timing.\p"
	.string "Du wolltest doch sowieso wissen,\n"
	.string "wie ich mich hier so schlage.\p"
	.string "Wie du siehst - die Arena steht noch.$"

PetalburgCity_Gym_Text_KaiIntroducesPlayerBrendan:
	.string "Marek: Na, das nenn ich mal Timing.\p"
	.string "Du wolltest doch sowieso wissen,\n"
	.string "wie ich mich hier so schlage.\p"
	.string "Wie du siehst - die Arena steht noch.$"

PetalburgCity_Gym_Text_ChampExplainsWhyHereMay:
	.string "Mai: Noch.\p"
	.string "Ich wollte nur kurz vorbeischauen\n"
	.string "und sehen, ob du hier klarkommst.\p"
	.string "Aber mit {PLAYER} hab ich heute\n"
	.string "wirklich nicht gerechnet.$"

PetalburgCity_Gym_Text_ChampExplainsWhyHereBrendan:
	.string "Brix: Noch.\p"
	.string "Ich wollte nur kurz vorbeischauen\n"
	.string "und sehen, ob du hier klarkommst.\p"
	.string "Aber mit {PLAYER} hab ich heute\n"
	.string "wirklich nicht gerechnet.$"

PetalburgCity_Gym_Text_MarekBestFriendsRivals:
	.string "Marek: Dein Vater und ich waren\n"
	.string "jahrelang die dicksten Freunde.\p"
	.string "Und gleichzeitig Rivalen.\p"
	.string "Norman konnte verlieren wie kaum\n"
	.string "ein anderer Mensch.\p"
	.string "Vor allem gegen mich.$"

PetalburgCity_Gym_Text_ChampReunionMemoryMay:
	.string "Mai: Eigentlich kennen wir uns\n"
	.string "sogar schon ziemlich lange.\p"
	.string "Das letzte Mal hab ich dich in\n"
	.string "{STR_VAR_1} gesehen.\p"
	.string "Da warst du noch ein Baby.$"

PetalburgCity_Gym_Text_ChampReunionMemoryBrendan:
	.string "Brix: Eigentlich kennen wir uns\n"
	.string "sogar schon ziemlich lange.\p"
	.string "Das letzte Mal hab ich dich in\n"
	.string "{STR_VAR_1} gesehen.\p"
	.string "Da warst du noch ein Baby.$"

PetalburgCity_Gym_Text_PlayerDontRememberThat:
	.string "{PLAYER}: … Ernsthaft?\n"
	.string "Daran erinnere ich mich überhaupt nicht.$"

PetalburgCity_Gym_Text_ChampFatherRavedAboutYouMay:
	.string "Mai: Würde mich auch wundern.\n"
	.string "Du warst wirklich winzig.\p"
	.string "Aber vergessen hab ich dich trotzdem\n"
	.string "nicht.$"

PetalburgCity_Gym_Text_ChampFatherRavedAboutYouBrendan:
	.string "Brix: Würde mich auch wundern.\n"
	.string "Du warst wirklich winzig.\p"
	.string "Aber vergessen hab ich dich trotzdem\n"
	.string "nicht.$"

PetalburgCity_Gym_Text_MarekFatherWasProud:
	.string "Marek: Norman dagegen hat damals\n"
	.string "wirklich jedem von dir erzählt.\p"
	.string "Der Kerl war unerträglich stolz.$"

PetalburgCity_Gym_Text_MarekFatherCouldntWalk:
	.string "Marek: Ich hab ihm immer gesagt,\n"
	.string "er soll mal langsam machen.\p"
	.string "Du konntest ja noch nicht mal laufen.$"

PetalburgCity_Gym_Text_ChampLaughsAtJokeMay:
	.string "Mai: Haha… ja.\n"
	.string "Das klingt wirklich nach Norman.\p"
	.string "Wenn der einmal stolz auf etwas war,\n"
	.string "wusste es danach ganz Hoenn.$"

PetalburgCity_Gym_Text_ChampLaughsAtJokeBrendan:
	.string "Brix: Haha… ja.\n"
	.string "Das klingt wirklich nach Norman.\p"
	.string "Wenn der einmal stolz auf etwas war,\n"
	.string "wusste es danach ganz Hoenn.$"

PetalburgCity_Gym_Text_ChampUsedToStandHereMay:
	.string "Mai: Aber genug von früher.\p"
	.string "{PLAYER}, du bist jetzt selbst\n"
	.string "mit einem Pokémon unterwegs.\p"
	.string "Dann sollte dir wenigstens jemand\n"
	.string "zeigen, wie man eins fängt.\p"
	.string "Und wo ich schon mal hier bin…\n"
	.string "übernehm ich das.$"

PetalburgCity_Gym_Text_ChampUsedToStandHereBrendan:
	.string "Brix: Aber genug von früher.\p"
	.string "{PLAYER}, du bist jetzt selbst\n"
	.string "mit einem Pokémon unterwegs.\p"
	.string "Dann sollte dir wenigstens jemand\n"
	.string "zeigen, wie man eins fängt.\p"
	.string "Und wo ich schon mal hier bin…\n"
	.string "übernehm ich das.$"

PetalburgCity_Gym_Text_ChampOffersCatchDemoMay:
	.string "Mai: Pass gut auf!$"

PetalburgCity_Gym_Text_ChampOffersCatchDemoBrendan:
	.string "Brix: Pass gut auf!$"

PetalburgCity_Gym_Text_ChampCatchDemoMay:
	.string "Mai: Los, FLEMMLI!\p"
	.string "Ein wildes Zigzachs erscheint!\p"
	.string "Mai: Ein Angriff reicht meistens\n"
	.string "schon, um's zu schwächen.\p"
	.string "So, und jetzt…\p"
	.string "Mai: Pokéball, los!\p"
	.string "Geschafft!\n"
	.string "So einfach ist das.$"

PetalburgCity_Gym_Text_ChampCatchDemoBrendan:
	.string "Brix: Los, HYDROPI!\p"
	.string "Ein wildes Zigzachs erscheint!\p"
	.string "Brix: Ein Angriff reicht meistens\n"
	.string "schon, um's zu schwächen.\p"
	.string "So, und jetzt…\p"
	.string "Brix: Pokéball, los!\p"
	.string "Geschafft!\n"
	.string "So einfach ist das.$"

PetalburgCity_Gym_Text_ChampLikeAlwaysMay:
	.string "Mai: Wie immer.$"

PetalburgCity_Gym_Text_ChampLikeAlwaysBrendan:
	.string "Brix: Wie immer.$"

PetalburgCity_Gym_Text_MarekAskAboutCompetition:
	.string "Marek: Und?\n"
	.string "Zufrieden mit dem Laden?\p"
	.string "Oder kommt jetzt wieder deine Liste\n"
	.string "mit hundert Verbesserungsvorschlägen?$"

PetalburgCity_Gym_Text_ChampStayVigilantMay:
	.string "Mai: Heute nicht.\p"
	.string "Du schlägst dich besser,\n"
	.string "als ich erwartet hab.\p"
	.string "Aber gewöhn dich nicht an das Lob.$"

PetalburgCity_Gym_Text_ChampStayVigilantBrendan:
	.string "Brix: Heute nicht.\p"
	.string "Du schlägst dich besser,\n"
	.string "als ich erwartet hab.\p"
	.string "Aber gewöhn dich nicht an das Lob.$"

PetalburgCity_Gym_Text_ChampSaysByeMay:
	.string "Mai: So, {PLAYER}.\n"
	.string "Jetzt weißt du, wie's geht.\p"
	.string "Wir sehen uns bestimmt wieder.\p"
	.string "Und… pass auf dich auf, ja?$"

PetalburgCity_Gym_Text_ChampSaysByeBrendan:
	.string "Brix: So, {PLAYER}.\n"
	.string "Jetzt weißt du, wie's geht.\p"
	.string "Wir sehen uns garantiert wieder.\p"
	.string "Und… pass auf dich auf, ja?$"

PetalburgCity_Gym_Text_DadPlayerGoWithWally:
	.string "Marek: {PLAYER}, hast du das mitbekommen?\p"
	.string "Hilf Heiko bitte beim Fangen\n"
	.string "seines ersten Pokémon.$"

PetalburgCity_Gym_Text_IllLoanYouMyZigzagoon:
	.string "Heiko, hier. Ich leih dir mal\n"
	.string "eins meiner Pokémon.\p"
	.string "Heiko bekommt ein Zigzachs.$"

PetalburgCity_Gym_Text_WallyThankYouAndDadGivesPokeBall:
	.string "Heiko: Oh wow!!!\n"
	.string "Ein Pokémon!\p"
	.string "Marek: Hier, ich geb dir auch einen\n"
	.string "Pokéball. Viel Erfolg!\p"
	.string "Heiko erhält einen Pokéball!$"

PetalburgCity_Gym_Text_WouldYouReallyComeWithMe:
	.string "{PLAYER}… Kommst du echt mit mir???$"

PetalburgCity_Gym_Text_WallyOhWowThankYou:
	.string "Heiko: Oh wow!!!\n"
	.string "Danke dir!$"

PetalburgCity_Gym_Text_DadSoDidItWorkOut:
	.string "Marek: Na? Hat's geklappt?$"

PetalburgCity_Gym_Text_WallyThankYouBye:
	.string "Heiko: Danke! Es war mega.\n"
	.string "Hier ist dein Pokémon zurück.\p"
	.string "Und danke, {PLAYER}, fürs Mitkommen!\p"
	.string "Nur dank euch konnte ich mein\n"
	.string "erstes Pokémon fangen.\p"
	.string "Ich verspreche, ich kümmere mich gut\n"
	.string "darum!\p"
	.string "Oh! Meine Mom wartet bestimmt schon!\n"
	.string "Ich muss los!\p"
	.string "Bis bald, {PLAYER}!$"

PetalburgCity_Gym_Text_DadGoCollectBadges:
	.string "Marek: Also…\p"
	.string "{PLAYER}, wenn du ein richtig guter\n"
	.string "Trainer werden willst, hör zu:\p"
	.string "Geh nach Metarost City, gleich hinter\n"
	.string "der Route hier.\p"
	.string "Dort solltest du die Arenaleiterin\n"
	.string "FELIZIA herausfordern.\p"
	.string "Dann besiegst du noch weitere Arenen -\n"
	.string "und sammelst dir die Orden.$"

PetalburgCity_Gym_Text_NormanGoToRustboro:
	.string "Marek: Hm? Wolltest du nicht zur Arena\n"
	.string "in Metarost City?\p"
	.string "Ich kämpfe nicht gegen Frischlinge -\n"
	.string "tut mir leid, {PLAYER}.\p"
	.string "Komm zurück, wenn du mindestens\n"
	.string "vier Orden hast.$"

PetalburgCity_Gym_Text_NormanGoToDewford:
	.string "Marek: Ah, du hast Felizia in Metarost\n"
	.string "besiegt? Stark.\p"
	.string "Aber da draußen warten noch\n"
	.string "viel stärkere Trainer, {PLAYER}.\p"
	.string "Geh nach Faustauhaven - da ist Kamillo.\n"
	.string "Der wird dich fordern.$"

PetalburgCity_Gym_Text_YouHaveGottenStronger:
	.string "Marek: Hm… {PLAYER}, du bist echt stärker\n"
	.string "geworden.\p"
	.string "Man sieht's an deinen Orden.$"

PetalburgCity_Gym_Text_NormanIntro:
	.string "Marek: Hm…\n"
	.string "Du hast also vier Orden.\p"
	.string "Wie versprochen gibt’s jetzt den Kampf.\p"
	.string "{PLAYER}…\p"
	.string "Dein Vater wäre stolz, wenn er sehen\n"
	.string "könnte, wie stark du geworden bist.\p"
	.string "Aber jetzt bin ich dran, dich zu fordern.\p"
	.string "Ich kämpfe als Arenaleiter - und gebe\n"
	.string "alles.\p"
	.string "Also los, {PLAYER}. Zeig, was du kannst!$"

PetalburgCity_Gym_Text_NormanDefeat:
	.string "…\p"
	.string "Ich… Ich fass es nicht…\p"
	.string "Ich hab wirklich gegen dich verloren…\p"
	.string "Regeln sind Regeln.\n"
	.string "Hier ist dein Orden.$"

PetalburgCity_Gym_Text_ReceivedBalanceBadge:
	.string "{PLAYER} bekommt den Balanceorden\n"
	.string "von Marek!$"

PetalburgCity_Gym_Text_ExplainBalanceBadgeTakeThis:
	.string "Marek: Mit diesem Orden steigt die\n"
	.string "Verteidigung deiner Pokémon.\p"
	.string "Und Pokémon mit der VM Surfer können\n"
	.string "jetzt übers Wasser gleiten.\p"
	.string "Und hier - das ist mein Geschenk für dich.\n"
	.string "Mach was draus, {PLAYER}.$"

PetalburgCity_Gym_Text_ExplainFacade:
	.string "Marek: TM42 enthält Fassade.\p"
	.string "Die Attacke wird doppelt so stark,\n"
	.string "wenn das Pokémon z. B. vergiftet,\l"
	.string "verbrannt oder paralysiert ist.\p"
	.string "Aus einem Nachteil kann man so\n"
	.string "einen Vorteil machen.$"

PetalburgCity_Gym_Text_DadHappyAndSad:
	.string "Marek: Als Arenaleiter bin ich… enttäuscht.\p"
	.string "Aber als der, der dich aufwachsen sah,\n"
	.string "bin ich unglaublich stolz.\p"
	.string "Und ein bisschen wehmütig, ehrlich gesagt.\n"
	.string "Dein Vater wäre das jetzt auch.$"

PetalburgCity_Gym_Text_PleaseComeWithMe:
	.string "Ah, da bist du ja, {PLAYER}{KUN}!\p"
	.string "Komm bitte kurz mit - ich hab\n"
	.string "etwas für dich.$"

PetalburgCity_Gym_Text_LetMeBorrowPlayer:
	.string "Marek, du hast doch nix dagegen?\p"
	.string "Ich entführ {PLAYER}{KUN} mal kurz\n"
	.string "für ein paar Minuten.$"

PetalburgCity_Gym_Text_DadGoingToKeepTraining:
	.string "Marek: {PLAYER}, besuch deinen Opa mal öfter.\p"
	.string "Ich bleib hier und trainier doppelt so hart.\p"
	.string "Ich will irgendwann Revanche - du bist\n"
	.string "jetzt mein Ziel als Trainer.$"

PetalburgCity_Gym_Text_DadNoAmountOfTrainingIsEnough:
	.string "Marek: {PLAYER}! Na, wie läuft’s?\p"
	.string "Die Welt der Pokémon ist riesig…\p"
	.string "Egal wie hart man trainiert -\n"
	.string "man kommt nie ganz an alles ran.$"

PetalburgCity_Gym_Text_GymGuideAdvice:
	.string "Na, {PLAYER}, bereit für den CHAMP-Weg?\p"
	.string "Die Türen in dieser Arena öffnen sich,\n"
	.string "wenn du alle Trainer im Raum besiegst.\p"
	.string "Oh! Diese hier ist schon offen - bitte\n"
	.string "nicht angreifen, ich arbeite nur hier!\p"
	.string "Die Trainer in dieser Arena setzen\n"
	.string "verschiedene Items ein.\p"
	.string "Links geht’s in den INITIATIVE-Raum,\n"
	.string "rechts in den GENAUIGKEIT-Raum.\p"
	.string "Alle Türen sind beschriftet - überleg\n"
	.string "gut, bevor du eine öffnest.\p"
	.string "Na dann… Viel Glück!$"

PetalburgCity_Gym_Text_GymGuidePostVictory:
	.string "{PLAYER}! Du hast sogar Marek besiegt!\p"
	.string "Und der kennt dich schon, seit du ein\n"
	.string "Baby warst!\p"
	.string "Unfassbar! Was für ein Comeback!$"

PetalburgCity_Gym_Text_RandallIntro:
	.string "Wer schneller angreift, gewinnt oft den\n"
	.string "Kampf. Findest du nicht auch?$"

PetalburgCity_Gym_Text_RandallDefeat:
	.string "Krasser Kampf!$"

PetalburgCity_Gym_Text_RandallPostBattle:
	.string "Weiter geht’s: Links ist der VERWIRRUNG-Raum,\n"
	.string "rechts der VERTEIDIGUNG-Raum.$"

PetalburgCity_Gym_Text_RandallPostBadge:
	.string "Egal ob Sieg oder Niederlage -\n"
	.string "Training ist das Wichtigste.$"

PetalburgCity_Gym_Text_ParkerIntro:
	.string "Dies ist der VERWIRRUNG-Raum.\p"
	.string "Zeig mir, wie gut du dein Team kennst.$"

PetalburgCity_Gym_Text_ParkerDefeat:
	.string "Unser Band war nicht stark genug…$"

PetalburgCity_Gym_Text_ParkerPostBattle:
	.string "Der nächste Raum ist STÄRKE.\n"
	.string "Mal sehen, wie du mit roher Power klarkommst.$"

PetalburgCity_Gym_Text_ParkerPostBadge:
	.string "Seit du Marek besiegt hast, ist das\n"
	.string "Training in der Arena viel härter geworden.$"

PetalburgCity_Gym_Text_GeorgeIntro:
	.string "Kurz vorm Sieg - zack, Gegner heilt sich.\p"
	.string "Kennst du das Gefühl? Ich zeig's dir.$"

PetalburgCity_Gym_Text_GeorgeDefeat:
	.string "Nicht mal Heilen hat gereicht…$"

PetalburgCity_Gym_Text_GeorgePostBattle:
	.string "Ich hab gehört, Marek kennt dich schon,\n"
	.string "seit du ein Baby warst…\p"
	.string "Dann wundert mich dein Können nicht.\p"
	.string "Nächster Raum: K.O.-TREFFER-RAUM!$"

PetalburgCity_Gym_Text_GeorgePostBadge:
	.string "Ich werd selbst Arenaleiter!\n"
	.string "Irgendwann.$"

PetalburgCity_Gym_Text_BerkeIntro:
	.string "Nur weil Marek dich kennt,\n"
	.string "kriegst du keine Sonderbehandlung.\p"
	.string "Ich zeig dir, wie sich ein Volltreffer\n"
	.string "anfühlt!$"

PetalburgCity_Gym_Text_BerkeDefeat:
	.string "Stark! Respekt.$"

PetalburgCity_Gym_Text_BerkePostBattle:
	.string "Marek ist echt ein Monster.\n"
	.string "Und du? Ebenfalls gefährlich.$"

PetalburgCity_Gym_Text_BerkePostBadge:
	.string "Seit Marek hier Leiter ist, ist das Niveau\n"
	.string "deutlich gestiegen.$"

PetalburgCity_Gym_Text_MaryIntro:
	.string "Kicher… GENAUIGKEIT ist mies fies.\p"
	.string "Wenn jeder Angriff trifft… Heftig, oder?$"

PetalburgCity_Gym_Text_MaryDefeat:
	.string "Du bist… etwas besser als ich.$"

PetalburgCity_Gym_Text_MaryPostBattle:
	.string "Links ist der VERTEIDIGUNG-Raum,\n"
	.string "rechts ERHOLUNG.\n"
	.string "Beide werden deine Moves testen.$"

PetalburgCity_Gym_Text_MaryPostBadge:
	.string "Wir streben danach, eins zu werden -\n"
	.string "mit unseren Pokémon.$"

PetalburgCity_Gym_Text_AlexiaIntro:
	.string "Mit guter Verteidigung greif ich noch\n"
	.string "härter an. Bereit?$"

PetalburgCity_Gym_Text_AlexiaDefeat:
	.string "Verteidigung war nicht genug…$"

PetalburgCity_Gym_Text_AlexiaPostBattle:
	.string "Danke, du hast mir was gezeigt.\p"
	.string "Links: STÄRKE - Rechts: K.O.-Treffer.\p"
	.string "Beide Räume sind kein Zuckerschlecken.$"

PetalburgCity_Gym_Text_AlexiaPostBadge:
	.string "Hast du Surfer schon ausprobiert?$"

PetalburgCity_Gym_Text_JodyIntro:
	.string "Marek meinte: Gib alles gegen {PLAYER}!\p"
	.string "Ist mir egal, dass er dich schon als\n"
	.string "Baby kannte!$"

PetalburgCity_Gym_Text_JodyDefeat:
	.string "Oof. Das war nix.$"

PetalburgCity_Gym_Text_JodyPostBattle:
	.string "Dein Kampfstil… Erinnert an deinen\n"
	.string "Vater, hab ich gehört.\p"
	.string "Marek wartet schon auf dich.$"

PetalburgCity_Gym_Text_JodyPostBadge:
	.string "Stärke ist gut - aber ohne Vertrauen\n"
	.string "zwischen dir und deinem Team\n"
	.string "bist du kein Sieger.$"

PetalburgCity_Gym_Text_DoorAppearsLocked:
	.string "Die Tür ist noch verschlossen…$"

PetalburgCity_Gym_Text_EnterSpeedRoom:
	.string "“INITIATIVE-RAUM” steht auf\n"
	.string "dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"

@ Unused
PetalburgCity_Gym_Text_DoorAppearsLocked2:
	.string "This door appears to be locked\n"
	.string "right now…$"

PetalburgCity_Gym_Text_EnterAccuracyRoom:
	.string "“RAUM der GENAUIGKEIT” steht\n"
	.string "auf dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"

PetalburgCity_Gym_Text_EnterConfusionRoom:
	.string "“RAUM der VERWIRRUNG”\n"
	.string "steht auf dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"

PetalburgCity_Gym_Text_EnterDefenseRoom:
	.string "“RAUM der VERTEIDIGUNG” steht\n"
	.string "auf dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"

PetalburgCity_Gym_Text_EnterRecoveryRoom:
	.string "“RAUM der ERHOLUNG” steht auf\n"
	.string "dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"

PetalburgCity_Gym_Text_EnterStrengthRoom:
	.string "“RAUM der STÄRKE” steht auf\n"
	.string "dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"

PetalburgCity_Gym_Text_EnterOHKORoom:
	.string "“K.O.-TREFFER-RAUM”\n"
	.string "steht auf dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"

PetalburgCity_Gym_Text_EnterGymLeadersRoom:
	.string "“ARENALEITER”\p"
	.string "“Sieh selbst, welche POKéMON dich\n"
	.string "erwarten!” steht auf dem Schild.\p"
	.string "Möchtest du die Tür öffnen?$"

PetalburgCity_Gym_Text_GymStatue:
	.string "POKéMON ARENA von BLÜTENBURG CITY$"

PetalburgCity_Gym_Text_GymStatueCertified:
	.string "POKéMON ARENA von BLÜTENBURG CITY\p"
	.string "KAIs ANERKANNTE TRAINER:\n"
	.string "{PLAYER}$"

PetalburgCity_Gym_Text_NormanPreRematch:
	.string "Marek: {PLAYER}…\n"
	.string "Ich wusste, dass du wiederkommst.\p"
	.string "Ich würde niemals eine Herausforderung\n"
	.string "von dir ablehnen.\p"
	.string "Weißt du, was ich meine?\p"
	.string "In der Arena zählt nicht, dass wir\n"
	.string "uns schon ewig kennen.\p"
	.string "Im Gegenteil - gerade deshalb müssen\n"
	.string "wir beide alles geben.\n"
	.string "Oder, {PLAYER}?$"

PetalburgCity_Gym_Text_NormanRematchDefeat:
	.string "Äh… Haha…\n"
	.string "Du bist wirklich ein harter Brocken.$"

PetalburgCity_Gym_Text_NormanPostRematch:
	.string "Marek: {PLAYER}…\n"
	.string "Was ist eigentlich dein Traum?\p"
	.string "{COLOR PLAYER_CLR}{PLAYER}: Mein Traum…?\n"
	.string "Hahaha…\l"
	.string "Ich glaub, der ist längst wahr geworden.\p"
    .string "Spaß, natürlich der Stärkste werden!\p{COLOR WHITE}"
    .string "Marek: Hm, das ist ein guter Traum.\p"
    .string "Ich bin stolz auf dich, {PLAYER}.\n"
    .string "Du bist ein toller Trainer geworden.\l"
    .string "Ich bin mir sicher, dass du es schaffst!$"

PetalburgCity_Gym_Text_NormanRematchNeedTwoMons:
	.string "Marek: {PLAYER}…\n"
	.string "Ich wusste, dass du wiederkommst.\p"
	.string "Ich würde niemals eine Herausforderung\n"
	.string "von dir ablehnen.\p"
	.string "Weißt du, was ich meine?\p"
	.string "In der Arena zählt nicht, dass wir\n"
	.string "uns schon ewig kennen.\p"
	.string "Hm? Moment mal, {PLAYER}…\p"
	.string "Du hast nur ein einziges Pokémon,\n"
	.string "das kämpfen kann?\p"
	.string "Tut mir leid, aber du brauchst mindestens\n"
	.string "zwei Pokémon für diesen Kampf.$"

