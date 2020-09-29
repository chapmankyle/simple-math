#pragma once

#ifndef TEST_COMMON_ABS_H
#define TEST_COMMON_ABS_H

#include "../utils.hpp"
#include "smath/math.hpp"
#include "smath/vec1.hpp"

#include <iostream>

namespace test {

	/**
	 * @brief Test cases for the `smath::abs` function
	 */
	class Abs {

	private:

		/**
		 * @brief Test with integer inputs.
		 */
		static int integers() {
			int errors = 0;

			errors += (smath::abs(0) == 0 ? 0 : 1);
			errors += (smath::abs(3) == 3 ? 0 : 1);
			errors += (smath::abs(-3) == 3 ? 0 : 1);
			errors += (smath::abs(1000231) == 1000231 ? 0 : 1);
			errors += (smath::abs(12343) == 12343 ? 0 : 1);
			errors += (smath::abs(-38732) == 38732 ? 0 : 1);
			errors += (smath::abs(-28462) == 28462 ? 0 : 1);

			std::cout << "[integers] : " << RESULT(errors) << '\n';
			return errors;
		}

		/**
		 * @brief Test with single precision inputs.
		 */
		static int floats() {
			int errors = 0;

			errors += (smath::abs(0.0f) == 0.0f ? 0 : 1);
			errors += (smath::abs(3.2f) == 3.2f ? 0 : 1);
			errors += (smath::abs(-3.863f) == 3.863f ? 0 : 1);
			errors += (smath::abs(1000231.2946f) == 1000231.2946f ? 0 : 1);
			errors += (smath::abs(12.343f) == 12.343f ? 0 : 1);
			errors += (smath::abs(-3.8732f) == 3.8732f ? 0 : 1);
			errors += (smath::abs(-284.62f) == 284.62f ? 0 : 1);

			std::cout << "[floats]   : " << RESULT(errors) << '\n';
			return errors;
		}

		/**
		 * @brief Test with double precision inputs.
		 */
		static int doubles() {
			int errors = 0;

			errors += (smath::abs(0.0) == 0.0 ? 0 : 1);
			errors += (smath::abs(3.2) == 3.2 ? 0 : 1);
			errors += (smath::abs(-3.863) == 3.863 ? 0 : 1);
			errors += (smath::abs(1000231.2946) == 1000231.2946 ? 0 : 1);
			errors += (smath::abs(12.343) == 12.343 ? 0 : 1);
			errors += (smath::abs(-3.8732) == 3.8732 ? 0 : 1);
			errors += (smath::abs(-284.62) == 284.62 ? 0 : 1);

			std::cout << "[doubles]  : " << RESULT(errors) << '\n';
			return errors;
		}

		/**
		 * @brief Test with 1-dimensional vector inputs (float).
		 */
		static int vec1float() {
			int errors = 0;

			errors += (smath::abs(smath::vec1(-2.2f)) == smath::vec1(smath::abs(-2.2f)) ? 0 : 1);
			errors += (smath::abs(smath::vec1(2.2f)) == smath::vec1(smath::abs(2.2f)) ? 0 : 1);
			errors += (smath::abs(smath::vec1(-14.8302f)) == smath::vec1(smath::abs(-14.8302f)) ? 0 : 1);
			errors += (smath::abs(smath::vec1(942.91484f)) == smath::vec1(smath::abs(942.91484f)) ? 0 : 1);
			errors += (smath::abs(smath::vec1(0.0f)) == smath::vec1(smath::abs(0.0f)) ? 0 : 1);
			errors += (smath::abs(smath::vec1(-0.0f)) == smath::vec1(smath::abs(-0.0f)) ? 0 : 1);

			std::cout << "[vec1]     : " << RESULT(errors) << '\n';
			return errors;
		}

		/**
		 * @brief Test with 1-dimensional vector inputs (double).
		 */
		static int vec1double() {
			int errors = 0;

			errors += (smath::abs(smath::vec1d(-2.2)) == smath::vec1d(smath::abs(-2.2)) ? 0 : 1);
			errors += (smath::abs(smath::vec1d(2.2)) == smath::vec1d(smath::abs(2.2)) ? 0 : 1);
			errors += (smath::abs(smath::vec1d(-14.8302)) == smath::vec1d(smath::abs(-14.8302)) ? 0 : 1);
			errors += (smath::abs(smath::vec1d(942.91484)) == smath::vec1d(smath::abs(942.91484)) ? 0 : 1);
			errors += (smath::abs(smath::vec1d(0.0)) == smath::vec1d(smath::abs(0.0)) ? 0 : 1);
			errors += (smath::abs(smath::vec1d(-0.0)) == smath::vec1d(smath::abs(-0.0)) ? 0 : 1);

			std::cout << "[vec1d]    : " << RESULT(errors) << '\n';
			return errors;
		}

		/**
		 * @brief Test with 1-dimensional vector inputs (int).
		 */
		static int vec1int() {
			int errors = 0;

			errors += (smath::abs(smath::vec1i(-2)) == smath::vec1i(smath::abs(-2)) ? 0 : 1);
			errors += (smath::abs(smath::vec1i(2)) == smath::vec1i(smath::abs(2)) ? 0 : 1);
			errors += (smath::abs(smath::vec1i(-14)) == smath::vec1i(smath::abs(-14)) ? 0 : 1);
			errors += (smath::abs(smath::vec1i(942)) == smath::vec1i(smath::abs(942)) ? 0 : 1);
			errors += (smath::abs(smath::vec1i(0)) == smath::vec1i(smath::abs(0)) ? 0 : 1);
			errors += (smath::abs(smath::vec1i(-0)) == smath::vec1i(smath::abs(-0)) ? 0 : 1);

			std::cout << "[vec1i]    : " << RESULT(errors) << '\n';
			return errors;
		}

	public:

		/**
		 * @brief Runs all test cases.
		 * @returns Number of tests failed.
		 */
		static int run() {
			std::cout << "-- Testing \033[34msmath::abs\033[0m --\n";
			int errors = 0;

			errors += integers();
			errors += floats();
			errors += doubles();
			errors += vec1float();
			errors += vec1double();
			errors += vec1int();

			std::cout << '\n';
			return errors;
		}

	};

} // namespace test

#endif // !TEST_COMMON_ABS_H
