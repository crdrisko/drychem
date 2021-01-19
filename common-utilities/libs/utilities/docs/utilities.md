# Utilities

The utilities library consists of a number of miscellaneous functions and classes that either don't belong in one of the other libraries, don't have enough substance to warrant their own library, or exist only to assist other libraries in the project. I imagine as time goes on some of the modules within this library will spin-off into their own complete library, but for now this serves as a good place to collect them.

## Table Of Contents

- [Getting Started](#Getting-Started)
- [Features](#Features)
  - [Operators](#Operators)
  - [Testing](#Testing)
  - [Tuples](#Tuples)
- [Usage](#Usage)

## Getting Started

All the functions and classes belonging to the utilities library are wrapped in the namespace `DryChem`. Alternatively, each of the separate modules (Operators, Testing, etc.), have their own nested namespace in the `CppUtils` namespace. While either can be used, `DryChem` is preferred to provide a uniform interface for all portions of the library. The following line can be included in any user project to provide access to the utilities library:

```C++
#include <common-utils/utilities.hpp>
```

## Features

### Operators

- [Comparison Operators:](../../../include/common-utils/utilities/operators/comparisonOperators.hpp)

  The comparison operators portion of the utilities library serves to provide a robust way of implementing all comparison operators in terms of the `==` and `<` operators. Similar to how you would go about using the [`std::rel_opts`](https://en.cppreference.com/w/cpp/utility/rel_ops/operator_cmp), defining these two operators for your class gives you the remaining operators without having to hard code them yourself. The difference between the `CompletelyComparable<>` class template and `std::rel_opts` however, is that the `CompletelyComparable<>` class template when inherited via private inheritance, does not inject the additional operators into the global namespace. Rather we use friend functions and the curiously recurring template pattern (CRTP) to provide the limited interface we want.

  The other class templates, `EqualityComparable<>` and `LessThanComparable<>` aren't really designed to be used by the end user, but could be if really needed. Instead, they split the functionality up into logical components that when combined, give us the `CompletelyComparable<>` class. The `Empty` template parameter exists only to avoid inhibiting any optimizations (see below) the compiler may be able to make.

  For a good example of a project implementing the operators afforded by the `CompletelyComparable<>` class, check out the other project in this repository: [C++ Units](../../../../cpp-units), specifically the `PhysicalQuantity<>` class template. This class defines the comparison operators `operator==()` and `operator<()` then implements, via private inheritance, the rest of the comparison operators.

- [A Potentially Empty Base Class:](../../../include/common-utils/utilities/operators/potentiallyEmptyBaseClass.hpp)

  The empty base class optimization (EBCO) is an optimization strategy implemented by some compilers, which allows for empty classes deriving from other empty classes to contribute no additional memory. However, if two empty-base class derived classes are inherited by another class, this optimization is inhibited and both classes contribute to the memory. We can get around this by defining additional template parameters for potentially empty base classes, and use the curiously recurring template pattern (CRTP) in conjunction with the EBCO, to optimize, or rather let the compiler optimize, the traits and policies we intend to inherit. With this in mind, the `PotentiallyEmptyBaseClass<>` class template is a helper class for some of the operators and traits in the library. I don't imagine this class will get much use outside the repository, but examples of where it is used can be found with the [Comparison Operators](#Comparison-Operators) above.

---

### Testing

- [Performance Testing:](../../../include/common-utils/utilities/testing/performanceTesting.hpp)

  Often when I go to refactor some code I wonder if the changes I'm making are making the program faster or slower. The performanceTesting utility module consists of a simple function that times how long it takes to invoke a function. The `timeAndInvoke<>()` function template takes a function and a variable number of arguments and (depending on the return type of the function in question) can either return a structure containing the result of the function call and the time or just the time it took to invoke the function. Utilizing some features from C++17, the return type can be used as a structured binding as we can see in the example below. This interface provides a lightweight and easy way to visualize the time it takes each function to be called, while sacrificing very little in terms of readability.

  ```C++
  #include <common-utils/utilities.hpp>

  auto [result, time] = DryChem::timeAndInvoke(funcToCall, arg1, arg2, ..., argN);
  ```

  In this example, the `result` variable now contains the value returned from `funcToCall(arg1, arg2, ..., argN)`, and the `time` variable contains the time (in microseconds) it took to invoke `funcToCall`.

---

## Usage

For working examples of how to use the library, refer to the [testing](../tests) and/or [samples](../samples) directories, which together provide a comprehensive overview of the library's usage.

To build and run the code samples for the utilities library, one should include the `utils_build_samples=ON` option to the CMake instructions. Similarly, to build and run the unit tests for the individual utility functions, one should include the `utils_build_tests=ON` option, as shown in the code below:

```bash
cmake ../drychem/. -Dutils_build_samples=ON -Dutils_build_tests=ON
make

## Run the utility library's samples ##
cd bin/samples
./comparableExample

## Run the utility library's unit tests ##
cd ../tests
./testAllUtilityFunctions
```

*NOTE: The samples and tests will not be installed with the rest of the library. They exist only to extend the documentation and help the user navigate the library.*
