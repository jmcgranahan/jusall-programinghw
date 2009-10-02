/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:32 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccFileSharingManager.idl:
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

#ifndef __IAccFileSharingManager_h__
#define __IAccFileSharingManager_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccFileSharingManager_FWD_DEFINED__
#define __IAccFileSharingManager_FWD_DEFINED__
typedef interface IAccFileSharingManager IAccFileSharingManager;
#endif 	/* __IAccFileSharingManager_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccFileSharingSession.h"


#ifndef __IAccFileSharingManager_INTERFACE_DEFINED__
#define __IAccFileSharingManager_INTERFACE_DEFINED__

/* interface IAccFileSharingManager */
/* [object][dual][uuid] */ 


EXTERN_C const IID IID_IAccFileSharingManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("62f6a9d0-e923-11d7-90db-00e081103594")
    IAccFileSharingManager : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateSession( 
            /* [in] */ xp_kstr userName,
            /* [in] */ xp_kstr invitation,
            /* [in] */ xp_int flags,
            /* [retval][out] */ IAccFileSharingSession __RPC_FAR *__RPC_FAR *fileSharingSession) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccFileSharingManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccFileSharingManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccFileSharingManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccFileSharingManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccFileSharingManager __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccFileSharingManager __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccFileSharingManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccFileSharingManager __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateSession )( 
            IAccFileSharingManager __RPC_FAR * This,
            /* [in] */ xp_kstr userName,
            /* [in] */ xp_kstr invitation,
            /* [in] */ xp_int flags,
            /* [retval][out] */ IAccFileSharingSession __RPC_FAR *__RPC_FAR *fileSharingSession);
        
        END_INTERFACE
    } IAccFileSharingManagerVtbl;

    interface IAccFileSharingManager
    {
        CONST_VTBL struct IAccFileSharingManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccFileSharingManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccFileSharingManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccFileSharingManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccFileSharingManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccFileSharingManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccFileSharingManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccFileSharingManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccFileSharingManager_CreateSession(This,userName,invitation,flags,fileSharingSession)	\
    (This)->lpVtbl -> CreateSession(This,userName,invitation,flags,fileSharingSession)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAccFileSharingManager_CreateSession_Proxy( 
    IAccFileSharingManager __RPC_FAR * This,
    /* [in] */ xp_kstr userName,
    /* [in] */ xp_kstr invitation,
    /* [in] */ xp_int flags,
    /* [retval][out] */ IAccFileSharingSession __RPC_FAR *__RPC_FAR *fileSharingSession);


void __RPC_STUB IAccFileSharingManager_CreateSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccFileSharingManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccFileSharingManager_0365 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccFileSharingManager)


extern RPC_IF_HANDLE __MIDL_itf_IAccFileSharingManager_0365_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccFileSharingManager_0365_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
