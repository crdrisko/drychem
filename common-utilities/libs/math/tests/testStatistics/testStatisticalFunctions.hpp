// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testStatisticalFunctions.hpp
// Author: crdrisko
// Date: 10/23/2020-15:54:44
// Description: Provides ~100% unit test coverage over all statistics-based mathematical functions

#ifndef COMMON_UTILITIES_TESTING_TESTSTATISTICALFUNCTIONS_HPP
#define COMMON_UTILITIES_TESTING_TESTSTATISTICALFUNCTIONS_HPP

#include <array>
#include <vector>

#include <gtest/gtest.h>

#include "math.hpp"

using namespace CppUtils::Math;

//! \test Testing the \c findOrderOfMagnitude() function
GTEST_TEST(testStatisticalFunctions, orderOfMagnitudeIsCalculatedCorrectly)
{
    ASSERT_EQ(-15, findOrderOfMagnitude(1e-15));
    ASSERT_EQ(0, findOrderOfMagnitude(6.8));
    ASSERT_EQ(1, findOrderOfMagnitude(50));
    ASSERT_EQ(2, findOrderOfMagnitude(457));
    ASSERT_EQ(3, findOrderOfMagnitude(1000));
    ASSERT_EQ(18, findOrderOfMagnitude(1.7e18));
}

//! \test Testing the \c findAbsoluteError() function
GTEST_TEST(testStatisticalFunctions, weCanEasilyApproximatePiToACetainDegreeOfAccurracy)
{
    ASSERT_NEAR(3.14159265, (355.0 / 113.0), findAbsoluteError(3.14159265, 7));
}

//! \test Testing the \c calculateAverage() function
GTEST_TEST(testStatisticalFunctions, averageCalculationsWorkOnARangeOfValuesInAGivenContainer)
{
    std::vector<long double> x {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::array<long double, 10> y {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

    ASSERT_EQ(5.5, calculateAverage(x.begin(), x.end()));
    ASSERT_EQ(3.0, calculateAverage(y.begin(), y.end() - 5));
}

//! \test Testing the \c calculateVariance() function
GTEST_TEST(testStatisticalFunctions, varianceCalculationsWorkOnARangeOfValuesInAGivenContainer)
{
    std::vector<long double> x {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::array<long double, 10> y {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

    ASSERT_NEAR(3.027650, std::sqrt(calculateVariance(x.begin(), x.end())), findAbsoluteError(3.027650, 7));
    ASSERT_NEAR(2.449490, std::sqrt(calculateVariance(y.begin() + 2, y.end())), findAbsoluteError(2.449490, 7));
}

// GTEST_TEST(testStatisticalFunctions, certainStatisticalFunctionsOnlyWorkWithArithmeticTypes)
// {
//     struct NonArithmetic
//     {
//     } nonArithmeticType;

//     ASSERT_FALSE(findOrderOfMagnitude(nonArithmeticType));                      // no instance of function template matches the argument list
//     ASSERT_FALSE(findAbsoluteError(nonArithmeticType, 7));                      // no instance of function template matches the argument list
// }

// GTEST_TEST(testStatisticalFunctions, certainStatisticalFunctionsOnlyWorkWithTypesThatHaveDefaultConstructors)
// {
//     struct NoDefaultConstructor
//     {
//         NoDefaultConstructor() = delete;
//     };

//     std::vector<NoDefaultConstructor> x;

//     ASSERT_FALSE(calculateAverage(x.begin(), x.end()));                         // no instance of function template matches the argument list
//     ASSERT_FALSE(calculateStandardDeviation(x.begin(), x.end()));               // no instance of function template matches the argument list
// }

#endif
