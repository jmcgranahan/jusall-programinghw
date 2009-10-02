/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Oct 17 18:06:10 2007
 */
/* Compiler settings for C:\dev\cvs\client\aimcc\idl\IAccIm.idl:
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

#ifndef __IAccIm_h__
#define __IAccIm_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccIm_FWD_DEFINED__
#define __IAccIm_FWD_DEFINED__
typedef interface IAccIm IAccIm;
#endif 	/* __IAccIm_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccStream.h"


#ifndef __IAccIm_INTERFACE_DEFINED__
#define __IAccIm_INTERFACE_DEFINED__

/* interface IAccIm */
/* [object][dual][uuid] */ 

typedef 
enum AccImProp
    {	AccImProp_MimeType	= 0,
	AccImProp_Flags	= AccImProp_MimeType + 1,
	AccImProp_Timestamp	= AccImProp_Flags + 1,
	AccImProp_Verified	= AccImProp_Timestamp + 1,
	AccImProp_Segments	= AccImProp_Verified + 1,
	AccImProp_SegmentCharsRemaining	= AccImProp_Segments + 1,
	AccImProp_Cookie	= AccImProp_SegmentCharsRemaining + 1,
	AccImProp_ContainsImages	= AccImProp_Cookie + 1,
	AccImProp_AllowImages	= AccImProp_ContainsImages + 1,
	AccImProp_Subject	= AccImProp_AllowImages + 1,
	AccImProp_StreamCount	= AccImProp_Subject + 1,
	AccImProp_Disposition	= AccImProp_StreamCount + 1,
	AccImProp_SerializedText	= AccImProp_Disposition + 1,
	AccImProp_Local	= AccImProp_SerializedText + 1,
	AccImProp_AllowedContentFlags	= AccImProp_Local + 1,
	AccImProp_ActualContentFlags	= AccImProp_AllowedContentFlags + 1,
	AccImProp_BartBase	= 10000,
	AccImProp_BuddyIcon	= AccImProp_BartBase + 1,
	AccImProp_SuperIcon	= AccImProp_BartBase + 5,
	AccImProp_SuperIconTrigger	= AccImProp_BartBase + 7,
	AccImProp_BigIcon	= AccImProp_BartBase + 12,
	AccImProp_Wallpaper	= AccImProp_BartBase + 129,
	AccImProp_Sound	= AccImProp_BartBase + 131,
	AccImProp_FlashWallpaper	= AccImProp_BartBase + 136
    }	AccImProp;

typedef 
enum AccImFlags
    {	AccImFlags_AutoResponse	= 0x1,
	AccImFlags_Store	= 0x2,
	AccImFlags_Rtim	= 0x4
    }	AccImFlags;

typedef 
enum AccImContentFlags
    {	AccImContentFlags_Image	= 0x1,
	AccImContentFlags_Video	= 0x2,
	AccImContentFlags_All	= AccImContentFlags_Image + AccImContentFlags_Video
    }	AccImContentFlags;


