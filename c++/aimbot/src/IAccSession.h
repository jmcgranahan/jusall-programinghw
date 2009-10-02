/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Feb 12 14:49:28 2008
 */
/* Compiler settings for C:\dev\aimcc\aimcc\idl\IAccSession.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "AccBase.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#endif /*COM_NO_WINDOWS_H*/

#ifndef __IAccSession_h__
#define __IAccSession_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccSession_FWD_DEFINED__
#define __IAccSession_FWD_DEFINED__
typedef interface IAccSession IAccSession;
#endif 	/* __IAccSession_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccBartCacheManager.h"
#include "IAccBuddyList.h"
#include "IAccCallAlertControlHook.h"
#include "IAccClientInfo.h"
#include "IAccCustomSession.h"
#include "IAccDirEntry.h"
#include "IAccImSession.h"
#include "IAccInstance.h"
#include "IAccPreferences.h"
#include "IAccPreferencesHook.h"
#include "IAccSecurityManager.h"
#include "IAccPluginManager.h"
#include "IAccStats.h"
#include "IAccStoredImManager.h"


#ifndef __IAccSession_INTERFACE_DEFINED__
#define __IAccSession_INTERFACE_DEFINED__

/* interface IAccSession */
/* [object][dual][uuid] */ 

typedef 
enum AccSessionState
    {	AccSessionState_Offline	= 0,
	AccSessionState_Disconnected	= 50,
	AccSessionState_QueryingDcs	= 75,
	AccSessionState_Connecting	= 100,
	AccSessionState_Challenging	= 150,
	AccSessionState_Validating	= 200,
	AccSessionState_SecurId	= 210,
	AccSessionState_SecurIdNextKey	= 211,
	AccSessionState_Transferring	= 300,
	AccSessionState_Negotiating	= 350,
	AccSessionState_Starting	= 400,
	AccSessionState_Online	= 500,
	AccSessionState_WillShutdown	= 550,
	AccSessionState_Shutdown	= 600,
	AccSessionState_Paused	= 700
    }	AccSessionState;

typedef 
enum AccParentalControlFlags
    {	AccParentalControlFlags_NoIm	= 0x1,
	AccParentalControlFlags_NoChat	= 0x2,
	AccParentalControlFlags_NoBuddyList	= 0x4,
	AccParentalControlFlags_NoAudio	= 0x8,
	AccParentalControlFlags_NoVideo	= 0x10,
	AccParentalControlFlags_NoDirectIm	= 0x20,
	AccParentalControlFlags_NoCustomSound	= 0x40,
	AccParentalControlFlags_NoCustomIcon	= 0x80,
	AccParentalControlFlags_NoFileXfer	= 0x200,
	AccParentalControlFlags_ForceRelay	= 0x400,
	AccParentalControlFlags_NoChatLinks	= 0x800,
	AccParentalControlFlags_NoBuddyFeed	= 0x1000
    }	AccParentalControlFlags;

typedef 
enum AccSubscriptionFlags
    {	AccSubscriptionFlags_E911	= 0x40000000,
	AccSubscriptionFlags_Voip	= 0x80000000
    }	AccSubscriptionFlags;

typedef 
enum AccSessionUiFlags
    {	AccSessionUiFlags_HideChangeEmail	= 0x1,
	AccSessionUiFlags_HideConfirmEmail	= 0x2,
	AccSessionUiFlags_HideFormatScreenName	= 0x4,
	AccSessionUiFlags_HideSns	= 0x8,
	AccSessionUiFlags_DisableAlerts	= 0x10,
	AccSessionUiFlags_HideRegisStatusPref	= 0x20
    }	AccSessionUiFlags;

