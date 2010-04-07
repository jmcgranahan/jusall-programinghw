#Persistent
#SingleInstance force
#NoTrayIcon

BlockInput, MouseMove
Gui, -Caption +ToolWindow +AlwaysOnTop
Gui, Color, FFFFFF, 0
Gui, -Caption +ToolWindow +E0x20
Gui, Show, X0 Y0 W%A_ScreenWidth% H%A_ScreenHeight% 
sleep 1000
Gui 2: -Caption +ToolWindow +AlwaysOnTop
Gui 2: Color, ffffff, 0
Gui 2: Font, S13 c0, ariel
Gui 2: Add, Button, h200 w550 x100 y100, Turn screen brightness to maximum and leave on for 10 to 15 minutes.`nThis white screen is used to help eliminate burn ins to LCD screens.`n`nThe screen will automatically terminate after 15 minutes.`n(End + Delete keys to exit)
Gui 2: Show
sleep 20000
Gui 2: Destroy
DllCall("ShowCursor", "Int", 0)
SetTimer, Exit, 900000 ;Exit point set @ 15 minutes 
return


Exit:
DllCall("ShowCursor", "Int", 1)
Gui, Destroy
ExitApp
Return

End & Delete:: ;press 'End + Delete' keys together to terminate
DllCall("ShowCursor", "Int", 1)
Gui, Destroy
ExitApp
Return