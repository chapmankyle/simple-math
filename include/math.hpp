#pragma once

#ifndef MATH_H
#define MATH_H

#include <cmath>

#include "detail/setup.hpp"
#include "detail/function.hpp"

#include "template_types.hpp"

namespace smath {

	/**
	 * @brief Calculates the maximum between two types, comparable by operator<
	 * @returns The larger of the two provided types.
	 */
	template<class T>
	SMATH_CONSTEXPR const T& max(const T &a, const T &b) {
		return (a < b) ? b : a;
	}

	/**
	 * @brief Calculates the maximum between three types, comparable by operator<
	 * @returns The larger of the three provided types.
	 */
	template<class T>
	SMATH_CONSTEXPR const T max(const T &a, const T &b, const T &c) {
		return smath::max(a, smath::max(b, c));
	}

	/**
	 * @brief Calculates the minimum between two types, comparable by operator<
	 * @returns The smaller of the two provided types.
	 */
	template<class T>
	SMATH_CONSTEXPR const T& min(const T &a, const T &b) {
		return (a < b) ? a : b;
	}

	/**
	 * @brief Calculates the minimum between three types, comparable by operator<
	 * @returns The smaller of the three provided types.
	 */
	template<class T>
	SMATH_CONSTEXPR const T min(const T &a, const T &b, const T &c) {
		return smath::min(a, smath::min(b, c));
	}

	/**
	 * @brief Calculates the absolute value of the given type.
	 * @returns `a` if `a` >= 0 else `-a`.
	 */
	template<class T>
	SMATH_CONSTEXPR const T abs(const T &a) {
		SMATH_STATIC_ASSERT(smath::is_integer_type<T>::value || smath::is_floating_type<T>::value, "'abs' only accepts integer or floating-point inputs");
		return (a >= 0) ? a : -a;
	}

	/**
	 * @brief Converts each component of a vector into the absolute value of that component.
	 * @tparam L The number of components in the vector in range [1, 4]
	 * @tparam T The type of the vector (int, float, double)
	 * @returns A vector of length `L` and type `T` with each component as a positive number.
	 */
	template<length_t L, class T>
	SMATH_CONSTEXPR vec<L, T> abs(const vec<L, T> &v) {
		SMATH_STATIC_ASSERT(smath::is_integer_type<T>::value || smath::is_floating_type<T>::value, "'abs' only accepts integer or floating-point inputs");
		SMATH_STATIC_ASSERT(smath::is_valid_vector(L), "'abs' only works on vectors with 1 to 4 components");
		return function::one<vec, L, T, T>::apply(::std::abs, v);
	}

	/**
	 * @brief Rounds a number to the nearest integer.
	 * @tparam T The type of number (int, float, double)
	 * @returns A number that is closest to the given input number.
	 */
	template<class T>
	SMATH_CONSTEXPR T round(const T &a) {
		SMATH_STATIC_ASSERT(smath::is_integer_type<T>::value || smath::is_floating_type<T>::value, "'round' only accepts integer or floating-point inputs");
		return static_cast<T>(static_cast<int>(a + 0.5));
	}

	/**
	 * @brief Rounds each component of a vector to the nearest whole number.
	 * @tparam L The number of components in the vector in range [1, 4]
	 * @tparam T The type of the vector (int, float, double)
	 * @returns A vector of length `L` and type `T` with each component rounded
	 * to the nearest whole number.
	 */
	template<length_t L, class T>
	SMATH_CONSTEXPR vec<L, T> round(const vec<L, T> &v) {
		SMATH_STATIC_ASSERT(smath::is_integer_type<T>::value || smath::is_floating_type<T>::value, "'round' only accepts integer or floating-point inputs");
		SMATH_STATIC_ASSERT(smath::is_valid_vector(L), "'round' only works on vectors with 1 to 4 components");
		return function::one<vec, L, T, T>::apply(::std::round, v);
	}

