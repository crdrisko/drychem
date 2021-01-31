// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: front.hpp
// Author: crdrisko
// Date: 01/21/2021-09:09:40
// Description:

#ifndef FRONT_HPP
#define FRONT_HPP

#include <tuple>
#include <utility>

#include "common-utils/meta/types/tuples/tupleAlgorithms/select.hpp"

namespace CppUtils::Meta
{
    /*!
     *
     * 
     */
    template<typename... Elements>
    constexpr auto front(const std::tuple<Elements...>& tuple)
    {
        return std::get<0>(tuple);
    }
}   // namespace CppUtils::Meta

#endif
