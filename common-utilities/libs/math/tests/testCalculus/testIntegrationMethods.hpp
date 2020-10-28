// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testIntegrationMethods.hpp
// Author: crdrisko
// Date: 10/28/2020-07:58:30
// Description: Provides ~100% unit test coverage over the approximate integration methods

#ifndef COMMON_UTILITIES_TESTING_TESTINTEGRATIONMETHODS_HPP
#define COMMON_UTILITIES_TESTING_TESTINTEGRATIONMETHODS_HPP

#include <cstddef>
#include <vector>

#include <gtest/gtest.h>

#include "math.hpp"

using namespace CppUtils::Math;

GTEST_TEST(testIntegrationMethods, theTrapzMethodCanBeUsedInCompileTimeCalculations)
{
    const int x1 {0}, x2 {15}, y1 {0}, y2 {6};

    GTEST_COMPILE_ASSERT_(45 == trapz(x1, x2, y1, y2), "Trapz method failed.");
}

GTEST_TEST(testIntegrationMethods, theTrapzMethodCanAcceptMultipleTypes)
{
    long double x1 {0.1}, x2 {22.5}, y1 {2.3}, y2 {6.0};

    ASSERT_DOUBLE_EQ(92.96, trapz(x1, x2, y1, y2));
}

GTEST_TEST(testIntegrationMethods, theCumulativeTrapzMethodHasAnOptionalParameterWhichCanBeOverriden)
{
    std::vector<long double> x, y, expectedResult;

    for (std::size_t i {}; i <= 10; ++i)
    {
        x.push_back(i);
        y.push_back(i);

        expectedResult.push_back((x[i] * x[i]) / 2);
    }

    // ∫x = 1/2 x^2
    auto integrationResult1 = cumulativeTrapzIntegration(x.begin(), x.end(), y.begin(), y.end());
    auto integrationResult2 = cumulativeTrapzIntegration(x.begin(), x.end(), y.begin(), y.end(), 0);
    auto integrationResult3 = cumulativeTrapzIntegration(x.begin(), x.end(), y.begin(), y.end(), 5);

    for (std::size_t i {}; i < expectedResult.size(); ++i)
    {
        ASSERT_EQ(expectedResult[i], integrationResult2[i]);

        if (i == 0)
            ASSERT_EQ(5, integrationResult3[i]);
        else
            ASSERT_EQ(expectedResult[i], integrationResult3[i]);

        if (i == expectedResult.size() - 1)
            break;
        else
            ASSERT_EQ(expectedResult[i + 1], integrationResult1[i]);
    }
}

GTEST_TEST(testIntegrationMethods, passingTwoDifferentlySizedContainersResultsInFatalException)
{
    std::vector<long double> x {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::vector<long double> y {2.0, 5.0, 3.0, 7.0, 8.0, 9.0, 12.0, 10.0, 15.0, 20.0};

    ASSERT_DEATH(
        {
            try
            {
                cumulativeTrapzIntegration(x.begin(), x.end(), y.begin(), y.end() - 2);
            }
            catch (const InputSizeMismatch& except)
            {
                except.handleErrorWithMessage();
            }
        },
        "Common-Utilities Fatal Error:\n\tInput sizes for x and y containers must be the same.\n");
}

#endif
