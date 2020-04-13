// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testTemperatureConversionFunctions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:34:29
// Description: Provides ~100% unit test coverage over all temperature conversion functions

#ifndef TESTTEMPERATURECONVERSIONFUNCTIONS_HPP
#define TESTTEMPERATURECONVERSIONFUNCTIONS_HPP

#include <utils-api/errors.hpp>

#include "../testAssertions.hpp"
#include "../../../include/cpp-units/physicalQuantities.hpp"

GTEST_TEST(testTemperatureConversionFunctions, conversionsOfTemperatureFrom_K)
{
    assertThat<PhysicalQuantities::Temperature>("K", "K").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Temperature>("K", "degC").isConvertedTo(-272.15);
    assertThat<PhysicalQuantities::Temperature>("K", "degF").isConvertedTo(-457.87);
}

GTEST_TEST(testTemperatureConversionFunctions, conversionsOfTemperatureFrom_degC)
{
    assertThat<PhysicalQuantities::Temperature>("degC", "K").isConvertedTo(274.15);
    assertThat<PhysicalQuantities::Temperature>("degC", "degC").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Temperature>("degC", "degF").isConvertedTo(33.8);
}

GTEST_TEST(testTemperatureConversionFunctions, conversionsOfTemperatureFrom_degF)
{
    assertThat<PhysicalQuantities::Temperature>("degF", "K").isConvertedToAValueNear(255.928, 6);
    assertThat<PhysicalQuantities::Temperature>("degF", "degC").isConvertedToAValueNear(-17.22222, 6);
    assertThat<PhysicalQuantities::Temperature>("degF", "degF").isConvertedTo(1.0);
}

GTEST_TEST(testTemperatureConversionFunctions, temperatureWillThrowIfInvalidInputIsSupplied)
{
    PhysicalQuantities::Temperature value {1.0};

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("Kelvin", "degC");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tKelvin is not a valid unit.\n");

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("K", "degreesCelcius");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tdegreesCelcius is not a valid unit.\n");

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("K", "base");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tInitial and final units must be of the same type.\n");
}

#endif
