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
    /*!
     * A partial specialization of our \c front metafunction for when the compile-time
     *  list is a typelist.
     * 
     * \tparam    Head - The first element in the typelist
     * \tparam ...Tail - All elements but the first in the typelist
     */
    template<typename Head, typename... Tail>
    struct front<typelist<Head, Tail...>>
    {
        using type = Head;
    };


    /*!
     * A partial specialization of our \c is_empty metafunction for when the compile-time
     *  list is a typelist.
     */
    template<>
    struct is_empty<typelist<>> : std::true_type
    {
    };


    /*!
     * A partial specialization of our \c push_back metafunction for when the compile-time
     *  list is a typelist.
     * 
     * \tparam ...Elements - The elements of the typelist
     * \tparam  NewElement - The element we wish to add to the back of the typelist
     */
    template<typename... Elements, typename NewElement>
    struct push_back<typelist<Elements...>, NewElement>
    {
        using type = typelist<Elements..., NewElement>;
    };


    /*!
     * A partial specialization of our \c push_front metafunction for when the compile-time
     *  list is a typelist.
     * 
     * \tparam ...Elements - The elements of the typelist
     * \tparam  NewElement - The element we wish to add to the front of the typelist
     */
    template<typename... Elements, typename NewElement>
    struct push_front<typelist<Elements...>, NewElement>
    {
        using type = typelist<NewElement, Elements...>;
    };


    /*!
     * A partial specialization of our \c pop_front metafunction for when the compile-time
     *  list is a typelist.
     * 
     * \tparam    Head - The first element in the typelist
     * \tparam ...Tail - All elements but the first in the typelist
     */
    template<typename Head, typename... Tail>
    struct pop_front<typelist<Head, Tail...>>
    {
        using type = typelist<Tail...>;
    };
}   // namespace CppUtils::Meta

#endif
