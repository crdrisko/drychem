### Top Level CMake Script for C++ Units ###
cmake_minimum_required(VERSION 3.12.0)
project(CppUnits VERSION 1.0.0)


### Options ###
option(utils_build_all       "Builds common-utils library, corresponding unit tests, and corresponding code samples." OFF)
option(utils_build_tests     "Builds common-utils library and corresponding unit tests." OFF)
option(utils_build_samples   "Builds common-utils library and corresponding code samples." OFF)
option(utils_exclude_scripts "Builds appropriate libraries while ignoring the scripts directory." OFF)

option(units_build_all       "Builds all libraries, unit tests, and code samples." OFF)
option(units_build_tests     "Builds all libraries and unit tests." OFF)
option(units_build_samples   "Builds all libraries and code samples." OFF)
option(units_enable_coverage "Builds all libraries, unit tests, and enables coverage options." OFF)
option(units_format_codebase "Builds appropriate libraries while also formatting the code." OFF)

## Set appropriate option flags and continue ##
if (units_format_codebase)
    ## Run clang-format on all code except the files passed as arguments with the '-i' flag ##
    execute_process(COMMAND bash cmake/scripts/format-codebase.sh
                                    -i cpp-units/include/cpp-units/types/physicalQuantity.hpp
                                    -i cpp-units/include/cpp-units/physicalQuantities.hpp
                                    -i common-utilities/libs/utilities/samples/comparableExample.cpp
                    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                    OUTPUT_QUIET)
endif()

if (units_enable_coverage)
    set(units_build_tests ON)
    set(CMAKE_BUILD_TYPE "Debug")
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} --coverage)
endif()

if (units_build_all)
    set(utils_build_all ON)
    set(units_build_tests ON)
    set(units_build_samples ON)
endif()

if (units_build_tests)
    set(utils_build_tests ON)
endif()

if (units_build_samples)
    set(utils_build_samples ON)
endif()

if (utils_build_all)
    set(utils_build_tests ON)
    set(utils_build_samples ON)

    if (NOT units_build_all AND NOT units_build_tests AND NOT units_build_samples)
        set(exclude_units ON)
    endif()
endif()


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
include(cmake/units-utility-functions.cmake)


### Files / Directories ###
if (NOT exclude_scripts)
    set(SCRIPTS
        common-utilities/scripts/changeCase.sh
        common-utilities/scripts/compiler.sh
        common-utilities/scripts/fileMaker.sh
        common-utilities/scripts/linkLogin.sh
        common-utilities/scripts/modifyFiles.sh
        common-utilities/scripts/remover.sh
        common-utilities/scripts/utilities/errorHandling.sh
        common-utilities/scripts/utilities/showArgs.sh
        common-utilities/scripts/utilities/showOpts.sh
        common-utilities/scripts/utilities/typeParsing.sh)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/bin
    CACHE PATH
    "Single directory for all executables.")


### Libraries / Executables ###
include_directories(common-utilities/include common-utilities/include/common-utils)

set(LIBRARIES
    common-utilities/include/common-utils)

## Build the common-utilities code samples ##
if (utils_build_samples)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/samples)

    add_executable(fibonacciExample common-utilities/libs/errors/samples/fibonacciExample.cpp)                                 
    add_executable(comparableExample common-utilities/libs/utilities/samples/comparableExample.cpp)

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
endif()

if (NOT exclude_units)
    include_directories(cpp-units/include cpp-units/include/cpp-units)

    ## Build the cpp-units code samples ##
    # if (units_build_samples)
    #     set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/samples)

    #     add_executable(* cpp-units/libs/*/samples/*.cpp)

    #     set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
    # endif()

    list(APPEND LIBRARIES cpp-units/include/cpp-units)
endif()


### Installation ###
install(DIRECTORY ${LIBRARIES}
        DESTINATION include)

if (NOT units_exclude_scripts)
    foreach (SCRIPT ${SCRIPTS})
        ## Remove extensions and make scripts executable ##
        get_filename_component(filename "${SCRIPT}" NAME_WE)

        configure_file(${SCRIPT} "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${filename}" @ONLY)

        install(FILES "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${filename}"
                DESTINATION bin
                PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
                            GROUP_READ             GROUP_EXECUTE
                            WORLD_READ             WORLD_EXECUTE)
    endforeach()
endif()


### Unit Testing ###
if (utils_build_tests OR units_build_tests)
    find_package(GTest)
    find_package(Threads)

    if (NOT ${GTest_FOUND})
        ## If googletest isn't installed or can't be found, download it from github ##
        CppUnitsExternalDownload(PROJECT googletest
                                 REPOSITORY "https://github.com/google/googletest.git")

        set(GTEST_LIBRARIES gtest)
        set(GTEST_INCLUDE_DIRS "${gtest_SOURCE_DIR}/include")
    endif()

    include_directories(${GTEST_INCLUDE_DIRS})

    include(CTest)
    include(GoogleTest)

    enable_testing()

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/tests)

    add_subdirectory(cmake/Testing ${PROJECT_BINARY_DIR}/Testing)

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
endif()
