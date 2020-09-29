#pragma once

#ifndef TEST_COMMON_MAX_H
#define TEST_COMMON_MAX_H

#include "../utils.hpp"
#include "smath/math.hpp"

#include <cmath>
#include <iostream>

namespace test {

	/**
	 * @brief Test cases for the `smath::max` function
	 */
	class Max {

	private:

		/**
		 * @brief Test with integer inputs.
		 */
		static int integers() {
			int errors = 0;

			errors += (smath::max(3, 4) == std::max(3, 4) ? 0 : 1);
			errors += (smath::max(23, 23) == std::max(23, 23) ? 0 : 1);
			errors += (smath::max(1000203, 1000202) == std::max(1000203, 1000202) ? 0 : 1);
			errors += (smath::max(-2, -10) == std::max(-2, -10) ? 0 : 1);
			errors += (smath::max(-62, -62) == std::max(-62, -62) ? 0 : 1);
			errors += (smath::max(-88, -213) == std::max(-88, -213) ? 0 : 1);
			errors += (smath::max(-183026, -183028) == std::max(-183026, -183028) ? 0 : 1);
			errors += (smath::max(-1849264, 82) == std::max(-1849264, 82) ? 0 : 1);
			errors += (smath::max(82, -1849264) == std::max(82, -1849264) ? 0 : 1);

			std::cout << "[integers] : " << RESULT(errors) << '\n';
			return errors;
		}

		/**
		 * @brief Test with single precision inputs.
		 */
		static int floats() {
			int errors = 0;

			errors += (smath::max(3.2f, 4.8f) == std::max(3.2f, 4.8f) ? 0 : 1);
			errors += (smath::max(23.2f, 23.2f) == std::max(23.2f, 23.2f) ? 0 : 1);
			errors += (smath::max(10.02341f, 10.02340f) == std::max(10.02341f, 10.02340f) ? 0 : 1);
			errors += (smath::max(-2.35f, -10.47f) == std::max(-2.35f, -10.47f) ? 0 : 1);
			errors += (smath::max(-62.3429f, -62.3429f) == std::max(-62.3429f, -62.3429f) ? 0 : 1);
			errors += (smath::max(-88.98f, -213.9502f) == std::max(-88.98f, -213.9502f) ? 0 : 1);
			errors += (smath::max(-1830.26f, -1830.28f) == std::max(-1830.26f, -1830.28f) ? 0 : 1);
			errors += (smath::max(-1.849264f, 8.2274f) == std::max(-1.849264f, 8.2274f) ? 0 : 1);
			errors += (smath::max(8.2274f, -1.849264f) == std::max(8.2274f, -1.849264f) ? 0 : 1);

			std::cout << "[floats]   : " << RESULT(errors) << '\n';
			return errors;
		}

		/**
		 * @brief Test with double precision inputs.
		 */
		static int doubles() {
			int errors = 0;

			errors += (smath::max(3.2145, 4.8) == std::max(3.2145, 4.8) ? 0 : 1);
			errors += (smath::max(23.2, 23.2) == std::max(23.2, 23.2) ? 0 : 1);
			errors += (smath::max(10.0234152901, 10.0234052901) == std::max(10.0234152901, 10.0234052901) ? 0 : 1);
			errors += (smath::max(-2.35, -10.47) == std::max(-2.35, -10.47) ? 0 : 1);
			errors += (smath::max(-62.3429, -62.3429) == std::max(-62.3429, -62.3429) ? 0 : 1);
			errors += (smath::max(-88.98, -213.9502) == std::max(-88.98, -213.9502) ? 0 : 1);
			errors += (smath::max(-1830.26, -1830.28) == std::max(-1830.26, -1830.28) ? 0 : 1);
			errors += (smath::max(-1.849264, 8.2274) == std::max(-1.849264, 8.2274) ? 0 : 1);
			errors += (smath::max(8.2274, 8.2274198) == std::max(8.2274, 8.2274198) ? 0 : 1);

			std::cout << "[doubles]  : " << RESULT(errors) << '\n';
			return errors;
		}

		/**
		 * @brief Test with character inputs.
		 */
		static int chars() {
			int errors = 0;

			errors += (smath::max('a', 'z') == std::max('a', 'z') ? 0 : 1);
			errors += (smath::max('A', 'z') == std::max('A', 'z') ? 0 : 1);
			errors += (smath::max('a', 'Z') == std::max('a', 'Z') ? 0 : 1);
			errors += (smath::max('A', 'Z') == std::max('A', 'Z') ? 0 : 1);
			errors += (smath::max('A', 'A') == std::max('A', 'A') ? 0 : 1);
			errors += (smath::max('Z', 'Z') == std::max('Z', 'Z') ? 0 : 1);
			errors += (smath::max('a', 'a') == std::max('a', 'a') ? 0 : 1);
			errors += (smath::max('z', 'z') == std::max('z', 'z') ? 0 : 1);

			std::cout << "[chars]    : " << RESULT(errors) << '\n';
			return errors;
		}

	public:

		/**
		 * @brief Runs all test cases.
		 * @returns Number of tests failed.
		 */
		static int run() {
			std::cout << "-- Testing \033[34msmath::max\033[0m --\n";
			int errors = 0;

			errors += integers();
			errors += floats();
			errors += doubles();
			errors += chars();

			std::cout << '\n';
			return errors;
		}

	};

} // namespace test

#endif // !TEST_COMMON_MAX_H
