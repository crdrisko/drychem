// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testComparisonOperators.hpp
// Author: crdrisko
// Date: 09/17/2020-09:42:58
// Description: Provides ~100% unit test coverage over all comparison functions and traits

#ifndef DRYCHEM_CPP_UNITS_LIBS_PHYSICALQUANTITIES_TESTS_TESTOPERATORS_TESTCOMPARISONOPERATORS_HPP
#define DRYCHEM_CPP_UNITS_LIBS_PHYSICALQUANTITIES_TESTS_TESTOPERATORS_TESTCOMPARISONOPERATORS_HPP

#include <type_traits>

#include <gtest/gtest.h>

#include "cpp-units/physicalQuantities.hpp"

using namespace CppUnits;
using namespace CppUnits::Literals;

GTEST_TEST(testComparisonOperators, overloadedComparsionOperatorsPerformComparisonsOnMagnitude)
{
    DimensionlessQuantity value1 = 1.0_;
    DimensionlessQuantity value2 = 2.0_;
    DimensionlessQuantity value3 = 1.0_;

    ASSERT_TRUE(value1 == value3);
    ASSERT_FALSE(value1 == value2);

    ASSERT_TRUE(value1 < value2);
    ASSERT_FALSE(value2 < value1);

    // Length value4 = 2.0_m;
    // ASSERT_TRUE(value2 == value4);                       // Error: no operator "==" matches these operands
    // ASSERT_TRUE(value1 < value4);                        // Error: no operator "<" matches these operands
}

GTEST_TEST(testComparisonOperators, physicalQuantitiesInheritAndImplementAllComparisonOperators)
{
    DimensionlessQuantity value1 = 1.0_;
    DimensionlessQuantity value2 = 2.0_;
    DimensionlessQuantity value3 = 5.0_;
    DimensionlessQuantity value4 = 1.0_;

    ASSERT_TRUE(value3 != value2);
    ASSERT_FALSE(value4 != value1);

    ASSERT_TRUE(value1 <= value2);
    ASSERT_FALSE(value2 <= value1);

    ASSERT_TRUE(value3 > value2);
    ASSERT_FALSE(value2 > value3);

    ASSERT_TRUE(value3 >= value2);
    ASSERT_FALSE(value2 >= value3);
}

GTEST_TEST(testComparisonOperators, physicalQuantitiesAreOnlyCompletelyComparableWithTheSameTypeOfPhysicalQuantity)
{
    ASSERT_TRUE((std::is_base_of_v<DryChem::CompletelyComparable<Length>, Length>));
    ASSERT_FALSE((std::is_base_of_v<DryChem::CompletelyComparable<Length>, DimensionlessQuantity>));
}

#endif
