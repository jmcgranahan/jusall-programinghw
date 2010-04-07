#Persistent

   Hotkey, RButton, RightClick

   Menu, Tray, Click, 1
   Menu, Tray, NoStandard
   Menu, Tray, Add, Single Click,    SingleClick
   Menu, Tray, Add, Double Click, DoubleClick
   Menu, Tray, Default, Double Click
   Menu, Tray, Add, Exit
   Return

DoubleClick:
   If RClicked <> Yes
      {
         If Clicks =
            {
               SetTimer, SingleClick, 500
               Clicks = 1
               Return
            }
      }
   SetTimer, SingleClick, Off
   MsgBox, 0, Message, Double Click Detected!
   Clicks =
   RClicked =
   Return

SingleClick:   
   SetTimer, SingleClick, Off
   MsgBox, 0, Message, Single Click Detected!
   Clicks =
   RClicked =
   Return
   
RightClick:
   RClicked = Yes
   GetKeyState, state, RButton, P
   If state = D
      {
         Send, {RButton down}
         KeyWait, RButton
         Send, {RButton up}
      }
   Else
      {
         Send, {RButton}
      }
   RClicked =
   Return
   
Exit:
   ExitApp