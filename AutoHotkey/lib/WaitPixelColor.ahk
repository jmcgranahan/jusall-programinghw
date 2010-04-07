;========================================================================
; 
; Function:     WaitPixelColor
; Description:  Waits until pixel is a certain color (w/ optional timeout)
; Online Ref.:  http://www.autohotkey.com/forum/topic43807.html
;
; Last Update:  19/July/2009 04:30
;
; Created by:   MasterFocus
;               http://www.autohotkey.net/~MasterFocus/AHK/
;
;========================================================================
;
; DesiredColor, PosX, PosY [, TimeOut, GetMode, ReturnMode]
;
; + Required parameters:
; - DesiredColor      The color you are waiting for
; - PosX, PosY        Pixel coordinates
;
; + Optional parameters:
; - TimeOut           Timeout in milliseconds
; - GetMode           Mode(s) for the PixelGetColor function
; - ReturnMode        0 or 1 (see list of return values below)
;
; + Return values when ReturnMode is 0:
; - 0      The desired color was found
; - 1      There was a problem during PixelGetColor
; - 2      The function timed out
;
; + Return values when ReturnMode is 1:
; - Blank         There was a problem during PixelGetColor
; - Non-Blank     Will be the latest found color, even if not the desired one
;
;========================================================================

WaitPixelColor(DesiredColor,PosX,PosY,TimeOut=0,GetMode="",ReturnMode=0)
{
    Start := A_TickCount
    Loop
    {
        PixelGetColor, RetrievedColor, %PosX%, %PosY%, %GetMode%
        if ErrorLevel
        {
            if !ReturnMode
                return 1
            break
        }
        if ( RetrievedColor = DesiredColor )
        {
            if !ReturnMode
                return 0
            break
        }
        if ( TimeOut ) AND ( A_TickCount - Start >= TimeOut )
        {
            if !ReturnMode
                return 2
            break
        }
    }
    return RetrievedColor
}