// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: frontList.hpp
// Author: crdrisko
// Date: 01/10/2021-08:41:37
// Description: A metafunction for extracting the first element from a compile-time list

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_BASICALGORITHMS_FRONTLIST_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_BASICALGORITHMS_FRONTLIST_HPP

namespace CppUtils::Meta
{
    /*!
     * The declaration of a metafunction used to extract the first element of the compile-time
     *  list for which it is specialized.
     *
     * \tparam List - The compile-time list we are operating on
     */
    template<typename List>
    struct front_list;

    //! Convenience variable template for ease-of-use
    template<typename List>
    using front_list_t = typename front_list<List>::type;
}   // namespace CppUtils::Meta

#endif
