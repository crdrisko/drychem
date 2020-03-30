### Unit Testing ###
include(CTest)
include(GoogleTest)

enable_testing()

## Function to create a new test based off the pre-defined naming template ##
function(new_test testname interiorDirectory)
    add_executable(test${testname}Functions ${interiorDirectory}/test${testname}Functions.cpp)

    if (coverage)
        target_compile_options(test${testname}Functions PRIVATE --coverage)
        target_link_libraries(test${testname}Functions PRIVATE --coverage)
    endif()

    target_link_libraries(test${testname}Functions gtest utilities-api)

    gtest_discover_tests(test${testname}Functions
                         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${interiorDirectory})
endfunction(new_test)

## Create all tests ##
new_test(Error TestErrors)
new_test(File TestFiles)
new_test(Math TestMath)
new_test(String TestStrings)
