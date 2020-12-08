// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: errors.hpp - Version 3.0.0
// Author: cdrisko
// Date: 01/31/2020-15:31:26
// Description: The public API for the Errors section of the Common-Utilities library.
//   This header file should be included in all user programs using these utilities.
//
// Note: The internal implementation details associated with this API should not be used in any
//   user program as they are subject to change at any time without warning.

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_ERRORS_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_ERRORS_HPP

#include "errors/exceptions/fatalException.hpp"
#include "errors/traits/isFatal.hpp"
#include "errors/utils/errorHandling.hpp"
#include "errors/utils/errorTypes.hpp"

//! Allow for a shorter namespace name for less \c using statements
namespace DryChem
{
    inline namespace CppUtils
    {
        inline namespace Errors
        {
            using namespace ::CppUtils::Errors;
        }
    }   // namespace CppUtils
}   // namespace DryChem

#endif
