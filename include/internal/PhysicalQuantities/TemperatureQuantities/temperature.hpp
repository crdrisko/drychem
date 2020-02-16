// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: temperature.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:45:39
// Description: Defines the units, constants, and conversions of temperature

#ifndef UTILITIES_API_TEMPERATURE_HPP
#define UTILITIES_API_TEMPERATURE_HPP

#include "../conversions.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using TemperatureDimensionality = Dimensionality<0, 0, 0, 0, 1>;
    using Temperature = PhysicalQuantity<TemperatureDimensionality>;

    // Temperature Units
    constexpr Temperature operator"" _K(long double magnitude)
    {
        return Temperature(magnitude);
    }

    constexpr Temperature operator"" _degC(long double magnitude)
    {
        return Temperature(magnitude);
    }

    constexpr Temperature operator"" _degF(long double magnitude)
    {
        return Temperature(magnitude);
    }

    // Temperature Conversions
    namespace Conversions
    {
        constexpr Temperature convertTemperature(Temperature temperatureToConvert,
            const std::string& initialUnits, const std::string& finalUnits)
        {
            Temperature convertedTemperature = temperatureToConvert;

            if ( (initialUnits == "K") && (finalUnits != "K") )
            {
                if (finalUnits == "degC")
                    convertedTemperature = temperatureToConvert.convertQuantity(1.0_, -273.15);

                else if (finalUnits == "degF")
                    convertedTemperature = temperatureToConvert.convertQuantity((9.0_ / 5.0_), 32.0,
                        -273.15);

                else
                    Utilities_API::Errors::printFatalErrorMessage(1, finalUnits
                        + " are not recognized Temperature units.");
            }
            else if ( (initialUnits != "K") && (finalUnits == "K") )
            {
                if (initialUnits == "degC")
                    convertedTemperature = temperatureToConvert.convertQuantity(1.0_, 273.15);

                else if (initialUnits == "degF")
                    convertedTemperature = temperatureToConvert.convertQuantity((5.0_ / 9.0_), 273.15,
                        -32.0);

                else
                    Utilities_API::Errors::printFatalErrorMessage(1, initialUnits
                        + " are not recognized Temperature units.");
            }
            else if ( (initialUnits != "K") && (finalUnits != "K") && (initialUnits != finalUnits) )
            {
                Temperature initialTempInKelvin {convertTemperature(temperatureToConvert, initialUnits, "K")};
                convertedTemperature = convertTemperature(initialTempInKelvin, "K", finalUnits);
            }

            return convertedTemperature;
        }
    }
}

#endif
