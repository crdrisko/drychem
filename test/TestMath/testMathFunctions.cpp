// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testMathFunctions.cpp - Version 1.0.0
// Author: crdrisko
// Date: 03/04/2020-07:50:11
// Description:

#include <exception>

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
        Length length = -1.0_m;

        Math::log(length);
    }, "The value inside the natural logarithm must be positive.");
}

TEST(testMathFunctions, testPowerFunctionality)
{
    Length length = 5.0_m;

    ASSERT_DOUBLE_EQ(25.0, Math::pow<AreaDimensionality>(length, 2).getMagnitude());
    ASSERT_DOUBLE_EQ(125.0, Math::pow<VolumeDimensionality>(length, 3).getMagnitude());
}
