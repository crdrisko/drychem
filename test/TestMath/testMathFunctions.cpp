// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testMathFunctions.cpp - Version 1.0.0
// Author: crdrisko
// Date: 03/04/2020-07:50:11
// Description: Provides 100% unit test coverage over all mathematical functions for the PhysicalQuantities

#include <gtest/gtest.h>

#include "../../include/physicalQuantities.hpp"

using namespace PhysicalQuantities;
using namespace PhysicalQuantities::Literals;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testMathFunctions, testNaturalLogFunctionality)
{
    Length length = 1.0_m;
    ASSERT_DOUBLE_EQ(0.0, Math::log(length).getMagnitude());

    ASSERT_DEATH(
    {
        Math::log(-1.0_m);
    }, "The value inside the natural logarithm must be positive.");
}

TEST(testMathFunctions, testPowerFunctionality)
{
    Length length = 5.0_m;

    WaveNumber waveNumber = Math::pow<WaveNumber>(length, -1);
    DimensionlessQuantity dimensionlessQuantity = Math::pow<DimensionlessQuantity>(length, 0);

    ASSERT_DOUBLE_EQ(0.2, waveNumber.getMagnitude());
    ASSERT_DOUBLE_EQ(1.0, dimensionlessQuantity.getMagnitude());

    // Specializations of pow with automatic type deduction
    ASSERT_DOUBLE_EQ(25.0, Math::square(length).getMagnitude());
    ASSERT_TRUE(Math::square(length) == Math::pow<Area>(length, 2));

    ASSERT_DOUBLE_EQ(125.0, Math::cube(length).getMagnitude());
    ASSERT_TRUE(Math::cube(length) == Math::pow<Volume>(length, 3));
}
