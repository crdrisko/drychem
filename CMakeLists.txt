### Top Level CMake Script for DryChem ###
cmake_minimum_required(VERSION 3.20.0)
project(DryChem VERSION 1.2.0)


### Options ###
option(chem_build_all             "Builds all libraries, unit tests, and code samples." OFF)
option(chem_build_tests           "Builds all libraries and unit tests." OFF)
option(chem_build_samples         "Builds all libraries and code samples." OFF)
option(chem_configure_docs        "Builds specified libraries while configuring the Doxygen file for documentation generation." OFF)
option(chem_enable_coverage       "Builds all libraries, unit tests, and enables coverage options." OFF)
option(chem_format_codebase       "Builds specified libraries while also formatting the code." OFF)

option(units_build_all            "Builds cpp-units library, corresponding unit tests, and corresponding code samples." OFF)
option(units_build_tests          "Builds cpp-units library and corresponding unit tests." OFF)
option(units_build_samples        "Builds cpp-units library and corresponding code samples." OFF)

option(utils_build_all            "Builds common-utils library, corresponding unit tests, and corresponding code samples." OFF)
option(utils_build_tests          "Builds common-utils library and corresponding unit tests." OFF)
option(utils_build_samples        "Builds common-utils library and corresponding code samples." OFF)
option(utils_exclude_scripts      "Builds specified libraries while ignoring the scripts directory." OFF)
option(utils_install_applications "Builds specified libraries and installs the applications associated with them." OFF)

if (chem_format_codebase AND NOT WIN32)
    find_program(formatter clang-format HINTS /opt/homebrew/bin/)

    if (NOT formatter_NOTFOUND)
        message(STATUS "Formatting DryChem")
        
        ## Run clang-format on all code except the files passed as arguments with the '-i' flag ##
        execute_process(COMMAND bash cmake/scripts/format-codebase.sh
                                        -f ${formatter}
                                        -i include/drychem/files/utils/fileExceptions.hpp
                                        -i include/drychem/math/calculus/differentiation/*
                                        -i include/drychem/math/calculus/integration.hpp
                                        -i include/drychem/math/statistics/*
                                        -i include/drychem/math/utils/mathExceptions.hpp
                                        -i include/drychem/meta/traits/containerTraits/*
                                        -i include/drychem/strings/utils/tokenizer.hpp
                                        -i include/cpp-units/math/basicMath.hpp
                                        -i include/cpp-units/types/physicalQuantity.hpp
                                        -i include/cpp-units/physicalQuantities.hpp
                                        -i samples/comparableExample.cpp
                        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
                        OUTPUT_QUIET)
    endif()
endif()

if (chem_enable_coverage)
    set(chem_build_tests ON)
    set(CMAKE_BUILD_TYPE "Debug")
    set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} --coverage)
endif()

if (chem_configure_docs)
    configure_file(${PROJECT_SOURCE_DIR}/docs/Doxyfile.in ${PROJECT_BINARY_DIR}/Doxyfile)
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

if (utils_build_all)
    set(utils_build_tests ON)
    set(utils_build_samples ON)
endif()

if (units_build_all)
    set(units_build_tests ON)
    set(units_build_samples ON)
endif()


### Compilation Options ###
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

if (NOT WIN32)
    add_compile_options(-Wall -Wextra -pedantic -Werror)

    if (CMAKE_COMPILER_IS_GNUCXX)
        add_definitions(-Wno-psabi)
    endif()
else()
    add_compile_options(/MD /WX)
endif()


### Functions ###
include(cmake/utility-functions.cmake)


### Files / Directories ###
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin
    CACHE PATH "Single directory for all executables.")

SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib
    CACHE PATH "Single directory for all static libraries.")


### Libraries / Executables ###
include_directories("${PROJECT_SOURCE_DIR}/include")
set(LIBRARIES include/drychem)

if (utils_build_samples)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/samples)

    add_executable(fibonacciExample         samples/fibonacciExample.cpp)
    add_executable(markupParsingExample     samples/markupParsingExample.cpp)
    add_executable(finiteDifferencesExample samples/finiteDifferencesExample.cpp)
    add_executable(getOptsExample           samples/getOptsExample.cpp)
    add_executable(ciTokenizerExample       samples/ciTokenizerExample.cpp)
    add_executable(comparableExample        samples/comparableExample.cpp)

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
endif()

if (NOT exclude_units)
    set(LIBRARIES ${LIBRARIES} include/cpp-units)

    if (units_build_samples)
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/samples)

        # add_executable(***Example cpp-units/libs/***/samples/***Example.cpp)

        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
    endif()
endif()


### Installation ###
install(DIRECTORY ${LIBRARIES}
        DESTINATION include)

if (utils_install_applications)
    foreach (APP ${APPLICATIONS})
        install(FILES "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${APP}"
                DESTINATION bin
                PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
                            GROUP_READ             GROUP_EXECUTE
                            WORLD_READ             WORLD_EXECUTE)
    endforeach()
endif()

if (NOT utils_exclude_scripts)
    set(SCRIPTS scripts/changeCase.sh
                scripts/compiler.sh
                scripts/fileMaker.sh
                scripts/linkLogin.sh
                scripts/modifyFiles.sh
                scripts/utilities/errorHandling.sh
                scripts/utilities/showOpts.sh
                scripts/utilities/typeParsing.sh)

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
    # find_package(GTest 1.15.2)
    find_package(Threads)

    if (NOT GTEST_FOUND)
        include(FetchContent)

        ## If googletest isn't installed or can't be found, download it from github ##
        message(STATUS "Fetching GoogleTest...")
        FetchContent_Declare(googletest     # v1.15.2
                             GIT_REPOSITORY "https://github.com/google/googletest.git"
                             GIT_TAG        "b514bdc898e2951020cbdca1304b75f5950d1f59")
                            
        FetchContent_MakeAvailable(googletest)

        set(GTEST_FOUND TRUE)
        set(GTEST_LIBRARIES gtest)
        set(GTEST_INCLUDE_DIRS "${gtest_SOURCE_DIR}/include")
    endif()

    include_directories(${GTEST_INCLUDE_DIRS})

    include(CTest)
    include(GoogleTest)

    enable_testing()

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/tests)

    ## Use a seperate directory for tests to declutter build directory
    add_subdirectory(cmake/Testing ${PROJECT_BINARY_DIR}/Testing)

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)
endif()
