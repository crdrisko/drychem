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

#include "internal/math.hpp"
#include "internal/conversions.hpp"
#include "internal/physicalQuantity.hpp"

namespace PhysicalQuantities
{
    #define DeclareNewPhysicalQuantity(NAME, ...)                                               \
        using NAME ##Dimensionality = Dimensionality<__VA_ARGS__>;                              \
        using NAME = PhysicalQuantity<NAME ##Dimensionality>;

    // Dimensionless Quantities
    using DimensionlessQuantity = PhysicalQuantity< Dimensionality<> >;
    using Angle = DimensionlessQuantity;

    // MKS Quantities
    DeclareNewPhysicalQuantity(Area, 2, 0, 0)
    DeclareNewPhysicalQuantity(Length, 1, 0, 0)
    DeclareNewPhysicalQuantity(Volume, 3, 0, 0)

    DeclareNewPhysicalQuantity(Irradiance, 0, 1, -3)
    DeclareNewPhysicalQuantity(MassDensity, -3, 1, 0)
    DeclareNewPhysicalQuantity(MomentumFlux, -1, 1, -2)
    DeclareNewPhysicalQuantity(SpecificEnergy, 2, 0, -2)
    DeclareNewPhysicalQuantity(SpecificVolume, 3, -1, 0)

    DeclareNewPhysicalQuantity(Acceleration, 1, 0, -2)
    DeclareNewPhysicalQuantity(Force, 1, 1, -2)
    DeclareNewPhysicalQuantity(Mass, 0, 1, 0)
    DeclareNewPhysicalQuantity(Momentum, 1, 1, -1)
    DeclareNewPhysicalQuantity(Power, 2, 1, -3)
    DeclareNewPhysicalQuantity(Pressure, -1, 1, -2)
    DeclareNewPhysicalQuantity(Time, 0, 0, 1)
    DeclareNewPhysicalQuantity(Velocity, 1, 0, -1)

    DeclareNewPhysicalQuantity(Action, 2, 2, -2)
    DeclareNewPhysicalQuantity(Energy, 2, 1, -2)
    DeclareNewPhysicalQuantity(Frequency, 0, 0, -1)
    DeclareNewPhysicalQuantity(WaveNumber, -1, 0, 0)

    // Electromagnetic Quantities
    DeclareNewPhysicalQuantity(Capacitance, -2, -1, 4, 2)
    DeclareNewPhysicalQuantity(CurrentDensity, -2, 0, 0, 1)
    DeclareNewPhysicalQuantity(ElectricCharge, 0, 0, 1, 1)
    DeclareNewPhysicalQuantity(ElectricChargeDensity, -3, 0, 1, 1)
    DeclareNewPhysicalQuantity(ElectricConductance, -2, -1, 3, 2)
    DeclareNewPhysicalQuantity(ElectricConductivity, -3, -1, 3, 2)
    DeclareNewPhysicalQuantity(ElectricCurrent, 0, 0, 0, 1)
    DeclareNewPhysicalQuantity(ElectricField, 1, 1, -3, -1)
    DeclareNewPhysicalQuantity(ElectricFluxDensity, -2, 0, 1, 1)
    DeclareNewPhysicalQuantity(ElectricPotential, 2, 1, -3, -1)
    DeclareNewPhysicalQuantity(ElectricResistance, 2, 1, -3, -2)
    DeclareNewPhysicalQuantity(Mobility, 0, -1, 2, 1)
    DeclareNewPhysicalQuantity(Permittivity, -3, -1, 4, 2)

    DeclareNewPhysicalQuantity(Inductance, 2, 1, -2, -2)
    DeclareNewPhysicalQuantity(MagneticFieldStrength, -1, 0, 0, 1)
    DeclareNewPhysicalQuantity(MagneticFlux, 2, 1, -2, -1)
    DeclareNewPhysicalQuantity(MagneticFluxDensity, 0, 1, -2, -1)
    DeclareNewPhysicalQuantity(Permeability, 1, 1, -2, -2)


