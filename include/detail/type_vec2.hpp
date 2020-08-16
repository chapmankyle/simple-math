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

		// -- Constructors --

		/**
		 * Default constructor for a 2-component vector.
		 */
		constexpr vec()
			: x{}, y{}
		{}

		/**
		 * Constructor to initialize a vector to a single scalar.
		 * @tparam T The type of the vector.
		 * @param scalar The scalar value to initialize the vector to.
		 */
		constexpr vec(T scalar)
			: x(scalar), y(scalar)
		{}

		/**
		 * Constructor to initialize each component in the vector.
		 * @tparam T The type of the vector.
		 * @param _x The x component of the vector.
		 * @param _y The y component of the vector.
		 */
		constexpr vec(T _x, T _y)
			: x(_x), y(_y)
		{}

		/**
		 * Constructor to initialize each component in the vector using
		 * different types
		 */
		template<class A, class B>
		constexpr vec(A _x, B _y)
			: x(static_cast<T>(_x))
			, y(static_cast<T>(_y))
		{}

		/**
		 * Constructor to initialize a vector to another vector.
		 * @param v The vector initialize to.
		 */
		constexpr vec(const vec<2, T> &v)
			: x(v.x), y(v.y)
		{}

		/**
		 * Constructor to initialize a vector to a vector from another type.
		 * @param v The vector of a different type.
		 */
		template<class A>
		constexpr vec(const vec<2, A> &v)
			: x(static_cast<T>(v.x))
			, y(static_cast<T>(v.y))
		{}

		// -- Element Accesses --

		constexpr T& operator[](int i) {
			assert(i >= 0 && i < this->length());
			switch(i) {
				default:
				case 0:
					return x;
				case 1:
					return y;
			}
		}

		constexpr const T& operator[](int i) const {
			assert(i >= 0 && i < this->length());
			switch(i) {
				default:
				case 0:
					return x;
				case 1:
					return y;
			}
		}

		/**
		 * @returns The number of components that the vector contains.
		 */
		static constexpr int length() {
			return 2;
		}

		// -- Unary arithmetic operators --

		constexpr vec<2, T> operator+(const vec<2, T> &v) {
			return v;
		}

		constexpr vec<2, T> operator-(const vec<2, T> &v) {
			return vec<2, T>(-v.x, -v.y);
		}

		template<class A>
		constexpr vec<2, T>& operator=(const vec<2, A> &v) {
			this->x = static_cast<T>(v.x);
			this->y = static_cast<T>(v.y);
			return *this;
		}

		template<class A>
		constexpr vec<2, T>& operator+=(A scalar) {
			this->x += static_cast<T>(scalar);
			this->y += static_cast<T>(scalar);
			return *this;
		}

		template<class A>
		constexpr vec<2, T>& operator+=(const vec<2, A> &v) {
			this->x += static_cast<T>(v.x);
			this->y += static_cast<T>(v.y);
			return *this;
		}

		template<class A>
		constexpr vec<2, T>& operator-=(A scalar) {
			this->x -= static_cast<T>(scalar);
			this->y -= static_cast<T>(scalar);
			return *this;
		}

		template<class A>
		constexpr vec<2, T>& operator-=(const vec<2, A> &v) {
			this->x -= static_cast<T>(v.x);
			this->y -= static_cast<T>(v.y);
			return *this;
		}

		template<class A>
		constexpr vec<2, T>& operator*=(A scalar) {
			this->x *= static_cast<T>(scalar);
			this->y *= static_cast<T>(scalar);
			return *this;
		}

		template<class A>
		constexpr vec<2, T>& operator*=(const vec<2, A> &v) {
			this->x *= static_cast<T>(v.x);
			this->y *= static_cast<T>(v.y);
			return *this;
		}

		template<class A>
		constexpr vec<2, T>& operator/=(A scalar) {
			this->x /= static_cast<T>(scalar);
			this->y /= static_cast<T>(scalar);
			return *this;
		}

		template<class A>
		constexpr vec<2, T>& operator/=(const vec<2, A> &v) {
			this->x /= static_cast<T>(v.x);
			this->y /= static_cast<T>(v.y);
			return *this;
		}

	};

} // namespace smath

#endif
