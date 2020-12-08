// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: fatalException.hpp
// Author: crdrisko
// Date: 04/07/2020-11:09:24
// Description: Defines a specialized exception handling class designed around the error utilities

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_ERRORS_EXCEPTIONS_FATALEXCEPTION_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_ERRORS_EXCEPTIONS_FATALEXCEPTION_HPP

#include <exception>
#include <string>

#include "common-utils/errors/utils/errorHandling.hpp"
#include "common-utils/errors/utils/errorTypes.hpp"

namespace CppUtils::Errors
{
    /*!
     * Our main exception class deriving from \c std::exception. This class formats the supplied error 
     *  message and provides methods for handling the fatal errors it represents.
     * 
     * \note Here we make \c what() a private member function so users are forced to handle the exception
     */
    class FatalException : public std::exception
    {
    private:
        ErrorMessage error {};

        const char* what() const noexcept override { return error.message.c_str(); }

    public:
        explicit FatalException(const ErrorMessage& Error) : error {Error}
        {
            if (!error.fileName.empty() && error.lineNumber != 0ul)
                error.message = '(' + error.fileName.substr(error.fileName.find_last_of('/') + 1, error.fileName.length())
                                + ": " + std::to_string(error.lineNumber) + ")\n\t" + error.message;
        }

        //! Delegate our exception handling to the error handling classes
        void handleErrorWithMessage() const { printFatalErrorMessage(error); }
    };
}   // namespace CppUtils::Errors

#endif
