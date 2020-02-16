// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: length.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:29:07
// Description: Defines the units, constants, and conversions of length

#ifndef UTILITIES_API_LENGTH_HPP
#define UTILITIES_API_LENGTH_HPP

#include "../../conversions.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using LengthDimensionality = Dimensionality<1, 0, 0>;
    using Length = PhysicalQuantity<LengthDimensionality>;

    // Length Units
    constexpr Length operator"" _m(long double magnitude)
    {
        return Length(magnitude);
    }

    constexpr Length operator"" _Ang(long double magnitude)
    {
        return Length(magnitude);
    }

    constexpr Length operator"" _in(long double magnitude)
    {
        return Length(magnitude);
    }

    constexpr Length operator"" _feet(long double magnitude)
    {
        return Length(magnitude);
    }

    constexpr Length operator"" _yards(long double magnitude)
    {
        return Length(magnitude);
    }

    constexpr Length operator"" _miles(long double magnitude)
    {
        return Length(magnitude);
    }

    // Length Constants
    namespace Constants
    {
        constexpr Length bohrRadius = 5.29177210903e-11_m;
    }

    // Length Conversions
    namespace Conversions
    {
        static inline std::map<std::string_view, long double> lengthUnitsRelativeToMeters
        {
            {"m", 1.0},
            {"Ang", 1e10},
            {"in", 39.3700787},
            {"ft", 3.280840},
            {"yd", 1.093613},
            {"mil", 6.213712e-4}
        };

        inline auto getLengthConversionFactor = [](const std::string& initialUnits,
            const std::string& finalUnits) -> auto { return getConversionFactor(initialUnits,
                finalUnits, lengthUnitsRelativeToMeters); };
    }
}

#endif
