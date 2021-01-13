// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: popFront.hpp
// Author: crdrisko
// Date: 01/10/2021-08:42:01
// Description: A metafunction for removing the first element from a compile-time list

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_BASICALGORITHMS_POPFRONT_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_BASICALGORITHMS_POPFRONT_HPP

namespace CppUtils::Meta
{
    template<typename List>
    struct pop_front;

    template<typename List>
    using pop_front_t = typename pop_front<List>::type;
}   // namespace CppUtils::Meta

#endif
