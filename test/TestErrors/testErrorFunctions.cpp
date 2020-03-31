// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testErrorFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:55:57
// Description: Provides 100% unit test coverage over all error utility functions

#include <memory>
#include <string>

#include <gtest/gtest.h>

#include "../../include/utils-api/internal/Errors/errorUtilities.hpp"

using namespace Utilities_API::Errors;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testErrorFunctions, errorPrintsMessageToStandardError)
{
    testing::internal::CaptureStderr();

    ErrorMessagePtr errorMessage { std::make_shared<ErrorMessage>("Utilities-API") };

    errorMessage->printErrorMessage("Testing the output of the non-fatal error message command.");

    std::string output = testing::internal::GetCapturedStderr();
    ASSERT_EQ(output, "Utilities-API:\n\tTesting the output of the non-fatal error message command.\n");
}

TEST(testErrorFunctions, fatalErrorCausesProgramTermination)
{
    ASSERT_DEATH(
    {
        ErrorMessagePtr errorMessage { std::make_shared<FatalErrorMessage>("Utilities-API", 1) };

        errorMessage->printErrorMessage("Fatal Error, Program Terminated.");
    }, "Utilities-API:\n\tFatal Error, Program Terminated.");
}
