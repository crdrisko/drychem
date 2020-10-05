# Utilities

The utilities library consists of a number of miscellaneous functions and classes that either don't belong in one of the other libraries, don't have enough substance to warrant their own library, or exist only to assist other libraries in the project. I imagine as time goes on some of the modules within this library will spin-off into their own complete library, but for now this serves as a good place to collect them.

## Table Of Contents

- [Getting Started](#Getting-Started)
- [Features](#Features)
  - [Comparison Operators](#Comparison-Operators)
  - [Miscellaneous Utilities](#Miscellaneous-Utilities)
- [Working Example](#Working-Example)

## Getting Started

The following lines of code can be included in any user project to provide access to the utilities library:

```C++
#include <common-utils/utilities.hpp>

using namespace CommonUtilities::Utilities;
```

## Features

### [Comparison Operators](../../../include/common-utils/utilities/operators)

The comparison operators portion of the utilities library serves to provide a robust way of implementing all comparison operators in terms of the `==` and `<` operators. Similar to how you would go about using the [`std::rel_opts`](https://en.cppreference.com/w/cpp/utility/rel_ops/operator_cmp), defining these two operators for your class gives you the remaining operators without having to hard code them yourself. The difference between the `CompletelyComparable<>` class template and `std::rel_opts` however, is that the `CompletelyComparable<>` class template when inherited via private inheritance, does not inject the additional operators into the global namespace. Rather we use friend functions and the curiously recurring template pattern (CRTP) to provide the limited interface we want.

The other class templates, `EqualityComparable<>` and `LessThanComparable<>` aren't really designed to be used by the end user, but could be if really needed. Instead, they split the functionality up into logical components that when combined, give us the `CompletelyComparable<>` class. The `Empty` template parameter exists only to avoid inhibiting any optimizations (see below) the compiler may be able to make.

For a good example of a project implementing the operators afforded by the `CompletelyComparable<>` class, check out the other project in this repository: [C++ Units](../../../../cpp-units), specifically the `PhysicalQuantity<>` class template. This class defines the comparison operators `operator==()` and `operator<()` then implements, via private inheritance, the rest of the comparison operators.

### [Miscellaneous Utilities](../../../include/common-utils/utilities/utils)

The empty base class optimization (EBCO) is an optimization strategy implemented by some compilers, which allows for empty classes deriving from other empty classes to contribute no additional memory. However, if two empty-base class derived classes are inherited by another class, this optimization is inhibited and both classes contribute to the memory. We can get around this by defining additional template parameters for potentially empty base classes, and use the curiously recurring template pattern (CRTP) in conjunction with the EBCO, to optimize, or rather let the compiler optimize, the traits and policies we intend to inherit. With this in mind, the `PotentiallyEmptyBaseClass<>` class template is a helper class for some of the operators and traits in the library. I don't imagine this class will get much use outside the repository, but examples of where it is used can be found with the [Comparison Operators](#Comparison-Operators) above.

## Working Example

For working examples of how to use the library, refer to the [testing](../tests) files or the [samples](../samples) directory, which together provide a comprehensive overview of the library's usage.

To build and run the code samples for the utilities library, one should include the `utils_build_samples=ON` option to the CMake instructions. Similarly, to build and run the unit tests for the individual utility functions, one should include the `utils_build_tests=ON` option, as shown in the code below:

```bash
cmake ../cpp-units/. -Dutils_build_samples=ON -Dutils_build_tests=ON
make

## Run the utility library's samples ##
cd bin/samples
./comparableExample

## Run the utility library's unit tests ##
cd ../tests
./testAllUtilityFunctions
```

*NOTE: the samples and tests will not be installed with the rest of the library. They exist only to extend the documentation and help the user navigate the library.*