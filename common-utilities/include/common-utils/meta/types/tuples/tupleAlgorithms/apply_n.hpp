// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: apply_n.hpp
// Author: crdrisko
// Date: 11/21/2020-10:35:11
// Description: An algorithm, based off std::apply, that only applies a function to the first N elements of a tuple

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TYPES_TUPLES_TUPLEALGORITHMS_APPLY_N_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TYPES_TUPLES_TUPLEALGORITHMS_APPLY_N_HPP

#include <cstddef>
#include <tuple>
#include <utility>

#include "common-utils/meta/types/tuples/tupleAlgorithms/select.hpp"

namespace CppUtils::Meta
{
    /*!
     * A function that applies a given function to the first N elements of a tuple
     * 
     * \tparam N     The number of elements to select
     * \tparam F     The callable type we are invoking for the first N elements of the tuple
     * \tparam Tuple The type of tuple we are passing to std::apply
     * 
     * \param f     The function we are applying to the new tuple
     * \param tuple The tuple we are trying to apply the function to
     */
    template<std::size_t N, typename F, typename Tuple>
    constexpr decltype(auto) apply_n(F&& f, Tuple&& tuple)
    {
        return std::apply(std::forward<F>(f), select(std::forward<Tuple>(tuple), std::make_index_sequence<N> {}));
    }
}   // namespace CppUtils::Meta

#endif
