#pragma once

#ifndef TYPE_VEC3_H
#define TYPE_VEC3_H

#include "qualifier.hpp"

namespace smath {

	template<class T>
	class vec<3, T> {

	private:

		static SMATH_CONSTEXPR length_t m_size{ 3 };

	public:

		// -- Components --

		T x;
		T y;
		T z;

		/**
		 * @returns The number of components that the vector contains.
		 */
		static SMATH_CONSTEXPR length_t size() {
			return m_size;
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
		 * @brief Constructor to initialize a vector to an x and y, setting z to 0.
		 * @tparam T The type of the vector.
		 * @param _x The x component of the vector.
		 * @param _y The y component of the vector.
		 */
		SMATH_CONSTEXPR vec(T _x, T _y);

		/**
		 * @brief Constructor to initialize each component in the vector.
		 * @tparam T The type of the vector.
		 * @param _x The x component of the vector.
		 * @param _y The y component of the vector.
		 * @param _z The z component of the vector.
		 */
		SMATH_CONSTEXPR vec(T _x, T _y, T _z);

		/**
		 * @brief Constructor to initialize the x and y components in the vector
		 * using different parameter types, and setting z to 0.
		 * @tparam A Some data type that is not the same base data type.
		 * @tparam B Some data type that is not the same base data type.
		 * @param _x The x component of the vector.
		 * @param _y The y component of the vector.
		 */
		template<class A, class B>
		SMATH_CONSTEXPR vec(A _x, B _y);

		/**
		 * @brief Constructor to initialize each component in the vector using
		 * different parameter types.
		 * @tparam A Some data type that is not the same base data type.
		 * @tparam B Some data type that is not the same base data type.
		 * @tparam C Some data type that is not the same base data type.
		 * @param _x The x component of the vector.
		 * @param _y The y component of the vector.
		 * @param _z The z component of the vector.
		 */
		template<class A, class B, class C>
		SMATH_CONSTEXPR vec(A _x, B _y, C _z);

		/**
		 * @brief Constructor to initialize a vector to another vector.
		 * @param v The vector initialize to.
		 */
		SMATH_CONSTEXPR vec(const vec<3, T> &v);

		/**
		 * @brief Constructor to initialize a vector to a vector from another type.
		 * @tparam A Some data type that is not the same as the base data type.
		 * @param v The vector of a different type.
		 */
		template<class A>
		SMATH_CONSTEXPR vec(const vec<3, A> &v);

		// -- Other vectors --

		/**
		 * @brief Constructor to initialize a 3-component vector to a 1-component
		 * vector.
		 * @tparam T The type of vector to create.
		 * @param v The 1-component vector to use for initialization.
		 */
		SMATH_CONSTEXPR vec(const vec<1, T> &v);

		/**
		 * @brief Constructor to initialize a 3-component vector to a 2-component
		 * vector with a scalar as the third component.
		 * @tparam T The type of vector to create.
		 * @param v The 2-component vector to use for initialization.
		 * @param scalar The scalar to initialize the third component to.
		 */
		SMATH_CONSTEXPR vec(const vec<2, T> &v, T scalar);

		// -- Element accesses --

		SMATH_CONSTEXPR T& operator[](int i);
		SMATH_CONSTEXPR const T& operator[](int i) const;

		// -- Unary arithmetic operators --

		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator=(const vec<3, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator+=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator+=(const vec<3, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator-=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator-=(const vec<3, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator*=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator*=(const vec<3, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator/=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator/=(const vec<3, A> &v);

		// -- Unary bit operators --

		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator%=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator%=(const vec<3, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator&=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator&=(const vec<3, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator|=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator|=(const vec<3, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator^=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator^=(const vec<3, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator<<=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator<<=(const vec<3, A> &v);

		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator>>=(A scalar);
		template<class A>
		SMATH_CONSTEXPR vec<3, T>& operator>>=(const vec<3, A> &v);

		// -- Increment and decrement operators --

		SMATH_CONSTEXPR vec<3, T>& operator++();
		SMATH_CONSTEXPR vec<3, T> operator++(int);

		SMATH_CONSTEXPR vec<3, T>& operator--();
		SMATH_CONSTEXPR vec<3, T> operator--(int);

	};

	// -- Unary arithmetic operators --

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator+(const vec<3, T> &v);

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator-(const vec<3, T> &v);

	// -- Binary arithmetic operators --

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator+(const vec<3, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator+(T scalar, const vec<3, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator+(const vec<3, T> &v1, const vec<3, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator-(const vec<3, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator-(T scalar, const vec<3, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator-(const vec<3, T> &v1, const vec<3, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator*(const vec<3, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator*(T scalar, const vec<3, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator*(const vec<3, T> &v1, const vec<3, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator/(const vec<3, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator/(T scalar, const vec<3, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator/(const vec<3, T> &v1, const vec<3, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator%(const vec<3, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator%(T scalar, const vec<3, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator%(const vec<3, T> &v1, const vec<3, T> &v2);

	// -- Bitwise arithmetic operators --

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator&(const vec<3, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator&(T scalar, const vec<3, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator&(const vec<3, T> &v1, const vec<3, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator|(const vec<3, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator|(T scalar, const vec<3, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator|(const vec<3, T> &v1, const vec<3, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator^(const vec<3, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator^(T scalar, const vec<3, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator^(const vec<3, T> &v1, const vec<3, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator<<(const vec<3, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator<<(T scalar, const vec<3, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator<<(const vec<3, T> &v1, const vec<3, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator>>(const vec<3, T> &v, T scalar);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator>>(T scalar, const vec<3, T> &v);
	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator>>(const vec<3, T> &v1, const vec<3, T> &v2);

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator~(const vec<3, T> &v);

	// -- Boolean operators --

	template<class T>
	SMATH_CONSTEXPR bool operator==(const vec<3, T> &v1, const vec<3, T> &v2);
	template<class T>
	SMATH_CONSTEXPR bool operator!=(const vec<3, T> &v1, const vec<3, T> &v2);

	SMATH_CONSTEXPR vec<3, bool> operator&&(const vec<3, bool> &v1, const vec<3, bool> &v2);
	SMATH_CONSTEXPR vec<3, bool> operator||(const vec<3, bool> &v1, const vec<3, bool> &v2);

	// -- Output stream --

	template<class T>
	SMATH_CONSTEXPR std::ostream& operator<<(std::ostream &out, const vec<3, T> &v);

} // namespace smath

#include "type_vec3.inl"

#endif // TYPE_VEC3_H
