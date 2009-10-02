/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Jan 07 12:47:04 2007
 */
/* Compiler settings for C:\dev\cvs\client\aimcc\idl\IAccEmoticon.idl:
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

#ifndef __IAccEmoticon_h__
#define __IAccEmoticon_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccEmoticon_FWD_DEFINED__
#define __IAccEmoticon_FWD_DEFINED__
typedef interface IAccEmoticon IAccEmoticon;
#endif 	/* __IAccEmoticon_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccStream.h"


#ifndef __IAccEmoticon_INTERFACE_DEFINED__
#define __IAccEmoticon_INTERFACE_DEFINED__

/* interface IAccEmoticon */
/* [object][dual][uuid] */ 

typedef 
enum AccEmoticonProp
    {	AccEmoticonProp_Data	= 0,
	AccEmoticonProp_Text	= AccEmoticonProp_Data + 1,
	AccEmoticonProp_Description	= AccEmoticonProp_Text + 1,
	AccEmoticonProp_DataStream	= AccEmoticonProp_Description + 1,
	AccEmoticonProp_BartUrl	= AccEmoticonProp_DataStream + 1
    }	AccEmoticonProp;


EXTERN_C const IID IID_IAccEmoticon;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0B951410-9D33-11D8-89B5-0003936CB786")
    IAccEmoticon : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Data( 
            /* [retval][out] */ xp_variant __RPC_FAR *data) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Text( 
            /* [retval][out] */ xp_str __RPC_FAR *text) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccEmoticonProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccEmoticonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccEmoticon __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccEmoticon __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccEmoticon __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccEmoticon __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccEmoticon __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccEmoticon __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccEmoticon __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Data )( 
            IAccEmoticon __RPC_FAR * This,
            /* [retval][out] */ xp_variant __RPC_FAR *data);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Text )( 
            IAccEmoticon __RPC_FAR * This,
            /* [retval][out] */ xp_str __RPC_FAR *text);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccEmoticon __RPC_FAR * This,
            /* [in] */ AccEmoticonProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        END_INTERFACE
    } IAccEmoticonVtbl;

    interface IAccEmoticon
    {
        CONST_VTBL struct IAccEmoticonVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccEmoticon_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccEmoticon_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccEmoticon_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccEmoticon_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccEmoticon_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccEmoticon_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccEmoticon_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccEmoticon_get_Data(This,data)	\
    (This)->lpVtbl -> get_Data(This,data)

#define IAccEmoticon_get_Text(This,text)	\
    (This)->lpVtbl -> get_Text(This,text)

#define IAccEmoticon_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccEmoticon_get_Data_Proxy( 
    IAccEmoticon __RPC_FAR * This,
    /* [retval][out] */ xp_variant __RPC_FAR *data);


void __RPC_STUB IAccEmoticon_get_Data_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccEmoticon_get_Text_Proxy( 
    IAccEmoticon __RPC_FAR * This,
    /* [retval][out] */ xp_str __RPC_FAR *text);


void __RPC_STUB IAccEmoticon_get_Text_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccEmoticon_get_Property_Proxy( 
    IAccEmoticon __RPC_FAR * This,
    /* [in] */ AccEmoticonProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccEmoticon_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccEmoticon_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccEmoticon_0263 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccEmoticon)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_Data(IAccEmoticon* pi, xp_array** px) { return get_Property(pi, AccEmoticonProp_Data, px); };
static inline HRESULT get_Text(IAccEmoticon* pi, xp_str* px) { return get_Property(pi, AccEmoticonProp_Text, px); };
static inline HRESULT get_Description(IAccEmoticon* pi, xp_str* px) { return get_Property(pi, AccEmoticonProp_Description, px); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_DataStream(IAccEmoticon* pi, IAccStream** px) { return get_Property(pi, AccEmoticonProp_DataStream, IID_IAccStream, px); };
#endif
static inline HRESULT get_BartUrl(IAccEmoticon* pi, xp_str* px) { return get_Property(pi, AccEmoticonProp_BartUrl, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccEmoticon_0263_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccEmoticon_0263_v0_0_s_ifspec;

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
