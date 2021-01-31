// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testTupleAlgorithms.hpp
// Author: crdrisko
// Date: 01/06/2021-10:57:07
// Description: Provides ~100% unit test coverage over all tuple algorithms

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_META_TESTS_TESTTYPES_TESTTUPLEALGORITHMS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_META_TESTS_TESTTYPES_TESTTUPLEALGORITHMS_HPP

#include <iostream>
#include <string>
#include <tuple>
#include <utility>

#include <common-utils/meta.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testTupleAlgorithms, theFrontAlgorithmReturnsTheFirstElementOfATuple)
{
    std::tuple tuple {std::string {"Hello, World!"}, 12.3, 6, std::string {"A string"}, true};

    auto front = DryChem::front(tuple);

    ASSERT_EQ(front, std::string {"Hello, World!"});
}

GTEST_TEST(testTupleAlgorithms, theIsEmptyAlgorithmChecksIfATupleIsEmpty)
{
    std::tuple tuple {std::string {"Hello, World!"}, 12.3, 6, std::string {"A string"}, true};
    std::tuple emptyTuple {};

    ASSERT_TRUE(DryChem::is_empty(emptyTuple));
    ASSERT_FALSE(DryChem::is_empty(tuple));
}

GTEST_TEST(testTupleAlgorithms, thePopFrontAlgorithmRemovesAnElementFromTheFrontOfATuple)
{
    std::tuple tuple {std::string {"Hello, World!"}, 12.3, 6, std::string {"A string"}, true};

    auto newTuple = DryChem::pop_front(tuple);

    std::tuple expectedTuple {12.3, 6, std::string {"A string"}, true};

    ASSERT_EQ(newTuple, expectedTuple);
}

GTEST_TEST(testTupleAlgorithms, thePushBackAlgorithmAddsANewElementToTheBackOfATuple)
{
    std::tuple tuple {std::string {"Hello, World!"}, 12.3, 6, std::string {"A string"}, true};

    auto newTuple = DryChem::push_back(tuple, 1.267e-4l);

    std::tuple expectedTuple {std::string {"Hello, World!"}, 12.3, 6, std::string {"A string"}, true, 1.267e-4l};

    ASSERT_EQ(newTuple, expectedTuple);
}

GTEST_TEST(testTupleAlgorithms, thePushFrontAlgorithmAddsANewElementToTheFrontOfATuple)
{
    std::tuple tuple {std::string {"Hello, World!"}, 12.3, 6, std::string {"A string"}, true};

    auto newTuple = DryChem::push_front(tuple, 1.267e-4l);

    std::tuple expectedTuple {1.267e-4l, std::string {"Hello, World!"}, 12.3, 6, std::string {"A string"}, true};

    ASSERT_EQ(newTuple, expectedTuple);
}

GTEST_TEST(testTupleAlgorithms, theApplyNAlgorithmAppliesAFunctionToTheFirstNElementsOfATuple)
{
    testing::internal::CaptureStdout();

    std::tuple tuple {std::string {"Hello, World!"}, 12.3, 6, std::string {"A string"}, true};

    DryChem::apply_n<2>([&](auto... elem) { ((std::cout << elem << std::endl), ...); }, tuple);

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Hello, World!\n12.3\n");
}

GTEST_TEST(testTupleAlgorithms, theReverseAlgorithmReversesTheSuppliedTuple)
{
    std::tuple tuple {std::string {"Hello, World!"}, 12.3, 6, std::string {"A string"}, true};

    auto newTuple = DryChem::reverse(tuple);

    std::tuple expectedTuple {true, std::string {"A string"}, 6, 12.3, std::string {"Hello, World!"}};

    ASSERT_EQ(newTuple, expectedTuple);
}

GTEST_TEST(testTupleAlgorithms, theSelectAlgorithmShufflesATupleBasedOnTheOrderingOfAnIndexList)
{
    std::tuple tuple {std::string {"Hello, World!"}, 12.3, 6, std::string {"A string"}, true};

    auto newTuple = DryChem::select(tuple, std::index_sequence<1, 4, 0, 3> {});

    std::tuple expectedTuple {12.3, true, std::string {"Hello, World!"}, std::string {"A string"}};

    ASSERT_EQ(newTuple, expectedTuple);
}

#endif