typedef 
enum AccSessionProp
    {	AccSessionProp_Identity	= 0,
	AccSessionProp_LinkedIdentities	= AccSessionProp_Identity + 1,
	AccSessionProp_InstanceId	= AccSessionProp_LinkedIdentities + 1,
	AccSessionProp_OnlineTime	= AccSessionProp_InstanceId + 1,
	AccSessionProp_IpAddress	= AccSessionProp_OnlineTime + 1,
	AccSessionProp_Port	= AccSessionProp_IpAddress + 1,
	AccSessionProp_Profile	= AccSessionProp_Port + 1,
	AccSessionProp_AwayMessage	= AccSessionProp_Profile + 1,
	AccSessionProp_Capabilities	= AccSessionProp_AwayMessage + 1,
	AccSessionProp_AppearOffline	= AccSessionProp_Capabilities + 1,
	AccSessionProp_ImForwardingCapable	= AccSessionProp_AppearOffline + 1,
	AccSessionProp_ImForwardingActive	= AccSessionProp_ImForwardingCapable + 1,
	AccSessionProp_SecondsOfInactivityBeforeIdleState	= AccSessionProp_ImForwardingActive + 1,
	AccSessionProp_SecondsSinceUserActivity	= AccSessionProp_SecondsOfInactivityBeforeIdleState + 1,
	AccSessionProp_SecondsSinceKeyboardActivity	= AccSessionProp_SecondsSinceUserActivity + 1,
	AccSessionProp_SecondsRemainingUntilIdleState	= AccSessionProp_SecondsSinceKeyboardActivity + 1,
	AccSessionProp_UserIdle	= AccSessionProp_SecondsRemainingUntilIdleState + 1,
	AccSessionProp_BetaUpgradeInfo	= AccSessionProp_UserIdle + 1,
	AccSessionProp_UpgradeInfo	= AccSessionProp_BetaUpgradeInfo + 1,
	AccSessionProp_UpgradeRecommended	= AccSessionProp_UpgradeInfo + 1,
	AccSessionProp_HostTime	= AccSessionProp_UpgradeRecommended + 1,
	AccSessionProp_ChangePasswordUrl	= AccSessionProp_HostTime + 1,
	AccSessionProp_UiFlags	= AccSessionProp_ChangePasswordUrl + 1,
	AccSessionProp_InstanceFlags	= AccSessionProp_UiFlags + 1,
	AccSessionProp_ParentalControls	= AccSessionProp_InstanceFlags + 1,
	AccSessionProp_Subscriptions	= AccSessionProp_ParentalControls + 1,
	AccSessionProp_MaxProfileLength	= AccSessionProp_Subscriptions + 1,
	AccSessionProp_MaxAwayMessageLength	= AccSessionProp_MaxProfileLength + 1,
	AccSessionProp_MaxChatRoomNameLength	= AccSessionProp_MaxAwayMessageLength + 1,
	AccSessionProp_MaxInvitationLength	= AccSessionProp_MaxChatRoomNameLength + 1,
	AccSessionProp_MaxLookupUserCount	= AccSessionProp_MaxInvitationLength + 1,
	AccSessionProp_MaxUserLookups	= AccSessionProp_MaxLookupUserCount,
	AccSessionProp_LinkedMasterSession	= AccSessionProp_MaxUserLookups + 1,
	AccSessionProp_MaxChatSessionCount	= AccSessionProp_LinkedMasterSession + 1,
	AccSessionProp_MaxChatSessions	= AccSessionProp_MaxChatSessionCount,
	AccSessionProp_MaxPermittedUserCount	= AccSessionProp_MaxChatSessions + 1,
	AccSessionProp_MaxDeniedUserCount	= AccSessionProp_MaxPermittedUserCount + 1,
	AccSessionProp_LocalIpAddress	= AccSessionProp_MaxDeniedUserCount + 1,
	AccSessionProp_MaxFavoriteLocationCount	= AccSessionProp_LocalIpAddress + 1,
	AccSessionProp_Plugins	= AccSessionProp_MaxFavoriteLocationCount + 1,
	AccSessionProp_StoredImManager	= AccSessionProp_Plugins + 1,
	AccSessionProp_PhoneNumber	= AccSessionProp_StoredImManager + 1,
	AccSessionProp_Pause	= AccSessionProp_PhoneNumber + 1,
	AccSessionProp_Credentials	= AccSessionProp_Pause + 1,
	AccSessionProp_BartCacheManager	= AccSessionProp_Credentials + 1,
	AccSessionProp_BartBase	= 10000,
	AccSessionProp_SmallIcon	= AccSessionProp_BartBase + 0,
	AccSessionProp_BuddyIcon	= AccSessionProp_BartBase + 1,
	AccSessionProp_StatusText	= AccSessionProp_BartBase + 2,
	AccSessionProp_ArriveSound	= AccSessionProp_BartBase + 3,
	AccSessionProp_RichName	= AccSessionProp_BartBase + 4,
	AccSessionProp_SuperIcon	= AccSessionProp_BartBase + 5,
	AccSessionProp_RadioStation	= AccSessionProp_BartBase + 6,
	AccSessionProp_SuperIconTrigger	= AccSessionProp_BartBase + 7,
	AccSessionProp_StatusTextLink	= AccSessionProp_BartBase + 9,
	AccSessionProp_E911Location	= AccSessionProp_BartBase + 10,
	AccSessionProp_Location	= AccSessionProp_BartBase + 11,
	AccSessionProp_BigIcon	= AccSessionProp_BartBase + 12,
	AccSessionProp_StatusTextTimestamp	= AccSessionProp_BartBase + 13,
	AccSessionProp_AvTrack	= AccSessionProp_BartBase + 15,
	AccSessionProp_DepartSound	= AccSessionProp_BartBase + 96,
	AccSessionProp_Wallpaper	= AccSessionProp_BartBase + 129,
	AccSessionProp_Badge	= AccSessionProp_BartBase + 132,
	AccSessionProp_FlashWallpaper	= AccSessionProp_BartBase + 136,
	AccSessionProp_ImmersiveWallpaper	= AccSessionProp_BartBase + 137,
	AccSessionProp_BartMax	= AccSessionProp_BartBase + 4095
    }	AccSessionProp;


