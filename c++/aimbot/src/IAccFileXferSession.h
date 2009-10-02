/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:36 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccFileXferSession.idl:
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

#ifndef __IAccFileXferSession_h__
#define __IAccFileXferSession_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccFileXferSession_FWD_DEFINED__
#define __IAccFileXferSession_FWD_DEFINED__
typedef interface IAccFileXferSession IAccFileXferSession;
#endif 	/* __IAccFileXferSession_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccSecondarySession.h"


#ifndef __IAccFileXferSession_INTERFACE_DEFINED__
#define __IAccFileXferSession_INTERFACE_DEFINED__

/* interface IAccFileXferSession */
/* [object][dual][uuid] */ 

typedef 
enum AccFileXferSessionProp
    {	AccFileXferSessionProp_CurrentFileXfer	= 1000,
	AccFileXferSessionProp_DownloadDirPath	= AccFileXferSessionProp_CurrentFileXfer + 1,
	AccFileXferSessionProp_FileSharingSession	= AccFileXferSessionProp_DownloadDirPath + 1,
	AccFileXferSessionProp_IsDirectory	= AccFileXferSessionProp_FileSharingSession + 1,
	AccFileXferSessionProp_Name	= AccFileXferSessionProp_IsDirectory + 1,
	AccFileXferSessionProp_Send	= AccFileXferSessionProp_Name + 1,
	AccFileXferSessionProp_Speed	= AccFileXferSessionProp_Send + 1,
	AccFileXferSessionProp_TotalBytes	= AccFileXferSessionProp_Speed + 1,
	AccFileXferSessionProp_TotalBytesXferred	= AccFileXferSessionProp_TotalBytes + 1,
	AccFileXferSessionProp_TotalNumFiles	= AccFileXferSessionProp_TotalBytesXferred + 1,
	AccFileXferSessionProp_TotalNumFilesRemaining	= AccFileXferSessionProp_TotalNumFiles + 1
    }	AccFileXferSessionProp;

typedef 
enum AccFileXferSessionCollisionAction
    {	AccFileXferSessionCollisionAction_SaveAs	= 0,
	AccFileXferSessionCollisionAction_Skip	= AccFileXferSessionCollisionAction_SaveAs + 1,
	AccFileXferSessionCollisionAction_Replace	= AccFileXferSessionCollisionAction_Skip + 1,
	AccFileXferSessionCollisionAction_SkipAll	= AccFileXferSessionCollisionAction_Replace + 1,
	AccFileXferSessionCollisionAction_ReplaceAll	= AccFileXferSessionCollisionAction_SkipAll + 1
    }	AccFileXferSessionCollisionAction;


