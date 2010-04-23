;Setup
SetTitleMatchMode, 2
SetWinDelay -1

sethigh = 50
setsite = www.google.com
xlocation = 400

;ping setup
TempDir = %A_Temp%
TrcR = 20  ; German language = 23
If A_OSVersion = WIN_2000  ; Win 95/98/2000 do not have tracert switches
   TrcV =
Else
   TrcV = -h 1

;gui
Gui, 1:-Caption +ToolWindow +LastFound +AlwaysOnTop +Border
Gui, 1:Color, F6FF00
gui, 1:add, text, w100 x3 y3 h13 vhighpingtext,
;start
SetTimer, getip, 2000
Return


getip:
    RunWait, cmd /C ping %setsite% -n 1 >"%TempDir%\IPHost.txt",,Hide
    FileReadLine, FRead, %TempDir%\IPHost.txt, 3
    ;run, %TempDir%\IPHost.txt ;open file
    StringGetPos, FReadL, FRead, =, R2
    StringGetPos, FReadR, FRead, ms
   
    FReadR := FReadR - FReadL - 1
    FReadL := FReadL + 2
    StringMid, FRead, FRead, %FReadL%, %FReadR%
   
    stringleft, isours, FRead, 10
   
    IP1 = %FRead%
   GuiControl,,highpingtext, High Ping! (%IP1%)
   
    if (IP1 >sethigh)
        gui, 1:show, NoActivate w100 x%xlocation% y0, Pinger
    Else
        gui, 1:hide
Return