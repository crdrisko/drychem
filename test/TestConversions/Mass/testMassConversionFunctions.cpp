// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testMassConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 03/05/2020-11:42:52
// Description: Provides 100% unit test coverage over all mass conversion functions

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
    Mass mass(1.0);

    Mass convertedValue = mass.convertQuantity(initialUnits, finalUnits);

    return convertedValue.getMagnitude();
}

TEST(testMassConversionFunctions, conversionsOfMassFrom_kg)
{
    assertThat("kg", "kg").isConvertedTo(1.0);
    assertThat("kg", "lbs").isConvertedTo(2.20462);
}

TEST(testMassConversionFunctions, conversionsOfMassFrom_lbs)
{
    assertThat("lbs", "kg").isConvertedToAValueNear(0.453593, 6);
    assertThat("lbs", "lbs").isConvertedTo(1.0);
}
