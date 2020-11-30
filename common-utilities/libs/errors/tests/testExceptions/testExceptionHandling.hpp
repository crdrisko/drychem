// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testExceptionHandling.hpp
// Author: crdrisko
// Date: 08/27/2020-12:07:48
// Description: Provides ~100% unit test coverage over all exception handing functions

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_ERRORS_TESTS_TESTEXCEPTIONS_TESTEXCEPTIONHANDLING_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_ERRORS_TESTS_TESTEXCEPTIONS_TESTEXCEPTIONHANDLING_HPP

#include <exception>
#include <iostream>
#include <string>
#include <sstream>

#include <common-utils/errors.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testExceptionHandling, thisIsHowWeWouldCatchAndHandleAStdException)
{
    std::stringstream deathRegex;
    
    deathRegex << "YourProgramName Fatal Error:\n\tAn exception was thrown from " << std::exception().what();

    ASSERT_DEATH(
        {
            try
            {
                try
                {
                    throw std::exception();
                }
                catch (const std::exception& except)
                {
                    // Toss the exception back up for program termination and a more verbose message
                    DryChem::ErrorMessage error1;
                    error1.programName = "YourProgramName";
                    error1.message     = "An exception was thrown from " + std::string {except.what()};

                    throw DryChem::FatalException(error1);
                }
            }
            catch (const DryChem::FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        deathRegex.str());
}

GTEST_TEST(testExceptionHandling, thisIsHowWeWouldCatchAndHandleAFatalException)
{
    std::stringstream deathRegex;

    deathRegex << "YourProgramName Fatal Error:\n\tAn exception was thrown from ";

#if GTEST_USES_POSIX_RE
    deathRegex << "[(]testExceptionHandling.hpp: *[0-9]*[)]";
#elif GTEST_USES_SIMPLE_RE
    deathRegex << "\\(testExceptionHandling.hpp: \\d*\\)";
#endif

     deathRegex << "\n\tLocation message.\n";

    ASSERT_DEATH(
        {
            try
            {
                try
                {
                    throw DryChem::FatalException(
                        DryChem::ErrorMessage {"Common-Utilities", "Location message.", __FILE__, __LINE__});
                }
                catch (const std::exception& except)
                {
                    // Toss the exception back up for program termination and a more verbose message
                    DryChem::ErrorMessage error1;
                    error1.programName = "YourProgramName";
                    error1.message     = "An exception was thrown from " + std::string {except.what()};

                    throw DryChem::FatalException(error1);
                }
            }
            catch (const DryChem::FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        deathRegex.str());
}

GTEST_TEST(testExceptionHandling, fatalErrorsAreHandledByTerminating)
{
    std::stringstream deathRegex;

    deathRegex << "Common-Utilities Fatal Error: ";

#if GTEST_USES_POSIX_RE
    deathRegex << "[(]testExceptionHandling.hpp: *[0-9]*[)]";
#elif GTEST_USES_SIMPLE_RE
    deathRegex << "\\(testExceptionHandling.hpp: \\d*\\)";
#endif

     deathRegex << "\n\tThis would be the error message.\n";

    ASSERT_DEATH(
        {
            DryChem::ErrorMessage error;
            error.programName = "Common-Utilities";
            error.message     = "This would be the error message.";
            error.fileName    = __FILE__;
            error.lineNumber  = __LINE__;

            DryChem::FatalException exceptFatal {error};
            exceptFatal.handleErrorWithMessage();
        },
        deathRegex.str());
}

GTEST_TEST(testExceptionHandling, derivedExceptionClassIsCaughtByParentClass)
{
    testing::internal::CaptureStderr();

    try
    {
        DryChem::ErrorMessage error {};
        error.programName = "Common-Utilities";
        error.message     = "Let's throw a non-fatal warning.";
        error.fileName    = __FILE__;
        error.lineNumber  = __LINE__;

        throw DryChem::FatalException(error);
    }
    catch (const std::exception& except)
    {
        std::cerr << except.what() << std::endl;
    }

    std::string actualOutput = testing::internal::GetCapturedStderr();
    ASSERT_EQ(actualOutput, "(testExceptionHandling.hpp: 131)\n\tLet's throw a non-fatal warning.\n");
}

#endif
