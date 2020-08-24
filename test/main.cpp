#include <iostream>
#include <cmath>
#include <iomanip>
#include <typeinfo>

#include "include/smath.hpp"

/**
 * Test the smath::max function against std::max
 */
void test_max() {
	std::cout << "\033[32m-- smath::max --\033[0m\n";

	SMATH_STATIC_ASSERT(smath::max(3, 5) == std::max(3, 5), "Failed max(3, 5)");
	SMATH_STATIC_ASSERT(smath::max(8.4f, 5.2f) == std::max(8.4f, 5.2f), "Failed max(8.4f, 5.2f)");

	SMATH_STATIC_ASSERT(smath::max('a', 'z') == std::max('a', 'z'), "Failed max('a', 'z')");
	SMATH_STATIC_ASSERT(smath::max('A', 'Z') == std::max('A', 'Z'), "Failed max('A', 'Z')");
	SMATH_STATIC_ASSERT(smath::max('A', 'z') == std::max('A', 'z'), "Failed max('A', 'z')");

	std::cout << "Passed\n\n";
}

/**
 * Test the smath::min function against std::min
 */
void test_min() {
	std::cout << "\033[32m-- smath::min --\033[0m\n";

	SMATH_STATIC_ASSERT(smath::min(3, 5) == std::min(3, 5), "Failed min(3, 5");
	SMATH_STATIC_ASSERT(smath::min(8.4f, 5.2f) == std::min(8.4f, 5.2f), "Failed min(8.4f, 5.2f)");

	SMATH_STATIC_ASSERT(smath::min('a', 'z') == std::min('a', 'z'), "Failed min('a', 'z')");
	SMATH_STATIC_ASSERT(smath::min('A', 'Z') == std::min('A', 'Z'), "Failed min('A', 'Z')");
	SMATH_STATIC_ASSERT(smath::min('A', 'z') == std::min('A', 'z'), "Failed min('A', 'z')");

	std::cout << "Passed\n\n";
}

/**
 * Test the smath::abs function against std::abs
 */
void test_abs() {
	std::cout << "\033[32m-- smath::abs --\033[0m\n";

	SMATH_STATIC_ASSERT(smath::abs(-9.2f) == std::abs(-9.2f), "Failed abs(-9.2f)");
	SMATH_STATIC_ASSERT(smath::abs(3.9) == std::abs(3.9), "Failed abs(3.9)");
	SMATH_STATIC_ASSERT(smath::abs(17) == std::abs(17), "Failed abs(17)");

	std::cout << "Passed\n\n";
}

/**
 * Test the smath::sqrt function against std::sqrt
 */
void test_sqrt() {
	std::cout << "\033[32m-- smath::sqrt --\033[0m\n";

	assert(smath::sqrt(smath::vec1(4)) == smath::vec1(std::sqrt(4)) && "Failed sqrt of vec1(4)");
	assert(smath::sqrt(smath::vec1(4.0)) == smath::vec1(std::sqrt(4.0)) && "Failed sqrt of vec1(4.0)");
	assert(smath::sqrt(smath::vec1(4.0f)) == smath::vec1(std::sqrt(4.0f)) && "Failed sqrt of vec1(4.0f)");

	assert(smath::sqrt(smath::vec2(4, 16)) == smath::vec2(std::sqrt(4), std::sqrt(16)) && "Failed sqrt of vec2(4,16)");
	assert(smath::sqrt(smath::vec2(4.0, 16.0)) == smath::vec2(std::sqrt(4.0), std::sqrt(16.0)) && "Failed sqrt of vec2(4.0,16.0)");
	assert(smath::sqrt(smath::vec2(4.0f, 16.0f)) == smath::vec2(std::sqrt(4.0f), std::sqrt(16.0f)) && "Failed sqrt of vec2(4.0f,16.0f)");

	assert(smath::sqrt(smath::vec3(4, 16, 12)) == smath::vec3(std::sqrt(4), std::sqrt(16), std::sqrt(12)) && "Failed sqrt of vec3(4,16,12)");
	assert(smath::sqrt(smath::vec3(4.0, 16.0, 12.0)) == smath::vec3(std::sqrt(4.0), std::sqrt(16.0), std::sqrt(12.0)) && "Failed sqrt of vec3(4.0,16.0,12.0)");
	assert(smath::sqrt(smath::vec3(4.0f, 16.0f, 12.0f)) == smath::vec3(std::sqrt(4.0f), std::sqrt(16.0f), std::sqrt(12.0f)) && "Failed sqrt of vec3(4.0f,16.0f,12.0f)");

	std::cout << "Passed\n\n";
}

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
	std::cout << "-------- CEIL --------\n";
	std::cout << smath::ceil(0) << '\n';
	std::cout << std::ceil(0) << '\n';

	std::cout << smath::ceil(-1.2) << '\n';
	std::cout << std::ceil(-1.2) << '\n';

	std::cout << smath::ceil(1.2) << '\n';
	std::cout << std::ceil(1.2) << '\n';

	std::cout << smath::ceil(2.7) << '\n';
	std::cout << std::ceil(2.7) << '\n';

	std::cout << smath::ceil(3) << '\n';
	std::cout << std::ceil(3) << '\n';
	std::cout << '\n';
}

