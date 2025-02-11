// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testLinearLeastSquaresFitting.hpp
// Author: crdrisko
// Date: 10/26/2020-11:56:41
// Description: Provides ~100% unit test coverage over the linear least squares fitting function

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_MATH_TESTS_TESTSTATISTICS_TESTLINEARLEASTSQUARESFITTING_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_MATH_TESTS_TESTSTATISTICS_TESTLINEARLEASTSQUARESFITTING_HPP

#include <cmath>
#include <sstream>
#include <vector>

#include <common-utils/math.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testLinearLeastSquaresFitting, linearLeastSquaresFittingReturnsMultipleValuesInAStruct)
{
    std::vector<long double> x {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::vector<long double> y {2.0, 5.0, 3.0, 7.0, 8.0, 9.0, 12.0, 10.0, 15.0, 20.0};

    CppUtils::Math::details::LinearLeastSquaresResult<long double> result
        = DryChem::linearLeastSquaresFitting(x.begin(), x.end(), y.begin(), y.end());

    ASSERT_NEAR(1.7152, result.slope, DryChem::findAbsoluteError(1.7152, 5));
    ASSERT_NEAR(-0.33333, result.intercept, DryChem::findAbsoluteError(-0.33333, 5));
    ASSERT_NEAR(0.2139317, std::sqrt(result.variance), DryChem::findAbsoluteError(0.2139317, 7));
}

GTEST_TEST(testLinearLeastSquaresFitting, linearLeastSquaresFittingCanReturnATypeCompatibleWithStructuredBinding)
{
    std::vector<long double> x {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::vector<long double> y {2.0, 5.0, 3.0, 7.0, 8.0, 9.0, 12.0, 10.0, 15.0, 20.0};

    auto [slope, intercept, variance] = DryChem::linearLeastSquaresFitting(x.cbegin(), x.cend(), y.cbegin(), y.cend());

    ASSERT_NEAR(1.7152, slope, DryChem::findAbsoluteError(1.7152, 5));
    ASSERT_NEAR(-0.33333, intercept, DryChem::findAbsoluteError(-0.33333, 5));
    ASSERT_NEAR(0.2139317, std::sqrt(variance), DryChem::findAbsoluteError(0.2139317, 7));
}

GTEST_TEST(testLinearLeastSquaresFitting, passingTwoDifferentlySizedContainersResultsInFatalException)
{
    std::stringstream deathRegex;

    deathRegex << "Common-Utilities Fatal Error: ";

#if GTEST_USES_POSIX_RE
    deathRegex << "[(]linearLeastSquaresFitting.hpp: *[0-9]*[)]\n\t";
#elif GTEST_USES_SIMPLE_RE
    deathRegex << "\\(linearLeastSquaresFitting.hpp: \\d*\\)\n\t";
#endif

    deathRegex << "Input sizes for x and y containers must be the same.\n";

    std::vector<long double> x {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::vector<long double> y {2.0, 5.0, 3.0, 7.0, 8.0, 9.0, 12.0, 10.0, 15.0, 20.0};

    ASSERT_DEATH(
        {
            try
            {
                DryChem::linearLeastSquaresFitting(x.begin(), x.end(), y.begin(), y.end() - 2);
            }
            catch (const DryChem::InputSizeMismatch& except)
            {
                except.handleErrorWithMessage();
            }
        },
        deathRegex.str());
}

#endif
