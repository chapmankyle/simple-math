/**
 * Implementation of the type_vec1.hpp header functions.
 */

namespace smath {

	// -- Constructors --

	template<class T>
	constexpr vec<1, T>::vec()
		: x{}
	{}

	template<class T>
	constexpr vec<1, T>::vec(T scalar)
		: x(scalar)
	{}

	template<class T>
	template<class A>
	constexpr vec<1, T>::vec(A _x)
		: x(static_cast<T>(_x))
	{}

	template<class T>
	constexpr vec<1, T>::vec(const vec<1, T> &v)
		: x(v.x)
	{}

	template<class T>
	template<class A>
	constexpr vec<1, T>::vec(const vec<1, A> &v)
		: x(static_cast<T>(v.x))
	{}

	// -- Element Accesses --

	template<class T>
	constexpr T& vec<1, T>::operator[](int i) {
		assert(i >= 0 && i < this->size());
		switch(i) {
			default:
			case 0:
				return x;
		}
	}

	template<class T>
	constexpr const T& vec<1, T>::operator[](int i) const {
		assert(i >= 0 && i < this->size());
		switch(i) {
			default:
			case 0:
				return x;
		}
	}

	// -- Unary arithmetic operators --

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator=(const vec<1, A> &v) {
		this->x = static_cast<T>(v.x);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator+=(A scalar) {
		this->x += static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator+=(const vec<1, A> &v) {
		this->x += static_cast<T>(v.x);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator-=(A scalar) {
		this->x -= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator-=(const vec<1, A> &v) {
		this->x -= static_cast<T>(v.x);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator*=(A scalar) {
		this->x *= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator*=(const vec<1, A> &v) {
		this->x *= static_cast<T>(v.x);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator/=(A scalar) {
		this->x /= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator/=(const vec<1, A> &v) {
		this->x /= static_cast<T>(v.x);
		return *this;
	}

	// -- Unary bit operators --

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator%=(A scalar) {
		this->x %= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator%=(const vec<1, A> &v) {
		this->x %= static_cast<T>(v.x);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator&=(A scalar) {
		this->x &= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator&=(const vec<1, A> &v) {
		this->x &= static_cast<T>(v.x);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator|=(A scalar) {
		this->x |= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator|=(const vec<1, A> &v) {
		this->x |= static_cast<T>(v.x);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator^=(A scalar) {
		this->x ^= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator^=(const vec<1, A> &v) {
		this->x ^= static_cast<T>(v.x);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator<<=(A scalar) {
		this->x <<= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator<<=(const vec<1, A> &v) {
		this->x <<= static_cast<T>(v.x);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator>>=(A scalar) {
		this->x >>= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<1, T>& vec<1, T>::operator>>=(const vec<1, A> &v) {
		this->x >>= static_cast<T>(v.x);
		return *this;
	}

	// -- Increment and decrement operators --

	template<class T>
	constexpr vec<1, T>& vec<1, T>::operator++() {
		// allow for prefix (i.e. ++a)
		++this->x;
		return *this;
	}

	template<class T>
	constexpr vec<1, T> vec<1, T>::operator++(int) {
		// allow for postfix (i.e. a++)
		vec<1, T> copy(*this);
		++*this;
		return copy;
	}

	template<class T>
	constexpr vec<1, T>& vec<1, T>::operator--() {
		--this->x;
		return *this;
	}

	template<class T>
	constexpr vec<1, T> vec<1, T>::operator--(int) {
		vec<1, T> copy(*this);
		--*this;
		return copy;
	}

	// -- Unary arithmetic operators --

	template<class T>
	constexpr vec<1, T> operator+(const vec<1, T> &v) {
		return v;
	}

	template<class T>
	constexpr vec<1, T> operator-(const vec<1, T> &v) {
		return vec<1, T>(-v.x);
	}

	// -- Binary arithmetic operators --

	template<class T>
	constexpr vec<1, T> operator+(const vec<1, T> &v, T scalar) {
		return vec<1, T>(
			v.x + scalar
		);
	}

	template<class T>
	constexpr vec<1, T> operator+(T scalar, const vec<1, T> &v) {
		return vec<1, T>(
			scalar + v.x
		);
	}

	template<class T>
	constexpr vec<1, T> operator+(const vec<1, T> &v1, const vec<1, T> &v2) {
		return vec<1, T>(
			v1.x + v2.x
		);
	}

	template<class T>
	constexpr vec<1, T> operator-(const vec<1, T> &v, T scalar) {
		return vec<1, T>(
			v.x - scalar
		);
	}

	template<class T>
	constexpr vec<1, T> operator-(T scalar, const vec<1, T> &v) {
		return vec<1, T>(
			scalar - v.x
		);
	}

	template<class T>
	constexpr vec<1, T> operator-(const vec<1, T> &v1, const vec<1, T> &v2) {
		return vec<1, T>(
			v1.x - v2.x
	);
	}

	template<class T>
	constexpr vec<1, T> operator*(const vec<1, T> &v, T scalar) {
		return vec<1, T>(
			v.x * scalar
		);
	}

	template<class T>
	constexpr vec<1, T> operator*(T scalar, const vec<1, T> &v) {
		return vec<1, T>(
			scalar * v.x
		);
	}

	template<class T>
	constexpr vec<1, T> operator*(const vec<1, T> &v1, const vec<1, T> &v2) {
		return vec<1, T>(
			v1.x * v2.x
		);
	}

	template<class T>
	constexpr vec<1, T> operator/(const vec<1, T> &v, T scalar) {
		return vec<1, T>(
			v.x / scalar
		);
	}

	template<class T>
	constexpr vec<1, T> operator/(T scalar, const vec<1, T> &v) {
		return vec<1, T>(
			scalar / v.x
		);
	}

	template<class T>
	constexpr vec<1, T> operator/(const vec<1, T> &v1, const vec<1, T> &v2) {
		return vec<1, T>(
			v1.x / v2.x
	);
	}

	template<class T>
	constexpr vec<1, T> operator%(const vec<1, T> &v, T scalar) {
		return vec<1, T>(
			v.x % scalar
		);
	}

	template<class T>
	constexpr vec<1, T> operator%(T scalar, const vec<1, T> &v) {
		return vec<1, T>(
			scalar % v.x
		);
	}

	template<class T>
	constexpr vec<1, T> operator%(const vec<1, T> &v1, const vec<1, T> &v2) {
		return vec<1, T>(
			v1.x % v2.x
		);
	}

	// -- Bitwise arithmetic operators --

	template<class T>
	constexpr vec<1, T> operator&(const vec<1, T> &v, T scalar) {
		return vec<1, T>(
			v.x & scalar
		);
	}

	template<class T>
	constexpr vec<1, T> operator&(T scalar, const vec<1, T> &v) {
		return vec<1, T>(
			scalar & v.x
		);
	}

	template<class T>
	constexpr vec<1, T> operator&(const vec<1, T> &v1, const vec<1, T> &v2) {
		return vec<1, T>(
			v1.x & v2.x
		);
	}

	template<class T>
	constexpr vec<1, T> operator|(const vec<1, T> &v, T scalar) {
		return vec<1, T>(
			v.x | scalar
		);
	}

	template<class T>
	constexpr vec<1, T> operator|(T scalar, const vec<1, T> &v) {
		return vec<1, T>(
			scalar | v.x
		);
	}

	template<class T>
	constexpr vec<1, T> operator|(const vec<1, T> &v1, const vec<1, T> &v2) {
		return vec<1, T>(
			v1.x | v2.x
		);
	}

	template<class T>
	constexpr vec<1, T> operator^(const vec<1, T> &v, T scalar) {
		return vec<1, T>(
			v.x ^ scalar
		);
	}

	template<class T>
	constexpr vec<1, T> operator^(T scalar, const vec<1, T> &v) {
		return vec<1, T>(
			scalar ^ v.x
		);
	}

	template<class T>
	constexpr vec<1, T> operator^(const vec<1, T> &v1, const vec<1, T> &v2) {
		return vec<1, T>(
			v1.x ^ v2.x
		);
	}

	template<class T>
	constexpr vec<1, T> operator<<(const vec<1, T> &v, T scalar) {
		return vec<1, T>(
			v.x << scalar
		);
	}

	template<class T>
	constexpr vec<1, T> operator<<(T scalar, const vec<1, T> &v) {
		return vec<1, T>(
			scalar << v.x
		);
	}

	template<class T>
	constexpr vec<1, T> operator<<(const vec<1, T> &v1, const vec<1, T> &v2) {
		return vec<1, T>(
			v1.x << v2.x
		);
	}

	template<class T>
	constexpr vec<1, T> operator>>(const vec<1, T> &v, T scalar) {
		return vec<1, T>(
			v.x >> scalar
		);
	}

	template<class T>
	constexpr vec<1, T> operator>>(T scalar, const vec<1, T> &v) {
		return vec<1, T>(
			scalar >> v.x
		);
	}

	template<class T>
	constexpr vec<1, T> operator>>(const vec<1, T> &v1, const vec<1, T> &v2) {
		return vec<1, T>(
			v1.x >> v2.x
		);
	}

	template<class T>
	constexpr vec<1, T> operator~(const vec<1, T> &v) {
		return vec<1, T>(~v.x);
	}

	template<class T>
	constexpr bool operator==(const vec<1, T> &v1, const vec<1, T> &v2) {
		return v1.x == v2.x;
	}

	template<class T>
	constexpr bool operator!=(const vec<1, T> &v1, const vec<1, T> &v2) {
		return !(v1 == v2);
	}

	constexpr vec<1, bool> operator&&(const vec<1, bool> &v1, const vec<1, bool> &v2) {
		return vec<1, bool>(v1.x && v2.x);
	}

	constexpr vec<1, bool> operator||(const vec<1, bool> &v1, const vec<1, bool> &v2) {
		return vec<1, bool>(v1.x || v2.x);
	}

} // namespace smath
