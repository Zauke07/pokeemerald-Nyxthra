MauvilleCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MauvilleCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call Common_EventScript_UpdateBrineyLocation
	goto MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx::
	special SetMauvilleOldManObjEventGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_MAUVILLE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman1::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman2::
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings::
	.string "Der Typ da drüben labert nur Müll!\p"
	.string "Der ist auf eine ganz miese Art\n"
	.string "durchgeknallt. Den vergisst man so\l"
	.string "schnell nicht, leider!$"

MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner::
	.string "Ich war in der STATISTIK-ECKE und hab\n"
	.string "den neuesten Klatsch aus FAUSTAUHAVEN\l"
	.string "abgegriffen.\p"
	.string "Jetzt bin ich genauso schlau wie mein\n"
	.string "Kumpel - also immer noch ziemlich dumm!$"

MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun::
	.string "Oben im Center hat so ’ne STATISTIK-\n"
	.string "ECKE aufgemacht.\p"
	.string "Keine Ahnung, was man da soll, aber\n"
	.string "vielleicht kann man da ja jemanden\l"
	.string "abziehen. Ich geh mal gucken!$"

