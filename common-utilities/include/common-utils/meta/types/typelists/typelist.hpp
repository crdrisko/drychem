// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: typelist.hpp
// Author: crdrisko
// Date: 01/07/2021-09:47:41
// Description: A metaprogramming container for a list of types

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TYPES_TYPELISTS_TYPELIST_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_TYPES_TYPELISTS_TYPELIST_HPP

namespace CppUtils::Meta
{
    /*!
     * A list of types that can be manipulated through template metaprograms and algorithms.
     * 
     * \tparam ...Elements The elements of the type_list
     */
    template<typename... Elements>
    class typelist
    {
    };
}   // namespace CppUtils::Meta

#endif
