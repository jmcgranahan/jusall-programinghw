/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Dec 02 11:52:03 2007
 */
/* Compiler settings for C:\dev\cvs\client\aimcc\idl\IAccBartCacheManager.idl:
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

#ifndef __IAccBartCacheManager_h__
#define __IAccBartCacheManager_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccBartCacheManager_FWD_DEFINED__
#define __IAccBartCacheManager_FWD_DEFINED__
typedef interface IAccBartCacheManager IAccBartCacheManager;
#endif 	/* __IAccBartCacheManager_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccBartItem.h"


#ifndef __IAccBartCacheManager_INTERFACE_DEFINED__
#define __IAccBartCacheManager_INTERFACE_DEFINED__

/* interface IAccBartCacheManager */
/* [object][dual][uuid] */ 


EXTERN_C const IID IID_IAccBartCacheManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("06201F8E-3F34-4daa-BEA9-BE298D92CD67")
    IAccBartCacheManager : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetItemByUserName( 
            /* [in] */ AccBartItemType type,
            /* [in] */ xp_kstr userName,
            /* [retval][out] */ IAccBartItem __RPC_FAR *__RPC_FAR *ppiAccBartItem) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccBartCacheManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccBartCacheManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccBartCacheManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccBartCacheManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccBartCacheManager __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccBartCacheManager __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccBartCacheManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccBartCacheManager __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetItemByUserName )( 
            IAccBartCacheManager __RPC_FAR * This,
            /* [in] */ AccBartItemType type,
            /* [in] */ xp_kstr userName,
            /* [retval][out] */ IAccBartItem __RPC_FAR *__RPC_FAR *ppiAccBartItem);
        
        END_INTERFACE
    } IAccBartCacheManagerVtbl;

    interface IAccBartCacheManager
    {
        CONST_VTBL struct IAccBartCacheManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccBartCacheManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccBartCacheManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccBartCacheManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccBartCacheManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccBartCacheManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccBartCacheManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccBartCacheManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccBartCacheManager_GetItemByUserName(This,type,userName,ppiAccBartItem)	\
    (This)->lpVtbl -> GetItemByUserName(This,type,userName,ppiAccBartItem)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAccBartCacheManager_GetItemByUserName_Proxy( 
    IAccBartCacheManager __RPC_FAR * This,
    /* [in] */ AccBartItemType type,
    /* [in] */ xp_kstr userName,
    /* [retval][out] */ IAccBartItem __RPC_FAR *__RPC_FAR *ppiAccBartItem);


void __RPC_STUB IAccBartCacheManager_GetItemByUserName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccBartCacheManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccBartCacheManager_0267 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccBartCacheManager)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccBartCacheManager_0267_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccBartCacheManager_0267_v0_0_s_ifspec;

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
