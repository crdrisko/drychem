// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: electricCurrent.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:53:24
// Description: Defines the units, constants, and conversions of electric current

#ifndef UTILITIES_API_ELECTRICCURRENT_HPP
#define UTILITIES_API_ELECTRICCURRENT_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using ElectricCurrentDimensionality = Dimensionality<0, 0, 0, 1>;
    using ElectricCurrent = PhysicalQuantity<ElectricCurrentDimensionality>;

    // ElectricCurrent Units
    constexpr ElectricCurrent operator"" _A(long double magnitude)
    {
        return ElectricCurrent(magnitude);
    }
}

#endif
