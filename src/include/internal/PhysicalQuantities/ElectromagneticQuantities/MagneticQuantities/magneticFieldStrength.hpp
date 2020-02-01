// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: magneticFieldStrength.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:59:34
// Description: Defines the units, constants, and conversions of magnetic field strength

#ifndef UTILITIES_API_MAGNETICFIELDSTRENGTH_HPP
#define UTILITIES_API_MAGNETICFIELDSTRENGTH_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using MagneticFieldStrengthDimensionality = Dimensionality<-1, 0, 0, 1>;
    using MagneticFieldStrength = PhysicalQuantity<MagneticFieldStrengthDimensionality>;

    // MagneticFieldStrength Units
    constexpr MagneticFieldStrength operator"" _A_m(long double magnitude)
    {
        return MagneticFieldStrength(magnitude);
    }
}

#endif
