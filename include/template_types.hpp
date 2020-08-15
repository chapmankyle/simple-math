#pragma once

#ifndef TEMPLATE_TYPES_H
#define TEMPLATE_TYPES_H

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
	struct is_floating_type<char> {
		static const bool value = false;
	};

} // namespace smath

#endif
