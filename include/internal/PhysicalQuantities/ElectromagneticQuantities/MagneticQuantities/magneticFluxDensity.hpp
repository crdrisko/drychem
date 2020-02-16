// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: magneticFluxDensity.hpp - Version 1.0.0
// Author: cdrisko
// Date: 02/01/2020-09:59:34
// Description: Defines the units, constants, and conversions of magnetic flux density

#ifndef UTILITIES_API_MAGNETICFLUXDENSITY_HPP
#define UTILITIES_API_MAGNETICFLUXDENSITY_HPP

#include "../../conversions.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using MagneticFluxDensityDimensionality = Dimensionality<0, 1, -2, -1>;
    using MagneticFluxDensity = PhysicalQuantity<MagneticFluxDensityDimensionality>;

    // MagneticFluxDensity Units
    constexpr MagneticFluxDensity operator"" _T(long double magnitude)          // Tesla (T)
    {
        return MagneticFluxDensity(magnitude);
    }

    constexpr MagneticFluxDensity operator"" _G(long double magnitude)          // Gauss (G)
    {
        return MagneticFluxDensity(magnitude);
    }

    constexpr MagneticFluxDensity operator"" _gamma(long double magnitude)      // gamma
    {
        return MagneticFluxDensity(magnitude);
    }

    constexpr MagneticFluxDensity operator"" _Wb_m2(long double magnitude)
    {
        return MagneticFluxDensity(magnitude);
    }

    constexpr MagneticFluxDensity operator"" _kg_As2(long double magnitude)
    {
        return MagneticFluxDensity(magnitude);
    }

    // MagneticFluxDensity Conversions
    namespace Conversions
    {
        static inline std::map<std::string_view, long double> magneticFluxDensityUnitsRelativeToTesla
        {
            {"T", 1.0},
            {"G", 10'000.0},
            {"gamma", 1e9}
        };

        inline auto getMagneticFluxDensityConversionFactor = [](const std::string& initialUnits,
            const std::string& finalUnits) -> auto { return getConversionFactor(initialUnits,
                finalUnits, magneticFluxDensityUnitsRelativeToTesla); };
    }
}

#endif
