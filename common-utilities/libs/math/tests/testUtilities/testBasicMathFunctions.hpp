// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testBasicMathFunctions.hpp
// Author: crdrisko
// Date: 09/28/2020-11:46:58
// Description: Provides ~100% unit test coverage over all basic mathematical functions

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_MATH_TESTS_TESTUTILITIES_TESTBASICMATHFUNCTIONS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_MATH_TESTS_TESTUTILITIES_TESTBASICMATHFUNCTIONS_HPP

#include <cstddef>
#include <string>
#include <vector>

#include <common-utils/math.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testBasicMathFunctions, isEvenReturnCorrectBooleansForIntegralTypes)
{
    char cValue {'2'};
    short sValue {4};
    int iValue {6};
    long lValue {8};
    long long llValue {10};

    ASSERT_TRUE(DryChem::isEven(cValue));
    ASSERT_TRUE(DryChem::isEven(sValue));
    ASSERT_TRUE(DryChem::isEven(iValue));
    ASSERT_TRUE(DryChem::isEven(lValue));
    ASSERT_TRUE(DryChem::isEven(llValue));

    ASSERT_FALSE(DryChem::isEven(3));

    // ASSERT_TRUE(DryChem::isEven(false));         // no instance of function template matches the argument list
    // ASSERT_TRUE(DryChem::isEven(2.0));           // no instance of function template matches the argument list
}

GTEST_TEST(testBasicMathFunctions, isOddReturnCorrectBooleansForIntegralTypes)
{
    char cValue {'3'};
    short sValue {5};
    int iValue {7};
    long lValue {9};
    long long llValue {11};

    ASSERT_TRUE(DryChem::isOdd(cValue));
    ASSERT_TRUE(DryChem::isOdd(sValue));
    ASSERT_TRUE(DryChem::isOdd(iValue));
    ASSERT_TRUE(DryChem::isOdd(lValue));
    ASSERT_TRUE(DryChem::isOdd(llValue));

    ASSERT_FALSE(DryChem::isOdd(2));

    // ASSERT_TRUE(DryChem::isOdd(true));           // no instance of function template matches the argument list
    // ASSERT_TRUE(DryChem::isOdd(3.0));            // no instance of function template matches the argument list
}

GTEST_TEST(testBasicMathFunctions, withinRangeFunctionalityWorksForIntegers)
{
    int integerValue {10};

    ASSERT_TRUE(DryChem::withinRange(integerValue, 5, 15));
    ASSERT_FALSE(DryChem::withinRange(integerValue, 15, 20));

    bool passingRangeTestForIntegers = DryChem::withinRange<5, 15>(integerValue);
    bool failingRangeTestIntegers    = DryChem::withinRange<15, 20>(integerValue);

    ASSERT_TRUE(passingRangeTestForIntegers);
    ASSERT_FALSE(failingRangeTestIntegers);
}

GTEST_TEST(testBasicMathFunctions, withinRangeFunctionalityWorksForDoubles)
{
    double doubleValue {42.67};

    ASSERT_TRUE(DryChem::withinRange(doubleValue, 42.0, 42.75));
    ASSERT_FALSE(DryChem::withinRange(doubleValue, 42.0, 42.5));

    bool passingRangeTestForDoubles = DryChem::withinRange<42, 43>(doubleValue);
    bool failingRangeTestDoubles    = DryChem::withinRange<41, 42>(doubleValue);

    ASSERT_TRUE(passingRangeTestForDoubles);
    ASSERT_FALSE(failingRangeTestDoubles);
}

GTEST_TEST(testBasicMathFunctions, withinRangeFunctionalityWorksForStrings)
{
    std::string stringValue {"How are you?"};

    ASSERT_TRUE(DryChem::withinRange<std::string>(stringValue, "Hello", "What's new?"));
    ASSERT_FALSE(DryChem::withinRange<std::string>(stringValue, "Hello", "Goodbye"));
}

GTEST_TEST(testBasicMathFunctions, linearInterpolationOf_y_along_x_gives_x)
{
    std::vector<long double> x;
    std::vector<long double> y;

    for (std::size_t i {}; i <= 10; ++i)
        x.push_back(static_cast<long double>(i));

    y = DryChem::linearlyInterpolate(x, 0.0l, 10.0l);

    ASSERT_EQ(x, y);
}

#endif
