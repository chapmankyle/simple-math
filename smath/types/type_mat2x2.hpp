#pragma once

#ifndef TYPE_MAT2x2_H
#define TYPE_MAT2x2_H

#include "type_vec2.hpp"

namespace smath {

	template<class T>
	class mat<2, 2, T> {

	// Default class access specifier is private

	static SMATH_CONSTEXPR length_t m_rows{ 2 };
	static SMATH_CONSTEXPR length_t m_cols{ 2 };
	static SMATH_CONSTEXPR length_t m_length{ m_cols };

	public:
		// -- Useful type definitions --

		using row_t = vec<m_cols, T>;
		using column_t = vec<m_rows, T>;

		using matrix_t = mat<2, 2, T>;
		using transpose_t = mat<2, 2, T>;
		using value_t = T;

	private:

		// store vectors
		row_t values[m_length];

	};
}

#endif // TYPE_MAT2x2_H
