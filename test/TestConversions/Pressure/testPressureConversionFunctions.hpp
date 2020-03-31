// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testPressureConversionFunctions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:34:29
// Description: Provides 100% unit test coverage over all presure conversion functions

#ifndef TESTPRESSURECONVERSIONFUNCTIONS_HPP
#define TESTPRESSURECONVERSIONFUNCTIONS_HPP

#include "../testAssertions.hpp"
#include "../../../include/cpp-units/physicalQuantities.hpp"

TEST(testPressureConversionFunctions, conversionsOfPressureFrom_atm)
{
    assertThat<PhysicalQuantities::Pressure>("atm", "atm").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Pressure>("atm", "bar").isConvertedToAValueNear(1.01325, 6);
    assertThat<PhysicalQuantities::Pressure>("atm", "Pa").isConvertedToAValueNear(101'325, 6);
    assertThat<PhysicalQuantities::Pressure>("atm", "psi").isConvertedToAValueNear(14.6959, 6);
    assertThat<PhysicalQuantities::Pressure>("atm", "torr").isConvertedToAValueNear(760, 6);
}

TEST(testPressureConversionFunctions, conversionsOfPressureFrom_bar)
{
    assertThat<PhysicalQuantities::Pressure>("bar", "atm").isConvertedTo(0.986923);
    assertThat<PhysicalQuantities::Pressure>("bar", "bar").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Pressure>("bar", "Pa").isConvertedTo(1e5);
    assertThat<PhysicalQuantities::Pressure>("bar", "psi").isConvertedTo(14.5038);
    assertThat<PhysicalQuantities::Pressure>("bar", "torr").isConvertedTo(750.062);
}

TEST(testPressureConversionFunctions, conversionsOfPressureFrom_Pa)
{
    assertThat<PhysicalQuantities::Pressure>("Pa", "atm").isConvertedToAValueNear(9.86923e-6, 6);
    assertThat<PhysicalQuantities::Pressure>("Pa", "bar").isConvertedTo(1e-5);
    assertThat<PhysicalQuantities::Pressure>("Pa", "Pa").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Pressure>("Pa", "psi").isConvertedToAValueNear(1.45038e-4, 6);
    assertThat<PhysicalQuantities::Pressure>("Pa", "torr").isConvertedToAValueNear(7.50062e-3, 6);
}

TEST(testPressureConversionFunctions, conversionsOfPressureFrom_psi)
{
    assertThat<PhysicalQuantities::Pressure>("psi", "atm").isConvertedToAValueNear(6.80458e-2, 6);
    assertThat<PhysicalQuantities::Pressure>("psi", "bar").isConvertedToAValueNear(6.89474e-2, 6);
    assertThat<PhysicalQuantities::Pressure>("psi", "Pa").isConvertedToAValueNear(6894.74, 6);
    assertThat<PhysicalQuantities::Pressure>("psi", "psi").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Pressure>("psi", "torr").isConvertedToAValueNear(51.7149, 6);
}

TEST(testPressureConversionFunctions, conversionsOfPressureFrom_torr)
{
    assertThat<PhysicalQuantities::Pressure>("torr", "atm").isConvertedToAValueNear(1.31579e-3, 6);
    assertThat<PhysicalQuantities::Pressure>("torr", "bar").isConvertedToAValueNear(1.33322e-3, 6);
    assertThat<PhysicalQuantities::Pressure>("torr", "Pa").isConvertedToAValueNear(133.322, 6);
    assertThat<PhysicalQuantities::Pressure>("torr", "psi").isConvertedToAValueNear(1.93368e-2, 6);
    assertThat<PhysicalQuantities::Pressure>("torr", "torr").isConvertedTo(1.0);
}

#endif
