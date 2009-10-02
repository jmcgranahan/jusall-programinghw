/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Feb 27 08:14:46 2008
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccCommandTarget.idl:
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

#ifndef __IAccCommandTarget_h__
#define __IAccCommandTarget_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccCommandTarget_FWD_DEFINED__
#define __IAccCommandTarget_FWD_DEFINED__
typedef interface IAccCommandTarget IAccCommandTarget;
#endif 	/* __IAccCommandTarget_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"


#ifndef __IAccCommandTarget_INTERFACE_DEFINED__
#define __IAccCommandTarget_INTERFACE_DEFINED__

/* interface IAccCommandTarget */
/* [object][oleautomation][uuid] */ 


EXTERN_C const IID IID_IAccCommandTarget;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2508F89B-E84C-4d6d-B475-0F0F41F17EC3")
    IAccCommandTarget : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryStatus( 
            /* [in] */ xp_int command,
            /* [in] */ xp_kvariant names,
            /* [retval][out] */ xp_vbool __RPC_FAR *enabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Exec( 
            /* [in] */ xp_int command,
            /* [in] */ xp_kvariant names) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccCommandTargetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccCommandTarget __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccCommandTarget __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccCommandTarget __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryStatus )( 
            IAccCommandTarget __RPC_FAR * This,
            /* [in] */ xp_int command,
            /* [in] */ xp_kvariant names,
            /* [retval][out] */ xp_vbool __RPC_FAR *enabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Exec )( 
            IAccCommandTarget __RPC_FAR * This,
            /* [in] */ xp_int command,
            /* [in] */ xp_kvariant names);
        
        END_INTERFACE
    } IAccCommandTargetVtbl;

    interface IAccCommandTarget
    {
        CONST_VTBL struct IAccCommandTargetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccCommandTarget_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccCommandTarget_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccCommandTarget_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccCommandTarget_QueryStatus(This,command,names,enabled)	\
    (This)->lpVtbl -> QueryStatus(This,command,names,enabled)

#define IAccCommandTarget_Exec(This,command,names)	\
    (This)->lpVtbl -> Exec(This,command,names)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAccCommandTarget_QueryStatus_Proxy( 
    IAccCommandTarget __RPC_FAR * This,
    /* [in] */ xp_int command,
    /* [in] */ xp_kvariant names,
    /* [retval][out] */ xp_vbool __RPC_FAR *enabled);


void __RPC_STUB IAccCommandTarget_QueryStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccCommandTarget_Exec_Proxy( 
    IAccCommandTarget __RPC_FAR * This,
    /* [in] */ xp_int command,
    /* [in] */ xp_kvariant names);


void __RPC_STUB IAccCommandTarget_Exec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccCommandTarget_INTERFACE_DEFINED__ */


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
