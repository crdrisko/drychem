// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testCommonExceptionTypes.hpp - Version 2.0.0
// Author: crdrisko
// Date: 08/27/2020-12:15:18
// Description: Provides ~100% unit test coverage over all specialty exception handling classes

#ifndef TESTCOMMONEXCEPTIONTYPES_HPP
#define TESTCOMMONEXCEPTIONTYPES_HPP

#include <gtest/gtest.h>

#include "../../../include/common-utils/errors.hpp"

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
    }, "Common-Utilities Fatal Error:\n\tUnable to open file: test.cpp.\n");
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
    }, "Common-Utilities Fatal Error:\n\tThe user-supplied input is invalid.\n");
}

GTEST_TEST(testErrorFunctions, invalidInputExceptionPrintsNonDefaultMessage)
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
    }, "Common-Utilities Fatal Error:\n\tLet's throw a fatal error.\n");
}

#endif
