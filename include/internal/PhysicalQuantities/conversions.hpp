// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: conversions.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:44:02
// Description: Conversion factors and functions relating to unit conversions and dimensionless quantities

#ifndef UTILITIES_API_CONVERSIONS_HPP
#define UTILITIES_API_CONVERSIONS_HPP

#include <map>
#include <string>
#include <functional>
#include "physicalQuantity.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using DimensionlessQuantity = PhysicalQuantity< Dimensionality<> >;

    // DimensionlessQuantity Units
    constexpr DimensionlessQuantity operator"" _(long double magnitude)
    {
        return DimensionlessQuantity(magnitude);
    }

    namespace Conversions
    {
        inline DimensionlessQuantity getConversionFactor(const std::string& initialUnits,
            const std::string& finalUnits, std::map<std::string_view, long double>& unitsRelativeToBase)
        {
            if ( unitsRelativeToBase.count(initialUnits) != 1 )
                Utilities_API::Errors::printFatalErrorMessage(1, initialUnits
                    + " is not one of the pre-defined units.");

            else if ( unitsRelativeToBase.count(finalUnits) != 1 )
                Utilities_API::Errors::printFatalErrorMessage(1, finalUnits
                    + " is not one of the pre-defined units.");

            return DimensionlessQuantity(unitsRelativeToBase[finalUnits]
                / unitsRelativeToBase[initialUnits]);
        }

        static inline std::map<std::string_view, long double> siUnitPrefixesRelativeToBase
        {
            {"yotta", 1e-24}, {"zetta", 1e-21}, {"exa",   1e-18},
            {"peta",  1e-15}, {"tera",  1e-12}, {"giga",  1e-9},
            {"mega",  1e-6},  {"kilo",  1e-3},  {"hecto", 1e-2},
            {"deka",  1e-1},  {"base",  1e0},   {"deci",  1e1},
            {"centi", 1e2},   {"milli", 1e3},   {"micro", 1e6},
            {"nano",  1e9},   {"pico",  1e12},  {"femto", 1e15},
            {"atto",  1e18},  {"zepto", 1e21},  {"yocto", 1e24}
        };

        inline auto getSIPrexixConversionFactor = [](const std::string& initialUnits,
            const std::string& finalUnits) -> auto { return getConversionFactor(initialUnits,
                finalUnits, siUnitPrefixesRelativeToBase); };
    }
}

#endif
