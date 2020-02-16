// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: energy.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:16:37
// Description: Defines the units, constants, and conversions of energy

#ifndef UTILITIES_API_ENERGY_HPP
#define UTILITIES_API_ENERGY_HPP

#include "../../conversions.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using EnergyDimensionality = Dimensionality<2, 1, -2>;
    using Energy = PhysicalQuantity<EnergyDimensionality>;

    // Energy Units
    constexpr Energy operator"" _J(long double magnitude)               // Joule (J)
    {
        return Energy(magnitude);
    }

    constexpr Energy operator"" _eV(long double magnitude)              // Electron-Volt (eV)
    {
        return Energy(magnitude);
    }

    constexpr Energy operator"" _Ha(long double magnitude)              // Hartree (Ha)
    {
        return Energy(magnitude);
    }

    constexpr Energy operator"" _cal(long double magnitude)             // Small calorie (cal)
    {
        return Energy(magnitude);
    }

    constexpr Energy operator"" _Cal(long double magnitude)             // Large calorie (Cal)
    {
        return Energy(magnitude);
    }

    // Energy Conversions
    namespace Conversions
    {
        static inline std::map<std::string_view, long double> energyUnitsRelativeToJoules
        {
            {"J", 1.0},
            {"eV", 6.241509074e18},
            {"Hartree", 2.2937122783963e17},
            {"cal", 0.2390},
            {"Cal", 0.0002390}
        };

        inline auto getEnergyConversionFactor = [&](const std::string& initialUnits,
            const std::string& finalUnits) -> auto { return getConversionFactor(initialUnits,
                finalUnits, energyUnitsRelativeToJoules); };
    }
}

#endif
