/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:46 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccPluginManager.idl:
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

#ifndef __IAccPluginManager_h__
#define __IAccPluginManager_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccPluginManager_FWD_DEFINED__
#define __IAccPluginManager_FWD_DEFINED__
typedef interface IAccPluginManager IAccPluginManager;
#endif 	/* __IAccPluginManager_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccPluginInfo.h"


#ifndef __IAccPluginManager_INTERFACE_DEFINED__
#define __IAccPluginManager_INTERFACE_DEFINED__

/* interface IAccPluginManager */
/* [object][dual][uuid] */ 


EXTERN_C const IID IID_IAccPluginManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5B1AF4E2-09EF-49BE-AE79-3016070B6CB4")
    IAccPluginManager : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetInstalledPlugins( 
            /* [retval][out] */ xp_variant __RPC_FAR *pluginInfos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPluginByUuid( 
            /* [in] */ xp_kstr uuid,
            /* [retval][out] */ IAccPluginInfo __RPC_FAR *__RPC_FAR *pluginInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnabledPlugins( 
            /* [retval][out] */ xp_variant __RPC_FAR *pluginInfos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnablePlugin( 
            /* [in] */ xp_kstr uuid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisablePlugin( 
            /* [in] */ xp_kstr uuid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryCommandStatus( 
            /* [in] */ xp_kstr uuid,
            /* [in] */ xp_int command,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExecCommand( 
            /* [in] */ xp_kstr uuid,
            /* [in] */ xp_int command,
            /* [in] */ xp_kvariant value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccPluginManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccPluginManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccPluginManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccPluginManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccPluginManager __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccPluginManager __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccPluginManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccPluginManager __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInstalledPlugins )( 
            IAccPluginManager __RPC_FAR * This,
            /* [retval][out] */ xp_variant __RPC_FAR *pluginInfos);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPluginByUuid )( 
            IAccPluginManager __RPC_FAR * This,
            /* [in] */ xp_kstr uuid,
            /* [retval][out] */ IAccPluginInfo __RPC_FAR *__RPC_FAR *pluginInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabledPlugins )( 
            IAccPluginManager __RPC_FAR * This,
            /* [retval][out] */ xp_variant __RPC_FAR *pluginInfos);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnablePlugin )( 
            IAccPluginManager __RPC_FAR * This,
            /* [in] */ xp_kstr uuid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DisablePlugin )( 
            IAccPluginManager __RPC_FAR * This,
            /* [in] */ xp_kstr uuid);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryCommandStatus )( 
            IAccPluginManager __RPC_FAR * This,
            /* [in] */ xp_kstr uuid,
            /* [in] */ xp_int command,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExecCommand )( 
            IAccPluginManager __RPC_FAR * This,
            /* [in] */ xp_kstr uuid,
            /* [in] */ xp_int command,
            /* [in] */ xp_kvariant value);
        
        END_INTERFACE
    } IAccPluginManagerVtbl;

    interface IAccPluginManager
    {
        CONST_VTBL struct IAccPluginManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccPluginManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccPluginManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccPluginManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccPluginManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccPluginManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccPluginManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccPluginManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccPluginManager_GetInstalledPlugins(This,pluginInfos)	\
    (This)->lpVtbl -> GetInstalledPlugins(This,pluginInfos)

#define IAccPluginManager_GetPluginByUuid(This,uuid,pluginInfo)	\
    (This)->lpVtbl -> GetPluginByUuid(This,uuid,pluginInfo)

#define IAccPluginManager_GetEnabledPlugins(This,pluginInfos)	\
    (This)->lpVtbl -> GetEnabledPlugins(This,pluginInfos)

#define IAccPluginManager_EnablePlugin(This,uuid)	\
    (This)->lpVtbl -> EnablePlugin(This,uuid)

#define IAccPluginManager_DisablePlugin(This,uuid)	\
    (This)->lpVtbl -> DisablePlugin(This,uuid)

#define IAccPluginManager_QueryCommandStatus(This,uuid,command,value)	\
    (This)->lpVtbl -> QueryCommandStatus(This,uuid,command,value)

#define IAccPluginManager_ExecCommand(This,uuid,command,value)	\
    (This)->lpVtbl -> ExecCommand(This,uuid,command,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAccPluginManager_GetInstalledPlugins_Proxy( 
    IAccPluginManager __RPC_FAR * This,
    /* [retval][out] */ xp_variant __RPC_FAR *pluginInfos);


void __RPC_STUB IAccPluginManager_GetInstalledPlugins_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPluginManager_GetPluginByUuid_Proxy( 
    IAccPluginManager __RPC_FAR * This,
    /* [in] */ xp_kstr uuid,
    /* [retval][out] */ IAccPluginInfo __RPC_FAR *__RPC_FAR *pluginInfo);


void __RPC_STUB IAccPluginManager_GetPluginByUuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPluginManager_GetEnabledPlugins_Proxy( 
    IAccPluginManager __RPC_FAR * This,
    /* [retval][out] */ xp_variant __RPC_FAR *pluginInfos);


void __RPC_STUB IAccPluginManager_GetEnabledPlugins_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPluginManager_EnablePlugin_Proxy( 
    IAccPluginManager __RPC_FAR * This,
    /* [in] */ xp_kstr uuid);


void __RPC_STUB IAccPluginManager_EnablePlugin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPluginManager_DisablePlugin_Proxy( 
    IAccPluginManager __RPC_FAR * This,
    /* [in] */ xp_kstr uuid);


void __RPC_STUB IAccPluginManager_DisablePlugin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPluginManager_QueryCommandStatus_Proxy( 
    IAccPluginManager __RPC_FAR * This,
    /* [in] */ xp_kstr uuid,
    /* [in] */ xp_int command,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccPluginManager_QueryCommandStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPluginManager_ExecCommand_Proxy( 
    IAccPluginManager __RPC_FAR * This,
    /* [in] */ xp_kstr uuid,
    /* [in] */ xp_int command,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccPluginManager_ExecCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccPluginManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccPluginManager_0125 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccPluginManager)


extern RPC_IF_HANDLE __MIDL_itf_IAccPluginManager_0125_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccPluginManager_0125_v0_0_s_ifspec;

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
