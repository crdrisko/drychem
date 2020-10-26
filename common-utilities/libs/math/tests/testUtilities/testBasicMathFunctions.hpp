// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testBasicMathFunctions.hpp
// Author: crdrisko
// Date: 09/28/2020-11:46:58
// Description: Provides ~100% unit test coverage over all basic mathematical functions

#ifndef COMMON_UTILITIES_TESTING_TESTBASICMATHFUNCTIONS_HPP
#define COMMON_UTILITIES_TESTING_TESTBASICMATHFUNCTIONS_HPP

#include <string>

#include <gtest/gtest.h>

#include "math.hpp"

using namespace CppUtils::Math;

GTEST_TEST(testBasicMathFunctions, isEvenReturnCorrectBooleansForIntegralTypes)
{
    bool bValue {false};
    char cValue {'2'};
    short sValue {4};
    int iValue {6};
    long lValue {8};
    long long llValue {10};

    ASSERT_TRUE(isEven(bValue));
    ASSERT_TRUE(isEven(cValue));
    ASSERT_TRUE(isEven(sValue));
    ASSERT_TRUE(isEven(iValue));
    ASSERT_TRUE(isEven(lValue));
    ASSERT_TRUE(isEven(llValue));

    ASSERT_FALSE(isEven(3));

    // ASSERT_TRUE(isEven(2.0));        // no instance of function template matches the argument list
}

GTEST_TEST(testBasicMathFunctions, isOddReturnCorrectBooleansForIntegralTypes)
{
    bool bValue {true};
    char cValue {'3'};
    short sValue {5};
    int iValue {7};
    long lValue {9};
    long long llValue {11};

    ASSERT_TRUE(isOdd(bValue));
    ASSERT_TRUE(isOdd(cValue));
    ASSERT_TRUE(isOdd(sValue));
    ASSERT_TRUE(isOdd(iValue));
    ASSERT_TRUE(isOdd(lValue));
    ASSERT_TRUE(isOdd(llValue));

    ASSERT_FALSE(isOdd(2));

    // ASSERT_TRUE(isOdd(3.0));        // no instance of function template matches the argument list
}

GTEST_TEST(testBasicMathFunctions, withinRangeFunctionalityWorksForIntegers)
{
    int integerValue {10};

    ASSERT_TRUE(withinRange(integerValue, 5, 15));
    ASSERT_FALSE(withinRange(integerValue, 15, 20));

    bool passingRangeTestForIntegers = withinRange<5, 15>(integerValue);
    bool failingRangeTestIntegers    = withinRange<15, 20>(integerValue);

    ASSERT_TRUE(passingRangeTestForIntegers);
    ASSERT_FALSE(failingRangeTestIntegers);
}

GTEST_TEST(testBasicMathFunctions, withinRangeFunctionalityWorksForDoubles)
{
    double doubleValue {42.67};

    ASSERT_TRUE(withinRange(doubleValue, 42.0, 42.75));
    ASSERT_FALSE(withinRange(doubleValue, 42.0, 42.5));

    bool passingRangeTestForDoubles = withinRange<42, 43>(doubleValue);
    bool failingRangeTestDoubles    = withinRange<41, 42>(doubleValue);

    ASSERT_TRUE(passingRangeTestForDoubles);
    ASSERT_FALSE(failingRangeTestDoubles);
}

GTEST_TEST(testBasicMathFunctions, withinRangeFunctionalityWorksForStrings)
{
    std::string stringValue {"How are you?"};

    ASSERT_TRUE(withinRange<std::string>(stringValue, "Hello", "What's new?"));
    ASSERT_FALSE(withinRange<std::string>(stringValue, "Hello", "Goodbye"));
}

GTEST_TEST(testBasicMathFunctions, linearInterpolationOf_y_along_x_gives_x)
{
    std::vector<long double> x;
    std::vector<long double> y;

    for (std::size_t i {}; i <= 10; ++i)
        x.push_back(i);

    y = linearlyInterpolate(x, 0.0l, 10.0l);

    ASSERT_EQ(x, y);
}

#endif