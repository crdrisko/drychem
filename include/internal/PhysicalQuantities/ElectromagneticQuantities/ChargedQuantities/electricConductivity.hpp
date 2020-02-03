// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: electricConductivity.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:53:24
// Description: Defines the units, constants, and conversions of electric conductivity

#ifndef UTILITIES_API_ELECTRICCONDUCTIVITY_HPP
#define UTILITIES_API_ELECTRICCONDUCTIVITY_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using ElectricConductivityDimensionality = Dimensionality<-3, -1, 3, 2>;
    using ElectricConductivity = PhysicalQuantity<ElectricConductivityDimensionality>;

    // ElectricConductivity Units
    constexpr ElectricConductivity operator"" _S_m(long double magnitude)
    {
        return ElectricConductivity(magnitude);
    }

    constexpr ElectricConductivity operator"" _A_Vm(long double magnitude)
    {
        return ElectricConductivity(magnitude);
    }

    constexpr ElectricConductivity operator"" _A2s3_kgm3(long double magnitude)
    {
        return ElectricConductivity(magnitude);
    }
}

#endif
