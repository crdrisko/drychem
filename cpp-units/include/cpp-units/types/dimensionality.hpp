// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: dimensionality.hpp
// Author: crdrisko
// Date: 09/02/2020-10:58:01
// Description: A structure holding the SI base units from which all physical quantities can be constructed

#ifndef CPP_UNITS_DIMENSIONALITY_HPP
#define CPP_UNITS_DIMENSIONALITY_HPP

namespace PhysicalQuantities
{
    /* When using static constant members instead of enumerations, we want to ensure any usage of the members is limited
        to a purely compile-time effect, so we'll explicitly use the inline keyword in conjuction with constexpr */
    template<int L = 0, int M = 0, int T = 0, int I = 0, int Th = 0, int N = 0, int J = 0>
    struct Dimensionality
    {
        static inline constexpr int Length            = L;
        static inline constexpr int Mass              = M;
        static inline constexpr int Time              = T;
        static inline constexpr int ElectricCurrent   = I;
        static inline constexpr int Temperature       = Th;
        static inline constexpr int AmountOfSubstance = N;
        static inline constexpr int LuminousIntensity = J;

        using Type = Dimensionality<Length, Mass, Time, ElectricCurrent, Temperature, AmountOfSubstance, LuminousIntensity>;
    };
}   // namespace PhysicalQuantities

#endif
