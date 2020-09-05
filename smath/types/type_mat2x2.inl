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
	SMATH_CONSTEXPR mat<2, 2, T>::mat(T scalar)
		: values{ row_t(scalar, scalar), row_t(scalar, scalar) }
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

	// -- Output stream --

	template<class T>
	SMATH_CONSTEXPR std::ostream& operator<<(std::ostream &out, const mat<2, 2, T> &m) {
		out << "[ " << m[0][0] << "  " << m[0][1] << " ]\n";
		out << "[ " << m[1][0] << "  " << m[1][1] << " ]\n";
		return out;
	}

}
