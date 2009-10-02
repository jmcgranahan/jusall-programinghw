/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Apr 10 11:33:28 2007
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccAvSession.idl:
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

#ifndef __IAccAvSession_h__
#define __IAccAvSession_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccAvSession_FWD_DEFINED__
#define __IAccAvSession_FWD_DEFINED__
typedef interface IAccAvSession IAccAvSession;
#endif 	/* __IAccAvSession_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccSecondarySession.h"


#ifndef __IAccAvSession_INTERFACE_DEFINED__
#define __IAccAvSession_INTERFACE_DEFINED__

/* interface IAccAvSession */
/* [object][dual][uuid] */ 

typedef 
enum AccAvStreamType
    {	AccAvStreamType_AudioSend	= 0,
	AccAvStreamType_AudioReceive	= AccAvStreamType_AudioSend + 1,
	AccAvStreamType_VideoSend	= AccAvStreamType_AudioReceive + 1,
	AccAvStreamType_VideoReceive	= AccAvStreamType_VideoSend + 1
    }	AccAvStreamType;

typedef 
enum AccAvSessionType
    {	AccAvSessionType_Talk	= 0,
	AccAvSessionType_Rtp	= AccAvSessionType_Talk + 1,
	AccAvSessionType_RtpConference	= AccAvSessionType_Rtp + 1
    }	AccAvSessionType;

typedef 
enum AccAvLocalVideoMode
    {	AccAvLocalVideoMode_Hidden	= 0,
	AccAvLocalVideoMode_PictureInPicture	= AccAvLocalVideoMode_Hidden + 1
    }	AccAvLocalVideoMode;

typedef 
enum AccAvSessionProp
    {	AccAvSessionProp_Video	= 1000,
	AccAvSessionProp_NetworkQuality	= AccAvSessionProp_Video + 1,
	AccAvSessionProp_SessionType	= AccAvSessionProp_NetworkQuality + 1,
	AccAvSessionProp_SessionTypeProposed	= AccAvSessionProp_SessionType + 1,
	AccAvSessionProp_PromoteCentralized	= AccAvSessionProp_SessionTypeProposed + 1,
	AccAvSessionProp_LocalVideoMode	= AccAvSessionProp_PromoteCentralized + 1
    }	AccAvSessionProp;


