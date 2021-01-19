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
    /*!
     * A partial specialization of our \c front metafunction for when the compile-time
     *  list is a std::tuple.
     * 
     * \tparam    Head - The first element in the tuple
     * \tparam ...Tail - All elements but the first in the tuple
     */
    template<typename Head, typename... Tail>
    struct front<std::tuple<Head, Tail...>>
    {
        using type = Head;
    };


    /*!
     * A partial specialization of our \c is_empty metafunction for when the compile-time
     *  list is a std::tuple.
     */
    template<>
    struct is_empty<std::tuple<>> : std::true_type
    {
    };


    /*!
     * A partial specialization of our \c push_back metafunction for when the compile-time
     *  list is a std::tuple.
     * 
     * \tparam ...Elements - The elements of the tuple
     * \tparam  NewElement - The element we wish to add to the back of the tuple
     */
    template<typename... Elements, typename NewElement>
    struct push_back<std::tuple<Elements...>, NewElement>
    {
        using type = std::tuple<Elements..., NewElement>;
    };


    /*!
     * A partial specialization of our \c push_front metafunction for when the compile-time
     *  list is a std::tuple.
     * 
     * \tparam ...Elements - The elements of the tuple
     * \tparam  NewElement - The element we wish to add to the front of the tuple
     */
    template<typename... Elements, typename NewElement>
    struct push_front<std::tuple<Elements...>, NewElement>
    {
        using type = std::tuple<NewElement, Elements...>;
    };


    /*!
     * A partial specialization of our \c pop_front metafunction for when the compile-time
     *  list is a std::tuple.
     * 
     * \tparam    Head - The first element in the tuple
     * \tparam ...Tail - All elements but the first in the tuple
     */
    template<typename Head, typename... Tail>
    struct pop_front<std::tuple<Head, Tail...>>
    {
        using type = std::tuple<Tail...>;
    };
}   // namespace CppUtils::Meta

#endif
