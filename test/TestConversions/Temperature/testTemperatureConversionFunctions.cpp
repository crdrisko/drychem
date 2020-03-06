// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testTemperatureConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 03/05/2020-12:27:09
// Description: Provides 100% unit test coverage over all temperature conversion functions

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
    Temperature temperature(1.0);

    Temperature convertedTemperature = temperature.convertQuantity(initialUnits, finalUnits);

    return convertedTemperature.getMagnitude();
}

TEST(testTemperatureConversionFunctions, conversionsOfTemperatureFrom_K)
{
    assertThat("K", "K").isConvertedTo(1.0);
    assertThat("K", "degC").isConvertedTo(-272.15);
    assertThat("K", "degF").isConvertedTo(-457.87);
}

TEST(testTemperatureConversionFunctions, conversionsOfTemperatureFrom_degC)
{
    assertThat("degC", "K").isConvertedTo(274.15);
    assertThat("degC", "degC").isConvertedTo(1.0);
    assertThat("degC", "degF").isConvertedTo(33.8);
}

TEST(testTemperatureConversionFunctions, conversionsOfTemperatureFrom_degF)
{
    assertThat("degF", "K").isConvertedToAValueNear(255.928, 6);
    assertThat("degF", "degC").isConvertedToAValueNear(-17.22222, 6);
    assertThat("degF", "degF").isConvertedTo(1.0);
}
