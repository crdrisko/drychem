# Strings

...

## Table Of Contents

- [Getting Started](#Getting-Started)
- [Features](#Features)
  - [String Type Traits](#String-Type-Traits)
  - [String Utilities](#String-Utilities)
- [Working Example](#Working-Example)

## Getting Started

All the functions and classes belonging to the strings library are wrapped in the namespace `DryChem`. Alternatively, these functions and classes also have their own nested namespace in the `CppUtils` namespace, which can be called as `CppUtils::Strings`. While either can be used, `DryChem` is preferred to provide a uniform interface for all portions of the library. The following line can be included in any user project to provide access to the strings library:

```C++
#include <common-utils/strings.hpp>
```

## Features

### String Type Traits

- [Case-Insensitive Strings:](../../../include/common-utils/strings/traits/ciString.hpp)

  ...

---

### String Utilities

- [Lexical Casting:](../../../include/common-utils/strings/utils/lexical_cast.hpp)

  ...

- [String Function Wrappers:](../../../include/common-utils/strings/utils/stringUtils.hpp)

  ...

- [Tokenizer:](../../../include/common-utils/strings/utils/tokenizer.hpp)

  ...

---

## Working Example

For working examples of how to use the library, refer to the [testing](../tests) and/or [samples](../samples) directories, which together provide a comprehensive overview of the library's usage.

To build and run the code samples for the string library, one should include the `utils_build_samples=ON` option to the CMake instructions. Similarly, to build and run the unit tests for the individual error functions, one should include the `utils_build_tests=ON` option, as shown in the code below:

```bash
cmake ../cpp-units/. -Dutils_build_samples=ON -Dutils_build_tests=ON
make

## Run the string library's samples ##
cd bin/samples
./ciTokenizerExample.cpp

## Run the string library's unit tests ##
cd ../tests
./testAllStringFunctions
```

*NOTE: The samples and tests will not be installed with the rest of the library. They exist only to extend the documentation and help the user navigate the library.*
