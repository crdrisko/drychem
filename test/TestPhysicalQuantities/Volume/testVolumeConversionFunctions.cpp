// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testVolumeConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:03:54
// Description: Provides 100% unit test coverage over all angle conversion functions

#include "../testAssertions.hpp"
#include "../../../include/internal/PhysicalQuantities/MKSQuantities/GeometricQuantities/volume.hpp"

using namespace Utilities_API::PhysicalQuantities;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

long double ConversionAssert::doConversion() const
{
    Volume volume(1.0);

    return (volume.convertQuantity(Conversions::getVolumeConversionFactor(initialUnits,
        finalUnits))).getMagnitude();
}

TEST(testVolumeConversionFunctions, conversionsOfVolumeFrom_m3)
{
    assertThat("m3", "m3").isConvertedTo(1.0);
    assertThat("m3", "Ang3").isConvertedTo(1e30);
    assertThat("m3", "L").isConvertedTo(1e3);
}

TEST(testVolumeConversionFunctions, conversionsOfVolumeFrom_Ang3)
{
    assertThat("Ang3", "m3").isConvertedTo(1e-30);
    assertThat("Ang3", "Ang3").isConvertedTo(1.0);
    assertThat("Ang3", "L").isConvertedTo(1e-27);
}

TEST(testVolumeConversionFunctions, conversionsOfVolumeFrom_L)
{
    assertThat("L", "m3").isConvertedTo(1e-3);
    assertThat("L", "Ang3").isConvertedTo(1e27);
    assertThat("L", "L").isConvertedTo(1.0);
}
