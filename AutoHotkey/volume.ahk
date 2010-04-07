
;By Dominic Tay
;Master Mute
^#m::
Gui,Destroy
SoundSet, +1,, mute
SoundGet, Master_mute,, mute
if Master_mute = On
{
Gui, Color, 000080
Gui, font, s20 bold cYellow, Tahoma
Gui, Add, text,x0 y0, Mute On
DetectHiddenWindows on
WinWait, %A_ScriptName%  ; Set the "last found" window to GUI window.
WinSet, TransColor,000080 %transparent%
WinSet, AlwaysOnTop, On
Gui, -Caption
Gui, Show, w200 h50 x10 y705
setenv, presstime, %A_MDay%%A_hour%%A_Min%%A_Sec%
envadd, presstime, 2
SetTimer, RemoveGui, On
return
RemoveGui:
  setenv, presstime2, %A_MDay%%A_hour%%A_Min%%A_Sec%
  ifgreaterorequal, presstime2, %presstime%
  {
    Gui, Destroy
    SetTimer, RemoveGui, off
  }
return
}
else
{
Gui, Color, 000080
Gui, font, s20 bold cYellow, Tahoma
Gui, Add, text,x0 y0 vMyText, Mute Off
DetectHiddenWindows on
WinWait, %A_ScriptName%  ; Set the "last found" window to GUI window.
WinSet, TransColor,000080 %transparent%
WinSet, AlwaysOnTop, On
Gui, -Caption
Gui, Show, w200 h50 x10 y705
setenv, presstime, %A_MDay%%A_hour%%A_Min%%A_Sec%
envadd, presstime, 2
SetTimer, RemoveGui, On
return
}
return