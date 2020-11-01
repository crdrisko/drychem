// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isSequenceContainer.hpp
// Author: crdrisko
// Date: 09/24/2020-09:04:56
// Description: A type trait for determining whether a type T meets the requirements of a sequence container

#ifndef COMMON_UTILITIES_ISSEQUENCECONTAINER_HPP
#define COMMON_UTILITIES_ISSEQUENCECONTAINER_HPP

#include <type_traits>

#include "math/traits/containerTraits/isAssociativeContainer.hpp"
#include "math/traits/containerTraits/isContainer.hpp"
#include "math/traits/containerTraits/isUnorderedAssociativeContainer.hpp"

namespace CppUtils::Math
{
    // Main template
    template<typename T>
    struct is_sequence_container : std::conditional_t<is_container_v<T>,
                                     std::conditional_t<!is_associative_container_v<T>,
                                       std::conditional_t<!is_unordered_associative_container_v<T>, std::true_type,
                                       std::false_type>,
                                     std::false_type>,
                                   std::false_type> {};

    // Convenience variable template for ease-of-use
    template<typename T>
    constexpr bool is_sequence_container_v = is_sequence_container<T>::value;
}   // namespace CppUtils::Math

#endif
