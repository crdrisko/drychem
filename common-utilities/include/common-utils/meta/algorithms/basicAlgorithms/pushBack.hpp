// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: pushBack.hpp
// Author: crdrisko
// Date: 01/10/2021-08:41:48
// Description: A metafunction for inserting a new element at the back of a compile-time list

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_BASICALGORITHMS_PUSHBACK_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_BASICALGORITHMS_PUSHBACK_HPP

namespace CppUtils::Meta
{
    /*!
     * The declaration of a metafunction used to insert a new element at the back of the 
     *  compile-time list for which it is specialized.
     *
     * \tparam       List - The compile-time list we are operating on
     * \tparam NewElement - The type of element we are inserting
     */
    template<typename List, typename NewElement>
    struct push_back;

    //! Convenience variable template for ease-of-use
    template<typename List, typename NewElement>
    using push_back_t = typename push_back<List, NewElement>::type;
}   // namespace CppUtils::Meta

#endif
