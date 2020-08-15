#pragma once

#ifndef TRIGONOMETRY_H
#define TRIGONOMETRY_H

#include "constants.hpp"
#include "template_types.hpp"

namespace smath {

	/**
	 * @brief Converts a number from degrees to radians.
	 * @returns The number in terms of radians.
	 */
	template<class T>
	constexpr const T to_radians(const T &degrees) {
		static_assert(smath::is_floating_type<T>::value, "'to_radians' only accepts floating-point inputs");
		return degrees * static_cast<T>(smath::RAD);
	}

	/**
	 * @brief Converts a number from radians to degrees.
	 * @returns The number in terms of degrees.
	 */
	template<class T>
	constexpr const T to_degrees(const T &radians) {
		static_assert(smath::is_floating_type<T>::value, "'to_degrees' only accepts floating-point inputs");
		return radians * static_cast<T>(smath::DEG);
	}

} // namespace smath

#endif
