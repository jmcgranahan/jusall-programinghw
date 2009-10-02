/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Sep 12 14:01:06 2007
 */
/* Compiler settings for C:\dev\cvs\client\aimcc\idl\IAccAvManager.idl:
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

#ifndef __IAccAvManager_h__
#define __IAccAvManager_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccAvManager_FWD_DEFINED__
#define __IAccAvManager_FWD_DEFINED__
typedef interface IAccAvManager IAccAvManager;
#endif 	/* __IAccAvManager_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccAvSession.h"


#ifndef __IAccAvManager_INTERFACE_DEFINED__
#define __IAccAvManager_INTERFACE_DEFINED__

/* interface IAccAvManager */
/* [object][dual][uuid] */ 

typedef 
enum AccAvFlags
    {	AccAvFlags_ForceNonSecure	= 0x2,
	AccAvFlags_ForceSecure	= 0x3,
	AccAvFlags_Video	= 0x4
    }	AccAvFlags;

typedef 
enum AccAvManagerProp
    {	AccAvManagerProp_InputMuted	= 0,
	AccAvManagerProp_InputVolume	= AccAvManagerProp_InputMuted + 1,
	AccAvManagerProp_OutputVolume	= AccAvManagerProp_InputVolume + 1,
	AccAvManagerProp_InputDevice	= AccAvManagerProp_OutputVolume + 1,
	AccAvManagerProp_OutputDevice	= AccAvManagerProp_InputDevice + 1,
	AccAvManagerProp_AvailableInputDevices	= AccAvManagerProp_OutputDevice + 1,
	AccAvManagerProp_AvailableOutputDevices	= AccAvManagerProp_AvailableInputDevices + 1,
	AccAvManagerProp_TemporalSpatialTradeOff	= AccAvManagerProp_AvailableOutputDevices + 1,
	AccAvManagerProp_MaxBitrate	= AccAvManagerProp_TemporalSpatialTradeOff + 1,
	AccAvManagerProp_EchoCancellation	= AccAvManagerProp_MaxBitrate + 1,
	AccAvManagerProp_LibraryName	= AccAvManagerProp_EchoCancellation + 1,
	AccAvManagerProp_LibraryVersion	= AccAvManagerProp_LibraryName + 1,
	AccAvManagerProp_VideoInputDevice	= AccAvManagerProp_LibraryVersion + 1,
	AccAvManagerProp_AvailableVideoInputDevices	= AccAvManagerProp_VideoInputDevice + 1,
	AccAvManagerProp_WindowsVoiceInputDevice	= AccAvManagerProp_AvailableVideoInputDevices + 1,
	AccAvManagerProp_WindowsVoiceOutputDevice	= AccAvManagerProp_WindowsVoiceInputDevice + 1,
	AccAvManagerProp_WindowsAudioInputDevice	= AccAvManagerProp_WindowsVoiceOutputDevice + 1,
	AccAvManagerProp_WindowsAudioOutputDevice	= AccAvManagerProp_WindowsAudioInputDevice + 1
    }	AccAvManagerProp;


