// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: molarEntropy.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:49:23
// Description: Defines the units, constants, and conversions of molar entropy

#ifndef UTILITIES_API_MOLARENTROPY_HPP
#define UTILITIES_API_MOLARENTROPY_HPP

#include "../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using MolarEntropyDimensionality = Dimensionality<2, 1, -2, 0, -1, -1>;
    using MolarEntropy = PhysicalQuantity<MolarEntropyDimensionality>;

    // MolarEntropy Units
    constexpr MolarEntropy operator"" _J_molK(long double magnitude)
    {
        return MolarEntropy(magnitude);
    }

    constexpr MolarEntropy operator"" _kgm2_s2molK(long double magnitude)
    {
        return MolarEntropy(magnitude);
    }
}

#endif
