#pragma once

#ifndef TEST_COMMON_SQRT_H
#define TEST_COMMON_SQRT_H

#include "../utils.hpp"
#include "smath/exponential.hpp"
#include "smath/vec1.hpp"
#include "smath/vec2.hpp"
#include "smath/vec3.hpp"

#include <cmath>
#include <iostream>

namespace test {

	/**
	 * @brief Test cases for the `smath::sqrt` function
	 */
	class Sqrt {

	private:

		/**
		 * @brief Test with integer inputs.
		 */
		static int integers() {
			int errors = 0;

			errors += (smath::sqrt(4) == std::sqrt(4) ? 0 : 1);
			errors += (smath::sqrt(23) == std::sqrt(23) ? 0 : 1);
			errors += (smath::sqrt(82) == std::sqrt(82) ? 0 : 1);
			errors += (smath::sqrt(183028) == std::sqrt(183028) ? 0 : 1);
			errors += (smath::sqrt(1000202) == std::sqrt(1000202) ? 0 : 1);
			errors += (smath::sqrt(1849264) == std::sqrt(1849264) ? 0 : 1);

			std::cout << "[integers] : " << RESULT(errors) << '\n';
			return errors;
		}

		/**
		 * @brief Test with single precision inputs.
		 */
		static int floats() {
			int errors = 0;

			errors += (smath::sqrt(4.8f) == std::sqrt(4.8f) ? 0 : 1);
			errors += (smath::sqrt(8.2274f) == std::sqrt(8.2274f) ? 0 : 1);
			errors += (smath::sqrt(10.02340f) == std::sqrt(10.02340f) ? 0 : 1);
			errors += (smath::sqrt(23.2f) == std::sqrt(23.2f) ? 0 : 1);
			errors += (smath::sqrt(56.43f) == std::sqrt(56.43f) ? 0 : 1);
			errors += (smath::sqrt(87.5f) == std::sqrt(87.5f) ? 0 : 1);

			std::cout << "[floats]   : " << RESULT(errors) << '\n';
			return errors;
		}

		/**
		 * @brief Test with double precision inputs.
		 */
		static int doubles() {
			int errors = 0;

			errors += (smath::sqrt(4.8) == std::sqrt(4.8) ? 0 : 1);
			errors += (smath::sqrt(8.2274) == std::sqrt(8.2274) ? 0 : 1);
			errors += (smath::sqrt(10.02340) == std::sqrt(10.02340) ? 0 : 1);
			errors += (smath::sqrt(23.2) == std::sqrt(23.2) ? 0 : 1);
			errors += (smath::sqrt(56.43) == std::sqrt(56.43) ? 0 : 1);
			errors += (smath::sqrt(87.5) == std::sqrt(87.5) ? 0 : 1);

			std::cout << "[doubles]  : " << RESULT(errors) << '\n';
			return errors;
		}

		/**
		 * @brief Test with 1-dimensional vector inputs.
		 */
		static int vec1() {
			int errors = 0;

			errors += (smath::sqrt(smath::vec1d(4.0)) == smath::vec1d(std::sqrt(4.0)) ? 0 : 1);
			errors += (smath::sqrt(smath::vec1d(5.2)) == smath::vec1d(std::sqrt(5.2)) ? 0 : 1);
			errors += (smath::sqrt(smath::vec1d(16.5)) == smath::vec1d(std::sqrt(16.5)) ? 0 : 1);

			errors += (smath::sqrt(smath::vec1(4.0f)) == smath::vec1(std::sqrt(4.0f)) ? 0 : 1);
			errors += (smath::sqrt(smath::vec1(5.23957f)) == smath::vec1(std::sqrt(5.23957f)) ? 0 : 1);
			errors += (smath::sqrt(smath::vec1(25.0f)) == smath::vec1(std::sqrt(25.0f)) ? 0 : 1);

			std::cout << "[vec1]     : " << RESULT(errors) << '\n';
			return errors;
		}

		/**
		 * @brief Test with 2-dimensional vector inputs.
		 */
		static int vec2() {
			int errors = 0;

			errors += (smath::sqrt(smath::vec2d(4.0, 16.0)) == smath::vec2d(std::sqrt(4.0), std::sqrt(16.0)) ? 0 : 1);
			errors += (smath::sqrt(smath::vec2d(5.2, 8.94)) == smath::vec2d(std::sqrt(5.2), std::sqrt(8.94)) ? 0 : 1);
			errors += (smath::sqrt(smath::vec2d(16.5, 25.6)) == smath::vec2d(std::sqrt(16.5), std::sqrt(25.6)) ? 0 : 1);

			errors += (smath::sqrt(smath::vec2(4.0f, 16.0f)) == smath::vec2(std::sqrt(4.0f), std::sqrt(16.0f)) ? 0 : 1);
			errors += (smath::sqrt(smath::vec2(5.2f, 8.94f)) == smath::vec2(std::sqrt(5.2f), std::sqrt(8.94f)) ? 0 : 1);
			errors += (smath::sqrt(smath::vec2(16.5f, 25.6f)) == smath::vec2(std::sqrt(16.5f), std::sqrt(25.6f)) ? 0 : 1);

			std::cout << "[vec2]     : " << RESULT(errors) << '\n';
			return errors;
		}

	public:

		/**
		 * @brief Runs all test cases.
		 * @returns Number of tests failed.
		 */
		static int run() {
			std::cout << "-- Testing \033[34msmath::sqrt\033[0m --\n";
			int errors = 0;

			errors += integers();
			errors += floats();
			errors += doubles();
			errors += vec1();
			errors += vec2();

			std::cout << '\n';
			return errors;
		}

	};

} // namespace test

#endif // !TEST_COMMON_SQRT_H
