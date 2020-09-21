### Unit Testing ###
include(CTest)
include(GoogleTest)

enable_testing()

## Tests ##
UtilsNewTest(TESTNAME AllErrorFunctions
             INTERIOR_DIRECTORY errors)

# UtilsNewTest(TESTNAME AllFileFunctions
#              INTERIOR_DIRECTORY files)

# UtilsNewTest(TESTNAME AllMathFunctions
#              INTERIOR_DIRECTORY math)

# UtilsNewTest(TESTNAME AllOperationFunctions
#              INTERIOR_DIRECTORY operations)

# UtilsNewTest(TESTNAME AllStringFunctions
#              INTERIOR_DIRECTORY strings)
