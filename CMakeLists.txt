### Top Level CMake Script for CPP-Units ###
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


### External Modules ###
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

find_package(Utilities_API REQUIRED)
include_directories(${UTILITIES_API_INCLUDE_DIR})


### Installation ###
install(DIRECTORY include/cpp-units
        DESTINATION include)


### Unit Testing ###
option(cpp-units_build_tests "Build all unit tests in the test directory." OFF)

if (cpp-units_build_tests)
    find_package(GTest)

    if (NOT ${GTest_FOUND})
        ## If GTest isn't installed or can't be found, look in the external modules file ##
        find_package(GoogleTest)
    endif()

    include_directories(${GTEST_INCLUDE_DIRS})
    add_compile_options(-pthread)

    add_subdirectory(test)
endif()
