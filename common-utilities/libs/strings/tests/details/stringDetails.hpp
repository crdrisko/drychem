// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: stringDetails.hpp
// Author: crdrisko
// Date: 11/15/2020-07:26:05
// Description: Details to be used with the testing of the strings library

#ifndef DRYCHEM_COMMON_UTILITIES_LIBS_STRINGS_TESTS_DETAILS_STRINGDETAILS_HPP
#define DRYCHEM_COMMON_UTILITIES_LIBS_STRINGS_TESTS_DETAILS_STRINGDETAILS_HPP

#include <iostream>
#include <string>

namespace CppUtils::Strings::details::testing
{
    class GoodValue
    {
    private:
        int val {};

    public:
        GoodValue() = default;
        explicit GoodValue(int Val) : val {Val} {}

        int getValue() const { return val; }

        friend std::istream& operator>>(std::istream& stream, GoodValue& rhs)
        {
            std::string str {};
            stream >> str;

            rhs.val = std::stoi(str);

            return stream;
        }
    };

    class BadValue : public GoodValue
    {
    public:
        BadValue() = default;
        explicit BadValue(int Val) : GoodValue {Val} {}

        friend std::istream& operator>>(std::istream& stream, BadValue&)
        {
            stream.setstate(std::ios::badbit);

            return stream;
        }
    };

    class FailValue : public GoodValue
    {
    public:
        FailValue() = default;
        explicit FailValue(int Val) : GoodValue {Val} {}

        friend std::istream& operator>>(std::istream& stream, FailValue&)
        {
            stream.setstate(std::ios::failbit);

            return stream;
        }
    };
}   // namespace CppUtils::Strings::details::testing

#endif
