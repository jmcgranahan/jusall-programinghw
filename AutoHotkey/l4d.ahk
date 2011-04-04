; Author:         gowness <biga05@gmail.com>
;
; Script Function: L4D firemode changer
;	
;


Splashup(Active="")
{
	global $Active, $FireMode, $first
	
	
	if($FireMode = "")
		$FireMode = Normal
		
	if Active is not Space
	{
		if(Active != $Active)
			$first := true
		$Active:=Active
		
	}
		
	if($Active)
	{
		Osd("", $FireMode,"","Courier New","FS20 XR Y250 CT00FF00 WS700",7)
		;if($first)
		;{
		;	SplashOn($FireMode,"",0,"Courier New","FS16 XM YTop")
		;	$first := false
		;}
		;SplashOn_Off(true)
	}
	else
	{
		Osd_Off(7)
		;SplashOn_Off(false)
	}
}

ChangeFireMode:

if($FireMode = "Auto")
	$FireMode = Normal
else if($FireMode = "Single")
	$FireMode = Burst
else if($FireMode = "Burst")
	$FireMode = Auto
else if($FireMode = "Normal")
	$FireMode = Single			
	
Splashup(false)
return

mousedown:

if($Firemode = "Normal")
	Click down
if($FireMode = "Single")
	Click
	
if($FireMode = "Auto")
{
		while GetKeyState("LButton","P")
		{
			click up
			Sleep, 5
			click down
			Sleep,5
		}
	}

if($FireMode = "Burst")
{
		while GetKeyState("LButton","P")
		{
			Loop, 3
			{
				click up
				Sleep, 40
				click down
			}
			click up
			sleep, 125
		}
	}
Keywait, LButton
Click up
return


