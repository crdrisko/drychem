// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: area.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:29:07
// Description: Defines the units, constants, and conversions of area

#ifndef UTILITIES_API_AREA_HPP
#define UTILITIES_API_AREA_HPP

#include "length.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using AreaDimensionality = Dimensionality<2, 0, 0>;
    using Area = PhysicalQuantity<AreaDimensionality>;

    // Area Units
    constexpr Area operator"" _m2(long double magnitude)
    {
        return Area(magnitude);
    }

    constexpr Area operator"" _Ang2(long double magnitude)
    {
        return Area(magnitude);
    }

    // Area Conversions
    namespace Conversions
    {
        constexpr long double getAreaUnitsFromLengthSquared(std::string_view desiredLengthUnits)
        {
            Length length(lengthUnitsRelativeToMeters[desiredLengthUnits]);
            Area area = length.raisePower<AreaDimensionality>(2);

            return area.getMagnitude();
        }

        static inline std::map<std::string_view, long double> areaUnitsRelativeToMetersSquared
        {
            {"m2", getAreaUnitsFromLengthSquared("m")},
            {"Ang2", getAreaUnitsFromLengthSquared("Ang")}
        };

        constexpr auto getAreaConversionFactor = [&](const std::string& initialUnits,
            const std::string& finalUnits) -> auto { return getConversionFactor(initialUnits,
                finalUnits, areaUnitsRelativeToMetersSquared); };
    }
}

#endif
