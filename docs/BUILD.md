# Building and Installing Common-Utilities

## Installation

Using [CMake](https://cmake.org), the following commands can be run to install the repository:

```bash
git clone https://github.com/crdrisko/common-utilities.git
mkdir build && cd build
cmake ../common-utilities/.
make && [sudo] make install
```

By default, the project is installed in the `/usr/local` filesystem but can be changed with the `CMAKE_INSTALL_PREFIX` option.

## Testing

With each library in the project (Errors, Math, etc.), I have strived to provide ~100% unit test coverage for all functions. These tests can be found in the `root/libs/libraryName/tests` directory but do not get built by default. To turn on the testing features of the repository, add the `utils_build_tests=ON` option to the CMake instructions as shown in the code below:

```bash
## Same steps as before ... ##
cmake ../common-utilities/. -Dutils_build_tests=ON
make && [sudo] make install

## Run the unit tests ##
ctest --output-on-failure
```

[GoogleTest](https://github.com/google/googletest), which is used as the unit test framework, will be installed as an external CMake project if the repository was not already found.
