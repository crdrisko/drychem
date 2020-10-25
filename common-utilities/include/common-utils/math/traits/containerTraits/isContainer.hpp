// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isContainer.hpp
// Author: crdrisko
// Date: 09/15/2020-08:38:28
// Description: A type trait for determining whether a type T meets the requirements of a container

#ifndef COMMON_UTILITIES_ISCONTAINER_HPP
#define COMMON_UTILITIES_ISCONTAINER_HPP

#include <type_traits>
#include <utility>

namespace CppUtils::Math
{
    // Main template
    template<typename, typename = std::void_t<>>
    struct IsContainerT : std::false_type {};

    // Partial specialization (may be SFINAE'd away)
    template<typename T>
    struct IsContainerT<T, std::void_t<typename T::value_type,
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
                                       decltype(std::declval<T>().empty())>> : std::true_type {};

    // Convenience variable template for ease-of-use
    template<typename T>
    constexpr bool IsContainer = IsContainerT<T>::value;
}   // namespace CppUtils::Math

#endif
