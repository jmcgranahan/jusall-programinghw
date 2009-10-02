/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Sep 12 14:08:10 2007
 */
/* Compiler settings for C:\dev\cvs\client\aimcc\idl\IAccAvTrack.idl:
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

#ifndef __IAccAvTrack_h__
#define __IAccAvTrack_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccAvTrack_FWD_DEFINED__
#define __IAccAvTrack_FWD_DEFINED__
typedef interface IAccAvTrack IAccAvTrack;
#endif 	/* __IAccAvTrack_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccImageReference.h"


#ifndef __IAccAvTrack_INTERFACE_DEFINED__
#define __IAccAvTrack_INTERFACE_DEFINED__

/* interface IAccAvTrack */
/* [object][dual][uuid] */ 

typedef 
enum AccAvTrackProp
    {	AccAvTrackProp_Name	= 0,
	AccAvTrackProp_Link	= AccAvTrackProp_Name + 1,
	AccAvTrackProp_ImageReferences	= AccAvTrackProp_Link + 1
    }	AccAvTrackProp;


EXTERN_C const IID IID_IAccAvTrack;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CF9E9DF0-5F28-4c22-AAD9-C52184E0ECFA")
    IAccAvTrack : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccAvTrackProp prop,
            /* [retval][out] */ xp_variant __RPC_FAR *pv) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccAvTrackProp prop,
            /* [in] */ xp_kvariant v) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccAvTrackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccAvTrack __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccAvTrack __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccAvTrack __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccAvTrack __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccAvTrack __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccAvTrack __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccAvTrack __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccAvTrack __RPC_FAR * This,
            /* [in] */ AccAvTrackProp prop,
            /* [retval][out] */ xp_variant __RPC_FAR *pv);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccAvTrack __RPC_FAR * This,
            /* [in] */ AccAvTrackProp prop,
            /* [in] */ xp_kvariant v);
        
        END_INTERFACE
    } IAccAvTrackVtbl;

    interface IAccAvTrack
    {
        CONST_VTBL struct IAccAvTrackVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccAvTrack_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccAvTrack_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccAvTrack_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccAvTrack_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccAvTrack_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccAvTrack_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccAvTrack_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccAvTrack_get_Property(This,prop,pv)	\
    (This)->lpVtbl -> get_Property(This,prop,pv)

#define IAccAvTrack_put_Property(This,prop,v)	\
    (This)->lpVtbl -> put_Property(This,prop,v)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccAvTrack_get_Property_Proxy( 
    IAccAvTrack __RPC_FAR * This,
    /* [in] */ AccAvTrackProp prop,
    /* [retval][out] */ xp_variant __RPC_FAR *pv);


void __RPC_STUB IAccAvTrack_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccAvTrack_put_Property_Proxy( 
    IAccAvTrack __RPC_FAR * This,
    /* [in] */ AccAvTrackProp prop,
    /* [in] */ xp_kvariant v);


void __RPC_STUB IAccAvTrack_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccAvTrack_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccAvTrack_0121 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccAvTrack)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_Name(IAccAvTrack* pi, xp_str* px) { return get_Property(pi, AccAvTrackProp_Name, px); };
static inline HRESULT put_Name(IAccAvTrack* pi, xp_kstr x) { return put_Property(pi, AccAvTrackProp_Name, x); };
static inline HRESULT get_Link(IAccAvTrack* pi, xp_str* px) { return get_Property(pi, AccAvTrackProp_Link, px); };
static inline HRESULT put_Link(IAccAvTrack* pi, xp_kstr x) { return put_Property(pi, AccAvTrackProp_Link, x); };
static inline HRESULT get_ImageReferences(IAccAvTrack* pi, xp_array** px) { return get_Property(pi, AccAvTrackProp_ImageReferences, px); };
static inline HRESULT put_ImageReferences(IAccAvTrack* pi, xp_array* x) { return put_Property(pi, AccAvTrackProp_ImageReferences, x); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccAvTrack_0121_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccAvTrack_0121_v0_0_s_ifspec;

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
