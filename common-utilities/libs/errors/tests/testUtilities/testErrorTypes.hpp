// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testErrorTypes.hpp
// Author: crdrisko
// Date: 08/26/2020-15:02:42
// Description: Provides ~100% unit test coverage over all error types and associated functions

#ifndef COMMON_UTILITIES_TESTING_TESTERRORTYPES_HPP
#define COMMON_UTILITIES_TESTING_TESTERRORTYPES_HPP

#include <gtest/gtest.h>

#include "errors.hpp"

using namespace CppUtils::Errors;

//! \test Testing the \c CppUtils::Errors::ErrorSeverity scoped enumeration
GTEST_TEST(testErrorTypes, errorSeveritiesConvertToCorrectValues)
{
    ASSERT_FALSE(static_cast<bool>(ErrorSeverity::Warning));
    ASSERT_TRUE(static_cast<bool>(ErrorSeverity::Fatal));

    ASSERT_TRUE(static_cast<int>(ErrorSeverity::Warning) == 0);
    ASSERT_TRUE(static_cast<int>(ErrorSeverity::Fatal) == 1);
}

//! \test Testing the \c CppUtils::Errors::ErrorMessage structure
GTEST_TEST(testErrorTypes, errorMessagesCanBeSetByIndividualValues)
{
    ErrorMessage err {};

    ASSERT_TRUE(err.programName.empty() && err.message.empty() && err.fileName.empty() && err.lineNumber == 0ul);

    err.programName = "Common-Utilities";
    err.message     = "This is the error message.";
    err.fileName    = __FILE__;
    err.lineNumber  = __LINE__;

    ASSERT_EQ("Common-Utilities", err.programName);
    ASSERT_EQ("This is the error message.", err.message);
    ASSERT_EQ("testErrorTypes.hpp", err.fileName.substr(err.fileName.find_last_of('/') + 1, err.fileName.length()));
    ASSERT_EQ(36ul, err.lineNumber);
}

//! \test Testing the \c CppUtils::Errors::ErrorMessage structure
GTEST_TEST(testErrorTypes, errorMessagesCanBeSetByConstructor)
{
    ErrorMessage err {"Common-Utilities", "This is the error message.", __FILE__, __LINE__};

    ASSERT_EQ("Common-Utilities", err.programName);
    ASSERT_EQ("This is the error message.", err.message);
    ASSERT_EQ("testErrorTypes.hpp", err.fileName.substr(err.fileName.find_last_of('/') + 1, err.fileName.length()));
    ASSERT_EQ(46ul, err.lineNumber);
}

#endif
