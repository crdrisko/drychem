// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testVolumeConversionFunctions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:34:29
// Description: Provides 100% unit test coverage over all volume conversion functions

#ifndef TESTVOLUMECONVERSIONFUNCTIONS_HPP
#define TESTVOLUMECONVERSIONFUNCTIONS_HPP

#include "../testAssertions.hpp"
#include "../../../include/physicalQuantities.hpp"

TEST(testVolumeConversionFunctions, conversionsOfVolumeFrom_m3)
{
    assertThat<PhysicalQuantities::Volume>("m3", "m3").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Volume>("m3", "Ang3").isConvertedTo(1e30);
    assertThat<PhysicalQuantities::Volume>("m3", "L").isConvertedTo(1e3);
}

TEST(testVolumeConversionFunctions, conversionsOfVolumeFrom_Ang3)
{
    assertThat<PhysicalQuantities::Volume>("Ang3", "m3").isConvertedTo(1e-30);
    assertThat<PhysicalQuantities::Volume>("Ang3", "Ang3").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Volume>("Ang3", "L").isConvertedTo(1e-27);
}

TEST(testVolumeConversionFunctions, conversionsOfVolumeFrom_L)
{
    assertThat<PhysicalQuantities::Volume>("L", "m3").isConvertedTo(1e-3);
    assertThat<PhysicalQuantities::Volume>("L", "Ang3").isConvertedTo(1e27);
    assertThat<PhysicalQuantities::Volume>("L", "L").isConvertedTo(1.0);
}

#endif
