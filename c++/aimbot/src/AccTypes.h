/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Wed Jan 23 13:47:32 2008
 */
/* Compiler settings for C:\work\aimcc\cvs\aimcc\idl\AccTypes.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "AccBase.h"

#ifndef __AccTypes_h__
#define __AccTypes_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

/* header files for imported files */


/* interface __MIDL_itf_AccTypes_0000 */
/* [local] */ 

typedef int xp_int;

typedef int xp_sint;

typedef unsigned int xp_uint;

typedef signed char xp_s08;

typedef unsigned char xp_u08;

typedef short xp_s16;

typedef unsigned short xp_u16;

typedef int xp_s32;

typedef unsigned int xp_u32;

#if defined(WIN32)
typedef hyper xp_s64;

typedef MIDL_uhyper xp_u64;

#elif defined(__LONG_LONG_MAX__) && (__LONG_LONG_MAX__ == 9223372036854775807LL)
typedef signed long long xp_s64;
typedef unsigned long long xp_u64;
#endif
typedef float xp_float;

typedef double xp_double;

typedef DATE xp_date;

typedef VARIANT_BOOL xp_vbool;

typedef VARTYPE xp_vtype;

#ifdef __cplusplus
typedef bool xp_bool;
#endif
typedef OLECHAR xp_unichar;

typedef BSTR xp_str;

#if 0
typedef BSTR xp_kstr;

#else
typedef const xp_unichar* xp_kstr; // const BSTR 
#endif
typedef VARIANT xp_variant;

#if 0
typedef VARIANT xp_kvariant;

#else
typedef const VARIANT xp_kvariant;
#endif
#ifdef __cplusplus
inline xp_kvariant AccEmptyVariant() { xp_variant v = {0}; return v; }
#define accOptVariant v = AccEmptyVariant()
#endif
typedef SAFEARRAY xp_array;

typedef xp_int AccTransId;

typedef void ( __RPC_FAR *AccMessageAvailableCallback )( 
    void __RPC_FAR *data);

