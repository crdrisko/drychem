// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testMiscellaneousUnitFunctions.cpp - Version 1.0.0
// Author: crdrisko
// Date: 03/05/2020-09:03:19
// Description: Provides 100% unit test coverage over all operators and other miscellaneous functions

#include <gtest/gtest.h>
#include <utils-api/errors.hpp>

#include "../../include/physicalQuantities.hpp"

using namespace PhysicalQuantities;
using namespace PhysicalQuantities::Literals;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


TEST(testMiscellaneousUnitFunctions, testPrintingMagnitudeUsingStreamOperator)
{
    testing::internal::CaptureStdout();

    DimensionlessQuantity value = 1.0_;

    std::cout << value << std::endl;
    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "1\n");
}

TEST(testMiscellaneousUnitFunctions, testComparisonOperators)
{
    DimensionlessQuantity value1 = 1.0_;
    DimensionlessQuantity value2 = 2.0_;
    DimensionlessQuantity value3 = 5.0_;
    DimensionlessQuantity value4 = 1.0_;

    ASSERT_TRUE(value1 < value2);
    ASSERT_TRUE(value1 <= value2);
    ASSERT_TRUE(value3 > value2);
    ASSERT_TRUE(value3 >= value2);
    ASSERT_TRUE(value1 == value4);
    ASSERT_TRUE(value3 != value2);

    ASSERT_FALSE(value1 == value2);
    ASSERT_FALSE(value1 >= value2);
    ASSERT_FALSE(value4 != value1);
}

TEST(testMiscellaneousUnitFunctions, testArithmeticOperators)
{
    DimensionlessQuantity dimensionlessQuantity1 = 5.0_;
    DimensionlessQuantity dimensionlessQuantity2 = 25.0_;

    ASSERT_DOUBLE_EQ(30.0, (dimensionlessQuantity2 + dimensionlessQuantity1).getMagnitude());

    dimensionlessQuantity1 += 2.0_;
    ASSERT_DOUBLE_EQ(7.0, dimensionlessQuantity1.getMagnitude());

    ASSERT_DOUBLE_EQ(18.0, (dimensionlessQuantity2 - dimensionlessQuantity1).getMagnitude());

    dimensionlessQuantity1 -= 2.0_;
    ASSERT_DOUBLE_EQ(5.0, dimensionlessQuantity1.getMagnitude());

    ASSERT_DOUBLE_EQ(125.0, (dimensionlessQuantity2 * dimensionlessQuantity1).getMagnitude());
    ASSERT_DOUBLE_EQ(5.0, (dimensionlessQuantity2 / dimensionlessQuantity1).getMagnitude());
}

TEST(testMiscellaneousUnitFunctions, testUnaryMinusOperator)
{
    DimensionlessQuantity dimensionlessQuantity = -5.0_;

    ASSERT_TRUE(dimensionlessQuantity.getMagnitude() < 0.0);
}

TEST(testMiscellaneousUnitFunctions, testDefaultInitializerAndSetter)
{
    DimensionlessQuantity defaultInitialized;
    ASSERT_EQ(0.0, defaultInitialized.getMagnitude());

    defaultInitialized.setMagnitude(1e5);
    ASSERT_EQ(1e5, defaultInitialized.getMagnitude());
}

TEST(testMiscellaneousUnitFunctions, testStringConstructor)
{
    DimensionlessQuantity dimensionlessQuantity("1e5");
    ASSERT_DOUBLE_EQ(1e5, dimensionlessQuantity.getMagnitude());

    ASSERT_DEATH(
    {
        try
        {
            DimensionlessQuantity dimensionlessQuantity("Not a number");
        }
        catch(const std::exception& e)
        {
            Utilities_API::Errors::printFatalErrorMessage(1, "stold: no conversion");
        }
    }, "stold: no conversion");
}
