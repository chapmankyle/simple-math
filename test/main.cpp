#include <iostream>
#include <cmath>
#include <iomanip>
#include <typeinfo>

#include "include/smath.hpp"

/**
 * Test the smath::max function compared to std::max
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
 * Test the smath::min function compared to std::min
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
 * Test the smath::abs function compared to std::abs
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
 * Test the smath::sqrt function compared to std::sqrt
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
	test_consts();

	return 0;
}
