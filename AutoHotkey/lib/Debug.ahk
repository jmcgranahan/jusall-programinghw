; Author:         gowness <biga05@gmail.com>
; Version:		1.0.2.1
;
; Script Function: Debug messages
; 	
; REQ: Simple Array (http://www.autohotkey.com/forum/topic35041.html) 
; REQ: modified Osd Me (http://www.autohotkey.net/~gowness/lib/OSD.ahk)
; REQ: GDI+ (http://www.autohotkey.com/forum/viewtopic.php?t=32238)

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
	
	If !pToken := Gdip_Startup()
		{
			MsgBox, 48, gdiplus error!, Gdiplus failed to start. Please ensure you have gdiplus on your system
			ExitApp
		}
		
		Width := A_ScreenWidth-150, Height := A_ScreenHeight
		Gui, 1: -Caption +E0x80000 +LastFound +OwnDialogs +Owner +AlwaysOnTop
		Gui, 1: Show, NA
		hwnd1 := WinExist()
		
		hbm := CreateDIBSection(Width, Height)
		hdc := CreateCompatibleDC()
		obm := SelectObject(hdc, hbm)
		G := Gdip_GraphicsFromHDC(hdc)
		Gdip_SetSmoothingMode(G, 4)
	
	pBrush := Gdip_BrushCreateSolid(0x88000000)
	


	loop 10 {
		line := SA_Get(SA_Get(DebugArray, A_INDEX+1),1)
		linelv:= SA_Get(SA_Get(DebugArray, A_INDEX+1),2)
		
		if A_INDEX+1>SA_Len(DebugArray)
			Osd_Off(A_INDEX)
		else if linelv = low
		{
			Osd("", line ,"","MS Sans Serif","FS20 X0 Y" . ((A_INDEX-1)*25)-9 . " CT00FF00 CWBlack C0 WS500" ,A_INDEX)
			Gdip_FillRectangle(G, pBrush, -1, ((A_INDEX-1)*25)-1, Width+1, 25)
			}
		else if linelv = medium
		{
			Osd("", line ,"","MS Sans Serif","FS20 X0 Y" . ((A_INDEX-1)*25)-9 . " CTFFFF00 CWBlack C0 WS500" ,A_INDEX)
			Gdip_FillRectangle(G, pBrush, -1, ((A_INDEX-1)*25)-1, Width+1, 25)
			}
		else if linelv = high
		{
			Osd("", line ,"","MS Sans Serif","FS20 X0 Y" . ((A_INDEX-1)*25)-9 . " CTFF0000 CWBlack C0 WS500" ,A_INDEX)
			Gdip_FillRectangle(G, pBrush, -1, ((A_INDEX-1)*25)-1, Width+1, 25)
			}
		
	}
	Gdip_DeleteBrush(pBrush)
	
	UpdateLayeredWindow(hwnd1, hdc, 0, 0, Width, Height)	
	SelectObject(hdc, obm)
	DeleteObject(hbm)
	DeleteDC(hdc)
	Gdip_DeleteGraphics(G)


	 
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
	Gdip_Shutdown(pToken)
	SetTimer, DebugRemoveTimer, off
	DebugArray := SA_Del(DebugArray,1)
	
	
	
	if SA_Len(DebugArray) < 2
	{
		Loop 9 { 
			OSD_Off(A_INDEX)
		}
		
		DebugTimer := false
		gui, 1: destroy
		;Debug_Display()
		
	}
	Else
	{
		SetTimer, DebugRemoveTimer, %DebugDelay%
		Debug_Display()
	}

return
		
	