	/**
	 * @brief Rounds a number to the nearest multiple of the `nearest` input parameter.
	 * @tparam T The type of number to round.
	 * @param a The number to round.
	 * @param nearest The number to round up or down to.
	 * @returns The input rounded to the nearest multiple of the input parameter.
	 */
	template<class T>
	SMATH_CONSTEXPR T round_nearest(const T &a, const int &nearest) {
		SMATH_STATIC_ASSERT(smath::is_integer_type<T>::value || smath::is_floating_type<T>::value, "'round_nearest' only accept integers or floating-point inputs");
		return static_cast<T>(static_cast<int>(smath::round(static_cast<double>(a) / nearest) * nearest));
	}

	/**
	 * @brief Rounds the input number downwards, effectively removing the decimal
	 * point if it exists.
	 * @tparam T The type of number (int, float, double)
	 * @returns A number that has been rounded down.
	 */
	template<class T>
	SMATH_CONSTEXPR T floor(const T &a) {
		SMATH_STATIC_ASSERT(smath::is_integer_type<T>::value || smath::is_floating_type<T>::value, "'floor' only accepts integer or floating-point inputs");
		if (smath::is_integer_type<T>::value) {
			return a;
		}
		return static_cast<T>(static_cast<int>((a > 0) ? a : a - 1));
	}

	/**
	 * @brief Rounds each component of a vector downwards.
	 * @tparam L The number of components in the vector in range [1, 4]
	 * @tparam T The type of the vector (int, float, double)
	 * @returns A vector of length `L` and type `T` with each component rounded down.
	 */
	template<length_t L, class T>
	SMATH_CONSTEXPR vec<L, T> floor(const vec<L, T> &v) {
		SMATH_STATIC_ASSERT(smath::is_integer_type<T>::value || smath::is_floating_type<T>::value, "'floor' only accepts integer or floating-point inputs");
		SMATH_STATIC_ASSERT(smath::is_valid_vector(L), "'floor' only works on vectors with 1 to 4 components");
		return function::one<vec, L, T, T>::apply(::std::floor, v);
	}

	/**
	 * @brief Rounds the input number upwards.
	 * @tparam T The type of number (int, float, double)
	 * @returns A number that has been rounded upwards.
	 */
	template<class T>
	SMATH_CONSTEXPR T ceil(const T &a) {
		SMATH_STATIC_ASSERT(smath::is_integer_type<T>::value || smath::is_floating_type<T>::value, "'ceil' only accepts integer or floating-point inputs");
		if (smath::is_integer_type<T>::value) {
			return a;
		}
		return static_cast<T>(static_cast<int>((a > 0) ? a + 1 : a));
	}

	/**
	 * @brief Rounds each component of a vector upwards.
	 * @tparam L The number of components in the vector in range [1, 4]
	 * @tparam T The type of the vector (int, float, double)
	 * @returns A vector of length `L` and type `T` with each component rounded up.
	 */
	template<length_t L, class T>
	SMATH_CONSTEXPR vec<L, T> ceil(const vec<L, T> &v) {
		SMATH_STATIC_ASSERT(smath::is_integer_type<T>::value || smath::is_floating_type<T>::value, "'ceil' only accepts integer or floating-point inputs");
		SMATH_STATIC_ASSERT(smath::is_valid_vector(L), "'ceil' only works on vectors with 1 to 4 components");
		return function::one<vec, L, T, T>::apply(::std::ceil, v);
	}

	/**
	 * @brief Scales the input value `x` from range [a, b] to range [c, d].
	 * Credit: https://stats.stackexchange.com/a/281165.
	 * @param x The input value to scale.
	 * @param a The minimum of the original range.
	 * @param b The maximum of the original range.
	 * @param c The new minimum of the range to scale to.
	 * @param d The new maximum of the range to scale to.
	 * @returns A scaled value in the range [c, d].
	 */
	template<class T>
	SMATH_CONSTEXPR T scale(const T &x, const T &a, const T &b, const T &c, const T &d) {
		SMATH_STATIC_ASSERT(smath::is_integer_type<T>::value || smath::is_floating_type<T>::value, "'scale' only accepts integer or floating-point inputs");
		if (smath::is_integer_type<T>::value) {
			return smath::round((d - c) * ((x - a) / static_cast<float>(b - a)) + c);
		}
		return (d - c) * ((x - a) / (b - a)) + c;
	}

} // namespace smath

#endif // MATH_H
