;*******************
;*                 *
;*    Osd On       *
;*                 *
;*******************
;
;   Description
;   ===========
;   This function generates a borderless text Splash window and is used in
;   conjunction with the SplashOff, PreserveSplashWindow, and SplashOff_Timer
;   functions/subroutines.
;
;
;
;   Parameters
;   ==========
;
;       Name                    Description
;       ----                    -----------
;       p_MainText              Main text. [Optional]  The default is null.
;
;       p_SubText               Sub text. [Optional]  The default is null.
;
;       p_Dummy                 Value ignored, just there to keep parameters
;                               identical to SplashOn
;
;       p_Font                  Font Name.  [Optional]  The default is null (the
;                               system default font is used).
;
;                               This font is used for both the MainText (top
;                               line(s)) and SubText (bottom line(s)).
;                               
;
;       p_Options               See the "Splash Options" section for more
;                               information.
;
;       p_Window                Window. Can be 0-9 (8 reserved for SplashMe)
;
;
;
;   Splash Options
;   ==============
;   The p_Options parameter is used to set any SplashImage options that are not
;   set by default.  If more than one option is defined, separate each option by
;   a space.  For example:
;
;       "CWBlack CTYellow"
;
;   For a complete list of SplashImage options, see the  AutoHotkey
;   documentation (keyword: SplashImage).
;
;
;   The following SplashImage options are automatically included by default:
;
;       Name                    Description
;       ----                    -----------
;       b2                      No title bar, dialog style border
;
;       W{Function determined}  Splash window width.  The size doesn't include
;                               border.
;
;
;   If not explicitly defined, the following SplashImage options/values are
;   included:
;
;       Name                    Description/Value
;       ----                    -----------------
;       FM10                    Font size for MainText - 10
;       FS12                    Font size for SubText - 12
;       WM600                   Font weight for MainText - 600 (Bold)
;       WS400                   Font weight for SubText - 400 (Normal)
;
;
;   In addition to the standard X/Y options, the following options are
;   available to position the Splash window on the screen:
;
;       Name                    Description/Value
;       ----                    -----------------
;       XL or XLeft             Left side of the screen.  Not necessarily the
;                               same as X0.
;
;       XM or XMiddle           Horizontally centered on the screen.  This is
;                               SplashImage default.
;
;       XR or XRight            Right side of the screen.
;
;       YT or YTop              Top of the screen.  Not necessarily the same as
;                               Y0.
;
;       YM or YMiddle           Vertically centered on the screen.  This is
;                               SplashImage default.
;
;       YB or YBottom           Bottom of the screen.
;
;
;   The preceding X/Y options are calculated based on the work area for the
;   primary monitor.  The work area excludes the taskbar and other registered
;   desktop toolbars.
;   
;
;
;   Calls To Other Functions
;   ========================
;   Osd_Off
;
;
;
;-------------------------------------------------------------------------------

