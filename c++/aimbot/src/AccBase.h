///----------------------------------------------------------------------------
///
/// File Name: AccBase.h
/// Support for non-Windows platforms.
/// Copyright 2006-2007 AOL LLC. All rights reserved.
///
///----------------------------------------------------------------------------

#ifndef ACCBASE_H
#define ACCBASE_H

// For Windows, we just include the main oleauto file.
//
#if (defined WIN32) || (defined (_WIN32_WCE)) || (defined _XPTL)

#include "oaidl.h"
#include "ocidl.h"

#else

// Defines
//
#define interface               struct
#define EXTERN_C                extern "C"
#define STDMETHODCALLTYPE
#define STDAPI                  EXTERN_C HRESULT STDMETHODCALLTYPE
#define STDAPI_(x)              EXTERN_C x STDMETHODCALLTYPE
#define STDMETHOD(m)            virtual HRESULT STDMETHODCALLTYPE m
#define STDMETHOD_(x, m)        virtual x STDMETHODCALLTYPE m

#define SUCCEEDED(x)            ((x) >= 0)
#define FAILED(x)               ((x) < 0)
#define S_OK                    ((HRESULT)0)
#define S_FALSE                 ((HRESULT)1)
#define E_UNEXPECTED            ((HRESULT)0x8000FFFF)
#define E_NOTIMPL               ((HRESULT)0x80000001)
#define E_OUTOFMEMORY           ((HRESULT)0x80000002)
#define E_INVALIDARG            ((HRESULT)0x80000003)
#define E_NOINTERFACE           ((HRESULT)0x80000004)
#define E_POINTER               ((HRESULT)0x80000005)
#define E_ABORT                 ((HRESULT)0x80000007)
#define E_FAIL                  ((HRESULT)0x80000008)
#define E_ACCESSDENIED          ((HRESULT)0x80000009)
#define E_PENDING               ((HRESULT)0x8000000A)
#define DISP_E_TYPEMISMATCH     ((HRESULT)0x80020005)

#define MIDL_INTERFACE(x)       interface
#define DECLSPEC_UUID(x)
#define __RPCNDR_H_VERSION__    450
#define __RPC_CALLEE    
#define __RPC_FAR
#define __RPC_API  
#define __RPC_USER
#define __RPC_STUB
#define RPC_ENTRY 

#ifdef CONST_VTABLE // __cplusplus?
#define CONST_VTBL              const
#else
#define CONST_VTBL
#endif

// Typedefs
//
typedef char CHAR;
typedef unsigned char UCHAR;
typedef short SHORT;
typedef unsigned short USHORT;
typedef int INT;
typedef unsigned int UINT;
typedef long LONG;
typedef unsigned long ULONG;
typedef long long LONGLONG;
typedef unsigned long long ULONGLONG;
typedef float FLOAT;
typedef double DOUBLE;
typedef void* PVOID;

typedef UCHAR BYTE;
typedef USHORT WORD;
typedef USHORT OLECHAR; // not wchar_t because gcc wchar_t is 4 bytes
typedef LONG HRESULT;
typedef ULONG DWORD;
typedef OLECHAR* LPOLESTR;
typedef OLECHAR* BSTR;

typedef long long hyper;
typedef unsigned long long MIDL_uhyper;

typedef long RPC_STATUS;
typedef void* I_RPC_HANDLE;
typedef void* RPC_IF_HANDLE;
typedef void* PRPC_MESSAGE;
typedef void IRpcChannelBuffer;
typedef void IRpcStubBuffer;

// General structs
//
struct LARGE_INTEGER
{
    LONGLONG QuadPart;
};

struct ULARGE_INTEGER
{
    ULONGLONG QuadPart;
};

typedef struct tagGUID
{
    ULONG Data1; // need to ensure 32 bits
    USHORT Data2;
    USHORT Data3;
    UCHAR Data4[8];
} GUID;

typedef GUID IID;
typedef GUID CLSID;
EXTERN_C const GUID GUID_NULL;
#define IID_NULL GUID_NULL


#ifdef __cplusplus
typedef const IID& REFIID;
typedef const CLSID& REFCLSID;
bool inline operator==(const GUID& g1, const GUID& g2)
{
    int* p1 = (int*)&g1; int* p2 = (int*)&g2;
    return (
        p1[0] == p2[0] &&
        p1[1] == p2[1] &&
        p1[2] == p2[2] &&
        p1[3] == p2[3]
    );
}
bool inline operator!=(const GUID& g1, const GUID& g2)
{
    return !operator==(g1, g2);
}
#else
typedef const IID* REFIID;
typedef const CLSID* REFCLSID;
#endif

// IUnknown
//
EXTERN_C const IID IID_IUnknown;
interface IUnknown
{
public:    
    STDMETHOD(QueryInterface)(REFIID, void**) = 0;    
    STDMETHOD_(ULONG, AddRef)(void) = 0;    
    STDMETHOD_(ULONG, Release)(void) = 0;        
};

