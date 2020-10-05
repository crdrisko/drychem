# C++ Units

[![Build Status](https://travis-ci.com/crdrisko/cpp-units.svg?branch=master)](docs/QUICK_LINKS.md#Current-Build-Status) [![Coverage Status](https://coveralls.io/repos/github/crdrisko/cpp-units/badge.svg?branch=master)](docs/QUICK_LINKS.md#Code-Coverage) [![GitHub release (latest by date including pre-releases)](https://img.shields.io/github/v/release/crdrisko/cpp-units?include_prereleases)](https://github.com/crdrisko/cpp-units/releases)

Welcome to the C++ Units project! This repository is a merger of the formerly separate C++ Units and Common-Utilities projects. Because these repositories were so closely related, it made sense to maintain and release them together.

## Getting started

General information for getting started using C++ Units is available in the documentation [here](docs/PRIMER.md).

More detailed documentation for Common-Utilities and C++ Units can be found in the interior [`common-utilities/README.md`](common-utilities/README.md) and [`cpp-units/README.md`](cpp-units/README.md) files, respectively.

## Features

- A compile-time, header-only physical quantity library.
- A set of compile-time user defined literals for cleaner code that takes away nothing from overall performance.
- A common method of error and exception handling.
- A number of utility type traits for better, more general programming.

## Platforms

The C++ Units project has been built and tested on a number of operating systems, computer architectures, and compiler combinations.

- Mac OS X
- Linux
- Windows Subsystem for Linux (WSL)

**Coming Soon:**

- Windows
- Cygwin

## Requirements

The C++ Units project was designed to have as few external dependencies as possible so it could be easily built and used by other projects. The project requires:

- A C++17-standard-compliant compiler with support for the Standard Library.

- The Bourne Again SHell (bash) is required to use of any of the scripts. While other versions of bash may work, the lowest version of bash I have tested these scripts on is 3.2. Many, if not all, shell scripts in this repository are *not* compliant with the POSIX shell.

### Build Requirements

- [CMake](https://cmake.org): Version 3.12.0 or higher. See the documentation in the [`BUILD.md`](docs/BUILD.md) file for specific instructions on installing the project.

### Test Requirements

- [GoogleTest](https://github.com/google/googletest) was used for the testing all the source code in the project. Building and running all these tests is optional and more information can be found in the testing section of [`BUILD.md`](docs/BUILD.md#Testing).

## Contributing

Please read [CONTRIBUTING.md](docs/CONTRIBUTING.md) for details on how you can become a contributor and the process for submitting pull requests to us.

## License

Copyright (c) 2020 Cody R. Drisko. All rights reserved.

Licensed under the [MIT License](LICENSE).
