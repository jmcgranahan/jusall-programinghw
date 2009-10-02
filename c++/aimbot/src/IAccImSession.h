/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Jan 24 09:34:29 2008
 */
/* Compiler settings for C:\dev\cvs\client\aimcc\idl\IAccImSession.idl:
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

#ifndef __IAccImSession_h__
#define __IAccImSession_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccImSession_FWD_DEFINED__
#define __IAccImSession_FWD_DEFINED__
typedef interface IAccImSession IAccImSession;
#endif 	/* __IAccImSession_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccSecondarySession.h"
#include "IAccIm.h"


#ifndef __IAccImSession_INTERFACE_DEFINED__
#define __IAccImSession_INTERFACE_DEFINED__

/* interface IAccImSession */
/* [object][dual][uuid] */ 

typedef 
enum AccImSessionType
    {	AccImSessionType_Im	= 0,
	AccImSessionType_DirectIm	= AccImSessionType_Im + 1,
	AccImSessionType_Chat	= AccImSessionType_DirectIm + 1
    }	AccImSessionType;

typedef 
enum AccImInputState
    {	AccImInputState_None	= 0,
	AccImInputState_NotEmpty	= 1,
	AccImInputState_Typing	= 2,
	AccImInputState_Recording	= 3
    }	AccImInputState;

typedef 
enum AccRateState
    {	AccRateState_Unknown	= 0,
	AccRateState_Limit	= 1,
	AccRateState_Alert	= 2,
	AccRateState_Clear	= 3
    }	AccRateState;

typedef 
enum AccImExchange
    {	AccImExchange_PrivateAutomatic	= 0,
	AccImExchange_PrivateSecure	= 2,
	AccImExchange_PrivateNonSecure	= 4
    }	AccImExchange;

typedef 
enum AccImSessionProp
    {	AccImSessionProp_SessionType	= 1000,
	AccImSessionProp_SessionTypeProposed	= AccImSessionProp_SessionType + 1,
	AccImSessionProp_ChatExchange	= AccImSessionProp_SessionTypeProposed + 1,
	AccImSessionProp_ChatRoomName	= AccImSessionProp_ChatExchange + 1,
	AccImSessionProp_ChatRoomFullyQualifiedName	= AccImSessionProp_ChatRoomName + 1,
	AccImSessionProp_ChatInstance	= AccImSessionProp_ChatRoomFullyQualifiedName + 1,
	AccImSessionProp_CanStop	= AccImSessionProp_ChatInstance + 1,
	AccImSessionProp_OutgoingPersonality	= AccImSessionProp_CanStop + 1,
	AccImSessionProp_MaxImLength	= AccImSessionProp_OutgoingPersonality + 1,
	AccImSessionProp_MaxVisibleImLength	= AccImSessionProp_MaxImLength + 1,
	AccImSessionProp_RateState	= AccImSessionProp_MaxVisibleImLength + 1,
	AccImSessionProp_PromoteCentralized	= AccImSessionProp_RateState + 1,
	AccImSessionProp_LocalWantsRtim	= AccImSessionProp_PromoteCentralized + 1,
	AccImSessionProp_RemoteWantsRtim	= AccImSessionProp_LocalWantsRtim + 1,
	AccImSessionProp_QueuedImCount	= AccImSessionProp_RemoteWantsRtim + 1
    }	AccImSessionProp;


