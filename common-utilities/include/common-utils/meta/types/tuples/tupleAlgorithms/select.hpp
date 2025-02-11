// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: select.hpp
// Author: crdrisko
// Date: 11/21/2020-06:52:54
// Description: An algorithm to select the appropriate elements of a given tuple

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TYPES_TUPLES_TUPLEALGORITHMS_SELECT_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TYPES_TUPLES_TUPLEALGORITHMS_SELECT_HPP

#include <cstddef>
#include <tuple>
#include <utility>

namespace CppUtils::Meta
{
    /*!
     * Function to create a new tuple in a different order from the input tuple.
     * 
     * \tparam ...Elements - The elements of the input tuple
     * \tparam  ...Indices - The new order of indices
     * 
     * \param tuple - The \c std::tuple we are trying to shuffle
     */
    template<typename... Elements, std::size_t... Indices>
    constexpr auto select(const std::tuple<Elements...>& tuple, std::index_sequence<Indices...>)
    {
        return std::make_tuple(std::get<Indices>(tuple)...);
    }
}   // namespace CppUtils::Meta

#endif
