### Lower Level CMake Script for DryChem ###
cmake_minimum_required(VERSION 3.20.0)
project(UnitTesting VERSION 1.2.0)


### Unit Tests ###
if (units_build_tests)
    DryChemNewTest(TESTNAME AllMathFunctions
                   LIBRARY Units
                   INTERIOR_DIRECTORY CppUnits)

    DryChemNewTest(TESTNAME AllPhysicalQuantityFunctions
                   LIBRARY Units
                   INTERIOR_DIRECTORY CppUnits)
endif()

if (utils_build_tests)
    DryChemNewTest(TESTNAME AllErrorFunctions
                   LIBRARY Utilities
                   INTERIOR_DIRECTORY Errors)

    DryChemNewTest(TESTNAME AllFileFunctions
                   LIBRARY Utilities
                   INTERIOR_DIRECTORY Files
                   USEFILESYSTEM)

    DryChemNewTest(TESTNAME AllMathFunctions
                   LIBRARY Utilities
                   INTERIOR_DIRECTORY Math)

    DryChemNewTest(TESTNAME AllMetaFunctions
                   LIBRARY Utilities
                   INTERIOR_DIRECTORY Meta)

    DryChemNewTest(TESTNAME AllStringFunctions
                   LIBRARY Utilities
                   INTERIOR_DIRECTORY Strings)

    DryChemNewTest(TESTNAME AllUtilityFunctions
                   LIBRARY Utilities
                   INTERIOR_DIRECTORY Utilities)
endif()
