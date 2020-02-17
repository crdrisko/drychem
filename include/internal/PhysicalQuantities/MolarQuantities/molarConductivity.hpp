// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: molarConductivity.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:49:23
// Description: Defines the units, constants, and conversions of molar conductivity

#ifndef UTILITIES_API_MOLARCONDUCTIVITY_HPP
#define UTILITIES_API_MOLARCONDUCTIVITY_HPP

#include "concentration.hpp"
#include "../ElectromagneticQuantities/ChargedQuantities/electricConductivity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using MolarConductivityDimensionality = Dimensionality<0, -1, 3, 2, 0, -1>;
    using MolarConductivity = PhysicalQuantity<MolarConductivityDimensionality>;

    // MolarConductivity Units
    constexpr MolarConductivity operator"" _Sm2_mol(long double magnitude)
    {
        return MolarConductivity(magnitude);
    }

    constexpr MolarConductivity operator"" _A2s3_kgmol(long double magnitude)
    {
        return MolarConductivity(magnitude);
    }

    // MolarConductivity Calculations
    namespace Calculations
    {
        constexpr MolarConductivity calculateMolarConductivity(ElectricConductivity sigma, Concentration conc)
        {
            return sigma / conc;
        }
    }
}

#endif
