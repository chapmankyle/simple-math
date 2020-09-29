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

		/**
		 * @brief Default constructor to zero-initialize a matrix.
		 */
		SMATH_CONSTEXPR mat();

		/**
		 * @brief Initialize a matrix to the content of another matrix.
		 * @param m The matrix to initialize to.
		 */
		SMATH_CONSTEXPR mat(const mat<2, 2, T> &m);

		/**
		 * @brief Initialize a matrix to the content of another matrix.
		 * @tparam A The type of the matrix given.
		 * @param m The matrix to initialize to.
		 */
		template<class A>
		SMATH_CONSTEXPR mat(const mat<2, 2, A> &m);

		/**
		 * @brief Initialize each value in matrix to a scalar value.
		 * @param scalar The scalar to initialize the matrix contents to.
		 */
		explicit SMATH_CONSTEXPR mat(T scalar);

		SMATH_CONSTEXPR mat(const T &x1, const T &y1, const T &x2, const T &y2);
		SMATH_CONSTEXPR mat(const row_t &r1, const row_t &r2);

		template<class A, class B, class C, class D>
		SMATH_CONSTEXPR mat(const A &x1, const B &y1, const C &x2, const D &y2);
		template<class A, class B>
		SMATH_CONSTEXPR mat(const vec<2, A> &r1, const vec<2, B> &r2);

		// -- Element accesses --

		SMATH_CONSTEXPR row_t& operator[](length_t i);
		SMATH_CONSTEXPR const row_t& operator[](length_t i) const;

		// -- Unary arithmetic operators --

		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator=(const mat<2, 2, A> &m);

		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator+=(A scalar);
		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator+=(const mat<2, 2, A> &m);

		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator-=(A scalar);
		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator-=(const mat<2, 2, A> &m);

		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator*=(A scalar);
		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator*=(const mat<2, 2, A> &m);

		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator/=(A scalar);
		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator/=(const mat<2, 2, A> &m);

		// -- Unary bit operators --

		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator%=(A scalar);
		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator%=(const mat<2, 2, A> &m);

		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator&=(A scalar);
		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator&=(const mat<2, 2, A> &m);

		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator|=(A scalar);
		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator|=(const mat<2, 2, A> &m);

		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator^=(A scalar);
		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator^=(const mat<2, 2, A> &m);

		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator<<=(A scalar);
		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator<<=(const mat<2, 2, A> &m);

		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator>>=(A scalar);
		template<class A>
		SMATH_CONSTEXPR mat<2, 2, T>& operator>>=(const mat<2, 2, A> &m);

		// -- Increment and decrement operators --

		SMATH_CONSTEXPR mat<2, 2, T>& operator++();
		SMATH_CONSTEXPR mat<2, 2, T> operator++(int);

		SMATH_CONSTEXPR mat<2, 2, T>& operator--();
		SMATH_CONSTEXPR mat<2, 2, T> operator--(int);

	};

	// -- Unary arithmetic operators --

	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T> operator+(const mat<2, 2, T> &m);

	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T> operator-(const mat<2, 2, T> &m);

	// -- Binary arithmetic operators --

	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T> operator+(const mat<2, 2, T> &m, T scalar);
	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T> operator+(T scalar, const mat<2, 2, T> &m);
	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T> operator+(const mat<2, 2, T> &m1, const mat<2, 2, T> &m2);

	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T> operator-(const mat<2, 2, T> &m, T scalar);
	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T> operator-(T scalar, const mat<2, 2, T> &m);
	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T> operator-(const mat<2, 2, T> &m1, const mat<2, 2, T> &m2);

	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T> operator*(const mat<2, 2, T> &m, T scalar);
	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T> operator*(T scalar, const mat<2, 2, T> &m);
	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T> operator*(const mat<2, 2, T> &m1, const mat<2, 2, T> &m2);

	template<class T>
	SMATH_CONSTEXPR typename mat<2, 2, T>::col_t operator*(
		const mat<2, 2, T> &m,
		const typename mat<2, 2, T>::col_t &v
	);
	template<class T>
	SMATH_CONSTEXPR typename mat<2, 2, T>::row_t operator*(
		const typename mat<2, 2, T>::row_t &v,
		const mat<2, 2, T> &m
	);

	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T> operator/(const mat<2, 2, T> &m, T scalar);
	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T> operator/(T scalar, const mat<2, 2, T> &m);

	// -- Boolean operators --

	template<class T>
	SMATH_CONSTEXPR bool operator==(const mat<2, 2, T> &m1, const mat<2, 2, T> &m2);
	template<class T>
	SMATH_CONSTEXPR bool operator!=(const mat<2, 2, T> &m1, const mat<2, 2, T> &m2);

	// -- Output stream --

	template<class T>
	SMATH_CONSTEXPR std::ostream& operator<<(std::ostream &out, const mat<2, 2, T> &m);
}

#include "type_mat2x2.inl"

#endif // TYPE_MAT2x2_H