EXTERN_C const IID IID_IAccSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e0b2aa40-7bf5-11d3-a655-0060b0883b25")
    IAccSession : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ClientInfo( 
            /* [retval][out] */ IAccClientInfo __RPC_FAR *__RPC_FAR *ppiAccClientInfo) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_PrefsHook( 
            /* [in] */ IAccPreferencesHook __RPC_FAR *piAccPrefsHook) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Identity( 
            /* [in] */ xp_kstr identity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SignOn( 
            /* [in] */ xp_kstr password) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSecurIdKey( 
            /* [in] */ xp_kstr key) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SignOff( void) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_State( 
            /* [retval][out] */ AccSessionState __RPC_FAR *pState) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Identity( 
            /* [retval][out] */ xp_str __RPC_FAR *pIdentity) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_OtherInstances( 
            /* [retval][out] */ xp_variant __RPC_FAR *pInstances) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_BuddyList( 
            /* [retval][out] */ IAccBuddyList __RPC_FAR *__RPC_FAR *ppiBuddies) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_SecurityManager( 
            /* [retval][out] */ IAccSecurityManager __RPC_FAR *__RPC_FAR *ppiSecurityManager) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_PluginManager( 
            /* [retval][out] */ IAccPluginManager __RPC_FAR *__RPC_FAR *ppiPluginManager) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Prefs( 
            /* [retval][out] */ IAccPreferences __RPC_FAR *__RPC_FAR *prefs) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccSessionProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccSessionProp property,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSecondaryManager( 
            /* [in] */ xp_int serviceId,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppiManager) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSecondarySessions( 
            /* [in] */ xp_int serviceId,
            /* [retval][out] */ xp_variant __RPC_FAR *pSessions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateGroup( 
            /* [in] */ xp_kstr name,
            /* [retval][out] */ IAccGroup __RPC_FAR *__RPC_FAR *group) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateUser( 
            /* [in] */ xp_kstr name,
            /* [retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *user) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateImSession( 
            /* [in] */ xp_kstr userName,
            /* [defaultvalue][in] */ AccImSessionType sessionType,
            /* [retval][out] */ IAccImSession __RPC_FAR *__RPC_FAR *imSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateChatSession( 
            /* [defaultvalue][in] */ xp_kstr roomName,
            /* [defaultvalue][in] */ xp_int exchange,
            /* [defaultvalue][in] */ xp_int instance,
            /* [retval][out] */ IAccImSession __RPC_FAR *__RPC_FAR *imSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateCustomSession( 
            /* [in] */ xp_kstr uuid,
            /* [retval][out] */ IAccCustomSession __RPC_FAR *__RPC_FAR *customSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateIm( 
            /* [defaultvalue][in] */ xp_kstr text,
            /* [defaultvalue][in] */ xp_kstr type,
            /* [retval][out] */ IAccIm __RPC_FAR *__RPC_FAR *ppiIm) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateBartItem( 
            /* [in] */ AccBartItemType type,
            /* [in] */ xp_kstr id,
            /* [retval][out] */ IAccBartItem __RPC_FAR *__RPC_FAR *ppiAccBartItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateDirEntry( 
            /* [retval][out] */ IAccDirEntry __RPC_FAR *__RPC_FAR *ppiAccDirEntry) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateStream( 
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ IAccStream __RPC_FAR *__RPC_FAR *ppiStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LookupUsers( 
            /* [in] */ xp_kvariant users,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SearchDirectory( 
            /* [in] */ xp_kvariant query,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendInviteMail( 
            /* [in] */ xp_kstr email,
            /* [defaultvalue][in] */ xp_kstr message,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestService( 
            /* [in] */ xp_kstr serviceId,
            /* [in] */ xp_kvariant qualifiers,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConfirmAccount( 
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelEvent( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddCapabilities( 
            /* [in] */ xp_kvariant caps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveCapabilities( 
            /* [in] */ xp_kvariant caps) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE VerifyPassword( 
            /* [in] */ xp_kstr password,
            /* [retval][out] */ xp_vbool __RPC_FAR *verified) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccSessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccSession __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccSession __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ClientInfo )( 
            IAccSession __RPC_FAR * This,
            /* [retval][out] */ IAccClientInfo __RPC_FAR *__RPC_FAR *ppiAccClientInfo);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PrefsHook )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ IAccPreferencesHook __RPC_FAR *piAccPrefsHook);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Identity )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ xp_kstr identity);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SignOn )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ xp_kstr password);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSecurIdKey )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ xp_kstr key);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SignOff )( 
            IAccSession __RPC_FAR * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_State )( 
            IAccSession __RPC_FAR * This,
            /* [retval][out] */ AccSessionState __RPC_FAR *pState);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Identity )( 
            IAccSession __RPC_FAR * This,
            /* [retval][out] */ xp_str __RPC_FAR *pIdentity);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OtherInstances )( 
            IAccSession __RPC_FAR * This,
            /* [retval][out] */ xp_variant __RPC_FAR *pInstances);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BuddyList )( 
            IAccSession __RPC_FAR * This,
            /* [retval][out] */ IAccBuddyList __RPC_FAR *__RPC_FAR *ppiBuddies);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SecurityManager )( 
            IAccSession __RPC_FAR * This,
            /* [retval][out] */ IAccSecurityManager __RPC_FAR *__RPC_FAR *ppiSecurityManager);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PluginManager )( 
            IAccSession __RPC_FAR * This,
            /* [retval][out] */ IAccPluginManager __RPC_FAR *__RPC_FAR *ppiPluginManager);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Prefs )( 
            IAccSession __RPC_FAR * This,
            /* [retval][out] */ IAccPreferences __RPC_FAR *__RPC_FAR *prefs);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ AccSessionProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ AccSessionProp property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSecondaryManager )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ xp_int serviceId,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppiManager);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSecondarySessions )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ xp_int serviceId,
            /* [retval][out] */ xp_variant __RPC_FAR *pSessions);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateGroup )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ xp_kstr name,
            /* [retval][out] */ IAccGroup __RPC_FAR *__RPC_FAR *group);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateUser )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ xp_kstr name,
            /* [retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *user);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateImSession )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ xp_kstr userName,
            /* [defaultvalue][in] */ AccImSessionType sessionType,
            /* [retval][out] */ IAccImSession __RPC_FAR *__RPC_FAR *imSession);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateChatSession )( 
            IAccSession __RPC_FAR * This,
            /* [defaultvalue][in] */ xp_kstr roomName,
            /* [defaultvalue][in] */ xp_int exchange,
            /* [defaultvalue][in] */ xp_int instance,
            /* [retval][out] */ IAccImSession __RPC_FAR *__RPC_FAR *imSession);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateCustomSession )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ xp_kstr uuid,
            /* [retval][out] */ IAccCustomSession __RPC_FAR *__RPC_FAR *customSession);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateIm )( 
            IAccSession __RPC_FAR * This,
            /* [defaultvalue][in] */ xp_kstr text,
            /* [defaultvalue][in] */ xp_kstr type,
            /* [retval][out] */ IAccIm __RPC_FAR *__RPC_FAR *ppiIm);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateBartItem )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ AccBartItemType type,
            /* [in] */ xp_kstr id,
            /* [retval][out] */ IAccBartItem __RPC_FAR *__RPC_FAR *ppiAccBartItem);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateDirEntry )( 
            IAccSession __RPC_FAR * This,
            /* [retval][out] */ IAccDirEntry __RPC_FAR *__RPC_FAR *ppiAccDirEntry);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateStream )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ IAccStream __RPC_FAR *__RPC_FAR *ppiStream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LookupUsers )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ xp_kvariant users,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SearchDirectory )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ xp_kvariant query,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SendInviteMail )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ xp_kstr email,
            /* [defaultvalue][in] */ xp_kstr message,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestService )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ xp_kstr serviceId,
            /* [in] */ xp_kvariant qualifiers,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConfirmAccount )( 
            IAccSession __RPC_FAR * This,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CancelEvent )( 
            IAccSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddCapabilities )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ xp_kvariant caps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveCapabilities )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ xp_kvariant caps);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *VerifyPassword )( 
            IAccSession __RPC_FAR * This,
            /* [in] */ xp_kstr password,
            /* [retval][out] */ xp_vbool __RPC_FAR *verified);
        
        END_INTERFACE
    } IAccSessionVtbl;

    interface IAccSession
    {
        CONST_VTBL struct IAccSessionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccSession_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccSession_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccSession_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccSession_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccSession_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccSession_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccSession_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccSession_get_ClientInfo(This,ppiAccClientInfo)	\
    (This)->lpVtbl -> get_ClientInfo(This,ppiAccClientInfo)

#define IAccSession_put_PrefsHook(This,piAccPrefsHook)	\
    (This)->lpVtbl -> put_PrefsHook(This,piAccPrefsHook)

#define IAccSession_put_Identity(This,identity)	\
    (This)->lpVtbl -> put_Identity(This,identity)

#define IAccSession_SignOn(This,password)	\
    (This)->lpVtbl -> SignOn(This,password)

#define IAccSession_SetSecurIdKey(This,key)	\
    (This)->lpVtbl -> SetSecurIdKey(This,key)

#define IAccSession_SignOff(This)	\
    (This)->lpVtbl -> SignOff(This)

#define IAccSession_get_State(This,pState)	\
    (This)->lpVtbl -> get_State(This,pState)

#define IAccSession_get_Identity(This,pIdentity)	\
    (This)->lpVtbl -> get_Identity(This,pIdentity)

#define IAccSession_get_OtherInstances(This,pInstances)	\
    (This)->lpVtbl -> get_OtherInstances(This,pInstances)

#define IAccSession_get_BuddyList(This,ppiBuddies)	\
    (This)->lpVtbl -> get_BuddyList(This,ppiBuddies)

#define IAccSession_get_SecurityManager(This,ppiSecurityManager)	\
    (This)->lpVtbl -> get_SecurityManager(This,ppiSecurityManager)

#define IAccSession_get_PluginManager(This,ppiPluginManager)	\
    (This)->lpVtbl -> get_PluginManager(This,ppiPluginManager)

#define IAccSession_get_Prefs(This,prefs)	\
    (This)->lpVtbl -> get_Prefs(This,prefs)

#define IAccSession_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccSession_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccSession_GetSecondaryManager(This,serviceId,ppiManager)	\
    (This)->lpVtbl -> GetSecondaryManager(This,serviceId,ppiManager)

#define IAccSession_GetSecondarySessions(This,serviceId,pSessions)	\
    (This)->lpVtbl -> GetSecondarySessions(This,serviceId,pSessions)

#define IAccSession_CreateGroup(This,name,group)	\
    (This)->lpVtbl -> CreateGroup(This,name,group)

#define IAccSession_CreateUser(This,name,user)	\
    (This)->lpVtbl -> CreateUser(This,name,user)

#define IAccSession_CreateImSession(This,userName,sessionType,imSession)	\
    (This)->lpVtbl -> CreateImSession(This,userName,sessionType,imSession)

#define IAccSession_CreateChatSession(This,roomName,exchange,instance,imSession)	\
    (This)->lpVtbl -> CreateChatSession(This,roomName,exchange,instance,imSession)

#define IAccSession_CreateCustomSession(This,uuid,customSession)	\
    (This)->lpVtbl -> CreateCustomSession(This,uuid,customSession)

#define IAccSession_CreateIm(This,text,type,ppiIm)	\
    (This)->lpVtbl -> CreateIm(This,text,type,ppiIm)

#define IAccSession_CreateBartItem(This,type,id,ppiAccBartItem)	\
    (This)->lpVtbl -> CreateBartItem(This,type,id,ppiAccBartItem)

#define IAccSession_CreateDirEntry(This,ppiAccDirEntry)	\
    (This)->lpVtbl -> CreateDirEntry(This,ppiAccDirEntry)

#define IAccSession_CreateStream(This,specifier,ppiStream)	\
    (This)->lpVtbl -> CreateStream(This,specifier,ppiStream)

#define IAccSession_LookupUsers(This,users,pTransId)	\
    (This)->lpVtbl -> LookupUsers(This,users,pTransId)

#define IAccSession_SearchDirectory(This,query,pTransId)	\
    (This)->lpVtbl -> SearchDirectory(This,query,pTransId)

#define IAccSession_SendInviteMail(This,email,message,pTransId)	\
    (This)->lpVtbl -> SendInviteMail(This,email,message,pTransId)

#define IAccSession_RequestService(This,serviceId,qualifiers,pTransId)	\
    (This)->lpVtbl -> RequestService(This,serviceId,qualifiers,pTransId)

#define IAccSession_ConfirmAccount(This,pTransId)	\
    (This)->lpVtbl -> ConfirmAccount(This,pTransId)

#define IAccSession_CancelEvent(This)	\
    (This)->lpVtbl -> CancelEvent(This)

#define IAccSession_AddCapabilities(This,caps)	\
    (This)->lpVtbl -> AddCapabilities(This,caps)

#define IAccSession_RemoveCapabilities(This,caps)	\
    (This)->lpVtbl -> RemoveCapabilities(This,caps)

#define IAccSession_VerifyPassword(This,password,verified)	\
    (This)->lpVtbl -> VerifyPassword(This,password,verified)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccSession_get_ClientInfo_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [retval][out] */ IAccClientInfo __RPC_FAR *__RPC_FAR *ppiAccClientInfo);