EXTERN_C const IID IID_IAccFileXferSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8d1a492e-e923-11d7-962e-00e081103594")
    IAccFileXferSession : public IAccSecondarySession
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property_( 
            /* [in] */ AccFileXferSessionProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property_( 
            /* [in] */ AccFileXferSessionProp property,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResolveCollision( 
            /* [in] */ AccFileXferSessionCollisionAction action,
            /* [defaultvalue][in] */ xp_kstr path = 0) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccFileXferSessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccFileXferSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccFileXferSession __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccFileXferSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccFileXferSession __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccFileXferSession __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccFileXferSession __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccFileXferSession __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ServiceId )( 
            IAccFileXferSession __RPC_FAR * This,
            /* [retval][out] */ AccSecondarySessionServiceId __RPC_FAR *pId);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccFileXferSession __RPC_FAR * This,
            /* [in] */ xp_int property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccFileXferSession __RPC_FAR * This,
            /* [in] */ xp_int property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Accept )( 
            IAccFileXferSession __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Reject )( 
            IAccFileXferSession __RPC_FAR * This,
            /* [defaultvalue][in] */ xp_int reason);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invite )( 
            IAccFileXferSession __RPC_FAR * This,
            /* [in] */ xp_kstr invitee,
            /* [in] */ xp_kstr invitation,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CancelProposal )( 
            IAccFileXferSession __RPC_FAR * This,
            /* [in] */ xp_kstr invitee);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Eject )( 
            IAccFileXferSession __RPC_FAR * This,
            /* [in] */ xp_kstr userName,
            /* [defaultvalue][in] */ xp_kstr reason,
            /* [retval][out] */ AccTransId __RPC_FAR *pTransId);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EndSession )( 
            IAccFileXferSession __RPC_FAR * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property_ )( 
            IAccFileXferSession __RPC_FAR * This,
            /* [in] */ AccFileXferSessionProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property_ )( 
            IAccFileXferSession __RPC_FAR * This,
            /* [in] */ AccFileXferSessionProp property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ResolveCollision )( 
            IAccFileXferSession __RPC_FAR * This,
            /* [in] */ AccFileXferSessionCollisionAction action,
            /* [defaultvalue][in] */ xp_kstr path);
        
        END_INTERFACE
    } IAccFileXferSessionVtbl;

    interface IAccFileXferSession
    {
        CONST_VTBL struct IAccFileXferSessionVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccFileXferSession_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccFileXferSession_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccFileXferSession_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccFileXferSession_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccFileXferSession_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccFileXferSession_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccFileXferSession_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccFileXferSession_get_ServiceId(This,pId)	\
    (This)->lpVtbl -> get_ServiceId(This,pId)

#define IAccFileXferSession_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccFileXferSession_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccFileXferSession_Accept(This)	\
    (This)->lpVtbl -> Accept(This)

#define IAccFileXferSession_Reject(This,reason)	\
    (This)->lpVtbl -> Reject(This,reason)

#define IAccFileXferSession_Invite(This,invitee,invitation,pTransId)	\
    (This)->lpVtbl -> Invite(This,invitee,invitation,pTransId)

#define IAccFileXferSession_CancelProposal(This,invitee)	\
    (This)->lpVtbl -> CancelProposal(This,invitee)

#define IAccFileXferSession_Eject(This,userName,reason,pTransId)	\
    (This)->lpVtbl -> Eject(This,userName,reason,pTransId)

#define IAccFileXferSession_EndSession(This)	\
    (This)->lpVtbl -> EndSession(This)


#define IAccFileXferSession_get_Property_(This,property,value)	\
    (This)->lpVtbl -> get_Property_(This,property,value)

#define IAccFileXferSession_put_Property_(This,property,value)	\
    (This)->lpVtbl -> put_Property_(This,property,value)

#define IAccFileXferSession_ResolveCollision(This,action,path)	\
    (This)->lpVtbl -> ResolveCollision(This,action,path)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccFileXferSession_get_Property__Proxy( 
    IAccFileXferSession __RPC_FAR * This,
    /* [in] */ AccFileXferSessionProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccFileXferSession_get_Property__Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccFileXferSession_put_Property__Proxy( 
    IAccFileXferSession __RPC_FAR * This,
    /* [in] */ AccFileXferSessionProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccFileXferSession_put_Property__Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccFileXferSession_ResolveCollision_Proxy( 
    IAccFileXferSession __RPC_FAR * This,
    /* [in] */ AccFileXferSessionCollisionAction action,
    /* [defaultvalue][in] */ xp_kstr path);


void __RPC_STUB IAccFileXferSession_ResolveCollision_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccFileXferSession_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccFileXferSession_0121 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccFileXferSession)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_CurrentFileXfer(IAccFileXferSession* pi, IAccFileXfer** px) { return get_Property(pi, AccFileXferSessionProp_CurrentFileXfer, IID_IAccFileXfer, px); };
#endif
static inline HRESULT get_DownloadDirPath(IAccFileXferSession* pi, xp_str* px) { return get_Property(pi, AccFileXferSessionProp_DownloadDirPath, px); };
static inline HRESULT put_DownloadDirPath(IAccFileXferSession* pi, xp_kstr x) { return put_Property(pi, AccFileXferSessionProp_DownloadDirPath, x); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_FileSharingSession(IAccFileXferSession* pi, IAccFileXferSession** px) { return get_Property(pi, AccFileXferSessionProp_FileSharingSession, IID_IAccFileXferSession, px); };
#endif
static inline HRESULT get_IsDirectory(IAccFileXferSession* pi, xp_bool* px) { return get_Property(pi, AccFileXferSessionProp_IsDirectory, px); };
static inline HRESULT get_Name(IAccFileXferSession* pi, xp_str* px) { return get_Property(pi, AccFileXferSessionProp_Name, px); };
static inline HRESULT put_Name(IAccFileXferSession* pi, xp_kstr x) { return put_Property(pi, AccFileXferSessionProp_Name, x); };
static inline HRESULT get_Send(IAccFileXferSession* pi, xp_bool* px) { return get_Property(pi, AccFileXferSessionProp_Send, px); };
static inline HRESULT get_Speed(IAccFileXferSession* pi, xp_s32* px) { return get_Property(pi, AccFileXferSessionProp_Speed, px); };
static inline HRESULT get_TotalBytes(IAccFileXferSession* pi, xp_s64* px) { return get_Property(pi, AccFileXferSessionProp_TotalBytes, px); };
static inline HRESULT get_TotalBytesXferred(IAccFileXferSession* pi, xp_s64* px) { return get_Property(pi, AccFileXferSessionProp_TotalBytesXferred, px); };
static inline HRESULT get_TotalNumFiles(IAccFileXferSession* pi, xp_s32* px) { return get_Property(pi, AccFileXferSessionProp_TotalNumFiles, px); };
static inline HRESULT get_TotalNumFilesRemaining(IAccFileXferSession* pi, xp_s32* px) { return get_Property(pi, AccFileXferSessionProp_TotalNumFilesRemaining, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccFileXferSession_0121_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccFileXferSession_0121_v0_0_s_ifspec;

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
