#include <cmath>
#include <iostream>

#include "smath/smath.hpp"

#include "common/min.hpp"
#include "common/max.hpp"
#include "common/abs.hpp"
#include "common/square_root.hpp"

/**
 * Test the smath::round function against std::round
 */
void test_round() {
	std::cout << "\033[32m-- smath::round --\033[0m\n";

	assert(smath::round(7.2f) == std::round(7.2f) && "Failed round(7.2f)");
	assert(smath::round(6.4) == std::round(6.4) && "Failed round(6.4)");
	assert(smath::round(2) == std::round(2) && "Failed round(2)");

	assert(smath::round_nearest(38, 10) == 40 && "Failed round_nearest(38,10)");
	assert(smath::round_nearest(12.5, 5) == 15 && "Failed round_nearest(12.5,5)");

	std::cout << "Passed\n\n";
}

/**
 * Test the smath::floor function against std::floor
 */
void test_floor() {
	std::cout << "\033[32m-- smath::floor --\033[0m\n";

	assert(smath::floor(0) == std::floor(0) && "Failed floor(0)");
	assert(smath::floor(-1.2) == std::floor(-1.2) && "Failed floor(-1.2)");
	assert(smath::floor(1.2) == std::floor(1.2) && "Failed floor(1.2)");
	assert(smath::floor(2.7) == std::floor(2.7) && "Failed floor(2.7)");
	assert(smath::floor(3) == std::floor(3) && "Failed floor(3)");

	std::cout << "Passed\n\n";
}

/**
 * Test the smath::ceil function against std::ceil
 */
void test_ceil() {
	std::cout << "\033[32m-- smath::ceil --\033[0m\n";

	assert(smath::ceil(0) == std::ceil(0) && "Failed ceil(0)");
	assert(smath::ceil(-1.2) == std::ceil(-1.2) && "Failed ceil(-1.2)");
	assert(smath::ceil(1.2) == std::ceil(1.2) && "Failed ceil(1.2)");
	assert(smath::ceil(2.7) == std::ceil(2.7) && "Failed ceil(2.7)");
	assert(smath::ceil(3) == std::ceil(3) && "Failed ceil(3)");

	std::cout << "Passed\n\n";
}

/**
 * Test the conversion between degrees and radians
 */
void test_convert_radians_degrees() {
	std::cout << "\033[32m-- radians and degrees --\033[0m\n";

	SMATH_STATIC_ASSERT(smath::radians(smath::degrees(3.1416f)) == 3.1416f, "Failed radians(degrees(3.1416f))");

	SMATH_STATIC_ASSERT(smath::degrees(smath::radians(180.f)) == 180, "Failed degrees(radians(180.f))");
	SMATH_STATIC_ASSERT(smath::degrees(smath::radians(90.f)) == 90, "Failed degrees(radians(90.f))");
	SMATH_STATIC_ASSERT(smath::degrees(smath::radians(45.f)) == 45, "Failed degrees(radians(45.f))");

	assert(smath::degrees(smath::radians(smath::vec1(180.f))) == smath::vec1(smath::degrees(smath::radians(180.f))) && "Failed degrees(vec1)");
	assert(smath::degrees(smath::radians(smath::vec1(90.f))) == smath::vec1(smath::degrees(smath::radians(90.f))) && "Failed degrees(vec1)");

	std::cout << "Passed\n\n";
}

/**
 * Test the scaling of a number to a new range
 */
void test_scale() {
	std::cout << "\033[32m-- smath::scale --\033[0m\n";

	SMATH_STATIC_ASSERT(smath::scale(3, 1, 10, 1, 100) == 23, "Failed scale(3,1,10,1,100)");
	SMATH_STATIC_ASSERT(smath::scale(27, 11, 40, 1, 100) == 56, "Failed scale(27,11,40,1,100)");

	std::cout << "Passed\n\n";
}

/**
 * Test my implementation of 1-component vectors.
 */
