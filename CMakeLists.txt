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

## Need to find utilities-api or build it from source ##
find_package(Utilities_API)
include_directories(${UTILITIES_API_INCLUDE_DIR})


### Installation ###
install(DIRECTORY include
        DESTINATION include)


### Unit Testing ###
option(cpp-units_build_tests "Build all unit tests in the test directory." OFF)

if (cpp-units_build_tests)
    ## Need to find googletest or build it from source ##
    find_package(GTest)

    if (NOT ${GTest_FOUND})
        ## Download and unpack googletest at configure time ##
        configure_file(cmake/GTest-CMakeLists.txt.in googletest-download/CMakeLists.txt)

        execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                        RESULT_VARIABLE result
                        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
        if(result)
            message(FATAL_ERROR "CMake step for googletest failed: ${result}")
        endif()

        execute_process(COMMAND ${CMAKE_COMMAND} --build .
                        RESULT_VARIABLE result
                        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download)
        if(result)
            message(FATAL_ERROR "Build step for googletest failed: ${result}")
        endif()

        ## Add googletest directly to our build ##
        add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                         ${CMAKE_CURRENT_BINARY_DIR}/googletest-build
                         EXCLUDE_FROM_ALL)

        set(GTEST_LIBRARIES gtest)
        set(GTEST_INCLUDE_DIRS "${gtest_SOURCE_DIR}/include")
    endif()

    include_directories(${GTEST_INCLUDE_DIRS})
    add_compile_options(-pthread)

    add_subdirectory(test)
endif()
