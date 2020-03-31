// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testMagneticFluxDensityConversionFunctions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:34:29
// Description: Provides 100% unit test coverage over all magnetic flux density conversion functions

#ifndef TESTMAGNETICFLUXDENSITYCONVERSIONFUNCTIONS_HPP
#define TESTMAGNETICFLUXDENSITYCONVERSIONFUNCTIONS_HPP

#include "../testAssertions.hpp"
#include "../../../include/cpp-units/physicalQuantities.hpp"

TEST(testMagneticFluxDensityConversionFunctions, conversionsOfMagneticFluxDensityFrom_T)
{
    assertThat<PhysicalQuantities::MagneticFluxDensity>("T", "T").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::MagneticFluxDensity>("T", "G").isConvertedTo(1e4);
    assertThat<PhysicalQuantities::MagneticFluxDensity>("T", "gamma").isConvertedTo(1e9);
}

TEST(testMagneticFluxDensityConversionFunctions, conversionsOfMagneticFluxDensityFrom_G)
{
    assertThat<PhysicalQuantities::MagneticFluxDensity>("G", "T").isConvertedTo(1e-4);
    assertThat<PhysicalQuantities::MagneticFluxDensity>("G", "G").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::MagneticFluxDensity>("G", "gamma").isConvertedTo(1e5);
}

TEST(testMagneticFluxDensityConversionFunctions, conversionsOfMagneticFluxDensityFrom_gamma)
{
    assertThat<PhysicalQuantities::MagneticFluxDensity>("gamma", "T").isConvertedTo(1e-9);
    assertThat<PhysicalQuantities::MagneticFluxDensity>("gamma", "G").isConvertedTo(1e-5);
    assertThat<PhysicalQuantities::MagneticFluxDensity>("gamma", "gamma").isConvertedTo(1.0);
}

#endif
