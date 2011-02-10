#Persistent
#SingleInstance force
#NoTrayIcon

;BlockInput, MouseMove
Gui, -Caption +ToolWindow +AlwaysOnTop
Gui, Color, 000000, 0
Gui, -Caption +ToolWindow +E0x20
Gui, Show, X0 Y0 W%A_ScreenWidth% H%A_ScreenHeight% 
sleep 1000
Gui 2: -Caption +ToolWindow +AlwaysOnTop
Gui 2: Color, 000000, 0
Gui 2: Font, S13 c0, ariel
Gui 2: Add, Button, h20 w250 x100 y100,(End + Delete keys to exit)
Gui 2: Show
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