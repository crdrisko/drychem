// Copyright (c) 2020-2024 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: dimensionality.hpp
// Author: crdrisko
// Date: 09/02/2020-10:58:01
// Description: A structure holding the SI base units from which all physical quantities can be constructed

#ifndef DRYCHEM_CPP_UNITS_INCLUDE_CPP_UNITS_TYPES_DIMENSIONALITY_HPP
#define DRYCHEM_CPP_UNITS_INCLUDE_CPP_UNITS_TYPES_DIMENSIONALITY_HPP

namespace CppUnits
{
    /*!
     * A structure representing the dimensionality of a unit in terms of the seven SI base units.
     * 
     * \tparam  L - The length dimensionality of the unit, defaults to 0
     * \tparam  M - The mass dimensionality of the unit, defaults to 0
     * \tparam  T - The time dimensionality of the unit, defaults to 0
     * \tparam  I - The electric current dimensionality of the unit, defaults to 0
     * \tparam Th - The temperature dimensionality of the unit, defaults to 0
     * \tparam  N - The amount of substance dimensionality of the unit, defaults to 0
     * \tparam  J - The luminous intensity dimensionality of the unit, defaults to 0
     */
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
}   // namespace CppUnits

#endif
