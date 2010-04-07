
; AutoHotkey Version: 1.x
; Author:        gowness <biga05@gmail.com>
;
; Script Function: 
;

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

return
