/**
 * Implementation of the type_mat2x2.hpp header functions.
 */

namespace smath {

	// -- Constructors --

	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T>::mat()
		: values{ row_t(0, 0), row_t(0, 0) }
	{}

	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T>::mat(const mat<2, 2, T> &m)
		: values{ m[0], m[1] }
	{}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>::mat(const mat<2, 2, A> &m)
		: values{ row_t(m[0]), row_t(m[1]) }
	{}

	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T>::mat(T scalar)
		: values{ row_t(scalar, 0), row_t(0, scalar) }
	{}

	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T>::mat(const T &x1, const T &y1, const T &x2, const T &y2)
		: values{ row_t(x1, y1), row_t(x2, y2) }
	{}

	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T>::mat(const row_t &r1, const row_t &r2)
		: values{ r1, r2 }
	{}

	template<class T>
	template<class A, class B, class C, class D>
	SMATH_CONSTEXPR mat<2, 2, T>::mat(const A &x1, const B &y1, const C &x2, const D &y2)
		: values{ row_t(static_cast<T>(x1), static_cast<T>(y1)), row_t(static_cast<T>(x2), static_cast<T>(y2)) }
	{}

	template<class T>
	template<class A, class B>
	SMATH_CONSTEXPR mat<2, 2, T>::mat(const vec<2, A> &r1, const vec<2, B> &r2)
		: values{ row_t(r1), row_t(r2) }
	{}

	// -- Element accesses --

	template<class T>
	SMATH_CONSTEXPR typename mat<2, 2, T>::row_t& mat<2, 2, T>::operator[](length_t i) {
		assert(i < this->m_rows);
		return this->values[i];
	}

	template<class T>
	SMATH_CONSTEXPR const typename mat<2, 2, T>::row_t& mat<2, 2, T>::operator[](length_t i) const {
		assert(i < this->m_rows);
		return this->values[i];
	}

	// -- Unary arithmetic operators --

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator=(const mat<2, 2, A> &m) {
		this->values[0] = m[0];
		this->values[1] = m[1];
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator+=(A scalar) {
		this->values[0] += static_cast<T>(scalar);
		this->values[1] += static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator+=(const mat<2, 2, A> &m) {
		this->values[0] += m[0];
		this->values[1] += m[1];
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator-=(A scalar) {
		this->values[0] -= static_cast<T>(scalar);
		this->values[1] -= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator-=(const mat<2, 2, A> &m) {
		this->values[0] -= m[0];
		this->values[1] -= m[1];
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator*=(A scalar) {
		this->values[0] *= static_cast<T>(scalar);
		this->values[1] *= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator*=(const mat<2, 2, A> &m) {
		this->values[0] *= m[0];
		this->values[1] *= m[1];
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator/=(A scalar) {
		this->values[0] /= static_cast<T>(scalar);
		this->values[1] /= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator/=(const mat<2, 2, A> &m) {
		this->values[0] /= m[0];
		this->values[1] /= m[1];
		return *this;
	}

	// -- Unary bit operators --

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator%=(A scalar) {
		this->values[0] %= static_cast<T>(scalar);
		this->values[1] %= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator%=(const mat<2, 2, A> &m) {
		this->values[0] %= m[0];
		this->values[1] %= m[1];
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator&=(A scalar) {
		this->values[0] &= static_cast<T>(scalar);
		this->values[1] &= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator&=(const mat<2, 2, A> &m) {
		this->values[0] &= m[0];
		this->values[1] &= m[1];
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator|=(A scalar) {
		this->values[0] |= static_cast<T>(scalar);
		this->values[1] |= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator|=(const mat<2, 2, A> &m) {
		this->values[0] |= m[0];
		this->values[1] |= m[1];
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator^=(A scalar) {
		this->values[0] ^= static_cast<T>(scalar);
		this->values[1] ^= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator^=(const mat<2, 2, A> &m) {
		this->values[0] ^= m[0];
		this->values[1] ^= m[1];
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator<<=(A scalar) {
		this->values[0] <<= static_cast<T>(scalar);
		this->values[1] <<= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator<<=(const mat<2, 2, A> &m) {
		this->values[0] <<= m[0];
		this->values[1] <<= m[1];
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator>>=(A scalar) {
		this->values[0] >>= static_cast<T>(scalar);
		this->values[1] >>= static_cast<T>(scalar);
		return *this;
	}

	template<class T>
	template<class A>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator>>=(const mat<2, 2, A> &m) {
		this->values[0] >>= m[0];
		this->values[1] >>= m[1];
		return *this;
	}

	// -- Increment and decrement operators --

	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator++() {
		// allow for prefix (i.e. ++a)
		++this->values[0];
		++this->values[1];
		return *this;
	}

	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T> mat<2, 2, T>::operator++(int) {
		// allow for postfix (i.e. a++)
		mat<2, 2, T> copy(*this);
		++*this;
		return copy;
	}

	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T>& mat<2, 2, T>::operator--() {
		--this->values[0];
		--this->values[1];
		return *this;
	}

	template<class T>
	SMATH_CONSTEXPR mat<2, 2, T> mat<2, 2, T>::operator--(int) {
		mat<2, 2, T> copy(*this);
		--*this;
		return copy;
	}

	// -- Boolean operators --

	template<class T>
	SMATH_CONSTEXPR bool operator==(const mat<2, 2, T> &m1, const mat<2, 2, T> &m2) {
		return (m1[0] == m2[0]) && (m1[1] == m2[1]);
	}

	template<class T>
	SMATH_CONSTEXPR bool operator!=(const mat<2, 2, T> &m1, const mat<2, 2, T> &m2) {
		return (m1[0] != m2[0]) || (m1[1] != m2[1]);
	}

	// -- Output stream --

	template<class T>
	SMATH_CONSTEXPR std::ostream& operator<<(std::ostream &out, const mat<2, 2, T> &m) {
		out << "[ " << m[0][0] << "  " << m[0][1] << " ]\n";
		out << "[ " << m[1][0] << "  " << m[1][1] << " ]\n";
		return out;
	}

}
