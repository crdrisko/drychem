// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testMiscellaneousUnitFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:04:24
// Description: Provides 100% unit test coverage over all operators and other miscellaneous functions

#include <gtest/gtest.h>
#include "../../../include/internal/PhysicalQuantities/MKSQuantities/GeometricQuantities/length.hpp"
#include "../../../include/internal/PhysicalQuantities/MolarQuantities/concentration.hpp"
#include "../../../include/internal/PhysicalQuantities/MolarQuantities/concentrationGradient.hpp"

using namespace Utilities_API::PhysicalQuantities;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testMiscellaneousUnitFunctions, properPrintingOfPhysicalQuantitysMagnitude)
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
    DimensionlessQuantity value4(1.0);

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
    DimensionlessQuantity dimensionlessQuantity = 5.0_;
    DimensionlessQuantity dimensionlessQuantitySquared = dimensionlessQuantity.raisePower(2);

    ASSERT_DOUBLE_EQ(30.0, (dimensionlessQuantitySquared + dimensionlessQuantity).getMagnitude());

    dimensionlessQuantity += 2.0_;
    ASSERT_DOUBLE_EQ(7.0, dimensionlessQuantity.getMagnitude());

    ASSERT_DOUBLE_EQ(18.0, (dimensionlessQuantitySquared - dimensionlessQuantity).getMagnitude());

    dimensionlessQuantity -= 2.0_;
    ASSERT_DOUBLE_EQ(5.0, dimensionlessQuantity.getMagnitude());

    ASSERT_DOUBLE_EQ(125.0, (dimensionlessQuantitySquared * dimensionlessQuantity).getMagnitude());
    ASSERT_DOUBLE_EQ(5.0, (dimensionlessQuantitySquared / dimensionlessQuantity).getMagnitude());
}

TEST(testMiscellaneousUnitFunctions, testAdvancedMathFunctions)
{
    // A test of the PhysicalQuantity class's finite difference method function
    std::vector<Length> lengthVector { 1.0_m, 2.0_m, 3.0_m, 4.0_m, 5.0_m };
    std::vector<Concentration> concentrationVector { 1.0_M, 2.0_M, 3.0_M, 4.0_M, 5.0_M };

    std::vector<double> expectedResults { 1.0, 1.0, 1.0, 1.0, 1.0 };

    std::vector<ConcentrationGradient> gradientVector = finiteDifferenceMethod(lengthVector,
        concentrationVector, "Centered");

    std::vector<double> actualResults;

    for (const auto& result : gradientVector)
        actualResults.push_back(result.getMagnitude());

    ASSERT_EQ(expectedResults, actualResults);


    // A test of the PhysicalQuantity class's average calculation method
    Length averageLength = calculateAverage(lengthVector);

    ASSERT_EQ(3, averageLength.getMagnitude());
}

TEST(testMiscellaneousUnitFunctions, testAllOtherMiscellaneousFunctions)
{
    // A test of the PhysicalQuantity class's negation function
    DimensionlessQuantity positiveValue = 1.0_;
    ASSERT_DOUBLE_EQ(1.0, positiveValue.getMagnitude());
    ASSERT_DOUBLE_EQ(-1.0, positiveValue.negateQuantity().getMagnitude());


    // A test of the PhysicalQuantity class's default initializer
    DimensionlessQuantity defaultInitialized;
    ASSERT_DOUBLE_EQ(0.0, defaultInitialized.getMagnitude());

    defaultInitialized.setMagnitude(1e5);
    ASSERT_DOUBLE_EQ(1e5, defaultInitialized.getMagnitude());
}