void test_vec1() {
	std::cout << "\033[32m-- smath::vec1 --\033[0m\n";
	using v1 = smath::vec1;
	using v1d = smath::vec1d;
	using v1i = smath::vec1i;

	SMATH_STATIC_ASSERT((v1{ 1.5f } + v1{ 5.f } == v1{ 6.5f }), "Failed vec1f addition with vec1f");
	SMATH_STATIC_ASSERT((v1{ 1.5f } + 2.f == v1{ 3.5f }), "Failed vec1f addition with scalar");
	SMATH_STATIC_ASSERT((2.f + v1{ 1.5f } == v1{ 3.5f }), "Failed scalar addition with vec1f");

	SMATH_STATIC_ASSERT((v1d{ 1.5 } + v1d{ 5.0 } == v1d{ 6.5 }), "Failed vec1d addition with vec1d");
	SMATH_STATIC_ASSERT((v1d{ 1.5 } + 2.0 == v1d{ 3.5 }), "Failed vec1d addition with scalar");
	SMATH_STATIC_ASSERT((2.0 + v1d{ 1.5 } == v1d{ 3.5 }), "Failed scalar addition with vec1d");

	SMATH_STATIC_ASSERT((v1i{ 1 } + v1i{ 5 } == v1i{ 6 }), "Failed vec1i addition with vec1i");
	SMATH_STATIC_ASSERT((v1i{ 1 } + 2 == v1i{ 3 }), "Failed vec1i addition with scalar");
	SMATH_STATIC_ASSERT((2 + v1i{ 1 } == v1i{ 3 }), "Failed scalar addition with vec1i");

	SMATH_STATIC_ASSERT((v1{ 2.5f } * v1{ 2.f } == v1{ 5.f }), "Failed vec1f multiplication with vec1f");
	SMATH_STATIC_ASSERT((v1{ 2.5f } * 2.f == v1{ 5.f }), "Failed vec1f multiplication with scalar");
	SMATH_STATIC_ASSERT((2.f * v1{ 2.5f } == v1{ 5.f }), "Failed scalar multiplication with vec1f");

	SMATH_STATIC_ASSERT((v1d{ 2.5 } * v1d{ 2.0 } == v1d{ 5.0 }), "Failed vec1d multiplication with vec1d");
	SMATH_STATIC_ASSERT((v1d{ 2.5 } * 2.0 == v1d{ 5.0 }), "Failed vec1d multiplication with scalar");
	SMATH_STATIC_ASSERT((2.0 * v1d{ 2.5 } == v1d{ 5.0 }), "Failed scalar multiplication with vec1d");

	SMATH_STATIC_ASSERT((v1i{ 2 } * v1i{ 2 } == v1i{ 4 }), "Failed vec1i multiplication with vec1i");
	SMATH_STATIC_ASSERT((v1i{ 2 } * 2 == v1i{ 4 }), "Failed vec1i multiplication with scalar");
	SMATH_STATIC_ASSERT((2 * v1i{ 2 } == v1i{ 4 }), "Failed scalar multiplication with vec1i");

	SMATH_STATIC_ASSERT(v1{}.size() == 1, "Failed size of vec1f");
	SMATH_STATIC_ASSERT(v1d{}.size() == 1, "Failed size of vec1d");
	SMATH_STATIC_ASSERT(v1i{}.size() == 1, "Failed size of vec1i");

	SMATH_STATIC_ASSERT((v1{ 1.2f }[0] == 1.2f), "Failed vec1f access at 0");
	SMATH_STATIC_ASSERT((v1d{ 1.2 }[0] == 1.2), "Failed vec1d access at 0");
	SMATH_STATIC_ASSERT((v1i{ 1 }[0] == 1), "Failed vec1i access at 0");

	std::cout << "Passed\n\n";
}

/**
 * Test my implementation of 2-component vectors.
 */
