

SetBatchLines, -1
SetFormat, float, 5.1

Menu, Tray, Add, Exit
Menu, Tray, Tip, Free Space
Menu, Tray, Nostandard
Return

GuiEscape:
Default:
^!+s::
If Toggle
{
   Gui, Destroy
   Toggle--
}
Else
{
   Gosub, Get_List
   Gosub, Gui_Create
   Gui, Show, w178 h%Height%, Free Space
   WinSet, Region, % "0-8 3-6 9-6 9-1 64-1 64-6 176-6 178-8 178-"Height-4 " 175-"Height " 2-"Height " 0-"Height-4, Free Space
   Toggle++
}
Return

Get_List:
DrvNum = 0
DriveGet, FD_List, List, Fixed
Loop Parse, FD_List
{

   Spaces := "       "
   DriveGet, Cap_%A_LoopField%, Cap, %A_LoopField%:\
   DriveSpaceFree, Free_Space, %A_LoopField%:\    ;Get the free space in each drive
   Percent_Free :=  Free_Space / (Cap_%A_LoopField%) * 100
   If (Free_Space > 1000)
   {
      SetFormat, Float, 0.3
      Free_Space = %Free_Space%.0            ;Treat free space like a float
      Free_Space /= 1000
      Unit = Go
      StringTrimRight, Spaces, Spaces, % (Strlen(Free_Space) - 1)   ;Reduce the number of spaces
   }
   Else
   {
      StringTrimRight, Spaces, Spaces, %  (Strlen(Free_Space) - 1)
      Unit = Mo
   }
   SetFormat, float, 5.1
   Result := (Result . A_LoopField ":\" Spaces . Free_Space " " Unit " [" Percent_Free "%] `n") ;Create the list
   DrvNum++                        ;Count drives
}

StringTrimRight, Result, Result, 1    ;Delete the tailing linefeed char
Return

Gui_Create:
Height := 17+12*DrvNum          ;Height depends on how many drives are present
Gui, Margin, x0, y0
Gui, Add, GroupBox, x0 y0 w178 h%Height%, Free Space
Gui, -Caption +AlwaysOnTop +ToolWindow
Gui, Font, s8, Dina
Gui, Add, Text, xp+9 yp+13, %Result%
Result =             ;Frees the result list
Return

Exit:
ExitApp