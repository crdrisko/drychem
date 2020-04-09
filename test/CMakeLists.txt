### Unit Testing ###
include(CTest)
include(GoogleTest)

enable_testing()


### Tests ###
newTest(TESTNAME Error
        INTERIOR_DIRECTORY TestErrors)

newTest(TESTNAME File
        INTERIOR_DIRECTORY TestFiles)

newTest(TESTNAME Math
        INTERIOR_DIRECTORY TestMath)

newTest(TESTNAME String
        INTERIOR_DIRECTORY TestStrings)
