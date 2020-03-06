// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testAmountOfSubstanceConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-07:34:26
// Description: Provides 100% unit test coverage over all amount of substance conversion functions

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
    AmountOfSubstance amountOfSubstance(1.0);

    AmountOfSubstance convertedValue = amountOfSubstance.convertQuantity(initialUnits, finalUnits);

    return convertedValue.getMagnitude();
}

TEST(testAmountOfSubstanceConversionFunctions, conversionsOfAmountOfSubstanceFrom_mol)
{
    assertThat("mol", "mol").isConvertedTo(1.0);
    assertThat("mol", "part").isConvertedTo(6.02214076e23);
}

TEST(testAmountOfSubstanceConversionFunctions, conversionsOfAmountOfSubstanceFrom_part)
{
    assertThat("part", "mol").isConvertedToAValueNear(1.66053907e-24, 9);
    assertThat("part", "part").isConvertedTo(1.0);
}
