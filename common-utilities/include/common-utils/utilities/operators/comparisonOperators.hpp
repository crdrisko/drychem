// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: comparisonOperators.hpp
// Author: crdrisko
// Date: 09/17/2020-12:36:17
// Description: An alternative to std::rel_opts which doesn't inject the comparison operators into the global namespace

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_UTILITIES_OPERATORS_COMPARISONOPERATORS_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_UTILITIES_OPERATORS_COMPARISONOPERATORS_HPP

#include "common-utils/utilities/operators/potentiallyEmptyBaseClass.hpp"

namespace CppUtils::Operators
{
    /*!
     * The comparison operators that can be derived from the equals-to operator
     *
     * \tparam Derived - The class with the overloaded \c operator==()
     * \tparam   Empty - An empty base class, not really needed for the general user
     */
    template<typename Derived, typename Empty = PotentiallyEmptyBaseClass<Derived>>
    class EqualityComparable : public Empty
    {
    public:
        constexpr friend bool operator!=(const Derived& x1_, const Derived& x2_) { return !(x1_ == x2_); }
    };

    /*!
     * The comparison operators that can be derived from the less-than operator
     *
     * \tparam Derived - The class with the overloaded \c operator<()
     * \tparam   Empty - An empty base class, not really needed for the general user
     */
    template<typename Derived, typename Empty = PotentiallyEmptyBaseClass<Derived>>
    class LessThanComparable : public Empty
    {
    public:
        constexpr friend bool operator>(const Derived& x1_, const Derived& x2_) { return x2_ < x1_; }
        constexpr friend bool operator<=(const Derived& x1_, const Derived& x2_) { return !(x2_ < x1_); }
        constexpr friend bool operator>=(const Derived& x1_, const Derived& x2_) { return !(x1_ < x2_); }
    };

    /*!
     * An empty class used to combine the EqualityComparable and LessThanComparable class templates
     *
     * \tparam Derived - The class with the overloaded \c operator==() and \c operator<()'s
     * \tparam   Empty - An empty base class, not really needed for the general user
     *
     * \note If we were to inherit both \c EqualityComparable and \c LessThanComparable, we could be setting ourselves to
     *  inhibit the EBCO. This way, if we do inherit an empty base class, our compiler can capitalize on that.
     */
    template<typename Derived, typename Empty = PotentiallyEmptyBaseClass<Derived>>
    class CompletelyComparable : public EqualityComparable<Derived, LessThanComparable<Derived, Empty>>
    {
    };
}   // namespace CppUtils::Operators

#endif
