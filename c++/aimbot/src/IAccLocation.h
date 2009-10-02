/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Mar 07 09:43:07 2007
 */
/* Compiler settings for C:\cvswork\aimcc\idl\IAccLocation.idl:
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

#ifndef __IAccLocation_h__
#define __IAccLocation_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccLocation_FWD_DEFINED__
#define __IAccLocation_FWD_DEFINED__
typedef interface IAccLocation IAccLocation;
#endif 	/* __IAccLocation_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"


#ifndef __IAccLocation_INTERFACE_DEFINED__
#define __IAccLocation_INTERFACE_DEFINED__

/* interface IAccLocation */
/* [object][dual][uuid] */ 

typedef 
enum AccLocationProp
    {	AccLocationProp_Name	= 0,
	AccLocationProp_Latitude	= AccLocationProp_Name + 1,
	AccLocationProp_Longitude	= AccLocationProp_Latitude + 1,
	AccLocationProp_Altitude	= AccLocationProp_Longitude + 1,
	AccLocationProp_HouseNum	= AccLocationProp_Altitude + 1,
	AccLocationProp_HouseNumSuffix	= AccLocationProp_HouseNum + 1,
	AccLocationProp_Street	= AccLocationProp_HouseNumSuffix + 1,
	AccLocationProp_ExtraInfo	= AccLocationProp_Street + 1,
	AccLocationProp_Neighborhood	= AccLocationProp_ExtraInfo + 1,
	AccLocationProp_District	= AccLocationProp_Neighborhood + 1,
	AccLocationProp_City	= AccLocationProp_District + 1,
	AccLocationProp_County	= AccLocationProp_City + 1,
	AccLocationProp_State	= AccLocationProp_County + 1,
	AccLocationProp_Country	= AccLocationProp_State + 1,
	AccLocationProp_PostalCode	= AccLocationProp_Country + 1,
	AccLocationProp_Method	= AccLocationProp_PostalCode + 1,
	AccLocationProp_MacAddress	= AccLocationProp_Method + 1,
	AccLocationProp_GatewayMacAddress	= AccLocationProp_MacAddress + 1,
	AccLocationProp_IpAddress	= AccLocationProp_GatewayMacAddress + 1,
	AccLocationProp_GatewayIpAddress	= AccLocationProp_IpAddress + 1,
	AccLocationProp_Nickname	= AccLocationProp_GatewayIpAddress + 1,
	AccLocationProp_UseCount	= AccLocationProp_Nickname + 1
    }	AccLocationProp;


EXTERN_C const IID IID_IAccLocation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("477acc33-e523-4f16-8ee3-62b425f75738")
    IAccLocation : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccLocationProp prop,
            /* [retval][out] */ xp_variant __RPC_FAR *pv) = 0;
        
        virtual /* [propput] */ HRESULT STDMETHODCALLTYPE put_Property( 
            /* [in] */ AccLocationProp prop,
            /* [in] */ xp_kvariant v) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccLocationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccLocation __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccLocation __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccLocation __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccLocation __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccLocation __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccLocation __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccLocation __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccLocation __RPC_FAR * This,
            /* [in] */ AccLocationProp prop,
            /* [retval][out] */ xp_variant __RPC_FAR *pv);
        
        /* [propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Property )( 
            IAccLocation __RPC_FAR * This,
            /* [in] */ AccLocationProp prop,
            /* [in] */ xp_kvariant v);
        
        END_INTERFACE
    } IAccLocationVtbl;

    interface IAccLocation
    {
        CONST_VTBL struct IAccLocationVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccLocation_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccLocation_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccLocation_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccLocation_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccLocation_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccLocation_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccLocation_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccLocation_get_Property(This,prop,pv)	\
    (This)->lpVtbl -> get_Property(This,prop,pv)

#define IAccLocation_put_Property(This,prop,v)	\
    (This)->lpVtbl -> put_Property(This,prop,v)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccLocation_get_Property_Proxy( 
    IAccLocation __RPC_FAR * This,
    /* [in] */ AccLocationProp prop,
    /* [retval][out] */ xp_variant __RPC_FAR *pv);


void __RPC_STUB IAccLocation_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput] */ HRESULT STDMETHODCALLTYPE IAccLocation_put_Property_Proxy( 
    IAccLocation __RPC_FAR * This,
    /* [in] */ AccLocationProp prop,
    /* [in] */ xp_kvariant v);


