// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: testMathFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:58:59
// Description: Provides 100% unit test coverage over all math utility functions

#include <gtest/gtest.h>
#include "../../include/internal/Math/basicMath.hpp"
#include "../../include/internal/Math/statistics.hpp"
#include "../../include/internal/Math/calculus.hpp"

using namespace Utilities_API::Math;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testMathFunctions, withinRangeTest)
{
    int integerValue {10};
    double doubleValue {42.67};
    std::string stringValue {"Hello, World!"};

    ASSERT_TRUE(withinRange(integerValue, 5, 15));
    ASSERT_FALSE(withinRange(integerValue, 15, 20));

    ASSERT_TRUE(withinRange(doubleValue, 42.0, 42.75));
    ASSERT_FALSE(withinRange(doubleValue, 42.0, 42.5));

    ASSERT_TRUE(withinRange<std::string>(stringValue, "Hello", "This should be a longer string"));
    ASSERT_FALSE(withinRange<std::string>(stringValue, "This should be a longer string", "Hello"));

    // Testing the overloaded version of withinRange
    bool passingRangeTestForIntegers = withinRange<5, 15>(integerValue);
    bool failingRangeTestIntegers = withinRange<15, 20>(integerValue);
    bool passingRangeTestForDoubles = withinRange<42, 43>(doubleValue);
    bool failingRangeTestDoubles = withinRange<41, 42>(doubleValue);

    ASSERT_TRUE( passingRangeTestForIntegers );
    ASSERT_FALSE( failingRangeTestIntegers );

    ASSERT_TRUE( passingRangeTestForDoubles );
    ASSERT_FALSE( failingRangeTestDoubles );
}

TEST(testMathFunctions, statisticalTests)
{
    ASSERT_EQ(-15, findOrderOfMagnitude(1e-15));
    ASSERT_EQ(0, findOrderOfMagnitude(6.8));
    ASSERT_EQ(1, findOrderOfMagnitude(50));
    ASSERT_EQ(2, findOrderOfMagnitude(457));
    ASSERT_EQ(3, findOrderOfMagnitude(1000));
    ASSERT_EQ(18, findOrderOfMagnitude(1.7e18));

    // The fraction 355/113 is an approximation of pi accurate up to 6 decimal places
    ASSERT_NEAR(3.14159265, (355.0 / 113.0), findAbsoluteError(3.14159265, 7));


    // Test of the calculateAverage functionality
    std::vector<long double> x {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};
    ASSERT_EQ(5.5, calculateAverage(x));


    // Test of the averageCorrection functionality
    std::vector<long double> predictedValues {-4.5, -3.5, -2.5, -1.5,-0.5, 0.5, 1.5, 2.5, 3.5, 4.5};
    ASSERT_EQ(predictedValues, averageCorrection(x));


    // Test of the linearLeastSquaresFitting functionality
    std::vector<double> x_values { 1.0,  2.0,  3.0,  4.0,  5.0,  6.0,  7.0,  8.0,  9.0, 10.0};
    std::vector<double> y_values { 2.0,  4.0,  6.0,  8.0, 10.0, 12.0, 14.0, 16.0, 18.0, 20.0};

    std::map<std::string, double> parameters { linearLeastSquaresFitting<double>(x_values, y_values) };

    ASSERT_EQ(2.0, parameters["slope"]);
    ASSERT_EQ(0.0, parameters["intercept"]);
}

TEST(testMathFunctions, allOtherMathematicalTests)
{
    std::vector<long double> x;
    std::vector<long double> y;
    std::vector<long double> result;

    for (size_t i {}; i <= 10; ++i)
    {
        x.push_back(i);
        result.push_back( (x[i] * x[i]) / 2 );
    }

    // Linear interpolation of y along x
    y = linearlyInterpolate(x, 0, 10);
    ASSERT_EQ(y, x);


    // Integration of f(x) = x
    ASSERT_EQ(3.5, trapz(1, 2, 3, 4));
    ASSERT_EQ(50, trapz(0, 10, 0, 10));
    ASSERT_EQ(result, cumulativeTrapz(x, y));


    // Actual: d/dx (x) = 1
    std::vector<long double> centeredFDM1(11, 1);
    ASSERT_EQ(centeredFDM1, finiteDifferenceMethod(x, y));

    // Actual: d/dx (1/2 x^2) = x
    std::vector<long double> centeredFDM2 {0.5, 1, 2, 3, 4, 5, 6, 7, 8, 9, 9.5};
    ASSERT_EQ(centeredFDM2, finiteDifferenceMethod(x, result, "Centered"));

    std::vector<long double> nonCenteredFDM {0.5, 1.5, 2.5, 3.5, 4.5, 5.5, 6.5, 7.5, 8.5, 9.5};
    ASSERT_EQ(nonCenteredFDM, finiteDifferenceMethod(x, result, "Forward"));
    ASSERT_EQ(nonCenteredFDM, finiteDifferenceMethod(x, result, "Backward"));
}
