// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isAssociativeContainer.hpp
// Author: crdrisko
// Date: 09/23/2020-07:42:36
// Description: A type trait for determining whether a type T meets the requirements of an associative container

#ifndef COMMON_UTILITIES_ISASSOCIATIVECONTAINER_HPP
#define COMMON_UTILITIES_ISASSOCIATIVECONTAINER_HPP

#include <type_traits>
#include <utility>

#include "math/traits/containerTraits/isContainer.hpp"

namespace CppUtils::Math
{
    // Main template
    template<typename, typename = std::void_t<>>
    struct IsAssociativeContainerT : std::false_type {};

    // Partial specialization (may be SFINAE'd away)
    template<typename T>
    struct IsAssociativeContainerT<T, std::void_t<typename T::key_type,
                                                  typename T::key_compare,
                                                  typename T::value_compare,
                                                  decltype(std::declval<T>().key_comp()),
                                                  decltype(std::declval<T>().value_comp())>> : IsContainerT<T> {};

    // Convenience variable template for ease-of-use
    template<typename T>
    constexpr bool IsAssociativeContainer = IsAssociativeContainerT<T>::value;
}   // namespace CppUtils::Math

#endif