// IClassFactory
//
EXTERN_C const IID IID_IClassFactory;
interface IClassFactory : public IUnknown
{   
    STDMETHOD(CreateInstance)(IUnknown* pIOuterUnknown, const IID& iid, void** ppI) = 0;     
    STDMETHOD(LockServer)(int lock) = 0;
};

// IDispatch
//
#define VARIANT_TRUE ((VARIANT_BOOL)-1)
#define VARIANT_FALSE ((VARIANT_BOOL)0)

typedef USHORT VARTYPE;
typedef USHORT VARIANT_BOOL;
typedef LONG DISPID;
typedef ULONG SCODE;
typedef ULONG LCID;
typedef DOUBLE DATE;

enum VARENUM
{   VT_EMPTY = 0,
    VT_NULL = 1,
    VT_I2   = 2,
    VT_I4   = 3,
    VT_R4   = 4,
    VT_R8   = 5,
    VT_CY   = 6,
    VT_DATE = 7,
    VT_BSTR = 8,
    VT_DISPATCH = 9,
    VT_ERROR    = 10,
    VT_BOOL = 11,
    VT_VARIANT  = 12,
    VT_UNKNOWN  = 13,
    VT_DECIMAL  = 14,
    VT_I1   = 16,
    VT_UI1  = 17,
    VT_UI2  = 18,
    VT_UI4  = 19,
    VT_I8   = 20,
    VT_UI8  = 21,
    VT_INT  = 22,
    VT_UINT = 23,
    VT_VOID = 24,
    VT_HRESULT  = 25,
    VT_VECTOR   = 0x1000,
    VT_ARRAY    = 0x2000,
    VT_BYREF    = 0x4000,
    VT_RESERVED = 0x8000,
    VT_ILLEGAL  = 0xffff,
    VT_ILLEGALMASKED    = 0xfff,
    VT_TYPEMASK = 0xfff
};

typedef struct tagCY
{
    LONGLONG int64;
} CY;

typedef struct tagSAFEARRAYBOUND
{
    ULONG cElements;
    LONG lLbound;
} SAFEARRAYBOUND, *LPSAFEARRAYBOUND;

typedef struct tagSAFEARRAY
{
    USHORT cDims;
    USHORT fFeatures;
    ULONG cbElements;
    ULONG cLocks;
    PVOID pvData;
    SAFEARRAYBOUND rgsabound[ 1 ];
} SAFEARRAY, *LPSAFEARRAY;

interface IDispatch;
typedef struct tagVARIANT VARIANT;
struct tagVARIANT
{    
    VARTYPE vt;
    WORD wReserved1;
    WORD wReserved2;
    WORD wReserved3;
    union 
    {
        LONGLONG llVal;
        LONG lVal;
        BYTE bVal;
        SHORT iVal;
        FLOAT fltVal;
        DOUBLE dblVal;
        VARIANT_BOOL boolVal;
        SCODE scode;
        CY cyVal;
        DATE date;
        BSTR bstrVal;
        IUnknown* punkVal;
        IDispatch* pdispVal;
        SAFEARRAY* parray;
        BYTE* pbVal;
        SHORT* piVal;
        LONG* plVal;
        LONGLONG* pllVal;
        FLOAT* pfltVal;
        DOUBLE* pdblVal;
        VARIANT_BOOL* pboolVal;
        SCODE* pscode;
        CY* pcyVal;
        DATE* pdate;
        BSTR* pbstrVal;
        IUnknown** ppunkVal;
        IDispatch** ppdispVal;
        SAFEARRAY** pparray;
        VARIANT* pvarVal;
        PVOID byref;
        CHAR cVal;
        USHORT uiVal;
        ULONG ulVal;
        ULONGLONG ullVal;
        INT intVal;
        UINT uintVal;
        CHAR* pcVal;
        USHORT* puiVal;
        ULONG* pulVal;
        ULONGLONG* pullVal;
        INT* pintVal;
        UINT* puintVal;
        /*
        struct __tagBRECORD
        {
            PVOID pvRecord;
            IRecordInfo* pRecInfo;
        } __VARIANT_NAME_4;
        */
    };
};
typedef VARIANT VARIANTARG;

typedef struct tagDISPPARAMS
{
    VARIANTARG* rgvarg;
    DISPID* rgdispidNamedArgs;
    UINT cArgs;
    UINT cNamedArgs;
} DISPPARAMS;

typedef struct tagEXCEPINFO
{
} EXCEPINFO;

interface ITypeInfo;
EXTERN_C const IID IID_IDispatch;
interface IDispatch : public IUnknown
{
public:
    STDMETHOD(GetTypeInfoCount)(UINT*) = 0;  
    STDMETHOD(GetTypeInfo)(UINT, LCID, ITypeInfo**) = 0;
    STDMETHOD(GetIDsOfNames)(REFIID, OLECHAR**, UINT, LCID, DISPID*) = 0;
    STDMETHOD(Invoke)(DISPID, REFIID, LCID, WORD, DISPPARAMS*, VARIANT*, EXCEPINFO*, UINT*) = 0;
};

