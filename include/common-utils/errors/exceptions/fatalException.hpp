// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: fatalException.hpp - Version 2.0.1
// Author: crdrisko
// Date: 04/07/2020-11:09:24
// Description: Defines a specialized exception handling class designed around the error utilities

#ifndef COMMON_UTILITIES_FATALEXCEPTION_HPP
#define COMMON_UTILITIES_FATALEXCEPTION_HPP

#include <exception>

#include "../utils/errorHandling.hpp"
#include "../utils/errorTypes.hpp"

namespace CommonUtilities::Errors
{
    class FatalException : public std::exception
    {
    private:
        ErrorMessage error;

        // Making what() a private member function so users are forced to handle the exception
        virtual const char* what() const noexcept override { return error.message.c_str(); }

    public:
        explicit FatalException(const ErrorMessage& Error) : error{Error}
        {
            if ( error.programName.empty() || error.message.empty() )
            {
                // This specific error is always fatal but needs to override the current exception that was thrown
                printFatalErrorMessage("Common-Utilities", "Program name and error message must be set.");
            }
        }

        // Delegate our exception handling to the error handling classes
        void handleErrorWithMessage() const { printFatalErrorMessage(error.programName, error.message); }
    };
}

#endif
