### Top level cmake script for Utilities-API ###
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


### Files / Directories ###
set(SOURCES
    src/Files/markupFile.cpp
    src/Strings/stringUtilities.cpp
    src/Files/textFile.cpp)

set(BASH_FILES
    scripts/changeCase.sh
    scripts/compiler.sh
    scripts/errorHandling.sh
    scripts/fileMaker.sh
    scripts/linkLogin.sh
    scripts/modifyFiles.sh
    scripts/remover.sh
    scripts/showArguments.sh
    scripts/showOptions.sh)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/lib
    CACHE PATH
    "Single directory for all shared libraries.")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY
    ${PROJECT_BINARY_DIR}/bin
    CACHE PATH
    "Single directory for all executables.")


### Libraries / Executables ###
add_library(utilities-api SHARED ${SOURCES})

if (CMAKE_COMPILER_IS_GNUCXX)
    target_link_libraries(utilities-api stdc++fs)
endif()


### Installation ###
install(TARGETS utilities-api
        DESTINATION lib)

install(DIRECTORY include/
        DESTINATION include/utils-api)

foreach(BASH_FILE ${BASH_FILES})
    ## Remove bash extensions and make scripts executable ##
    get_filename_component(filename "${BASH_FILE}" NAME_WE)

    configure_file(${BASH_FILE} "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${filename}" @ONLY)

    install(FILES "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${filename}"
            DESTINATION bin
            PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE
                        GROUP_READ             GROUP_EXECUTE
                        WORLD_READ             WORLD_EXECUTE)
endforeach()


### Unit Testing ###
option(build_all_tests "Build all unit tests in the test directory." OFF)

if (build_all_tests)
    add_subdirectory(test)
endif()