EXTERN_C const IID IID_IAccAvSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("e65fed86-c6f2-4e4c-8da2-b688eb3f0a5b")
    IAccAvSession : public IAccSecondarySession
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property_( 
            /* [in] */ AccAvSessionProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property_( 
            /* [in] */ AccAvSessionProp property,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVideoWindow( 
            /* [in] */ xp_kstr userName,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *window) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendDtmf( 
            /* [in] */ xp_kstr tones) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendSoundEffect( 
            /* [in] */ xp_kstr url) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Hold( 
            /* [in] */ xp_vbool on) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartRecording( 
            /* [in] */ xp_kstr file) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopRecording( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccAvSessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccAvSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccAvSession __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccAvSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccAvSession __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccAvSession __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccAvSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccAvSession __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ServiceId )( 
            IAccAvSession __RPC_FAR * This,
            /* [retval][out] */ AccSecondarySessionServiceId __RPC_FAR *pId);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccAvSession __RPC_FAR * This,
            /* [in] */ xp_int property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccAvSession __RPC_FAR * This,
            /* [in] */ xp_int property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Accept )( 
            IAccAvSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reject )( 
            IAccAvSession __RPC_FAR * This,
            /* [defaultvalue][in] */ xp_int reason);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invite )( 
            IAccAvSession __RPC_FAR * This,
            /* [in] */ xp_kstr invitee,
            /* [in] */ xp_kstr invitation,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CancelProposal )( 
            IAccAvSession __RPC_FAR * This,
            /* [in] */ xp_kstr invitee);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Eject )( 
            IAccAvSession __RPC_FAR * This,
            /* [in] */ xp_kstr userName,
            /* [defaultvalue][in] */ xp_kstr reason,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EndSession )( 
            IAccAvSession __RPC_FAR * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property_ )( 
            IAccAvSession __RPC_FAR * This,
            /* [in] */ AccAvSessionProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property_ )( 
            IAccAvSession __RPC_FAR * This,
            /* [in] */ AccAvSessionProp property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVideoWindow )( 
            IAccAvSession __RPC_FAR * This,
            /* [in] */ xp_kstr userName,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *window);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SendDtmf )( 
            IAccAvSession __RPC_FAR * This,
            /* [in] */ xp_kstr tones);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SendSoundEffect )( 
            IAccAvSession __RPC_FAR * This,
            /* [in] */ xp_kstr url);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Hold )( 
            IAccAvSession __RPC_FAR * This,
            /* [in] */ xp_vbool on);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StartRecording )( 
            IAccAvSession __RPC_FAR * This,
            /* [in] */ xp_kstr file);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StopRecording )( 
            IAccAvSession __RPC_FAR * This);
        
        END_INTERFACE
    } IAccAvSessionVtbl;

    interface IAccAvSession
    {
        CONST_VTBL struct IAccAvSessionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccAvSession_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccAvSession_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccAvSession_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccAvSession_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccAvSession_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccAvSession_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccAvSession_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccAvSession_get_ServiceId(This,pId)	\
    (This)->lpVtbl -> get_ServiceId(This,pId)

#define IAccAvSession_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccAvSession_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccAvSession_Accept(This)	\
    (This)->lpVtbl -> Accept(This)

#define IAccAvSession_Reject(This,reason)	\
    (This)->lpVtbl -> Reject(This,reason)

#define IAccAvSession_Invite(This,invitee,invitation,pTransId)	\
    (This)->lpVtbl -> Invite(This,invitee,invitation,pTransId)

#define IAccAvSession_CancelProposal(This,invitee)	\
    (This)->lpVtbl -> CancelProposal(This,invitee)

#define IAccAvSession_Eject(This,userName,reason,pTransId)	\
    (This)->lpVtbl -> Eject(This,userName,reason,pTransId)

#define IAccAvSession_EndSession(This)	\
    (This)->lpVtbl -> EndSession(This)


#define IAccAvSession_get_Property_(This,property,value)	\
    (This)->lpVtbl -> get_Property_(This,property,value)

#define IAccAvSession_put_Property_(This,property,value)	\
    (This)->lpVtbl -> put_Property_(This,property,value)

#define IAccAvSession_GetVideoWindow(This,userName,window)	\
    (This)->lpVtbl -> GetVideoWindow(This,userName,window)

#define IAccAvSession_SendDtmf(This,tones)	\
    (This)->lpVtbl -> SendDtmf(This,tones)

#define IAccAvSession_SendSoundEffect(This,url)	\
    (This)->lpVtbl -> SendSoundEffect(This,url)

#define IAccAvSession_Hold(This,on)	\
    (This)->lpVtbl -> Hold(This,on)

#define IAccAvSession_StartRecording(This,file)	\
    (This)->lpVtbl -> StartRecording(This,file)

#define IAccAvSession_StopRecording(This)	\
    (This)->lpVtbl -> StopRecording(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccAvSession_get_Property__Proxy( 
    IAccAvSession __RPC_FAR * This,
    /* [in] */ AccAvSessionProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccAvSession_get_Property__Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccAvSession_put_Property__Proxy( 
    IAccAvSession __RPC_FAR * This,
    /* [in] */ AccAvSessionProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccAvSession_put_Property__Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccAvSession_GetVideoWindow_Proxy( 
    IAccAvSession __RPC_FAR * This,
    /* [in] */ xp_kstr userName,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *window);


void __RPC_STUB IAccAvSession_GetVideoWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccAvSession_SendDtmf_Proxy( 
    IAccAvSession __RPC_FAR * This,
    /* [in] */ xp_kstr tones);


void __RPC_STUB IAccAvSession_SendDtmf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccAvSession_SendSoundEffect_Proxy( 
    IAccAvSession __RPC_FAR * This,
    /* [in] */ xp_kstr url);


void __RPC_STUB IAccAvSession_SendSoundEffect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccAvSession_Hold_Proxy( 
    IAccAvSession __RPC_FAR * This,
    /* [in] */ xp_vbool on);


void __RPC_STUB IAccAvSession_Hold_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccAvSession_StartRecording_Proxy( 
    IAccAvSession __RPC_FAR * This,
    /* [in] */ xp_kstr file);


void __RPC_STUB IAccAvSession_StartRecording_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccAvSession_StopRecording_Proxy( 
    IAccAvSession __RPC_FAR * This);


void __RPC_STUB IAccAvSession_StopRecording_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccAvSession_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccAvSession_0121 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccAvSession)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_Video(IAccAvSession* pi, xp_bool* px) { return get_Property(pi, AccAvSessionProp_Video, px); };
static inline HRESULT get_NetworkQuality(IAccAvSession* pi, xp_s32* px) { return get_Property(pi, AccAvSessionProp_NetworkQuality, px); };
static inline HRESULT get_SessionType(IAccAvSession* pi, AccAvSessionType* px) { return get_Property(pi, AccAvSessionProp_SessionType, (xp_s32*)px); };
static inline HRESULT get_SessionTypeProposed(IAccAvSession* pi, AccAvSessionType* px) { return get_Property(pi, AccAvSessionProp_SessionTypeProposed, (xp_s32*)px); };
static inline HRESULT get_PromoteCentralized(IAccAvSession* pi, xp_bool* px) { return get_Property(pi, AccAvSessionProp_PromoteCentralized, px); };
static inline HRESULT put_PromoteCentralized(IAccAvSession* pi, xp_bool x) { return put_Property(pi, AccAvSessionProp_PromoteCentralized, x); };
static inline HRESULT get_LocalVideoMode(IAccAvSession* pi, AccAvLocalVideoMode* px) { return get_Property(pi, AccAvSessionProp_LocalVideoMode, (xp_s32*)px); };
static inline HRESULT put_LocalVideoMode(IAccAvSession* pi, AccAvLocalVideoMode x) { return put_Property(pi, AccAvSessionProp_LocalVideoMode, (xp_s32)x); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccAvSession_0121_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccAvSession_0121_v0_0_s_ifspec;

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
