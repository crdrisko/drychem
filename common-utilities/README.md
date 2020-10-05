# Common-Utilities

Welcome to the Common-Utilities project! This project is a compilation of a number of unrelated programs and scripts I've written over the years, providing a single source of utilities for their use in other repositories. The goal of this project is to strive for compliance with the "Don't Repeat Yourself" (DRY) principle of modern software development.

## Table Of Contents

- [Building and Installing](#Building-and-Installing)

- [C++ Libraries](#C++-Libraries)

- [Bash Scripts](#Bash-Scripts)

## Building and Installing

...

## C++ Libraries

The libraries included in this project include the following, and more information can be found in the specific libraries documentation:

- [Errors](libs/errors/docs/errors.md)

<!--
- [Files](libs/files/docs/files.md)

- [Math](libs/math/docs/math.md)

- [Strings](libs/strings/docs/strings.md)
-->

- [Utilities](libs/utilities/docs/utilities.md)

The following tree diagram shows how a sample library, `library1`, would be organized in the API:

```bash
.
├── include
│   └── common-utils
│       ├── library1
│       │   └── ...
│       ├── library1.hpp
│       └── ...
└── libs
    └── library1
        ├── docs
        │   └── ...
        ├── samples
        │   └── ...
        ├── src (optional)
        │   └── ...
        └── tests
            ├── testAllLibrary1Functions.cpp
            └── ...
```

The `libs` directory contains information about the specific library, such as the documentation, example code samples, source code (if any), and unit tests. The `include/common-utils` directory is where the header files for the library are stored. Note that the `libraryName.hpp` file serves as the public API of the library and should be `#include`'d in a user's project. The files in the `libraryName` directory contain the internal implementation details and are subject to change without notice.

## Bash Scripts

Consisting of a number of bash scripts for mainly automating some of my most common tasks, the files located in the [`root/common-utilities/scripts`](https://github.com/crdrisko/cpp-units/blob/master/common-utilities/scripts) directory are simple scripts and programs that don't really belong in any other repository, so they have been collected here.

For the programs that support command-line argument parsing, the `-h` flag will print the help message associated with the program. Scripts like `errorHandling.sh`, `showArgs.sh`, and `showOpts.sh` are designed to either be incorporated in other bash programs or are so simple, no help option is needed.

When the repository is installed, all shell scripts will be installed without the `.sh` extension and will be made executable. If the `${CMAKE_INSTALL_PREFIX}/bin` directory is in the system's path, these programs can be called as follows:

```bash
$ changeCase -h

USAGE: changeCase [-hvulf] [-w word]

  -h  Prints help information about the changeCase program.
  -v  Verbose mode. Defaults to false/off.
  -u  Change word/letter to uppercase. Defaults to false/off.
  -l  Change word/letter to lowercase. Defaults to false/off.
  -f  Change only the first letter to selected case. Defaults to false/off.

  -w  REQUIRED: Word to change case of.

EXAMPLE: changeCase -f -l -w LOWERCASE

$ changeCase -l -w LOWERCASE
lowercase
```
