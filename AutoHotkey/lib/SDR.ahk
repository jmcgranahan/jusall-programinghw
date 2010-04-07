/*
SaveDoesReload function

Put this function in your library and call in the auto-exec of your script like this:

SDR()

That's it. Done. Your scipt will reload when you press Ctrl+s 
or even the save button of your editor.


Advantages:
# Really easy to add to your script
# Doesn't create any global variables
# Doesn't mess up the auto-execute section by stopping it
# Automatically turns off the tooltip if there was a problem reloading


Recommended Personalizations:
# How often it checks if you save it without the hotkey
	(	SetTimer, SDR_CheckForChange, 1000	)
# Change the tooltip to a splash screen/traytip
# Change %A_ScriptName% to %A_ScriptFullPath% if you editor displays the full path in the title bar
# Change the hotkey label to SDR_CheckForChange to make sure it really saved and changed
# Change the tooltip number

*/


SDR()
{
	Static SDR_OldUT, SDR_InUse
	
	SetTitleMatchMode, 2
	GroupAdd, SDR_ReloadGroup, %A_ScriptName%
	GroupAdd, SDR_ReloadGroup, SDR.ahk ;reload all scripts with SDR if you modify this file
	
	Hotkey, IfWinActive, ahk_group SDR_ReloadGroup
	Hotkey, ~^s, SDR_Save
	Hotkey, IfWinActive ;reset the #ifwinactive

	FileGetTime, SDR_OldUT, %A_ScriptFullPath%, M ;Old Update time. M: Modification time
	SetTimer, SDR_CheckForChange, 1000
	
	
	SDR_CheckForChange:
	If SDR_InUse		;so it doesn't try to reload agian if it's already reloading
		return
	FileGetTime, SDR_NewUT, %A_ScriptFullPath%, M
	If (SDR_NewUT = SDR_OldUT) ;if it's different, continue thru to SDR_Save
		Return

	SDR_Save:
		SDR_InUse = 1		;so it doesn't try to reload agian if it's already reloading
	ToolTip, %A_ScriptName%   -   Updating in 3. ,
	Sleep, 250
	ToolTip, %A_ScriptName%   -   Updating in 2. . ,
	Sleep, 200
	ToolTip, %A_ScriptName%   -   Updating in 1. . . ,
	Sleep, 200
	SetTimer, SDR_Reset, -3000		;if it hasn't reloaded in 3 seconds, there must've been a problem
	ToolTip, Updating. . . . ,
	Reload
	return

	SDR_Reset:
	FileGetTime, SDR_OldUT, %A_ScriptFullPath%, M
	ToolTip %A_ScriptName%   -   There was a problem reloading.
	Sleep 500
	ToolTip
	SDR_InUse = 
	return
}