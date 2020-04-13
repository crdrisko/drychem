// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testAreaConversionFunctions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:34:29
// Description: Provides ~100% unit test coverage over all area conversion functions

#ifndef TESTAREACONVERSIONFUNCTIONS_HPP
#define TESTAREACONVERSIONFUNCTIONS_HPP

#include <utils-api/errors.hpp>

#include "../testAssertions.hpp"
#include "../../../include/cpp-units/physicalQuantities.hpp"

GTEST_TEST(testAreaConversionFunctions, conversionsOfAreaFrom_m2)
{
    assertThat<PhysicalQuantities::Area>("m2", "m2").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Area>("m2", "Ang2").isConvertedTo(1e20);
}

GTEST_TEST(testAreaConversionFunctions, conversionsOfAreaFrom_Ang2)
{
    assertThat<PhysicalQuantities::Area>("Ang2", "m2").isConvertedTo(1e-20);
    assertThat<PhysicalQuantities::Area>("Ang2", "Ang2").isConvertedTo(1.0);
}

GTEST_TEST(testAreaConversionFunctions, areaWillThrowIfInvalidInputIsSupplied)
{
    PhysicalQuantities::Area value {1.0};

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("Angstroms2", "m2");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tAngstroms2 is not a valid unit.\n");

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("Ang2", "meters2");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tmeters2 is not a valid unit.\n");

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("Ang2", "e");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tInitial and final units must be of the same type.\n");
}

#endif
