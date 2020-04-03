### Unit Testing ###
include(CTest)
include(GoogleTest)

enable_testing()


### Functions ###
function(newTest)
    set(options)
    set(one_value_keywords TESTNAME
                           INTERIOR_DIRECTORY)
    set(multi_value_keywords)

    cmake_parse_arguments(TEST_ARGS "${options}" "${one_value_keywords}" "${multi_value_keywords}" ${ARGN})

    add_executable(test${TEST_ARGS_TESTNAME}Functions
                   ${TEST_ARGS_INTERIOR_DIRECTORY}/test${TEST_ARGS_TESTNAME}Functions.cpp)

    target_link_libraries(test${TEST_ARGS_TESTNAME}Functions ${GTEST_LIBRARIES})

    gtest_discover_tests(test${TEST_ARGS_TESTNAME}Functions
                         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${TEST_ARGS_INTERIOR_DIRECTORY})
endfunction()


### Tests ###
newTest(TESTNAME Error
        INTERIOR_DIRECTORY TestErrors)

newTest(TESTNAME File
        INTERIOR_DIRECTORY TestFiles)

newTest(TESTNAME Math
        INTERIOR_DIRECTORY TestMath)

newTest(TESTNAME String
        INTERIOR_DIRECTORY TestStrings)
