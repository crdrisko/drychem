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
#include <string>

#include "errors/traits/isFatal.hpp"
#include "errors/utils/errorTypes.hpp"

namespace CppUtils::Errors
{
    /*!
     * A simple function to format and print an error message according to 1) the information 
     *  provided, and 2) the severity of the given error.
     * 
     * \tparam Severity The severity of the error in question (defaults to a warning message)
     * 
     * \param error The error message and other information about the location of the error
     */
    template<ErrorSeverity Severity = ErrorSeverity::Warning>
    inline void printErrorMessage(const ErrorMessage& error)
    {
        std::string message {};

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

    //! A convenience function for printing an error message when said error is fatal
    inline auto printFatalErrorMessage = [](const ErrorMessage& error) { printErrorMessage<ErrorSeverity::Fatal>(error); };
}   // namespace CppUtils::Errors

#endif
