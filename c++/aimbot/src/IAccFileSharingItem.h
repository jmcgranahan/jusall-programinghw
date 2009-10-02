/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:30 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccFileSharingItem.idl:
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

#ifndef __IAccFileSharingItem_h__
#define __IAccFileSharingItem_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccFileSharingItem_FWD_DEFINED__
#define __IAccFileSharingItem_FWD_DEFINED__
typedef interface IAccFileSharingItem IAccFileSharingItem;
#endif 	/* __IAccFileSharingItem_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccFileSharingSession.h"
#include "IAccFileXferSession.h"


#ifndef __IAccFileSharingItem_INTERFACE_DEFINED__
#define __IAccFileSharingItem_INTERFACE_DEFINED__

/* interface IAccFileSharingItem */
/* [object][dual][uuid] */ 

typedef 
enum AccFileSharingItemProp
    {	AccFileSharingItemProp_IsDirectory	= 0,
	AccFileSharingItemProp_ListingCount	= AccFileSharingItemProp_IsDirectory + 1,
	AccFileSharingItemProp_LocalPath	= AccFileSharingItemProp_ListingCount + 1,
	AccFileSharingItemProp_ParentItem	= AccFileSharingItemProp_LocalPath + 1,
	AccFileSharingItemProp_RemoteName	= AccFileSharingItemProp_ParentItem + 1,
	AccFileSharingItemProp_RemotePath	= AccFileSharingItemProp_RemoteName + 1,
	AccFileSharingItemProp_FileBytes	= AccFileSharingItemProp_RemotePath + 1,
	AccFileSharingItemProp_FileMacCreator	= AccFileSharingItemProp_FileBytes + 1,
	AccFileSharingItemProp_FileMacFlags	= AccFileSharingItemProp_FileMacCreator + 1,
	AccFileSharingItemProp_FileMacType	= AccFileSharingItemProp_FileMacFlags + 1,
	AccFileSharingItemProp_FileTimeCreated	= AccFileSharingItemProp_FileMacType + 1,
	AccFileSharingItemProp_FileTimeModified	= AccFileSharingItemProp_FileTimeCreated + 1,
	AccFileSharingItemProp_FileSharingSession	= AccFileSharingItemProp_FileTimeModified + 1
    }	AccFileSharingItemProp;


