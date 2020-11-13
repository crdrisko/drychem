// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testPerformanceTesting.hpp
// Author: crdrisko
// Date: 10/21/2020-16:42:31
// Description: Provides ~100% unit test coverage over all performance testing functions

#ifndef DRYCHEM_COMMON_UTILITIES_TESTING_TESTPERFORMANCETESTING_HPP
#define DRYCHEM_COMMON_UTILITIES_TESTING_TESTPERFORMANCETESTING_HPP

#include <cstddef>

#include <gtest/gtest.h>

#include "common-utils/utilities.hpp"

namespace CppUtils::Testing::details::testing
{
    struct SumSquares
    {
        std::size_t operator()(std::size_t iter) const
        {
            std::size_t result {};

            for (std::size_t i {}; i < iter; ++i)
                result += i * i;

            return result;
        }
    };

    class MyClass
    {
    private:
        std::size_t iter {};

    public:
        explicit MyClass(std::size_t Iter) : iter {Iter} {}

        std::size_t sumSquares() const
        {
            std::size_t result {};

            for (std::size_t i {}; i < iter; ++i)
                result += i * i;

            return result;
        }
    };

    std::size_t sumSquares(std::size_t iter)
    {
        std::size_t result {};

        for (std::size_t i {}; i < iter; ++i)
            result += i * i;

        return result;
    }

    void voidSumSquares(std::size_t iter)
    {
        std::size_t result {};

        for (std::size_t i {}; i < iter; ++i)
            result += i * i;
    }
}   // namespace CppUtils::Testing::details::testing

GTEST_TEST(testPerformanceTesting, timeAndInvokeReturnsAReturnTypeStruct)
{
    using CppUtils::Testing::details::testing::sumSquares;

    std::size_t iterations {1'000'000UL};

    CppUtils::Testing::details::ReturnType ret = DryChem::timeAndInvoke(sumSquares, iterations);

    ASSERT_TRUE(ret.time >= 0);
    ASSERT_EQ(ret.result, 333'332'833'333'500'000ULL);
}

GTEST_TEST(testPerformanceTesting, timeAndInvokeWithAVoidFunctionReturnsOnlyTheTime)
{
    using CppUtils::Testing::details::testing::voidSumSquares;

    std::size_t iterations {1'000'000UL};

    auto time = DryChem::timeAndInvoke(voidSumSquares, iterations);

    ASSERT_TRUE(time >= 0);
}

GTEST_TEST(testPerformanceTesting, timeAndInvokeWithAFunctorReturnsResultAndTime)
{
    using CppUtils::Testing::details::testing::SumSquares;

    std::size_t iterations {1'000'000UL};

    auto [result, time] = DryChem::timeAndInvoke(SumSquares(), iterations);

    ASSERT_TRUE(time >= 0);
    ASSERT_EQ(result, 333'332'833'333'500'000ULL);
}

GTEST_TEST(testPerformanceTesting, timeAndInvokeWithAMemberFunctionReturnsResultAndTime)
{
    using CppUtils::Testing::details::testing::MyClass;

    std::size_t iterations {1'000'000UL};
    MyClass myClass {iterations};

    auto [result, time] = DryChem::timeAndInvoke(&MyClass::sumSquares, myClass);

    ASSERT_TRUE(time >= 0);
    ASSERT_EQ(result, 333'332'833'333'500'000ULL);
}

GTEST_TEST(testPerformanceTesting, timeAndInvokeWithAPlainFunctionReturnsResultAndTime)
{
    using CppUtils::Testing::details::testing::sumSquares;

    std::size_t iterations {1'000'000UL};

    auto [result, time] = DryChem::timeAndInvoke(sumSquares, iterations);

    ASSERT_TRUE(time >= 0);
    ASSERT_EQ(result, 333'332'833'333'500'000ULL);
}

GTEST_TEST(testPerformanceTesting, timeAndInvokeWithALambdaFunctionReturnsResultAndTime)
{
    using CppUtils::Testing::details::testing::sumSquares;

    std::size_t iterations {1'000'000UL};

    auto [result, time] = DryChem::timeAndInvoke([=]() { return sumSquares(iterations); });

    ASSERT_TRUE(time >= 0);
    ASSERT_EQ(result, 333'332'833'333'500'000ULL);
}

#endif
