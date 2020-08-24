/**
 * Implementation of the type_vec3.hpp header functions.
 */

namespace smath {

	// -- Constructors --

	template<class T>
	SMATH_CONSTEXPR vec<3, T>::vec()
		: x{}, y{}, z{}
	{}

	template<class T>
	SMATH_CONSTEXPR vec<3, T>::vec(T scalar)
		: x(scalar), y(scalar), z(scalar)
	{}

	template<class T>
	SMATH_CONSTEXPR vec<3, T>::vec(T _x, T _y, T _z)
		: x(_x), y(_y), z(_z)
	{}

	template<class T>
	template<class A, class B, class C>
	SMATH_CONSTEXPR vec<3, T>::vec(A _x, B _y, C _z)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_y))
		, z(static_cast<T>(_z))
	{}

	template<class T>
	SMATH_CONSTEXPR vec<3, T>::vec(const vec<3, T> &v)
		: x(v.x), y(v.y), z(v.z)
	{}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>::vec(const vec<3, A> &v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.y))
		, z(static_cast<T>(v.z))
	{}

	// -- Element Accesses --

	template<class T>
	SMATH_CONSTEXPR T& vec<3, T>::operator[](int i) {
		assert(i >= 0 && i < this->size());
		switch(i) {
			default:
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
		}
	}

	template<class T>
	SMATH_CONSTEXPR const T& vec<3, T>::operator[](int i) const {
		assert(i >= 0 && i < this->size());
		switch(i) {
			default:
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
		}
	}

	// -- Unary arithmetic operators --

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator=(const vec<3, A> &v) {
		this->x = static_cast<T>(v.x);
		this->y = static_cast<T>(v.y);
		this->z = static_cast<T>(v.z);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator+=(A scalar) {
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		this->z += static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator+=(const vec<3, A> &v) {
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.y);
		this->z += static_cast<T>(v.z);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator-=(A scalar) {
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		this->z -= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator-=(const vec<3, A> &v) {
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.y);
		this->z -= static_cast<T>(v.z);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator*=(A scalar) {
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		this->z *= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator*=(const vec<3, A> &v) {
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.y);
		this->z *= static_cast<T>(v.z);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator/=(A scalar) {
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		this->z /= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator/=(const vec<3, A> &v) {
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.y);
		this->z /= static_cast<T>(v.z);
		return *this;
	}

	// -- Unary bit operators --

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator%=(A scalar) {
		this->x %= static_cast<T>(scalar);
		this->y %= static_cast<T>(scalar);
		this->z %= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator%=(const vec<3, A> &v) {
		this->x %= static_cast<T>(v.x);
		this->y %= static_cast<T>(v.y);
		this->z %= static_cast<T>(v.z);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator&=(A scalar) {
		this->x &= static_cast<T>(scalar);
		this->y &= static_cast<T>(scalar);
		this->z &= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator&=(const vec<3, A> &v) {
		this->x &= static_cast<T>(v.x);
		this->y &= static_cast<T>(v.y);
		this->z &= static_cast<T>(v.z);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator|=(A scalar) {
		this->x |= static_cast<T>(scalar);
		this->y |= static_cast<T>(scalar);
		this->z |= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator|=(const vec<3, A> &v) {
		this->x |= static_cast<T>(v.x);
		this->y |= static_cast<T>(v.y);
		this->z |= static_cast<T>(v.z);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator^=(A scalar) {
		this->x ^= static_cast<T>(scalar);
		this->y ^= static_cast<T>(scalar);
		this->z ^= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator^=(const vec<3, A> &v) {
		this->x ^= static_cast<T>(v.x);
		this->y ^= static_cast<T>(v.y);
		this->z ^= static_cast<T>(v.z);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator<<=(A scalar) {
		this->x <<= static_cast<T>(scalar);
		this->y <<= static_cast<T>(scalar);
		this->z <<= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator<<=(const vec<3, A> &v) {
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.y);
		this->z <<= static_cast<T>(v.z);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator>>=(A scalar) {
		this->x >>= static_cast<T>(scalar);
		this->y >>= static_cast<T>(scalar);
		this->z >>= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator>>=(const vec<3, A> &v) {
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.y);
		this->z >>= static_cast<T>(v.z);
		return *this;
	}

	// -- Increment and decrement operators --

	template<class T>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator++() {
		// allow for prefix (i.e. ++a)
		++this->x;
		++this->y;
		++this->z;
		return *this;
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> vec<3, T>::operator++(int) {
		// allow for postfix (i.e. a++)
		vec<3, T> copy(*this);
		++*this;
		return copy;
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T>& vec<3, T>::operator--() {
		--this->x;
		--this->y;
		--this->z;
		return *this;
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> vec<3, T>::operator--(int) {
		vec<3, T> copy(*this);
		--*this;
		return copy;
	}

	// -- Unary arithmetic operators --

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator+(const vec<3, T> &v) {
		return v;
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator-(const vec<3, T> &v) {
		return vec<3, T>(-v.x, -v.y, -v.z);
	}

	// -- Binary arithmetic operators --

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator+(const vec<3, T> &v, T scalar) {
		return vec<3, T>(
			v.x + scalar,
			v.y + scalar,
			v.z + scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator+(T scalar, const vec<3, T> &v) {
		return vec<3, T>(
			scalar + v.x,
			scalar + v.y,
			scalar + v.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator+(const vec<3, T> &v1, const vec<3, T> &v2) {
		return vec<3, T>(
			v1.x + v2.x,
			v1.y + v2.y,
			v1.z + v2.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator-(const vec<3, T> &v, T scalar) {
		return vec<3, T>(
			v.x - scalar,
			v.y - scalar,
			v.z - scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator-(T scalar, const vec<3, T> &v) {
		return vec<3, T>(
			scalar - v.x,
			scalar - v.y,
			scalar - v.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator-(const vec<3, T> &v1, const vec<3, T> &v2) {
		return vec<3, T>(
			v1.x - v2.x,
			v1.y - v2.y,
			v1.z - v2.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator*(const vec<3, T> &v, T scalar) {
		return vec<3, T>(
			v.x * scalar,
			v.y * scalar,
			v.z * scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator*(T scalar, const vec<3, T> &v) {
		return vec<3, T>(
			scalar * v.x,
			scalar * v.y,
			scalar * v.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator*(const vec<3, T> &v1, const vec<3, T> &v2) {
		return vec<3, T>(
			v1.x * v2.x,
			v1.y * v2.y,
			v1.z * v2.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator/(const vec<3, T> &v, T scalar) {
		return vec<3, T>(
			v.x / scalar,
			v.y / scalar,
			v.z / scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator/(T scalar, const vec<3, T> &v) {
		return vec<3, T>(
			scalar / v.x,
			scalar / v.y,
			scalar / v.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator/(const vec<3, T> &v1, const vec<3, T> &v2) {
		return vec<3, T>(
			v1.x / v2.x,
			v1.y / v2.y,
			v1.z / v2.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator%(const vec<3, T> &v, T scalar) {
		return vec<3, T>(
			v.x % scalar,
			v.y % scalar,
			v.z % scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator%(T scalar, const vec<3, T> &v) {
		return vec<3, T>(
			scalar % v.x,
			scalar % v.y,
			scalar % v.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator%(const vec<3, T> &v1, const vec<3, T> &v2) {
		return vec<3, T>(
			v1.x % v2.x,
			v1.y % v2.y,
			v1.z % v2.z
		);
	}

	// -- Bitwise arithmetic operators --

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator&(const vec<3, T> &v, T scalar) {
		return vec<3, T>(
			v.x & scalar,
			v.y & scalar,
			v.z & scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator&(T scalar, const vec<3, T> &v) {
		return vec<3, T>(
			scalar & v.x,
			scalar & v.y,
			scalar & v.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator&(const vec<3, T> &v1, const vec<3, T> &v2) {
		return vec<3, T>(
			v1.x & v2.x,
			v1.y & v2.y,
			v1.z & v2.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator|(const vec<3, T> &v, T scalar) {
		return vec<3, T>(
			v.x | scalar,
			v.y | scalar,
			v.z | scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator|(T scalar, const vec<3, T> &v) {
		return vec<3, T>(
			scalar | v.x,
			scalar | v.y,
			scalar | v.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator|(const vec<3, T> &v1, const vec<3, T> &v2) {
		return vec<3, T>(
			v1.x | v2.x,
			v1.y | v2.y,
			v1.z | v2.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator^(const vec<3, T> &v, T scalar) {
		return vec<3, T>(
			v.x ^ scalar,
			v.y ^ scalar,
			v.z ^ scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator^(T scalar, const vec<3, T> &v) {
		return vec<3, T>(
			scalar ^ v.x,
			scalar ^ v.y,
			scalar ^ v.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator^(const vec<3, T> &v1, const vec<3, T> &v2) {
		return vec<3, T>(
			v1.x ^ v2.x,
			v1.y ^ v2.y,
			v1.z ^ v2.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator<<(const vec<3, T> &v, T scalar) {
		return vec<3, T>(
			v.x << scalar,
			v.y << scalar,
			v.z << scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator<<(T scalar, const vec<3, T> &v) {
		return vec<3, T>(
			scalar << v.x,
			scalar << v.y,
			scalar << v.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator<<(const vec<3, T> &v1, const vec<3, T> &v2) {
		return vec<3, T>(
			v1.x << v2.x,
			v1.y << v2.y,
			v1.z << v2.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator>>(const vec<3, T> &v, T scalar) {
		return vec<3, T>(
			v.x >> scalar,
			v.y >> scalar,
			v.z >> scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator>>(T scalar, const vec<3, T> &v) {
		return vec<3, T>(
			scalar >> v.x,
			scalar >> v.y,
			scalar >> v.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator>>(const vec<3, T> &v1, const vec<3, T> &v2) {
		return vec<3, T>(
			v1.x >> v2.x,
			v1.y >> v2.y,
			v1.z >> v2.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<3, T> operator~(const vec<3, T> &v) {
		return vec<3, T>(
			~v.x,
			~v.y,
			~v.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR bool operator==(const vec<3, T> &v1, const vec<3, T> &v2) {
		return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
	}

	template<class T>
	SMATH_CONSTEXPR bool operator!=(const vec<3, T> &v1, const vec<3, T> &v2) {
		return !(v1 == v2);
	}

	SMATH_CONSTEXPR vec<3, bool> operator&&(const vec<3, bool> &v1, const vec<3, bool> &v2) {
		return vec<3, bool>(
			v1.x && v2.x,
			v1.y && v2.y,
			v1.z && v2.z
		);
	}

	SMATH_CONSTEXPR vec<3, bool> operator||(const vec<3, bool> &v1, const vec<3, bool> &v2) {
		return vec<3, bool>(
			v1.x || v2.x,
			v1.y || v2.y,
			v1.z || v2.z
		);
	}

	template<class T>
	SMATH_CONSTEXPR std::ostream& operator<<(std::ostream &out, const vec<3, T> &v) {
		out << '(' << v.x << ", " << v.y << ", " << v.z << ')';
		return out;
	}

} // namespace smath
