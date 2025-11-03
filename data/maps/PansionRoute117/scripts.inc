PansionRoute117_MapScripts::
	.byte 0

@ Fiffyen Event
PansionRoute117_EventScript_Poochyena::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POOCHYENA, CRY_MODE_NORMAL
	msgbox PansionRoute117_Text_Poochyena, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PansionRoute117_Text_Poochyena:
	.string "FIFFYEN wedelt fröhlich mit dem\n"
	.string "Schwanz!\p"
	.string "Wuff!$"

@ Kirlia Event
PansionRoute117_EventScript_Kirlia::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	msgbox PansionRoute117_Text_Kirlia, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PansionRoute117_Text_Kirlia:
	.string "KIRLIA dreht sich anmutig!\p"
	.string "Kiirr~$"
