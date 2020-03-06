// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testAngleConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 03/05/2020-11:11:18
// Description: Provides 100% unit test coverage over all angle conversion functions

#include "../testAssertions.hpp"
#include "../../../include/physicalQuantities.hpp"

using namespace PhysicalQuantities;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

long double ConversionAssert::doConversion() const
{
    Angle angle(1.0);

    Angle convertedValue = angle.convertQuantity(initialUnits, finalUnits);

    return convertedValue.getMagnitude();
}

TEST(testAngleConversionFunctions, conversionsOfAngleFrom_rad)
{
    assertThat("rad", "rad").isConvertedTo(1.0);
    assertThat("rad", "deg").isConvertedToAValueNear(57.2957795, 9);
}

TEST(testAngleConversionFunctions, conversionsOfAngleFrom_deg)
{
    assertThat("deg", "rad").isConvertedToAValueNear(0.0174532925, 9);
    assertThat("deg", "deg").isConvertedTo(1.0);
}
