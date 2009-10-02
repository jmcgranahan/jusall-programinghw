/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Sep 12 14:01:27 2007
 */
/* Compiler settings for C:\dev\cvs\client\aimcc\idl\IAccSecondarySession.idl:
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

#ifndef __IAccSecondarySession_h__
#define __IAccSecondarySession_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccSecondarySession_FWD_DEFINED__
#define __IAccSecondarySession_FWD_DEFINED__
typedef interface IAccSecondarySession IAccSecondarySession;
#endif 	/* __IAccSecondarySession_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"


#ifndef __IAccSecondarySession_INTERFACE_DEFINED__
#define __IAccSecondarySession_INTERFACE_DEFINED__

/* interface IAccSecondarySession */
/* [object][dual][uuid] */ 

typedef 
enum AccSecondarySessionServiceId
    {	AccSecondarySessionServiceId_Im	= 1,
	AccSecondarySessionServiceId_AudioVideo	= 2,
	AccSecondarySessionServiceId_FileXfer	= 3,
	AccSecondarySessionServiceId_FileSharing	= 4,
	AccSecondarySessionServiceId_ShareBuddies	= 5,
	AccSecondarySessionServiceId_Custom	= 6
    }	AccSecondarySessionServiceId;

typedef 
enum AccSecondarySessionState
    {	AccSecondarySessionState_Offline	= 0,
	AccSecondarySessionState_ReceivedProposal	= 50,
	AccSecondarySessionState_SentProposal	= 75,
	AccSecondarySessionState_Connecting	= 100,
	AccSecondarySessionState_Online	= 500,
	AccSecondarySessionState_Paused	= 600
    }	AccSecondarySessionState;

typedef 
enum AccSecondarySessionProp
    {	AccSecondarySessionProp_Session	= -1,
	AccSecondarySessionProp_ServiceId	= AccSecondarySessionProp_Session + 1,
	AccSecondarySessionProp_State	= AccSecondarySessionProp_ServiceId + 1,
	AccSecondarySessionProp_SessionState	= AccSecondarySessionProp_State,
	AccSecondarySessionProp_Invitation	= AccSecondarySessionProp_SessionState + 1,
	AccSecondarySessionProp_Secure	= AccSecondarySessionProp_Invitation + 1,
	AccSecondarySessionProp_RemoteUserName	= AccSecondarySessionProp_Secure + 1,
	AccSecondarySessionProp_Participants	= AccSecondarySessionProp_RemoteUserName + 1,
	AccSecondarySessionProp_MaxParticipantCount	= AccSecondarySessionProp_Participants + 1,
	AccSecondarySessionProp_Invitees	= AccSecondarySessionProp_MaxParticipantCount + 1,
	AccSecondarySessionProp_Name	= AccSecondarySessionProp_Invitees + 1,
	AccSecondarySessionProp_CreationTime	= AccSecondarySessionProp_Name + 1,
	AccSecondarySessionProp_OnlineTime	= AccSecondarySessionProp_CreationTime + 1,
	AccSecondarySessionProp_RemainingTime	= AccSecondarySessionProp_OnlineTime + 1,
	AccSecondarySessionProp_Id	= AccSecondarySessionProp_RemainingTime + 1,
	AccSecondarySessionProp_LinkedSessions	= AccSecondarySessionProp_Id + 1,
	AccSecondarySessionProp_Max	= 999
    }	AccSecondarySessionProp;


