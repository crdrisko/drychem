// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
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
    /*!
     * A partial specialization of our \c front_list metafunction for when the compile-time
     *  list is a std::integer_sequence.
     *
     * \tparam       T - The integer type to use for the elements of the sequence 
     * \tparam    Head - The first element in the sequence
     * \tparam ...Tail - All elements but the first in the sequence
     */
    template<typename T, T Head, T... Tail>
    struct front_list<std::integer_sequence<T, Head, Tail...>>
    {
        using type = std::integral_constant<T, Head>;
    };


    /*!
     * A partial specialization of our \c is_empty_list metafunction for when the compile-time
     *  list is a std::integer_sequence.
     *
     * \tparam          T  - The integer type to use for the elements of the sequence 
     * \tparam ...Elements - The sequence of integer types
     */
    template<typename T, T... Elements>
    struct is_empty_list<std::integer_sequence<T, Elements...>>
    {
        static constexpr bool value = sizeof...(Elements) == 0;
    };


    /*!
     * A partial specialization of our \c pop_front_list metafunction for when the compile-time
     *  list is a std::integer_sequence.
     *
     * \tparam       T - The integer type to use for the elements of the sequence 
     * \tparam    Head - The first element in the sequence
     * \tparam ...Tail - All elements but the first in the sequence
     */
    template<typename T, T Head, T... Tail>
    struct pop_front_list<std::integer_sequence<T, Head, Tail...>>
    {
        using type = std::integer_sequence<T, Tail...>;
    };


    /*!
     * A partial specialization of our \c push_back_list metafunction for when the compile-time
     *  list is a std::integer_sequence.
     *
     * \tparam           T - The integer type to use for the elements of the sequence 
     * \tparam ...Elements - The sequence of integer types
     * \tparam  NewElement - The element we wish to add to the back of the sequence
     */
    template<typename T, T... Elements, T NewElement>
    struct push_back_list<std::integer_sequence<T, Elements...>, std::integral_constant<T, NewElement>>
    {
        using type = std::integer_sequence<T, Elements..., NewElement>;
    };


    /*!
     * A partial specialization of our \c push_front metafunction for when the compile-time
     *  list is a std::integer_sequence.
     *
     * \tparam           T - The integer type to use for the elements of the sequence 
     * \tparam ...Elements - The sequence of integer types
     * \tparam  NewElement - The element we wish to add to the front of the sequence
     */
    template<typename T, T... Elements, T NewElement>
    struct push_front_list<std::integer_sequence<T, Elements...>, std::integral_constant<T, NewElement>>
    {
        using type = std::integer_sequence<T, NewElement, Elements...>;
    };
}   // namespace CppUtils::Meta

#endif
