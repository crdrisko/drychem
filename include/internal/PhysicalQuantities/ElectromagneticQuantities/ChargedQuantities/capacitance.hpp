// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: capacitance.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:53:24
// Description: Defines the units, constants, and conversions of capacitance

#ifndef UTILITIES_API_CAPACITANCE_HPP
#define UTILITIES_API_CAPACITANCE_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using CapacitanceDimensionality = Dimensionality<-2, -1, 4, 2>;
    using Capacitance = PhysicalQuantity<CapacitanceDimensionality>;

    // Capacitance Units
    constexpr Capacitance operator"" _F(long double magnitude)                  // Farads (F)
    {
        return Capacitance(magnitude);
    }

    constexpr Capacitance operator"" _C_V(long double magnitude)
    {
        return Capacitance(magnitude);
    }

    constexpr Capacitance operator"" _A2s4_kgm2(long double magnitude)
    {
        return Capacitance(magnitude);
    }
}

#endif
