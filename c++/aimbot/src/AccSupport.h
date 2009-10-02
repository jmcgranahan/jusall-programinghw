///----------------------------------------------------------------------------
///
/// File Name: AccSupport.h
/// Copyright 2003-2007 AOL LLC. All rights reserved.
///
///----------------------------------------------------------------------------

#ifndef ACCSUPPORT_H
#define ACCSUPPORT_H

#include <stddef.h> // for ptrdiff_t
#include <stdio.h>  // for fopen, etc
#include <string.h> // for strchr
#include <vector>   // for vector
#include <map>      // for map
#ifdef _MSC_VER
#pragma warning(disable : 4127) // for "while(0)"
#endif

// AccCore.h must be included first to use the classes below
//
#ifdef __AccCore_h__

// Helper macros
//
#define ACC_TRY_HR(x) do {HRESULT thr; if (FAILED(thr = (x))) return thr;} while(0)
#define ACC_TRY_EXPR_(x, thr) do {if (!(x)) return thr;} while(0)
#define ACC_TRY_EXPR_FAIL(x) ACC_TRY_EXPR_(x, E_FAIL)
#define ACC_THROW_HR(x) do {HRESULT thr; if (FAILED(thr = (x))) CAccException::Throw(thr);} while(0)
#define ACC_THROW_EXPR_(x, thr) do {if (!(x)) CAccException::Throw(thr);} while(0)
#define ACC_THROW_EXPR_FAIL(x) ACC_THROW_EXPR_(x, E_FAIL)

