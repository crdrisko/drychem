// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testStatisticalFunctions.hpp
// Author: crdrisko
// Date: 10/23/2020-15:54:44
// Description: Provides ~100% unit test coverage over all statistics-based mathematical functions

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_MATH_TESTS_TESTSTATISTICS_TESTSTATISTICALFUNCTIONS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_MATH_TESTS_TESTSTATISTICS_TESTSTATISTICALFUNCTIONS_HPP

#include <array>
#include <cmath>
#include <vector>

#include <common-utils/math.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testStatisticalFunctions, orderOfMagnitudeIsCalculatedCorrectly)
{
    ASSERT_EQ(-15, DryChem::findOrderOfMagnitude(1e-15));
    ASSERT_EQ(0, DryChem::findOrderOfMagnitude(6.8));
    ASSERT_EQ(1, DryChem::findOrderOfMagnitude(50));
    ASSERT_EQ(2, DryChem::findOrderOfMagnitude(457));
    ASSERT_EQ(3, DryChem::findOrderOfMagnitude(1000));
    ASSERT_EQ(18, DryChem::findOrderOfMagnitude(1.7e18));
}

GTEST_TEST(testStatisticalFunctions, weCanEasilyApproximatePiToACetainDegreeOfAccurracy)
{
    ASSERT_NEAR(3.14159265, (355.0 / 113.0), DryChem::findAbsoluteError(3.14159265, 7));
}

GTEST_TEST(testStatisticalFunctions, averageCalculationsWorkOnARangeOfValuesInAGivenContainer)
{
    std::vector<long double> x {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::array<long double, 10> y {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

    ASSERT_EQ(5.5, DryChem::calculateAverage(x.begin(), x.end()));
    ASSERT_EQ(3.0, DryChem::calculateAverage(y.begin(), y.end() - 5));
}

GTEST_TEST(testStatisticalFunctions, varianceCalculationsWorkOnARangeOfValuesInAGivenContainer)
{
    using namespace DryChem;

    std::vector<long double> x {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::array<long double, 10> y {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

    ASSERT_NEAR(3.027650, std::sqrt(calculateVariance(x.begin(), x.end())), findAbsoluteError(3.027650, 7));
    ASSERT_NEAR(2.449490, std::sqrt(calculateVariance(y.begin() + 2, y.end())), findAbsoluteError(2.449490, 7));
}

#endif