    // Molar Quantities
    DeclareNewPhysicalQuantity(AmountOfSubstance, 0, 0, 0, 0, 0, 1)
    DeclareNewPhysicalQuantity(Concentration, -3, 0, 0, 0, 0, 1)
    DeclareNewPhysicalQuantity(ConcentrationGradient, -4, 0, 0, 0, 0, 1)
    DeclareNewPhysicalQuantity(Faradays, 0, 0, 1, 1, 0, -1)
    DeclareNewPhysicalQuantity(MolarConductivity, 0, -1, 3, 2, 0, -1)
    DeclareNewPhysicalQuantity(MolarEnergy, 2, 1, -2, 0, 0, -1)
    DeclareNewPhysicalQuantity(MolarEnergyFlux, 0, 1, -3, 0, 0, -1)
    DeclareNewPhysicalQuantity(MolarEntropy, 2, 1, -2, 0, -1, -1)
    DeclareNewPhysicalQuantity(MolarMass, 0, 1, 0, 0, 0, -1)


    // Thermal Quantities
    DeclareNewPhysicalQuantity(Entropy, 2, 1, -2, 0, -1)
    DeclareNewPhysicalQuantity(SpecificEntropy, 2, 0, -2, 0, -1)
    DeclareNewPhysicalQuantity(Temperature, 0, 0, 0, 0, 1)
    DeclareNewPhysicalQuantity(ThermalConductivity, 1, 1, -3, 0, -1)


    namespace Literals
    {
        #define DeclareNewLiteral(NAME, UNIT)                                                   \
            constexpr NAME operator"" UNIT(long double magnitude) { return NAME(magnitude); }


        // Dimensionless Quantities
        DeclareNewLiteral(DimensionlessQuantity, _)

        DeclareNewLiteral(Angle, _deg)
        DeclareNewLiteral(Angle, _rad)


        // MKS Quantities
        DeclareNewLiteral(Length, _m)
        DeclareNewLiteral(Length, _Ang)
        DeclareNewLiteral(Length, _in)
        DeclareNewLiteral(Length, _ft)
        DeclareNewLiteral(Length, _yd)
        DeclareNewLiteral(Length, _mil)

        DeclareNewLiteral(Area, _m2)
        DeclareNewLiteral(Area, _Ang2)

        DeclareNewLiteral(Volume, _m3)
        DeclareNewLiteral(Volume, _Ang3)
        DeclareNewLiteral(Volume, _L)

        DeclareNewLiteral(Irradiance, _W_m2)
        DeclareNewLiteral(Irradiance, _kg_s3)

        DeclareNewLiteral(MassDensity, _kg_m3)

        DeclareNewLiteral(MomentumFlux, _kg_ms2)

        DeclareNewLiteral(SpecificEnergy, _J_kg)
        DeclareNewLiteral(SpecificEnergy, _m2_s2)

        DeclareNewLiteral(SpecificVolume, _m3_kg)

        DeclareNewLiteral(Acceleration, _m_s2)

        DeclareNewLiteral(Force, _N)
        DeclareNewLiteral(Force, _kgm_s2)

        DeclareNewLiteral(Mass, _kg)
        DeclareNewLiteral(Mass, _lbs)

        DeclareNewLiteral(Momentum, _kgm_s)

        DeclareNewLiteral(Power, _W)
        DeclareNewLiteral(Power, _kgm2_s3)

        DeclareNewLiteral(Pressure, _Pa)
        DeclareNewLiteral(Pressure, _atm)
        DeclareNewLiteral(Pressure, _bar)
        DeclareNewLiteral(Pressure, _torr)
        DeclareNewLiteral(Pressure, _psi)

        DeclareNewLiteral(Time, _s)
        DeclareNewLiteral(Time, _min)
        DeclareNewLiteral(Time, _hr)
        DeclareNewLiteral(Time, _days)
        DeclareNewLiteral(Time, _weeks)
        DeclareNewLiteral(Time, _months)
        DeclareNewLiteral(Time, _years)

        DeclareNewLiteral(Velocity, _m_s)

        DeclareNewLiteral(Action, _Js)
        DeclareNewLiteral(Action, _kg2m2_s2)

        DeclareNewLiteral(Energy, _J)
        DeclareNewLiteral(Energy, _eV)
        DeclareNewLiteral(Energy, _Ha)
        DeclareNewLiteral(Energy, _cal)
        DeclareNewLiteral(Energy, _Cal)

        DeclareNewLiteral(Frequency, _Hz)
        DeclareNewLiteral(Frequency, _1_s)

        DeclareNewLiteral(WaveNumber, _1_m)


        // Electromagnetic Quantities
        DeclareNewLiteral(Capacitance, _F)
        DeclareNewLiteral(Capacitance, _C_V)
        DeclareNewLiteral(Capacitance, _A2s4_kgm2)

        DeclareNewLiteral(CurrentDensity, _A_m2)

