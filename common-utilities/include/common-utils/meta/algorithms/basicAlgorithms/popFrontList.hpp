// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: popFrontList.hpp
// Author: crdrisko
// Date: 01/10/2021-08:42:01
// Description: A metafunction for removing the first element from a compile-time list

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_BASICALGORITHMS_POPFRONTLIST_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_BASICALGORITHMS_POPFRONTLIST_HPP

namespace CppUtils::Meta
{
    /*!
     * The declaration of a metafunction used to remove the first element of the compile-time
     *  list for which it is specialized.
     *
     * \tparam List - The compile-time list we are operating on
     */
    template<typename List>
    struct pop_front_list;

    //! Convenience variable template for ease-of-use
    template<typename List>
    using pop_front_list_t = typename pop_front_list<List>::type;
}   // namespace CppUtils::Meta

#endif
