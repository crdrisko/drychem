# Meta

The metaprogramming library of the Common-Utilities project consists of functions and classes dedicated to ...

## Table Of Contents

- [Getting Started](#Getting-Started)
- [Features](#Features)
  - [Algorithms](#Algorithms)
  - [Traits](#Traits)
  - [Types](#Types)
- [Working Example](#Working-Example)

## Getting Started

All the functions and classes belonging to the metaprogramming library are wrapped in the namespace `DryChem`. Alternatively, these functions and classes also have their own nested namespace in the `CppUtils` namespace, which can be called as `CppUtils::Meta`. While either can be used, `DryChem` is preferred to provide a uniform interface for all portions of the library. The following line can be included in any user project to provide access to the metaprogramming library:

```C++
#include <common-utils/meta.hpp>
```

## Features

### Algorithms

- [Basic Algorithms](../../../include/common-utils/meta/algorithms/basicAlgorithms.hpp)

  ...

- [Reverse](../../../include/common-utils/meta/algorithms/reverseList.hpp)

  ...

---

### Traits

- [Container Traits:](../../../include/common-utils/meta/traits/containerTraits.hpp)

  The container traits folder consists of a number of predicate type traits that classify a given container according to the member functions and types it contains. Following the standard library's naming system, each of the type traits is in all lowercase, with underscores separating the individual words. A convenience variable template is provided to help shorten the use cases:

  ```C++
  DryChem::is_container<std::vector<int>>::value;  // yields true
  DryChem::is_container_v<std::vector<int>>;       // yields true
  ```

  The testing module for this specific part of the library is probably more useful than any desciption I could write, so you can look at the example usage [here](../tests/testTraits/testContainerTraits.hpp).

---

### Types

- [Integer Sequence Algorithms](../../../include/common-utils/meta/types/integer_sequences/integerSequenceAlgorithms.hpp)

  ...

- [Tuple Algorithms](../../../include/common-utils/meta/types/tuples/tupleAlgorithms.hpp)

  In addition to specializations for all the basic algorithms defined above, we have also defined a number of algorithms revolving around the `std::tuple` class template. Because heterogeneous collections like the `std::tuple` are fairly common but don't have the same interface as other standard containers; for this reason, basic algorithms have to be defined specifically for this type. One of the most fundamental algorithms for the `std::tuple` is the `select<>()` function template. It takes a tuple and a list of indices and constructs a new tuple in the desired order. We can define other algorithms like reversing a tuple in terms of the `select<>()` metafunction. We can also define an `apply_n<>()` function that applies a given function to a specified number of elements.

---

## Working Example

For working examples of how to use the library, refer to the [testing](../tests) and/or [samples](../samples) directories, which together provide a comprehensive overview of the library's usage.

To build and run the code samples for the metaprogramming library, one should include the `utils_build_samples=ON` option to the CMake instructions. Similarly, to build and run the unit tests for the individual meta functions, one should include the `utils_build_tests=ON` option, as shown in the code below:

```bash
cmake ../drychem/. -Dutils_build_samples=ON -Dutils_build_tests=ON
make

## Run the metaprogramming library's samples ##
cd bin/samples
./getOptsExample

## Run the metaprogramming library's unit tests ##
cd ../tests
./testAllMetaFunctions
```

*NOTE: The samples and tests will not be installed with the rest of the library. They exist only to extend the documentation and help the user navigate the library.*
