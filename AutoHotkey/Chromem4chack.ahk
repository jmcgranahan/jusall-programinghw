; AutoHotkey Version: 1.x
; Author:        gowness <biga05@gmail.com>
;
; Script Function:
;

Chromem4chack:
	send {ctrl down}
	keywait, XButton1
	send {ctrl up}
	if ( A_ThisHotkey = "XButton1" )
		send {XButton1}
return 