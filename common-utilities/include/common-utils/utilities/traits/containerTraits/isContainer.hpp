// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isContainer.hpp
// Author: crdrisko
// Date: 09/15/2020-08:38:28
// Description: A type trait for determining whether a type T meets the requirements of a container

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_UTILITIES_TRAITS_CONTAINERTRAITS_ISCONTAINER_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_UTILITIES_TRAITS_CONTAINERTRAITS_ISCONTAINER_HPP

#include <type_traits>
#include <utility>

namespace CppUtils::Traits
{
    /*!
     * A type trait to determine whether or not the supplied container is a container.
     *
     * \tparam (unnamed) A placeholder parameter for the container we are checking
     * \tparam (unnamed) A placeholder parameter that serves as our default state (i.e. false)
     */
    template<typename, typename = std::void_t<>>
    struct is_container : std::false_type
    {
    };

    /*!
     * A partial specialization of our \c is_container type trait for when
     *  the given container meets the requirements of a container.
     *
     * \tparam T The container that may or may not meet the requirements of a container
     *
     * \note We have removed the requirement for a \c size() member function so our definition
     *       can encompass the \c std::forward_list<> container.
     */
    template<typename T>
    struct is_container<T, std::void_t<typename T::value_type,
                                       typename T::reference,
                                       typename T::const_reference,
                                       typename T::iterator,
                                       typename T::const_iterator,
                                       typename T::difference_type,
                                       typename T::size_type,
                                       decltype(std::declval<T>().begin()),
                                       decltype(std::declval<T>().end()),
                                       decltype(std::declval<T>().cbegin()),
                                       decltype(std::declval<T>().cend()),
                                       decltype(std::declval<T>().max_size()),
            decltype(std::declval<T>().empty())>> : std::true_type
    {
    };

    //! Convenience variable template for ease-of-use
    template<typename T>
    constexpr bool is_container_v = is_container<T>::value;
}   // namespace CppUtils::Traits

#endif
