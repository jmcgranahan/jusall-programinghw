#NoTrayIcon
#SingleInstance force
; Example: Simple input-box:

name = %1%
pass = %2%
profile = %3%

Process, Exist, openvpn-gui.exe
NewPid=%ErrorLevel%
if NewPID = 0 
{
run "C:\Program Files (x86)\OpenVPN\bin\openvpn-gui-1.0.3.exe" --connect %profile%
}



WinWait, OpenVPN - User Authentication, Username:
IfWinNotActive, OpenVPN - User Authentication, Username:, WinActivate, OpenVPN - User Authentication, Username:
WinWaitActive, OpenVPN - User Authentication, Username:
Send, %name%{tab}%pass%{ENTER}
IfWinExist, OpenVPN Connection (client)
{
WinClose, OpenVPN Connection (client)
}
ExitApp
