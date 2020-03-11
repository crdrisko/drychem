# C++ Units

## Release: Version 0.0.1 (Pre-Release)

### Build Status

[![Build Status](https://travis-ci.com/crdrisko/cpp-units.svg?branch=master)](https://travis-ci.com/crdrisko/cpp-units)

- NOTE: Until Version 1.0.0 is released, the project's interface is subject to change at any time without warning.

## Platforms

The C++ Units project has been built and tested on a number of operating systems, computer architectures, and compiler combinations.

- Mac OS X

- Linux

## Requirements

The C++ Units project requires

- [CMake](https://cmake.org): Version 3.10.0 or higher.

- A C++17-standard-compliant compiler with support for the Standard Library.

- [Utilities-API](https://github.com/crdrisko/utilities-api): used for a number of the utilities found throughout the various projects and scripts. More information about the API can be found in the repository's README. The procedure outlined in the `ci/install-utilities-api.sh` script can be followed to install the repository where desired.

Optional:

- [GoogleTest](https://github.com/google/googletest) was used for the testing of all source code in the project (see the `test` directory). The `ci/install-gtest.sh` script in the utilities-api repository (see above) can be used to install GoogleTest where desired. Running all these tests is optional and can be turned on using the `-Dbuild_all_tests=ON` flag during the build.

## Installation

Installation of the C++ Units project is designed to be as easy as possible. Using CMake, the following commands can be run:

```bash
$ git clone https://github.com/crdrisko/cpp-units.git
$ mkdir build && cd build
$ cmake ../cpp-units/.
$ make && [sudo] make install
```

- NOTE: the default install directory is `/usr/local`.
