// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: permeability.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:59:34
// Description: Defines the units, constants, and conversions of permeability

#ifndef UTILITIES_API_PERMEABILITY_HPP
#define UTILITIES_API_PERMEABILITY_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using PermeabilityDimensionality = Dimensionality<1, 1, -2, -2>;
    using Permeability = PhysicalQuantity<PermeabilityDimensionality>;

    // Permeability Units
    constexpr Permeability operator"" _H_m(long double magnitude)
    {
        return Permeability(magnitude);
    }

    constexpr Permeability operator"" _N_A2(long double magnitude)
    {
        return Permeability(magnitude);
    }

    constexpr Permeability operator"" _kgm_A2s2(long double magnitude)
    {
        return Permeability(magnitude);
    }
}

#endif
