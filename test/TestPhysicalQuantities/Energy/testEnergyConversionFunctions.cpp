// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testEnergyConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:03:53
// Description: Provides 100% unit test coverage over all energy conversion functions

#include "../testAssertions.hpp"
#include "../../../include/internal/PhysicalQuantities/MKSQuantities/WaveQuantities/energy.hpp"

using namespace Utilities_API::PhysicalQuantities;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

long double ConversionAssert::doConversion() const
{
    Energy energy(1.0);

    return (energy.convertQuantity(Conversions::getEnergyConversionFactor(initialUnits,
        finalUnits))).getMagnitude();
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
    assertThat("eV", "J").isConvertedToAValueNear(1.602176634e-19, 10);             // AbsError = 1e-28
    assertThat("eV", "eV").isConvertedTo(1.0);
    assertThat("eV", "Hartree").isConvertedToAValueNear(0.03674932218, 10);         // AbsError = 1e-11
    assertThat("eV", "cal").isConvertedToAValueNear(3.829e-20, 4);                  // AbsError = 1e-23
    assertThat("eV", "Cal").isConvertedToAValueNear(3.829e-23, 4);                  // AbsError = 1e-26
}

TEST(testEnergyConversionFunctions, conversionsOfEnergyFrom_Hartree)
{
    assertThat("Hartree", "J").isConvertedToAValueNear(4.3597447222071e-18, 14);    // AbsError = 1e-31
    assertThat("Hartree", "eV").isConvertedToAValueNear(27.21138625, 10);           // AbsError = 1e-8
    assertThat("Hartree", "Hartree").isConvertedTo(1.0);
    assertThat("Hartree", "cal").isConvertedToAValueNear(1.042e-18, 4);             // AbsError = 1e-21
    assertThat("Hartree", "Cal").isConvertedToAValueNear(1.042e-21, 4);             // AbsError = 1e-24
}

TEST(testEnergyConversionFunctions, conversionsOfEnergyFrom_cal)
{
    assertThat("cal", "J").isConvertedToAValueNear(4.184, 4);                       // AbsError = 1e-3
    assertThat("cal", "eV").isConvertedToAValueNear(2.611e19, 4);                   // AbsError = 1e16
    assertThat("cal", "Hartree").isConvertedToAValueNear(9.597e17, 4);              // AbsError = 1e14
    assertThat("cal", "cal").isConvertedTo(1.0);
    assertThat("cal", "Cal").isConvertedToAValueNear(1.000e-3, 4);                  // AbsError = 1e-6
}

TEST(testEnergyConversionFunctions, conversionsOfEnergyFrom_Cal)
{
    assertThat("Cal", "J").isConvertedToAValueNear(4'184, 4);                       // AbsError = 1
    assertThat("Cal", "eV").isConvertedToAValueNear(2.611e22, 4);                   // AbsError = 1e19
    assertThat("Cal", "Hartree").isConvertedToAValueNear(9.597e20, 4);              // AbsError = 1e17
    assertThat("Cal", "cal").isConvertedToAValueNear(1e3, 4);                       // AbsError = 1
    assertThat("Cal", "Cal").isConvertedTo(1.0);
}
