// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testErrorHandling.hpp
// Author: crdrisko
// Date: 08/26/2020-14:35:44
// Description: Provides ~100% unit test coverage over all error handing functions

#ifndef DRYCHEM_COMMON_UTILITIES_TESTING_TESTERRORHANDLING_HPP
#define DRYCHEM_COMMON_UTILITIES_TESTING_TESTERRORHANDLING_HPP

#include <string>

#include <gtest/gtest.h>

#include "common-utils/errors.hpp"

GTEST_TEST(testErrorHandling, errorPrintsMessageToStandardError)
{
    testing::internal::CaptureStderr();

    DryChem::printErrorMessage<DryChem::ErrorSeverity::Warning>(
        DryChem::ErrorMessage {"Common-Utilities", "Testing the output of the non-fatal error message command."});

    std::string output = testing::internal::GetCapturedStderr();
    ASSERT_EQ(output, "Common-Utilities Warning:\n\tTesting the output of the non-fatal error message command.\n");
}

GTEST_TEST(testErrorHandling, fatalErrorCausesProgramTermination)
{
    ASSERT_DEATH(
        {
            DryChem::printErrorMessage<DryChem::ErrorSeverity::Fatal>(
                DryChem::ErrorMessage {"Common-Utilities", "Fatal Error, Program Terminated."});
        },
        "Common-Utilities Fatal Error:\n\tFatal Error, Program Terminated.\n");
}

GTEST_TEST(testErrorHandling, defaultTemplateParameterIsAWarning)
{
    testing::internal::CaptureStderr();

    DryChem::printErrorMessage(
        DryChem::ErrorMessage {"Common-Utilities", "Testing the output of the non-fatal error message command."});

    std::string output = testing::internal::GetCapturedStderr();
    ASSERT_EQ(output, "Common-Utilities Warning:\n\tTesting the output of the non-fatal error message command.\n");
}

GTEST_TEST(testErrorHandling, aliasLambdaFunctionWorksForAFatalError)
{
    ASSERT_DEATH(
        {
            DryChem::printFatalErrorMessage(DryChem::ErrorMessage {"Common-Utilities", "Fatal Error, Program Terminated."});
        },
        "Common-Utilities Fatal Error:\n\tFatal Error, Program Terminated.\n");
}

#endif
