///----------------------------------------------------------------------------
///
/// File Name:   AccVersion.h
///
///----------------------------------------------------------------------------
///
/// Copyright 1999-2008 AOL LLC. All rights reserved.
/// This software contains valuable confidential and proprietary information of
/// AOL LLCÊand its use is subject to a license agreement.  Any unauthorized
/// modification, use, reproduction, transmission or distribution of this
/// software code is strictly prohibited.
///
///           A O L   L L C   C O N F I D E N T I A L
///
///----------------------------------------------------------------------------

#ifndef ACCVERSION_H
#define ACCVERSION_H

#define ACC_MAJOR_VERSION           1
#define ACC_MINOR_VERSION           6
#define ACC_POINT_VERSION           7
#define ACC_BUILD_NUMBER            1982

#define ACC_MAJOR_VERSION_STRING    "1"
#define ACC_MINOR_VERSION_STRING    "6"
#define ACC_POINT_VERSION_STRING    "7"
#define ACC_BUILD_NUMBER_STRING     "1982"

#define ACC_VERSION_STRING          ACC_MAJOR_VERSION_STRING "." ACC_MINOR_VERSION_STRING "." ACC_POINT_VERSION_STRING "." ACC_BUILD_NUMBER_STRING

#define ACC_COMPANYNAME             "AOL LLC"
#define ACC_LEGALCOPYRIGHT          "Copyright 2003-2008 AOL LLC"
#define ACC_LEGALTRADEMARKS         ""

#define ACC_PRODUCTNAME             "AIMCC"
#define ACC_SELFREGISTER            VALUE "OLESelfRegister", ""
#define ACC_NOSELFREGISTER          

#if defined(WIN32) || defined(_WIN32_WCE)

#ifndef VS_VERSION_INFO
#define VS_VERSION_INFO 1
#endif

#ifdef _DEBUG
#define ACC_FILEFLAGS 0x1L
#else
#define ACC_FILEFLAGS 0x0L
#endif

#define ACC_IMPLEMENT_VERSIONINFO_APP(module, desc) \
ACC_IMPLEMENT_VERSIONINFO_EX(0x1L, module, exe, desc, ACC_NOSELFREGISTER)

#define ACC_IMPLEMENT_VERSIONINFO_APP_SR(module, desc) \
ACC_IMPLEMENT_VERSIONINFO_EX(0x1L, module, dll, desc, ACC_SELFREGISTER)

#define ACC_IMPLEMENT_VERSIONINFO_DLL(module, desc) \
ACC_IMPLEMENT_VERSIONINFO_EX(0x2L, module, dll, desc, ACC_NOSELFREGISTER)

#define ACC_IMPLEMENT_VERSIONINFO_DLL_SR(module, desc) \
ACC_IMPLEMENT_VERSIONINFO_EX(0x2L, module, dll, desc, ACC_SELFREGISTER)

#define ACC_IMPLEMENT_VERSIONINFO_EX(type, module, ext, desc, selfreg)                      \
VS_VERSION_INFO VERSIONINFO                                                                 \
 FILEVERSION ACC_MAJOR_VERSION,ACC_MINOR_VERSION,ACC_POINT_VERSION,ACC_BUILD_NUMBER         \
 PRODUCTVERSION ACC_MAJOR_VERSION,ACC_MINOR_VERSION,ACC_POINT_VERSION,ACC_BUILD_NUMBER      \
 FILEFLAGSMASK 0x3fL                                                                        \
 FILEFLAGS ACC_FILEFLAGS                                                                    \
 FILEOS 0x4L /* WIN32 */                                                                    \
 FILETYPE type                                                                              \
 FILESUBTYPE 0x0L                                                                           \
BEGIN                                                                                       \
    BLOCK "StringFileInfo"                                                                  \
    BEGIN                                                                                   \
        BLOCK "040904b0"                                                                    \
        BEGIN                                                                               \
            VALUE "CompanyName", ACC_COMPANYNAME                                            \
            VALUE "FileDescription", #module " " #desc                                      \
            VALUE "FileVersion", ACC_VERSION_STRING                                         \
            VALUE "InternalName", #module                                                   \
            VALUE "LegalCopyright", ACC_LEGALCOPYRIGHT                                      \
            VALUE "LegalTrademarks", ACC_LEGALTRADEMARKS                                    \
            VALUE "OriginalFilename", #module "." #ext                                      \
            VALUE "ProductName", ACC_PRODUCTNAME                                            \
            VALUE "ProductVersion", ACC_VERSION_STRING                                      \
            selfreg                                                                         \
        END                                                                                 \
    END                                                                                     \
    BLOCK "VarFileInfo"                                                                     \
    BEGIN                                                                                   \
        VALUE "Translation", 0x409, 1200                                                    \
    END                                                                                     \
END

#elif defined(unix)

#define ACC_IMPLEMENT_VERSIONINFO_IDENTc(label,value)        \
{ static const char* identValue = "$" label ": " value " $"; \
  strlen(identValue); }

#define ACC_IMPLEMENT_VERSIONINFO_IDENTd(x, label,value)     \
static const char* _ACC_identValue##x = "$" label ": " value " $";

#define ACC_IMPLEMENT_VERSIONINFO_IDENT_CODE(module) \
  ACC_IMPLEMENT_VERSIONINFO_IDENTc("Product",   ACC_PRODUCTNAME " - " #module) \
  ACC_IMPLEMENT_VERSIONINFO_IDENTc("Copyright", ACC_LEGALCOPYRIGHT) \
  ACC_IMPLEMENT_VERSIONINFO_IDENTc("Version",   ACC_VERSION_STRING) \
  ACC_IMPLEMENT_VERSIONINFO_IDENTc("BuildDate", __DATE__ " " __TIME__)

#define ACC_IMPLEMENT_VERSIONINFO_IDENT_DATA(module) \
  ACC_IMPLEMENT_VERSIONINFO_IDENTd(1, "Product",   ACC_PRODUCTNAME " - " #module) \
  ACC_IMPLEMENT_VERSIONINFO_IDENTd(2, "Copyright", ACC_LEGALCOPYRIGHT) \
  ACC_IMPLEMENT_VERSIONINFO_IDENTd(3, "Version",   ACC_VERSION_STRING) \
  ACC_IMPLEMENT_VERSIONINFO_IDENTd(4, "BuildDate", __DATE__ " " __TIME__)

#elif defined(macintosh)

#define ACC_IMPLEMENT_VERSIONINFO                       \
resource 'vers' (1)                                 \
{                                                   \
    ACC_MAJOR_VERSION,                              \
    ACC_MINOR_VERSION << 4 | ACC_POINT_VERSION,     \
    release,                                        \
    ACC_BUILD_NUMBER % 255,                         \
    verUS,                                          \
    ACC_VERSION_STRING,                             \
    ACC_VERSION_STRING "\n" ACC_LEGALCOPYRIGHT      \
};

#endif

#ifndef ACC_IMPLEMENT_VERSIONINFO_IDENT_CODE
#define ACC_IMPLEMENT_VERSIONINFO_IDENT_CODE(x)
#endif
#ifndef ACC_IMPLEMENT_VERSIONINFO_IDENT_DATA
#define ACC_IMPLEMENT_VERSIONINFO_IDENT_DATA(x)
#endif


#endif
