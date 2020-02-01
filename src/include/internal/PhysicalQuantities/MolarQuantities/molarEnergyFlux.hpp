// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: molarEnergyFlux.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:49:23
// Description: Defines the units, constants, and conversions of molar mass

#ifndef UTILITIES_API_MOLARENERGYFLUX_HPP
#define UTILITIES_API_MOLARENERGYFLUX_HPP

#include "../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using MolarEnergyFluxDimensionality = Dimensionality<0, 1, -3, 0, 0, -1>;
    using MolarEnergyFlux = PhysicalQuantity<MolarEnergyFluxDimensionality>;

    // MolarEnergyFlux Units
    constexpr MolarEnergyFlux operator"" _kg_mols3(long double magnitude)
    {
        return MolarEnergyFlux(magnitude);
    }
}

#endif
