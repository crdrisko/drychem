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
    ASSERT_TRUE((IsAllocatorAwareContainerT<std::deque<int>>::value));
    ASSERT_TRUE((IsAllocatorAwareContainerT<std::forward_list<int>>::value));
    ASSERT_TRUE((IsAllocatorAwareContainerT<std::list<int>>::value));
    ASSERT_TRUE((IsAllocatorAwareContainerT<std::map<int, int>>::value));
    ASSERT_TRUE((IsAllocatorAwareContainerT<std::multimap<int, int>>::value));
    ASSERT_TRUE((IsAllocatorAwareContainerT<std::multiset<int>>::value));
    ASSERT_TRUE((IsAllocatorAwareContainerT<std::set<int>>::value));
    ASSERT_TRUE((IsAllocatorAwareContainerT<std::string>::value));
    ASSERT_TRUE((IsAllocatorAwareContainerT<std::unordered_map<int, int>>::value));
    ASSERT_TRUE((IsAllocatorAwareContainerT<std::unordered_multimap<int, int>>::value));
    ASSERT_TRUE((IsAllocatorAwareContainerT<std::unordered_multiset<int>>::value));
    ASSERT_TRUE((IsAllocatorAwareContainerT<std::unordered_set<int>>::value));
    ASSERT_TRUE((IsAllocatorAwareContainerT<std::vector<int>>::value));

    ASSERT_FALSE((IsAllocatorAwareContainerT<std::array<int, 3>>::value));
    ASSERT_FALSE((IsAllocatorAwareContainerT<std::priority_queue<int>>::value));
    ASSERT_FALSE((IsAllocatorAwareContainerT<std::queue<int>>::value));
    ASSERT_FALSE((IsAllocatorAwareContainerT<std::stack<int>>::value));
}

GTEST_TEST(testContainerTraits, onlyOrderedMapsAndSetsAreAssociativeContainers)
{
    ASSERT_TRUE((IsAssociativeContainerT<std::map<int, int>>::value));
    ASSERT_TRUE((IsAssociativeContainerT<std::multimap<int, int>>::value));
    ASSERT_TRUE((IsAssociativeContainerT<std::multiset<int>>::value));
    ASSERT_TRUE((IsAssociativeContainerT<std::set<int>>::value));

    ASSERT_FALSE((IsAssociativeContainerT<std::array<int, 3>>::value));
    ASSERT_FALSE((IsAssociativeContainerT<std::deque<int>>::value));
    ASSERT_FALSE((IsAssociativeContainerT<std::forward_list<int>>::value));
    ASSERT_FALSE((IsAssociativeContainerT<std::list<int>>::value));
    ASSERT_FALSE((IsAssociativeContainerT<std::priority_queue<int>>::value));
    ASSERT_FALSE((IsAssociativeContainerT<std::queue<int>>::value));
    ASSERT_FALSE((IsAssociativeContainerT<std::stack<int>>::value));
    ASSERT_FALSE((IsAssociativeContainerT<std::string>::value));
    ASSERT_FALSE((IsAssociativeContainerT<std::unordered_map<int, int>>::value));
    ASSERT_FALSE((IsAssociativeContainerT<std::unordered_multimap<int, int>>::value));
    ASSERT_FALSE((IsAssociativeContainerT<std::unordered_multiset<int>>::value));
    ASSERT_FALSE((IsAssociativeContainerT<std::unordered_set<int>>::value));
    ASSERT_FALSE((IsAssociativeContainerT<std::vector<int>>::value));
}

