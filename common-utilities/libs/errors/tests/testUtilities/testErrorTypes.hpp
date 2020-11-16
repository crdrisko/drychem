// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testErrorTypes.hpp
// Author: crdrisko
// Date: 08/26/2020-15:02:42
// Description: Provides ~100% unit test coverage over all error types and associated functions

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_ERRORS_TESTS_TESTUTILITIES_TESTERRORTYPES_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_ERRORS_TESTS_TESTUTILITIES_TESTERRORTYPES_HPP

#include <common-utils/errors.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testErrorTypes, errorSeveritiesConvertToCorrectValues)
{
    ASSERT_FALSE(static_cast<bool>(DryChem::ErrorSeverity::Warning));
    ASSERT_TRUE(static_cast<bool>(DryChem::ErrorSeverity::Fatal));

    ASSERT_TRUE(static_cast<int>(DryChem::ErrorSeverity::Warning) == 0);
    ASSERT_TRUE(static_cast<int>(DryChem::ErrorSeverity::Fatal) == 1);
}

GTEST_TEST(testErrorTypes, errorMessagesCanBeSetByIndividualValues)
{
    DryChem::ErrorMessage err {};

    ASSERT_TRUE(err.programName.empty() && err.message.empty() && err.fileName.empty() && err.lineNumber == 0ul);

    err.programName = "Common-Utilities";
    err.message     = "This is the error message.";
    err.fileName    = __FILE__;
    err.lineNumber  = __LINE__;

    ASSERT_EQ("Common-Utilities", err.programName);
    ASSERT_EQ("This is the error message.", err.message);
    ASSERT_EQ("testErrorTypes.hpp", err.fileName.substr(err.fileName.find_last_of('/') + 1, err.fileName.length()));
    ASSERT_EQ(33ul, err.lineNumber);
}

GTEST_TEST(testErrorTypes, errorMessagesCanBeSetByConstructor)
{
    DryChem::ErrorMessage err {"Common-Utilities", "This is the error message.", __FILE__, __LINE__};

    ASSERT_EQ("Common-Utilities", err.programName);
    ASSERT_EQ("This is the error message.", err.message);
    ASSERT_EQ("testErrorTypes.hpp", err.fileName.substr(err.fileName.find_last_of('/') + 1, err.fileName.length()));
    ASSERT_EQ(43ul, err.lineNumber);
}

#endif
