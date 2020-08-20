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
		static constexpr int size() {
			return 1;
		}

		// -- Constructors --

		/**
		 * Default constructor for a 1-component vector.
		 */
		constexpr vec();

		/**
		 * Constructor to initialize a vector to a single scalar.
		 * @tparam T The type of the vector.
		 * @param scalar The scalar value to initialize the vector to.
		 */
		constexpr vec(T scalar);

		/**
		 * Constructor to initialize each component in the vector using
		 * different parameter types.
		 * @tparam A Some data type that is not the same base data type.
		 * @param _x The x component of the vector.
		 */
		template<class A>
		constexpr vec(A _x);

		/**
		 * Constructor to initialize a vector to another vector.
		 * @param v The vector initialize to.
		 */
		constexpr vec(const vec<1, T> &v);

		/**
		 * Constructor to initialize a vector to a vector from another type.
		 * @tparam A Some data type that is not the same as the base data type.
		 * @param v The vector of a different type.
		 */
		template<class A>
		constexpr vec(const vec<1, A> &v);

		// -- Element accesses --

		constexpr T& operator[](int i);
		constexpr const T& operator[](int i) const;

		// -- Unary arithmetic operators --

		template<class A>
		constexpr vec<1, T>& operator=(const vec<1, A> &v);

		template<class A>
		constexpr vec<1, T>& operator+=(A scalar);
		template<class A>
		constexpr vec<1, T>& operator+=(const vec<1, A> &v);

		template<class A>
		constexpr vec<1, T>& operator-=(A scalar);
		template<class A>
		constexpr vec<1, T>& operator-=(const vec<1, A> &v);

		template<class A>
		constexpr vec<1, T>& operator*=(A scalar);
		template<class A>
		constexpr vec<1, T>& operator*=(const vec<1, A> &v);

		template<class A>
		constexpr vec<1, T>& operator/=(A scalar);
		template<class A>
		constexpr vec<1, T>& operator/=(const vec<1, A> &v);

		// -- Unary bit operators --

		template<class A>
		constexpr vec<1, T>& operator%=(A scalar);
		template<class A>
		constexpr vec<1, T>& operator%=(const vec<1, A> &v);

		template<class A>
		constexpr vec<1, T>& operator&=(A scalar);
		template<class A>
		constexpr vec<1, T>& operator&=(const vec<1, A> &v);

		template<class A>
		constexpr vec<1, T>& operator|=(A scalar);
		template<class A>
		constexpr vec<1, T>& operator|=(const vec<1, A> &v);

		template<class A>
		constexpr vec<1, T>& operator^=(A scalar);
		template<class A>
		constexpr vec<1, T>& operator^=(const vec<1, A> &v);

		template<class A>
		constexpr vec<1, T>& operator<<=(A scalar);
		template<class A>
		constexpr vec<1, T>& operator<<=(const vec<1, A> &v);

		template<class A>
		constexpr vec<1, T>& operator>>=(A scalar);
		template<class A>
		constexpr vec<1, T>& operator>>=(const vec<1, A> &v);

		// -- Increment and decrement operators --

		constexpr vec<1, T>& operator++();
		constexpr vec<1, T> operator++(int);

		constexpr vec<1, T>& operator--();
		constexpr vec<1, T> operator--(int);

	};

	// -- Unary arithmetic operators --

	template<class T>
	constexpr vec<1, T> operator+(const vec<1, T> &v);

	template<class T>
	constexpr vec<1, T> operator-(const vec<1, T> &v);

	// -- Binary arithmetic operators --

	template<class T>
	constexpr vec<1, T> operator+(const vec<1, T> &v, T scalar);
	template<class T>
	constexpr vec<1, T> operator+(T scalar, const vec<1, T> &v);
	template<class T>
	constexpr vec<1, T> operator+(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	constexpr vec<1, T> operator-(const vec<1, T> &v, T scalar);
	template<class T>
	constexpr vec<1, T> operator-(T scalar, const vec<1, T> &v);
	template<class T>
	constexpr vec<1, T> operator-(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	constexpr vec<1, T> operator*(const vec<1, T> &v, T scalar);
	template<class T>
	constexpr vec<1, T> operator*(T scalar, const vec<1, T> &v);
	template<class T>
	constexpr vec<1, T> operator*(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	constexpr vec<1, T> operator/(const vec<1, T> &v, T scalar);
	template<class T>
	constexpr vec<1, T> operator/(T scalar, const vec<1, T> &v);
	template<class T>
	constexpr vec<1, T> operator/(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	constexpr vec<1, T> operator%(const vec<1, T> &v, T scalar);
	template<class T>
	constexpr vec<1, T> operator%(T scalar, const vec<1, T> &v);
	template<class T>
	constexpr vec<1, T> operator%(const vec<1, T> &v1, const vec<1, T> &v2);

	// -- Bitwise arithmetic operators --

	template<class T>
	constexpr vec<1, T> operator&(const vec<1, T> &v, T scalar);
	template<class T>
	constexpr vec<1, T> operator&(T scalar, const vec<1, T> &v);
	template<class T>
	constexpr vec<1, T> operator&(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	constexpr vec<1, T> operator|(const vec<1, T> &v, T scalar);
	template<class T>
	constexpr vec<1, T> operator|(T scalar, const vec<1, T> &v);
	template<class T>
	constexpr vec<1, T> operator|(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	constexpr vec<1, T> operator^(const vec<1, T> &v, T scalar);
	template<class T>
	constexpr vec<1, T> operator^(T scalar, const vec<1, T> &v);
	template<class T>
	constexpr vec<1, T> operator^(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	constexpr vec<1, T> operator<<(const vec<1, T> &v, T scalar);
	template<class T>
	constexpr vec<1, T> operator<<(T scalar, const vec<1, T> &v);
	template<class T>
	constexpr vec<1, T> operator<<(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	constexpr vec<1, T> operator>>(const vec<1, T> &v, T scalar);
	template<class T>
	constexpr vec<1, T> operator>>(T scalar, const vec<1, T> &v);
	template<class T>
	constexpr vec<1, T> operator>>(const vec<1, T> &v1, const vec<1, T> &v2);

	template<class T>
	constexpr vec<1, T> operator~(const vec<1, T> &v);

	// -- Boolean operators --

	template<class T>
	constexpr bool operator==(const vec<1, T> &v1, const vec<1, T> &v2);
	template<class T>
	constexpr bool operator!=(const vec<1, T> &v1, const vec<1, T> &v2);

	constexpr vec<1, bool> operator&&(const vec<1, bool> &v1, const vec<1, bool> &v2);
	constexpr vec<1, bool> operator||(const vec<1, bool> &v1, const vec<1, bool> &v2);

} // namespace smath

#include "type_vec1.inl"

#endif
