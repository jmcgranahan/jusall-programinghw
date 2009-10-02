/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:44 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccPlugin.idl:
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

#ifndef __IAccPlugin_h__
#define __IAccPlugin_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccPlugin_FWD_DEFINED__
#define __IAccPlugin_FWD_DEFINED__
typedef interface IAccPlugin IAccPlugin;
#endif 	/* __IAccPlugin_FWD_DEFINED__ */


#ifndef __IAccPluginAdapter_FWD_DEFINED__
#define __IAccPluginAdapter_FWD_DEFINED__
typedef interface IAccPluginAdapter IAccPluginAdapter;
#endif 	/* __IAccPluginAdapter_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccSession.h"


#ifndef __IAccPlugin_INTERFACE_DEFINED__
#define __IAccPlugin_INTERFACE_DEFINED__

/* interface IAccPlugin */
/* [object][oleautomation][uuid] */ 


EXTERN_C const IID IID_IAccPlugin;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E49938B8-818A-457D-A6AC-B903AC26B1C8")
    IAccPlugin : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ IAccSession __RPC_FAR *session,
            /* [in] */ IAccPluginInfo __RPC_FAR *pluginInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Shutdown( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccPluginVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccPlugin __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccPlugin __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccPlugin __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Init )( 
            IAccPlugin __RPC_FAR * This,
            /* [in] */ IAccSession __RPC_FAR *session,
            /* [in] */ IAccPluginInfo __RPC_FAR *pluginInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Shutdown )( 
            IAccPlugin __RPC_FAR * This);
        
        END_INTERFACE
    } IAccPluginVtbl;

    interface IAccPlugin
    {
        CONST_VTBL struct IAccPluginVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccPlugin_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccPlugin_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccPlugin_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccPlugin_Init(This,session,pluginInfo)	\
    (This)->lpVtbl -> Init(This,session,pluginInfo)

#define IAccPlugin_Shutdown(This)	\
    (This)->lpVtbl -> Shutdown(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAccPlugin_Init_Proxy( 
    IAccPlugin __RPC_FAR * This,
    /* [in] */ IAccSession __RPC_FAR *session,
    /* [in] */ IAccPluginInfo __RPC_FAR *pluginInfo);


void __RPC_STUB IAccPlugin_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPlugin_Shutdown_Proxy( 
    IAccPlugin __RPC_FAR * This);


void __RPC_STUB IAccPlugin_Shutdown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccPlugin_INTERFACE_DEFINED__ */


#ifndef __IAccPluginAdapter_INTERFACE_DEFINED__
#define __IAccPluginAdapter_INTERFACE_DEFINED__

/* interface IAccPluginAdapter */
/* [object][hidden][oleautomation][uuid] */ 


EXTERN_C const IID IID_IAccPluginAdapter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("40DA67CB-1C81-4d9c-92BF-55CA2545DF92")
    IAccPluginAdapter : public IUnknown
    {
    public:
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_FileSpec( 
            /* [in] */ xp_kstr fileSpec) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccPluginAdapterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccPluginAdapter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccPluginAdapter __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccPluginAdapter __RPC_FAR * This);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FileSpec )( 
            IAccPluginAdapter __RPC_FAR * This,
            /* [in] */ xp_kstr fileSpec);
        
        END_INTERFACE
    } IAccPluginAdapterVtbl;

    interface IAccPluginAdapter
    {
        CONST_VTBL struct IAccPluginAdapterVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccPluginAdapter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccPluginAdapter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccPluginAdapter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccPluginAdapter_put_FileSpec(This,fileSpec)	\
    (This)->lpVtbl -> put_FileSpec(This,fileSpec)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propput] */ HRESULT STDMETHODCALLTYPE IAccPluginAdapter_put_FileSpec_Proxy( 
    IAccPluginAdapter __RPC_FAR * This,
    /* [in] */ xp_kstr fileSpec);


void __RPC_STUB IAccPluginAdapter_put_FileSpec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccPluginAdapter_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
