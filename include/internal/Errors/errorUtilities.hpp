// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: errorUtilities.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:38:03
// Description: Error handling functions and utilities

#ifndef UTILITIES_API_ERRORUTILITIES_HPP
#define UTILITIES_API_ERRORUTILITIES_HPP

#include <cstdlib>
#include <iostream>
#include <string_view>

namespace Utilities_API::Errors
{
    inline void printNonFatalErrorMessage(std::string_view message)
    {
        std::cerr << message << std::endl;
    }

    inline void printFatalErrorMessage(int error_code, std::string_view message)
    {
        printNonFatalErrorMessage(message);
        std::exit(error_code);
    }
}

#endif
