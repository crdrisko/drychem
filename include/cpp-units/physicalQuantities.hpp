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

#include "internal/conversions.hpp"
#include "internal/math.hpp"
#include "internal/physicalQuantity.hpp"

namespace PhysicalQuantities
{
    #define DeclareNewPhysicalQuantity(NAME, BASEUNIT, ...)                                         \
        using NAME ##Dimensionality = Dimensionality<__VA_ARGS__>;                                  \
        using NAME = PhysicalQuantity<NAME ##Dimensionality>;                                       \
        namespace Literals                                                                          \
        {                                                                                           \
            constexpr NAME operator"" BASEUNIT(long double magnitude) { return NAME(magnitude); }   \
        }

    using DimensionlessQuantity = PhysicalQuantity< Dimensionality<> >;

    // MKS Quantities
    DeclareNewPhysicalQuantity(Angle, _rad, 0, 0, 0)
    DeclareNewPhysicalQuantity(Area, _m2, 2, 0, 0)
    DeclareNewPhysicalQuantity(Length, _m, 1, 0, 0)
    DeclareNewPhysicalQuantity(Volume, _m3, 3, 0, 0)

    DeclareNewPhysicalQuantity(Irradiance, _W_m2, 0, 1, -3)
    DeclareNewPhysicalQuantity(MassDensity, _kg_m3, -3, 1, 0)
    DeclareNewPhysicalQuantity(MomentumFlux, _kg_ms2, -1, 1, -2)
    DeclareNewPhysicalQuantity(SpecificEnergy, _J_kg, 2, 0, -2)
    DeclareNewPhysicalQuantity(SpecificVolume, _m3_kg, 3, -1, 0)

    DeclareNewPhysicalQuantity(Acceleration, _m_s2, 1, 0, -2)
    DeclareNewPhysicalQuantity(Force, _N, 1, 1, -2)
    DeclareNewPhysicalQuantity(Mass, _kg, 0, 1, 0)
    DeclareNewPhysicalQuantity(Momentum, _kgm_s, 1, 1, -1)
    DeclareNewPhysicalQuantity(Power, _W, 2, 1, -3)
    DeclareNewPhysicalQuantity(Pressure, _bar, -1, 1, -2)
    DeclareNewPhysicalQuantity(Time, _s, 0, 0, 1)
    DeclareNewPhysicalQuantity(Velocity, _m_s, 1, 0, -1)

    DeclareNewPhysicalQuantity(Action, _Js, 2, 2, -2)
    DeclareNewPhysicalQuantity(AngularVelocity, _m2_s, 2, 0, -1)
    DeclareNewPhysicalQuantity(Energy, _J, 2, 1, -2)
    DeclareNewPhysicalQuantity(Frequency, _Hz, 0, 0, -1)
    DeclareNewPhysicalQuantity(WaveNumber, _1_m, -1, 0, 0)

    // Electromagnetic Quantities
    DeclareNewPhysicalQuantity(Capacitance, _F, -2, -1, 4, 2)
    DeclareNewPhysicalQuantity(CurrentDensity, _A_m2, -2, 0, 0, 1)
    DeclareNewPhysicalQuantity(ElectricCharge, _e, 0, 0, 1, 1)
    DeclareNewPhysicalQuantity(ElectricChargeDensity, _C_m3, -3, 0, 1, 1)
    DeclareNewPhysicalQuantity(ElectricConductance, _S, -2, -1, 3, 2)
    DeclareNewPhysicalQuantity(ElectricConductivity, _S_m, -3, -1, 3, 2)
    DeclareNewPhysicalQuantity(ElectricCurrent, _A, 0, 0, 0, 1)
    DeclareNewPhysicalQuantity(ElectricField, _V_m, 1, 1, -3, -1)
    DeclareNewPhysicalQuantity(ElectricFluxDensity, _C_m2, -2, 0, 1, 1)
    DeclareNewPhysicalQuantity(ElectricPotential, _V, 2, 1, -3, -1)
    DeclareNewPhysicalQuantity(ElectricResistance, _Ohm, 2, 1, -3, -2)
    DeclareNewPhysicalQuantity(Mobility, _m2_Vs, 0, -1, 2, 1)
    DeclareNewPhysicalQuantity(Permittivity, _F_m, -3, -1, 4, 2)

    DeclareNewPhysicalQuantity(Inductance, _H, 2, 1, -2, -2)
    DeclareNewPhysicalQuantity(MagneticFieldStrength, _A_m, -1, 0, 0, 1)
    DeclareNewPhysicalQuantity(MagneticFlux, _Wb, 2, 1, -2, -1)
    DeclareNewPhysicalQuantity(MagneticFluxDensity, _T, 0, 1, -2, -1)
    DeclareNewPhysicalQuantity(Permeability, _H_m, 1, 1, -2, -2)

