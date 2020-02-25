// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: mobility.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:53:24
// Description: Defines the units, constants, and conversions of mobility

#ifndef UTILITIES_API_MOBILITY_HPP
#define UTILITIES_API_MOBILITY_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using MobilityDimensionality = Dimensionality<0, -1, 2, 1>;
    using Mobility = PhysicalQuantity<MobilityDimensionality>;

    // Mobility Units
    constexpr Mobility operator"" _m2_Vs(long double magnitude)
    {
        return Mobility(magnitude);
    }

    constexpr Mobility operator"" _As2_kg(long double magnitude)
    {
        return Mobility(magnitude);
    }
}

#endif
