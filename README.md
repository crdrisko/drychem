# Utilities-API

[![Build Status](https://travis-ci.com/crdrisko/utilities-api.svg?branch=master)](https://travis-ci.com/crdrisko/utilities-api)

Welcome to the Utilities-API project! This project is a compilation of a number of unrelated programs and scripts I've written over the years, providing a single source of common utilities used in other repositories. The goal of this project is to strive for compliance with the "Don't Repeat Yourself" (DRY) principle of modern software development.

The project is organized as follows:

- [Public API](https://github.com/crdrisko/utilities-api/tree/master/include): All hpp files are located in the `root/include` directory. This directory serves as the public API of the project and other projects wishing to utilize it should include the specific module desired.

- [Bash Scripts](https://github.com/crdrisko/utilities-api/tree/master/scripts): Consisting of a number of bash scripts for mainly automating some of my most common tasks, the files located in the `root/scripts` directory are scripts and programs that don't really belong in any other repository.

- [Testing](https://github.com/crdrisko/utilities-api/tree/master/test): With each utility module in the project (Errors, Math, etc.), I have strived to provide ~100% unit test coverage. These tests can be found in the `root/test` directory but do not get built by default. See below for more information on testing.

## Features

- Error and exception handling.
- File parsing for a variety of file types.
- String manipulation.
- Advanced mathematical functions.

## Platforms

The Utilities-API project has been built and tested on a number of operating systems, computer architectures, and compiler combinations.

- Mac OS X
- Linux

## Requirements

The Utilities-API project was designed to have as few external dependencies as possible so it could be easily built and used by other projects. The project requires:

- A C++17-standard-compliant compiler with support for the Standard Library.

- The Bourne Again SHell (bash) is required if the use of any of the scripts in the `scripts` directory is desired. While other versions of bash may work, the lowest version of bash I have tested these scripts on is 3.2. Many, if not all, shell scripts in this repository are *not* compliant with the POSIX shell.

### Build Requirements

- [CMake](https://cmake.org): Version 3.10.0 or higher. Using CMake, the following commands can be run to install the repository:

    ```bash
    git clone https://github.com/crdrisko/utilities-api.git
    mkdir build && cd build
    cmake ../utilities-api/.
    make && [sudo] make install
    ```

### Optional

- [GoogleTest](https://github.com/google/googletest) was used for the testing of all source code in the project (see the `test` directory). Running all these tests is optional and can be turned on using the `build_all_tests=ON` flag during the build.