GTEST_TEST(testContainerTraits, allStdContainersAreContainers)
{
    ASSERT_TRUE((IsContainerT<std::array<int, 3>>::value));
    ASSERT_TRUE((IsContainerT<std::deque<int>>::value));
    ASSERT_TRUE((IsContainerT<std::forward_list<int>>::value));
    ASSERT_TRUE((IsContainerT<std::list<int>>::value));
    ASSERT_TRUE((IsContainerT<std::map<int, int>>::value));
    ASSERT_TRUE((IsContainerT<std::multimap<int, int>>::value));
    ASSERT_TRUE((IsContainerT<std::multiset<int>>::value));
    ASSERT_TRUE((IsContainerT<std::set<int>>::value));
    ASSERT_TRUE((IsContainerT<std::string>::value));
    ASSERT_TRUE((IsContainerT<std::unordered_map<int, int>>::value));
    ASSERT_TRUE((IsContainerT<std::unordered_multimap<int, int>>::value));
    ASSERT_TRUE((IsContainerT<std::unordered_multiset<int>>::value));
    ASSERT_TRUE((IsContainerT<std::unordered_set<int>>::value));
    ASSERT_TRUE((IsContainerT<std::vector<int>>::value));

    ASSERT_FALSE((IsContainerT<std::priority_queue<int>>::value));
    ASSERT_FALSE((IsContainerT<std::queue<int>>::value));
    ASSERT_FALSE((IsContainerT<std::stack<int>>::value));
}

GTEST_TEST(testContainerTraits, containerAdaptersRequireAWrappedContainerType)
{
    ASSERT_TRUE((IsContainerAdapterT<std::priority_queue<int>>::value));
    ASSERT_TRUE((IsContainerAdapterT<std::queue<int>>::value));
    ASSERT_TRUE((IsContainerAdapterT<std::stack<int>>::value));

    ASSERT_FALSE((IsContainerAdapterT<std::array<int, 3>>::value));
    ASSERT_FALSE((IsContainerAdapterT<std::deque<int>>::value));
    ASSERT_FALSE((IsContainerAdapterT<std::forward_list<int>>::value));
    ASSERT_FALSE((IsContainerAdapterT<std::list<int>>::value));
    ASSERT_FALSE((IsContainerAdapterT<std::map<int, int>>::value));
    ASSERT_FALSE((IsContainerAdapterT<std::multimap<int, int>>::value));
    ASSERT_FALSE((IsContainerAdapterT<std::multiset<int>>::value));
    ASSERT_FALSE((IsContainerAdapterT<std::set<int>>::value));
    ASSERT_FALSE((IsContainerAdapterT<std::string>::value));
    ASSERT_FALSE((IsContainerAdapterT<std::unordered_map<int, int>>::value));
    ASSERT_FALSE((IsContainerAdapterT<std::unordered_multimap<int, int>>::value));
    ASSERT_FALSE((IsContainerAdapterT<std::unordered_multiset<int>>::value));
    ASSERT_FALSE((IsContainerAdapterT<std::unordered_set<int>>::value));
    ASSERT_FALSE((IsContainerAdapterT<std::vector<int>>::value));
}

GTEST_TEST(testContainerTraits, almostAllStandardContainersAreReversible)
{
    ASSERT_TRUE((IsReversibleContainerT<std::array<int, 3>>::value));
    ASSERT_TRUE((IsReversibleContainerT<std::deque<int>>::value));
    ASSERT_TRUE((IsReversibleContainerT<std::list<int>>::value));
    ASSERT_TRUE((IsReversibleContainerT<std::map<int, int>>::value));
    ASSERT_TRUE((IsReversibleContainerT<std::multimap<int, int>>::value));
    ASSERT_TRUE((IsReversibleContainerT<std::multiset<int>>::value));
    ASSERT_TRUE((IsReversibleContainerT<std::set<int>>::value));
    ASSERT_TRUE((IsReversibleContainerT<std::string>::value));
    ASSERT_TRUE((IsReversibleContainerT<std::vector<int>>::value));

    ASSERT_FALSE((IsReversibleContainerT<std::forward_list<int>>::value));
    ASSERT_FALSE((IsReversibleContainerT<std::priority_queue<int>>::value));
    ASSERT_FALSE((IsReversibleContainerT<std::queue<int>>::value));
    ASSERT_FALSE((IsReversibleContainerT<std::stack<int>>::value));
    ASSERT_FALSE((IsReversibleContainerT<std::unordered_map<int, int>>::value));
    ASSERT_FALSE((IsReversibleContainerT<std::unordered_multimap<int, int>>::value));
    ASSERT_FALSE((IsReversibleContainerT<std::unordered_multiset<int>>::value));
    ASSERT_FALSE((IsReversibleContainerT<std::unordered_set<int>>::value));
}

