/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:51 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccShareBuddiesManager.idl:
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

#ifndef __IAccShareBuddiesManager_h__
#define __IAccShareBuddiesManager_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccShareBuddiesManager_FWD_DEFINED__
#define __IAccShareBuddiesManager_FWD_DEFINED__
typedef interface IAccShareBuddiesManager IAccShareBuddiesManager;
#endif 	/* __IAccShareBuddiesManager_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccShareBuddiesSession.h"


#ifndef __IAccShareBuddiesManager_INTERFACE_DEFINED__
#define __IAccShareBuddiesManager_INTERFACE_DEFINED__

/* interface IAccShareBuddiesManager */
/* [object][dual][uuid] */ 


EXTERN_C const IID IID_IAccShareBuddiesManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("81d8b3d0-c6ee-408d-93dc-acc9a935dfdc")
    IAccShareBuddiesManager : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Send( 
            /* [in] */ xp_kstr userName,
            /* [in] */ xp_kvariant groups,
            /* [in] */ xp_int flags,
            /* [retval][out] */ IAccShareBuddiesSession __RPC_FAR *__RPC_FAR *shareBuddiesSession) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccShareBuddiesManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccShareBuddiesManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccShareBuddiesManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccShareBuddiesManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccShareBuddiesManager __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccShareBuddiesManager __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccShareBuddiesManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccShareBuddiesManager __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Send )( 
            IAccShareBuddiesManager __RPC_FAR * This,
            /* [in] */ xp_kstr userName,
            /* [in] */ xp_kvariant groups,
            /* [in] */ xp_int flags,
            /* [retval][out] */ IAccShareBuddiesSession __RPC_FAR *__RPC_FAR *shareBuddiesSession);
        
        END_INTERFACE
    } IAccShareBuddiesManagerVtbl;

    interface IAccShareBuddiesManager
    {
        CONST_VTBL struct IAccShareBuddiesManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccShareBuddiesManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccShareBuddiesManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccShareBuddiesManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccShareBuddiesManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccShareBuddiesManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccShareBuddiesManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccShareBuddiesManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccShareBuddiesManager_Send(This,userName,groups,flags,shareBuddiesSession)	\
    (This)->lpVtbl -> Send(This,userName,groups,flags,shareBuddiesSession)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAccShareBuddiesManager_Send_Proxy( 
    IAccShareBuddiesManager __RPC_FAR * This,
    /* [in] */ xp_kstr userName,
    /* [in] */ xp_kvariant groups,
    /* [in] */ xp_int flags,
    /* [retval][out] */ IAccShareBuddiesSession __RPC_FAR *__RPC_FAR *shareBuddiesSession);


void __RPC_STUB IAccShareBuddiesManager_Send_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccShareBuddiesManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccShareBuddiesManager_0125 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccShareBuddiesManager)


extern RPC_IF_HANDLE __MIDL_itf_IAccShareBuddiesManager_0125_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccShareBuddiesManager_0125_v0_0_s_ifspec;

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
