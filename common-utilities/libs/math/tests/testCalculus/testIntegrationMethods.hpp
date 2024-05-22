// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testIntegrationMethods.hpp
// Author: crdrisko
// Date: 10/28/2020-07:58:30
// Description: Provides ~100% unit test coverage over the approximate integration methods

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_MATH_TESTS_TESTCALCULUS_TESTINTEGRATIONMETHODS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_MATH_TESTS_TESTCALCULUS_TESTINTEGRATIONMETHODS_HPP

#include <cstddef>
#include <sstream>
#include <vector>

#include <common-utils/math.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testIntegrationMethods, theTrapzMethodCanBeUsedInCompileTimeCalculations)
{
    const int x1 {0}, x2 {15}, y1 {0}, y2 {6};

    static_assert(45 == DryChem::trapz(x1, x2, y1, y2), "Trapz method failed.");
}

GTEST_TEST(testIntegrationMethods, theTrapzMethodCanAcceptMultipleTypes)
{
    long double x1 {0.1}, x2 {22.5}, y1 {2.3}, y2 {6.0};

    ASSERT_DOUBLE_EQ(92.96, DryChem::trapz(x1, x2, y1, y2));
}

GTEST_TEST(testIntegrationMethods, theCumulativeTrapzMethodHasAnOptionalParameterWhichCanBeOverriden)
{
    std::vector<long double> x, y, expectedResult;

    for (std::size_t i {}; i <= 10; ++i)
    {
        x.push_back(static_cast<long double>(i));
        y.push_back(static_cast<long double>(i));

        expectedResult.push_back((x[i] * x[i]) / 2.0);
    }

    // ∫x = 1/2 x^2
    auto integrationResult1 = DryChem::cumulativeTrapzIntegration(x.begin(), x.end(), y.begin(), y.end());
    auto integrationResult2 = DryChem::cumulativeTrapzIntegration(x.begin(), x.end(), y.begin(), y.end(), 0.0);
    auto integrationResult3 = DryChem::cumulativeTrapzIntegration(x.begin(), x.end(), y.begin(), y.end(), 5.0);

    for (std::size_t i {}; i < expectedResult.size(); ++i)
    {
        ASSERT_EQ(expectedResult[i], integrationResult2[i]);

        if (i == 0)
            ASSERT_EQ(5.0, integrationResult3[i]);
        else
            ASSERT_EQ(expectedResult[i], integrationResult3[i]);

        if (i == expectedResult.size() - 1)
            break;
        else
            ASSERT_EQ(expectedResult[i + 1], integrationResult1[i]);
    }
}

GTEST_TEST(testIntegrationMethods, insteadOfUsingIteratorsWeCanJustPassFullContainers)
{
    std::vector<long double> x, y, expectedResult;

    for (std::size_t i {}; i <= 10; ++i)
    {
        x.push_back(static_cast<long double>(i));
        y.push_back(static_cast<long double>(i));

        expectedResult.push_back((x[i] * x[i]) / 2.0);
    }

    // ∫x = 1/2 x^2
    auto integrationResult = DryChem::cumulativeTrapzIntegration(x, y, 0.0);

    ASSERT_EQ(expectedResult, integrationResult);
}

GTEST_TEST(testIntegrationMethods, passingTwoDifferentlySizedContainersResultsInFatalException)
{
    std::stringstream deathRegex;

    deathRegex << "Common-Utilities Fatal Error: ";

#if GTEST_USES_POSIX_RE
    deathRegex << "[(]integration.hpp: *[0-9]*[)]\n\t";
#elif GTEST_USES_SIMPLE_RE
    deathRegex << "\\(integration.hpp: \\d*\\)\n\t";
#endif

    deathRegex << "Input sizes for x and y containers must be the same.\n";

    std::vector<long double> x {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::vector<long double> y {2.0, 5.0, 3.0, 7.0, 8.0, 9.0, 12.0, 10.0, 15.0, 20.0};

    ASSERT_DEATH(
        {
            try
            {
                DryChem::cumulativeTrapzIntegration(x.begin(), x.end(), y.begin(), y.end() - 2);
            }
            catch (const DryChem::InputSizeMismatch& except)
            {
                except.handleErrorWithMessage();
            }
        },
        deathRegex.str());
}

#endif
