// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: magneticFlux.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:59:34
// Description: Defines the units, constants, and conversions of magentic flux

#ifndef UTILITIES_API_MAGNETICFLUX_HPP
#define UTILITIES_API_MAGNETICFLUX_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using MagneticFluxDimensionality = Dimensionality<2, 1, -2, -1>;
    using MagneticFlux = PhysicalQuantity<MagneticFluxDimensionality>;

    // MagneticFlux Units
    constexpr MagneticFlux operator"" _Wb(long double magnitude)           // Weber (Wb)
    {
        return MagneticFlux(magnitude);
    }

    constexpr MagneticFlux operator"" _kgm2_As2(long double magnitude)
    {
        return MagneticFlux(magnitude);
    }
}

#endif
