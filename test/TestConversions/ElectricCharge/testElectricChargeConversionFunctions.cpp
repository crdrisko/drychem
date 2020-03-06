// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testElectricChargeConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-07:34:26
// Description: Provides 100% unit test coverage over all electric charge conversion functions

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
    ElectricCharge electricCharge(1.0);

    ElectricCharge convertedValue = electricCharge.convertQuantity(initialUnits, finalUnits);

    return convertedValue.getMagnitude();
}

TEST(testElectricChargeConversionFunctions, conversionsOfElectricChargeFrom_C)
{
    assertThat("C", "C").isConvertedTo(1.0);
    assertThat("C", "e").isConvertedToAValueNear(6.241509074e18, 10);
}

TEST(testElectricChargeConversionFunctions, conversionsOfElectricChargeFrom_e)
{
    assertThat("e", "C").isConvertedTo(1.602176634e-19);
    assertThat("e", "e").isConvertedTo(1.0);
}
