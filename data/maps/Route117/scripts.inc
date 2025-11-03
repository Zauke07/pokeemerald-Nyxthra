.set LOCALID_DAYCARE_MON_0, 25
.set LOCALID_DAYCARE_MON_1, 26

Route117_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_OnTransition
	.byte 0

Route117_OnTransition:
	call Route117_EventScript_TryMoveDayCareMan
	@ set flags for OW daycare mons
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	getdaycaregfx VAR_OBJ_GFX_ID_0, VAR_OBJ_GFX_ID_1, VAR_TEMP_0, VAR_TEMP_1
	switch VAR_RESULT
	case 2, Route117_EventScript_ShowDaycareMon1
	case 1, Route117_EventScript_ShowDaycareMon0
	end

Route117_EventScript_ShowDaycareMon1:
	@ set pokemon movement type based on compatibility
	special SetDaycareCompatibilityString
	call_if_eq VAR_RESULT, PARENTS_INCOMPATIBLE, Route117_EventScript_DaycareMonIncompatible
	@ Don't do anything if PARENTS_LOW_COMPATIBILITY
	call_if_eq VAR_RESULT, PARENTS_MED_COMPATIBILITY, Route117_EventScript_DaycareMonMedCompatibility
	call_if_eq VAR_RESULT, PARENTS_MAX_COMPATIBILITY, Route117_EventScript_DaycareMonMaxCompatibility
	clearflag FLAG_TEMP_2
Route117_EventScript_ShowDaycareMon0:
	clearflag FLAG_TEMP_1
	end

Route117_EventScript_DaycareMonIncompatible: @ mons never face each other
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_FACE_DOWN_UP_AND_LEFT
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_FACE_DOWN_UP_AND_RIGHT
	return

Route117_EventScript_DaycareMonMedCompatibility: @ down and towards each other
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_FACE_DOWN_AND_LEFT
	return

Route117_EventScript_DaycareMonMaxCompatibility: @ facing; walk in place
	setobjectmovementtype LOCALID_DAYCARE_MON_0, MOVEMENT_TYPE_WALK_IN_PLACE_RIGHT
	setobjectmovementtype LOCALID_DAYCARE_MON_1, MOVEMENT_TYPE_WALK_IN_PLACE_LEFT
	return

Route117_EventScript_TryMoveDayCareMan::
	@ Quest noch nicht abgeschlossen
	goto_if_unset FLAG_DAYCARE_RESCUE_QUEST_COMPLETED, Route117_EventScript_RescueQuestActive
	@ Quest abgeschlossen - normales Verhalten
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, Route117_EventScript_StopMoveDayCareMan
	setobjectxyperm LOCALID_DAYCARE_MAN, 47, 6
Route117_EventScript_StopMoveDayCareMan::
	return

Route117_EventScript_RescueQuestActive::
	@ Wenn Ei bereit ist, verstecke den bösen NPC (er ist dann im Labor)
	goto_if_set FLAG_PENDING_DAYCARE_EGG, Route117_EventScript_HideEvilNPC
	@ Sonst: Verstecke Old Man, zeige bösen NPC
	setflag FLAG_HIDE_ROUTE117_DAYCARE_MAN
	clearflag FLAG_HIDE_ROUTE117_EVIL_NPC
	return

Route117_EventScript_HideEvilNPC::
	@ Böser NPC ist jetzt im Labor
	setflag FLAG_HIDE_ROUTE117_EVIL_NPC
	setflag FLAG_HIDE_ROUTE117_DAYCARE_MAN
	return

@ Böser NPC Script (auf Route 117)
Route117_EventScript_EvilNPC::
	lock
	faceplayer
	@ Vor dem Ei - normales Verhalten wie Old Man
	goto_if_unset FLAG_PENDING_DAYCARE_EGG, Route117_EventScript_EvilNPCNormalDialogue
	@ Wenn Ei bereit ist, soll Spieler ins Labor gehen
	msgbox Route117_Text_EvilNPCEggReady, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_EvilNPCNormalDialogue::
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route117_EventScript_EvilNPCCheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route117_EventScript_EvilNPCCheckOnTwoMons
	msgbox Route117_Text_EvilNPCSeeWife, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_EvilNPCCheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

