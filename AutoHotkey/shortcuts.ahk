

:*:/ahkfolder::
run explorer C:\Users\gowness\Documents\AutoHotkey\
return

:*:/ip:: 
SendInput %A_IPAddress1%
return
:*:/gmail::biga05@gmail.com

:*:/typecb::
cb := clipboard
SendInput %cb%
return

^!k:: kill()

:*:/public-vpn::
run vpn.exe gowness passes client.ovpn
return 

:*:/public-secure-vpn::
run vpn.exe gowness passes stealthy.ovpn
return

:*:/home-vpn::
run vpn.exe gowness	passes acewizard.ovpn
return

^!g::
keywait Alt
keywait ctrl
clipboard = 
WinGet, Win, PID, A
SetTitleMatchMode, 2
IfWinExist, Google Chrome 
{
    WinActivate  
    Send, {F6}
	Send, {ctrl down}c{ctrl up} 
	ClipWait 
	sUrl := clipboard
	clipboard := googl(sUrl)
	ClipWait
	IfWinExist, ahk_pid %Win%
	{
		WinActivate
		sendinput %clipboard%
		return
	}
	return
}
return



#c::
run C:\Windows\System32\control.exe
return

*CapsLock::
SetKeyDelay -1
Send {alt downtemp}{pgup downtemp}
ifwinexist, TeamSpeak
	Osd("", "Voice Active" ,"","MS Sans Serif","FM15 FS30 X0 Y100 CTDD4400 C0" ,9)
return

*CapsLock up::
SetKeyDelay -1
Send {alt up}{pgup up}
Osd_Off(9)
return

*!F::
if(active)
	ChangeFireMode()
else
	send {alt down}{f down}
return

*!F up::
if(!active)
	send {alt up}{f up}
return
*LButton::mousedown()

+z::   Win__Fling(1, "A")

