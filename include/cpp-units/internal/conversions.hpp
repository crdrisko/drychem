// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: conversions.hpp - Version 1.0.0
// Author: crdrisko
// Date: 03/03/2020-18:45:36
// Description: Conversion factors and functions relating to unit conversions for PhysicalQuantities

#ifndef CPP_UNITS_CONVERSIONS_HPP
#define CPP_UNITS_CONVERSIONS_HPP

#include <cmath>
#include <map>
#include <memory>
#include <string>
#include <string_view>

#include <utils-api/errors.hpp>

namespace PhysicalQuantities::Conversions
{
    class Conversion
    {
    private:
        static inline std::map<std::string_view, long double> SIPrefixUnitsRelativeToBase
        {
            {"yotta", 1e-24}, {"zetta", 1e-21}, {"exa",   1e-18},
            {"peta",  1e-15}, {"tera",  1e-12}, {"giga",  1e-9},
            {"mega",  1e-6},  {"kilo",  1e-3},  {"hecto", 1e-2},
            {"deka",  1e-1},  {"base",  1e0},   {"deci",  1e1},
            {"centi", 1e2},   {"milli", 1e3},   {"micro", 1e6},
            {"nano",  1e9},   {"pico",  1e12},  {"femto", 1e15},
            {"atto",  1e18},  {"zepto", 1e21},  {"yocto", 1e24}
        };

        static inline std::map<std::string_view, long double> AngleUnitsRelativeTo_rad
        {
            {"deg", 57.2957795},
            {"rad", 1.0}
        };

        static inline std::map<std::string_view, long double> LengthUnitsRelativeTo_m
        {
            {"m", 1.0},
            {"Ang", 1e10},
            {"in", 39.3700787},
            {"ft", 3.280840},
            {"yd", 1.093613},
            {"mil", 6.213712e-4}
        };

        static inline std::map<std::string_view, long double> AreaUnitsRelativeTo_m2
        {
            {"m2", std::pow(LengthUnitsRelativeTo_m["m"], 2)},
            {"Ang2", std::pow(LengthUnitsRelativeTo_m["Ang"], 2)}
        };

        static inline std::map<std::string_view, long double> VolumeUnitsRelativeTo_m3
        {
            {"m3", std::pow(LengthUnitsRelativeTo_m["m"], 3)},
            {"Ang3", std::pow(LengthUnitsRelativeTo_m["Ang"], 3)},
            {"L", 1e3}
        };

        static inline std::map<std::string_view, long double> MassUnitsRelativeTo_kg
        {
            {"kg", 1.0},
            {"lbs", 2.20462}
        };

        static inline std::map<std::string_view, long double> PressureUnitsRelativeTo_bar
        {
            {"Pa", 1e5},
            {"atm", 0.986923},
            {"torr", 750.062},
            {"bar", 1.0},
            {"psi", 14.5038}
        };

        static inline std::map<std::string_view, long double> TimeUnitsRelativeTo_s
        {
            {"s", 1.0},
            {"min", 1 / 60.0},
            {"hr", 1 / 3600.0},
            {"days", 1 / 8.64e4},
            {"weeks", 1 / 6.048e5},
            {"months", 1 / 2.628e6},
            {"years", 1 / 3.154e7}
        };

        static inline std::map<std::string_view, long double> EnergyUnitsRelativeTo_J
        {
            {"J", 1.0},
            {"eV", 6.241509074e18},
            {"Hartree", 2.2937122783963e17},
            {"cal", 0.2390},
            {"Cal", 0.0002390}
        };

        static inline std::map<std::string_view, long double> ElectricChargeUnitsRelativeTo_e
        {
            {"e", 1.0},
            {"C", 1.602176634e-19}
        };

