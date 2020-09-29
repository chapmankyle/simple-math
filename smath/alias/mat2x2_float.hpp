#pragma once

#ifndef ALIAS_MAT2x2_FLOAT_H
#define ALIAS_MAT2x2_FLOAT_H

#include "../types/type_mat2x2.hpp"

namespace smath {

	// Single precision floating-point matrix with 2 rows and 2 columns.
	using mat2x2 = mat<2, 2, float>;

	using mat2 = mat2x2;

} // namespace smath

#endif // ALIAS_MAT2x2_FLOAT_H
