// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: faradays.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:49:23
// Description: Defines the units, constants, and conversions of faradays

#ifndef UTILITIES_API_FARADAYS_HPP
#define UTILITIES_API_FARADAYS_HPP

#include "amountOfSubstance.hpp"
#include "../ElectromagneticQuantities/ChargedQuantities/electricCharge.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using FaradaysDimensionality = Dimensionality<0, 0, 1, 1, 0, -1>;
    using Faradays = PhysicalQuantity<FaradaysDimensionality>;

    // Faradays Units
    constexpr Faradays operator"" _C_mol(long double magnitude)
    {
        return Faradays(magnitude);
    }

    // Faradays Constants
    namespace Constants
    {
        constexpr Faradays faradaysConstant = (elementaryCharge * avogadrosNumber) / 1.0_mol;
    }
}

#endif
