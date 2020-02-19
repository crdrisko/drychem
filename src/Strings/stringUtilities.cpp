// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: stringUtilities.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:22:40
// Description: Additional string functions and utilities

#include "../../include/internal/Strings/stringUtilities.hpp"

namespace Utilities_API::Strings
{
    std::vector<std::string> splitString(const std::string& inputString, const std::string& separators)
    {
        std::vector<std::string> words;
        size_t startOfWord {inputString.find_first_not_of(separators)};

        while (startOfWord != std::string::npos)
        {
            size_t endOfWord = inputString.find_first_of(separators, startOfWord + 1);

            if (endOfWord == std::string::npos)
                endOfWord = inputString.length();

            words.push_back(inputString.substr(startOfWord, endOfWord - startOfWord));

            startOfWord = inputString.find_first_not_of(separators, endOfWord + 1);
        }

        return words;
    }
}
