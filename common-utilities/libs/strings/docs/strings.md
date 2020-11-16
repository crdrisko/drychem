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

  Because the standard library designed the `std::basic_string<>` to be easily specialized with user-defined character traits, we made use of that here by creating case-insensitive character traits. Combining these traits with the `std::basic_string<>`, we can create a string that is also case-insensitive. Whenever the characters in a `ci_string` are compared, they are first converted to uppercase and then compared. For example a comparison between the letters 'c' and 'C' would result in a match.

---

### String Utilities

- [Lexical Casting:](../../../include/common-utils/strings/utils/lexical_cast.hpp)

  In order to allow the `Tokenizer<>` class (see below) to convert strings to other types when splitting on delimiters, a function needed to be able to convert the string to the correct type, preferable by not doing too much more work on built-in types where functions like this already exist. Thus, the `lexical_cast<>` function template was born. For built-in types, the standard library functions are used (i.e. `std::stold()`, `std::stoi()`, etc.), whereas for everything else, the string we are converting from is placed into an input stream and streamed into the type we want. This only works if the type we are trying to convert to has a overloaded `operator>>()` function and could result in some error messages if the stream fails. The testing files show some examples of how to use this in practice.

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

  The `Tokenizer<>` class template is likely the feature we will use the most from this strings library. The main idea behind it is to take an input string, either the full string or a range defined by iterators, and return the individual tokens that exist between specified delimiters. By default these delimiters are spaces, tabs, and newlines but they can be any set of characters the user needs. The one public member function of the `Tokenizer<>` class is the `split<>()` function template. It is templated because it can return any container the user desires but defaults to a `std::vector<std::basic_string<char, CharTraits>>` where `CharTraits` are what the `Tokenizer<>` class is templated on. The only restrictions to what type the user can return is that it must be an allocator-aware container that does not have a `mapped_type` member. Returning a container of a type other than a string is fine as well, as long as type can be lexically cast from a string to the desired type (see above).

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
