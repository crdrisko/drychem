// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: pushFront.hpp
// Author: crdrisko
// Date: 01/10/2021-08:42:06
// Description: A metafunction for inserting a new element at the front of a compile-time list

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_BASICALGORITHMS_PUSHFRONT_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_BASICALGORITHMS_PUSHFRONT_HPP

namespace CppUtils::Meta
{
    template<typename List, typename NewElement>
    struct push_front;

    template<typename List, typename NewElement>
    using push_front_t = typename push_front<List, NewElement>::type;
}   // namespace CppUtils::Meta

#endif
