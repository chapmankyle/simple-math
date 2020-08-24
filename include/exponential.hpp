#pragma once

#ifndef EXPONENTIAL_H
#define EXPONENTIAL_H

#include <cmath>
#include <cstdint>

#include "setup/setup.hpp"
#include "types/function.hpp"

#include "template_types.hpp"

#include "types/type_vec1.hpp"
#include "types/type_vec2.hpp"
#include "types/type_vec3.hpp"

namespace smath {

	/**
	 * @brief Performs the fast, inverse square root of a floating-point number
	 * with 7 digits of precision.
	 *
	 * Credit to Quake III: Arena for first implementation of the fast, inverse
	 * square root.
	 *
	 * @returns The inverse square root of a given floating-point number, up
	 * to 7 digits of precision.
	 */
	SMATH_CONSTEXPR float inv_sqrt(const float &a) {
		float y{ a };
		float x{ y * 0.5f };

		std::uint_fast32_t i = *(std::uint_fast32_t *) &y;
		i = 0x5f375a86 - (i >> 1);
		y = *(float *) &i;
		y = y * (1.5f - (x * y * y));
		y = y * (1.5f - (x * y * y));
		return y;
	}

	/**
	 * @brief Performs the fast, inverse square root of a floating-point number
	 * with 15 digits of precision.
	 *
	 * Credit to https://cs.uwaterloo.ca/~m32rober/rsqrt.pdf for the extension
	 * of the fast, inverse square root to work with higher precision.
	 *
	 * @returns The inverse square root of a given floating-point number, up
	 * to 15 digits of precision.
	 */
	SMATH_CONSTEXPR double inv_sqrt(const double &a) {
		double y{ a };
		double x{ y * 0.5 };

		std::uint_fast64_t i = *(std::uint_fast64_t *) &y;
		i = 0x5fe6eb50c7b537a9 - (i >> 1);
		y = *(double *) &i;
		y = y * (1.5 - (x * y * y));
		y = y * (1.5 - (x * y * y));
		return y;
	}

	/**
	 * @brief Performs the square root of a floating-point number.
	 * @returns The square root of the floating-point input number.
	 */
	template<class T>
	SMATH_CONSTEXPR const T sqrt(const T &a) {
		return ::std::sqrt(a);
	}

	/**
	 * @brief Performs the square root on all of the components of a vector.
	 * @tparam L The number of components in the vector (1 <= L <= 4)
	 * @tparam T The type of the vector (bool, int, float, double)
	 * @param v The vector to apply the function to.
	 * @returns A vector containing the square root of all the components.
	 */
	template<length_t L, class T>
	SMATH_CONSTEXPR vec<L, T> sqrt(const vec<L, T> &v) {
		SMATH_STATIC_ASSERT(smath::is_integer_type<T>::value || smath::is_floating_type<T>::value, "'sqrt' only accepts an integer or floating-point vector");
		SMATH_STATIC_ASSERT(L > 0 && L < 4, "'sqrt' currently only works on vectors with 1 to 3 components");
		return function::one<vec, L, T, T>::apply(::std::sqrt, v);
	}

} // namespace smath

#endif
