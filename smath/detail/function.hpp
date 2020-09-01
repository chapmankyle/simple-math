#pragma once

#ifndef FUNCTION_H
#define FUNCTION_H

#include "../types/qualifier.hpp"

namespace smath {

	namespace function {

		/**
		 * @brief Template class to execute a function with a single parameter.
		 * @tparam L The number of components of the vector.
		 * @tparam T The type of the given vector (bool, int, double, float)
		 * @tparam A The return type of the vector (bool, int, double, float)
		 */
		template<template<length_t L, class T> class vec, length_t L, class A, class T>
		struct one{};

		template<template<length_t L, class T> class vec, class A, class T>
		struct one<vec, 1, A, T> {
			SMATH_CONSTEXPR static vec<1, A> apply(A (*func) (T x), const vec<1, T> &v) {
				return vec<1, A>(func(v.x));
			}
		};

		template<template<length_t L, class T> class vec, class A, class T>
		struct one<vec, 2, A, T> {
			SMATH_CONSTEXPR static vec<2, A> apply(A (*func) (T x), const vec<2, T> &v) {
				return vec<2, A>(func(v.x), func(v.y));
			}
		};

		template<template<length_t L, class T> class vec, class A, class T>
		struct one<vec, 3, A, T> {
			SMATH_CONSTEXPR static vec<3, A> apply(A (*func) (T x), const vec<3, T> &v) {
				return vec<3, A>(func(v.x), func(v.y), func(v.z));
			}
		};

		template<template<length_t L, class T> class vec, class A, class T>
		struct one<vec, 4, A, T> {
			SMATH_CONSTEXPR static vec<4, A> apply(A (*func) (T x), const vec<4, T> &v) {
				return vec<4, A>(func(v.x), func(v.y), func(v.z), func(v.w));
			}
		};

		/**
		 * @brief Template class to execute a function with two parameters.
		 * @tparam L The number of components of the vector.
		 * @tparam T The type of the given vector (bool, int, double, float)
		 * @tparam A The return type of the vector (bool, int, double, float)
		 */
		template<template<length_t L, class T> class vec, length_t L, class T>
		struct two{};

		template<template<length_t L, class T> class vec, class T>
		struct two<vec, 1, T> {
			SMATH_CONSTEXPR static vec<1, T> apply(T (*func) (T x, T y), const vec<1, T> &a, const vec<1, T> &b) {
				return vec<1, T>(func(a.x, b.x));
			}
		};

		template<template<length_t L, class T> class vec, class T>
		struct two<vec, 2, T> {
			SMATH_CONSTEXPR static vec<2, T> apply(T (*func) (T x, T y), const vec<2, T> &a, const vec<2, T> &b) {
				return vec<2, T>(func(a.x, b.x), func(a.y, b.y));
			}
		};

		template<template<length_t L, class T> class vec, class T>
		struct two<vec, 3, T> {
			SMATH_CONSTEXPR static vec<3, T> apply(T (*func) (T x, T y), const vec<3, T> &a, const vec<3, T> &b) {
				return vec<3, T>(func(a.x, b.x), func(a.y, b.y), func(a.z, b.z));
			}
		};

		template<template<length_t L, class T> class vec, class T>
		struct two<vec, 4, T> {
			SMATH_CONSTEXPR static vec<4, T> apply(T (*func) (T x, T y), const vec<4, T> &a, const vec<4, T> &b) {
				return vec<4, T>(func(a.x, b.x), func(a.y, b.y), func(a.z, b.z), func(a.w, b.w));
			}
		};

	} // namespace function

} // namespace smath

#endif // FUNCTION_H
