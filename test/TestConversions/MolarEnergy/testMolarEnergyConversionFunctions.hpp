// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testMolarEnergyConversionFunctions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:34:29
// Description: Provides ~100% unit test coverage over all molar energy conversion functions

#ifndef TESTMOLARENERGYCONVERSIONFUNCTIONS_HPP
#define TESTMOLARENERGYCONVERSIONFUNCTIONS_HPP

#include <utils-api/errors.hpp>

#include "../testAssertions.hpp"
#include "../../../include/cpp-units/physicalQuantities.hpp"

GTEST_TEST(testMolarEnergyConversionFunctions, conversionsOfEnergyFrom_J_mol)
{
    assertThat<PhysicalQuantities::MolarEnergy>("J_mol", "J_mol").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::MolarEnergy>("J_mol", "eV_part").isConvertedToAValueNear(1.036426966e-5, 10);
    assertThat<PhysicalQuantities::MolarEnergy>("J_mol", "kcal_mol").isConvertedToAValueNear(0.00023901, 5);
}

GTEST_TEST(testMolarEnergyConversionFunctions, conversionsOfEnergyFrom_eV_part)
{
    assertThat<PhysicalQuantities::MolarEnergy>("eV_part", "J_mol").isConvertedToAValueNear(96'485.33209, 10);
    assertThat<PhysicalQuantities::MolarEnergy>("eV_part", "eV_part").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::MolarEnergy>("eV_part", "kcal_mol").isConvertedToAValueNear(23.061, 5);
}

GTEST_TEST(testMolarEnergyConversionFunctions, conversionsOfEnergyFrom_kcal_mol)
{
    assertThat<PhysicalQuantities::MolarEnergy>("kcal_mol", "J_mol").isConvertedToAValueNear(4'184.0, 5);
    assertThat<PhysicalQuantities::MolarEnergy>("kcal_mol", "eV_part").isConvertedToAValueNear(4.3364e-2, 5);
    assertThat<PhysicalQuantities::MolarEnergy>("kcal_mol", "kcal_mol").isConvertedTo(1.0);
}

GTEST_TEST(testMolarEnergyConversionFunctions, molarEnergyWillThrowIfInvalidInputIsSupplied)
{
    PhysicalQuantities::MolarEnergy value {1.0};

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("kcal_mol", "Joules_per_mol");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tJoules_per_mol is not a valid unit.\n");

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("kilocalories_per_mol", "J_mol");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tkilocalories_per_mol is not a valid unit.\n");

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("kcal_mol", "degC");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tInitial and final units must be of the same type.\n");
}

#endif
