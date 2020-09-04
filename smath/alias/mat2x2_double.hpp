#pragma once

#ifndef ALIAS_MAT2x2_DOUBLE_H
#define ALIAS_MAT2x2_DOUBLE_H

#include "../types/type_mat2x2.hpp"

namespace smath {

	// Double precision floating-point matrix with 2 rows and 2 columns.
	using mat2x2d = mat<2, 2, double>;

	using mat2d = mat2x2d;

} // namespace smath

#endif // ALIAS_MAT2x2_DOUBLE_H