void __RPC_STUB IAccLocation_put_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccLocation_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccLocation_0117 */
/* [local] */ 

/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_Name(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_Name, px); };
static inline HRESULT put_Name(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_Name, x); };
static inline HRESULT get_Latitude(IAccLocation* pi, xp_double* px) { return get_PropertyDouble(pi, AccLocationProp_Latitude, px); };
static inline HRESULT put_Latitude(IAccLocation* pi, xp_double x) { return put_PropertyDouble(pi, AccLocationProp_Latitude, x); };
static inline HRESULT get_Longitude(IAccLocation* pi, xp_double* px) { return get_PropertyDouble(pi, AccLocationProp_Longitude, px); };
static inline HRESULT put_Longitude(IAccLocation* pi, xp_double x) { return put_PropertyDouble(pi, AccLocationProp_Longitude, x); };
static inline HRESULT get_Altitude(IAccLocation* pi, xp_double* px) { return get_PropertyDouble(pi, AccLocationProp_Altitude, px); };
static inline HRESULT put_Altitude(IAccLocation* pi, xp_double x) { return put_PropertyDouble(pi, AccLocationProp_Altitude, x); };
static inline HRESULT get_HouseNum(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_HouseNum, px); };
static inline HRESULT put_HouseNum(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_HouseNum, x); };
static inline HRESULT get_HouseNumSuffix(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_HouseNumSuffix, px); };
static inline HRESULT put_HouseNumSuffix(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_HouseNumSuffix, x); };
static inline HRESULT get_Street(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_Street, px); };
static inline HRESULT put_Street(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_Street, x); };
static inline HRESULT get_ExtraInfo(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_ExtraInfo, px); };
static inline HRESULT put_ExtraInfo(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_ExtraInfo, x); };
static inline HRESULT get_Neighborhood(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_Neighborhood, px); };
static inline HRESULT put_Neighborhood(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_Neighborhood, x); };
static inline HRESULT get_District(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_District, px); };
static inline HRESULT put_District(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_District, x); };
static inline HRESULT get_City(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_City, px); };
static inline HRESULT put_City(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_City, x); };
static inline HRESULT get_County(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_County, px); };
static inline HRESULT put_County(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_County, x); };
static inline HRESULT get_State(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_State, px); };
static inline HRESULT put_State(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_State, x); };
static inline HRESULT get_Country(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_Country, px); };
static inline HRESULT put_Country(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_Country, x); };
static inline HRESULT get_PostalCode(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_PostalCode, px); };
static inline HRESULT put_PostalCode(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_PostalCode, x); };
static inline HRESULT get_Method(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_Method, px); };
static inline HRESULT put_Method(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_Method, x); };
static inline HRESULT get_MacAddress(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_MacAddress, px); };
static inline HRESULT put_MacAddress(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_MacAddress, x); };
static inline HRESULT get_GatewayMacAddress(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_GatewayMacAddress, px); };
static inline HRESULT put_GatewayMacAddress(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_GatewayMacAddress, x); };
static inline HRESULT get_IpAddress(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_IpAddress, px); };
static inline HRESULT put_IpAddress(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_IpAddress, x); };
static inline HRESULT get_GatewayIpAddress(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_GatewayIpAddress, px); };
static inline HRESULT put_GatewayIpAddress(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_GatewayIpAddress, x); };
static inline HRESULT get_Nickname(IAccLocation* pi, xp_str* px) { return get_Property(pi, AccLocationProp_Nickname, px); };
static inline HRESULT put_Nickname(IAccLocation* pi, xp_kstr x) { return put_Property(pi, AccLocationProp_Nickname, x); };
static inline HRESULT get_UseCount(IAccLocation* pi, xp_u32* px) { return get_Property(pi, AccLocationProp_UseCount, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccLocation_0117_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccLocation_0117_v0_0_s_ifspec;

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
