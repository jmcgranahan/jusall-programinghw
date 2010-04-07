; Author:         gowness <biga05@gmail.com>
;
; Script Function:
;	basic math output
;


:*b0:/m[::
Input, eval, V , ]
length := StrLen(eval) + 4
sendinput {BS %length%}
sendinput % eval(Eval)
return

:*b0:/mwe[::
Input, eval, V , ]
length := StrLen(eval)
sendinput {BS}{Left %length%} {BS 6} {Right %length%} {space}={space}
sendinput % eval(Eval)
return

::/mcb::
eval := clipboard
length := StrLen(eval) + 4
sendinput {BS %length%}
sendinput % eval(Eval)
return

::/mcbwe::
eval := clipboard
length := StrLen(eval)
sendinput %eval%{space}={space}
sendinput % eval(Eval)
return