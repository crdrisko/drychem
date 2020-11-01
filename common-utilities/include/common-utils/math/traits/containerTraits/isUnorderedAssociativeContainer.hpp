// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isUnorderedAssociativeContainer.hpp
// Author: crdrisko
// Date: 09/23/2020-07:42:43
// Description: A type trait for determining whether a type T meets the requirements of an unordered, associative container

#ifndef COMMON_UTILITIES_ISUNORDEREDASSOCIATIVECONTAINER_HPP
#define COMMON_UTILITIES_ISUNORDEREDASSOCIATIVECONTAINER_HPP

#include <type_traits>

#include "math/traits/containerTraits/isContainer.hpp"

namespace CppUtils::Math
{
    // Main template
    template<typename, typename = std::void_t<>>
    struct is_unordered_associative_container : std::false_type {};

    // Partial specialization (may be SFINAE'd away)
    template<typename T>
    struct is_unordered_associative_container<T, std::void_t<typename T::key_type,
                                                             typename T::value_type,
                                                             typename T::hasher,
                                                             typename T::key_equal,
                                                             typename T::local_iterator,
                                                             typename T::const_local_iterator>> : is_container<T> {};

    // Convenience variable template for ease-of-use
    template<typename T>
    constexpr bool is_unordered_associative_container_v = is_unordered_associative_container<T>::value;
}   // namespace CppUtils::Math

#endif
