// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: action.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:16:31
// Description: Defines the units, constants, and conversions of action

#ifndef UTILITIES_API_ACTION_HPP
#define UTILITIES_API_ACTION_HPP

#include "../../physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using ActionDimensionality = Dimensionality<2, 2, -2>;
    using Action = PhysicalQuantity<ActionDimensionality>;

    // Action Units
    constexpr Action operator"" _Js(long double magnitude)
    {
        return Action(magnitude);
    }

    constexpr Action operator"" _kg2m2_s2(long double magnitude)
    {
        return Action(magnitude);
    }

    // Action Constants
    namespace Constants
    {
        constexpr Action plancksConstant = 6.62607015e-34_Js;
    }
}

#endif
