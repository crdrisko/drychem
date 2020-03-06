// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testAmountOfSubstanceConversionFunctions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:34:29
// Description: Provides 100% unit test coverage over all amount of substance conversion functions

#ifndef TESTAMOUNTOFSUBSTANCECONVERSIONFUNCTIONS_HPP
#define TESTAMOUNTOFSUBSTANCECONVERSIONFUNCTIONS_HPP

#include "../testAssertions.hpp"
#include "../../../include/physicalQuantities.hpp"

TEST(testAmountOfSubstanceConversionFunctions, conversionsOfAmountOfSubstanceFrom_mol)
{
    assertThat<PhysicalQuantities::AmountOfSubstance>("mol", "mol").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::AmountOfSubstance>("mol", "part").isConvertedTo(6.02214076e23);
}

TEST(testAmountOfSubstanceConversionFunctions, conversionsOfAmountOfSubstanceFrom_part)
{
    assertThat<PhysicalQuantities::AmountOfSubstance>("part", "mol").isConvertedToAValueNear(1.66053907e-24, 9);
    assertThat<PhysicalQuantities::AmountOfSubstance>("part", "part").isConvertedTo(1.0);
}

#endif
