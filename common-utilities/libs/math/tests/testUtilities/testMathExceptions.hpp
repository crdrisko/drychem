// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testMathExceptions.hpp
// Author: crdrisko
// Date: 10/27/2020-07:31:00
// Description: Provides ~100% unit test coverage over all exceptions specifically relating to the math library

#ifndef COMMON_UTILITIES_TESTING_TESTMATHEXCEPTIONS_HPP
#define COMMON_UTILITIES_TESTING_TESTMATHEXCEPTIONS_HPP

#include <gtest/gtest.h>

#include "errors.hpp"
#include "math.hpp"

using namespace CppUtils::Math;

GTEST_TEST(testMathExceptions, inputSizeMismatchIsAFatalExceptionAndCanTerminateWhenHandled)
{
    InputSizeMismatch exception1 {"Common-Utilities", __FILE__, __LINE__};

    ASSERT_DEATH(
        {
            try
            {
                throw exception1;
            }
            catch (const InputSizeMismatch& except)
            {
                except.handleErrorWithMessage();
            }
        },
        "Common-Utilities Fatal Error: [(]testMathExceptions.hpp: 21[)]\n\tInput sizes for x and y containers must be the same.\n");
}

GTEST_TEST(testMathExceptions, derivedExceptionsCanBeCaughtByBaseFatalException)
{
    ASSERT_DEATH(
        {
            try
            {
                throw InputSizeMismatch("Common-Utilities", __FILE__, __LINE__);
            }
            catch (const CppUtils::Errors::FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        "Common-Utilities Fatal Error: [(]testMathExceptions.hpp: 43[)]\n\tInput sizes for x and y containers must be the same.\n");
}

#endif
