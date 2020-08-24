#pragma once

#ifndef TYPE_VEC1_H
#define TYPE_VEC1_H

#include "qualifier.hpp"

namespace smath {

	template<class T>
	struct vec<1, T> {

		// -- Components --

		T x;

		/**
		 * @returns The number of components that the vector contains.
		 */
		static SMATH_CONSTEXPR int size() {
			return 1;
		}

		// -- Constructors --

		/**
		 * Default constructor for a 1-component vector.
		 */
		SMATH_CONSTEXPR vec();

		/**
		 * Constructor to initialize a vector to a single scalar.
		 * @tparam T The type of the vector.
		 * @param scalar The scalar value to initialize the vector to.
		 */
		SMATH_CONSTEXPR vec(T scalar);

		/**
		 * Constructor to initialize each component in the vector using
		 * different parameter types.
		 * @tparam A Some data type that is not the same base data type.
		 * @param _x The x component of the vector.
		 */
		template<class A>
		SMATH_CONSTEXPR vec(A _x);

		/**
		 * Constructor to initialize a vector to another vector.
		 * @param v The vector initialize to.
		 */
		SMATH_CONSTEXPR vec(const vec<1, T> &v);

		/**
		 * Constructor to initialize a vector to a vector from another type.
		 * @tparam A Some data type that is not the same as the base data type.
		 * @param v The vector of a different type.
		 */
		template<class A>
		SMATH_CONSTEXPR vec(const vec<1, A> &v);

		// -- Element accesses --

		SMATH_CONSTEXPR T& operator[](int i);
		SMATH_CONSTEXPR const T& operator[](int i) const;

		// -- Unary arithmetic operators --

		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator=(const vec<1, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator+=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator+=(const vec<1, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator-=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator-=(const vec<1, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator*=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator*=(const vec<1, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator/=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator/=(const vec<1, A> &v);

		// -- Unary bit operators --

		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator%=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator%=(const vec<1, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator&=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator&=(const vec<1, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator|=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator|=(const vec<1, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator^=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator^=(const vec<1, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator<<=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator<<=(const vec<1, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator>>=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<1, T>& operator>>=(const vec<1, A> &v);

		// -- Increment and decrement operators --

		SMATH_CONSTEXPR vec<1, T>& operator++();
		SMATH_CONSTEXPR vec<1, T> operator++(int);

		SMATH_CONSTEXPR vec<1, T>& operator--();
		SMATH_CONSTEXPR vec<1, T> operator--(int);

	};

	// -- Unary arithmetic operators --

	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator+(const vec<1, T> &v);

	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator-(const vec<1, T> &v);

	// -- Binary arithmetic operators --

	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator+(const vec<1, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator+(T scalar, const vec<1, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator+(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator-(const vec<1, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator-(T scalar, const vec<1, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator-(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator*(const vec<1, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator*(T scalar, const vec<1, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator*(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator/(const vec<1, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator/(T scalar, const vec<1, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator/(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator%(const vec<1, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator%(T scalar, const vec<1, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator%(const vec<1, T> &v1, const vec<1, T> &v2);

	// -- Bitwise arithmetic operators --

	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator&(const vec<1, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator&(T scalar, const vec<1, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator&(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator|(const vec<1, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator|(T scalar, const vec<1, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator|(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator^(const vec<1, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator^(T scalar, const vec<1, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator^(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator<<(const vec<1, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator<<(T scalar, const vec<1, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator<<(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator>>(const vec<1, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator>>(T scalar, const vec<1, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator>>(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<1, T> operator~(const vec<1, T> &v);

	// -- Boolean operators --

	template<class T>
	SMATH_CONSTEXPR bool operator==(const vec<1, T> &v1, const vec<1, T> &v2);
	template<class T>
	SMATH_CONSTEXPR bool operator!=(const vec<1, T> &v1, const vec<1, T> &v2);

	SMATH_CONSTEXPR vec<1, bool> operator&&(const vec<1, bool> &v1, const vec<1, bool> &v2);
	SMATH_CONSTEXPR vec<1, bool> operator||(const vec<1, bool> &v1, const vec<1, bool> &v2);

} // namespace smath

#include "type_vec1.inl"

#endif
