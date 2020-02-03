// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: momentum.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:19:39
// Description: Defines the units, constants, and conversions of momentum

#ifndef UTILITIES_API_MOMENTUM_HPP
#define UTILITIES_API_MOMENTUM_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using MomentumDimensionality = Dimensionality<1, 1, -1>;
    using Momentum = PhysicalQuantity<MomentumDimensionality>;

    // Momentum Units
    constexpr Momentum operator"" _kgm_s(long double magnitude)
    {
        return Momentum(magnitude);
    }
}

#endif
