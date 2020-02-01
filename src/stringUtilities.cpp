// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: stringUtilities.cpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:22:40
// Description: Additional string functions and utilities

#include "include/internal/Strings/stringUtilities.hpp"

namespace Utilities_API::Strings
{
    std::vector<std::string> splitString(std::string inputString, std::string separators)
    {
        std::vector<std::string> words;
        size_t start {inputString.find_first_not_of(separators)};

        while (start != std::string::npos)
        {
            size_t end = inputString.find_first_of(separators, start + 1);

            if (end == std::string::npos)
                end = inputString.length();

            words.push_back(inputString.substr(start, end - start));

            start = inputString.find_first_not_of(separators, end + 1);
        }
        return words;
    }
}
