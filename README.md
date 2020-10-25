<h1 align="center">smath</h1>

<p align="center">
  <img src="https://img.shields.io/circleci/build/gh/chapmankyle/smath" alt="CircleCI"></img>
  <img src="https://img.shields.io/github/license/chapmankyle/smath.svg?" alt="license: GPL-3.0"></img>
  <img src="https://img.shields.io/github/v/release/chapmankyle/smath.svg?" alt="Release"></img>
</p>

A header-only C++ math library designed for use in graphics software :tv: :art:

<em>smath</em> is written in C++17, is platform independent and has no external dependencies.
Performance was favoured over accuracy for some of the functions, and currently only a small
set of functions have been implemented.

## Setup :rocket:
Clone the repository and navigate to the `smath` directory.
```bash
# clone the repo
git clone https://github.com/chapmankyle/smath.git

# navigate to the `smath` directory
cd smath
```

## Usage :page_with_curl:
You can use the headers by simply copying the `smath` folder into your project
root folder. Example:
```c++
#include "smath/smath.hpp" // for all features

int main() {
    // create 3-component vectors
    smath::vec3 A{ 16.f, 4.f, 64.f };
    smath::vec3 B{ -4.6f, 2.f, 3.5f };

    // apply functions to vectors
    smath::vec3 C{ smath::sqrt(A) };
    smath::vec3 D{ smath::abs(B) };

    // perform arithmetic operations on vectors
    smath::vec3 E{ C + D };
    smath::vec3 F{ 1.f / (A - D) };

    // use constants
    float f_pi = smath::constants::pi;
    double d_pi = smath::constants::pi;

    // convert between radians and degrees
    float rad = smath::radians(90.f);
    double deg = smath::degrees(d_pi);

    return 0;
}
```
