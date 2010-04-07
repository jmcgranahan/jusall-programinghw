Gui, Font, s15
Gui, Add, Text,, % "This GUI should show a progress bar on its taskbar button.`n"
                 . "It will demonstrate the four different progress states:`n"
                 . "(N)ormal, (P)aused, (E)rror and (I)ndeterminate."
Gui, Show        ; Show the window and taskbar button.
Gui, +LastFound  ; SetTaskbarProgress will use this window.
Loop
{
    progress_states=NPE
    Loop, Parse, progress_states
    {
        SetTaskbarProgress(0, A_LoopField)
        Loop 50 {
            SetTaskbarProgress(A_Index*2)
            Sleep 50
        }
        Sleep 1000
        Loop 50 {
            SetTaskbarProgress(100-A_Index*2)
            Sleep 50
        }
        SetTaskbarProgress(0)
        Sleep 1000
    }
    SetTaskbarProgress("I")
    Sleep 4000
}
GuiClose:
GuiEscape:
ExitApp