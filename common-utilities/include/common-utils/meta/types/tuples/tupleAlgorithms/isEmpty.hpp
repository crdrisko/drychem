// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isEmpty.hpp
// Author: crdrisko
// Date: 01/21/2021-09:09:49
// Description:

#ifndef ISEMPTY_HPP
#define ISEMPTY_HPP

#include <tuple>
#include <utility>

#include "common-utils/meta/algorithms/basicAlgorithms/isEmptyList.hpp"

namespace CppUtils::Meta
{
    /*!
     * 
     */
    template<typename... Elements>
    constexpr bool is_empty(const std::tuple<Elements...>&)
    {
        return is_empty_list_v<std::make_index_sequence<sizeof...(Elements)>>;
    }
}   // namespace CppUtils::Meta

#endif
