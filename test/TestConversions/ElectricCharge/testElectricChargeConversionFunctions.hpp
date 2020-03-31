// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testElectricChargeConversionFunctions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:34:29
// Description: Provides 100% unit test coverage over all electric charge conversion functions

#ifndef TESTELECTRICCHARGECONVERSIONFUNCTIONS_HPP
#define TESTELECTRICCHARGECONVERSIONFUNCTIONS_HPP

#include "../testAssertions.hpp"
#include "../../../include/cpp-units/physicalQuantities.hpp"

TEST(testElectricChargeConversionFunctions, conversionsOfElectricChargeFrom_C)
{
    assertThat<PhysicalQuantities::ElectricCharge>("C", "C").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::ElectricCharge>("C", "e").isConvertedToAValueNear(6.241509074e18, 10);
}

TEST(testElectricChargeConversionFunctions, conversionsOfElectricChargeFrom_e)
{
    assertThat<PhysicalQuantities::ElectricCharge>("e", "C").isConvertedTo(1.602176634e-19);
    assertThat<PhysicalQuantities::ElectricCharge>("e", "e").isConvertedTo(1.0);
}

#endif
