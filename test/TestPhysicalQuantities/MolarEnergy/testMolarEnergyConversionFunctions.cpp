// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testMolarEnergyConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:03:53
// Description: Provides 100% unit test coverage over all molar energy conversion functions

#include "../testAssertions.hpp"
#include "../../../include/internal/PhysicalQuantities/MolarQuantities/molarEnergy.hpp"

using namespace Utilities_API::PhysicalQuantities;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

long double ConversionAssert::doConversion() const
{
    MolarEnergy molarEnergy(1.0);

    return (molarEnergy.convertQuantity(Conversions::getMolarEnergyConversionFactor(initialUnits,
        finalUnits))).getMagnitude();
}

TEST(testMolarEnergyConversionFunctions, conversionsOfEnergyFrom_J_mol)
{
    assertThat("J_mol", "J_mol").isConvertedTo(1.0);
    assertThat("J_mol", "eV_part").isConvertedToAValueNear(1.03642697e-5, 9);
    assertThat("J_mol", "kcal_mol").isConvertedToAValueNear(0.0002390, 4);
}

TEST(testMolarEnergyConversionFunctions, conversionsOfEnergyFrom_eV_part)
{
    assertThat("eV_part", "J_mol").isConvertedToAValueNear(96'485.3321, 9);
    assertThat("eV_part", "eV_part").isConvertedTo(1.0);
    assertThat("eV_part", "kcal_mol").isConvertedToAValueNear(23.0605478, 9);
}

TEST(testMolarEnergyConversionFunctions, conversionsOfEnergyFrom_kcal_mol)
{
    assertThat("kcal_mol", "J_mol").isConvertedToAValueNear(4'184, 4);
    assertThat("kcal_mol", "eV_part").isConvertedToAValueNear(4.33641043e-2, 9);
    assertThat("kcal_mol", "kcal_mol").isConvertedTo(1.0);
}
