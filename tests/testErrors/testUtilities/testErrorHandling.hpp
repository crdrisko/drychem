// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testErrorHandling.hpp
// Author: crdrisko
// Date: 08/26/2020-14:35:44
// Description: Provides ~100% unit test coverage over all error handing functions

#ifndef DRYCHEM_TESTS_TESTERRORS_TESTUTILITIES_TESTERRORHANDLING_HPP
#define DRYCHEM_TESTS_TESTERRORS_TESTUTILITIES_TESTERRORHANDLING_HPP

#include <string>

#include <drychem/drychem.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testErrorHandling, errorPrintsMessageToStandardError)
{
    testing::internal::CaptureStderr();

    DryChem::printErrorMessage<DryChem::ErrorSeverity::Warning>(
        DryChem::ErrorMessage {"DryChem", "Testing the output of the non-fatal error message command."});

    std::string output = testing::internal::GetCapturedStderr();
    ASSERT_EQ(output, "DryChem Warning:\n    Testing the output of the non-fatal error message command.\n");
}

GTEST_TEST(testErrorHandling, fatalErrorCausesProgramTermination)
{
    ASSERT_DEATH(
        {
            DryChem::printErrorMessage<DryChem::ErrorSeverity::Fatal>(
                DryChem::ErrorMessage {"DryChem", "Fatal Error, Program Terminated."});
        },
        "DryChem Fatal Error:\n    Fatal Error, Program Terminated.\n");
}

GTEST_TEST(testErrorHandling, defaultTemplateParameterIsAWarning)
{
    testing::internal::CaptureStderr();

    DryChem::printErrorMessage(
        DryChem::ErrorMessage {"DryChem", "Testing the output of the non-fatal error message command."});

    std::string output = testing::internal::GetCapturedStderr();
    ASSERT_EQ(output, "DryChem Warning:\n    Testing the output of the non-fatal error message command.\n");
}

GTEST_TEST(testErrorHandling, aliasLambdaFunctionWorksForAFatalError)
{
    ASSERT_DEATH(
        { DryChem::printFatalErrorMessage(DryChem::ErrorMessage {"DryChem", "Fatal Error, Program Terminated."}); },
        "DryChem Fatal Error:\n    Fatal Error, Program Terminated.\n");
}

#endif
