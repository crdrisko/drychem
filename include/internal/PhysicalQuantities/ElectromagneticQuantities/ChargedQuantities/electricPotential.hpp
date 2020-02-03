// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: electricPotential.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:53:24
// Description: Defines the units, constants, and conversions of electric potential

#ifndef UTILITIES_API_ELECTRICPOTENTIAL_HPP
#define UTILITIES_API_ELECTRICPOTENTIAL_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using ElectricPotentialDimensionality = Dimensionality<2, 1, -3, -1>;
    using ElectricPotential = PhysicalQuantity<ElectricPotentialDimensionality>;

    // ElectricPotential Units
    constexpr ElectricPotential operator"" _V(long double magnitude)            // Volt (V)
    {
        return ElectricPotential(magnitude);
    }

    constexpr ElectricPotential operator"" _kgm2_As3(long double magnitude)
    {
        return ElectricPotential(magnitude);
    }
}

#endif
