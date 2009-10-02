/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:27 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccDirEntry.idl:
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

#ifndef __IAccDirEntry_h__
#define __IAccDirEntry_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccDirEntry_FWD_DEFINED__
#define __IAccDirEntry_FWD_DEFINED__
typedef interface IAccDirEntry IAccDirEntry;
#endif 	/* __IAccDirEntry_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"


#ifndef __IAccDirEntry_INTERFACE_DEFINED__
#define __IAccDirEntry_INTERFACE_DEFINED__

/* interface IAccDirEntry */
/* [object][dual][uuid] */ 

typedef 
enum AccDirEntryProp
    {	AccDirEntryProp_UserName	= 9,
	AccDirEntryProp_FirstName	= 1,
	AccDirEntryProp_LastName	= 2,
	AccDirEntryProp_MiddleName	= 3,
	AccDirEntryProp_MaidenName	= 4,
	AccDirEntryProp_NickName	= 12,
	AccDirEntryProp_StreetAddress	= 33,
	AccDirEntryProp_City	= 8,
	AccDirEntryProp_State	= 7,
	AccDirEntryProp_ZipCode	= 13,
	AccDirEntryProp_Country	= 6
    }	AccDirEntryProp;


EXTERN_C const IID IID_IAccDirEntry;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("54faa38f-f5d0-42d7-9998-e6b52f1c1b1d")
    IAccDirEntry : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccDirEntryProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccDirEntryProp property,
            /* [in] */ xp_kvariant value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxPropertyLen( 
            /* [in] */ AccDirEntryProp property,
            /* [retval][out] */ xp_int __RPC_FAR *length) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccDirEntryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccDirEntry __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccDirEntry __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccDirEntry __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccDirEntry __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccDirEntry __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccDirEntry __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccDirEntry __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccDirEntry __RPC_FAR * This,
            /* [in] */ AccDirEntryProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccDirEntry __RPC_FAR * This,
            /* [in] */ AccDirEntryProp property,
            /* [in] */ xp_kvariant value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMaxPropertyLen )( 
            IAccDirEntry __RPC_FAR * This,
            /* [in] */ AccDirEntryProp property,
            /* [retval][out] */ xp_int __RPC_FAR *length);
        
        END_INTERFACE
    } IAccDirEntryVtbl;

    interface IAccDirEntry
    {
        CONST_VTBL struct IAccDirEntryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccDirEntry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccDirEntry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccDirEntry_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccDirEntry_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccDirEntry_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccDirEntry_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccDirEntry_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccDirEntry_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccDirEntry_put_Property(This,property,value)	\
    (This)->lpVtbl -> put_Property(This,property,value)

#define IAccDirEntry_GetMaxPropertyLen(This,property,length)	\
    (This)->lpVtbl -> GetMaxPropertyLen(This,property,length)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccDirEntry_get_Property_Proxy( 
    IAccDirEntry __RPC_FAR * This,
    /* [in] */ AccDirEntryProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccDirEntry_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccDirEntry_put_Property_Proxy( 
    IAccDirEntry __RPC_FAR * This,
    /* [in] */ AccDirEntryProp property,
    /* [in] */ xp_kvariant value);


void __RPC_STUB IAccDirEntry_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccDirEntry_GetMaxPropertyLen_Proxy( 
    IAccDirEntry __RPC_FAR * This,
    /* [in] */ AccDirEntryProp property,
    /* [retval][out] */ xp_int __RPC_FAR *length);


void __RPC_STUB IAccDirEntry_GetMaxPropertyLen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccDirEntry_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccDirEntry_0117 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccDirEntry)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_UserName(IAccDirEntry* pi, xp_str* px) { return get_Property(pi, AccDirEntryProp_UserName, px); };
static inline HRESULT put_UserName(IAccDirEntry* pi, xp_kstr x) { return put_Property(pi, AccDirEntryProp_UserName, x); };
static inline HRESULT get_FirstName(IAccDirEntry* pi, xp_str* px) { return get_Property(pi, AccDirEntryProp_FirstName, px); };
static inline HRESULT put_FirstName(IAccDirEntry* pi, xp_kstr x) { return put_Property(pi, AccDirEntryProp_FirstName, x); };
static inline HRESULT get_LastName(IAccDirEntry* pi, xp_str* px) { return get_Property(pi, AccDirEntryProp_LastName, px); };
static inline HRESULT put_LastName(IAccDirEntry* pi, xp_kstr x) { return put_Property(pi, AccDirEntryProp_LastName, x); };
static inline HRESULT get_MiddleName(IAccDirEntry* pi, xp_str* px) { return get_Property(pi, AccDirEntryProp_MiddleName, px); };
static inline HRESULT put_MiddleName(IAccDirEntry* pi, xp_kstr x) { return put_Property(pi, AccDirEntryProp_MiddleName, x); };
static inline HRESULT get_MaidenName(IAccDirEntry* pi, xp_str* px) { return get_Property(pi, AccDirEntryProp_MaidenName, px); };
static inline HRESULT put_MaidenName(IAccDirEntry* pi, xp_kstr x) { return put_Property(pi, AccDirEntryProp_MaidenName, x); };
static inline HRESULT get_NickName(IAccDirEntry* pi, xp_str* px) { return get_Property(pi, AccDirEntryProp_NickName, px); };
static inline HRESULT put_NickName(IAccDirEntry* pi, xp_kstr x) { return put_Property(pi, AccDirEntryProp_NickName, x); };
static inline HRESULT get_StreetAddress(IAccDirEntry* pi, xp_str* px) { return get_Property(pi, AccDirEntryProp_StreetAddress, px); };
static inline HRESULT put_StreetAddress(IAccDirEntry* pi, xp_kstr x) { return put_Property(pi, AccDirEntryProp_StreetAddress, x); };
static inline HRESULT get_City(IAccDirEntry* pi, xp_str* px) { return get_Property(pi, AccDirEntryProp_City, px); };
static inline HRESULT put_City(IAccDirEntry* pi, xp_kstr x) { return put_Property(pi, AccDirEntryProp_City, x); };
static inline HRESULT get_State(IAccDirEntry* pi, xp_str* px) { return get_Property(pi, AccDirEntryProp_State, px); };
static inline HRESULT put_State(IAccDirEntry* pi, xp_kstr x) { return put_Property(pi, AccDirEntryProp_State, x); };
static inline HRESULT get_ZipCode(IAccDirEntry* pi, xp_str* px) { return get_Property(pi, AccDirEntryProp_ZipCode, px); };
static inline HRESULT put_ZipCode(IAccDirEntry* pi, xp_kstr x) { return put_Property(pi, AccDirEntryProp_ZipCode, x); };
static inline HRESULT get_Country(IAccDirEntry* pi, xp_str* px) { return get_Property(pi, AccDirEntryProp_Country, px); };
static inline HRESULT put_Country(IAccDirEntry* pi, xp_kstr x) { return put_Property(pi, AccDirEntryProp_Country, x); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccDirEntry_0117_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccDirEntry_0117_v0_0_s_ifspec;

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
