// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: errorHandling.hpp - Version 2.0.0
// Author: cdrisko
// Date: 01/31/2020-15:38:03
// Description: Utilities for printing error messages according to an error's severity

#ifndef COMMON_UTILITIES_ERRORHANDLING_HPP
#define COMMON_UTILITIES_ERRORHANDLING_HPP

#include <cstdlib>
#include <iostream>
#include <string_view>

#include "errorTraits.hpp"
#include "errorTypes.hpp"

namespace CommonUtilities::Errors
{
    template<ErrorSeverity Severity = ErrorSeverity::Warning>
    constexpr void printErrorMessage(std::string_view programName, std::string_view message)
    {
        if constexpr(Traits::isFatal<Severity>)
        {
            std::cerr << programName << " Fatal Error:\n\t" << message << std::endl;
            std::exit(1);
        }
        else
            std::cerr << programName << " Warning:\n\t" << message << std::endl;
    }

    constexpr auto printFatalErrorMessage = [](std::string_view programName, std::string_view message) {
        printErrorMessage<ErrorSeverity::Fatal>(programName, message);
    };
}

#endif
