/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Jul 05 12:07:06 2007
 */
/* Compiler settings for C:\cvs_source\aimcc\idl\IAccCallAlertControlHook.idl:
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

#ifndef __IAccCallAlertControlHook_h__
#define __IAccCallAlertControlHook_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccCallAlertControlHook_FWD_DEFINED__
#define __IAccCallAlertControlHook_FWD_DEFINED__
typedef interface IAccCallAlertControlHook IAccCallAlertControlHook;
#endif 	/* __IAccCallAlertControlHook_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccSession.h"


#ifndef __IAccCallAlertControlHook_INTERFACE_DEFINED__
#define __IAccCallAlertControlHook_INTERFACE_DEFINED__

/* interface IAccCallAlertControlHook */
/* [object][oleautomation][uuid] */ 


EXTERN_C const IID IID_IAccCallAlertControlHook;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D43B8FD2-BA46-4e21-87BA-C37EE26BFAF3")
    IAccCallAlertControlHook : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnCallAlertSendResult( 
            /* [in] */ IAccSession __RPC_FAR *session,
            /* [in] */ HRESULT result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccCallAlertControlHookVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccCallAlertControlHook __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccCallAlertControlHook __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccCallAlertControlHook __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnCallAlertSendResult )( 
            IAccCallAlertControlHook __RPC_FAR * This,
            /* [in] */ IAccSession __RPC_FAR *session,
            /* [in] */ HRESULT result);
        
        END_INTERFACE
    } IAccCallAlertControlHookVtbl;

    interface IAccCallAlertControlHook
    {
        CONST_VTBL struct IAccCallAlertControlHookVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccCallAlertControlHook_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccCallAlertControlHook_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccCallAlertControlHook_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccCallAlertControlHook_OnCallAlertSendResult(This,session,result)	\
    (This)->lpVtbl -> OnCallAlertSendResult(This,session,result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAccCallAlertControlHook_OnCallAlertSendResult_Proxy( 
    IAccCallAlertControlHook __RPC_FAR * This,
    /* [in] */ IAccSession __RPC_FAR *session,
    /* [in] */ HRESULT result);


void __RPC_STUB IAccCallAlertControlHook_OnCallAlertSendResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccCallAlertControlHook_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccCallAlertControlHook_0358 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccCallAlertControlHook)


extern RPC_IF_HANDLE __MIDL_itf_IAccCallAlertControlHook_0358_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccCallAlertControlHook_0358_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
