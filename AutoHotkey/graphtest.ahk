

DetectHiddenWindows On
OnExit GuiClose

Gui Add,Progress,w402 h1 x10 y10
Gui Add,Progress,w1 h402 x10 y10
Gui Add,Progress,w402 h1 x10 y411
Gui Add,Progress,w1 h402 x411 y10
Process Exist
WinGet ScriptID,ID,ahk_pid %ErrorLevel%
Gui Show,w422 h422,Function Grapher

GraphOpt_defGraphColor := 0xFF0000  ;red
Graph_Create(ScriptID,11,11,400,400,"GraphOpt_")
return

GuiContextMenu:
InputBox,Equation,Function Grapher,Enter an equation in terms of x:
Graph(Equation)
return

GuiEscape:
Graph_Clear()
return

GuiClose:
Graph_Destroy()
ExitApp