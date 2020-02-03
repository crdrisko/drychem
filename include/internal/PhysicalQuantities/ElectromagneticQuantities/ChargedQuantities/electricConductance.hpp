// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: electricConductance.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:53:24
// Description: Defines the units, constants, and conversions of electric conductance

#ifndef UTILITIES_API_ELECTRICCONDUCTANCE_HPP
#define UTILITIES_API_ELECTRICCONDUCTANCE_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using ElectricConductanceDimensionality = Dimensionality<-2, -1, 3, 2>;
    using ElectricConductance = PhysicalQuantity<ElectricConductanceDimensionality>;

    // ElectricConductance Units
    constexpr ElectricConductance operator"" _S(long double magnitude)          // Siemens (S)
    {
        return ElectricConductance(magnitude);
    }

    constexpr ElectricConductance operator"" _A_V(long double magnitude)
    {
        return ElectricConductance(magnitude);
    }

    constexpr ElectricConductance operator"" _A2s3_kgm2(long double magnitude)
    {
        return ElectricConductance(magnitude);
    }
}

#endif
