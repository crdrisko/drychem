// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isContainerAdapter.hpp
// Author: crdrisko
// Date: 09/23/2020-07:42:03
// Description: A type trait for determining whether a type T meets the requirements of a container adapter

#ifndef COMMON_UTILITIES_ISCONTAINERADAPTER_HPP
#define COMMON_UTILITIES_ISCONTAINERADAPTER_HPP

#include <type_traits>
#include <utility>

namespace CppUtils::Traits
{
    /*!
     * A type trait to determine whether or not the supplied container is a container adapter.
     *
     * \tparam (unnamed) A placeholder parameter for the container we are checking
     * \tparam (unnamed) A placeholder parameter that serves as our default state (i.e. false)
     */
    template<typename T, typename = std::void_t<>>
    struct is_container_adapter : std::false_type
    {
    };

    /*!
     * A partial specialization of our \c is_container_adapter type trait for when
     *  the given container meets the requirements of a container adapter.
     *
     * \tparam T The container that may or may not meet the requirements of a container adapter
     */
    template<typename T>
    struct is_container_adapter<T, std::void_t<typename T::container_type,
                                               typename T::value_type,
                                               typename T::size_type,
                                               typename T::reference,
                                               typename T::const_reference,
                                               decltype(std::declval<T>().empty()),
                                               decltype(std::declval<T>().size())>> : std::true_type
    {
    };

    //! Convenience variable template for ease-of-use
    template<typename T>
    constexpr bool is_container_adapter_v = is_container_adapter<T>::value;
}   // namespace CppUtils::Traits

#endif