EXTERN_C const IID IID_IAccSecondarySession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("94ba92f6-e923-11d7-9237-00e081103594")
    IAccSecondarySession : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ServiceId( 
            /* [retval][out] */ AccSecondarySessionServiceId __RPC_FAR *pId) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ xp_int property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ xp_int property,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Accept( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reject( 
            /* [defaultvalue][in] */ xp_int reason = ACC_E_USER_REJECTED) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Invite( 
            /* [in] */ xp_kstr invitee,
            /* [in] */ xp_kstr invitation,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelProposal( 
            /* [in] */ xp_kstr invitee) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Eject( 
            /* [in] */ xp_kstr userName,
            /* [defaultvalue][in] */ xp_kstr reason,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndSession( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccSecondarySessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccSecondarySession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccSecondarySession __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccSecondarySession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccSecondarySession __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccSecondarySession __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccSecondarySession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccSecondarySession __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ServiceId )( 
            IAccSecondarySession __RPC_FAR * This,
            /* [retval][out] */ AccSecondarySessionServiceId __RPC_FAR *pId);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccSecondarySession __RPC_FAR * This,
            /* [in] */ xp_int property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccSecondarySession __RPC_FAR * This,
            /* [in] */ xp_int property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Accept )( 
            IAccSecondarySession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reject )( 
            IAccSecondarySession __RPC_FAR * This,
            /* [defaultvalue][in] */ xp_int reason);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invite )( 
            IAccSecondarySession __RPC_FAR * This,
            /* [in] */ xp_kstr invitee,
            /* [in] */ xp_kstr invitation,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CancelProposal )( 
            IAccSecondarySession __RPC_FAR * This,
            /* [in] */ xp_kstr invitee);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Eject )( 
            IAccSecondarySession __RPC_FAR * This,
            /* [in] */ xp_kstr userName,
            /* [defaultvalue][in] */ xp_kstr reason,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EndSession )( 
            IAccSecondarySession __RPC_FAR * This);
        
        END_INTERFACE
    } IAccSecondarySessionVtbl;

    interface IAccSecondarySession
    {
        CONST_VTBL struct IAccSecondarySessionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccSecondarySession_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccSecondarySession_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccSecondarySession_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccSecondarySession_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccSecondarySession_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccSecondarySession_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccSecondarySession_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccSecondarySession_get_ServiceId(This,pId)	\
    (This)->lpVtbl -> get_ServiceId(This,pId)

#define IAccSecondarySession_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccSecondarySession_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccSecondarySession_Accept(This)	\
    (This)->lpVtbl -> Accept(This)

#define IAccSecondarySession_Reject(This,reason)	\
    (This)->lpVtbl -> Reject(This,reason)

#define IAccSecondarySession_Invite(This,invitee,invitation,pTransId)	\
    (This)->lpVtbl -> Invite(This,invitee,invitation,pTransId)

#define IAccSecondarySession_CancelProposal(This,invitee)	\
    (This)->lpVtbl -> CancelProposal(This,invitee)

#define IAccSecondarySession_Eject(This,userName,reason,pTransId)	\
    (This)->lpVtbl -> Eject(This,userName,reason,pTransId)

#define IAccSecondarySession_EndSession(This)	\
    (This)->lpVtbl -> EndSession(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccSecondarySession_get_ServiceId_Proxy( 
    IAccSecondarySession __RPC_FAR * This,
    /* [retval][out] */ AccSecondarySessionServiceId __RPC_FAR *pId);


void __RPC_STUB IAccSecondarySession_get_ServiceId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccSecondarySession_get_Property_Proxy( 
    IAccSecondarySession __RPC_FAR * This,
    /* [in] */ xp_int property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccSecondarySession_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccSecondarySession_put_Property_Proxy( 
    IAccSecondarySession __RPC_FAR * This,
    /* [in] */ xp_int property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccSecondarySession_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSecondarySession_Accept_Proxy( 
    IAccSecondarySession __RPC_FAR * This);


void __RPC_STUB IAccSecondarySession_Accept_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSecondarySession_Reject_Proxy( 
    IAccSecondarySession __RPC_FAR * This,
    /* [defaultvalue][in] */ xp_int reason);


void __RPC_STUB IAccSecondarySession_Reject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSecondarySession_Invite_Proxy( 
    IAccSecondarySession __RPC_FAR * This,
    /* [in] */ xp_kstr invitee,
    /* [in] */ xp_kstr invitation,
    /* [retval][out] */ AccTransId __RPC_FAR *pTransId);


void __RPC_STUB IAccSecondarySession_Invite_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSecondarySession_CancelProposal_Proxy( 
    IAccSecondarySession __RPC_FAR * This,
    /* [in] */ xp_kstr invitee);


void __RPC_STUB IAccSecondarySession_CancelProposal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSecondarySession_Eject_Proxy( 
    IAccSecondarySession __RPC_FAR * This,
    /* [in] */ xp_kstr userName,
    /* [defaultvalue][in] */ xp_kstr reason,
    /* [retval][out] */ AccTransId __RPC_FAR *pTransId);


void __RPC_STUB IAccSecondarySession_Eject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSecondarySession_EndSession_Proxy( 
    IAccSecondarySession __RPC_FAR * This);


void __RPC_STUB IAccSecondarySession_EndSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccSecondarySession_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccSecondarySession_0117 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccSecondarySession)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_Session(IAccSecondarySession* pi, IAccSession** px) { return get_Property(pi, AccSecondarySessionProp_Session, IID_IAccSession, px); };
#endif
static inline HRESULT get_ServiceId(IAccSecondarySession* pi, AccSecondarySessionServiceId* px) { return get_Property(pi, AccSecondarySessionProp_ServiceId, (xp_s32*)px); };
static inline HRESULT get_State(IAccSecondarySession* pi, AccSecondarySessionState* px) { return get_Property(pi, AccSecondarySessionProp_State, (xp_s32*)px); };
static inline HRESULT get_SessionState(IAccSecondarySession* pi, AccSecondarySessionState* px) { return get_Property(pi, AccSecondarySessionProp_SessionState, (xp_s32*)px); };
static inline HRESULT get_Invitation(IAccSecondarySession* pi, xp_str* px) { return get_Property(pi, AccSecondarySessionProp_Invitation, px); };
static inline HRESULT get_Secure(IAccSecondarySession* pi, xp_bool* px) { return get_Property(pi, AccSecondarySessionProp_Secure, px); };
static inline HRESULT get_RemoteUserName(IAccSecondarySession* pi, xp_str* px) { return get_Property(pi, AccSecondarySessionProp_RemoteUserName, px); };
static inline HRESULT get_Participants(IAccSecondarySession* pi, xp_array** px) { return get_Property(pi, AccSecondarySessionProp_Participants, px); };
static inline HRESULT get_MaxParticipantCount(IAccSecondarySession* pi, xp_s32* px) { return get_Property(pi, AccSecondarySessionProp_MaxParticipantCount, px); };
static inline HRESULT get_Invitees(IAccSecondarySession* pi, xp_array** px) { return get_Property(pi, AccSecondarySessionProp_Invitees, px); };
static inline HRESULT get_Name(IAccSecondarySession* pi, xp_str* px) { return get_Property(pi, AccSecondarySessionProp_Name, px); };
static inline HRESULT get_CreationTime(IAccSecondarySession* pi, xp_date* px) { return get_PropertyDate(pi, AccSecondarySessionProp_CreationTime, px); };
static inline HRESULT get_OnlineTime(IAccSecondarySession* pi, xp_s32* px) { return get_Property(pi, AccSecondarySessionProp_OnlineTime, px); };
static inline HRESULT get_RemainingTime(IAccSecondarySession* pi, xp_s32* px) { return get_Property(pi, AccSecondarySessionProp_RemainingTime, px); };
static inline HRESULT get_LinkedSessions(IAccSecondarySession* pi, xp_array** px) { return get_Property(pi, AccSecondarySessionProp_LinkedSessions, px); };
static inline HRESULT put_LinkedSessions(IAccSecondarySession* pi, xp_array* x) { return put_Property(pi, AccSecondarySessionProp_LinkedSessions, x); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccSecondarySession_0117_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccSecondarySession_0117_v0_0_s_ifspec;

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