// Helper classes
//
namespace AIMCC {

// Exception class used by the classes below
//
class CAccException
{
public:
    CAccException(HRESULT hr = E_FAIL) throw() : m_hr(hr)
        {}
    HRESULT Result() const throw()
        { return m_hr; }
    static void Throw(HRESULT hr)
        { throw new CAccException(hr); }
private:
    HRESULT m_hr;
};

// Smart pointer helper class
// Example:
// CAccPtr<IAccUser> sp;
// s->CreateUser(name, &sp);
//
template <class T> //, const IID* piid = NULL> // *TODO* remove piid once accbuddy is updated
class CAccPtr
{
    // Overloading on T* and IUnknown* is problematic, since passing NULL is
    // ambiguous. Overloading on T* and QIHelper addresses this problem.
    struct QIHelper
    {
        QIHelper(IUnknown* p) : m_p(p) {}
        template <class U> QIHelper(const CAccPtr<U>& sp) : m_p(sp.m_p) {}
        IUnknown* m_p;
    };
public:
    CAccPtr() throw() : m_p(NULL)
        { m_p = NULL; }
    CAccPtr(T* p) throw()
        { Adopt(p); }
    CAccPtr(const CAccPtr& sp) throw()
        { Adopt(sp.m_p); }
    CAccPtr(const QIHelper& x) throw()
        { AdoptQI(x.m_p); }
    ~CAccPtr() throw()
        { SafeRelease(m_p); }
    void Attach(T* p) throw()
        { SafeRelease(m_p); m_p = p; }
    T* Detach() throw()
        { T* p = m_p; m_p = NULL; return p; }
    void Release() throw()
        { SafeRelease(m_p); m_p = NULL; }
    HRESULT Copy(T** pp)
        { if (!*pp) return E_POINTER; SafeAddRef(*pp = m_p); return S_OK; }
    CAccPtr& operator=(T* p) throw()
        { Exchange(p); return *this; }
    CAccPtr& operator=(const CAccPtr& sp) throw()
        { Exchange(sp.m_p); return *this; }
    CAccPtr& operator=(const QIHelper& x) throw()
        { SafeRelease(m_p); AdoptQI(x.m_p); return *this; }
    operator T*() throw()
        { return m_p; }
    T** operator&() throw()
        { return &m_p; }
    T* operator->() throw()
        { return m_p; }
private:
    void Adopt(T* p)
        { SafeAddRef(m_p = p); }
    void AdoptQI(IUnknown* p)
        { if (p) p->QueryInterface(xp_uuidof(m_p), (void**)&m_p); else m_p = NULL; }
    void Exchange(T* p)
        { SafeRelease(m_p); Adopt(p); }
    static void SafeAddRef(T* p) throw()
        { if (p) p->AddRef(); }
    static void SafeRelease(T* p) throw()
        { if (p) p->Release(); }
public: // *TODO* remove this once accbuddy is updated
    //union {
    T* m_p;
    //T* p;
    //};
};

// String management helper class
// Example:
// CAccBstr name;
// s->get_Identity(&name);
//
class CAccBstr
{
public:
    CAccBstr() throw() : m_str(NULL)
        {}
    CAccBstr(const CAccBstr& s)
        { Construct(s.m_str); }
    CAccBstr(xp_kstr s)
        { Construct(s); }
    CAccBstr(const char* utf8)
        { Construct(utf8); }
    ~CAccBstr() throw()
        { Free(m_str); }
    void Attach(xp_str s) throw()
        { Free(m_str); m_str = s; }
    xp_str Detach() throw()
        { xp_str s = m_str; m_str = NULL; return s; }
    HRESULT Copy(xp_str* ps) throw()
        { if (!ps) return E_POINTER; return Alloc(m_str, *ps); }
    xp_int Length() const throw()
        { return AccStringLen(m_str); }
    OLECHAR operator[](xp_int index) const
    {
        if (index < 0)
            CAccException::Throw(E_INVALIDARG);
        if (!m_str && index != 0)
            CAccException::Throw(E_INVALIDARG);
        return m_str[index];
    }
    xp_int Compare(xp_kstr s) const throw()
        { return AccStringCompare(m_str, s); }
    xp_int GetUtf8(char* buf, xp_int len) const throw()
        { return AccStringGetUtf8(m_str, buf, len); }
    /*
    HRESULT GetUtf8(char** pp)
    {
        if (!pp) return E_POINTER;
        xp_int len = AccStringGetUtf8(m_str, NULL, 0);
        HRESULT hr = AccMemAlloc(len, pp);
        if (SUCCEEDED(hr))
            AccStringGetUtf8(m_str, *pp, len);
        return hr;
    ]
    */
    CAccBstr& operator=(const CAccBstr& s)
        { if (s.m_str != m_str) { Free(m_str); Construct(s.m_str); } return *this; }
    CAccBstr& operator=(xp_kstr s)
        { if (s != m_str) { Free(m_str); Construct(s); } return *this; }
    CAccBstr& operator=(const char* utf8)
        { Free(m_str); Construct(utf8); return *this; }
    bool operator==(const CAccBstr& s) const throw()
        { return (Compare(s) == 0); }
    bool operator==(xp_kstr s) const throw()
        { return (Compare(s) == 0); }
    bool operator!=(const CAccBstr& s) const throw()
        { return (Compare(s) != 0); }
    bool operator!=(xp_kstr s) const throw()
        { return (Compare(s) != 0); }
    bool operator<(xp_kstr s) const throw()
        { return (Compare(s) < 0); }
    bool operator<(const CAccBstr& s) const throw()
        { return (Compare(s) < 0); }
    operator xp_str() const throw() { return m_str; }
    xp_str* operator&() throw() { return &m_str; }
private:
    void Construct(xp_kstr s)
    {
        HRESULT hr = AccStringAlloc(s, &m_str);
        if (FAILED(hr))
            CAccException::Throw(hr);
    }
    void Construct(const char* utf8)
    {
        HRESULT hr = AccStringAllocUtf8(utf8, &m_str);
        if (FAILED(hr))
            CAccException::Throw(hr);
    }
    static HRESULT Alloc(xp_kstr s, xp_str& d) throw()
    {
        return AccStringAlloc(s, &d);
    }
    static void Free(xp_str s) throw()
    {
        AccStringFree(s);
    }
private:
    xp_str m_str;
};

#ifndef OLESTR
#define OLESTR(utf8ptr) CAccBstr(utf8ptr)
#endif

// Variant management helper class
// Example:
// CAccVariant v;
// s->get_Property(AccSessionProp_IpAddress, &v);
//
class CAccVariant : public xp_variant
{
public:
    CAccVariant() throw()
        { vt = VT_EMPTY; }
    CAccVariant(const xp_variant& v) // CAccVariant too
        { vt = VT_EMPTY; Construct(v); }
    CAccVariant(xp_int n) throw()
        { vt = VT_I4; lVal = n; }
    CAccVariant(xp_uint n) throw()
        { vt = VT_UI4; ulVal = n; }
    CAccVariant(xp_double n, VARTYPE vtype = VT_R8 ) throw()
        { vt = vtype; dblVal = n; }
    CAccVariant(xp_kstr s) // can throw
        { Construct(s); }
    CAccVariant(const char* utf8) // can throw
        { Construct(utf8); }
    CAccVariant(IUnknown* p) throw()
        { vt = VT_UNKNOWN; if ((punkVal = p) != NULL) p->AddRef(); }
    CAccVariant(IDispatch* p) throw()
        { vt = VT_DISPATCH; if ((pdispVal = p) != NULL) p->AddRef(); }
    ~CAccVariant() throw()
        { Clear(); }
    HRESULT Attach(xp_variant& v) throw()
        { HRESULT hr = Clear(); if (SUCCEEDED(hr)) { (xp_variant&)*this = v; v.vt = VT_EMPTY; } return hr; }
    HRESULT Detach(xp_variant& v) throw()
        { HRESULT hr = AccVarClear(&v); if (SUCCEEDED(hr)) { v = (xp_variant&)*this; vt = VT_EMPTY; } return hr; }
    HRESULT Copy(const xp_variant& v) throw()
        { return AccVarCopy(const_cast<xp_variant*>(&v), this); }
    HRESULT Clear() throw()
        { return AccVarClear(this); }
    HRESULT ChangeType(xp_vtype vtype) throw()
        { return AccVarChangeType(this, this, vtype); }
    CAccVariant& operator=(const xp_variant& v) // CAccVariant too
        { if (&v != this) Construct(v); return *this; }
    CAccVariant& operator=(xp_int n) throw()
        { Clear(); vt = VT_I4; lVal = n; return *this;}
    CAccVariant& operator=(xp_uint n) throw()
        { Clear(); vt = VT_UI4; ulVal = n; return *this; }
    CAccVariant& operator=(xp_double n) throw()
        { Clear(); vt = VT_R8; dblVal = n; return *this;}
    CAccVariant& operator=(xp_kstr s) // can throw
        { Clear(); Construct(s); return *this;}
    CAccVariant& operator=(const char* utf8) // can throw
        { Clear(); Construct(utf8); return *this;}
    CAccVariant& operator=(IUnknown* p) throw()
        { Clear(); vt = VT_UNKNOWN; if ((punkVal = p) != NULL) p->AddRef(); return *this; }
    CAccVariant& operator=(IDispatch* p) throw()
        { Clear(); vt = VT_DISPATCH; if ((pdispVal = p) != NULL) p->AddRef(); return *this; }
private:
    void Construct(const xp_variant& v)
    {
        HRESULT hr = AccVarCopy(this, const_cast<xp_variant*>(&v));
        if (FAILED(hr))
            CAccException::Throw(hr);
    }
    void Construct(xp_kstr s)
    {
        vt = VT_BSTR;
        HRESULT hr = AccStringAlloc(s, &bstrVal);
        if (FAILED(hr))
            CAccException::Throw(hr);
    }
    void Construct(const char* utf8)
    {
        vt = VT_BSTR;
        HRESULT hr = AccStringAllocUtf8(utf8, &bstrVal);
        if (FAILED(hr))
            CAccException::Throw(hr);
    }
};

// Array management base class
//
class CAccBaseArray
{
public:
    CAccBaseArray() throw() : m_psa(NULL)
        {}
    ~CAccBaseArray() throw()
        { AccArrayDestroy(m_psa); }
    HRESULT Attach(xp_array* psa) throw()
        { HRESULT hr = AccArrayDestroy(m_psa); if (SUCCEEDED(hr)) m_psa = psa; return hr; }
    xp_array* Detach() throw()
        { xp_array* psa = m_psa; m_psa = NULL; return psa; }
    HRESULT Copy(xp_array** ppsa) throw()
        { HRESULT hr = S_OK; if (m_psa) hr = AccArrayCopy(m_psa, ppsa); else *ppsa = NULL; return hr; }
    xp_int Count() const throw()
    {
        xp_int count = 0;
        if (m_psa)
            AccArrayGetCount(m_psa, &count);
        return count;
    }
    //xp_int GetCount() const throw() { return Count(); } // *TODO* remove once accbuddy is updated
    operator xp_array*() throw() { return m_psa; }
    xp_array** operator&() throw() { return &m_psa; }
protected:
    HRESULT Create(xp_vtype vt, xp_int size) throw()
        { return AccArrayCreate(vt, size, &m_psa); }
    HRESULT Resize(xp_int newSize) throw()
        { return AccArrayRedim(m_psa, newSize); }
    HRESULT GetAt(xp_int index, void* elem) throw()
        { return AccArrayGetElement(m_psa, index, elem); }
    HRESULT SetAt(xp_int index, const void* elem) throw()
        { return AccArrayPutElement(m_psa, index, const_cast<void*>(elem)); }
    HRESULT Add(const void* elem) throw()
        { xp_int count = Count(); HRESULT hr = Resize(count + 1); if (SUCCEEDED(hr)) hr = SetAt(count, elem); return hr; }
private:
public: //++++
    xp_array* m_psa;
};

// Byte array helper class
//
class CAccByteArray : public CAccBaseArray
{
public:
    CAccByteArray() throw()
        {}
    HRESULT Create(xp_int size = 0) throw()
        { return CAccBaseArray::Create(VT_UI1, size); }
    HRESULT GetAt(xp_int index, xp_u08& elem) throw()
        { return CAccBaseArray::GetAt(index, &elem); }
    HRESULT SetAt(xp_int index, xp_u08 elem) throw()
        { return CAccBaseArray::SetAt(index, &elem); }
    HRESULT Add(xp_u08 elem) throw()
        { return CAccBaseArray::Add(&elem); }
};

// Variant array helper class
//
class CAccVariantArray : public CAccBaseArray
{
public:
    CAccVariantArray() throw()
        {}
    HRESULT Create(xp_int size = 0) throw()
        { return CAccBaseArray::Create(VT_VARIANT, size); }
    HRESULT GetAt(xp_int index, xp_variant& elem) throw()
        { return CAccBaseArray::GetAt(index, &elem); }
    HRESULT SetAt(xp_int index, const xp_variant& elem) throw()
        { return CAccBaseArray::SetAt(index, &elem); }
    HRESULT Add(const xp_variant& elem) throw()
        { return CAccBaseArray::Add(&elem); }
};


// Transaction id helper class.
// Clients use this class to associate transaction ids returned from API calls
// with transaction ids supplied in callbacks.
// Example:
// AccTransId transId;
// if (SUCCEEDED(x->RequestProperty(prop, &transId)))
//     myMap.Add(transId);
// ...
// void OnUserRequestPropertyResult(IAccSession*, IAccUser*, AccUserProp, AccTransId transId, ...
// {
//     if (FAILED(myMap.Remove(transId)) // ignore requests that aren't ours
//         return;
//
class CAccTransIdMap
{
public:
    CAccTransIdMap() throw() {}

    // CAccTransId Auto() { return CAccTransId(*this); }
    // CAccTransId Auto(const CAccVariant& v) { return CAccTransId(*this, v); }

