// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testAdvancedMathFunctions.hpp
// Author: crdrisko
// Date: 10/28/2020-10:15:51
// Description: Provides ~100% unit test coverage over all mathematical functions in the Common-Utilities library for PhysicalQuantities

#ifndef DRYCHEM_CPP_UNITS_TESTING_TESTADVANCEDMATHFUNCTIONS_HPP
#define DRYCHEM_CPP_UNITS_TESTING_TESTADVANCEDMATHFUNCTIONS_HPP

#include <array>
#include <vector>

#include <common-utils/math.hpp>
#include <gtest/gtest.h>

#include "cpp-units/physicalQuantities.hpp"

using namespace CppUnits;
using namespace CppUnits::Literals;

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

GTEST_TEST(testBasicMathFunctions, weCanApproximateTheDerivativeOfAContainerOfPhysicalQuantities)
{
    std::vector<Length> length {1.0_m, 2.0_m, 3.0_m, 4.0_m, 5.0_m};
    std::vector<Concentration> concentration {1.0_M, 2.0_M, 3.0_M, 4.0_M, 5.0_M};
    std::vector<ConcentrationGradient> expectedResults {1.0_M_m, 1.0_M_m, 1.0_M_m, 1.0_M_m, 1.0_M_m};

    auto actualResults
        = CppUtils::Math::centeredDifferenceMethod(length.begin(), length.end(), concentration.begin(), concentration.end());

    ASSERT_EQ(expectedResults, actualResults);
}

GTEST_TEST(testBasicMathFunctions, weCanApproximateTheIntegralOfAContainerOfPhysicalQuantities)
{
    std::vector<Length> length {1.0_m, 2.0_m, 3.0_m, 4.0_m, 5.0_m};
    std::vector<ElectricField> eField {1.0_V_m, 2.0_V_m, 3.0_V_m, 4.0_V_m, 5.0_V_m};
    std::vector<ElectricPotential> expectedResults {0.0_V, 1.5_V, 4.0_V, 7.5_V, 12.0_V};

    auto actualResults
        = CppUtils::Math::cumulativeTrapzIntegration(length.begin(), length.end(), eField.begin(), eField.end(), 0.0_V);

    ASSERT_EQ(expectedResults, actualResults);
}

#endif
