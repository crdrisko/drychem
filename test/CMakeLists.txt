### Unit Testing ###
include(CTest)
include(GoogleTest)

enable_testing()


### Tests ###
newTest(TESTNAME AllConversion
        INTERIOR_DIRECTORY TestConversions)

newTest(TESTNAME Mathematical
        INTERIOR_DIRECTORY TestMathematics)

newTest(TESTNAME MiscellaneousUnit
        INTERIOR_DIRECTORY TestPhysicalQuantities)