#ifndef xp_countof
#define xp_countof(x) (sizeof(x)/sizeof(x[0]))
#endif
#ifndef XP_BEGIN_NAMESPACE
#define XP_BEGIN_NAMESPACE(x) namespace x {
#define XP_END_NAMESPACE() }
#endif
#ifndef XP_IMPLEMENT_UUIDOF_IDL
#ifdef __cplusplus
} extern "C++" {
template<class T> struct xp_uuidof_helper \
{ static const IID& uuid() { return GUID_NULL; } };
template<class T> inline const IID& xp_uuidof(T*) \
{ return xp_uuidof_helper<T*>::uuid(); }
#define XP_IMPLEMENT_UUIDOF(x) \
template<> struct xp_uuidof_helper<x*> \
{ static const IID& uuid() { return IID_##x; } };
#define XP_IMPLEMENT_UUIDOF_IDL(x) \
} extern "C++" { XP_IMPLEMENT_UUIDOF(x) } extern "C" {
XP_IMPLEMENT_UUIDOF(IUnknown)
} extern "C" {
#else
#define XP_IMPLEMENT_UUIDOF_IDL(x)
#endif
#endif
#ifdef __cplusplus
} extern "C++" {
XP_IMPLEMENT_UUIDOF(IDispatch)
XP_IMPLEMENT_UUIDOF(IConnectionPoint)
XP_IMPLEMENT_UUIDOF(IConnectionPointContainer)
XP_IMPLEMENT_UUIDOF(IStream)
XP_IMPLEMENT_UUIDOF(ISequentialStream)
} extern "C" {
#endif
typedef 
enum AccResult
    {	ACC_E	= -2147221504,
	ACC_S	= 0x40000,
	ACC_E_TOO_MANY_ITEMS	= ACC_E | 0x200,
	ACC_E_TOO_MUCH_DATA	= ACC_E | 0x201,
	ACC_E_ALREADY_EXISTS	= ACC_E | 0x202,
	ACC_E_NO_DATA	= ACC_E | 0x203,
	ACC_E_INVALID_DATA	= ACC_E | 0x204,
	ACC_E_BANNED_DATA	= ACC_E | 0x205,
	ACC_E_TOO_MANY_MATCHES	= ACC_E | 0x206,
	ACC_E_MUST_REQUEST_DATA	= ACC_E | 0x207,
	ACC_E_RATE_LIMITED	= ACC_E | 0x210,
	ACC_E_NOT_LOGGED_ON	= ACC_E | 0x211,
	ACC_E_INVALID_CLIENT_INFO	= ACC_E | 0x212,
	ACC_E_INVALID_IDENTITY	= ACC_E | 0x213,
	ACC_E_SERVER_ERROR	= ACC_E | 0x214,
	ACC_E_TIMEOUT	= ACC_E | 0x215,
	ACC_E_FEATURE_DISABLED	= ACC_E | 0x216,
	ACC_E_FEATURE_UNAVAILABLE	= ACC_E | 0x217,
	ACC_E_INSUFFICIENT_RIGHTS	= ACC_E | 0x218,
	ACC_E_FILE_NOT_FOUND	= ACC_E | 0x220,
	ACC_E_WRITE_FAILED	= ACC_E | 0x221,
	ACC_E_INVALID_PASSWORD	= ACC_E | 0x222,
	ACC_E_READ_FAILED	= ACC_E | 0x223,
	ACC_E_INVALID_CHECKSUM	= ACC_E | 0x224,
	ACC_E_FILE_CORRUPT	= ACC_E | 0x224,
	ACC_E_REQUEST_DENIED	= ACC_E | 0x225,
	ACC_E_NO_ADDRESS	= ACC_E | 0x226,
	ACC_E_UNSUPPORTED_CONVERSION	= ACC_E | 0x227,
	ACC_E_READ_ONLY	= ACC_E | 0x228,
	ACC_E_STORAGE_FULL	= ACC_E | 0x229,
	ACC_E_PEER_UNREACHABLE	= ACC_E | 0x325,
	ACC_E_BUDDYLIST_UNAVAILABLE	= ACC_E | 0x326,
	ACC_E_INVALID_SERVER_NAME	= ACC_E | 0x230,
	ACC_E_CONNECT_ERROR	= ACC_E | 0x231,
	ACC_E_INVALID_PROXY_NAME	= ACC_E | 0x232,
	ACC_E_PROXY_CONNECT_ERROR	= ACC_E | 0x233,
	ACC_E_PROXY_AUTH_ERROR	= ACC_E | 0x234,
	ACC_E_INVALID_TUNNEL_NAME	= ACC_E | 0x235,
	ACC_E_TUNNEL_CONNECT_ERROR	= ACC_E | 0x236,
	ACC_E_BUMPED	= ACC_E | 0x237,
	ACC_E_SSL_HANDSHAKE_ERROR	= ACC_E | 0x238,
	ACC_E_DISCONNECTED	= ACC_E | 0x23f,
	ACC_E_SUSPENDED_IDENTITY	= ACC_E | 0x240,
	ACC_E_MANDATORY_UPGRADE	= ACC_E | 0x241,
	ACC_E_INVALID_SECURID	= ACC_E | 0x242,
	ACC_E_NEED_CREDIT_CARD_VALIDATION	= ACC_E | 0x243,
	ACC_E_INVALID_LINK	= ACC_E | 0x244,
	ACC_E_BROKEN_LINK	= ACC_E | 0x245,
	ACC_E_NOT_FROM_FREE_AREA	= ACC_E | 0x250,
	ACC_E_PARENTAL_CONTROLS	= ACC_E | 0x251,
	ACC_E_SESSION_FULL	= ACC_E | 0x252,
	ACC_E_PAYMENT_REQUIRED	= ACC_E | 0x253,
	ACC_E_INVALID_SESSION_NAME	= ACC_E | 0x254,
	ACC_E_CANNOT_INITIATE_SESSION	= ACC_E | 0x255,
	ACC_E_SESSION_NOT_READY	= ACC_E | 0x256,
	ACC_E_USER_BLOCKED	= ACC_E | 0x260,
	ACC_E_USER_NOT_CAPABLE	= ACC_E | 0x261,
	ACC_E_USER_NOT_LOGGED_ON	= ACC_E | 0x262,
	ACC_E_USER_PARENTAL_CONTROLS	= ACC_E | 0x263,
	ACC_E_USER_INNOCENT	= ACC_E | 0x264,
	ACC_E_USER_IS_BUDDY	= ACC_E | 0x265,
	ACC_E_USER_IS_BOT	= ACC_E | 0x266,
	ACC_E_USER_DID_NOT_INITIATE	= ACC_E | 0x267,
	ACC_E_USER_AUTH_REQUIRED	= ACC_E | 0x268,
	ACC_E_USER_REJECTED	= ACC_E | 0x270,
	ACC_E_USER_UNAVAILABLE	= ACC_E | 0x271,
	ACC_E_VERSION_MISMATCH	= ACC_E | 0x272,
	ACC_E_SECURITY_MISMATCH	= ACC_E | 0x273,
	ACC_E_USER_BUSY	= ACC_E | 0x274,
	ACC_E_USER_CANCELLED	= ACC_E | 0x278,
	ACC_E_USER_ABANDONED	= ACC_E | 0x279,
	ACC_E_ACCEPTED_ELSEWHERE	= ACC_E | 0x27a,
	ACC_E_SESSION_CLOSED	= ACC_E | 0x280,
	ACC_E_SESSION_EXPIRED	= ACC_E | 0x281,
	ACC_E_SESSION_SHUTDOWN	= ACC_E | 0x282,
	ACC_E_EJECTED	= ACC_E | 0x283,
	ACC_E_INVALID_SIGNATURE	= ACC_E | 0x300,
	ACC_E_EXPIRED_CERT	= ACC_E | 0x310,
	ACC_E_UNKNOWN_CERT_ISSUER	= ACC_E | 0x311,
	ACC_E_UNTRUSTED_CERT_ISSUER	= ACC_E | 0x312,
	ACC_E_INVALID_CERT_USAGE	= ACC_E | 0x313,
	ACC_E_REVOKED_CERT	= ACC_E | 0x314,
	ACC_E_NO_DEVICE	= ACC_E | 0x323,
	ACC_E_BUSY_DEVICE	= ACC_E | 0x324,
	ACC_E_PLUGIN_ABORTED_ACTION	= ACC_E | 0x400,
	ACC_E_PLUGIN_CONSUMED_ACTION	= ACC_E | 0x401,
	ACC_E_INVALID_KEY	= ACC_E | 0x410,
	ACC_E_RATE_LIMITED_KEY	= ACC_E | 0x411,
	ACC_E_EXPIRED_KEY	= ACC_E | 0x412,
	ACC_E_SUSPENDED_KEY	= ACC_E | 0x413,
	ACC_E_INVALID_FINGERPRINT	= ACC_E | 0x414,
	ACC_S_NO_CHANGE	= ACC_S | 0x201
    }	AccResult;


enum __MIDL___MIDL_itf_AccTypes_0000_0001
    {	ACC_STREAM_CREATE_FLAGS_NOCOPY	= 0x1
    };
#define \
kAccCap_SecureIm OLESTR("{09460001-4C7F-11D1-8222-444553540000}")
#define \
kAccCap_XhtmlIm OLESTR("{09460002-4C7F-11D1-8222-444553540000}")
#define \
kAccCap_RtpVideo OLESTR("{09460101-4C7F-11D1-8222-444553540000}")
#define \
kAccCap_HasCamera OLESTR("{09460102-4C7F-11D1-8222-444553540000}")
#define \
kAccCap_HasMic OLESTR("{09460103-4C7F-11D1-8222-444553540000}")
#define \
kAccCap_RtpAudio OLESTR("{09460104-4C7F-11D1-8222-444553540000}")
#define \
kAccCap_AvailForCall OLESTR("{09460105-4C7F-11D1-8222-444553540000}")
#define \
kAccCap_MultiAudio OLESTR("{09460107-4C7F-11D1-8222-444553540000}")
#define \
kAccCap_MultiVideo OLESTR("{09460108-4C7F-11D1-8222-444553540000}")
#define \
kAccCap_OldAudio OLESTR("{09461341-4C7F-11D1-8222-444553540000}")
#define \
kAccCap_FileXfer OLESTR("{09461343-4C7F-11D1-8222-444553540000}")
#define \
kAccCap_DirectIm OLESTR("{09461345-4C7F-11D1-8222-444553540000}")
#define \
kAccCap_BuddyIcon OLESTR("{09461346-4C7F-11D1-8222-444553540000}")
#define \
kAccCap_FileSharing OLESTR("{09461348-4C7F-11D1-8222-444553540000}")
#define \
kAccCap_ShareBuddies OLESTR("{0946134B-4C7F-11D1-8222-444553540000}")
#define \
kAccCap_Chat OLESTR("{748F2420-6287-11D1-8222-444553540000}")
#define \
kAccCap_SmartCaps OLESTR("{094601FF-4C7F-11D1-8222-444553540000}")
EXTERN_C const IID IID_IAccBartItem;
EXTERN_C const IID IID_IAccCertificate;
EXTERN_C const IID IID_IAccFileSharingItem;
EXTERN_C const IID IID_IAccFileXfer;
EXTERN_C const IID IID_IAccFileXferSession;
EXTERN_C const IID IID_IAccIm;
EXTERN_C const IID IID_IAccUpgradeInfo;
EXTERN_C const IID IID_IAccSecondarySession;
EXTERN_C const IID IID_IAccSession;
struct IAccBartItem;
struct IAccCertificate;
struct IAccFileSharingItem;
struct IAccFileXfer;
struct IAccFileXferSession;
struct IAccIm;
struct IAccUpgradeInfo;
struct IAccSecondarySession;


extern RPC_IF_HANDLE __MIDL_itf_AccTypes_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_AccTypes_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
