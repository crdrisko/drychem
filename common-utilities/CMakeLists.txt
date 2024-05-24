### Lower Level CMake Script for DryChem ###
cmake_minimum_required(VERSION 3.12.0)
project(CommonUtils VERSION 1.0.0)


### Options ###
if (utils_build_all)
    set(utils_build_tests ON PARENT_SCOPE)
    set(utils_build_samples ON)
endif()


### Libraries / Executables ###
set(LIBRARIES common-utilities/include/common-utils PARENT_SCOPE)

if (utils_build_samples)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DryChem_BINARY_DIR}/bin/samples)

    add_executable(fibonacciExample         libs/errors/samples/fibonacciExample.cpp)
    add_executable(markupParsingExample     libs/files/samples/markupParsingExample.cpp)
    add_executable(finiteDifferencesExample libs/math/samples/finiteDifferencesExample.cpp)
    add_executable(getOptsExample           libs/meta/samples/getOptsExample.cpp)
    add_executable(ciTokenizerExample       libs/strings/samples/ciTokenizerExample.cpp)
    add_executable(comparableExample        libs/utilities/samples/comparableExample.cpp)

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DryChem_BINARY_DIR}/bin)
endif()


### Installation ###
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
    set(SCRIPTS
        scripts/changeCase.sh
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
