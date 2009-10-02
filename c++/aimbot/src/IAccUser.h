/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Feb 27 15:59:25 2008
 */
/* Compiler settings for C:\dev\cvs\client\aimcc\idl\IAccUser.idl:
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

#ifndef __IAccUser_h__
#define __IAccUser_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccUser_FWD_DEFINED__
#define __IAccUser_FWD_DEFINED__
typedef interface IAccUser IAccUser;
#endif 	/* __IAccUser_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccSession.h"


#ifndef __IAccUser_INTERFACE_DEFINED__
#define __IAccUser_INTERFACE_DEFINED__

/* interface IAccUser */
/* [object][dual][uuid] */ 

typedef 
enum AccUserState
    {	AccUserState_Unknown	= -1,
	AccUserState_Offline	= 0,
	AccUserState_Online	= 1,
	AccUserState_Idle	= 2,
	AccUserState_Away	= 3
    }	AccUserState;

typedef 
enum AccUserFlags
    {	AccUserFlags_Unconfirmed	= 0x1,
	AccUserFlags_AOL	= 0x4,
	AccUserFlags_InternetFree	= 0x10,
	AccUserFlags_ICQ	= 0x40,
	AccUserFlags_Wireless	= 0x80,
	AccUserFlags_Internal	= 0x100,
	AccUserFlags_ImForwarding	= 0x200,
	AccUserFlags_Bot	= 0x400,
	AccUserFlags_Beast	= 0x800,
	AccUserFlags_OneWayForwarding	= 0x1000,
	AccUserFlags_Official	= 0x2000,
	AccUserFlags_BuddyMatchDirect	= 0x10000,
	AccUserFlags_BuddyMatchIndirect	= 0x20000
    }	AccUserFlags;

typedef 
enum AccUserProp
    {	AccUserProp_Session	= -1,
	AccUserProp_Name	= AccUserProp_Session + 1,
	AccUserProp_FriendlyName	= 2,
	AccUserProp_State	= AccUserProp_FriendlyName + 1,
	AccUserProp_Flags	= AccUserProp_State + 1,
	AccUserProp_Blocked	= AccUserProp_Flags + 1,
	AccUserProp_Ignored	= AccUserProp_Blocked + 1,
	AccUserProp_OnlineTime	= AccUserProp_Ignored + 1,
	AccUserProp_IdleTime	= AccUserProp_OnlineTime + 1,
	AccUserProp_WarningPercent	= AccUserProp_IdleTime + 1,
	AccUserProp_SmsChargeback	= AccUserProp_WarningPercent + 1,
	AccUserProp_EmailAddress	= AccUserProp_SmsChargeback + 1,
	AccUserProp_Note	= AccUserProp_EmailAddress + 1,
	AccUserProp_Frequency	= AccUserProp_Note + 1,
	AccUserProp_InBuddyList	= AccUserProp_Frequency + 1,
	AccUserProp_TrustedAsBuddy	= AccUserProp_InBuddyList + 1,
	AccUserProp_BuddyFeedUpdateTime	= AccUserProp_TrustedAsBuddy + 1,
	AccUserProp_BuddyFeedViewTime	= AccUserProp_BuddyFeedUpdateTime + 1,
	AccUserProp_BuddyFeedUrl	= AccUserProp_BuddyFeedViewTime + 1,
	AccUserProp_Profile	= 100,
	AccUserProp_AwayMessage	= AccUserProp_Profile + 1,
	AccUserProp_Capabilities	= AccUserProp_AwayMessage + 1,
	AccUserProp_Certificate	= AccUserProp_Capabilities + 1,
	AccUserProp_HtmlInfo	= 110,
	AccUserProp_DirEntry	= 200,
	AccUserProp_BartBase	= 10000,
	AccUserProp_SmallIcon	= AccUserProp_BartBase + 0,
	AccUserProp_BuddyIcon	= AccUserProp_BartBase + 1,
	AccUserProp_StatusText	= AccUserProp_BartBase + 2,
	AccUserProp_ArriveSound	= AccUserProp_BartBase + 3,
	AccUserProp_RichName	= AccUserProp_BartBase + 4,
	AccUserProp_SuperIcon	= AccUserProp_BartBase + 5,
	AccUserProp_RadioStation	= AccUserProp_BartBase + 6,
	AccUserProp_SuperIconTrigger	= AccUserProp_BartBase + 7,
	AccUserProp_StatusTextLink	= AccUserProp_BartBase + 9,
	AccUserProp_E911Location	= AccUserProp_BartBase + 10,
	AccUserProp_Location	= AccUserProp_BartBase + 11,
	AccUserProp_BigIcon	= AccUserProp_BartBase + 12,
	AccUserProp_StatusTextTimestamp	= AccUserProp_BartBase + 13,
	AccUserProp_AvTrack	= AccUserProp_BartBase + 15,
	AccUserProp_DepartSound	= AccUserProp_BartBase + 96,
	AccUserProp_Wallpaper	= AccUserProp_BartBase + 129,
	AccUserProp_Badge	= AccUserProp_BartBase + 132,
	AccUserProp_FlashWallpaper	= AccUserProp_BartBase + 136,
	AccUserProp_ImmersiveWallpaper	= AccUserProp_BartBase + 137,
	AccUserProp_BartMax	= AccUserProp_BartBase + 4096,
	AccUserProp_MaxFriendlyNameLength	= 100000,
	AccUserProp_MaxEmailAddressLength	= AccUserProp_MaxFriendlyNameLength + 1,
	AccUserProp_MaxNoteLength	= AccUserProp_MaxEmailAddressLength + 1
    }	AccUserProp;


