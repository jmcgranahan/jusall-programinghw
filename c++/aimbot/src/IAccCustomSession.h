/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Aug 02 16:40:54 2006
 */
/* Compiler settings for C:\work\aimcc\cvs\aimcc\idl\IAccCustomSession.idl:
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

#ifndef __IAccCustomSession_h__
#define __IAccCustomSession_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccCustomSession_FWD_DEFINED__
#define __IAccCustomSession_FWD_DEFINED__
typedef interface IAccCustomSession IAccCustomSession;
#endif 	/* __IAccCustomSession_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccSecondarySession.h"
#include "IAccStream.h"
#include "IAccIm.h"


#ifndef __IAccCustomSession_INTERFACE_DEFINED__
#define __IAccCustomSession_INTERFACE_DEFINED__

/* interface IAccCustomSession */
/* [object][dual][uuid] */ 

typedef 
enum AccCustomSessionMode
    {	AccCustomSessionMode_OfferAnswer	= 0,
	AccCustomSessionMode_Streams	= AccCustomSessionMode_OfferAnswer + 1,
	AccCustomSessionMode_Message	= AccCustomSessionMode_Streams + 1
    }	AccCustomSessionMode;

typedef 
enum AccCustomSessionProp
    {	AccCustomSessionProp_Uuid	= 1000,
	AccCustomSessionProp_Mode	= AccCustomSessionProp_Uuid + 1,
	AccCustomSessionProp_InvitationData	= AccCustomSessionProp_Mode + 1
    }	AccCustomSessionProp;


EXTERN_C const IID IID_IAccCustomSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a3119b1a-0f83-4496-9c2d-b280d09a0b8b")
    IAccCustomSession : public IAccSecondarySession
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SendData( 
            /* [in] */ xp_kstr toName,
            /* [in] */ xp_int streamId,
            /* [in] */ IAccIm __RPC_FAR *im) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStream( 
            /* [in] */ xp_kstr reserved,
            /* [in] */ xp_int streamId,
            /* [out] */ IAccStream __RPC_FAR *__RPC_FAR *pp) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccCustomSessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccCustomSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccCustomSession __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccCustomSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccCustomSession __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccCustomSession __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccCustomSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccCustomSession __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ServiceId )( 
            IAccCustomSession __RPC_FAR * This,
            /* [retval][out] */ AccSecondarySessionServiceId __RPC_FAR *pId);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccCustomSession __RPC_FAR * This,
            /* [in] */ xp_int property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccCustomSession __RPC_FAR * This,
            /* [in] */ xp_int property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Accept )( 
            IAccCustomSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reject )( 
            IAccCustomSession __RPC_FAR * This,
            /* [defaultvalue][in] */ xp_int reason);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invite )( 
            IAccCustomSession __RPC_FAR * This,
            /* [in] */ xp_kstr invitee,
            /* [in] */ xp_kstr invitation,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CancelProposal )( 
            IAccCustomSession __RPC_FAR * This,
            /* [in] */ xp_kstr invitee);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Eject )( 
            IAccCustomSession __RPC_FAR * This,
            /* [in] */ xp_kstr userName,
            /* [defaultvalue][in] */ xp_kstr reason,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EndSession )( 
            IAccCustomSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SendData )( 
            IAccCustomSession __RPC_FAR * This,
            /* [in] */ xp_kstr toName,
            /* [in] */ xp_int streamId,
            /* [in] */ IAccIm __RPC_FAR *im);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStream )( 
            IAccCustomSession __RPC_FAR * This,
            /* [in] */ xp_kstr reserved,
            /* [in] */ xp_int streamId,
            /* [out] */ IAccStream __RPC_FAR *__RPC_FAR *pp);
        
        END_INTERFACE
    } IAccCustomSessionVtbl;

    interface IAccCustomSession
    {
        CONST_VTBL struct IAccCustomSessionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccCustomSession_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccCustomSession_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccCustomSession_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccCustomSession_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccCustomSession_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccCustomSession_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccCustomSession_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccCustomSession_get_ServiceId(This,pId)	\
    (This)->lpVtbl -> get_ServiceId(This,pId)

#define IAccCustomSession_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccCustomSession_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccCustomSession_Accept(This)	\
    (This)->lpVtbl -> Accept(This)

#define IAccCustomSession_Reject(This,reason)	\
    (This)->lpVtbl -> Reject(This,reason)

#define IAccCustomSession_Invite(This,invitee,invitation,pTransId)	\
    (This)->lpVtbl -> Invite(This,invitee,invitation,pTransId)

#define IAccCustomSession_CancelProposal(This,invitee)	\
    (This)->lpVtbl -> CancelProposal(This,invitee)

#define IAccCustomSession_Eject(This,userName,reason,pTransId)	\
    (This)->lpVtbl -> Eject(This,userName,reason,pTransId)

#define IAccCustomSession_EndSession(This)	\
    (This)->lpVtbl -> EndSession(This)


#define IAccCustomSession_SendData(This,toName,streamId,im)	\
    (This)->lpVtbl -> SendData(This,toName,streamId,im)

#define IAccCustomSession_GetStream(This,reserved,streamId,pp)	\
    (This)->lpVtbl -> GetStream(This,reserved,streamId,pp)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAccCustomSession_SendData_Proxy( 
    IAccCustomSession __RPC_FAR * This,
    /* [in] */ xp_kstr toName,
    /* [in] */ xp_int streamId,
    /* [in] */ IAccIm __RPC_FAR *im);


void __RPC_STUB IAccCustomSession_SendData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccCustomSession_GetStream_Proxy( 
    IAccCustomSession __RPC_FAR * This,
    /* [in] */ xp_kstr reserved,
    /* [in] */ xp_int streamId,
    /* [out] */ IAccStream __RPC_FAR *__RPC_FAR *pp);


void __RPC_STUB IAccCustomSession_GetStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccCustomSession_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccCustomSession_0272 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccCustomSession)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_Uuid(IAccCustomSession* pi, xp_str* px) { return get_Property(pi, AccCustomSessionProp_Uuid, px); };
static inline HRESULT get_Mode(IAccCustomSession* pi, AccCustomSessionMode* px) { return get_Property(pi, AccCustomSessionProp_Mode, (xp_s32*)px); };
static inline HRESULT put_Mode(IAccCustomSession* pi, AccCustomSessionMode x) { return put_Property(pi, AccCustomSessionProp_Mode, (xp_s32)x); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccCustomSession_0272_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccCustomSession_0272_v0_0_s_ifspec;

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
