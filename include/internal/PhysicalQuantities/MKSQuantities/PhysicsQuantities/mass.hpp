// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: mass.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:19:39
// Description: Defines the units, constants, and conversions of mass

#ifndef UTILITIES_API_MASS_HPP
#define UTILITIES_API_MASS_HPP

#include "../../conversions.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using MassDimensionality = Dimensionality<0, 1, 0>;
    using Mass = PhysicalQuantity<MassDimensionality>;

    // Mass Units
    constexpr Mass operator"" _kg(long double magnitude)
    {
        return Mass(magnitude);
    }

    constexpr Mass operator"" _lbs(long double magnitude)
    {
        return Mass(magnitude);
    }

    // Mass Conversions
    namespace Conversions
    {
        static inline std::map<std::string_view, long double> massUnitsRelativeToKilograms
        {
            {"kg", 1.0},
            {"lbs", 2.20462}
        };

        inline auto getMassConversionFactor = [](const std::string& initialUnits,
            const std::string& finalUnits) -> auto { return getConversionFactor(initialUnits,
                finalUnits, massUnitsRelativeToKilograms); };
    }
}

#endif
