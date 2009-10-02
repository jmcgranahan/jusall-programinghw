/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Feb 27 08:15:04 2008
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccGroup.idl:
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

#ifndef __IAccGroup_h__
#define __IAccGroup_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccGroup_FWD_DEFINED__
#define __IAccGroup_FWD_DEFINED__
typedef interface IAccGroup IAccGroup;
#endif 	/* __IAccGroup_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccUser.h"


#ifndef __IAccGroup_INTERFACE_DEFINED__
#define __IAccGroup_INTERFACE_DEFINED__

/* interface IAccGroup */
/* [object][dual][uuid] */ 

typedef 
enum AccGroupProp
    {	AccGroupProp_Session	= -1,
	AccGroupProp_Name	= AccGroupProp_Session + 1,
	AccGroupProp_OnlineCount	= AccGroupProp_Name + 1,
	AccGroupProp_Collapsed	= AccGroupProp_OnlineCount + 1,
	AccGroupProp_Shared	= AccGroupProp_Collapsed + 1,
	AccGroupProp_RecentBuddies	= AccGroupProp_Shared + 1,
	AccGroupProp_Smart	= AccGroupProp_RecentBuddies + 1,
	AccGroupProp_ReadOnly	= AccGroupProp_Smart + 1,
	AccGroupProp_SynchronizedStorageType	= AccGroupProp_ReadOnly + 1,
	AccGroupProp_SynchronizedStorageName	= AccGroupProp_SynchronizedStorageType + 1,
	AccGroupProp_Offline	= AccGroupProp_SynchronizedStorageName + 1
    }	AccGroupProp;


EXTERN_C const IID IID_IAccGroup;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8809d5f0-b112-11d3-90a7-001083341cf5")
    IAccGroup : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ xp_str __RPC_FAR *name) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ xp_kstr name) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccGroupProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccGroupProp property,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_BuddyCount( 
            /* [retval][out] */ xp_int __RPC_FAR *count) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBuddyByIndex( 
            /* [in] */ xp_int position,
            /* [retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *user) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBuddyPosition( 
            /* [in] */ IAccUser __RPC_FAR *user,
            /* [retval][out] */ xp_int __RPC_FAR *position) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertBuddy( 
            /* [in] */ xp_kvariant user,
            /* [defaultvalue][in] */ xp_int position = -1,
            /* [defaultvalue][retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *userRetval = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveBuddy( 
            /* [in] */ xp_int position) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveBuddy( 
            /* [in] */ xp_int fromPosition,
            /* [in] */ xp_int toPosition) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBuddyByName( 
            /* [in] */ xp_kstr name,
            /* [retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *user) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccGroupVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccGroup __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccGroup __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccGroup __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccGroup __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccGroup __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccGroup __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccGroup __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            IAccGroup __RPC_FAR * This,
            /* [retval][out] */ xp_str __RPC_FAR *name);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            IAccGroup __RPC_FAR * This,
            /* [in] */ xp_kstr name);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccGroup __RPC_FAR * This,
            /* [in] */ AccGroupProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccGroup __RPC_FAR * This,
            /* [in] */ AccGroupProp property,
            /* [in] */ xp_kvariant value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BuddyCount )( 
            IAccGroup __RPC_FAR * This,
            /* [retval][out] */ xp_int __RPC_FAR *count);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBuddyByIndex )( 
            IAccGroup __RPC_FAR * This,
            /* [in] */ xp_int position,
            /* [retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *user);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBuddyPosition )( 
            IAccGroup __RPC_FAR * This,
            /* [in] */ IAccUser __RPC_FAR *user,
            /* [retval][out] */ xp_int __RPC_FAR *position);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertBuddy )( 
            IAccGroup __RPC_FAR * This,
            /* [in] */ xp_kvariant user,
            /* [defaultvalue][in] */ xp_int position,
            /* [defaultvalue][retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *userRetval);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveBuddy )( 
            IAccGroup __RPC_FAR * This,
            /* [in] */ xp_int position);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveBuddy )( 
            IAccGroup __RPC_FAR * This,
            /* [in] */ xp_int fromPosition,
            /* [in] */ xp_int toPosition);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBuddyByName )( 
            IAccGroup __RPC_FAR * This,
            /* [in] */ xp_kstr name,
            /* [retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *user);
        
        END_INTERFACE
    } IAccGroupVtbl;

    interface IAccGroup
    {
        CONST_VTBL struct IAccGroupVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccGroup_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccGroup_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccGroup_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccGroup_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccGroup_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccGroup_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccGroup_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccGroup_get_Name(This,name)	\
    (This)->lpVtbl -> get_Name(This,name)

#define IAccGroup_put_Name(This,name)	\
    (This)->lpVtbl -> put_Name(This,name)

#define IAccGroup_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccGroup_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccGroup_get_BuddyCount(This,count)	\
    (This)->lpVtbl -> get_BuddyCount(This,count)

#define IAccGroup_GetBuddyByIndex(This,position,user)	\
    (This)->lpVtbl -> GetBuddyByIndex(This,position,user)

#define IAccGroup_GetBuddyPosition(This,user,position)	\
    (This)->lpVtbl -> GetBuddyPosition(This,user,position)

#define IAccGroup_InsertBuddy(This,user,position,userRetval)	\
    (This)->lpVtbl -> InsertBuddy(This,user,position,userRetval)

#define IAccGroup_RemoveBuddy(This,position)	\
    (This)->lpVtbl -> RemoveBuddy(This,position)

#define IAccGroup_MoveBuddy(This,fromPosition,toPosition)	\
    (This)->lpVtbl -> MoveBuddy(This,fromPosition,toPosition)

#define IAccGroup_GetBuddyByName(This,name,user)	\
    (This)->lpVtbl -> GetBuddyByName(This,name,user)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IAccGroup_get_Name_Proxy( 
    IAccGroup __RPC_FAR * This,
    /* [retval][out] */ xp_str __RPC_FAR *name);