void test_vec2() {
	std::cout << "\033[32m-- smath::vec2 --\033[0m\n";
	using v2 = smath::vec2;
	using v2d = smath::vec2d;
	using v2i = smath::vec2i;

	SMATH_STATIC_ASSERT((v2{ 1.5f, 2.6f } + v2{ 5.f, 3.f } == v2{ 6.5f, 5.6f }), "Failed vec2f addition with vec2f");
	SMATH_STATIC_ASSERT((v2{ 1.5f, 2.6f } + 2.f == v2{ 3.5f, 4.6f }), "Failed vec2f addition with scalar");
	SMATH_STATIC_ASSERT((2.f + v2{ 1.5f, 2.6f } == v2{ 3.5f, 4.6f }), "Failed scalar addition with vec2f");

	SMATH_STATIC_ASSERT((v2d{ 1.5, 2.6 } + v2d{ 5.0, 3.0 } == v2d{ 6.5, 5.6 }), "Failed vec2d addition with vec2d");
	SMATH_STATIC_ASSERT((v2d{ 1.5, 2.6 } + 2.0 == v2d{ 3.5, 4.6 }), "Failed vec2d addition with scalar");
	SMATH_STATIC_ASSERT((2.0 + v2d{ 1.5, 2.6 } == v2d{ 3.5, 4.6 }), "Failed scalar addition with vec2d");

	SMATH_STATIC_ASSERT((v2i{ 1, 2 } + v2i{ 5, 3 } == v2i{ 6, 5 }), "Failed vec2i addition with vec2i");
	SMATH_STATIC_ASSERT((v2i{ 1, 2 } + 2 == v2i{ 3, 4 }), "Failed vec2i addition with scalar");
	SMATH_STATIC_ASSERT((2 + v2i{ 1, 2 } == v2i{ 3, 4 }), "Failed scalar addition with vec2i");

	SMATH_STATIC_ASSERT((v2{ 2.5f, 4.f } * v2{ 2.f, 2.f } == v2{ 5.f, 8.f }), "Failed vec2f multiplication with vec2f");
	SMATH_STATIC_ASSERT((v2{ 2.5f, 4.f } * 2.f == v2{ 5.f, 8.f }), "Failed vec2f multiplication with scalar");
	SMATH_STATIC_ASSERT((2.f * v2{ 2.5f, 4.f } == v2{ 5.f, 8.f }), "Failed scalar multiplication with vec2f");

	SMATH_STATIC_ASSERT((v2d{ 2.5, 4.0 } * v2d{ 2.0, 2.0 } == v2d{ 5.0, 8.0 }), "Failed vec2d multiplication with vec2d");
	SMATH_STATIC_ASSERT((v2d{ 2.5, 4.0 } * 2.0 == v2d{ 5.0, 8.0 }), "Failed vec2d multiplication with scalar");
	SMATH_STATIC_ASSERT((2.0 * v2d{ 2.5, 4.0 } == v2d{ 5.0, 8.0 }), "Failed scalar multiplication with vec2d");

	SMATH_STATIC_ASSERT((v2i{ 2, 4 } * v2i{ 2, 2 } == v2i{ 4, 8 }), "Failed vec2i multiplication with vec2i");
	SMATH_STATIC_ASSERT((v2i{ 2, 4 } * 2 == v2i{ 4, 8 }), "Failed vec2i multiplication with scalar");
	SMATH_STATIC_ASSERT((2 * v2i{ 2, 4 } == v2i{ 4, 8 }), "Failed scalar multiplication with vec2i");

	SMATH_STATIC_ASSERT(v2{}.size() == 2, "Failed size of vec2f");
	SMATH_STATIC_ASSERT(v2d{}.size() == 2, "Failed size of vec2d");
	SMATH_STATIC_ASSERT(v2i{}.size() == 2, "Failed size of vec2i");

	SMATH_STATIC_ASSERT((v2{ 1.2f, 2.3f }[0] == 1.2f), "Failed vec2f access at 0");
	SMATH_STATIC_ASSERT((v2{ 1.2f, 2.3f }[1] == 2.3f), "Failed vec2f access at 1");

	SMATH_STATIC_ASSERT((v2d{ 1.2, 2.3 }[0] == 1.2), "Failed vec2d access at 0");
	SMATH_STATIC_ASSERT((v2d{ 1.2, 2.3 }[1] == 2.3), "Failed vec2d access at 1");

	SMATH_STATIC_ASSERT((v2i{ 1, 2 }[0] == 1), "Failed vec2i access at 0");
	SMATH_STATIC_ASSERT((v2i{ 1, 2 }[1] == 2), "Failed vec2i access at 1");

	std::cout << "Passed\n\n";
}

/**
 * Test my implementation of 3-component vectors.
 */
