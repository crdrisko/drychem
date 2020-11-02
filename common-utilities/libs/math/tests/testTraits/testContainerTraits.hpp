// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: testContainerTraits.hpp
// Author: crdrisko
// Date: 09/22/2020-13:02:50
// Description: Provides ~100% unit test coverage over all type traits relating to the classification of containers

#ifndef COMMON_UTILITIES_TESTING_TESTCONTAINERTRAITS_HPP
#define COMMON_UTILITIES_TESTING_TESTCONTAINERTRAITS_HPP

#include <array>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <gtest/gtest.h>

#include "math.hpp"

using namespace CppUtils::Math;

GTEST_TEST(testContainerTraits, allContainersButStdArrayAreAllocatorAwareContainers)
{
    ASSERT_TRUE((is_allocator_aware_container<std::deque<int>>::value));
    ASSERT_TRUE((is_allocator_aware_container<std::forward_list<int>>::value));
    ASSERT_TRUE((is_allocator_aware_container<std::list<int>>::value));
    ASSERT_TRUE((is_allocator_aware_container<std::map<int, int>>::value));
    ASSERT_TRUE((is_allocator_aware_container<std::multimap<int, int>>::value));
    ASSERT_TRUE((is_allocator_aware_container<std::multiset<int>>::value));
    ASSERT_TRUE((is_allocator_aware_container<std::set<int>>::value));
    ASSERT_TRUE((is_allocator_aware_container<std::string>::value));
    ASSERT_TRUE((is_allocator_aware_container<std::unordered_map<int, int>>::value));
    ASSERT_TRUE((is_allocator_aware_container<std::unordered_multimap<int, int>>::value));
    ASSERT_TRUE((is_allocator_aware_container<std::unordered_multiset<int>>::value));
    ASSERT_TRUE((is_allocator_aware_container<std::unordered_set<int>>::value));
    ASSERT_TRUE((is_allocator_aware_container<std::vector<int>>::value));

    ASSERT_FALSE((is_allocator_aware_container<std::array<int, 3>>::value));
    ASSERT_FALSE((is_allocator_aware_container<std::priority_queue<int>>::value));
    ASSERT_FALSE((is_allocator_aware_container<std::queue<int>>::value));
    ASSERT_FALSE((is_allocator_aware_container<std::stack<int>>::value));
}

GTEST_TEST(testContainerTraits, onlyOrderedMapsAndSetsAreAssociativeContainers)
{
    ASSERT_TRUE((is_associative_container<std::map<int, int>>::value));
    ASSERT_TRUE((is_associative_container<std::multimap<int, int>>::value));
    ASSERT_TRUE((is_associative_container<std::multiset<int>>::value));
    ASSERT_TRUE((is_associative_container<std::set<int>>::value));

    ASSERT_FALSE((is_associative_container<std::array<int, 3>>::value));
    ASSERT_FALSE((is_associative_container<std::deque<int>>::value));
    ASSERT_FALSE((is_associative_container<std::forward_list<int>>::value));
    ASSERT_FALSE((is_associative_container<std::list<int>>::value));
    ASSERT_FALSE((is_associative_container<std::priority_queue<int>>::value));
    ASSERT_FALSE((is_associative_container<std::queue<int>>::value));
    ASSERT_FALSE((is_associative_container<std::stack<int>>::value));
    ASSERT_FALSE((is_associative_container<std::string>::value));
    ASSERT_FALSE((is_associative_container<std::unordered_map<int, int>>::value));
    ASSERT_FALSE((is_associative_container<std::unordered_multimap<int, int>>::value));
    ASSERT_FALSE((is_associative_container<std::unordered_multiset<int>>::value));
    ASSERT_FALSE((is_associative_container<std::unordered_set<int>>::value));
    ASSERT_FALSE((is_associative_container<std::vector<int>>::value));
}

