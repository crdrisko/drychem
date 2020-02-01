// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testTimeConversionFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:03:54
// Description: Provides 100% unit test coverage over all time conversion functions

#include "../testAssertions.hpp"
#include "../../../src/include/internal/PhysicalQuantities/MKSQuantities/PhysicsQuantities/time.hpp"

using namespace Utilities_API::PhysicalQuantities;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

long double ConversionAssert::doConversion() const
{
    Time time(1.0);

    return (time.convertQuantity(Conversions::getTimeConversionFactor(initialUnits,
        finalUnits))).getMagnitude();
}

TEST(testTimeConversionFunctions, conversionsOfTimeFrom_s)
{
    assertThat("s", "s").isConvertedTo(1.0);
    assertThat("s", "min").isConvertedToAValueNear(0.01666666667, 10);
    assertThat("s", "hr").isConvertedToAValueNear(2.777777778e-4, 10);
    assertThat("s", "days").isConvertedToAValueNear(1.157407407e-5, 10);
    assertThat("s", "weeks").isConvertedToAValueNear(1.653439153e-6, 10);
    assertThat("s", "months").isConvertedToAValueNear(3.805175038e-7, 10);
    assertThat("s", "years").isConvertedToAValueNear(3.170577045e-8, 10);
}

TEST(testTimeConversionFunctions, conversionsOfTimeFrom_min)
{
    assertThat("min", "s").isConvertedTo(60.0);
    assertThat("min", "min").isConvertedTo(1.0);
    assertThat("min", "hr").isConvertedToAValueNear(0.01666666667, 10);
    assertThat("min", "days").isConvertedToAValueNear(6.944444444e-4, 10);
    assertThat("min", "weeks").isConvertedToAValueNear(9.920634921e-5, 10);
    assertThat("min", "months").isConvertedToAValueNear(2.283105023e-5, 10);
    assertThat("min", "years").isConvertedToAValueNear(1.902346227e-6, 10);
}

TEST(testTimeConversionFunctions, conversionsOfTimeFrom_hr)
{
    assertThat("hr", "s").isConvertedTo(3600.0);
    assertThat("hr", "min").isConvertedTo(60.0);
    assertThat("hr", "hr").isConvertedTo(1.0);
    assertThat("hr", "days").isConvertedToAValueNear(0.04166666667, 10);
    assertThat("hr", "weeks").isConvertedToAValueNear(5.952380952e-3, 10);
    assertThat("hr", "months").isConvertedToAValueNear(1.369863014e-3, 10);
    assertThat("hr", "years").isConvertedToAValueNear(1.141407736e-4, 10);
}

TEST(testTimeConversionFunctions, conversionsOfTimeFrom_days)
{
    assertThat("days", "s").isConvertedTo(8.64e4);
    assertThat("days", "min").isConvertedTo(1440.0);
    assertThat("days", "hr").isConvertedTo(24.0);
    assertThat("days", "days").isConvertedTo(1.0);
    assertThat("days", "weeks").isConvertedToAValueNear(0.1428571429, 10);
    assertThat("days", "months").isConvertedToAValueNear(0.03287671233, 10);
    assertThat("days", "years").isConvertedToAValueNear(2.739378567e-3, 10);
}

TEST(testTimeConversionFunctions, conversionsOfTimeFrom_weeks)
{
    assertThat("weeks", "s").isConvertedTo(6.048e5);
    assertThat("weeks", "min").isConvertedTo(1.008e4);
    assertThat("weeks", "hr").isConvertedTo(168.0);
    assertThat("weeks", "days").isConvertedTo(7.0);
    assertThat("weeks", "weeks").isConvertedTo(1.0);
    assertThat("weeks", "months").isConvertedToAValueNear(0.2301369863, 10);
    assertThat("weeks", "years").isConvertedToAValueNear(0.01917564997, 10);
}

TEST(testTimeConversionFunctions, conversionsOfTimeFrom_months)
{
    assertThat("months", "s").isConvertedTo(2.628e6);
    assertThat("months", "min").isConvertedTo(43'800.0);
    assertThat("months", "hr").isConvertedTo(730.0);
    assertThat("months", "days").isConvertedToAValueNear(30.41666667, 10);
    assertThat("months", "weeks").isConvertedToAValueNear(4.345238095, 10);
    assertThat("months", "months").isConvertedTo(1.0);
    assertThat("months", "years").isConvertedToAValueNear(0.08332276474, 10);
}

TEST(testTimeConversionFunctions, conversionsOfTimeFrom_years)
{
    assertThat("years", "s").isConvertedTo(3.154e7);
    assertThat("years", "min").isConvertedToAValueNear(5.256666667e5, 10);
    assertThat("years", "hr").isConvertedToAValueNear(8761.111111, 10);
    assertThat("years", "days").isConvertedToAValueNear(365.0462963, 10);
    assertThat("years", "weeks").isConvertedToAValueNear(52.14947090, 10);
    assertThat("years", "months").isConvertedToAValueNear(12.00152207, 10);
    assertThat("years", "years").isConvertedTo(1.0);
}
