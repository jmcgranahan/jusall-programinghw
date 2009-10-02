/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:07 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccAccessControlHook.idl:
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

#ifndef __IAccAccessControlHook_h__
#define __IAccAccessControlHook_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccAccessControlHook_FWD_DEFINED__
#define __IAccAccessControlHook_FWD_DEFINED__
typedef interface IAccAccessControlHook IAccAccessControlHook;
#endif 	/* __IAccAccessControlHook_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccSession.h"


#ifndef __IAccAccessControlHook_INTERFACE_DEFINED__
#define __IAccAccessControlHook_INTERFACE_DEFINED__

/* interface IAccAccessControlHook */
/* [object][oleautomation][uuid] */ 


EXTERN_C const IID IID_IAccAccessControlHook;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("83A57DCF-E2F6-4e03-867D-5C7A981A5A0B")
    IAccAccessControlHook : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnAccessCheck( 
            /* [in] */ IAccSession __RPC_FAR *session,
            /* [in] */ xp_kstr userName,
            /* [in] */ xp_kvariant resource,
            /* [retval][out] */ xp_vbool __RPC_FAR *pAllow) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccAccessControlHookVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccAccessControlHook __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccAccessControlHook __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccAccessControlHook __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnAccessCheck )( 
            IAccAccessControlHook __RPC_FAR * This,
            /* [in] */ IAccSession __RPC_FAR *session,
            /* [in] */ xp_kstr userName,
            /* [in] */ xp_kvariant resource,
            /* [retval][out] */ xp_vbool __RPC_FAR *pAllow);
        
        END_INTERFACE
    } IAccAccessControlHookVtbl;

    interface IAccAccessControlHook
    {
        CONST_VTBL struct IAccAccessControlHookVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccAccessControlHook_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccAccessControlHook_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccAccessControlHook_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccAccessControlHook_OnAccessCheck(This,session,userName,resource,pAllow)	\
    (This)->lpVtbl -> OnAccessCheck(This,session,userName,resource,pAllow)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAccAccessControlHook_OnAccessCheck_Proxy( 
    IAccAccessControlHook __RPC_FAR * This,
    /* [in] */ IAccSession __RPC_FAR *session,
    /* [in] */ xp_kstr userName,
    /* [in] */ xp_kvariant resource,
    /* [retval][out] */ xp_vbool __RPC_FAR *pAllow);


void __RPC_STUB IAccAccessControlHook_OnAccessCheck_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccAccessControlHook_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccAccessControlHook_0346 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccAccessControlHook)


extern RPC_IF_HANDLE __MIDL_itf_IAccAccessControlHook_0346_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccAccessControlHook_0346_v0_0_s_ifspec;

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
