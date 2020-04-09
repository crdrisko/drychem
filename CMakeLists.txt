### Top Level CMake Script for Utilities-API ###
cmake_minimum_required(VERSION 3.10.0)
project(Utilities-API VERSION 1.1.0)


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


### Files / Directories ###
set(SCRIPTS
    scripts/changeCase.sh
    scripts/compiler.sh
    scripts/errorHandling.sh
    scripts/fileMaker.sh
    scripts/linkLogin.sh
    scripts/modifyFiles.sh
    scripts/remover.sh
    scripts/showArguments.sh
    scripts/showOptions.sh)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/bin
    CACHE PATH
    "Single directory for all executables.")


### Installation ###
install(DIRECTORY include/utils-api
        DESTINATION include)

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


### Unit Testing ###
option(utils-api_build_tests "Build all unit tests in the test directory." OFF)

if (utils-api_build_tests)
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
