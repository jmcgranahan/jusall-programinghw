/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:40 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccInstance.idl:
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

#ifndef __IAccInstance_h__
#define __IAccInstance_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccInstance_FWD_DEFINED__
#define __IAccInstance_FWD_DEFINED__
typedef interface IAccInstance IAccInstance;
#endif 	/* __IAccInstance_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"


#ifndef __IAccInstance_INTERFACE_DEFINED__
#define __IAccInstance_INTERFACE_DEFINED__

/* interface IAccInstance */
/* [object][dual][uuid] */ 

typedef 
enum AccInstanceProp
    {	AccInstanceProp_Id	= 0,
	AccInstanceProp_State	= AccInstanceProp_Id + 1,
	AccInstanceProp_OnlineTime	= AccInstanceProp_State + 1,
	AccInstanceProp_IpAddress	= AccInstanceProp_OnlineTime + 1,
	AccInstanceProp_Port	= AccInstanceProp_IpAddress + 1,
	AccInstanceProp_Flags	= AccInstanceProp_Port + 1
    }	AccInstanceProp;


EXTERN_C const IID IID_IAccInstance;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ebe4eb0c-a31e-42d1-95e4-b1ccde18e69d")
    IAccInstance : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ xp_int __RPC_FAR *id) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccInstanceProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccInstanceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccInstance __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccInstance __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccInstance __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccInstance __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccInstance __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccInstance __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccInstance __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Id )( 
            IAccInstance __RPC_FAR * This,
            /* [retval][out] */ xp_int __RPC_FAR *id);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccInstance __RPC_FAR * This,
            /* [in] */ AccInstanceProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        END_INTERFACE
    } IAccInstanceVtbl;

    interface IAccInstance
    {
        CONST_VTBL struct IAccInstanceVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccInstance_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccInstance_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccInstance_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccInstance_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccInstance_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccInstance_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccInstance_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccInstance_get_Id(This,id)	\
    (This)->lpVtbl -> get_Id(This,id)

#define IAccInstance_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IAccInstance_get_Id_Proxy( 
    IAccInstance __RPC_FAR * This,
    /* [retval][out] */ xp_int __RPC_FAR *id);


void __RPC_STUB IAccInstance_get_Id_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccInstance_get_Property_Proxy( 
    IAccInstance __RPC_FAR * This,
    /* [in] */ AccInstanceProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccInstance_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccInstance_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccInstance_0117 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccInstance)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_Id(IAccInstance* pi, xp_s32* px) { return get_Property(pi, AccInstanceProp_Id, px); };
static inline HRESULT get_State(IAccInstance* pi, AccUserState* px) { return get_Property(pi, AccInstanceProp_State, (xp_s32*)px); };
static inline HRESULT get_OnlineTime(IAccInstance* pi, xp_s32* px) { return get_Property(pi, AccInstanceProp_OnlineTime, px); };
static inline HRESULT get_IpAddress(IAccInstance* pi, xp_str* px) { return get_Property(pi, AccInstanceProp_IpAddress, px); };
static inline HRESULT get_Port(IAccInstance* pi, xp_s32* px) { return get_Property(pi, AccInstanceProp_Port, px); };
static inline HRESULT get_Flags(IAccInstance* pi, xp_u32* px) { return get_Property(pi, AccInstanceProp_Flags, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccInstance_0117_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccInstance_0117_v0_0_s_ifspec;

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
