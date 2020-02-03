// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testErrorFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:55:57
// Description: Provides 100% unit test coverage over all error utility functions

#include <gtest/gtest.h>
#include "../../include/internal/Errors/errorUtilities.hpp"

using namespace Utilities_API::Errors;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testErrorFunctions, properErrorMessagePrinting)
{
    testing::internal::CaptureStderr();

    printNonFatalErrorMessage("Testing the output of the non-fatal error message command.");

    std::string output = testing::internal::GetCapturedStderr();
    ASSERT_EQ(output, "Testing the output of the non-fatal error message command.\n");
}

TEST(testErrorFunctions, properFatalErrorProgramExit)
{
    ASSERT_DEATH(
    {
        printFatalErrorMessage(1, "Fatal Error, Program Terminated.");
    }, "Fatal Error, Program Terminated.");
}