        DeclareNewLiteral(ElectricCharge, _C)
        DeclareNewLiteral(ElectricCharge, _e)

        DeclareNewLiteral(ElectricChargeDensity, _C_m3)
        DeclareNewLiteral(ElectricChargeDensity, _As_m3)

        DeclareNewLiteral(ElectricConductance, _S)
        DeclareNewLiteral(ElectricConductance, _A_V)
        DeclareNewLiteral(ElectricConductance, _A2s3_kgm2)

        DeclareNewLiteral(ElectricConductivity, _S_m)
        DeclareNewLiteral(ElectricConductivity, _A_Vm)
        DeclareNewLiteral(ElectricConductivity, _A2s3_kgm3)

        DeclareNewLiteral(ElectricCurrent, _A)

        DeclareNewLiteral(ElectricField, _V_m)
        DeclareNewLiteral(ElectricField, _N_C)
        DeclareNewLiteral(ElectricField, _kgm_As3)

        DeclareNewLiteral(ElectricFluxDensity, _C_m2)
        DeclareNewLiteral(ElectricFluxDensity, _As_m2)

        DeclareNewLiteral(ElectricPotential, _V)
        DeclareNewLiteral(ElectricPotential, _kgm2_As3)

        DeclareNewLiteral(ElectricResistance, _Ohm)
        DeclareNewLiteral(ElectricResistance, _kgm2_A2s3)

        DeclareNewLiteral(Mobility, _m2_Vs)
        DeclareNewLiteral(Mobility, _As2_kg)

        DeclareNewLiteral(Permittivity, _F_m)
        DeclareNewLiteral(Permittivity, _A2s4_kgm3)

        DeclareNewLiteral(Inductance, _H)
        DeclareNewLiteral(Inductance, _kgm2_A2s2)

        DeclareNewLiteral(MagneticFieldStrength, _A_m)

        DeclareNewLiteral(MagneticFlux, _Wb)
        DeclareNewLiteral(MagneticFlux, _kgm2_As2)

        DeclareNewLiteral(MagneticFluxDensity, _T)
        DeclareNewLiteral(MagneticFluxDensity, _G)
        DeclareNewLiteral(MagneticFluxDensity, _gamma)
        DeclareNewLiteral(MagneticFluxDensity, _Wb_m2)
        DeclareNewLiteral(MagneticFluxDensity, _kg_As2)

        DeclareNewLiteral(Permeability, _H_m)
        DeclareNewLiteral(Permeability, _N_A2)
        DeclareNewLiteral(Permeability, _kgm_A2s2)


        // Molar Quantities
        DeclareNewLiteral(AmountOfSubstance, _mol)
        DeclareNewLiteral(AmountOfSubstance, _part)

        DeclareNewLiteral(Concentration, _M)
        DeclareNewLiteral(Concentration, _mol_m3)

        DeclareNewLiteral(ConcentrationGradient, _M_m)
        DeclareNewLiteral(ConcentrationGradient, _mol_m4)

        DeclareNewLiteral(Faradays, _C_mol)

        DeclareNewLiteral(MolarConductivity, _Sm2_mol)
        DeclareNewLiteral(MolarConductivity, _A2s3_kgmol)

        DeclareNewLiteral(MolarEnergy, _J_mol)
        DeclareNewLiteral(MolarEnergy, _eV_mol)
        DeclareNewLiteral(MolarEnergy, _kcal_mol)

        DeclareNewLiteral(MolarEnergyFlux, _kg_mols3)

        DeclareNewLiteral(MolarEntropy, _J_molK)
        DeclareNewLiteral(MolarEntropy, _kgm2_s2molK)

        DeclareNewLiteral(MolarMass, _g_mol)
        DeclareNewLiteral(MolarMass, _amu)


        // Thermal Quantities
        DeclareNewLiteral(Entropy, _J_K)
        DeclareNewLiteral(Entropy, _eV_K)

        DeclareNewLiteral(SpecificEntropy, _J_kgK)
        DeclareNewLiteral(SpecificEntropy, _m2_Ks2)

        DeclareNewLiteral(Temperature, _K)
        DeclareNewLiteral(Temperature, _degC)
        DeclareNewLiteral(Temperature, _degF)

        DeclareNewLiteral(ThermalConductivity, _W_mK)
        DeclareNewLiteral(ThermalConductivity, _kgm_Ks3)
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


    // Limit the scope of the preprocessing macros we used by undefining them here
    #undef DeclareNewPhysicalQuantity
    #undef DeclareNewLiteral
}

#endif
