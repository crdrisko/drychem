// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isEmpty.hpp
// Author: crdrisko
// Date: 01/21/2021-09:09:49
// Description: An algorithm that checks whether or not a tuple is empty

#ifndef DRYCHEM_INCLUDE_DRYCHEM_META_TYPES_TUPLES_TUPLEALGORITHMS_ISEMPTY_HPP
#define DRYCHEM_INCLUDE_DRYCHEM_META_TYPES_TUPLES_TUPLEALGORITHMS_ISEMPTY_HPP

#include <tuple>
#include <utility>

#include "drychem/meta/algorithms/basicAlgorithms/isEmptyList.hpp"

namespace DryChem
{
    /*!
     * An algorithm based on the \ref is_empty_list_v meta-algorithm that checks whether or not a
     *  \c std::tuple is empty.
     *
     * @tparam ...Elements - Elements of the \c std::tuple pased to the function
     */
    template<typename... Elements>
    constexpr bool is_empty(const std::tuple<Elements...>&)
    {
        return is_empty_list_v<std::make_index_sequence<sizeof...(Elements)>>;
    }
}   // namespace DryChem

#endif
