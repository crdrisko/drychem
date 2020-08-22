### Unit Testing ###
include(CTest)
include(GoogleTest)

enable_testing()

## Tests ##
UtilsNewTest(TESTNAME Container
             INTERIOR_DIRECTORY TestContainers)

UtilsNewTest(TESTNAME Error
             INTERIOR_DIRECTORY TestErrors)

UtilsNewTest(TESTNAME File
             INTERIOR_DIRECTORY TestFiles)

UtilsNewTest(TESTNAME Math
             INTERIOR_DIRECTORY TestMath)

UtilsNewTest(TESTNAME String
             INTERIOR_DIRECTORY TestStrings)
