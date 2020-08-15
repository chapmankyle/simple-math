#include <iostream>
#include <cmath>
#include <iomanip>
#include <typeinfo>

#include "include/smath.hpp"

/**
 * Test the smath::max function against std::max
 */
void test_max() {
	std::cout << "-------- MAX --------\n";
	std::cout << smath::max(3, 5) << '\n';
	std::cout << std::max(3, 5) << '\n';

	std::cout << smath::max(8.4f, 5.2f) << '\n';
	std::cout << std::max(8.4f, 5.2f) << '\n';

	std::cout << smath::max('a', 'z') << '\n';
	std::cout << std::max('a', 'z') << '\n';

	std::cout << smath::max('A', 'Z') << '\n';
	std::cout << std::max('A', 'Z') << '\n';

	std::cout << smath::max('A', 'z') << '\n';
	std::cout << std::max('A', 'z') << '\n';

	std::cout << '\n';
}

/**
 * Test the smath::min function against std::min
 */
void test_min() {
	std::cout << "-------- MIN --------\n";
	std::cout << smath::min(3, 5) << '\n';
	std::cout << std::min(3, 5) << '\n';

	std::cout << smath::min(8.4f, 5.2f) << '\n';
	std::cout << std::min(8.4f, 5.2f) << '\n';

	std::cout << smath::min('a', 'z') << '\n';
	std::cout << std::min('a', 'z') << '\n';

	std::cout << smath::min('A', 'Z') << '\n';
	std::cout << std::min('A', 'Z') << '\n';

	std::cout << smath::min('A', 'z') << '\n';
	std::cout << std::min('A', 'z') << '\n';
	std::cout << '\n';
}

/**
 * Test the smath::abs function against std::abs
 */
void test_abs() {
	std::cout << "-------- ABS --------\n";
	std::cout << smath::abs(-9.2) << '\n';
	std::cout << std::abs(-9.2) << '\n';

	std::cout << smath::abs(17) << '\n';
	std::cout << std::abs(17) << '\n';
	std::cout << '\n';
}

/**
 * Test the smath::sqrt function against std::sqrt
 */
void test_sqrt() {
	std::cout << "-------- SQRT --------\n";
	std::cout << std::setprecision(16);

	std::cout << smath::sqrt(2.0f) << '\n';
	std::cout << std::sqrt(2.0f) << '\n';
	std::cout << smath::sqrt(2.0) << '\n';
	std::cout << std::sqrt(2.0) << '\n';
	std::cout << '\n';

	std::cout << smath::sqrt(4.0f) << '\n';
	std::cout << std::sqrt(4.0f) << '\n';
	std::cout << smath::sqrt(4.0) << '\n';
	std::cout << std::sqrt(4.0) << '\n';
	std::cout << '\n';

	std::cout << smath::sqrt(16.0f) << '\n';
	std::cout << std::sqrt(16.0f) << '\n';
	std::cout << smath::sqrt(16.0) << '\n';
	std::cout << std::sqrt(16.0) << '\n';
	std::cout << '\n';
}

/**
 * Test the smath::round function against std::round
 */
void test_round() {
	std::cout << "-------- ROUND --------\n";
	std::cout << smath::round(7.2f) << '\n';
	std::cout << std::round(7.2f) << '\n';

	std::cout << smath::round(7.6) << '\n';
	std::cout << std::round(7.6) << '\n';

	std::cout << smath::round(2) << '\n';
	std::cout << std::round(2) << '\n';

	std::cout << smath::round_nearest(38, 10) << '\n';
	std::cout << smath::round_nearest(12.5, 5) << '\n';
	std::cout << '\n';
}

/**
 * Test the smath::floor function against std::floor
 */
void test_floor() {
	std::cout << "-------- FLOOR --------\n";
	std::cout << smath::floor(0) << '\n';
	std::cout << std::floor(0) << '\n';

	std::cout << smath::floor(-1.2) << '\n';
	std::cout << std::floor(-1.2) << '\n';

	std::cout << smath::floor(1.2) << '\n';
	std::cout << std::floor(1.2) << '\n';

	std::cout << smath::floor(2.7) << '\n';
	std::cout << std::floor(2.7) << '\n';

	std::cout << smath::floor(3) << '\n';
	std::cout << std::floor(3) << '\n';
	std::cout << '\n';
	std::log(3);
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
 * Test the differences between the constants
 */
void test_consts() {
	std::cout << "-------- CONSTS --------\n";
	std::cout << smath::PI << '\n';
	std::cout << M_PI << '\n';

	std::cout << smath::E << '\n';
	std::cout << M_E << '\n';
	std::cout << '\n';
}

/**
 * Main function for testing
 */
int main() {

	test_max();
	test_min();
	test_abs();
	test_sqrt();
	test_round();
	test_floor();
	test_ceil();
	test_convert_radians_degrees();
	test_scale();
	test_consts();

	return 0;
}
