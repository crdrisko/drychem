// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testLinearLeastSquaresFitting.hpp
// Author: crdrisko
// Date: 10/26/2020-11:56:41
// Description: Provides ~100% unit test coverage over the linear least squares fitting function

#ifndef COMMON_UTILITIES_TESTING_TESTLINEARLEASTSQUARESFITTING_HPP
#define COMMON_UTILITIES_TESTING_TESTLINEARLEASTSQUARESFITTING_HPP

#include <vector>

#include <gtest/gtest.h>

#include "math.hpp"

using namespace CppUtils::Math;

//! \test Testing the \c linearLeastSquaresFitting<> function
GTEST_TEST(testLinearLeastSquaresFitting, linearLeastSquaresFittingReturnsMultipleValuesInAStruct)
{
    std::vector<long double> x {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::vector<long double> y {2.0, 5.0, 3.0, 7.0, 8.0, 9.0, 12.0, 10.0, 15.0, 20.0};

    LinearLeastSquaresResult<long double> result = linearLeastSquaresFitting(x.begin(), x.end(), y.begin(), y.end());

    ASSERT_NEAR(1.7152, result.slope, findAbsoluteError(1.7152, 5));
    ASSERT_NEAR(-0.33333, result.intercept, findAbsoluteError(-0.33333, 5));
    ASSERT_NEAR(0.2139317, std::sqrt(result.variance_slope), findAbsoluteError(0.2139317, 7));
}

//! \test Testing the \c linearLeastSquaresFitting<> function with structured binding
GTEST_TEST(testLinearLeastSquaresFitting, linearLeastSquaresFittingCanReturnATypeCompatibleWithStructuredBinding)
{
    std::vector<long double> x {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::vector<long double> y {2.0, 5.0, 3.0, 7.0, 8.0, 9.0, 12.0, 10.0, 15.0, 20.0};

    auto [slope, intercept, variance] = linearLeastSquaresFitting(x.cbegin(), x.cend(), y.cbegin(), y.cend());

    ASSERT_NEAR(1.7152, slope, findAbsoluteError(1.7152, 5));
    ASSERT_NEAR(-0.33333, intercept, findAbsoluteError(-0.33333, 5));
    ASSERT_NEAR(0.2139317, std::sqrt(variance), findAbsoluteError(0.2139317, 7));
}

//! \test Testing the \c linearLeastSquaresFitting<> function
GTEST_TEST(testLinearLeastSquaresFitting, passingTwoDifferentlySizedContainersResultsInFatalException)
{
    std::vector<long double> x {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    std::vector<long double> y {2.0, 5.0, 3.0, 7.0, 8.0, 9.0, 12.0, 10.0, 15.0, 20.0};

    ASSERT_DEATH(
        {
            try
            {
                linearLeastSquaresFitting(x.begin(), x.end(), y.begin(), y.end() - 2);
            }
            catch (const InputSizeMismatch& except)
            {
                except.handleErrorWithMessage();
            }
        },
        "Common-Utilities Fatal Error: [(]linearLeastSquaresFitting.hpp: 53[)]\n\tInput sizes for x and y containers must be the same.\n");
}

#endif
