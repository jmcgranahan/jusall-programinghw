/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Feb 13 18:41:32 2008
 */
/* Compiler settings for C:\dev\aimcc\aimcc\idl\IAccPluginInfo.idl:
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

#ifndef __IAccPluginInfo_h__
#define __IAccPluginInfo_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccPluginInfo_FWD_DEFINED__
#define __IAccPluginInfo_FWD_DEFINED__
typedef interface IAccPluginInfo IAccPluginInfo;
#endif 	/* __IAccPluginInfo_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccCommand.h"
#include "IAccPlugin.h"


#ifndef __IAccPluginInfo_INTERFACE_DEFINED__
#define __IAccPluginInfo_INTERFACE_DEFINED__

/* interface IAccPluginInfo */
/* [object][dual][uuid] */ 

typedef 
enum AccPluginType
    {	AccPluginType_Unknown	= 0,
	AccPluginType_Binary	= AccPluginType_Unknown + 1,
	AccPluginType_Widget	= AccPluginType_Binary + 1,
	AccPluginType_UiPlugin	= AccPluginType_Widget + 1
    }	AccPluginType;

typedef 
enum AccPluginInfoProp
    {	AccPluginInfoProp_Uuid	= 0,
	AccPluginInfoProp_Name	= AccPluginInfoProp_Uuid + 1,
	AccPluginInfoProp_Version	= AccPluginInfoProp_Name + 1,
	AccPluginInfoProp_Description	= AccPluginInfoProp_Version + 1,
	AccPluginInfoProp_Url	= AccPluginInfoProp_Description + 1,
	AccPluginInfoProp_VendorName	= AccPluginInfoProp_Url + 1,
	AccPluginInfoProp_VendorUrl	= AccPluginInfoProp_VendorName + 1,
	AccPluginInfoProp_IconUrl	= AccPluginInfoProp_VendorUrl + 1,
	AccPluginInfoProp_SmallIconUrl	= AccPluginInfoProp_IconUrl + 1,
	AccPluginInfoProp_Type	= AccPluginInfoProp_SmallIconUrl + 1,
	AccPluginInfoProp_Enabled	= 100,
	AccPluginInfoProp_VerificationResult	= AccPluginInfoProp_Enabled + 1,
	AccPluginInfoProp_TrustFlags	= AccPluginInfoProp_VerificationResult + 1,
	AccPluginInfoProp_Started	= AccPluginInfoProp_TrustFlags + 1,
	AccPluginInfoProp_Plugin	= AccPluginInfoProp_Started + 1,
	AccPluginInfoProp_LatestVersion	= AccPluginInfoProp_Plugin + 1,
	AccPluginInfoProp_DownloadUrl	= AccPluginInfoProp_LatestVersion + 1,
	AccPluginInfoProp_ContentUrl	= AccPluginInfoProp_DownloadUrl + 1,
	AccPluginInfoProp_PluginUrl	= AccPluginInfoProp_ContentUrl + 1,
	AccPluginInfoProp_SettingsUrl	= AccPluginInfoProp_PluginUrl + 1,
	AccPluginInfoProp_AboutUrl	= AccPluginInfoProp_SettingsUrl + 1,
	AccPluginInfoProp_Commands	= 200,
	AccPluginInfoProp_Windows	= 300
    }	AccPluginInfoProp;


