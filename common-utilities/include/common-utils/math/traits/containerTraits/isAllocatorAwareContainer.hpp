// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isAllocatorAwareContainer.hpp
// Author: crdrisko
// Date: 09/23/2020-07:41:26
// Description: A type trait for determining whether a type T meets the requirements of an allocator-aware container

#ifndef COMMON_UTILITIES_ISALLOCATORAWARECONTAINER_HPP
#define COMMON_UTILITIES_ISALLOCATORAWARECONTAINER_HPP

#include <type_traits>

#include "math/traits/containerTraits/isContainer.hpp"

namespace CppUtils::Math
{
    // Main template
    template<typename, typename = std::void_t<>>
    struct IsAllocatorAwareContainerT : std::false_type {};

    // Partial specialization (may be SFINAE'd away)
    template<typename T>
    struct IsAllocatorAwareContainerT<T, std::void_t<typename T::allocator_type>> : IsContainerT<T> {};

    // Convenience variable template for ease-of-use
    template<typename T>
    constexpr bool IsAllocatorAwareContainer = IsAllocatorAwareContainerT<T>::value;
}   // namespace CppUtils::Math

#endif
