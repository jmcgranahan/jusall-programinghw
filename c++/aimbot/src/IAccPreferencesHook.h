/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Apr 25 11:36:36 2007
 */
/* Compiler settings for C:\dev\cvs\client\aimcc\idl\IAccPreferencesHook.idl:
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

#ifndef __IAccPreferencesHook_h__
#define __IAccPreferencesHook_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccPreferencesHook_FWD_DEFINED__
#define __IAccPreferencesHook_FWD_DEFINED__
typedef interface IAccPreferencesHook IAccPreferencesHook;
#endif 	/* __IAccPreferencesHook_FWD_DEFINED__ */


#ifndef __IAccPreferencesHook2_FWD_DEFINED__
#define __IAccPreferencesHook2_FWD_DEFINED__
typedef interface IAccPreferencesHook2 IAccPreferencesHook2;
#endif 	/* __IAccPreferencesHook2_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"


#ifndef __IAccPreferencesHook_INTERFACE_DEFINED__
#define __IAccPreferencesHook_INTERFACE_DEFINED__

/* interface IAccPreferencesHook */
/* [object][oleautomation][uuid] */ 


EXTERN_C const IID IID_IAccPreferencesHook;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3eb54ae3-76cf-4f47-9165-81bfb7963ed6")
    IAccPreferencesHook : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetValue( 
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
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

    typedef struct IAccPreferencesHookVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccPreferencesHook __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccPreferencesHook __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccPreferencesHook __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetValue )( 
            IAccPreferencesHook __RPC_FAR * This,
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDefaultValue )( 
            IAccPreferencesHook __RPC_FAR * This,
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetValue )( 
            IAccPreferencesHook __RPC_FAR * This,
            /* [in] */ xp_kstr specifier,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IAccPreferencesHook __RPC_FAR * This,
            /* [in] */ xp_kstr specifier);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetChildSpecifiers )( 
            IAccPreferencesHook __RPC_FAR * This,
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        END_INTERFACE
    } IAccPreferencesHookVtbl;

    interface IAccPreferencesHook
    {
        CONST_VTBL struct IAccPreferencesHookVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccPreferencesHook_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccPreferencesHook_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccPreferencesHook_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccPreferencesHook_GetValue(This,specifier,value)	\
    (This)->lpVtbl -> GetValue(This,specifier,value)

#define IAccPreferencesHook_GetDefaultValue(This,specifier,value)	\
    (This)->lpVtbl -> GetDefaultValue(This,specifier,value)

#define IAccPreferencesHook_SetValue(This,specifier,value)	\
    (This)->lpVtbl -> SetValue(This,specifier,value)

#define IAccPreferencesHook_Reset(This,specifier)	\
    (This)->lpVtbl -> Reset(This,specifier)

#define IAccPreferencesHook_GetChildSpecifiers(This,specifier,value)	\
    (This)->lpVtbl -> GetChildSpecifiers(This,specifier,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAccPreferencesHook_GetValue_Proxy( 
    IAccPreferencesHook __RPC_FAR * This,
    /* [in] */ xp_kstr specifier,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccPreferencesHook_GetValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPreferencesHook_GetDefaultValue_Proxy( 
    IAccPreferencesHook __RPC_FAR * This,
    /* [in] */ xp_kstr specifier,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccPreferencesHook_GetDefaultValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPreferencesHook_SetValue_Proxy( 
    IAccPreferencesHook __RPC_FAR * This,
    /* [in] */ xp_kstr specifier,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccPreferencesHook_SetValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPreferencesHook_Reset_Proxy( 
    IAccPreferencesHook __RPC_FAR * This,
    /* [in] */ xp_kstr specifier);


void __RPC_STUB IAccPreferencesHook_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPreferencesHook_GetChildSpecifiers_Proxy( 
    IAccPreferencesHook __RPC_FAR * This,
    /* [in] */ xp_kstr specifier,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccPreferencesHook_GetChildSpecifiers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccPreferencesHook_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccPreferencesHook_0117 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccPreferencesHook)


extern RPC_IF_HANDLE __MIDL_itf_IAccPreferencesHook_0117_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccPreferencesHook_0117_v0_0_s_ifspec;

#ifndef __IAccPreferencesHook2_INTERFACE_DEFINED__
#define __IAccPreferencesHook2_INTERFACE_DEFINED__

/* interface IAccPreferencesHook2 */
/* [object][oleautomation][uuid] */ 


EXTERN_C const IID IID_IAccPreferencesHook2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3B363576-7D8B-4b9a-A4BD-F286D816AB48")
    IAccPreferencesHook2 : public IAccPreferencesHook
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSecureValue( 
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSecureValue( 
            /* [in] */ xp_kstr specifier,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetSecure( 
            /* [in] */ xp_kstr specifier) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccPreferencesHook2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccPreferencesHook2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccPreferencesHook2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccPreferencesHook2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetValue )( 
            IAccPreferencesHook2 __RPC_FAR * This,
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDefaultValue )( 
            IAccPreferencesHook2 __RPC_FAR * This,
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetValue )( 
            IAccPreferencesHook2 __RPC_FAR * This,
            /* [in] */ xp_kstr specifier,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reset )( 
            IAccPreferencesHook2 __RPC_FAR * This,
            /* [in] */ xp_kstr specifier);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetChildSpecifiers )( 
            IAccPreferencesHook2 __RPC_FAR * This,
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSecureValue )( 
            IAccPreferencesHook2 __RPC_FAR * This,
            /* [in] */ xp_kstr specifier,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSecureValue )( 
            IAccPreferencesHook2 __RPC_FAR * This,
            /* [in] */ xp_kstr specifier,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResetSecure )( 
            IAccPreferencesHook2 __RPC_FAR * This,
            /* [in] */ xp_kstr specifier);
        
        END_INTERFACE
    } IAccPreferencesHook2Vtbl;

    interface IAccPreferencesHook2
    {
        CONST_VTBL struct IAccPreferencesHook2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccPreferencesHook2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccPreferencesHook2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccPreferencesHook2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccPreferencesHook2_GetValue(This,specifier,value)	\
    (This)->lpVtbl -> GetValue(This,specifier,value)

#define IAccPreferencesHook2_GetDefaultValue(This,specifier,value)	\
    (This)->lpVtbl -> GetDefaultValue(This,specifier,value)

#define IAccPreferencesHook2_SetValue(This,specifier,value)	\
    (This)->lpVtbl -> SetValue(This,specifier,value)

#define IAccPreferencesHook2_Reset(This,specifier)	\
    (This)->lpVtbl -> Reset(This,specifier)

#define IAccPreferencesHook2_GetChildSpecifiers(This,specifier,value)	\
    (This)->lpVtbl -> GetChildSpecifiers(This,specifier,value)


#define IAccPreferencesHook2_GetSecureValue(This,specifier,value)	\
    (This)->lpVtbl -> GetSecureValue(This,specifier,value)

#define IAccPreferencesHook2_SetSecureValue(This,specifier,value)	\
    (This)->lpVtbl -> SetSecureValue(This,specifier,value)

#define IAccPreferencesHook2_ResetSecure(This,specifier)	\
    (This)->lpVtbl -> ResetSecure(This,specifier)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAccPreferencesHook2_GetSecureValue_Proxy( 
    IAccPreferencesHook2 __RPC_FAR * This,
    /* [in] */ xp_kstr specifier,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccPreferencesHook2_GetSecureValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPreferencesHook2_SetSecureValue_Proxy( 
    IAccPreferencesHook2 __RPC_FAR * This,
    /* [in] */ xp_kstr specifier,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccPreferencesHook2_SetSecureValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPreferencesHook2_ResetSecure_Proxy( 
    IAccPreferencesHook2 __RPC_FAR * This,
    /* [in] */ xp_kstr specifier);


void __RPC_STUB IAccPreferencesHook2_ResetSecure_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccPreferencesHook2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccPreferencesHook_0118 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccPreferencesHook2)


extern RPC_IF_HANDLE __MIDL_itf_IAccPreferencesHook_0118_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccPreferencesHook_0118_v0_0_s_ifspec;

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
