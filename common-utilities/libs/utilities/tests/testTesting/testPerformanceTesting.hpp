// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testPerformanceTesting.hpp
// Author: crdrisko
// Date: 10/21/2020-16:42:31
// Description: Provides ~100% unit test coverage over all performance testing functions

#ifndef COMMON_UTILITIES_TESTING_TESTPERFORMANCETESTING_HPP
#define COMMON_UTILITIES_TESTING_TESTPERFORMANCETESTING_HPP

#include <cstddef>

#include <gtest/gtest.h>

#include "utilities.hpp"

using namespace CppUtils::Testing;

namespace CppUtils::Internal::Testing
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
}   // namespace CppUtils::Internal::Testing

//! \test Testing the \c CppUtils::Testing::ReturnType structure without structured binding
GTEST_TEST(testPerformanceTesting, timeAndInvokeReturnsAReturnTypeStruct)
{
    std::size_t iterations {1'000'000UL};

    ReturnType ret = timeAndInvoke(CppUtils::Internal::Testing::sumSquares, iterations);

    ASSERT_TRUE(ret.time >= 0);
    ASSERT_EQ(ret.result, 333'332'833'333'500'000ULL);
}

//! \test Testing the \c CppUtils::Testing::timeAndInvoke() function with a \c void input function
GTEST_TEST(testPerformanceTesting, timeAndInvokeWithAVoidFunctionReturnsOnlyTheTime)
{
    std::size_t iterations {1'000'000UL};

    auto time = timeAndInvoke(CppUtils::Internal::Testing::voidSumSquares, iterations);

    ASSERT_TRUE(time >= 0);
}

//! \test Testing the \c CppUtils::Testing::timeAndInvoke() function with a functor
GTEST_TEST(testPerformanceTesting, timeAndInvokeWithAFunctorReturnsResultAndTime)
{
    std::size_t iterations {1'000'000UL};

    auto [result, time] = timeAndInvoke(CppUtils::Internal::Testing::SumSquares(), iterations);

    ASSERT_TRUE(time >= 0);
    ASSERT_EQ(result, 333'332'833'333'500'000ULL);
}

//! \test Testing the \c CppUtils::Testing::timeAndInvoke() function with a member function
GTEST_TEST(testPerformanceTesting, timeAndInvokeWithAMemberFunctionReturnsResultAndTime)
{
    std::size_t iterations {1'000'000UL};
    CppUtils::Internal::Testing::MyClass myClass {iterations};

    auto [result, time] = timeAndInvoke(&CppUtils::Internal::Testing::MyClass::sumSquares, myClass);

    ASSERT_TRUE(time >= 0);
    ASSERT_EQ(result, 333'332'833'333'500'000ULL);
}

//! \test Testing the \c CppUtils::Testing::timeAndInvoke() function with a regular function
GTEST_TEST(testPerformanceTesting, timeAndInvokeWithAPlainFunctionReturnsResultAndTime)
{
    std::size_t iterations {1'000'000UL};

    auto [result, time] = timeAndInvoke(CppUtils::Internal::Testing::sumSquares, iterations);

    ASSERT_TRUE(time >= 0);
    ASSERT_EQ(result, 333'332'833'333'500'000ULL);
}

//! \test Testing the \c CppUtils::Testing::timeAndInvoke() function with a lambda function
GTEST_TEST(testPerformanceTesting, timeAndInvokeWithALambdaFunctionReturnsResultAndTime)
{
    std::size_t iterations {1'000'000UL};

    auto [result, time] = timeAndInvoke([=]() { return CppUtils::Internal::Testing::sumSquares(iterations); });

    ASSERT_TRUE(time >= 0);
    ASSERT_EQ(result, 333'332'833'333'500'000ULL);
}

#endif
