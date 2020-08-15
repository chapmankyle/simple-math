#pragma once

#ifndef EXPONENTIAL_H
#define EXPONENTIAL_H

#include <cstdint>

#include "constants.hpp"
#include "template_types.hpp"

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
	inline constexpr float inv_sqrt(const float &a) {
		float y{ a };
		float x{ y * 0.5f };

		std::uint_fast32_t i = *(std::uint_fast32_t *) &y;
		i = 0x5f375a86 - (i >> 1);
		y = *(float *) &i;
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
	inline constexpr double inv_sqrt(const double &a) {
		double y{ a };
		double x{ y * 0.5 };

		std::uint_fast64_t i = *(std::uint_fast64_t *) &y;
		i = 0x5fe6eb50c7b537a9 - (i >> 1);
		y = *(double *) &i;
		y = y * (1.5 - (x * y * y));
		return y;
	}

	/**
	 * @brief Performs the square root of a floating-point number, using the
	 * fast, inverse square root method.
	 * @returns The square root of the floating-point input number.
	 */
	template<class T>
	constexpr const T sqrt(const T &a) {
		static_assert(smath::is_floating_type<T>::value, "'sqrt' only accepts floating-point inputs");
		if (a == static_cast<T>(2.0)) {
			return static_cast<T>(smath::SQRT2);
		}
		return static_cast<T>(1.0) / inv_sqrt(a);
	}

} // namespace smath

#endif
