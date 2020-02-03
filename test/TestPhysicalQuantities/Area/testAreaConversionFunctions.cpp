// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testAreaConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:03:53
// Description: Provides 100% unit test coverage over all area conversion functions

#include "../testAssertions.hpp"
#include "../../../include/internal/PhysicalQuantities/MKSQuantities/GeometricQuantities/area.hpp"
#include "../../../include/internal/PhysicalQuantities/MKSQuantities/GeometricQuantities/length.hpp"

using namespace Utilities_API::PhysicalQuantities;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

long double ConversionAssert::doConversion() const
{
    Area area(1.0);

    return (area.convertQuantity(Conversions::getAreaConversionFactor(initialUnits,
        finalUnits))).getMagnitude();
}

TEST(testAreaConversionFunctions, conversionsOfAreaFrom_m2)
{
    assertThat("m2", "m2").isConvertedTo(1.0);
    assertThat("m2", "Ang2").isConvertedTo(1e20);
}

TEST(testAreaConversionFunctions, conversionsOfAreaFrom_Ang2)
{
    assertThat("Ang2", "m2").isConvertedTo(1e-20);
    assertThat("Ang2", "Ang2").isConvertedTo(1.0);
}
