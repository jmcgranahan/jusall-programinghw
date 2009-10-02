/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri May 25 14:14:39 2007
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccServiceTicket.idl:
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

#ifndef __IAccServiceTicket_h__
#define __IAccServiceTicket_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccServiceTicket_FWD_DEFINED__
#define __IAccServiceTicket_FWD_DEFINED__
typedef interface IAccServiceTicket IAccServiceTicket;
#endif 	/* __IAccServiceTicket_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccStream.h"


#ifndef __IAccServiceTicket_INTERFACE_DEFINED__
#define __IAccServiceTicket_INTERFACE_DEFINED__

/* interface IAccServiceTicket */
/* [object][dual][uuid] */ 

typedef 
enum AccServiceTicketVersion
    {	AccServiceTicketVersion_KRB_V5	= 5,
	AccServiceTicketVersion_REF_V1	= -1001
    }	AccServiceTicketVersion;

typedef 
enum AccServiceTicketProp
    {	AccServiceTicketProp_Identity	= 0,
	AccServiceTicketProp_Service	= AccServiceTicketProp_Identity + 1,
	AccServiceTicketProp_ServerRealm	= AccServiceTicketProp_Service + 1,
	AccServiceTicketProp_Version	= AccServiceTicketProp_ServerRealm + 1,
	AccServiceTicketProp_UrlEncodedString	= AccServiceTicketProp_Version + 1,
	AccServiceTicketProp_Ticket	= 100,
	AccServiceTicketProp_TicketStream	= AccServiceTicketProp_Ticket + 1,
	AccServiceTicketProp_TicketBase64	= AccServiceTicketProp_TicketStream + 1,
	AccServiceTicketProp_Authenticator	= 200,
	AccServiceTicketProp_AuthenticatorStream	= AccServiceTicketProp_Authenticator + 1,
	AccServiceTicketProp_AuthenticatorBase64	= AccServiceTicketProp_AuthenticatorStream + 1
    }	AccServiceTicketProp;


EXTERN_C const IID IID_IAccServiceTicket;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("baa47cc8-0f44-4467-ae0d-6621c2d2ef20")
    IAccServiceTicket : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccServiceTicketProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccServiceTicketProp property,
            /* [in] */ xp_kvariant value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccServiceTicketVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccServiceTicket __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccServiceTicket __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccServiceTicket __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccServiceTicket __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccServiceTicket __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccServiceTicket __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccServiceTicket __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccServiceTicket __RPC_FAR * This,
            /* [in] */ AccServiceTicketProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccServiceTicket __RPC_FAR * This,
            /* [in] */ AccServiceTicketProp property,
            /* [in] */ xp_kvariant value);
        
        END_INTERFACE
    } IAccServiceTicketVtbl;

    interface IAccServiceTicket
    {
        CONST_VTBL struct IAccServiceTicketVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccServiceTicket_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccServiceTicket_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccServiceTicket_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccServiceTicket_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccServiceTicket_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccServiceTicket_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccServiceTicket_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccServiceTicket_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccServiceTicket_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccServiceTicket_get_Property_Proxy( 
    IAccServiceTicket __RPC_FAR * This,
    /* [in] */ AccServiceTicketProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccServiceTicket_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccServiceTicket_put_Property_Proxy( 
    IAccServiceTicket __RPC_FAR * This,
    /* [in] */ AccServiceTicketProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccServiceTicket_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccServiceTicket_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccServiceTicket_0263 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccServiceTicket)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_Identity(IAccServiceTicket* pi, xp_str* px) { return get_Property(pi, AccServiceTicketProp_Identity, px); };
static inline HRESULT get_Service(IAccServiceTicket* pi, xp_str* px) { return get_Property(pi, AccServiceTicketProp_Service, px); };
static inline HRESULT get_ServerRealm(IAccServiceTicket* pi, xp_str* px) { return get_Property(pi, AccServiceTicketProp_ServerRealm, px); };
static inline HRESULT get_Version(IAccServiceTicket* pi, AccServiceTicketVersion* px) { return get_Property(pi, AccServiceTicketProp_Version, (xp_s32*)px); };
static inline HRESULT get_UrlEncodedString(IAccServiceTicket* pi, xp_str* px) { return get_Property(pi, AccServiceTicketProp_UrlEncodedString, px); };
static inline HRESULT get_Ticket(IAccServiceTicket* pi, xp_array** px) { return get_Property(pi, AccServiceTicketProp_Ticket, px); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_TicketStream(IAccServiceTicket* pi, IAccStream** px) { return get_Property(pi, AccServiceTicketProp_TicketStream, IID_IAccStream, px); };
#endif
static inline HRESULT get_TicketBase64(IAccServiceTicket* pi, xp_str* px) { return get_Property(pi, AccServiceTicketProp_TicketBase64, px); };
static inline HRESULT get_Authenticator(IAccServiceTicket* pi, xp_array** px) { return get_Property(pi, AccServiceTicketProp_Authenticator, px); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_AuthenticatorStream(IAccServiceTicket* pi, IAccStream** px) { return get_Property(pi, AccServiceTicketProp_AuthenticatorStream, IID_IAccStream, px); };
#endif
static inline HRESULT get_AuthenticatorBase64(IAccServiceTicket* pi, xp_str* px) { return get_Property(pi, AccServiceTicketProp_AuthenticatorBase64, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccServiceTicket_0263_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccServiceTicket_0263_v0_0_s_ifspec;

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
