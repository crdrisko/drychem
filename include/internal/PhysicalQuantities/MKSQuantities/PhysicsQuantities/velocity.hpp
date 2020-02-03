// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: velocity.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:19:39
// Description: Defines the units, constants, and conversions of velocity

#ifndef UTILITIES_API_VELOCITY_HPP
#define UTILITIES_API_VELOCITY_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using VelocityDimensionality = Dimensionality<1, 0, -1>;
    using Velocity = PhysicalQuantity<VelocityDimensionality>;

    // Velocity Units
    constexpr Velocity operator"" _m_s(long double magnitude)
    {
        return Velocity(magnitude);
    }

    // Velocity Constants
    namespace Constants
    {
        constexpr Velocity speedOfLight = 299'792'458.0_m_s;
    }
}

#endif