/**
 * Test the conversion between degrees and radians
 */
void test_convert_radians_degrees() {
	std::cout << "-------- CONVERTING --------\n";
	std::cout << smath::to_radians(180.0f) << '\n';
	std::cout << smath::to_radians(90.0f) << '\n';
	std::cout << smath::to_radians(45.0f) << '\n';
	std::cout << smath::to_radians(1.0f) << '\n';

	std::cout << smath::to_degrees(3.1416f) << '\n';
	std::cout << smath::to_degrees(1.573f) << '\n';
	std::cout << '\n';
}

/**
 * Test the scaling of a number to a new range
 */
void test_scale() {
	std::cout << "-------- SCALE --------\n";
	std::cout << smath::scale(3, 1, 10, 1, 100) << '\n';
	std::cout << smath::scale(27, 11, 40, 1, 100) << '\n';
	std::cout << smath::scale(1.0f, 0.1f, 4.0f, 1.0f, 100.0f) << '\n';
	std::cout << '\n';
}

/**
 * Test my implementation of 2-component vectors.
 */
void test_vec2() {
	std::cout << "-------- VECTOR 2f --------\n";

	smath::vec2 A{ 4.2f, 0.05f };
	smath::vec2 B{ 8.9f, 1.1f };

	smath::vec2 C{ B };
	C += A;

	std::cout << A.size() << '\n';
	std::cout << A[0] << '\n';

	std::cout << B[0] << '\n';
	std::cout << C << '\n';

	smath::vec2 D{ B * C };
	std::cout << D << '\n';

	smath::vec2 E{ 1.0f / B };
	std::cout << E << '\n';
	std::cout << '\n';
}

/**
 * Test my implementation of 3-component vectors.
 */
void test_vec3() {
	std::cout << "-------- VECTOR 3f --------\n";
	smath::vec3 A{ 4.2f, 0.05f, 8.12f };
	smath::vec3 B{ 8.9f, 1.1f, 3.14f };

	smath::vec3 C{ B };
	C += A;

	std::cout << A.size() << '\n';
	std::cout << A[0] << '\n';

	std::cout << B[0] << '\n';
	std::cout << '(' << C[0] << ", " << C[1] << ", " << C[2] << ")\n";

	smath::vec3 D{ B * C };
	std::cout << '(' << D.x << ", " << D.y << ", " << D.z << ")\n";

	smath::vec3 E{ 1.0f / B };
	std::cout << '(' << E.x << ", " << E.y << ", " << E.z << ")\n";
	std::cout << '\n';
}

/**
 * Test the differences between the constants
 */
void test_consts() {
	std::cout << "-------- CONSTS --------\n";
	std::cout << smath::constants::PI << '\n';
	std::cout << M_PI << '\n';

	std::cout << smath::constants::E << '\n';
	std::cout << M_E << '\n';
	std::cout << '\n';
}

/**
 * Main function for testing
 */
int main() {

	std::cout << '\n';

	test_max();
	test_min();
	test_abs();
	test_sqrt();
	test_round();
	test_floor();
	test_ceil();
	test_convert_radians_degrees();
	test_scale();
	test_vec2();
	test_vec3();
	test_consts();

	return 0;
}
