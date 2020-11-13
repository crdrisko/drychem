// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testErrorTraits.hpp
// Author: crdrisko
// Date: 08/26/2020-14:36:00
// Description: Provides ~100% unit test coverage over all type traits associated with error and exception handling

#ifndef DRYCHEM_COMMON_UTILITIES_TESTING_TESTERRORTRAITS_HPP
#define DRYCHEM_COMMON_UTILITIES_TESTING_TESTERRORTRAITS_HPP

#include <gtest/gtest.h>

#include "common-utils/errors.hpp"

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
