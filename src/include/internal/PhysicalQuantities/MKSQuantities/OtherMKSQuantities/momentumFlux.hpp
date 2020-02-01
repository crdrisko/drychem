// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: momentumFlux.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:23:43
// Description: Defines the units, constants, and conversions of molar mass

#ifndef UTILITIES_API_MOMENTUMFLUX_HPP
#define UTILITIES_API_MOMENTUMFLUX_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using MomentumFluxDimensionality = Dimensionality<-1, 1, -2>;
    using MomentumFlux = PhysicalQuantity<MomentumFluxDimensionality>;

    // MomentumFlux Units
    constexpr MomentumFlux operator"" _kg_ms2(long double magnitude)
    {
        return MomentumFlux(magnitude);
    }
}

#endif
