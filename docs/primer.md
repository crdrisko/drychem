# Common-Utilities Primer

## Table Of Contents

- [C++ Modules and Libraries](#C++-Modules-and-Libraries)
  - [Errors](#Errors)
  - [Files](#Files)
  - [Math](#Math)
  - [Strings](#Strings)

- [Bash Scripts and Programs](#Bash-Scripts-and-Programs)

## C++ Modules and Libraries

The C++ libraries which make up the [public API](https://github.com/crdrisko/common-utilities/tree/master/include) of this repository are all organized in the same way, and by including the `library.hpp` file (which `#include`'s the internal files) features can be added without changing the interface of the library. The following tree diagram shows how a sample library (Library1), would be organized in the API:

```C++
include
| -- common-utils
     | -- library1.hpp
     | -- ...
     |
     | -- library1
          |    | -- internalFile1.hpp
          |    | -- ...
          |
          | -- ...
```

### Errors

The error handling library of the Common-Utilities project consists of functions and classes dedicated to error and exception handling. Since these types of events occur in virtually every project imaginable, it has proved useful collecting these functions in a single place.

**Getting Started:**

The following lines of code can be included in any user project to provide access to the errors library:

```C++
#include <common-utils/errors.hpp>

using namespace CommonUtilities::Errors;
```

**Exception Handling:**

This library provides an exception handling class: `CommonUtilities::Errors::FatalException` which derives from `std::exception`. Some other commonly used exceptions can also be found, all of which derive from this FatalException class. Because these exceptions derive from `std::exception` (either directly or indirectly), they can be caught by statements like the following:

```C++
catch (const std::exception& e)
{
    std::cerr << e.what() << std::endl;
}
```

However, if we throw an additional `FatalException` in this catch block (see below), we can customize the error messages and handle the exception based on whether it is fatal or not. The information we throw via our `FatalException` constructor includes the name of the program where the exception originated, and of course, the error message itself.

The `FatalException` class delegates its error handling to a separate utility function (discussed next) when the user invokes `handleErrorWithMessage()`. Because this exception type is deemed fatal, a verbose error message will be printed and `std::exit()` will be called.

**Error Handling Utilities:**

In the way of error handling, the Common-Utilities project defines two types of error severity: Warning and Fatal. These designations are defined as an enum class, `ErrorSeverity` and are used to template the main function responsible for handling errors. Some type traits are provided as well which allow for compile-time determination of the level of severity our functions are dealing with. Some convenience type aliases and lambda functions are also defined to enhance code readability.

**Working Example:**

As a working example, consider the following code snippet which demonstrates how to both throw and catch a `CommonUtilities::Errors::FatalException`:

```C++
#include <exception>
#include <iostream>
#include <string>

#include <common-utils/errors.hpp>

using namespace CommonUtilities;

void printCounter(int i);

int main()
{
    try
    {
        try
        {
            for (int count {}; count <= 10; ++count)
            {
                printCounter(count);
            }

        }
        catch (const std::exception& except)
        {
            Errors::ErrorMessage error;
            error.programName = "Common-Utilities";
            error.message = "Exception message: " + std::string{except.what()};

            throw Errors::FatalException(error);
        }
    }
    catch (const Errors::FatalException& except)
    {
        except.handleErrorWithMessage();
    }
}

void printCounter(int count)
{
    if (count == 8)
        Errors::printErrorMessage("Common-Utilities", "The loop counter reached 8, careful it doesn't get to 9.");

    else if (count == 9)
        throw Errors::InvalidInputException("Common-Utilities", "The loop counter reached 9.");

    std::cout << count << std::endl;
}
```

For more examples of how to use the library, refer to the [testing](https://github.com/crdrisko/common-utilities/tree/master/test/TestErrors) files, which provide a comprehensive overview of the library's usage.

### Files

The file module consists of a class dedicated to handling input files of various types. By splitting files into metadata and data blocks based on comments or specific tags (see below), parsing an input file becomes easy, and access to the underlying data is readily accessible in a `std::vector< std::vector<std::string> >` container. The currently supported file types are:

- Plain text files
- Markup files

**Getting Started:**

The following lines of code can be included in any user project to provide access to the files module:

```C++
#include <common-utils/files.hpp>

using namespace CommonUtilities::Files;
```

For examples of how to use the file handling classes and functions, refer to the [testing](https://github.com/crdrisko/common-utilities/tree/master/test/TestFiles/testFileFunctions.cpp) files, which provide a comprehensive overview of the module's usage.

### Math

The math library consists of a number of advanced mathematical functions and classes, providing an easy-to-use interface. Some of the functions offered in this library include:

- Linear interpolation
- Linear least squares fitting
- Numerical integration
- Numerical differentiation

**Getting Started:**

The following lines of code can be included in any user project to provide access to the math module:

```C++
#include <common-utils/math.hpp>

using namespace CommonUtilities::Math;
```

For examples of how to use the advanced mathematical classes and functions, refer to the [testing](https://github.com/crdrisko/common-utilities/tree/master/test/TestMath/testMathFunctions.cpp) files, which provide a comprehensive overview of the module's usage.

#### Containers

This module provides classes that wrap some of the standard library containers, such as `std::array`, `std::vector`, etc. providing a limited interface responsible for ease-of-use in other programs. For example, the `Vector3D` class template wraps a `std::array` with three elements to simulate a vector in physics or mathematics with x, y, and z components.

**Getting Started:**

The following lines of code can be included in any user project to provide access to the containers module:

```C++
#include <common-utils/containers.hpp>

using namespace CommonUtilities::Containers;
```

For more examples of how to use the containers module, refer to the [testing](https://github.com/crdrisko/common-utilities/tree/master/test/TestContainers/testContainerFunctions.cpp) files, which provide a comprehensive overview of the module's usage.

### Strings

The strings module consists of a few functions relating to the parsing of `std::string` containers or wrappers for Standard Library functions that enhance readability of the code.

**Getting Started:**

The following lines of code can be included in any user project to provide access to the strings module:

```C++
#include <common-utils/strings.hpp>

using namespace CommonUtilities::Strings;
```

For examples of how to use the string parsing classes and functions, refer to the [testing](https://github.com/crdrisko/common-utilities/tree/master/test/TestStrings/testStringFunctions.cpp) files, which provide a comprehensive overview of the module's usage.

## Bash Scripts and Programs

Consisting of a number of bash scripts for mainly automating some of my most common tasks, the files located in the [`root/scripts`](https://github.com/crdrisko/common-utilities/tree/master/scripts) directory are scripts and programs that don't really belong in any other repository, so they have been collected here.

For the programs that support command-line argument parsing, the `-h` flag will print the help message associated with the program. Scripts like `errorHandling.sh`, `showArgs.sh`, and `showOpts.sh` are designed to either be incorporated in other bash programs or are so simple, no help option is needed.

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
