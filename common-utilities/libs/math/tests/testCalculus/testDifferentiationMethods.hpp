// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testDifferentiationMethods.hpp
// Author: crdrisko
// Date: 10/28/2020-07:58:23
// Description: Provides ~100% unit test coverage over the approximate differentiation methods

#ifndef COMMON_UTILITIES_TESTING_TESTDIFFERENTIATIONMETHODS_HPP
#define COMMON_UTILITIES_TESTING_TESTDIFFERENTIATIONMETHODS_HPP

#include <cstddef>
#include <vector>

#include <gtest/gtest.h>

#include "math.hpp"

using namespace CppUtils::Math;

GTEST_TEST(testDifferentiationMethods, forwardDifferenceMethodReturnsAVectorWithASizeOneLessThanTheInputs)
{
    std::vector<long double> x, y, expectedResult;

    for (std::size_t i {}; i <= 10; ++i)
    {
        x.push_back(i);
        y.push_back(i);

        expectedResult.push_back((x[i] * x[i]) / 2);
    }

    // Actual: d/dx (x) = 1
    std::vector<long double> forwardFDM1(10, 1);
    auto forwardResult1 = forwardDifferenceMethod(x.begin(), x.end(), y.begin(), y.end());

    ASSERT_EQ(forwardFDM1, forwardResult1);

    // Actual: d/dx (1/2 x^2) = x
    std::vector<long double> forwardFDM2 {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5};
    auto forwardResult2 = forwardDifferenceMethod(x.begin(), x.end(), expectedResult.begin(), expectedResult.end());

    ASSERT_EQ(forwardFDM2, forwardResult2);
}

GTEST_TEST(testDifferentiationMethods, backwardsDifferenceMethodReturnsAVectorWithASizeOneLessThanTheInputs)
{
    std::vector<long double> x, y, expectedResult;

    for (std::size_t i {}; i <= 10; ++i)
    {
        x.push_back(i);
        y.push_back(i);

        expectedResult.push_back((x[i] * x[i]) / 2);
    }

    // Actual: d/dx (x) = 1
    std::vector<long double> backwardsFDM1(10, 1);
    auto backwardsResult1 = backwardsDifferenceMethod(x.begin(), x.end(), y.begin(), y.end());

    ASSERT_EQ(backwardsFDM1, backwardsResult1);

    // Actual: d/dx (1/2 x^2) = x
    std::vector<long double> backwardsFDM2 {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5};
    auto backwardsResult2 = backwardsDifferenceMethod(x.begin(), x.end(), expectedResult.begin(), expectedResult.end());

    ASSERT_EQ(backwardsFDM2, backwardsResult2);
}

GTEST_TEST(testDifferentiationMethods, defaultCenteredDifferenceMethodReturnsAVectorWithASizeEqualToThatOfTheInputs)
{
    std::vector<long double> x, y, expectedResult;

    for (std::size_t i {}; i <= 10; ++i)
    {
        x.push_back(i);
        y.push_back(i);
        expectedResult.push_back((x[i] * x[i]) / 2);
    }

    // Actual: d/dx (x) = 1
    std::vector<long double> centeredFDM1(11, 1);
    auto centeredResult1 = centeredDifferenceMethod(x.begin(), x.end(), y.begin(), y.end());

    ASSERT_EQ(centeredFDM1, centeredResult1);

    // Actual: d/dx (1/2 x^2) = x
    std::vector<long double> centeredFDM2 {0.5, 1, 2, 3, 4, 5, 6, 7, 8, 9, 9.5};
    auto centeredResult2 = centeredDifferenceMethod(x.begin(), x.end(), expectedResult.begin(), expectedResult.end());

    ASSERT_EQ(centeredFDM2, centeredResult2);
}

GTEST_TEST(testDifferentiationMethods, nonDefaultCenteredDifferenceMethodReturnsAVectorWithASizeTwoLessThanTheInputs)
{
    std::vector<long double> x, y, expectedResult;

    for (std::size_t i {}; i <= 10; ++i)
    {
        x.push_back(i);
        y.push_back(i);
        expectedResult.push_back((x[i] * x[i]) / 2);
    }

    // Actual: d/dx (x) = 1
    std::vector<long double> centeredFDM1(9, 1);
    auto centeredResult1 = centeredDifferenceMethod(x.begin(), x.end(), y.begin(), y.end(), false);

    ASSERT_EQ(centeredFDM1, centeredResult1);

    // Actual: d/dx (1/2 x^2) = x
    std::vector<long double> centeredFDM2 {1, 2, 3, 4, 5, 6, 7, 8, 9};
    auto centeredResult2 = centeredDifferenceMethod(x.begin(), x.end(), expectedResult.begin(), expectedResult.end(), false);

    ASSERT_EQ(centeredFDM2, centeredResult2);
}

GTEST_TEST(testDifferentiationMethods, passingTwoDifferentlySizedContainersResultsInFatalException)
{
    std::vector<long double> x {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::vector<long double> y {2.0, 5.0, 3.0, 7.0, 8.0, 9.0, 12.0, 10.0, 15.0, 20.0};

    ASSERT_DEATH(
        {
            try
            {
                forwardDifferenceMethod(x.begin(), x.end(), y.begin(), y.end() - 2);
            }
            catch (const InputSizeMismatch& except)
            {
                except.handleErrorWithMessage();
            }
        },
        "Common-Utilities Fatal Error: [(]differentiation.hpp: *[0-9]*[)]\n\tInput sizes for x and y containers must be the same.\n");

    ASSERT_DEATH(
        {
            try
            {
                backwardsDifferenceMethod(x.begin(), x.end(), y.begin(), y.end() - 2);
            }
            catch (const InputSizeMismatch& except)
            {
                except.handleErrorWithMessage();
            }
        },
        "Common-Utilities Fatal Error: [(]differentiation.hpp: *[0-9]*[)]\n\tInput sizes for x and y containers must be the same.\n");

    ASSERT_DEATH(
        {
            try
            {
                centeredDifferenceMethod(x.begin(), x.end(), y.begin(), y.end() - 2);
            }
            catch (const InputSizeMismatch& except)
            {
                except.handleErrorWithMessage();
            }
        },
        "Common-Utilities Fatal Error: [(]differentiation.hpp: *[0-9]*[)]\n\tInput sizes for x and y containers must be the same.\n");
}

#endif
