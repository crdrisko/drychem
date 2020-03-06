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

## Function to create a new test based off the pre-defined naming template for unit conversions ##
function(new_conversion_test testname)
    new_test(${testname}Conversion TestConversions/${testname})
endfunction(new_conversion_test)

## Locate GTest ##
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

## Create all tests ##
new_test(Math TestMath)
new_test(MiscellaneousUnit TestPhysicalQuantities)

new_conversion_test(AmountOfSubstance)
new_conversion_test(Angle)
new_conversion_test(Area)
# new_conversion_test(ElectricCharge)
new_conversion_test(Energy)
new_conversion_test(Length)
# new_conversion_test(MagneticFluxDensity)
new_conversion_test(Mass)
new_conversion_test(MolarEnergy)
new_conversion_test(Pressure)
new_conversion_test(SI_UnitPrefixes)
new_conversion_test(Temperature)
new_conversion_test(Time)
new_conversion_test(Volume)