        static inline std::map<std::string_view, long double> MagneticFluxDensityUnitsRelativeTo_T
        {
            {"T", 1.0},
            {"G", 10'000.0},
            {"gamma", 1e9}
        };

        static inline std::map<std::string_view, long double> AmountOfSubstanceUnitsRelativeTo_mol
        {
            {"mol", 1.0},
            {"part", 6.02214076e23}
        };

        static inline std::map<std::string_view, long double> MolarEnergyUnitsRelativeTo_J_mol
        {
            {"J_mol", 1.0},
            {"eV_part", 1.036426966e-5},
            {"kcal_mol", 0.00023901}
        };

        static inline std::map<std::string_view, long double> TemperatureUnitsRelativeTo_K
        {
            {"K", 1.0},
            {"degC", 1.0},
            {"degF", 9.0 / 5.0}
        };

        static inline std::map<std::string_view, std::map<std::string_view, long double> > conversionMap
        {
            // SI Prefix Units
            {"yotta", SIPrefixUnitsRelativeToBase},
            {"zetta", SIPrefixUnitsRelativeToBase},
            {"exa",   SIPrefixUnitsRelativeToBase},
            {"peta",  SIPrefixUnitsRelativeToBase},
            {"tera",  SIPrefixUnitsRelativeToBase},
            {"giga",  SIPrefixUnitsRelativeToBase},
            {"mega",  SIPrefixUnitsRelativeToBase},
            {"kilo",  SIPrefixUnitsRelativeToBase},
            {"hecto", SIPrefixUnitsRelativeToBase},
            {"deka",  SIPrefixUnitsRelativeToBase},
            {"base",  SIPrefixUnitsRelativeToBase},
            {"deci",  SIPrefixUnitsRelativeToBase},
            {"centi", SIPrefixUnitsRelativeToBase},
            {"milli", SIPrefixUnitsRelativeToBase},
            {"micro", SIPrefixUnitsRelativeToBase},
            {"nano",  SIPrefixUnitsRelativeToBase},
            {"pico",  SIPrefixUnitsRelativeToBase},
            {"femto", SIPrefixUnitsRelativeToBase},
            {"atto",  SIPrefixUnitsRelativeToBase},
            {"zepto", SIPrefixUnitsRelativeToBase},
            {"yocto", SIPrefixUnitsRelativeToBase},

            // Angle Units
            {"deg", AngleUnitsRelativeTo_rad},
            {"rad", AngleUnitsRelativeTo_rad},

            // Length Units
            {"m", LengthUnitsRelativeTo_m},
            {"Ang", LengthUnitsRelativeTo_m},
            {"in", LengthUnitsRelativeTo_m},
            {"ft", LengthUnitsRelativeTo_m},
            {"yd", LengthUnitsRelativeTo_m},
            {"mil", LengthUnitsRelativeTo_m},

            // Area Units
            {"m2", AreaUnitsRelativeTo_m2},
            {"Ang2", AreaUnitsRelativeTo_m2},

            // Volume Units
            {"m3", VolumeUnitsRelativeTo_m3},
            {"Ang3", VolumeUnitsRelativeTo_m3},
            {"L", VolumeUnitsRelativeTo_m3},

            // Mass Units
            {"kg", MassUnitsRelativeTo_kg},
            {"lbs", MassUnitsRelativeTo_kg},

            // Pressure Units
            {"Pa", PressureUnitsRelativeTo_bar},
            {"atm", PressureUnitsRelativeTo_bar},
            {"torr", PressureUnitsRelativeTo_bar},
            {"bar", PressureUnitsRelativeTo_bar},
            {"psi", PressureUnitsRelativeTo_bar},

            // Time Units
            {"s", TimeUnitsRelativeTo_s},
            {"min", TimeUnitsRelativeTo_s},
            {"hr", TimeUnitsRelativeTo_s},
            {"days", TimeUnitsRelativeTo_s},
            {"weeks", TimeUnitsRelativeTo_s},
            {"months", TimeUnitsRelativeTo_s},
            {"years", TimeUnitsRelativeTo_s},

            // Energy Units
            {"J", EnergyUnitsRelativeTo_J},
            {"eV", EnergyUnitsRelativeTo_J},
            {"Hartree", EnergyUnitsRelativeTo_J},
            {"cal", EnergyUnitsRelativeTo_J},
            {"Cal", EnergyUnitsRelativeTo_J},

            // Electric Charge Units
            {"e", ElectricChargeUnitsRelativeTo_e},
            {"C", ElectricChargeUnitsRelativeTo_e},

            // Magnetic Flux Density Units
            {"T", MagneticFluxDensityUnitsRelativeTo_T},
            {"G", MagneticFluxDensityUnitsRelativeTo_T},
            {"gamma", MagneticFluxDensityUnitsRelativeTo_T},

            // Amount of Substance Units
            {"mol", AmountOfSubstanceUnitsRelativeTo_mol},
            {"part", AmountOfSubstanceUnitsRelativeTo_mol},

            // Molar Energy Units
            {"J_mol", MolarEnergyUnitsRelativeTo_J_mol},
            {"eV_part", MolarEnergyUnitsRelativeTo_J_mol},
            {"kcal_mol", MolarEnergyUnitsRelativeTo_J_mol},

            // Temperature Units
            {"K", TemperatureUnitsRelativeTo_K},
            {"degC", TemperatureUnitsRelativeTo_K},
            {"degF", TemperatureUnitsRelativeTo_K}
        };

    public:
        Conversion() = default;

        long double convertQuantity(long double magnitude, const std::string& initialUnits,
            const std::string& finalUnits) const;
    };


