F12::
GPF_Main()
var_ShowText := 1

; Current var_ObjNumer is 0, so it sets the data of the first SingLine Text Field
GPF_SetSingleLine(var_ObjNumber,var_PosX,var_PosY,var_TextLine,var_ARGB,var_UseBlackBG,var_FontSize,var_UseBold,var_FontFamily)

; Shows the SingleLine Text Field number 0 (the first one)
GPF_ShowSingleLine(var_ObjNumber,var_ShowText)

Sleep, 1000
GPF_ShowFPS(1)
; Now previous text will be replaced by a new one
GPF_SetSingleLine(var_ObjNumber,var_PosX,var_PosY,"Test number 2!",var_ARGB,var_UseBlackBG,var_FontSize,var_UseBold,var_FontFamily)

Return