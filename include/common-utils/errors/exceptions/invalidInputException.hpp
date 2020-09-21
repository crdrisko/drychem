// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: invalidInputException.hpp - Version 2.0.0
// Author: crdrisko
// Date: 08/26/2020-12:44:36
// Description: An exception class used when some type of input is invalid

#ifndef COMMON_UTILITIES_INVALIDINPUTEXCEPTION_HPP
#define COMMON_UTILITIES_INVALIDINPUTEXCEPTION_HPP

#include <string_view>

#include "errors/exceptions/fatalException.hpp"
#include "errors/utils/errorTypes.hpp"

namespace CommonUtilities::Errors
{
    class InvalidInputException : public FatalException
    {
    public:
        explicit InvalidInputException(std::string_view ProgramName,
            std::string_view Message = "The user-supplied input is invalid.")
                : FatalException{ ErrorMessage(ProgramName, Message) } {}
    };
}

#endif
