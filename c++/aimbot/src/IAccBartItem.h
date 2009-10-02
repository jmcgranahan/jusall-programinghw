/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Feb 27 08:14:38 2008
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccBartItem.idl:
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

#ifndef __IAccBartItem_h__
#define __IAccBartItem_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccBartItem_FWD_DEFINED__
#define __IAccBartItem_FWD_DEFINED__
typedef interface IAccBartItem IAccBartItem;
#endif 	/* __IAccBartItem_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccStream.h"


#ifndef __IAccBartItem_INTERFACE_DEFINED__
#define __IAccBartItem_INTERFACE_DEFINED__

/* interface IAccBartItem */
/* [object][dual][uuid] */ 

typedef 
enum AccBartItemType
    {	AccBartItemType_SmallIcon	= 0,
	AccBartItemType_BuddyIcon	= 1,
	AccBartItemType_StatusText	= 2,
	AccBartItemType_ArriveSound	= 3,
	AccBartItemType_RichName	= 4,
	AccBartItemType_SuperIcon	= 5,
	AccBartItemType_RadioStation	= 6,
	AccBartItemType_SuperIconTrigger	= 7,
	AccBartItemType_StatusTextLink	= 9,
	AccBartItemType_Location	= 11,
	AccBartItemType_BigIcon	= 12,
	AccBartItemType_StatusTextTimestamp	= 13,
	AccBartItemType_CurrentAvTrack	= 15,
	AccBartItemType_DepartSound	= 96,
	AccBartItemType_Wallpaper	= 129,
	AccBartItemType_ImSound	= 131,
	AccBartItemType_Badge	= 132,
	AccBartItemType_ImInitialSound	= 134,
	AccBartItemType_FlashWallpaper	= 136,
	AccBartItemType_ImmersiveWallpaper	= 137,
	AccBartItemType_EmoticonSet	= 1024
    }	AccBartItemType;

typedef 
enum AccBartItemProp
    {	AccBartItemProp_BartItemType	= 0,
	AccBartItemProp_Official	= AccBartItemProp_BartItemType + 1,
	AccBartItemProp_Id	= AccBartItemProp_Official + 1,
	AccBartItemProp_IdHex	= AccBartItemProp_Id + 1,
	AccBartItemProp_MimeType	= AccBartItemProp_IdHex + 1,
	AccBartItemProp_Data	= AccBartItemProp_MimeType + 1,
	AccBartItemProp_DataObject	= AccBartItemProp_Data + 1,
	AccBartItemProp_DataStream	= AccBartItemProp_DataObject + 1,
	AccBartItemProp_BartUrl	= AccBartItemProp_DataStream + 1,
	AccBartItemProp_Name	= AccBartItemProp_BartUrl + 1
    }	AccBartItemProp;


EXTERN_C const IID IID_IAccBartItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3b99239d-0066-4f7e-9e1c-0888be7f4799")
    IAccBartItem : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccBartItemProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccBartItemProp property,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestProperty( 
            /* [in] */ AccBartItemProp property,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccBartItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccBartItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccBartItem __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccBartItem __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccBartItem __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccBartItem __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccBartItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccBartItem __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccBartItem __RPC_FAR * This,
            /* [in] */ AccBartItemProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccBartItem __RPC_FAR * This,
            /* [in] */ AccBartItemProp property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestProperty )( 
            IAccBartItem __RPC_FAR * This,
            /* [in] */ AccBartItemProp property,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        END_INTERFACE
    } IAccBartItemVtbl;

    interface IAccBartItem
    {
        CONST_VTBL struct IAccBartItemVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccBartItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccBartItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccBartItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccBartItem_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccBartItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccBartItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccBartItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccBartItem_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccBartItem_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccBartItem_RequestProperty(This,property,pTransId)	\
    (This)->lpVtbl -> RequestProperty(This,property,pTransId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccBartItem_get_Property_Proxy( 
    IAccBartItem __RPC_FAR * This,
    /* [in] */ AccBartItemProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccBartItem_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccBartItem_put_Property_Proxy( 
    IAccBartItem __RPC_FAR * This,
    /* [in] */ AccBartItemProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccBartItem_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccBartItem_RequestProperty_Proxy( 
    IAccBartItem __RPC_FAR * This,
    /* [in] */ AccBartItemProp property,
    /* [retval][out] */ AccTransId __RPC_FAR *pTransId);


void __RPC_STUB IAccBartItem_RequestProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccBartItem_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccBartItem_0263 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccBartItem)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_BartItemType(IAccBartItem* pi, AccBartItemType* px) { return get_Property(pi, AccBartItemProp_BartItemType, (xp_s32*)px); };
static inline HRESULT get_Official(IAccBartItem* pi, xp_bool* px) { return get_Property(pi, AccBartItemProp_Official, px); };
static inline HRESULT get_Id(IAccBartItem* pi, xp_str* px) { return get_Property(pi, AccBartItemProp_Id, px); };
static inline HRESULT get_IdHex(IAccBartItem* pi, xp_str* px) { return get_Property(pi, AccBartItemProp_IdHex, px); };
static inline HRESULT get_MimeType(IAccBartItem* pi, xp_str* px) { return get_Property(pi, AccBartItemProp_MimeType, px); };
static inline HRESULT get_Data(IAccBartItem* pi, xp_array** px) { return get_Property(pi, AccBartItemProp_Data, px); };
static inline HRESULT get_DataObject(IAccBartItem* pi, xp_variant* px) { return get_Property(pi, AccBartItemProp_DataObject, px); };
static inline HRESULT put_DataObject(IAccBartItem* pi, xp_kvariant x) { return put_Property(pi, AccBartItemProp_DataObject, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_DataStream(IAccBartItem* pi, IAccStream** px) { return get_Property(pi, AccBartItemProp_DataStream, IID_IAccStream, px); };
#endif
static inline HRESULT get_BartUrl(IAccBartItem* pi, xp_str* px) { return get_Property(pi, AccBartItemProp_BartUrl, px); };
static inline HRESULT get_Name(IAccBartItem* pi, xp_str* px) { return get_Property(pi, AccBartItemProp_Name, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccBartItem_0263_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccBartItem_0263_v0_0_s_ifspec;

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
