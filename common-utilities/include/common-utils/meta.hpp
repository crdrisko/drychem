// Copyright (c) 2020-2021 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: meta.hpp - Version 1.0.0
// Author: crdrisko
// Date: 01/07/2021-10:19:01
// Description: The public API for the Meta section of the Common-Utilities library.
//   This header file should be included in all user programs using these utilities.
//
// Note: The internal implementation details associated with this API should not be used in any
//   user program as they are subject to change at any time without warning.

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_META_HPP

#include "meta/algorithms/basicAlgorithms.hpp"
#include "meta/algorithms/reverseList.hpp"
#include "meta/traits/containerTraits.hpp"
#include "meta/types/integer_sequences/integerSequenceAlgorithms.hpp"
#include "meta/types/tuples/tupleAlgorithms.hpp"

//! Allow for a shorter namespace name for less \c using statements
namespace DryChem
{
    inline namespace CppUtils
    {
        inline namespace Meta
        {
            using namespace ::CppUtils::Meta;
        }
    }   // namespace CppUtils
}   // namespace DryChem

#endif
