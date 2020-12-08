// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testPerformanceTesting.hpp
// Author: crdrisko
// Date: 10/21/2020-16:42:31
// Description: Provides ~100% unit test coverage over all performance testing functions

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_UTILITIES_TESTS_TESTTESTING_TESTPERFORMANCETESTING_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_UTILITIES_TESTS_TESTTESTING_TESTPERFORMANCETESTING_HPP

#include <cstddef>

#include <common-utils/utilities.hpp>
#include <gtest/gtest.h>

#include "../details/testingDetails.hpp"

GTEST_TEST(testPerformanceTesting, timeAndInvokeReturnsAReturnTypeStruct)
{
    using CppUtils::Testing::details::testing::sumSquares;

    std::size_t iterations {1'000};

    CppUtils::Testing::details::ReturnType ret = DryChem::timeAndInvoke(sumSquares, iterations);

    ASSERT_TRUE(ret.time >= 0);
    ASSERT_EQ(ret.result, 332'833'500ULL);
}

GTEST_TEST(testPerformanceTesting, timeAndInvokeWithAVoidFunctionReturnsOnlyTheTime)
{
    using CppUtils::Testing::details::testing::voidSumSquares;

    std::size_t iterations {1'000};

    auto time = DryChem::timeAndInvoke(voidSumSquares, iterations);

    ASSERT_TRUE(time >= 0);
}

GTEST_TEST(testPerformanceTesting, timeAndInvokeWithAFunctorReturnsResultAndTime)
{
    using CppUtils::Testing::details::testing::SumSquares;

    std::size_t iterations {1'000};

    auto [result, time] = DryChem::timeAndInvoke(SumSquares(), iterations);

    ASSERT_TRUE(time >= 0);
    ASSERT_EQ(result, 332'833'500ULL);
}

GTEST_TEST(testPerformanceTesting, timeAndInvokeWithAMemberFunctionReturnsResultAndTime)
{
    using CppUtils::Testing::details::testing::MyClass;

    std::size_t iterations {1'000};
    MyClass myClass {iterations};

    auto [result, time] = DryChem::timeAndInvoke(&MyClass::sumSquares, myClass);

    ASSERT_TRUE(time >= 0);
    ASSERT_EQ(result, 332'833'500ULL);
}

GTEST_TEST(testPerformanceTesting, timeAndInvokeWithAPlainFunctionReturnsResultAndTime)
{
    using CppUtils::Testing::details::testing::sumSquares;

    std::size_t iterations {1'000};

    auto [result, time] = DryChem::timeAndInvoke(sumSquares, iterations);

    ASSERT_TRUE(time >= 0);
    ASSERT_EQ(result, 332'833'500ULL);
}

GTEST_TEST(testPerformanceTesting, timeAndInvokeWithALambdaFunctionReturnsResultAndTime)
{
    using CppUtils::Testing::details::testing::sumSquares;

    std::size_t iterations {1'000};

    auto [result, time] = DryChem::timeAndInvoke([=]() { return sumSquares(iterations); });

    ASSERT_TRUE(time >= 0);
    ASSERT_EQ(result, 332'833'500ULL);
}

#endif