EXTERN_C const IID IID_IAccImSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6858bdee-c081-11d6-9158-001083341cf5")
    IAccImSession : public IAccSecondarySession
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property_( 
            /* [in] */ AccImSessionProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property_( 
            /* [in] */ AccImSessionProp property,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_InputState( 
            /* [in] */ AccImInputState state) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendIm( 
            /* [in] */ IAccIm __RPC_FAR *im) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SegmentIm( 
            /* [in] */ IAccIm __RPC_FAR *im) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProposeChange( 
            /* [in] */ AccImSessionType sessionType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopRecv( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopSend( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccImSessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccImSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccImSession __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccImSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccImSession __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccImSession __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccImSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccImSession __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ServiceId )( 
            IAccImSession __RPC_FAR * This,
            /* [retval][out] */ AccSecondarySessionServiceId __RPC_FAR *pId);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccImSession __RPC_FAR * This,
            /* [in] */ xp_int property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccImSession __RPC_FAR * This,
            /* [in] */ xp_int property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Accept )( 
            IAccImSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reject )( 
            IAccImSession __RPC_FAR * This,
            /* [defaultvalue][in] */ xp_int reason);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invite )( 
            IAccImSession __RPC_FAR * This,
            /* [in] */ xp_kstr invitee,
            /* [in] */ xp_kstr invitation,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CancelProposal )( 
            IAccImSession __RPC_FAR * This,
            /* [in] */ xp_kstr invitee);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Eject )( 
            IAccImSession __RPC_FAR * This,
            /* [in] */ xp_kstr userName,
            /* [defaultvalue][in] */ xp_kstr reason,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EndSession )( 
            IAccImSession __RPC_FAR * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property_ )( 
            IAccImSession __RPC_FAR * This,
            /* [in] */ AccImSessionProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property_ )( 
            IAccImSession __RPC_FAR * This,
            /* [in] */ AccImSessionProp property,
            /* [in] */ xp_kvariant value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_InputState )( 
            IAccImSession __RPC_FAR * This,
            /* [in] */ AccImInputState state);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SendIm )( 
            IAccImSession __RPC_FAR * This,
            /* [in] */ IAccIm __RPC_FAR *im);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SegmentIm )( 
            IAccImSession __RPC_FAR * This,
            /* [in] */ IAccIm __RPC_FAR *im);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ProposeChange )( 
            IAccImSession __RPC_FAR * This,
            /* [in] */ AccImSessionType sessionType);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopRecv )( 
            IAccImSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopSend )( 
            IAccImSession __RPC_FAR * This);
        
        END_INTERFACE
    } IAccImSessionVtbl;

    interface IAccImSession
    {
        CONST_VTBL struct IAccImSessionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccImSession_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccImSession_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccImSession_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccImSession_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccImSession_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccImSession_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccImSession_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccImSession_get_ServiceId(This,pId)	\
    (This)->lpVtbl -> get_ServiceId(This,pId)

#define IAccImSession_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccImSession_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccImSession_Accept(This)	\
    (This)->lpVtbl -> Accept(This)

#define IAccImSession_Reject(This,reason)	\
    (This)->lpVtbl -> Reject(This,reason)

#define IAccImSession_Invite(This,invitee,invitation,pTransId)	\
    (This)->lpVtbl -> Invite(This,invitee,invitation,pTransId)

#define IAccImSession_CancelProposal(This,invitee)	\
    (This)->lpVtbl -> CancelProposal(This,invitee)

#define IAccImSession_Eject(This,userName,reason,pTransId)	\
    (This)->lpVtbl -> Eject(This,userName,reason,pTransId)

#define IAccImSession_EndSession(This)	\
    (This)->lpVtbl -> EndSession(This)


#define IAccImSession_get_Property_(This,property,value)	\
    (This)->lpVtbl -> get_Property_(This,property,value)

#define IAccImSession_put_Property_(This,property,value)	\
    (This)->lpVtbl -> put_Property_(This,property,value)

#define IAccImSession_put_InputState(This,state)	\
    (This)->lpVtbl -> put_InputState(This,state)

#define IAccImSession_SendIm(This,im)	\
    (This)->lpVtbl -> SendIm(This,im)

#define IAccImSession_SegmentIm(This,im)	\
    (This)->lpVtbl -> SegmentIm(This,im)

#define IAccImSession_ProposeChange(This,sessionType)	\
    (This)->lpVtbl -> ProposeChange(This,sessionType)

#define IAccImSession_StopRecv(This)	\
    (This)->lpVtbl -> StopRecv(This)

#define IAccImSession_StopSend(This)	\
    (This)->lpVtbl -> StopSend(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccImSession_get_Property__Proxy( 
    IAccImSession __RPC_FAR * This,
    /* [in] */ AccImSessionProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccImSession_get_Property__Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccImSession_put_Property__Proxy( 
    IAccImSession __RPC_FAR * This,
    /* [in] */ AccImSessionProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccImSession_put_Property__Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccImSession_put_InputState_Proxy( 
    IAccImSession __RPC_FAR * This,
    /* [in] */ AccImInputState state);


void __RPC_STUB IAccImSession_put_InputState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccImSession_SendIm_Proxy( 
    IAccImSession __RPC_FAR * This,
    /* [in] */ IAccIm __RPC_FAR *im);


void __RPC_STUB IAccImSession_SendIm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccImSession_SegmentIm_Proxy( 
    IAccImSession __RPC_FAR * This,
    /* [in] */ IAccIm __RPC_FAR *im);


void __RPC_STUB IAccImSession_SegmentIm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccImSession_ProposeChange_Proxy( 
    IAccImSession __RPC_FAR * This,
    /* [in] */ AccImSessionType sessionType);


void __RPC_STUB IAccImSession_ProposeChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccImSession_StopRecv_Proxy( 
    IAccImSession __RPC_FAR * This);


void __RPC_STUB IAccImSession_StopRecv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccImSession_StopSend_Proxy( 
    IAccImSession __RPC_FAR * This);


void __RPC_STUB IAccImSession_StopSend_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccImSession_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccImSession_0271 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccImSession)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_SessionType(IAccImSession* pi, AccImSessionType* px) { return get_Property(pi, AccImSessionProp_SessionType, (xp_s32*)px); };
static inline HRESULT get_SessionTypeProposed(IAccImSession* pi, AccImSessionType* px) { return get_Property(pi, AccImSessionProp_SessionTypeProposed, (xp_s32*)px); };
static inline HRESULT get_ChatExchange(IAccImSession* pi, xp_s32* px) { return get_Property(pi, AccImSessionProp_ChatExchange, px); };
static inline HRESULT get_ChatRoomName(IAccImSession* pi, xp_str* px) { return get_Property(pi, AccImSessionProp_ChatRoomName, px); };
static inline HRESULT get_ChatRoomFullyQualifiedName(IAccImSession* pi, xp_str* px) { return get_Property(pi, AccImSessionProp_ChatRoomFullyQualifiedName, px); };
static inline HRESULT get_ChatInstance(IAccImSession* pi, xp_s32* px) { return get_Property(pi, AccImSessionProp_ChatInstance, px); };
static inline HRESULT get_CanStop(IAccImSession* pi, xp_bool* px) { return get_Property(pi, AccImSessionProp_CanStop, px); };
static inline HRESULT get_OutgoingPersonality(IAccImSession* pi, xp_str* px) { return get_Property(pi, AccImSessionProp_OutgoingPersonality, px); };
static inline HRESULT put_OutgoingPersonality(IAccImSession* pi, xp_kstr x) { return put_Property(pi, AccImSessionProp_OutgoingPersonality, x); };
static inline HRESULT get_MaxImLength(IAccImSession* pi, xp_s64* px) { return get_Property(pi, AccImSessionProp_MaxImLength, px); };
static inline HRESULT get_MaxVisibleImLength(IAccImSession* pi, xp_s32* px) { return get_Property(pi, AccImSessionProp_MaxVisibleImLength, px); };
static inline HRESULT get_RateState(IAccImSession* pi, AccRateState* px) { return get_Property(pi, AccImSessionProp_RateState, (xp_s32*)px); };
static inline HRESULT get_PromoteCentralized(IAccImSession* pi, xp_bool* px) { return get_Property(pi, AccImSessionProp_PromoteCentralized, px); };
static inline HRESULT put_PromoteCentralized(IAccImSession* pi, xp_bool x) { return put_Property(pi, AccImSessionProp_PromoteCentralized, x); };
static inline HRESULT get_LocalWantsRtim(IAccImSession* pi, xp_bool* px) { return get_Property(pi, AccImSessionProp_LocalWantsRtim, px); };
static inline HRESULT put_LocalWantsRtim(IAccImSession* pi, xp_bool x) { return put_Property(pi, AccImSessionProp_LocalWantsRtim, x); };
static inline HRESULT get_RemoteWantsRtim(IAccImSession* pi, xp_bool* px) { return get_Property(pi, AccImSessionProp_RemoteWantsRtim, px); };
static inline HRESULT get_QueuedImCount(IAccImSession* pi, xp_s32* px) { return get_Property(pi, AccImSessionProp_QueuedImCount, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccImSession_0271_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccImSession_0271_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long __RPC_FAR *, unsigned long            , VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  VARIANT_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, VARIANT __RPC_FAR * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long __RPC_FAR *, VARIANT __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
