; AutoHotkey Version: 1.x
; Author:        gowness <biga05@gmail.com>
;
; Script Function: notify me of new message via debug interface
;

pidgincheck()
{
	static bnewMessage := false
	
    if WinExist("<(^.^)>")
    {
        bnewMessage := true
        debug("You have a message", "medium")
		sleep 3000
    }
    else if(bnewMessage)
    {
        debug("You have a message", "medium")
		sleep 3000
    }
	
    ifWinActive,,Pidgin
        bnewMessage := false
	return
}
