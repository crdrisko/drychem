// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testLengthConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:03:53
// Description: Provides 100% unit test coverage over all length conversion functions

#include "../testAssertions.hpp"
#include "../../../include/internal/PhysicalQuantities/MKSQuantities/GeometricQuantities/length.hpp"

using namespace Utilities_API::PhysicalQuantities;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

long double ConversionAssert::doConversion() const
{
    Length length(1.0);

    return (length.convertQuantity(Conversions::getLengthConversionFactor(initialUnits,
        finalUnits))).getMagnitude();
}

TEST(testlengthConversionFunctions, conversionsOfLengthFrom_m)
{
    assertThat("m", "m").isConvertedTo(1.0);
    assertThat("m", "Ang").isConvertedTo(1e10);
    assertThat("m", "in").isConvertedTo(39.3700787);
    assertThat("m", "ft").isConvertedTo(3.280840);
    assertThat("m", "yd").isConvertedTo(1.093613);
    assertThat("m", "mil").isConvertedTo(6.213712e-4);
}

TEST(testlengthConversionFunctions, conversionsOfLengthFrom_Ang)
{
    assertThat("Ang", "m").isConvertedTo(1e-10);
    assertThat("Ang", "Ang").isConvertedTo(1.0);
    assertThat("Ang", "in").isConvertedToAValueNear(3.9370079e-9, 8);
    assertThat("Ang", "ft").isConvertedToAValueNear(3.280840e-10, 7);
    assertThat("Ang", "yd").isConvertedToAValueNear(1.093613e-10, 7);
    assertThat("Ang", "mil").isConvertedToAValueNear(6.213712e-14, 7);
}

TEST(testlengthConversionFunctions, conversionsOfLengthFrom_in)
{
    assertThat("in", "m").isConvertedToAValueNear(0.0254, 8);
    assertThat("in", "Ang").isConvertedToAValueNear(2.54e8, 8);
    assertThat("in", "in").isConvertedTo(1.0);
    assertThat("in", "ft").isConvertedToAValueNear(0.08333333, 7);
    assertThat("in", "yd").isConvertedToAValueNear(0.02777777, 7);
    assertThat("in", "mil").isConvertedToAValueNear(1.578283e-5, 7);
}

TEST(testlengthConversionFunctions, conversionsOfLengthFrom_ft)
{
    assertThat("ft", "m").isConvertedToAValueNear(0.3048, 7);
    assertThat("ft", "Ang").isConvertedToAValueNear(3.048e9, 7);
    assertThat("ft", "in").isConvertedToAValueNear(12.0, 7);
    assertThat("ft", "ft").isConvertedTo(1.0);
    assertThat("ft", "yd").isConvertedToAValueNear(0.3333333, 7);
    assertThat("ft", "mil").isConvertedToAValueNear(1.893939e-4, 7);
}

TEST(testlengthConversionFunctions, conversionsOfLengthFrom_yd)
{
    assertThat("yd", "m").isConvertedToAValueNear(0.9144002, 7);
    assertThat("yd", "Ang").isConvertedToAValueNear(9.144002e9, 7);
    assertThat("yd", "in").isConvertedToAValueNear(36.0, 7);
    assertThat("yd", "ft").isConvertedToAValueNear(3.0, 7);
    assertThat("yd", "yd").isConvertedTo(1.0);
    assertThat("yd", "mil").isConvertedToAValueNear(5.681820e-4, 7);
}

TEST(testlengthConversionFunctions, conversionsOfLengthFrom_mil)
{
    assertThat("mil", "m").isConvertedToAValueNear(1609.344, 7);
    assertThat("mil", "Ang").isConvertedToAValueNear(1.609344e13, 7);
    assertThat("mil", "in").isConvertedToAValueNear(6.336e4, 7);
    assertThat("mil", "ft").isConvertedToAValueNear(5280.00, 7);
    assertThat("mil", "yd").isConvertedToAValueNear(1760.0, 7);
    assertThat("mil", "mil").isConvertedTo(1.0);
}
