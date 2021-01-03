// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: fileExceptions.hpp
// Author: crdrisko
// Date: 12/30/2020-17:26:56
// Description: Exception classes specifically made for errors that could arrise in file-related functions

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_FILES_UTILS_FILEEXCEPTIONS_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_FILES_UTILS_FILEEXCEPTIONS_HPP

#include <cstddef>
#include <string>

#include "common-utils/errors/exceptions/fatalException.hpp"
#include "common-utils/errors/utils/errorTypes.hpp"

namespace CppUtils::Files
{
    /*!
     * An exception class used specifically for the file handling libraries when the requested file
     *  can not be found.
     */
    class FileNotFound : public Errors::FatalException
    {
    public:
        FileNotFound(const std::string& programName, const std::string& fileName, std::size_t lineNumber)
            : Errors::FatalException {Errors::ErrorMessage {programName, "Could not find the requested file.",
                fileName, lineNumber}}
        {
        }
    };
}   // namespace CppUtils::Files

#endif
