// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: reverse.hpp
// Author: crdrisko
// Date: 01/07/2021-07:03:42
// Description: A metafunction for reversing a std::tuple

#ifndef DRYCHEM_INCLUDE_DRYCHEM_META_TYPES_TUPLES_TUPLEALGORITHMS_REVERSE_HPP
#define DRYCHEM_INCLUDE_DRYCHEM_META_TYPES_TUPLES_TUPLEALGORITHMS_REVERSE_HPP

#include <tuple>
#include <utility>

#include "drychem/meta/algorithms/reverseList.hpp"
#include "drychem/meta/types/tuples/tupleAlgorithms/select.hpp"

namespace DryChem
{
    /*!
     * An algorithm to reverse the contents of a \c std::tuple using its indices.
     * 
     * \tparam ...Elements - The elements of the tuple
     * 
     * \param tuple - The \c std::tuple we are trying to reverse
     */
    template<typename... Elements>
    constexpr auto reverse(const std::tuple<Elements...>& tuple)
    {
        return select(tuple, reverse_list_t<std::make_index_sequence<sizeof...(Elements)>>());
    }
}   // namespace DryChem

#endif
