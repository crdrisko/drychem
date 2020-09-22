# Utilities

A brief summary of the library as a whole...

**Getting Started:**

The following lines of code can be included in any user project to provide access to the utilities library:

```C++
#include <common-utils/utilities.hpp>

using namespace CommonUtilities::Utilities;
```

**Comparison Operators:**

A brief summary of the comparison operators portion of the library...

**Miscellaneous Utility Functions:**

A brief summary of the utilities portion of the library...

**Working Example:**

For working examples of how to use the library, refer to the [testing](https://github.com/crdrisko/common-utilities/tree/master/libs/utilities/tests) files or the [samples](https://github.com/crdrisko/common-utilities/tree/master/libs/utilities/samples) directory, which together provide a comprehensive overview of the library's usage.

To build and run the code samples for the utilities library, one should include the `utils_build_samples=ON` option to the CMake instructions. Similarly, to build and run the unit tests for the individual utility functions, one should include the `utils_build_tests=ON` option, as shown in the code below:

```bash
cmake ../common-utilities/. -Dutils_build_samples=ON -Dutils_build_tests=ON
make

## Run utility library's samples ##
cd bin/samples
./sampleName

## Run utility library's unit tests ##
cd ../tests
./testAllUtilityFunctions
```

*NOTE: the samples and tests will not be installed with the rest of the library. They exist only to extend the documentation and help the user navigate the library.*
