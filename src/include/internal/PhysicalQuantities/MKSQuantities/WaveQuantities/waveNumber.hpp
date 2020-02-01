// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: waveNumber.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:16:51
// Description: Defines the units, constants, and conversions of wavenumbers

#ifndef UTILITIES_API_WAVENUMBER_HPP
#define UTILITIES_API_WAVENUMBER_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using WaveNumberDimensionality = Dimensionality<-1, 0, 0>;
    using WaveNumber = PhysicalQuantity<WaveNumberDimensionality>;

    // WaveNumber Units
    constexpr WaveNumber operator"" _1_m(long double magnitude)
    {
        return WaveNumber(magnitude);
    }
}

#endif