Route117_EventScript_EvilNPCCheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route117_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route117_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route117_EventScript_CheckMonReceivedMail
	release
	end

@ NEUE TEXTE für bösen NPC

Route117_Text_EvilNPCSeeWife:
	.string "Wenn du möchtest, dass ich mich um ein\n"
	.string "Pokémon kümmere, sprich mit meiner\l"
	.string "Frau drinnen.$"

Route117_Text_EvilNPCEggReady:
	.string "Hm… wo ist das EI geblieben?\p"
	.string "Ich glaube… äh… ich muss mal kurz\n"
	.string "nachschauen…$"

Route117_EventScript_Isaac::
	trainerbattle_single TRAINER_ISAAC_1, Route117_Text_IsaacIntro, Route117_Text_IsaacDefeat, Route117_EventScript_RegisterIsaac
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchIsaac
	msgbox Route117_Text_IsaacPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_Woman::
	msgbox Route117_Text_ArentTheseFlowersPretty, MSGBOX_NPC
	end

Route117_EventScript_LittleBoy::
	msgbox Route117_Text_AirIsTastyHere, MSGBOX_NPC
	end

Route117_EventScript_Girl::
	msgbox Route117_Text_DayCarePokemonHadNewMove, MSGBOX_NPC
	end

Route117_EventScript_RouteSignVerdanturf::
	msgbox Route117_Text_RouteSignVerdanturf, MSGBOX_SIGN
	end

Route117_EventScript_RouteSignMauville::
	msgbox Route117_Text_RouteSignMauville, MSGBOX_SIGN
	end

Route117_EventScript_DayCareSign::
	msgbox Route117_Text_DayCareSign, MSGBOX_SIGN
	end

Route117_EventScript_RegisterIsaac::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route117_Text_IsaacRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISAAC_1
	release
	end

Route117_EventScript_RematchIsaac::
	trainerbattle_rematch TRAINER_ISAAC_1, Route117_Text_IsaacRematchIntro, Route117_Text_IsaacRematchDefeat
	msgbox Route117_Text_IsaacPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Lydia::
	trainerbattle_single TRAINER_LYDIA_1, Route117_Text_LydiaIntro, Route117_Text_LydiaDefeat, Route117_EventScript_RegisterLydia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchLydia
	msgbox Route117_Text_LydiaPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_RegisterLydia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route117_Text_LydiaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LYDIA_1
	release
	end

Route117_EventScript_RematchLydia::
	trainerbattle_rematch TRAINER_LYDIA_1, Route117_Text_LydiaRematchIntro, Route117_Text_LydiaRematchDefeat
	msgbox Route117_Text_LydiaPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Dylan::
	trainerbattle_single TRAINER_DYLAN_1, Route117_Text_DylanIntro, Route117_Text_DylanDefeat, Route117_EventScript_RegisterDylan
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchDylan
	msgbox Route117_Text_DylanPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_RegisterDylan::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route117_Text_DylanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_DYLAN_1
	release
	end

Route117_EventScript_RematchDylan::
	trainerbattle_rematch TRAINER_DYLAN_1, Route117_Text_DylanRematchIntro, Route117_Text_DylanRematchDefeat
	msgbox Route117_Text_DylanPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Maria::
	trainerbattle_single TRAINER_MARIA_1, Route117_Text_MariaIntro, Route117_Text_MariaDefeat, Route117_EventScript_RegisterMaria
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchMaria
	msgbox Route117_Text_MariaPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_RegisterMaria::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route117_Text_MariaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_MARIA_1
	release
	end

Route117_EventScript_RematchMaria::
	trainerbattle_rematch TRAINER_MARIA_1, Route117_Text_MariaRematchIntro, Route117_Text_MariaRematchDefeat
	msgbox Route117_Text_MariaPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Derek::
	trainerbattle_single TRAINER_DEREK, Route117_Text_DerekIntro, Route117_Text_DerekDefeat
	msgbox Route117_Text_DerekPostBattle, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Anna::
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route117_Text_AnnaIntro, Route117_Text_AnnaDefeat, Route117_Text_AnnaNotEnoughMons, Route117_EventScript_RegisterAnna
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchAnna
	msgbox Route117_Text_AnnaPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_RegisterAnna::
	msgbox Route117_Text_AnnaAndMegRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANNA_AND_MEG_1
	release
	end

