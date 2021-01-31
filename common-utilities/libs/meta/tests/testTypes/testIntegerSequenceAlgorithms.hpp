// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testIntegerSequenceAlgorithms.hpp
// Author: crdrisko
// Date: 01/23/2021-08:09:51
// Description: Provides ~100% unit test coverage over all std::integer_sequence<> algorithms

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_META_TESTS_TESTTYPES_TESTINTEGERSEQUENCEALGORITHMS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_META_TESTS_TESTTYPES_TESTINTEGERSEQUENCEALGORITHMS_HPP

#include <cstddef>
#include <type_traits>
#include <utility>

#include <common-utils/meta.hpp>
#include <gtest/gtest.h>

GTEST_TEST(testIntegerSequenceAlgorithms, theFrontListAlgorithmReturnsTheFirstElementOfAnIntegerSequence)
{
    using ExpectedResult         = std::integral_constant<std::size_t, 5>;
    using ActualResultSimplified = DryChem::front_list_t<std::index_sequence<5, 10, 15, 20, 25>>;
    using ActualResultExplicit   = typename DryChem::front_list<std::index_sequence<5, 10, 15, 20, 25>>::type;

    GTEST_COMPILE_ASSERT_((ExpectedResult {} == ActualResultSimplified {}),
        "front_list_t did not return the first element of the index_sequence.");

    GTEST_COMPILE_ASSERT_((ExpectedResult {} == ActualResultExplicit {}),
        "front_list did not return the first element of the index_sequence.");
}

GTEST_TEST(testIntegerSequenceAlgorithms, theIsEmptyAlgorithmChecksIfAnIntegerSequenceIsEmpty)
{
    using EmptyList    = std::index_sequence<>;
    using NonEmptyList = std::index_sequence<5, 10, 15, 20, 25>;

    GTEST_COMPILE_ASSERT_((!DryChem::is_empty_list_v<NonEmptyList>), "is_empty_list_v was not false on a non-empty list.");
    GTEST_COMPILE_ASSERT_(
        (!DryChem::is_empty_list<NonEmptyList>::value), "is_empty_list was not false on a non-empty list.");

    GTEST_COMPILE_ASSERT_((DryChem::is_empty_list_v<EmptyList>), "is_empty_list_v was not true on an empty list.");
    GTEST_COMPILE_ASSERT_((DryChem::is_empty_list<EmptyList>::value), "is_empty_list was not true on an empty list.");
}

GTEST_TEST(testIntegerSequenceAlgorithms, thePopFrontAlgorithmRemovesAnElementFromTheFrontOfAnIntegerSequence)
{
    using ExpectedResult         = std::index_sequence<10, 15, 20, 25>;
    using ActualResultSimplified = DryChem::pop_front_list_t<std::index_sequence<5, 10, 15, 20, 25>>;
    using ActualResultExplicit   = typename DryChem::pop_front_list<std::index_sequence<5, 10, 15, 20, 25>>::type;

    GTEST_COMPILE_ASSERT_((std::is_same_v<ExpectedResult, ActualResultSimplified>),
        "pop_front_list_t did not remove the first element of the index_sequence.");

    GTEST_COMPILE_ASSERT_((std::is_same_v<ExpectedResult, ActualResultExplicit>),
        "pop_front_list did not remove the first element of the index_sequence.");
}

GTEST_TEST(testIntegerSequenceAlgorithms, thePushBackAlgorithmAddsANewElementToTheBackOfAnIntegerSequence)
{
    using CT30                   = std::integral_constant<std::size_t, 30>;
    using ExpectedResult         = std::index_sequence<5, 10, 15, 20, 25, 30>;
    using ActualResultSimplified = DryChem::push_back_list_t<std::index_sequence<5, 10, 15, 20, 25>, CT30>;
    using ActualResultExplicit   = typename DryChem::push_back_list<std::index_sequence<5, 10, 15, 20, 25>, CT30>::type;

    GTEST_COMPILE_ASSERT_((std::is_same_v<ExpectedResult, ActualResultSimplified>),
        "push_back_list_t did not add a new element to the back of the index_sequence.");

    GTEST_COMPILE_ASSERT_((std::is_same_v<ExpectedResult, ActualResultExplicit>),
        "push_back_list did not add a new element to the back of the index_sequence.");
}

GTEST_TEST(testIntegerSequenceAlgorithms, thePushFrontAlgorithmAddsANewElementToTheFrontOfAnIntegerSequence)
{
    using CT0                    = std::integral_constant<std::size_t, 0>;
    using ExpectedResult         = std::index_sequence<0, 5, 10, 15, 20, 25>;
    using ActualResultSimplified = DryChem::push_front_list_t<std::index_sequence<5, 10, 15, 20, 25>, CT0>;
    using ActualResultExplicit   = typename DryChem::push_front_list<std::index_sequence<5, 10, 15, 20, 25>, CT0>::type;

    GTEST_COMPILE_ASSERT_((std::is_same_v<ExpectedResult, ActualResultSimplified>),
        "push_front_list_t did not add a new element to the front of the index_sequence.");

    GTEST_COMPILE_ASSERT_((std::is_same_v<ExpectedResult, ActualResultExplicit>),
        "push_front_list did not add a new element to the front of the index_sequence.");
}

GTEST_TEST(testIntegerSequenceAlgorithms, theReverseAlgorithmReversesTheSuppliedIntegerSequence)
{
    using ExpectedResult         = std::index_sequence<25, 20, 15, 10, 5>;
    using ActualResultSimplified = DryChem::reverse_list_t<std::index_sequence<5, 10, 15, 20, 25>>;
    using ActualResultExplicit   = typename DryChem::reverse_list<std::index_sequence<5, 10, 15, 20, 25>>::type;

    GTEST_COMPILE_ASSERT_(
        (std::is_same_v<ExpectedResult, ActualResultSimplified>), "reverse_list_t did not reverse the index_sequence.");

    GTEST_COMPILE_ASSERT_(
        (std::is_same_v<ExpectedResult, ActualResultExplicit>), "reverse_list did not reverse the index_sequence.");
}

#endif
