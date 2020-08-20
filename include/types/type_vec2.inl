/**
 * Implementation of the type_vec2.hpp header functions.
 */

namespace smath {

	// -- Constructors --

	template<class T>
	constexpr vec<2, T>::vec()
		: x{}, y{}
	{}

	template<class T>
	constexpr vec<2, T>::vec(T scalar)
		: x(scalar), y(scalar)
	{}

	template<class T>
	constexpr vec<2, T>::vec(T _x, T _y)
		: x(_x), y(_y)
	{}

	template<class T>
	template<class A, class B>
	constexpr vec<2, T>::vec(A _x, B _y)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_y))
	{}

	template<class T>
	constexpr vec<2, T>::vec(const vec<2, T> &v)
		: x(v.x), y(v.y)
	{}

	template<class T>
	template<class A>
	constexpr vec<2, T>::vec(const vec<2, A> &v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.y))
	{}

	// -- Element Accesses --

	template<class T>
	constexpr T& vec<2, T>::operator[](int i) {
		assert(i >= 0 && i < this->size());
		switch(i) {
			default:
			case 0:
				return x;
			case 1:
				return y;
		}
	}

	template<class T>
	constexpr const T& vec<2, T>::operator[](int i) const {
		assert(i >= 0 && i < this->size());
		switch(i) {
			default:
			case 0:
				return x;
			case 1:
				return y;
		}
	}

	// -- Unary arithmetic operators --

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator=(const vec<2, A> &v) {
		this->x = static_cast<T>(v.x);
		this->y = static_cast<T>(v.y);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator+=(A scalar) {
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator+=(const vec<2, A> &v) {
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.y);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator-=(A scalar) {
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator-=(const vec<2, A> &v) {
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.y);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator*=(A scalar) {
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator*=(const vec<2, A> &v) {
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.y);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator/=(A scalar) {
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator/=(const vec<2, A> &v) {
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.y);
		return *this;
	}

	// -- Unary bit operators --

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator%=(A scalar) {
		this->x %= static_cast<T>(scalar);
		this->y %= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator%=(const vec<2, A> &v) {
		this->x %= static_cast<T>(v.x);
		this->y %= static_cast<T>(v.y);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator&=(A scalar) {
		this->x &= static_cast<T>(scalar);
		this->y &= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator&=(const vec<2, A> &v) {
		this->x &= static_cast<T>(v.x);
		this->y &= static_cast<T>(v.y);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator|=(A scalar) {
		this->x |= static_cast<T>(scalar);
		this->y |= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator|=(const vec<2, A> &v) {
		this->x |= static_cast<T>(v.x);
		this->y |= static_cast<T>(v.y);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator^=(A scalar) {
		this->x ^= static_cast<T>(scalar);
		this->y ^= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator^=(const vec<2, A> &v) {
		this->x ^= static_cast<T>(v.x);
		this->y ^= static_cast<T>(v.y);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator<<=(A scalar) {
		this->x <<= static_cast<T>(scalar);
		this->y <<= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator<<=(const vec<2, A> &v) {
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.y);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator>>=(A scalar) {
		this->x >>= static_cast<T>(scalar);
		this->y >>= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	constexpr vec<2, T>& vec<2, T>::operator>>=(const vec<2, A> &v) {
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.y);
		return *this;
	}

	// -- Increment and decrement operators --

	template<class T>
	constexpr vec<2, T>& vec<2, T>::operator++() {
		// allow for prefix (i.e. ++a)
		++this->x;
		++this->y;
		return *this;
	}

	template<class T>
	constexpr vec<2, T> vec<2, T>::operator++(int) {
		// allow for postfix (i.e. a++)
		vec<2, T> copy(*this);
		++*this;
		return copy;
	}

	template<class T>
	constexpr vec<2, T>& vec<2, T>::operator--() {
		--this->x;
		--this->y;
		return *this;
	}

	template<class T>
	constexpr vec<2, T> vec<2, T>::operator--(int) {
		vec<2, T> copy(*this);
		--*this;
		return copy;
	}

	// -- Unary arithmetic operators --

	template<class T>
	constexpr vec<2, T> operator+(const vec<2, T> &v) {
		return v;
	}

	template<class T>
	constexpr vec<2, T> operator-(const vec<2, T> &v) {
		return vec<2, T>(-v.x, -v.y);
	}

	// -- Binary arithmetic operators --

	template<class T>
	constexpr vec<2, T> operator+(const vec<2, T> &v, T scalar) {
		return vec<2, T>(
			v.x + scalar,
			v.y + scalar
		);
	}

	template<class T>
	constexpr vec<2, T> operator+(T scalar, const vec<2, T> &v) {
		return vec<2, T>(
			scalar + v.x,
			scalar + v.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator+(const vec<2, T> &v1, const vec<2, T> &v2) {
		return vec<2, T>(
			v1.x + v2.x,
			v1.y + v2.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator-(const vec<2, T> &v, T scalar) {
		return vec<2, T>(
			v.x - scalar,
			v.y - scalar
		);
	}

	template<class T>
	constexpr vec<2, T> operator-(T scalar, const vec<2, T> &v) {
		return vec<2, T>(
			scalar - v.x,
			scalar - v.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator-(const vec<2, T> &v1, const vec<2, T> &v2) {
		return vec<2, T>(
			v1.x - v2.x,
			v1.y - v2.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator*(const vec<2, T> &v, T scalar) {
		return vec<2, T>(
			v.x * scalar,
			v.y * scalar
		);
	}

	template<class T>
	constexpr vec<2, T> operator*(T scalar, const vec<2, T> &v) {
		return vec<2, T>(
			scalar * v.x,
			scalar * v.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator*(const vec<2, T> &v1, const vec<2, T> &v2) {
		return vec<2, T>(
			v1.x * v2.x,
			v1.y * v2.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator/(const vec<2, T> &v, T scalar) {
		return vec<2, T>(
			v.x / scalar,
			v.y / scalar
		);
	}

	template<class T>
	constexpr vec<2, T> operator/(T scalar, const vec<2, T> &v) {
		return vec<2, T>(
			scalar / v.x,
			scalar / v.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator/(const vec<2, T> &v1, const vec<2, T> &v2) {
		return vec<2, T>(
			v1.x / v2.x,
			v1.y / v2.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator%(const vec<2, T> &v, T scalar) {
		return vec<2, T>(
			v.x % scalar,
			v.y % scalar
		);
	}

	template<class T>
	constexpr vec<2, T> operator%(T scalar, const vec<2, T> &v) {
		return vec<2, T>(
			scalar % v.x,
			scalar % v.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator%(const vec<2, T> &v1, const vec<2, T> &v2) {
		return vec<2, T>(
			v1.x % v2.x,
			v1.y % v2.y
		);
	}

	// -- Bitwise arithmetic operators --

	template<class T>
	constexpr vec<2, T> operator&(const vec<2, T> &v, T scalar) {
		return vec<2, T>(
			v.x & scalar,
			v.y & scalar
		);
	}

	template<class T>
	constexpr vec<2, T> operator&(T scalar, const vec<2, T> &v) {
		return vec<2, T>(
			scalar & v.x,
			scalar & v.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator&(const vec<2, T> &v1, const vec<2, T> &v2) {
		return vec<2, T>(
			v1.x & v2.x,
			v1.y & v2.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator|(const vec<2, T> &v, T scalar) {
		return vec<2, T>(
			v.x | scalar,
			v.y | scalar
		);
	}

	template<class T>
	constexpr vec<2, T> operator|(T scalar, const vec<2, T> &v) {
		return vec<2, T>(
			scalar | v.x,
			scalar | v.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator|(const vec<2, T> &v1, const vec<2, T> &v2) {
		return vec<2, T>(
			v1.x | v2.x,
			v1.y | v2.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator^(const vec<2, T> &v, T scalar) {
		return vec<2, T>(
			v.x ^ scalar,
			v.y ^ scalar
		);
	}

	template<class T>
	constexpr vec<2, T> operator^(T scalar, const vec<2, T> &v) {
		return vec<2, T>(
			scalar ^ v.x,
			scalar ^ v.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator^(const vec<2, T> &v1, const vec<2, T> &v2) {
		return vec<2, T>(
			v1.x ^ v2.x,
			v1.y ^ v2.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator<<(const vec<2, T> &v, T scalar) {
		return vec<2, T>(
			v.x << scalar,
			v.y << scalar
		);
	}

	template<class T>
	constexpr vec<2, T> operator<<(T scalar, const vec<2, T> &v) {
		return vec<2, T>(
			scalar << v.x,
			scalar << v.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator<<(const vec<2, T> &v1, const vec<2, T> &v2) {
		return vec<2, T>(
			v1.x << v2.x,
			v1.y << v2.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator>>(const vec<2, T> &v, T scalar) {
		return vec<2, T>(
			v.x >> scalar,
			v.y >> scalar
		);
	}

	template<class T>
	constexpr vec<2, T> operator>>(T scalar, const vec<2, T> &v) {
		return vec<2, T>(
			scalar >> v.x,
			scalar >> v.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator>>(const vec<2, T> &v1, const vec<2, T> &v2) {
		return vec<2, T>(
			v1.x >> v2.x,
			v1.y >> v2.y
		);
	}

	template<class T>
	constexpr vec<2, T> operator~(const vec<2, T> &v) {
		return vec<2, T>(
			~v.x,
			~v.y
		);
	}

	template<class T>
	constexpr bool operator==(const vec<2, T> &v1, const vec<2, T> &v2) {
		return v1.x == v2.x && v1.y == v2.y;
	}

	template<class T>
	constexpr bool operator!=(const vec<2, T> &v1, const vec<2, T> &v2) {
		return !(v1 == v2);
	}

	constexpr vec<2, bool> operator&&(const vec<2, bool> &v1, const vec<2, bool> &v2) {
		return vec<2, bool>(
			v1.x && v2.x,
			v1.y && v2.y
		);
	}

	constexpr vec<2, bool> operator||(const vec<2, bool> &v1, const vec<2, bool> &v2) {
		return vec<2, bool>(
			v1.x || v2.x,
			v1.y || v2.y
		);
	}

} // namespace smath
