/**
 * Defines the GExL engine version numbers and provides OS identification and
 * other OS and OS independent values for all GExL engines.
 *
 * @file include/GExL/Config.hpp
 * @author Jacob Dix
 * @date 2014905- Initial Release

 */
#ifndef GExL_CONFIG_HPP
#define GExL_CONFIG_HPP


////////////////////////////////////////////////////////////
// Define the GExL version
////////////////////////////////////////////////////////////
/// Define the GExL Major version number
#define GExL_VERSION_MAJOR 0
/// Define the GExL Minor version number
#define GExL_VERSION_MINOR 1


////////////////////////////////////////////////////////////
// Identify the operating system
////////////////////////////////////////////////////////////
#if defined(_WIN32) || defined(__WIN32__)

/// Define a GExL Windows OS flag
#define GExL_WINDOWS
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif

#elif defined(linux) || defined(__linux)

/// Define a GExL Linux OS flag
#define GExL_LINUX

#elif defined(__APPLE__) || defined(MACOSX) || defined(macintosh) || defined(Macintosh)

/// Define a GExL Mac OS flag
#define GExL_MACOS

#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)

/// Define a GExL FreeBSD OS flag
#define GExL_FREEBSD

#else

// Unsupported system
#error This operating system is not supported by GExL library

#endif

#if defined(ANDROID) || defined(__ANDROID__)
#define GExL_ANDROID
#endif

////////////////////////////////////////////////////////////
// Identify the endianess
////////////////////////////////////////////////////////////
#if defined(__m68k__) || defined(mc68000) || defined(_M_M68K) || (defined(__MIPS__) && defined(__MISPEB__)) || \
  defined(__ppc__) || defined(__POWERPC__) || defined(_M_PPC) || defined(__sparc__) || defined(__hppa__)

/// Define a GExL Big endian flag
#define GExL_ENDIAN_BIG

#else

/// Define a GExL Little endian flag
#define GExL_ENDIAN_LITTLE

#endif

////////////////////////////////////////////////////////////
// Include endianness functions
////////////////////////////////////////////////////////////
#if defined(__GNUC__) && !defined(__MINGW32__)
#include <netinet/in.h>
#else
#include <winsock2.h>
#endif

////////////////////////////////////////////////////////////
// Define a portable debug macro
////////////////////////////////////////////////////////////
#if !defined(NDEBUG)

/// Define a GExL Debug build flag
#define GExL_DEBUG

#endif


////////////////////////////////////////////////////////////
// Define portable import / export macros
////////////////////////////////////////////////////////////
#if defined(GExL_WINDOWS) && defined(GExL_DYNAMIC)

#ifdef GExL_EXPORTS

// From DLL side, we must export
/// Define the GExL DLL API for exporting classes and methods
#define GExL_API __declspec(dllexport)

#else

// From client application side, we must import
/// Define the GExL DLL API for importing classes and methods
#define GExL_API __declspec(dllimport)

#endif

// For Visual C++ compilers, we also need to turn off this annoying C4251 warning.
// You can read lots of different things about it, but the point is the code will
// just work fine, and so the simplest way to get rid of this warning is to disable it
#ifdef _MSC_VER

#pragma warning(disable : 4251)

#endif

#else

// Other platforms and static build don't need these export macros
/// Define the GExL DLL API for non DLL OS platforms as nothing
#define GExL_API

#endif


////////////////////////////////////////////////////////////
// Define portable fixed-size types
////////////////////////////////////////////////////////////
#include <stdint.h>
namespace GExL
{
  // All "common" platforms use the same size for char, short and int
  // (basically there are 3 types for 3 sizes, so no other match is possible),
  // we can use them without doing any kind of check

  // 8 bits integer types
  typedef signed   char Int8;     ///< Standard 8 bit signed integer
  typedef unsigned char Uint8;    ///< Standard 8 bit unsigned integer

  // 16 bits integer types
  typedef signed   short Int16;   ///< Standard 16 bit signed integer
  typedef unsigned short Uint16;  ///< Standard 16 bit unsigned integer

  // 32 bits integer types
  typedef signed   int Int32;     ///< Standard 32 bit signed integer
  typedef unsigned int Uint32;    ///< Standard 32 bit unsigned integer

  // 64 bits integer types
#if defined(_MSC_VER)
  typedef signed   __int64 Int64;  ///< Standard 64 bit signed integer
  typedef unsigned __int64 Uint64; ///< Standard 64 bit unsigned integer
#else
  typedef int64_t          Int64;  ///< Standard 64 bit signed integer
  typedef uint64_t         Uint64; ///< Standard 64 bit unsigned integer
#endif

} // namespace GExL


#endif // GExL_CONFIG_HPP
