// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: time.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:19:39
// Description: Defines the units, constants, and conversions of time

#ifndef UTILITIES_API_TIME_HPP
#define UTILITIES_API_TIME_HPP

#include "../../conversions.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using TimeDimensionality = Dimensionality<0, 0, 1>;
    using Time = PhysicalQuantity<TimeDimensionality>;

    // Time Units
    constexpr Time operator"" _s(long double magnitude)
    {
        return Time(magnitude);
    }

    constexpr Time operator"" _min(long double magnitude)
    {
        return Time(magnitude);
    }

    constexpr Time operator"" _hr(long double magnitude)
    {
        return Time(magnitude);
    }

    constexpr Time operator"" _days(long double magnitude)
    {
        return Time(magnitude);
    }

    constexpr Time operator"" _weeks(long double magnitude)
    {
        return Time(magnitude);
    }

    constexpr Time operator"" _months(long double magnitude)
    {
        return Time(magnitude);
    }

    constexpr Time operator"" _years(long double magnitude)
    {
        return Time(magnitude);
    }

    // Time Conversions
    namespace Conversions
    {
        static inline std::map<std::string_view, long double> timeUnitsRelativeToSeconds
        {
            {"s", 1.0},
            {"min", 1 / 60.0},
            {"hr", 1 / 3600.0},
            {"days", 1 / 8.64e4},
            {"weeks", 1 / 6.048e5},
            {"months", 1 / 2.628e6},
            {"years", 1 / 3.154e7}
        };

        inline auto getTimeConversionFactor = [&](const std::string& initialUnits,
            const std::string& finalUnits) -> auto { return getConversionFactor(initialUnits,
                finalUnits, timeUnitsRelativeToSeconds); };
    }
}

#endif
