// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: tupleAlgorithms.hpp
// Author: crdrisko
// Date: 01/06/2021-11:31:05
// Description: A collection of all the metafunctions relating to the std::tuple<> class template

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TYPES_TUPLES_TUPLEALGORITHMS_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TYPES_TUPLES_TUPLEALGORITHMS_HPP

#include "common-utils/meta/algorithms/basicAlgorithms.hpp"
#include "tupleAlgorithms/apply_n.hpp"
#include "tupleAlgorithms/reverse.hpp"
#include "tupleAlgorithms/select.hpp"

namespace CppUtils::Meta
{
    template<>
    struct is_empty<std::tuple<>> : std::true_type
    {
    };


    template<typename Head, typename... Tail>
    struct front<std::tuple<Head, Tail...>>
    {
        using type = Head;
    };


    template<typename... Elements, typename NewElement>
    struct push_back<std::tuple<Elements...>, NewElement>
    {
        using type = std::tuple<Elements..., NewElement>;
    };


    template<typename... Elements, typename NewElement>
    struct push_front<std::tuple<Elements...>, NewElement>
    {
        using type = std::tuple<NewElement, Elements...>;
    };


    template<typename Head, typename... Tail>
    struct pop_front<std::tuple<Head, Tail...>>
    {
        using type = std::tuple<Tail...>;
    };
}   // namespace CppUtils::Meta

#endif
