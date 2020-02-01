// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: force.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:19:39
// Description: Defines the units, constants, and conversions of force

#ifndef UTILITIES_API_FORCE_HPP
#define UTILITIES_API_FORCE_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using ForceDimensionality = Dimensionality<1, 1, -2>;
    using Force = PhysicalQuantity<ForceDimensionality>;

    // Force Units
    constexpr Force operator"" _N(long double magnitude)                // Newton (N)
    {
        return Force(magnitude);
    }

    constexpr Force operator"" _kgm_s2(long double magnitude)
    {
        return Force(magnitude);
    }
}

#endif
