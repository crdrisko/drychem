### Top Level CMake Script for CPP-Units ###
cmake_minimum_required(VERSION 3.10.0)
project(CPP-Units VERSION 1.0.0)


### Compilation Options ###
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

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

find_package(Utilities_API REQUIRED)

if (NOT ${UTILITIES_API_FOUND})
    ## If utilities-api isn't installed or can't be found, download it from github ##
    externalDownload(PROJECT utilities-api
                     REPOSITORY "https://github.com/crdrisko/utilities-api.git")

    set(UTILITIES_API_INCLUDE_DIR "${Utilities-API_SOURCE_DIR}/include")
    set(UTILITIES_API_FOUND TRUE)
endif()

include_directories(${UTILITIES_API_INCLUDE_DIR})


### Installation ###
install(DIRECTORY include/cpp-units
        DESTINATION include)


### Unit Testing ###
option(cpp-units_build_tests "Build all unit tests in the test directory." OFF)

if (cpp-units_build_tests)
    find_package(GTest)

    if (NOT ${GTest_FOUND})
        ## If googletest isn't installed or can't be found, download it from github ##
        externalDownload(PROJECT googletest
                         REPOSITORY "https://github.com/google/googletest.git")

        set(GTEST_LIBRARIES gtest)
        set(GTEST_INCLUDE_DIRS "${gtest_SOURCE_DIR}/include")
    endif()

    include_directories(${GTEST_INCLUDE_DIRS})
    set(CMAKE_CXX_FLAGS -pthread)

    add_subdirectory(test)
endif()
