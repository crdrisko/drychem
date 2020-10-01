// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testErrorTraits.hpp
// Author: crdrisko
// Date: 08/26/2020-14:36:00
// Description: Provides ~100% unit test coverage over all type traits associated with error and exception handling

#ifndef COMMON_UTILITIES_TESTING_TESTERRORTRAITS_HPP
#define COMMON_UTILITIES_TESTING_TESTERRORTRAITS_HPP

#include <gtest/gtest.h>

#include "errors.hpp"

using namespace CommonUtilities::Errors;

GTEST_TEST(testErrorTraits, isFatal_IsFalseWhenTemplateParameterIsWarning)
{
    ASSERT_FALSE( IsFatalT<ErrorSeverity::Warning>::value );
    ASSERT_FALSE( isFatal<ErrorSeverity::Warning> );
}

GTEST_TEST(testErrorTraits, isFatal_IsTrueWhenTemplateParameterIsFatal)
{
    ASSERT_TRUE( IsFatalT<ErrorSeverity::Fatal>::value );
    ASSERT_TRUE( isFatal<ErrorSeverity::Fatal> );
}

#endif
