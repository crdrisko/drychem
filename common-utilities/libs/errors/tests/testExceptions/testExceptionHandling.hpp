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

//! \test Testing the \c CppUtils::Errors::FatalException class when a standard exception is thrown
GTEST_TEST(testExceptionHandling, thisIsHowWeWouldCatchAndHandleAStdException)
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
                    error1.message     = "An exception was thrown from " + std::string {except.what()};

                    throw FatalException(error1);
                }
            }
            catch (const FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        "YourProgramName Fatal Error:\n\tAn exception was thrown from std::bad_alloc\n");
}

//! \test Testing the \c CppUtils::Errors::FatalException class when a FatalException is thrown
GTEST_TEST(testExceptionHandling, thisIsHowWeWouldCatchAndHandleAFatalException)
{
    ASSERT_DEATH(
        {
            try
            {
                try
                {
                    throw FatalException(ErrorMessage {"Common-Utilities", "Location message.", __FILE__, __LINE__});
                }
                catch (const std::exception& except)
                {
                    // Toss the exception back up for program termination and a more verbose message
                    ErrorMessage error1;
                    error1.programName = "YourProgramName";
                    error1.message     = "An exception was thrown from " + std::string {except.what()};

                    throw FatalException(error1);
                }
            }
            catch (const FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        "YourProgramName Fatal Error:\n\tAn exception was thrown from [(]testExceptionHandling.hpp: *[0-9]*[)]\n\tLocation message.\n");
}

//! \test Testing the \c CppUtils::Errors::FatalException class
GTEST_TEST(testExceptionHandling, fatalErrorsAreHandledByTerminating)
{
    ASSERT_DEATH(
        {
            ErrorMessage error;
            error.programName = "Common-Utilities";
            error.message     = "This would be the error message.";
            error.fileName    = __FILE__;
            error.lineNumber  = __LINE__;

            FatalException exceptFatal {error};
            exceptFatal.handleErrorWithMessage();
        },
        "Common-Utilities Fatal Error: [(]testExceptionHandling.hpp: *[0-9]*[)]\n\tThis would be the error message.\n");
}

//! \test Testing the \c CppUtils::Errors::FatalException class
GTEST_TEST(testExceptionHandling, derivedExceptionClassIsCaughtByParentClass)
{
    testing::internal::CaptureStderr();

    try
    {
        ErrorMessage error {};
        error.programName = "Common-Utilities";
        error.message     = "Let's throw a non-fatal warning.";
        error.fileName    = __FILE__;
        error.lineNumber  = __LINE__;

        throw FatalException(error);
    }
    catch (const std::exception& except)
    {
        std::cerr << except.what() << std::endl;
    }

    std::string actualOutput = testing::internal::GetCapturedStderr();
    ASSERT_EQ(actualOutput, "(testExceptionHandling.hpp: 109)\n\tLet's throw a non-fatal warning.\n");
}

#endif
