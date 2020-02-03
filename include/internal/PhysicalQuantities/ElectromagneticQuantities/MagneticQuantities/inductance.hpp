// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: inductance.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:59:34
// Description: Defines the units, constants, and conversions of inductance

#ifndef UTILITIES_API_INDUCTANCE_HPP
#define UTILITIES_API_INDUCTANCE_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using InductanceDimensionality = Dimensionality<2, 1, -2, -2>;
    using Inductance = PhysicalQuantity<InductanceDimensionality>;

    // Inductance Units
    constexpr Inductance operator"" _H(long double magnitude)                   // Henry (H)
    {
        return Inductance(magnitude);
    }

    constexpr Inductance operator"" _kgm2_A2s2(long double magnitude)
    {
        return Inductance(magnitude);
    }
}

#endif
