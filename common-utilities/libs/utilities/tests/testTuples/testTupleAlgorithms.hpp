// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testTupleAlgorithms.hpp
// Author: crdrisko
// Date: 01/06/2021-10:57:07
// Description: Provides ~100% unit test coverage over all tuple algorithms

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_UTILITIES_TESTS_TESTTUPLES_TESTTUPLEALGORITHMS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_UTILITIES_TESTS_TESTTUPLES_TESTTUPLEALGORITHMS_HPP

#include <iostream>
#include <string>
#include <tuple>

#include <common-utils/utilities.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testTupleAlgorithms, theApplyNAlgorithmAppliesAFunctionToTheFirstNElementsOfATuple)
{
    testing::internal::CaptureStdout();

    std::tuple tup1 {"Hello, World!", 12.3, 6, std::string {"A string"}};

    DryChem::apply_n<2>([&](auto... elem) { ((std::cout << elem << std::endl), ...); }, tup1);

    std::string output = testing::internal::GetCapturedStdout();
    ASSERT_EQ(output, "Hello, World!\n12.3\n");
}

GTEST_TEST(testTupleAlgorithms, theSelectAlgorithmShufflesATupleBasedOnTheOrderingOfAnIndexList)
{
    std::tuple tuple {std::string {"Hello, World!"}, 12.3, 6, std::string {"A string"}, true};

    auto shuffledTuple = DryChem::select(tuple, std::index_sequence<1, 4, 0, 3> {});

    std::tuple expectedTuple {12.3, true, std::string {"Hello, World!"}, std::string {"A string"}};

    ASSERT_EQ(shuffledTuple, expectedTuple);
}

#endif