    HRESULT Add(AccTransId id) throw()
    {
        return Add(id, CAccVariant());
    }
    HRESULT Add(AccTransId id, const CAccVariant& v) throw()
    {
        m_map.insert(std::make_pair(id, v));
        return S_OK;
    }
    HRESULT Lookup(AccTransId id) throw()
    {
        iterator it = m_map.find(id);
        if (it == m_map.end())
            return E_FAIL;
        return S_OK;
    }
    HRESULT Lookup(AccTransId id, CAccVariant& v) throw()
    {
        iterator it = m_map.find(id);
        if (it == m_map.end())
            return E_FAIL;
        v = it->second;
        return S_OK;
    }
    HRESULT Remove(AccTransId id) throw()
    {
        iterator it = m_map.find(id);
        if (it == m_map.end())
            return E_FAIL;
        m_map.erase(id);
        return S_OK;
    }
    HRESULT Remove(AccTransId id, CAccVariant& v) throw()
    {
        iterator it = m_map.find(id);
        if (it == m_map.end())
            return E_FAIL;
        v = it->second;
        m_map.erase(it);
        return S_OK;
    }
    void RemoveAll() throw()
    {
        m_map.clear();
    }
private:
    std::map<AccTransId, CAccVariant> m_map;
    typedef std::map<AccTransId, CAccVariant>::iterator iterator;
};

/*
// Transaction id helper class. Simplifies use of CAccTransIdMap.
// Example:
// CAccTransId transId(myMap);
// x->RequestProperty(prop, &transId); // x is auto-added to myMap
//
class CAccTransId
{
public:
    CAccTransId(CAccTransIdMap& m) : m_map(m)
    {
        m_pNode = new CAccTransIdMap::CNode(0, CAccVariant());
        if (!m_pNode)
            throw CAccException(E_OUTOFMEMORY);
    }
    CAccTransId(CAccTransIdMap& m, const CAccVariant& v) : m_map(m)
    {
        m_pNode = new CAccTransIdMap::CNode(0, v);
        if (!m_pNode)
            throw CAccException(E_OUTOFMEMORY);
    }
    ~CAccTransId() throw()
    {
        if (m_pNode->m_key != 0)
            m_map.AddNode(m_pNode);
        else
            delete m_pNode;
    }
    operator AccTransId() throw() { return m_pNode->m_key; }
    AccTransId* operator&() throw() { return &m_pNode->m_key; }
private:
    CAccTransId(const CAccTransId&);
    CAccTransId& operator=(const CAccTransId&);
private:
    CAccTransIdMap& m_map;
};
*/

// Class to implement simple COM objects
//
template <class T>
class CAccObject : public T
{
public:
    CAccObject() throw() : m_refs(0)
        {}
    virtual ~CAccObject() throw()
        {};
    STDMETHOD_(ULONG, AddRef)() throw()
        { return ++m_refs; }
    STDMETHOD_(ULONG, Release)() throw()
        { if (--m_refs == 0) { FinalRelease(); delete this; return 0; } return m_refs; }
    STDMETHOD(QueryInterface)(REFIID iid, void** pp) throw()
    {
        if (iid != IID_IUnknown && iid != xp_uuidof_helper<T*>::uuid())
        {
            *pp = NULL;
            return E_NOINTERFACE;
        }

        AddRef();
        *pp = this;
        return S_OK;
    }
protected:
    virtual void FinalRelease() throw()
        {}
private:
    xp_int m_refs;
};

// Class to implement IDispatch event sink
//
#define ACC_BEGIN_EVENT_MAP() \
    HRESULT STDMETHODCALLTYPE Invoke(DISPID id, REFIID, LCID, WORD, \
        DISPPARAMS* pdp, VARIANT*, EXCEPINFO*, UINT*) \
    { \
        VARIANT* args = pdp->rgvarg; UINT num = pdp->cArgs; \
        switch (id) \
        {
#define ACC_EVENT_ENTRY0(id, f) \
        case id: if (num >= 0) f(); break;
#define ACC_EVENT_ENTRY1(id, f, t1) \
        case id: if (num >= 1) f(  \
            var_cast<t1>(args[0])); break;
#define ACC_EVENT_ENTRY2(id, f, t1, t2) \
        case id: if (num >= 2) f(  \
            var_cast<t1>(args[1]), \
            var_cast<t2>(args[0])); break;
#define ACC_EVENT_ENTRY3(id, f, t1, t2, t3) \
        case id: if (num >= 3) f(  \
            var_cast<t1>(args[2]), \
            var_cast<t2>(args[1]), \
            var_cast<t3>(args[0])); break;
#define ACC_EVENT_ENTRY4(id, f, t1, t2, t3, t4) \
        case id: if (num >= 4) f(  \
            var_cast<t1>(args[3]), \
            var_cast<t2>(args[2]), \
            var_cast<t3>(args[1]), \
            var_cast<t4>(args[0])); break;
#define ACC_EVENT_ENTRY5(id, f, t1, t2, t3, t4, t5) \
        case id: if (num >= 5) f(  \
            var_cast<t1>(args[4]), \
            var_cast<t2>(args[3]), \
            var_cast<t3>(args[2]), \
            var_cast<t4>(args[1]), \
            var_cast<t5>(args[0])); break;
#define ACC_EVENT_ENTRY6(id, f, t1, t2, t3, t4, t5, t6) \
        case id: if (num >= 6) f(  \
            var_cast<t1>(args[5]), \
            var_cast<t2>(args[4]), \
            var_cast<t3>(args[3]), \
            var_cast<t4>(args[2]), \
            var_cast<t5>(args[1]), \
            var_cast<t6>(args[0])); break;
#define ACC_EVENT_ENTRY7(id, f, t1, t2, t3, t4, t5, t6, t7) \
        case id: if (num >= 7) f(  \
            var_cast<t1>(args[6]), \
            var_cast<t2>(args[5]), \
            var_cast<t3>(args[4]), \
            var_cast<t4>(args[3]), \
            var_cast<t5>(args[2]), \
            var_cast<t6>(args[1]), \
            var_cast<t7>(args[0])); break;
#define ACC_END_EVENT_MAP() \
        } \
    return S_OK; \
    }

// CAccEventSink_ is a base class of CAccEventSink, because
// the C++ standard indicates that template specializations can
// only be declared in namespace scope, while gcc (not sure about
// the standard) requires them to be declared before they are used.
class CAccEventSink_
{
public:
    template<class T> static T var_cast(VARIANT& v)
        { return (T)(ptrdiff_t)v.pdispVal; }
};
template<> inline xp_variant CAccEventSink_::var_cast(VARIANT& v)
    { return v; }
template<> inline xp_kvariant CAccEventSink_::var_cast(VARIANT& v)
    { return v; }

class CAccEventSink : public CAccObject<IDispatch>, public CAccEventSink_
{
public:
    CAccEventSink() throw() {}
    virtual ~CAccEventSink() throw() {};
    HRESULT Advise(IUnknown* piSource) throw()
    {
        DWORD cookie;
        if (SUCCEEDED(Lookup(piSource, &cookie)))
            return E_UNEXPECTED;
        CAccPtr<IConnectionPoint> spiCp;
        ACC_TRY_HR(FindConnectionPoint(piSource, &spiCp));
        ACC_TRY_HR(spiCp->Advise(this, &cookie));
        Add(piSource, cookie);
        return S_OK;
    }
    HRESULT Unadvise(IUnknown* piSource) throw()
    {
        DWORD cookie;
        if (FAILED(Lookup(piSource, &cookie)))
            return S_FALSE;
        CAccPtr<IConnectionPoint> spiCp;
        ACC_TRY_HR(FindConnectionPoint(piSource, &spiCp));
        ACC_TRY_HR(spiCp->Unadvise(cookie));
        Remove(piSource);
        return S_OK;
    }
    bool Advised(IUnknown* piSource = NULL) const throw()
    {
        // retain old behavior if no source specified
        if (!piSource)
            return m_conns.size() > 0;
        return SUCCEEDED(Lookup(piSource));
    }
protected:
    STDMETHOD(QueryInterface)(REFIID iid, void** pp) throw()
        { return CAccObject<IDispatch>::QueryInterface((iid != DIID_DAccEvents) ? iid : IID_IDispatch, pp); }
    STDMETHOD(GetTypeInfoCount)(UINT*) throw()
        { return E_NOTIMPL; }
    STDMETHOD(GetTypeInfo)(UINT, LCID, ITypeInfo**) throw()
        { return E_NOTIMPL; }
    STDMETHOD(GetIDsOfNames)(REFIID, LPOLESTR*, UINT, LCID, DISPID*) throw()
        { return E_NOTIMPL; }

