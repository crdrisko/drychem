// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: thermalConductivity.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:45:53
// Description: Defines the units, constants, and conversions of thermal conductivity

#ifndef UTILITIES_API_THERMALCONDUCTIVITY_HPP
#define UTILITIES_API_THERMALCONDUCTIVITY_HPP

#include "../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using ThermalConductivityDimensionality = Dimensionality<1, 1, -3, 0, -1>;
    using ThermalConductivity = PhysicalQuantity<ThermalConductivityDimensionality>;

    // ThermalConductivity Units
    constexpr ThermalConductivity operator"" _W_mK(long double magnitude)
    {
        return ThermalConductivity(magnitude);
    }

    constexpr ThermalConductivity operator"" _kgm_Ks3(long double magnitude)
    {
        return ThermalConductivity(magnitude);
    }
}

#endif
