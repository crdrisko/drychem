// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: power.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:19:39
// Description: Defines the units, constants, and conversions of power

#ifndef UTILITIES_API_POWER_HPP
#define UTILITIES_API_POWER_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using PowerDimensionality = Dimensionality<2, 1, -3>;
    using Power = PhysicalQuantity<PowerDimensionality>;

    // Power Units
    constexpr Power operator"" _W(long double magnitude)            // Watts (W)
    {
        return Power(magnitude);
    }

    constexpr Power operator"" _kgm2_s3(long double magnitude)
    {
        return Power(magnitude);
    }
}

#endif
