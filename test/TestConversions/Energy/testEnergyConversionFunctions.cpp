// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testEnergyConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 03/05/2020-12:05:29
// Description: Provides 100% unit test coverage over all energy conversion functions

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
    Energy energy(1.0);

    Energy convertedValue = energy.convertQuantity(initialUnits, finalUnits);

    return convertedValue.getMagnitude();
}

TEST(testEnergyConversionFunctions, conversionsOfEnergyFrom_J)
{
    assertThat("J", "J").isConvertedTo(1.0);
    assertThat("J", "eV").isConvertedTo(6.241509074e18);
    assertThat("J", "Hartree").isConvertedTo(2.2937122783963e17);
    assertThat("J", "cal").isConvertedTo(0.2390);
    assertThat("J", "Cal").isConvertedTo(0.0002390);
}

TEST(testEnergyConversionFunctions, conversionsOfEnergyFrom_eV)
{
    assertThat("eV", "J").isConvertedToAValueNear(1.602176634e-19, 10);
    assertThat("eV", "eV").isConvertedTo(1.0);
    assertThat("eV", "Hartree").isConvertedToAValueNear(0.03674932218, 10);
    assertThat("eV", "cal").isConvertedToAValueNear(3.829e-20, 4);
    assertThat("eV", "Cal").isConvertedToAValueNear(3.829e-23, 4);
}

TEST(testEnergyConversionFunctions, conversionsOfEnergyFrom_Hartree)
{
    assertThat("Hartree", "J").isConvertedToAValueNear(4.3597447222071e-18, 14);
    assertThat("Hartree", "eV").isConvertedToAValueNear(27.21138625, 10);
    assertThat("Hartree", "Hartree").isConvertedTo(1.0);
    assertThat("Hartree", "cal").isConvertedToAValueNear(1.042e-18, 4);
    assertThat("Hartree", "Cal").isConvertedToAValueNear(1.042e-21, 4);
}

TEST(testEnergyConversionFunctions, conversionsOfEnergyFrom_cal)
{
    assertThat("cal", "J").isConvertedToAValueNear(4.184, 4);
    assertThat("cal", "eV").isConvertedToAValueNear(2.611e19, 4);
    assertThat("cal", "Hartree").isConvertedToAValueNear(9.597e17, 4);
    assertThat("cal", "cal").isConvertedTo(1.0);
    assertThat("cal", "Cal").isConvertedToAValueNear(1.000e-3, 4);
}

TEST(testEnergyConversionFunctions, conversionsOfEnergyFrom_Cal)
{
    assertThat("Cal", "J").isConvertedToAValueNear(4'184, 4);
    assertThat("Cal", "eV").isConvertedToAValueNear(2.611e22, 4);
    assertThat("Cal", "Hartree").isConvertedToAValueNear(9.597e20, 4);
    assertThat("Cal", "cal").isConvertedToAValueNear(1e3, 4);
    assertThat("Cal", "Cal").isConvertedTo(1.0);
}
