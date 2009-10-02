/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Apr 10 11:44:23 2006
 */
/* Compiler settings for C:\gmdev\cvsdb\client\aimcc\idl\IAccCertificate.idl:
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

#ifndef __IAccCertificate_h__
#define __IAccCertificate_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IAccCertificate_FWD_DEFINED__
#define __IAccCertificate_FWD_DEFINED__
typedef interface IAccCertificate IAccCertificate;
#endif 	/* __IAccCertificate_FWD_DEFINED__ */


/* header files for imported files */
#include "AccTypes.h"


#ifndef __IAccCertificate_INTERFACE_DEFINED__
#define __IAccCertificate_INTERFACE_DEFINED__

/* interface IAccCertificate */
/* [object][dual][uuid] */ 

typedef 
enum AccCertificateTrustFlags
    {	AccCertificateTrustFlags_Ssl	= 0x1,
	AccCertificateTrustFlags_Email	= 0x2,
	AccCertificateTrustFlags_ObjectSigning	= 0x4
    }	AccCertificateTrustFlags;

typedef 
enum AccCertificateUsage
    {	AccCertificateUsage_SslClient	= 0x1,
	AccCertificateUsage_SslServer	= 0x2,
	AccCertificateUsage_Signing	= 0x10,
	AccCertificateUsage_Encryption	= 0x20
    }	AccCertificateUsage;

typedef 
enum AccCertificateProp
    {	AccCertificateProp_Name	= 0,
	AccCertificateProp_SerialNumber	= AccCertificateProp_Name + 1,
	AccCertificateProp_IssueTime	= AccCertificateProp_SerialNumber + 1,
	AccCertificateProp_ExpireTime	= AccCertificateProp_IssueTime + 1,
	AccCertificateProp_Usage	= AccCertificateProp_ExpireTime + 1,
	AccCertificateProp_SubjectCommonName	= 10,
	AccCertificateProp_SubjectOrg	= AccCertificateProp_SubjectCommonName + 1,
	AccCertificateProp_SubjectOrgUnit	= AccCertificateProp_SubjectOrg + 1,
	AccCertificateProp_SubjectDomainComponent	= AccCertificateProp_SubjectOrgUnit + 1,
	AccCertificateProp_SubjectEmailAddress	= AccCertificateProp_SubjectDomainComponent + 1,
	AccCertificateProp_IssuerCommonName	= 20,
	AccCertificateProp_IssuerOrg	= AccCertificateProp_IssuerCommonName + 1,
	AccCertificateProp_IssuerOrgUnit	= AccCertificateProp_IssuerOrg + 1,
	AccCertificateProp_IssuerDomainComponent	= AccCertificateProp_IssuerOrgUnit + 1,
	AccCertificateProp_Trusted	= 30
    }	AccCertificateProp;


