// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testElectricChargeConversionFunctions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:34:29
// Description: Provides ~100% unit test coverage over all electric charge conversion functions

#ifndef TESTELECTRICCHARGECONVERSIONFUNCTIONS_HPP
#define TESTELECTRICCHARGECONVERSIONFUNCTIONS_HPP

#include <utils-api/errors.hpp>

#include "../testAssertions.hpp"
#include "../../../include/cpp-units/physicalQuantities.hpp"

GTEST_TEST(testElectricChargeConversionFunctions, conversionsOfElectricChargeFrom_C)
{
    assertThat<PhysicalQuantities::ElectricCharge>("C", "C").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::ElectricCharge>("C", "e").isConvertedToAValueNear(6.241509074e18, 10);
}

GTEST_TEST(testElectricChargeConversionFunctions, conversionsOfElectricChargeFrom_e)
{
    assertThat<PhysicalQuantities::ElectricCharge>("e", "C").isConvertedTo(1.602176634e-19);
    assertThat<PhysicalQuantities::ElectricCharge>("e", "e").isConvertedTo(1.0);
}

GTEST_TEST(testElectricChargeConversionFunctions, electricChargeWillThrowIfInvalidInputIsSupplied)
{
    PhysicalQuantities::ElectricCharge value {1.0};

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("electrons", "C");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\telectrons is not a valid unit.\n");

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("e", "Coloumbs");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tColoumbs is not a valid unit.\n");

    ASSERT_DEATH(
    {
        try
        {
            value.convertQuantity("e", "Ang2");
        }
        catch(const Utilities_API::Errors::Exception& except)
        {
            except.handleErrorWithMessage();
        }
    }, "CPP-Units Fatal Error:\n\tInitial and final units must be of the same type.\n");
}

#endif
