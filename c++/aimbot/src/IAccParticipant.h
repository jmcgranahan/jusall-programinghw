/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:43 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccParticipant.idl:
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

#ifndef __IAccParticipant_h__
#define __IAccParticipant_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccParticipant_FWD_DEFINED__
#define __IAccParticipant_FWD_DEFINED__
typedef interface IAccParticipant IAccParticipant;
#endif 	/* __IAccParticipant_FWD_DEFINED__ */


/* header files for imported files */
#include "IAccUser.h"


#ifndef __IAccParticipant_INTERFACE_DEFINED__
#define __IAccParticipant_INTERFACE_DEFINED__

/* interface IAccParticipant */
/* [object][dual][uuid] */ 

typedef 
enum AccParticipantState
    {	AccParticipantState_Offline	= 0,
	AccParticipantState_Online	= 500,
	AccParticipantState_Paused	= 600
    }	AccParticipantState;

typedef 
enum AccParticipantProp
    {	AccParticipantProp_State	= 0,
	AccParticipantProp_Owner	= AccParticipantProp_State + 1
    }	AccParticipantProp;


EXTERN_C const IID IID_IAccParticipant;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("53780D28-3F9B-407C-9F55-FE3EA90091FB")
    IAccParticipant : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ xp_str __RPC_FAR *pName) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_User( 
            /* [retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *user) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccParticipantProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccParticipantProp property,
            /* [in] */ xp_kvariant value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccParticipantVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccParticipant __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccParticipant __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccParticipant __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccParticipant __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccParticipant __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccParticipant __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccParticipant __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IAccParticipant __RPC_FAR * This,
            /* [retval][out] */ xp_str __RPC_FAR *pName);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_User )( 
            IAccParticipant __RPC_FAR * This,
            /* [retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *user);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccParticipant __RPC_FAR * This,
            /* [in] */ AccParticipantProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccParticipant __RPC_FAR * This,
            /* [in] */ AccParticipantProp property,
            /* [in] */ xp_kvariant value);
        
        END_INTERFACE
    } IAccParticipantVtbl;

    interface IAccParticipant
    {
        CONST_VTBL struct IAccParticipantVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccParticipant_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccParticipant_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccParticipant_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccParticipant_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccParticipant_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccParticipant_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccParticipant_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccParticipant_get_Name(This,pName)	\
    (This)->lpVtbl -> get_Name(This,pName)

#define IAccParticipant_get_User(This,user)	\
    (This)->lpVtbl -> get_User(This,user)

#define IAccParticipant_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccParticipant_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccParticipant_get_Name_Proxy( 
    IAccParticipant __RPC_FAR * This,
    /* [retval][out] */ xp_str __RPC_FAR *pName);


void __RPC_STUB IAccParticipant_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccParticipant_get_User_Proxy( 
    IAccParticipant __RPC_FAR * This,
    /* [retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *user);


void __RPC_STUB IAccParticipant_get_User_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccParticipant_get_Property_Proxy( 
    IAccParticipant __RPC_FAR * This,
    /* [in] */ AccParticipantProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccParticipant_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccParticipant_put_Property_Proxy( 
    IAccParticipant __RPC_FAR * This,
    /* [in] */ AccParticipantProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccParticipant_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccParticipant_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccParticipant_0345 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccParticipant)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_State(IAccParticipant* pi, AccParticipantState* px) { return get_Property(pi, AccParticipantProp_State, (xp_s32*)px); };
static inline HRESULT get_Owner(IAccParticipant* pi, xp_bool* px) { return get_Property(pi, AccParticipantProp_Owner, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccParticipant_0345_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccParticipant_0345_v0_0_s_ifspec;

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