EXTERN_C const IID IID_IAccCertificate;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("27e58e07-f9c7-4d46-8cf1-ab28e36c8472")
    IAccCertificate : public IDispatch
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ AccCertificateProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetChain( 
            /* [in] */ xp_vbool wantRoot,
            /* [retval][out] */ xp_variant __RPC_FAR *certs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Verify( 
            /* [in] */ xp_int usage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Trust( 
            /* [in] */ xp_int trustFlags,
            /* [defaultvalue][in] */ xp_vbool permanent = 0) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IAccCertificateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IAccCertificate __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IAccCertificate __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IAccCertificate __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IAccCertificate __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IAccCertificate __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IAccCertificate __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IAccCertificate __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Property )( 
            IAccCertificate __RPC_FAR * This,
            /* [in] */ AccCertificateProp property,
            /* [retval][out] */ xp_variant __RPC_FAR *value);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetChain )( 
            IAccCertificate __RPC_FAR * This,
            /* [in] */ xp_vbool wantRoot,
            /* [retval][out] */ xp_variant __RPC_FAR *certs);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Verify )( 
            IAccCertificate __RPC_FAR * This,
            /* [in] */ xp_int usage);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Trust )( 
            IAccCertificate __RPC_FAR * This,
            /* [in] */ xp_int trustFlags,
            /* [defaultvalue][in] */ xp_vbool permanent);
        
        END_INTERFACE
    } IAccCertificateVtbl;

    interface IAccCertificate
    {
        CONST_VTBL struct IAccCertificateVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAccCertificate_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IAccCertificate_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IAccCertificate_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IAccCertificate_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IAccCertificate_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IAccCertificate_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IAccCertificate_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IAccCertificate_get_Property(This,property,value)	\
    (This)->lpVtbl -> get_Property(This,property,value)

#define IAccCertificate_GetChain(This,wantRoot,certs)	\
    (This)->lpVtbl -> GetChain(This,wantRoot,certs)

#define IAccCertificate_Verify(This,usage)	\
    (This)->lpVtbl -> Verify(This,usage)

#define IAccCertificate_Trust(This,trustFlags,permanent)	\
    (This)->lpVtbl -> Trust(This,trustFlags,permanent)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IAccCertificate_get_Property_Proxy( 
    IAccCertificate __RPC_FAR * This,
    /* [in] */ AccCertificateProp property,
    /* [retval][out] */ xp_variant __RPC_FAR *value);


void __RPC_STUB IAccCertificate_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccCertificate_GetChain_Proxy( 
    IAccCertificate __RPC_FAR * This,
    /* [in] */ xp_vbool wantRoot,
    /* [retval][out] */ xp_variant __RPC_FAR *certs);


void __RPC_STUB IAccCertificate_GetChain_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccCertificate_Verify_Proxy( 
    IAccCertificate __RPC_FAR * This,
    /* [in] */ xp_int usage);


void __RPC_STUB IAccCertificate_Verify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IAccCertificate_Trust_Proxy( 
    IAccCertificate __RPC_FAR * This,
    /* [in] */ xp_int trustFlags,
    /* [defaultvalue][in] */ xp_vbool permanent);


void __RPC_STUB IAccCertificate_Trust_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IAccCertificate_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_IAccCertificate_0117 */
/* [local] */ 

XP_IMPLEMENT_UUIDOF_IDL(IAccCertificate)
/* property accessors inserted by genpropaccessors.py */
#ifdef __cplusplus
#include "AccProps.h"
extern "C++" {
XP_BEGIN_NAMESPACE(AIMCC)
static inline HRESULT get_Name(IAccCertificate* pi, xp_str* px) { return get_Property(pi, AccCertificateProp_Name, px); };
static inline HRESULT get_SerialNumber(IAccCertificate* pi, xp_str* px) { return get_Property(pi, AccCertificateProp_SerialNumber, px); };
static inline HRESULT get_IssueTime(IAccCertificate* pi, xp_date* px) { return get_PropertyDate(pi, AccCertificateProp_IssueTime, px); };
static inline HRESULT get_ExpireTime(IAccCertificate* pi, xp_date* px) { return get_PropertyDate(pi, AccCertificateProp_ExpireTime, px); };
static inline HRESULT get_Usage(IAccCertificate* pi, xp_uint* px) { return get_Property(pi, AccCertificateProp_Usage, px); };
static inline HRESULT get_SubjectCommonName(IAccCertificate* pi, xp_str* px) { return get_Property(pi, AccCertificateProp_SubjectCommonName, px); };
static inline HRESULT get_SubjectOrg(IAccCertificate* pi, xp_str* px) { return get_Property(pi, AccCertificateProp_SubjectOrg, px); };
static inline HRESULT get_SubjectOrgUnit(IAccCertificate* pi, xp_str* px) { return get_Property(pi, AccCertificateProp_SubjectOrgUnit, px); };
static inline HRESULT get_SubjectDomainComponent(IAccCertificate* pi, xp_str* px) { return get_Property(pi, AccCertificateProp_SubjectDomainComponent, px); };
static inline HRESULT get_SubjectEmailAddress(IAccCertificate* pi, xp_str* px) { return get_Property(pi, AccCertificateProp_SubjectEmailAddress, px); };
static inline HRESULT get_IssuerCommonName(IAccCertificate* pi, xp_str* px) { return get_Property(pi, AccCertificateProp_IssuerCommonName, px); };
static inline HRESULT get_IssuerOrg(IAccCertificate* pi, xp_str* px) { return get_Property(pi, AccCertificateProp_IssuerOrg, px); };
static inline HRESULT get_IssuerOrgUnit(IAccCertificate* pi, xp_str* px) { return get_Property(pi, AccCertificateProp_IssuerOrgUnit, px); };
static inline HRESULT get_IssuerDomainComponent(IAccCertificate* pi, xp_str* px) { return get_Property(pi, AccCertificateProp_IssuerDomainComponent, px); };
static inline HRESULT get_Trusted(IAccCertificate* pi, xp_uint* px) { return get_Property(pi, AccCertificateProp_Trusted, px); };
XP_END_NAMESPACE()
} /* extern "C++" */
#endif


extern RPC_IF_HANDLE __MIDL_itf_IAccCertificate_0117_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_IAccCertificate_0117_v0_0_s_ifspec;

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
