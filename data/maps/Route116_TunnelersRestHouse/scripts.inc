Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "Der METAFLURTUNNEL…\p"
	.string "Am Anfang hatten wir 'ne ganze Truppe,\n"
	.string "die mit fetten Maschinen den Fels\n"
	.string "durchbohren wollte.\p"
	.string "Aber dann mussten wir alles stoppen…\p"
	.string "Es hieß, die wilden POKéMON in der\n"
	.string "Umgebung würden gestresst vom Krach.\p"
	.string "Jetzt hängen wir hier nur noch rum\n"
	.string "und zählen die Gesteinsbrocken.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Da draußen gibt’s so ’nen Typen,\n"
	.string "der buddelt sich allein durch zum Ziel.\p"
	.string "Ohne Werkzeug, nur mit den Händen…\n"
	.string "Weil er keinen Lärm machen will.\p"
	.string "Er sagt, das stört die POKéMON nicht\n"
	.string "und ihre Umgebung bleibt unberührt.$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Ohne Tunnel nach WIESENFLUR?\n"
	.string "Kein Spaß…\p"
	.string "Du müsstest erst rüber nach FAUSTAUHAVEN,\n"
	.string "dann mit’m Schiff nach GRAPHITPORT\n"
	.string "und von da weiter nach MALVENFROH…\p"
	.string "Ein echter Umweg also.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Hast du's schon gehört?!\n"
	.string "Der TUNNEL ist durchgebrochen!\p"
	.string "Wenn man hartnäckig bleibt,\n"
	.string "kann man sogar Berge versetzen.$"

