////////////////////////////////////////////////////////////
//
// MIT License
//
// Copyright(c) 2019 Kurt Slagle - kurt_slagle@yahoo.com
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files(the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions :
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
// The origin of this software must not be misrepresented; you must not claim
// that you wrote the original software.If you use this software in a product,
// an acknowledgment of the software used is required.
//
////////////////////////////////////////////////////////////

#pragma once

namespace detail
{

#define winapi __stdcall
#define apientry winapi
#define callback __stdcall

#if defined(_WIN64)
  using ulong_ptr  = unsigned __int64;
  using half_ptr   = int;
  using int_ptr    = __int64;
  using long_ptr   = __int64;
  using uhalf_ptr  = unsigned int;
  using uint_ptr   = unsigned __int64;
  using puhalf_ptr = uhalf_ptr *;
#  define pointer_32 __ptr32
#else
  using ulong_ptr  = unsigned long;
  using half_ptr   = short;
  using int_ptr    = int;
  using long_ptr   = long;
  using uhalf_ptr  = unsigned short;
  using uint_ptr   = unsigned int;
  using puhalf_ptr = uhalf_ptr *;
#  define pointer_32
#endif

#if !defined(_M_IX86)
  using ulonglong = unsigned __int64;
  using longlong  = __int64;
#else
  using ulonglong = double;
  using longlong  = double;
#endif

#if (_MSC_VER >= 1300)
#  define pointer_64 __ptr64
#else
#  define pointer_64
#endif

  using bool_   = int;
  using byte    = unsigned char;
  using boolean = byte;
  using char_   = char;
  using wchar   = wchar_t;
  using cchar   = char;
  using uchar   = unsigned char;
  using short_  = short;
  using ushort  = unsigned short;
  using int8    = signed char;
  using int16   = signed short;
  using int32   = signed int;
  using int64   = signed __int64;
  using uint    = unsigned int;
  using uint8   = unsigned char;
  using uint16  = unsigned short;
  using uint32  = unsigned int;
  using uint64  = unsigned __int64;
  using long32  = signed int;
  using long64  = __int64;
  using ulong   = unsigned long;
  using ulong32 = unsigned int;
  using ulong64 = unsigned __int64;
  using size_t  = ulong_ptr;
  using ssize_t = long_ptr;
  using float_  = float;

#if defined(UNICODE)
  using tchar  = wchar_t;
  using tbyte  = wchar;
#else
  using tchar  = unsigned char;
  using tbyte  = unsigned char;
#endif

  using word = unsigned short;
  using atom = word;

  using pvoid = void*;
  using dword = unsigned long;
  using dword_ptr = ulong_ptr;

  using pbool      = bool_ *;
  using pbyte      = byte *;
  using pboolean   = boolean *;
  using pchar      = char*;
  using pwchar     = wchar *;
  using pcchar     = cchar *;
  using puchar     = uchar *;
  using pshort     = short*;
  using pushort    = ushort *;
  using pint       = int*;
  using pint8      = int8 *;
  using pint16     = int16 *;
  using pint32     = int32 *;
  using pint64     = int64 *;
  using puint      = uint *;
  using puint8     = uint8 *;
  using puint16    = uint16 *;
  using puint32    = uint32 *;
  using puint64    = uint64 *;
  using plong32    = long32 *;
  using plong64    = long64 *;
  using pulong     = ulong *;
  using pulong32   = ulong32 *;
  using pulong64   = ulong64 *;
  using psize_t    = detail::size_t*;
  using pssize_t   = ssize_t *;
  using pfloat     = float*;

  using pint_ptr   = int_ptr;
  using puint_ptr  = uint_ptr *;
  using plong      = long*;
  using plonglong  = longlong *;
  using plong_ptr  = long_ptr *;  
  using pulonglong = ulonglong *;
  using pulong_ptr = ulong_ptr *;

  using ptbyte = tbyte *;
  using ptchar = tchar *;

  using colorref     = dword;
  using dwordlong    = unsigned __int64;
  using phalf_ptr    = half_ptr *;
  using dword32      = unsigned int;
  using dword64      = unsigned __int64;
  using handle       = pvoid;
  using haccel       = handle;
  using hbitmap      = handle;
  using hcolorspace  = handle;
  using hconv        = handle;
  using hconvlist    = handle;
  using hicon        = handle;
  using hcursor      = hicon;
  using hdc          = handle;
  using hdesk        = handle;
  using hdrop        = handle;
  using hdwp         = handle;
  using henhmetafile = handle;
  using hfile        = int;
  using hfont        = handle;
  using hgdiobj      = handle;
  using hglobal      = handle;
  using hhook        = handle;
  using hinstance    = handle;
  using hkey         = handle;
  using hkl          = handle;
  using hlocal       = handle;
  using hmenu        = handle;
  using hmetafile    = handle;
  using hmodule      = hinstance;
  using hmonitor     = handle;
  using hpalette     = handle;
  using hpen         = handle;
  using hresult      = long;
  using hrgn         = handle;
  using hrsrc        = handle;
  using hsz          = handle;
  using hwnd         = handle;

  using langid = word;
  using lcid = dword;
  using lctype = dword;
  using lgrpid = dword;

  using lparam     = long_ptr;
  using lpbool     = bool*;
  using lpbyte     = byte *;
  using lpcolorref = dword *;
  using lpcstr     = const char*;
  using lpctstr    = lpcstr;
  using lpcvoid    = const void*;
  using lpcwstr    = const wchar*;
  using lpwstr     = wchar *;
  using lpdword    = dword *;
  using lphandle   = handle *;
  using lpint      = int*;
  using lplong     = long*;
  using lpstr      = char*;
  
#if defined(UNICODE)
  using lptstr = lpwstr;
  using pctstr = lpwstr;
  using ptstr  = lpwstr;
#else
  using lptstr = lpstr;
  using pcrstr = lpcstr;
  using ptstr  = lpstr;
#endif

  using lpvoid  = void*;
  using lpword  = word *;
  using lresult = long_ptr;
 
#define pointer_signed __sptr
#define pointer_unsigned __uptr


  using pstr       = char*;
  using pcstr      = const char*;
  using pcwstr     = const wchar*;
  using pdword     = dword *;
  using pdwordlong = dwordlong *;
  using pdword_ptr = dword_ptr *;
  using pdword32   = dword32 *;
  using pdword64   = dword64 *;
  using pdfloat    = pfloat *;
  using phandle    = handle *;
  using phkey      = hkey *;
  using plcid      = pdword;

  using pword = word *;
  using pwstr = wchar *;

  using sc_handle             = handle;
  using sc_lock               = lpvoid;
  using service_status_handle = handle;

  struct unicode_string
  {
    ushort Length;
    ushort MaximumLength;
    pwstr Buffer;
  };

  using punicode_string  = unicode_string *;
  using pcunicode_string = const unicode_string*;

  using usn    = longlong;
  using void_  = void;
  using wparam = uint_ptr;

  struct filetime
  {
    dword dwLowDateTime;
    dword dwHighDateTime;
  };

  using pfiletime = filetime *;
  using lpfiletime = filetime *;

  constexpr auto null = 0;

}
