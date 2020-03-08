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
#include <cmath>
#include <string>
#include <string_view>

#include <utils-api/errors.hpp>

namespace PhysicalQuantities::Conversions
{
    class Conversion
    {
    private:
        long double magnitude;
        std::string initialUnits;
        std::string finalUnits;

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

        static inline std::map<std::string_view, long double> AngleUnitsRelativeToRadians
        {
            {"deg", 57.2957795},
            {"rad", 1.0}
        };

        static inline std::map<std::string_view, long double> LengthUnitsRelativeToMeters
        {
            {"m", 1.0},
            {"Ang", 1e10},
            {"in", 39.3700787},
            {"ft", 3.280840},
            {"yd", 1.093613},
            {"mil", 6.213712e-4}
        };

        static inline std::map<std::string_view, long double> AreaUnitsRelativeToMetersSquared
        {
            {"m2", std::pow(LengthUnitsRelativeToMeters["m"], 2)},
            {"Ang2", std::pow(LengthUnitsRelativeToMeters["Ang"], 2)}
        };

        static inline std::map<std::string_view, long double> VolumeUnitsRelativeToMetersCubed
        {
            {"m3", std::pow(LengthUnitsRelativeToMeters["m"], 3)},
            {"Ang3", std::pow(LengthUnitsRelativeToMeters["Ang"], 3)},
            {"L", 1e3}
        };

        static inline std::map<std::string_view, long double> MassUnitsRelativeToKilograms
        {
            {"kg", 1.0},
            {"lbs", 2.20462}
        };

        static inline std::map<std::string_view, long double> PressureUnitsRelativeToBar
        {
            {"Pa", 1e5},
            {"atm", 0.986923},
            {"torr", 750.062},
            {"bar", 1.0},
            {"psi", 14.5038}
        };

        static inline std::map<std::string_view, long double> TimeUnitsRelativeToSeconds
        {
            {"s", 1.0},
            {"min", 1 / 60.0},
            {"hr", 1 / 3600.0},
            {"days", 1 / 8.64e4},
            {"weeks", 1 / 6.048e5},
            {"months", 1 / 2.628e6},
            {"years", 1 / 3.154e7}
        };

        static inline std::map<std::string_view, long double> EnergyUnitsRelativeToJoules
        {
            {"J", 1.0},
            {"eV", 6.241509074e18},
            {"Hartree", 2.2937122783963e17},
            {"cal", 0.2390},
            {"Cal", 0.0002390}
        };

        static inline std::map<std::string_view, long double> ElectricChargeUnitsRelativeToElectrons
        {
            {"e", 1.0},
            {"C", 1.602176634e-19}
        };