Osd(p_MainText=""
        ,p_SubText=""
        ,p_Dummy=""
        ,p_Font=""
        ,p_Options=""
        ,p_Window=9)
    {
global

If (old_p_MainText%p_Window%=p_MainText
and old_p_Window%p_Window%=p_Window
and old_p_Font%p_Window%=p_Font
and old_p_Options%p_Window%=p_Options
and WinExist("OsdWindow" . p_Window)<>0)
{
;        SplashOn("",old_p_Window0 . ", " . old_p_Window1 . ", " . old_p_Window2 . ", " . old_p_Window3 . ", " . old_p_Window4 . ", " . old_p_Window5 . ", " . old_p_Window6 . ", " . old_p_Window7 . ", " . old_p_Window8 . ", " . old_p_Window9  ,-1,"","WS500 CWffff99")
        if (p_MainText = "")
            ControlSetText Static1,%p_SubText% ,OsdWindow%p_Window% 
        else
            ControlSetText Static2,%p_SubText% ,OsdWindow%p_Window%
;        old_p_SubText:=p_SubText
        return
}

old_p_MainText%p_Window%:=p_MainText
;old_p_SubText:=p_SubText
old_p_Window%p_Window%:=p_Window
old_p_Font%p_Window%:=p_Font
old_p_Options%p_Window%:=p_Options

    ;[==============]
    ;[  Initialize  ]
    ;[==============]
    local l_DetectHiddenWindows:=A_DetectHiddenWindows
    DetectHiddenWindows On

    local l_MainTextFontSize=10
    local l_MainTextFontWeight=600
    local l_SubTextFontSize=12
    local l_SubTextFontWeight=400


    ;[==============]
    ;[  Parameters  ]
    ;[==============]
    ;-- p_Window
    if p_Window is not Number
        p_Window=9


    ;-- p_Font
    p_Font=%p_Font%  ;-- AutoTrim


    ;[=======================]
    ;[  Extract font values  ]
    ;[  from p_Options       ]
    ;[=======================]
    loop parse,p_Options,%A_Space%
        {
        if A_LoopField is Space
            continue

        ;-- MainText options
        if instr(A_LoopField,"FM")=1
            if SubStr(A_LoopField,3) is Number
                StringTrimLeft l_MainTextFontSize,A_LoopField,2

        if instr(A_LoopField,"WM")=1
            if SubStr(A_LoopField,3) is Number
                StringTrimLeft l_MainTextFontWeight,A_LoopField,2


        ;-- SubText options
        if instr(A_LoopField,"FS")=1
            if SubStr(A_LoopField,3) is Number
                StringTrimLeft l_SubTextFontSize,A_LoopField,2

        if instr(A_LoopField,"WS")=1
            if SubStr(A_LoopField,3) is Number
                StringTrimLeft l_SubTextFontWeight,A_LoopField,2
        }


    ;[=============]
    ;[  p_Options  ]
    ;[=============]
    p_Options=%p_Options%  ;-- AutoTrim
    p_Options:="B " . p_Options

    ;-- If not explicitly defined, load font size just in case defaults don't
    ;   match system default
    ;
    if instr(p_Options," FM")=0
        p_Options:=p_Options . " FM" . l_MainTextFontSize

    if instr(p_Options," FS")=0
        p_Options:=p_Options . " FS" . l_SubTextFontSize


    ;-- Update/Simplify X/Y options
    StringReplace p_Options,p_Options,%A_Space%XLeft,%A_Space%XL,All
    StringReplace p_Options,p_Options,%A_Space%XMiddle,,All
    StringReplace p_Options,p_Options,%A_Space%XM,,All
    StringReplace p_Options,p_Options,%A_Space%XRight,%A_Space%XR,All

    StringReplace p_Options,p_Options,%A_Space%YTop,%A_Space%YT,All
    StringReplace p_Options,p_Options,%A_Space%YMiddle,,All
    StringReplace p_Options,p_Options,%A_Space%YM,,All
    StringReplace p_Options,p_Options,%A_Space%YBottom,%A_Space%YB,All



    ;[=========================]
    ;[  Find available window  ]
    ;[   (Starting with 71)    ]
    ;[=========================]
    local l_GUI=71
    loop
        {
        ;-- Window available?
        gui %l_GUI%:+LastFoundExist
        IfWinNotExist
            break

        ;-- Nothing available?
        if l_GUI=99
            {
            msgbox,262160,SplashOn Error,
               (ltrim
                Unable to create SplashOn temporary GUI.  %A_Space%
                GUI windows 71 to 99 are already in use.
               )

            return
            }

        ;-- Increment window
        l_GUI++
        }


    ;[==========================]
    ;[  Determine splash width  ]
    ;[==========================]
    ;-- Build temporary window to determine maximum width
    gui %l_GUI%:Margin,0,0
    gui %l_GUI%:Font,s%l_MainTextFontSize% w%l_MainTextFontWeight%,%p_Font%
    gui %l_GUI%:Add,Text,,%p_MainText%
    gui %l_GUI%:Font,s%l_SubTextFontSize% w%l_SubTextFontWeigth%
    gui %l_GUI%:Add,Text,,%p_SubText%
    gui %l_GUI%:Show,Hide  ;-- Render but don't show

    ;-- How wide is it?
    gui %l_GUI%:+LastFound
    WinGetPos ,,,l_SplashImageWidth,,% "ahk_id " . WinExist()
    gui %l_GUI%:Destroy


    ;-- Add some breathing room
    l_SplashImageWidth:=l_SplashImageWidth+40


    ;-- Too wide?
    l_MaxSplashImageWidth:=round(A_ScreenWidth*0.95)
    if (l_SplashImageWidth>l_MaxSplashImageWidth)
        l_SplashImageWidth:=l_MaxSplashImageWidth


    ;[==============]
    ;[  Splash it!  ]
    ;[==============]
    local l_BreakLoop:=false
    loop 2
        {
        ;-- Create working copy of p_Options
        local l_Options:=p_Options


        ;-- Function-specific X/Y options?
        if (instr(p_Options,A_Space . "XL")
        or  instr(p_Options,A_Space . "XR")
        or  instr(p_Options,A_Space . "YT")
        or  instr(p_Options,A_Space . "YB"))
            {
            StringReplace l_Options,l_Options,%A_Space%XL,,All
            StringReplace l_Options,l_Options,%A_Space%XR,,All
            StringReplace l_Options,l_Options,%A_Space%YT,,All
            StringReplace l_Options,l_Options,%A_Space%YB,,All
            l_Options:=l_Options . " Hide"
            }
         else
            l_BreakLoop:=true


        ;-- Splash using working copy of p_Options
        SplashImage %p_Window%:,W%l_SplashImageWidth% %l_Options% CWFEDCBA
            ,%p_SubText%
            ,%p_MainText%
            ,OsdWindow%p_Window%
            ,%p_Font%

            WinSet, ExStyle, +0x20, OsdWindow%p_Window%
            WinSet, TransColor,FEDCBA, OsdWindow%p_Window%

        ;-- Are we done yet?
        if l_BreakLoop
            break


        ;-- Collect splash window width and height
        WinGetPos ,,,l_SplashWindowWidth,l_SplashWindowHeight,OsdWindow%p_Window%


        ;-- Collect work area dimensions for primary monitor
        SysGet l_MonitorWorkArea,MonitorWorkArea


        ;-- Update X/Y positions
        StringReplace p_Options ,p_Options ,%A_Space%XL ,% " X" . l_MonitorWorkAreaLeft ,All

        StringReplace p_Options
            ,p_Options
            ,%A_Space%XR
            ,% " X" . l_MonitorWorkAreaRight-l_SplashWindowWidth
            ,All

        StringReplace p_Options
            ,p_Options
            ,%A_Space%YT
            ,% " Y" . l_MonitorWorkAreaTop
            ,All

        StringReplace p_Options
            ,p_Options
            ,%A_Space%YB
            ,% " Y" . l_MonitorWorkAreaBottom-l_SplashWindowHeight
            ,All
        }


    ;-- Minor delay to give the window a chance to render
    sleep 1


    ;[================]
    ;[  Housekeeping  ]
    ;[================]
    DetectHiddenWindows %l_DetectHiddenWindows%


    ;-- Return to sender
    return
    }



;********************
;*                  *
;*    OSD Off       *
;*                  *
;********************
Osd_Off(p_Window=9)
    {
         ;-- Destroy splash window
         SplashImage %p_Window%:Off

    ;-- Return to sender
    return
    }



;********************
;*                  *
;*    OSD Top All   *
;*                  *
;********************
Osd_ToggleOnTopAll()
{
    static TopToggle=0
    MyToggle := (TopToggle := !TopToggle) ? "On" : "Off"
    ;SplashOn("","AlwaysOnTop " . MyToggle ,-0.5,"","WS500 CWffff99")
    loop, 10
    {
        Index:=A_Index-1
        WinSet,AlwaysOnTop,%MyToggle%,OsdWindow%Index%
    }
}


;********************
;*                  *
;*    OSD Top       *
;*                  *
;********************
Osd_ToggleOnTop(p_Window=9)
{
    static TopToggle=0
    MyToggle := (TopToggle := !TopToggle) ? "On" : "Off"
    WinSet,AlwaysOnTop,%MyToggle%,OsdWindow%p_Window%
}