EXTERN_C const IID IID_IAccPluginInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A31B4AA6-5C8D-4E87-B100-11617101CA93")
    IAccPluginInfo : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Uuid( 
            /* [retval][out] */ xp_str __RPC_FAR *uuid) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccPluginInfoProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccPluginInfoProp property,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCommandById( 
            /* [in] */ xp_int command,
            /* [retval][out] */ IAccCommand __RPC_FAR *__RPC_FAR *outCommand) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddCommand( 
            /* [in] */ xp_int command,
            /* [retval][out] */ IAccCommand __RPC_FAR *__RPC_FAR *outCommand) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveCommand( 
            /* [in] */ xp_int command) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParameter( 
            /* [in] */ xp_kstr name,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccPluginInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccPluginInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccPluginInfo __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccPluginInfo __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccPluginInfo __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccPluginInfo __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccPluginInfo __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccPluginInfo __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Uuid )( 
            IAccPluginInfo __RPC_FAR * This,
            /* [retval][out] */ xp_str __RPC_FAR *uuid);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccPluginInfo __RPC_FAR * This,
            /* [in] */ AccPluginInfoProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccPluginInfo __RPC_FAR * This,
            /* [in] */ AccPluginInfoProp property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCommandById )( 
            IAccPluginInfo __RPC_FAR * This,
            /* [in] */ xp_int command,
            /* [retval][out] */ IAccCommand __RPC_FAR *__RPC_FAR *outCommand);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddCommand )( 
            IAccPluginInfo __RPC_FAR * This,
            /* [in] */ xp_int command,
            /* [retval][out] */ IAccCommand __RPC_FAR *__RPC_FAR *outCommand);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveCommand )( 
            IAccPluginInfo __RPC_FAR * This,
            /* [in] */ xp_int command);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetParameter )( 
            IAccPluginInfo __RPC_FAR * This,
            /* [in] */ xp_kstr name,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        END_INTERFACE
    } IAccPluginInfoVtbl;

    interface IAccPluginInfo
    {
        CONST_VTBL struct IAccPluginInfoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccPluginInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccPluginInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccPluginInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccPluginInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccPluginInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccPluginInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccPluginInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccPluginInfo_get_Uuid(This,uuid)	\
    (This)->lpVtbl -> get_Uuid(This,uuid)

#define IAccPluginInfo_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccPluginInfo_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccPluginInfo_GetCommandById(This,command,outCommand)	\
    (This)->lpVtbl -> GetCommandById(This,command,outCommand)

#define IAccPluginInfo_AddCommand(This,command,outCommand)	\
    (This)->lpVtbl -> AddCommand(This,command,outCommand)

#define IAccPluginInfo_RemoveCommand(This,command)	\
    (This)->lpVtbl -> RemoveCommand(This,command)

#define IAccPluginInfo_GetParameter(This,name,value)	\
    (This)->lpVtbl -> GetParameter(This,name,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IAccPluginInfo_get_Uuid_Proxy( 
    IAccPluginInfo __RPC_FAR * This,
    /* [retval][out] */ xp_str __RPC_FAR *uuid);


void __RPC_STUB IAccPluginInfo_get_Uuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccPluginInfo_get_Property_Proxy( 
    IAccPluginInfo __RPC_FAR * This,
    /* [in] */ AccPluginInfoProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccPluginInfo_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccPluginInfo_put_Property_Proxy( 
    IAccPluginInfo __RPC_FAR * This,
    /* [in] */ AccPluginInfoProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccPluginInfo_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPluginInfo_GetCommandById_Proxy( 
    IAccPluginInfo __RPC_FAR * This,
    /* [in] */ xp_int command,
    /* [retval][out] */ IAccCommand __RPC_FAR *__RPC_FAR *outCommand);


void __RPC_STUB IAccPluginInfo_GetCommandById_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPluginInfo_AddCommand_Proxy( 
    IAccPluginInfo __RPC_FAR * This,
    /* [in] */ xp_int command,
    /* [retval][out] */ IAccCommand __RPC_FAR *__RPC_FAR *outCommand);


void __RPC_STUB IAccPluginInfo_AddCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPluginInfo_RemoveCommand_Proxy( 
    IAccPluginInfo __RPC_FAR * This,
    /* [in] */ xp_int command);


void __RPC_STUB IAccPluginInfo_RemoveCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccPluginInfo_GetParameter_Proxy( 
    IAccPluginInfo __RPC_FAR * This,
    /* [in] */ xp_kstr name,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccPluginInfo_GetParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccPluginInfo_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccPluginInfo_0370 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccPluginInfo)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_Uuid(IAccPluginInfo* pi, xp_str* px) { return get_Property(pi, AccPluginInfoProp_Uuid, px); };
static inline HRESULT get_Name(IAccPluginInfo* pi, xp_str* px) { return get_Property(pi, AccPluginInfoProp_Name, px); };
static inline HRESULT get_Version(IAccPluginInfo* pi, xp_str* px) { return get_Property(pi, AccPluginInfoProp_Version, px); };
static inline HRESULT get_Description(IAccPluginInfo* pi, xp_str* px) { return get_Property(pi, AccPluginInfoProp_Description, px); };
static inline HRESULT get_Url(IAccPluginInfo* pi, xp_str* px) { return get_Property(pi, AccPluginInfoProp_Url, px); };
static inline HRESULT get_VendorName(IAccPluginInfo* pi, xp_str* px) { return get_Property(pi, AccPluginInfoProp_VendorName, px); };
static inline HRESULT get_VendorUrl(IAccPluginInfo* pi, xp_str* px) { return get_Property(pi, AccPluginInfoProp_VendorUrl, px); };
static inline HRESULT get_IconUrl(IAccPluginInfo* pi, xp_str* px) { return get_Property(pi, AccPluginInfoProp_IconUrl, px); };
static inline HRESULT get_SmallIconUrl(IAccPluginInfo* pi, xp_str* px) { return get_Property(pi, AccPluginInfoProp_SmallIconUrl, px); };
static inline HRESULT get_Type(IAccPluginInfo* pi, AccPluginType* px) { return get_Property(pi, AccPluginInfoProp_Type, (xp_s32*)px); };
static inline HRESULT get_Enabled(IAccPluginInfo* pi, xp_bool* px) { return get_Property(pi, AccPluginInfoProp_Enabled, px); };
static inline HRESULT put_Enabled(IAccPluginInfo* pi, xp_bool x) { return put_Property(pi, AccPluginInfoProp_Enabled, x); };
static inline HRESULT get_VerificationResult(IAccPluginInfo* pi, AccResult* px) { return get_Property(pi, AccPluginInfoProp_VerificationResult, (xp_s32*)px); };
static inline HRESULT get_TrustFlags(IAccPluginInfo* pi, xp_u32* px) { return get_Property(pi, AccPluginInfoProp_TrustFlags, px); };
static inline HRESULT get_Started(IAccPluginInfo* pi, xp_bool* px) { return get_Property(pi, AccPluginInfoProp_Started, px); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_Plugin(IAccPluginInfo* pi, IAccPlugin** px) { return get_Property(pi, AccPluginInfoProp_Plugin, IID_IAccPlugin, px); };
#endif
static inline HRESULT get_LatestVersion(IAccPluginInfo* pi, xp_str* px) { return get_Property(pi, AccPluginInfoProp_LatestVersion, px); };
static inline HRESULT get_DownloadUrl(IAccPluginInfo* pi, xp_str* px) { return get_Property(pi, AccPluginInfoProp_DownloadUrl, px); };
static inline HRESULT get_ContentUrl(IAccPluginInfo* pi, xp_str* px) { return get_Property(pi, AccPluginInfoProp_ContentUrl, px); };
static inline HRESULT get_PluginUrl(IAccPluginInfo* pi, xp_str* px) { return get_Property(pi, AccPluginInfoProp_PluginUrl, px); };
static inline HRESULT get_SettingsUrl(IAccPluginInfo* pi, xp_str* px) { return get_Property(pi, AccPluginInfoProp_SettingsUrl, px); };
static inline HRESULT get_AboutUrl(IAccPluginInfo* pi, xp_str* px) { return get_Property(pi, AccPluginInfoProp_AboutUrl, px); };
static inline HRESULT get_Commands(IAccPluginInfo* pi, xp_array** px) { return get_Property(pi, AccPluginInfoProp_Commands, px); };
static inline HRESULT get_Windows(IAccPluginInfo* pi, xp_array** px) { return get_Property(pi, AccPluginInfoProp_Windows, px); };
static inline HRESULT put_Windows(IAccPluginInfo* pi, xp_array* x) { return put_Property(pi, AccPluginInfoProp_Windows, x); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccPluginInfo_0370_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccPluginInfo_0370_v0_0_s_ifspec;

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
