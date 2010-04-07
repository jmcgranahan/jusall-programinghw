; Author:         gowness <biga05@gmail.com>
;
; Script Function:
;	basic time output
;


::/time::
CurrentTime := time_short()
SendInput %CurrentTime%
return

::/timel::
CurrentTime := time_24_long()
SendInput %CurrentTime%
return

::/date::
CurrentDate := time_date_short()
SendInput %CurrentDate%
return


