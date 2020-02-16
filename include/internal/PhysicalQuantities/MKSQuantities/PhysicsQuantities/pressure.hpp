// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: pressure.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:19:39
// Description: Defines the units, constants, and conversions of pressure

#ifndef UTILITIES_API_PRESSURE_HPP
#define UTILITIES_API_PRESSURE_HPP

#include "../../conversions.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using PressureDimensionality = Dimensionality<-1, 1, -2>;
    using Pressure = PhysicalQuantity<PressureDimensionality>;

    // Pressure Units
    constexpr Pressure operator"" _Pa(long double magnitude)            // Pascals (Pa)
    {
        return Pressure(magnitude);
    }

    constexpr Pressure operator"" _atm(long double magnitude)           // Atmospheres (atm)
    {
        return Pressure(magnitude);
    }

    constexpr Pressure operator"" _bar(long double magnitude)
    {
        return Pressure(magnitude);
    }

    constexpr Pressure operator"" _torr(long double magnitude)
    {
        return Pressure(magnitude);
    }

    constexpr Pressure operator"" _psi(long double magnitude)           // Pounds per square inch (psi)
    {
        return Pressure(magnitude);
    }

    // Pressure Conversions
    namespace Conversions
    {
        static inline std::map<std::string_view, long double> pressureUnitsRelativeToBar
        {
            {"Pa", 1e5},
            {"atm", 0.986923},
            {"torr", 750.062},
            {"bar", 1.0},
            {"psi", 14.5038}
        };

        constexpr auto getPressureConversionFactor = [&](const std::string& initialUnits,
            const std::string& finalUnits) -> auto { return getConversionFactor(initialUnits,
                finalUnits, pressureUnitsRelativeToBar); };
    }
}

#endif
