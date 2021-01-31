// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isEmptyList.hpp
// Author: crdrisko
// Date: 01/10/2021-08:41:09
// Description: A metafunction for determining whether a compile-time list is empty

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_BASICALGORITHMS_ISEMPTYLIST_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_BASICALGORITHMS_ISEMPTYLIST_HPP

#include <type_traits>

namespace CppUtils::Meta
{
    /*!
     * The declaration of a metafunction used to whether the compile-time list for which
     *  it is specialized is empty.
     *
     * \tparam List - The compile-time list we are operating on
     */
    template<typename List>
    struct is_empty_list : std::false_type
    {
    };

    //! Convenience variable template for ease-of-use
    template<typename List>
    constexpr bool is_empty_list_v = is_empty_list<List>::value;
}   // namespace CppUtils::Meta

#endif
