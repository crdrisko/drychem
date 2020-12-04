### Top Level CMake Script for DryChem ###
cmake_minimum_required(VERSION 3.12.0)
project(DryChem VERSION 1.0.0)


### Options ###
option(chem_build_all       "Builds all libraries, unit tests, and code samples." OFF)
option(chem_build_tests     "Builds all libraries and unit tests." OFF)
option(chem_build_samples   "Builds all libraries and code samples." OFF)
option(chem_enable_coverage "Builds all libraries, unit tests, and enables coverage options." OFF)
option(chem_format_codebase "Builds specified libraries while also formatting the code." OFF)

option(units_build_all       "Builds cpp-units library, corresponding unit tests, and corresponding code samples." OFF)
option(units_build_tests     "Builds cpp-units library and corresponding unit tests." OFF)
option(units_build_samples   "Builds cpp-units library and corresponding code samples." OFF)

option(utils_build_all       "Builds common-utils library, corresponding unit tests, and corresponding code samples." OFF)
option(utils_build_tests     "Builds common-utils library and corresponding unit tests." OFF)
option(utils_build_samples   "Builds common-utils library and corresponding code samples." OFF)
option(utils_exclude_scripts "Builds specified libraries while ignoring the scripts directory." OFF)

if (chem_format_codebase AND NOT WIN32)
    ## Run clang-format on all code except the files passed as arguments with the '-i' flag ##
    execute_process(COMMAND bash cmake/scripts/format-codebase.sh
                                    -i common-utilities/include/common-utils/math/calculus/differentiation/*
                                    -i common-utilities/include/common-utils/math/calculus/integration.hpp
                                    -i common-utilities/include/common-utils/math/statistics/*
                                    -i common-utilities/include/common-utils/math/utils/mathExceptions.hpp
                                    -i common-utilities/include/common-utils/strings/utils/tokenizer.hpp
                                    -i common-utilities/include/common-utils/utilities/traits/containerTraits/*
                                    -i common-utilities/libs/utilities/samples/comparableExample.cpp
                                    -i cpp-units/include/cpp-units/math/basicMath.hpp
                                    -i cpp-units/include/cpp-units/types/physicalQuantity.hpp
                                    -i cpp-units/include/cpp-units/physicalQuantities.hpp
                    WORKING_DIRECTORY ${DryChem_SOURCE_DIR}
                    OUTPUT_QUIET)
endif()

if (chem_enable_coverage)
    set(chem_build_tests ON)
    set(CMAKE_BUILD_TYPE "Debug")
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} --coverage)
endif()

if (chem_build_all)
    set(units_build_all ON)
    set(utils_build_all ON)
endif()

if (chem_build_tests)
    set(units_build_tests ON)
    set(utils_build_tests ON)
endif()

if (chem_build_samples)
    set(units_build_samples ON)
    set(utils_build_samples ON)
endif()

if (NOT chem_build_all AND NOT chem_build_tests AND NOT chem_build_samples
        AND NOT units_build_all AND NOT units_build_tests AND NOT units_build_samples)
    set(exclude_units ON)
endif()

### Compilation Options ###
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

if (WIN32)
    add_compile_options(/MD /WX)
else()
    add_compile_options(-pedantic-errors -Wall -Werror -Wextra)
endif()

if (CMAKE_COMPILER_IS_GNUCXX)
    add_compile_options(-Wno-psabi)
endif()


### Functions ###
include(cmake/utility-functions.cmake)


### Files / Directories ###
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin
    CACHE PATH "Single directory for all executables.")


### Libraries / Executables ###
include_directories(common-utilities/include)
add_subdirectory(common-utilities)

if (NOT exclude_units)
    include_directories(cpp-units/include)
    add_subdirectory(cpp-units)
endif()


### Installation ###
install(DIRECTORY ${LIBRARIES}
        DESTINATION include)


### Unit Testing ###
if (utils_build_tests OR units_build_tests)
    find_package(GTest)
    find_package(Threads)

    if (NOT ${GTest_FOUND})
        ## If googletest isn't installed or can't be found, download it from github ##
        DryChemExternalDownload(PROJECT googletest
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
