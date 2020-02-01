// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testAngleConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:03:53
// Description: Provides 100% unit test coverage over all angle conversion functions

#include "../testAssertions.hpp"
#include "../../../src/include/internal/PhysicalQuantities/MKSQuantities/GeometricQuantities/angle.hpp"

using namespace Utilities_API::PhysicalQuantities;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

long double ConversionAssert::doConversion() const
{
    Angle angle(1.0);

    return (angle.convertQuantity(Conversions::getAngleConversionFactor(initialUnits,
        finalUnits))).getMagnitude();
}

TEST(testAngleConversionFunctions, conversionsOfAnglesFrom_rad)
{
    assertThat("rad", "rad").isConvertedTo(1.0);
    assertThat("rad", "deg").isConvertedToAValueNear(57.2957796, 9);
}

TEST(testAngleConversionFunctions, conversionsOfAnglesFrom_deg)
{
    assertThat("deg", "rad").isConvertedToAValueNear(0.0174532925, 9);
    assertThat("deg", "deg").isConvertedTo(1.0);
}
