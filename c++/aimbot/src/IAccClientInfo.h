/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:24 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccClientInfo.idl:
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

#ifndef __IAccClientInfo_h__
#define __IAccClientInfo_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccClientInfo_FWD_DEFINED__
#define __IAccClientInfo_FWD_DEFINED__
typedef interface IAccClientInfo IAccClientInfo;
#endif 	/* __IAccClientInfo_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"


#ifndef __IAccClientInfo_INTERFACE_DEFINED__
#define __IAccClientInfo_INTERFACE_DEFINED__

/* interface IAccClientInfo */
/* [object][dual][uuid] */ 

typedef 
enum AccClientInfoProp
    {	AccClientInfoProp_Description	= 0,
	AccClientInfoProp_DistributionChannel	= 2,
	AccClientInfoProp_MajorVersion	= 8,
	AccClientInfoProp_MinorVersion	= AccClientInfoProp_MajorVersion + 1,
	AccClientInfoProp_PointVersion	= AccClientInfoProp_MinorVersion + 1,
	AccClientInfoProp_BuildNumber	= AccClientInfoProp_PointVersion + 1,
	AccClientInfoProp_Language	= 16,
	AccClientInfoProp_Country	= AccClientInfoProp_Language + 1
    }	AccClientInfoProp;


EXTERN_C const IID IID_IAccClientInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("f9447410-fa9f-4ac3-987b-aae41c1756ce")
    IAccClientInfo : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccClientInfoProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccClientInfoProp property,
            /* [in] */ xp_kvariant value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccClientInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccClientInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccClientInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccClientInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccClientInfo __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccClientInfo __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccClientInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccClientInfo __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccClientInfo __RPC_FAR * This,
            /* [in] */ AccClientInfoProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccClientInfo __RPC_FAR * This,
            /* [in] */ AccClientInfoProp property,
            /* [in] */ xp_kvariant value);
        
        END_INTERFACE
    } IAccClientInfoVtbl;

    interface IAccClientInfo
    {
        CONST_VTBL struct IAccClientInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccClientInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccClientInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccClientInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccClientInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccClientInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccClientInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccClientInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccClientInfo_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccClientInfo_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccClientInfo_get_Property_Proxy( 
    IAccClientInfo __RPC_FAR * This,
    /* [in] */ AccClientInfoProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccClientInfo_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccClientInfo_put_Property_Proxy( 
    IAccClientInfo __RPC_FAR * This,
    /* [in] */ AccClientInfoProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccClientInfo_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccClientInfo_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccClientInfo_0117 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccClientInfo)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_Description(IAccClientInfo* pi, xp_str* px) { return get_Property(pi, AccClientInfoProp_Description, px); };
static inline HRESULT put_Description(IAccClientInfo* pi, xp_kstr x) { return put_Property(pi, AccClientInfoProp_Description, x); };
static inline HRESULT get_DistributionChannel(IAccClientInfo* pi, xp_s32* px) { return get_Property(pi, AccClientInfoProp_DistributionChannel, px); };
static inline HRESULT put_DistributionChannel(IAccClientInfo* pi, xp_s32 x) { return put_Property(pi, AccClientInfoProp_DistributionChannel, x); };
static inline HRESULT get_MajorVersion(IAccClientInfo* pi, xp_s32* px) { return get_Property(pi, AccClientInfoProp_MajorVersion, px); };
static inline HRESULT put_MajorVersion(IAccClientInfo* pi, xp_s32 x) { return put_Property(pi, AccClientInfoProp_MajorVersion, x); };
static inline HRESULT get_MinorVersion(IAccClientInfo* pi, xp_s32* px) { return get_Property(pi, AccClientInfoProp_MinorVersion, px); };
static inline HRESULT put_MinorVersion(IAccClientInfo* pi, xp_s32 x) { return put_Property(pi, AccClientInfoProp_MinorVersion, x); };
static inline HRESULT get_PointVersion(IAccClientInfo* pi, xp_s32* px) { return get_Property(pi, AccClientInfoProp_PointVersion, px); };
static inline HRESULT put_PointVersion(IAccClientInfo* pi, xp_s32 x) { return put_Property(pi, AccClientInfoProp_PointVersion, x); };
static inline HRESULT get_BuildNumber(IAccClientInfo* pi, xp_s32* px) { return get_Property(pi, AccClientInfoProp_BuildNumber, px); };
static inline HRESULT put_BuildNumber(IAccClientInfo* pi, xp_s32 x) { return put_Property(pi, AccClientInfoProp_BuildNumber, x); };
static inline HRESULT get_Language(IAccClientInfo* pi, xp_str* px) { return get_Property(pi, AccClientInfoProp_Language, px); };
static inline HRESULT put_Language(IAccClientInfo* pi, xp_kstr x) { return put_Property(pi, AccClientInfoProp_Language, x); };
static inline HRESULT get_Country(IAccClientInfo* pi, xp_str* px) { return get_Property(pi, AccClientInfoProp_Country, px); };
static inline HRESULT put_Country(IAccClientInfo* pi, xp_kstr x) { return put_Property(pi, AccClientInfoProp_Country, x); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccClientInfo_0117_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccClientInfo_0117_v0_0_s_ifspec;

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