// IErrorInfo
//
EXTERN_C const IID IID_IErrorInfo;
interface IErrorInfo : public IUnknown
{
public:
    STDMETHOD(GetDescription)(BSTR*) = 0;
    STDMETHOD(GetGUID)(GUID*) = 0;
    STDMETHOD(GetHelpContext)(DWORD*) = 0;
    STDMETHOD(GetHelpFile)(BSTR*) = 0;
    STDMETHOD(GetSource)(BSTR*) = 0;
};

// IConnectionPoint
//
interface IConnectionPointContainer;
interface IEnumConnections;
EXTERN_C const IID IID_IConnectionPoint;
interface IConnectionPoint : public IUnknown
{
public:
    STDMETHOD(GetConnectionInterface)(IID *pIid) = 0;    
    STDMETHOD(GetConnectionPointContainer)(IConnectionPointContainer** ppIConnectionPointContainer) = 0;
    STDMETHOD(Advise)(IUnknown* pISinkUnknown, DWORD* pCookie) = 0;    
    STDMETHOD(Unadvise)(DWORD cookie) = 0;
    STDMETHOD(EnumConnections)(IEnumConnections** ppIEnumConnections) = 0;  
};    

// IConnectionPointContainer
//
interface IEnumConnectionPoints;
EXTERN_C const IID IID_IConnectionPointContainer;
interface IConnectionPointContainer : public IUnknown
{
public:
    STDMETHOD(EnumConnectionPoints)(IEnumConnectionPoints** ppIEnumConnectionPoints) = 0;
    STDMETHOD(FindConnectionPoint)(REFIID iid, IConnectionPoint** ppIConnectionPoint) = 0;
};
   
// IEnumConnectionPoints
//
EXTERN_C const IID IID_IEnumConnectionPoints;
interface IEnumConnectionPoints : public IUnknown
{
public:
    STDMETHOD(Next)(ULONG connections, IConnectionPoint** ppIConnectionPoint, ULONG* pFetched) = 0;
    STDMETHOD(Skip)(ULONG connections) = 0;    
    STDMETHOD(Reset)(void) = 0;  
    STDMETHOD(Clone)(IEnumConnectionPoints** ppIEnumConnectionPoints) = 0;
};

// IEnumConnections
//
typedef struct tagCONNECTDATA
{
    IUnknown* pUnk;
    DWORD dwCookie;
} CONNECTDATA;

EXTERN_C const IID IID_IEnumConnections;   
interface IEnumConnections : public IUnknown
{
public:
    STDMETHOD(Next)(ULONG connections, CONNECTDATA* pConnectData, ULONG *pFetched) = 0;    
    STDMETHOD(Skip)(ULONG connections) = 0;    
    STDMETHOD(Reset)(void) = 0;
    STDMETHOD(Clone)(IEnumConnections** ppIEnumConnections) = 0;    
};

// ISequentialStream
//
EXTERN_C const IID IID_ISequentialStream;
interface ISequentialStream : public IUnknown
{
public:
    STDMETHOD(Read)(void *pv, ULONG cb, ULONG *pcbRead) = 0;       
    STDMETHOD(Write)(const void *pv, ULONG cb, ULONG *pcbWritten) = 0;        
};

// IStream
//
typedef struct tagFILETIME
{
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME;

typedef struct tagSTATSTG
{
    LPOLESTR pwcsName;
    DWORD type;
    ULARGE_INTEGER cbSize;
    FILETIME mtime;
    FILETIME ctime;
    FILETIME atime;
    DWORD grfMode;
    DWORD grfLocksSupported;
    CLSID clsid;
    DWORD grfStateBits;
    DWORD reserved;
} STATSTG;

EXTERN_C const IID IID_IStream;
interface IStream : public ISequentialStream
{
public:
    STDMETHOD(Seek)(LARGE_INTEGER dlibMove, DWORD dwOrigin, ULARGE_INTEGER *plibNewPosition) = 0;   
    STDMETHOD(SetSize)(ULARGE_INTEGER libNewSize) = 0;   
    STDMETHOD(CopyTo)(IStream* pstm, ULARGE_INTEGER cb, ULARGE_INTEGER *pcbRead, ULARGE_INTEGER *pcbWritten) = 0;    
    STDMETHOD(Commit)(DWORD grfCommitFlags) = 0;   
    STDMETHOD(Revert)(void) = 0;   
    STDMETHOD(LockRegion)(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType) = 0;    
    STDMETHOD(UnlockRegion)(ULARGE_INTEGER libOffset, ULARGE_INTEGER cb, DWORD dwLockType) = 0;    
    STDMETHOD(Stat)(STATSTG* pstatstg, DWORD grfStatFlag) = 0;    
    STDMETHOD(Clone)(IStream** ppstm) = 0;    
};

#endif // WIN32
#endif
