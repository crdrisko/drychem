// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: lexicalCast.hpp
// Author: crdrisko
// Date: 11/05/2020-07:34:56
// Description: A common function for converting between strings and other (input streamable) types

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_STRINGS_UTILS_LEXICALCAST_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_STRINGS_UTILS_LEXICALCAST_HPP

#include <sstream>
#include <string>
#include <type_traits>
#include <utility>

#include "common-utils/errors/utils/errorHandling.hpp"
#include "common-utils/errors/utils/errorTypes.hpp"

namespace CppUtils::Strings
{
    /*!
     * A simple function for converting a string to another type.
     * 
     * \tparam T          The type to convert the input string to, must be input streamable
     * \tparam CharTraits A trait allowing for either case-sensitive or case-insensitive searches
     * 
     * \param str The input string to convert
     * 
     * \returns Either the converted value if nothing goes wrong, or the default constructed value 
     *          and a warning message if something does.
     */
    template<typename T, typename CharTraits = std::char_traits<char>>
    inline auto lexical_cast(const std::basic_string<char, CharTraits>& str)
    {
        if constexpr (std::is_same_v<T, std::basic_string<char, CharTraits>>)
            return str;
        else
        {
            try
            {
                T var;
                std::basic_istringstream<char, CharTraits> stream;

                stream.str(str);
                stream.exceptions(std::ios::failbit | std::ios_base::badbit);

                stream >> var;

                return var;
            }
            catch (const std::ios_base::failure& fail)
            {
                Errors::printErrorMessage(
                    Errors::ErrorMessage {"Common-Utilities", "Error in lexical_cast, default value returned."});

                return T {};
            }
        }
    }

    /*!
     * \overload
     */
    template<typename TO, typename FROM, typename = std::enable_if_t<std::is_pointer_v<std::decay_t<FROM>>>>
    inline auto lexical_cast(FROM&& str)
    {
        return lexical_cast<TO, std::char_traits<char>>(std::forward<FROM>(str));
    }
}   // namespace CppUtils::Strings

/*!
 * A macro for creating specializations of the \c lexical_cast<> template where 
 *  the standard library already has functions specificically for this purpose.
 * 
 * \note A full specialization is possible here because it doesn't matter if the 
 *  input string is case-sensitive or not, all we're looking for are the integers
 *  that make up the number.
 */
#define DEFINE_LEXI_CAST_OVERLOAD(TYPE, ABBREVIATION)                                                                       \
    template<>                                                                                                              \
    inline auto ::CppUtils::Strings::lexical_cast<TYPE, std::char_traits<char>>(const std::string& str)                     \
    {                                                                                                                       \
        return std::sto##ABBREVIATION(str);                                                                                 \
    }

DEFINE_LEXI_CAST_OVERLOAD(long double, ld)
DEFINE_LEXI_CAST_OVERLOAD(double, d)
DEFINE_LEXI_CAST_OVERLOAD(float, f)
DEFINE_LEXI_CAST_OVERLOAD(int, i)
DEFINE_LEXI_CAST_OVERLOAD(long, l)
DEFINE_LEXI_CAST_OVERLOAD(unsigned long, ul)
DEFINE_LEXI_CAST_OVERLOAD(long long, ll)
DEFINE_LEXI_CAST_OVERLOAD(unsigned long long, ull)

//! Limit the scope of the macro by undefining it here
#undef DEFINE_LEXI_CAST_OVERLOAD

#endif
