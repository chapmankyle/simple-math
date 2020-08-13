#pragma once
#ifndef INCLUDE_MATH_H

#include <cstdint>

namespace smath {

	// math constants

	inline constexpr double e{ 2.7182818284590452354 };
	inline constexpr double pi{ 3.1415926535897932385 };

	/**
	 * @brief Calculates the maximum between two types, comparable by operator<
	 * @returns The larger of the two provided types.
	 */
	template<class T> constexpr const T& max(const T &a, const T &b) {
		return (a < b) ? b : a;
	}

	/**
	 * @brief Calculates the minimum between two types, comparable by operator<
	 * @returns The smaller of the two provided types.
	 */
	template<class T> constexpr const T& min(const T &a, const T &b) {
		return (a < b) ? a : b;
	}

	/**
	 * @returns The absolute value of the given type.
	 */
	template<class T> constexpr const T& abs(const T& a) {
		return a >= 0 ? a : -a;
	}

	/**
	 * @brief Performs the square root of a floating-point number, using the
	 * fast, inverse square root method.
	 *
	 * Credit to https://cs.uwaterloo.ca/~m32rober/rsqrt.pdf
	 *
	 * @returns The square root of the provided floating-point number.
	 */
	inline constexpr double sqrt(const double &a) {
		constexpr double threehalfs{ 1.5 };

		double y{ a };
		double x{ y * 0.5 };

		std::uint_fast64_t i = *(std::uint_fast64_t *) &y;
		i = 0x5fe6eb50c7b537a9 - (i >> 1);
		y = *(double *) &i;
		y = y * (threehalfs - (x * y * y));
		y = y * (threehalfs - (x * y * y));
		return 1.0 / y;
	}

} // namespace smath

#endif // INCLUDE_MATH_H
