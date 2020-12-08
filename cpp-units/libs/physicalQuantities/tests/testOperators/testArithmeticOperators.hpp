// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testArithmeticOperators.hpp
// Author: crdrisko
// Date: 09/02/2020-14:48:00
// Description: Provides ~100% unit test coverage over all arithmetic functions

#ifndef DRYCHEM_CPP_UNITS_LIBS_PHYSICALQUANTITIES_TESTS_TESTOPERATORS_TESTARITHMETICOPERATORS_HPP
#define DRYCHEM_CPP_UNITS_LIBS_PHYSICALQUANTITIES_TESTS_TESTOPERATORS_TESTARITHMETICOPERATORS_HPP

#include <gtest/gtest.h>

#include "cpp-units/physicalQuantities.hpp"

using namespace CppUnits;
using namespace CppUnits::Literals;

GTEST_TEST(testArithmeticOperators, overloadedAdditionOperatorsActOnlyOnPhysicalQuantities)
{
    DimensionlessQuantity dimensionlessQuantity1 = 5.0_;
    DimensionlessQuantity dimensionlessQuantity2 = 25.0_;

    ASSERT_DOUBLE_EQ(30.0, (dimensionlessQuantity2 + dimensionlessQuantity1).getMagnitude());

    dimensionlessQuantity1 += 2.0_;
    ASSERT_DOUBLE_EQ(7.0, dimensionlessQuantity1.getMagnitude());
}

GTEST_TEST(testArithmeticOperators, overloadedSubtractionOperatorsActOnlyOnPhysicalQuantities)
{
    DimensionlessQuantity dimensionlessQuantity1 = 5.0_;
    DimensionlessQuantity dimensionlessQuantity2 = 25.0_;

    ASSERT_DOUBLE_EQ(20.0, (dimensionlessQuantity2 - dimensionlessQuantity1).getMagnitude());

    dimensionlessQuantity1 -= 2.0_;
    ASSERT_DOUBLE_EQ(3.0, dimensionlessQuantity1.getMagnitude());
}

GTEST_TEST(testArithmeticOperators, unaryMinusOperatorNegatesMagnitude)
{
    DimensionlessQuantity dimensionlessQuantity = -5.0_;

    ASSERT_TRUE(dimensionlessQuantity.getMagnitude() < 0.0);
}

GTEST_TEST(testArithmeticOperators, overloadedMultiplicationOperatorsActOnPhysicalQuantitiesAndNumericTypes)
{
    const Area area     = 24.0_m2;
    const Length length = 1.0_m;

    Volume volume = area * length;

    volume *= 6;
    volume *= 2.0_;
    // volume *= 2.0_m2;                                    // Error: no operator "*=" matches these operands

    Volume newVolume = volume * 2;
    Length newLength = 1.0 * length;

    ASSERT_DOUBLE_EQ(288.0, volume.getMagnitude());
    ASSERT_DOUBLE_EQ(576.0, newVolume.getMagnitude());
    ASSERT_DOUBLE_EQ(1.0, newLength.getMagnitude());
}

GTEST_TEST(testArithmeticOperators, overloadedDivisionOperatorsActOnPhysicalQuantitiesAndNumericTypes)
{
    const Volume volume = 24.0_m3;
    const Length length = 1.0_m;

    Area area = volume / length;

    area /= 6;
    area /= 2.0_;
    // area /= 2.0_m2;                                      // Error: no operator "/=" matches these operands

    Area newArea          = area / 2;
    WaveNumber wavenumber = 1.0 / length;

    ASSERT_DOUBLE_EQ(2.0, area.getMagnitude());
    ASSERT_DOUBLE_EQ(1.0, newArea.getMagnitude());
    ASSERT_DOUBLE_EQ(1.0, wavenumber.getMagnitude());
}

#endif