void __RPC_STUB IAccGroup_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE IAccGroup_put_Name_Proxy( 
    IAccGroup __RPC_FAR * This,
    /* [in] */ xp_kstr name);


void __RPC_STUB IAccGroup_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccGroup_get_Property_Proxy( 
    IAccGroup __RPC_FAR * This,
    /* [in] */ AccGroupProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccGroup_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccGroup_put_Property_Proxy( 
    IAccGroup __RPC_FAR * This,
    /* [in] */ AccGroupProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccGroup_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccGroup_get_BuddyCount_Proxy( 
    IAccGroup __RPC_FAR * This,
    /* [retval][out] */ xp_int __RPC_FAR *count);


void __RPC_STUB IAccGroup_get_BuddyCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccGroup_GetBuddyByIndex_Proxy( 
    IAccGroup __RPC_FAR * This,
    /* [in] */ xp_int position,
    /* [retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *user);


void __RPC_STUB IAccGroup_GetBuddyByIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccGroup_GetBuddyPosition_Proxy( 
    IAccGroup __RPC_FAR * This,
    /* [in] */ IAccUser __RPC_FAR *user,
    /* [retval][out] */ xp_int __RPC_FAR *position);


void __RPC_STUB IAccGroup_GetBuddyPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccGroup_InsertBuddy_Proxy( 
    IAccGroup __RPC_FAR * This,
    /* [in] */ xp_kvariant user,
    /* [defaultvalue][in] */ xp_int position,
    /* [defaultvalue][retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *userRetval);


void __RPC_STUB IAccGroup_InsertBuddy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccGroup_RemoveBuddy_Proxy( 
    IAccGroup __RPC_FAR * This,
    /* [in] */ xp_int position);


void __RPC_STUB IAccGroup_RemoveBuddy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccGroup_MoveBuddy_Proxy( 
    IAccGroup __RPC_FAR * This,
    /* [in] */ xp_int fromPosition,
    /* [in] */ xp_int toPosition);


void __RPC_STUB IAccGroup_MoveBuddy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccGroup_GetBuddyByName_Proxy( 
    IAccGroup __RPC_FAR * This,
    /* [in] */ xp_kstr name,
    /* [retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *user);


void __RPC_STUB IAccGroup_GetBuddyByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccGroup_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccGroup_0370 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccGroup)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_Session(IAccGroup* pi, IAccSession** px) { return get_Property(pi, AccGroupProp_Session, IID_IAccSession, px); };
#endif
static inline HRESULT get_Name(IAccGroup* pi, xp_str* px) { return get_Property(pi, AccGroupProp_Name, px); };
static inline HRESULT put_Name(IAccGroup* pi, xp_kstr x) { return put_Property(pi, AccGroupProp_Name, x); };
static inline HRESULT get_OnlineCount(IAccGroup* pi, xp_s32* px) { return get_Property(pi, AccGroupProp_OnlineCount, px); };
static inline HRESULT get_Collapsed(IAccGroup* pi, xp_bool* px) { return get_Property(pi, AccGroupProp_Collapsed, px); };
static inline HRESULT put_Collapsed(IAccGroup* pi, bool x) { return put_Property(pi, AccGroupProp_Collapsed, x); };
static inline HRESULT get_Shared(IAccGroup* pi, xp_bool* px) { return get_Property(pi, AccGroupProp_Shared, px); };
static inline HRESULT get_RecentBuddies(IAccGroup* pi, xp_bool* px) { return get_Property(pi, AccGroupProp_RecentBuddies, px); };
static inline HRESULT get_Smart(IAccGroup* pi, xp_bool* px) { return get_Property(pi, AccGroupProp_Smart, px); };
static inline HRESULT get_ReadOnly(IAccGroup* pi, xp_bool* px) { return get_Property(pi, AccGroupProp_ReadOnly, px); };
static inline HRESULT get_SynchronizedStorageType(IAccGroup* pi, xp_str* px) { return get_Property(pi, AccGroupProp_SynchronizedStorageType, px); };
static inline HRESULT put_SynchronizedStorageType(IAccGroup* pi, xp_kstr x) { return put_Property(pi, AccGroupProp_SynchronizedStorageType, x); };
static inline HRESULT get_SynchronizedStorageName(IAccGroup* pi, xp_str* px) { return get_Property(pi, AccGroupProp_SynchronizedStorageName, px); };
static inline HRESULT put_SynchronizedStorageName(IAccGroup* pi, xp_kstr x) { return put_Property(pi, AccGroupProp_SynchronizedStorageName, x); };
static inline HRESULT get_Offline(IAccGroup* pi, xp_bool* px) { return get_Property(pi, AccGroupProp_Offline, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccGroup_0370_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccGroup_0370_v0_0_s_ifspec;

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
