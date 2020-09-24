### Top Level CMake Script for C++ Units ###
cmake_minimum_required(VERSION 3.10.0)
project(CPPUnits VERSION 1.0.0)


### Options ###
option(units_build_tests "Build all unit tests in the testing directory." OFF)
option(units_coverage "Turn on coverage options for use with lcov, gcov, and/or coveralls." OFF)

if (units_coverage)
    set(units_build_tests ON)
    set(CMAKE_BUILD_TYPE "Debug")
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} --coverage)
endif()


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


### Functions ###
include(cmake/utility-functions.cmake)


### External Modules ###
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/modules")

find_package(CommonUtilities REQUIRED)

if (NOT ${COMMON_UTILITIES_FOUND})
    ## If common-utilities isn't installed or can't be found, download it from github ##
    UnitsExternalDownload(PROJECT common-utilities
                          REPOSITORY "https://github.com/crdrisko/common-utilities.git")

    set(COMMON_UTILITIES_INCLUDE_DIR "${CommonUtilities_SOURCE_DIR}/include")
    set(COMMON_UTILITIES_FOUND True)
endif()

include_directories(${COMMON_UTILITIES_INCLUDE_DIR}/common-utils)


### Libraries / Executables ###
include_directories(include/cpp-units)


### Installation ###
install(DIRECTORY include/cpp-units
        DESTINATION include)


### Unit Testing ###
if (units_build_tests)
    find_package(GTest)
    find_package(Threads)

    if (NOT ${GTest_FOUND})
        ## If googletest isn't installed or can't be found, download it from github ##
        UnitsExternalDownload(PROJECT googletest
                              REPOSITORY "https://github.com/google/googletest.git")

        set(GTEST_LIBRARIES gtest)
        set(GTEST_INCLUDE_DIRS "${gtest_SOURCE_DIR}/include")
    endif()

    include_directories(${GTEST_INCLUDE_DIRS})

    include(CTest)
    include(GoogleTest)

    enable_testing()

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/tests)

    add_subdirectory(cmake/tests ${PROJECT_BINARY_DIR}/Testing)

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
endif()
