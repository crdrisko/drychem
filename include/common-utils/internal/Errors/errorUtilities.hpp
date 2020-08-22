// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: errorUtilities.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:38:03
// Description: Error handling functions and utilities

#ifndef COMMON_UTILITIES_ERRORUTILITIES_HPP
#define COMMON_UTILITIES_ERRORUTILITIES_HPP

#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>
#include <string_view>

namespace CommonUtilities::Errors
{
    class ErrorMessage
    {
    private:
        std::string programName;

    public:
        explicit ErrorMessage(std::string_view ProgramName) : programName{ProgramName} {}
        virtual ~ErrorMessage() = default;

        virtual void printErrorMessage(std::string_view message) const
        {
            std::cerr << programName << ":\n\t" << message << std::endl;
        }
    };

    using ErrorMessagePtr = std::shared_ptr<ErrorMessage>;


    class FatalErrorMessage : public ErrorMessage
    {
    private:
        int exitCode;

    public:
        FatalErrorMessage(std::string_view ProgramName, int ExitCode)
            : ErrorMessage{ProgramName}, exitCode{ExitCode} {}

        virtual void printErrorMessage(std::string_view message) const override
        {
            ErrorMessage::printErrorMessage(message);
            std::exit(exitCode);
        }
    };
}

#endif
