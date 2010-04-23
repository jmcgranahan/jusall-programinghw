debug("Starting gowness's autohotkey script of doom...")
;#Persistent
; Author:  gowness <biga05@gmail.com>
;
; Script Function: defualt script
SysGet, Mon1, Monitor, 1 
SysGet, Mon2, Monitor, 2

#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
#SingleInstance force
SendMode Input ; Recommended for new scripts due to its superior speed and reliability.
SetWorkingDir %A_ScriptDir%  ; Ensures a consistent starting directory.

#include start-up.ahk
;----------------includes/functions------------------
#include G11shortcuts.ahk
#include BWmouse4hack.ahk
#include Chromem4chack.ahk
#include Actions.ahk
#include l4d.ahk
;----------------includes/binds----------------------
#include AutoCorrect.ahk
#include drivespace.ahk
#include math.ahk
#include shortcuts.ahk
#include time&date.ahk
#include truecrypt.ahk
#include volmenu.ahk



EmptyMem()
^!r:: 
debug("reloading main file, please wait...","high")
sleep 500
reload 
return


