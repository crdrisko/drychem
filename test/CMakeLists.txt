### Unit Testing ###
include(CTest)
include(GoogleTest)

enable_testing()

## Function to create a new test based off the pre-defined naming template ##
function(new_test testname interiorDirectory)
    add_executable(test${testname}Functions ${interiorDirectory}/test${testname}Functions.cpp)

    target_link_libraries(test${testname}Functions ${GTEST_LIBRARIES})

    gtest_discover_tests(test${testname}Functions
                         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${interiorDirectory})
endfunction(new_test)

## Create all tests ##
new_test(AllConversion TestConversions)
new_test(Math TestMath)
new_test(MiscellaneousUnit TestPhysicalQuantities)
