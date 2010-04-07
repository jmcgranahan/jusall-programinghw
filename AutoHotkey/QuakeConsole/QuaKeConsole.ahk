;Hide the script's tray icon
;#NoTrayIcon

;Use the same icon of console.exe for the script's tray icon (note that "#NoTrayIcon" hide the default one and any other icon, you must delete or coment "#NoTrayIcon" in order to show this icon in taskbar)
;Menu, Tray, Icon, %A_ScriptFullPath%\console.exe, 1

; Launch console if necessary; hide/show on Win+`
;You can coustomise this by yourself #=Win, !=Alt, ^=Ctrl, +=Shift, see (http://www.autohotkey.com/docs/Hotkey.htm - http://www.autohotkey.com/docs/KeyList.htm )
#`::
DetectHiddenWindows, on

IfWinExist ahk_class Console_2_Main
{
	IfWinActive ahk_class Console_2_Main
		{
			WinHide ahk_class Console_2_Main
			WinActivate ahk_class Shell_TrayWnd
		}
	else
		{
			WinShow ahk_class Console_2_Main
			WinActivate ahk_class Console_2_Main
		}
}
else
		
		; QuakeConsole.ahk (or QuakeConsole.exe if you don't have autohotkey instaled in your system) must be in the same folder as console.exe
		; -c <xxxx.xml> settings file for console2, if empty then  use console.xml
		; -w title of console2 window
		; -t Specifies a startup tab ;  tab must be defined in Console settings. There are 4 definied tabs in QuakeConsole.xml : cmd=cmd.exe(Ctrl+F1), ps=powershell.exe(Ctrl+F2), bash="x:\Cygwin\Cygwin.bat"(Ctrl+F3), telnet=telnet.exe(Ctrl+F4)
		; -d Specifies a startup directory
		
	Run %A_ScriptDir%\QuakeConsole\console -c QuakeConsole.xml -w QuakeConsole -t cmd -d %HOMEPATH%

DetectHiddenWindows, off
return

;hide console on "esc".
#IfWinActive ahk_class Console_2_Main
esc::
	{
		WinHide ahk_class Console_2_Main
		WinActivate ahk_class Shell_TrayWnd
	}
return
