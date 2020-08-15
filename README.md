<h1 align="center">smath</h1>

<p align="center">
  <img src="https://img.shields.io/github/license/chapmankyle/simple-math.svg?" alt="license: GPL-3.0"></img>
</p>

A header-only C++ math library designed for use in graphics software :tv: :art:

<em>smath</em> is written in C++17, is platform independent and has no external dependencies.
Performance was favoured over accuracy for some of the functions, and currently only a small 
set of functions have been implemented. 

## Setup :rocket:
Clone the repository and navigate to the `simple-math` directory.
```bash
# clone the repo
git clone https://github.com/chapmankyle/simple-math.git

# navigate to the `simple-math` directory
cd simple-math
```

## Usage :page_with_curl:
Include the `include` directory into your project folder, then you can use the headers as follows:
```c++
#include <iostream>
#include "smath.hpp" // for all features

int main() {
  std::cout << smath::to_radians(90.f) << '\n';
}
```
