# C++ Units

This project contains a unit converter written in C++ designed to be extendable with a number of interfaces. Currently, the public API of the project is in the development stage, but I hope to add a command line interface (CLI), graphical user interface (GUI), and web application very soon. Each of these interfaces will serve to help my software development skills by focusing on a singular project I can continue to enhance as I learn more.

## Table Of Contents

- [Building and Installing](#Building-and-Installing)

- [C++ Libraries](#C++-Libraries)

## Building and Installing

To build the cpp-units libraries there are a few options that can be specified when building with `cmake`, these are discussed here:

- `units_build_all`

  Libraries, unit tests, and code samples will all be built. This option should be used if you don't want to install the tests and samples of only the common-utilities portion of the larger drychem repository. Otherwise, use the `chem_build_all` option.

  *Note:* The common-utilities libraries will be installed regardless, becasue the cpp-units library depends on them.

- `units_build_tests`

  If you're interested in building the unit tests but don't care about the examples that accompany the project, this option will build the cpp-units library and the tests.

  *Note:* Only the libraries will be installed.

- `units_build_samples`

  If you're interested in building the examples but don't care about the unit tests that accompany the project, this option will build the cpp-units library and the samples.

  *Note:* Only the libraries will be installed.

## C++ Libraries

...
