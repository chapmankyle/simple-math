#pragma once

#ifndef TYPE_VEC4_H
#define TYPE_VEC4_H

#include "qualifier.hpp"

namespace smath {

	template<class T>
	struct vec<4, T> {

		// -- Components --

		T x;
		T y;
		T z;
		T w;

		/**
		 * @returns The number of components that the vector contains.
		 */
		static SMATH_CONSTEXPR int size() {
			return 4;
		}

		// -- Constructors --

		/**
		 * @brief Default constructor for a 3-component vector.
		 */
		SMATH_CONSTEXPR vec();

		/**
		 * @brief Constructor to initialize a vector to a single scalar.
		 * @tparam T The type of the vector.
		 * @param scalar The scalar value to initialize the vector to.
		 */
		SMATH_CONSTEXPR vec(T scalar);

		/**
		 * @brief Constructor to initialize each component in the vector.
		 * @tparam T The type of the vector.
		 * @param _x The x component of the vector.
		 * @param _y The y component of the vector.
		 * @param _z The z component of the vector.
		 * @param _w The w component of the vector.
		 */
		SMATH_CONSTEXPR vec(T _x, T _y, T _z, T _w);

		/**
		 * @brief Constructor to initialize each component in the vector using
		 * different parameter types.
		 * @tparam A Some data type that is not the same base data type.
		 * @tparam B Some data type that is not the same base data type.
		 * @tparam C Some data type that is not the same base data type.
		 * @tparam D Some data type that is not the same base data type.
		 * @param _x The x component of the vector.
		 * @param _y The y component of the vector.
		 * @param _z The z component of the vector.
		 */
		template<class A, class B, class C, class D>
		SMATH_CONSTEXPR vec(A _x, B _y, C _z, D _w);

		/**
		 * @brief Constructor to initialize a vector to another vector.
		 * @param v The vector initialize to.
		 */
		SMATH_CONSTEXPR vec(const vec<4, T> &v);

		/**
		 * @brief Constructor to initialize a vector to a vector from another type.
		 * @tparam A Some data type that is not the same as the base data type.
		 * @param v The vector of a different type.
		 */
		template<class A>
		SMATH_CONSTEXPR vec(const vec<4, A> &v);

		// -- Other vectors --

		/**
		 * @brief Constructor to initialize a 4-component vector to a 1-component
		 * vector.
		 * @tparam T The type of vector to create.
		 * @param v The 1-component vector to use for initialization.
		 */
		SMATH_CONSTEXPR vec(const vec<1, T> &v);

		/**
		 * @brief Constructor to initialize a 4-component vector to a 3-component
		 * vector with a scalar as the fourth component.
		 * @tparam T The type of vector to create.
		 * @param v The 3-component vector to use for initialization.
		 * @param scalar The scalar to initialize the fourth component to.
		 */
		SMATH_CONSTEXPR vec(const vec<3, T> &v, T scalar);

		// -- Element accesses --

		SMATH_CONSTEXPR T& operator[](int i);
		SMATH_CONSTEXPR const T& operator[](int i) const;

		// -- Unary arithmetic operators --

		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator=(const vec<4, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator+=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator+=(const vec<4, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator-=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator-=(const vec<4, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator*=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator*=(const vec<4, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator/=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator/=(const vec<4, A> &v);

		// -- Unary bit operators --

		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator%=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator%=(const vec<4, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator&=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator&=(const vec<4, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator|=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator|=(const vec<4, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator^=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator^=(const vec<4, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator<<=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator<<=(const vec<4, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator>>=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<4, T>& operator>>=(const vec<4, A> &v);

		// -- Increment and decrement operators --

		SMATH_CONSTEXPR vec<4, T>& operator++();
		SMATH_CONSTEXPR vec<4, T> operator++(int);

		SMATH_CONSTEXPR vec<4, T>& operator--();
		SMATH_CONSTEXPR vec<4, T> operator--(int);

	};

	// -- Unary arithmetic operators --

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator+(const vec<4, T> &v);

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator-(const vec<4, T> &v);

	// -- Binary arithmetic operators --

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator+(const vec<4, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator+(T scalar, const vec<4, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator+(const vec<4, T> &v1, const vec<4, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator-(const vec<4, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator-(T scalar, const vec<4, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator-(const vec<4, T> &v1, const vec<4, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator*(const vec<4, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator*(T scalar, const vec<4, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator*(const vec<4, T> &v1, const vec<4, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator/(const vec<4, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator/(T scalar, const vec<4, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator/(const vec<4, T> &v1, const vec<4, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator%(const vec<4, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator%(T scalar, const vec<4, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator%(const vec<4, T> &v1, const vec<4, T> &v2);

	// -- Bitwise arithmetic operators --

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator&(const vec<4, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator&(T scalar, const vec<4, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator&(const vec<4, T> &v1, const vec<4, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator|(const vec<4, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator|(T scalar, const vec<4, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator|(const vec<4, T> &v1, const vec<4, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator^(const vec<4, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator^(T scalar, const vec<4, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator^(const vec<4, T> &v1, const vec<4, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator<<(const vec<4, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator<<(T scalar, const vec<4, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator<<(const vec<4, T> &v1, const vec<4, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator>>(const vec<4, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator>>(T scalar, const vec<4, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator>>(const vec<4, T> &v1, const vec<4, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator~(const vec<4, T> &v);

	// -- Boolean operators --

	template<class T>
	SMATH_CONSTEXPR bool operator==(const vec<4, T> &v1, const vec<4, T> &v2);
	template<class T>
	SMATH_CONSTEXPR bool operator!=(const vec<4, T> &v1, const vec<4, T> &v2);

	SMATH_CONSTEXPR vec<4, bool> operator&&(const vec<4, bool> &v1, const vec<4, bool> &v2);
	SMATH_CONSTEXPR vec<4, bool> operator||(const vec<4, bool> &v1, const vec<4, bool> &v2);

	// -- Output stream --

	template<class T>
	SMATH_CONSTEXPR std::ostream& operator<<(std::ostream &out, const vec<4, T> &v);

} // namespace smath

#include "type_vec4.inl"

#endif // TYPE_VEC4_H
