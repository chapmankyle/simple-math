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

		using row_t    = vec<m_cols, T>;
		using column_t = vec<m_rows, T>;

		using matrix_t    = mat<m_rows, m_cols, T>;
		using transpose_t = mat<m_cols, m_rows, T>;

		using value_t = T;

	private:

		// values in matrix stored as array of vectors
		row_t values[m_length];

	public:

		/**
		 * @returns The number of columns that the matrix has.
		 */
		static SMATH_CONSTEXPR length_t length() {
			return m_length;
		}

		// -- Constructors --

		SMATH_CONSTEXPR mat();

		template<>
		SMATH_CONSTEXPR mat(const mat<2, 2, T> &m);

		explicit SMATH_CONSTEXPR mat(T scalar);
		SMATH_CONSTEXPR mat(const T &x1, const T &y1, const T &x2, const T &y2);
		SMATH_CONSTEXPR mat(const row_t &v1, const row_t &v2);

		// -- Element accesses --

		SMATH_CONSTEXPR row_t& operator[](length_t i);
		SMATH_CONSTEXPR const row_t& operator[](length_t i) const;

	};
}

#endif // TYPE_MAT2x2_H
