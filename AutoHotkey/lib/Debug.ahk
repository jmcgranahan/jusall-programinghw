; Author:         gowness <biga05@gmail.com>
; Version:		1.0.1
;
; Script Function: Debug messages
; 	
; REQ: Simple Array (http://www.autohotkey.com/forum/topic35041.html) 
; REQ: modified Osd Me (http://www.autohotkey.net/~gowness/lib/OSD.ahk)

Debug(message="",level="low")
{
	global DebugArray
	global DebugTimer
	global DebugDelay = 3000
	
	if DebugTimer = 
		DebugTimer := false
		
	if(message != "")
	{
		if(DebugArray="")
			DebugArray := SA_Set(DebugArray, SA_Set(SA_Set("", "void"), "void"))
	
		DebugArray := SA_Set(DebugArray,SA_Set(SA_Set("", message), level))
		
		if(SA_Len(DebugArray) > 11)
			DebugArray := SA_Del(DebugArray,1)
	}
	Debug_Display()
	
	if(!DebugTimer)
	{
		DebugTimer := true
		SetTimer, DebugRemoveTimer, %DebugDelay%
	}
	
}

Debug_Display()
{
	global DebugArray

	loop 10 {
		line := SA_Get(SA_Get(DebugArray, A_INDEX+1),1)
		linelv:= SA_Get(SA_Get(DebugArray, A_INDEX+1),2)
		
		if A_INDEX+1>SA_Len(DebugArray)
			Osd_Off(A_INDEX)
		else if linelv = low
			Osd("", line ,"","MS Sans Serif","FM15 FS15 X0 Y" . ((A_INDEX-1)*20)+20 . " CT00DD00 C0" ,A_INDEX)
		else if linelv = medium
			Osd("", line ,"","MS Sans Serif","FM15 FS15 X0 Y" . ((A_INDEX-1)*20)+20 . " CTDDDD00 C0" ,A_INDEX)
		else if linelv = high
			Osd("", line ,"","MS Sans Serif","FM15 FS15 X0 Y" . ((A_INDEX-1)*20)+20 . " CTDD0000 C0" ,A_INDEX)
		}
 
}

Debug_Clear()
{
	global DebugArray
	global DebugTimer
	DebugTimer := false
	
	DebugArray := SA_Set("", SA_Set(SA_Set("", "void"), "void"))
	Debug_Display()
}


DebugRemoveTimer:
	SetTimer, DebugRemoveTimer, off
	DebugArray := SA_Del(DebugArray,1)
	
	if SA_Len(DebugArray) < 2
	{
		Loop 9 {
			OSD_Off(A_INDEX)
		}
		DebugTimer := false
	}
	Else
	{
		SetTimer, DebugRemoveTimer, %DebugDelay%
		Debug_Display()
	}
	
return
		
	