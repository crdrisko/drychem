// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testMathExceptions.hpp
// Author: crdrisko
// Date: 10/27/2020-07:31:00
// Description: Provides ~100% unit test coverage over all exceptions specifically relating to the math library

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_MATH_TESTS_TESTUTILITIES_TESTMATHEXCEPTIONS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_MATH_TESTS_TESTUTILITIES_TESTMATHEXCEPTIONS_HPP

#include <sstream>

#include <common-utils/errors.hpp>
#include <common-utils/math.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testMathExceptions, inputSizeMismatchIsAFatalExceptionAndCanTerminateWhenHandled)
{
    std::stringstream deathRegex;

    deathRegex << "Common-Utilities Fatal Error: ";

#if GTEST_USES_POSIX_RE
    deathRegex << "[(]testMathExceptions.hpp: *[0-9]*[)]\n\t";
#elif GTEST_USES_SIMPLE_RE
    deathRegex << "\\(testMathExceptions.hpp: \\d*\\)\n\t";
#endif

    deathRegex << "Input sizes for x and y containers must be the same.\n";

    DryChem::InputSizeMismatch exception1 {"Common-Utilities", __FILE__, __LINE__};

    ASSERT_DEATH(
        {
            try
            {
                throw exception1;
            }
            catch (const DryChem::InputSizeMismatch& except)
            {
                except.handleErrorWithMessage();
            }
        },
        deathRegex.str());
}

GTEST_TEST(testMathExceptions, derivedExceptionsCanBeCaughtByBaseFatalException)
{
    std::stringstream deathRegex;

    deathRegex << "Common-Utilities Fatal Error: ";

#if GTEST_USES_POSIX_RE
    deathRegex << "[(]testMathExceptions.hpp: *[0-9]*[)]\n\t";
#elif GTEST_USES_SIMPLE_RE
    deathRegex << "\\(testMathExceptions.hpp: \\d*\\)\n\t";
#endif

    deathRegex << "Input sizes for x and y containers must be the same.\n";

    ASSERT_DEATH(
        {
            try
            {
                throw DryChem::InputSizeMismatch("Common-Utilities", __FILE__, __LINE__);
            }
            catch (const DryChem::FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        deathRegex.str());
}

#endif
