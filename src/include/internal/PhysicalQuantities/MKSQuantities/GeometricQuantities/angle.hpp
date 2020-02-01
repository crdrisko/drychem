// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: angle.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:29:07
// Description: Defines the units, constants, and conversions of an angle

#ifndef UTILITIES_API_ANGLE_HPP
#define UTILITIES_API_ANGLE_HPP

#include "../../conversions.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using Angle = DimensionlessQuantity;

    // Angle Units
    constexpr Angle operator"" _deg(long double magnitude)
    {
        return Angle(magnitude);
    }

    constexpr Angle operator"" _rad(long double magnitude)
    {
        return Angle(magnitude);
    }

    // Angle Constants
    namespace Constants
    {
        constexpr DimensionlessQuantity pi = 3.14159265_;
    }

    // Angle Conversions
    namespace Conversions
    {
        static inline std::map<std::string_view, long double> angleUnitsRelativeToRadians
        {
            {"deg", 180.0 / Constants::pi.getMagnitude()},
            {"rad", 1.0}
        };

        inline auto getAngleConversionFactor = std::bind(getConversionFactor, std::placeholders::_1,
            std::placeholders::_2, angleUnitsRelativeToRadians);
    }
}

#endif
