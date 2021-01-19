// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: stringUtils.hpp
// Author: cdrisko
// Date: 01/31/2020-15:41:47
// Description: A collection of random string utilities and functions

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_STRINGS_UTILS_STRINGUTILS_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_STRINGS_UTILS_STRINGUTILS_HPP

#include <string>

namespace CppUtils::Strings
{
    /*!
     * A predicate wrapper for std::basic_string<char, CharTraits>::find() that returns whether the 
     *  substring \c stringToFind was found in \c stringToSearch.
     * 
     * \tparam CharTraits - A trait allowing for either case-sensitive or case-insensitive searches
     * 
     * \param   stringToFind - The string/substring to seach for
     * \param stringToSearch - The string to seach through
     */
    template<typename CharTraits>
    constexpr bool foundSubstr(const std::basic_string<char, CharTraits>& stringToFind,
        const std::basic_string<char, CharTraits>& stringToSearch) noexcept
    {
        if (stringToSearch.find(stringToFind) != std::basic_string<char, CharTraits>::npos)
            return true;
        else
            return false;
    }

    /*!
     * \overload
     */
    template<typename CharTraits>
    constexpr bool foundSubstr(char stringToFind, const std::basic_string<char, CharTraits>& stringToSearch) noexcept
    {
        if (stringToSearch.find(stringToFind) != std::basic_string<char, CharTraits>::npos)
            return true;
        else
            return false;
    }

    /*!
     * \overload
     */
    template<typename CharTraits>
    constexpr bool foundSubstr(const char* stringToFind, const std::basic_string<char, CharTraits>& stringToSearch) noexcept
    {
        if (stringToSearch.find(stringToFind) != std::basic_string<char, CharTraits>::npos)
            return true;
        else
            return false;
    }
}   // namespace CppUtils::Strings

#endif
