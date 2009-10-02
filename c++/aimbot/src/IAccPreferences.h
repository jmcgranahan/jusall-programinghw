/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Nov 19 17:21:10 2006
 */
/* Compiler settings for C:\dev\cvs\client\aimcc\idl\IAccPreferences.idl:
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

#ifndef __IAccPreferences_h__
#define __IAccPreferences_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccPreferences_FWD_DEFINED__
#define __IAccPreferences_FWD_DEFINED__
typedef interface IAccPreferences IAccPreferences;
#endif 	/* __IAccPreferences_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"


#ifndef __IAccPreferences_INTERFACE_DEFINED__
#define __IAccPreferences_INTERFACE_DEFINED__

/* interface IAccPreferences */
/* [object][dual][uuid] */ 

typedef 
enum AccPermissions
    {	AccPermissions_Ask	= 0,
	AccPermissions_RejectAll	= 1,
	AccPermissions_AcceptAll	= 2
    }	AccPermissions;

typedef 
enum AccPrivacyMode
    {	AccPrivacyMode_DenyNone	= 1,
	AccPrivacyMode_PermitNone	= 2,
	AccPrivacyMode_Permit	= 3,
	AccPrivacyMode_Deny	= 4,
	AccPrivacyMode_PermitBuddies	= 5
    }	AccPrivacyMode;

typedef 
enum AccProxyProtocol
    {	AccProxyProtocol_None	= 0,
	AccProxyProtocol_Socks4	= 1,
	AccProxyProtocol_Socks5	= 2,
	AccProxyProtocol_Http	= 3,
	AccProxyProtocol_Https	= 4
    }	AccProxyProtocol;

typedef 
enum AccRegistrationStatus
    {	AccRegistrationStatus_NoDisclosure	= 1,
	AccRegistrationStatus_LimitedDisclosure	= AccRegistrationStatus_NoDisclosure + 1,
	AccRegistrationStatus_FullDisclosure	= AccRegistrationStatus_LimitedDisclosure + 1
    }	AccRegistrationStatus;

typedef 
enum AccWebPresencePrivacyMode
    {	AccWebPresencePrivacyMode_UsePrivacyMode	= 0,
	AccWebPresencePrivacyMode_DenyNone	= 1,
	AccWebPresencePrivacyMode_PermitNone	= 2
    }	AccWebPresencePrivacyMode;


EXTERN_C const IID IID_IAccPreferences;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("61585538-c057-11d6-9158-001083341cf5")
    IAccPreferences : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetValue( 
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestValue( 
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultValue( 
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetValue( 
            /* [in] */ xp_kstr specifier,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( 
            /* [in] */ xp_kstr specifier) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetChildSpecifiers( 
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccPreferencesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccPreferences __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccPreferences __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccPreferences __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccPreferences __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccPreferences __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccPreferences __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccPreferences __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetValue )( 
            IAccPreferences __RPC_FAR * This,
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestValue )( 
            IAccPreferences __RPC_FAR * This,
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDefaultValue )( 
            IAccPreferences __RPC_FAR * This,
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetValue )( 
            IAccPreferences __RPC_FAR * This,
            /* [in] */ xp_kstr specifier,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IAccPreferences __RPC_FAR * This,
            /* [in] */ xp_kstr specifier);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetChildSpecifiers )( 
            IAccPreferences __RPC_FAR * This,
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        END_INTERFACE
    } IAccPreferencesVtbl;

    interface IAccPreferences
    {
        CONST_VTBL struct IAccPreferencesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccPreferences_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccPreferences_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccPreferences_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccPreferences_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccPreferences_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccPreferences_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccPreferences_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccPreferences_GetValue(This,specifier,value)	\
    (This)->lpVtbl -> GetValue(This,specifier,value)

#define IAccPreferences_RequestValue(This,specifier,pTransId)	\
    (This)->lpVtbl -> RequestValue(This,specifier,pTransId)

#define IAccPreferences_GetDefaultValue(This,specifier,value)	\
    (This)->lpVtbl -> GetDefaultValue(This,specifier,value)

#define IAccPreferences_SetValue(This,specifier,value)	\
    (This)->lpVtbl -> SetValue(This,specifier,value)

#define IAccPreferences_Reset(This,specifier)	\
    (This)->lpVtbl -> Reset(This,specifier)

#define IAccPreferences_GetChildSpecifiers(This,specifier,value)	\
    (This)->lpVtbl -> GetChildSpecifiers(This,specifier,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAccPreferences_GetValue_Proxy( 
    IAccPreferences __RPC_FAR * This,
    /* [in] */ xp_kstr specifier,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccPreferences_GetValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPreferences_RequestValue_Proxy( 
    IAccPreferences __RPC_FAR * This,
    /* [in] */ xp_kstr specifier,
    /* [retval][out] */ AccTransId __RPC_FAR *pTransId);


void __RPC_STUB IAccPreferences_RequestValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPreferences_GetDefaultValue_Proxy( 
    IAccPreferences __RPC_FAR * This,
    /* [in] */ xp_kstr specifier,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccPreferences_GetDefaultValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPreferences_SetValue_Proxy( 
    IAccPreferences __RPC_FAR * This,
    /* [in] */ xp_kstr specifier,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccPreferences_SetValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPreferences_Reset_Proxy( 
    IAccPreferences __RPC_FAR * This,
    /* [in] */ xp_kstr specifier);


void __RPC_STUB IAccPreferences_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPreferences_GetChildSpecifiers_Proxy( 
    IAccPreferences __RPC_FAR * This,
    /* [in] */ xp_kstr specifier,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccPreferences_GetChildSpecifiers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccPreferences_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccPreferences_0117 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccPreferences)


extern RPC_IF_HANDLE __MIDL_itf_IAccPreferences_0117_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccPreferences_0117_v0_0_s_ifspec;

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