EXTERN_C const IID IID_IAccIm;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D56487C8-6C90-49DA-A431-3EFC493AB159")
    IAccIm : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ xp_str __RPC_FAR *text) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Text( 
            /* [in] */ xp_kstr text) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccImProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccImProp property,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConvertedText( 
            /* [in] */ xp_kstr type,
            /* [retval][out] */ xp_str __RPC_FAR *text) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConvertToMimeType( 
            /* [in] */ xp_kstr type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStream( 
            /* [in] */ xp_kstr id,
            /* [retval][out] */ IAccStream __RPC_FAR *__RPC_FAR *stream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStream( 
            /* [in] */ xp_kstr id,
            /* [in] */ IAccStream __RPC_FAR *stream) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccImVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccIm __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccIm __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccIm __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccIm __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccIm __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccIm __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccIm __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Text )( 
            IAccIm __RPC_FAR * This,
            /* [retval][out] */ xp_str __RPC_FAR *text);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Text )( 
            IAccIm __RPC_FAR * This,
            /* [in] */ xp_kstr text);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccIm __RPC_FAR * This,
            /* [in] */ AccImProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccIm __RPC_FAR * This,
            /* [in] */ AccImProp property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetConvertedText )( 
            IAccIm __RPC_FAR * This,
            /* [in] */ xp_kstr type,
            /* [retval][out] */ xp_str __RPC_FAR *text);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ConvertToMimeType )( 
            IAccIm __RPC_FAR * This,
            /* [in] */ xp_kstr type);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStream )( 
            IAccIm __RPC_FAR * This,
            /* [in] */ xp_kstr id,
            /* [retval][out] */ IAccStream __RPC_FAR *__RPC_FAR *stream);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStream )( 
            IAccIm __RPC_FAR * This,
            /* [in] */ xp_kstr id,
            /* [in] */ IAccStream __RPC_FAR *stream);
        
        END_INTERFACE
    } IAccImVtbl;

    interface IAccIm
    {
        CONST_VTBL struct IAccImVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccIm_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccIm_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccIm_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccIm_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccIm_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccIm_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccIm_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccIm_get_Text(This,text)	\
    (This)->lpVtbl -> get_Text(This,text)

#define IAccIm_put_Text(This,text)	\
    (This)->lpVtbl -> put_Text(This,text)

#define IAccIm_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccIm_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccIm_GetConvertedText(This,type,text)	\
    (This)->lpVtbl -> GetConvertedText(This,type,text)

#define IAccIm_ConvertToMimeType(This,type)	\
    (This)->lpVtbl -> ConvertToMimeType(This,type)

#define IAccIm_GetStream(This,id,stream)	\
    (This)->lpVtbl -> GetStream(This,id,stream)

#define IAccIm_SetStream(This,id,stream)	\
    (This)->lpVtbl -> SetStream(This,id,stream)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IAccIm_get_Text_Proxy( 
    IAccIm __RPC_FAR * This,
    /* [retval][out] */ xp_str __RPC_FAR *text);


void __RPC_STUB IAccIm_get_Text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IAccIm_put_Text_Proxy( 
    IAccIm __RPC_FAR * This,
    /* [in] */ xp_kstr text);


void __RPC_STUB IAccIm_put_Text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccIm_get_Property_Proxy( 
    IAccIm __RPC_FAR * This,
    /* [in] */ AccImProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccIm_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccIm_put_Property_Proxy( 
    IAccIm __RPC_FAR * This,
    /* [in] */ AccImProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccIm_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccIm_GetConvertedText_Proxy( 
    IAccIm __RPC_FAR * This,
    /* [in] */ xp_kstr type,
    /* [retval][out] */ xp_str __RPC_FAR *text);


void __RPC_STUB IAccIm_GetConvertedText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccIm_ConvertToMimeType_Proxy( 
    IAccIm __RPC_FAR * This,
    /* [in] */ xp_kstr type);


void __RPC_STUB IAccIm_ConvertToMimeType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccIm_GetStream_Proxy( 
    IAccIm __RPC_FAR * This,
    /* [in] */ xp_kstr id,
    /* [retval][out] */ IAccStream __RPC_FAR *__RPC_FAR *stream);


void __RPC_STUB IAccIm_GetStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccIm_SetStream_Proxy( 
    IAccIm __RPC_FAR * This,
    /* [in] */ xp_kstr id,
    /* [in] */ IAccStream __RPC_FAR *stream);


void __RPC_STUB IAccIm_SetStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccIm_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccIm_0263 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccIm)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_MimeType(IAccIm* pi, xp_str* px) { return get_Property(pi, AccImProp_MimeType, px); };
static inline HRESULT put_MimeType(IAccIm* pi, xp_kstr x) { return put_Property(pi, AccImProp_MimeType, x); };
static inline HRESULT get_Flags(IAccIm* pi, xp_u32* px) { return get_Property(pi, AccImProp_Flags, px); };
static inline HRESULT put_Flags(IAccIm* pi, xp_u32 x) { return put_Property(pi, AccImProp_Flags, x); };
static inline HRESULT get_Timestamp(IAccIm* pi, xp_date* px) { return get_PropertyDate(pi, AccImProp_Timestamp, px); };
static inline HRESULT get_Verified(IAccIm* pi, xp_bool* px) { return get_Property(pi, AccImProp_Verified, px); };
static inline HRESULT get_Segments(IAccIm* pi, xp_s32* px) { return get_Property(pi, AccImProp_Segments, px); };
static inline HRESULT get_SegmentCharsRemaining(IAccIm* pi, xp_s32* px) { return get_Property(pi, AccImProp_SegmentCharsRemaining, px); };
static inline HRESULT get_Cookie(IAccIm* pi, xp_str* px) { return get_Property(pi, AccImProp_Cookie, px); };
static inline HRESULT get_ContainsImages(IAccIm* pi, xp_bool* px) { return get_Property(pi, AccImProp_ContainsImages, px); };
static inline HRESULT get_AllowImages(IAccIm* pi, xp_bool* px) { return get_Property(pi, AccImProp_AllowImages, px); };
static inline HRESULT put_AllowImages(IAccIm* pi, xp_bool x) { return put_Property(pi, AccImProp_AllowImages, x); };
static inline HRESULT get_Subject(IAccIm* pi, xp_str* px) { return get_Property(pi, AccImProp_Subject, px); };
static inline HRESULT put_Subject(IAccIm* pi, xp_kstr x) { return put_Property(pi, AccImProp_Subject, x); };
static inline HRESULT get_StreamCount(IAccIm* pi, xp_int* px) { return get_Property(pi, AccImProp_StreamCount, px); };
static inline HRESULT get_Disposition(IAccIm* pi, AccResult* px) { return get_Property(pi, AccImProp_Disposition, (xp_s32*)px); };
static inline HRESULT put_Disposition(IAccIm* pi, AccResult x) { return put_Property(pi, AccImProp_Disposition, (xp_s32)x); };
static inline HRESULT get_SerializedText(IAccIm* pi, xp_str* px) { return get_Property(pi, AccImProp_SerializedText, px); };
static inline HRESULT put_SerializedText(IAccIm* pi, xp_kstr x) { return put_Property(pi, AccImProp_SerializedText, x); };
static inline HRESULT get_Local(IAccIm* pi, xp_bool* px) { return get_Property(pi, AccImProp_Local, px); };
static inline HRESULT put_Local(IAccIm* pi, xp_bool x) { return put_Property(pi, AccImProp_Local, x); };
static inline HRESULT get_AllowedContentFlags(IAccIm* pi, xp_u32* px) { return get_Property(pi, AccImProp_AllowedContentFlags, px); };
static inline HRESULT put_AllowedContentFlags(IAccIm* pi, xp_u32 x) { return put_Property(pi, AccImProp_AllowedContentFlags, x); };
static inline HRESULT get_ActualContentFlags(IAccIm* pi, xp_u32* px) { return get_Property(pi, AccImProp_ActualContentFlags, px); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_BuddyIcon(IAccIm* pi, IAccBartItem** px) { return get_Property(pi, AccImProp_BuddyIcon, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_BuddyIcon(IAccIm* pi, IAccBartItem* x) { return put_Property(pi, AccImProp_BuddyIcon, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_SuperIcon(IAccIm* pi, IAccBartItem** px) { return get_Property(pi, AccImProp_SuperIcon, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_SuperIcon(IAccIm* pi, IAccBartItem* x) { return put_Property(pi, AccImProp_SuperIcon, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_SuperIconTrigger(IAccIm* pi, IAccBartItem** px) { return get_Property(pi, AccImProp_SuperIconTrigger, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_SuperIconTrigger(IAccIm* pi, IAccBartItem* x) { return put_Property(pi, AccImProp_SuperIconTrigger, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_BigIcon(IAccIm* pi, IAccBartItem** px) { return get_Property(pi, AccImProp_BigIcon, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_BigIcon(IAccIm* pi, IAccBartItem* x) { return put_Property(pi, AccImProp_BigIcon, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_Wallpaper(IAccIm* pi, IAccBartItem** px) { return get_Property(pi, AccImProp_Wallpaper, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_Wallpaper(IAccIm* pi, IAccBartItem* x) { return put_Property(pi, AccImProp_Wallpaper, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_Sound(IAccIm* pi, IAccBartItem** px) { return get_Property(pi, AccImProp_Sound, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_Sound(IAccIm* pi, IAccBartItem* x) { return put_Property(pi, AccImProp_Sound, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_FlashWallpaper(IAccIm* pi, IAccBartItem** px) { return get_Property(pi, AccImProp_FlashWallpaper, IID_IAccBartItem, px); };
#endif
static inline HRESULT put_FlashWallpaper(IAccIm* pi, IAccBartItem* x) { return put_Property(pi, AccImProp_FlashWallpaper, x); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccIm_0263_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccIm_0263_v0_0_s_ifspec;

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
