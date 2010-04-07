bnewMessage := false
loop
{
    ifWinExist, <(^.^)>
    {
        bnewMessage := true
        debug("You have a message", "medium")
        sleep 3500
    }
    if(bnewMessage)
    {
        debug("You have a message", "medium")
        sleep 3500
    }
    ifWinActive,,Pidgin
        bnewMessage := false

}

