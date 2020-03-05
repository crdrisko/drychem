// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: conversions.hpp - Version 1.0.0
// Author: crdrisko
// Date: 03/03/2020-18:45:36
// Description: Conversion factors and functions relating to unit conversions for PhysicalQuantities

#ifndef CPP_UNITS_CONVERSIONS_HPP
#define CPP_UNITS_CONVERSIONS_HPP

#include <map>
#include <string>
#include <string_view>

#include <utils-api/errors.hpp>

#include "physicalQuantity.hpp"

namespace PhysicalQuantities::Conversions
{
    inline auto getConversionFactor(const std::string& initialUnits,
        const std::string& finalUnits, std::map<std::string_view, long double>& unitsRelativeToBase)
    {
        if ( unitsRelativeToBase.count(initialUnits) != 1 )
            Utilities_API::Errors::printFatalErrorMessage(1, initialUnits + " is not one of the pre-defined units.");

        else if ( unitsRelativeToBase.count(finalUnits) != 1 )
            Utilities_API::Errors::printFatalErrorMessage(1, finalUnits + " is not one of the pre-defined units.");

        return PhysicalQuantity< Dimensionality<> >(unitsRelativeToBase[finalUnits]
            / unitsRelativeToBase[initialUnits]);
    }

    static std::map<std::string_view, long double> LengthUnitsRelativeToMeters
    {
        {"m", 1.0},
        {"Ang", 1e10},
        {"in", 39.3700787},
        {"ft", 3.280840},
        {"yd", 1.093613},
        {"mil", 6.213712e-4}
    };

    static std::map<std::string_view, long double> SIPrefixUnitsRelativeToBase
    {
        {"yotta", 1e-24}, {"zetta", 1e-21}, {"exa",   1e-18},
        {"peta",  1e-15}, {"tera",  1e-12}, {"giga",  1e-9},
        {"mega",  1e-6},  {"kilo",  1e-3},  {"hecto", 1e-2},
        {"deka",  1e-1},  {"base",  1e0},   {"deci",  1e1},
        {"centi", 1e2},   {"milli", 1e3},   {"micro", 1e6},
        {"nano",  1e9},   {"pico",  1e12},  {"femto", 1e15},
        {"atto",  1e18},  {"zepto", 1e21},  {"yocto", 1e24}
    };
}

#endif
