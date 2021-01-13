// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: typelistAlgorithms.hpp
// Author: crdrisko
// Date: 01/07/2021-09:51:10
// Description: A collection of all the metafunctions relating to the typelist<> class template

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TYPES_TYPELISTS_TYPELISTALGORITHMS_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TYPES_TYPELISTS_TYPELISTALGORITHMS_HPP

#include <type_traits>

#include "common-utils/meta/algorithms/basicAlgorithms.hpp"
#include "common-utils/meta/types/typelists/typelist.hpp"

namespace CppUtils::Meta
{
    template<>
    struct is_empty<typelist<>> : std::true_type
    {
    };


    template<typename Head, typename... Tail>
    struct front<typelist<Head, Tail...>>
    {
        using type = Head;
    };


    template<typename... Elements, typename NewElement>
    struct push_back<typelist<Elements...>, NewElement>
    {
        using type = typelist<Elements..., NewElement>;
    };


    template<typename... Elements, typename NewElement>
    struct push_front<typelist<Elements...>, NewElement>
    {
        using type = typelist<NewElement, Elements...>;
    };


    template<typename Head, typename... Tail>
    struct pop_front<typelist<Head, Tail...>>
    {
        using type = typelist<Tail...>;
    };
}   // namespace CppUtils::Meta

#endif
