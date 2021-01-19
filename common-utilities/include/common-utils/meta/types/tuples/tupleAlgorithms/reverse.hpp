// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: reverse.hpp
// Author: crdrisko
// Date: 01/07/2021-07:03:42
// Description: A metafunction for reversing a std::tuple

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TYPES_TUPLES_TUPLEALGORITHMS_REVERSE_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TYPES_TUPLES_TUPLEALGORITHMS_REVERSE_HPP

#include <tuple>
#include <utility>

#include "common-utils/meta/algorithms/reverseList.hpp"
#include "common-utils/meta/types/tuples/tupleAlgorithms/select.hpp"

namespace CppUtils::Meta
{
    /*!
     * An algorithm to reverse the contents of a \c std::tuple using its indices.
     * 
     * \tparam ...Elements - The elements of the tuple
     * 
     * \param tuple - The \c std::tuple we are trying to reverse
     */
    template<typename... Elements>
    constexpr decltype(auto) reverse(const std::tuple<Elements...>& tuple)
    {
        return select(tuple, Meta::reverse_list_t<std::make_index_sequence<sizeof...(Elements)>>());
    }
}   // namespace CppUtils::Meta

#endif
