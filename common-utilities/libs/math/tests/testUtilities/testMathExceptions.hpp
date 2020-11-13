// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testMathExceptions.hpp
// Author: crdrisko
// Date: 10/27/2020-07:31:00
// Description: Provides ~100% unit test coverage over all exceptions specifically relating to the math library

#ifndef DRYCHEM_COMMON_UTILITIES_TESTING_TESTMATHEXCEPTIONS_HPP
#define DRYCHEM_COMMON_UTILITIES_TESTING_TESTMATHEXCEPTIONS_HPP

#include <gtest/gtest.h>

#include "common-utils/errors.hpp"
#include "common-utils/math.hpp"

GTEST_TEST(testMathExceptions, inputSizeMismatchIsAFatalExceptionAndCanTerminateWhenHandled)
{
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
        "Common-Utilities Fatal Error: [(]testMathExceptions.hpp: *[0-9]*[)]\n\tInput sizes for x and y containers must be the same.\n");
}

GTEST_TEST(testMathExceptions, derivedExceptionsCanBeCaughtByBaseFatalException)
{
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
        "Common-Utilities Fatal Error: [(]testMathExceptions.hpp: *[0-9]*[)]\n\tInput sizes for x and y containers must be the same.\n");
}

#endif
