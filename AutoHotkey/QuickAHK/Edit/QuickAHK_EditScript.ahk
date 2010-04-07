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