    ACC_BEGIN_EVENT_MAP()
    ACC_EVENT_ENTRY3(ACCDISPID_ONSTATECHANGE, OnStateChange,
        IAccSession*, AccSessionState, AccResult)
    ACC_EVENT_ENTRY2(ACCDISPID_ONSESSIONCHANGE, OnSessionChange,
        IAccSession*, AccSessionProp)
    ACC_EVENT_ENTRY2(ACCDISPID_ONIDLESTATECHANGE, OnIdleStateChange,
        IAccSession*, xp_int)
    ACC_EVENT_ENTRY4(ACCDISPID_ONINSTANCECHANGE, OnInstanceChange,
        IAccSession*, IAccInstance*, IAccInstance*, AccInstanceProp)
    ACC_EVENT_ENTRY6(ACCDISPID_ONREPORTUSERRESULT, OnReportUserResult,
        IAccSession*, IAccUser*, xp_int, AccResult, xp_int, xp_int)
    ACC_EVENT_ENTRY5(ACCDISPID_ONLOOKUPUSERSRESULT, OnLookupUsersResult,
        IAccSession*, xp_kvariant, AccTransId, AccResult, xp_kvariant)
    ACC_EVENT_ENTRY4(ACCDISPID_ONSEARCHDIRECTORYRESULT, OnSearchDirectoryResult,
        IAccSession*, AccTransId, AccResult, xp_kvariant)
    ACC_EVENT_ENTRY3(ACCDISPID_ONSENDINVITEMAILRESULT, OnSendInviteMailResult,
        IAccSession*, AccTransId, AccResult)
    ACC_EVENT_ENTRY6(ACCDISPID_ONREQUESTSERVICERESULT, OnRequestServiceResult,
        IAccSession*, AccTransId, AccResult, xp_kstr, xp_int, xp_kvariant)
    ACC_EVENT_ENTRY3(ACCDISPID_ONCONFIRMACCOUNTRESULT, OnConfirmAccountResult,
        IAccSession*, AccTransId, AccResult)
    ACC_EVENT_ENTRY2(ACCDISPID_ONALERTRECEIVED, OnAlertReceived,
        IAccSession*, IAccAlert*)
    ACC_EVENT_ENTRY6(ACCDISPID_ONBARTITEMREQUESTPROPERTYRESULT, OnBartItemRequestPropertyResult,
        IAccSession*, IAccBartItem*, AccBartItemProp, AccTransId, AccResult, xp_kvariant)
    ACC_EVENT_ENTRY6(ACCDISPID_ONUSERREQUESTPROPERTYRESULT, OnUserRequestPropertyResult,
        IAccSession*, IAccUser*, AccUserProp, AccTransId, AccResult, xp_kvariant)
    ACC_EVENT_ENTRY4(ACCDISPID_ONGROUPADDED, OnGroupAdded,
        IAccSession*, IAccGroup*, xp_int, AccResult)
    ACC_EVENT_ENTRY3(ACCDISPID_ONGROUPREMOVED, OnGroupRemoved,
        IAccSession*, IAccGroup*, AccResult)
    ACC_EVENT_ENTRY5(ACCDISPID_ONGROUPMOVED, OnGroupMoved,
        IAccSession*, IAccGroup*, xp_int, xp_int, AccResult)
    ACC_EVENT_ENTRY5(ACCDISPID_ONBUDDYADDED, OnBuddyAdded,
        IAccSession*, IAccGroup*, IAccUser*, xp_int, AccResult)
    ACC_EVENT_ENTRY4(ACCDISPID_ONBUDDYREMOVED, OnBuddyRemoved,
        IAccSession*, IAccGroup*, IAccUser*, AccResult)
    ACC_EVENT_ENTRY7(ACCDISPID_ONBUDDYMOVED, OnBuddyMoved,
        IAccSession*, IAccUser*, IAccGroup*, xp_int, IAccGroup*, xp_int, AccResult)
    ACC_EVENT_ENTRY3(ACCDISPID_ONBUDDYLISTCHANGE, OnBuddyListChange,
        IAccSession*, IAccBuddyList*, AccBuddyListProp)
    ACC_EVENT_ENTRY3(ACCDISPID_ONGROUPCHANGE, OnGroupChange,
        IAccSession*, IAccGroup*, AccGroupProp)
    ACC_EVENT_ENTRY5(ACCDISPID_ONUSERCHANGE, OnUserChange,
        IAccSession*, IAccUser*, IAccUser*, AccUserProp, AccResult)
    ACC_EVENT_ENTRY1(ACCDISPID_ONCHANGESBEGIN, OnChangesBegin,
        IAccSession*)
    ACC_EVENT_ENTRY1(ACCDISPID_ONCHANGESEND, OnChangesEnd,
        IAccSession*)
    ACC_EVENT_ENTRY3(ACCDISPID_ONPREFERENCECHANGE, OnPreferenceChange,
        IAccSession*, xp_kstr, AccResult)
    ACC_EVENT_ENTRY5(ACCDISPID_ONPREFERENCERESULT, OnPreferenceResult,
        IAccSession*, xp_kstr, AccTransId, xp_kvariant, AccResult)
    ACC_EVENT_ENTRY3(ACCDISPID_ONPREFERENCEINVALID, OnPreferenceInvalid,
        IAccSession*, xp_kstr, AccResult)
    ACC_EVENT_ENTRY3(ACCDISPID_ONPLUGINCHANGE, OnPluginChange,
        IAccSession*, IAccPluginInfo*, AccPluginInfoProp)
    ACC_EVENT_ENTRY3(ACCDISPID_ONNEWSECONDARYSESSION, OnNewSecondarySession,
        IAccSession*, IAccSecondarySession*, xp_int)
    ACC_EVENT_ENTRY4(ACCDISPID_ONSECONDARYSESSIONSTATECHANGE, OnSecondarySessionStateChange,
        IAccSession*, IAccSecondarySession*, AccSecondarySessionState, AccResult)
    ACC_EVENT_ENTRY3(ACCDISPID_ONSECONDARYSESSIONCHANGE, OnSecondarySessionChange,
        IAccSession*, IAccSecondarySession*, xp_int)
    ACC_EVENT_ENTRY3(ACCDISPID_ONPARTICIPANTJOINED, OnParticipantJoined,
        IAccSession*, IAccSecondarySession*, IAccParticipant*)
    ACC_EVENT_ENTRY6(ACCDISPID_ONPARTICIPANTLEFT, OnParticipantLeft,
        IAccSession*, IAccSecondarySession*, IAccParticipant*, AccResult, xp_kstr, xp_kstr)
    ACC_EVENT_ENTRY5(ACCDISPID_ONPARTICIPANTCHANGE, OnParticipantChange,
        IAccSession*, IAccSecondarySession*, IAccParticipant*, IAccParticipant*, AccParticipantProp)
    ACC_EVENT_ENTRY5(ACCDISPID_ONINVITERESULT, OnInviteResult,
        IAccSession*, IAccSecondarySession*, xp_kstr, AccTransId, AccResult)
    ACC_EVENT_ENTRY5(ACCDISPID_ONEJECTRESULT, OnEjectResult,
        IAccSession*, IAccSecondarySession*, xp_kstr, AccTransId, AccResult)
    ACC_EVENT_ENTRY4(ACCDISPID_BEFOREIMSEND, BeforeImSend,
        IAccSession*, IAccImSession*, IAccParticipant*, IAccIm*)
    ACC_EVENT_ENTRY4(ACCDISPID_ONIMSENT, OnImSent,
        IAccSession*, IAccImSession*, IAccParticipant*, IAccIm*)
    ACC_EVENT_ENTRY5(ACCDISPID_ONIMSENDRESULT, OnImSendResult,
        IAccSession*, IAccImSession*, IAccParticipant*, IAccIm*, AccResult)
    ACC_EVENT_ENTRY4(ACCDISPID_BEFOREIMRECEIVED, BeforeImReceived,
        IAccSession*, IAccImSession*, IAccParticipant*, IAccIm*)
    ACC_EVENT_ENTRY4(ACCDISPID_ONIMRECEIVED, OnImReceived,
        IAccSession*, IAccImSession*, IAccParticipant*, IAccIm*)
    ACC_EVENT_ENTRY3(ACCDISPID_ONLOCALIMRECEIVED, OnLocalImReceived,
        IAccSession*, IAccImSession*, IAccIm*)
    ACC_EVENT_ENTRY4(ACCDISPID_ONINPUTSTATECHANGE, OnInputStateChange,
        IAccSession*, IAccImSession*, xp_kstr, AccImInputState)
    ACC_EVENT_ENTRY5(ACCDISPID_ONEMBEDDOWNLOADPROGRESS, OnEmbedDownloadProgress,
        IAccSession*, IAccImSession*, IAccIm*, xp_kstr, IAccStream*)
    ACC_EVENT_ENTRY3(ACCDISPID_ONEMBEDDOWNLOADCOMPLETE, OnEmbedDownloadComplete,
        IAccSession*, IAccImSession*, IAccIm*)
    ACC_EVENT_ENTRY5(ACCDISPID_ONEMBEDUPLOADPROGRESS, OnEmbedUploadProgress,
        IAccSession*, IAccImSession*, IAccIm*, xp_kstr, IAccStream*)
    ACC_EVENT_ENTRY3(ACCDISPID_ONEMBEDUPLOADCOMPLETE, OnEmbedUploadComplete,
        IAccSession*, IAccImSession*, IAccIm*)
    ACC_EVENT_ENTRY3(ACCDISPID_ONRATELIMITSTATECHANGE, OnRateLimitStateChange,
        IAccSession*, IAccImSession*, AccRateState)
    ACC_EVENT_ENTRY3(ACCDISPID_ONNEWFILEXFER, OnNewFileXfer,
        IAccSession*, IAccFileXferSession*, IAccFileXfer*)
    ACC_EVENT_ENTRY3(ACCDISPID_ONFILEXFERPROGRESS, OnFileXferProgress,
        IAccSession*, IAccFileXferSession*, IAccFileXfer*)
    ACC_EVENT_ENTRY3(ACCDISPID_ONFILEXFERCOLLISION, OnFileXferCollision,
        IAccSession*, IAccFileXferSession*, IAccFileXfer*)
    ACC_EVENT_ENTRY4(ACCDISPID_ONFILEXFERCOMPLETE, OnFileXferComplete,
        IAccSession*, IAccFileXferSession*, IAccFileXfer*, AccResult)
    ACC_EVENT_ENTRY3(ACCDISPID_ONFILEXFERSESSIONCOMPLETE, OnFileXferSessionComplete,
        IAccSession*, IAccFileXferSession*, AccResult)
    ACC_EVENT_ENTRY5(ACCDISPID_ONFILESHARINGREQUESTLISTINGRESULT, OnFileSharingRequestListingResult,
        IAccSession*, IAccFileSharingSession*, IAccFileSharingItem*, AccTransId, AccResult)
    ACC_EVENT_ENTRY5(ACCDISPID_ONFILESHARINGREQUESTXFERRESULT, OnFileSharingRequestXferResult,
        IAccSession*, IAccFileSharingSession*, IAccFileXferSession*, AccTransId, IAccFileXfer*)
    ACC_EVENT_ENTRY6(ACCDISPID_ONAVSTREAMSTATECHANGE, OnAvStreamStateChange,
        IAccSession*, IAccAvSession*, xp_kstr, AccAvStreamType, AccSecondarySessionState, AccResult)
    ACC_EVENT_ENTRY4(ACCDISPID_ONAVMANAGERCHANGE, OnAvManagerChange,
        IAccSession*, IAccAvManager*, AccAvManagerProp, AccResult)
    ACC_EVENT_ENTRY4(ACCDISPID_ONAUDIOLEVELCHANGE, OnAudioLevelChange,
        IAccSession*, IAccAvSession*, xp_kstr, xp_int)
    ACC_EVENT_ENTRY4(ACCDISPID_ONSOUNDEFFECTRECEIVED, OnSoundEffectReceived,
        IAccSession*, IAccAvSession*, xp_kstr, xp_kstr)
    ACC_EVENT_ENTRY5(ACCDISPID_ONCUSTOMSENDRESULT, OnCustomSendResult,
        IAccSession*, IAccCustomSession*, IAccParticipant*, IAccIm*, AccResult)
    ACC_EVENT_ENTRY4(ACCDISPID_ONCUSTOMDATARECEIVED, OnCustomDataReceived,
        IAccSession*, IAccCustomSession*, IAccParticipant*, IAccIm*)
    ACC_EVENT_ENTRY4(ACCDISPID_ONREQUESTSUMMARIESRESULT, OnRequestSummariesResult,
        IAccSession*, AccTransId, AccResult, xp_kvariant)
    ACC_EVENT_ENTRY3(ACCDISPID_ONDELIVERSTOREDIMSRESULT, OnDeliverStoredImsResult,
        IAccSession*, AccTransId, AccResult)
    ACC_EVENT_ENTRY3(ACCDISPID_ONDELETESTOREDIMSRESULT, OnDeleteStoredImsResult,
        IAccSession*, AccTransId, AccResult)

