/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:08 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccAlert.idl:
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

#ifndef __IAccAlert_h__
#define __IAccAlert_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccAlert_FWD_DEFINED__
#define __IAccAlert_FWD_DEFINED__
typedef interface IAccAlert IAccAlert;
#endif 	/* __IAccAlert_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"


#ifndef __IAccAlert_INTERFACE_DEFINED__
#define __IAccAlert_INTERFACE_DEFINED__

/* interface IAccAlert */
/* [object][dual][uuid] */ 

typedef 
enum AccAlertType
    {	AccAlertType_Mail	= 0,
	AccAlertType_Ygp	= 1,
	AccAlertType_Rendered	= 2
    }	AccAlertType;

typedef 
enum AccAlertProp
    {	AccAlertProp_Uuid	= 0,
	AccAlertProp_Cookie	= AccAlertProp_Uuid + 1,
	AccAlertProp_Timestamp	= AccAlertProp_Cookie + 1,
	AccAlertProp_GotMail	= 1000,
	AccAlertProp_NumMails	= AccAlertProp_GotMail + 1,
	AccAlertProp_NumVoicemails	= AccAlertProp_NumMails + 1,
	AccAlertProp_Address	= AccAlertProp_NumVoicemails + 1,
	AccAlertProp_ReadUrl	= AccAlertProp_Address + 1,
	AccAlertProp_GotPics	= 1100,
	AccAlertProp_Description	= 1200,
	AccAlertProp_Content	= AccAlertProp_Description + 1,
	AccAlertProp_ImageUrl	= AccAlertProp_Content + 1,
	AccAlertProp_MoreInfoUrl	= AccAlertProp_ImageUrl + 1,
	AccAlertProp_Duplicate	= AccAlertProp_MoreInfoUrl + 1,
	AccAlertProp_DisplayTime	= AccAlertProp_Duplicate + 1,
	AccAlertProp_Duration	= AccAlertProp_DisplayTime + 1,
	AccAlertProp_NotifyPrefs	= AccAlertProp_Duration + 1
    }	AccAlertProp;


EXTERN_C const IID IID_IAccAlert;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A99EFA3F-23C5-4a4b-B2F8-01EF6625FD48")
    IAccAlert : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Type( 
            /* [retval][out] */ AccAlertType __RPC_FAR *type) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ xp_int property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccAlertVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccAlert __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccAlert __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccAlert __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccAlert __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccAlert __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccAlert __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccAlert __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Type )( 
            IAccAlert __RPC_FAR * This,
            /* [retval][out] */ AccAlertType __RPC_FAR *type);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccAlert __RPC_FAR * This,
            /* [in] */ xp_int property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        END_INTERFACE
    } IAccAlertVtbl;

    interface IAccAlert
    {
        CONST_VTBL struct IAccAlertVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccAlert_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccAlert_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccAlert_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccAlert_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccAlert_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccAlert_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccAlert_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccAlert_get_Type(This,type)	\
    (This)->lpVtbl -> get_Type(This,type)

#define IAccAlert_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccAlert_get_Type_Proxy( 
    IAccAlert __RPC_FAR * This,
    /* [retval][out] */ AccAlertType __RPC_FAR *type);


void __RPC_STUB IAccAlert_get_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccAlert_get_Property_Proxy( 
    IAccAlert __RPC_FAR * This,
    /* [in] */ xp_int property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccAlert_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccAlert_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccAlert_0117 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccAlert)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_Uuid(IAccAlert* pi, xp_str* px) { return get_Property(pi, AccAlertProp_Uuid, px); };
static inline HRESULT get_Cookie(IAccAlert* pi, xp_str* px) { return get_Property(pi, AccAlertProp_Cookie, px); };
static inline HRESULT get_Timestamp(IAccAlert* pi, xp_date* px) { return get_PropertyDate(pi, AccAlertProp_Timestamp, px); };
static inline HRESULT get_GotMail(IAccAlert* pi, xp_bool* px) { return get_Property(pi, AccAlertProp_GotMail, px); };
static inline HRESULT get_NumMails(IAccAlert* pi, xp_s32* px) { return get_Property(pi, AccAlertProp_NumMails, px); };
static inline HRESULT get_NumVoicemails(IAccAlert* pi, xp_s32* px) { return get_Property(pi, AccAlertProp_NumVoicemails, px); };
static inline HRESULT get_Address(IAccAlert* pi, xp_str* px) { return get_Property(pi, AccAlertProp_Address, px); };
static inline HRESULT get_ReadUrl(IAccAlert* pi, xp_str* px) { return get_Property(pi, AccAlertProp_ReadUrl, px); };
static inline HRESULT get_GotPics(IAccAlert* pi, xp_bool* px) { return get_Property(pi, AccAlertProp_GotPics, px); };
static inline HRESULT get_Description(IAccAlert* pi, xp_str* px) { return get_Property(pi, AccAlertProp_Description, px); };
static inline HRESULT get_Content(IAccAlert* pi, xp_str* px) { return get_Property(pi, AccAlertProp_Content, px); };
static inline HRESULT get_ImageUrl(IAccAlert* pi, xp_str* px) { return get_Property(pi, AccAlertProp_ImageUrl, px); };
static inline HRESULT get_MoreInfoUrl(IAccAlert* pi, xp_str* px) { return get_Property(pi, AccAlertProp_MoreInfoUrl, px); };
static inline HRESULT get_Duplicate(IAccAlert* pi, xp_bool* px) { return get_Property(pi, AccAlertProp_Duplicate, px); };
static inline HRESULT get_DisplayTime(IAccAlert* pi, xp_s32* px) { return get_Property(pi, AccAlertProp_DisplayTime, px); };
static inline HRESULT get_Duration(IAccAlert* pi, xp_s32* px) { return get_Property(pi, AccAlertProp_Duration, px); };
static inline HRESULT get_NotifyPrefs(IAccAlert* pi, xp_u32* px) { return get_Property(pi, AccAlertProp_NotifyPrefs, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccAlert_0117_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccAlert_0117_v0_0_s_ifspec;

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
