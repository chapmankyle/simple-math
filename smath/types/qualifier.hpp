#pragma once

#ifndef QUALIFIER_H
#define QUALIFIER_H

#include <cassert>
#include <iostream>

#include "../detail/setup.hpp"

namespace smath {

	// ---------------
	// --- vectors ---
	// ---------------

	// Supports:
	// - 2 components (x, y)
	// - 3 components (x, y, z)
	// - 4 components (x, y, z, w)

	/**
	 * General vector of arbitrary length and type.
	 * @tparam L The length of the vector, in range [1, 4]
	 * @tparam T The type of data to store in the vector (bool, int, float or double)
	 */
	template<length_t L, class T> struct vec;

} // namespace smath

#endif // QUALIFIER_H
