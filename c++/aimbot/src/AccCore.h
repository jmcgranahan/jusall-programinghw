/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Sep 12 14:01:45 2007
 */
/* Compiler settings for C:\dev\cvs\client\aimcc\idl\AccCore.idl:
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

#ifndef __AccCore_h__
#define __AccCore_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __DAccEvents_FWD_DEFINED__
#define __DAccEvents_FWD_DEFINED__
typedef interface DAccEvents DAccEvents;
#endif 	/* __DAccEvents_FWD_DEFINED__ */


#ifndef __AccSession_FWD_DEFINED__
#define __AccSession_FWD_DEFINED__

#ifdef __cplusplus
typedef class AccSession AccSession;
#else
typedef struct AccSession AccSession;
#endif /* __cplusplus */

#endif 	/* __AccSession_FWD_DEFINED__ */


#ifndef __IAccMessage_FWD_DEFINED__
#define __IAccMessage_FWD_DEFINED__
typedef interface IAccMessage IAccMessage;
#endif 	/* __IAccMessage_FWD_DEFINED__ */


/* header files for imported files */
#include "IAccSession.h"
#include "IAccAvManager.h"
#include "IAccAvTrack.h"
#include "IAccAlert.h"
#include "IAccCallAlert.h"
#include "IAccCommandTarget.h"
#include "IAccEmoticon.h"
#include "IAccEmoticonSet.h"
#include "IAccFileSharingItem.h"
#include "IAccFileSharingManager.h"
#include "IAccFileXfer.h"
#include "IAccFileXferManager.h"
#include "IAccImSummary.h"
#include "IAccLocation.h"
#include "IAccParticipant.h"
#include "IAccServiceTicket.h"
#include "IAccShareBuddiesManager.h"
#include "IAccStreamListener.h"
#include "IAccUpgradeInfo.h"


/* interface __MIDL_itf_AccCore_0000 */
/* [local] */ 

#include "AccDispid.h"


extern RPC_IF_HANDLE __MIDL_itf_AccCore_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AccCore_0000_v0_0_s_ifspec;


#ifndef __AccCoreLib_LIBRARY_DEFINED__
#define __AccCoreLib_LIBRARY_DEFINED__

/* library AccCoreLib */
/* [helpstring][version][uuid] */ 


























































































EXTERN_C const IID LIBID_AccCoreLib;

#ifndef __DAccEvents_DISPINTERFACE_DEFINED__
#define __DAccEvents_DISPINTERFACE_DEFINED__

/* dispinterface DAccEvents */
/* [uuid] */ 


