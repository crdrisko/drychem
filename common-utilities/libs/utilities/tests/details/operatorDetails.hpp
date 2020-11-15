// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: operatorDetails.hpp
// Author: crdrisko
// Date: 11/15/2020-11:01:03
// Description: Details to be used with the testing of the operators portion of the utilities library

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_UTILITIES_TESTS_DETAILS_OPERATORDETAILS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_UTILITIES_TESTS_DETAILS_OPERATORDETAILS_HPP

#include <common-utils/utilities.hpp>

namespace CppUtils::Operators::details::testing
{
    //! The EBCO and CRTP used together for an empty class
    class EmptyDerived : public DryChem::PotentiallyEmptyBaseClass<EmptyDerived>
    {
    };

    class SomewhatComparable1 : private DryChem::EqualityComparable<SomewhatComparable1>
    {
    private:
        int value;

    public:
        explicit SomewhatComparable1(int Value) noexcept : value {Value} {}

        friend bool operator==(const SomewhatComparable1& lhs, const SomewhatComparable1& rhs) noexcept
        {
            return lhs.value == rhs.value;
        }
    };

    class SomewhatComparable2 : private DryChem::LessThanComparable<SomewhatComparable2>
    {
    private:
        int value;

    public:
        explicit SomewhatComparable2(int Value) noexcept : value {Value} {}

        friend bool operator<(const SomewhatComparable2& lhs, const SomewhatComparable2& rhs) noexcept
        {
            return lhs.value < rhs.value;
        }
    };

    class Comparable : private DryChem::CompletelyComparable<Comparable>
    {
    private:
        int value;

    public:
        explicit Comparable(int Value) noexcept : value {Value} {}

        friend bool operator==(const Comparable& lhs, const Comparable& rhs) noexcept { return lhs.value == rhs.value; }
        friend bool operator<(const Comparable& lhs, const Comparable& rhs) noexcept { return lhs.value < rhs.value; }
    };
}   // namespace CppUtils::Operators::details::testing

#endif