void __RPC_STUB IAccSession_get_ClientInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccSession_put_PrefsHook_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ IAccPreferencesHook __RPC_FAR *piAccPrefsHook);


void __RPC_STUB IAccSession_put_PrefsHook_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccSession_put_Identity_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ xp_kstr identity);


void __RPC_STUB IAccSession_put_Identity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_SignOn_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ xp_kstr password);


void __RPC_STUB IAccSession_SignOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_SetSecurIdKey_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ xp_kstr key);


void __RPC_STUB IAccSession_SetSecurIdKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_SignOff_Proxy( 
    IAccSession __RPC_FAR * This);


void __RPC_STUB IAccSession_SignOff_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccSession_get_State_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [retval][out] */ AccSessionState __RPC_FAR *pState);


void __RPC_STUB IAccSession_get_State_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccSession_get_Identity_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [retval][out] */ xp_str __RPC_FAR *pIdentity);


void __RPC_STUB IAccSession_get_Identity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccSession_get_OtherInstances_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [retval][out] */ xp_variant __RPC_FAR *pInstances);


void __RPC_STUB IAccSession_get_OtherInstances_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccSession_get_BuddyList_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [retval][out] */ IAccBuddyList __RPC_FAR *__RPC_FAR *ppiBuddies);


