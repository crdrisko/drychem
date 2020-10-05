// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for more information.
//
// Name: physicalQuantities.hpp - Version 1.0.0
// Author: crdrisko
// Date: 03/04/2020-08:13:47
// Description: The public API for the PhysicalQuantities section of the C++ Units project.
//   This header file should be included in all user programs using these utilities.
//
// Note: The internal implementation details associated with this API should not be used in any
//   user program as they are subject to change at any time without warning.

#ifndef CPP_UNITS_PHYSICALQUANTITIES_HPP
#define CPP_UNITS_PHYSICALQUANTITIES_HPP

// #include "conversions/conversions.hpp"
// #include "math/math.hpp"
// #include "math/basicMath.hpp"
#include "types/dimensionality.hpp"
#include "types/physicalQuantity.hpp"

namespace PhysicalQuantities
{
    using DimensionlessQuantity = PhysicalQuantity<Dimensionality<>>;

    // MKS Quantities
    using MassDensity           = PhysicalQuantity<Dimensionality<-3,  1,  0>>;
    using WaveNumber            = PhysicalQuantity<Dimensionality<-1,  0,  0>>;
    using MomentumFlux          = PhysicalQuantity<Dimensionality<-1,  1, -2>>;
    using Pressure              = PhysicalQuantity<Dimensionality<-1,  1, -2>>;
    using Frequency             = PhysicalQuantity<Dimensionality< 0,  0, -1>>;
    using Angle                 = PhysicalQuantity<Dimensionality< 0,  0,  0>>;
    using Time                  = PhysicalQuantity<Dimensionality< 0,  0,  1>>;
    using Irradiance            = PhysicalQuantity<Dimensionality< 0,  1, -3>>;
    using Mass                  = PhysicalQuantity<Dimensionality< 0,  1,  0>>;
    using Acceleration          = PhysicalQuantity<Dimensionality< 1,  0, -2>>;
    using Velocity              = PhysicalQuantity<Dimensionality< 1,  0, -1>>;
    using Length                = PhysicalQuantity<Dimensionality< 1,  0,  0>>;
    using Force                 = PhysicalQuantity<Dimensionality< 1,  1, -2>>;
    using Momentum              = PhysicalQuantity<Dimensionality< 1,  1, -1>>;
    using Action                = PhysicalQuantity<Dimensionality< 2,  2, -2>>;
    using SpecificEnergy        = PhysicalQuantity<Dimensionality< 2,  0, -2>>;
    using AngularVelocity       = PhysicalQuantity<Dimensionality< 2,  0, -1>>;
    using Area                  = PhysicalQuantity<Dimensionality< 2,  0,  0>>;
    using Power                 = PhysicalQuantity<Dimensionality< 2,  1, -3>>;
    using Energy                = PhysicalQuantity<Dimensionality< 2,  1, -2>>;
    using SpecificVolume        = PhysicalQuantity<Dimensionality< 3, -1,  0>>;
    using Volume                = PhysicalQuantity<Dimensionality< 3,  0,  0>>;

    // Electromagnetic Quantities
    using ElectricConductivity  = PhysicalQuantity<Dimensionality<-3, -1,  3,  2>>;
    using Permittivity          = PhysicalQuantity<Dimensionality<-3, -1,  4,  2>>;
    using ElectricChargeDensity = PhysicalQuantity<Dimensionality<-3,  0,  1,  1>>;
    using ElectricConductance   = PhysicalQuantity<Dimensionality<-2, -1,  3,  2>>;
    using Capacitance           = PhysicalQuantity<Dimensionality<-2, -1,  4,  2>>;
    using CurrentDensity        = PhysicalQuantity<Dimensionality<-2,  0,  0,  1>>;
    using ElectricFluxDensity   = PhysicalQuantity<Dimensionality<-2,  0,  1,  1>>;
    using MagneticFieldStrength = PhysicalQuantity<Dimensionality<-1,  0,  0,  1>>;
    using Mobility              = PhysicalQuantity<Dimensionality< 0, -1,  2,  1>>;
    using ElectricCurrent       = PhysicalQuantity<Dimensionality< 0,  0,  0,  1>>;
    using ElectricCharge        = PhysicalQuantity<Dimensionality< 0,  0,  1,  1>>;
    using MagneticFluxDensity   = PhysicalQuantity<Dimensionality< 0,  1, -2, -1>>;
    using ElectricField         = PhysicalQuantity<Dimensionality< 1,  1, -3, -1>>;
    using Permeability          = PhysicalQuantity<Dimensionality< 1,  1, -2, -2>>;
    using ElectricResistance    = PhysicalQuantity<Dimensionality< 2,  1, -3, -2>>;
    using ElectricPotential     = PhysicalQuantity<Dimensionality< 2,  1, -3, -1>>;
    using Inductance            = PhysicalQuantity<Dimensionality< 2,  1, -2, -2>>;
    using MagneticFlux          = PhysicalQuantity<Dimensionality< 2,  1, -2, -1>>;

