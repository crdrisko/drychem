// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testErrorHandling.hpp
// Author: crdrisko
// Date: 08/26/2020-14:35:44
// Description: Provides ~100% unit test coverage over all error handing functions

#ifndef COMMON_UTILITIES_TESTING_TESTERRORHANDLING_HPP
#define COMMON_UTILITIES_TESTING_TESTERRORHANDLING_HPP

#include <string>

#include <gtest/gtest.h>

#include "errors.hpp"

using namespace CppUtils::Errors;

//! \test Testing the \c CppUtils::Errors::printErrorMessage function with a warning
GTEST_TEST(testErrorHandling, errorPrintsMessageToStandardError)
{
    testing::internal::CaptureStderr();

    printErrorMessage<ErrorSeverity::Warning>(
        ErrorMessage {"Common-Utilities", "Testing the output of the non-fatal error message command."});

    std::string output = testing::internal::GetCapturedStderr();
    ASSERT_EQ(output, "Common-Utilities Warning:\n\tTesting the output of the non-fatal error message command.\n");
}

//! \test Testing the \c CppUtils::Errors::printErrorMessage function with a fatal error
GTEST_TEST(testErrorHandling, fatalErrorCausesProgramTermination)
{
    ASSERT_DEATH(
        {
            printErrorMessage<ErrorSeverity::Fatal>(ErrorMessage {"Common-Utilities", "Fatal Error, Program Terminated."});
        },
        "Common-Utilities Fatal Error:\n\tFatal Error, Program Terminated.\n");
}

//! \test Testing the \c CppUtils::Errors::printErrorMessage function's default state
GTEST_TEST(testErrorHandling, defaultTemplateParameterIsAWarning)
{
    testing::internal::CaptureStderr();

    printErrorMessage(ErrorMessage {"Common-Utilities", "Testing the output of the non-fatal error message command."});

    std::string output = testing::internal::GetCapturedStderr();
    ASSERT_EQ(output, "Common-Utilities Warning:\n\tTesting the output of the non-fatal error message command.\n");
}

//! \test Testing the \c CppUtils::Errors::printFatalErrorMessage lambda function
GTEST_TEST(testErrorHandling, aliasLambdaFunctionWorksForAFatalError)
{
    ASSERT_DEATH(
        {
            printFatalErrorMessage(ErrorMessage {"Common-Utilities", "Fatal Error, Program Terminated."});
        },
        "Common-Utilities Fatal Error:\n\tFatal Error, Program Terminated.\n");
}

#endif
