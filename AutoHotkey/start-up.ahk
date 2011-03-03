; AutoHotkey Version: 1.x
; Author:        gowness <biga05@gmail.com>
;
; Script Function: 
;

Hotkey, IfWinActive, ahk_class LIONHEAD
Hotkey, XButton1, BWmouse4hack
Hotkey, IfWinActive, ahk_class Chrome_WidgetWin_0
Hotkey, XButton1, Chromem4chack
Hotkey, IfWinActive 
~Lbutton::

Hotkey, IfWinActive, Left 4 Dead 2
Hotkey, !f, ChangeFireMode
Hotkey, *LButton, mousedown
Hotkey, LButton, mousedown
Hotkey, IfWinActive
autoclick := false
Loop,12
{
	n := A_Index
	Hotkey, ^!+F%n%, G
}

Hotkey, ^!+insert, G
Hotkey, ^!+home, G
Hotkey, ^!+pgup, G
Hotkey, ^!+del, G
Hotkey, ^!+end, G
Hotkey, ^!+pgdn, G
settimer DebugMessages, 100
SetTimer WindowCheck, 250
setTimer timer, 10

return
