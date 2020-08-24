#pragma once

#ifndef SETUP_H
#define SETUP_H

#include "platform.hpp"

namespace smath {

	using length_t = int;

} // namespace glm


//  __      __           _
//  \ \    / /          (_)
//   \ \  / /__ _ __ ___ _  ___  _ __
//    \ \/ / _ \ '__/ __| |/ _ \| '_ \.
//     \  /  __/ |  \__ \ | (_) | | | |
//      \/ \___|_|  |___/_|\___/|_| |_|
//

#define SMATH_VERSION_MAJOR 0
#define SMATH_VERSION_MINOR 1
#define SMATH_VERSION_PATCH 2
#define SMATH_VERSION_MESSAGE "smath v0.1.2"

#define SMATH_DISABLE 0
#define SMATH_ENABLE  1

//    _____              _____ _                  _               _
//   / ____|_     _     / ____| |                | |             | |
//  | |   _| |_ _| |_  | (___ | |_ __ _ _ __   __| | __ _ _ __ __| |
//  | |  |_   _|_   _|  \___ \| __/ _` | '_ \ / _` |/ _` | '__/ _` |
//  | |____|_|   |_|    ____) | || (_| | | | | (_| | (_| | | | (_| |
//   \_____|           |_____/ \__\__,_|_| |_|\__,_|\__,_|_|  \__,_|
//

#define SMATH_LANG_CXX0X_FLAG  (1 << 1)
#define SMATH_LANG_CXX11_FLAG  (1 << 2)
#define SMATH_LANG_CXX14_FLAG  (1 << 3)
#define SMATH_LANG_CXX17_FLAG  (1 << 4)
#define SMATH_LANG_CXX2A_FLAG  (1 << 5)

#define SMATH_LANG_CXX0X  SMATH_LANG_CXX0X_FLAG
#define SMATH_LANG_CXX11  (SMATH_LANG_CXX0X | SMATH_LANG_CXX11_FLAG)
#define SMATH_LANG_CXX14  (SMATH_LANG_CXX11 | SMATH_LANG_CXX14_FLAG)
#define SMATH_LANG_CXX17  (SMATH_LANG_CXX14 | SMATH_LANG_CXX17_FLAG)
#define SMATH_LANG_CXX2A  (SMATH_LANG_CXX17 | SMATH_LANG_CXX2A_FLAG)

// Controls language extensions
#define SMATH_LANG_EXT SMATH_DISABLE

// check if using Visual Studio compiler
#if SMATH_COMPILER & SMATH_COMPILER_VC && defined(_MSVC_LANG)
#	if SMATH_COMPILER >= SMATH_COMPILER_VC15_7
#		define SMATH_LANG_PLATFORM _MSVC_LANG
#	elif SMATH_COMPILER >= SMATH_COMPILER_VC15
#		if _MSVC_LANG > 201402L
#			define SMATH_LANG_PLATFORM 201402L
#		else
#			define SMATH_LANG_PLATFORM _MSVC_LANG
#		endif
#	else
#		define SMATH_LANG_PLATFORM 0
#	endif
#else
#	define SMATH_LANG_PLATFORM 0
#endif

// check C++ standard
#if __cplusplus > 201703L || SMATH_LANG_PLATFORM > 201703L
#	define SMATH_LANG (SMATH_LANG_CXX2A | SMATH_LANG_EXT)
#elif __cplusplus == 201703L || SMATH_LANG_PLATFORM == 201703L
#	define SMATH_LANG (SMATH_LANG_CXX17 | SMATH_LANG_EXT)
#elif __cplusplus == 201402L || __cplusplus == 201406L || __cplusplus == 201500L || SMATH_LANG_PLATFORM == 201402L
#	define SMATH_LANG (SMATH_LANG_CXX14 | SMATH_LANG_EXT)
#elif __cplusplus == 201103L || SMATH_LANG_PLATFORM == 201103L
#	define SMATH_LANG (SMATH_LANG_CXX11 | SMATH_LANG_EXT)
#else
#	define SMATH_LANG (0 | SMATH_LANG_EXT)
#endif

//    _____             ______         _
//   / ____|_     _    |  ____|       | |
//  | |   _| |_ _| |_  | |__ ___  __ _| |_ _   _ _ __ ___  ___
//  | |  |_   _|_   _| |  __/ _ \/ _` | __| | | | '__/ _ \/ __|
//  | |____|_|   |_|   | | |  __/ (_| | |_| |_| | | |  __/\__ \.
//   \_____|           |_|  \___|\__,_|\__|\__,_|_|  \___||___/
//

// -- constexpr
// N2235 Generalized Constant Expressions http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2007/n2235.pdf
// N3652 Relaxing constraints on constexpr functions http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2013/n3652.html
#if (SMATH_COMPILER & SMATH_COMPILER_CLANG)
#	define SMATH_HAS_CONSTEXPR __has_feature(cxx_relaxed_constexpr)
#elif (SMATH_LANG & SMATH_LANG_CXX14_FLAG)
#	define SMATH_HAS_CONSTEXPR 1
#else
#	define SMATH_HAS_CONSTEXPR ((SMATH_LANG & SMATH_LANG_CXX0X_FLAG) && \
		((SMATH_COMPILER & SMATH_COMPILER_VC) && (SMATH_COMPILER >= SMATH_COMPILER_VC15)))
#endif

#if SMATH_HAS_CONSTEXPR
#	define SMATH_CONSTEXPR constexpr
#else
#	define SMATH_CONSTEXPR
#endif

// -- static_assert
// N1720 Proposal to Add Static Assertions to the Core Language http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2004/n1720.html
#if SMATH_COMPILER & SMATH_COMPILER_CLANG
#	define SMATH_HAS_STATIC_ASSERT __has_feature(cxx_static_assert)
#elif SMATH_LANG & SMATH_LANG_CXX11_FLAG
#	define SMATH_HAS_STATIC_ASSERT 1
#else
#	define SMATH_HAS_STATIC_ASSERT ((SMATH_LANG & SMATH_LANG_CXX0X_FLAG) && \
		((SMATH_COMPILER & SMATH_COMPILER_VC)))
#endif

#if SMATH_HAS_STATIC_ASSERT
#	define SMATH_STATIC_ASSERT(x, message) static_assert(x, message)
#elif SMATH_COMPILER & SMATH_COMPILER_VC
#	define SMATH_STATIC_ASSERT(x, message) typedef char __CASSERT__##__LINE__[(x) ? 1 : -1]
#else
#	define SMATH_STATIC_ASSERT(x, message) assert(x && message)
#endif

#endif // SETUP_H
