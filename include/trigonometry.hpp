#pragma once

#ifndef TRIGONOMETRY_H
#define TRIGONOMETRY_H

#include "detail/setup.hpp"
#include "detail/function.hpp"

#include "constants.hpp"
#include "template_types.hpp"

namespace smath {

	/**
	 * @brief Converts a number from degrees to radians.
	 * @returns The number in terms of radians.
	 */
	template<class T>
	SMATH_INLINE SMATH_CONSTEXPR T radians(T degrees) {
		SMATH_STATIC_ASSERT(smath::is_floating_type<T>::value, "'radians' only accepts floating-point inputs");
		return degrees * static_cast<T>(smath::constants::RAD);
	}

	/**
	 * @brief Converts each component in a vector to radians.
	 * @returns A vector with each component converted to radians.
	 */
	template<length_t L, class T>
	SMATH_INLINE SMATH_CONSTEXPR vec<L, T> radians(const vec<L, T> &v) {
		return function::one<vec, L, T, T>::apply(radians, v);
	}

	/**
	 * @brief Converts a number from radians to degrees.
	 * @returns The number in terms of degrees.
	 */
	template<class T>
	SMATH_INLINE SMATH_CONSTEXPR T degrees(T radians) {
		SMATH_STATIC_ASSERT(smath::is_floating_type<T>::value, "'degrees' only accepts floating-point inputs");
		return radians * static_cast<T>(smath::constants::DEG);
	}

	/**
	 * @brief Converts each component in a vector to degrees.
	 * @returns A vector with each component converted to degrees.
	 */
	template<length_t L, class T>
	SMATH_INLINE SMATH_CONSTEXPR vec<L, T> degrees(const vec<L, T> &v) {
		return function::one<vec, L, T, T>::apply(degrees, v);
	}

} // namespace smath

#endif // TRIGONOMETRY_H