void __RPC_STUB IAccSession_get_BuddyList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccSession_get_SecurityManager_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [retval][out] */ IAccSecurityManager __RPC_FAR *__RPC_FAR *ppiSecurityManager);


void __RPC_STUB IAccSession_get_SecurityManager_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccSession_get_PluginManager_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [retval][out] */ IAccPluginManager __RPC_FAR *__RPC_FAR *ppiPluginManager);


void __RPC_STUB IAccSession_get_PluginManager_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccSession_get_Prefs_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [retval][out] */ IAccPreferences __RPC_FAR *__RPC_FAR *prefs);


void __RPC_STUB IAccSession_get_Prefs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccSession_get_Property_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ AccSessionProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccSession_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccSession_put_Property_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ AccSessionProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccSession_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_GetSecondaryManager_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ xp_int serviceId,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *ppiManager);


void __RPC_STUB IAccSession_GetSecondaryManager_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_GetSecondarySessions_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ xp_int serviceId,
    /* [retval][out] */ xp_variant __RPC_FAR *pSessions);


void __RPC_STUB IAccSession_GetSecondarySessions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_CreateGroup_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ xp_kstr name,
    /* [retval][out] */ IAccGroup __RPC_FAR *__RPC_FAR *group);


void __RPC_STUB IAccSession_CreateGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_CreateUser_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ xp_kstr name,
    /* [retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *user);


void __RPC_STUB IAccSession_CreateUser_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_CreateImSession_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ xp_kstr userName,
    /* [defaultvalue][in] */ AccImSessionType sessionType,
    /* [retval][out] */ IAccImSession __RPC_FAR *__RPC_FAR *imSession);


