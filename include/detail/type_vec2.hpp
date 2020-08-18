#pragma once

#ifndef DETAIL_TYPE_VEC2_H
#define DETAIL_TYPE_VEC2_H

#include "qualifier.hpp"

namespace smath {

	template<class T>
	struct vec<2, T> {

		// -- Components --

		T x;
		T y;

		/**
		 * @returns The number of components that the vector contains.
		 */
		static constexpr int length() {
			return 2;
		}

		// -- Constructors --

		/**
		 * Default constructor for a 2-component vector.
		 */
		constexpr vec();

		/**
		 * Constructor to initialize a vector to a single scalar.
		 * @tparam T The type of the vector.
		 * @param scalar The scalar value to initialize the vector to.
		 */
		constexpr vec(T scalar);

		/**
		 * Constructor to initialize each component in the vector.
		 * @tparam T The type of the vector.
		 * @param _x The x component of the vector.
		 * @param _y The y component of the vector.
		 */
		constexpr vec(T _x, T _y);

		/**
		 * Constructor to initialize each component in the vector using
		 * different parameter types.
		 * @tparam A Some data type that is not the same base data type.
		 * @tparam B Some data type that is not the same base data type.
		 * @param _x The x component of the vector.
		 * @param _y The y component of the vector.
		 */
		template<class A, class B>
		constexpr vec(A _x, B _y);

		/**
		 * Constructor to initialize a vector to another vector.
		 * @param v The vector initialize to.
		 */
		constexpr vec(const vec<2, T> &v);

		/**
		 * Constructor to initialize a vector to a vector from another type.
		 * @tparam A Some data type that is not the same as the base data type.
		 * @param v The vector of a different type.
		 */
		template<class A>
		constexpr vec(const vec<2, A> &v);

		// -- Element accesses --

		constexpr T& operator[](int i);
		constexpr const T& operator[](int i) const;

		// -- Unary arithmetic operators --

		template<class A>
		constexpr vec<2, T>& operator=(const vec<2, A> &v);

		template<class A>
		constexpr vec<2, T>& operator+=(A scalar);
		template<class A>
		constexpr vec<2, T>& operator+=(const vec<2, A> &v);

		template<class A>
		constexpr vec<2, T>& operator-=(A scalar);
		template<class A>
		constexpr vec<2, T>& operator-=(const vec<2, A> &v);

		template<class A>
		constexpr vec<2, T>& operator*=(A scalar);
		template<class A>
		constexpr vec<2, T>& operator*=(const vec<2, A> &v);

		template<class A>
		constexpr vec<2, T>& operator/=(A scalar);
		template<class A>
		constexpr vec<2, T>& operator/=(const vec<2, A> &v);

		// -- Unary bit operators --

		template<class A>
		constexpr vec<2, T>& operator%=(A scalar);
		template<class A>
		constexpr vec<2, T>& operator%=(const vec<2, A> &v);

		template<class A>
		constexpr vec<2, T>& operator&=(A scalar);
		template<class A>
		constexpr vec<2, T>& operator&=(const vec<2, A> &v);

		template<class A>
		constexpr vec<2, T>& operator|=(A scalar);
		template<class A>
		constexpr vec<2, T>& operator|=(const vec<2, A> &v);

		template<class A>
		constexpr vec<2, T>& operator^=(A scalar);
		template<class A>
		constexpr vec<2, T>& operator^=(const vec<2, A> &v);

		template<class A>
		constexpr vec<2, T>& operator<<=(A scalar);
		template<class A>
		constexpr vec<2, T>& operator<<=(const vec<2, A> &v);

		template<class A>
		constexpr vec<2, T>& operator>>=(A scalar);
		template<class A>
		constexpr vec<2, T>& operator>>=(const vec<2, A> &v);

		// -- Increment and decrement operators --

		constexpr vec<2, T>& operator++();
		constexpr vec<2, T> operator++(int);

		constexpr vec<2, T>& operator--();
		constexpr vec<2, T> operator--(int);

	};

	// -- Unary arithmetic operators --

	template<class T>
	constexpr vec<2, T> operator+(const vec<2, T> &v);

