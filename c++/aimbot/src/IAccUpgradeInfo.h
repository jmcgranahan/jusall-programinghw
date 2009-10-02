/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:54 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccUpgradeInfo.idl:
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

#ifndef __IAccUpgradeInfo_h__
#define __IAccUpgradeInfo_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccUpgradeInfo_FWD_DEFINED__
#define __IAccUpgradeInfo_FWD_DEFINED__
typedef interface IAccUpgradeInfo IAccUpgradeInfo;
#endif 	/* __IAccUpgradeInfo_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"


#ifndef __IAccUpgradeInfo_INTERFACE_DEFINED__
#define __IAccUpgradeInfo_INTERFACE_DEFINED__

/* interface IAccUpgradeInfo */
/* [object][dual][uuid] */ 

typedef 
enum AccUpgradeInfoProp
    {	AccUpgradeInfoProp_BuildNumber	= 0,
	AccUpgradeInfoProp_DownloadUrl	= AccUpgradeInfoProp_BuildNumber + 1,
	AccUpgradeInfoProp_InfoUrl	= AccUpgradeInfoProp_DownloadUrl + 1,
	AccUpgradeInfoProp_Version	= AccUpgradeInfoProp_InfoUrl + 1
    }	AccUpgradeInfoProp;


EXTERN_C const IID IID_IAccUpgradeInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("212bdead-a5c9-49b4-88b2-13639abd4e6b")
    IAccUpgradeInfo : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccUpgradeInfoProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccUpgradeInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccUpgradeInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccUpgradeInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccUpgradeInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccUpgradeInfo __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccUpgradeInfo __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccUpgradeInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccUpgradeInfo __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccUpgradeInfo __RPC_FAR * This,
            /* [in] */ AccUpgradeInfoProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        END_INTERFACE
    } IAccUpgradeInfoVtbl;

    interface IAccUpgradeInfo
    {
        CONST_VTBL struct IAccUpgradeInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccUpgradeInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccUpgradeInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccUpgradeInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccUpgradeInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccUpgradeInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccUpgradeInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccUpgradeInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccUpgradeInfo_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccUpgradeInfo_get_Property_Proxy( 
    IAccUpgradeInfo __RPC_FAR * This,
    /* [in] */ AccUpgradeInfoProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccUpgradeInfo_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccUpgradeInfo_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccUpgradeInfo_0117 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccUpgradeInfo)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_BuildNumber(IAccUpgradeInfo* pi, xp_s32* px) { return get_Property(pi, AccUpgradeInfoProp_BuildNumber, px); };
static inline HRESULT get_DownloadUrl(IAccUpgradeInfo* pi, xp_str* px) { return get_Property(pi, AccUpgradeInfoProp_DownloadUrl, px); };
static inline HRESULT get_InfoUrl(IAccUpgradeInfo* pi, xp_str* px) { return get_Property(pi, AccUpgradeInfoProp_InfoUrl, px); };
static inline HRESULT get_Version(IAccUpgradeInfo* pi, xp_str* px) { return get_Property(pi, AccUpgradeInfoProp_Version, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccUpgradeInfo_0117_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccUpgradeInfo_0117_v0_0_s_ifspec;

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
