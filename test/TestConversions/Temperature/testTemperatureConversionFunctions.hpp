// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testTemperatureConversionFunctions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:34:29
// Description: Provides 100% unit test coverage over all temperature conversion functions

#ifndef TESTTEMPERATURECONVERSIONFUNCTIONS_HPP
#define TESTTEMPERATURECONVERSIONFUNCTIONS_HPP

#include "../testAssertions.hpp"
#include "../../../include/cpp-units/physicalQuantities.hpp"

TEST(testTemperatureConversionFunctions, conversionsOfTemperatureFrom_K)
{
    assertThat<PhysicalQuantities::Temperature>("K", "K").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Temperature>("K", "degC").isConvertedTo(-272.15);
    assertThat<PhysicalQuantities::Temperature>("K", "degF").isConvertedTo(-457.87);
}

TEST(testTemperatureConversionFunctions, conversionsOfTemperatureFrom_degC)
{
    assertThat<PhysicalQuantities::Temperature>("degC", "K").isConvertedTo(274.15);
    assertThat<PhysicalQuantities::Temperature>("degC", "degC").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Temperature>("degC", "degF").isConvertedTo(33.8);
}

TEST(testTemperatureConversionFunctions, conversionsOfTemperatureFrom_degF)
{
    assertThat<PhysicalQuantities::Temperature>("degF", "K").isConvertedToAValueNear(255.928, 6);
    assertThat<PhysicalQuantities::Temperature>("degF", "degC").isConvertedToAValueNear(-17.22222, 6);
    assertThat<PhysicalQuantities::Temperature>("degF", "degF").isConvertedTo(1.0);
}

#endif
