// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testMassConversionFunctions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:34:29
// Description: Provides ~100% unit test coverage over all mass conversion functions

#ifndef TESTMASSCONVERSIONFUNCTIONS_HPP
#define TESTMASSCONVERSIONFUNCTIONS_HPP

#include <utils-api/errors.hpp>

#include "../testAssertions.hpp"
#include "../../../include/cpp-units/physicalQuantities.hpp"

GTEST_TEST(testMassConversionFunctions, conversionsOfMassFrom_kg)
{
    assertThat<PhysicalQuantities::Mass>("kg", "kg").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Mass>("kg", "lbs").isConvertedTo(2.20462);
}

GTEST_TEST(testMassConversionFunctions, conversionsOfMassFrom_lbs)
{
    assertThat<PhysicalQuantities::Mass>("lbs", "kg").isConvertedToAValueNear(0.453593, 6);
    assertThat<PhysicalQuantities::Mass>("lbs", "lbs").isConvertedTo(1.0);
}

GTEST_TEST(testMassConversionFunctions, massWillThrowIfInvalidInputIsSupplied)
{
    PhysicalQuantities::Mass value {1.0};

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("pounds", "kg");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tpounds is not a valid unit.\n");

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("lbs", "kilogram");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tkilogram is not a valid unit.\n");

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("lbs", "eV");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tInitial and final units must be of the same type.\n");
}

#endif
