;////////////////////////////////////////////////////////////   
;// Parameters:
;// StringToComplete
;// ReturnValue			-	CSV (default): Suggestions as a comma separated list
;//				-	Raw: Raw XML as returned by google
;//
;// LanguageOfResults
;//				-	The standard two letter language code of the desired results
;//					http://en.wikipedia.org/wiki/List_of_ISO_639-1_codes
;//
;// Dependencies:
;// httpQuery()		http://www.autohotkey.com/forum/topic33506.html
;// uriEncode()		http://www.autohotkey.com/forum/topic33506.html&highlight=uriencode
;//
;// by gahks http://autohotkey.net/~gahks
;////////////////////////////////////////////////////////////

AutoComplete(StringtoComplete, ReturnValue="CSV", LanguageofResults="en") {
   local api_url, url, html, total, list, needle, haystack, pos
   api_url := "http://google.com/complete/search?hl=" . LanguageofResults . "&xml=true&q="
   url := api_url . uriEncode(StringtoComplete)
   httpQuery(html:="",url)
   VarSetCapacity(html,-1)
   if (ReturnValue = "Raw")
     return html
   haystack := html
   needle = is)<suggestion data="(.*?)"
   pos := 0
   while, pos := RegExMatch(haystack, needle, match, pos+1)
   {
		if (a_index = 1)
			list := match1
		else
			list .= "," match1
   }	
   return list
}	
