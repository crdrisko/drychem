// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: files.hpp - Version 1.0.0
// Author: crdrisko
// Date: 11/17/2020-13:49:28
// Description: The public API for the Files section of the Common-Utilities library.
//   This header file should be included in all user programs using these utilities.
//
// Note: The internal implementation details associated with this API should not be used in any
//   user program as they are subject to change at any time without warning.

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_FILES_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_FILES_HPP

#include "files/fileParsing/fileParser.hpp"
#include "files/fileParsing/parserStrategies.hpp"
#include "files/utils/fileExceptions.hpp"

//! Allow for a shorter namespace name for less \c using statements
namespace DryChem
{
    inline namespace CppUtils
    {
        inline namespace Files
        {
            using namespace ::CppUtils::Files;
        }
    }   // namespace CppUtils
}   // namespace DryChem

#endif
