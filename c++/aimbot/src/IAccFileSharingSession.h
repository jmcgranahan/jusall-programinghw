/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:34 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccFileSharingSession.idl:
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

#ifndef __IAccFileSharingSession_h__
#define __IAccFileSharingSession_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccFileSharingSession_FWD_DEFINED__
#define __IAccFileSharingSession_FWD_DEFINED__
typedef interface IAccFileSharingSession IAccFileSharingSession;
#endif 	/* __IAccFileSharingSession_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccFileSharingItem.h"
#include "IAccAccessControlHook.h"


#ifndef __IAccFileSharingSession_INTERFACE_DEFINED__
#define __IAccFileSharingSession_INTERFACE_DEFINED__

/* interface IAccFileSharingSession */
/* [object][dual][uuid] */ 

typedef 
enum AccFileSharingSessionProp
    {	AccFileSharingSessionProp_CanStop	= 1000,
	AccFileSharingSessionProp_FileXferSession	= AccFileSharingSessionProp_CanStop + 1,
	AccFileSharingSessionProp_TopLevelListingCount	= AccFileSharingSessionProp_FileXferSession + 1,
	AccFileSharingSessionProp_XferringFileSharingItem	= AccFileSharingSessionProp_TopLevelListingCount + 1,
	AccFileSharingSessionProp_AccessControlHook	= AccFileSharingSessionProp_XferringFileSharingItem + 1
    }	AccFileSharingSessionProp;


