// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testErrorTypes.hpp - Version 2.0.0
// Author: crdrisko
// Date: 08/26/2020-15:02:42
// Description: Provides ~100% unit test coverage over all error types and associated functions

#ifndef TESTERRORTYPES_HPP
#define TESTERRORTYPES_HPP

#include <gtest/gtest.h>

#include "../../../include/common-utils/errors.hpp"

using namespace CommonUtilities::Errors;

GTEST_TEST(testErrorTypes, errorSeveritiesConvertToCorrectValues)
{
    ASSERT_FALSE( static_cast<bool>(ErrorSeverity::Warning) );
    ASSERT_TRUE( static_cast<bool>(ErrorSeverity::Fatal) );

    ASSERT_TRUE( static_cast<int>(ErrorSeverity::Warning) == 0 );
    ASSERT_TRUE( static_cast<int>(ErrorSeverity::Fatal) == 1 );
}

GTEST_TEST(testErrorTypes, errorMessagesCanBeSetByIndividualValues)
{
    ErrorMessage error {};

    ASSERT_TRUE(error.programName.empty() && error.message.empty());

    error.programName = "Common-Utilities";
    error.message = "This is the error message.";

    ASSERT_EQ("Common-Utilities", error.programName);
    ASSERT_EQ("This is the error message.", error.message);

}

GTEST_TEST(testErrorTypes, errorMessagesCanBeSetByConstructor)
{
    ErrorMessage error {"Common-Utilities", "This is the error message."};

    ASSERT_EQ("Common-Utilities", error.programName);
    ASSERT_EQ("This is the error message.", error.message);
}

#endif
