/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:35 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccFileXferManager.idl:
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

#ifndef __IAccFileXferManager_h__
#define __IAccFileXferManager_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccFileXferManager_FWD_DEFINED__
#define __IAccFileXferManager_FWD_DEFINED__
typedef interface IAccFileXferManager IAccFileXferManager;
#endif 	/* __IAccFileXferManager_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccFileXferSession.h"


#ifndef __IAccFileXferManager_INTERFACE_DEFINED__
#define __IAccFileXferManager_INTERFACE_DEFINED__

/* interface IAccFileXferManager */
/* [object][dual][uuid] */ 

typedef 
enum AccFileXferFlags
    {	AccFileXferFlags_ForceNonSecure	= 0x2,
	AccFileXferFlags_ForceSecure	= 0x3
    }	AccFileXferFlags;


EXTERN_C const IID IID_IAccFileXferManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7325124c-e923-11d7-8102-00e081103594")
    IAccFileXferManager : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Send( 
            /* [in] */ xp_kstr userName,
            /* [in] */ xp_kstr path,
            /* [in] */ xp_kstr invitation,
            /* [in] */ xp_int flags,
            /* [retval][out] */ IAccFileXferSession __RPC_FAR *__RPC_FAR *fileXferSession) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccFileXferManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccFileXferManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccFileXferManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccFileXferManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccFileXferManager __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccFileXferManager __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccFileXferManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccFileXferManager __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Send )( 
            IAccFileXferManager __RPC_FAR * This,
            /* [in] */ xp_kstr userName,
            /* [in] */ xp_kstr path,
            /* [in] */ xp_kstr invitation,
            /* [in] */ xp_int flags,
            /* [retval][out] */ IAccFileXferSession __RPC_FAR *__RPC_FAR *fileXferSession);
        
        END_INTERFACE
    } IAccFileXferManagerVtbl;

    interface IAccFileXferManager
    {
        CONST_VTBL struct IAccFileXferManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccFileXferManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccFileXferManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccFileXferManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccFileXferManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccFileXferManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccFileXferManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccFileXferManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccFileXferManager_Send(This,userName,path,invitation,flags,fileXferSession)	\
    (This)->lpVtbl -> Send(This,userName,path,invitation,flags,fileXferSession)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAccFileXferManager_Send_Proxy( 
    IAccFileXferManager __RPC_FAR * This,
    /* [in] */ xp_kstr userName,
    /* [in] */ xp_kstr path,
    /* [in] */ xp_kstr invitation,
    /* [in] */ xp_int flags,
    /* [retval][out] */ IAccFileXferSession __RPC_FAR *__RPC_FAR *fileXferSession);


void __RPC_STUB IAccFileXferManager_Send_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccFileXferManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccFileXferManager_0125 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccFileXferManager)


extern RPC_IF_HANDLE __MIDL_itf_IAccFileXferManager_0125_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccFileXferManager_0125_v0_0_s_ifspec;

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