    ACC_END_EVENT_MAP()
    virtual void OnStateChange(IAccSession*, AccSessionState, AccResult)
        {}
    virtual void OnSessionChange(IAccSession*, AccSessionProp)
        {}
    virtual void OnInstanceChange(IAccSession*, IAccInstance*, IAccInstance*,
        AccInstanceProp) {}
    virtual void OnUserChange(IAccSession*, IAccUser*, IAccUser*, AccUserProp,
        AccResult) {}
    virtual void OnChangesBegin(IAccSession*)
        {}
    virtual void OnChangesEnd(IAccSession*)
        {}
    virtual void OnIdleStateChange(IAccSession*, xp_int)
        {}
    virtual void OnLookupUsersResult (IAccSession*, xp_kvariant, AccTransId,
        AccResult, xp_kvariant) {}
    virtual void OnReportUserResult(IAccSession*, IAccUser*, AccTransId,
        AccResult, xp_int, xp_int) {}
    virtual void OnSearchDirectoryResult(IAccSession*, AccTransId, AccResult,
        xp_kvariant) {}
    virtual void OnSendInviteMailResult(IAccSession*, AccTransId, AccResult)
        {}
    virtual void OnRequestServiceResult(IAccSession*, AccTransId, AccResult,
        xp_kstr, xp_int, xp_kvariant) {}
    virtual void OnConfirmAccountResult(IAccSession*, AccTransId, AccResult)
        {}
    virtual void OnPreferenceChange(IAccSession*, xp_kstr, AccResult)
        {}
    virtual void OnPreferenceResult(IAccSession*, xp_kstr, AccTransId,
        xp_kvariant, AccResult)
        {}
    virtual void OnPreferenceInvalid(IAccSession*, xp_kstr, AccResult)
        {}
    virtual void OnPluginChange(IAccSession*, IAccPluginInfo*,
        AccPluginInfoProp) {}
    virtual void OnBuddyListChange(IAccSession*, IAccBuddyList*,
        AccBuddyListProp) {}
    virtual void OnBuddyAdded(IAccSession*, IAccGroup*, IAccUser*, xp_int,
        AccResult) {}
    virtual void OnBuddyRemoved(IAccSession*, IAccGroup*, IAccUser*,
        AccResult) {}
    virtual void OnBuddyMoved(IAccSession*, IAccUser*, IAccGroup*, xp_int,
        IAccGroup*, xp_int, AccResult) {}
    virtual void OnGroupChange(IAccSession*, IAccGroup*, AccGroupProp)
        {}
    virtual void OnGroupAdded(IAccSession*, IAccGroup*, xp_int, AccResult)
        {}
    virtual void OnGroupRemoved(IAccSession*, IAccGroup*, AccResult)
        {}
    virtual void OnGroupMoved(IAccSession*, IAccGroup*, xp_int, xp_int,
        AccResult) {}
    virtual void OnBartItemRequestPropertyResult(IAccSession*, IAccBartItem*,
        AccBartItemProp, AccTransId, AccResult, xp_kvariant) {}
    virtual void OnUserRequestPropertyResult(IAccSession*, IAccUser*,
        AccUserProp, AccTransId, AccResult, xp_kvariant) {}
    virtual void OnAlertReceived(IAccSession*, IAccAlert*)
        {}
    virtual void OnNewSecondarySession(IAccSession*, IAccSecondarySession*,
        xp_int) {}
    virtual void OnSecondarySessionStateChange(IAccSession*,
        IAccSecondarySession*, AccSecondarySessionState, AccResult) {}
    virtual void OnSecondarySessionChange(IAccSession*, IAccSecondarySession*,
        xp_int) {}
    virtual void OnParticipantJoined(IAccSession*, IAccSecondarySession*,
        IAccParticipant*) {}
    virtual void OnParticipantChange(IAccSession*, IAccSecondarySession*,
        IAccParticipant*, IAccParticipant*, AccParticipantProp) {}
    virtual void OnParticipantLeft(IAccSession*, IAccSecondarySession*,
        IAccParticipant*, AccResult, xp_kstr, xp_kstr) {}
    virtual void OnInviteResult(IAccSession*, IAccSecondarySession*, xp_kstr,
        AccTransId, AccResult) {}
    virtual void OnEjectResult(IAccSession*, IAccSecondarySession*, xp_kstr,
        AccTransId, AccResult) {}
    virtual void OnInputStateChange(IAccSession*, IAccImSession*, xp_kstr,
        AccImInputState) {}
    virtual void BeforeImSend(IAccSession*, IAccImSession*, IAccParticipant*,
        IAccIm*) {}
    virtual void OnImSent(IAccSession*, IAccImSession*, IAccParticipant*,
        IAccIm*) {}
    virtual void OnImSendResult(IAccSession*, IAccImSession*, IAccParticipant*,
        IAccIm*, AccResult) {}
    virtual void BeforeImReceived(IAccSession*, IAccImSession*, IAccParticipant*,
        IAccIm*) {}
    virtual void OnImReceived(IAccSession*, IAccImSession*, IAccParticipant*,
        IAccIm*) {}
    virtual void OnLocalImReceived(IAccSession*, IAccImSession*, IAccIm*) {}
    virtual void OnEmbedDownloadProgress(IAccSession*, IAccImSession*,
        IAccIm*, xp_kstr, IAccStream*) {}
    virtual void OnEmbedDownloadComplete(IAccSession*, IAccImSession*,
        IAccIm*) {}
    virtual void OnEmbedUploadProgress(IAccSession*, IAccImSession*,
        IAccIm*, xp_kstr, IAccStream*) {}
    virtual void OnEmbedUploadComplete(IAccSession*, IAccImSession*,
        IAccIm*) {}
    virtual void OnRateLimitStateChange(IAccSession*, IAccImSession*,
        AccRateState) {}
    virtual void OnNewFileXfer(IAccSession*, IAccFileXferSession*,
        IAccFileXfer*) {}
    virtual void OnFileXferProgress(IAccSession*, IAccFileXferSession*,
        IAccFileXfer*) {}
    virtual void OnFileXferCollision(IAccSession*, IAccFileXferSession*,
        IAccFileXfer*) {}
    virtual void OnFileXferComplete(IAccSession*, IAccFileXferSession*,
        IAccFileXfer*, AccResult) {}
    virtual void OnFileXferSessionComplete(IAccSession*, IAccFileXferSession*,
        AccResult) {}
    virtual void OnFileSharingRequestListingResult(IAccSession*,
        IAccFileSharingSession*, IAccFileSharingItem*, AccTransId, AccResult) {}
    virtual void OnFileSharingRequestXferResult(IAccSession*,
        IAccFileSharingSession*, IAccFileXferSession*, AccTransId, IAccFileXfer*) {}
    virtual void OnAvStreamStateChange(IAccSession*, IAccAvSession*, xp_kstr,
        AccAvStreamType, AccSecondarySessionState, AccResult) {}
    virtual void OnAvManagerChange(IAccSession*, IAccAvManager*, AccAvManagerProp,
        AccResult) {}
    virtual void OnAudioLevelChange(IAccSession*, IAccAvSession*, xp_kstr,
        xp_int) {}
    virtual void OnSoundEffectReceived(IAccSession*, IAccAvSession*, xp_kstr,
        xp_kstr) {}
    virtual void OnCustomSendResult(IAccSession*, IAccCustomSession*, IAccParticipant*,
        IAccIm*, AccResult) {}
    virtual void OnCustomDataReceived(IAccSession*, IAccCustomSession*, IAccParticipant*,
        IAccIm*) {}
    virtual void OnRequestSummariesResult(IAccSession*, AccTransId, AccResult,
        xp_kvariant) {}
    virtual void OnDeliverStoredImsResult(IAccSession*, AccTransId, AccResult) {}
    virtual void OnDeleteStoredImsResult(IAccSession*, AccTransId, AccResult) {}

private:
    HRESULT Lookup(IUnknown* p, DWORD* pCookie = NULL) const throw()
    {
        xp_int i = LookupIndex(p);
        if (i == -1)
            return E_FAIL;
        if (pCookie)
            *pCookie = m_conns[i].cookie;
        return S_OK;
    }

