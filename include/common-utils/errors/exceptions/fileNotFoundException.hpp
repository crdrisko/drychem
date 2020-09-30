// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: fileNotFoundException.hpp
// Author: crdrisko
// Date: 08/26/2020-12:44:52
// Description: An exception class used when a file cannot be found

#ifndef COMMON_UTILITIES_FILENOTFOUNDEXCEPTION_HPP
#define COMMON_UTILITIES_FILENOTFOUNDEXCEPTION_HPP

#include <string>

#include "errors/exceptions/fatalException.hpp"
#include "errors/utils/errorTypes.hpp"

namespace CommonUtilities::Errors
{
    class FileNotFoundException : public FatalException
    {
    public:
        FileNotFoundException(const std::string& ProgramName, const std::string& FileName)
            : FatalException{ ErrorMessage{ProgramName, "Unable to open file: " + FileName + '.'} } {}
    };
}

#endif
