// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: acceleration.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:19:39
// Description: Defines the units, constants, and conversions of acceleration

#ifndef UTILITIES_API_ACCELERATION_HPP
#define UTILITIES_API_ACCELERATION_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using AccelerationDimensionality = Dimensionality<1, 0, -2>;
    using Acceleration = PhysicalQuantity<AccelerationDimensionality>;

    // Acceleration Units
    constexpr Acceleration operator"" _m_s2(long double magnitude)
    {
        return Acceleration(magnitude);
    }
}

#endif
