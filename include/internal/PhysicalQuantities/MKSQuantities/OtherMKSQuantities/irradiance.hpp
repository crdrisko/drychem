// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: irradiance.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:23:43
// Description: Defines the units, constants, and conversions of irradiance

#ifndef UTILITIES_API_IRRADIANCE_HPP
#define UTILITIES_API_IRRADIANCE_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using IrradianceDimensionality = Dimensionality<0, 1, -3>;
    using Irradiance = PhysicalQuantity<IrradianceDimensionality>;

    // Irradiance Units
    constexpr Irradiance operator"" _W_m2(long double magnitude)
    {
        return Irradiance(magnitude);
    }

    constexpr Irradiance operator"" _kg_s3(long double magnitude)
    {
        return Irradiance(magnitude);
    }
}

#endif
