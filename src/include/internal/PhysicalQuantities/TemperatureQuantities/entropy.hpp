// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: entropy.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:45:20
// Description: Defines the units, constants, and conversions of entropy

#ifndef UTILITIES_API_ENTROPY_HPP
#define UTILITIES_API_ENTROPY_HPP

#include "../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using EntropyDimensionality = Dimensionality<2, 1, -2, 0, -1>;
    using Entropy = PhysicalQuantity<EntropyDimensionality>;

    // Entropy Units
    constexpr Entropy operator"" _J_K(long double magnitude)
    {
        return Entropy(magnitude);
    }

    constexpr Entropy operator"" _eV_K(long double magnitude)
    {
        return Entropy(magnitude);
    }

    // Entropy Constants
    namespace Constants
    {
        constexpr Entropy boltzmannConstant = 1.380649e-23_J_K;
    }
}

#endif
