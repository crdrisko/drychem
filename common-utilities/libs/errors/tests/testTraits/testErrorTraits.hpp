// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testErrorTraits.hpp
// Author: crdrisko
// Date: 08/26/2020-14:36:00
// Description: Provides ~100% unit test coverage over all type traits associated with error and exception handling

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_ERRORS_TESTS_TESTTRAITS_TESTERRORTRAITS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_ERRORS_TESTS_TESTTRAITS_TESTERRORTRAITS_HPP

#include <common-utils/errors.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testErrorTraits, isFatalIsFalseWhenTemplateParameterIsWarning)
{
    ASSERT_FALSE(DryChem::is_fatal<DryChem::ErrorSeverity::Warning>::value);
    ASSERT_FALSE(DryChem::is_fatal_v<DryChem::ErrorSeverity::Warning>);
}

GTEST_TEST(testErrorTraits, isFatalIsTrueWhenTemplateParameterIsFatal)
{
    ASSERT_TRUE(DryChem::is_fatal<DryChem::ErrorSeverity::Fatal>::value);
    ASSERT_TRUE(DryChem::is_fatal_v<DryChem::ErrorSeverity::Fatal>);
}

#endif
