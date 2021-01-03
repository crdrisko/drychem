// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: apply_n.hpp
// Author: crdrisko
// Date: 11/21/2020-10:35:11
// Description:

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_UTILITIES_TUPLES_APPLY_N_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_UTILITIES_TUPLES_APPLY_N_HPP

#include <cstddef>
#include <tuple>
#include <utility>

#include "select.hpp"

namespace CppUtils::Tuples
{
    /*!
     *
     * 
     */
    template<std::size_t N, class F, class Tuple>
    constexpr decltype(auto) apply_n(F&& f, Tuple&& t)
    {
        return std::apply(std::forward<F>(f), select(std::forward<Tuple>(t), std::make_index_sequence<N> {}));
    }
}   // namespace CppUtils::Tuples

#endif