    // Thermal Quantities
    using Temperature           = PhysicalQuantity<Dimensionality< 0,  0,  0,  0,  1>>;
    using ThermalConductivity   = PhysicalQuantity<Dimensionality< 1,  1, -3,  0, -1>>;
    using SpecificEntropy       = PhysicalQuantity<Dimensionality< 2,  0, -2,  0, -1>>;
    using Entropy               = PhysicalQuantity<Dimensionality< 2,  1, -2,  0, -1>>;

    // Molar Quantities
    using AmountOfSubstance     = PhysicalQuantity<Dimensionality< 0,  0,  0,  0,  0,  1>>;
    using Concentration         = PhysicalQuantity<Dimensionality<-3,  0,  0,  0,  0,  1>>;
    using ConcentrationGradient = PhysicalQuantity<Dimensionality<-4,  0,  0,  0,  0,  1>>;
    using Faradays              = PhysicalQuantity<Dimensionality< 0,  0,  1,  1,  0, -1>>;
    using MolarConductivity     = PhysicalQuantity<Dimensionality< 0, -1,  3,  2,  0, -1>>;
    using MolarEnergy           = PhysicalQuantity<Dimensionality< 2,  1, -2,  0,  0, -1>>;
    using MolarEnergyFlux       = PhysicalQuantity<Dimensionality< 0,  1, -3,  0,  0, -1>>;
    using MolarEntropy          = PhysicalQuantity<Dimensionality< 2,  1, -2,  0, -1, -1>>;
    using MolarMass             = PhysicalQuantity<Dimensionality< 0,  1,  0,  0,  0, -1>>;

    // Luminous Quantities
    using Illuminance           = PhysicalQuantity<Dimensionality<-2,  0,  0,  0,  0,  0,  1>>;
    using LuminousIntensity     = PhysicalQuantity<Dimensionality< 0,  0,  0,  0,  0,  0,  1>>;
    using Luminance             = PhysicalQuantity<Dimensionality< 2,  0,  0,  0,  0,  0,  1>>;


    namespace Literals
    {
        // We need a better way to organize the unit literals than just a wall of possible units
        constexpr auto operator"" _(long double magnitude) { return DimensionlessQuantity(magnitude); }

