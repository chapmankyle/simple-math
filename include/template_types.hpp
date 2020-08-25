#pragma once

#ifndef TEMPLATE_TYPES_H
#define TEMPLATE_TYPES_H

#include "setup/setup.hpp"

namespace smath {

	/**
	 * Used to check for integer types.
	 * @tparam T Type to check if integer.
	 */
	template <class T>
	struct is_integer_type { };

	template<>
	struct is_integer_type<int> {
		static const bool value = true;
	};

	template<>
	struct is_integer_type<bool> {
		static const bool value = false;
	};

	template<>
	struct is_integer_type<char> {
		static const bool value = false;
	};

	template<>
	struct is_integer_type<double> {
		static const bool value = false;
	};

	template<>
	struct is_integer_type<float> {
		static const bool value = false;
	};

	/**
	 * Used to check for floating-point types.
	 * @tparam T Type to check if floating-point.
	 */
	template <class T>
	struct is_floating_type { };

	template<>
	struct is_floating_type<float> {
		static const bool value = true;
	};

	template<>
	struct is_floating_type<double> {
		static const bool value = true;
	};

	template<>
	struct is_floating_type<int> {
		static const bool value = false;
	};

	template<>
	struct is_floating_type<bool> {
		static const bool value = false;
	};

	template<>
	struct is_floating_type<char> {
		static const bool value = false;
	};

	/**
	 * Used to check if a vector has a valid length.
	 * @param L The length of the vector.
	 */
	SMATH_CONSTEXPR bool is_valid_vector(int L) {
		return L >= 1 && L <= 4;
	}

} // namespace smath

#endif
