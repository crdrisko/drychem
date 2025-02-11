// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: pushFront.hpp
// Author: crdrisko
// Date: 01/21/2021-09:10:03
// Description:

#ifndef PUSHFRONT_HPP
#define PUSHFRONT_HPP

#include <tuple>
#include <utility>

#include "common-utils/meta/types/tuples/tupleAlgorithms/select.hpp"

namespace CppUtils::Meta
{
    namespace details
    {
        /*!
        *
        * 
        */
        template<typename... Elements, typename NewElement, std::size_t... Indices>
        constexpr auto push_front_impl(
            const std::tuple<Elements...>& tuple, NewElement newElement, std::index_sequence<Indices...>)
        {
            return std::make_tuple(newElement, std::get<Indices>(tuple)...);
        }
    }   // namespace details

    /*!
     *
     * 
     */
    template<typename... Elements, typename NewElement>
    constexpr auto push_front(const std::tuple<Elements...>& tuple, NewElement newElement)
    {
        return details::push_front_impl(tuple, newElement, std::make_index_sequence<sizeof...(Elements)> {});
    }
}   // namespace CppUtils::Meta


#endif
