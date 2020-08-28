// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: errorTypes.hpp - Version 2.0.0
// Author: crdrisko
// Date: 08/26/2020-14:53:34
// Description: Common types to be used with the various error handling techniques

#ifndef COMMON_UTILITIES_ERRORTYPES_HPP
#define COMMON_UTILITIES_ERRORTYPES_HPP

#include <string>
#include <string_view>

namespace CommonUtilities::Errors
{
    enum class ErrorSeverity
    {
        Warning,
        Fatal
    };

    struct ErrorMessage
    {
        std::string programName;
        std::string message;

        ErrorMessage() noexcept = default;
        ErrorMessage(std::string_view ProgramName, std::string_view Message) noexcept
            : programName{ProgramName}, message{Message} {}
    };
}

#endif