    HRESULT Add(IUnknown* p, DWORD cookie) throw()
    {
        SConnection conn = { p, cookie };
        m_conns.push_back(conn);
        return S_OK;
    }
    HRESULT Remove(IUnknown* p) throw()
    {
        xp_int i = LookupIndex(p);
        if (i == -1)
            return S_FALSE;
        m_conns.erase(m_conns.begin() + i);
        return S_OK;
    }
    xp_int LookupIndex(IUnknown* p) const throw()
    {
        xp_int i;
        for (i = (xp_int)m_conns.size() - 1; i >= 0; i--)
        {
            if (m_conns[i].piSource == p)
                break;
        }
        return i;
    }
    static HRESULT FindConnectionPoint(IUnknown* piSource, IConnectionPoint** pp) throw()
    {
        CAccPtr<IConnectionPointContainer> spiCpc(piSource);
        if (!spiCpc)
            return E_FAIL;
        return spiCpc->FindConnectionPoint(DIID_DAccEvents, pp);
    }
private:
    struct SConnection
    {
        IUnknown* piSource;
        DWORD cookie;
    };
    std::vector<SConnection> m_conns;
};

// Base class to implement a preferences "hook".
// Clients typically will derive from this class so that they can implement
// Load() and Save() appropriately; however if only Add/RemoveOverride are
// needed, this class can be used directly.
//
class CAccPrefsHook : public CAccObject<IAccPreferencesHook>
{
public:
    // This method returns a properly ref-counted object.
    static HRESULT CreateInstance(CAccPrefsHook** pp) throw()
    {
        ACC_TRY_EXPR_(pp, E_POINTER);
        CAccPtr<CAccPrefsHook> sp(new CAccPrefsHook);
        ACC_TRY_EXPR_(sp, E_OUTOFMEMORY);
        *pp = sp.Detach();
        return S_OK;
    }
    CAccPrefsHook() throw() {}
    virtual ~CAccPrefsHook() throw() {}
    HRESULT Install(IAccSession* p) throw() { return p->put_PrefsHook(this); }
    HRESULT Uninstall(IAccSession* p) throw() { return p->put_PrefsHook(NULL); }
public:
    STDMETHOD(GetValue)(xp_kstr spec, xp_variant* pv) throw()
    {
        iterator it = m_map.find(spec);
        if (it == m_map.end())
            return ACC_E_NO_DATA;
        ACC_TRY_HR(it->second.Copy(&pv->bstrVal));
        pv->vt = VT_BSTR;
        return S_OK;
    }
    STDMETHOD(GetDefaultValue)(xp_kstr spec, xp_variant* pv) throw()
    {
        iterator it = m_defaults.find(spec);
        if (it == m_defaults.end())
            return ACC_E_NO_DATA;
        ACC_TRY_HR(it->second.Copy(&pv->bstrVal));
        pv->vt = VT_BSTR;
        return S_OK;
    }
    STDMETHOD(SetValue)(xp_kstr spec, xp_kvariant v) throw()
    {
        // need to catch exceptions here
        CAccVariant s(v);
        ACC_TRY_HR(s.ChangeType(VT_BSTR));
        m_map[spec] = s.bstrVal;
        Save(); // should rollback on error
        return S_OK;
    }
    STDMETHOD(Reset)(xp_kstr spec) throw()
    {
        if (m_map.erase(spec) == 0)
            return S_FALSE;
        Save(); // should rollback on error
        return S_OK;
    }
    STDMETHOD(GetChildSpecifiers)(xp_kstr parentSpec, xp_variant* pv) throw()
    {
        xp_int parentSpecLen = AccStringLen(parentSpec);
        std::map<CAccBstr, CAccBstr> foundStrs;

        // create safearray to hold child specifiers
        CAccVariantArray array;
        ACC_TRY_HR(array.Create());

        // iterate map
        for (iterator it = m_map.begin(); it != m_map.end(); it++)
        {
            // if find a descendant
            CAccBstr spec(it->first);
            if (AccStringHasPrefix(spec, parentSpec) &&
                spec.Length() > (parentSpecLen + 1) &&
                spec[parentSpecLen] == (OLECHAR)'.')
            {
                // only interested in immediate children, not grandchildren,
                // so truncate at next separator, if any
                char buf[256];
                if (spec.GetUtf8(buf, xp_countof(buf)) > (xp_int)xp_countof(buf))
                    return E_FAIL;
                char* nextSep = strchr(buf + parentSpecLen + 1, '.');
                if (nextSep)
                    *nextSep = '\0';
                spec = buf;

                // if child not already added to safearray, add
                if (foundStrs.find(spec) == foundStrs.end())
                {
                    foundStrs[spec] = spec;
                    ACC_TRY_HR(array.Add(CAccVariant(spec)));
                }
            }
        }

        // if no children found, we're done
        if (array.Count() == 0)
            return E_FAIL;

        // return safearray of child specifiers
        pv->vt = VT_ARRAY | VT_VARIANT;
        pv->parray = array.Detach();
        return S_OK;
    }
    // Allows the application to override AIMCC's default prefs.
    HRESULT AddOverride(xp_kstr spec, xp_kstr value)
    {
        return AddDefault(spec,value);
    }
    HRESULT RemoveOverride(xp_kstr spec)
    {
        return RemoveDefault(spec);
    }
    // Allows the application to override AIMCC's default prefs.
    HRESULT AddDefault(xp_kstr spec, xp_kstr value)
    {
        m_defaults[spec] = value;
        return S_OK;
    }
    HRESULT RemoveDefault(xp_kstr spec)
    {
        m_defaults.erase(spec);
        return S_OK;
    }
protected:
    virtual HRESULT Load() throw() { return S_FALSE; }
    virtual HRESULT Save() throw() { return S_FALSE; }
protected:
    std::map<CAccBstr, CAccBstr> m_map;
    std::map<CAccBstr, CAccBstr> m_defaults;
    typedef std::map<CAccBstr, CAccBstr>::iterator iterator;
};

class CAccPrefsHookOnFile : public CAccPrefsHook
{
public:
    // This method returns a properly ref-counted object.
    static HRESULT CreateInstance(xp_kstr fileSpec, CAccPrefsHook** pp) throw()
    {
        ACC_TRY_EXPR_(pp, E_POINTER);
        CAccPtr<CAccPrefsHookOnFile> sp(new CAccPrefsHookOnFile(fileSpec));
        ACC_TRY_EXPR_(sp, E_OUTOFMEMORY);
        ACC_TRY_HR(sp->Load());
        *pp = sp.Detach();
        return S_OK;
    }
    CAccPrefsHookOnFile(xp_kstr fileSpec) : m_fileSpec(fileSpec)
    {
#ifdef WIN32
            m_winVerOver98 = GetVersion()<0x80000000;
#endif
    }
protected:
    virtual HRESULT Load() throw()
    {
        FILE* fp = NULL;
#ifdef WIN32
        // Windows 98 doesn't have _wfopen
        if(m_winVerOver98) fp = _wfopen(m_fileSpec, L"r");
        else
#endif
        {
            char buf[256];
            if (m_fileSpec.GetUtf8(buf, xp_countof(buf)) > (xp_int)xp_countof(buf))
                return E_FAIL;
            fp = fopen(buf, "r");
        }
        if (!fp)
            return S_FALSE;
        while (LoadNode(fp) == S_OK)
            ;
        fclose(fp);
        return S_OK;
    }
    virtual HRESULT Save() throw()
    {
        FILE* fp = NULL;
#ifdef WIN32
        // Windows 98 doesn't have _wfopen
        if(m_winVerOver98) fp = _wfopen(m_fileSpec, L"w");
        else
#endif
        {
            char buf[256];
            if (m_fileSpec.GetUtf8(buf, xp_countof(buf)) > (xp_int)xp_countof(buf))
                return E_FAIL;
            fp = fopen(buf, "w");
        }
        if (!fp)
            return E_FAIL;
        for (iterator it = m_map.begin(); it != m_map.end(); it++)
            SaveNode(fp, it);
        fclose(fp);
        return S_OK;
    }
private:
    HRESULT LoadNode(FILE* fp) throw()
    {
        char line[4096], value[4096];
        if (!fgets(line, xp_countof(line), fp))
            return S_FALSE;
        char* eq = strchr(line, '=');
        if (!eq)
            return E_FAIL;
        *eq = '\0';
        char* p = eq + 1, *q = value;
        do
        {
            // skip trailing newline
            if (*p == '\n')
                ;
            // leave normal chars alone
            else if (*p != '\\')
            {
                *q = *p;
                q++;
            }
            // convert \r, \n, \\ to single characters
            else
            {
                p++;
                if (*p == 'r')
                    *q = '\r';
                else if (*p == 'n')
                    *q = '\n';
                else if (*p == '\\')
                    *q = '\\';
                else
                    return E_FAIL;
                q++;
            }
        }
        while (*p++);
        // need to try/catch here
        m_map.insert(std::make_pair(CAccBstr(line), CAccBstr(value)));
        return S_OK;
    }
    HRESULT SaveNode(FILE* fp, iterator it) throw()
    {
        char spec[256];
        char value[4096];
        size_t len;
        it->first.GetUtf8(spec, xp_countof(spec));
        it->second.GetUtf8(value, xp_countof(value));
        len = strlen(spec);
        ACC_TRY_EXPR_FAIL(fwrite(spec, 1, len, fp) == len);
        ACC_TRY_EXPR_FAIL(fwrite("=", 1, 1, fp) == 1);
        char* p = value;
        while (*p)
        {
            char* q;
            // escape special characters
            if (*p == '\r')
                q = "\\r";
            else if (*p == '\n')
                q = "\\n";
            else if (*p == '\\')
                q = "\\\\";
            // otherwise it's a normal char
            else
                q = p;
            len = (*q != '\\') ? 1 : 2;
            ACC_TRY_EXPR_FAIL(fwrite(q, 1, len, fp) == len);
            p++;
        }
        ACC_TRY_EXPR_FAIL(fwrite("\n", 1, 1, fp) == 1);
        return S_OK;
    }
private:
    CAccBstr m_fileSpec;
#ifdef WIN32
    bool m_winVerOver98;
#endif
};

// Class to help implement an IAccStream listener
// Clients derive from this interface
//
class CAccStreamListener : public CAccObject<IAccStreamListener>
{
public:
    HRESULT Install(IAccStream* p) throw() { return p->SetAsyncListener(this); }
    HRESULT Uninstall(IAccStream* p) throw() { return p->SetAsyncListener(NULL); }
protected:
    STDMETHOD(OnDataAvailable)(IAccStream*) throw()
        { return S_OK; }
    STDMETHOD(OnReadyForData)(IAccStream*) throw()
        { return S_OK; }
    STDMETHOD(OnClosed)(IAccStream*, AccResult) throw()
        { return S_OK; }
};

// Class to help implement an AIMCC plugin
//
class CAccPlugin : public CAccEventSink,
    public IAccPlugin, public IAccCommandTarget
{
public:
    template<class T>
    static HRESULT Create(REFIID iid, void** pp)
    {
        CAccPlugin* p = new T;
        ACC_TRY_EXPR_(p, E_OUTOFMEMORY);
        return p->QueryInterface(iid, pp);
    }
    static HRESULT Create(REFIID iid, void** pp)
    {
        return CAccPlugin::Create<CAccPlugin>(iid, pp);
    }
    //static HRESULT Register(REFCLSID clsid)
    //static HRESULT Unregister(REFCLSID clsid)
protected:
    STDMETHOD_(ULONG, AddRef)() throw() { return CAccEventSink::AddRef(); }
    STDMETHOD_(ULONG, Release)() throw() { return CAccEventSink::Release(); }
    STDMETHOD(QueryInterface) (REFIID iid, void** pp) throw()
    {
        HRESULT hr = S_OK;
        if (iid == IID_IAccPlugin)
        {
			*pp = (IAccPlugin*)this;
            AddRef();
        }
        else if (iid == IID_IAccCommandTarget)
        {
            *pp = (IAccCommandTarget*)this;
            AddRef();
        }
        else
            hr = CAccEventSink::QueryInterface(iid, pp);
        return hr;
    }
    STDMETHOD(Init)(IAccSession*, IAccPluginInfo*)
        { return S_OK; }
    STDMETHOD(Shutdown)()
        { return S_OK; }
    STDMETHOD(QueryStatus)(xp_int, xp_kvariant, xp_vbool*)
        { return E_NOTIMPL; }
    STDMETHOD(Exec)(xp_int, xp_kvariant)
        { return E_NOTIMPL; }
private:
    class CClassFactory : public CAccObject<IClassFactory>
    {
    public:
        typedef HRESULT (*CreateFunc)(REFIID, void**);
        static HRESULT Create(CreateFunc f, REFIID iid, void** pp)
        {
            CClassFactory* p = new CClassFactory;
            ACC_TRY_EXPR_(p, E_OUTOFMEMORY);
            p->m_createFunc = f;
            return p->QueryInterface(iid, pp);
        }
    protected:
        CClassFactory() : m_createFunc(NULL) {}
        STDMETHOD(CreateInstance)(IUnknown* piOuter, REFIID iid, void** pp)
        {
            ACC_TRY_EXPR_FAIL(m_createFunc);
            ACC_TRY_EXPR_FAIL(!piOuter);
            return m_createFunc(iid, pp);
        }
        STDMETHOD(LockServer)(int)
        {
            return E_NOTIMPL;
        }
    private:
        CreateFunc m_createFunc;
    };
};

} // namespace AIMCC
#endif // __AccCore_h__