void test_vec3() {
	std::cout << "\033[32m-- smath::vec3 --\033[0m\n";
	using v3 = smath::vec3;
	using v3d = smath::vec3d;
	using v3i = smath::vec3i;

	SMATH_STATIC_ASSERT((v3{ 1.5f, 2.6f, 1.2f } + v3{ 5.f, 3.f, 1.2f } == v3{ 6.5f, 5.6f, 2.4f }), "Failed vec3f addition with vec3f");
	SMATH_STATIC_ASSERT((v3{ 1.5f, 2.6f, 1.2f } + 2.f == v3{ 3.5f, 4.6f, 3.2f }), "Failed vec3f addition with scalar");
	SMATH_STATIC_ASSERT((2.f + v3{ 1.5f, 2.6f, 1.2f } == v3{ 3.5f, 4.6f, 3.2f }), "Failed scalar addition with vec3f");

	SMATH_STATIC_ASSERT((v3d{ 1.5, 2.6, 1.2 } + v3d{ 5.0, 3.0, 1.2 } == v3d{ 6.5, 5.6, 2.4 }), "Failed vec3d addition with vec3d");
	SMATH_STATIC_ASSERT((v3d{ 1.5, 2.6, 1.2 } + 2.0 == v3d{ 3.5, 4.6, 3.2 }), "Failed vec3d addition with scalar");
	SMATH_STATIC_ASSERT((2.0 + v3d{ 1.5, 2.6, 1.2 } == v3d{ 3.5, 4.6, 3.2 }), "Failed scalar addition with vec3d");

	SMATH_STATIC_ASSERT((v3i{ 1, 2, 3 } + v3i{ 5, 3, 1 } == v3i{ 6, 5, 4 }), "Failed vec3i addition with vec3i");
	SMATH_STATIC_ASSERT((v3i{ 1, 2, 3 } + 2 == v3i{ 3, 4, 5 }), "Failed vec3i addition with scalar");
	SMATH_STATIC_ASSERT((2 + v3i{ 1, 2, 3 } == v3i{ 3, 4, 5 }), "Failed scalar addition with vec3i");

	SMATH_STATIC_ASSERT((v3{ 2.5f, 4.f, 3.f } * v3{ 2.f, 2.f, 3.f } == v3{ 5.f, 8.f, 9.f }), "Failed vec3f multiplication with vec3f");
	SMATH_STATIC_ASSERT((v3{ 2.5f, 4.f, 3.f } * 2.f == v3{ 5.f, 8.f, 6.f }), "Failed vec3f multiplication with scalar");
	SMATH_STATIC_ASSERT((2.f * v3{ 2.5f, 4.f, 3.f } == v3{ 5.f, 8.f, 6.f }), "Failed scalar multiplication with vec3f");

	SMATH_STATIC_ASSERT((v3d{ 2.5, 4.0, 3.0 } * v3d{ 2.0, 2.0, 3.0 } == v3d{ 5.0, 8.0, 9.0 }), "Failed vec3d multiplication with vec3d");
	SMATH_STATIC_ASSERT((v3d{ 2.5, 4.0, 3.0 } * 2.0 == v3d{ 5.0, 8.0, 6.0 }), "Failed vec3d multiplication with scalar");
	SMATH_STATIC_ASSERT((2.0 * v3d{ 2.5, 4.0, 3.0 } == v3d{ 5.0, 8.0, 6.0 }), "Failed scalar multiplication with vec3d");

	SMATH_STATIC_ASSERT((v3i{ 2, 4, 3 } * v3i{ 2, 2, 3 } == v3i{ 4, 8, 9 }), "Failed vec3i multiplication with vec3i");
	SMATH_STATIC_ASSERT((v3i{ 2, 4, 3 } * 2 == v3i{ 4, 8, 6 }), "Failed vec3i multiplication with scalar");
	SMATH_STATIC_ASSERT((2 * v3i{ 2, 4, 3 } == v3i{ 4, 8, 6 }), "Failed scalar multiplication with vec3i");

	SMATH_STATIC_ASSERT(v3{}.size() == 3, "Failed size of vec3f");
	SMATH_STATIC_ASSERT(v3d{}.size() == 3, "Failed size of vec3d");
	SMATH_STATIC_ASSERT(v3i{}.size() == 3, "Failed size of vec3i");

	SMATH_STATIC_ASSERT((v3{ 1.2f, 2.3f, 3.4f }[0] == 1.2f), "Failed vec3f access at 0");
	SMATH_STATIC_ASSERT((v3{ 1.2f, 2.3f, 3.4f }[1] == 2.3f), "Failed vec3f access at 1");
	SMATH_STATIC_ASSERT((v3{ 1.2f, 2.3f, 3.4f }[2] == 3.4f), "Failed vec3f access at 2");

	SMATH_STATIC_ASSERT((v3d{ 1.2, 2.3, 3.4 }[0] == 1.2), "Failed vec3d access at 0");
	SMATH_STATIC_ASSERT((v3d{ 1.2, 2.3, 3.4 }[1] == 2.3), "Failed vec3d access at 1");
	SMATH_STATIC_ASSERT((v3d{ 1.2, 2.3, 3.4 }[2] == 3.4), "Failed vec3d access at 2");

	SMATH_STATIC_ASSERT((v3i{ 1, 2, 3 }[0] == 1), "Failed vec3i access at 0");
	SMATH_STATIC_ASSERT((v3i{ 1, 2, 3 }[1] == 2), "Failed vec3i access at 1");
	SMATH_STATIC_ASSERT((v3i{ 1, 2, 3 }[2] == 3), "Failed vec3i access at 2");

	std::cout << "Passed\n\n";
}

