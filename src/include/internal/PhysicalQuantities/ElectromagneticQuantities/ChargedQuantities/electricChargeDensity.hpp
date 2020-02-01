// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: electricChargeDensity.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:53:24
// Description: Defines the units, constants, and conversions of electric charge density

#ifndef UTILITIES_API_ELECTRICCHARGEDENSITY_HPP
#define UTILITIES_API_ELECTRICCHARGEDENSITY_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using ElectricChargeDensityDimensionality = Dimensionality<-3, 0, 1, 1>;
    using ElectricChargeDensity = PhysicalQuantity<ElectricChargeDensityDimensionality>;

    // ElectricChargeDensity Units
    constexpr ElectricChargeDensity operator"" _C_m3(long double magnitude)
    {
        return ElectricChargeDensity(magnitude);
    }

    constexpr ElectricChargeDensity operator"" _As_m3(long double magnitude)
    {
        return ElectricChargeDensity(magnitude);
    }
}

#endif
