// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isEmpty.hpp
// Author: crdrisko
// Date: 01/10/2021-08:41:09
// Description: A metafunction for determining whether a compile-time list is empty

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_BASICALGORITHMS_ISEMPTY_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_BASICALGORITHMS_ISEMPTY_HPP

#include <type_traits>

namespace CppUtils::Meta
{
    // is_empty
    template<typename List>
    struct is_empty : std::false_type
    {
    };

    template<typename List>
    constexpr bool is_empty_v = is_empty<List>::value;
}   // namespace CppUtils::Meta

#endif
