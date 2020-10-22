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
    struct IsSequenceContainerT
        : std::conditional_t<IsContainer<T>,
              std::conditional_t<!IsAssociativeContainer<T>,
                  std::conditional_t<!IsUnorderedAssociativeContainer<T>, std::true_type, std::false_type>,
                  std::false_type>,
              std::false_type>
    {
    };

    // Convenience variable template for ease-of-use
    template<typename T>
    constexpr bool IsSequenceContainer = IsSequenceContainerT<T>::value;
}   // namespace CppUtils::Math

#endif
