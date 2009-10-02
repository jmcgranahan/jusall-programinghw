/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Sep 12 14:08:08 2007
 */
/* Compiler settings for C:\dev\cvs\client\aimcc\idl\IAccImageReference.idl:
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

#ifndef __IAccImageReference_h__
#define __IAccImageReference_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccImageReference_FWD_DEFINED__
#define __IAccImageReference_FWD_DEFINED__
typedef interface IAccImageReference IAccImageReference;
#endif 	/* __IAccImageReference_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"


#ifndef __IAccImageReference_INTERFACE_DEFINED__
#define __IAccImageReference_INTERFACE_DEFINED__

/* interface IAccImageReference */
/* [object][dual][uuid] */ 

typedef 
enum AccImageReferenceProp
    {	AccImageReferenceProp_Uri	= 0,
	AccImageReferenceProp_Height	= AccImageReferenceProp_Uri + 1,
	AccImageReferenceProp_Width	= AccImageReferenceProp_Height + 1,
	AccImageReferenceProp_Tags	= AccImageReferenceProp_Width + 1
    }	AccImageReferenceProp;


EXTERN_C const IID IID_IAccImageReference;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EF9289A4-88FF-4ce1-B087-8DC1ED9746BA")
    IAccImageReference : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccImageReferenceProp prop,
            /* [retval][out] */ xp_variant __RPC_FAR *pv) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccImageReferenceProp prop,
            /* [in] */ xp_kvariant v) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccImageReferenceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccImageReference __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccImageReference __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccImageReference __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccImageReference __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccImageReference __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccImageReference __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccImageReference __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccImageReference __RPC_FAR * This,
            /* [in] */ AccImageReferenceProp prop,
            /* [retval][out] */ xp_variant __RPC_FAR *pv);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccImageReference __RPC_FAR * This,
            /* [in] */ AccImageReferenceProp prop,
            /* [in] */ xp_kvariant v);
        
        END_INTERFACE
    } IAccImageReferenceVtbl;

    interface IAccImageReference
    {
        CONST_VTBL struct IAccImageReferenceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccImageReference_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccImageReference_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccImageReference_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccImageReference_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccImageReference_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccImageReference_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccImageReference_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccImageReference_get_Property(This,prop,pv)	\
    (This)->lpVtbl -> get_Property(This,prop,pv)

#define IAccImageReference_put_Property(This,prop,v)	\
    (This)->lpVtbl -> put_Property(This,prop,v)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccImageReference_get_Property_Proxy( 
    IAccImageReference __RPC_FAR * This,
    /* [in] */ AccImageReferenceProp prop,
    /* [retval][out] */ xp_variant __RPC_FAR *pv);


void __RPC_STUB IAccImageReference_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccImageReference_put_Property_Proxy( 
    IAccImageReference __RPC_FAR * This,
    /* [in] */ AccImageReferenceProp prop,
    /* [in] */ xp_kvariant v);


void __RPC_STUB IAccImageReference_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccImageReference_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccImageReference_0117 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccImageReference)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_Uri(IAccImageReference* pi, xp_str* px) { return get_Property(pi, AccImageReferenceProp_Uri, px); };
static inline HRESULT put_Uri(IAccImageReference* pi, xp_kstr x) { return put_Property(pi, AccImageReferenceProp_Uri, x); };
static inline HRESULT get_Height(IAccImageReference* pi, xp_uint* px) { return get_Property(pi, AccImageReferenceProp_Height, px); };
static inline HRESULT put_Height(IAccImageReference* pi, xp_uint x) { return put_Property(pi, AccImageReferenceProp_Height, x); };
static inline HRESULT get_Width(IAccImageReference* pi, xp_uint* px) { return get_Property(pi, AccImageReferenceProp_Width, px); };
static inline HRESULT put_Width(IAccImageReference* pi, xp_uint x) { return put_Property(pi, AccImageReferenceProp_Width, x); };
static inline HRESULT get_Tags(IAccImageReference* pi, xp_array** px) { return get_Property(pi, AccImageReferenceProp_Tags, px); };
static inline HRESULT put_Tags(IAccImageReference* pi, xp_array* x) { return put_Property(pi, AccImageReferenceProp_Tags, x); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccImageReference_0117_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccImageReference_0117_v0_0_s_ifspec;

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
