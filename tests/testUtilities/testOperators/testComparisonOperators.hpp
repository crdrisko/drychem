// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testComparisonOperators.hpp
// Author: crdrisko
// Date: 09/18/2020-09:01:46
// Description: Provides ~100% unit test coverage over all comparison operators

#ifndef DRYCHEM_TESTS_TESTUTILITIES_TESTOPERATORS_TESTCOMPARISONOPERATORS_HPP
#define DRYCHEM_TESTS_TESTUTILITIES_TESTOPERATORS_TESTCOMPARISONOPERATORS_HPP

#include <drychem/drychem.hpp>
#include <gtest/gtest.h>

#include "../details/operatorDetails.hpp"

GTEST_TEST(testComparisonOperators, aClassThatInheritsFromEqualityComparableCanOnlyCallEqualityComparisons)
{
    using DryChem::details::testing::SomewhatComparable1;

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
    using DryChem::details::testing::SomewhatComparable2;

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
    using DryChem::details::testing::Comparable;

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
