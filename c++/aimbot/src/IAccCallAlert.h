/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Jul 27 17:21:24 2007
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccCallAlert.idl:
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

#ifndef __IAccCallAlert_h__
#define __IAccCallAlert_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccCallAlert_FWD_DEFINED__
#define __IAccCallAlert_FWD_DEFINED__
typedef interface IAccCallAlert IAccCallAlert;
#endif 	/* __IAccCallAlert_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccAlert.h"


#ifndef __IAccCallAlert_INTERFACE_DEFINED__
#define __IAccCallAlert_INTERFACE_DEFINED__

/* interface IAccCallAlert */
/* [object][dual][uuid] */ 

typedef 
enum AccCallAlertProp
    {	AccCallAlertProp_Identifier	= 0,
	AccCallAlertProp_Timestamp	= AccCallAlertProp_Identifier + 1,
	AccCallAlertProp_PackageUrl	= AccCallAlertProp_Timestamp + 1,
	AccCallAlertProp_PackageRoot	= AccCallAlertProp_PackageUrl + 1,
	AccCallAlertProp_PackageMD5	= AccCallAlertProp_PackageRoot + 1,
	AccCallAlertProp_Height	= AccCallAlertProp_PackageMD5 + 1,
	AccCallAlertProp_Width	= AccCallAlertProp_Height + 1,
	AccCallAlertProp_NotificationType	= AccCallAlertProp_Width + 1,
	AccCallAlertProp_FormattedOriginator	= AccCallAlertProp_NotificationType + 1,
	AccCallAlertProp_CorrelatedSource	= AccCallAlertProp_FormattedOriginator + 1,
	AccCallAlertProp_Blob	= AccCallAlertProp_CorrelatedSource + 1,
	AccCallAlertProp_BlobStream	= AccCallAlertProp_Blob + 1
    }	AccCallAlertProp;


EXTERN_C const IID IID_IAccCallAlert;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8DC4561C-A038-428f-8400-A87D72B56E0E")
    IAccCallAlert : public IAccAlert
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccCallAlertProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendReply( 
            /* [in] */ xp_kvariant id,
            /* [in] */ xp_kvariant type,
            /* [in] */ xp_kvariant result,
            /* [in] */ xp_kvariant stream) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccCallAlertVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccCallAlert __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccCallAlert __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccCallAlert __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccCallAlert __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccCallAlert __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccCallAlert __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccCallAlert __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Type )( 
            IAccCallAlert __RPC_FAR * This,
            /* [retval][out] */ AccAlertType __RPC_FAR *type);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccCallAlert __RPC_FAR * This,
            /* [in] */ xp_int property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccCallAlert __RPC_FAR * This,
            /* [in] */ AccCallAlertProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SendReply )( 
            IAccCallAlert __RPC_FAR * This,
            /* [in] */ xp_kvariant id,
            /* [in] */ xp_kvariant type,
            /* [in] */ xp_kvariant result,
            /* [in] */ xp_kvariant stream);
        
        END_INTERFACE
    } IAccCallAlertVtbl;

    interface IAccCallAlert
    {
        CONST_VTBL struct IAccCallAlertVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccCallAlert_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccCallAlert_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccCallAlert_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccCallAlert_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccCallAlert_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccCallAlert_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccCallAlert_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccCallAlert_get_Type(This,type)	\
    (This)->lpVtbl -> get_Type(This,type)

#define IAccCallAlert_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)


#define IAccCallAlert_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccCallAlert_SendReply(This,id,type,result,stream)	\
    (This)->lpVtbl -> SendReply(This,id,type,result,stream)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccCallAlert_get_Property_Proxy( 
    IAccCallAlert __RPC_FAR * This,
    /* [in] */ AccCallAlertProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccCallAlert_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccCallAlert_SendReply_Proxy( 
    IAccCallAlert __RPC_FAR * This,
    /* [in] */ xp_kvariant id,
    /* [in] */ xp_kvariant type,
    /* [in] */ xp_kvariant result,
    /* [in] */ xp_kvariant stream);


void __RPC_STUB IAccCallAlert_SendReply_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccCallAlert_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccCallAlert_0121 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccCallAlert)


extern RPC_IF_HANDLE __MIDL_itf_IAccCallAlert_0121_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccCallAlert_0121_v0_0_s_ifspec;

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
