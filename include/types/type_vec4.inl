/**
 * Implementation of the type_vec4.hpp header functions.
 */

namespace smath {

	// -- Constructors --

	template<class T>
	SMATH_CONSTEXPR vec<4, T>::vec()
		: x{}, y{}, z{}, w{}
	{}

	template<class T>
	SMATH_CONSTEXPR vec<4, T>::vec(T scalar)
		: x(scalar), y(scalar), z(scalar), w(scalar)
	{}

	template<class T>
	SMATH_CONSTEXPR vec<4, T>::vec(T _x, T _y, T _z, T _w)
		: x(_x), y(_y), z(_z), w(_w)
	{}

	template<class T>
	template<class A, class B, class C, class D>
	SMATH_CONSTEXPR vec<4, T>::vec(A _x, B _y, C _z, D _w)
		: x(static_cast<T>(_x))
		, y(static_cast<T>(_y))
		, z(static_cast<T>(_z))
		, w(static_cast<T>(_w))
	{}

	template<class T>
	SMATH_CONSTEXPR vec<4, T>::vec(const vec<4, T> &v)
		: x(v.x), y(v.y), z(v.z), w(v.w)
	{}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>::vec(const vec<4, A> &v)
		: x(static_cast<T>(v.x))
		, y(static_cast<T>(v.y))
		, z(static_cast<T>(v.z))
		, w(static_cast<T>(v.w))
	{}

	template<class T>
	SMATH_CONSTEXPR vec<4, T>::vec(const vec<1, T> &v)
		: x(v.x)
		, y(v.x)
		, z(v.x)
		, w(v.x)
	{}

	template<class T>
	SMATH_CONSTEXPR vec<4, T>::vec(const vec<3, T> &v, T scalar)
		: x(v.x)
		, y(v.y)
		, z(v.z)
		, w(scalar)
	{}

	// -- Element Accesses --

	template<class T>
	SMATH_CONSTEXPR T& vec<4, T>::operator[](int i) {
		assert(i >= 0 && i < this->size());
		switch(i) {
			default:
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			case 3:
				return w;
		}
	}

	template<class T>
	SMATH_CONSTEXPR const T& vec<4, T>::operator[](int i) const {
		assert(i >= 0 && i < this->size());
		switch(i) {
			default:
			case 0:
				return x;
			case 1:
				return y;
			case 2:
				return z;
			case 3:
				return w;
		}
	}

