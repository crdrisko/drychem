### Unit Tests ###
if (units_build_tests)
    # CppUnitsNewTest(TESTNAME AllConversionFunctions
    #                 LIBRARY cpp-units
    #                 INTERIOR_DIRECTORY conversions)

    # CppUnitsNewTest(TESTNAME AllMathFunctions
    #                 LIBRARY cpp-units
    #                 INTERIOR_DIRECTORY math)

    CppUnitsNewTest(TESTNAME AllPhysicalQuantityFunctions
                    LIBRARY cpp-units
                    INTERIOR_DIRECTORY physicalQuantities)
endif()

if (utils_build_tests)
    CppUnitsNewTest(TESTNAME AllErrorFunctions
                    LIBRARY common-utilities
                    INTERIOR_DIRECTORY errors)

    # CppUnitsNewTest(TESTNAME AllFileFunctions
    #                 LIBRARY common-utilities
    #                 INTERIOR_DIRECTORY files)

    CppUnitsNewTest(TESTNAME AllMathFunctions
                    LIBRARY common-utilities
                    INTERIOR_DIRECTORY math)

    # CppUnitsNewTest(TESTNAME AllStringFunctions
    #                 LIBRARY common-utilities
    #                 INTERIOR_DIRECTORY strings)

    CppUnitsNewTest(TESTNAME AllUtilityFunctions
                    LIBRARY common-utilities
                    INTERIOR_DIRECTORY utilities)
endif()
