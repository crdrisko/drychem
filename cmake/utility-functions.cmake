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
