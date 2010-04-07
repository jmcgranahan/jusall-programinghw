#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
#Persistent
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
OnExit, Cleanup

state = on
SetTimer, Check, On
SetTimer, Check, 10
return

Cleanup:
 If (state = "off")
  Control, Show,, SysListView321, ahk_class Progman
 ExitApp
return

Check:
 MouseGetPos, mx, my, win_under_mouse,
 WinGetClass, class_under_mouse, ahk_id %win_under_mouse%
 WinGetClass, class, A
 If (class = "Progman" OR not class OR class_under_mouse = "Progman" or class_under_mouse = "Shell_TrayWnd")
  {
   If (state = "off")
    {
     Control, Show,, SysListView321, ahk_class Progman
     state = on
    }
  }
 Else
  {
   If (state = "on")
    {
     Control, Hide,, SysListView321, ahk_class Progman
     state = off
    }
  }
return