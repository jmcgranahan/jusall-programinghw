; AutoHotkey Version: 1.x
; Author:        gowness <biga05@gmail.com>
;
; Script Function: 
;



G:
keywait, Alt, L
keywait, ctrl, L
keywait, shift, L
RegExMatch(A_ThisHotkey,"[0-9](.*)",nFnum)
if(nFnum == "")
{
	RegExMatch(A_ThisHotkey,"[a-z](.*)",sFnum)
	if(sFnum == "insert")
		nFnum = 13
	else if(sFnum == "home")
		nFnum = 14
	else if(sFnum == "pgup")
		nFnum = 15
	else if(sFnum == "del")
		nFnum = 16
	else if(sFnum == "end")
		nFnum = 17
	else if(sFnum == "pgdn")
		nFnum = 18
}
	

goto, G%nFnum%
return

G1:
	Listhotkeys
return

G2:
	WinActivate ahk_class Shell_TrayWnd
	WinActivate ahk_class Battlefield: Bad Company 2
	#IfWinActive ahk_class Battlefield: Bad Company 2
	MouseClick, left,  765,  147
	Sleep, 500
	MouseClick, left,  766,  208
	Sleep, 500
	MouseClick, left,  1234,  469
	Sleep, 250
	MouseClick, left,  1233,  485
	Sleep, 250
	MouseClick, left,  1236,  513
	Sleep, 250
	MouseClick, left,  1244,  413
	Sleep, 250
	MouseClick, left,  1188,  474
	Sleep, 500
	MouseClick, left,  987,  765
	Sleep, 500
	MouseClick, left,  758,  536
	#IfWinActive
return

G3:
return

G4:
return

G5:
return

G6:
return

G7:
return

G8:
return

G9:
return

G10:
return

G11:
	autoclick := !autoclick
return

G12:
WinWait, AikaClient, 
IfWinNotActive, AikaClient, , WinActivate, AikaClient, 
WinWaitActive, AikaClient, 
Send, , 
MouseGetPos, xpos, ypos 
MouseClick, left,  373,  100
Sleep, 100
MouseClick, left,  533,  52
Sleep, 100
mousemove, xpos, ypos
return

G13:
return

G14:
return

G15:
	clipboard := ""
	send {ctrl down}{alt down}{shift down}c{ctrl up}{alt up}{shift up}
	ClipWait
	send %clipboard%
return

G16:
	send {ctrl down}{alt down}g {ctrl up}{alt up}
return

G17:
return

G18:
	send {home}{delete 22}D:\Program Files
return


