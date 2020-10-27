// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testBasicMathFunctions.hpp
// Author: crdrisko
// Date: 08/25/2020-20:34:50
// Description: Provides ~100% unit test coverage over all basic mathematical functions in the CppUnits library

#ifndef CPP_UNITS_TESTING_TESTBASICMATHFUNCTIONS_HPP
#define CPP_UNITS_TESTING_TESTBASICMATHFUNCTIONS_HPP

#include <array>
#include <cmath>
#include <vector>

#include <common-utils/math.hpp>
#include <gtest/gtest.h>

#include "physicalQuantities.hpp"

using namespace CppUnits;
using namespace CppUnits::Literals;

GTEST_TEST(testBasicMathFunctions, absoluteValueReturnsPositiveValueOfPhysicalQuantity)
{
    constexpr Length positiveLength = 1.0_m;
    constexpr Length negativeLength = -1.0_m;

    ASSERT_TRUE(Math::abs(positiveLength) == Math::abs(negativeLength));
    ASSERT_FALSE(Math::abs(negativeLength) == negativeLength);
}

GTEST_TEST(testBasicMathFunctions, exponentialFunctionOverloadsAreEquivalentToTheirCorrespondingCmathFunctions)
{
    constexpr Length length = 2.0_m;

    ASSERT_DOUBLE_EQ(std::exp(length.getMagnitude()), Math::exp(length).getMagnitude());
    ASSERT_DOUBLE_EQ(std::exp2(length.getMagnitude()), Math::exp2(length).getMagnitude());
    ASSERT_DOUBLE_EQ(std::log(length.getMagnitude()), Math::log(length).getMagnitude());
    ASSERT_DOUBLE_EQ(std::log2(length.getMagnitude()), Math::log2(length).getMagnitude());
    ASSERT_DOUBLE_EQ(std::log10(length.getMagnitude()), Math::log10(length).getMagnitude());
}

GTEST_TEST(testBasicMathFunctions, powerFunctionOverloadsAreEquivalentToTheirCorrespondingCmathFunctions)
{
    constexpr Length length1                = 5.0_m;
    constexpr WaveNumber waveNumber         = Math::pow<-1>(length1);
    constexpr DimensionlessQuantity dimless = Math::pow<0>(length1);

    ASSERT_DOUBLE_EQ(0.2, waveNumber.getMagnitude());
    ASSERT_DOUBLE_EQ(1.0, dimless.getMagnitude());

    ASSERT_DOUBLE_EQ(25.0, Math::pow<2>(length1).getMagnitude());
    ASSERT_TRUE(length1 * length1 == Math::pow<2>(length1));

    ASSERT_DOUBLE_EQ(125.0, Math::pow<3>(length1).getMagnitude());
    ASSERT_TRUE(length1 * length1 * length1 == Math::pow<3>(length1));

    constexpr Area area     = 64.0_m2;
    constexpr Volume volume = 64.0_m3;

    ASSERT_EQ(8.0_m, Math::sqrt(area));
    ASSERT_EQ(4.0_m, Math::cbrt(volume));
}

GTEST_TEST(testBasicMathFunctions, trigonometricFunctionOverloadsAreEquivalentToTheirCorrespondingCmathFunctions)
{
    constexpr Angle angle = 2.0_rad * Constants::pi;

    ASSERT_DOUBLE_EQ(std::sin(angle.getMagnitude()), Math::sin(angle).getMagnitude());
    ASSERT_DOUBLE_EQ(std::cos(angle.getMagnitude()), Math::cos(angle).getMagnitude());
    ASSERT_DOUBLE_EQ(std::tan(angle.getMagnitude()), Math::tan(angle).getMagnitude());
    ASSERT_DOUBLE_EQ(std::tanh(angle.getMagnitude()), Math::tanh(angle).getMagnitude());

    ASSERT_TRUE(std::isnan(Math::asin(angle).getMagnitude()));
    ASSERT_TRUE(std::isnan(Math::acos(angle).getMagnitude()));
}