        static inline std::map<std::string_view, long double> MagneticFluxDensityUnitsRelativeToTesla
        {
            {"T", 1.0},
            {"G", 10'000.0},
            {"gamma", 1e9}
        };

        static inline std::map<std::string_view, long double> AmountOfSubstanceUnitsRelativeToMoles
        {
            {"mol", 1.0},
            {"part", 6.02214076e23}
        };

        static inline std::map<std::string_view, long double> MolarEnergyUnitsRelativeToJoulesPerMol
        {
            {"J_mol", 1.0},
            {"eV_part", 1.036426966e-5},
            {"kcal_mol", 0.00023901}
        };

        static inline std::map<std::string_view, long double> TemperatureUnitsRelativeToKelvin
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
            {"deg", AngleUnitsRelativeToRadians},
            {"rad", AngleUnitsRelativeToRadians},

            // Length Units
            {"m", LengthUnitsRelativeToMeters},
            {"Ang", LengthUnitsRelativeToMeters},
            {"in", LengthUnitsRelativeToMeters},
            {"ft", LengthUnitsRelativeToMeters},
            {"yd", LengthUnitsRelativeToMeters},
            {"mil", LengthUnitsRelativeToMeters},

            // Area Units
            {"m2", AreaUnitsRelativeToMetersSquared},
            {"Ang2", AreaUnitsRelativeToMetersSquared},

            // Volume Units
            {"m3", VolumeUnitsRelativeToMetersCubed},
            {"Ang3", VolumeUnitsRelativeToMetersCubed},
            {"L", VolumeUnitsRelativeToMetersCubed},

            // Mass Units
            {"kg", MassUnitsRelativeToKilograms},
            {"lbs", MassUnitsRelativeToKilograms},

            // Pressure Units
            {"Pa", PressureUnitsRelativeToBar},
            {"atm", PressureUnitsRelativeToBar},
            {"torr", PressureUnitsRelativeToBar},
            {"bar", PressureUnitsRelativeToBar},
            {"psi", PressureUnitsRelativeToBar},

            // Time Units
            {"s", TimeUnitsRelativeToSeconds},
            {"min", TimeUnitsRelativeToSeconds},
            {"hr", TimeUnitsRelativeToSeconds},
            {"days", TimeUnitsRelativeToSeconds},
            {"weeks", TimeUnitsRelativeToSeconds},
            {"months", TimeUnitsRelativeToSeconds},
            {"years", TimeUnitsRelativeToSeconds},

            // Energy Units
            {"J", EnergyUnitsRelativeToJoules},
            {"eV", EnergyUnitsRelativeToJoules},
            {"Hartree", EnergyUnitsRelativeToJoules},
            {"cal", EnergyUnitsRelativeToJoules},
            {"Cal", EnergyUnitsRelativeToJoules},

            // Electric Charge Units
            {"e", ElectricChargeUnitsRelativeToElectrons},
            {"C", ElectricChargeUnitsRelativeToElectrons},

            // Magnetic Flux Density Units
            {"T", MagneticFluxDensityUnitsRelativeToTesla},
            {"G", MagneticFluxDensityUnitsRelativeToTesla},
            {"gamma", MagneticFluxDensityUnitsRelativeToTesla},

            // Amount of Substance Units
            {"mol", AmountOfSubstanceUnitsRelativeToMoles},
            {"part", AmountOfSubstanceUnitsRelativeToMoles},

            // Molar Energy Units
            {"J_mol", MolarEnergyUnitsRelativeToJoulesPerMol},
            {"eV_part", MolarEnergyUnitsRelativeToJoulesPerMol},
            {"kcal_mol", MolarEnergyUnitsRelativeToJoulesPerMol},

            // Temperature Units
            {"K", TemperatureUnitsRelativeToKelvin},
            {"degC", TemperatureUnitsRelativeToKelvin},
            {"degF", TemperatureUnitsRelativeToKelvin}
        };

    public:
        Conversion(long double Magnitude, std::string_view InitialUnits, std::string_view FinalUnits) noexcept
            : magnitude{Magnitude}, initialUnits{InitialUnits}, finalUnits{FinalUnits} {}

        long double convertQuantity() const;
    };


    long double Conversion::convertQuantity() const
    {
        long double internalShearingFactor {0.0};
        long double externalShearingFactor {0.0};

        // Sanitize User Input
        if ( conversionMap.count(initialUnits) != 1 )
            Utilities_API::Errors::printFatalErrorMessage(1, initialUnits + " is not a valid unit.");

        else if ( conversionMap.count(finalUnits) != 1 )
            Utilities_API::Errors::printFatalErrorMessage(1, finalUnits + " is not a valid unit.");

        else if ( conversionMap[initialUnits] != conversionMap[finalUnits] )
            Utilities_API::Errors::printFatalErrorMessage(1, "Initial and final units must be of the same type.");

        else if (initialUnits == finalUnits)
            return magnitude;

        // Temperature requires a different process for determining the conversion factors
        else if (conversionMap[initialUnits] == TemperatureUnitsRelativeToKelvin)
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

        long double conversionFactor { conversionMap[finalUnits][finalUnits] / conversionMap[initialUnits][initialUnits] };

        long double convertedValue { ((magnitude + internalShearingFactor) * conversionFactor) + externalShearingFactor };

        return convertedValue;
    }
}

#endif
