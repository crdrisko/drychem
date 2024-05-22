### Lower Level CMake Script for DryChem ###
cmake_minimum_required(VERSION 3.12.0)
project(UnitTesting VERSION 1.0.0)


### Unit Tests ###
if (units_build_tests)
    # DryChemNewTest(TESTNAME AllConversionFunctions
    #                 LIBRARY cpp-units
    #                 INTERIOR_DIRECTORY conversions)

    DryChemNewTest(TESTNAME AllMathFunctions
                   LIBRARY cpp-units
                   INTERIOR_DIRECTORY math)

    DryChemNewTest(TESTNAME AllPhysicalQuantityFunctions
                   LIBRARY cpp-units
                   INTERIOR_DIRECTORY physicalQuantities)
endif()

if (utils_build_tests)
    DryChemNewTest(TESTNAME AllErrorFunctions
                   LIBRARY common-utilities
                   INTERIOR_DIRECTORY errors)

    DryChemNewTest(TESTNAME AllFileFunctions
                   LIBRARY common-utilities
                   INTERIOR_DIRECTORY files
                   USEFILESYSTEM)

    DryChemNewTest(TESTNAME AllMathFunctions
                   LIBRARY common-utilities
                   INTERIOR_DIRECTORY math)

    DryChemNewTest(TESTNAME AllMetaFunctions
                   LIBRARY common-utilities
                   INTERIOR_DIRECTORY meta)
    
    DryChemNewTest(TESTNAME AllNetworkingFunctions
                   LIBRARY common-utilities
                   INTERIOR_DIRECTORY networking)

    DryChemNewTest(TESTNAME AllStringFunctions
                   LIBRARY common-utilities
                   INTERIOR_DIRECTORY strings)

    DryChemNewTest(TESTNAME AllUtilityFunctions
                   LIBRARY common-utilities
                   INTERIOR_DIRECTORY utilities)
endif()