GTEST_TEST(testBasicMathFunctions, hyperbolicFunctionOverloadsAreEquivalentToTheirCorrespondingCmathFunctions)
{
    constexpr Angle angle = 2.0_rad * Constants::pi;

    ASSERT_DOUBLE_EQ(std::sinh(angle.getMagnitude()), Math::sinh(angle).getMagnitude());
    ASSERT_DOUBLE_EQ(std::cosh(angle.getMagnitude()), Math::cosh(angle).getMagnitude());
    ASSERT_DOUBLE_EQ(std::tanh(angle.getMagnitude()), Math::tanh(angle).getMagnitude());
    ASSERT_DOUBLE_EQ(std::asinh(angle.getMagnitude()), Math::asinh(angle).getMagnitude());
    ASSERT_DOUBLE_EQ(std::acosh(angle.getMagnitude()), Math::acosh(angle).getMagnitude());
    ASSERT_DOUBLE_EQ(std::acosh(angle.getMagnitude()), Math::acosh(angle).getMagnitude());
}

GTEST_TEST(testBasicMathFunctions, weCanTakeTheAverageOfContainersOfPhysicalQuantities)
{
    std::vector<Length> x {1.0_m, 2.0_m, 3.0_m, 4.0_m, 5.0_m, 6.0_m, 7.0_m, 8.0_m, 9.0_m, 10.0_m};
    std::array<Acceleration, 6> y {1.0_m_s2, 2.0_m_s2, 3.0_m_s2, 4.0_m_s2, 5.0_m_s2, 6.0_m_s2};

    ASSERT_EQ(5.5_m, CppUtils::Math::calculateAverage(x.begin(), x.end()));
    ASSERT_EQ(3.0_m_s2, CppUtils::Math::calculateAverage(y.begin(), y.end() - 1));
}

GTEST_TEST(testBasicMathFunctions, weCanTakeTheVarianceOfContainersOfPhysicalQuantities)
{
    std::vector<Length> x {1.0_m, 2.0_m, 3.0_m, 4.0_m, 5.0_m, 6.0_m, 7.0_m, 8.0_m, 9.0_m, 10.0_m};
    std::array<Acceleration, 6> y {1.0_m_s2, 2.0_m_s2, 3.0_m_s2, 4.0_m_s2, 5.0_m_s2, 6.0_m_s2};

    auto x_stdDev = Math::sqrt(CppUtils::Math::calculateVariance(x.begin(), x.end()));
    auto y_stdDev = Math::sqrt(CppUtils::Math::calculateVariance(y.begin() + 2, y.end()));

    ASSERT_NEAR(3.027650, x_stdDev.getMagnitude(), CppUtils::Math::findAbsoluteError(3.027650, 7));
    ASSERT_NEAR(1.290994, y_stdDev.getMagnitude(), CppUtils::Math::findAbsoluteError(1.290994, 7));
}

GTEST_TEST(testBasicMathFunctions, weCanFitALineThroughAContainerOfPhysicalQuantities)
{
    std::vector<Length> x {1.0_m, 2.0_m, 3.0_m, 4.0_m, 5.0_m, 6.0_m, 7.0_m, 8.0_m, 9.0_m, 10.0_m};
    std::vector<Concentration> y {2.0_M, 5.0_M, 3.0_M, 7.0_M, 8.0_M, 9.0_M, 12.0_M, 10.0_M, 15.0_M, 20.0_M};

    auto [slope, intercept, variance] = CppUtils::Math::linearLeastSquaresFitting(x.begin(), x.end(), y.begin(), y.end());

    ASSERT_NEAR(1.7152, slope.getMagnitude(), CppUtils::Math::findAbsoluteError(1.7152, 5));
    ASSERT_NEAR(-0.33333, intercept.getMagnitude(), CppUtils::Math::findAbsoluteError(-0.33333, 5));
    ASSERT_NEAR(0.2139317, Math::sqrt(variance).getMagnitude(), CppUtils::Math::findAbsoluteError(0.2139317, 7));
}

#endif
