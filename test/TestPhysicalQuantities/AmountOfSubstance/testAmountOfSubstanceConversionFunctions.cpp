// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testAmountOfSubstanceConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:03:53
// Description: Provides 100% unit test coverage over all amount of substance conversion functions

#include "../testAssertions.hpp"
#include "../../../include/internal/PhysicalQuantities/MolarQuantities/amountOfSubstance.hpp"

using namespace Utilities_API::PhysicalQuantities;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

long double ConversionAssert::doConversion() const
{
    AmountOfSubstance amountOfSubstance(1.0);

    return (amountOfSubstance.convertQuantity(Conversions::getAmountOfSubstanceConversionFactor(initialUnits,
        finalUnits))).getMagnitude();
}

TEST(testAmountOfSubstanceConversionFunctions, conversionsOfAmountOfSubstanceFrom_mol)
{
    assertThat("mol", "mol").isConvertedTo(1.0);
    assertThat("mol", "part").isConvertedTo(Constants::avogadrosNumber.getMagnitude());
}

TEST(testAmountOfSubstanceConversionFunctions, conversionsOfAmountOfSubstanceFrom_part)
{
    assertThat("part", "mol").isConvertedTo(1 / Constants::avogadrosNumber.getMagnitude());
    assertThat("part", "part").isConvertedTo(1.0);
}
