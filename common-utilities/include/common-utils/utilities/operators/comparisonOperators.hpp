// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: comparisonOperators.hpp
// Author: crdrisko
// Date: 09/17/2020-12:36:17
// Description: An alternative to std::rel_opts which doesn't inject the comparison operators into the global namespace

#ifndef COMMON_UTILITIES_COMPARISONOPERATORS_HPP
#define COMMON_UTILITIES_COMPARISONOPERATORS_HPP

#include "utilities/utils/potentiallyEmptyBaseClass.hpp"

namespace CommonUtilities::Utilities
{
    template<typename Derived, typename Empty = PotentiallyEmptyBaseClass<Derived>>
    class EqualityComparable : public Empty
    {
    public:
        constexpr friend bool operator!=(const Derived& x1, const Derived& x2) { return !(x1 == x2); }
    };

    template<typename Derived, typename Empty = PotentiallyEmptyBaseClass<Derived>>
    class LessThanComparable : public Empty
    {
    public:
        constexpr friend bool operator>(const Derived& x1, const Derived& x2) { return x2 < x1; }
        constexpr friend bool operator<=(const Derived& x1, const Derived& x2) { return !(x2 < x1); }
        constexpr friend bool operator>=(const Derived& x1, const Derived& x2) { return !(x1 < x2); }
    };

    /* Note: if we were to inherit both EqualityComparable and LessThanComparable, we could be setting ourselves to
        inhibit the EBCO. This way, if we do inherit an empty base class, our compiler can capitalize on that. */
    template<typename Derived, typename Empty = PotentiallyEmptyBaseClass<Derived>>
    class CompletelyComparable : public EqualityComparable<Derived, LessThanComparable<Derived, Empty>>
    {
    };
}   // namespace CommonUtilities::Utilities

#endif
