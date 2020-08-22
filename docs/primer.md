# Common-Utilities Primer

## Table Of Contents

- [C++ Modules and Libraries](#C++-Modules-and-Libraries)

  - [Containers](#Containers)
  - [Errors](#Errors)
  - [Files](#Files)
  - [Math](#Math)
  - [Strings](#Strings)

- [Bash Scripts and Programs](#Bash-Scripts-and-Programs)

## C++ Modules and Libraries

The C++ modules which make up the [public API](https://github.com/crdrisko/common-utilities/tree/master/include) of this repository are all organized in the same way, and by including the `module.hpp` file (which `#include`'s the internal files) features can be added without changing the interface of the module. The following tree diagram shows how a sample module (Module 1), would be organized in the API:

```C++
include
| -- common-utils
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

### Containers

This module provides classes that wrap some of the standard library containers, such as `std::array`, `std::vector`, etc. providing a limited interface responsible for ease-of-use in other programs. For example, the `Vector3D` class template wraps a `std::array` with three elements to simulate a vector in physics or mathematics with x, y, and z components.

**Getting Started:**

The following lines of code can be included in any user project to provide access to the containers module:

```C++
#include <common-utils/containers.hpp>

using namespace CommonUtilities::Containers;
```

For more examples of how to use the containers module, refer to the [testing](https://github.com/crdrisko/common-utilities/tree/master/test/TestContainers/testContainerFunctions.cpp) files, which provide a comprehensive overview of the module's usage.

### Errors

The error module of the Common-Utilities project consists of functions and classes dedicated to error and exception handling. Since these types of events occur in virtually every project imaginable, it has proved useful collecting these functions in a single place.

**Getting Started:**

The following lines of code can be included in any user project to provide access to the errors module:

```C++
#include <common-utils/errors.hpp>

using namespace CommonUtilities::Errors;
```

**Exception Handling:**

This module provides an exception handling class: `CommonUtilities::Errors::Exception` which derives from `std::exception`. Some other commonly used exceptions can also be found, all of which derive from the Exception class. Because these exceptions derive from `std::exception` (either directly or indirectly), they can be caught by statements like the following:

```C++
catch (const std::exception& e)
{
    std::cerr << e.what() << std::endl;
}
```

However, by defining an additional catch block **prior** to this standard block (see below), we can utilize the information stored in the new Exception object to print out more information than is otherwise provided by a call to `what()`. This information includes the name of the program where the exception originated, the severity of the error in question, and of course, the error message itself.

The Exception class delegates its error handling to the dedicated ErrorMessage classes by calling the `handleErrorWithMessage()` function. Depending on the level of error severity (Warning or Fatal) associated with the exception, the error will be handled accordingly.

**Error Handling:**

In the way of error handling, the Common-Utilities project defines two types of error classes: Fatal and Non-Fatal. The `FatalErrorMessage` class derives from the non-fatal version, `ErrorMessage` and the two utilize polymorphism to determine how the error should be handled. Polymorphic calls to the `printErrorMessage()` function will, as the name suggests, print the supplied error message. By design, fatal errors will cause program termination by envoking `std::exit()`.

*NOTE:* The use of the ErrorMessage classes descibed here is no longer the recommended method for handling errors. The exception classes described above provide an easy-to-use interface to these underlying error message classes, while providing the same functionality.

**Working Example:**

As a working example, consider the following code snipet which demonstrates how to both throw and catch a `CommonUtilities::Errors::Exception`:

```C++
#include <iostream>
#include <exception>

#include <common-utils/errors.hpp>

using namespace CommonUtilities::Errors;

int main()
{
    for (int i {}; i <= 10; ++i)
    {
        try
        {
            if (i == 4)
                throw Exception {"Common-Utilities", "Loop reached: i = 4", ErrorSeverity::Warning};

            std::cout << i << std::endl;
        }
        catch (const Exception& except)
        {
            except.handleErrorWithMessage();
        }
        catch (const std::exception& except)
        {
            std::cerr << except.what() << std::endl;
        }
    }
}
```

For more examples of how to use the error module, refer to the [testing](https://github.com/crdrisko/common-utilities/tree/master/test/TestErrors/testErrorFunctions.cpp) files, which provide a comprehensive overview of the module's usage.

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

Consisting of a number of bash scripts for mainly automating some of my most common tasks, the files located in the [`root/scripts`](https://github.com/crdrisko/common-utilities/tree/master/scripts) directory are scripts and programs that don't really belong in any other repository so they have been collected here.

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
