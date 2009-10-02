/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Feb 27 08:15:07 2008
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccImSummary.idl:
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

#ifndef __IAccImSummary_h__
#define __IAccImSummary_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccImSummary_FWD_DEFINED__
#define __IAccImSummary_FWD_DEFINED__
typedef interface IAccImSummary IAccImSummary;
#endif 	/* __IAccImSummary_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"


#ifndef __IAccImSummary_INTERFACE_DEFINED__
#define __IAccImSummary_INTERFACE_DEFINED__

/* interface IAccImSummary */
/* [object][dual][uuid] */ 

typedef 
enum AccImSummaryProp
    {	AccImSummaryProp_Id	= 0,
	AccImSummaryProp_Sender	= AccImSummaryProp_Id + 1,
	AccImSummaryProp_Timestamp	= AccImSummaryProp_Sender + 1
    }	AccImSummaryProp;


EXTERN_C const IID IID_IAccImSummary;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("627590AD-2DB2-43b8-9E58-D3546136355A")
    IAccImSummary : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            AccImSummaryProp __MIDL_0011,
            xp_variant __RPC_FAR *__MIDL_0012) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            AccImSummaryProp __MIDL_0013,
            xp_kvariant __MIDL_0014) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccImSummaryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccImSummary __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccImSummary __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccImSummary __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccImSummary __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccImSummary __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccImSummary __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccImSummary __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccImSummary __RPC_FAR * This,
            AccImSummaryProp __MIDL_0011,
            xp_variant __RPC_FAR *__MIDL_0012);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccImSummary __RPC_FAR * This,
            AccImSummaryProp __MIDL_0013,
            xp_kvariant __MIDL_0014);
        
        END_INTERFACE
    } IAccImSummaryVtbl;

    interface IAccImSummary
    {
        CONST_VTBL struct IAccImSummaryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccImSummary_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccImSummary_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccImSummary_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccImSummary_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccImSummary_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccImSummary_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccImSummary_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccImSummary_get_Property(This,__MIDL_0011,__MIDL_0012)	\
    (This)->lpVtbl -> get_Property(This,__MIDL_0011,__MIDL_0012)

#define IAccImSummary_put_Property(This,__MIDL_0013,__MIDL_0014)	\
    (This)->lpVtbl -> put_Property(This,__MIDL_0013,__MIDL_0014)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccImSummary_get_Property_Proxy( 
    IAccImSummary __RPC_FAR * This,
    AccImSummaryProp __MIDL_0011,
    xp_variant __RPC_FAR *__MIDL_0012);


void __RPC_STUB IAccImSummary_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccImSummary_put_Property_Proxy( 
    IAccImSummary __RPC_FAR * This,
    AccImSummaryProp __MIDL_0013,
    xp_kvariant __MIDL_0014);


void __RPC_STUB IAccImSummary_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccImSummary_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccImSummary_0117 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccImSummary)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_Id(IAccImSummary* pi, xp_u32* px) { return get_Property(pi, AccImSummaryProp_Id, px); };
static inline HRESULT get_Sender(IAccImSummary* pi, xp_str* px) { return get_Property(pi, AccImSummaryProp_Sender, px); };
static inline HRESULT get_Timestamp(IAccImSummary* pi, xp_date* px) { return get_PropertyDate(pi, AccImSummaryProp_Timestamp, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccImSummary_0117_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccImSummary_0117_v0_0_s_ifspec;

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
