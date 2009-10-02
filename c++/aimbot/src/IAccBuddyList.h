/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:23 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccBuddyList.idl:
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

#ifndef __IAccBuddyList_h__
#define __IAccBuddyList_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccBuddyList_FWD_DEFINED__
#define __IAccBuddyList_FWD_DEFINED__
typedef interface IAccBuddyList IAccBuddyList;
#endif 	/* __IAccBuddyList_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccGroup.h"


#ifndef __IAccBuddyList_INTERFACE_DEFINED__
#define __IAccBuddyList_INTERFACE_DEFINED__

/* interface IAccBuddyList */
/* [object][dual][uuid] */ 

typedef 
enum AccBuddyListProp
    {	AccBuddyListProp_Session	= -1,
	AccBuddyListProp_MaxGroupCount	= AccBuddyListProp_Session + 1,
	AccBuddyListProp_MaxBuddyCount	= AccBuddyListProp_MaxGroupCount + 1,
	AccBuddyListProp_MaxGroupNameLength	= AccBuddyListProp_MaxBuddyCount + 1,
	AccBuddyListProp_MaxBuddyNameLength	= AccBuddyListProp_MaxGroupNameLength + 1,
	AccBuddyListProp_MaxBuddyCountPerGroup	= AccBuddyListProp_MaxBuddyNameLength + 1,
	AccBuddyListProp_Ready	= AccBuddyListProp_MaxBuddyCountPerGroup + 1
    }	AccBuddyListProp;