// ATL component registrations helpers
//
#ifdef WIN32
#ifdef __ATLBASE_H__ // currently requires ATL
// Function to load AIMCC type library... stand-in for LoadRegTypeLib
//
inline HRESULT AccLoadTypeLib(REFGUID guid, WORD, WORD, LCID, ITypeLib** ppTypeLib)
{
#if defined(_WIN32_WCE)
    return E_NOTIMPL;
#else
    USES_CONVERSION;
    HRESULT hr;
    TCHAR buf[MAX_PATH];
    GetModuleFileName(GetModuleHandle(_T("acccore.dll")), buf, MAX_PATH);
    hr = LoadTypeLibEx(T2OLE(buf), REGKIND_NONE, ppTypeLib);
#ifdef _DEBUG
    // if using the static library, provide a workaround
    if (FAILED(hr))
        hr = LoadTypeLibEx(OLESTR("acccore.tlb"), REGKIND_NONE, ppTypeLib);
#endif
    return hr;
#endif
}

// Plugin registration helpers
//
inline HRESULT AccRegisterPlugin(REFGUID guid, HMODULE hMod, LPCTSTR name,
                                 LPCTSTR version, LPCTSTR desc, LPCTSTR url,
                                 LPCTSTR vend, LPCTSTR vurl)
{
    USES_CONVERSION;
    OLECHAR guidBuf[64];
    TCHAR pathBuf[MAX_PATH];
    StringFromGUID2(guid, guidBuf, 64);
    GetModuleFileName(hMod, pathBuf, MAX_PATH);

    CRegKey k1, k2, k3;
    if (k1.Open(HKEY_CLASSES_ROOT, _T("CLSID")) != ERROR_SUCCESS ||
        k2.Create(k1, OLE2T(guidBuf)) != ERROR_SUCCESS ||
        k2.SetStringValue(_T(""), name) != ERROR_SUCCESS ||
        k3.Create(k2, _T("InProcServer32")) != ERROR_SUCCESS ||
        k3.SetStringValue(_T(""), pathBuf) != ERROR_SUCCESS)
        return E_FAIL;

    CRegKey k4, k5;
    if (k4.Create(HKEY_LOCAL_MACHINE, _T("Software\\America Online\\AIM\\Plugins")) != ERROR_SUCCESS ||
        k5.Create(k4, OLE2T(guidBuf)) != ERROR_SUCCESS ||
        k5.SetStringValue(_T("Name"), name) != ERROR_SUCCESS ||
        k5.SetStringValue(_T("Version"), version) != ERROR_SUCCESS ||
        k5.SetStringValue(_T("Description"), desc) != ERROR_SUCCESS ||
        k5.SetStringValue(_T("Url"), url) != ERROR_SUCCESS ||
        k5.SetStringValue(_T("Vendor"), vend) != ERROR_SUCCESS ||
        k5.SetStringValue(_T("VendorUrl"), vurl) != ERROR_SUCCESS)
        return E_FAIL;

    return S_OK;
}

