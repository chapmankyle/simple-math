#pragma once

#ifndef CONSTANTS_H
#define CONSTANTS_H

namespace smath {

	namespace constants {
		inline constexpr double PI   { 3.14159265358979323846 }; // pi
		inline constexpr double TWOPI{ 6.28318530717958647693 }; // 2*pi
		inline constexpr double PI2  { 1.57079632679489661923 }; // pi/2
		inline constexpr double PI4  { 0.78539816339744830962 }; // pi/4

		inline constexpr double RAD{ 0.01745329251994329577 }; // pi/180 (1 radians = RAD degrees)
		inline constexpr double DEG{ 57.2957795130823208768 }; // 180/pi (1 degree = DEG radians)

		inline constexpr double E     { 2.7182818284590452354 }; // e
		inline constexpr double LOG2E { 1.4426950408889634074 }; // log_2 e
		inline constexpr double LOG10E{ 0.4342944819032518277 }; // log_10 e
		inline constexpr double LN2   { 0.6931471805599453094 }; // log_e 2
		inline constexpr double LN10  { 2.3025850929940456840 }; // log_e 10

		inline constexpr double SQRT2{ 1.41421356237309504880 }; // sqrt(2)

	} // namespace constants

} // namespace smath

#endif
