// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: exceptionHandling.hpp - Version 1.0.0
// Author: crdrisko
// Date: 04/07/2020-11:09:24
// Description: Defines a specialized exception handling classes designed around the error utilities

#ifndef UTILITIES_API_EXCEPTIONHANDLING_HPP
#define UTILITIES_API_EXCEPTIONHANDLING_HPP

#include <exception>
#include <memory>
#include <string>
#include <string_view>

#include "errorUtilities.hpp"

namespace Utilities_API::Errors
{
    // Forward declare ErrorSeverity, the preferred method of Exception instantiation
    enum class ErrorSeverity : bool;


    class Exception : public std::exception
    {
    private:
        std::string programName;
        std::string message;
        bool isErrorFatal;

        ErrorMessagePtr errorMessage;

    public:
        Exception(std::string_view ProgramName, std::string_view Message, bool IsErrorFatal)
            : programName{ProgramName}, message{Message}, isErrorFatal{IsErrorFatal}
        {
            if (isErrorFatal)
                errorMessage = std::make_shared<FatalErrorMessage>(programName + " Fatal Error", 1);
            else
                errorMessage = std::make_shared<ErrorMessage>(programName + " Warning");
        }

        Exception(std::string_view ProgramName, std::string_view Message, ErrorSeverity Severity)
            : Exception{ ProgramName, Message, static_cast<bool>(Severity) } {}

        bool isFatal() const { return isErrorFatal; }

        // Delegate our exception handling to the error handling classes
        void handleErrorWithMessage() const { errorMessage->printErrorMessage(message); }

        virtual const char* what() const noexcept override
        {
            // Program needs to exit if error is fatal, regardless of where it is caught
            if (isErrorFatal)
                handleErrorWithMessage();

            return message.c_str();
        }
    };


    class InvalidInputException : public Exception
    {
    public:
        explicit InvalidInputException(std::string_view ProgramName,
            std::string_view Message = "User supplied input is invalid.")
                : Exception{ProgramName, Message, true} {}
    };


    class FileNotFoundException : public Exception
    {
    public:
        FileNotFoundException(std::string_view ProgramName, std::string_view FileName)
            : Exception{ProgramName, "Unable to open file: " + std::string{FileName}, true} {}
    };
}

#endif
