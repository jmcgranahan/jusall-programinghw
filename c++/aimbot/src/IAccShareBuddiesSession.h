/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:51 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccShareBuddiesSession.idl:
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

#ifndef __IAccShareBuddiesSession_h__
#define __IAccShareBuddiesSession_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccShareBuddiesSession_FWD_DEFINED__
#define __IAccShareBuddiesSession_FWD_DEFINED__
typedef interface IAccShareBuddiesSession IAccShareBuddiesSession;
#endif 	/* __IAccShareBuddiesSession_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccSecondarySession.h"


#ifndef __IAccShareBuddiesSession_INTERFACE_DEFINED__
#define __IAccShareBuddiesSession_INTERFACE_DEFINED__

/* interface IAccShareBuddiesSession */
/* [object][dual][uuid] */ 

typedef 
enum AccShareBuddiesSessionProp
    {	AccShareBuddiesSessionProp_Groups	= 1000
    }	AccShareBuddiesSessionProp;


EXTERN_C const IID IID_IAccShareBuddiesSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4203d4f3-fc58-473d-b5fa-3a909078c760")
    IAccShareBuddiesSession : public IAccSecondarySession
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property_( 
            /* [in] */ AccShareBuddiesSessionProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property_( 
            /* [in] */ AccShareBuddiesSessionProp property,
            /* [in] */ xp_kvariant value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccShareBuddiesSessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccShareBuddiesSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccShareBuddiesSession __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccShareBuddiesSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccShareBuddiesSession __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccShareBuddiesSession __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccShareBuddiesSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccShareBuddiesSession __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ServiceId )( 
            IAccShareBuddiesSession __RPC_FAR * This,
            /* [retval][out] */ AccSecondarySessionServiceId __RPC_FAR *pId);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccShareBuddiesSession __RPC_FAR * This,
            /* [in] */ xp_int property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccShareBuddiesSession __RPC_FAR * This,
            /* [in] */ xp_int property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Accept )( 
            IAccShareBuddiesSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reject )( 
            IAccShareBuddiesSession __RPC_FAR * This,
            /* [defaultvalue][in] */ xp_int reason);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invite )( 
            IAccShareBuddiesSession __RPC_FAR * This,
            /* [in] */ xp_kstr invitee,
            /* [in] */ xp_kstr invitation,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CancelProposal )( 
            IAccShareBuddiesSession __RPC_FAR * This,
            /* [in] */ xp_kstr invitee);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Eject )( 
            IAccShareBuddiesSession __RPC_FAR * This,
            /* [in] */ xp_kstr userName,
            /* [defaultvalue][in] */ xp_kstr reason,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EndSession )( 
            IAccShareBuddiesSession __RPC_FAR * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property_ )( 
            IAccShareBuddiesSession __RPC_FAR * This,
            /* [in] */ AccShareBuddiesSessionProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property_ )( 
            IAccShareBuddiesSession __RPC_FAR * This,
            /* [in] */ AccShareBuddiesSessionProp property,
            /* [in] */ xp_kvariant value);
        
        END_INTERFACE
    } IAccShareBuddiesSessionVtbl;

    interface IAccShareBuddiesSession
    {
        CONST_VTBL struct IAccShareBuddiesSessionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccShareBuddiesSession_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccShareBuddiesSession_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccShareBuddiesSession_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccShareBuddiesSession_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccShareBuddiesSession_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccShareBuddiesSession_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccShareBuddiesSession_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccShareBuddiesSession_get_ServiceId(This,pId)	\
    (This)->lpVtbl -> get_ServiceId(This,pId)

#define IAccShareBuddiesSession_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccShareBuddiesSession_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccShareBuddiesSession_Accept(This)	\
    (This)->lpVtbl -> Accept(This)

#define IAccShareBuddiesSession_Reject(This,reason)	\
    (This)->lpVtbl -> Reject(This,reason)

#define IAccShareBuddiesSession_Invite(This,invitee,invitation,pTransId)	\
    (This)->lpVtbl -> Invite(This,invitee,invitation,pTransId)

#define IAccShareBuddiesSession_CancelProposal(This,invitee)	\
    (This)->lpVtbl -> CancelProposal(This,invitee)

#define IAccShareBuddiesSession_Eject(This,userName,reason,pTransId)	\
    (This)->lpVtbl -> Eject(This,userName,reason,pTransId)

#define IAccShareBuddiesSession_EndSession(This)	\
    (This)->lpVtbl -> EndSession(This)


#define IAccShareBuddiesSession_get_Property_(This,property,value)	\
    (This)->lpVtbl -> get_Property_(This,property,value)

#define IAccShareBuddiesSession_put_Property_(This,property,value)	\
    (This)->lpVtbl -> put_Property_(This,property,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccShareBuddiesSession_get_Property__Proxy( 
    IAccShareBuddiesSession __RPC_FAR * This,
    /* [in] */ AccShareBuddiesSessionProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccShareBuddiesSession_get_Property__Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccShareBuddiesSession_put_Property__Proxy( 
    IAccShareBuddiesSession __RPC_FAR * This,
    /* [in] */ AccShareBuddiesSessionProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccShareBuddiesSession_put_Property__Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccShareBuddiesSession_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccShareBuddiesSession_0121 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccShareBuddiesSession)


extern RPC_IF_HANDLE __MIDL_itf_IAccShareBuddiesSession_0121_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccShareBuddiesSession_0121_v0_0_s_ifspec;

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
