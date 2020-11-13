// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: isAllocatorAwareContainer.hpp
// Author: crdrisko
// Date: 09/23/2020-07:41:26
// Description: A type trait for determining whether a type T meets the requirements of an allocator-aware container

#ifndef DRYCHEM_COMMON_UTILITIES_ISALLOCATORAWARECONTAINER_HPP
#define DRYCHEM_COMMON_UTILITIES_ISALLOCATORAWARECONTAINER_HPP

#include <type_traits>

#include "common-utils/utilities/traits/containerTraits/isContainer.hpp"

namespace CppUtils::Traits
{
    /*!
     * A type trait to determine whether or not the supplied container is an allocator aware container.
     * 
     * \tparam (unnamed) A placeholder parameter for the container we are checking
     * \tparam (unnamed) A placeholder parameter that serves as our default state (i.e. false)
     */
    template<typename, typename = std::void_t<>>
    struct is_allocator_aware_container : std::false_type
    {
    };

    /*!
     * A partial specialization of our \c is_allocator_aware_container type trait for when  
     *  the given container meets the requirements of an allocator aware container.
     * 
     * \tparam T The container that may or may not meet the requirements of an allocator aware container
     */
    template<typename T>
    struct is_allocator_aware_container<T, std::void_t<typename T::allocator_type>> : is_container<T>
    {
    };

    //! Convenience variable template for ease-of-use
    template<typename T>
    constexpr bool is_allocator_aware_container_v = is_allocator_aware_container<T>::value;
}   // namespace CppUtils::Traits

#endif