void __RPC_STUB IAccSession_CreateImSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_CreateChatSession_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [defaultvalue][in] */ xp_kstr roomName,
    /* [defaultvalue][in] */ xp_int exchange,
    /* [defaultvalue][in] */ xp_int instance,
    /* [retval][out] */ IAccImSession __RPC_FAR *__RPC_FAR *imSession);


void __RPC_STUB IAccSession_CreateChatSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_CreateCustomSession_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ xp_kstr uuid,
    /* [retval][out] */ IAccCustomSession __RPC_FAR *__RPC_FAR *customSession);


void __RPC_STUB IAccSession_CreateCustomSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_CreateIm_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [defaultvalue][in] */ xp_kstr text,
    /* [defaultvalue][in] */ xp_kstr type,
    /* [retval][out] */ IAccIm __RPC_FAR *__RPC_FAR *ppiIm);


void __RPC_STUB IAccSession_CreateIm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_CreateBartItem_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ AccBartItemType type,
    /* [in] */ xp_kstr id,
    /* [retval][out] */ IAccBartItem __RPC_FAR *__RPC_FAR *ppiAccBartItem);


void __RPC_STUB IAccSession_CreateBartItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_CreateDirEntry_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [retval][out] */ IAccDirEntry __RPC_FAR *__RPC_FAR *ppiAccDirEntry);


void __RPC_STUB IAccSession_CreateDirEntry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_CreateStream_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ xp_kstr specifier,
    /* [retval][out] */ IAccStream __RPC_FAR *__RPC_FAR *ppiStream);


void __RPC_STUB IAccSession_CreateStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_LookupUsers_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ xp_kvariant users,
    /* [retval][out] */ AccTransId __RPC_FAR *pTransId);


void __RPC_STUB IAccSession_LookupUsers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_SearchDirectory_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ xp_kvariant query,
    /* [retval][out] */ AccTransId __RPC_FAR *pTransId);


void __RPC_STUB IAccSession_SearchDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_SendInviteMail_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ xp_kstr email,
    /* [defaultvalue][in] */ xp_kstr message,
    /* [retval][out] */ AccTransId __RPC_FAR *pTransId);


void __RPC_STUB IAccSession_SendInviteMail_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_RequestService_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ xp_kstr serviceId,
    /* [in] */ xp_kvariant qualifiers,
    /* [retval][out] */ AccTransId __RPC_FAR *pTransId);


void __RPC_STUB IAccSession_RequestService_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_ConfirmAccount_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [retval][out] */ AccTransId __RPC_FAR *pTransId);


void __RPC_STUB IAccSession_ConfirmAccount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_CancelEvent_Proxy( 
    IAccSession __RPC_FAR * This);


void __RPC_STUB IAccSession_CancelEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_AddCapabilities_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ xp_kvariant caps);


void __RPC_STUB IAccSession_AddCapabilities_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_RemoveCapabilities_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ xp_kvariant caps);


void __RPC_STUB IAccSession_RemoveCapabilities_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSession_VerifyPassword_Proxy( 
    IAccSession __RPC_FAR * This,
    /* [in] */ xp_kstr password,
    /* [retval][out] */ xp_vbool __RPC_FAR *verified);