        // User-Defined Literals for MKS Quantities
        constexpr auto operator"" _m_s2(long double magnitude) { return Acceleration(magnitude); }
        constexpr auto operator"" _Js(long double magnitude) { return Action(magnitude); }
        constexpr auto operator"" _rad(long double magnitude) { return Angle(magnitude); }
        constexpr auto operator"" _deg(long double magnitude) { return Angle(magnitude); }
        constexpr auto operator"" _m2_s(long double magnitude) { return AngularVelocity(magnitude); }
        constexpr auto operator"" _m2(long double magnitude) { return Area(magnitude); }
        constexpr auto operator"" _Ang2(long double magnitude) { return Area(magnitude); }
        constexpr auto operator"" _J(long double magnitude) { return Energy(magnitude); }
        constexpr auto operator"" _eV(long double magnitude) { return Energy(magnitude); }
        constexpr auto operator"" _Ha(long double magnitude) { return Energy(magnitude); }
        constexpr auto operator"" _cal(long double magnitude) { return Energy(magnitude); }
        constexpr auto operator"" _Cal(long double magnitude) { return Energy(magnitude); }
        constexpr auto operator"" _N(long double magnitude) { return Force(magnitude); }
        constexpr auto operator"" _Hz(long double magnitude) { return Frequency(magnitude); }
        constexpr auto operator"" _W_m2(long double magnitude) { return Irradiance(magnitude); }
        constexpr auto operator"" _m(long double magnitude) { return Length(magnitude); }
        constexpr auto operator"" _Ang(long double magnitude) { return Length(magnitude); }
        constexpr auto operator"" _in(long double magnitude) { return Length(magnitude); }
        constexpr auto operator"" _ft(long double magnitude) { return Length(magnitude); }
        constexpr auto operator"" _yd(long double magnitude) { return Length(magnitude); }
        constexpr auto operator"" _mil(long double magnitude) { return Length(magnitude); }
        constexpr auto operator"" _kg(long double magnitude) { return Mass(magnitude); }
        constexpr auto operator"" _lbs(long double magnitude) { return Mass(magnitude); }
        constexpr auto operator"" _kg_m3(long double magnitude) { return MassDensity(magnitude); }
        constexpr auto operator"" _kgm_s(long double magnitude) { return Momentum(magnitude); }
        constexpr auto operator"" _kg_ms2(long double magnitude) { return MomentumFlux(magnitude); }
        constexpr auto operator"" _W(long double magnitude) { return Power(magnitude); }
        constexpr auto operator"" _bar(long double magnitude) { return Pressure(magnitude); }
        constexpr auto operator"" _Pa(long double magnitude) { return Pressure(magnitude); }
        constexpr auto operator"" _atm(long double magnitude) { return Pressure(magnitude); }
        constexpr auto operator"" _torr(long double magnitude) { return Pressure(magnitude); }
        constexpr auto operator"" _psi(long double magnitude) { return Pressure(magnitude); }
        constexpr auto operator"" _J_kg(long double magnitude) { return SpecificEnergy(magnitude); }
        constexpr auto operator"" _m3_kg(long double magnitude) { return SpecificVolume(magnitude); }
        constexpr auto operator"" _s(long double magnitude) { return Time(magnitude); }
        constexpr auto operator"" _min(long double magnitude) { return Time(magnitude); }
        constexpr auto operator"" _hr(long double magnitude) { return Time(magnitude); }
        constexpr auto operator"" _days(long double magnitude) { return Time(magnitude); }
        constexpr auto operator"" _weeks(long double magnitude) { return Time(magnitude); }
        constexpr auto operator"" _months(long double magnitude) { return Time(magnitude); }
        constexpr auto operator"" _years(long double magnitude) { return Time(magnitude); }
        constexpr auto operator"" _m_s(long double magnitude) { return Velocity(magnitude); }
        constexpr auto operator"" _m3(long double magnitude) { return Volume(magnitude); }
        constexpr auto operator"" _Ang3(long double magnitude) { return Volume(magnitude); }
        constexpr auto operator"" _L(long double magnitude) { return Volume(magnitude); }
        constexpr auto operator"" _1_m(long double magnitude) { return WaveNumber(magnitude); }

        // User-Defined Literals for Electromagnetic Quantities
        constexpr auto operator"" _F(long double magnitude) { return Capacitance(magnitude); }
        constexpr auto operator"" _A_m2(long double magnitude) { return CurrentDensity(magnitude); }
        constexpr auto operator"" _e(long double magnitude) { return ElectricCharge(magnitude); }
        constexpr auto operator"" _C(long double magnitude) { return ElectricCharge(magnitude); }
        constexpr auto operator"" _C_m3(long double magnitude) { return ElectricChargeDensity(magnitude); }
        constexpr auto operator"" _S(long double magnitude) { return ElectricConductance(magnitude); }
        constexpr auto operator"" _S_m(long double magnitude) { return ElectricConductivity(magnitude); }
        constexpr auto operator"" _A(long double magnitude) { return ElectricCurrent(magnitude); }
        constexpr auto operator"" _V_m(long double magnitude) { return ElectricField(magnitude); }
        constexpr auto operator"" _C_m2(long double magnitude) { return ElectricFluxDensity(magnitude); }
        constexpr auto operator"" _V(long double magnitude) { return ElectricPotential(magnitude); }
        constexpr auto operator"" _Ohm(long double magnitude) { return ElectricResistance(magnitude); }
        constexpr auto operator"" _H(long double magnitude) { return Inductance(magnitude); }
        constexpr auto operator"" _A_m(long double magnitude) { return MagneticFieldStrength(magnitude); }
        constexpr auto operator"" _Wb(long double magnitude) { return MagneticFlux(magnitude); }
        constexpr auto operator"" _T(long double magnitude) { return MagneticFluxDensity(magnitude); }
        constexpr auto operator"" _G(long double magnitude) { return MagneticFluxDensity(magnitude); }
        constexpr auto operator"" _gamma(long double magnitude) { return MagneticFluxDensity(magnitude); }
        constexpr auto operator"" _Wb_m2(long double magnitude) { return MagneticFluxDensity(magnitude); }
        constexpr auto operator"" _kg_As2(long double magnitude) { return MagneticFluxDensity(magnitude); }
        constexpr auto operator"" _m2_Vs(long double magnitude) { return Mobility(magnitude); }
        constexpr auto operator"" _H_m(long double magnitude) { return Permeability(magnitude); }
        constexpr auto operator"" _F_m(long double magnitude) { return Permittivity(magnitude); }

