// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: utilities.hpp - Version 1.3.0
// Author: crdrisko
// Date: 09/17/2020-12:35:51
// Description: The public API for the Utilities section of the Common-Utilities library.
//   This header file should be included in all user programs using these utilities.
//
// Note: The internal implementation details associated with this API should not be used in any
//   user program as they are subject to change at any time without warning.

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_UTILITIES_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_UTILITIES_HPP

#include "utilities/operators/comparisonOperators.hpp"
#include "utilities/operators/potentiallyEmptyBaseClass.hpp"
#include "utilities/testing/performanceTesting.hpp"

//! Allow for a shorter namespace name for less \c using statements
namespace DryChem
{
    inline namespace CppUtils
    {
        inline namespace Operators
        {
            using namespace ::CppUtils::Operators;
        }

        inline namespace Testing
        {
            using namespace ::CppUtils::Testing;
        }
    }   // namespace CppUtils
}   // namespace DryChem

#endif