    inline long double Conversion::convertQuantity(long double magnitude, const std::string& initialUnits,
        const std::string& finalUnits) const
    {
        long double internalShearingFactor {0.0};
        long double externalShearingFactor {0.0};

        // Sanitize User Input
        if ( conversionMap.count(initialUnits) != 1 )
            throw Utilities_API::Errors::InvalidInputException { "CPP-Units",
                initialUnits + " is not a valid unit." };

        else if ( conversionMap.count(finalUnits) != 1 )
            throw Utilities_API::Errors::InvalidInputException { "CPP-Units",
                finalUnits + " is not a valid unit." };

        else if ( conversionMap[initialUnits] != conversionMap[finalUnits] )
            throw Utilities_API::Errors::InvalidInputException { "CPP-Units",
                "Initial and final units must be of the same type." };

        else if (initialUnits == finalUnits)
            return magnitude;

        // Temperature requires a different process for determining the conversion factors
        else if (conversionMap[initialUnits] == TemperatureUnitsRelativeTo_K)
        {
            if ( (initialUnits == "K") && (finalUnits == "degC") )
            {
                externalShearingFactor = -273.15;
                internalShearingFactor = 0.0;
            }
            else if ( (initialUnits == "K") && (finalUnits == "degF") )
            {
                externalShearingFactor = 32.0;
                internalShearingFactor = -273.15;
            }
            else if ( (initialUnits == "degC") && (finalUnits == "K") )
            {
                externalShearingFactor = 273.15;
                internalShearingFactor = 0.0;
            }
            else if ( (initialUnits == "degC") && (finalUnits == "degF") )
            {
                externalShearingFactor = 32.0;
                internalShearingFactor = 0.0;
            }
            else if ( (initialUnits == "degF") && (finalUnits == "K") )
            {
                externalShearingFactor = 273.15;
                internalShearingFactor = -32.0;
            }
            else if ( (initialUnits == "degF") && (finalUnits == "degC") )
            {
                externalShearingFactor = 0.0;
                internalShearingFactor = -32.0;
            }
        }

        long double conversionFactor { conversionMap[finalUnits][finalUnits]
            / conversionMap[initialUnits][initialUnits] };

        long double convertedValue { ((magnitude + internalShearingFactor) * conversionFactor)
            + externalShearingFactor };

        return convertedValue;
    }
}

#endif