EXTERN_C const IID IID_IAccFileSharingSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8178bc68-e923-11d7-89bb-00e081103594")
    IAccFileSharingSession : public IAccSecondarySession
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property_( 
            /* [in] */ AccFileSharingSessionProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property_( 
            /* [in] */ AccFileSharingSessionProp property,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemByIndex( 
            /* [in] */ xp_int index,
            /* [retval][out] */ IAccFileSharingItem __RPC_FAR *__RPC_FAR *item) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopRecv( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccFileSharingSessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccFileSharingSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccFileSharingSession __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccFileSharingSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccFileSharingSession __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccFileSharingSession __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccFileSharingSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccFileSharingSession __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ServiceId )( 
            IAccFileSharingSession __RPC_FAR * This,
            /* [retval][out] */ AccSecondarySessionServiceId __RPC_FAR *pId);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccFileSharingSession __RPC_FAR * This,
            /* [in] */ xp_int property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccFileSharingSession __RPC_FAR * This,
            /* [in] */ xp_int property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Accept )( 
            IAccFileSharingSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reject )( 
            IAccFileSharingSession __RPC_FAR * This,
            /* [defaultvalue][in] */ xp_int reason);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invite )( 
            IAccFileSharingSession __RPC_FAR * This,
            /* [in] */ xp_kstr invitee,
            /* [in] */ xp_kstr invitation,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CancelProposal )( 
            IAccFileSharingSession __RPC_FAR * This,
            /* [in] */ xp_kstr invitee);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Eject )( 
            IAccFileSharingSession __RPC_FAR * This,
            /* [in] */ xp_kstr userName,
            /* [defaultvalue][in] */ xp_kstr reason,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EndSession )( 
            IAccFileSharingSession __RPC_FAR * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property_ )( 
            IAccFileSharingSession __RPC_FAR * This,
            /* [in] */ AccFileSharingSessionProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property_ )( 
            IAccFileSharingSession __RPC_FAR * This,
            /* [in] */ AccFileSharingSessionProp property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetItemByIndex )( 
            IAccFileSharingSession __RPC_FAR * This,
            /* [in] */ xp_int index,
            /* [retval][out] */ IAccFileSharingItem __RPC_FAR *__RPC_FAR *item);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopRecv )( 
            IAccFileSharingSession __RPC_FAR * This);
        
        END_INTERFACE
    } IAccFileSharingSessionVtbl;

    interface IAccFileSharingSession
    {
        CONST_VTBL struct IAccFileSharingSessionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccFileSharingSession_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccFileSharingSession_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccFileSharingSession_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccFileSharingSession_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccFileSharingSession_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccFileSharingSession_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccFileSharingSession_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccFileSharingSession_get_ServiceId(This,pId)	\
    (This)->lpVtbl -> get_ServiceId(This,pId)

#define IAccFileSharingSession_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccFileSharingSession_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccFileSharingSession_Accept(This)	\
    (This)->lpVtbl -> Accept(This)

#define IAccFileSharingSession_Reject(This,reason)	\
    (This)->lpVtbl -> Reject(This,reason)

#define IAccFileSharingSession_Invite(This,invitee,invitation,pTransId)	\
    (This)->lpVtbl -> Invite(This,invitee,invitation,pTransId)

#define IAccFileSharingSession_CancelProposal(This,invitee)	\
    (This)->lpVtbl -> CancelProposal(This,invitee)

#define IAccFileSharingSession_Eject(This,userName,reason,pTransId)	\
    (This)->lpVtbl -> Eject(This,userName,reason,pTransId)

#define IAccFileSharingSession_EndSession(This)	\
    (This)->lpVtbl -> EndSession(This)


#define IAccFileSharingSession_get_Property_(This,property,value)	\
    (This)->lpVtbl -> get_Property_(This,property,value)

#define IAccFileSharingSession_put_Property_(This,property,value)	\
    (This)->lpVtbl -> put_Property_(This,property,value)

#define IAccFileSharingSession_GetItemByIndex(This,index,item)	\
    (This)->lpVtbl -> GetItemByIndex(This,index,item)

#define IAccFileSharingSession_StopRecv(This)	\
    (This)->lpVtbl -> StopRecv(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccFileSharingSession_get_Property__Proxy( 
    IAccFileSharingSession __RPC_FAR * This,
    /* [in] */ AccFileSharingSessionProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccFileSharingSession_get_Property__Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccFileSharingSession_put_Property__Proxy( 
    IAccFileSharingSession __RPC_FAR * This,
    /* [in] */ AccFileSharingSessionProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccFileSharingSession_put_Property__Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccFileSharingSession_GetItemByIndex_Proxy( 
    IAccFileSharingSession __RPC_FAR * This,
    /* [in] */ xp_int index,
    /* [retval][out] */ IAccFileSharingItem __RPC_FAR *__RPC_FAR *item);


void __RPC_STUB IAccFileSharingSession_GetItemByIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccFileSharingSession_StopRecv_Proxy( 
    IAccFileSharingSession __RPC_FAR * This);


void __RPC_STUB IAccFileSharingSession_StopRecv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccFileSharingSession_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccFileSharingSession_0361 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccFileSharingSession)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_CanStop(IAccFileSharingSession* pi, xp_bool* px) { return get_Property(pi, AccFileSharingSessionProp_CanStop, px); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_FileXferSession(IAccFileSharingSession* pi, IAccFileXferSession** px) { return get_Property(pi, AccFileSharingSessionProp_FileXferSession, IID_IAccFileXferSession, px); };
#endif
static inline HRESULT get_TopLevelListingCount(IAccFileSharingSession* pi, xp_s32* px) { return get_Property(pi, AccFileSharingSessionProp_TopLevelListingCount, px); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_XferringFileSharingItem(IAccFileSharingSession* pi, IAccFileSharingItem** px) { return get_Property(pi, AccFileSharingSessionProp_XferringFileSharingItem, IID_IAccFileSharingItem, px); };
#endif
static inline HRESULT put_AccessControlHook(IAccFileSharingSession* pi, IAccAccessControlHook* x) { return put_Property(pi, AccFileSharingSessionProp_AccessControlHook, x); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccFileSharingSession_0361_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccFileSharingSession_0361_v0_0_s_ifspec;

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
