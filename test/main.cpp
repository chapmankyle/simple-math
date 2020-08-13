#include <iostream>
#include "include/math.hpp"

int main() {

	std::cout << smath::max(3, 5) << '\n';
	std::cout << smath::max(8.4f, 5.2f) << '\n';
	std::cout << smath::max('a', 'z') << '\n';
	std::cout << smath::max('A', 'Z') << '\n';
	std::cout << smath::max('A', 'z') << '\n';

	std::cout << smath::sqrt(4.0) << '\n';
	std::cout << smath::sqrt(16.0) << '\n';

	return 0;
}
