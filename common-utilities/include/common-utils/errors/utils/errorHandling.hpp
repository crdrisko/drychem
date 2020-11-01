// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: errorHandling.hpp
// Author: cdrisko
// Date: 01/31/2020-15:38:03
// Description: Utilities for printing error messages according to an error's severity

#ifndef COMMON_UTILITIES_ERRORHANDLING_HPP
#define COMMON_UTILITIES_ERRORHANDLING_HPP

#include <cstdlib>
#include <iostream>
#include <string_view>

#include "errors/traits/isFatal.hpp"
#include "errors/utils/errorTypes.hpp"

namespace CppUtils::Errors
{
    template<ErrorSeverity Severity = ErrorSeverity::Warning>
    constexpr void printErrorMessage(const ErrorMessage& error)
    {
        std::string_view message {};

        if (error.fileName.empty() && error.lineNumber == 0ul)
            message = "\n\t" + error.message;
        else
            message = ' ' + error.message;

        if constexpr (is_fatal_v<Severity>)
        {
            std::cerr << error.programName << " Fatal Error:" << message << std::endl;
            std::exit(EXIT_FAILURE);
        }
        else
            std::cerr << error.programName << " Warning:" << message << std::endl;
    }

    // A convenience function for printing an error message when the error is fatal
    constexpr auto printFatalErrorMessage
        = [](const ErrorMessage& error) { printErrorMessage<ErrorSeverity::Fatal>(error); };
}   // namespace CppUtils::Errors

#endif
