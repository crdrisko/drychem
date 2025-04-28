// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: pushBack.hpp
// Author: crdrisko
// Date: 01/21/2021-09:09:57
// Description: An algorithm that allows a new element to be placed at the end of an existing tuple.

#ifndef DRYCHEM_INCLUDE_DRYCHEM_META_TYPES_TUPLES_TUPLEALGORITHMS_PUSHBACK_HPP
#define DRYCHEM_INCLUDE_DRYCHEM_META_TYPES_TUPLES_TUPLEALGORITHMS_PUSHBACK_HPP

#include <cstddef>
#include <tuple>
#include <utility>

namespace DryChem
{
    namespace details
    {
        /*!
         * Implementation details associated with the \ref push_back algorithm for tuples. Allows for
         *  a new tuple to be constructed with a new element at the back.
         *
         * @tparam ...Elements - The elements of the original tuple
         * @tparam  NewElement - A new element type to add to the tuple
         * @tparam  ...Indices - The new order of tuple indices
         * 
         * @param      tuple - The \c std::tuple we are trying to add an element to the back of
         * @param newElement - The new element to add to the back of the tuple
         */
        template<typename... Elements, typename NewElement, std::size_t... Indices>
        constexpr auto push_back_impl(
            const std::tuple<Elements...>& tuple, NewElement newElement, std::index_sequence<Indices...>)
        {
            return std::make_tuple(std::get<Indices>(tuple)..., newElement);
        }
    }   // namespace details

    /*!
      * An algorithm that allows a new element to be placed at the back of an existing tuple.
      *
      * @tparam ...Elements - The elements of the original tuple
      * @tparam  NewElement - A new element type to add to the tuple
      * 
      * @param      tuple - The \c std::tuple we are trying to add an element to the back of
      * @param newElement - The new element to add to the back of the tuple
      */
    template<typename... Elements, typename NewElement>
    constexpr auto push_back(const std::tuple<Elements...>& tuple, NewElement newElement)
    {
        return details::push_back_impl(tuple, newElement, std::make_index_sequence<sizeof...(Elements)> {});
    }
}   // namespace DryChem

#endif
