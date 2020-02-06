// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: electricCharge.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:53:24
// Description: Defines the units, constants, and conversions of electric charge

#ifndef UTILITIES_API_ELECTRICCHARGE_HPP
#define UTILITIES_API_ELECTRICCHARGE_HPP

#include "../../conversions.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using ElectricChargeDimensionality = Dimensionality<0, 0, 1, 1>;
    using ElectricCharge = PhysicalQuantity<ElectricChargeDimensionality>;

    // ElectricCharge Units
    constexpr ElectricCharge operator"" _C(long double magnitude)               // Coulomb (C)
    {
        return ElectricCharge(magnitude);
    }

    constexpr ElectricCharge operator"" _e(long double magnitude)
    {
        return ElectricCharge(magnitude);
    }

    // ElectricCharge Constants
    namespace Constants
    {
        constexpr ElectricCharge elementaryCharge = 1.602176634e-19_C;
    }

    // ElectricCharge Conversions
    namespace Conversions
    {
        static inline std::map<std::string_view, long double> electricChargeUnitsRelativeToElectrons
        {
            {"C", Constants::elementaryCharge.getMagnitude()},
            {"e", 1.0}
        };

        inline auto getElectricChargeConversionFactor = std::bind(getConversionFactor, std::placeholders::_1,
            std::placeholders::_2, electricChargeUnitsRelativeToElectrons);
    }
}

#endif
