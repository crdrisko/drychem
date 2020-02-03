// Copyright (c) 2020 Cody R. Drisko. All rights reserved.
// Licensed under the MIT License. See the LICENSE file in the project root for license information.
//
// Name: basicMath.hpp - Version 1.0.0
// Author: cdrisko
// Date: 01/31/2020-15:42:41
// Description: Common mathematical function definitions and prototypes

#ifndef UTILITIES_API_BASICMATH_HPP
#define UTILITIES_API_BASICMATH_HPP

#include <vector>

namespace Utilities_API::Math
{
    std::vector<long double> linearlyInterpolate(std::vector<long double> x, long double y1, long double y2);

    template<typename T>
    inline bool withinRange(const T& value, const T& min, const T& max)
    {
        return (value <= max) && (value >= min);
    }

    template<int min, int max, typename T>
    inline bool withinRange(const T& value)
    {
        return withinRange(value, static_cast<T>(min), static_cast<T>(max));
    }
}

#endif
