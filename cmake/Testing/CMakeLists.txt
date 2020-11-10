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

    # DryChemNewTest(TESTNAME AllFileFunctions
    #                 LIBRARY common-utilities
    #                 INTERIOR_DIRECTORY files)

    DryChemNewTest(TESTNAME AllMathFunctions
                    LIBRARY common-utilities
                    INTERIOR_DIRECTORY math)

    # DryChemNewTest(TESTNAME AllStringFunctions
    #                 LIBRARY common-utilities
    #                 INTERIOR_DIRECTORY strings)

    DryChemNewTest(TESTNAME AllUtilityFunctions
                    LIBRARY common-utilities
                    INTERIOR_DIRECTORY utilities)
endif()
