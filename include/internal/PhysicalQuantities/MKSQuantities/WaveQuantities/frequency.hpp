// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: frequency.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:16:43
// Description: Defines the units, constants, and conversions of frequency

#ifndef UTILITIES_API_FREQUENCY_HPP
#define UTILITIES_API_FREQUENCY_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using FrequencyDimensionality = Dimensionality<0, 0, -1>;
    using Frequency = PhysicalQuantity<FrequencyDimensionality>;

    // Frequency Units
    constexpr Frequency operator"" _Hz(long double magnitude)           // Hertz (Hz)
    {
        return Frequency(magnitude);
    }

    constexpr Frequency operator"" _1_s(long double magnitude)
    {
        return Frequency(magnitude);
    }
}

#endif
