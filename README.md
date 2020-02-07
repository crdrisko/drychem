# Utilities-API

### Build Status - Version 1.0.0

[![Build Status](https://travis-ci.com/crdrisko/utilities-api.svg?branch=master)](https://travis-ci.com/crdrisko/utilities-api)

## Platforms

The Utilities-API project has been built and tested on a number of operating systems, computer architectures, and compiler combinations.

- Mac OS X

- Linux

## Requirements

The Utilities-API requires

- [CMake](https://cmake.org): Version 3.10.0 or higher.

- A C++17-standard-compliant compiler.

Optional:

- [GoogleTest](https://github.com/google/googletest) was used for the testing of all source code in the project (see the `test` directory). The `ci/install-gtest.sh` script can be used to install GoogleTest where desired. Running all these tests is optional and can be turned on using the `-Dbuild_all_tests=ON` flag during the build.

- The Bourne Again SHell (bash) is required if the use of any of the scripts in the `scripts` directory is desired. While other versions of bash may work, the lowest version of bash I have tested these scripts on is 3.2. Many, if not all, shell scripts in this repository are *not* compliant with the POSIX shell.

## Installation

Installation of the Utilities-API project is designed to be as easy as possible. Using CMake, the following commands can be run:

```bash
$ git clone https://github.com/crdrisko/utilities-api.git
$ mkdir build && cd build
$ cmake ../utilities-api/.
$ make && [sudo] make install
```

- NOTE: the default install directory is `/usr/local`.
