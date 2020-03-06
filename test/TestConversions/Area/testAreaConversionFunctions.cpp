// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testAreaConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 03/05/2020-11:11:18
// Description: Provides 100% unit test coverage over all area conversion functions

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
    Area area(1.0);

    Area convertedValue = area.convertQuantity(initialUnits, finalUnits);

    return convertedValue.getMagnitude();
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