EXTERN_C const IID IID_IAccAvManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a947d235-6d8e-4d0f-8867-f74f49d811d9")
    IAccAvManager : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccAvManagerProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccAvManagerProp property,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateSession( 
            /* [in] */ xp_kstr userName,
            /* [in] */ xp_int flags,
            /* [retval][out] */ IAccAvSession __RPC_FAR *__RPC_FAR *avSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateMultipartySession( 
            /* [in] */ xp_kstr reserved,
            /* [in] */ xp_int flags,
            /* [retval][out] */ IAccAvSession __RPC_FAR *__RPC_FAR *avSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NormalizePhoneNumber( 
            /* [in] */ xp_kstr inNumber,
            /* [retval][out] */ xp_str __RPC_FAR *outNumber) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccAvManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccAvManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccAvManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccAvManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccAvManager __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccAvManager __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccAvManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccAvManager __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccAvManager __RPC_FAR * This,
            /* [in] */ AccAvManagerProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccAvManager __RPC_FAR * This,
            /* [in] */ AccAvManagerProp property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateSession )( 
            IAccAvManager __RPC_FAR * This,
            /* [in] */ xp_kstr userName,
            /* [in] */ xp_int flags,
            /* [retval][out] */ IAccAvSession __RPC_FAR *__RPC_FAR *avSession);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateMultipartySession )( 
            IAccAvManager __RPC_FAR * This,
            /* [in] */ xp_kstr reserved,
            /* [in] */ xp_int flags,
            /* [retval][out] */ IAccAvSession __RPC_FAR *__RPC_FAR *avSession);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NormalizePhoneNumber )( 
            IAccAvManager __RPC_FAR * This,
            /* [in] */ xp_kstr inNumber,
            /* [retval][out] */ xp_str __RPC_FAR *outNumber);
        
        END_INTERFACE
    } IAccAvManagerVtbl;

    interface IAccAvManager
    {
        CONST_VTBL struct IAccAvManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccAvManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccAvManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccAvManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccAvManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccAvManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccAvManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccAvManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccAvManager_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccAvManager_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccAvManager_CreateSession(This,userName,flags,avSession)	\
    (This)->lpVtbl -> CreateSession(This,userName,flags,avSession)

#define IAccAvManager_CreateMultipartySession(This,reserved,flags,avSession)	\
    (This)->lpVtbl -> CreateMultipartySession(This,reserved,flags,avSession)

#define IAccAvManager_NormalizePhoneNumber(This,inNumber,outNumber)	\
    (This)->lpVtbl -> NormalizePhoneNumber(This,inNumber,outNumber)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccAvManager_get_Property_Proxy( 
    IAccAvManager __RPC_FAR * This,
    /* [in] */ AccAvManagerProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccAvManager_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccAvManager_put_Property_Proxy( 
    IAccAvManager __RPC_FAR * This,
    /* [in] */ AccAvManagerProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccAvManager_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccAvManager_CreateSession_Proxy( 
    IAccAvManager __RPC_FAR * This,
    /* [in] */ xp_kstr userName,
    /* [in] */ xp_int flags,
    /* [retval][out] */ IAccAvSession __RPC_FAR *__RPC_FAR *avSession);


void __RPC_STUB IAccAvManager_CreateSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccAvManager_CreateMultipartySession_Proxy( 
    IAccAvManager __RPC_FAR * This,
    /* [in] */ xp_kstr reserved,
    /* [in] */ xp_int flags,
    /* [retval][out] */ IAccAvSession __RPC_FAR *__RPC_FAR *avSession);


void __RPC_STUB IAccAvManager_CreateMultipartySession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccAvManager_NormalizePhoneNumber_Proxy( 
    IAccAvManager __RPC_FAR * This,
    /* [in] */ xp_kstr inNumber,
    /* [retval][out] */ xp_str __RPC_FAR *outNumber);


void __RPC_STUB IAccAvManager_NormalizePhoneNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccAvManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccAvManager_0125 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccAvManager)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_InputMuted(IAccAvManager* pi, xp_bool* px) { return get_Property(pi, AccAvManagerProp_InputMuted, px); };
static inline HRESULT put_InputMuted(IAccAvManager* pi, xp_bool x) { return put_Property(pi, AccAvManagerProp_InputMuted, x); };
static inline HRESULT get_InputVolume(IAccAvManager* pi, xp_s32* px) { return get_Property(pi, AccAvManagerProp_InputVolume, px); };
static inline HRESULT put_InputVolume(IAccAvManager* pi, xp_s32 x) { return put_Property(pi, AccAvManagerProp_InputVolume, x); };
static inline HRESULT get_OutputVolume(IAccAvManager* pi, xp_s32* px) { return get_Property(pi, AccAvManagerProp_OutputVolume, px); };
static inline HRESULT put_OutputVolume(IAccAvManager* pi, xp_s32 x) { return put_Property(pi, AccAvManagerProp_OutputVolume, x); };
static inline HRESULT get_InputDevice(IAccAvManager* pi, xp_str* px) { return get_Property(pi, AccAvManagerProp_InputDevice, px); };
static inline HRESULT put_InputDevice(IAccAvManager* pi, xp_kstr x) { return put_Property(pi, AccAvManagerProp_InputDevice, x); };
static inline HRESULT get_OutputDevice(IAccAvManager* pi, xp_str* px) { return get_Property(pi, AccAvManagerProp_OutputDevice, px); };
static inline HRESULT put_OutputDevice(IAccAvManager* pi, xp_kstr x) { return put_Property(pi, AccAvManagerProp_OutputDevice, x); };
static inline HRESULT get_AvailableInputDevices(IAccAvManager* pi, xp_array** px) { return get_Property(pi, AccAvManagerProp_AvailableInputDevices, px); };
static inline HRESULT get_AvailableOutputDevices(IAccAvManager* pi, xp_array** px) { return get_Property(pi, AccAvManagerProp_AvailableOutputDevices, px); };
static inline HRESULT get_TemporalSpatialTradeOff(IAccAvManager* pi, xp_s32* px) { return get_Property(pi, AccAvManagerProp_TemporalSpatialTradeOff, px); };
static inline HRESULT put_TemporalSpatialTradeOff(IAccAvManager* pi, xp_s32 x) { return put_Property(pi, AccAvManagerProp_TemporalSpatialTradeOff, x); };
static inline HRESULT get_MaxBitrate(IAccAvManager* pi, xp_s32* px) { return get_Property(pi, AccAvManagerProp_MaxBitrate, px); };
static inline HRESULT put_MaxBitrate(IAccAvManager* pi, xp_s32 x) { return put_Property(pi, AccAvManagerProp_MaxBitrate, x); };
static inline HRESULT get_EchoCancellation(IAccAvManager* pi, xp_bool* px) { return get_Property(pi, AccAvManagerProp_EchoCancellation, px); };
static inline HRESULT put_EchoCancellation(IAccAvManager* pi, xp_bool x) { return put_Property(pi, AccAvManagerProp_EchoCancellation, x); };
static inline HRESULT get_LibraryName(IAccAvManager* pi, xp_str* px) { return get_Property(pi, AccAvManagerProp_LibraryName, px); };
static inline HRESULT get_LibraryVersion(IAccAvManager* pi, xp_u32* px) { return get_Property(pi, AccAvManagerProp_LibraryVersion, px); };
static inline HRESULT get_VideoInputDevice(IAccAvManager* pi, xp_str* px) { return get_Property(pi, AccAvManagerProp_VideoInputDevice, px); };
static inline HRESULT put_VideoInputDevice(IAccAvManager* pi, xp_kstr x) { return put_Property(pi, AccAvManagerProp_VideoInputDevice, x); };
static inline HRESULT get_AvailableVideoInputDevices(IAccAvManager* pi, xp_array** px) { return get_Property(pi, AccAvManagerProp_AvailableVideoInputDevices, px); };
static inline HRESULT get_WindowsVoiceInputDevice(IAccAvManager* pi, xp_str* px) { return get_Property(pi, AccAvManagerProp_WindowsVoiceInputDevice, px); };
static inline HRESULT get_WindowsVoiceOutputDevice(IAccAvManager* pi, xp_str* px) { return get_Property(pi, AccAvManagerProp_WindowsVoiceOutputDevice, px); };
static inline HRESULT get_WindowsAudioInputDevice(IAccAvManager* pi, xp_str* px) { return get_Property(pi, AccAvManagerProp_WindowsAudioInputDevice, px); };
static inline HRESULT get_WindowsAudioOutputDevice(IAccAvManager* pi, xp_str* px) { return get_Property(pi, AccAvManagerProp_WindowsAudioOutputDevice, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccAvManager_0125_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccAvManager_0125_v0_0_s_ifspec;

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
