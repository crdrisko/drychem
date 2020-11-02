# Math

The math library consists of a number of different functions and classes related to different fields in mathematics. The calculus module consists of functions and algorithms related to numerical differentiation and integration, while the statistics module contains functions and algorithms related to, you guessed it, statistics. There are also some standard library container wrappers and type traits for classifying containers according to the member functions and types it has. The following documentation describes the usage and motivation for the library.

## Table Of Contents

- [Getting Started](#Getting-Started)
- [Features](#Features)
  - [Calculus](#Calculus)
  - [Containers](#Containers)
  - [Statistics](#Statistics)
  - [Traits](#Traits)
  - [Math Utilities](#Math-Utilities)
- [Usage](#Usage)

## Getting Started

The following lines of code can be included in any user project to provide access to the math library:

```C++
#include <common-utils/math.hpp>

using namespace CppUtils::Math;
```

## Features

### Calculus

- [Differentiation:](../../../include/common-utils/math/calculus/differentiation.hpp)

  In the differentiation portion of the math library, three finite difference method (FDM) functions are provided for approximating the derivative of a given function. The methods implemented in this library are the forward difference method, the backwards difference method, and finally, the centered difference method. One thing to note when using either the forward or the backwards difference method is the output vector will have a size one less than the input container's sizes.
  
  The centered difference method, which is effectively an average of the forward and backwards methods, will, by default, approximate the edge cases using the finite and backwards methods. These points will be less accurate than the middle elements of the returned vector, but serve to keep the size of the returned vector equal to those of the input containers. This can be turned off using the `correctBoundaries` flag.

  All FDM methods take four iterators, two from the first container and two from the second container. The first two represent the independent variable in the function, while the second two iterators represent the dependent variable. Put another way, we are differentiating the second two iterators with respect to the first two. The iterator interface allows us to 1) use any conforming container range we want, and 2) differentiate over a range other than just the full container. While the templated interface of the functions may look intimidating, all template parameters can be correctly deduced by the compiler without any specifications from the end user. The interfaces were designed this way to accomodate the `PhysicalQuantity` type in the CppUnits library without any change in how you would call the given function for a built-in type.

  The `centeredDifferenceMethod()` function was based loosely off NumPy's `gradient()` function, which you can read more about [here](https://numpy.org/doc/stable/reference/generated/numpy.gradient.html).

- [Integration:](../../../include/common-utils/math/calculus/integration.hpp)

  The integration portion of the math library consists of one main function template, `cumulativeTrapzIntegration()`, and another helper function, `trapz()`, that our main function calls.
  
  The interface of the `cumulativeTrapzIntegration()` function is nearly identical to those of the differentiation module, so consult that documentation for more information. Where the two methods differ is in the optional parameter: `initialValue`. By default, no value is specified for `initialValue`, and as such, the function returns a `std::vector<>` with one less element than the original container sizes. If a value is specified (note it should usually be a value of 0), this value becomes the first element of the returned container and all subsequent values depend on it. The returned container when an initial value is specified has the same size as the input containers.

  This function was based loosely off SciPy's `cumtrapz()` function, which you can read more about [here](https://docs.scipy.org/doc/scipy/reference/generated/scipy.integrate.cumtrapz.html).

---

### Containers

- [Vector3D:](../../../include/common-utils/math/containers/vector3D.hpp)

---

### Statistics

- [Linear Least Squares Fitting:](../../../include/common-utils/math/statistics/linearLeastSquaresFitting.hpp)

- [General Statistical Functions:](../../../include/common-utils/math/statistics/statistics.hpp)

---

### Traits

- [Container Traits:](../../../include/common-utils/math/traits/containerTraits.hpp)

  The container traits folder consists of a number of predicate type traits that classify a given container according to the member functions and types it contains. Following the standard library's naming system, each of the type traits is in all lowercase, with underscores separating the individual words. A convinence variable template is provided to help shorten the use cases:

  ```C++
  Math::is_container<std::vector<int>>::value;  // yields true
  Math::is_container_v<std::vector<int>>;       // yields true
  ```

  The testing module for this specific part of the library is probably more useful than any desciption I could write, so you can look at the example usage [here](../tests/testTraits/testContainerTraits.hpp).

---

### Math Utilities

- [Basic Mathematical Functions:](../../../include/common-utils/math/utils/basicMath.hpp)

  By the way of basic math utilities, we have a couple helper functions that mainly can be used in `if` statements. `isEven` and `isOdd` both return a boolean if the passed integral type fits the classification of being even or odd, respectively. The `withinRange<>` function template performs some simple bounds checking and determines whether a given value is within a min and max value. All of these predicate functions can be used to simplify conditionals while giving the user a clean interface.

  This part of the library also provides a little function to interpolate values along a given vector. By passing the `linearlyInterpolate<>()` function a `std::vector` to interpolate a long and the bounds of the interpolation, the function spits out a `std::vector` who's slope is linear from the lower to upper bound.

- [Error Handling:](../../../include/common-utils/math/utils/mathExceptions.hpp)

  All the major advanced mathematical functions (`linearLeastSquaresFitting()`, `centeredDifferenceMethod()`, etc.) have the requirement that the sizes of the two containers we iterate over are the same. Since this would require a lot of repitition going through the `FatalException` interface, it was decided that a new, specialized exception type should be defined. This exception type, `InputSizeMismatch` derives from our `FatalException` class but controls the error message that is printed. Thus, all math functions that throw this exception will have the same basic message. The only difference between them is the file name and location of the error, a feature added with version 3.0 of the error library.

---

## Usage

For working examples of how to use the library, refer to the [testing](../tests) and/or [samples](../samples) directories, which together provide a comprehensive overview of the library's usage.

To build and run the code samples for the math library, one should include the `utils_build_samples=ON` option to the CMake instructions. Similarly, to build and run the unit tests for the individual math functions, one should include the `utils_build_tests=ON` option, as shown in the code below:

```bash
cmake ../cpp-units/. -Dutils_build_samples=ON -Dutils_build_tests=ON
make

## Run the math library's samples ##
cd bin/samples
./finiteDifferencesExample

## Run the math library's unit tests ##
cd ../tests
./testAllMathFunctions
```

*NOTE: the samples and tests will not be installed with the rest of the library. They exist only to extend the documentation and help the user navigate the library.*
