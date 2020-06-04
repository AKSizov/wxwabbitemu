#ifndef _STDAFX_H
#define _STDAFX_H

#if defined(_WINDOWS)
#pragma once

#define _WIN32_LEAN_AND_MEAN

#ifndef STRICT
#define STRICT
#endif

#define _ATL_NO_AUTOMATIC_NAMESPACE
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

#include <winsock2.h>
#include <Windows.h>
#include <WindowsX.h>
#include <tchar.h>
#include <strsafe.h>
#include <CommCtrl.h>
#include <shlobj.h>
#include <math.h>
#include <Uxtheme.h>
#include <dwmapi.h>
#include <Ole2.h>
#include <OleIdl.h>
#include <ShObjIdl.h>
#include <assert.h>
#include <setjmp.h>
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#include <stdio.h>
#include <sys/types.h>
#include <mmsystem.h>
#include <stddef.h>
#include <time.h>


#ifdef __cplusplus
#include <gdiplus.h>
using namespace Gdiplus;
#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>
using namespace ATL;
#include <map>
#include <list>
#include <vector>
#include <string>

namespace std
{
#ifdef UNICODE
typedef std::wstring tstring;
#else
typedef std::string tstring;
#endif
}
#endif

#elif defined(_LINUX)
#include <assert.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <stddef.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <float.h>
#include <algorithm>

using std::min;
using std::max;

#ifdef _UNICODE
#include <wchar.h>
#endif
#ifdef WXVER
#include <wx/wx.h>
#undef _T
#endif

#include "config.h"

#ifdef _In_
#undef _In_
#endif
#define _In_

#ifdef _Inout_
#undef _Inout_
#endif
#define _Inout_

#ifdef _Out_
#undef _Out_
#endif
#define _Out_

typedef void *LPVOID;
#define MAX_PATH 256
#ifndef _T

#ifndef HAVE_STRCPY_S
// TODO: properly implement this bounded func
#define strcpy_s(dst, dst_sz, src) strncpy(dst, src, dst_sz)
#endif

// TODO: make configurable
#define vsprintf_s(buf, n, fmt, ap) vsnprintf(buf, n, fmt, ap)
#define vsprintf_s(buf, fmt, ap) vsprintf(buf, fmt, ap)

// TODO: make configurable
typedef int errno_t;
errno_t fopen_s(FILE **f, const wchar_t *name, const wchar_t *mode) {
    errno_t ret = 0;
    assert(f);
    *f = fopen(wxFNCONV(name), (char *)mode);
    /* Can't be sure about 1-to-1 mapping of errno and MS' errno_t */
    if (!*f)
        ret = errno;
    return ret;
}

typedef signed char BOOL;

#ifdef _UNICODE
#define _T(z) L ## z

#ifndef HAVE_WCHAR_T
typedef char TCHAR;
#else
typedef wchar_t TCHAR;
#endif

typedef const wchar_t *LPCTSTR;
typedef wchar_t *LPTSTR;

#ifndef HAVE_MBSTOWCS_S
// TODO: properly implement this bounded func
#define mbstowcs_s(szptr, dst, dst_sz, src, len) mbstowcs(dst, src, len)
#endif

#ifndef HAVE_WCSNCPY_S
// TODO: properly implement this bounded func
#define wcsncpy_s(dst, dst_sz, src, cpy_sz) wcsncpy(dst, (wchar_t *)src, cpy_sz)
#endif

#define StringCbCopy(dst, sz, src) wcsncpy(dst, src, sz)
#define StringCbCopyNA(dst, dst_sz, src, cpy_sz) strcpy_s(dst, dst_sz, src)
#define StringCbPrintf(dst, sz, fmt, ...) swprintf(dst, sz, fmt, __VA_ARGS__)

#define _tcscpy _tcscpy_s
#define _tcscpy_s std::wcscpy
#define _tcsncpy std::wcsncpy
//TODO: fix this to actually properly pass the size
#define _tprintf_s wprintf
#define _tprintf _tprintf_s
#define _tcsicmp wcscasecmp
#define _tcscmp wcscmp
#define _tcsncmp wcsncmp
#define _putts puts
#define _tcsrchr wcsrchr
#define _tcslen wcslen
#define _tfopen_s fopen_s
#define _stscanf swscanf
#define _tcscat wcscat
#define _vstprintf(buffer, format, ...) vswprintf(buffer, wcslen(buffer), format, __VA_ARGS__)
#define _vftprintf vfwprintf
#define _tcsnicmp wcsncasecmp

#else

#define _T(z) z
#define TCHAR char
typedef const char *LPCTSTR;
typedef char *LPCTSTR;

#define mbstowcs_s(szptr, dst, dst_sz, src, len) strncpy(dst, src, len)
#define StringCbCopy(dst, sz, src) strncpy(dst, src, sz)
#define StringCbCopyNA(dst, dst_sz, src, cpy_sz) strcpy_s(dst, dst_sz, src)
#define StringCbPrintf(dst, sz, fmt, ...) snprintf(dst, sz, fmt, __VA_ARGS__)

#define _tprintf_s _tprintf
#define _tprintf sprintf
#define _tcsicmp strcasecmp
#define _putts puts
#define _tcsrchr strrchr
#define _tcsncpy strncpy
#define _tcscpy_s strcpy
#define _tcscpy strcpy
#define _tcslen strlen
#define _tcsncmp strncmp
#define _tcscmp strcmp
#define _tfopen_s fopen_s
#define _stscanf sscanf
#define _tcscat strcat
#define _vftprintf vfprintf
#define _vstprintf vsprintf
#define _tcsnicmp strncasecmp
#endif
#endif
#define _strnicmp strncasecmp
#define ARRAYSIZE(z) (sizeof(z)/sizeof((z)[0]))
#define ZeroMemory(dest, size) memset(dest, 0, size)

#elif defined(_MACVER)
#include <assert.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <sys/types.h>
#include <stddef.h>
#include <time.h>
#include <ctype.h>

/*
typedef char TCHAR;
typedef void *LPVOID;
typedef const char *LPCTSTR;
typedef u_int8_t uint8_t;
typedef u_int16_t uint16_t;
typedef u_int32_t uint32_t;
typedef u_int8_t BYTE, *LPBYTE;
typedef u_int16_t WORD, *LPWORD;
typedef u_int32_t DWORD, *LPDWORD;
 */
/*
#ifndef TRUE
#define FALSE (0)
#define TRUE (!FALSE)
#ifdef WINVER
typedef int BOOL;
#else
typedef signed char BOOL;
#endif
#endif
*/
#define MAX_PATH 256
#define _tprintf_s printf
#define ARRAYSIZE(z) (sizeof(z)/sizeof((z)[0]))
#define _strnicmp strncasecmp
#define _tcsicmp strcasecmp
#define _putts puts
#define _tcsrchr strrchr
#define _tcscpy_s strcpy
#define _tcsncpy strncpy
#define _tcslen strlen
#define _tcscmp strcmp
#define _stscanf sscanf

#endif

#endif
