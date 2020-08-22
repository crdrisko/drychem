// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: stringUtilities.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:41:47
// Description: Additional string functions and utilities

#ifndef COMMON_UTILITIES_STRINGUTILITIES_HPP
#define COMMON_UTILITIES_STRINGUTILITIES_HPP

#include <string>
#include <string_view>
#include <vector>

namespace CommonUtilities::Strings
{
    constexpr bool stringFinder(std::string_view stringToFind, std::string_view stringToSearch)
    {
        return (stringToSearch.find(stringToFind) != std::string::npos) ? true : false;
    }


    inline std::vector<std::string> splitString(std::string_view stringToSplit,
        std::string_view separators = " \t\n")
    {
        std::vector<std::string> words;
        std::size_t startOfWord { stringToSplit.find_first_not_of(separators) };

        while (startOfWord != std::string::npos)
        {
            std::size_t endOfWord { stringToSplit.find_first_of(separators, startOfWord + 1) };

            if (endOfWord == std::string::npos)
                endOfWord = stringToSplit.length();

            words.push_back( std::string{stringToSplit.substr(startOfWord, endOfWord - startOfWord)} );

            startOfWord = stringToSplit.find_first_not_of(separators, endOfWord + 1);
        }

        return words;
    }
}

#endif
