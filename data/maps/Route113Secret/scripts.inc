Route113Secret_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route113Secret_OnResume
	.byte 0

Route113Secret_OnResume:
	setstepcallback STEP_CB_ASH
	end

