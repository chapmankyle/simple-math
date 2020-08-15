#pragma once

#ifndef MATH_H
#define MATH_H

namespace smath {

	/**
	 * @brief Calculates the maximum between two types, comparable by operator<
	 * @returns The larger of the two provided types.
	 */
	template<class T> constexpr const T& max(const T &a, const T &b) {
		return (a < b) ? b : a;
	}

	/**
	 * @brief Calculates the maximum between three types, comparable by operator<
	 * @returns The larger of the three provided types.
	 */
	template<class T> constexpr const T& max(const T &a, const T &b, const T &c) {
		return smath::max(a, smath::max(b, c));
	}

	/**
	 * @brief Calculates the minimum between two types, comparable by operator<
	 * @returns The smaller of the two provided types.
	 */
	template<class T> constexpr const T& min(const T &a, const T &b) {
		return (a < b) ? a : b;
	}

	/**
	 * @brief Calculates the minimum between three types, comparable by operator<
	 * @returns The smaller of the three provided types.
	 */
	template<class T> constexpr const T& min(const T &a, const T &b, const T &c) {
		return smath::min(a, smath::min(b, c));
	}

	/**
	 * @brief Calculates the absolute value of the given type.
	 *
	 * `abs(x) = x if x >=0, or -x if x < 0`
	 *
	 * @returns The absolute value of the given type.
	 */
	template<class T> constexpr const T abs(const T &a) {
		return a >= 0 ? a : -a;
	}

} // namespace smath

#endif // MATH_H
