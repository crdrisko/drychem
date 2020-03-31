// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testAngleConversionFunctions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:34:29
// Description: Provides 100% unit test coverage over all angle conversion functions

#ifndef TESTANGLECONVERSIONFUNCTIONS_HPP
#define TESTANGLECONVERSIONFUNCTIONS_HPP

#include "../testAssertions.hpp"
#include "../../../include/cpp-units/physicalQuantities.hpp"

TEST(testAngleConversionFunctions, conversionsOfAngleFrom_rad)
{
    assertThat<PhysicalQuantities::Angle>("rad", "rad").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Angle>("rad", "deg").isConvertedToAValueNear(57.2957795, 9);
}

TEST(testAngleConversionFunctions, conversionsOfAngleFrom_deg)
{
    assertThat<PhysicalQuantities::Angle>("deg", "rad").isConvertedToAValueNear(0.0174532925, 9);
    assertThat<PhysicalQuantities::Angle>("deg", "deg").isConvertedTo(1.0);
}

#endif
