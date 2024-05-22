// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: errorHandling.hpp
// Author: cdrisko
// Date: 01/31/2020-15:38:03
// Description: Utilities for printing error messages according to an error's severity

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_ERRORS_UTILS_ERRORHANDLING_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_ERRORS_UTILS_ERRORHANDLING_HPP

#include <cstdlib>
#include <iostream>
#include <sstream>

#include "common-utils/errors/traits/isFatal.hpp"
#include "common-utils/errors/utils/errorTypes.hpp"

namespace CppUtils::Errors
{
    /*!
     * A simple function to format and print an error message according to 1) the information 
     *  provided, and 2) the severity of the given error.
     * 
     * \tparam Severity - The severity of the error in question (defaults to a warning message)
     * 
     * \param error - The error message and other information about the location of the error
     */
    template<ErrorSeverity Severity = ErrorSeverity::Warning>
    inline void printErrorMessage(const ErrorMessage& error)
    {
        std::stringstream errorMessage;

        if (error.fileName.empty() && error.lineNumber == 0ul)
            errorMessage << "\n    " << error.message;
        else
            errorMessage << ' ' << error.message;

        if constexpr (is_fatal_v<Severity>)
        {
            std::cerr << error.programName << " Fatal Error:" << errorMessage.str() << std::endl;
            std::exit(EXIT_FAILURE);
        }
        else
            std::cerr << error.programName << " Warning:" << errorMessage.str() << std::endl;
    }

    //! A convenience function for printing an error message when said error is fatal
    inline auto printFatalErrorMessage = [](const ErrorMessage& error) { printErrorMessage<ErrorSeverity::Fatal>(error); };
}   // namespace CppUtils::Errors

#endif
