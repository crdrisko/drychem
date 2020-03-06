// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testMagneticFluxDensityConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-07:34:26
// Description: Provides 100% unit test coverage over all magnetic flux density conversion functions

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
    MagneticFluxDensity magneticFluxDensity(1.0);

    MagneticFluxDensity convertedValue = magneticFluxDensity.convertQuantity(initialUnits, finalUnits);

    return convertedValue.getMagnitude();
}

TEST(testMagneticFluxDensityConversionFunctions, conversionsOfMagneticFluxDensityFrom_T)
{
    assertThat("T", "T").isConvertedTo(1.0);
    assertThat("T", "G").isConvertedTo(1e4);
    assertThat("T", "gamma").isConvertedTo(1e9);
}

TEST(testMagneticFluxDensityConversionFunctions, conversionsOfMagneticFluxDensityFrom_G)
{
    assertThat("G", "T").isConvertedTo(1e-4);
    assertThat("G", "G").isConvertedTo(1.0);
    assertThat("G", "gamma").isConvertedTo(1e5);
}

TEST(testMagneticFluxDensityConversionFunctions, conversionsOfMagneticFluxDensityFrom_gamma)
{
    assertThat("gamma", "T").isConvertedTo(1e-9);
    assertThat("gamma", "G").isConvertedTo(1e-5);
    assertThat("gamma", "gamma").isConvertedTo(1.0);
}
