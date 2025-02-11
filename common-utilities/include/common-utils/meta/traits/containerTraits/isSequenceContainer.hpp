// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isSequenceContainer.hpp
// Author: crdrisko
// Date: 09/24/2020-09:04:56
// Description: A type trait for determining whether a type T meets the requirements of a sequence container

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TRAITS_CONTAINERTRAITS_ISSEQUENCECONTAINER_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TRAITS_CONTAINERTRAITS_ISSEQUENCECONTAINER_HPP

#include <type_traits>

#include "common-utils/meta/traits/containerTraits/isAssociativeContainer.hpp"
#include "common-utils/meta/traits/containerTraits/isContainer.hpp"
#include "common-utils/meta/traits/containerTraits/isUnorderedAssociativeContainer.hpp"

namespace CppUtils::Meta
{
    /*!
     * A type trait to determine whether or not the supplied container is a sequence container.
     *
     * \tparam (unnamed) - A placeholder parameter for the container we are checking
     */
    template<typename T>
    struct is_sequence_container : std::conditional_t<is_container_v<T>,
                                     std::conditional_t<!is_associative_container_v<T>,
                                       std::conditional_t<!is_unordered_associative_container_v<T>, std::true_type,
                                       std::false_type>,
                                     std::false_type>,
                                   std::false_type>
    {
    };

    //! Convenience variable template for ease-of-use
    template<typename T>
    constexpr bool is_sequence_container_v = is_sequence_container<T>::value;
}   // namespace CppUtils::Meta

#endif
