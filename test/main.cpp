#include <iostream>
#include <cmath>
#include <iomanip>
#include <typeinfo>

#include "include/smath.hpp"

int main() {

	std::cout << smath::max(3, 5) << '\n';
	std::cout << smath::max(8.4f, 5.2f) << '\n';
	std::cout << smath::max('a', 'z') << '\n';
	std::cout << smath::max('A', 'Z') << '\n';
	std::cout << smath::max('A', 'z') << '\n';
	std::cout << '\n';

	std::cout << std::setprecision(16);
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

	std::cout << M_PI << '\n';
	std::cout << smath::PI << '\n';

	return 0;
}