EXTERN_C const IID IID_IAccBuddyList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4d0cc892-b61c-11d6-9156-001083341cf5")
    IAccBuddyList : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_GroupCount( 
            /* [retval][out] */ xp_int __RPC_FAR *count) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGroupByIndex( 
            /* [in] */ xp_int position,
            /* [retval][out] */ IAccGroup __RPC_FAR *__RPC_FAR *group) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGroupPosition( 
            /* [in] */ IAccGroup __RPC_FAR *group,
            /* [retval][out] */ xp_int __RPC_FAR *position) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccBuddyListProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccBuddyListProp property,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InsertGroup( 
            /* [in] */ xp_kvariant group,
            /* [defaultvalue][in] */ xp_int position = -1,
            /* [defaultvalue][retval][out] */ IAccGroup __RPC_FAR *__RPC_FAR *groupRetval = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveGroup( 
            /* [in] */ xp_int position) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveGroup( 
            /* [in] */ xp_int fromPosition,
            /* [in] */ xp_int toPosition) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveBuddy( 
            /* [in] */ xp_int fromGroup,
            /* [in] */ xp_int fromPosition,
            /* [in] */ xp_int toGroup,
            /* [in] */ xp_int toPosition) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGroupByName( 
            /* [in] */ xp_kstr name,
            /* [retval][out] */ IAccGroup __RPC_FAR *__RPC_FAR *group) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBuddyByName( 
            /* [in] */ xp_kstr name,
            /* [retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *buddy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFrequentBuddies( 
            /* [defaultvalue][in] */ xp_int num,
            /* [retval][out] */ xp_variant __RPC_FAR *sortedBuddies) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccBuddyListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccBuddyList __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccBuddyList __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccBuddyList __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccBuddyList __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccBuddyList __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccBuddyList __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccBuddyList __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GroupCount )( 
            IAccBuddyList __RPC_FAR * This,
            /* [retval][out] */ xp_int __RPC_FAR *count);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGroupByIndex )( 
            IAccBuddyList __RPC_FAR * This,
            /* [in] */ xp_int position,
            /* [retval][out] */ IAccGroup __RPC_FAR *__RPC_FAR *group);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGroupPosition )( 
            IAccBuddyList __RPC_FAR * This,
            /* [in] */ IAccGroup __RPC_FAR *group,
            /* [retval][out] */ xp_int __RPC_FAR *position);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccBuddyList __RPC_FAR * This,
            /* [in] */ AccBuddyListProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccBuddyList __RPC_FAR * This,
            /* [in] */ AccBuddyListProp property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InsertGroup )( 
            IAccBuddyList __RPC_FAR * This,
            /* [in] */ xp_kvariant group,
            /* [defaultvalue][in] */ xp_int position,
            /* [defaultvalue][retval][out] */ IAccGroup __RPC_FAR *__RPC_FAR *groupRetval);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveGroup )( 
            IAccBuddyList __RPC_FAR * This,
            /* [in] */ xp_int position);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveGroup )( 
            IAccBuddyList __RPC_FAR * This,
            /* [in] */ xp_int fromPosition,
            /* [in] */ xp_int toPosition);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MoveBuddy )( 
            IAccBuddyList __RPC_FAR * This,
            /* [in] */ xp_int fromGroup,
            /* [in] */ xp_int fromPosition,
            /* [in] */ xp_int toGroup,
            /* [in] */ xp_int toPosition);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGroupByName )( 
            IAccBuddyList __RPC_FAR * This,
            /* [in] */ xp_kstr name,
            /* [retval][out] */ IAccGroup __RPC_FAR *__RPC_FAR *group);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBuddyByName )( 
            IAccBuddyList __RPC_FAR * This,
            /* [in] */ xp_kstr name,
            /* [retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *buddy);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFrequentBuddies )( 
            IAccBuddyList __RPC_FAR * This,
            /* [defaultvalue][in] */ xp_int num,
            /* [retval][out] */ xp_variant __RPC_FAR *sortedBuddies);
        
        END_INTERFACE
    } IAccBuddyListVtbl;

    interface IAccBuddyList
    {
        CONST_VTBL struct IAccBuddyListVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccBuddyList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccBuddyList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccBuddyList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccBuddyList_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccBuddyList_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccBuddyList_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccBuddyList_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccBuddyList_get_GroupCount(This,count)	\
    (This)->lpVtbl -> get_GroupCount(This,count)

#define IAccBuddyList_GetGroupByIndex(This,position,group)	\
    (This)->lpVtbl -> GetGroupByIndex(This,position,group)

#define IAccBuddyList_GetGroupPosition(This,group,position)	\
    (This)->lpVtbl -> GetGroupPosition(This,group,position)

#define IAccBuddyList_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccBuddyList_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccBuddyList_InsertGroup(This,group,position,groupRetval)	\
    (This)->lpVtbl -> InsertGroup(This,group,position,groupRetval)

#define IAccBuddyList_RemoveGroup(This,position)	\
    (This)->lpVtbl -> RemoveGroup(This,position)

#define IAccBuddyList_MoveGroup(This,fromPosition,toPosition)	\
    (This)->lpVtbl -> MoveGroup(This,fromPosition,toPosition)

#define IAccBuddyList_MoveBuddy(This,fromGroup,fromPosition,toGroup,toPosition)	\
    (This)->lpVtbl -> MoveBuddy(This,fromGroup,fromPosition,toGroup,toPosition)

#define IAccBuddyList_GetGroupByName(This,name,group)	\
    (This)->lpVtbl -> GetGroupByName(This,name,group)

#define IAccBuddyList_GetBuddyByName(This,name,buddy)	\
    (This)->lpVtbl -> GetBuddyByName(This,name,buddy)

#define IAccBuddyList_GetFrequentBuddies(This,num,sortedBuddies)	\
    (This)->lpVtbl -> GetFrequentBuddies(This,num,sortedBuddies)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccBuddyList_get_GroupCount_Proxy( 
    IAccBuddyList __RPC_FAR * This,
    /* [retval][out] */ xp_int __RPC_FAR *count);


void __RPC_STUB IAccBuddyList_get_GroupCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccBuddyList_GetGroupByIndex_Proxy( 
    IAccBuddyList __RPC_FAR * This,
    /* [in] */ xp_int position,
    /* [retval][out] */ IAccGroup __RPC_FAR *__RPC_FAR *group);


void __RPC_STUB IAccBuddyList_GetGroupByIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccBuddyList_GetGroupPosition_Proxy( 
    IAccBuddyList __RPC_FAR * This,
    /* [in] */ IAccGroup __RPC_FAR *group,
    /* [retval][out] */ xp_int __RPC_FAR *position);


void __RPC_STUB IAccBuddyList_GetGroupPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccBuddyList_get_Property_Proxy( 
    IAccBuddyList __RPC_FAR * This,
    /* [in] */ AccBuddyListProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccBuddyList_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccBuddyList_put_Property_Proxy( 
    IAccBuddyList __RPC_FAR * This,
    /* [in] */ AccBuddyListProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccBuddyList_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccBuddyList_InsertGroup_Proxy( 
    IAccBuddyList __RPC_FAR * This,
    /* [in] */ xp_kvariant group,
    /* [defaultvalue][in] */ xp_int position,
    /* [defaultvalue][retval][out] */ IAccGroup __RPC_FAR *__RPC_FAR *groupRetval);


void __RPC_STUB IAccBuddyList_InsertGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccBuddyList_RemoveGroup_Proxy( 
    IAccBuddyList __RPC_FAR * This,
    /* [in] */ xp_int position);


void __RPC_STUB IAccBuddyList_RemoveGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccBuddyList_MoveGroup_Proxy( 
    IAccBuddyList __RPC_FAR * This,
    /* [in] */ xp_int fromPosition,
    /* [in] */ xp_int toPosition);


void __RPC_STUB IAccBuddyList_MoveGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccBuddyList_MoveBuddy_Proxy( 
    IAccBuddyList __RPC_FAR * This,
    /* [in] */ xp_int fromGroup,
    /* [in] */ xp_int fromPosition,
    /* [in] */ xp_int toGroup,
    /* [in] */ xp_int toPosition);


void __RPC_STUB IAccBuddyList_MoveBuddy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccBuddyList_GetGroupByName_Proxy( 
    IAccBuddyList __RPC_FAR * This,
    /* [in] */ xp_kstr name,
    /* [retval][out] */ IAccGroup __RPC_FAR *__RPC_FAR *group);


void __RPC_STUB IAccBuddyList_GetGroupByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccBuddyList_GetBuddyByName_Proxy( 
    IAccBuddyList __RPC_FAR * This,
    /* [in] */ xp_kstr name,
    /* [retval][out] */ IAccUser __RPC_FAR *__RPC_FAR *buddy);


void __RPC_STUB IAccBuddyList_GetBuddyByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccBuddyList_GetFrequentBuddies_Proxy( 
    IAccBuddyList __RPC_FAR * This,
    /* [defaultvalue][in] */ xp_int num,
    /* [retval][out] */ xp_variant __RPC_FAR *sortedBuddies);


void __RPC_STUB IAccBuddyList_GetFrequentBuddies_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccBuddyList_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccBuddyList_0342 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccBuddyList)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_Session(IAccBuddyList* pi, IAccSession** px) { return get_Property(pi, AccBuddyListProp_Session, IID_IAccSession, px); };
#endif
static inline HRESULT get_MaxGroupCount(IAccBuddyList* pi, xp_s32* px) { return get_Property(pi, AccBuddyListProp_MaxGroupCount, px); };
static inline HRESULT get_MaxBuddyCount(IAccBuddyList* pi, xp_s32* px) { return get_Property(pi, AccBuddyListProp_MaxBuddyCount, px); };
static inline HRESULT get_MaxGroupNameLength(IAccBuddyList* pi, xp_s32* px) { return get_Property(pi, AccBuddyListProp_MaxGroupNameLength, px); };
static inline HRESULT get_MaxBuddyNameLength(IAccBuddyList* pi, xp_s32* px) { return get_Property(pi, AccBuddyListProp_MaxBuddyNameLength, px); };
static inline HRESULT get_MaxBuddyCountPerGroup(IAccBuddyList* pi, xp_s32* px) { return get_Property(pi, AccBuddyListProp_MaxBuddyCountPerGroup, px); };
static inline HRESULT get_Ready(IAccBuddyList* pi, xp_bool* px) { return get_Property(pi, AccBuddyListProp_Ready, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccBuddyList_0342_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccBuddyList_0342_v0_0_s_ifspec;

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
