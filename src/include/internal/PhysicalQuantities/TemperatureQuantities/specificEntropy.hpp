// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: specificEntropy.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:45:30
// Description: Defines the units, constants, and conversions of specific entropy

#ifndef UTILITIES_API_SPECIFICENTROPY_HPP
#define UTILITIES_API_SPECIFICENTROPY_HPP

#include "../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using SpecificEntropyDimensionality = Dimensionality<2, 0, -2, 0, -1>;
    using SpecificEntropy = PhysicalQuantity<SpecificEntropyDimensionality>;

    // SpecificEntropy Units
    constexpr SpecificEntropy operator"" _J_kgK(long double magnitude)
    {
        return SpecificEntropy(magnitude);
    }

    constexpr SpecificEntropy operator"" _m2_Ks2(long double magnitude)
    {
        return SpecificEntropy(magnitude);
    }
}

#endif
