// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: reverseList.hpp
// Author: crdrisko
// Date: 01/10/2021-08:41:25
// Description: A metafunction for reversing a compile-time list

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_REVERSELIST_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_ALGORITHMS_REVERSELIST_HPP

#include "common-utils/meta/algorithms/basicAlgorithms/front.hpp"
#include "common-utils/meta/algorithms/basicAlgorithms/isEmpty.hpp"
#include "common-utils/meta/algorithms/basicAlgorithms/popFront.hpp"
#include "common-utils/meta/algorithms/basicAlgorithms/pushBack.hpp"

namespace CppUtils::Meta
{
    /*!
     * The declaration of a metafunction used to reverse the compile-time list for
     *  which it is specialized.
     *
     * \tparam  List - The compile-time list we are operating on
     * \tparam Empty - A flag to determine whether the list is empty
     */
    template<typename List, bool Empty = is_empty_v<List>>
    struct reverse_list;

    //! Convenience variable template for ease-of-use
    template<typename List>
    using reverse_list_t = typename reverse_list<List>::type;

    /*!
     * A partial specialization of our \c reverse_list metafunction for when the given
     *  list is not empty.
     *
     * \tparam List - The compile-time list we are operating on
     */
    template<typename List>
    struct reverse_list<List, false> : public push_back<reverse_list_t<pop_front_t<List>>, front_t<List>>
    {
    };

    /*!
     * A partial specialization of our \c reverse_list metafunction for when the given
     *  list is empty - signifying the end of the algorithm.
     *
     * \tparam List - The compile-time list we are operating on
     */
    template<typename List>
    struct reverse_list<List, true>
    {
        using type = List;
    };
}   // namespace CppUtils::Meta

#endif
