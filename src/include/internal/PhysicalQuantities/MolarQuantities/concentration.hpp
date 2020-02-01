// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: concentration.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:49:23
// Description: Defines the units, constants, and conversions of concentration

#ifndef UTILITIES_API_CONCENTRATION_HPP
#define UTILITIES_API_CONCENTRATION_HPP

#include "../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using ConcentrationDimensionality = Dimensionality<-3, 0, 0, 0, 0, 1>;
    using Concentration = PhysicalQuantity<ConcentrationDimensionality>;

    // Concentration Units
    constexpr Concentration operator"" _M(long double magnitude)            // Molar (M)
    {
        return Concentration(magnitude);
    }

    constexpr Concentration operator"" _mol_m3(long double magnitude)
    {
        return Concentration(magnitude);
    }
}

#endif
