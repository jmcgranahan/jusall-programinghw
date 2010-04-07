FtpOpen(Server, Port=21, Username=0, Password=0 ,Proxy="", ProxyBypass="")
{
menu, Tray, Icon, status_icons.dll, 1 
IfEqual, Username, 0, SetEnv, Username, anonymous
IfEqual, Password, 0, SetEnv, Password, anonymous

If (Proxy != "")
AccessType=3
Else
AccessType=1

menu, Tray, Icon, status_icons.dll, 8
sleep 300
menu, Tray, Icon, status_icons.dll, 1
sleep 100
menu, Tray, Icon, status_icons.dll, 8
sleep 200
menu, Tray, Icon, status_icons.dll, 1
global ic_hInternet, io_hInternet, hModule
hModule := DllCall("LoadLibrary", "str", "wininet.dll")

io_hInternet := DllCall("wininet\InternetOpenA"
, "str", A_ScriptName ;lpszAgent
, "UInt", AccessType
, "str", Proxy
, "str", ProxyBypass
, "UInt", 0) ;dwFlags

If (ErrorLevel != 0 or io_hInternet = 0) 
	{
	FtpClose()
	return 0
	}

ic_hInternet := DllCall("wininet\InternetConnectA"
, "uint", io_hInternet
, "str", Server
, "uint", Port
, "str", Username
, "str", Password
, "uint" , 1 ;dwService (INTERNET_SERVICE_FTP = 1)
, "uint", 0 ;dwFlags
, "uint", 0) ;dwContext

If (ErrorLevel != 0 or ic_hInternet = 0)
return 0
else
return 1
}

FtpClose() 
{
global ic_hInternet, io_hInternet, hModule
DllCall("wininet\InternetCloseHandle",  "UInt", ic_hInternet)
DllCall("wininet\InternetCloseHandle",  "UInt", io_hInternet)
DllCall("FreeLibrary", "UInt", hModule)
}

FtpPutFile(LocalFile, NewRemoteFile="", Flags=0) {
menu, Tray, Icon, status_icons.dll, 4
;TrayTip,,Sending...
;Flags:
;FTP_TRANSFER_TYPE_UNKNOWN = 0 (Defaults to FTP_TRANSFER_TYPE_BINARY)
;FTP_TRANSFER_TYPE_ASCII = 1
;FTP_TRANSFER_TYPE_BINARY = 2
If NewRemoteFile=
NewRemoteFile := LocalFile
global ic_hInternet
r := DllCall("wininet\FtpPutFileA"
, "uint", ic_hInternet
, "str", LocalFile
, "str", NewRemoteFile
, "uint", Flags
, "uint", 0) ;dwContext
If (ErrorLevel != 0 or r = 0)
return 0
else
return 1
}
menu, Tray, Icon, status_icons.dll, 2
;TrayTip,,Initialisation...
sleep 1000

IfExist, Config.ini
{
IniRead, imgext , Config.ini, prefs, Ext_Images
If !imgext 
	{
	SoundPlay,*64
	menu, Tray, Icon, status_icons.dll, 6
	TrayTip,Config error, Error images ext not set in Config.ini. `nNow exiting...,2,2,1000
	sleep,8000
	Exitapp
	}
IniRead, FTP_Remote_Host_name , Config.ini, prefs, FTP_Remote_Host_name
If !FTP_Remote_Host_name 
	{
	SoundPlay,*64
	menu, Tray, Icon, status_icons.dll, 6
	TrayTip,Config error, Error host name not set in Config.ini. `nNow exiting...,2,2,1000
	sleep,8000
	Exitapp
	}
IniRead, FTP_Remote_Host_port , Config.ini, prefs, FTP_Remote_Host_port
If !FTP_Remote_Host_port
	{
	SoundPlay,*64
	menu, Tray, Icon, status_icons.dll, 6
	TrayTip,Config error, Error host port not set in Config.ini. `nNow exiting...,2,2,1000
	sleep,8000
	Exitapp
	}
IniRead, FTP_Remote_Host_user , Config.ini, prefs, FTP_Remote_Host_user
If !FTP_Remote_Host_user
	{
	SoundPlay,*64
	menu, Tray, Icon, status_icons.dll, 6
	TrayTip,Config error, Error user name not set in Config.ini. `nNow exiting...,2,2,1000
	sleep,8000
	Exitapp
	}
IniRead, FTP_Remote_Host_passwd , Config.ini, prefs, FTP_Remote_Host_passwd
If !FTP_Remote_Host_passwd
	{
	SoundPlay,*64
	menu, Tray, Icon, status_icons.dll, 6
	TrayTip,Config error, Error password not set in Config.ini. `nNow exiting...,2,2,1000
	sleep,8000
	Exitapp
	}
IniRead, HTTP_Remote_path , Config.ini, prefs, HTTP_Remote_path
If !HTTP_Remote_path
	{
	SoundPlay,*64
	menu, Tray, Icon, status_icons.dll, 6
	TrayTip,Config error, Error WWW path not set in Config.ini. `nNow exiting...,2,2,1000
	sleep,8000
	Exitapp
	}
}
else
{
SoundPlay,*64
menu, Tray, Icon, status_icons.dll, 6
TrayTip,Config error, Can't find Config.ini file. `nNow exiting...,2,2,1000
sleep,8000
Exitapp
}

ifexist %1%
{

	If (FtpOpen(FTP_Remote_Host_name, FTP_Remote_Host_port, FTP_Remote_Host_user, FTP_Remote_Host_passwd) != 1)
  	 {
	SoundPlay,*64
	menu, Tray, Icon, status_icons.dll, 6
  	TrayTip,Connexion error, Can't connect to %FTP_Remote_Host_name%. `nNow exiting..,2,2,1000
	sleep,8000
	FtpClose() 
  	exitapp
 	 }
	Else
	{

	File_path=%1%
	SplitPath, File_path , remote_file
	If (FtpPutFile(File_path, remote_file, Flags=1) != 1)
 		 {
		SoundPlay,*64
		menu, Tray, Icon, status_icons.dll, 6
    		TrayTip,Transfert error, An error ocured while transfering %remote_file%. `nNow exiting..,2,2,1000
		sleep,8000
		FtpClose() 	
   		exitapp
  		 }
	
	SplitPath, File_path ,,, file_ext
	if file_ext in %imgext%
		{
		Clipboard=[img]%HTTP_Remote_path%%remote_file%[/img]
		menu, Tray, Icon, status_icons.dll, 5
		TrayTip,BBCode "IMG" copied in clipboard.,[img]%HTTP_Remote_path%%remote_file%[/img],2,1,1000
		FtpClose() 
		sleep,8000
		exitapp
		}
		else
		{
		Clipboard=[url]%HTTP_Remote_path%%remote_file%[/url]
		menu, Tray, Icon, status_icons.dll, 5
		TrayTip,BBCode "URL" copied in clipboard.,[url]%HTTP_Remote_path%%remote_file%[/url],2,1,1000
		FtpClose() 
		sleep,8000
		exitapp
		}




	}
}
SoundPlay,*64
menu, Tray, Icon, status_icons.dll, 6
TrayTip,Path error., Can't find the file: "%1%". `nNow exiting..,2,2,1000
sleep,8000
Exitapp








