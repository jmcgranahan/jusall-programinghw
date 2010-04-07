; DesktopSwitch
;
; AutoHotkey Version: 1.0.40.00 (that's at least the version I'm using)
; Language:       English
; Platform:       Win9x/NT/XP
; Author:         Christian Schüler <c_schueler@gmx.at>
; last changes:   25. jun. 2009
;
; Script Function:
;
; A small tool for switching between multiple virtual desktops.
; Use Alt-F<desktop index> (e.g. Alt-F2) to switch between desktops and
; Quit the script and all windows on all virtual desktops will be soon
; Currently, 4 desktops are supported, because more will start to confuse me...
;
; Version history:
;
; v1.14, 25 jun 2009 Emiel Witteman
; Fixed bug window disappearing when sending it to the current desktop

; v1.13, 08 sept 2008 Emiel Witteman
; Fixed bugs in array housekeeping, explained the faulty hide/show of some windows
;
; v1.12, 08 sept 2008 Emiel Witteman
; Code cleanup, removed some redundant code from previous versions.
; Added support for MultiMonTaskbar (a taskbar on a second physical screen)
; Added storing of active window per virtual desktop
; Added Traytips to inform the user what happened
;
; v1.11, 22. Nov. 2005
; Fixed bug: windows are now corrrectly activated after switching/sending
;
; v1.1, 05. Nov. 2005
; Added feature: pressing Ctrl/Alt-<index> sends the active window to the desktop <index>.
;
; v1.0, 04. Nov. 2005
; It works!
; Switching can be done using Alt-<desktop index>, e.g. Alt-1. Pressing
; Alt-0 will exit the script and show all windows from all virtual desktops
; at once.

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Auto timers, usefull when debugging  ;
; turn off or set high to save cpu     ;
; when debug is done                   ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
SetTimer,AutoReloadScript,1000 

; ***** initialization *****
#WinActivateForce
SetBatchLines, -1   ; maximize script speed!
SetWinDelay, -1
OnExit, CleanUp     ; clean up in case of error (otherwise some windows will get lost)

numDesktops := 4    ; maximum number of desktops
curDesktop := 1     ; index number of current desktop

; ***** hotkeys *****
!1::SwitchToDesktop(1)
!2::SwitchToDesktop(2)
!3::SwitchToDesktop(3)
!4::SwitchToDesktop(4)

^!1::SendActiveToDesktop(1)
^!2::SendActiveToDesktop(2)
^!3::SendActiveToDesktop(3)
^!4::SendActiveToDesktop(4)

;!0::ExitApp

;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; AutoScriptReload/Suspend ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;
AutoReloadScript:
   FileGetAttrib,attribs,%A_ScriptFullPath%
   IfInString,attribs,A
   {
      FileSetAttrib,-A,%A_ScriptFullPath%
      TrayTip, %A_ScriptName%, updated AutoHotkey script
      SetTimer, AutoReloadScriptTrayTip, 2000 
   }
return 
AutoReloadScriptTrayTip:
    SetTimer, AutoReloadScriptTrayTip, Off
    TrayTip
    Reload
return


; ***** functions *****

; switch to the desktop with the given index number
SwitchToDesktop(newDesktop)
{
   global

   if (curDesktop <> newDesktop)
   {
      GetCurrentWindows(curDesktop)
      ShowHideWindows(curDesktop, false)
      ShowHideWindows(newDesktop, true)
      activate_window := % active_id%newDesktop%
      WinActivate, ahk_id %activate_window%
      TrayTip, DesktopSwitch, Switching to desktop %newDesktop%
      curDesktop := newDesktop
   }
   return
}

; sends the given window from the current desktop to the given desktop
SendToDesktop(windowID, newDesktop)
{
   global
   if (curDesktop <> newDesktop)
   {
   RemoveWindowID(curDesktop, windowID)

   ; add window to destination desktop
   windows%newDesktop% += 1
   i := windows%newDesktop%

   windows%newDesktop%%i% := windowID
   
   WinHide, ahk_id %windowID%
   TrayTip, DesktopSwitch, Window send to desktop %newDesktop%

   Send, {ALT DOWN}{TAB}{ALT UP}   ; activate the right window
   }
}

; sends the currently active window to the given desktop
SendActiveToDesktop(newDesktop)
{
   WinGet, id, ID, A
   SendToDesktop(id, newDesktop)
}

; removes the given window id from the desktop <desktopIdx>
RemoveWindowID(desktopIdx, ID)
{
   global   
   Loop, % windows%desktopIdx%
   {
      if (windows%desktopIdx%%A_Index% = ID)
      {
         windows%desktopIdx%%A_Index%=      ;Emiel: just empty the array element, array will be emptied by next switch anyway
         Break
      }
   }
}

; this builds a list of all currently visible windows in stores it in desktop <index>
GetCurrentWindows(index)
{
   global
   WinGet, active_id%index%, ID, A                      ; get the current active window
   emptyString =
   StringSplit, windows%index%, emptyString             ; Emiel: delete the entire windows_index_ array 
   WinGet, windows%index%, List,,, Program Manager      ; get list of all visible windows

   ; remove windows which we want to see on all virtual desktops
   Loop, % windows%index%
   {
      id := % windows%index%%A_Index%
      WinGetClass, windowClass, ahk_id %id%
      if windowClass = Shell_TrayWnd     ; remove task bar window id
           windows%index%%A_Index%=      ; Emiel: just empty the array element, array will be emptied by next switch anyway
      if windowClass = #32770            ; Emiel: we also want multimontaskbar on all virtual desktops
           windows%index%%A_Index%=      ; Emiel: just empty the array element, array will be emptied by next switch anyway
      if windowClass = cygwin/x X rl-xosview-XOsview-0   ; Emiel: xosviews e.d.
           windows%index%%A_Index%=      
      if windowClass = cygwin/x X rl-xosview-XOsview-1   ; Emiel: xosviews e.d.
           windows%index%%A_Index%=      
      if windowClass = MozillaUIWindowClass              ; Mozilla thunderbird
      {
        WinGet, ExStyle, ExStyle, ahk_id %id%
          if (ExStyle & 0x8)  ; 0x8 is WS_EX_TOPMOST.    ; Alleen de mailboxalertmelding!
           windows%index%%A_Index%=      
      }
   }
}

; if show=true then shows windows of desktop %index%, otherwise hides them
ShowHideWindows(index, show)
{
   global

   Loop, % windows%index%
   {
      id := % windows%index%%A_Index%
      if show
         WinShow, ahk_id %id%
      else
         WinHide, ahk_id %id%
   }
}

; show all windows from all desktops on exit
CleanUp:
Loop, %numDesktops%
   ShowHideWindows(A_Index, true)
ExitApp 