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
	 * @brief Calculates the minimum between two types, comparable by operator<
	 * @returns The smaller of the two provided types.
	 */
	template<class T> constexpr const T& min(const T &a, const T &b) {
		return (a < b) ? a : b;
	}

	/**
	 * @returns The absolute value of the given type.
	 */
	template<class T> constexpr const T& abs(const T &a) {
		return a >= 0 ? a : -a;
	}

} // namespace smath

#endif // MATH_H
