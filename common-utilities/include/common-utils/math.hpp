// Copyright (c) 2020-2025 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: math.hpp
// Author: crdrisko - Version 1.0.0
// Date: 10/07/2020-11:51:14
// Description: The public API for the Math section of the Common-Utilities library.
//   This header file should be included in all user programs using these utilities.
//
// Note: The internal implementation details associated with this API should not be used in any
//   user program as they are subject to change at any time without warning.

#ifndef DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_HPP
#define DRYCHEM_COMMON_UTILITIES_INCLUDE_COMMON_UTILS_MATH_HPP

#include "math/calculus/differentiation.hpp"
#include "math/calculus/integration.hpp"
#include "math/containers/vector3D.hpp"
#include "math/statistics/linearLeastSquaresFitting.hpp"
#include "math/statistics/quadraticLeastSquaresFitting.hpp"
#include "math/statistics/statistics.hpp"
#include "math/utils/basicMath.hpp"
#include "math/utils/mathExceptions.hpp"

//! Allow for a shorter namespace name for less \c using statements
namespace DryChem
{
    inline namespace CppUtils
    {
        inline namespace Math
        {
            using namespace ::CppUtils::Math;
        }
    }   // namespace CppUtils
}   // namespace DryChem

#endif
