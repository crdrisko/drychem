// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testBasicMathFunctions.hpp
// Author: crdrisko
// Date: 08/25/2020-20:34:50
// Description: Provides ~100% unit test coverage over all basic mathematical functions in the CppUnits library

#ifndef DRYCHEM_CPP_UNITS_TESTS_TESTMATHFUNCTIONS_TESTBASICMATHFUNCTIONS_HPP
#define DRYCHEM_CPP_UNITS_TESTS_TESTMATHFUNCTIONS_TESTBASICMATHFUNCTIONS_HPP

#include <cmath>

#include <common-utils/math.hpp>
#include <gtest/gtest.h>

#include "cpp-units/physicalQuantities.hpp"

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

#endif