inline HRESULT AccUnregisterPlugin(REFGUID guid)
{
    USES_CONVERSION;
    OLECHAR guidBuf[256];
    StringFromGUID2(guid, guidBuf, 64);

    CRegKey k1, k2;
    if (k1.Open(HKEY_CLASSES_ROOT, _T("CLSID")) == ERROR_SUCCESS)
        k1.RecurseDeleteKey(OLE2T(guidBuf));
    if (k2.Open(HKEY_LOCAL_MACHINE, _T("Software\\America Online\\AIM\\Plugins")) == ERROR_SUCCESS)
        k2.DeleteSubKey(OLE2T(guidBuf));
    return S_OK;
}

#define ACC_DECLARE_REGISTRY(name, version, desc, url, vend, vurl) \
    static HRESULT WINAPI UpdateRegistry(BOOL bRegister) \
    { \
        return bRegister ? \
            AccRegisterPlugin(GetObjectCLSID(), _AtlBaseModule.GetModuleInstance(), \
                _T(name), _T(version), _T(desc), _T(url), _T(vend), _T(vurl)) : \
            AccUnregisterPlugin(GetObjectCLSID()); \
    }
#endif // __ATLBASE_H__

#elif defined(linux)
//Linux plugin information helper
#define _ACC_PLUGIN_DECLARE_INFO_HELPER(x, pp) do { CAccBstr _bstr(x); return (_bstr.Length() && (*pp = _bstr.Detach()) ? S_OK : E_FAIL); } while(0)
#define ACC_PLUGIN_DECLARE_INFO(PluginClassName, AccVer, Uuid, name, ver, desc, url, ven, venurl ) \
    STDAPI CreateInstance(REFIID iid, void** pp) { return CAccPlugin::Create<PluginClassName>(iid, pp);} \
    STDAPI GetAccVersion(xp_str* pp) {_ACC_PLUGIN_DECLARE_INFO_HELPER(AccVer, pp);} \
    STDAPI GetPluginUuid(xp_str* pp) {_ACC_PLUGIN_DECLARE_INFO_HELPER("{"Uuid"}", pp);} \
    STDAPI GetPluginName(xp_str* pp) {_ACC_PLUGIN_DECLARE_INFO_HELPER(name, pp);} \
    STDAPI GetPluginVersion(xp_str* pp) {_ACC_PLUGIN_DECLARE_INFO_HELPER(ver, pp);} \
    STDAPI GetPluginDesc(xp_str* pp) {_ACC_PLUGIN_DECLARE_INFO_HELPER(desc, pp);} \
    STDAPI GetPluginVendor(xp_str* pp) {_ACC_PLUGIN_DECLARE_INFO_HELPER(ven, pp);} \
    STDAPI GetPluginVendorUrl(xp_str* pp) {_ACC_PLUGIN_DECLARE_INFO_HELPER(venurl, pp);} \
    STDAPI GetPluginUrl(xp_str* pp) {_ACC_PLUGIN_DECLARE_INFO_HELPER(url, pp);}
#endif // WIN32

#endif // ACCSUPPORT_H
