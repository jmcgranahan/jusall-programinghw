; AutoHotkey Version: 1.x
; Author:        gowness <biga05@gmail.com>
;
; Script Function: 
;

DebugMessages:
	pidgincheck()
return

WindowCheck:
	WinGetActiveTitle, Title
	if((Title = "Left 4 Dead 2")||(Title = "Left4Dead"))
	{
		L4DActive := true
	}
	else
	{
		L4DActive := false
	}
	Splashup(L4DActive)
	
	ifWinExist, User Account Control
	{
		winActivate
		send {alt down}y{alt up}
	}
return 

