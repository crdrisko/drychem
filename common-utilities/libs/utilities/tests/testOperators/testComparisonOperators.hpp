// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testComparisonOperators.hpp
// Author: crdrisko
// Date: 09/18/2020-09:01:46
// Description: Provides ~100% unit test coverage over all comparison operators

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_UTILITIES_TESTS_TESTOPERATORS_TESTCOMPARISONOPERATORS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_UTILITIES_TESTS_TESTOPERATORS_TESTCOMPARISONOPERATORS_HPP

#include <common-utils/utilities.hpp>
#include <gtest/gtest.h>

#include "../details/operatorDetails.hpp"

GTEST_TEST(testComparisonOperators, aClassThatInheritsFromEqualityComparableCanOnlyCallEqualityComparisons)
{
    using CppUtils::Operators::details::testing::SomewhatComparable1;

    SomewhatComparable1 value1 {5};
    SomewhatComparable1 value2 {5};
    SomewhatComparable1 value3 {10};

    ASSERT_TRUE(value1 == value2);
    ASSERT_FALSE(value1 == value3);

    ASSERT_TRUE(value1 != value3);
    ASSERT_FALSE(value1 != value2);

    // ASSERT_TRUE(value1 < value3);                        // Error: no operator "<" matches these operands
}

GTEST_TEST(testComparisonOperators, aClassThatInheritsFromLessThanComparableCanOnlyCallInequalityComparisons)
{
    using CppUtils::Operators::details::testing::SomewhatComparable2;

    SomewhatComparable2 value1 {5};
    SomewhatComparable2 value2 {5};
    SomewhatComparable2 value3 {10};

    ASSERT_TRUE(value1 < value3);
    ASSERT_FALSE(value1 < value2);

    ASSERT_TRUE(value3 > value2);
    ASSERT_FALSE(value1 > value2);

    ASSERT_TRUE(value1 <= value2);
    ASSERT_FALSE(value3 <= value2);

    ASSERT_TRUE(value3 >= value2);
    ASSERT_FALSE(value1 >= value3);

    // ASSERT_TRUE(value1 == value2);                       // Error: no operator "==" matches these operands
}

GTEST_TEST(testComparisonOperators, aClassThatInheritsFromCompletelyComparableCanCallAllComparisons)
{
    using CppUtils::Operators::details::testing::Comparable;

    Comparable value1 {5};
    Comparable value2 {5};
    Comparable value3 {10};

    ASSERT_TRUE(value1 == value2);
    ASSERT_FALSE(value1 == value3);

    ASSERT_TRUE(value1 != value3);
    ASSERT_FALSE(value1 != value2);

    ASSERT_TRUE(value1 < value3);
    ASSERT_FALSE(value1 < value2);

    ASSERT_TRUE(value3 > value2);
    ASSERT_FALSE(value1 > value2);

    ASSERT_TRUE(value1 <= value2);
    ASSERT_FALSE(value3 <= value2);

    ASSERT_TRUE(value3 >= value2);
    ASSERT_FALSE(value1 >= value3);
}

#endif