        // User-Defined Literals for Molar Quantities
        constexpr auto operator"" _mol(long double magnitude) { return AmountOfSubstance(magnitude); }
        constexpr auto operator"" _part(long double magnitude) { return AmountOfSubstance(magnitude); }
        constexpr auto operator"" _M(long double magnitude) { return Concentration(magnitude); }
        constexpr auto operator"" _M_m(long double magnitude) { return ConcentrationGradient(magnitude); }
        constexpr auto operator"" _C_mol(long double magnitude) { return Faradays(magnitude); }
        constexpr auto operator"" _Sm2_mol(long double magnitude) { return MolarConductivity(magnitude); }
        constexpr auto operator"" _J_mol(long double magnitude) { return MolarEnergy(magnitude); }
        constexpr auto operator"" _eV_mol(long double magnitude) { return MolarEnergy(magnitude); }
        constexpr auto operator"" _kcal_mol(long double magnitude) { return MolarEnergy(magnitude); }
        constexpr auto operator"" _kg_mols3(long double magnitude) { return MolarEnergyFlux(magnitude); }
        constexpr auto operator"" _J_molK(long double magnitude) { return MolarEntropy(magnitude); }
        constexpr auto operator"" _g_mol(long double magnitude) { return MolarMass(magnitude); }
        constexpr auto operator"" _amu(long double magnitude) { return MolarMass(magnitude); }

        // User-Defined Literals for Thermal Quantities
        constexpr auto operator"" _J_K(long double magnitude) { return Entropy(magnitude); }
        constexpr auto operator"" _eV_K(long double magnitude) { return Entropy(magnitude); }
        constexpr auto operator"" _J_kgK(long double magnitude) { return SpecificEntropy(magnitude); }
        constexpr auto operator"" _K(long double magnitude) { return Temperature(magnitude); }
        constexpr auto operator"" _degC(long double magnitude) { return Temperature(magnitude); }
        constexpr auto operator"" _degF(long double magnitude) { return Temperature(magnitude); }
        constexpr auto operator"" _W_mK(long double magnitude) { return ThermalConductivity(magnitude); }

        // User-Defined Literals for Luminous Quantities
        constexpr auto operator"" _cd_m2(long double magnitude) { return Luminance(magnitude); }
        constexpr auto operator"" _lx(long double magnitude) { return Illuminance(magnitude); }
        constexpr auto operator"" _cd(long double magnitude) { return LuminousIntensity(magnitude); }
    }


    namespace Constants
    {
        using namespace Literals;

        constexpr DimensionlessQuantity avogadrosNumber = 6.02214076e23_;
        constexpr Length                bohrRadius = 5.29177210903e-11_m;
        constexpr Entropy               boltzmannConstant = 1.380649e-23_J_K;
        constexpr ElectricCharge        elementaryCharge = 1.602176634e-19_C;
        constexpr Faradays              faradaysConstant = (elementaryCharge * avogadrosNumber) / 1.0_mol;
        constexpr Permittivity          permittivityFreeSpace = 8.8541878128e-12_F_m;
        constexpr DimensionlessQuantity pi = 3.14159265_;
        constexpr Action                plancksConstant = 6.62607015e-34_Js;
        constexpr Velocity              speedOfLight = 299'792'458.0_m_s;
    }
}

#endif
