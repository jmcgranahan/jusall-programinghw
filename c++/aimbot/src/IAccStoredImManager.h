/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Oct 10 18:19:47 2006
 */
/* Compiler settings for C:\dev\cvs\client\aimcc\idl\IAccStoredImManager.idl:
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

#ifndef __IAccStoredImManager_h__
#define __IAccStoredImManager_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccStoredImManager_FWD_DEFINED__
#define __IAccStoredImManager_FWD_DEFINED__
typedef interface IAccStoredImManager IAccStoredImManager;
#endif 	/* __IAccStoredImManager_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"


#ifndef __IAccStoredImManager_INTERFACE_DEFINED__
#define __IAccStoredImManager_INTERFACE_DEFINED__

/* interface IAccStoredImManager */
/* [object][dual][uuid] */ 


EXTERN_C const IID IID_IAccStoredImManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6D09234D-4065-419a-973F-1B28AD5A8AD7")
    IAccStoredImManager : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RequestSummaries( 
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeliverIms( 
            /* [in] */ xp_kvariant whichIms,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteIms( 
            /* [in] */ xp_kvariant whichIms,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccStoredImManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccStoredImManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccStoredImManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccStoredImManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccStoredImManager __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccStoredImManager __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccStoredImManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccStoredImManager __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestSummaries )( 
            IAccStoredImManager __RPC_FAR * This,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeliverIms )( 
            IAccStoredImManager __RPC_FAR * This,
            /* [in] */ xp_kvariant whichIms,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DeleteIms )( 
            IAccStoredImManager __RPC_FAR * This,
            /* [in] */ xp_kvariant whichIms,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        END_INTERFACE
    } IAccStoredImManagerVtbl;

    interface IAccStoredImManager
    {
        CONST_VTBL struct IAccStoredImManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccStoredImManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccStoredImManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccStoredImManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccStoredImManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccStoredImManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccStoredImManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccStoredImManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccStoredImManager_RequestSummaries(This,pTransId)	\
    (This)->lpVtbl -> RequestSummaries(This,pTransId)

#define IAccStoredImManager_DeliverIms(This,whichIms,pTransId)	\
    (This)->lpVtbl -> DeliverIms(This,whichIms,pTransId)

#define IAccStoredImManager_DeleteIms(This,whichIms,pTransId)	\
    (This)->lpVtbl -> DeleteIms(This,whichIms,pTransId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAccStoredImManager_RequestSummaries_Proxy( 
    IAccStoredImManager __RPC_FAR * This,
    /* [retval][out] */ AccTransId __RPC_FAR *pTransId);


void __RPC_STUB IAccStoredImManager_RequestSummaries_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccStoredImManager_DeliverIms_Proxy( 
    IAccStoredImManager __RPC_FAR * This,
    /* [in] */ xp_kvariant whichIms,
    /* [retval][out] */ AccTransId __RPC_FAR *pTransId);


void __RPC_STUB IAccStoredImManager_DeliverIms_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccStoredImManager_DeleteIms_Proxy( 
    IAccStoredImManager __RPC_FAR * This,
    /* [in] */ xp_kvariant whichIms,
    /* [retval][out] */ AccTransId __RPC_FAR *pTransId);


void __RPC_STUB IAccStoredImManager_DeleteIms_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccStoredImManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccStoredImManager_0117 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccStoredImManager)


extern RPC_IF_HANDLE __MIDL_itf_IAccStoredImManager_0117_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccStoredImManager_0117_v0_0_s_ifspec;

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
