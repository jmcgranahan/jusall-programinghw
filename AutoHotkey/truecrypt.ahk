; Author:         gowness <biga05@gmail.com>
;
; Script Function:
;	
;

#NoEnv  ; Recommended for performance and compatibility with future AutoHotkey releases.
SendMode Input  ; Recommended for new scripts due to its superior speed and reliability.
#NoTrayIcon
#SingleInstance force

::/truecrypt::
Process, Exist, truecrypt.exe
NewPid=%ErrorLevel%
if NewPID = 0 
{
run C:\Program Files (x86)\TrueCrypt\TrueCrypt.exe /a /v D:\Documents\rofl\rofl.dat
}
return