# C++ Units

[![Build Status](https://travis-ci.com/crdrisko/cpp-units.svg?branch=master)](https://travis-ci.com/crdrisko/cpp-units)

Welcome to the CPP-Units project! This project is a unit converter written in C++ designed to be extendable with a number of interfaces. Currently, the public API of the project is in the development stage, but I hope to add a command line interface (CLI), graphical user interface (GUI), and web application very soon. Each of these interfaces will serve to help my software development skills by focusing on a singular project I can continue to enhance as I learn more.

<!--More detailed documentation for using cpp-units can be found in the [`docs/primer.md`](https://github.com/crdrisko/cpp-units/tree/master/docs/primer.md) file.-->

## Features

- A compile-time, header-only physical quantity library.
- Compile-time user defined literals for clean code that takes away nothing from overall performance.
- Advanced mathematical functions (including many of the `<cmath>` header functions) that act on the physical quantities themselves without explicit conversion into a more compatible type.
- A unit conversion API for many of the physical quantities in the library.

## Platforms

The CPP-Units project has been built and tested on a number of operating systems, computer architectures, and compiler combinations.

- Mac OS X
- Linux
- Windows Subsystem for Linux (WSL)

**Coming Soon:**

- Windows
- Cygwin

## Requirements

The CPP-Units project was designed to have as few external dependencies as possible so it could be easily built and used by other projects. The project requires:

- A C++17-standard-compliant compiler with support for the Standard Library.

- [Utilities-API](https://github.com/crdrisko/utilities-api) was used for a number of the utilities found throughout the project. More information about the API can be found in the repository's README.

- [GoogleTest](https://github.com/google/googletest) was used for the testing all the source code in the project. Building and running all these tests is optional and more information can be found in the testing section of [`docs/build.md`](https://github.com/crdrisko/cpp-units/tree/master/docs/build.md).

### Build Requirements

- [CMake](https://cmake.org): Version 3.10.0 or higher. See the documentation in the [`docs/build.md`](https://github.com/crdrisko/cpp-units/tree/master/docs/build.md) file for specific instructions on installing the project.

## License

Copyright (c) 2020 Cody R. Drisko. All rights reserved.

Licensed under the [MIT License](https://github.com/crdrisko/cpp-units/blob/master/LICENSE).
