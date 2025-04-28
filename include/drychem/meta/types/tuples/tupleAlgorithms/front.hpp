// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: front.hpp
// Author: crdrisko
// Date: 01/21/2021-09:09:40
// Description: An algorithm that allows for the retrieval of the first elememt in a std::tuple

#ifndef DRYCHEM_INCLUDE_DRYCHEM_META_TYPES_TUPLES_TUPLEALGORITHMS_FRONT_HPP
#define DRYCHEM_INCLUDE_DRYCHEM_META_TYPES_TUPLES_TUPLEALGORITHMS_FRONT_HPP

#include <tuple>
#include <utility>

namespace DryChem
{
    /*!
     * An algorithm that allows for the retrieval of the first elememt in a \c std::tuple
     *
     * @tparam ...Elements - The elements of the tuple
     * 
     * @param tuple - The \c std::tuple we are trying to get the first element from
     */
    template<typename... Elements>
    constexpr auto front(const std::tuple<Elements...>& tuple)
    {
        return std::get<0>(tuple);
    }
}   // namespace DryChem

#endif
