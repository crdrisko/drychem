// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: integerSequenceAlgorithms.hpp
// Author: crdrisko
// Date: 01/08/2021-08:00:49
// Description: A collection of all the metafunctions relating to the std::integer_sequence<> class template

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TYPES_INTEGER_SEQUENCES_INTEGERSEQUENCEALGORITHMS_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TYPES_INTEGER_SEQUENCES_INTEGERSEQUENCEALGORITHMS_HPP

#include <type_traits>
#include <utility>

#include "common-utils/meta/algorithms/basicAlgorithms.hpp"

namespace CppUtils::Meta
{
    template<typename T, T... Indices>
    struct is_empty<std::integer_sequence<T, Indices...>>
    {
        static constexpr bool value = sizeof...(Indices) == 0;
    };


    template<typename T, T Head, T... Tail>
    struct front<std::integer_sequence<T, Head, Tail...>>
    {
        using type = std::integral_constant<T, Head>;
    };


    template<typename T, T... Elements, T NewElement>
    struct push_back<std::integer_sequence<T, Elements...>, std::integral_constant<T, NewElement>>
    {
        using type = std::integer_sequence<T, Elements..., NewElement>;
    };


    template<typename T, T... Elements, T NewElement>
    struct push_front<std::integer_sequence<T, Elements...>, std::integral_constant<T, NewElement>>
    {
        using type = std::integer_sequence<T, NewElement, Elements...>;
    };


    template<typename T, T Head, T... Tail>
    struct pop_front<std::integer_sequence<T, Head, Tail...>>
    {
        using type = std::integer_sequence<T, Tail...>;
    };
}   // namespace CppUtils::Meta

#endif
