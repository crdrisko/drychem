// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isUnorderedAssociativeContainer.hpp
// Author: crdrisko
// Date: 09/23/2020-07:42:43
// Description: A type trait for determining whether a type T meets the requirements of an unordered, associative container

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TRAITS_CONTAINERTRAITS_ISUNORDEREDASSOCIATIVECONTAINER_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TRAITS_CONTAINERTRAITS_ISUNORDEREDASSOCIATIVECONTAINER_HPP

#include <type_traits>

#include "common-utils/meta/traits/containerTraits/isContainer.hpp"

namespace CppUtils::Meta
{
    /*!
     * A type trait to determine whether or not the supplied container is an unordered associative container.
     *
     * \tparam (unnamed) - A placeholder parameter for the container we are checking
     * \tparam (unnamed) - A placeholder parameter that serves as our default state (i.e. false)
     */
    template<typename, typename = std::void_t<>>
    struct is_unordered_associative_container : std::false_type
    {
    };

    /*!
     * A partial specialization of our \c is_unordered_associative_container type trait for when
     *  the given container meets the requirements of an unordered associative container.
     *
     * \tparam T - The container that may or may not meet the requirements of an unordered associative container
     */
    template<typename T>
    struct is_unordered_associative_container<T, std::void_t<typename T::key_type,
                                                             typename T::value_type,
                                                             typename T::hasher,
                                                             typename T::key_equal,
                                                             typename T::local_iterator,
                                                             typename T::const_local_iterator>> : is_container<T>
    {
    };

    //! Convenience variable template for ease-of-use
    template<typename T>
    constexpr bool is_unordered_associative_container_v = is_unordered_associative_container<T>::value;
}   // namespace CppUtils::Meta

#endif
