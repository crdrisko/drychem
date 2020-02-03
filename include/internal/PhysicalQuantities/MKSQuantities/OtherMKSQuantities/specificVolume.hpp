// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: specificVolume.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:23:43
// Description: Defines the units, constants, and conversions of specific volume

#ifndef UTILITIES_API_SPECIFICVOLUME_HPP
#define UTILITIES_API_SPECIFICVOLUME_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using SpecificVolumeDimensionality = Dimensionality<3, -1, 0>;
    using SpecificVolume = PhysicalQuantity<SpecificVolumeDimensionality>;

    // SpecificVolume Units
    constexpr SpecificVolume operator"" _m3_kg(long double magnitude)
    {
        return SpecificVolume(magnitude);
    }
}

#endif
