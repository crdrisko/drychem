// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isReversibleContainer.hpp
// Author: crdrisko
// Date: 09/23/2020-07:41:46
// Description: A type trait for determining whether a type T meets the requirements of a reversible container

#ifndef COMMON_UTILITIES_ISREVERSIBLECONTAINER_HPP
#define COMMON_UTILITIES_ISREVERSIBLECONTAINER_HPP

#include <type_traits>
#include <utility>

#include "math/traits/containerTraits/isContainer.hpp"

namespace CppUtils::Math
{
    // Main template
    template<typename, typename = std::void_t<>>
    struct IsReversibleContainerT : std::false_type
    {
    };

    // Partial specialization (may be SFINAE'd away)
    template<typename T>
    struct IsReversibleContainerT<T,
        std::void_t<typename T::reverse_iterator,
            typename T::const_reverse_iterator,
            decltype(std::declval<T>().rbegin()),
            decltype(std::declval<T>().rend()),
            decltype(std::declval<T>().crbegin()),
            decltype(std::declval<T>().crend())>> : IsContainerT<T>
    {
    };

    // Convenience variable template for ease-of-use
    template<typename T>
    constexpr bool IsReversibleContainer = IsReversibleContainerT<T>::value;
}   // namespace CppUtils::Math

#endif
