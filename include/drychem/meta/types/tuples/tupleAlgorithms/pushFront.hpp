// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: pushFront.hpp
// Author: crdrisko
// Date: 01/21/2021-09:10:03
// Description: An algorithm that allows a new element to be placed at the front of an existing tuple

#ifndef DRYCHEM_INCLUDE_DRYCHEM_META_TYPES_TUPLES_TUPLEALGORITHMS_PUSHFRONT_HPP
#define DRYCHEM_INCLUDE_DRYCHEM_META_TYPES_TUPLES_TUPLEALGORITHMS_PUSHFRONT_HPP

#include <tuple>
#include <utility>

namespace DryChem
{
    namespace details
    {
        /*!
         * Implementation details associated with the \ref push_front algorithm for tuples. Allows for
         *  a new tuple to be constructed with a new element at the front.
         *
         * @tparam ...Elements - The elements of the original tuple
         * @tparam  NewElement - A new element type to add to the tuple
         * @tparam  ...Indices - The new order of tuple indices
         * 
         * @param      tuple - The \c std::tuple we are trying to add an element to the front of
         * @param newElement - The new element to add to the front of the tuple
         */
        template<typename... Elements, typename NewElement, std::size_t... Indices>
        constexpr auto push_front_impl(
            const std::tuple<Elements...>& tuple, NewElement newElement, std::index_sequence<Indices...>)
        {
            return std::make_tuple(newElement, std::get<Indices>(tuple)...);
        }
    }   // namespace details

    /*!
      * An algorithm that allows a new element to be placed at the front of an existing tuple.
      *
      * @tparam ...Elements - The elements of the original tuple
      * @tparam  NewElement - A new element type to add to the tuple
      * 
      * @param      tuple - The \c std::tuple we are trying to add an element to the front of
      * @param newElement - The new element to add to the front of the tuple
      */
    template<typename... Elements, typename NewElement>
    constexpr auto push_front(const std::tuple<Elements...>& tuple, NewElement newElement)
    {
        return details::push_front_impl(tuple, newElement, std::make_index_sequence<sizeof...(Elements)> {});
    }
}   // namespace DryChem


#endif