EXTERN_C const IID DIID_DAccEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("0D476EFC-40DB-4d5f-AF29-C7D08FB56B8C")
    DAccEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct DAccEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            DAccEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            DAccEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            DAccEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            DAccEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            DAccEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            DAccEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            DAccEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } DAccEventsVtbl;

    interface DAccEvents
    {
        CONST_VTBL struct DAccEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define DAccEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define DAccEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define DAccEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define DAccEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define DAccEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define DAccEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define DAccEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __DAccEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_AccSession;

#ifdef __cplusplus

class DECLSPEC_UUID("C27E3386-E992-4321-B38E-684D8EFA5647")
AccSession;
#endif
#endif /* __AccCoreLib_LIBRARY_DEFINED__ */

#ifndef __IAccMessage_INTERFACE_DEFINED__
#define __IAccMessage_INTERFACE_DEFINED__

/* interface IAccMessage */
/* [local][hidden][uuid][object] */ 


EXTERN_C const IID IID_IAccMessage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4822FAB7-66DE-401c-902F-177F548F9B27")
    IAccMessage : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Dispatch( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccMessageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccMessage __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccMessage __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccMessage __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Dispatch )( 
            IAccMessage __RPC_FAR * This);
        
        END_INTERFACE
    } IAccMessageVtbl;

    interface IAccMessage
    {
        CONST_VTBL struct IAccMessageVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccMessage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccMessage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccMessage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccMessage_Dispatch(This)	\
    (This)->lpVtbl -> Dispatch(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IAccMessage_Dispatch_Proxy( 
    IAccMessage __RPC_FAR * This);


void __RPC_STUB IAccMessage_Dispatch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccMessage_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_AccCore_0502 */
/* [local] */ 

STDAPI AccCreateObject(REFCLSID, REFIID, void**);
STDAPI AccCreateSession(REFIID, void**);
STDAPI AccGetSession(xp_kstr userName, REFIID iid, void** pp);
STDAPI AccGetSessions(xp_array** ppsa);
STDAPI_(void) AccDispatchMessages(xp_int msec);
STDAPI AccMessageLoop();
STDAPI_(void*) AccGetMessageQueue();
STDAPI AccPostMessage(IAccMessage*);
STDAPI AccPostMessage2(void* queue, IAccMessage*);
STDAPI AccPostQuit(HRESULT);
#ifndef WIN32
STDAPI AccSetMessageAvailableCallback(AccMessageAvailableCallback, void*);
#endif
STDAPI_(void) AccSetDelayLoadRoot(xp_kstr);
STDAPI AccGetErrorInfo(IErrorInfo**);
STDAPI AccMemAlloc(xp_int size, void** pp);
STDAPI AccMemFree(void* p);
STDAPI AccStringAlloc(xp_kstr buf, xp_str* pstr);
STDAPI AccStringAllocUtf8(const char* buf, xp_str* pstr);
STDAPI_(void) AccStringFree(xp_str str);
STDAPI_(xp_int) AccStringLen(xp_kstr str);
STDAPI_(xp_int) AccStringCompare(xp_kstr str1, xp_kstr str2);
STDAPI_(xp_int) AccStringGetUtf8(xp_kstr str, char* buf, xp_int bufLen);
STDAPI_(xp_bool) AccStringWillTruncateForBartItem(xp_kstr str, AccBartItemType bartItemType);
STDAPI_(xp_bool) AccStringHasPrefix(xp_kstr str, xp_kstr prefix);
STDAPI_(void) AccVarInit(xp_variant* pvar);
STDAPI AccVarClear(xp_variant* pvar);
STDAPI AccVarCopy(xp_variant* pvard, xp_variant* pvars);
STDAPI AccVarTimeToUnixTime(DATE d, xp_s32 *t);
STDAPI AccUnixTimeToVarTime(xp_s32 t, DATE* d);
STDAPI AccVarChangeType(xp_variant* pvard, xp_variant* pvars, xp_vtype vt);
STDAPI AccArrayCreate(xp_vtype vt, xp_int size, xp_array** ppsa);
STDAPI AccArrayDestroy(xp_array* psa);
STDAPI AccArrayCopy(xp_array* psa, xp_array** ppsa);
STDAPI AccArrayRedim(xp_array* psa, xp_int size);
STDAPI AccArrayLock(xp_array* psa);
STDAPI AccArrayUnlock(xp_array* psa);
STDAPI AccArrayGetVartype(xp_array* psa, xp_vtype* pvt);
STDAPI AccArrayGetCount(xp_array* psa, xp_int* pVal);
STDAPI AccArrayGetElement(xp_array* psa, xp_int index, void* p);
STDAPI AccArrayPutElement(xp_array* psa, xp_int index, void* p);
STDAPI AccArrayPtrOfIndex(xp_array* psa, xp_int index, void** pp);
STDAPI AccArrayGetElemsize(xp_array* psa);
STDAPI AccStreamCreateFromMemory(const xp_u08* p, xp_s64 size, xp_kstr name, xp_uint flags, IAccStream** ppiStream);
#ifdef WIN32
STDAPI AccPluginGetInfo(xp_kstr path, IAccPluginInfo** pp);
STDAPI AccPluginInstall(xp_kstr path, xp_kstr dstDir);
STDAPI AccPluginUninstall(xp_kstr uuid);
#endif

extern RPC_IF_HANDLE __MIDL_itf_AccCore_0502_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AccCore_0502_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
