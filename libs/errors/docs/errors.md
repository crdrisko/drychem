# Errors

The error handling library of the Common-Utilities project consists of functions and classes dedicated to error and exception handling. Since these types of events occur in virtually every project imaginable, it has proved useful collecting these functions in a single place.

**Getting Started:**

The following lines of code can be included in any user project to provide access to the errors library:

```C++
#include <common-utils/errors.hpp>

using namespace CommonUtilities::Errors;
```

**Exception Handling:**

This library provides an exception handling class: `CommonUtilities::Errors::FatalException` which derives from `std::exception`. Some other commonly used exceptions can also be found, all of which derive from this `FatalException` class. Because these exceptions derive from `std::exception` (either directly or indirectly), they can be caught by statements like the following:

```C++
catch (const std::exception& e)
{
    std::cerr << e.what() << std::endl;
}
```

However, if we throw an additional `FatalException` in this catch block (see [example](https://github.com/crdrisko/common-utilities/tree/master/libs/errors/samples/fibonacciExample.cpp)), we can customize the error messages and handle the exception based on whether it is fatal or not. The information we throw, via our `FatalException` constructor, includes the name of the program where the exception originated, and of course, the error message itself.

The `FatalException` class delegates its error handling to a separate utility function (discussed next) when the user invokes `handleErrorWithMessage()`. Because this exception type is deemed fatal, a verbose error message will be printed and `std::exit()` will be called.

**Error Handling Utilities:**

In the way of error handling, the Common-Utilities project defines two types of error severity: Warning and Fatal. These designations are defined as an enum class, `ErrorSeverity`, and are used to template the main function responsible for handling errors. Some type traits are provided as well which allow for compile-time determination of the level of severity our functions are dealing with. Some convenience type aliases and lambda functions are also defined to enhance code readability.

The `printErrorMessage()` function template is a helper function for the `FatalException` class but can be called directly if needed. Depending on the error severity, the function will either print a warning to STDERR or print the supplied message and exit. `printFatalErrorMessage()` exists as a convience function for a fatal error so template parameters don't need to be explicitly writen.

**Working Example:**

For working examples of how to use the library, refer to the [testing](https://github.com/crdrisko/common-utilities/tree/master/libs/errors/tests) files or the [samples](https://github.com/crdrisko/common-utilities/tree/master/libs/errors/samples) directory, which together provide a comprehensive overview of the library's usage.
