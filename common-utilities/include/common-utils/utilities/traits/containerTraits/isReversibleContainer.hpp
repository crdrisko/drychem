// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isReversibleContainer.hpp
// Author: crdrisko
// Date: 09/23/2020-07:41:46
// Description: A type trait for determining whether a type T meets the requirements of a reversible container

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_UTILITIES_TRAITS_CONTAINERTRAITS_ISREVERSIBLECONTAINER_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_UTILITIES_TRAITS_CONTAINERTRAITS_ISREVERSIBLECONTAINER_HPP

#include <type_traits>
#include <utility>

#include "common-utils/utilities/traits/containerTraits/isContainer.hpp"

namespace CppUtils::Traits
{
    /*!
     * A type trait to determine whether or not the supplied container is a reversible container.
     *
     * \tparam (unnamed) A placeholder parameter for the container we are checking
     * \tparam (unnamed) A placeholder parameter that serves as our default state (i.e. false)
     */
    template<typename, typename = std::void_t<>>
    struct is_reversible_container : std::false_type
    {
    };

    /*!
     * A partial specialization of our \c is_reversible_container type trait for when
     *  the given container meets the requirements of a reversible container.
     *
     * \tparam T The container that may or may not meet the requirements of a reversible container
     */
    template<typename T>
    struct is_reversible_container<T, std::void_t<typename T::reverse_iterator,
                                                  typename T::const_reverse_iterator,
                                                  decltype(std::declval<T>().rbegin()),
                                                  decltype(std::declval<T>().rend()),
                                                  decltype(std::declval<T>().crbegin()),
                                                  decltype(std::declval<T>().crend())>> : is_container<T>
    {
    };

    //! Convenience variable template for ease-of-use
    template<typename T>
    constexpr bool is_reversible_container_v = is_reversible_container<T>::value;
}   // namespace CppUtils::Traits

#endif
