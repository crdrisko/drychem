// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: molarEnergy.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:49:23
// Description: Defines the units, constants, and conversions of molar energy

#ifndef UTILITIES_API_MOLARENERGY_HPP
#define UTILITIES_API_MOLARENERGY_HPP

#include "faradays.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using MolarEnergyDimensionality = Dimensionality<2, 1, -2, 0, 0, -1>;
    using MolarEnergy = PhysicalQuantity<MolarEnergyDimensionality>;

    // MolarEnergy Units
    constexpr MolarEnergy operator"" _J_mol(long double magnitude)
    {
        return MolarEnergy(magnitude);
    }

    constexpr MolarEnergy operator"" _eV_mol(long double magnitude)
    {
        return MolarEnergy(magnitude);
    }

    constexpr MolarEnergy operator"" _kcal_mol(long double magnitude)
    {
        return MolarEnergy(magnitude);
    }

    // MolarEnergy Conversions
    namespace Conversions
    {
        static inline std::map<std::string_view, long double> molarEnergyUnitsRelativeToJoules
        {
            {"J_mol", 1.0},
            {"eV_part", 1 / Constants::faradaysConstant.getMagnitude()},
            {"kcal_mol", 1 / 4'184.0}
        };

        inline auto getMolarEnergyConversionFactor = [&](const std::string& initialUnits,
            const std::string& finalUnits) -> auto { return getConversionFactor(initialUnits,
                finalUnits, molarEnergyUnitsRelativeToJoules); };
    }
}

#endif
