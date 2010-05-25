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
return 

timer:
	if autoclick
	{
		click down
		Sleep, 1
		click up
	}
	
return

