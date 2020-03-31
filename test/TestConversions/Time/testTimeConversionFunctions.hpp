// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testTimeConversionFunctions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 03/06/2020-11:34:29
// Description: Provides 100% unit test coverage over all time conversion functions

#ifndef TESTTIMECONVERSIONFUNCTIONS_HPP
#define TESTTIMECONVERSIONFUNCTIONS_HPP

#include "../testAssertions.hpp"
#include "../../../include/cpp-units/physicalQuantities.hpp"

TEST(testTimeConversionFunctions, conversionsOfTimeFrom_s)
{
    assertThat<PhysicalQuantities::Time>("s", "s").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Time>("s", "min").isConvertedToAValueNear(0.01666666667, 10);
    assertThat<PhysicalQuantities::Time>("s", "hr").isConvertedToAValueNear(2.777777778e-4, 10);
    assertThat<PhysicalQuantities::Time>("s", "days").isConvertedToAValueNear(1.157407407e-5, 10);
    assertThat<PhysicalQuantities::Time>("s", "weeks").isConvertedToAValueNear(1.653439153e-6, 10);
    assertThat<PhysicalQuantities::Time>("s", "months").isConvertedToAValueNear(3.805175038e-7, 10);
    assertThat<PhysicalQuantities::Time>("s", "years").isConvertedToAValueNear(3.170577045e-8, 10);
}

TEST(testTimeConversionFunctions, conversionsOfTimeFrom_min)
{
    assertThat<PhysicalQuantities::Time>("min", "s").isConvertedTo(60.0);
    assertThat<PhysicalQuantities::Time>("min", "min").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Time>("min", "hr").isConvertedToAValueNear(0.01666666667, 10);
    assertThat<PhysicalQuantities::Time>("min", "days").isConvertedToAValueNear(6.944444444e-4, 10);
    assertThat<PhysicalQuantities::Time>("min", "weeks").isConvertedToAValueNear(9.920634921e-5, 10);
    assertThat<PhysicalQuantities::Time>("min", "months").isConvertedToAValueNear(2.283105023e-5, 10);
    assertThat<PhysicalQuantities::Time>("min", "years").isConvertedToAValueNear(1.902346227e-6, 10);
}

TEST(testTimeConversionFunctions, conversionsOfTimeFrom_hr)
{
    assertThat<PhysicalQuantities::Time>("hr", "s").isConvertedTo(3600.0);
    assertThat<PhysicalQuantities::Time>("hr", "min").isConvertedTo(60.0);
    assertThat<PhysicalQuantities::Time>("hr", "hr").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Time>("hr", "days").isConvertedToAValueNear(0.04166666667, 10);
    assertThat<PhysicalQuantities::Time>("hr", "weeks").isConvertedToAValueNear(5.952380952e-3, 10);
    assertThat<PhysicalQuantities::Time>("hr", "months").isConvertedToAValueNear(1.369863014e-3, 10);
    assertThat<PhysicalQuantities::Time>("hr", "years").isConvertedToAValueNear(1.141407736e-4, 10);
}

TEST(testTimeConversionFunctions, conversionsOfTimeFrom_days)
{
    assertThat<PhysicalQuantities::Time>("days", "s").isConvertedTo(8.64e4);
    assertThat<PhysicalQuantities::Time>("days", "min").isConvertedTo(1440.0);
    assertThat<PhysicalQuantities::Time>("days", "hr").isConvertedTo(24.0);
    assertThat<PhysicalQuantities::Time>("days", "days").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Time>("days", "weeks").isConvertedToAValueNear(0.1428571429, 10);
    assertThat<PhysicalQuantities::Time>("days", "months").isConvertedToAValueNear(0.03287671233, 10);
    assertThat<PhysicalQuantities::Time>("days", "years").isConvertedToAValueNear(2.739378567e-3, 10);
}

TEST(testTimeConversionFunctions, conversionsOfTimeFrom_weeks)
{
    assertThat<PhysicalQuantities::Time>("weeks", "s").isConvertedTo(6.048e5);
    assertThat<PhysicalQuantities::Time>("weeks", "min").isConvertedTo(1.008e4);
    assertThat<PhysicalQuantities::Time>("weeks", "hr").isConvertedTo(168.0);
    assertThat<PhysicalQuantities::Time>("weeks", "days").isConvertedTo(7.0);
    assertThat<PhysicalQuantities::Time>("weeks", "weeks").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Time>("weeks", "months").isConvertedToAValueNear(0.2301369863, 10);
    assertThat<PhysicalQuantities::Time>("weeks", "years").isConvertedToAValueNear(0.01917564997, 10);
}

TEST(testTimeConversionFunctions, conversionsOfTimeFrom_months)
{
    assertThat<PhysicalQuantities::Time>("months", "s").isConvertedTo(2.628e6);
    assertThat<PhysicalQuantities::Time>("months", "min").isConvertedTo(43'800.0);
    assertThat<PhysicalQuantities::Time>("months", "hr").isConvertedTo(730.0);
    assertThat<PhysicalQuantities::Time>("months", "days").isConvertedToAValueNear(30.41666667, 10);
    assertThat<PhysicalQuantities::Time>("months", "weeks").isConvertedToAValueNear(4.345238095, 10);
    assertThat<PhysicalQuantities::Time>("months", "months").isConvertedTo(1.0);
    assertThat<PhysicalQuantities::Time>("months", "years").isConvertedToAValueNear(0.08332276474, 10);
}

TEST(testTimeConversionFunctions, conversionsOfTimeFrom_years)
{
    assertThat<PhysicalQuantities::Time>("years", "s").isConvertedTo(3.154e7);
    assertThat<PhysicalQuantities::Time>("years", "min").isConvertedToAValueNear(5.256666667e5, 10);
    assertThat<PhysicalQuantities::Time>("years", "hr").isConvertedToAValueNear(8761.111111, 10);
    assertThat<PhysicalQuantities::Time>("years", "days").isConvertedToAValueNear(365.0462963, 10);
    assertThat<PhysicalQuantities::Time>("years", "weeks").isConvertedToAValueNear(52.14947090, 10);
    assertThat<PhysicalQuantities::Time>("years", "months").isConvertedToAValueNear(12.00152207, 10);
    assertThat<PhysicalQuantities::Time>("years", "years").isConvertedTo(1.0);
}

#endif
