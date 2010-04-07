; Author:         gowness <biga05@gmail.com>
;
; Script Function: open mixer when doubletap mute
;	
;


~Volume_Mute::
SendInput {Volume_Mute}
presses++
SetTimer CheckTaps, 200
return

CheckTaps:
if(presses>1){
	run C:\Windows\System32\SndVol.exe
}
else {
	SendInput {Volume_Mute}
}
presses := 0
SetTimer CheckTaps, off
return 