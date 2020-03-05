// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: physicalQuantities.hpp - Version 1.0.0
// Author: crdrisko
// Date: 03/04/2020-08:13:47
// Description: The public API for the PhysicalQuantities section of the CPP-Units program. This
//   header file should be included in all user programs using these utilities.
//
// Note: The internal implementation details associated with this API should not be used in any
//   user program as they are subject to change at any time without warning.

#ifndef CPP_UNITS_PHYSICALQUANTITIES_HPP
#define CPP_UNITS_PHYSICALQUANTITIES_HPP

#include <functional>

#include "internal/math.hpp"
#include "internal/conversions.hpp"
#include "internal/physicalQuantity.hpp"

namespace PhysicalQuantities
{
    #define DeclareNewPhysicalQuantity(NAME, ...)                                                   \
        using NAME ##Dimensionality = Dimensionality<__VA_ARGS__>;                                  \
        using NAME = PhysicalQuantity<NAME ##Dimensionality>;

    using DimensionlessQuantity = PhysicalQuantity< Dimensionality<> >;

    // MKS Quantities
    DeclareNewPhysicalQuantity(Length, 1, 0, 0)
    DeclareNewPhysicalQuantity(Area, 2, 0, 0)
    DeclareNewPhysicalQuantity(Volume, 3, 0, 0)

    namespace Conversions
    {
        #define DeclareNewConversionFactor(NAME, BASEUNIT)                                          \
            inline auto get ##NAME ##ConversionFactor = std::bind(&getConversionFactor,             \
                std::placeholders::_1, std::placeholders::_2, NAME ##UnitsRelativeTo ##BASEUNIT);
        
        DeclareNewConversionFactor(SIPrefix, Base)
        DeclareNewConversionFactor(Length, Meters)
    }


    namespace Literals
    {
        #define DeclareNewLiteral(NAME, UNIT)                                                       \
            constexpr NAME operator"" UNIT(long double magnitude) { return NAME(magnitude); }

        DeclareNewLiteral(DimensionlessQuantity, _)
        
        DeclareNewLiteral(Length, _m)
        DeclareNewLiteral(Length, _Ang)
        DeclareNewLiteral(Length, _in)
        DeclareNewLiteral(Length, _feet)
        DeclareNewLiteral(Length, _yards)
        DeclareNewLiteral(Length, _miles)
    }


    namespace Constants
    {
        using namespace Literals;

        constexpr Length bohrRadius = 5.29177210903e-11_m;
    }


    // Limit the scope of the preprocessing macros we used by undefining them here
    #undef DeclareNewPhysicalQuantity
    #undef DeclareNewConversionFactor
    #undef DeclareNewLiteral
}

#endif
