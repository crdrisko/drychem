### Function to find and download external projects from Github ###
function(DryChemExternalDownload)
    set(options)
    set(one_value_keywords PROJECT
                           REPOSITORY)
    set(multi_value_keywords)

    cmake_parse_arguments(EXTERN_ARGS "${options}" "${one_value_keywords}" "${multi_value_keywords}" ${ARGN})

    ## Download and unpack project at configure time ##
    configure_file(${DryChem_SOURCE_DIR}/cmake/CMakeLists.txt.in ${EXTERN_ARGS_PROJECT}-download/CMakeLists.txt)

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


### Function to create a new test from a predefined naming template ###
function(DryChemNewTest)
    set(options USEFILESYSTEM)
    set(one_value_keywords TESTNAME
                           LIBRARY
                           INTERIOR_DIRECTORY)
    set(multi_value_keywords)

    cmake_parse_arguments(TEST_ARGS "${options}" "${one_value_keywords}" "${multi_value_keywords}" ${ARGN})

    set(TESTPATH ${DryChem_SOURCE_DIR}/${TEST_ARGS_LIBRARY}/libs/${TEST_ARGS_INTERIOR_DIRECTORY}/tests)

    add_executable(${TEST_ARGS_LIBRARY}Test${TEST_ARGS_TESTNAME} ${TESTPATH}/test${TEST_ARGS_TESTNAME}.cpp)

    target_link_libraries(${TEST_ARGS_LIBRARY}Test${TEST_ARGS_TESTNAME} ${GTEST_LIBRARIES} Threads::Threads)

    if (TEST_ARGS_USEFILESYSTEM AND CMAKE_COMPILER_IS_GNUCXX)
        target_link_libraries(${TEST_ARGS_LIBRARY}Test${TEST_ARGS_TESTNAME} stdc++fs)
    endif()

    gtest_discover_tests(${TEST_ARGS_LIBRARY}Test${TEST_ARGS_TESTNAME} WORKING_DIRECTORY ${TESTPATH})
endfunction()
