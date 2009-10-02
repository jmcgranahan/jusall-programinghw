/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Feb 11 16:20:34 2007
 */
/* Compiler settings for C:\dev\cvs\client\aimcc\idl\IAccStreamListener.idl:
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

#ifndef __IAccStreamListener_h__
#define __IAccStreamListener_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccStreamListener_FWD_DEFINED__
#define __IAccStreamListener_FWD_DEFINED__
typedef interface IAccStreamListener IAccStreamListener;
#endif 	/* __IAccStreamListener_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccStream.h"


#ifndef __IAccStreamListener_INTERFACE_DEFINED__
#define __IAccStreamListener_INTERFACE_DEFINED__

/* interface IAccStreamListener */
/* [object][dual][uuid] */ 

#include "AccDispid.h"

EXTERN_C const IID IID_IAccStreamListener;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2C3C9AB6-FB7A-473f-B632-88C28340F988")
    IAccStreamListener : public IUnknown
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OnDataAvailable( 
            /* [in] */ IAccStream __RPC_FAR *stream) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OnReadyForData( 
            /* [in] */ IAccStream __RPC_FAR *stream) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OnClosed( 
            /* [in] */ IAccStream __RPC_FAR *stream,
            /* [in] */ AccResult hr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccStreamListenerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccStreamListener __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccStreamListener __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccStreamListener __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnDataAvailable )( 
            IAccStreamListener __RPC_FAR * This,
            /* [in] */ IAccStream __RPC_FAR *stream);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnReadyForData )( 
            IAccStreamListener __RPC_FAR * This,
            /* [in] */ IAccStream __RPC_FAR *stream);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnClosed )( 
            IAccStreamListener __RPC_FAR * This,
            /* [in] */ IAccStream __RPC_FAR *stream,
            /* [in] */ AccResult hr);
        
        END_INTERFACE
    } IAccStreamListenerVtbl;

    interface IAccStreamListener
    {
        CONST_VTBL struct IAccStreamListenerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccStreamListener_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccStreamListener_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccStreamListener_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccStreamListener_OnDataAvailable(This,stream)	\
    (This)->lpVtbl -> OnDataAvailable(This,stream)

#define IAccStreamListener_OnReadyForData(This,stream)	\
    (This)->lpVtbl -> OnReadyForData(This,stream)

#define IAccStreamListener_OnClosed(This,stream,hr)	\
    (This)->lpVtbl -> OnClosed(This,stream,hr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE IAccStreamListener_OnDataAvailable_Proxy( 
    IAccStreamListener __RPC_FAR * This,
    /* [in] */ IAccStream __RPC_FAR *stream);


void __RPC_STUB IAccStreamListener_OnDataAvailable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAccStreamListener_OnReadyForData_Proxy( 
    IAccStreamListener __RPC_FAR * This,
    /* [in] */ IAccStream __RPC_FAR *stream);


void __RPC_STUB IAccStreamListener_OnReadyForData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IAccStreamListener_OnClosed_Proxy( 
    IAccStreamListener __RPC_FAR * This,
    /* [in] */ IAccStream __RPC_FAR *stream,
    /* [in] */ AccResult hr);


void __RPC_STUB IAccStreamListener_OnClosed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccStreamListener_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccStreamListener_0263 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccStreamListener)


extern RPC_IF_HANDLE __MIDL_itf_IAccStreamListener_0263_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccStreamListener_0263_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
