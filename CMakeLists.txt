### Top Level CMake Script for Utilities-API ###
cmake_minimum_required(VERSION 3.10.0)
project(Utilities-API VERSION 1.0.0)


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
function(externalDownload)
    set(options)
    set(one_value_keywords PROJECT
                           REPOSITORY)
    set(multi_value_keywords)

    cmake_parse_arguments(EXTERN_ARGS "${options}" "${one_value_keywords}" "${multi_value_keywords}" ${ARGN})

    ## Download and unpack project at configure time ##
    configure_file(cmake/CMakeLists.txt.in ${EXTERN_ARGS_PROJECT}-download/CMakeLists.txt)

    ## Configuration step ##
    execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
                    RESULT_VARIABLE result
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${EXTERN_ARGS_PROJECT}-download)
    if (result)
        message(FATAL_ERROR "CMake step for ${EXTERN_ARGS_PROJECT} failed: ${result}")
    endif()

    ## Build Step ##
    execute_process(COMMAND ${CMAKE_COMMAND} --build .
                    RESULT_VARIABLE result
                    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/${EXTERN_ARGS_PROJECT}-download)
    if (result)
        message(FATAL_ERROR "Build step for ${EXTERN_ARGS_PROJECT} failed: ${result}")
    endif()

    ## Add project directly to our build ##
    add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/${EXTERN_ARGS_PROJECT}-download/${EXTERN_ARGS_PROJECT}-src
                     ${CMAKE_CURRENT_BINARY_DIR}/${EXTERN_ARGS_PROJECT}-download/${EXTERL_ARGS_PROJECT}-build
                     EXCLUDE_FROM_ALL)
endfunction()


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
        ## If GTest isn't installed or can't be found, download it from github ##
        externalDownload(PROJECT googletest
                         REPOSITORY "https://github.com/google/googletest.git")

        set(GTEST_LIBRARIES gtest)
        set(GTEST_INCLUDE_DIRS "${gtest_SOURCE_DIR}/include")
    endif()

    include_directories(${GTEST_INCLUDE_DIRS})
    add_compile_options(-pthread)

    add_subdirectory(test)
endif()
