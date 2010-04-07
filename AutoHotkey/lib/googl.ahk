;
; AutoHotkey Version: 1.x
; Language:       English
; Platform:       Win9x/NT
; Author:         A.N.Other <myemail@nowhere.com>
;
; Script Function:
;	Template script (you can customize this template by editing "ShellNew\Template.ahk" in your Windows folder)
;

googl(sUrl){
	Regex := RegExMatch(sUrl,"http")
	sPattern := ""
	if(Regex == 1){
		Url := "http://ggl-shortener.appspot.com/?url=" . sUrl
		sData := ""
		httpQuery(sData,Url)
		VarSetCapacity(sData,-1)
		RegExMatch(sData,"http(.*)\w", sPattern)
		}
	else {
		msgbox Passed text was not a url
	}
	return sPattern
		
}