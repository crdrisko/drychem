// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: currentDensity.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:53:24
// Description: Defines the units, constants, and conversions of current density

#ifndef UTILITIES_API_CURRENTDENSITY_HPP
#define UTILITIES_API_CURRENTDENSITY_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using CurrentDensityDimensionality = Dimensionality<-2, 0, 0, 1>;
    using CurrentDensity = PhysicalQuantity<CurrentDensityDimensionality>;

    // CurrentDensity Units
    constexpr CurrentDensity operator"" _A_m2(long double magnitude)
    {
        return CurrentDensity(magnitude);
    }
}

#endif
