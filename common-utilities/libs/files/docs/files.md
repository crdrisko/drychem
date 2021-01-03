# Files

...

## Table Of Contents

- [Getting Started](#Getting-Started)
- [Features](#Features)
  - [...](#...)
- [Working Example](#Working-Example)

## Getting Started

All the functions and classes belonging to the file handling library are wrapped in the namespace `DryChem`. Alternatively, these functions and classes also have their own nested namespace in the `CppUtils` namespace, which can be called as `CppUtils::Files`. While either can be used, `DryChem` is preferred to provide a uniform interface for all portions of the library. The following line can be included in any user project to provide access to the files library:

```C++
#include <common-utils/files.hpp>
```

## Features

### ...

- [...:](../../../include/common-utils/files/...)

---

## Working Example

For working examples of how to use the library, refer to the [testing](../tests) and/or [samples](../samples) directories, which together provide a comprehensive overview of the library's usage.

To build and run the code samples for the file library, one should include the `utils_build_samples=ON` option to the CMake instructions. Similarly, to build and run the unit tests for the individual file handling functions, one should include the `utils_build_tests=ON` option, as shown in the code below:

```bash
cmake ../drychem/. -Dutils_build_samples=ON -Dutils_build_tests=ON
make

## Run the file library's samples ##
cd bin/samples
./...Example

## Run the file library's unit tests ##
cd ../tests
./testAllFileFunctions
```

*NOTE: The samples and tests will not be installed with the rest of the library. They exist only to extend the documentation and help the user navigate the library.*
