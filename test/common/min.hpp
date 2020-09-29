#pragma once

#ifndef TEST_COMMON_MIN_H
#define TEST_COMMON_MIN_H

#include "../utils.hpp"
#include "smath/math.hpp"

#include <cmath>
#include <iostream>

namespace test {

	/**
	 * @brief Test cases for the `smath::min` function
	 */
	class Min {

	private:

		/**
		 * @brief Test with integer inputs.
		 */
		static int integers() {
			int errors = 0;

			errors += (smath::min(3, 4) == std::min(3, 4) ? 0 : 1);
			errors += (smath::min(23, 23) == std::min(23, 23) ? 0 : 1);
			errors += (smath::min(1000203, 1000202) == std::min(1000203, 1000202) ? 0 : 1);
			errors += (smath::min(-2, -10) == std::min(-2, -10) ? 0 : 1);
			errors += (smath::min(-62, -62) == std::min(-62, -62) ? 0 : 1);
			errors += (smath::min(-88, -213) == std::min(-88, -213) ? 0 : 1);
			errors += (smath::min(-183026, -183028) == std::min(-183026, -183028) ? 0 : 1);
			errors += (smath::min(-1849264, 82) == std::min(-1849264, 82) ? 0 : 1);
			errors += (smath::min(82, -1849264) == std::min(82, -1849264) ? 0 : 1);

			std::cout << "[integers] : " << RESULT(errors) << '\n';
			return errors;
		}

		/**
		 * @brief Test with single precision inputs.
		 */
		static int floats() {
			int errors = 0;

			errors += (smath::min(3.2f, 4.8f) == std::min(3.2f, 4.8f) ? 0 : 1);
			errors += (smath::min(23.2f, 23.2f) == std::min(23.2f, 23.2f) ? 0 : 1);
			errors += (smath::min(10.02341f, 10.02340f) == std::min(10.02341f, 10.02340f) ? 0 : 1);
			errors += (smath::min(-2.35f, -10.47f) == std::min(-2.35f, -10.47f) ? 0 : 1);
			errors += (smath::min(-62.3429f, -62.3429f) == std::min(-62.3429f, -62.3429f) ? 0 : 1);
			errors += (smath::min(-88.98f, -213.9502f) == std::min(-88.98f, -213.9502f) ? 0 : 1);
			errors += (smath::min(-1830.26f, -1830.28f) == std::min(-1830.26f, -1830.28f) ? 0 : 1);
			errors += (smath::min(-1.849264f, 8.2274f) == std::min(-1.849264f, 8.2274f) ? 0 : 1);
			errors += (smath::min(8.2274f, -1.849264f) == std::min(8.2274f, -1.849264f) ? 0 : 1);

			std::cout << "[floats]   : " << RESULT(errors) << '\n';
			return errors;
		}

		/**
		 * @brief Test with double precision inputs.
		 */
		static int doubles() {
			int errors = 0;

			errors += (smath::min(3.2145, 4.8) == std::min(3.2145, 4.8) ? 0 : 1);
			errors += (smath::min(23.2, 23.2) == std::min(23.2, 23.2) ? 0 : 1);
			errors += (smath::min(10.0234152901, 10.0234052901) == std::min(10.0234152901, 10.0234052901) ? 0 : 1);
			errors += (smath::min(-2.35, -10.47) == std::min(-2.35, -10.47) ? 0 : 1);
			errors += (smath::min(-62.3429, -62.3429) == std::min(-62.3429, -62.3429) ? 0 : 1);
			errors += (smath::min(-88.98, -213.9502) == std::min(-88.98, -213.9502) ? 0 : 1);
			errors += (smath::min(-1830.26, -1830.28) == std::min(-1830.26, -1830.28) ? 0 : 1);
			errors += (smath::min(-1.849264, 8.2274) == std::min(-1.849264, 8.2274) ? 0 : 1);
			errors += (smath::min(8.2274, 8.2274198) == std::min(8.2274, 8.2274198) ? 0 : 1);

			std::cout << "[doubles]  : " << RESULT(errors) << '\n';
			return errors;
		}

		/**
		 * @brief Test with character inputs.
		 */
		static int chars() {
			int errors = 0;

			errors += (smath::min('a', 'z') == std::min('a', 'z') ? 0 : 1);
			errors += (smath::min('A', 'z') == std::min('A', 'z') ? 0 : 1);
			errors += (smath::min('a', 'Z') == std::min('a', 'Z') ? 0 : 1);
			errors += (smath::min('A', 'Z') == std::min('A', 'Z') ? 0 : 1);
			errors += (smath::min('A', 'A') == std::min('A', 'A') ? 0 : 1);
			errors += (smath::min('Z', 'Z') == std::min('Z', 'Z') ? 0 : 1);
			errors += (smath::min('a', 'a') == std::min('a', 'a') ? 0 : 1);
			errors += (smath::min('z', 'z') == std::min('z', 'z') ? 0 : 1);

			std::cout << "[chars]    : " << RESULT(errors) << '\n';
			return errors;
		}

	public:

		/**
		 * @brief Runs all test cases.
		 * @returns Number of tests failed.
		 */
		static int run() {
			std::cout << "-- Testing \033[34msmath::min\033[0m --\n";
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

#endif // !TEST_COMMON_MIN_H