    // Molar Quantities
    DeclareNewPhysicalQuantity(AmountOfSubstance, _mol, 0, 0, 0, 0, 0, 1)
    DeclareNewPhysicalQuantity(Concentration, _M, -3, 0, 0, 0, 0, 1)
    DeclareNewPhysicalQuantity(ConcentrationGradient, _M_m, -4, 0, 0, 0, 0, 1)
    DeclareNewPhysicalQuantity(Faradays, _C_mol, 0, 0, 1, 1, 0, -1)
    DeclareNewPhysicalQuantity(MolarConductivity, _Sm2_mol, 0, -1, 3, 2, 0, -1)
    DeclareNewPhysicalQuantity(MolarEnergy, _J_mol, 2, 1, -2, 0, 0, -1)
    DeclareNewPhysicalQuantity(MolarEnergyFlux, _kg_mols3, 0, 1, -3, 0, 0, -1)
    DeclareNewPhysicalQuantity(MolarEntropy, _J_molK, 2, 1, -2, 0, -1, -1)
    DeclareNewPhysicalQuantity(MolarMass, _g_mol, 0, 1, 0, 0, 0, -1)

    // Thermal Quantities
    DeclareNewPhysicalQuantity(Entropy, _J_K, 2, 1, -2, 0, -1)
    DeclareNewPhysicalQuantity(SpecificEntropy, _J_kgK, 2, 0, -2, 0, -1)
    DeclareNewPhysicalQuantity(Temperature, _K, 0, 0, 0, 0, 1)
    DeclareNewPhysicalQuantity(ThermalConductivity, _W_mK, 1, 1, -3, 0, -1)


    namespace Literals
    {
        #define DeclareAdditionalLiteral(NAME, UNIT)                                                \
            constexpr NAME operator"" UNIT(long double magnitude) { return NAME(magnitude); }

        DeclareAdditionalLiteral(DimensionlessQuantity, _)

        // MKS Quantities
        DeclareAdditionalLiteral(Angle, _deg)

        DeclareAdditionalLiteral(Area, _Ang2)

        DeclareAdditionalLiteral(Length, _Ang)
        DeclareAdditionalLiteral(Length, _in)
        DeclareAdditionalLiteral(Length, _ft)
        DeclareAdditionalLiteral(Length, _yd)
        DeclareAdditionalLiteral(Length, _mil)

        DeclareAdditionalLiteral(Volume, _Ang3)
        DeclareAdditionalLiteral(Volume, _L)

        DeclareAdditionalLiteral(Mass, _lbs)

        DeclareAdditionalLiteral(Pressure, _Pa)
        DeclareAdditionalLiteral(Pressure, _atm)
        DeclareAdditionalLiteral(Pressure, _torr)
        DeclareAdditionalLiteral(Pressure, _psi)

        DeclareAdditionalLiteral(Time, _min)
        DeclareAdditionalLiteral(Time, _hr)
        DeclareAdditionalLiteral(Time, _days)
        DeclareAdditionalLiteral(Time, _weeks)
        DeclareAdditionalLiteral(Time, _months)
        DeclareAdditionalLiteral(Time, _years)

        DeclareAdditionalLiteral(Energy, _eV)
        DeclareAdditionalLiteral(Energy, _Ha)
        DeclareAdditionalLiteral(Energy, _cal)
        DeclareAdditionalLiteral(Energy, _Cal)

        // Electromagnetic Quantities
        DeclareAdditionalLiteral(ElectricCharge, _C)

        DeclareAdditionalLiteral(MagneticFluxDensity, _G)
        DeclareAdditionalLiteral(MagneticFluxDensity, _gamma)
        DeclareAdditionalLiteral(MagneticFluxDensity, _Wb_m2)
        DeclareAdditionalLiteral(MagneticFluxDensity, _kg_As2)

        // Molar Quantities
        DeclareAdditionalLiteral(AmountOfSubstance, _part)

        DeclareAdditionalLiteral(MolarEnergy, _eV_mol)
        DeclareAdditionalLiteral(MolarEnergy, _kcal_mol)

        DeclareAdditionalLiteral(MolarMass, _amu)

        // Thermal Quantities
        DeclareAdditionalLiteral(Entropy, _eV_K)

        DeclareAdditionalLiteral(Temperature, _degC)
        DeclareAdditionalLiteral(Temperature, _degF)
    }


    namespace Constants
    {
        using namespace Literals;

        constexpr DimensionlessQuantity avogadrosNumber = 6.02214076e23_;
        constexpr Length bohrRadius = 5.29177210903e-11_m;
        constexpr Entropy boltzmannConstant = 1.380649e-23_J_K;
        constexpr ElectricCharge elementaryCharge = 1.602176634e-19_C;
        constexpr Faradays faradaysConstant = (elementaryCharge * avogadrosNumber) / 1.0_mol;
        constexpr Permittivity permittivityFreeSpace = 8.8541878128e-12_F_m;
        constexpr DimensionlessQuantity pi = 3.14159265_;
        constexpr Action plancksConstant = 6.62607015e-34_Js;
        constexpr Velocity speedOfLight = 299'792'458.0_m_s;
    }
}

#endif