void __RPC_STUB IAccSession_VerifyPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccSession_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccSession_0370 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccSession)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_Identity(IAccSession* pi, xp_str* px) { return get_Property(pi, AccSessionProp_Identity, px); };
static inline HRESULT get_LinkedIdentities(IAccSession* pi, xp_array** px) { return get_Property(pi, AccSessionProp_LinkedIdentities, px); };
static inline HRESULT get_InstanceId(IAccSession* pi, xp_s32* px) { return get_Property(pi, AccSessionProp_InstanceId, px); };
static inline HRESULT get_OnlineTime(IAccSession* pi, xp_s32* px) { return get_Property(pi, AccSessionProp_OnlineTime, px); };
static inline HRESULT get_IpAddress(IAccSession* pi, xp_str* px) { return get_Property(pi, AccSessionProp_IpAddress, px); };
static inline HRESULT get_Port(IAccSession* pi, xp_s32* px) { return get_Property(pi, AccSessionProp_Port, px); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_Profile(IAccSession* pi, IAccIm** px) { return get_Property(pi, AccSessionProp_Profile, IID_IAccIm, px); };
#endif
static inline HRESULT put_Profile(IAccSession* pi, IAccIm* x) { return put_Property(pi, AccSessionProp_Profile, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_AwayMessage(IAccSession* pi, IAccIm** px) { return get_Property(pi, AccSessionProp_AwayMessage, IID_IAccIm, px); };
#endif
static inline HRESULT put_AwayMessage(IAccSession* pi, IAccIm* x) { return put_Property(pi, AccSessionProp_AwayMessage, x); };
static inline HRESULT get_Capabilities(IAccSession* pi, xp_array** px) { return get_Property(pi, AccSessionProp_Capabilities, px); };
static inline HRESULT get_AppearOffline(IAccSession* pi, xp_bool* px) { return get_Property(pi, AccSessionProp_AppearOffline, px); };
static inline HRESULT put_AppearOffline(IAccSession* pi, xp_bool x) { return put_Property(pi, AccSessionProp_AppearOffline, x); };
static inline HRESULT get_ImForwardingCapable(IAccSession* pi, xp_bool* px) { return get_Property(pi, AccSessionProp_ImForwardingCapable, px); };
static inline HRESULT get_ImForwardingActive(IAccSession* pi, xp_bool* px) { return get_Property(pi, AccSessionProp_ImForwardingActive, px); };
static inline HRESULT put_ImForwardingActive(IAccSession* pi, xp_bool x) { return put_Property(pi, AccSessionProp_ImForwardingActive, x); };
static inline HRESULT get_SecondsOfInactivityBeforeIdleState(IAccSession* pi, xp_s32* px) { return get_Property(pi, AccSessionProp_SecondsOfInactivityBeforeIdleState, px); };
static inline HRESULT put_SecondsOfInactivityBeforeIdleState(IAccSession* pi, xp_s32 x) { return put_Property(pi, AccSessionProp_SecondsOfInactivityBeforeIdleState, x); };
static inline HRESULT get_SecondsSinceUserActivity(IAccSession* pi, xp_s32* px) { return get_Property(pi, AccSessionProp_SecondsSinceUserActivity, px); };
static inline HRESULT put_SecondsSinceUserActivity(IAccSession* pi, xp_s32 x) { return put_Property(pi, AccSessionProp_SecondsSinceUserActivity, x); };
static inline HRESULT get_SecondsRemainingUntilIdleState(IAccSession* pi, xp_s32* px) { return get_Property(pi, AccSessionProp_SecondsRemainingUntilIdleState, px); };
static inline HRESULT put_SecondsRemainingUntilIdleState(IAccSession* pi, xp_s32 x) { return put_Property(pi, AccSessionProp_SecondsRemainingUntilIdleState, x); };
static inline HRESULT get_UserIdle(IAccSession* pi, xp_bool* px) { return get_Property(pi, AccSessionProp_UserIdle, px); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_BetaUpgradeInfo(IAccSession* pi, IAccUpgradeInfo** px) { return get_Property(pi, AccSessionProp_BetaUpgradeInfo, IID_IAccUpgradeInfo, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_UpgradeInfo(IAccSession* pi, IAccUpgradeInfo** px) { return get_Property(pi, AccSessionProp_UpgradeInfo, IID_IAccUpgradeInfo, px); };
#endif
static inline HRESULT get_UpgradeRecommended(IAccSession* pi, xp_bool* px) { return get_Property(pi, AccSessionProp_UpgradeRecommended, px); };
static inline HRESULT get_HostTime(IAccSession* pi, xp_date* px) { return get_PropertyDate(pi, AccSessionProp_HostTime, px); };
static inline HRESULT get_ChangePasswordUrl(IAccSession* pi, xp_str* px) { return get_Property(pi, AccSessionProp_ChangePasswordUrl, px); };
static inline HRESULT get_UiFlags(IAccSession* pi, xp_u32* px) { return get_Property(pi, AccSessionProp_UiFlags, px); };
static inline HRESULT get_InstanceFlags(IAccSession* pi, xp_u32* px) { return get_Property(pi, AccSessionProp_InstanceFlags, px); };
static inline HRESULT get_ParentalControls(IAccSession* pi, xp_u32* px) { return get_Property(pi, AccSessionProp_ParentalControls, px); };
static inline HRESULT get_Subscriptions(IAccSession* pi, xp_u32* px) { return get_Property(pi, AccSessionProp_Subscriptions, px); };
static inline HRESULT get_MaxProfileLength(IAccSession* pi, xp_s32* px) { return get_Property(pi, AccSessionProp_MaxProfileLength, px); };
static inline HRESULT get_MaxAwayMessageLength(IAccSession* pi, xp_s32* px) { return get_Property(pi, AccSessionProp_MaxAwayMessageLength, px); };
static inline HRESULT get_MaxChatRoomNameLength(IAccSession* pi, xp_s32* px) { return get_Property(pi, AccSessionProp_MaxChatRoomNameLength, px); };
static inline HRESULT get_MaxInvitationLength(IAccSession* pi, xp_s32* px) { return get_Property(pi, AccSessionProp_MaxInvitationLength, px); };
static inline HRESULT get_MaxLookupUserCount(IAccSession* pi, xp_s32* px) { return get_Property(pi, AccSessionProp_MaxLookupUserCount, px); };
static inline HRESULT get_MaxUserLookups(IAccSession* pi, xp_s32* px) { return get_Property(pi, AccSessionProp_MaxUserLookups, px); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_LinkedMasterSession(IAccSession* pi, IAccSession** px) { return get_Property(pi, AccSessionProp_LinkedMasterSession, IID_IAccSession, px); };
#endif
static inline HRESULT put_LinkedMasterSession(IAccSession* pi, IAccSession* x) { return put_Property(pi, AccSessionProp_LinkedMasterSession, x); };
static inline HRESULT get_MaxChatSessionCount(IAccSession* pi, xp_s32* px) { return get_Property(pi, AccSessionProp_MaxChatSessionCount, px); };
static inline HRESULT get_MaxChatSessions(IAccSession* pi, xp_s32* px) { return get_Property(pi, AccSessionProp_MaxChatSessions, px); };
static inline HRESULT get_MaxPermittedUserCount(IAccSession* pi, xp_s32* px) { return get_Property(pi, AccSessionProp_MaxPermittedUserCount, px); };
static inline HRESULT get_MaxDeniedUserCount(IAccSession* pi, xp_s32* px) { return get_Property(pi, AccSessionProp_MaxDeniedUserCount, px); };
static inline HRESULT get_LocalIpAddress(IAccSession* pi, xp_str* px) { return get_Property(pi, AccSessionProp_LocalIpAddress, px); };
static inline HRESULT get_MaxFavoriteLocationCount(IAccSession* pi, xp_s32* px) { return get_Property(pi, AccSessionProp_MaxFavoriteLocationCount, px); };
static inline HRESULT get_Plugins(IAccSession* pi, xp_array** px) { return get_Property(pi, AccSessionProp_Plugins, px); };
static inline HRESULT put_Plugins(IAccSession* pi, xp_array* x) { return put_Property(pi, AccSessionProp_Plugins, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_StoredImManager(IAccSession* pi, IAccStoredImManager** px) { return get_Property(pi, AccSessionProp_StoredImManager, IID_IAccStoredImManager, px); };
#endif
static inline HRESULT get_PhoneNumber(IAccSession* pi, xp_str* px) { return get_Property(pi, AccSessionProp_PhoneNumber, px); };
static inline HRESULT put_Pause(IAccSession* pi, xp_bool x) { return put_Property(pi, AccSessionProp_Pause, x); };
static inline HRESULT put_Credentials(IAccSession* pi, xp_kvariant x) { return put_Property(pi, AccSessionProp_Credentials, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_BartCacheManager(IAccSession* pi, IAccBartCacheManager** px) { return get_Property(pi, AccSessionProp_BartCacheManager, IID_IAccBartCacheManager, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_SmallIcon(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_SmallIcon, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_SmallIcon(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_SmallIcon, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_BuddyIcon(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_BuddyIcon, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_BuddyIcon(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_BuddyIcon, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_StatusText(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_StatusText, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_StatusText(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_StatusText, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_ArriveSound(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_ArriveSound, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_ArriveSound(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_ArriveSound, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_RichName(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_RichName, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_RichName(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_RichName, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_SuperIcon(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_SuperIcon, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_SuperIcon(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_SuperIcon, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_RadioStation(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_RadioStation, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_RadioStation(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_RadioStation, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_SuperIconTrigger(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_SuperIconTrigger, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_SuperIconTrigger(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_SuperIconTrigger, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_StatusTextLink(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_StatusTextLink, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_StatusTextLink(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_StatusTextLink, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_E911Location(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_E911Location, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_E911Location(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_E911Location, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_Location(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_Location, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_Location(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_Location, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_BigIcon(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_BigIcon, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_BigIcon(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_BigIcon, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_StatusTextTimestamp(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_StatusTextTimestamp, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_AvTrack(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_AvTrack, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_AvTrack(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_AvTrack, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_DepartSound(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_DepartSound, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_DepartSound(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_DepartSound, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_Wallpaper(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_Wallpaper, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_Wallpaper(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_Wallpaper, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_Badge(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_Badge, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_Badge(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_Badge, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_FlashWallpaper(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_FlashWallpaper, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_FlashWallpaper(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_FlashWallpaper, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_ImmersiveWallpaper(IAccSession* pi, IAccBartItem** px) { return get_Property(pi, AccSessionProp_ImmersiveWallpaper, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_ImmersiveWallpaper(IAccSession* pi, IAccBartItem* x) { return put_Property(pi, AccSessionProp_ImmersiveWallpaper, x); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccSession_0370_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccSession_0370_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
