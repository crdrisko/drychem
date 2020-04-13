// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testEnergyConversionFunctions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:34:29
// Description: Provides ~100% unit test coverage over all energy conversion functions

#ifndef TESTENERGYCONVERSIONFUNCTIONS_HPP
#define TESTENERGYCONVERSIONFUNCTIONS_HPP

#include <utils-api/errors.hpp>

#include "../testAssertions.hpp"
#include "../../../include/cpp-units/physicalQuantities.hpp"

GTEST_TEST(testEnergyConversionFunctions, conversionsOfEnergyFrom_J)
{
    assertThat<PhysicalQuantities::Energy>("J", "J").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Energy>("J", "eV").isConvertedTo(6.241509074e18);
    assertThat<PhysicalQuantities::Energy>("J", "Hartree").isConvertedTo(2.2937122783963e17);
    assertThat<PhysicalQuantities::Energy>("J", "cal").isConvertedTo(0.2390);
    assertThat<PhysicalQuantities::Energy>("J", "Cal").isConvertedTo(0.0002390);
}

GTEST_TEST(testEnergyConversionFunctions, conversionsOfEnergyFrom_eV)
{
    assertThat<PhysicalQuantities::Energy>("eV", "J").isConvertedToAValueNear(1.602176634e-19, 10);
    assertThat<PhysicalQuantities::Energy>("eV", "eV").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Energy>("eV", "Hartree").isConvertedToAValueNear(0.03674932218, 10);
    assertThat<PhysicalQuantities::Energy>("eV", "cal").isConvertedToAValueNear(3.829e-20, 4);
    assertThat<PhysicalQuantities::Energy>("eV", "Cal").isConvertedToAValueNear(3.829e-23, 4);
}

GTEST_TEST(testEnergyConversionFunctions, conversionsOfEnergyFrom_Hartree)
{
    assertThat<PhysicalQuantities::Energy>("Hartree", "J").isConvertedToAValueNear(4.3597447222071e-18, 14);
    assertThat<PhysicalQuantities::Energy>("Hartree", "eV").isConvertedToAValueNear(27.21138625, 10);
    assertThat<PhysicalQuantities::Energy>("Hartree", "Hartree").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Energy>("Hartree", "cal").isConvertedToAValueNear(1.042e-18, 4);
    assertThat<PhysicalQuantities::Energy>("Hartree", "Cal").isConvertedToAValueNear(1.042e-21, 4);
}

GTEST_TEST(testEnergyConversionFunctions, conversionsOfEnergyFrom_cal)
{
    assertThat<PhysicalQuantities::Energy>("cal", "J").isConvertedToAValueNear(4.184, 4);
    assertThat<PhysicalQuantities::Energy>("cal", "eV").isConvertedToAValueNear(2.611e19, 4);
    assertThat<PhysicalQuantities::Energy>("cal", "Hartree").isConvertedToAValueNear(9.597e17, 4);
    assertThat<PhysicalQuantities::Energy>("cal", "cal").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Energy>("cal", "Cal").isConvertedToAValueNear(1.000e-3, 4);
}

GTEST_TEST(testEnergyConversionFunctions, conversionsOfEnergyFrom_Cal)
{
    assertThat<PhysicalQuantities::Energy>("Cal", "J").isConvertedToAValueNear(4'184, 4);
    assertThat<PhysicalQuantities::Energy>("Cal", "eV").isConvertedToAValueNear(2.611e22, 4);
    assertThat<PhysicalQuantities::Energy>("Cal", "Hartree").isConvertedToAValueNear(9.597e20, 4);
    assertThat<PhysicalQuantities::Energy>("Cal", "cal").isConvertedToAValueNear(1e3, 4);
    assertThat<PhysicalQuantities::Energy>("Cal", "Cal").isConvertedTo(1.0);
}

GTEST_TEST(testEnergyConversionFunctions, energyWillThrowIfInvalidInputIsSupplied)
{
    PhysicalQuantities::Energy value {1.0};

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("Calories", "eV");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tCalories is not a valid unit.\n");

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("Cal", "electronVolts");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\telectronVolts is not a valid unit.\n");

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("Cal", "Ang2");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tInitial and final units must be of the same type.\n");
}

#endif