EXTERN_C const IID IID_IAccFileSharingItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7aaa9b22-e923-11d7-9ff5-00e081103594")
    IAccFileSharingItem : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccFileSharingItemProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccFileSharingItemProp property,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestListing( 
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemByIndex( 
            /* [in] */ xp_int index,
            /* [retval][out] */ IAccFileSharingItem __RPC_FAR *__RPC_FAR *item) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RequestXfer( 
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccFileSharingItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccFileSharingItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccFileSharingItem __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccFileSharingItem __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccFileSharingItem __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccFileSharingItem __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccFileSharingItem __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccFileSharingItem __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccFileSharingItem __RPC_FAR * This,
            /* [in] */ AccFileSharingItemProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccFileSharingItem __RPC_FAR * This,
            /* [in] */ AccFileSharingItemProp property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestListing )( 
            IAccFileSharingItem __RPC_FAR * This,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetItemByIndex )( 
            IAccFileSharingItem __RPC_FAR * This,
            /* [in] */ xp_int index,
            /* [retval][out] */ IAccFileSharingItem __RPC_FAR *__RPC_FAR *item);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RequestXfer )( 
            IAccFileSharingItem __RPC_FAR * This,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        END_INTERFACE
    } IAccFileSharingItemVtbl;

    interface IAccFileSharingItem
    {
        CONST_VTBL struct IAccFileSharingItemVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccFileSharingItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccFileSharingItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccFileSharingItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccFileSharingItem_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccFileSharingItem_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccFileSharingItem_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccFileSharingItem_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccFileSharingItem_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccFileSharingItem_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccFileSharingItem_RequestListing(This,pTransId)	\
    (This)->lpVtbl -> RequestListing(This,pTransId)

#define IAccFileSharingItem_GetItemByIndex(This,index,item)	\
    (This)->lpVtbl -> GetItemByIndex(This,index,item)

#define IAccFileSharingItem_RequestXfer(This,pTransId)	\
    (This)->lpVtbl -> RequestXfer(This,pTransId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccFileSharingItem_get_Property_Proxy( 
    IAccFileSharingItem __RPC_FAR * This,
    /* [in] */ AccFileSharingItemProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccFileSharingItem_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccFileSharingItem_put_Property_Proxy( 
    IAccFileSharingItem __RPC_FAR * This,
    /* [in] */ AccFileSharingItemProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccFileSharingItem_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccFileSharingItem_RequestListing_Proxy( 
    IAccFileSharingItem __RPC_FAR * This,
    /* [retval][out] */ AccTransId __RPC_FAR *pTransId);


void __RPC_STUB IAccFileSharingItem_RequestListing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccFileSharingItem_GetItemByIndex_Proxy( 
    IAccFileSharingItem __RPC_FAR * This,
    /* [in] */ xp_int index,
    /* [retval][out] */ IAccFileSharingItem __RPC_FAR *__RPC_FAR *item);


void __RPC_STUB IAccFileSharingItem_GetItemByIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccFileSharingItem_RequestXfer_Proxy( 
    IAccFileSharingItem __RPC_FAR * This,
    /* [retval][out] */ AccTransId __RPC_FAR *pTransId);


void __RPC_STUB IAccFileSharingItem_RequestXfer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccFileSharingItem_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccFileSharingItem_0361 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccFileSharingItem)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_IsDirectory(IAccFileSharingItem* pi, xp_bool* px) { return get_Property(pi, AccFileSharingItemProp_IsDirectory, px); };
static inline HRESULT get_ListingCount(IAccFileSharingItem* pi, xp_s32* px) { return get_Property(pi, AccFileSharingItemProp_ListingCount, px); };
static inline HRESULT get_LocalPath(IAccFileSharingItem* pi, xp_str* px) { return get_Property(pi, AccFileSharingItemProp_LocalPath, px); };
static inline HRESULT put_LocalPath(IAccFileSharingItem* pi, xp_kstr x) { return put_Property(pi, AccFileSharingItemProp_LocalPath, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_ParentItem(IAccFileSharingItem* pi, IAccFileSharingItem** px) { return get_Property(pi, AccFileSharingItemProp_ParentItem, IID_IAccFileSharingItem, px); };
#endif
static inline HRESULT get_RemoteName(IAccFileSharingItem* pi, xp_str* px) { return get_Property(pi, AccFileSharingItemProp_RemoteName, px); };
static inline HRESULT get_RemotePath(IAccFileSharingItem* pi, xp_str* px) { return get_Property(pi, AccFileSharingItemProp_RemotePath, px); };
static inline HRESULT get_FileBytes(IAccFileSharingItem* pi, xp_s64* px) { return get_Property(pi, AccFileSharingItemProp_FileBytes, px); };
static inline HRESULT get_FileMacCreator(IAccFileSharingItem* pi, xp_u32* px) { return get_Property(pi, AccFileSharingItemProp_FileMacCreator, px); };
static inline HRESULT get_FileMacFlags(IAccFileSharingItem* pi, xp_u32* px) { return get_Property(pi, AccFileSharingItemProp_FileMacFlags, px); };
static inline HRESULT get_FileMacType(IAccFileSharingItem* pi, xp_u32* px) { return get_Property(pi, AccFileSharingItemProp_FileMacType, px); };
static inline HRESULT get_FileTimeCreated(IAccFileSharingItem* pi, xp_date* px) { return get_PropertyDate(pi, AccFileSharingItemProp_FileTimeCreated, px); };
static inline HRESULT get_FileTimeModified(IAccFileSharingItem* pi, xp_date* px) { return get_PropertyDate(pi, AccFileSharingItemProp_FileTimeModified, px); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_FileSharingSession(IAccFileSharingItem* pi, IAccFileSharingSession** px) { return get_Property(pi, AccFileSharingItemProp_FileSharingSession, IID_IAccFileSharingSession, px); };
#endif
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccFileSharingItem_0361_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccFileSharingItem_0361_v0_0_s_ifspec;

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
