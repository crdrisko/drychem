// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: stringUtilities.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:41:47
// Description: Additional string functions and utilities

#ifndef UTILITIES_API_STRINGUTILITIES_HPP
#define UTILITIES_API_STRINGUTILITIES_HPP

#include <vector>
#include <string>
#include <string_view>

namespace Utilities_API::Strings
{
    std::vector<std::string> splitString(std::string inputString, std::string separators = " \t\n");

    inline bool stringFinder(std::string_view stringToFind, std::string_view stringToSearch)
    {
        return (stringToSearch.find(stringToFind) != std::string::npos) ? true : false;
    }
}

#endif
