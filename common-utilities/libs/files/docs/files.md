# Files

The file handling library of the Common-Utilities project consists of functions and classes dedicated to the parsing of input files. When working on the command line, efficiently reading and utilizing files is a must. This library seeks to provide as efficient a method as possible while also providing an easy-to-use *and* easy-to-extend interface for file parsing and handling.

## Table Of Contents

- [Getting Started](#Getting-Started)
- [Features](#Features)
  - [File Parsing](#File-Parsing)
  - [File Handling Utilities](#File-Handling-Utilities)
- [Working Example](#Working-Example)

## Getting Started

All the functions and classes belonging to the file handling library are wrapped in the namespace `DryChem`. Alternatively, these functions and classes also have their own nested namespace in the `CppUtils` namespace, which can be called as `CppUtils::Files`. While either can be used, `DryChem` is preferred to provide a uniform interface for all portions of the library. The following line can be included in any user project to provide access to the files library:

```C++
#include <common-utils/files.hpp>
```

## Features

### File Parsing

- [File Parsing:](../../../include/common-utils/files/fileParsing/fileParser.hpp)

  The `FileParser` class, the flagship of the file handling library, takes an input file or `std::filesystem::path` and through lazy evaluation will read and parse the file. Designed using the Strategy design pattern but templated and localized to only the calling function, the end user decides how they want the file parsed using the contents that have been cached for them. Another benefit to localizing the strategies is that should the user wish to parse the same file two or more ways, the file is only read once and each parser can easily access that data. If we had templated the entire class, new parsers would have to be created each time the same file needed to be parsed in a new way.

- [Concrete File Parsers:](../../../include/common-utils/files/fileParsing/parserStrategies.hpp)

  Both to demonstrate how to use the `FileParser` class and to cover some of the most basic and common use-cases, the file library provides two concrete parser strategies. The first of which parses the input file by splitting the file into rows. The second, which is more involved, parses the file by splitting the file into columns. If either of these two options aren't enough for the end user, the interface can be extended using the two as a model.

  So long as the strategy can be called with the following:

  ```C++
  ReturnType strategy(const std::string& fileContents, ...);
  ```

  where `ReturnType` can be any type or `void`, any function is callable. Unfortunately, this interface excludes all member functions from being called as they take an implicit class variable as their first argument.

---

### File Handling Utilities

- [Error Handling:](../../../include/common-utils/files/utils/fileExceptions.hpp)

  One of the most common errors we come across when using files, is when the desired file doesn't exist. To avoid the repition of using the `FatalException` interface, we provide a specialized exception, the `FileNotFound` exception, which can be used whenever a file is expected but doesn't exit in the specified directory. Because this exception class derives from  FatalException  , the preferred method of error handling with the nested `try-catch` blocks still applies.

---

## Working Example

For working examples of how to use the library, refer to the [testing](../tests) and/or [samples](../samples) directories, which together provide a comprehensive overview of the library's usage.

To build and run the code samples for the file library, one should include the `utils_build_samples=ON` option to the CMake instructions. Similarly, to build and run the unit tests for the individual file handling functions, one should include the `utils_build_tests=ON` option, as shown in the code below:

```bash
cmake ../drychem/. -Dutils_build_samples=ON -Dutils_build_tests=ON
make

## Run the file library's samples ##
cd bin/samples
./markupParsingExample

## Run the file library's unit tests ##
cd ../tests
./testAllFileFunctions
```

*NOTE: The samples and tests will not be installed with the rest of the library. They exist only to extend the documentation and help the user navigate the library.*