GTEST_TEST(testContainerTraits, allStdContainersAreContainers)
{
    ASSERT_TRUE((is_container<std::array<int, 3>>::value));
    ASSERT_TRUE((is_container<std::deque<int>>::value));
    ASSERT_TRUE((is_container<std::forward_list<int>>::value));
    ASSERT_TRUE((is_container<std::list<int>>::value));
    ASSERT_TRUE((is_container<std::map<int, int>>::value));
    ASSERT_TRUE((is_container<std::multimap<int, int>>::value));
    ASSERT_TRUE((is_container<std::multiset<int>>::value));
    ASSERT_TRUE((is_container<std::set<int>>::value));
    ASSERT_TRUE((is_container<std::string>::value));
    ASSERT_TRUE((is_container<std::unordered_map<int, int>>::value));
    ASSERT_TRUE((is_container<std::unordered_multimap<int, int>>::value));
    ASSERT_TRUE((is_container<std::unordered_multiset<int>>::value));
    ASSERT_TRUE((is_container<std::unordered_set<int>>::value));
    ASSERT_TRUE((is_container<std::vector<int>>::value));

    ASSERT_FALSE((is_container<std::priority_queue<int>>::value));
    ASSERT_FALSE((is_container<std::queue<int>>::value));
    ASSERT_FALSE((is_container<std::stack<int>>::value));
}

GTEST_TEST(testContainerTraits, containerAdaptersRequireAWrappedContainerType)
{
    ASSERT_TRUE((is_container_adapter<std::priority_queue<int>>::value));
    ASSERT_TRUE((is_container_adapter<std::queue<int>>::value));
    ASSERT_TRUE((is_container_adapter<std::stack<int>>::value));

    ASSERT_FALSE((is_container_adapter<std::array<int, 3>>::value));
    ASSERT_FALSE((is_container_adapter<std::deque<int>>::value));
    ASSERT_FALSE((is_container_adapter<std::forward_list<int>>::value));
    ASSERT_FALSE((is_container_adapter<std::list<int>>::value));
    ASSERT_FALSE((is_container_adapter<std::map<int, int>>::value));
    ASSERT_FALSE((is_container_adapter<std::multimap<int, int>>::value));
    ASSERT_FALSE((is_container_adapter<std::multiset<int>>::value));
    ASSERT_FALSE((is_container_adapter<std::set<int>>::value));
    ASSERT_FALSE((is_container_adapter<std::string>::value));
    ASSERT_FALSE((is_container_adapter<std::unordered_map<int, int>>::value));
    ASSERT_FALSE((is_container_adapter<std::unordered_multimap<int, int>>::value));
    ASSERT_FALSE((is_container_adapter<std::unordered_multiset<int>>::value));
    ASSERT_FALSE((is_container_adapter<std::unordered_set<int>>::value));
    ASSERT_FALSE((is_container_adapter<std::vector<int>>::value));
}

GTEST_TEST(testContainerTraits, almostAllStandardContainersAreReversible)
{
    ASSERT_TRUE((is_reversible_container<std::array<int, 3>>::value));
    ASSERT_TRUE((is_reversible_container<std::deque<int>>::value));
    ASSERT_TRUE((is_reversible_container<std::list<int>>::value));
    ASSERT_TRUE((is_reversible_container<std::map<int, int>>::value));
    ASSERT_TRUE((is_reversible_container<std::multimap<int, int>>::value));
    ASSERT_TRUE((is_reversible_container<std::multiset<int>>::value));
    ASSERT_TRUE((is_reversible_container<std::set<int>>::value));
    ASSERT_TRUE((is_reversible_container<std::string>::value));
    ASSERT_TRUE((is_reversible_container<std::vector<int>>::value));

    ASSERT_FALSE((is_reversible_container<std::forward_list<int>>::value));
    ASSERT_FALSE((is_reversible_container<std::priority_queue<int>>::value));
    ASSERT_FALSE((is_reversible_container<std::queue<int>>::value));
    ASSERT_FALSE((is_reversible_container<std::stack<int>>::value));
    ASSERT_FALSE((is_reversible_container<std::unordered_map<int, int>>::value));
    ASSERT_FALSE((is_reversible_container<std::unordered_multimap<int, int>>::value));
    ASSERT_FALSE((is_reversible_container<std::unordered_multiset<int>>::value));
    ASSERT_FALSE((is_reversible_container<std::unordered_set<int>>::value));
}

