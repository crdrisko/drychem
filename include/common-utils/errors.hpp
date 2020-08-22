// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: errors.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:31:26
// Description: The public API for the Errors section of the Common-Utilities library.
//   This header file should be included in all user programs using these utilities.
//
// Note: The internal implementation details associated with this API should not be used in any
//   user program as they are subject to change at any time without warning.

#ifndef COMMON_UTILITIES_ERRORS_HPP
#define COMMON_UTILITIES_ERRORS_HPP

#include "internal/Errors/errorUtilities.hpp"
#include "internal/Errors/exceptionHandling.hpp"

namespace CommonUtilities::Errors
{
    enum class ErrorSeverity : bool { Warning = false, Fatal = true };
}

#endif
