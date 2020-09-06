# Common-Utilities

[![Build Status](https://travis-ci.com/crdrisko/common-utilities.svg?branch=master)](https://travis-ci.com/crdrisko/common-utilities) [![Coverage Status](https://coveralls.io/repos/github/crdrisko/common-utilities/badge.svg?branch=master)](https://coveralls.io/github/crdrisko/common-utilities?branch=master) ![GitHub release (latest by date including pre-releases)](https://img.shields.io/github/v/release/crdrisko/common-utilities?include_prereleases)

Welcome to the Common-Utilities project! This project is a compilation of a number of unrelated programs and scripts I've written over the years, providing a single source of utilities used in other repositories. The goal of this project is to strive for compliance with the "Don't Repeat Yourself" (DRY) principle of modern software development.

More detailed documentation for using the common-utilities can be found in the [`docs/PRIMER.md`](https://github.com/crdrisko/common-utilities/blob/master/docs/PRIMER.md) file.

## Features

- Wrappers for some standard library containers.
- Error and exception handling.
- File parsing for a variety of file types.
- String manipulation.
- Advanced mathematical functions.

## Platforms

The Common-Utilities project has been built and tested on a number of operating systems, computer architectures, and compiler combinations.

- Mac OS X
- Linux
- Windows Subsystem for Linux (WSL)

**Coming Soon:**

- Windows
- Cygwin

## Requirements

The Common-Utilities project was designed to have as few external dependencies as possible so it could be easily built and used by other projects. The project requires:

- A C++17-standard-compliant compiler with support for the Standard Library.

- The Bourne Again SHell (bash) is required to use of any of the scripts. While other versions of bash may work, the lowest version of bash I have tested these scripts on is 3.2. Many, if not all, shell scripts in this repository are *not* compliant with the POSIX shell.

- [GoogleTest](https://github.com/google/googletest) was used for the testing all the source code in the project. Building and running all these tests is optional and more information can be found in the testing section of [`docs/BUILD.md`](https://github.com/crdrisko/common-utilities/blob/master/docs/BUILD.md).

### Build Requirements

- [CMake](https://cmake.org): Version 3.10.0 or higher. See the documentation in the [`docs/BUILD.md`](https://github.com/crdrisko/common-utilities/blob/master/docs/BUILD.md) file for specific instructions on installing the project.

## Contributing

Please read CONTRIBUTING.md for details on how you can become a contributor and the process for submitting pull requests to us.

## License

Copyright (c) 2020 Cody R. Drisko. All rights reserved.

Licensed under the [MIT License](https://github.com/crdrisko/common-utilities/blob/master/LICENSE).