GTEST_TEST(testContainerTraits, ifContainerIsntAssociativeOrUnorderedItsASequenceContainer)
{
    ASSERT_TRUE((is_sequence_container<std::array<int, 3>>::value));
    ASSERT_TRUE((is_sequence_container<std::deque<int>>::value));
    ASSERT_TRUE((is_sequence_container<std::forward_list<int>>::value));
    ASSERT_TRUE((is_sequence_container<std::list<int>>::value));
    ASSERT_TRUE((is_sequence_container<std::string>::value));
    ASSERT_TRUE((is_sequence_container<std::vector<int>>::value));

    ASSERT_FALSE((is_sequence_container<std::map<int, int>>::value));
    ASSERT_FALSE((is_sequence_container<std::multimap<int, int>>::value));
    ASSERT_FALSE((is_sequence_container<std::multiset<int>>::value));
    ASSERT_FALSE((is_sequence_container<std::priority_queue<int>>::value));
    ASSERT_FALSE((is_sequence_container<std::queue<int>>::value));
    ASSERT_FALSE((is_sequence_container<std::set<int>>::value));
    ASSERT_FALSE((is_sequence_container<std::stack<int>>::value));
    ASSERT_FALSE((is_sequence_container<std::unordered_map<int, int>>::value));
    ASSERT_FALSE((is_sequence_container<std::unordered_multimap<int, int>>::value));
    ASSERT_FALSE((is_sequence_container<std::unordered_multiset<int>>::value));
    ASSERT_FALSE((is_sequence_container<std::unordered_set<int>>::value));
}

GTEST_TEST(testContainerTraits, unorderedMapsAndSetsAreTheOnlyUnorderedAssociativeContainers)
{
    ASSERT_TRUE((is_unordered_associative_container<std::unordered_map<int, int>>::value));
    ASSERT_TRUE((is_unordered_associative_container<std::unordered_multimap<int, int>>::value));
    ASSERT_TRUE((is_unordered_associative_container<std::unordered_multiset<int>>::value));
    ASSERT_TRUE((is_unordered_associative_container<std::unordered_set<int>>::value));

    ASSERT_FALSE((is_unordered_associative_container<std::array<int, 3>>::value));
    ASSERT_FALSE((is_unordered_associative_container<std::deque<int>>::value));
    ASSERT_FALSE((is_unordered_associative_container<std::forward_list<int>>::value));
    ASSERT_FALSE((is_unordered_associative_container<std::list<int>>::value));
    ASSERT_FALSE((is_unordered_associative_container<std::map<int, int>>::value));
    ASSERT_FALSE((is_unordered_associative_container<std::multimap<int, int>>::value));
    ASSERT_FALSE((is_unordered_associative_container<std::multiset<int>>::value));
    ASSERT_FALSE((is_unordered_associative_container<std::priority_queue<int>>::value));
    ASSERT_FALSE((is_unordered_associative_container<std::queue<int>>::value));
    ASSERT_FALSE((is_unordered_associative_container<std::set<int>>::value));
    ASSERT_FALSE((is_unordered_associative_container<std::stack<int>>::value));
    ASSERT_FALSE((is_unordered_associative_container<std::string>::value));
    ASSERT_FALSE((is_unordered_associative_container<std::vector<int>>::value));
}

GTEST_TEST(testContainerTraits, convenienceVariableTemplatesAreInFactConvenient)
{
    ASSERT_FALSE((is_allocator_aware_container_v<std::array<int, 3>>));
    ASSERT_FALSE((is_associative_container_v<std::array<int, 3>>));
    ASSERT_TRUE((is_container_v<std::array<int, 3>>));
    ASSERT_FALSE((is_container_adapter_v<std::array<int, 3>>));
    ASSERT_TRUE((is_reversible_container_v<std::array<int, 3>>));
    ASSERT_TRUE((is_sequence_container_v<std::array<int, 3>>));
    ASSERT_FALSE((is_unordered_associative_container_v<std::array<int, 3>>));
}

#endif
