// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: tokenizer.hpp
// Author: crdrisko
// Date: 11/04/2020-07:04:33
// Description: A class dedicated to splitting strings (tokens) on selected delimiters

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_STRINGS_UTILS_TOKENIZER_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_STRINGS_UTILS_TOKENIZER_HPP

#include <algorithm>
#include <forward_list>
#include <iterator>
#include <optional>
#include <string>
#include <type_traits>
#include <vector>

#include "common-utils/strings/utils/lexicalCast.hpp"
#include "common-utils/strings/utils/stringUtils.hpp"
#include "common-utils/utilities/traits/containerTraits.hpp"

namespace CppUtils::Strings
{
    namespace details
    {
        /*!
         * A type trait to determine whether or not the supplied container has a \c mapped_type member.
         *
         * \tparam (unnamed) A placeholder parameter for the container we are checking
         * \tparam (unnamed) A placeholder parameter that serves as our default state (i.e. false)
         */
        template<typename, typename = std::void_t<>>
        struct has_mapped_type : std::false_type
        {
        };

        /*!
         * A partial specialization of our \c has_mapped_type type trait for when the given
         *  container meets the requirements of having a \c mapped_type member.
         *
         * \tparam T The container that may or may not meet the requirements of having a \c mapped_type member
         */
        template<typename T>
        struct has_mapped_type<T, std::void_t<typename T::mapped_type>> : std::true_type
        {
        };
    }   // namespace details

    /*!
     * A class template which separates a given string into "tokens", which fall between
     *  specified delimiters.
     *
     * \tparam CharTraits The character traits used when comparing strings
     *
     * \note We can make use of Class Template Argument Deduction (CTAD) in most cases with the
     *       provided deduction guides.
     */
    template<typename CharTraits>
    class Tokenizer
    {
    public:
        //! Member types
        using value_type      = std::basic_string<char, CharTraits>;
        using reference       = std::basic_string<char, CharTraits>&;
        using const_reference = const std::basic_string<char, CharTraits>&;
        using iterator        = typename std::basic_string<char, CharTraits>::iterator;
        using const_iterator  = typename std::basic_string<char, CharTraits>::const_iterator;

    private:
        const_iterator str_current;
        const_iterator str_end;
        value_type delimiters;
        std::optional<value_type> keepDelimiters;

        /*!
         * A private helper function that is essentially just a wrapper for \c foundSubstr().
         *
         * \param ch The character we are evaluating from the list of delimiters
         */
        constexpr bool isDelimiter(const char ch) const noexcept { return foundSubstr(ch, delimiters); }

        /*!
         * A private helper function which iterates through the remaining string looking for
         *  the next token.
         *
         * \returns The next token we are looking for.
         */
        constexpr value_type nextToken()
        {
            value_type str {};

            if (str_current != str_end)
            {
                while (str_current != str_end && isDelimiter(*str_current))
                {
                    if (keepDelimiters && foundSubstr(*str_current, keepDelimiters.value()))
                        return value_type {*str_current++};

                    ++str_current;
                }

                while (str_current != str_end && !isDelimiter(*str_current))
                    str += value_type {*str_current++};
            }

            return str;
        }

    public:
        /*!
         * A constructor allowing for the user to pass a range to iterate through.
         *
         * \param begin      The start of our sequence to iterate over
         * \param end        The end of our sequence to iterate over
         * \param delims     The delimiters we are using as our splitting criterion
         * \param keepDelims The delimiters to include as tokens (optional)
         */
        constexpr Tokenizer(const_iterator begin, const_iterator end, const_reference delims = " \t\n",
            std::optional<value_type> keepDelims = std::nullopt)
                : str_current {begin}, str_end {end}, delimiters {delims}, keepDelimiters {keepDelims} {}

        /*!
         * Delegating constructor taking a full string instead of just a range.
         *
         * \param str        The full string we will be splitting
         * \param delims     The delimiters we are using as our splitting criterion
         * \param keepDelims The delimiters to include as tokens (optional)
         */
        explicit constexpr Tokenizer(const_reference str, const_reference delims = " \t\n",
            std::optional<value_type> keepDelims = std::nullopt)
                : str_current {str.begin()}, str_end {str.end()}, delimiters {delims}, keepDelimiters {keepDelims} {}

        /*!
         * The main function we call to split our input string into separate tokens.
         *
         * \tparam Container The container type we wish to return
         * \tparam T         The type of the value we will cast our tokens into
         *
         * \returns A container with the separated tokens cast to whatever type we specified
         *
         * \note A \c std::forward_list<> requires special treatment as it can only call \c insert_front
         */
        template<typename Container = std::vector<value_type>, typename T = typename Container::value_type,
                 typename = std::enable_if_t<std::conjunction_v<Traits::is_allocator_aware_container<Container>,
                                                                std::negation<details::has_mapped_type<Container>>>>>
        constexpr Container split()
        {
            Container tokens;

            if (str_current != str_end)
            {
                if constexpr (std::is_same_v<Container, std::forward_list<T>>)
                {
                    std::front_insert_iterator<Container> tokensIter {tokens};

                    std::for_each(str_current, str_end, [&](const auto) {
                        auto str = this->nextToken();

                        if (!str.empty())
                            *tokensIter++ = lexical_cast<T>(str);
                    });
                }
                else
                {
                    std::insert_iterator<Container> tokensIter {tokens, tokens.begin()};

                    std::for_each(str_current, str_end, [&](const auto) {
                        value_type str = this->nextToken();

                        if (!str.empty())
                            *tokensIter++ = lexical_cast<T>(str);
                    });
                }
            }

            return tokens;
        }
    };

    /*!
     * Declaration guide for the Tokenizer<> class template so we can still deduce the character
     *  traits when the other arguments are passed as character arrays.
     *
     * \tparam CharTraits The character traits we are trying to deduce
     * \tparam TArgs      Variadic template parameters representing the types of delimiters
     */
    template<typename CharTraits, typename... TArgs>
    Tokenizer(const std::basic_string<char, CharTraits>&, TArgs...) -> Tokenizer<CharTraits>;
}   // namespace CppUtils::Strings

#endif
