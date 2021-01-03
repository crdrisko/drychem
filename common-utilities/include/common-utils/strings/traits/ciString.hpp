// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: ciString.hpp
// Author: crdrisko
// Date: 11/03/2020-07:26:03
// Description: Defining a new char_traits class and associated utilities for case-insensitive string comparisons

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_STRINGS_TRAITS_CISTRING_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_STRINGS_TRAITS_CISTRING_HPP

#include <cstddef>
#include <iostream>
#include <string>

namespace CppUtils::Strings
{
    /*!
     * A character traits structure allowing for case-insensitive string comparisons. Overloads
     *  the functions it needs and inherits the rest from \c std::char_traits<char>.
     */
    struct ci_char_traits : public std::char_traits<char>
    {
        /*!
         * Convert a character, \c ch, to uppercase at compile-time.
         * 
         * \param ch The character to convert to uppercase
         * 
         * \returns The uppercase version of \c ch if \c ch falls between 'a' and 'z' inclusive
         */
        static constexpr char ct_toupper(char ch) noexcept
        {
            if (ch >= 'a' && ch <= 'z')
                return ch - 'a' + 'A';

            return ch;
        }

        /*!
         * Lexicographically, and without regard to case, compares the first \c count 
         *  characters of the character strings \c s1 and \c s2.
         * 
         * \param s1    A pointer to the first character string to compare
         * \param s2    A pointer to the second character string to compare
         * \param count The number of characters to compare from each character string
         * 
         * \returns Zero if the two strings are equal or count is zero
         */
        static constexpr int compare(const char* s1, const char* s2, std::size_t count) noexcept
        {
            while (count-- != 0)
            {
                if (ct_toupper(*s1) < ct_toupper(*s2))
                    return -1;

                if (ct_toupper(*s1) > ct_toupper(*s2))
                    return 1;

                ++s1;
                ++s2;
            }

            return 0;
        }

        /*!
         * Searches for character \c ch within the first \c count characters of the sequence
         *  pointed to by \c p.
         * 
         * \param p     A pointer to a character string to search
         * \param count The number of characters to analyze
         * \param ch    The character to search for
         * 
         * \returns \c nullptr if \c ch is not found in the string or count is 0
         */
        static constexpr const char* find(const char* p, std::size_t count, const char& ch) noexcept
        {
            const auto CH {ct_toupper(ch)};

            while (count-- != 0)
            {
                if (ct_toupper(*p) == CH)
                    return p;

                ++p;
            }

            return nullptr;
        }

        static constexpr bool eq(char a, char b) noexcept { return ct_toupper(a) == ct_toupper(b); }
        static constexpr bool lt(char a, char b) noexcept { return ct_toupper(a) < ct_toupper(b); }
    };


    /*! 
     * A simple function for casting one char_trait to another
     * 
     * \param input An input string with some char_traits
     * 
     * \returns An output string with another type of char_traits
     */
    template<class OutputTraits, class InputTraits>
    constexpr std::basic_string<char, OutputTraits> traits_cast(const std::basic_string<char, InputTraits>& input) noexcept
    {
        std::basic_string<char, OutputTraits> ouput {input.data(), input.size()};
        return ouput;
    }


    /*! 
     * Allow for case-insensitive strings to be inserted into a ouput stream 
     *  like a normal \c std::string.
     * 
     * \param os  A character output stream
     * \param str The string to be inserted     
     */
    inline std::ostream& operator<<(std::ostream& os, const std::basic_string<char, ci_char_traits>& str)
    {
        os << str.c_str();
        return os;
    }


    //! Type alias for case-insensitive strings
    using ci_string = std::basic_string<char, ci_char_traits>;
}   // namespace CppUtils::Strings

#endif