GTEST_TEST(testContainerTraits, ifContainerIsntAssociativeOrUnorderedItsASequenceContainer)
{
    ASSERT_TRUE((IsSequenceContainerT<std::array<int, 3>>::value));
    ASSERT_TRUE((IsSequenceContainerT<std::deque<int>>::value));
    ASSERT_TRUE((IsSequenceContainerT<std::forward_list<int>>::value));
    ASSERT_TRUE((IsSequenceContainerT<std::list<int>>::value));
    ASSERT_TRUE((IsSequenceContainerT<std::string>::value));
    ASSERT_TRUE((IsSequenceContainerT<std::vector<int>>::value));

    ASSERT_FALSE((IsSequenceContainerT<std::map<int, int>>::value));
    ASSERT_FALSE((IsSequenceContainerT<std::multimap<int, int>>::value));
    ASSERT_FALSE((IsSequenceContainerT<std::multiset<int>>::value));
    ASSERT_FALSE((IsSequenceContainerT<std::priority_queue<int>>::value));
    ASSERT_FALSE((IsSequenceContainerT<std::queue<int>>::value));
    ASSERT_FALSE((IsSequenceContainerT<std::set<int>>::value));
    ASSERT_FALSE((IsSequenceContainerT<std::stack<int>>::value));
    ASSERT_FALSE((IsSequenceContainerT<std::unordered_map<int, int>>::value));
    ASSERT_FALSE((IsSequenceContainerT<std::unordered_multimap<int, int>>::value));
    ASSERT_FALSE((IsSequenceContainerT<std::unordered_multiset<int>>::value));
    ASSERT_FALSE((IsSequenceContainerT<std::unordered_set<int>>::value));
}

GTEST_TEST(testContainerTraits, unorderedMapsAndSetsAreTheOnlyUnorderedAssociativeContainers)
{
    ASSERT_TRUE((IsUnorderedAssociativeContainerT<std::unordered_map<int, int>>::value));
    ASSERT_TRUE((IsUnorderedAssociativeContainerT<std::unordered_multimap<int, int>>::value));
    ASSERT_TRUE((IsUnorderedAssociativeContainerT<std::unordered_multiset<int>>::value));
    ASSERT_TRUE((IsUnorderedAssociativeContainerT<std::unordered_set<int>>::value));

    ASSERT_FALSE((IsUnorderedAssociativeContainerT<std::array<int, 3>>::value));
    ASSERT_FALSE((IsUnorderedAssociativeContainerT<std::deque<int>>::value));
    ASSERT_FALSE((IsUnorderedAssociativeContainerT<std::forward_list<int>>::value));
    ASSERT_FALSE((IsUnorderedAssociativeContainerT<std::list<int>>::value));
    ASSERT_FALSE((IsUnorderedAssociativeContainerT<std::map<int, int>>::value));
    ASSERT_FALSE((IsUnorderedAssociativeContainerT<std::multimap<int, int>>::value));
    ASSERT_FALSE((IsUnorderedAssociativeContainerT<std::multiset<int>>::value));
    ASSERT_FALSE((IsUnorderedAssociativeContainerT<std::priority_queue<int>>::value));
    ASSERT_FALSE((IsUnorderedAssociativeContainerT<std::queue<int>>::value));
    ASSERT_FALSE((IsUnorderedAssociativeContainerT<std::set<int>>::value));
    ASSERT_FALSE((IsUnorderedAssociativeContainerT<std::stack<int>>::value));
    ASSERT_FALSE((IsUnorderedAssociativeContainerT<std::string>::value));
    ASSERT_FALSE((IsUnorderedAssociativeContainerT<std::vector<int>>::value));
}

GTEST_TEST(testContainerTraits, convenienceVariableTemplatesAreInFactConvenient)
{
    ASSERT_FALSE((IsAllocatorAwareContainer<std::array<int, 3>>));
    ASSERT_FALSE((IsAssociativeContainer<std::array<int, 3>>));
    ASSERT_TRUE((IsContainer<std::array<int, 3>>));
    ASSERT_FALSE((IsContainerAdapter<std::array<int, 3>>));
    ASSERT_TRUE((IsReversibleContainer<std::array<int, 3>>));
    ASSERT_TRUE((IsSequenceContainer<std::array<int, 3>>));
    ASSERT_FALSE((IsUnorderedAssociativeContainer<std::array<int, 3>>));
}

#endif
