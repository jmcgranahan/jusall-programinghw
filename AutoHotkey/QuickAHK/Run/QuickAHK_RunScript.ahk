loop
{
    if WinExist("<(^.^)>")
    {
        bnewMessage := true
        debug("You have a message", "medium")
        sleep 3500
    }
    else if(bnewMessage)
    {
        debug("You have a message", "medium")
        sleep 3500
    }
	
    ifWinActive,,Pidgin
        bnewMessage := false

}
;-- Begin debug script ---
ExitApp  ;-- Useful for "Run Selected" command

;-- A few example hotkeys.  Change to fit your needs
#!h::ListHotkeys
#!k::KeyHistory
#!l::ListLines
#!p::Pause    ;-- Toggle
#!q::ExitApp
#!s::Suspend  ;-- Toggle
#!v::ListVars