	// -- Unary arithmetic operators --

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator=(const vec<4, A> &v) {
		this->x = static_cast<T>(v.x);
		this->y = static_cast<T>(v.y);
		this->z = static_cast<T>(v.z);
		this->w = static_cast<T>(v.w);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator+=(A scalar) {
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		this->z += static_cast<T>(scalar);
		this->w += static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator+=(const vec<4, A> &v) {
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.y);
		this->z += static_cast<T>(v.z);
		this->w += static_cast<T>(v.w);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator-=(A scalar) {
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		this->z -= static_cast<T>(scalar);
		this->w -= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator-=(const vec<4, A> &v) {
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.y);
		this->z -= static_cast<T>(v.z);
		this->w -= static_cast<T>(v.w);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator*=(A scalar) {
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		this->z *= static_cast<T>(scalar);
		this->w *= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator*=(const vec<4, A> &v) {
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.y);
		this->z *= static_cast<T>(v.z);
		this->w *= static_cast<T>(v.w);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator/=(A scalar) {
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		this->z /= static_cast<T>(scalar);
		this->w /= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator/=(const vec<4, A> &v) {
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.y);
		this->z /= static_cast<T>(v.z);
		this->w /= static_cast<T>(v.w);
		return *this;
	}

	// -- Unary bit operators --

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator%=(A scalar) {
		this->x %= static_cast<T>(scalar);
		this->y %= static_cast<T>(scalar);
		this->z %= static_cast<T>(scalar);
		this->w %= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator%=(const vec<4, A> &v) {
		this->x %= static_cast<T>(v.x);
		this->y %= static_cast<T>(v.y);
		this->z %= static_cast<T>(v.z);
		this->w %= static_cast<T>(v.w);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator&=(A scalar) {
		this->x &= static_cast<T>(scalar);
		this->y &= static_cast<T>(scalar);
		this->z &= static_cast<T>(scalar);
		this->w &= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator&=(const vec<4, A> &v) {
		this->x &= static_cast<T>(v.x);
		this->y &= static_cast<T>(v.y);
		this->z &= static_cast<T>(v.z);
		this->w &= static_cast<T>(v.w);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator|=(A scalar) {
		this->x |= static_cast<T>(scalar);
		this->y |= static_cast<T>(scalar);
		this->z |= static_cast<T>(scalar);
		this->w |= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator|=(const vec<4, A> &v) {
		this->x |= static_cast<T>(v.x);
		this->y |= static_cast<T>(v.y);
		this->z |= static_cast<T>(v.z);
		this->w |= static_cast<T>(v.w);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator^=(A scalar) {
		this->x ^= static_cast<T>(scalar);
		this->y ^= static_cast<T>(scalar);
		this->z ^= static_cast<T>(scalar);
		this->w ^= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator^=(const vec<4, A> &v) {
		this->x ^= static_cast<T>(v.x);
		this->y ^= static_cast<T>(v.y);
		this->z ^= static_cast<T>(v.z);
		this->w ^= static_cast<T>(v.w);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator<<=(A scalar) {
		this->x <<= static_cast<T>(scalar);
		this->y <<= static_cast<T>(scalar);
		this->z <<= static_cast<T>(scalar);
		this->w <<= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator<<=(const vec<4, A> &v) {
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.y);
		this->z <<= static_cast<T>(v.z);
		this->w <<= static_cast<T>(v.w);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator>>=(A scalar) {
		this->x >>= static_cast<T>(scalar);
		this->y >>= static_cast<T>(scalar);
		this->z >>= static_cast<T>(scalar);
		this->w >>= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator>>=(const vec<4, A> &v) {
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.y);
		this->z >>= static_cast<T>(v.z);
		this->w >>= static_cast<T>(v.w);
		return *this;
	}

	// -- Increment and decrement operators --

	template<class T>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator++() {
		// allow for prefix (i.e. ++a)
		++this->x;
		++this->y;
		++this->z;
		++this->w;
		return *this;
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> vec<4, T>::operator++(int) {
		// allow for postfix (i.e. a++)
		vec<4, T> copy(*this);
		++*this;
		return copy;
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T>& vec<4, T>::operator--() {
		--this->x;
		--this->y;
		--this->z;
		--this->w;
		return *this;
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> vec<4, T>::operator--(int) {
		vec<4, T> copy(*this);
		--*this;
		return copy;
	}

	// -- Unary arithmetic operators --

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator+(const vec<4, T> &v) {
		return v;
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator-(const vec<4, T> &v) {
		return vec<4, T>(-v.x, -v.y, -v.z, -v.w);
	}

	// -- Binary arithmetic operators --

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator+(const vec<4, T> &v, T scalar) {
		return vec<4, T>(
			v.x + scalar,
			v.y + scalar,
			v.z + scalar,
			v.w + scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator+(T scalar, const vec<4, T> &v) {
		return vec<4, T>(
			scalar + v.x,
			scalar + v.y,
			scalar + v.z,
			scalar + v.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator+(const vec<4, T> &v1, const vec<4, T> &v2) {
		return vec<4, T>(
			v1.x + v2.x,
			v1.y + v2.y,
			v1.z + v2.z,
			v1.w + v2.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator-(const vec<4, T> &v, T scalar) {
		return vec<4, T>(
			v.x - scalar,
			v.y - scalar,
			v.z - scalar,
			v.w - scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator-(T scalar, const vec<4, T> &v) {
		return vec<4, T>(
			scalar - v.x,
			scalar - v.y,
			scalar - v.z,
			scalar - v.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator-(const vec<4, T> &v1, const vec<4, T> &v2) {
		return vec<4, T>(
			v1.x - v2.x,
			v1.y - v2.y,
			v1.z - v2.z,
			v1.w - v2.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator*(const vec<4, T> &v, T scalar) {
		return vec<4, T>(
			v.x * scalar,
			v.y * scalar,
			v.z * scalar,
			v.w * scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator*(T scalar, const vec<4, T> &v) {
		return vec<4, T>(
			scalar * v.x,
			scalar * v.y,
			scalar * v.z,
			scalar * v.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator*(const vec<4, T> &v1, const vec<4, T> &v2) {
		return vec<4, T>(
			v1.x * v2.x,
			v1.y * v2.y,
			v1.z * v2.z,
			v1.w * v2.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator/(const vec<4, T> &v, T scalar) {
		return vec<4, T>(
			v.x / scalar,
			v.y / scalar,
			v.z / scalar,
			v.w / scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator/(T scalar, const vec<4, T> &v) {
		return vec<4, T>(
			scalar / v.x,
			scalar / v.y,
			scalar / v.z,
			scalar / v.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator/(const vec<4, T> &v1, const vec<4, T> &v2) {
		return vec<4, T>(
			v1.x / v2.x,
			v1.y / v2.y,
			v1.z / v2.z,
			v1.w / v2.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator%(const vec<4, T> &v, T scalar) {
		return vec<4, T>(
			v.x % scalar,
			v.y % scalar,
			v.z % scalar,
			v.w % scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator%(T scalar, const vec<4, T> &v) {
		return vec<4, T>(
			scalar % v.x,
			scalar % v.y,
			scalar % v.z,
			scalar % v.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator%(const vec<4, T> &v1, const vec<4, T> &v2) {
		return vec<4, T>(
			v1.x % v2.x,
			v1.y % v2.y,
			v1.z % v2.z,
			v1.w % v2.w
		);
	}

	// -- Bitwise arithmetic operators --

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator&(const vec<4, T> &v, T scalar) {
		return vec<4, T>(
			v.x & scalar,
			v.y & scalar,
			v.z & scalar,
			v.w & scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator&(T scalar, const vec<4, T> &v) {
		return vec<4, T>(
			scalar & v.x,
			scalar & v.y,
			scalar & v.z,
			scalar & v.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator&(const vec<4, T> &v1, const vec<4, T> &v2) {
		return vec<4, T>(
			v1.x & v2.x,
			v1.y & v2.y,
			v1.z & v2.z,
			v1.w & v2.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator|(const vec<4, T> &v, T scalar) {
		return vec<4, T>(
			v.x | scalar,
			v.y | scalar,
			v.z | scalar,
			v.w | scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator|(T scalar, const vec<4, T> &v) {
		return vec<4, T>(
			scalar | v.x,
			scalar | v.y,
			scalar | v.z,
			scalar | v.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator|(const vec<4, T> &v1, const vec<4, T> &v2) {
		return vec<4, T>(
			v1.x | v2.x,
			v1.y | v2.y,
			v1.z | v2.z,
			v1.w | v2.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator^(const vec<4, T> &v, T scalar) {
		return vec<4, T>(
			v.x ^ scalar,
			v.y ^ scalar,
			v.z ^ scalar,
			v.w ^ scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator^(T scalar, const vec<4, T> &v) {
		return vec<4, T>(
			scalar ^ v.x,
			scalar ^ v.y,
			scalar ^ v.z,
			scalar ^ v.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator^(const vec<4, T> &v1, const vec<4, T> &v2) {
		return vec<4, T>(
			v1.x ^ v2.x,
			v1.y ^ v2.y,
			v1.z ^ v2.z,
			v1.w ^ v2.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator<<(const vec<4, T> &v, T scalar) {
		return vec<4, T>(
			v.x << scalar,
			v.y << scalar,
			v.z << scalar,
			v.w << scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator<<(T scalar, const vec<4, T> &v) {
		return vec<4, T>(
			scalar << v.x,
			scalar << v.y,
			scalar << v.z,
			scalar << v.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator<<(const vec<4, T> &v1, const vec<4, T> &v2) {
		return vec<4, T>(
			v1.x << v2.x,
			v1.y << v2.y,
			v1.z << v2.z,
			v1.w << v2.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator>>(const vec<4, T> &v, T scalar) {
		return vec<4, T>(
			v.x >> scalar,
			v.y >> scalar,
			v.z >> scalar,
			v.w >> scalar
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator>>(T scalar, const vec<4, T> &v) {
		return vec<4, T>(
			scalar >> v.x,
			scalar >> v.y,
			scalar >> v.z,
			scalar >> v.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator>>(const vec<4, T> &v1, const vec<4, T> &v2) {
		return vec<4, T>(
			v1.x >> v2.x,
			v1.y >> v2.y,
			v1.z >> v2.z,
			v1.w >> v2.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR vec<4, T> operator~(const vec<4, T> &v) {
		return vec<4, T>(
			~v.x,
			~v.y,
			~v.z,
			~v.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR bool operator==(const vec<4, T> &v1, const vec<4, T> &v2) {
		return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z && v1.w == v2.w;
	}

	template<class T>
	SMATH_CONSTEXPR bool operator!=(const vec<4, T> &v1, const vec<4, T> &v2) {
		return !(v1 == v2);
	}

	SMATH_CONSTEXPR vec<4, bool> operator&&(const vec<4, bool> &v1, const vec<4, bool> &v2) {
		return vec<4, bool>(
			v1.x && v2.x,
			v1.y && v2.y,
			v1.z && v2.z,
			v1.w && v2.w
		);
	}

	SMATH_CONSTEXPR vec<4, bool> operator||(const vec<4, bool> &v1, const vec<4, bool> &v2) {
		return vec<4, bool>(
			v1.x || v2.x,
			v1.y || v2.y,
			v1.z || v2.z,
			v1.w || v2.w
		);
	}

	template<class T>
	SMATH_CONSTEXPR std::ostream& operator<<(std::ostream &out, const vec<4, T> &v) {
		out << '(' << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ')';
		return out;
	}

} // namespace smath