/*
 * Test my implementation of 4-component vectors.
 */
void test_vec4() {
	std::cout << "\033[32m-- smath::vec4 --\033[0m\n";
	using v4 = smath::vec4;
	using v4d = smath::vec4d;
	using v4i = smath::vec4i;

	SMATH_STATIC_ASSERT((v4{ 1.5f, 2.6f, 1.2f, 0.1f } + v4{ 5.f, 3.f, 1.2f, 1.1f } == v4{ 6.5f, 5.6f, 2.4f, 1.2f }), "Failed vec4f addition with vec4f");
	SMATH_STATIC_ASSERT((v4{ 1.5f, 2.6f, 1.2f, 0.1f } + 2.f == v4{ 3.5f, 4.6f, 3.2f, 2.1f }), "Failed vec4f addition with scalar");
	SMATH_STATIC_ASSERT((2.f + v4{ 1.5f, 2.6f, 1.2f, 0.1f } == v4{ 3.5f, 4.6f, 3.2f, 2.1f }), "Failed scalar addition with vec4f");

	SMATH_STATIC_ASSERT((v4d{ 1.5, 2.6, 1.2, 0.4 } + v4d{ 5.0, 3.0, 1.2, 0.4 } == v4d{ 6.5, 5.6, 2.4, 0.8 }), "Failed vec4d addition with vec4d");
	SMATH_STATIC_ASSERT((v4d{ 1.5, 2.6, 1.2, 0.4 } + 2.0 == v4d{ 3.5, 4.6, 3.2, 2.4 }), "Failed vec4d addition with scalar");
	SMATH_STATIC_ASSERT((2.0 + v4d{ 1.5, 2.6, 1.2, 0.4 } == v4d{ 3.5, 4.6, 3.2, 2.4 }), "Failed scalar addition with vec4d");

	SMATH_STATIC_ASSERT((v4i{ 1, 2, 3, 4 } + v4i{ 5, 3, 1, 2 } == v4i{ 6, 5, 4, 6 }), "Failed vec4i addition with vec4i");
	SMATH_STATIC_ASSERT((v4i{ 1, 2, 3, 4 } + 2 == v4i{ 3, 4, 5, 6 }), "Failed vec4i addition with scalar");
	SMATH_STATIC_ASSERT((2 + v4i{ 1, 2, 3, 4 } == v4i{ 3, 4, 5, 6 }), "Failed scalar addition with vec4i");

	SMATH_STATIC_ASSERT((v4{ 2.5f, 4.f, 3.f, 1.5f } * v4{ 2.f, 2.f, 3.f, 2.f } == v4{ 5.f, 8.f, 9.f, 3.f }), "Failed vec4f multiplication with vec4f");
	SMATH_STATIC_ASSERT((v4{ 2.5f, 4.f, 3.f, 1.5f } * 2.f == v4{ 5.f, 8.f, 6.f, 3.f }), "Failed vec4f multiplication with scalar");
	SMATH_STATIC_ASSERT((2.f * v4{ 2.5f, 4.f, 3.f, 1.5f } == v4{ 5.f, 8.f, 6.f, 3.f }), "Failed scalar multiplication with vec4f");

	SMATH_STATIC_ASSERT((v4d{ 2.5, 4.0, 3.0, 1.5 } * v4d{ 2.0, 2.0, 3.0, 2.0 } == v4d{ 5.0, 8.0, 9.0, 3.0 }), "Failed vec4d multiplication with vec4d");
	SMATH_STATIC_ASSERT((v4d{ 2.5, 4.0, 3.0, 1.5 } * 2.0 == v4d{ 5.0, 8.0, 6.0, 3.0 }), "Failed vec4d multiplication with scalar");
	SMATH_STATIC_ASSERT((2.0 * v4d{ 2.5, 4.0, 3.0, 1.5 } == v4d{ 5.0, 8.0, 6.0, 3.0 }), "Failed scalar multiplication with vec4d");

	SMATH_STATIC_ASSERT((v4i{ 2, 4, 3, 1 } * v4i{ 2, 2, 3, 1 } == v4i{ 4, 8, 9, 1 }), "Failed vec4i multiplication with vec4i");
	SMATH_STATIC_ASSERT((v4i{ 2, 4, 3, 1 } * 2 == v4i{ 4, 8, 6, 2 }), "Failed vec4i multiplication with scalar");
	SMATH_STATIC_ASSERT((2 * v4i{ 2, 4, 3, 1 } == v4i{ 4, 8, 6, 2 }), "Failed scalar multiplication with vec4i");

	SMATH_STATIC_ASSERT(v4{}.size() == 4, "Failed size of vec4f");
	SMATH_STATIC_ASSERT(v4d{}.size() == 4, "Failed size of vec4d");
	SMATH_STATIC_ASSERT(v4i{}.size() == 4, "Failed size of vec4i");

	SMATH_STATIC_ASSERT((v4{ 1.2f, 2.3f, 3.4f, 0.1f }[0] == 1.2f), "Failed vec4f access at 0");
	SMATH_STATIC_ASSERT((v4{ 1.2f, 2.3f, 3.4f, 0.1f }[1] == 2.3f), "Failed vec4f access at 1");
	SMATH_STATIC_ASSERT((v4{ 1.2f, 2.3f, 3.4f, 0.1f }[2] == 3.4f), "Failed vec4f access at 2");
	SMATH_STATIC_ASSERT((v4{ 1.2f, 2.3f, 3.4f, 0.1f }[3] == 0.1f), "Failed vec4f access at 3");

	SMATH_STATIC_ASSERT((v4d{ 1.2, 2.3, 3.4, 0.1 }[0] == 1.2), "Failed vec4d access at 0");
	SMATH_STATIC_ASSERT((v4d{ 1.2, 2.3, 3.4, 0.1 }[1] == 2.3), "Failed vec4d access at 1");
	SMATH_STATIC_ASSERT((v4d{ 1.2, 2.3, 3.4, 0.1 }[2] == 3.4), "Failed vec4d access at 2");
	SMATH_STATIC_ASSERT((v4d{ 1.2, 2.3, 3.4, 0.1 }[3] == 0.1), "Failed vec4d access at 3");

	SMATH_STATIC_ASSERT((v4i{ 1, 2, 3, 4 }[0] == 1), "Failed vec4i access at 0");
	SMATH_STATIC_ASSERT((v4i{ 1, 2, 3, 4 }[1] == 2), "Failed vec4i access at 1");
	SMATH_STATIC_ASSERT((v4i{ 1, 2, 3, 4 }[2] == 3), "Failed vec4i access at 2");
	SMATH_STATIC_ASSERT((v4i{ 1, 2, 3, 4 }[3] == 4), "Failed vec4i access at 3");

	std::cout << "Passed\n\n";
}

/**
 * Test my implementation of matrix with 2 rows and 2 columns.
 */
void test_mat2x2() {
	std::cout << "\033[32m-- smath::mat2x2 --\033[0m\n";

	smath::mat2 A{ 12.2f };
	std::cout << A << '\n';

	std::cout << "Passed\n\n";
}

/**
 * Test the differences between the constants
 */
void test_consts() {
	std::cout << "\033[32m-- smath::constants --\033[0m\n";

	SMATH_STATIC_ASSERT(static_cast<float>(smath::constants::PI) == static_cast<float>(M_PI), "Failed PI constant");
	SMATH_STATIC_ASSERT(static_cast<float>(smath::constants::E) == static_cast<float>(M_E), "Failed E constant");

	std::cout << "Passed\n\n";
}

/**
 * Main function for testing
 */
int main() {

	std::cout << '\n';
	int errors = 0;

	errors += test::Abs::run();
	errors += test::Min::run();
	errors += test::Max::run();
	errors += test::Sqrt::run();
	test_round();
	test_floor();
	test_ceil();
	test_convert_radians_degrees();
	test_scale();
	test_vec1();
	test_vec2();
	test_vec3();
	test_vec4();
	test_mat2x2();
	test_consts();

	return errors;
}
