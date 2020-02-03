// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: electricField.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:53:24
// Description: Defines the units, constants, and conversions of electric field

#ifndef UTILITIES_API_ELECTRICFIELD_HPP
#define UTILITIES_API_ELECTRICFIELD_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using ElectricFieldDimensionality = Dimensionality<1, 1, -3, -1>;
    using ElectricField = PhysicalQuantity<ElectricFieldDimensionality>;

    // ElectricField Units
    constexpr ElectricField operator"" _V_m(long double magnitude)
    {
        return ElectricField(magnitude);
    }

    constexpr ElectricField operator"" _N_C(long double magnitude)
    {
        return ElectricField(magnitude);
    }

    constexpr ElectricField operator"" _kgm_As3(long double magnitude)
    {
        return ElectricField(magnitude);
    }
}

#endif
