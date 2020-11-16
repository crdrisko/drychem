# Strings

The strings library is a collection of functions and classes related to the manipulation and handling of strings. The library provides a tokenizer class for splitting strings on certain delimiters and a new specialization of a `std::basic_string<>` for case-insensitive string comparisons. Some additional functionality exists but these two features are the main components of the library.

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

  Because the `std::string::find()` member function returns `std::string::npos` (a large positive number) when a substring or character isn't found in the larger string, conversions to bool are problematic. For that reason, the `foundSubstr()` function was introduced to alleviate this problem. Providing a simple wrapper for the `std::string::find()` function, `foundSubstr()` returns `true` if the substring was found in the larger string and `false` if `std::string::npos` was returned. This allows usage like the following:

  ```C++
  #include <string>

  #include <common-utils/strings.hpp>

  std::string str {"Hello World"};

  if (DryChem::foundSubstr('!', str))
      std::cout << str << '\n';
  else
      std::cout << str << "!\n";
  ```

- [Tokenizer:](../../../include/common-utils/strings/utils/tokenizer.hpp)

  ...

---

## Working Example

For working examples of how to use the library, refer to the [testing](../tests) and/or [samples](../samples) directories, which together provide a comprehensive overview of the library's usage.

To build and run the code samples for the string library, one should include the `utils_build_samples=ON` option to the CMake instructions. Similarly, to build and run the unit tests for the individual string functions, one should include the `utils_build_tests=ON` option, as shown in the code below:

```bash
cmake ../drychem/. -Dutils_build_samples=ON -Dutils_build_tests=ON
make

## Run the string library's samples ##
cd bin/samples
./ciTokenizerExample.cpp

## Run the string library's unit tests ##
cd ../tests
./testAllStringFunctions
```

*NOTE: The samples and tests will not be installed with the rest of the library. They exist only to extend the documentation and help the user navigate the library.*
