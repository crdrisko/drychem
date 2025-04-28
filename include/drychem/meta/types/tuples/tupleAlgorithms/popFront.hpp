// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: popFront.hpp
// Author: crdrisko
// Date: 01/21/2021-09:10:15
// Description: An algorithm that allows for the removal of the first elememt in a std::tuple

#ifndef DRYCHEM_INCLUDE_DRYCHEM_META_TYPES_TUPLES_TUPLEALGORITHMS_POPFRONT_HPP
#define DRYCHEM_INCLUDE_DRYCHEM_META_TYPES_TUPLES_TUPLEALGORITHMS_POPFRONT_HPP

#include <tuple>
#include <utility>

#include "drychem/meta/algorithms/basicAlgorithms/popFrontList.hpp"
#include "drychem/meta/types/tuples/tupleAlgorithms/select.hpp"

namespace DryChem
{
    /*!
     * An algorithm that allows for the removal of the first elememt in a \c std::tuple
     *
     * @tparam ...Elements - The elements of the tuple
     * 
     * @param tuple - The \c std::tuple we are trying to remove the first element from
     */
    template<typename... Elements>
    constexpr auto pop_front(const std::tuple<Elements...>& tuple)
    {
        return select(tuple, pop_front_list_t<std::make_index_sequence<sizeof...(Elements)>> {});
    }
}   // namespace DryChem

#endif
