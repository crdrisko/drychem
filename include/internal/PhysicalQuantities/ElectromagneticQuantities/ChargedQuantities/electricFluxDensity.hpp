// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: electricFluxDensity.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:53:24
// Description: Defines the units, constants, and conversions of electric flux density

#ifndef UTILITIES_API_ELECTRICFLUXDENSITY_HPP
#define UTILITIES_API_ELECTRICFLUXDENSITY_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using ElectricFluxDensityDimensionality = Dimensionality<-2, 0, 1, 1>;
    using ElectricFluxDensity = PhysicalQuantity<ElectricFluxDensityDimensionality>;

    // ElectricFluxDensity
    constexpr ElectricFluxDensity operator"" _C_m2(long double magnitude)
    {
        return ElectricFluxDensity(magnitude);
    }

    constexpr ElectricFluxDensity operator"" _As_m2(long double magnitude)
    {
        return ElectricFluxDensity(magnitude);
    }
}

#endif
