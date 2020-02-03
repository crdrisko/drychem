// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: specificEnergy.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:23:43
// Description: Defines the units, constants, and conversions of specific energy

#ifndef UTILITIES_API_SPECIFICENERGY_HPP
#define UTILITIES_API_SPECIFICENERGY_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using SpecificEnergyDimensionality = Dimensionality<2, 0, -2>;
    using SpecificEnergy = PhysicalQuantity<SpecificEnergyDimensionality>;

    // SpecificEnergy Units
    constexpr SpecificEnergy operator"" _J_kg(long double magnitude)
    {
        return SpecificEnergy(magnitude);
    }

    constexpr SpecificEnergy operator"" _m2_s2(long double magnitude)
    {
        return SpecificEnergy(magnitude);
    }
}

#endif
