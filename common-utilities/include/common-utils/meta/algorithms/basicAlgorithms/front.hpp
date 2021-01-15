// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: front.hpp
// Author: crdrisko
// Date: 01/10/2021-08:41:37
// Description: A metafunction for extracting the first element from a compile-time list

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_BASICALGORITHMS_FRONT_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_BASICALGORITHMS_FRONT_HPP

namespace CppUtils::Meta
{
    // front
    template<typename List>
    struct front;

    template<typename List>
    using front_t = typename front<List>::type;
}   // namespace CppUtils::Meta

#endif