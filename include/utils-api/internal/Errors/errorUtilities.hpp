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
#include <memory>
#include <string>
#include <string_view>

namespace Utilities_API::Errors
{
    class ErrorMessage
    {
    private:
        std::string projectName;

    public:
        explicit ErrorMessage(std::string_view ProjectName) noexcept : projectName{ProjectName} {}
        virtual ~ErrorMessage() = default;

        virtual void printErrorMessage(std::string_view message) const
        {
            std::cerr << projectName << ":\n\t" << message << std::endl;
        }
    };

    using ErrorMessagePtr = std::shared_ptr<ErrorMessage>;


    class FatalErrorMessage : public ErrorMessage
    {
    private:
        int exitCode;

    public:
        FatalErrorMessage(std::string_view ProjectName, int ExitCode) noexcept : ErrorMessage{ProjectName},
            exitCode{ExitCode} {}

        virtual void printErrorMessage(std::string_view message) const override
        {
            ErrorMessage::printErrorMessage(message);
            std::exit(exitCode);
        }
    };
}

#endif
