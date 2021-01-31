// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: pushBack.hpp
// Author: crdrisko
// Date: 01/21/2021-09:09:57
// Description:

#ifndef PUSHBACK_HPP
#define PUSHBACK_HPP

#include <cstddef>
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
        constexpr auto push_back_impl(
            const std::tuple<Elements...>& tuple, NewElement newElement, std::index_sequence<Indices...>)
        {
            return std::make_tuple(std::get<Indices>(tuple)..., newElement);
        }
    }   // namespace details

    /*!
     *
     * 
     */
    template<typename... Elements, typename NewElement>
    constexpr auto push_back(const std::tuple<Elements...>& tuple, NewElement newElement)
    {
        return details::push_back_impl(tuple, newElement, std::make_index_sequence<sizeof...(Elements)> {});
    }
}   // namespace CppUtils::Meta

#endif
