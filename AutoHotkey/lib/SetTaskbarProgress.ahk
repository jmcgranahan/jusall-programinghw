; SetTaskbarProgress  -  Requires Windows 7.
;
; pct    -  A number between 0 and 100 or a state value (see below).
; state  -  "N" (normal), "P" (paused), "E" (error) or "I" (indeterminate).
;           If omitted (and pct is a number), the state is not changed.
; hwnd   -  The ID of the window which owns the taskbar button.
;           If omitted, the Last Found Window is used.
;
SetTaskbarProgress(pct, state="", hwnd="")
{
    static tbl, s0:=0, sI:=1, sN:=2, sE:=4, sP:=8
    if !tbl
    {
        COM_Init() ; Create a TaskbarList object with ITaskbarList3 interface:
        if DllCall("ole32\CoCreateInstance", "uint", COM_GUID4String(CLSID,"{56FDF344-FD6D-11d0-958A-006097C9A090}"), "uint", 0, "uint", 21, "uint", COM_GUID4String(IID,"{ea1afb91-9e28-4b86-90e9-9e9f8a5eefaf}"), "uint*", tbl) != 0
        {
            MsgBox 16,, Error creating TaskbarList object. Is this script running on Windows 7? Exiting.
            ExitApp
        }
    }
    if hwnd =
        hwnd := WinExist()
    if pct is not number
        state := pct, pct := ""
    else if (pct = 0 && state="")
        state := 0, pct := ""
    if state in 0,I,N,E,P   ; ITaskbarList3::SetProgressState
        DllCall(NumGet(NumGet(tbl+0)+40), "uint", tbl, "uint", hwnd, "uint", s%state%)
    if pct !=               ; ITaskbarList3::SetProgressValue
        DllCall(NumGet(NumGet(tbl+0)+36), "uint", tbl, "uint", hwnd, "int64", pct*10, "int64", 1000)
}