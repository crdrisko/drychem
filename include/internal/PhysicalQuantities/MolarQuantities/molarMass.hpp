// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: molarMass.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:49:23
// Description: Defines the units, constants, and conversions of molar mass

#ifndef UTILITIES_API_MOLARMASS_HPP
#define UTILITIES_API_MOLARMASS_HPP

#include "../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using MolarMassDimensionality = Dimensionality<0, 1, 0, 0, 0, -1>;
    using MolarMass = PhysicalQuantity<MolarMassDimensionality>;

    // MolarMass Units
    constexpr MolarMass operator"" _g_mol(long double magnitude)
    {
        return MolarMass(magnitude);
    }

    constexpr MolarMass operator"" _amu(long double magnitude)
    {
        return MolarMass(magnitude);
    }
}

#endif
