#pragma once

#ifndef TEST_UTILS_H
#define TEST_UTILS_H

namespace test {

#	define STR_PASS "\033[32mPass\033[0m"
#	define STR_FAIL "\033[31mFail\033[0m"

#	define RESULT(errors) (errors == 0 ? STR_PASS : STR_FAIL)

} // namespace test

#endif //!TEST_UTILS_H
