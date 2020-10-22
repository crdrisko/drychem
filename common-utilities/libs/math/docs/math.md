# Math

The math library consists of a number of advanced mathematical functions and classes, providing an easy-to-use interface. Some of the functions offered in this library include:

- Linear interpolation
- Linear least squares fitting
- Numerical integration
- Numerical differentiation

**Getting Started:**

The following lines of code can be included in any user project to provide access to the math module:

```C++
#include <common-utils/math.hpp>

using namespace CppUtils::Math;
```

For examples of how to use the advanced mathematical classes and functions, refer to the [testing](https://github.com/crdrisko/common-utilities/tree/master/test/TestMath/testMathFunctions.cpp) files, which provide a comprehensive overview of the module's usage.

## Containers

This module provides classes that wrap some of the standard library containers, such as `std::array`, `std::vector`, etc. providing a limited interface responsible for ease-of-use in other programs. For example, the `Vector3D` class template wraps a `std::array` with three elements to simulate a vector in physics or mathematics with x, y, and z components.

**Getting Started:**

The following lines of code can be included in any user project to provide access to the containers module:

```C++
#include <common-utils/containers.hpp>

using namespace CppUtils::Containers;
```

For more examples of how to use the containers module, refer to the [testing](https://github.com/crdrisko/common-utilities/tree/master/test/TestContainers/testContainerFunctions.cpp) files, which provide a comprehensive overview of the module's usage.
