# DryChem

[![cmake](https://github.com/crdrisko/drychem/workflows/build/badge.svg)](docs/QUICK_LINKS.md#Current-Build-Status) [![Coverage Status](https://coveralls.io/repos/github/crdrisko/drychem/badge.svg?branch=main)](docs/QUICK_LINKS.md#Code-Coverage) [![GitHub release (latest by date including pre-releases)](https://img.shields.io/github/v/release/crdrisko/drychem?include_prereleases)](https://github.com/crdrisko/drychem/releases)

Welcome to the DryChem project! DryChem is a collection of generic C++ libraries, who's main goal is compliance with the "Don't Repeat Yourself" (DRY) principle of modern software development. The libraries we release and maintain are general enough to find use in a number of projects, but don't go much farther than what you would find in your average computational chemistry codebases' utility library.

This repository is a merger of the formerly separate C++ Units and Common-Utilities projects. Because these repositories were so closely related, it made sense to maintain and release them together.

## Getting started

General information for getting started using DryChem is available in the documentation [here](docs/PRIMER.md).

More detailed documentation for Common-Utilities and C++ Units can be found in the interior [`common-utilities/README.md`](common-utilities/README.md) and [`cpp-units/README.md`](cpp-units/README.md) files, respectively.

## Features

- A familiar framework for error and exception handling.
- A number of mathematical functions with domains ranging from calculus to statistics.
- A number of utility type traits for better, more general programming.
- A compile-time, header-only physical quantity library.

## Platforms

The DryChem project has been built and tested on a number of operating systems, computer architectures, and compiler combinations.

- Linux
- Mac OS X
- Windows

## Requirements

The DryChem project was designed to have as few external dependencies as possible so it could be easily built and used by other projects. The project requires:

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
