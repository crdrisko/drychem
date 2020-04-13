// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testAngleConversionFunctions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:34:29
// Description: Provides ~100% unit test coverage over all angle conversion functions

#ifndef TESTANGLECONVERSIONFUNCTIONS_HPP
#define TESTANGLECONVERSIONFUNCTIONS_HPP

#include <utils-api/errors.hpp>

#include "../testAssertions.hpp"
#include "../../../include/cpp-units/physicalQuantities.hpp"

GTEST_TEST(testAngleConversionFunctions, conversionsOfAngleFrom_rad)
{
    assertThat<PhysicalQuantities::Angle>("rad", "rad").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Angle>("rad", "deg").isConvertedToAValueNear(57.2957795, 9);
}

GTEST_TEST(testAngleConversionFunctions, conversionsOfAngleFrom_deg)
{
    assertThat<PhysicalQuantities::Angle>("deg", "rad").isConvertedToAValueNear(0.0174532925, 9);
    assertThat<PhysicalQuantities::Angle>("deg", "deg").isConvertedTo(1.0);
}

GTEST_TEST(testAngleConversionFunctions, angleWillThrowIfInvalidInputIsSupplied)
{
    PhysicalQuantities::Angle value {1.0};

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("radians", "deg");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tradians is not a valid unit.\n");

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("rad", "degrees");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tdegrees is not a valid unit.\n");

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("rad", "e");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tInitial and final units must be of the same type.\n");
}

#endif
