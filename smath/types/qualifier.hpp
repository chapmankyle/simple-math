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
	 * General vector class of arbitrary length and type.
	 * @tparam L The length of the vector, in range [1, 4]
	 * @tparam T The type of data to store in the vector (bool, int, float or double)
	 */
	template<length_t L, class T> class vec;

	// ----------------
	// --- matrices ---
	// ----------------

	// Supports:
	// - N x N, where N in range [2, 4]
	// - M x N, where M and N in range [2, 4]

	/**
	 * General matrix class of arbitrary number of rows, columns and type.
	 * @tparam R The number of rows, in range [2,4]
	 * @tparam C The number of columns, in range [2,4]
	 * @tparam T The type of data to store in the matrix (int, float or double)
	 */
	template<length_t R, length_t C, class T> class mat;

} // namespace smath

#endif // QUALIFIER_H
