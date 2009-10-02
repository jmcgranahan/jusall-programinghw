/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Feb 05 15:43:17 2008
 */
/* Compiler settings for C:\dev\aimcc\aimcc\idl\IAccCommand.idl:
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

#ifndef __IAccCommand_h__
#define __IAccCommand_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccCommand_FWD_DEFINED__
#define __IAccCommand_FWD_DEFINED__
typedef interface IAccCommand IAccCommand;
#endif 	/* __IAccCommand_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"


/* interface __MIDL_itf_IAccCommand_0000 */
/* [local] */ 

typedef 
enum AccCommandId
    {	AccCommandId_Preferences	= -1,
	AccCommandId_Default	= 0
    }	AccCommandId;



extern RPC_IF_HANDLE __MIDL_itf_IAccCommand_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccCommand_0000_v0_0_s_ifspec;

#ifndef __IAccCommand_INTERFACE_DEFINED__
#define __IAccCommand_INTERFACE_DEFINED__

/* interface IAccCommand */
/* [object][dual][uuid] */ 

typedef 
enum AccCommandFlags
    {	AccCommandFlags_BuddyCentric	= 0x1,
	AccCommandFlags_ActionsUi	= 0x2,
	AccCommandFlags_BuddyUi	= 0x4,
	AccCommandFlags_GroupUi	= 0x8,
	AccCommandFlags_ImSessionUi	= 0x10,
	AccCommandFlags_PreferencesUi	= 0x20,
	AccCommandFlags_AboutUi	= 0x40,
	AccCommandFlags_PresenceUi	= 0x80,
	AccCommandFlags_UninstallUi	= 0x100
    }	AccCommandFlags;

typedef 
enum AccCommandProp
    {	AccCommandProp_Id	= 0,
	AccCommandProp_Text	= AccCommandProp_Id + 1,
	AccCommandProp_SmallIconUrl	= AccCommandProp_Text + 1,
	AccCommandProp_Flags	= AccCommandProp_SmallIconUrl + 1,
	AccCommandProp_ParentId	= AccCommandProp_Flags + 1
    }	AccCommandProp;


EXTERN_C const IID IID_IAccCommand;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("c7c8c8b2-ebe6-42a7-b225-29d5c403e498")
    IAccCommand : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Id( 
            /* [retval][out] */ xp_int __RPC_FAR *id) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccCommandProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccCommandProp property,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryStatus( 
            /* [in] */ xp_kvariant names,
            /* [retval][out] */ xp_vbool __RPC_FAR *enabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Exec( 
            /* [in] */ xp_kvariant names) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccCommandVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccCommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccCommand __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccCommand __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccCommand __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccCommand __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccCommand __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccCommand __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Id )( 
            IAccCommand __RPC_FAR * This,
            /* [retval][out] */ xp_int __RPC_FAR *id);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccCommand __RPC_FAR * This,
            /* [in] */ AccCommandProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccCommand __RPC_FAR * This,
            /* [in] */ AccCommandProp property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryStatus )( 
            IAccCommand __RPC_FAR * This,
            /* [in] */ xp_kvariant names,
            /* [retval][out] */ xp_vbool __RPC_FAR *enabled);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Exec )( 
            IAccCommand __RPC_FAR * This,
            /* [in] */ xp_kvariant names);
        
        END_INTERFACE
    } IAccCommandVtbl;

    interface IAccCommand
    {
        CONST_VTBL struct IAccCommandVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccCommand_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccCommand_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccCommand_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccCommand_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccCommand_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccCommand_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccCommand_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccCommand_get_Id(This,id)	\
    (This)->lpVtbl -> get_Id(This,id)

#define IAccCommand_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccCommand_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccCommand_QueryStatus(This,names,enabled)	\
    (This)->lpVtbl -> QueryStatus(This,names,enabled)

#define IAccCommand_Exec(This,names)	\
    (This)->lpVtbl -> Exec(This,names)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IAccCommand_get_Id_Proxy( 
    IAccCommand __RPC_FAR * This,
    /* [retval][out] */ xp_int __RPC_FAR *id);


void __RPC_STUB IAccCommand_get_Id_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccCommand_get_Property_Proxy( 
    IAccCommand __RPC_FAR * This,
    /* [in] */ AccCommandProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccCommand_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccCommand_put_Property_Proxy( 
    IAccCommand __RPC_FAR * This,
    /* [in] */ AccCommandProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccCommand_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccCommand_QueryStatus_Proxy( 
    IAccCommand __RPC_FAR * This,
    /* [in] */ xp_kvariant names,
    /* [retval][out] */ xp_vbool __RPC_FAR *enabled);


void __RPC_STUB IAccCommand_QueryStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccCommand_Exec_Proxy( 
    IAccCommand __RPC_FAR * This,
    /* [in] */ xp_kvariant names);


void __RPC_STUB IAccCommand_Exec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccCommand_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccCommand_0117 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccCommand)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_Id(IAccCommand* pi, xp_int* px) { return get_Property(pi, AccCommandProp_Id, px); };
static inline HRESULT get_Text(IAccCommand* pi, xp_str* px) { return get_Property(pi, AccCommandProp_Text, px); };
static inline HRESULT put_Text(IAccCommand* pi, xp_kstr x) { return put_Property(pi, AccCommandProp_Text, x); };
static inline HRESULT get_SmallIconUrl(IAccCommand* pi, xp_str* px) { return get_Property(pi, AccCommandProp_SmallIconUrl, px); };
static inline HRESULT put_SmallIconUrl(IAccCommand* pi, xp_kstr x) { return put_Property(pi, AccCommandProp_SmallIconUrl, x); };
static inline HRESULT get_Flags(IAccCommand* pi, xp_u32* px) { return get_Property(pi, AccCommandProp_Flags, px); };
static inline HRESULT put_Flags(IAccCommand* pi, xp_u32 x) { return put_Property(pi, AccCommandProp_Flags, x); };
static inline HRESULT get_ParentId(IAccCommand* pi, xp_int* px) { return get_Property(pi, AccCommandProp_ParentId, px); };
static inline HRESULT put_ParentId(IAccCommand* pi, xp_int x) { return put_Property(pi, AccCommandProp_ParentId, x); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccCommand_0117_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccCommand_0117_v0_0_s_ifspec;

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
