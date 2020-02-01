// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testMagneticFluxDensityConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:03:53
// Description: Provides 100% unit test coverage over all magnetic flux density conversion functions

#include "../testAssertions.hpp"
#include "../../../src/include/internal/PhysicalQuantities/ElectromagneticQuantities/MagneticQuantities/magneticFluxDensity.hpp"

using namespace Utilities_API::PhysicalQuantities;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

long double ConversionAssert::doConversion() const
{
    MagneticFluxDensity magneticFluxDensity(1.0);

    return (magneticFluxDensity.convertQuantity(Conversions::getMagneticFluxDensityConversionFactor(initialUnits,
        finalUnits))).getMagnitude();
}

TEST(testMagneticFluxDensityConversionFunctions, conversionsOfElectricChargeFrom_T)
{
    assertThat("T", "T").isConvertedTo(1.0);
    assertThat("T", "G").isConvertedTo(1e4);
    assertThat("T", "gamma").isConvertedTo(1e9);
}

TEST(testMagneticFluxDensityConversionFunctions, conversionsOfElectricChargeFrom_G)
{
    assertThat("G", "T").isConvertedTo(1e-4);
    assertThat("G", "G").isConvertedTo(1.0);
    assertThat("G", "gamma").isConvertedTo(1e5);
}

TEST(testMagneticFluxDensityConversionFunctions, conversionsOfElectricChargeFrom_gamma)
{
    assertThat("gamma", "T").isConvertedTo(1e-9);
    assertThat("gamma", "G").isConvertedTo(1e-5);
    assertThat("gamma", "gamma").isConvertedTo(1.0);
}
