// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testPressureConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:03:53
// Description: Provides 100% unit test coverage over all pressure conversion functions

#include "../testAssertions.hpp"
#include "../../../src/include/internal/PhysicalQuantities/MKSQuantities/PhysicsQuantities/pressure.hpp"

using namespace Utilities_API::PhysicalQuantities;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

long double ConversionAssert::doConversion() const
{
    Pressure pressure(1.0);

    return pressure.convertQuantity(Conversions::getPressureConversionFactor(initialUnits,
        finalUnits)).getMagnitude();
}

TEST(testPressureConversionFunctions, conversionsOfPressureFrom_atm)
{
    assertThat("atm", "atm").isConvertedTo(1.0);
    assertThat("atm", "bar").isConvertedToAValueNear(1.01325, 6);
    assertThat("atm", "Pa").isConvertedToAValueNear(101'325, 6);
    assertThat("atm", "psi").isConvertedToAValueNear(14.6959, 6);
    assertThat("atm", "torr").isConvertedToAValueNear(760, 6);
}

TEST(testPressureConversionFunctions, conversionsOfPressureFrom_bar)
{
    assertThat("bar", "atm").isConvertedTo(0.986923);
    assertThat("bar", "bar").isConvertedTo(1.0);
    assertThat("bar", "Pa").isConvertedTo(1e5);
    assertThat("bar", "psi").isConvertedTo(14.5038);
    assertThat("bar", "torr").isConvertedTo(750.062);
}

TEST(testPressureConversionFunctions, conversionsOfPressureFrom_Pa)
{
    assertThat("Pa", "atm").isConvertedToAValueNear(9.86923e-6, 6);
    assertThat("Pa", "bar").isConvertedTo(1e-5);
    assertThat("Pa", "Pa").isConvertedTo(1.0);
    assertThat("Pa", "psi").isConvertedToAValueNear(1.45038e-4, 6);
    assertThat("Pa", "torr").isConvertedToAValueNear(7.50062e-3, 6);
}

TEST(testPressureConversionFunctions, conversionsOfPressureFrom_psi)
{
    assertThat("psi", "atm").isConvertedToAValueNear(6.80458e-2, 6);
    assertThat("psi", "bar").isConvertedToAValueNear(6.89474e-2, 6);
    assertThat("psi", "Pa").isConvertedToAValueNear(6894.74, 6);
    assertThat("psi", "psi").isConvertedTo(1.0);
    assertThat("psi", "torr").isConvertedToAValueNear(51.7149, 6);
}

TEST(testPressureConversionFunctions, conversionsOfPressureFrom_torr)
{
    assertThat("torr", "atm").isConvertedToAValueNear(1.31579e-3, 6);
    assertThat("torr", "bar").isConvertedToAValueNear(1.33322e-3, 6);
    assertThat("torr", "Pa").isConvertedToAValueNear(133.322, 6);
    assertThat("torr", "psi").isConvertedToAValueNear(1.93368e-2, 6);
    assertThat("torr", "torr").isConvertedTo(1.0);
}
