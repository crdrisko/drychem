// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testMolarEnergyConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-07:34:26
// Description: Provides 100% unit test coverage over all molar energy conversion functions

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
    MolarEnergy molarEnergy(1.0);

    MolarEnergy convertedValue = molarEnergy.convertQuantity(initialUnits, finalUnits);

    return convertedValue.getMagnitude();
}

TEST(testMolarEnergyConversionFunctions, conversionsOfEnergyFrom_J_mol)
{
    assertThat("J_mol", "J_mol").isConvertedTo(1.0);
    assertThat("J_mol", "eV_part").isConvertedToAValueNear(1.036426966e-5, 10);
    assertThat("J_mol", "kcal_mol").isConvertedToAValueNear(0.00023901, 5);
}

TEST(testMolarEnergyConversionFunctions, conversionsOfEnergyFrom_eV_part)
{
    assertThat("eV_part", "J_mol").isConvertedToAValueNear(96'485.33209, 10);
    assertThat("eV_part", "eV_part").isConvertedTo(1.0);
    assertThat("eV_part", "kcal_mol").isConvertedToAValueNear(23.061, 5);
}

TEST(testMolarEnergyConversionFunctions, conversionsOfEnergyFrom_kcal_mol)
{
    assertThat("kcal_mol", "J_mol").isConvertedToAValueNear(4'184.0, 5);
    assertThat("kcal_mol", "eV_part").isConvertedToAValueNear(4.3364e-2, 5);
    assertThat("kcal_mol", "kcal_mol").isConvertedTo(1.0);
}