	template<class T>
	constexpr vec<2, T> operator-(const vec<2, T> &v);

	// -- Binary arithmetic operators --

	template<class T>
	constexpr vec<2, T> operator+(const vec<2, T> &v, T scalar);
	template<class T>
	constexpr vec<2, T> operator+(T scalar, const vec<2, T> &v);
	template<class T>
	constexpr vec<2, T> operator+(const vec<2, T> &v1, const vec<2, T> &v2);

	template<class T>
	constexpr vec<2, T> operator-(const vec<2, T> &v, T scalar);
	template<class T>
	constexpr vec<2, T> operator-(T scalar, const vec<2, T> &v);
	template<class T>
	constexpr vec<2, T> operator-(const vec<2, T> &v1, const vec<2, T> &v2);

	template<class T>
	constexpr vec<2, T> operator*(const vec<2, T> &v, T scalar);
	template<class T>
	constexpr vec<2, T> operator*(T scalar, const vec<2, T> &v);
	template<class T>
	constexpr vec<2, T> operator*(const vec<2, T> &v1, const vec<2, T> &v2);

	template<class T>
	constexpr vec<2, T> operator/(const vec<2, T> &v, T scalar);
	template<class T>
	constexpr vec<2, T> operator/(T scalar, const vec<2, T> &v);
	template<class T>
	constexpr vec<2, T> operator/(const vec<2, T> &v1, const vec<2, T> &v2);

	template<class T>
	constexpr vec<2, T> operator%(const vec<2, T> &v, T scalar);
	template<class T>
	constexpr vec<2, T> operator%(T scalar, const vec<2, T> &v);
	template<class T>
	constexpr vec<2, T> operator%(const vec<2, T> &v1, const vec<2, T> &v2);

	// -- Bitwise arithmetic operators --

	template<class T>
	constexpr vec<2, T> operator&(const vec<2, T> &v, T scalar);
	template<class T>
	constexpr vec<2, T> operator&(T scalar, const vec<2, T> &v);
	template<class T>
	constexpr vec<2, T> operator&(const vec<2, T> &v1, const vec<2, T> &v2);

	template<class T>
	constexpr vec<2, T> operator|(const vec<2, T> &v, T scalar);
	template<class T>
	constexpr vec<2, T> operator|(T scalar, const vec<2, T> &v);
	template<class T>
	constexpr vec<2, T> operator|(const vec<2, T> &v1, const vec<2, T> &v2);

	template<class T>
	constexpr vec<2, T> operator^(const vec<2, T> &v, T scalar);
	template<class T>
	constexpr vec<2, T> operator^(T scalar, const vec<2, T> &v);
	template<class T>
	constexpr vec<2, T> operator^(const vec<2, T> &v1, const vec<2, T> &v2);

	template<class T>
	constexpr vec<2, T> operator<<(const vec<2, T> &v, T scalar);
	template<class T>
	constexpr vec<2, T> operator<<(T scalar, const vec<2, T> &v);
	template<class T>
	constexpr vec<2, T> operator<<(const vec<2, T> &v1, const vec<2, T> &v2);

	template<class T>
	constexpr vec<2, T> operator>>(const vec<2, T> &v, T scalar);
	template<class T>
	constexpr vec<2, T> operator>>(T scalar, const vec<2, T> &v);
	template<class T>
	constexpr vec<2, T> operator>>(const vec<2, T> &v1, const vec<2, T> &v2);

	template<class T>
	constexpr vec<2, T> operator~(const vec<2, T> &v);

	// -- Boolean operators --

	template<class T>
	constexpr bool operator==(const vec<2, T> &v1, const vec<2, T> &v2);
	template<class T>
	constexpr bool operator!=(const vec<2, T> &v1, const vec<2, T> &v2);

	constexpr vec<2, bool> operator&&(const vec<2, bool> &v1, const vec<2, bool> &v2);
	constexpr vec<2, bool> operator||(const vec<2, bool> &v1, const vec<2, bool> &v2);

} // namespace smath

#include "type_vec2.inl"

#endif