Route117_EventScript_RematchAnna::
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_AnnaRematchIntro, Route117_Text_AnnaRematchDefeat, Route117_Text_AnnaRematchNotEnoughMons
	msgbox Route117_Text_AnnaPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Meg::
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route117_Text_MegIntro, Route117_Text_MegDefeat, Route117_Text_MegNotEnoughMons, Route117_EventScript_RegisterMeg
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route117_EventScript_RematchMeg
	msgbox Route117_Text_MegPostBattle, MSGBOX_DEFAULT
	release
	end

Route117_EventScript_RegisterMeg::
	msgbox Route117_Text_AnnaAndMegRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANNA_AND_MEG_1
	release
	end

Route117_EventScript_RematchMeg::
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_MegRematchIntro, Route117_Text_MegRematchDefeat, Route117_Text_MegRematchNotEnoughMons
	msgbox Route117_Text_MegPostRematch, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Melina::
	trainerbattle_single TRAINER_MELINA, Route117_Text_MelinaIntro, Route117_Text_MelinaDefeat
	msgbox Route117_Text_MelinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Brandi::
	trainerbattle_single TRAINER_BRANDI, Route117_Text_BrandiIntro, Route117_Text_BrandiDefeat
	msgbox Route117_Text_BrandiPostBattle, MSGBOX_AUTOCLOSE
	end

Route117_EventScript_Aisha::
	trainerbattle_single TRAINER_AISHA, Route117_Text_AishaIntro, Route117_Text_AishaDefeat
	msgbox Route117_Text_AishaPostBattle, MSGBOX_AUTOCLOSE
	end

Route117_Text_DayCarePokemonHadNewMove:
	.string "Ich habe mein Pokémon in der PENSION\n"
	.string "abgegeben.\p"
	.string "Als ich es wieder abholte, kannte es\n"
	.string "eine Attacke, die ich ihm nicht beige-\l"
	.string "bracht habe. Ich war total überrascht.$"

Route117_Text_ArentTheseFlowersPretty:
	.string "Was meinst du?\n"
	.string "Sind diese Blumen nicht wunderhübsch?\p"
	.string "Ich habe sie alle selber gepflanzt.$"

Route117_Text_AirIsTastyHere:
	.string "Die Luft hier ist wunderbar frisch.$"

Route117_Text_RouteSignVerdanturf:
	.string "ROUTE 117\n"
	.string "{LEFT_ARROW} WIESENFLUR$"

Route117_Text_RouteSignMauville:
	.string "ROUTE 117\n"
	.string "{RIGHT_ARROW} MALVENFROH CITY$"

Route117_Text_DayCareSign:
	.string "Pokémon Pension\n"
	.string "“Lass uns deine Pokémon aufziehen.”$"

Route117_EventScript_Chelast::
	msgbox Route117_Text_Chelast, MSGBOX_NPC
	end

Route117_Text_Chelast:
	.string "Tipp:\p"
	.string "Auf dieser Route versteckt sich ein\n"
	.string "Starter aus der 4 Generation mit\l"
	.string "einer Spawnrate von 1%!\p"
	.string "Welches es ist, musst du selbst\n"
	.string "herausfinden :D !$"

@ ========== POKEMON IM GARTEN ==========

Route117_EventScript_Kecleon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_NORMAL
	msgbox Route117_Text_Kecleon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route117_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox Route117_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route117_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox Route117_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

@ ========== TEXTE PKMN ==========

Route117_Text_Kecleon:
	.string "Kecleon: Kecleeeon!$"

Route117_Text_Azumarill:
	.string "Azumarill: Azuuu!$"

Route117_Text_Pikachu:
	.string "Pikachu: Pika Pika!$"

