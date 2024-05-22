// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: strings.hpp - Version 1.0.0
// Author: crdrisko
// Date: 11/06/2020-15:10:26
// Description: The public API for the Strings section of the Common-Utilities library.
//   This header file should be included in all user programs using these utilities.
//
// Note: The internal implementation details associated with this API should not be used in any
//   user program as they are subject to change at any time without warning.

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_STRINGS_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_STRINGS_HPP

#include "strings/traits/ciString.hpp"
#include "strings/utils/lexicalCast.hpp"
#include "strings/utils/stringUtils.hpp"
#include "strings/utils/tokenizer.hpp"

//! Allow for a shorter namespace name for less \c using statements
namespace DryChem
{
    inline namespace CppUtils
    {
        inline namespace Strings
        {
            using namespace ::CppUtils::Strings;
        }
    }   // namespace CppUtils
}   // namespace DryChem

#endif
