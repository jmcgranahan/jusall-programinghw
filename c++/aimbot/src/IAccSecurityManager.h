/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:48 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccSecurityManager.idl:
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

#ifndef __IAccSecurityManager_h__
#define __IAccSecurityManager_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccSecurityManager_FWD_DEFINED__
#define __IAccSecurityManager_FWD_DEFINED__
typedef interface IAccSecurityManager IAccSecurityManager;
#endif 	/* __IAccSecurityManager_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccCertificate.h"


#ifndef __IAccSecurityManager_INTERFACE_DEFINED__
#define __IAccSecurityManager_INTERFACE_DEFINED__

/* interface IAccSecurityManager */
/* [object][dual][uuid] */ 

typedef 
enum AccSecurityManagerProp
    {	AccSecurityManagerProp_PasswordInited	= 0
    }	AccSecurityManagerProp;


EXTERN_C const IID IID_IAccSecurityManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0558B1D7-C287-4ee5-8DC3-5E996370FAD6")
    IAccSecurityManager : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccSecurityManagerProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitPassword( 
            /* [in] */ xp_kstr password) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Authenticate( 
            /* [in] */ xp_kstr password) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCertificates( 
            /* [in] */ xp_int usage,
            /* [retval][out] */ xp_variant __RPC_FAR *certs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ImportCertificates( 
            /* [in] */ xp_kstr pkcs12fileSpec,
            /* [in] */ xp_kstr pkcs12Password,
            /* [defaultvalue][retval][out] */ xp_variant __RPC_FAR *certs = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExportCertificates( 
            /* [in] */ xp_kstr pkcs12fileSpec,
            /* [in] */ xp_kstr pkcs12Password,
            /* [in] */ xp_kstr tokenPassword,
            /* [in] */ xp_kvariant certs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetStore( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccSecurityManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccSecurityManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccSecurityManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccSecurityManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccSecurityManager __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccSecurityManager __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccSecurityManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccSecurityManager __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccSecurityManager __RPC_FAR * This,
            /* [in] */ AccSecurityManagerProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitPassword )( 
            IAccSecurityManager __RPC_FAR * This,
            /* [in] */ xp_kstr password);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Authenticate )( 
            IAccSecurityManager __RPC_FAR * This,
            /* [in] */ xp_kstr password);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCertificates )( 
            IAccSecurityManager __RPC_FAR * This,
            /* [in] */ xp_int usage,
            /* [retval][out] */ xp_variant __RPC_FAR *certs);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ImportCertificates )( 
            IAccSecurityManager __RPC_FAR * This,
            /* [in] */ xp_kstr pkcs12fileSpec,
            /* [in] */ xp_kstr pkcs12Password,
            /* [defaultvalue][retval][out] */ xp_variant __RPC_FAR *certs);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExportCertificates )( 
            IAccSecurityManager __RPC_FAR * This,
            /* [in] */ xp_kstr pkcs12fileSpec,
            /* [in] */ xp_kstr pkcs12Password,
            /* [in] */ xp_kstr tokenPassword,
            /* [in] */ xp_kvariant certs);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetStore )( 
            IAccSecurityManager __RPC_FAR * This);
        
        END_INTERFACE
    } IAccSecurityManagerVtbl;

    interface IAccSecurityManager
    {
        CONST_VTBL struct IAccSecurityManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccSecurityManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccSecurityManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccSecurityManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccSecurityManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccSecurityManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccSecurityManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccSecurityManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccSecurityManager_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccSecurityManager_InitPassword(This,password)	\
    (This)->lpVtbl -> InitPassword(This,password)

#define IAccSecurityManager_Authenticate(This,password)	\
    (This)->lpVtbl -> Authenticate(This,password)

#define IAccSecurityManager_GetCertificates(This,usage,certs)	\
    (This)->lpVtbl -> GetCertificates(This,usage,certs)

#define IAccSecurityManager_ImportCertificates(This,pkcs12fileSpec,pkcs12Password,certs)	\
    (This)->lpVtbl -> ImportCertificates(This,pkcs12fileSpec,pkcs12Password,certs)

#define IAccSecurityManager_ExportCertificates(This,pkcs12fileSpec,pkcs12Password,tokenPassword,certs)	\
    (This)->lpVtbl -> ExportCertificates(This,pkcs12fileSpec,pkcs12Password,tokenPassword,certs)

#define IAccSecurityManager_ResetStore(This)	\
    (This)->lpVtbl -> ResetStore(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccSecurityManager_get_Property_Proxy( 
    IAccSecurityManager __RPC_FAR * This,
    /* [in] */ AccSecurityManagerProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccSecurityManager_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSecurityManager_InitPassword_Proxy( 
    IAccSecurityManager __RPC_FAR * This,
    /* [in] */ xp_kstr password);


void __RPC_STUB IAccSecurityManager_InitPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSecurityManager_Authenticate_Proxy( 
    IAccSecurityManager __RPC_FAR * This,
    /* [in] */ xp_kstr password);


void __RPC_STUB IAccSecurityManager_Authenticate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSecurityManager_GetCertificates_Proxy( 
    IAccSecurityManager __RPC_FAR * This,
    /* [in] */ xp_int usage,
    /* [retval][out] */ xp_variant __RPC_FAR *certs);


void __RPC_STUB IAccSecurityManager_GetCertificates_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSecurityManager_ImportCertificates_Proxy( 
    IAccSecurityManager __RPC_FAR * This,
    /* [in] */ xp_kstr pkcs12fileSpec,
    /* [in] */ xp_kstr pkcs12Password,
    /* [defaultvalue][retval][out] */ xp_variant __RPC_FAR *certs);


void __RPC_STUB IAccSecurityManager_ImportCertificates_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSecurityManager_ExportCertificates_Proxy( 
    IAccSecurityManager __RPC_FAR * This,
    /* [in] */ xp_kstr pkcs12fileSpec,
    /* [in] */ xp_kstr pkcs12Password,
    /* [in] */ xp_kstr tokenPassword,
    /* [in] */ xp_kvariant certs);


void __RPC_STUB IAccSecurityManager_ExportCertificates_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccSecurityManager_ResetStore_Proxy( 
    IAccSecurityManager __RPC_FAR * This);


void __RPC_STUB IAccSecurityManager_ResetStore_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccSecurityManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccSecurityManager_0121 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccSecurityManager)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_PasswordInited(IAccSecurityManager* pi, xp_bool* px) { return get_Property(pi, AccSecurityManagerProp_PasswordInited, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccSecurityManager_0121_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccSecurityManager_0121_v0_0_s_ifspec;

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
