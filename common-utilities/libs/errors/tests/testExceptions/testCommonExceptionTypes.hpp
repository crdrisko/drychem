// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testCommonExceptionTypes.hpp
// Author: crdrisko
// Date: 08/27/2020-12:15:18
// Description: Provides ~100% unit test coverage over all specialty exception handling classes

#ifndef COMMON_UTILITIES_TESTING_TESTCOMMONEXCEPTIONTYPES_HPP
#define COMMON_UTILITIES_TESTING_TESTCOMMONEXCEPTIONTYPES_HPP

#include <gtest/gtest.h>

#include "errors.hpp"

using namespace CommonUtilities::Errors;

GTEST_TEST(testCommonExceptionTypes, fileNotFoundExceptionResultsInProgramTermination)
{
    ASSERT_DEATH(
        {
            try
            {
                throw FileNotFoundException("Common-Utilities", "test.cpp");
            }
            catch (const FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        "Common-Utilities Fatal Error:\n\tUnable to open file: test.cpp.\n");
}

GTEST_TEST(testCommonExceptionTypes, invalidInputExceptionResultsInProgramTermination)
{
    ASSERT_DEATH(
        {
            try
            {
                throw InvalidInputException("Common-Utilities");
            }
            catch (const FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        "Common-Utilities Fatal Error:\n\tThe user-supplied input is invalid.\n");
}

GTEST_TEST(testCommonExceptionTypes, invalidInputExceptionPrintsNonDefaultMessage)
{
    ASSERT_DEATH(
        {
            try
            {
                throw InvalidInputException("Common-Utilities", "Let's throw a fatal error.");
            }
            catch (const FatalException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        "Common-Utilities Fatal Error:\n\tLet's throw a fatal error.\n");
}

GTEST_TEST(testCommonExceptionTypes, catchSpecializedExceptionsWithSpecializations)
{
    InvalidInputException exception1 {"Common-Utilities", "Let's throw a fatal error."};
    FileNotFoundException exception2 {"Common-Utilities", "test.cpp"};

    ASSERT_DEATH(
        {
            try
            {
                throw exception1;
            }
            catch (const InvalidInputException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        "Common-Utilities Fatal Error:\n\tLet's throw a fatal error.\n");

    ASSERT_DEATH(
        {
            try
            {
                throw exception2;
            }
            catch (const FileNotFoundException& except)
            {
                except.handleErrorWithMessage();
            }
        },
        "Common-Utilities Fatal Error:\n\tUnable to open file: test.cpp.\n");
}

#endif
