// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testMathFunctions.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:58:59
// Description: Provides ~100% unit test coverage over all math utility functions

#include <map>
#include <memory>
#include <string>
#include <vector>

#include <gtest/gtest.h>

#include "../../include/common-utils/math.hpp"

using namespace CommonUtilities::Math;

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

GTEST_TEST(testMathFunctions, withinRangeFunctionalityWorksForIntegers)
{
    int integerValue {10};

    ASSERT_TRUE(withinRange(integerValue, 5, 15));
    ASSERT_FALSE(withinRange(integerValue, 15, 20));

    bool passingRangeTestForIntegers = withinRange<5, 15>(integerValue);
    bool failingRangeTestIntegers = withinRange<15, 20>(integerValue);

    ASSERT_TRUE(passingRangeTestForIntegers);
    ASSERT_FALSE(failingRangeTestIntegers);
}

GTEST_TEST(testMathFunctions, withinRangeFunctionalityWorksForDoubles)
{
    double doubleValue {42.67};

    ASSERT_TRUE(withinRange(doubleValue, 42.0, 42.75));
    ASSERT_FALSE(withinRange(doubleValue, 42.0, 42.5));

    bool passingRangeTestForDoubles = withinRange<42, 43>(doubleValue);
    bool failingRangeTestDoubles = withinRange<41, 42>(doubleValue);

    ASSERT_TRUE(passingRangeTestForDoubles);
    ASSERT_FALSE(failingRangeTestDoubles);
}

GTEST_TEST(testMathFunctions, withinRangeFunctionalityWorksForStrings)
{
    std::string stringValue {"Hello, World!"};

    ASSERT_TRUE(withinRange<std::string>(stringValue, "Hello", "This should be a longer string"));
    ASSERT_FALSE(withinRange<std::string>(stringValue, "This should be a longer string", "Hello"));
}

GTEST_TEST(testMathFunctions, linearInterpolationOf_y_along_x_gives_x)
{
    std::vector<long double> x;

    for (std::size_t i {}; i <= 10; ++i)
        x.push_back(i);

    ASSERT_EQ(x, linearlyInterpolate(x, 0.0L, 10.0L));
}

GTEST_TEST(testMathFunctions, differentiationAndIntegrationWithAdvancedMath)
{
    std::vector<long double> x;
    std::vector<long double> y;
    std::vector<long double> expectedResult;

    for (std::size_t i {}; i <= 10; ++i)
    {
        x.push_back(i);
        expectedResult.push_back( (x[i] * x[i]) / 2 );
    }

    y = linearlyInterpolate(x, 0.0L, 10.0L);


    // Integration of f(x) = x
    AdvancedMathPtr mathematicalFunction { std::make_shared<CumulativeTrapzIntegration>(x, y) };

    ASSERT_EQ( expectedResult, mathematicalFunction->doCalculation() );


    // Actual: d/dx (x) = 1
    std::vector<long double> centeredFDM1(11, 1);
    mathematicalFunction = std::make_shared<CenteredDifferenceMethod>(x, y);

    ASSERT_EQ( centeredFDM1, mathematicalFunction->doCalculation() );


    // Actual: d/dx (1/2 x^2) = x
    std::vector<long double> centeredFDM2 {0.5, 1, 2, 3, 4, 5, 6, 7, 8, 9, 9.5};
    mathematicalFunction = std::make_shared<CenteredDifferenceMethod>(x, expectedResult);

    ASSERT_EQ( centeredFDM2, mathematicalFunction->doCalculation() );
}

GTEST_TEST(testMathFunctions, orderOfMagnitudeIsCalculatedCorrectly)
{
    ASSERT_EQ(-15, findOrderOfMagnitude(1e-15));
    ASSERT_EQ(0, findOrderOfMagnitude(6.8));
    ASSERT_EQ(1, findOrderOfMagnitude(50));
    ASSERT_EQ(2, findOrderOfMagnitude(457));
    ASSERT_EQ(3, findOrderOfMagnitude(1000));
    ASSERT_EQ(18, findOrderOfMagnitude(1.7e18));
}

GTEST_TEST(testMathFunctions, _355_over_113_isAnApproximationOfPi)
{
    ASSERT_NEAR(3.14159265, (355.0 / 113.0), findAbsoluteError(3.14159265, 7));
}

GTEST_TEST(testMathFunctions, averageAndStandardDeviationOfAVector)
{
    std::vector<long double> x {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0};

    ASSERT_EQ(5.5, calculateAverage(x));
    ASSERT_NEAR(3.027650, calculateStandardDeviation(x), findAbsoluteError(3.027650, 7));
}

GTEST_TEST(testMathFunctions, linearLeastSquaresFittingResultingInVector)
{
    std::vector<long double> x { 1.0,  2.0,  3.0,  4.0,  5.0,  6.0,  7.0,  8.0,  9.0, 10.0 };
    std::vector<long double> y { 2.0,  5.0,  3.0,  7.0,  8.0,  9.0, 12.0, 10.0, 15.0, 20.0 };

    AdvancedMathPtr mathematicalFunction { std::make_shared<LinearLeastSquaresFitting>(x, y) };

    std::vector<long double> fittingResult { mathematicalFunction->doCalculation() };

    ASSERT_NEAR(1.7152, fittingResult[0], findAbsoluteError(1.7152, 5));
    ASSERT_NEAR(-0.33333, fittingResult[1], findAbsoluteError(-0.33333, 5));
    ASSERT_NEAR(0.2139317, fittingResult[2], findAbsoluteError(0.2139317, 7));
}

GTEST_TEST(testMathFunctions, linearLeastSquaresFittingResultingInMap)
{
    std::vector<long double> x { 1.0,  2.0,  3.0,  4.0,  5.0,  6.0,  7.0,  8.0,  9.0, 10.0 };
    std::vector<long double> y { 2.0,  5.0,  3.0,  7.0,  8.0,  9.0, 12.0, 10.0, 15.0, 20.0 };

    LinearLeastSquaresFitting mathematicalFunction {x, y};

    std::map<std::string, long double> parameters
        = mathematicalFunction.mapFittingParametersToLabels( mathematicalFunction.doCalculation() );

    ASSERT_NEAR(1.7152, parameters["slope"], findAbsoluteError(1.7152, 5));
    ASSERT_NEAR(-0.33333, parameters["intercept"], findAbsoluteError(-0.33333, 5));
    ASSERT_NEAR(0.2139317, parameters["stdDev(slope)"], findAbsoluteError(0.2139317, 7));
}

GTEST_TEST(testMathFunctions, vectorsOfUnequalSizesThrowAndCatchExceptions)
{
    std::vector<long double> x { 1.0,  2.0,  3.0,  4.0,  5.0,  6.0,  7.0,  8.0,  9.0, 10.0 };
    std::vector<long double> y { 2.0,  5.0,  3.0,  7.0,  8.0,  9.0, 12.0, 10.0, 15.0 };

    ASSERT_DEATH(
    {
        auto mathematicalFunction = std::make_shared<LinearLeastSquaresFitting>(x, y);
    }, "Common-Utilities Fatal Error:\n\tThe size of the x and y vectors must be equal.\n");


    y.push_back(20.0);
    LinearLeastSquaresFitting fittingMathematicalFunction {x, y};

    ASSERT_DEATH(
    {
        auto fittingParameters = fittingMathematicalFunction.mapFittingParametersToLabels(x);
    }, "Common-Utilities Fatal Error:\n\tThe size of input vector must be equal to 3\n");
}
