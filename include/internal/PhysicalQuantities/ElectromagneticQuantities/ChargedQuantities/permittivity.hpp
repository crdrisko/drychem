// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: permittivity.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:53:24
// Description: Defines the units, constants, and conversions of permittivity

#ifndef UTILITIES_API_PERMITTIVITY_HPP
#define UTILITIES_API_PERMITTIVITY_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using PermittivityDimensionality = Dimensionality<-3, -1, 4, 2>;
    using Permittivity = PhysicalQuantity<PermittivityDimensionality>;

    // Permittivity Units
    constexpr Permittivity operator"" _F_m(long double magnitude)
    {
        return Permittivity(magnitude);
    }

    constexpr Permittivity operator"" _A2s4_kgm3(long double magnitude)
    {
        return Permittivity(magnitude);
    }

    // Permittivity Constants
    namespace Constants
    {
        constexpr Permittivity permittivityFreeSpace = 8.8541878128e-12_F_m;
    }
}

#endif
