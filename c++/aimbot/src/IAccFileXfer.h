/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:35 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccFileXfer.idl:
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

#ifndef __IAccFileXfer_h__
#define __IAccFileXfer_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccFileXfer_FWD_DEFINED__
#define __IAccFileXfer_FWD_DEFINED__
typedef interface IAccFileXfer IAccFileXfer;
#endif 	/* __IAccFileXfer_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"


#ifndef __IAccFileXfer_INTERFACE_DEFINED__
#define __IAccFileXfer_INTERFACE_DEFINED__

/* interface IAccFileXfer */
/* [object][dual][uuid] */ 

typedef 
enum AccFileXferProp
    {	AccFileXferProp_Bytes	= 0,
	AccFileXferProp_BytesXferred	= AccFileXferProp_Bytes + 1,
	AccFileXferProp_LocalPath	= AccFileXferProp_BytesXferred + 1,
	AccFileXferProp_Name	= AccFileXferProp_LocalPath + 1
    }	AccFileXferProp;


EXTERN_C const IID IID_IAccFileXfer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("87a21eae-e923-11d7-9cfd-00e081103594")
    IAccFileXfer : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccFileXferProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccFileXferProp property,
            /* [in] */ xp_kvariant value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccFileXferVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccFileXfer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccFileXfer __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccFileXfer __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccFileXfer __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccFileXfer __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccFileXfer __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccFileXfer __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccFileXfer __RPC_FAR * This,
            /* [in] */ AccFileXferProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccFileXfer __RPC_FAR * This,
            /* [in] */ AccFileXferProp property,
            /* [in] */ xp_kvariant value);
        
        END_INTERFACE
    } IAccFileXferVtbl;

    interface IAccFileXfer
    {
        CONST_VTBL struct IAccFileXferVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccFileXfer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccFileXfer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccFileXfer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccFileXfer_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccFileXfer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccFileXfer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccFileXfer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccFileXfer_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccFileXfer_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccFileXfer_get_Property_Proxy( 
    IAccFileXfer __RPC_FAR * This,
    /* [in] */ AccFileXferProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccFileXfer_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccFileXfer_put_Property_Proxy( 
    IAccFileXfer __RPC_FAR * This,
    /* [in] */ AccFileXferProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccFileXfer_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccFileXfer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccFileXfer_0117 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccFileXfer)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_Bytes(IAccFileXfer* pi, xp_s64* px) { return get_Property(pi, AccFileXferProp_Bytes, px); };
static inline HRESULT get_BytesXferred(IAccFileXfer* pi, xp_s64* px) { return get_Property(pi, AccFileXferProp_BytesXferred, px); };
static inline HRESULT get_LocalPath(IAccFileXfer* pi, xp_str* px) { return get_Property(pi, AccFileXferProp_LocalPath, px); };
static inline HRESULT get_Name(IAccFileXfer* pi, xp_str* px) { return get_Property(pi, AccFileXferProp_Name, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccFileXfer_0117_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccFileXfer_0117_v0_0_s_ifspec;

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
