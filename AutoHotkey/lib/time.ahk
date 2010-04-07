time_short()
{
	FormatTime, CurrentTime,,  h:mm tt
	Return	%CurrentTime%
}

time_long()
{
	FormatTime, CurrentTime,,  h:mm:ss tt
	Return	%CurrentTime%
}

time_24_short()
{
	FormatTime, CurrentTime,,  HH:mm
	Return	%CurrentTime%
}

time_24_long()
{
	FormatTime, CurrentTime,,  HH:mm:ss
	Return	%CurrentTime%
}

time_date_short()
{
	FormatTime, CurrentTime,,  M/d/yy
	Return	%CurrentTime%
}

time_date_long()
{
	FormatTime, CurrentTime,,  MM/dd/yy
	Return	%CurrentTime%
}

time_date_text_short()
{
	FormatTime, CurrentTime,, ddd, MMM dd, yyyy
	Return	%CurrentTime%
}

time_date_text_long()
{
	FormatTime, CurrentTime,, dddd, MMMM dd, yyyy
	Return	%CurrentTime%
}

