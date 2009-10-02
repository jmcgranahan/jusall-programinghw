/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:29 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccEmoticonSet.idl:
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

#ifndef __IAccEmoticonSet_h__
#define __IAccEmoticonSet_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccEmoticonSet_FWD_DEFINED__
#define __IAccEmoticonSet_FWD_DEFINED__
typedef interface IAccEmoticonSet IAccEmoticonSet;
#endif 	/* __IAccEmoticonSet_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"
#include "IAccEmoticon.h"


#ifndef __IAccEmoticonSet_INTERFACE_DEFINED__
#define __IAccEmoticonSet_INTERFACE_DEFINED__

/* interface IAccEmoticonSet */
/* [object][dual][uuid] */ 

typedef 
enum AccEmoticonSetProp
    {	AccEmoticonSetProp_BartId	= 0,
	AccEmoticonSetProp_Description	= AccEmoticonSetProp_BartId + 1,
	AccEmoticonSetProp_PaletteIconData	= AccEmoticonSetProp_Description + 1,
	AccEmoticonSetProp_PaletteIconDataStream	= AccEmoticonSetProp_PaletteIconData + 1
    }	AccEmoticonSetProp;


EXTERN_C const IID IID_IAccEmoticonSet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1617C55E-9D33-11D8-8884-0003936CB786")
    IAccEmoticonSet : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccEmoticonSetProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ xp_int __RPC_FAR *count) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEmoticonByIndex( 
            /* [in] */ xp_int num,
            /* [retval][out] */ IAccEmoticon __RPC_FAR *__RPC_FAR *emoticon) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEmoticonByText( 
            /* [in] */ xp_kstr text,
            /* [retval][out] */ IAccEmoticon __RPC_FAR *__RPC_FAR *emoticon) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccEmoticonSetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccEmoticonSet __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccEmoticonSet __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccEmoticonSet __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccEmoticonSet __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccEmoticonSet __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccEmoticonSet __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccEmoticonSet __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccEmoticonSet __RPC_FAR * This,
            /* [in] */ AccEmoticonSetProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            IAccEmoticonSet __RPC_FAR * This,
            /* [retval][out] */ xp_int __RPC_FAR *count);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEmoticonByIndex )( 
            IAccEmoticonSet __RPC_FAR * This,
            /* [in] */ xp_int num,
            /* [retval][out] */ IAccEmoticon __RPC_FAR *__RPC_FAR *emoticon);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEmoticonByText )( 
            IAccEmoticonSet __RPC_FAR * This,
            /* [in] */ xp_kstr text,
            /* [retval][out] */ IAccEmoticon __RPC_FAR *__RPC_FAR *emoticon);
        
        END_INTERFACE
    } IAccEmoticonSetVtbl;

    interface IAccEmoticonSet
    {
        CONST_VTBL struct IAccEmoticonSetVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccEmoticonSet_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccEmoticonSet_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccEmoticonSet_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccEmoticonSet_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccEmoticonSet_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccEmoticonSet_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccEmoticonSet_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccEmoticonSet_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccEmoticonSet_get_Count(This,count)	\
    (This)->lpVtbl -> get_Count(This,count)

#define IAccEmoticonSet_GetEmoticonByIndex(This,num,emoticon)	\
    (This)->lpVtbl -> GetEmoticonByIndex(This,num,emoticon)

#define IAccEmoticonSet_GetEmoticonByText(This,text,emoticon)	\
    (This)->lpVtbl -> GetEmoticonByText(This,text,emoticon)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccEmoticonSet_get_Property_Proxy( 
    IAccEmoticonSet __RPC_FAR * This,
    /* [in] */ AccEmoticonSetProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccEmoticonSet_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IAccEmoticonSet_get_Count_Proxy( 
    IAccEmoticonSet __RPC_FAR * This,
    /* [retval][out] */ xp_int __RPC_FAR *count);


void __RPC_STUB IAccEmoticonSet_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccEmoticonSet_GetEmoticonByIndex_Proxy( 
    IAccEmoticonSet __RPC_FAR * This,
    /* [in] */ xp_int num,
    /* [retval][out] */ IAccEmoticon __RPC_FAR *__RPC_FAR *emoticon);


void __RPC_STUB IAccEmoticonSet_GetEmoticonByIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccEmoticonSet_GetEmoticonByText_Proxy( 
    IAccEmoticonSet __RPC_FAR * This,
    /* [in] */ xp_kstr text,
    /* [retval][out] */ IAccEmoticon __RPC_FAR *__RPC_FAR *emoticon);


void __RPC_STUB IAccEmoticonSet_GetEmoticonByText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccEmoticonSet_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccEmoticonSet_0267 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccEmoticonSet)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_BartId(IAccEmoticonSet* pi, xp_str* px) { return get_Property(pi, AccEmoticonSetProp_BartId, px); };
static inline HRESULT get_Description(IAccEmoticonSet* pi, xp_str* px) { return get_Property(pi, AccEmoticonSetProp_Description, px); };
static inline HRESULT get_PaletteIconData(IAccEmoticonSet* pi, xp_array** px) { return get_Property(pi, AccEmoticonSetProp_PaletteIconData, px); };
#ifndef ACC_NO_UUIDOF
static inline HRESULT get_PaletteIconDataStream(IAccEmoticonSet* pi, IAccStream** px) { return get_Property(pi, AccEmoticonSetProp_PaletteIconDataStream, IID_IAccStream, px); };
#endif
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccEmoticonSet_0267_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccEmoticonSet_0267_v0_0_s_ifspec;

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
