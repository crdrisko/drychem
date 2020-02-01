// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: amountOfSubstance.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:49:23
// Description: Defines the units, constants, and conversions of amount of substance

#ifndef UTILITIES_API_AMOUNTOFSUBSTANCE_HPP
#define UTILITIES_API_AMOUNTOFSUBSTANCE_HPP

#include "../conversions.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using AmountOfSubstanceDimensionality = Dimensionality<0, 0, 0, 0, 0, 1>;
    using AmountOfSubstance = PhysicalQuantity<AmountOfSubstanceDimensionality>;

    // AmountOfSubstance Units
    constexpr AmountOfSubstance operator"" _mol(long double magnitude)
    {
        return AmountOfSubstance(magnitude);
    }

    constexpr AmountOfSubstance operator"" _part(long double magnitude)
    {
        return AmountOfSubstance(magnitude);
    }

    // AmountOfSubstance Constants
    namespace Constants
    {
        constexpr DimensionlessQuantity avogadrosNumber = 6.02214076e23_;
    }

    // AmountOfSubstance Conversions
    namespace Conversions
    {
        static inline std::map<std::string_view, long double> amountOfSubstanceUnitsRelativeToMoles
        {
            {"mol", 1.0},
            {"part", Constants::avogadrosNumber.getMagnitude()}
        };

        inline auto getAmountOfSubstanceConversionFactor = std::bind(getConversionFactor,
            std::placeholders::_1, std::placeholders::_2, amountOfSubstanceUnitsRelativeToMoles);
    }
}

#endif
