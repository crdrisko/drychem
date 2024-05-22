# Networking

The networking library...

## Table Of Contents

- [Getting Started](#Getting-Started)
- [Features](#Features)
  - [](#)
  - [Networking Utilities](#Networking-Utilities)
- [Usage](#Usage)

## Getting Started

All the functions and classes belonging to the networking library are wrapped in the namespace `DryChem`. Alternatively, these functions and classes also have their own nested namespace in the `CppUtils` namespace, which can be called as `CppUtils::Networking`. While either can be used, `DryChem` is preferred to provide a uniform interface for all portions of the library. The following line can be included in any user project to provide access to the networking library:

```C++
#include <common-utils/networking.hpp>
```

## Features

### 

- [:](../../../include/common-utils/math/calculus/differentiation.hpp)

  ...

---

### Networking Utilities

- [:](../../../include/common-utils/networking/utils/networkingHeaders.hpp)

  ...

- [Error Handling:](../../../include/common-utils/math/utils/mathExceptions.hpp)

  ...

---

## Usage

For working examples of how to use the library, refer to the [testing](../tests) and/or [samples](../samples) directories, which together provide a comprehensive overview of the library's usage.

To build and run the code samples for the networking library, one should include the `utils_build_samples=ON` option to the CMake instructions. Similarly, to build and run the unit tests for the individual networking functions, one should include the `utils_build_tests=ON` option, as shown in the code below:

```bash
cmake ../drychem/. -Dutils_build_samples=ON -Dutils_build_tests=ON
make

## Run the networking library's samples ##
cd bin/samples
./finiteDifferencesExample

## Run the networking library's unit tests ##
cd ../tests
./testAllNetworkingFunctions
```

*NOTE: The samples and tests will not be installed with the rest of the library. They exist only to extend the documentation and help the user navigate the library.*
