### Unit Testing ###
include(CTest)
include(GoogleTest)

enable_testing()

## Tests ##
UtilsNewTest(TESTNAME AllErrorFunctions
             INTERIOR_DIRECTORY TestErrors)

UtilsNewTest(TESTNAME FileFunctions
             INTERIOR_DIRECTORY TestFiles)

UtilsNewTest(TESTNAME MathFunctions
             INTERIOR_DIRECTORY TestMath)

UtilsNewTest(TESTNAME StringFunctions
             INTERIOR_DIRECTORY TestStrings)
