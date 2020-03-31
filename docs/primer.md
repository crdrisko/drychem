# Utilities-API Primer

## Table Of Contents

- [Utilities-API Modules](#Utilities-API-Modules)

  - [Errors](#Errors)
  - [Files](#Files)
  - [Math](#Math)
  - [Strings](#Strings)

- [Bash Scripts and Programs](#Bash-Scripts-and-Programs)

## Utilities-API Modules

The C++ modules which make up the [public API](https://github.com/crdrisko/utilities-api/tree/master/include) of the repository are all organized in the same way, and by including the `module.hpp` file (which `#include`'s the internal files) features can be added to the module with no effect on the public API.

```C++
include
| -- utils-api
     | -- module1.hpp
     | -- ...
     |
     | -- internal
          | -- Module1
          |    | -- internalFile1.hpp
          |    | -- ...
          |
          | -- ...
```

### Errors

The error module of the Utilities-API project consists of functions and classes dedicated to error and exception handling. Since these types of events occur in virtually every type of project imaginable, it has proved useful collecting these functions in a single place.

The following lines of code can be included in any user project to provide access to the errors module:

```C++
#include <utils-api/errors.hpp>

using namespace Utilities_API::Errors;
```

For examples of how to use the error handling classes and functions, refer to the [testing](https://github.com/crdrisko/utilities-api/tree/master/test/TestErrors/testErrorFunctions.cpp) files, which provide a comprehensive overview of the module's usage.

### Files

The file module consists of a class dedicated to handling input files of various types. By splitting files into metadata and data blocks based on comments or specific tags (see below), parsing an input file becomes easy, and access to the underlying data is readily accessible in a `std::vector<std::string>` container. The currently supported file types are:

- Plain text files
- Markup files

The following lines of code can be included in any user project to provide access to the files module:

```C++
#include <utils-api/files.hpp>

using namespace Utilities_API::Files;
```

For examples of how to use the file handling classes and functions, refer to the [testing](https://github.com/crdrisko/utilities-api/tree/master/test/TestFiles/testFileFunctions.cpp) files, which provide a comprehensive overview of the module's usage.

### Math

The math library consists of a number of advanced mathematical functions and classes, providing an easy-to-use interface. Some of the functions offered in this library include:

- Linear interpolation
- Linear least squares fitting
- Numerical integration
- Numerical differentiation

The following lines of code can be included in any user project to provide access to the math module:

```C++
#include <utils-api/math.hpp>

using namespace Utilities_API::Math;
```

For examples of how to use the advanced mathematical classes and functions, refer to the [testing](https://github.com/crdrisko/utilities-api/tree/master/test/TestMath/testMathFunctions.cpp) files, which provide a comprehensive overview of the module's usage.

### Strings

The strings module consists of a few functions relating to the parsing of `std::string` containers or wrappers for Standard Library functions that enhance readability of the code.

The following lines of code can be included in any user project to provide access to the strings module:

```C++
#include <utils-api/strings.hpp>

using namespace Utilities_API::Strings;
```

For examples of how to use the string parsing classes and functions, refer to the [testing](https://github.com/crdrisko/utilities-api/tree/master/test/TestStrings/testStringFunctions.cpp) files, which provide a comprehensive overview of the module's usage.

## Bash Scripts and Programs

Consisting of a number of bash scripts for mainly automating some of my most common tasks, the files located in the [`root/scripts`](https://github.com/crdrisko/utilities-api/tree/master/scripts) directory are scripts and programs that don't really belong in any other repository so they have been collected here.

For the programs that support command-line parsing arguments, the `-h` flag will print the help message associated with the program. Scripts like `errorHandling.sh`, `showArguments.sh`, and `showOptions.sh` are designed to either be incorporated in other bash programs or are so simple, no help option is needed.

When the repository is installed, all shell scripts will be installed without the `.sh` extension and will be made executable. If the `${CMAKE_INSTALL_PREFIX}/bin` directory is in the system's path, these programs can be called as follows:

```bash
$ changeCase -h

USAGE: changeCase [-hvulf] [-w word]

  -h  Prints help information about the changeCase program.
  -v  Verbose mode. Defaults to false/off.
  -u  Change word/letter to uppercase. Defaults to false/off.
  -l  Change word/letter to lowercase. Defaults to false/off.
  -f  Change only the first letter to selected case. Defaults to false/off.

  -w  REQUIRED: Word to change case of.

EXAMPLE: changeCase -f -l -w LOWERCASE

$ changeCase -l -w LOWERCASE
lowercase
```
