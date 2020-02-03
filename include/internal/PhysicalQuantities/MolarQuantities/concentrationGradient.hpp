// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: concentrationGradient.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:49:23
// Description: Defines the units, constants, and conversions of concentration gradient

#ifndef UTILITIES_API_CONCENTRATIONGRADIENT_HPP
#define UTILITIES_API_CONCENTRATIONGRADIENT_HPP

#include "../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using ConcentrationGradientDimensionality = Dimensionality<-4, 0, 0, 0, 0, 1>;
    using ConcentrationGradient = PhysicalQuantity<ConcentrationGradientDimensionality>;

    // ConcentrationGradient Units
    constexpr ConcentrationGradient operator"" _M_m(long double magnitude)
    {
        return ConcentrationGradient(magnitude);
    }

    constexpr ConcentrationGradient operator"" _mol_m4(long double magnitude)
    {
        return ConcentrationGradient(magnitude);
    }
}

#endif
