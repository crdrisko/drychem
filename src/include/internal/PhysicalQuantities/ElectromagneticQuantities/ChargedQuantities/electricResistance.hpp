// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: electricResistance.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:53:24
// Description: Defines the units, constants, and conversions of electric resistance

#ifndef UTILITIES_API_ELECTRICRESISTANCE_HPP
#define UTILITIES_API_ELECTRICRESISTANCE_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using ElectricResistanceDimensionality = Dimensionality<2, 1, -3, -2>;
    using ElectricResistance = PhysicalQuantity<ElectricResistanceDimensionality>;

    // ElectricResistance Units
    constexpr ElectricResistance operator"" _Ohm(long double magnitude)         // Ohm
    {
        return ElectricResistance(magnitude);
    }

    constexpr ElectricResistance operator"" _kgm2_A2s3(long double magnitude)
    {
        return ElectricResistance(magnitude);
    }
}

#endif
