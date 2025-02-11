// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: popFront.hpp
// Author: crdrisko
// Date: 01/21/2021-09:10:15
// Description:

#ifndef POPFRONT_HPP
#define POPFRONT_HPP

#include <tuple>
#include <utility>

#include "common-utils/meta/algorithms/basicAlgorithms/popFrontList.hpp"
#include "common-utils/meta/types/tuples/tupleAlgorithms/select.hpp"

namespace CppUtils::Meta
{
    template<typename... Elements>
    constexpr auto pop_front(const std::tuple<Elements...>& tuple)
    {
        return select(tuple, pop_front_list_t<std::make_index_sequence<sizeof...(Elements)>> {});
    }
}   // namespace CppUtils::Meta

#endif
