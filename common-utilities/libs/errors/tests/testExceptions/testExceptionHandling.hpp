// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testExceptionHandling.hpp
// Author: crdrisko
// Date: 08/27/2020-12:07:48
// Description: Provides ~100% unit test coverage over all exception handing functions

#ifndef COMMON_UTILITIES_TESTING_TESTEXCEPTIONHANDLING_HPP
#define COMMON_UTILITIES_TESTING_TESTEXCEPTIONHANDLING_HPP

#include <exception>
#include <iostream>
#include <new>
#include <string>

#include <gtest/gtest.h>

#include "errors.hpp"

using namespace CppUtils::Errors;

GTEST_TEST(testExceptionHandling, thisIsHowWeShouldCatchAndHandleAllExceptions)
{
    ASSERT_DEATH(
        {
            try
            {
                try
                {
                    throw std::bad_alloc();
                }
                catch (const std::exception& except)
                {
                    // Toss the exception back up for program termination and a more verbose message
                    ErrorMessage error1;
                    error1.programName = "YourProgramName";
                    error1.message     = "A verbose error message describing the problem: " + std::string {except.what()};

                    throw FatalException(error1);
                }
            }
            catch (const FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        "YourProgramName Fatal Error:\n\tA verbose error message describing the problem: std::bad_alloc\n");
}

GTEST_TEST(testExceptionHandling, fatalErrorsAreHandledByTerminating)
{
    ASSERT_DEATH(
        {
            ErrorMessage error;
            error.programName = "Common-Utilities";
            error.message     = "This would be the error message.";

            FatalException exceptFatal {error};
            exceptFatal.handleErrorWithMessage();
        },
        "Common-Utilities Fatal Error:\n\tThis would be the error message.\n");
}

GTEST_TEST(testExceptionHandling, derivedExceptionClassIsCaughtByParentClass)
{
    testing::internal::CaptureStderr();

    try
    {
        ErrorMessage error {};
        error.programName = "Common-Utilities";
        error.message     = "Let's throw a non-fatal warning.";

        throw FatalException(error);
    }
    catch (const std::exception& except)
    {
        std::cerr << except.what() << std::endl;
    }

    std::string actualOutput = testing::internal::GetCapturedStderr();

    ASSERT_EQ(actualOutput, "Let's throw a non-fatal warning.\n");
}

#endif
