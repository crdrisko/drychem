// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: volume.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-16:29:07
// Description: Defines the units, constants, and conversions of volume

#ifndef UTILITIES_API_VOLUME_HPP
#define UTILITIES_API_VOLUME_HPP

#include "length.hpp"

namespace Utilities_API::PhysicalQuantities
{
    using VolumeDimensionality = Dimensionality<3, 0, 0>;
    using Volume = PhysicalQuantity<VolumeDimensionality>;

    // Volume Units
    constexpr Volume operator"" _m3(long double magnitude)
    {
        return Volume(magnitude);
    }

    constexpr Volume operator"" _Ang3(long double magnitude)
    {
        return Volume(magnitude);
    }

    constexpr Volume operator"" _L(long double magnitude)
    {
        return Volume(magnitude);
    }

    // Volume Conversions
    namespace Conversions
    {
        inline long double getVolumeUnitsFromLengthCubed(std::string_view desiredLengthUnits)
        {
            Length length(lengthUnitsRelativeToMeters[desiredLengthUnits]);
            Volume volume = length.raisePower<VolumeDimensionality>(3);

            return volume.getMagnitude();
        }

        static inline std::map<std::string_view, long double> volumeUnitsRelativeToMetersCubed
        {
            {"m3", getVolumeUnitsFromLengthCubed("m")},
            {"Ang3", getVolumeUnitsFromLengthCubed("Ang")},
            {"L", 1e3}
        };

        inline auto getVolumeConversionFactor = std::bind(getConversionFactor, std::placeholders::_1,
            std::placeholders::_2, volumeUnitsRelativeToMetersCubed);
    }
}

#endif
