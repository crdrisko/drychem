// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testLengthConversionFunctions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:34:29
// Description: Provides 100% unit test coverage over all length conversion functions

#ifndef TESTLENGTHCONVERSIONFUNCTIONS_HPP
#define TESTLENGTHCONVERSIONFUNCTIONS_HPP

#include "../testAssertions.hpp"
#include "../../../include/cpp-units/physicalQuantities.hpp"

TEST(testLengthConversionFunctions, conversionsOfLengthFrom_m)
{
    assertThat<PhysicalQuantities::Length>("m", "m").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Length>("m", "Ang").isConvertedTo(1e10);
    assertThat<PhysicalQuantities::Length>("m", "in").isConvertedTo(39.3700787);
    assertThat<PhysicalQuantities::Length>("m", "ft").isConvertedTo(3.280840);
    assertThat<PhysicalQuantities::Length>("m", "yd").isConvertedTo(1.093613);
    assertThat<PhysicalQuantities::Length>("m", "mil").isConvertedTo(6.213712e-4);
}

TEST(testLengthConversionFunctions, conversionsOfLengthFrom_Ang)
{
    assertThat<PhysicalQuantities::Length>("Ang", "m").isConvertedTo(1e-10);
    assertThat<PhysicalQuantities::Length>("Ang", "Ang").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Length>("Ang", "in").isConvertedToAValueNear(3.9370079e-9, 8);
    assertThat<PhysicalQuantities::Length>("Ang", "ft").isConvertedToAValueNear(3.280840e-10, 7);
    assertThat<PhysicalQuantities::Length>("Ang", "yd").isConvertedToAValueNear(1.093613e-10, 7);
    assertThat<PhysicalQuantities::Length>("Ang", "mil").isConvertedToAValueNear(6.213712e-14, 7);
}

TEST(testLengthConversionFunctions, conversionsOfLengthFrom_in)
{
    assertThat<PhysicalQuantities::Length>("in", "m").isConvertedToAValueNear(0.0254, 8);
    assertThat<PhysicalQuantities::Length>("in", "Ang").isConvertedToAValueNear(2.54e8, 8);
    assertThat<PhysicalQuantities::Length>("in", "in").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Length>("in", "ft").isConvertedToAValueNear(0.08333333, 7);
    assertThat<PhysicalQuantities::Length>("in", "yd").isConvertedToAValueNear(0.02777777, 7);
    assertThat<PhysicalQuantities::Length>("in", "mil").isConvertedToAValueNear(1.578283e-5, 7);
}

TEST(testLengthConversionFunctions, conversionsOfLengthFrom_ft)
{
    assertThat<PhysicalQuantities::Length>("ft", "m").isConvertedToAValueNear(0.3048, 7);
    assertThat<PhysicalQuantities::Length>("ft", "Ang").isConvertedToAValueNear(3.048e9, 7);
    assertThat<PhysicalQuantities::Length>("ft", "in").isConvertedToAValueNear(12.0, 7);
    assertThat<PhysicalQuantities::Length>("ft", "ft").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Length>("ft", "yd").isConvertedToAValueNear(0.3333333, 7);
    assertThat<PhysicalQuantities::Length>("ft", "mil").isConvertedToAValueNear(1.893939e-4, 7);
}

TEST(testLengthConversionFunctions, conversionsOfLengthFrom_yd)
{
    assertThat<PhysicalQuantities::Length>("yd", "m").isConvertedToAValueNear(0.9144002, 7);
    assertThat<PhysicalQuantities::Length>("yd", "Ang").isConvertedToAValueNear(9.144002e9, 7);
    assertThat<PhysicalQuantities::Length>("yd", "in").isConvertedToAValueNear(36.0, 7);
    assertThat<PhysicalQuantities::Length>("yd", "ft").isConvertedToAValueNear(3.0, 7);
    assertThat<PhysicalQuantities::Length>("yd", "yd").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Length>("yd", "mil").isConvertedToAValueNear(5.681820e-4, 7);
}

TEST(testLengthConversionFunctions, conversionsOfLengthFrom_mil)
{
    assertThat<PhysicalQuantities::Length>("mil", "m").isConvertedToAValueNear(1609.344, 7);
    assertThat<PhysicalQuantities::Length>("mil", "Ang").isConvertedToAValueNear(1.609344e13, 7);
    assertThat<PhysicalQuantities::Length>("mil", "in").isConvertedToAValueNear(6.336e4, 7);
    assertThat<PhysicalQuantities::Length>("mil", "ft").isConvertedToAValueNear(5280.00, 7);
    assertThat<PhysicalQuantities::Length>("mil", "yd").isConvertedToAValueNear(1760.0, 7);
    assertThat<PhysicalQuantities::Length>("mil", "mil").isConvertedTo(1.0);
}

#endif
