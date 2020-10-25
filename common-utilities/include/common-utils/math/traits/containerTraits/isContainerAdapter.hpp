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

namespace CppUtils::Math
{
    // Main template
    template<typename T, typename = std::void_t<>>
    struct IsContainerAdapterT : std::false_type {};

    // Partial specialization (may be SFINAE'd away)
    template<typename T>
    struct IsContainerAdapterT<T, std::void_t<typename T::container_type,
                                              typename T::value_type,
                                              typename T::size_type,
                                              typename T::reference,
                                              typename T::const_reference,
                                              decltype(std::declval<T>().empty()),
                                              decltype(std::declval<T>().size())>> : std::true_type {};

    // Convenience variable template for ease-of-use
    template<typename T>
    constexpr bool IsContainerAdapter = IsContainerAdapterT<T>::value;
}   // namespace CppUtils::Math

#endif