EXTERN_C const IID IID_IAccUser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("82047114-bed0-11d6-9157-001083341cf5")
    IAccUser : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ xp_str __RPC_FAR *name) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Groups( 
            /* [retval][out] */ xp_variant __RPC_FAR *groups) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccUserProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccUserProp property,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestProperty( 
            /* [in] */ AccUserProp property,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Report( 
            /* [defaultvalue][in] */ xp_vbool notify,
            /* [defaultvalue][in] */ xp_kstr reason,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccUserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccUser __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccUser __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccUser __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccUser __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccUser __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccUser __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccUser __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IAccUser __RPC_FAR * This,
            /* [retval][out] */ xp_str __RPC_FAR *name);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Groups )( 
            IAccUser __RPC_FAR * This,
            /* [retval][out] */ xp_variant __RPC_FAR *groups);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccUser __RPC_FAR * This,
            /* [in] */ AccUserProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccUser __RPC_FAR * This,
            /* [in] */ AccUserProp property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestProperty )( 
            IAccUser __RPC_FAR * This,
            /* [in] */ AccUserProp property,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Report )( 
            IAccUser __RPC_FAR * This,
            /* [defaultvalue][in] */ xp_vbool notify,
            /* [defaultvalue][in] */ xp_kstr reason,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        END_INTERFACE
    } IAccUserVtbl;

    interface IAccUser
    {
        CONST_VTBL struct IAccUserVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccUser_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccUser_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccUser_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccUser_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccUser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccUser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccUser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccUser_get_Name(This,name)	\
    (This)->lpVtbl -> get_Name(This,name)

#define IAccUser_get_Groups(This,groups)	\
    (This)->lpVtbl -> get_Groups(This,groups)

#define IAccUser_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccUser_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccUser_RequestProperty(This,property,pTransId)	\
    (This)->lpVtbl -> RequestProperty(This,property,pTransId)

#define IAccUser_Report(This,notify,reason,pTransId)	\
    (This)->lpVtbl -> Report(This,notify,reason,pTransId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IAccUser_get_Name_Proxy( 
    IAccUser __RPC_FAR * This,
    /* [retval][out] */ xp_str __RPC_FAR *name);


void __RPC_STUB IAccUser_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccUser_get_Groups_Proxy( 
    IAccUser __RPC_FAR * This,
    /* [retval][out] */ xp_variant __RPC_FAR *groups);


void __RPC_STUB IAccUser_get_Groups_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccUser_get_Property_Proxy( 
    IAccUser __RPC_FAR * This,
    /* [in] */ AccUserProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccUser_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccUser_put_Property_Proxy( 
    IAccUser __RPC_FAR * This,
    /* [in] */ AccUserProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccUser_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccUser_RequestProperty_Proxy( 
    IAccUser __RPC_FAR * This,
    /* [in] */ AccUserProp property,
    /* [retval][out] */ AccTransId __RPC_FAR *pTransId);


void __RPC_STUB IAccUser_RequestProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccUser_Report_Proxy( 
    IAccUser __RPC_FAR * This,
    /* [defaultvalue][in] */ xp_vbool notify,
    /* [defaultvalue][in] */ xp_kstr reason,
    /* [retval][out] */ AccTransId __RPC_FAR *pTransId);


void __RPC_STUB IAccUser_Report_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccUser_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccUser_0370 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccUser)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_Session(IAccUser* pi, IAccSession** px) { return get_Property(pi, AccUserProp_Session, IID_IAccSession, px); };
#endif
static inline HRESULT get_Name(IAccUser* pi, xp_str* px) { return get_Property(pi, AccUserProp_Name, px); };
static inline HRESULT get_FriendlyName(IAccUser* pi, xp_str* px) { return get_Property(pi, AccUserProp_FriendlyName, px); };
static inline HRESULT put_FriendlyName(IAccUser* pi, xp_kstr x) { return put_Property(pi, AccUserProp_FriendlyName, x); };
static inline HRESULT get_State(IAccUser* pi, AccUserState* px) { return get_Property(pi, AccUserProp_State, (xp_s32*)px); };
static inline HRESULT get_Flags(IAccUser* pi, xp_u32* px) { return get_Property(pi, AccUserProp_Flags, px); };
static inline HRESULT get_Blocked(IAccUser* pi, xp_bool* px) { return get_Property(pi, AccUserProp_Blocked, px); };
static inline HRESULT put_Blocked(IAccUser* pi, xp_bool x) { return put_Property(pi, AccUserProp_Blocked, x); };
static inline HRESULT get_Ignored(IAccUser* pi, xp_bool* px) { return get_Property(pi, AccUserProp_Ignored, px); };
static inline HRESULT put_Ignored(IAccUser* pi, xp_bool x) { return put_Property(pi, AccUserProp_Ignored, x); };
static inline HRESULT get_OnlineTime(IAccUser* pi, xp_s32* px) { return get_Property(pi, AccUserProp_OnlineTime, px); };
static inline HRESULT get_IdleTime(IAccUser* pi, xp_s32* px) { return get_Property(pi, AccUserProp_IdleTime, px); };
static inline HRESULT get_WarningPercent(IAccUser* pi, xp_s32* px) { return get_Property(pi, AccUserProp_WarningPercent, px); };
static inline HRESULT get_SmsChargeback(IAccUser* pi, xp_bool* px) { return get_Property(pi, AccUserProp_SmsChargeback, px); };
static inline HRESULT get_EmailAddress(IAccUser* pi, xp_str* px) { return get_Property(pi, AccUserProp_EmailAddress, px); };
static inline HRESULT put_EmailAddress(IAccUser* pi, xp_kstr x) { return put_Property(pi, AccUserProp_EmailAddress, x); };
static inline HRESULT get_Note(IAccUser* pi, xp_str* px) { return get_Property(pi, AccUserProp_Note, px); };
static inline HRESULT put_Note(IAccUser* pi, xp_kstr x) { return put_Property(pi, AccUserProp_Note, x); };
static inline HRESULT get_Frequency(IAccUser* pi, xp_double* px) { return get_PropertyDouble(pi, AccUserProp_Frequency, px); };
static inline HRESULT get_InBuddyList(IAccUser* pi, xp_bool* px) { return get_Property(pi, AccUserProp_InBuddyList, px); };
static inline HRESULT get_TrustedAsBuddy(IAccUser* pi, xp_bool* px) { return get_Property(pi, AccUserProp_TrustedAsBuddy, px); };
static inline HRESULT get_BuddyFeedUpdateTime(IAccUser* pi, xp_date* px) { return get_PropertyDate(pi, AccUserProp_BuddyFeedUpdateTime, px); };
static inline HRESULT get_BuddyFeedViewTime(IAccUser* pi, xp_date* px) { return get_PropertyDate(pi, AccUserProp_BuddyFeedViewTime, px); };
static inline HRESULT put_BuddyFeedViewTime(IAccUser* pi, xp_date x) { return put_PropertyDate(pi, AccUserProp_BuddyFeedViewTime, x); };
static inline HRESULT get_BuddyFeedUrl(IAccUser* pi, xp_str* px) { return get_Property(pi, AccUserProp_BuddyFeedUrl, px); };
static inline HRESULT get_Capabilities(IAccUser* pi, xp_array** px) { return get_Property(pi, AccUserProp_Capabilities, px); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_Certificate(IAccUser* pi, IAccCertificate** px) { return get_Property(pi, AccUserProp_Certificate, IID_IAccCertificate, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_SmallIcon(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_SmallIcon, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_BuddyIcon(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_BuddyIcon, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_StatusText(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_StatusText, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_ArriveSound(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_ArriveSound, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_RichName(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_RichName, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_SuperIcon(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_SuperIcon, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_RadioStation(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_RadioStation, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_SuperIconTrigger(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_SuperIconTrigger, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_StatusTextLink(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_StatusTextLink, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_E911Location(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_E911Location, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_Location(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_Location, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_BigIcon(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_BigIcon, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_StatusTextTimestamp(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_StatusTextTimestamp, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_AvTrack(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_AvTrack, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_DepartSound(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_DepartSound, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_Wallpaper(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_Wallpaper, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_Badge(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_Badge, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_FlashWallpaper(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_FlashWallpaper, IID_IAccBartItem, px); };
#endif
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_ImmersiveWallpaper(IAccUser* pi, IAccBartItem** px) { return get_Property(pi, AccUserProp_ImmersiveWallpaper, IID_IAccBartItem, px); };
#endif
static inline HRESULT get_MaxFriendlyNameLength(IAccUser* pi, xp_s32* px) { return get_Property(pi, AccUserProp_MaxFriendlyNameLength, px); };
static inline HRESULT get_MaxEmailAddressLength(IAccUser* pi, xp_s32* px) { return get_Property(pi, AccUserProp_MaxEmailAddressLength, px); };
static inline HRESULT get_MaxNoteLength(IAccUser* pi, xp_s32* px) { return get_Property(pi, AccUserProp_MaxNoteLength, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccUser_0370_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccUser_0370_v0_0_s_ifspec;

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
