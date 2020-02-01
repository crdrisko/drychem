// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: massDensity.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:23:43
// Description: Defines the units, constants, and conversions of mass density

#ifndef UTILITIES_API_MASSDENSITY_HPP
#define UTILITIES_API_MASSDENSITY_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using MassDensityDimensionality = Dimensionality<-3, 1, 0>;
    using MassDensity = PhysicalQuantity<MassDensityDimensionality>;

    // MassDensity Units
    constexpr MassDensity operator"" _kg_m3(long double magnitude)
    {
        return MassDensity(magnitude);
    }
}

#endif
