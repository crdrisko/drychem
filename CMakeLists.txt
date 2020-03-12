### Top level cmake script for CPP-Units ###
cmake_minimum_required(VERSION 3.10.0)
project(CPP-Units VERSION 1.0.0)


### Compilation Options ###
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

add_compile_options(-Wall -Wextra -pedantic -Werror)

if (CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-Wno-psabi)
endif()


### Libraries / Executables ###
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

find_package(Utilities_API REQUIRED)
include_directories(${UTILITIES_API_INCLUDE_DIR})


### Installation ###
install(DIRECTORY include/
        DESTINATION include/cpp-units)


### Unit Testing ###
option(build_all_tests "Build all unit tests in the test directory." OFF)

if (build_all_tests)
    add_subdirectory(test)
endif()
