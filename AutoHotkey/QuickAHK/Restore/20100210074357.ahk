rows := cols := 40                               ; set grid dimensions
grid := AHKA_NewArray()
line := AHKA_NewArray()
alive:= "2 3"
dead := "3"
 
Loop % rows {                                    ; setup grid of checkboxes
   r := A_Index, y := r*17-8                     
   Loop % cols {
      c := A_Index, x := c*17-5
      Gui Add, CheckBox, x%x% y%y% w17 h17 vv%c%_%r% gCheck
	  line := AHKA_Add(line, "0")
   }
   grid := AHKA_Add(grid, line)
   line := AHKA_Remove(line, rows)
}
Gui Add, Button, % "x12 w" x/3, step             ; button to step to next generation
Gui Show
Return
 
Check:
   GuiControlGet %A_GuiControl%                  ; manual set of cells
Return
 
ButtonStep:                                      ; move to next generation
   Loop % rows {
      r := A_Index
	  line := AHKA_Get(grid, r)
      Loop % cols {
         c := A_Index, n := 
		 
		 if(AHKA_Get(grid,r,c) == 1) {
			StringGetPos,found,alive,% AliveNeighbors(r,c)
			line := AHKA_Set(line, (found) ? ("1") : ("0") ,c)
		}
		else {
			StringGetPos,found,dead,% AliveNeighbors(r,c)
			line := AHKA_Set(line, (found) ? ("1") : ("0") ,c)
		}
         ;Loop 8                                  ; w[x,y] <- new states
         ;   x := c+i%A_Index%, y := r+j%A_Index%, n += 1=v%x%_%y%
         GuiControl,,v%c%_%r%,% AHKA_Get(line,c)
      }
	  grid := AHKA_Set(grid, line, r)
   }
   
   ;Loop % rows {                                 ; update v[x,y] = states
   ;   r := A_Index
   ;   Loop % cols
   ;      v%A_Index%_%r% := w%A_Index%_%r%
   ;}
Return
 
GuiClose:                                        ; exit when GUI is closed
ExitApp

AliveNeighbors(x,y)
{
	alive = 0
	loop 3 {
		r := A_Index
		loop 3{
			c := A_Index
			if((AHKA_GET(grid,r,c) == "1") && (r != x && c != y))
				alive++
		}
	}
	return alive
}